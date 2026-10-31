#include "Data.h"
#include<thread>
#include <unordered_map>
#include <map>
#include "Memory.h"
#include <locale>
#include <codecvt>
#include <array>
#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
Espp* g_pEsp = new Espp();
DWORD Data::ViewMatrixBase;
DWORD Data::Ue4base;
AActor Data::TargetActor;
DWORD Data::UWorld = 0;
BYTE ViewMatrixSearch[] =
{
	0x02, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x01
};

BYTE ue4[] =
{
	0x10, 0x4C, 0x2D, 0xE9, 0x08, 0xB0, 0x8D, 0xE2, 0x00, 0x40, 0xA0, 0xE1, 0x00, 0x00, 0x94, 0xE5, 0x00, 0x00, 0x50, 0xE3, 0x00, 0x00, 0x00, 0x0A, 0xB3, 0x3F, 0x3F, 0xEB, 0x04, 0x00, 0xA0, 0xE1, 0x10, 0x8C, 0xBD, 0xE8, 0x0F, 0xE0, 0xA0, 0xE1, 0x5F, 0xA7, 0x00, 0xEA, 0x30, 0x48, 0x2D, 0xE9
};

DWORD Data::GetUe4Base(DWORD StartAddress, DWORD EndAddress)
{
	DWORD ViewMatrixBase = 0;
	std::vector<DWORD_PTR> FoundedBase;
	Utility::MemSearch(ue4, sizeof(ue4), StartAddress, EndAddress, 0, 0, FoundedBase);

	/*for (int i = 0; i < FoundedBase.size(); i++)
	{
		DWORD Cand = FoundedBase[i] - 0x20;
		DWORD Eng = Utility::ReadMemoryEx<DWORD>(Cand) + 0x20;
		DWORD Tmp = Utility::ReadMemoryEx<DWORD>(Eng) + 0x200;

		float v1, v2, v3, v4;
		v1 = Utility::ReadMemoryEx<float>(Tmp + 0x8);
		v2 = Utility::ReadMemoryEx<float>(Tmp + 0x18);
		v3 = Utility::ReadMemoryEx<float>(Tmp + 0x28);
		v4 = Utility::ReadMemoryEx<float>(Tmp + 0x38);

		if (v1 == 0 && v2 == 0 && v3 == 0 && v4 >= 3)
		{
			ViewMatrixBase = Cand;
			FoundedBase.clear();
			break;
		}
	}

	FoundedBase.clear();*/
	return ViewMatrixBase;
}

DWORD Data::GetViewMatrixBase(DWORD StartAddress, DWORD EndAddress)
{
	DWORD ViewMatrixBase = 0;
	std::vector<DWORD_PTR> FoundedBase;
	Utility::MemSearch(ViewMatrixSearch, sizeof(ViewMatrixSearch), StartAddress, EndAddress, 0, 0, FoundedBase);

	for (int i = 0; i < FoundedBase.size(); i++)
	{
		DWORD Cand = FoundedBase[i] - 0x20;
		DWORD Eng = Utility::ReadMemoryEx<DWORD>(Cand) + 0x20;
		DWORD Tmp = Utility::ReadMemoryEx<DWORD>(Eng) + 0x200;

		float v1, v2, v3, v4;
		v1 = Utility::ReadMemoryEx<float>(Tmp + 0x8);
		v2 = Utility::ReadMemoryEx<float>(Tmp + 0x18);
		v3 = Utility::ReadMemoryEx<float>(Tmp + 0x28);
		v4 = Utility::ReadMemoryEx<float>(Tmp + 0x38);

		if (v1 == 0 && v2 == 0 && v3 == 0 && v4 >= 3)
		{
			ViewMatrixBase = Cand;
			FoundedBase.clear();
			break;
		}
	}

	FoundedBase.clear();
	return ViewMatrixBase;
}

string GetString(DWORD BaseAddress)
{
	char* String = new char[34];
	for (int i = 0; i < 34; i++)
	{
		String[i] = Utility::ReadMemoryEx<char>(BaseAddress + i);
	}

	string Result = String;

	delete[] String;
	return Result;
}

string GetEntityTypeo(LONG GNames, LONG Id)
{
	string Result = "";

	DWORD GName = Utility::ReadMemoryEx<DWORD>(GNames);

	if (Id > 0 && Id < 2000000)
	{
		DWORD Page = Id / 16384;
		DWORD Index = Id % 16384;
		DWORD SecPartAddv = Utility::ReadMemoryEx<DWORD>(GName + Page * 4);

		if (SecPartAddv > 0)
		{
			LONG NameAddv = Utility::ReadMemoryEx<DWORD>(SecPartAddv + Index * 4);

			if (NameAddv > 0)
			{
				Result = GetString(NameAddv + 0x8);
			}
		}
	}

	return Result;
}

std::string GetEntityType(DWORD gNames, int id)
{

	//auto gname = Utility::ReadMemoryEx<DWORD>(Utility::ReadMemoryEx<DWORD>(gNames) + 0x80);
//	auto fNamePtr = Utility::ReadMemoryEx<DWORD>(gNames + int(id / 16384) * 0x4);
	auto fName = Utility::ReadMemoryEx<DWORD>(gNames + int(id % 16384) * 0x4);
	auto entryOffset = fName + 0x8;
	auto nameEntry = Utility::ReadMemoryEx<INT16>(entryOffset);

	auto nameLength = nameEntry >> 6;
	char buff[1028]{};

	if ((uint32_t)nameLength && nameLength > 0)
	{
		ReadProcessMemory(Game::hProcess, LPCVOID(entryOffset), buff, nameLength, 0);

		buff[nameLength] = '\0';

		std::string name_str(buff, nameLength);

		return name_str.c_str();
	}
	else
		return "";

	return "";
}

struct ObjectName
{
	char Data[64];
};

string GetEntityType2(LONG GNames, LONG Id)
{
	DWORD GName = Utility::ReadMemoryEx<DWORD>(GNames);
	DWORD NamePtr = Utility::ReadMemoryEx<DWORD>(GName + int(Id / 16384) * 0x4);
	DWORD Name = Utility::ReadMemoryEx<DWORD>(NamePtr + int(Id % 16384) * 0x4);
	ObjectName pBuffer = Utility::ReadMemoryEx<ObjectName>(Name + 0x8);

	return string(pBuffer.Data);
}

std::string GetPlayerNameUTF(uint32_t entityAddv)
{
	wchar_t szChar[64] = { '\0' };

	ReadProcessMemory(Game::hProcess, (void*)(entityAddv), &szChar, sizeof(szChar), NULL);

	std::wstring_convert<std::codecvt_utf8<wchar_t>> utf8_conv;
	return utf8_conv.to_bytes(szChar);



}

string GetPlayerName(DWORD BaseAddress)
{
	char* String = new char[34];
	for (int i = 0; i < 34; i++)
	{
		String[i] = Utility::ReadMemoryEx<char>(BaseAddress + i * 2);
	}

	string Name = String;

	delete[] String;
	return Name;
}

string GetPlayerFlag(DWORD BaseAddress)
{
	char* String = new char[34];
	for (int i = 0; i < 34; i++)
	{
		String[i] = Utility::ReadMemoryEx<char>(BaseAddress + i * 2);
	}

	string Name = String;

	delete[] String;
	return Name;
}

BOOL IsPlayer(string str)
{
	if (Setting::TrainingGrounds_ModelEsp)
	{
		if (str.find("BP_PlayerPawn") != std::string::npos
			|| str.find("PlayerCharacter") != std::string::npos
			|| str.find("PlanET_FakePlayer") != std::string::npos
			|| str.find("BP_PlayerPawn_FM_C") != std::string::npos
			|| str.find("BP_PlayerPawn_C") != std::string::npos
			|| str.find("BP_PlayerPawn_Rune_C") != std::string::npos
			|| str.find("PlayerPawn_Infec_InvisibleZombie_C") != std::string::npos
			|| str.find("PlayerPawn_Infec_Human_C") != std::string::npos
			|| str.find("BP_PlayerPawn_ZombieBase_C") != std::string::npos
			|| str.find("BP_PlayerPawn_TDM_TPP_C") != std::string::npos
			|| str.find("BP_PlayerPawn_FM_Bot_C") != std::string::npos
			|| str.find("BP_PlayerCharacter_SlayTheBot_C") != std::string::npos
			|| str.find("PlanET_FakePlayer_AIPawn_C") != std::string::npos
			|| str.find("BP_PlayerPawn_SI_C") != std::string::npos
			|| str.find("BP_PlayerPawn_Heavy_C") != std::string::npos
			|| str.find("PlayerPawn_Infec_Revenger_C") != std::string::npos
			|| str.find("PlayerPawn_Infec_NormalZombie_C") != std::string::npos
			|| str.find("PlayerPawn_Infec_KingZombie_C") != std::string::npos
			|| str.find("BP_PlayerCharacter_PlanA_C") != std::string::npos
			|| str.find("BP_CharacterModelTaget_C") != std::string::npos)
		{
			return true;
		}

		return FALSE;
	}
	else
	{
		if (str.find("BP_PlayerPawn") != std::string::npos
			|| str.find("PlayerCharacter") != std::string::npos
			|| str.find("PlanET_FakePlayer") != std::string::npos
			|| str.find("BP_PlayerPawn_FM_C") != std::string::npos
			|| str.find("BP_PlayerPawn_C") != std::string::npos
			|| str.find("BP_PlayerPawn_Rune_C") != std::string::npos
			|| str.find("PlayerPawn_Infec_InvisibleZombie_C") != std::string::npos
			|| str.find("PlayerPawn_Infec_Human_C") != std::string::npos
			|| str.find("BP_PlayerPawn_ZombieBase_C") != std::string::npos
			|| str.find("BP_PlayerPawn_TDM_TPP_C") != std::string::npos
			|| str.find("BP_PlayerPawn_FM_Bot_C") != std::string::npos
			|| str.find("BP_PlayerCharacter_SlayTheBot_C") != std::string::npos
			|| str.find("PlanET_FakePlayer_AIPawn_C") != std::string::npos
			|| str.find("BP_PlayerPawn_SI_C") != std::string::npos
			|| str.find("BP_PlayerPawn_Heavy_C") != std::string::npos
			|| str.find("PlayerPawn_Infec_Revenger_C") != std::string::npos
			|| str.find("PlayerPawn_Infec_NormalZombie_C") != std::string::npos
			|| str.find("PlayerPawn_Infec_KingZombie_C") != std::string::npos
			|| str.find("BP_PlayerCharacter_PlanA_C") != std::string::npos

			//|| str.find("BP_PlayerLobbyPawn_C") != std::string::npos
			//|| str.find("Lobby_Main_int_C") != std::string::npos
			/*|| str.find("BP_CharacterModelTaget_C") != std::string::npos*/)
		{
			return true;
		}

		return FALSE;
	}
}

std::string GetGrenadeType(std::string classname)
{
	if (classname.find("BP_Grenade_Smoke_C") != std::string::npos)
		return "Smoke";
	if (classname.find("BP_Grenade_Burn_C") != std::string::npos)
		return "Burn";
	if (classname.find("BP_Grenade_Stun_C") != std::string::npos)
		return "[ALERT] !Flash Granade";
	if (classname.find("BP_Grenade_Shoulei") != std::string::npos)
		if (classname.find("BP_Grenade_Shoulei_C") != std::string::npos)
			return "Frag";
	if (classname.find("AirAttackBomb") != std::string::npos)
		return "Air Bomb !";
	//if (classname.find("BP_Rifle_M416_Wrapper_C") != std::string::npos)
	//	return "M416.";
	return "noooooooot";
}

string GetItemType(string Name)
{
	if (Setting::Esp_Item_AKM) if (Name.find("BP_Rifle_AKM_Wrapper_C") != std::string::npos) return "AKM";
	if (Setting::Esp_Item_M249) if (Name.find("BP_Other_M249_Wrapper_C") != std::string::npos)return "M249";

	if (Setting::Esp_Item_Mk12) if (Name.find("BP_Other_MK12_Wrapper_C") != std::string::npos)return "MK12";
	if (Setting::plan)  if (Name.find("AirDropPlane") != std::string::npos) return "[AIR-PLANE]";
	if (Name.find("BP_MVP_Statue_C") != std::string::npos) return "[MVP-STATUE]";


	if (Setting::Esp_Item_SCARL) if (Name.find("BP_Rifle_SCAR_Wrapper_C") != string::npos) return "SCAR-L";
	if (Setting::Esp_Item_M416) if (Name.find("BP_Rifle_M416_Wrapper_C") != std::string::npos) return "M416";
	if (Setting::Esp_Item_M24) if (Name.find("BP_Sniper_M24_Wrapper_C") != string::npos) return "M24";
	if (Setting::Esp_Item_Kar98k) if (Name.find("BP_Sniper_Kar98k_Wrapper_C") != string::npos) return "Kar98k";
	if (Setting::Esp_Item_Awm) if (Name.find("BP_Sniper_AWM_Wrapper_C") != string::npos) return "AWM";

	if (Setting::Esp_Item_SniperAMR) if (Name.find("BP_Sniper_AMR_Wrapper_C") != string::npos) return "Sniper-AMR";
	if (Setting::Esp_Item_BulletAMR) if (Name.find("BP_Ammo_50BMG_Pickup_C") != string::npos) return "Ammo-50BMG";

	if (Setting::Esp_Item_FlareGun) if (Name.find("BP_Pistol_Flaregun_Wrapper_C") != string::npos) return "Flare Gun";
	if (Setting::Esp_Item_Flare) if (Name.find("BP_Ammo_Flare_Pickup_C") != string::npos) return "Flare";


	if (Setting::Esp_Item_M762) if (Name.find("BP_Rifle_M762_Wrapper_C") != string::npos) return "M762";
	if (Setting::Esp_Item_Mk47Mutant) if (Name.find("BP_Rifle_Mk47_Wrapper_C") != string::npos) return "Mk47 Mutant";
	if (Setting::Esp_Item_DP28) if (Name.find("BP_Other_DP28_Wrapper_C") != string::npos) return "DP28";

	if (Setting::Esp_Item_M16A4) if (Name.find("BP_Rifle_M16A4_Wrapper_C") != string::npos) return "M16A4";
	if (Setting::Esp_Item_G36C) if (Name.find("BP_Rifle_G36_Wrapper_C") != string::npos) return "G36C";
	if (Setting::Esp_Item_QBZ) if (Name.find("BP_Rifle_QBZ_Wrapper_C") != string::npos) return "QBZ";

	if (Setting::Esp_Item_QBU) if (Name.find("BP_Sniper_QBU_Wrapper_C") != string::npos) return "QBU";
	if (Setting::Esp_Item_SLR) if (Name.find("BP_Sniper_SLR_Wrapper_C") != string::npos) return "SLR";
	if (Setting::Esp_Item_SKS) if (Name.find("BP_Sniper_SKS_Wrapper_C") != string::npos) return "SKS";
	if (Setting::Esp_Item_Mini14) if (Name.find("BP_Sniper_Mini14_Wrapper_C") != string::npos) return "Mini-14";


	if (Setting::Esp_Item_PP19) if (Name.find("BP_MachineGun_PP19_Wrapper_C") != string::npos) return "PP19";
	if (Setting::Esp_Item_TommyGun) if (Name.find("BP_MachineGun_TommyGun_Wrapper_C") != string::npos) return "Tommy Gun";
	if (Setting::Esp_Item_MP5K) if (Name.find("BP_MachineGun_MP5K_Wrapper_C") != string::npos) return "MP5K";
	if (Setting::Esp_Item_UMP9) if (Name.find("BP_MachineGun_UMP9_Wrapper_C") != string::npos) return "UMP9";
	if (Setting::Esp_Item_Vector) if (Name.find("BP_MachineGun_Vector_Wrapper_C") != string::npos) return "Vector";
	if (Setting::Esp_Item_Uzi) if (Name.find("BP_MachineGun_Uzi_Wrapper_C") != string::npos) return "Uzi";
	if (Setting::Esp_Item_Awmimo) if (Name.find("BP_Ammo_300Magnum_Pickup_C") != std::string::npos) return "300Magnum";
	if (Setting::Esp_Item_762mm) if (Name.find("BP_Ammo_762mm_Pickup_C") != string::npos) return "7.62mm";
	if (Setting::Esp_Item_556mm) if (Name.find("BP_Ammo_556mm_Pickup_C") != string::npos) return "5.56mm";
	if (Setting::Esp_Item_9mm) if (Name.find("BP_Ammo_9mm_Pickup_C") != string::npos) return "9mm";
	if (Setting::Esp_Item_45ACP) if (Name.find("BP_Ammo_45ACP_Pickup_C") != string::npos) return "45ACP";

	if (Setting::Esp_Item_Holo) if (Name.find("BP_MZJ_QX_Pickup_C") != string::npos) return "Holo";


	//if (Setting::Esp_Item_AirDrop) if (Name.find("BP_AirDropBox_C") != string::npos || Name.find("BP_AirDropBox_New_C") != std::string::npos || Name == "AirDropListWrapperActor") return "Air Drop";
	if (Setting::Esp_Item_AirDrop) if (Name.find("BP_AirDropBox") != string::npos || Name.find("BP_AirDropBox_C") != string::npos || Name.find("BP_AirDropBox_New_C") != std::string::npos || Name.find("BP_AirDropBox_C_Recycled") != std::string::npos || Name.find("PlayerDeadInventoryBox") != std::string::npos || Name == "AirDropListWrapperActor") return "Air Drop";
	//if (Setting::Esp_Item_AirDrop) if (Name.find("BP_AirDropBox") != string::npos) return "[Air-Drop]";
	if (Setting::Esp_Item_MedKit) if (Name.find("FirstAidbox_Pickup_C") != string::npos) return "Med Kit";
	if (Setting::Esp_Item_FirstAidKit) if (Name.find("Firstaid_Pickup_C") != string::npos) return "First Aid Kit";
	if (Setting::Esp_Item_Bandage) if (Name.find("Bandage_Pickup_C") != string::npos) return "Bandage";
	if (Setting::Esp_Item_Painkiller) if (Name.find("Pills_Pickup_C") != string::npos) return "Painkiller";
	if (Setting::Esp_Item_EnergyDrink) if (Name.find("Drink_Pickup_C") != string::npos) return "Energy Drink";
	if (Setting::Esp_Item_AdrenalineSyringe) if (Name.find("Injection_Pickup_C") != string::npos) return "Adrenaline Syringe";

	if (Setting::Esp_Item_Frag) if (Name.find("BP_Grenade_Shoulei_Weapon_Wrapper_C") != string::npos) return "frag";
	if (Setting::Esp_Item_Frag) if (Name.find("BP_Grenade_Shoulei_C") != string::npos) return "Frag";
	if (Setting::Esp_Item_Smoke) if (Name.find("BP_Grenade_Smoke_Weapon_Wrapper_C") != string::npos) return "Smoke";
	if (Setting::Esp_Item_Molotof) 	if (Name.find("BP_Grenade_Burn_C") != std::string::npos)return "Burn";

	if (Setting::Esp_Item_Molotof) if (Name.find("BP_Grenade_Burn_Weapon_Wrapper_C") != string::npos) return "Molotof";

	if (Setting::Esp_Item_Helmet1) if (Name.find("PickUp_BP_Helmet_Lv1") != string::npos) return "Helmet L.1";
	if (Setting::Esp_Item_Helmet2) if (Name.find("PickUp_BP_Helmet_Lv2") != string::npos) return "Helmet L.2";
	if (Setting::Esp_Item_Helmet3) if (Name.find("PickUp_BP_Helmet_Lv3") != string::npos) return "Helmet L.3";

	if (Setting::Esp_Item_Armor1) if (Name.find("PickUp_BP_Armor_Lv1") != string::npos) return "Armor L.1";
	if (Setting::Esp_Item_Armor2) if (Name.find("PickUp_BP_Armor_Lv2") != string::npos) return "Armor L.2";
	if (Setting::Esp_Item_Armor3) if (Name.find("PickUp_BP_Armor_Lv3") != string::npos) return "Armor L.3";
	if (Setting::Esp_Item_x2) if (Name.find("BP_MZJ_2X_Pickup_C") != string::npos) return "2x";
	if (Setting::Esp_Item_x3) if (Name.find("BP_MZJ_3X_Pickup_C") != string::npos) return "3x";
	if (Setting::Esp_Item_x4) if (Name.find("BP_MZJ_4X_Pickup_C") != string::npos) return "4x";
	if (Setting::Esp_Item_x6) if (Name.find("BP_MZJ_6X_Pickup_C") != string::npos) return "6x";
	if (Setting::Esp_Item_x8) if (Name.find("BP_MZJ_8X_Pickup_C") != string::npos) return "8x";
	if (Setting::Esp_Item_Bag1) if (Name.find("PickUp_BP_Bag_Lv1") != string::npos) return "Bag L.1";
	if (Setting::Esp_Item_Bag2) if (Name.find("PickUp_BP_Bag_Lv2") != string::npos) return "Bag L.2";
	if (Setting::Esp_Item_Bag3) if (Name.find("PickUp_BP_Bag_Lv3") != string::npos) return "Bag L.3";
	if (Setting::Esp_Item_exquic) if (Name.find("BP_DJ_Large_EQ_Pickup_C") != string::npos) return "Extended QuickDraw";

	if (Setting::token)if (Name.find("GoldenTokenWrapper_C") != string::npos) return "Shop Token";
	if (Setting::BP_QK_Choke_Pickup_C_1) if (Name.find("BP_QK_Choke_Pickup_C") != string::npos) return "Choke";
	if (Setting::BP_QK_Mid_Compensator_Pickup_C_1) if (Name.find("BP_QK_Mid_Compensator_Pickup_C") != string::npos) return "Compensator (SMG)";
	if (Setting::BP_QK_Sniper_Compensator_Pickup_C_1) if (Name.find("BP_QK_Sniper_Compensator_Pickup_C") != string::npos) return "Compensator (Snipers)";
	if (Setting::BP_QK_Mid_FlashHider_Pickup_C_1) if (Name.find("BP_QK_Mid_FlashHider_Pickup_C") != string::npos) return "Flash Hider (SMG)";
	if (Setting::BP_QK_Sniper_FlashHider_Pickup_C_1) if (Name.find("BP_QK_Sniper_FlashHider_Pickup_C") != string::npos) return "Flash Hider (Snipers)";
	if (Setting::BP_QK_Mid_Suppressor_Pickup_C_1) if (Name.find("BP_QK_Mid_Suppressor_Pickup_C") != string::npos) return "Suppressor (SMG)";
	if (Setting::BP_QK_Sniper_Suppressor_Pickup_C_1) if (Name.find("BP_QK_Sniper_Suppressor_Pickup_C") != string::npos) return "Suppressor (Snipers)";
	if (Setting::BP_QK_Large_Compensator_Pickup_C_1) if (Name.find("BP_QK_Large_Compensator_Pickup_C") != string::npos) return "Compensator (AR)";
	if (Setting::BP_QK_Large_FlashHider_Pickup_C_1) if (Name.find("BP_QK_Large_FlashHider_Pickup_C") != string::npos) return "Flash Hider (AR)";
	if (Setting::BP_QK_Large_Suppressor_Pickup_C_1) if (Name.find("BP_QK_Large_Suppressor_Pickup_C") != string::npos) return "Suppressor (AR)";
	if (Setting::BP_QK_DuckBill_Pickup_C_1) if (Name.find("BP_QK_DuckBill_Pickup_C") != string::npos) return "Duckbill (Shotguns)";
	if (Setting::BP_WB_Angled_Pickup_C_1) if (Name.find("BP_WB_Angled_Pickup_C") != string::npos) return "Angled Foregrip";
	if (Setting::BP_WB_Vertical_Pickup_C_1) if (Name.find("BP_WB_Vertical_Pickup_C") != string::npos) return "Vertical Foregrip";
	if (Setting::BP_WB_LightGrip_Pickup_C_1) if (Name.find("BP_WB_LightGrip_Pickup_C") != string::npos) return "Light Grip";
	if (Setting::BP_WB_HalfGrip_Pickup_C_1) if (Name.find("BP_WB_HalfGrip_Pickup_C") != string::npos) return "Half Grip";
	if (Setting::BP_WB_ThumbGrip_Pickup_C_1) if (Name.find("BP_WB_ThumbGrip_Pickup_C") != string::npos) return "Thumb Grip";
	if (Setting::BP_WB_Lasersight_Pickup_C_1) if (Name.find("BP_WB_Lasersight_Pickup_C") != string::npos) return "Laser Sight";
	if (Setting::BP_MZJ_SideRMR_Pickup_C_1) if (Name.find("BP_MZJ_SideRMR_Pickup_C") != string::npos) return "Canted Sight";
	if (Setting::BP_ZDD_Sniper_Pickup_C_1) if (Name.find("BP_ZDD_Sniper_Pickup_C") != string::npos) return "Bullet Loop (Shotguns, Sniper Rifles)	";
	if (Setting::BP_QT_UZI_Pickup_C_1) if (Name.find("BP_QT_UZI_Pickup_C") != string::npos) return "Stock (Micro UZI)";
	if (Setting::BP_QT_A_Pickup_C_1) if (Name.find("BP_QT_A_Pickup_C") != string::npos) return "Tactical Stock (Rifles, SMG)";
	if (Setting::BP_QT_Sniper_Pickup_C_1) if (Name.find("BP_QT_Sniper_Pickup_C") != string::npos) return "Cheek Pad (Snipers)";
	if (Setting::BP_ZDD_Crossbow_Q_Pickup_C_1) if (Name.find("BP_ZDD_Crossbow_Q_Pickup_C") != string::npos) return "Quiver (Crossbow)";
	if (Setting::BP_DJ_Mid_E_Pickup_C_1) if (Name.find("BP_DJ_Mid_E_Pickup_C") != string::npos) return "Extended Mag (SMG, Pistols)";
	if (Setting::BP_DJ_Mid_Q_Pickup_C_1) if (Name.find("BP_DJ_Mid_Q_Pickup_C") != string::npos) return "Quickdraw Mag (SMG, Pistols)";
	if (Setting::BP_DJ_Mid_EQ_Pickup_C_1) if (Name.find("BP_DJ_Mid_EQ_Pickup_C") != string::npos) return "Extended Quickdraw Mag (SMG, Pistols)";
	if (Setting::BP_DJ_Sniper_E_Pickup_C_1) if (Name.find("BP_DJ_Sniper_E_Pickup_C") != string::npos) return "Extended Mag (Snipers)";
	if (Setting::BP_DJ_Sniper_Q_Pickup_C_1) if (Name.find("BP_DJ_Sniper_Q_Pickup_C") != string::npos) return "Quickdraw Mag (Snipers)";
	if (Setting::BP_DJ_Sniper_EQ_Pickup_C_1) if (Name.find("BP_DJ_Sniper_EQ_Pickup_C") != string::npos) return "Extended Quickdraw Mag (Snipers)";
	if (Setting::BP_DJ_Large_E_Pickup_C_1) if (Name.find("BP_DJ_Large_E_Pickup_C") != string::npos) return "Extended Quickdraw Mag (AR)";
	if (Setting::BP_DJ_Large_Q_Pickup_C_1) if (Name.find("BP_DJ_Large_Q_Pickup_C") != string::npos) return "Quickdraw Mag (AR)";
	if (Setting::BP_DJ_Large_EQ_Pickup_C_1) if (Name.find("BP_DJ_Large_EQ_Pickup_C") != string::npos) return "Extended Quickdraw Mag";

	//----------------------------PISTOLS-----------------------//

	if (Setting::BP_Pistol_P92_Wrapper_C_1) if (Name.find("BP_Pistol_P92_Wrapper_C") != string::npos) return "P92";
	if (Setting::BP_Pistol_P1911_Wrapper_C_1) if (Name.find("BP_Pistol_P1911_Wrapper_C") != string::npos) return "P1911";
	if (Setting::BP_Pistol_R1895_Wrapper_C_1) if (Name.find("BP_Pistol_R1895_Wrapper_C") != string::npos) return "R1895";
	if (Setting::BP_Pistol_P18C_Wrapper_C_1) if (Name.find("BP_Pistol_P18C_Wrapper_C") != string::npos) return "P18C";
	if (Setting::BP_Pistol_R45_Wrapper_C_1) if (Name.find("BP_Pistol_R45_Wrapper_C") != string::npos) return "R45";
	if (Setting::BP_Pistol_Vz61_Wrapper_C_1) if (Name.find("BP_Pistol_Vz61_Wrapper_C") != string::npos) return "Vz61";
	if (Setting::BP_Pistol_DesertEagle_Wrapper_C_1) if (Name.find("BP_Pistol_DesertEagle_Wrapper_C") != string::npos) return "Desert Eagle";
	if (Setting::BP_ShotGun_SawedOff_Wrapper_C_1) if (Name.find("BP_ShotGun_SawedOff_Wrapper_C") != string::npos) return "Sawed-off";
	///////////////////////////////////////////////////////////////
	if (Setting::BP_ShotGun_S686_Wrapper_C_1) if (Name.find("BP_ShotGun_S686_Wrapper_C") != string::npos) return   "S686";
	if (Setting::BP_ShotGun_S1897_Wrapper_C_1) if (Name.find("BP_ShotGun_S1897_Wrapper_C") != string::npos) return "S1897";
	if (Setting::BP_ShotGun_S12K_Wrapper_C_1) if (Name.find("BP_ShotGun_S12K_Wrapper_C") != string::npos) return   "S12K";
	if (Setting::BP_ShotGun_DP12_Wrapper_C_1) if (Name.find("BP_ShotGun_DP12_Wrapper_C") != string::npos) return   "DP12";
	if (Setting::BP_ShotGun_M1014_Wrapper_C_1) if (Name.find("BP_ShotGun_M1014_Wrapper_C") != string::npos) return "M1014 Shotgun";

	//---------------------------------------------------//
	if (Setting::BP_WEP_Machete_Pickup_C_1) if (Name.find("BP_WEP_Machete_Pickup_C") != string::npos) return   "Machete";
	if (Setting::BP_WEP_Cowbar_Pickup_C_1) if (Name.find("BP_WEP_Cowbar_Pickup_C") != string::npos) return   "Crowbar";
	if (Setting::BP_WEP_Sickle_Pickup_C_1) if (Name.find("BP_WEP_Sickle_Pickup_C") != string::npos) return   "Sickle";
	if (Setting::BP_WEP_Pan_Pickup_C_1) if (Name.find("BP_WEP_Pan_Pickup_C") != string::npos) return   "Pan";
	///////////////////////////////////////////////////////////////

	if (Setting::playerdeadbox) if (Name.find("PlayerDeadBox_C") != string::npos || Name.find("PlayerTombBox_NG_C") != string::npos) return "Death Box";

	//if (Setting::deadbox) if (Name.find("PlayerDeadInventoryBox") != std::string::npos || Name.find("PickUpListWrapperActor") != std::string::npos || Name.find("PlayerTombBox_NG_C") != std::string::npos || Name.find("PlayerDeadBox_C") != std::string::npos) return "Dead-Box1";
	
	if (Setting::UselessShow) 
	{
		cout << Name << endl;
		return Name;
	}
	else 
{
		return "Unknown";
	}


}
bool IsBox(std::string classname)
{
	/*if (classname.find("PickUpListWrapperActor") != std::string::npos)
		return true;
	else if (classname.find("BP_AirDropBox") != std::string::npos)
		return true;
	else	if (classname.find("Treasure") != std::string::npos)
		return true;
	else	if (classname.find("PlayerDeadBox_C") != std::string::npos || classname.find("PlayerTombBox_NG_C") != std::string::npos)
		return true;
	else	if (classname.find("AirDropListWrapperActor") != std::string::npos)
		return true;

	return false;*/
	if (classname.find("PickUpListWrapperActor") != std::string::npos || classname.find("AirDropListWrapperActor") != std::string::npos || classname.find("PlayerTombBox_NG_C") != std::string::npos)
		return true;

	return false;
}
bool IsAirBox(std::string classname)
{
	/*if (classname.find("BP_AirDropBox_C") != std::string::npos || classname.find("BP_AirDropBox_New_C") != std::string::npos)
		return true;

	if (classname.find("AirDropListWrapperActor") != std::string::npos)
		return true;
	return false;*/
}
bool IsTreasureBox(std::string classname)
{
	/*if (classname.find("TreasureBox") != std::string::npos)
		return true;


	return false;*/
}
string GetVehicleType(string Name)
{
	if (Name.find("BRDM") != std::string::npos) return "BRDM";
	if (Name.find("Scooter") != std::string::npos) return "Scooter";
	if (Name.find("Snowbike") != std::string::npos) return "SnowBike";
	if (Name.find("Motorcycle") != std::string::npos) return "Motorcycle";
	if (Name.find("Snowmobile") != std::string::npos) return "Snowmobile";
	if (Name.find("VH_Snowbike_C") != std::string::npos) return "SnowBike";
	if (Name.find("BP_Bike_WithRack") != std::string::npos || Name.find("BP_Bike_WithRack_SI_C") != std::string::npos || Name.find("BP_Bike_WithRack_Pickable_C") != std::string::npos || Name.find("PickUp_BP_Bike_WithRack_C") != std::string::npos || Name.find("PickUp_BP_Bike_WithRack1_C") != std::string::npos || Name.find("PickUp_BP_Bike_WithRack2_C") != std::string::npos) return "Bike";
	if (Name.find("Tuk") != std::string::npos) return "Tuk Tuk";
	if (Name.find("Buggy") != std::string::npos) return "Buggy";
	if (Name.find("open") != std::string::npos) return "Sports";
	if (Name.find("close") != std::string::npos) return "Sportsa";
	if (Name.find("Dacia") != std::string::npos) return "Dacia";
	if (Name.find("Rony") != std::string::npos) return "Rony";
	if (Name.find("UAZ") != std::string::npos) return "UAZ";
	if (Name.find("MiniBus") != std::string::npos) return "Minibus";
	if (Name.find("PG117") != std::string::npos) return "Ship";
	if (Name.find("AquaRail") != std::string::npos) return "Boat";
	if (Name.find("Bigfoot") != std::string::npos) return "Monster Truck";
	if (Name.find("CoupeRB") != std::string::npos) return "Coupe-RB";
	if (Name.find("Mirado_open") != std::string::npos) return "Mirado";
	if (Name.find("PickUp_07_C") != std::string::npos) return "PickUp Truck";
	if (Name.find("Motorglider") != std::string::npos) return "Motorglider";
	if (Name.find("wing_Vehicle") != std::string::npos) return "Helicopter";
	if (Name.find("UTV") != std::string::npos) return "UTV";
	if (Name.find("ATV") != std::string::npos) return "Quad";
	if (Name.find("VH_") != std::string::npos) return Name;


	return "Unknown";
}
std::string GetBoxItems0(int code)
{
	if (code == 103003)
	{
		Setting::colorcode = weapon1::AWM;
		return "AWM";
	}
	else if (code == 103002)
	{
		Setting::colorcode = weapon1::M24;
		return "M24";
	}
	else if (code == 103001)
	{
		Setting::colorcode = weapon1::kar98;
		return "Kar-98k";
	}
	else if (code == 103011)
	{
		Setting::colorcode = Colors1::mosin;
		return "Mosin";
	}
	else if (code == 103012)
	{
		Setting::colorcode = Colors1::mosin;
		return "AMR";
	}
	else if (code == 103004)
	{
		Setting::colorcode = weapon1::M24;
		return "SKS";
	}
	else if (code == 103007)
	{
		Setting::colorcode = weapon1::M24;
		return "Mk14";
	}
	else if (code == 103010)
	{
		Setting::colorcode = weapon1::M24;
		return "QBU";
	}
	else if (code == 103009)
	{
		Setting::colorcode = weapon1::M24;
		return "SLR";
	}
	else if (code == 103006)
	{
		Setting::colorcode = weapon1::M24;
		return "Mini-14";
	}
	else if (code == 103005)
	{
		Setting::colorcode = weapon1::M24;
		return "VSS";
	}
	else if (code == 103008)
	{
		Setting::colorcode = weapon1::M24;
		return "Win-94";
	}
	//
	else if (code == 101001)
	{
		Setting::colorcode = weapon1::AKM;
		return "AKM";
	}
	else if (code == 101008)
	{
		Setting::colorcode = weapon1::m762;
		return "M762";
	}
	else if (code == 105002)
	{
		Setting::colorcode = Colors1::dp;
		return "DP28";
	}
	else if (code == 101005)
	{
		Setting::colorcode = weapon1::GROZZA;
		return "Groza";
	}
	else if (code == 101009)
	{
		Setting::colorcode = weapon1::GROZZA;
		return "Mk47";
	}
	//
	else if (code == 101004)
	{
		Setting::colorcode = weapon1::m16;
		return "M416";
	}
	else if (code == 101003)
	{
		Setting::colorcode = weapon1::scarl;
		return "SCAR-L";
	}
	else if (code == 101002)
	{
		Setting::colorcode = weapon1::scarl;
		return "M16A-4";
	}
	else if (code == 101010)
	{
		Setting::colorcode = Colors1::g36c;
		return "G36C";
	}
	else if (code == 101006)
	{
		Setting::colorcode = Colors1::aug;
		return "AUG-A3";
	}
	else if (code == 101007)
	{
		Setting::colorcode = Colors1::aug;
		return "QBZ";
	}
	else if (code == 101101)
	{
		Setting::colorcode = Colors1::assm;
		return "ASM";
	}
	else if (code == 105001)
	{
		Setting::colorcode = Colors1::M249Color;
		return "M249";
	}
	else if (code == 105010)
	{
		Setting::colorcode = Colors1::mg3;
		return "MG3";
	}
	else if (code == 106007)
	{
		Setting::colorcode = weapon1::Flare;
		return "Flaregun";
	}
	//
	else if (code == 104003)
	{
		Setting::colorcode = weapon1::Flare;
		return "S12K";
	}
	else if (code == 104004)
	{
		Setting::colorcode = weapon1::Flare;
		return "DBS";
	}
	else if (code == 104001)
	{
		Setting::colorcode = weapon1::Flare;
		return "S686";
	}
	else if (code == 104002)
	{
		Setting::colorcode = weapon1::Flare;
		return "S1897";
	}
	else if (code == 106006)
	{
		Setting::colorcode = weapon1::Flare;
		return "Sawed-Off";
	}
	//
	else if (code == 102005)
	{
		Setting::colorcode = weapon1::Flare;
		return "PP19Bizon";
	}
	else if (code == 102004)
	{
		Setting::colorcode = weapon1::Flare;
		return "TommyGun";
	}
	else if (code == 102007)
	{
		Setting::colorcode = weapon1::Flare;
		return "MP5K";
	}
	else if (code == 102002)
	{
		Setting::colorcode = weapon1::Flare;
		return "UMP9";
	}
	else if (code == 102003)
	{
		Setting::colorcode = weapon1::Flare;
		return "Vector";
	}
	else if (code == 102001)
	{
		Setting::colorcode = weapon1::Flare;
		return "Uzi";
	}
	//
	else if (code == 106003)
	{
		Setting::colorcode = weapon1::Flare;
		return "R1895";
	}
	else if (code == 106008)
	{
		Setting::colorcode = weapon1::Flare;
		return "Vz61";
	}
	else if (code == 106001)
	{
		Setting::colorcode = weapon1::Flare;
		return "P92";
	}
	else if (code == 106004)
	{
		Setting::colorcode = weapon1::Flare;
		return "P18C";
	}
	else if (code == 106005)
	{
		Setting::colorcode = weapon1::Flare;
		return "R45";
	}
	else if (code == 106002)
	{
		Setting::colorcode = weapon1::Flare;
		return "P1911";
	}
	else if (code == 106010)
	{
		Setting::colorcode = weapon1::Flare;
		return "Desert-Eagle";
	}
	//
	else if (code == 108003)
	{
		Setting::colorcode = weapon1::Flare;
		return "Sickle";
	}
	else if (code == 108001)
	{
		Setting::colorcode = weapon1::Flare;
		return "Machete";
	}
	else if (code == 107001)
	{
		Setting::colorcode = weapon1::Flare;
		return "CrossBow";
	}
	else if (code == 108004)
	{
		Setting::colorcode = weapon1::Flare;
		return "Pan";
	}
	//
	else if (code == 303001)
	{
		Setting::colorcode = Colors1::ammo_5_56mm;
		return "5.56";
	}
	else if (code == 302001)
	{
		Setting::colorcode = Colors1::ammo_7_62mm;
		return "7.62";
	}
	else if (code == 305001)
	{
		Setting::colorcode = Colors1::ammo_45ACP;
		return "45.ACP";
	}
	else if (code == 301001)
	{
		Setting::colorcode = Colors1::ammo_9mm;
		return "9mm";
	}
	else if (code == 304001)
	{
		Setting::colorcode = Colors1::ammo_7_62mm;
		return "12.Guage";
	}
	else if (code == 307001)
	{
		Setting::colorcode = Colors1::ammo_7_62mm;
		return "Ammo_Bolt";
	}
	else if (code == 308001)
	{
		Setting::colorcode = Colors1::ammo_Flare_Gun;
		return "Flare Ammo";
	}
	else if (code == 306001)
	{
		Setting::colorcode = weapon1::AWMimmo;
		return "AWM.Ammo";
	}
	//
	else if (code == 201004)
	{
		Setting::colorcode = Colors1::ammo_7_62mm;
		return "FlashHider (SMG)";
	}
	else if (code == 201002)
	{
		Setting::colorcode = Colors1::ammo_7_62mm;
		return "Compensator (SMG)";
	}
	else if (code == 201010)
	{
		Setting::colorcode = { ImColor(255, 0, 153, 255) };
		return "Flash Hider (AR)";
	}
	else if (code == 201009)
	{
		Setting::colorcode = { ImColor(255, 0, 153, 255) };
		return "Compensator (AR)";
	}
	else if (code == 205002)
	{
		Setting::colorcode = Colors1::ammo_7_62mm;
		return "Tactical Stock (SMG)";
	}
	else if (code == 201012)
	{
		Setting::colorcode = Colors1::ammo_7_62mm;
		return "Duckbill (Pompalı)";
	}
	else if (code == 201005)
	{
		Setting::colorcode = Colors1::ammo_7_62mm;
		return "FlashHider (Sniper)";
	}
	else if (code == 201006)
	{
		Setting::colorcode = Colors1::ammo_7_62mm;
		return "Suppressor (SMG)";
	}
	else if (code == 205003)
	{
		Setting::colorcode = Colors1::ammo_7_62mm;
		return "Chekpad Sniper";
	}
	else if (code == 201001)
	{
		Setting::colorcode = Colors1::ammo_7_62mm;
		return "Choke (SG)";
	}
	else if (code == 205001)
	{
		Setting::colorcode = Colors1::ammo_7_62mm;
		return "Dipcik (Micro Uzi)";
	}
	else if (code == 201003)
	{
		Setting::colorcode = Colors1::ammo_7_62mm;
		return "Compensator (Sniper)";
	}
	else if (code == 201007)
	{
		Setting::colorcode = Colors1::ammo_7_62mm;
		return "Suppressor (Sniper)";
	}
	else if (code == 201011)
	{
		Setting::colorcode = { ImColor(255, 0, 153, 255) };
		return "Suppressor (AR)";
	}
	else if (code == 3000331)
		return "AR Suppressor";
	//
	else if (code == 204009)
	{
		Setting::colorcode = Colors1::ammo_7_62mm;
		return "Extended Quickdraw Mag (Sniper)";
	}
	else if (code == 204004)
	{
		Setting::colorcode = Colors1::ammo_7_62mm;
		return "Uz.Haf.Sarjor";
	}
	else if (code == 204005)
	{
		Setting::colorcode = Colors1::ammo_7_62mm;
		return "Hc.Haf.Sarjor";
	}
	else if (code == 204007)
	{
		Setting::colorcode = Colors1::ammo_7_62mm;
		return "Extended Mag (Sniper)";
	}
	else if (code == 204008)
	{
		Setting::colorcode = Colors1::ammo_7_62mm;
		return "Quickdraw Mag (Sniper)";
	}
	else if (code == 204012)
	{
		Setting::colorcode = { ImColor(255, 0, 153, 255) };
		return "Quickdraw Mag (AR)";
	}
	else if (code == 204013)
	{
		Setting::colorcode = { ImColor(255, 0, 153, 255) };
		return "Extended Quickdraw Mag (AR)";
	}
	else if (code == 204011)
	{
		Setting::colorcode = { ImColor(255, 0, 153, 255) };
		return "Extended Mag (AR)";
	}
	else if (code == 204006)
	{
		Setting::colorcode = Colors1::ammo_7_62mm;
		return "Hc.Uz.Haf.Sarjor";
	}
	else if (code == 205004)
	{
		Setting::colorcode = Colors1::ammo_7_62mm;
		return "ZDD_Crossbow_Q";
	}
	else if (code == 204014)
	{
		Setting::colorcode = Colors1::ammo_7_62mm;
		return "ZDD_Sniper";
	}
	else if (code == 202006)
	{
		Setting::colorcode = Colors1::ammo_7_62mm;
		return "Thumb-Grip";
	}
	else if (code == 202004)
	{
		Setting::colorcode = Colors1::ammo_7_62mm;
		return "Light-Grip";
	}
	else if (code == 202007)
	{
		Setting::colorcode = Colors1::ammo_7_62mm;
		return "WB_Lasersight";
	}
	else if (code == 202001)
	{
		Setting::colorcode = Colors1::ammo_7_62mm;
		return "WB_Angled";
	}
	else if (code == 202002)
	{
		Setting::colorcode = Colors1::ammo_7_62mm;
		return "WB_Vertical";
	}
	//
	else if (code == 502001)
	{
		Setting::colorcode = Colors1::helmat;
		return "Helmet Lv.1";
	}
	else if (code == 502002)
	{
		Setting::colorcode = Colors1::helmat;
		return "Helmet Lv.2";
	}
	else if (code == 502003)
	{
		Setting::colorcode = Colors1::helmat;
		return "Helmet Lv.3";
	}
	//
	else if (code == 502005)
	{
		Setting::colorcode = Colors1::helmat;
		return "Helmet Lv.2";
	}
	//
	else if (code == 503001)
	{
		Setting::colorcode = Colors1::armer;
		return "Armour Lv.1";
	}
	else if (code == 503002)
	{
		Setting::colorcode = Colors1::armer;
		return "Armour Lv.2";
	}
	else if (code == 503003)
	{
		Setting::colorcode = Colors1::armer;
		return "Armour Lv.3";
	}
	//
	else if (code == 501004)
	{
		Setting::colorcode = Colors1::bag;
		return "Bag Lv.1";
	}
	else if (code == 501005)
	{
		Setting::colorcode = Colors1::bag;
		return "Bag Lv.2";
	}
	else if (code == 501006)
	{
		Setting::colorcode = Colors1::bag;
		return "Bag Lv.3";
	}
	//
	else if (code == 501001)
	{
		Setting::colorcode = Colors1::bag;
		return "Bag Lv.1";
	}
	else if (code == 501002)
	{
		Setting::colorcode = Colors1::bag;
		return "Bag Lv.2";
	}
	else if (code == 501003)
	{
		Setting::colorcode = Colors1::bag;
		return "Bag Lv.3";
	}
	//
	else if (code == 203001)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "0x Red.Dot";
	}
	else if (code == 203002)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "0x Holo";
	}
	else if (code == 203003)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "2X";
	}
	else if (code == 203014)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "3X";
	}
	else if (code == 203004)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "4x";
	}
	else if (code == 203015)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "6x";
	}
	else if (code == 203005)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "8x";
	}
	//
	else if (code == 601005)
	{
		Setting::colorcode = Colors1::Firstkit;
		return "First Aid Kit";
	}
	else if (code == 601006)
	{
		Setting::colorcode = Colors1::Madkit;
		return "Med Kit";
	}
	else if (code == 601003)
	{
		Setting::colorcode = Colors1::Painkiller;
		return "Painkiller";
	}
	else if (code == 601002)
	{
		Setting::colorcode = Colors1::AdrenalineSyringe;
		return "Adrenaline_Syringe";
	}
	else if (code == 601001)
	{
		Setting::colorcode = Colors1::EnergyDrink;
		return "Energy_Drink";
	}
	else if (code == 601004)
	{
		Setting::colorcode = Colors1::Bandage;
		return "Bandage";
	}
	else if (code == 603001)
	{
		Setting::colorcode = Colors1::Madkit;
		return "GasCan";
	}
	//
	else if (code == 602004)
	{
		Setting::colorcode = Colors1::Grenade_Color;
		return "Grenade";
	}
	else if (code == 602003)
	{
		Setting::colorcode = Colors1::Molotof_Color;
		return "Molotof";
	}
	else if (code == 602002)
	{
		Setting::colorcode = Colors1::Smoke_Color;
		return "Smoke";
	}
	else if (code == 602005)
	{
		Setting::colorcode = Colors1::Smoke_Color;
		return "Grenade_Apple";
	}
	//
	else if (code == 3000312)
		return "GameCoin";
	else if (code == 3000324)
		return "Golden Token";
	else if (code == 3000324)
		return "Acsses card";
	//

	return "tatti";
}

std::string GetBoxItems01(int code)
{
	if (code == 403989)//arctic ocean
	{
		return "Ghillie Suit";
		//Setting::colorcode = Colors::mg3;
	}
	else if (code == 403045)//woodland hills
	{
		//Setting::colorcode = Colors::mg3;
		return "Ghillie.Suit";
	}
	else if (code == 403187)//Desert
	{
		//Setting::colorcode = Colors::mg3;
		return  "Ghillie-Suit";
	}
	else if (code == 403188)//Desert
	{
		//Setting::colorcode = Colors::mg3;
		return  "Ghillie_Suit";
	}
	//

	return "tatti";
}


std::string GetBoxItems00(int code)
{
	if (code == 101008)
	{
		Setting::colorcode = weapon::m762;
		return "M762";

	}
	else if (code == 306001)
	{
		Setting::colorcode = weapon::AWMimmo;
		return "AWM Ammo";
	}

	else if (code == 101003)
	{
		Setting::colorcode = weapon::scarl;
		return "SCAR-L";
	}
	else if (code == 302001)
	{

		Setting::colorcode = Colors::ammo7;
		return "7.62";
	}
	else if (code == 303001)
	{

		Setting::colorcode = Colors::ammo5;
		return "5.56";
	}
	else if (code == 602004)
	{
		Setting::colorcode = Colors::Grandes;

		return "Grenade";
	}
	else if (code == 601006)
	{
		Setting::colorcode = Colors::madkit;

		return "Medkit";
	}
	else if (code == 101004)
	{
		Setting::colorcode = weapon::m16;
		return "M416";
	}

	else if (code == 101010)
	{
		Setting::colorcode = Colors::g36;
		return "G36";
	}

	else if (code == 101006)
	{
		Setting::colorcode = Colors::aug;
		return "AUG";
	}

	else if (code == 101101)
	{
		Setting::colorcode = Colors::assm;
		return "ASM"; //time
	}

	else if (code == 101001)
	{
		Setting::colorcode = weapon::AKM;
		return "AKM";
	}

	else if (code == 101005)
	{
		Setting::colorcode = weapon::GROZZA;
		return "Groza";
	}

	else if (code == 103003)
	{
		Setting::colorcode = weapon::AWM;
		return "AWM";
	}

	else if (code == 103002)
	{
		Setting::colorcode = weapon::M24;
		return "M24";
	}

	else if (code == 103001)
	{
		Setting::colorcode = weapon::kar98;
		return "Kar98k";
	}

	else if (code == 103011)
	{
		Setting::colorcode = Colors::mosin;
		return "Mosin";
	}

	else if (code == 502002)
	{
		Setting::colorcode = Colors::helmat;
		return "Helmet Lv.2";
	}

	else if (code == 502003)
	{
		Setting::colorcode = Colors::helmat;
		return "Helmet Lv.3";
	}

	else if (code == 503002)
	{
		Setting::colorcode = Colors::armer;
		return "Armour Lv.2";
	}

	else if (code == 503003)
	{
		Setting::colorcode = Colors::armer;
		return "Armour Lv.3";
	}

	else if (code == 501006)
	{
		Setting::colorcode = Colors::bag;
		return "Bag Lv.3";
	}

	else if (code == 501005)
	{
		Setting::colorcode = Colors::bag;
		return "Bag Lv.2";
	}

	else if (code == 203014)
	{
		Setting::colorcode = Colors::scope3x;
		return "3X";

	}

	else if (code == 203004)
	{
		Setting::colorcode = Colors::scope4x;
		return "4x";
	}

	else if (code == 203015)
	{
		Setting::colorcode = Colors::scope6x;
		return "6x";
	}

	else if (code == 203005)
	{
		Setting::colorcode = weapon::scope8x;
		return "8x";
	}

	else if (code == 106007)
	{
		Setting::colorcode = weapon::Flare;
		return "Flaregun";
	}

	else if (code == 105001)
	{
		Setting::colorcode = Colors::M249;
		return "M249";
	}

	else if (code == 105002)
	{
		Setting::colorcode = Colors::dp;
		return "DP28";
	}

	else if (code == 105010)
	{
		Setting::colorcode = Colors::mg3;
		return "MG3";
	}

	return "Noothing";
}

std::string GetBoxItems(int code)
{
	if (code == 103003)
	{
		Setting::colorcode = weapon::AWM;
		return "AWM";
	}
	else if (code == 103002)
	{
		Setting::colorcode = weapon::M24;
		return "M24";
	}
	else if (code == 103001)
	{
		Setting::colorcode = weapon::kar98;
		return "Kar-98k";
	}
	else if (code == 103011)
	{
		Setting::colorcode = Colors::mosin;
		return "Mosin";
	}
	else if (code == 103012)
	{
		Setting::colorcode = Colors::mosin;
		return "AMR";
	}
	else if (code == 103004)
	{
		Setting::colorcode = weapon::M24;
		return "SKS";
	}
	else if (code == 103007)
	{
		Setting::colorcode = weapon::M24;
		return "Mk14";
	}
	else if (code == 103010)
	{
		Setting::colorcode = weapon::M24;
		return "QBU";
	}
	else if (code == 103009)
	{
		Setting::colorcode = weapon::M24;
		return "SLR";
	}
	else if (code == 103006)
	{
		Setting::colorcode = weapon::M24;
		return "Mini-14";
	}
	else if (code == 103005)
	{
		Setting::colorcode = weapon::M24;
		return "VSS";
	}
	else if (code == 103008)
	{
		Setting::colorcode = weapon::M24;
		return "Win-94";
	}
	//
	else if (code == 101001)
	{
		Setting::colorcode = weapon::AKM;
		return "AKM";
	}
	else if (code == 101008)
	{
		Setting::colorcode = weapon::m762;
		return "M762";
	}
	else if (code == 105002)
	{
		Setting::colorcode = Colors::dp;
		return "DP28";
	}
	else if (code == 101005)
	{
		Setting::colorcode = weapon::GROZZA;
		return "Groza";
	}
	else if (code == 101009)
	{
		Setting::colorcode = weapon::GROZZA;
		return "Mk47";
	}
	//
	else if (code == 101004)
	{
		Setting::colorcode = weapon::m16;
		return "M416";
	}
	else if (code == 101003)
	{
		Setting::colorcode = weapon::scarl;
		return "SCAR-L";
	}
	else if (code == 101002)
	{
		Setting::colorcode = weapon::scarl;
		return "M16A-4";
	}
	else if (code == 101010)
	{
		Setting::colorcode = { ImColor(43, 178, 255, 255) };
		return "G36C";
	}
	else if (code == 101006)
	{
		Setting::colorcode = Colors::aug;
		return "AUG-A3";
	}
	else if (code == 101007)
	{
		Setting::colorcode = Colors::aug;
		return "QBZ";
	}
	else if (code == 101101)
	{
		Setting::colorcode = Colors::assm;
		return "ASM";
	}
	else if (code == 105001)
	{
		Setting::colorcode = { ImColor(43, 178, 255, 255) };
		return "M249";
	}
	else if (code == 105010)
	{
		Setting::colorcode = Colors::mg3;
		return "MG3";
	}
	else if (code == 106007)
	{
		Setting::colorcode = weapon::Flare;
		return "Flaregun";
	}
	//
	else if (code == 104003)
	{
		Setting::colorcode = weapon::Flare;
		return "S12K";
	}
	else if (code == 104004)
	{
		Setting::colorcode = weapon::Flare;
		return "DBS";
	}
	else if (code == 104001)
	{
		Setting::colorcode = weapon::Flare;
		return "S686";
	}
	else if (code == 104002)
	{
		Setting::colorcode = weapon::Flare;
		return "S1897";
	}
	else if (code == 106006)
	{
		Setting::colorcode = weapon::Flare;
		return "Sawed-Off";
	}
	//
	else if (code == 102005)
	{
		Setting::colorcode = weapon::Flare;
		return "PP19Bizon";
	}
	else if (code == 102004)
	{
		Setting::colorcode = weapon::Flare;
		return "TommyGun";
	}
	else if (code == 102007)
	{
		Setting::colorcode = weapon::Flare;
		return "MP5K";
	}
	else if (code == 102002)
	{
		Setting::colorcode = weapon::Flare;
		return "UMP9";
	}
	else if (code == 102003)
	{
		Setting::colorcode = weapon::Flare;
		return "Vector";
	}
	else if (code == 102001)
	{
		Setting::colorcode = weapon::Flare;
		return "Uzi";
	}
	//
	else if (code == 106003)
	{
		Setting::colorcode = weapon::Flare;
		return "R1895";
	}
	else if (code == 106008)
	{
		Setting::colorcode = weapon::Flare;
		return "Vz61";
	}
	else if (code == 106001)
	{
		Setting::colorcode = weapon::Flare;
		return "P92";
	}
	else if (code == 106004)
	{
		Setting::colorcode = weapon::Flare;
		return "P18C";
	}
	else if (code == 106005)
	{
		Setting::colorcode = weapon::Flare;
		return "R45";
	}
	else if (code == 106002)
	{
		Setting::colorcode = weapon::Flare;
		return "P1911";
	}
	else if (code == 106010)
	{
		Setting::colorcode = weapon::Flare;
		return "Desert-Eagle";
	}
	//
	else if (code == 108003)
	{
		Setting::colorcode = { ImColor(255, 255, 0, 255) };
		return "Sickle";
	}
	else if (code == 108001)
	{
		Setting::colorcode = { ImColor(255, 255, 0, 255) };
		return "Machete";
	}
	else if (code == 107001)
	{
		Setting::colorcode = { ImColor(255, 255, 0, 255) };
		return "CrossBow";
	}
	else if (code == 108004)
	{
		Setting::colorcode = { ImColor(255, 255, 0, 255) };
		return "Pan";
	}
	//
	else if (code == 303001)
	{
		Setting::colorcode = { ImColor(0, 255, 0, 255) };
		return "5.56";
	}
	else if (code == 302001)
	{
		Setting::colorcode = { ImColor(255, 170, 0, 255) };
		return "7.62";
	}
	else if (code == 305001)
	{
		Setting::colorcode = { ImColor(0, 255, 230, 255) };
		return "45.ACP";
	}
	else if (code == 301001)
	{
		Setting::colorcode = { ImColor(0, 255, 230, 255) };
		return "9mm";
	}
	else if (code == 304001)
	{
		Setting::colorcode = { ImColor(0, 255, 230, 255) };
		return "12.Guage";
	}
	else if (code == 307001)
	{
		Setting::colorcode = { ImColor(0, 213, 255, 255) };
		return "Ammo_Bolt";
	}
	else if (code == 308001)
	{
		Setting::colorcode = { ImColor(43, 178, 255, 255) };
		return "Flare Ammo";
	}
	else if (code == 306001)
	{
		Setting::colorcode = { ImColor(255, 0, 153, 255) };
		return "AWM.Ammo";
	}
	//
	else if (code == 201004)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "FlashHider (SMG)";
	}
	else if (code == 201002)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "Compensator (SMG)";
	}
	else if (code == 201010)
	{
		Setting::colorcode = { ImColor(255, 0, 153, 255) };
		return "Flash Hider (AR)";
	}
	else if (code == 201009)
	{
		Setting::colorcode = { ImColor(255, 0, 153, 255) };
		return "Compensator (AR)";
	}
	else if (code == 205002)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "Tactical Stock (SMG)";
	}
	else if (code == 201012)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "Duckbill (Pompalı)";
	}
	else if (code == 201005)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "FlashHider (Sniper)";
	}
	else if (code == 201006)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "Suppressor (SMG)";
	}
	else if (code == 205003)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "Chekpad Sniper";
	}
	else if (code == 201001)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "Choke (SG)";
	}
	else if (code == 205001)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "Dipcik (Micro Uzi)";
	}
	else if (code == 201003)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "Compensator (Sniper)";
	}
	else if (code == 201007)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "Suppressor (Sniper)";
	}
	else if (code == 201011)
	{
		Setting::colorcode = { ImColor(255, 0, 153, 255) };
		return "Suppressor (AR)";
	}
	else if (code == 3000331)
	{
		Setting::colorcode = { ImColor(255, 0, 153, 255) };
		return "AR Suppressor";
	}
	//
	else if (code == 204009)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "Extended Quickdraw Mag (Sniper)";
	}
	else if (code == 204004)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "Uz.Haf.Sarjor";
	}
	else if (code == 204005)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "Hc.Haf.Sarjor";
	}
	else if (code == 204007)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "Extended Mag (Sniper)";
	}
	else if (code == 204008)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "Quickdraw Mag (Sniper)";
	}
	else if (code == 204012)
	{
		Setting::colorcode = { ImColor(255, 0, 153, 255) };
		return "Quickdraw Mag (AR)";
	}
	else if (code == 204013)
	{
		Setting::colorcode = { ImColor(255, 0, 153, 255) };
		return "Extended Quickdraw Mag (AR)";
	}
	else if (code == 204011)
	{
		Setting::colorcode = { ImColor(255, 0, 153, 255) };
		return "Extended Mag (AR)";
	}
	else if (code == 204006)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "Hc.Uz.Haf.Sarjor";
	}
	else if (code == 205004)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "ZDD_Crossbow_Q";
	}
	else if (code == 204014)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "ZDD_Sniper";
	}
	else if (code == 202006)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "Thumb-Grip";
	}
	else if (code == 202004)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "Light-Grip";
	}
	else if (code == 202007)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "WB_Lasersight";
	}
	else if (code == 202001)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "WB_Angled";
	}
	else if (code == 202002)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "WB_Vertical";
	}
	//
	else if (code == 502001)
	{
		Setting::colorcode = { ImColor(145, 187, 255, 255) };
		return "Helmet Lv.1";
	}
	else if (code == 502002)
	{
		Setting::colorcode = { ImColor(145, 187, 255, 255) };
		return "Helmet Lv.2";
	}
	else if (code == 502003)
	{
		Setting::colorcode = { ImColor(145, 187, 255, 255) };
		return "Helmet Lv.3";
	}
	//
	else if (code == 502005)
	{
		Setting::colorcode = { ImColor(145, 187, 255, 255) };
		return "Helmet Lv.2";
	}
	//
	else if (code == 503001)
	{
		Setting::colorcode = { ImColor(216, 255, 143, 255) };
		return "Armour Lv.1";
	}
	else if (code == 503002)
	{
		Setting::colorcode = { ImColor(216, 255, 143, 255) };
		return "Armour Lv.2";
	}
	else if (code == 503003)
	{
		Setting::colorcode = { ImColor(216, 255, 143, 255) };
		return "Armour Lv.3";
	}
	//
	else if (code == 501004)
	{
		Setting::colorcode = { ImColor(0, 255, 255, 255) };
		return "Bag Lv.1";
	}
	else if (code == 501005)
	{
		Setting::colorcode = { ImColor(0, 255, 255, 255) };
		return "Bag Lv.2";
	}
	else if (code == 501006)
	{
		Setting::colorcode = { ImColor(0, 255, 255, 255) };
		return "Bag Lv.3";
	}
	//
	else if (code == 501001)
	{
		Setting::colorcode = { ImColor(0, 255, 255, 255) };
		return "Bag Lv.1";
	}
	else if (code == 501002)
	{
		Setting::colorcode = { ImColor(0, 255, 255, 255) };
		return "Bag Lv.2";
	}
	else if (code == 501003)
	{
		Setting::colorcode = { ImColor(0, 255, 255, 255) };
		return "Bag Lv.3";
	}
	//
	else if (code == 203001)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "0x Red.Dot";
	}
	else if (code == 203002)
	{
		Setting::colorcode = { ImColor(255, 255, 255, 255) };
		return "0x Holo";
	}
	else if (code == 203003)
	{
		Setting::colorcode = { ImColor(43, 178, 255, 255) };
		return "2X";
	}
	else if (code == 203014)
	{
		Setting::colorcode = { ImColor(43, 178, 255, 255) };
		return "3X";
	}
	else if (code == 203004)
	{
		Setting::colorcode = { ImColor(43, 178, 255, 255) };
		return "4x";
	}
	else if (code == 203015)
	{
		Setting::colorcode = { ImColor(255, 0, 0, 255) };
		return "6x";
	}
	else if (code == 203005)
	{
		Setting::colorcode = { ImColor(255, 0, 0, 255) };
		return "8x";
	}
	//
	else if (code == 601005)
	{
		Setting::colorcode = { ImColor(43, 178, 255, 255) };
		return "First Aid Kit";
	}
	else if (code == 601006)
	{
		Setting::colorcode = { ImColor(43, 178, 255, 255) };
		return "Med Kit";
	}
	else if (code == 601003)
	{
		Setting::colorcode = { ImColor(43, 178, 255, 255) };
		return "Painkiller";
	}
	else if (code == 601002)
	{
		Setting::colorcode = { ImColor(43, 178, 255, 255) };
		return "Adrenaline_Syringe";
	}
	else if (code == 601001)
	{
		Setting::colorcode = { ImColor(43, 178, 255, 255) };
		return "Energy_Drink";
	}
	else if (code == 601004)
	{
		Setting::colorcode = { ImColor(43, 178, 255, 255) };
		return "Bandage";
	}
	else if (code == 603001)
	{
		Setting::colorcode = { ImColor(43, 178, 255, 255) };
		return "GasCan";
	}
	//
	else if (code == 602004)
	{
		Setting::colorcode = { ImColor(43, 178, 255, 255) };
		return "Grenade";
	}
	else if (code == 602003)
	{
		Setting::colorcode = { ImColor(43, 178, 255, 255) };
		return "Molotof";
	}
	else if (code == 602002)
	{
		Setting::colorcode = { ImColor(43, 178, 255, 255) };
		return "Smoke";
	}
	else if (code == 602005)
	{
		Setting::colorcode = { ImColor(43, 178, 255, 255) };
		return "Grenade_Apple";
	}
	//
	else if (code == 3000312)
		return "GameCoin";
	else if (code == 3000324)
		return "Golden Token";
	else if (code == 3000324)
		return "Acsses card";
	//

	return "Noothing";
}

std::string GetBoxItems1(int code)
{
	if (code == 403989)//arctic ocean
	{
		return "Ghillie Suit";
		//Setting::colorcode = Colors::mg3;
	}
	else if (code == 403045)//woodland hills
	{
		//Setting::colorcode = Colors::mg3;
		return "Ghillie.Suit";
	}
	else if (code == 403187)//Desert
	{
		//Setting::colorcode = Colors::mg3;
		return  "Ghillie-Suit";
	}
	else if (code == 403188)//Desert
	{
		//Setting::colorcode = Colors::mg3;
		return  "Ghillie_Suit";
	}
	//

	return "Noothing";
}

D3DMATRIX1 ToMatrix(FRotator rot = { 0,0,0 }, FRotator origin = { 0,0,0 })
{
	float radPitch = (rot.Pitch * float(M_PI) / 180.f);
	float radYaw = (rot.Yaw * float(M_PI) / 180.f);
	float radRoll = (rot.Roll * float(M_PI) / 180.f);

	float SP = sinf(radPitch);
	float CP = cosf(radPitch);
	float SY = sinf(radYaw);
	float CY = cosf(radYaw);
	float SR = sinf(radRoll);
	float CR = cosf(radRoll);

	D3DMATRIX1 matrix;
	matrix.m[0][0] = CP * CY;
	matrix.m[0][1] = CP * SY;
	matrix.m[0][2] = SP;
	matrix.m[0][3] = 0.f;

	matrix.m[1][0] = SR * SP * CY - CR * SY;
	matrix.m[1][1] = SR * SP * SY + CR * CY;
	matrix.m[1][2] = -SR * CP;
	matrix.m[1][3] = 0.f;

	matrix.m[2][0] = -(CR * SP * CY + SR * SY);
	matrix.m[2][1] = CY * SR - CR * SP * SY;
	matrix.m[2][2] = CR * CP;
	matrix.m[2][3] = 0.f;

	matrix.m[3][0] = origin.Pitch;
	matrix.m[3][1] = origin.Yaw;
	matrix.m[3][2] = origin.Roll;
	matrix.m[3][3] = 1.f;

	return matrix;
}

bool WorldToScreenWithoutMatrix(VECTOR3 WorldLocation, VECTOR3& Screenlocation)
{
	FRotator Rotation = Data::CameraCache.POV.Rotation;
	D3DMATRIX1 tempMatrix = ToMatrix(Rotation);

	VECTOR3 vAxisX, vAxisY, vAxisZ;

	vAxisX.X = tempMatrix.m[0][0];
	vAxisX.Y = tempMatrix.m[0][1];
	vAxisX.Z = tempMatrix.m[0][2];
	vAxisY.X = tempMatrix.m[1][0];
	vAxisY.Y = tempMatrix.m[1][1];
	vAxisY.Z = tempMatrix.m[1][2];
	vAxisZ.X = tempMatrix.m[2][0];
	vAxisZ.Y = tempMatrix.m[2][1];
	vAxisZ.Z = tempMatrix.m[2][2];
	VECTOR3 vDelta = Subtract(WorldLocation, Data::CameraCache.POV.Location);

	VECTOR3 vTransformed;

	vTransformed.X = (vDelta.X * vAxisY.X) + (vDelta.Y * vAxisY.Y) + (vDelta.Z * vAxisY.Z);
	vTransformed.Y = (vDelta.X * vAxisZ.X) + (vDelta.Y * vAxisZ.Y) + (vDelta.Z * vAxisZ.Z);
	vTransformed.Z = (vDelta.X * vAxisX.X) + (vDelta.Y * vAxisX.Y) + (vDelta.Z * vAxisX.Z);


	if (vTransformed.Z < 0.0001f) return false;


	float FovAngle = Data::CameraCache.POV.FOV;

	float ScreenCenterX = DX11Window::Width / 2;
	float ScreenCenterY = DX11Window::Height / 2;

	Screenlocation.X = ScreenCenterX + vTransformed.X * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.Z;
	Screenlocation.Y = ScreenCenterY - vTransformed.Y * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.Z;
	if (Screenlocation.X > DX11Window::Width || Screenlocation.Y > DX11Window::Height || Screenlocation.X < 0 || Screenlocation.Y < 0)
		return false;
	return true;
}

std::string PlayerWeapon(std::string str)
{
	if (str == "BP_Sniper_AWM_C")
		return "AWM";
	else if (str == "BP_Sniper_QBU_C")
		return "QBU";
	else if (str == "BP_Sniper_SLR_C")
		return "SLR";
	else if (str == "BP_Sniper_SKS_C")
		return "SKS";
	else if (str == "BP_Sniper_Mini14_C")
		return "Mini14";
	else if (str == "BP_Sniper_M24_C")
		return "M24";
	else if (str == "BP_Sniper_Kar98k_C")
		return "Kar98k";
	else if (str == "BP_Sniper_VSS_C")
		return "VSS";
	else if (str == "BP_Sniper_Win94_C")
		return "Win94";
	else if (str == "BP_Sniper_Mosin_C")
		return "Mosin";
	else if (str == "BP_Sniper_MK12_C")
		return "MK12";
	else if (str == "BP_Rifle_AUG_C")
		return "AUG";
	else if (str == "BP_Rifle_M762_C")
		return "M762";
	else if (str == "BP_Rifle_SCAR_C")
		return "SCAR";
	else if (str == "BP_Rifle_M416_C")
		return "M416";
	else if (str == "BP_Rifle_M16A4_C")
		return "M16A4";
	else if (str == "BP_Rifle_Mk47_C")
		return "Mk47";
	else if (str == "BP_Rifle_G36_C")
		return "G36";
	else if (str == "BP_Rifle_QBZ_C")
		return "QBZ";
	else if (str == "BP_Rifle_AKM_C")
		return "AKM";
	else if (str == "BP_Rifle_Groza_C")
		return "Groza";

	else if (str == "BP_Other_DP28_C")
		return "DP28";
	else if (str == "BP_Other_M249_C")
		return "M249";
	else if (str == "BP_Other_MG3_C")
		return "MG3";

	else if (str == "BP_MachineGun_P90_C")
		return "P90";
	else if (str == "BP_ShotGun_S12K_C")
		return "S12K";
	else if (str == "BP_ShotGun_DP12_C")
		return "DP12";
	else if (str == "BP_ShotGun_S686_C")
		return "S686";
	else if (str == "BP_ShotGun_S1897_C")
		return "S1897";
	else if (str == "BP_ShotGun_SawedOff_C")
		return "SawedOff";
	else if (str == "BP_MachineGun_PP19_C")
		return "PP19";
	else if (str == "BP_MachineGun_TommyGun_C")
		return "TommyGu";
	else if (str == "BP_MachineGun_MP5K_C")
		return "MP5K";
	else if (str == "BP_MachineGun_UMP9_C")
		return "UMP9";
	else if (str == "BP_MachineGun_Vector_C")
		return "Vector";
	else if (str == "BP_MachineGun_Uzi_C")
		return "Uzi";
	else if (str == "BP_Pistol_Flaregun_C")
		return "Flaregun";
	else if (str == "BP_Pistol_R1895_C")
		return "R1895";
	else if (str == "BP_Pistol_Vz61_C")
		return "Vz61";
	else if (str == "BP_Pistol_P92_C")
		return "P92";
	else if (str == "BP_Pistol_P18C_C")
		return "P18C";
	else if (str == "BP_Pistol_R45_C")
		return "R45";
	else if (str == "BP_Pistol_P1911_C")
		return "P1911";
	else if (str == "BP_Pistol_DesertEagle_C")
		return "DesertEagle";
	else if (str == "BP_WEP_Mk14_C")
		return "Mk14";

	else if (str == "BP_Other_CrossBow_C")
		return "CrossBow";
	else if (str == "BP_WEP_Cowbar_C")
		return "Crowbar";
	else if (str == "BP_WEP_Machete_C")
		return "Machete";
	else if (str == "BP_WEP_Pan_C")
		return "Pan";

	else if (str == "BP_Grenade_Shoulei_C")
		return "Grenade";
	else if (str == "BP_Grenade_Shoulei_Weapon_C")
		return "Grenade";
	else if (str == "BP_Grenade_Smoke_C")
		return "Smoke";
	else if (str == "BP_Grenade_Smoke_Weapon_C")
		return "Smoke";
	else if (str == "BP_Grenade_Burn_C")
		return "Burn";
	else if (str == "BP_Grenade_Burn_Weapon_C")
		return "Burn";
	else
		//return "Be Careful | Weapon Not Detect";
		return "";
	return "Fist";
}
std::string scopes(int fov)
{
	if (fov == 70)
		return " : Iron";
	else if (fov == 55)
		return " : RedDot";
	else if (fov == 44)
		return " : X2";
	else if (fov == 26)
		return " : X3";
	else if (fov == 20)
		return " : X4";
	else if (fov == 13)
		return " : X6";
	else if (fov == 11)
		return " : X8";
	else
		return "";

	return "";
}
bool IsItem(const std::string& actorName)
{
	// Don't sort AirDrop and LootBox actor
	if (actorName == "PickUpListWrapperActor"
		|| actorName == "PickUpListWrapperActor_Recycled"
		|| actorName == "AirDropListWrapperActor"
		|| actorName == "AirDropListWrapperActor_Recycled"
		|| actorName == "BP_AirDropBox_C"
		|| actorName == "BP_AirDropBox_New_C"
		|| actorName == "BP_AirDropBox_C_Recycled"
		)
		return false;

	if (actorName.find("Wrapper") == std::string::npos
		|| actorName.find("PickUp") == std::string::npos

		)
		return true;

	return false;
}

bool
IsVehicle(const std::string& actorName)
{
	if (actorName.find('/') != std::string::npos
		|| actorName.find("Parachute") != std::string::npos
		)
		return false;

	if (actorName.find("VH_") != std::string::npos
		|| actorName.find("Mirado") != std::string::npos
		|| actorName.find("water_Plane") != std::string::npos
		|| actorName.find("AquaRail") != std::string::npos
		|| actorName.find("Rony") != std::string::npos
		)
		return true;

	return false;
}

bool
IsBombe(const std::string& classname)
{
	if (classname.find("BP_Grenade_Smoke_C") != std::string::npos)
		return true;
	if (classname.find("BP_Grenade_Burn_C") != std::string::npos)
		return true;
	if (classname.find("BP_Grenade_Stun_C") != std::string::npos)
		return true;
	if (classname.find("BP_Grenade_Shoulei") != std::string::npos)
		if (classname.find("BP_Grenade_Shoulei_C") != std::string::npos)
			return true;
	if (classname.find("AirAttackBomb") != std::string::npos)
		return true;


	return false;
}
bool ISUseFulVector(VECTOR3 input) {
	if (isnan(input.X) && isnan(input.Y))return false;
	if (input.X == 0 && input.Y == 0)return false;
	return true;
}
bool areEqual(VECTOR3 vs, VECTOR3 vea) {
	if (vs.X == vea.X && vs.Y == vea.Y)return true;
	else return false;
}

VOID Data::KeyHandler()
{
	////////while (true)
	////////{
	////////	if (GetAsyncKeyState(VK_INSERT) & 0x1)
	////////	{

	////////		Setting::ShowMenu = !Setting::ShowMenu;
	////////	}
	////////	if (GetAsyncKeyState(VK_HOME) & 0x1) 
	////////	{

	////////		Setting::ShowSideMenu = !Setting::ShowSideMenu;
	////////	}
	////////	//if (GetAsyncKeyState(VK_F9) & 1)
	////////	//{
	////////	//	Setting::UselessShow = !Setting::UselessShow;
	////////	//}
	////////	if (GetAsyncKeyState(VK_F2) & 1)
	////////	{
	////////		//Setting::MagicBullet = !Setting::MagicBullet;
	////////		Setting::MagicBulletticked = !Setting::MagicBulletticked;
	////////	}
	////////	if (GetAsyncKeyState(VK_F3) & 1)
	////////	{
	////////		Setting::fightmode = !Setting::fightmode;
	////////	}
	////////	//if (GetAsyncKeyState(VK_TAB) & 1)
	////////	//{
	////////	//	Setting::Aimbot = !Setting::Aimbot;
	////////	//}
	////////	if (GetAsyncKeyState(VK_F9) & 1)
	////////	//if (GetAsyncKeyState(VK_LCONTROL) & 1)
	////////	{
	////////		Setting::CRPTPressed = !Setting::CRPTPressed;
	////////	}
	////////	if (GetAsyncKeyState(Setting::curraimKey) & 1)//T
	////////	{
	////////		if (Setting::curraim == 0)
	////////		{

	////////			Setting::curraim++;
	////////		}
	////////		else
	////////		{
	////////			if (Setting::curraim == 1) 
	////////			{
	////////				Setting::curraim = 3;
	////////			}
	////////			else if (Setting::curraim == 3)
	////////			{
	////////				Setting::curraim = 0;
	////////			}
	////////		}


	////////	}

	////////	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	////////}

}


const DWORD WORLD_ROOT = 0x781638C;
const DWORD NAMES_ROOT = 0x7928780;
DWORD GetWorldPtr(DWORD libUE4_base) {
	DWORD worldDec = 0;
	DWORD worldRoot = Utility::ReadMemoryEx<DWORD>(libUE4_base + WORLD_ROOT);

	int i = 0;

	while (i <= 3) {
		uint32_t ptrVal = Utility::ReadMemoryEx<uint32_t>(worldRoot + 4 * i + 0x80);

		uint64_t byteVal = (Utility::ReadMemoryEx<uint8_t>(worldRoot + ptrVal));

		worldDec += (byteVal << (8 * i++));
	}

	return  (worldDec);

}
uint32_t GetFNamesAddr(DWORD UE4)
{
	uint32_t Encryption = (Utility::ReadMemoryEx<uint32_t>(UE4 + 0x7928780) - 0x64) / 3;
	uint32_t Ptr = Utility::ReadMemoryEx<uint32_t>(UE4 + 0x7928780 + 0x8);
	for (uint32_t i = 0; i != Encryption; i++)
		Ptr = Utility::ReadMemoryEx<uint32_t>(Ptr);
	return Ptr;
}
DWORD GetNamesPtr(DWORD libUE4_base) {
	std::array <DWORD, 16> arr;

	arr.fill(0);

	uint32_t a = Utility::ReadMemoryEx<uint32_t>(libUE4_base + NAMES_ROOT) - 100;

	uint32_t b = a / 3;

	arr[b - 1] = Utility::ReadMemoryEx<DWORD>(libUE4_base + NAMES_ROOT + 8);

	if (((b - 2) & 0x80000000) == 0) {
		uint64_t c = (((uint64_t)0xAAAAAAAB * a) >> 33) - 1;

		do {
			DWORD e = Utility::ReadMemoryEx<DWORD>(arr[c]);
			--c;
			arr[c] = e;
		} while (c > 0);
	}

	return (arr[0]);
}

uint32_t DecryptActorsArray(uint32_t uLevel, int Actors_Offset, int EncryptedActors_Offset)
{
	if (uLevel < 0x10000000)
		return 0;

	if (Utility::ReadMemoryEx<uint32_t>(uLevel + Actors_Offset) > 0)
		return uLevel + Actors_Offset;

	if (Utility::ReadMemoryEx<uint32_t>(uLevel + EncryptedActors_Offset) > 0)
		return uLevel + EncryptedActors_Offset;

	auto Encryption = Utility::ReadMemoryEx<ActorsEncryption>(uLevel + EncryptedActors_Offset + 0x0C);

	if (Encryption.Enc_1 > 0)
	{
		uint32_t DecryptedActorsPointer = 0;
		int DecCount = 4;
		int index = 0;
		while (index < DecCount) {
			auto ival = Utility::ReadMemoryEx<uint32_t>(Encryption.Enc_1 + 0x80 + (0x4 * index));
			DecryptedActorsPointer += Utility::ReadMemoryEx<uint8_t>(Encryption.Enc_1 + ival) << (0x8 * index++);
		}
		return DecryptedActorsPointer;
	}
	else if (Encryption.Enc_2 > 0)
	{
		auto Encrypted_Actors = Utility::ReadMemoryEx<uint32_t>(Encryption.Enc_2);
		if (Encrypted_Actors > 0)
		{
			return ((unsigned short)Encrypted_Actors - 0x400) & 0xFF00
				| (unsigned char)(Encrypted_Actors - 0x04)
				| (Encrypted_Actors + 0xFC0000) & 0xFF0000
				| (Encrypted_Actors - 0x4000000) & 0xFF000000;
		}
	}
	else if (Encryption.Enc_3 > 0)
	{
		auto Encrypted_Actors = Utility::ReadMemoryEx<uint32_t>(Encryption.Enc_3);
		if (Encrypted_Actors > 0)
			return _rotr(Encrypted_Actors, 0x18);
	}
	else if (Encryption.Enc_4 > 0)
	{
		auto Encrypted_Actors = Utility::ReadMemoryEx<uint32_t>(Encryption.Enc_4);
		if (Encrypted_Actors > 0)
			return Encrypted_Actors ^ 0xCDCD00;
	}
	return 0;
}

std::string playerstatus(int GetEnemyState)
{
	switch (GetEnemyState)
	{
	case 0:
		return "AFK";
	case 1:
		return "In Water";
	case 8:
		return "Stand";
	case 9:
		return "Walking";
	case 10:
		return "Landing";
	case 11:
		return "Running";
	case 16:
		return "Crouching";
	case 17:
		return "Crouching Walk";
	case 19:
		return "Crouching Run";
	case 32:
		return "Snaking";
	case 33:
		return "Snaking Walk";
	case 35:
		return "Snaking Run";
	case 5445:
	case 762:
		return "Snake";
	case 72:
	case 73:
	case 75:
		return "Jumping";
	case 264:
	case 272:
	case 273:
	case 288:
	case 265:
	case 329:
		return "Relaoding";
	case 136:
	case 137:
	case 144:
	case 145:
	case 160:
	case 648:
	case 649:
	case 1160:
	case 1161:
	case 1169:
	case 201:
		return "Firing";
	case 4194304:
	case 4194307:
		return "Swimming";
	case 131070:
	case 131071:
	case 131072:
	case 131073:
	case 131074:
	case 131075:
		return "Knocked";
	case 524296:
		return "Driving Vehicle";
	case 524288:
		return "Driving Boat";
	case 1048584:
		return "Set in Vehicle";
	case 1048576:
		return "Set in Boat";
	case 33554440:
		return "Set in Plane";
	case 3146248:
		return "Aim in vehicle";
	case 3146240:
		return "Aim in boat";
	case 3145736:
		return "Beek in vehicle";
	case 3145728:
		return "Beek in boat";
	case 1050632:
		return "Change vehicle seat";
	case 1050624:
		return "Change boat seat";
	case 32784:
		return "Reviving";
	case 16392:
	case 16393:
	case 16401:
	case 16416:
	case 16417:
	case 16457:
	case 16400:
	case 17401:
	case 17417:
	case 17424:
	case 17425:
		return "Throwing Bomp";
	case 16777224:
		return "Climping";
	case 8200:
	case 8208:
		return "Punish, Stab";
	case 520:
	case 544:
	case 521:
	case 656:
	case 528:
		return "Aiming";
	case 1680:
	case 1672:
	case 1673:
	case 1032:
	case 1544:
	case 1545:
	case 1033:
		return "Peeking";
	case 2056:
		return "Change Weapon";
	case 65544:
		return "Healing";
	case 65545:
		return "Healing & Walk";
	case 268435464:
		return "Playing Emotion";
	case 4194305:
		return "Diving, Floating";
	}

	return std::to_string(GetEnemyState);
}

DWORD Data::NetDriver;
DWORD Data::GName;
DWORD Data::GameState;
DWORD Data::GameMode;
int Data::NoneAIGameTime;
int Data::PlayerNumPerTeam;
string Data::GameType;
DWORD Data::TimeRemind;
DWORD Data::TimeRemindWWCD;
int Data::PlayerAddonCount;

string Data::MyPlayerName = "";
string Data::MyPlayerNation = "";
string Data::MyPlayerUID = "";
int Data::MyPlayerTeamID;
int Data::MyPlayerLevel;
FLOAT Data::MyPlayerHealth;
int Data::MyPlayerTotalKills;
int Data::MyPlayerTotalKillsWWCD;

int Data::ElapsedTime;
int Data::GameModeID;
int Data::CurCircleWave;
int Data::PlayerNumGameState;
int Data::AlivePlayerNum;
int Data::AliveTeamNum;
DWORD Data::LocalPlayer;
DWORD Data::LocalPlayerAddr;
DWORD Data::LocalController;
DWORD Data::CurrentReloadWeapon;
DWORD Data::ShootWeaponEntity;
DWORD Data::PlayerController;
DWORD Data::PlayerCameraManager;
CameraCacheEntry Data::CameraCache;;
VECTOR3 Data::lOCALPLAYERHEAD;
VECTOR3 Data::lOCALPLAYERPosotion;
VECTOR3 Data::AimingCoordinates;
FRotator Data::lOCALPLAYERRotation;
DWORD Data::EntityAddress = 0;
std::string Data::Weapon;
vector<AActor> Data::AActorList = {};
vector<AActor> Data::AimingAtMePlayersList = {};
vector<AActor> Data::ABotList = {};
vector<BombAlert> Data::BombAlertList = {};
vector<Item> Data::ItemList = {};
vector<impItem> Data::impItemList = {};
vector<Vehicle> Data::VehicleList = {};
vector<Deadbox> Data::BoxesList = {};

std::map<DWORD, int> GrenadesCD;
std::string Data::LocalPawn;
std::string Data::CharacterModel_Health;
std::string Data::LocalPawnWWCD;
std::unordered_map<DWORD, DWORD> RepeatedActors = {};
std::unordered_map<DWORD, string> TempAllActorsCache = {};
vector<DWORD>  TempActorAdrress = {};

string ItemType = "";

//std::vector<Airdrop>  Data::LootData, Data::LootDatadatar = {};

VOID Data::ItemPicker()
{
	std::unordered_map<DWORD, string> TempList = {};
	vector<DWORD>  TempCacheActorAdrress = {};






	Data::Ue4base = Utility::ReadMemoryEx<UINT>(Offset::UE4Pointer);
	GName = (Utility::ReadMemoryEx<DWORD>(Data::Ue4base + Offset::GName) + 136);
	DWORD GWorld = Utility::ReadMemoryEx<DWORD>(Data::Ue4base + Offset::GWorld) + 60;
	Data::ViewMatrixBase = Data::Ue4base + Offset::ViewMatrixBase;


	while (true)
	{
		g_pEsp->lootbox.clear();

		UWorld = Utility::ReadMemoryEx<DWORD>(GWorld);
		std::cout << UWorld << std::endl;
		if (UWorld != 0)
		{
			DWORD PersistentLevel = Utility::ReadMemoryEx<DWORD>(UWorld + Offset::PersistentLevel);

			NetDriver = Utility::ReadMemoryEx<DWORD>(UWorld + Offset::NetDriver);
			/*if (NetDriver > 0) {

			}
			else {

				Data::AActorList.clear();
				Data::AimingAtMePlayersList.clear();
				Data::ABotList.clear();
				Data::BombAlertList.clear();
				Data::ItemList.clear();
				Data::VehicleList.clear();
				Data::BoxesList.clear();
				TempActorAdrress.clear();
				TempAllActorsCache.clear();
				RepeatedActors.clear();
				GrenadesCD.clear();
				TempCacheActorAdrress.clear();
				TempList.clear();
				continue;
			}*/

			GameState = Utility::ReadMemoryEx<DWORD>(UWorld + Offset::GameState);
			AliveTeamNum = Utility::ReadMemoryEx<int>(GameState + Offset::AliveTeamNum);
			AlivePlayerNum = Utility::ReadMemoryEx<int>(GameState + Offset::AlivePlayerNum);
			PlayerNumGameState = Utility::ReadMemoryEx<int>(GameState + Offset::PlayerNum);
			PlayerNumPerTeam = Utility::ReadMemoryEx<int>(GameState + Offset::PlayerNumPerTeam);
			CurCircleWave = Utility::ReadMemoryEx<int>(GameState + Offset::CurCircleWave);
			GameModeID = Utility::ReadMemoryEx<int>(GameState + Offset::GameModeID) * -1;
			TimeRemind = Utility::ReadMemoryEx<int>(GameState + Offset::ElapsedTime);
			TimeRemindWWCD = Utility::ReadMemoryEx<int>(GameState + Offset::ElapsedTime);
			if (Data::NetDriver > 0)
			{
				//if (PlayerNumPerTeam == 1) GameType = "SOLO"; else if (PlayerNumPerTeam == 2) GameType = "DUO"; else if (PlayerNumPerTeam == 4) GameType = "SQUAD"; else GameType = "Detecting Mode;";
				if (PlayerNumPerTeam == 1) GameType = "SOLO"; else if (PlayerNumPerTeam == 2) GameType = "DUO"; else if (PlayerNumPerTeam == 4) GameType = "SQUAD"; else GameType = "Detecting...";
			}
			else
			{
				//if (PlayerNumPerTeam == 1) GameType = "SOLO"; else if (PlayerNumPerTeam == 2) GameType = "DUO"; else if (PlayerNumPerTeam == 4) GameType = "SQUAD"; else GameType = "Waiting In Lobby";
				if (PlayerNumPerTeam == 1) GameType = "SOLO"; else if (PlayerNumPerTeam == 2) GameType = "DUO"; else if (PlayerNumPerTeam == 4) GameType = "SQUAD"; else GameType = "In Lobby";
			}
			
			
			//int GameType = Utility::ReadMemoryEx<int>(Data::LocalController + Offset::GameReplayType);

			if (PersistentLevel != 0)
			{
				/*	DWORD EntityList = Utility::ReadMemoryEx<DWORD>(PersistentLevel + Offset::EntityList);
					DWORD EntityCount = Utility::ReadMemoryEx<INT>(PersistentLevel + Offset::EntityCount);*/

				auto ActorsPointerAddress = DecryptActorsArray(PersistentLevel, Offset::EntityList, Offset::EncryptedActors_Offset);
				DWORD EntityList = Utility::ReadMemoryEx<uint32_t>(ActorsPointerAddress);
				DWORD EntityCount = Utility::ReadMemoryEx<int>(ActorsPointerAddress + 0x4);


				/*if (EntityList == EntityCount)ExitProcess(1);
				if (EntityCount > 600)
				{
					EntityCount = 600;
				}
				if (EntityCount <= 0)
				{
					ExitProcess(1);
					continue;
				}*/
				for (int i = 0; i < EntityCount; i++)
				{
					DWORD EntityAddress = Utility::ReadMemoryEx<DWORD>(EntityList + i * 4);
					if (!EntityAddress)
						continue;
					if (EntityAddress == (DWORD)nullptr || EntityAddress == -1 || EntityAddress == NULL)
						continue;


					if (RepeatedActors.find(EntityAddress) == RepeatedActors.end())
					{
						RepeatedActors.insert(make_pair(EntityAddress, PersistentLevel));
					}
					else
					{
						continue;
					}
					DWORD EntityStruct = Utility::ReadMemoryEx<DWORD>(EntityAddress + 0x10);
					std::string EntityType = GetEntityType2(GName, EntityStruct);
					if (EntityType == "None" || EntityType == " " || EntityType == "") continue;

					if (Data::NetDriver > 0)
					{
						if (EntityType == "BP_CharacterModelTaget_C" || EntityType == "BP_CharacterModel")
						{
							Data::CharacterModel_Health = "CharacterModel";
						}
					}
					else
					{
						if (EntityType == "BP_CharacterModelTaget_C" || EntityType == "BP_CharacterModel")
						{
							Data::CharacterModel_Health = "CharacterModel";
						}
					}

					if (Data::NetDriver > 0)
					{
						if (EntityType == "PUBG_Forest_x7_y7_Collision")
						{
							Data::LocalPawn = "In Erangel";
						}
						else if (EntityType == "BRPlayerStateTeam_DeathMatch" || EntityType == "TD_Factory_Depot_Main_C")
						{
							Data::LocalPawn = "In TDM";
						}
						else if (EntityType == "BuildingKanerjing_Trigger")
						{
							Data::LocalPawn = "In Livik";
						}
						else if (EntityType == "SocialIsland_Main_C")
						{
							Data::LocalPawn = "In CheerPark";
						}
						else if (EntityType == "PUBG_Desert_C")
						{
							Data::LocalPawn = "In Miramar";
						}
						else if (EntityType == "PUBG_Savage_Main_C")
						{
							Data::LocalPawn = "In Sanhok";
						}
						else if (EntityType == "DihorOtok_Main_C")
						{
							Data::LocalPawn = "In Vikendi";
						}
						else if (EntityType == "SummerLand_ObjectPoolMgr")
						{
							Data::LocalPawn = "In Karakin";
						}
						else if (EntityType == "BP_BRGameState_TeamHardPoint_C")
						{
							Data::LocalPawn = "In Domination";
						}
						else if (EntityType == "PUBG_Borderland_Main_C")
						{
							Data::LocalPawn = "In Nusa";
						}
						else if (EntityType == "SingleTraining_Main_C")
						{
							Data::LocalPawn = "In Training";
						}
						else if (EntityType == "BP_PlayerLobbyPawn_C" || EntityType == "Lobby_Main_int_C")
						{
							Data::LocalPawn = "In Lobby";
						}
					}
					else
					{
						Data::LocalPawn = "In Lobby";
					}

					if (Setting::WWCD)
					{
						if (Data::NetDriver > 0)
						{
							if (EntityType == "PUBG_Forest_x7_y7_Collision")
							{
								Data::LocalPawnWWCD = "Erangel";
							}
							else if (EntityType == "BRPlayerStateTeam_DeathMatch" || EntityType == "TD_Factory_Depot_Main_C")
							{
								Data::LocalPawnWWCD = "TDM";
							}
							else if (EntityType == "BuildingKanerjing_Trigger")
							{
								Data::LocalPawnWWCD = "Livik";
							}
							else if (EntityType == "SocialIsland_Main_C")
							{
								Data::LocalPawnWWCD = "CheerPark";
							}
							else if (EntityType == "PUBG_Desert_C")
							{
								Data::LocalPawnWWCD = "Miramar";
							}
							else if (EntityType == "PUBG_Savage_Main_C")
							{
								Data::LocalPawnWWCD = "Sanhok";
							}
							else if (EntityType == "DihorOtok_Main_C")
							{
								Data::LocalPawnWWCD = "Vikendi";
							}
							else if (EntityType == "SummerLand_ObjectPoolMgr")
							{
								Data::LocalPawnWWCD = "Karakin";
							}
							else if (EntityType == "BP_BRGameState_TeamHardPoint_C")
							{
								Data::LocalPawnWWCD = "Domination";
							}
							else if (EntityType == "PUBG_Borderland_Main_C")
							{
								Data::LocalPawnWWCD = "Nusa";
							}
							else if (EntityType == "SingleTraining_Main_C")
							{
								Data::LocalPawnWWCD = "Training";
							}
							else if (EntityType == "BP_PlayerLobbyPawn_C" || EntityType == "Lobby_Main_int_C")
							{
								Data::LocalPawnWWCD = "Lobby";
							}
						}
						else
						{
							Data::LocalPawnWWCD = "Lobby";
						}
					}
					
					

					if (Setting::UselessShow)
					{
						ofstream cpp;
						cpp.open("c://EntityDumps.txt", ios::app);
						cpp << EntityType << endl;
						cout << EntityType << endl;
					}

					if (Setting::PlayerESP)
					{
						if (IsPlayer(EntityType))
						{
							TempList.emplace(make_pair(EntityAddress, EntityType));
							TempCacheActorAdrress.emplace_back(EntityAddress);
							continue;
						}
					}

					if (Setting::Vehicle)
					{
						if (IsVehicle(EntityType)) 
						{
							TempList.emplace(make_pair(EntityAddress, EntityType));
							TempCacheActorAdrress.emplace_back(EntityAddress);
							continue;
						}
					}

					if (Setting::BombAlert)
					{
						if (IsBombe(EntityType))
						{
							TempList.emplace(make_pair(EntityAddress, EntityType));
							TempCacheActorAdrress.emplace_back(EntityAddress);
							continue;
						}
					}

					if (Setting::Item)
					{
						if (IsItem(EntityType))
						{
							TempList.emplace(make_pair(EntityAddress, EntityType));
							TempCacheActorAdrress.emplace_back(EntityAddress);
							continue;
						}


						/*ItemType = GetItemType(EntityType);
						if (ItemType.find("Unknown") == std::string::npos)
						{
							Item Item;
							Item.Name = ItemType;
							Item.Position = Utility::ReadMemoryEx<VECTOR3>(RootComponent + Offset::Position);

							ItemList.push_back(Item);
						}*/
					}



					if (Setting::UselessShow)
					{
						TempList.emplace(make_pair(EntityAddress, EntityType));
						TempCacheActorAdrress.emplace_back(EntityAddress);
						continue;
					}

					if (Setting::playerdeadbox)
					{
						if (IsBox(EntityType))
						{
							DWORD  count = Utility::ReadMemoryEx<DWORD>(EntityAddress + Offset::PickUpDataList + 0x4);
							if (count > 30)
								count = 30;
							g_pEsp->lbox.boxitem.clear();
							if (count > 0)
							{
								long itemBase = Utility::ReadMemoryEx<DWORD>(EntityAddress + Offset::PickUpDataList);
								long itemAddv;
								for (int t = 0; t < count; t++)
								{
									itemAddv = itemBase + t * 48;
									std::string bitm = GetBoxItems0(Utility::ReadMemoryEx<DWORD>(itemAddv + 0x4));
									std::string bitm1 = GetBoxItems01(Utility::ReadMemoryEx<DWORD>(itemAddv + 0x4));
									if (bitm.find("tatti") == std::string::npos)
									{
										Itemb temo;
										bitm.append("  :  ").append(std::to_string(Utility::ReadMemoryEx<DWORD>(itemAddv + 0x18)));
										temo.colorcod = Setting::colorcode;
										temo.Displayname = bitm;
										g_pEsp->lbox.boxitem.push_back(temo);
									}
									bitm.clear();

									if (bitm1.find("tatti") == std::string::npos)
									{
										Itemb temo;
										bitm1.append("  :  ").append(std::to_string(Utility::ReadMemoryEx<DWORD>(itemAddv + 0x18)));
										temo.colorcod = Setting::colorcode;
										temo.Displayname = bitm1;
										g_pEsp->lbox.boxitem.push_back(temo);
									}
									bitm1.clear();
								}
							}
							g_pEsp->lbox.Position = Utility::ReadMemoryEx<VECTOR3>(Utility::ReadMemoryEx<DWORD>(EntityAddress + Offset::RootComponent) + Offset::Position);
							g_pEsp->lootbox.push_back(g_pEsp->lbox);
						}
					}

				}

			}
		}

		/*	TempAllActorsCache.clear();
			TempActorAdrress.clear();*/
		TempAllActorsCache = TempList;
		TempActorAdrress = TempCacheActorAdrress;
		g_pEsp->lootboxr = g_pEsp->lootbox;
		TempCacheActorAdrress.clear();
		TempList.clear();
		RepeatedActors.clear();
		std::this_thread::sleep_for(std::chrono::milliseconds(Setting::AdreessGetterDelay));



	}

}

#define	PTR_SIZE 4 
uintptr_t GetVirtualFunctionAddresss(uintptr_t Class, uint32_t index)
{
	if (!Class)
		return 0;

	return Utility::ReadMemoryEx<uintptr_t>(Utility::ReadMemoryEx<uintptr_t>(Class) + (index * PTR_SIZE));
}

VOID Data::QueryThread()
{

	//DWORD UWorld = 0;
	DWORD PersistentLevel = 0;
	DWORD ServerConnection = 0;
	DWORD EntityList = 0;
	INT EntityCount = 0;


	DWORD EntityStruct = 0;
	string EntityType = "";

	DWORD RootComponent = 0;
	INT MyTeamId = 9999;
	DWORD PlayerStateBASE;
	DWORD PlayerStateBASE1;


	string GrenadeType = "";
	string ItemType = "";
	string VehicleType = "";
	string airdroptype = "";
	string deadboxtype = "";

	vector<AActor> AActorList = {};
	vector<AActor> ABotList = {};
	vector<AActor> AimingAtMePlayersList = {};
	vector<BombAlert> BombAlertList = {};
	vector<Item> ItemList = {};
	vector<impItem> impItemList = {};
	vector<Vehicle> VehicleList = {};
	std::vector<Deadbox> Boxess = {};



	for (;;)
	{
		try {
	
			ElapsedTime = Utility::ReadMemoryEx<int>(GameState + Offset::ElapsedTime);
			NoneAIGameTime = Utility::ReadMemoryEx<int>(GameState + Offset::NoneAIGameTime);
			ServerConnection = Utility::ReadMemoryEx<DWORD>(NetDriver + Offset::ServerConnection);
			PlayerController = Utility::ReadMemoryEx<DWORD>(ServerConnection + Offset::PlayerController);
			LocalPlayer = Utility::ReadMemoryEx<DWORD>(PlayerController + Offset::AcknowledgedPawn);
			LocalPlayerAddr = Utility::ReadMemoryEx<uint32_t>(PlayerController + Offset::STExtraBaseCharacter);
			LocalController = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayerAddr + Offset::STExtraPlayerCharacter::STPlayerController);
			PlayerCameraManager = Utility::ReadMemoryEx<DWORD>(LocalController + Offset::PlayerController1::PlayerCameraManager);

			PlayerStateBASE = Utility::ReadMemoryEx<DWORD>(LocalPlayer + 0x350);//3.4 0x31c);//2.8// Class: Pawn.Actor.Object, PlayerState* PlayerState;//[Offset: 0x31c, Size: 4]
			Data::MyPlayerName = GetPlayerName(Utility::ReadMemoryEx<DWORD>(LocalPlayer + 0x6b0));//3.4 0x680));//3.2 // Class: UAECharacter.Character.Pawn.Actor.Object, FString PlayerName;//[Offset: 0x680, Size: 12]
			Data::MyPlayerNation = GetPlayerName(Utility::ReadMemoryEx<DWORD>(LocalPlayer + 0x6bc));//3.4 0x68c));//3.2 // Class: UAECharacter.Character.Pawn.Actor.Object, FString Nation;//[Offset: 0x68c, Size: 12]
			Data::MyPlayerUID = GetPlayerName(Utility::ReadMemoryEx<DWORD>(LocalPlayer + Offset::PlayerUID));//3.4// Class: UAECharacter.Character.Pawn.Actor.Object, FString PlayerUID;//[Offset: 0x69c, Size: 12]
			//Data::MyPlayerUID = GetPlayerName(Utility::ReadMemoryEx<DWORD>(PlayerStateBASE + 0x48c));//3.4// Class: UAEPlayerState.LuaPlayerState.PlayerState.Info.Actor.Object, FString PlayerUID;//[Offset: 0x464, Size: 12]
			Data::MyPlayerTeamID = Utility::ReadMemoryEx<INT>(LocalPlayer + Offset::TeamId);// 3.4 // Class: UAECharacter.Character.Pawn.Actor.Object, int TeamID;//[Offset:
			Data::MyPlayerLevel = Utility::ReadMemoryEx<INT>(PlayerStateBASE + 0x490);
			Data::MyPlayerHealth = Utility::ReadMemoryEx<FLOAT>(PlayerStateBASE + 0xf70/*0xee4*/);//3.4// Class: STExtraPlayerState.UAEPlayerState.LuaPlayerState.PlayerState.Info.Actor.Object, float PlayerHealth;//[Offset: 0xee4, Size: 4]
			Data::MyPlayerTotalKills = Utility::ReadMemoryEx<INT>(PlayerStateBASE + 0x528/*0x4f8*/);//3.4// Class: UAEPlayerState.LuaPlayerState.PlayerState.Info.Actor.Object, int Kills;//[Offset: 0x4f8, Size: 4]
			Data::MyPlayerTotalKillsWWCD = Utility::ReadMemoryEx<INT>(PlayerStateBASE + 0x528/*0x4f8*/);//3.4// Class: UAEPlayerState.LuaPlayerState.PlayerState.Info.Actor.Object, int Kills;//[Offset: 0x4f8, Size: 4]

			/*	auto LineOfSightTo = GetVirtualFunctionAddresss(LocalController, 231);
				cout << "Address : 0x" << hex << LineOfSightTo << endl;*/
			for (int i = 0; i < TempActorAdrress.size(); i++)
			{
				if (TempActorAdrress.empty())break;
				EntityAddress = TempActorAdrress[i];
				if (EntityAddress == NULL) { continue; }
				if (TempAllActorsCache.empty())break;
				//	EntityType = TempAllActorsCache.at(EntityAddress);
				DWORD EntityStruct = Utility::ReadMemoryEx<DWORD>(EntityAddress + 0x10);
				std::string EntityType = GetEntityType2(GName, EntityStruct);
				RootComponent = Utility::ReadMemoryEx<DWORD>(EntityAddress + Offset::RootComponent);

				if (IsPlayer(EntityType) && Setting::PlayerESP)
				{
					int KnockedHealth = Utility::ReadMemoryEx<FLOAT>(EntityAddress + Offset::NearDeathBreath); if (KnockedHealth <= 0) continue;
					bool IsDead = Utility::ReadMemoryEx<bool>(EntityAddress + Offset::IsDead); if (IsDead == true) continue;
					AActor AActor;
					AActor.TeamId = Utility::ReadMemoryEx<INT>(EntityAddress + Offset::TeamId);
					AActor.Address = EntityAddress;


					if (!Setting::MeEnemyShow)
					{
						if (AActor.Address == LocalPlayerAddr)
						{
							CurrentReloadWeapon = Utility::ReadMemoryEx<DWORD>(LocalPlayer + Offset::CurrentWeapon);
							ShootWeaponEntity = Utility::ReadMemoryEx<DWORD>(CurrentReloadWeapon + Offset::ShootWeaponEntity);

							/*	MeshAddv = Utility::ReadMemoryEx<DWORD>(AActor.Address + Offset::Mesh);
								BodyAddv = MeshAddv + Offset::BodyAddv;
								BoneAddv = Utility::ReadMemoryEx<DWORD>(MeshAddv + Offset::MinLOD) + 48;*/

							MyTeamId = AActor.TeamId;
							if (Setting::MyLineOfSight)
							{
								FRotator RelativeRotation = Utility::ReadMemoryEx<FRotator>(RootComponent + Offset::RelativeRotation);
								lOCALPLAYERRotation = RelativeRotation;

							}
							continue;
						}
						if (AActor.TeamId == MyTeamId) continue;
					}
					
					//AActor.Position = Utility::ReadMemoryEx<VECTOR3>(RootComponent + Offset::Position);
					FRotator RelativeRotation = Utility::ReadMemoryEx<FRotator>(RootComponent + Offset::RelativeRotation);
					VECTOR3 RelativeLocation = Utility::ReadMemoryEx<VECTOR3>(RootComponent + Offset::RelativeLocation);

					AActor.RelativeLocation = RelativeLocation;
					AActor.RelativeRotation = RelativeRotation;
					AActor.IsBot = Utility::ReadMemoryEx<bool>(EntityAddress + Offset::IsBot);
					AActor.Name = GetPlayerNameUTF(Utility::ReadMemoryEx<DWORD>(EntityAddress + Offset::Name));
					AActor.Nation = GetPlayerName(Utility::ReadMemoryEx<DWORD>(EntityAddress + Offset::Nation));
					AActor.Health = Utility::ReadMemoryEx<FLOAT>(EntityAddress + Offset::Health);
					AActor.UID = GetPlayerName(Utility::ReadMemoryEx<DWORD>(EntityAddress + Offset::PlayerUID));
					if (AActor.Health <= 0)
					{
						AActor.KnockedHealth = Utility::ReadMemoryEx<FLOAT>(EntityAddress + Offset::NearDeathBreath);
						DWORD NearDeatchComponent = Utility::ReadMemoryEx<DWORD>(EntityAddress + Offset::NearDeatchComponent);
						if (NearDeatchComponent)
						{
							AActor.HealthMax = Utility::ReadMemoryEx<FLOAT>(NearDeatchComponent + Offset::BreathMax);
						}
					}
					else
					{
						AActor.HealthMax = Utility::ReadMemoryEx<FLOAT>(EntityAddress + Offset::HealthMax);
					}

					if (Setting::playerweapon)
					{
						DWORD wep = Utility::ReadMemoryEx<DWORD>(EntityAddress + Offset::CurrentWeapon);
						if (wep) {

							std::string weapon = PlayerWeapon(GetEntityType2(GName, Utility::ReadMemoryEx<DWORD>(wep + 16)));
							AActor.Weapon = weapon;

							DWORD STExtraShootWeaponComponent = Utility::ReadMemoryEx<DWORD>(wep + Offset::ShootWeaponComponent);
							if (STExtraShootWeaponComponent != 0)
							{
								DWORD STExtraShootWeapon = Utility::ReadMemoryEx<DWORD>(STExtraShootWeaponComponent + Offset::OwnerShootWeapon);
								if (STExtraShootWeapon != 0)
								{
									AActor.Ammo = Utility::ReadMemoryEx<int>(STExtraShootWeapon + Offset::CurBulletNumInClip);
									AActor.AmmoMax = Utility::ReadMemoryEx<int>(STExtraShootWeapon + Offset::CurMaxBulletNumInOneClip);

									AActor.ScopeFov = scopes(Utility::ReadMemoryEx<FLOAT>(EntityAddress + Offset::ScopeFov));
								}
							}
						}
						else
						{
							AActor.Weapon = "Fist";

						}
						DWORD CurrWeapon1 = Utility::ReadMemoryEx<DWORD>(LocalPlayer + Offset::CurrentReloadWeapon);
						AActor.Weapon1 = GetEntityType(GName, Utility::ReadMemoryEx<DWORD>(CurrWeapon1 + 16));
						Data::Weapon = PlayerWeapon(GetEntityType2(GName, Utility::ReadMemoryEx<DWORD>(Utility::ReadMemoryEx<DWORD>(LocalPlayer + Offset::CurrentWeapon) + 16)));
						if (Data::Weapon == "")
							Data::Weapon = "Fist";
						AActor.Weapon1 = Data::Weapon;

						Data::Weapon = PlayerWeapon(GetEntityType2(GName, Utility::ReadMemoryEx<DWORD>(Utility::ReadMemoryEx<DWORD>(EntityAddress + Offset::CurrentReloadWeapon) + 16)));

					}

					if (Setting::PlayerStatus)
					{
						std::string pstatus = playerstatus(Utility::ReadMemoryEx<DWORD>(EntityAddress + Offset::CurrentStates));
						if (pstatus == "")
							pstatus = "NoStatus";
						AActor.playerstatus = pstatus;
					}
					//	AActor.Velocity = Utility::ReadMemoryEx<VECTOR3>(Utility::ReadMemoryEx<DWORD>(AActor.Address + Offset::CharacterMovement) + Offset::LastUpdateVelocity);
						//AActor.TeamId = Utility::ReadMemoryEx<INT>(EntityAddress + Offset::TeamId);


					if (Setting::IsimingAtYou)
					{

						FRotator RelativeRotation = AActor.RelativeRotation;
						ClampAngles(RelativeRotation);
						VECTOR3 MyHEad = lOCALPLAYERPosotion;
						VECTOR3 EnemyHed = Utility::ReadMemoryEx<VECTOR3>(Utility::ReadMemoryEx<DWORD>(EntityAddress + Offset::RootComponent) + Offset::Position);

						auto Angle = ToRotator(EnemyHed, MyHEad);
						ClampAngles(Angle);


						float num = abs(RelativeRotation.Pitch - Angle.Pitch);
						float num2 = abs(RelativeRotation.Yaw - Angle.Yaw);
						bool num3 = (num + num2) <= 6.f;

						if (num3 == true) {
							AActor.isAimingAtMe = true;
							AimingAtMePlayersList.emplace_back(AActor);
						}

					}


					if (AActor.IsBot)
					{

						if (Setting::botnameShow)
						{
							/*AActor.Name = GetPlayerName(Utility::ReadMemoryEx<DWORD>(EntityAddress + Offset::Name));
							AActor.Nation = GetPlayerFlag(Utility::ReadMemoryEx<DWORD>(EntityAddress + Offset::Nation));*/

							AActor.Name = GetPlayerNameUTF(Utility::ReadMemoryEx<DWORD>(EntityAddress + Offset::Name));
							AActor.Nation = GetPlayerName(Utility::ReadMemoryEx<DWORD>(EntityAddress + Offset::Nation));

						}
						else
						{
							AActor.Name = "BOT";
							AActor.Nation = "";

						}

						//ABotList.emplace_back(AActor);
					}
					else
					{
						//AActor.Name = GetPlayerNameUTF(Utility::ReadMemoryEx<DWORD>(EntityAddress + Offset::Name));
						//AActor.Nation = GetPlayerName(Utility::ReadMemoryEx<DWORD>(EntityAddress + Offset::Nation));

					}
					AActorList.emplace_back(AActor);
					continue;

				}

				if (Setting::BombAlert)
				{
					ItemType = GetGrenadeType(EntityType);
					if (ItemType.find(("noooooooot")) == std::string::npos)
					{
						if (GrenadesCD.find(EntityAddress) == GrenadesCD.end())
						{
							GrenadesCD.insert({ EntityAddress,  ElapsedTime + 17 });
						}
						int CurrentTime = GrenadesCD.at(EntityAddress) - ElapsedTime;
						if (CurrentTime > 0) {

							BombAlert Bomb;
							Bomb.Name = ItemType;
							Bomb.Address = EntityAddress;
							Bomb.timeLeft = CurrentTime;
							Bomb.Position = Utility::ReadMemoryEx<VECTOR3>(RootComponent + Offset::Position);
							BombAlertList.emplace_back(Bomb);
							continue;

						}


					}
				}
				if (Setting::Vehicle)
				{

					VehicleType = GetVehicleType(EntityType);
					if (VehicleType.find(("Unknown")) == std::string::npos)
					{

						Vehicle Vehicle;
						Vehicle.Name = VehicleType;
						Vehicle.Address = EntityAddress;
						//Vehicle.Position = Utility::ReadMemoryEx<VECTOR3>(RootComponent + Offset::Position);

						DWORD veh = Utility::ReadMemoryEx<DWORD>(EntityAddress + Offset::VehicleCommon);
						float speed = Utility::ReadMemoryEx<float>(EntityAddress + Offset::lastForwardSpeed);
						//Offset::VehicleCommonComponent VehicleCommonComponent = Utility::ReadMemoryEx<Offset::VehicleCommonComponent>(veh);

						float HP = Utility::ReadMemoryEx<float>(veh + Offset::HP);
						float HPMax = Utility::ReadMemoryEx<float>(veh + Offset::HPMax);
						float Fuel = Utility::ReadMemoryEx<float>(veh + Offset::Fuel);
						float FuelMax = Utility::ReadMemoryEx<float>(veh + Offset::FuelMax);
						/*float HPMax = VehicleCommonComponent.HPMax;
						float HP = VehicleCommonComponent.HP;
						float Fuel = VehicleCommonComponent.Fuel;
						float FuelMax = VehicleCommonComponent.FuelMax;*/
						if (HPMax == 0)continue;
						if (FuelMax == 0)continue;
						Vehicle.hp = (int)(HP * 100 / HPMax);
						if (speed > 8 || speed < -8)
						{
							Vehicle.driving = true;
						}
						else
						{
							Vehicle.driving = false;
						}
						Vehicle.oil = (int)(Fuel * 100 / FuelMax);
						if (Vehicle.oil < 0 || Vehicle.oil > 101) {
							continue;
						}
						else {
							VehicleList.emplace_back(Vehicle);
							continue;
						}

					}
				}
				/*if (Setting::Item)
				{

					ItemType = GetItemType(EntityType);
					if (ItemType.find(("Unknown")) == std::string::npos)
					{
						Item Item;
						Item.Name = ItemType;
						Item.Position = Utility::ReadMemoryEx<VECTOR3>(RootComponent + Offset::Position);

						ItemList.emplace_back(Item);
						continue;
					}
				}*/

				if (Setting::Item)
				{
					/*if (GetItemType(EntityType))
					{
						TempList.emplace(make_pair(EntityAddress, EntityType));
						TempCacheActorAdrress.emplace_back(EntityAddress);
						continue;
					}*/


					ItemType = GetItemType(EntityType);
					if (ItemType.find("Unknown") == std::string::npos)
					{
						Item Item;
						Item.Name = ItemType;
						Item.Position = Utility::ReadMemoryEx<VECTOR3>(RootComponent + Offset::Position);

						ItemList.push_back(Item);
					}
				}
			}

			/*	Data::AActorList.clear();
				Data::AimingAtMePlayersList.clear();
				Data::ABotList.clear();
				Data::BombAlertList.clear();
				Data::ItemList.clear();
				Data::VehicleList.clear();
				Data::BoxesList.clear();*/

			Data::AActorList = AActorList;
			Data::ABotList = ABotList;
			Data::AimingAtMePlayersList = AimingAtMePlayersList;
			Data::BombAlertList = BombAlertList;
			Data::ItemList = ItemList;
			Data::VehicleList = VehicleList;



			AActorList.clear();
			ABotList.clear();
			BombAlertList.clear();
			ItemList.clear();
			VehicleList.clear();
			AimingAtMePlayersList.clear();

			std::this_thread::sleep_for(std::chrono::milliseconds(150));


		}
		catch (int e) {
			cout << e << endl;
		}
	}
}
