#pragma once

#include "Includes.h"
#include "imgui-docking/imgui.h"
#include "imgui-docking/imgui_impl_win32.h"
#include "imgui-docking/imgui_impl_dx11.h"
#include "imgui-docking/imgui_internal.h"

namespace Setting1
{
	extern bool style1;
	extern bool style2;
	extern bool style3;
	extern bool style4;


	//bot=================================
	extern bool botname, botline, botBone, bothealth, botcornerbox, botfullbox, botblood, botdistance, botweapon, botWeapons_iconsH;
	//bst1
	extern bool botst1name, botst1line, botst1Bone, botst1health, botst1cornerbox, botst1fullbox, botst1blood, botst1distance, botst1weapon, botst1Weapons_iconsH;
	//bst2
	extern bool botst2name, botst2line, botst2Bone, botst2health, botst2cornerbox, botst2fullbox, botst2blood, botst2distance, botst2weapon, botst2Weapons_iconsH;
	//bst3
	extern bool botst3name, botst3line, botst3Bone, botst3health, botst3cornerbox, botst3fullbox, botst3blood, botst3distance, botst3weapon, botst3Weapons_iconsH;

	//playr===============================
	extern bool playername, playerline, playerBone, playerhealth, playercornerbox, playerfullbox, playerblood, playerdistance, playerweapon, playerWeapons_iconsH;
	//bst1
	extern bool playerst1name, playerst1line, playerst1Bone, playerst1health, playerst1cornerbox, playerst1fullbox, playerst1blood, playerst1distance, playerst1weapon, playerst1Weapons_iconsH;
	//bst2
	extern bool playerst2name, playerst2line, playerst2Bone, playerst2health, playerst2cornerbox, playerst2fullbox, playerst2blood, playerst2distance, playerst2weapon, playerst2Weapons_iconsH;
	//bst3
	extern bool playerst3name, playerst3line, playerst3Bone, playerst3health, playerst3cornerbox, playerst3fullbox, playerst3blood, playerst3distance, playerst3weapon, playerst3Weapons_iconsH;

	//--------------------------------------------
	extern bool Flags, FlagText, Flagimge;
	extern bool AimingAlert;
	extern bool AirDropBox, AirDropBoxItems;
	extern bool deadbox, deadboxItems;
	//------------------------------------------
	extern bool Vehicle, Vehiclest1, Vehiclest2, Vehiclest3;
	extern bool VehicleFeul, VehicleFeulst1, VehicleFeulst2, VehicleFeulst3;
	extern bool VehicleHp, VehicleHpst1, VehicleHpst2, VehicleHpst3;
	//---------------------------------------------------------------------
	extern float botnames1, botnames2, botnames3;
	extern float botlines1, botlines2, botlines3;
	extern float botBones1, botBones2, botBones3;
	extern float bothealths1, bothealths2, bothealths3;
	extern float botcornerboxs1, botcornerboxs2, botcornerboxs3;
	extern float botfullboxs1, botfullboxs2, botfullboxs3;
	extern float botdistances1, botdistances2, botdistances3;
	extern float botweaponFalses1, botweaponFalses2, botweaponFalses3;
	extern float botweapons1, botweapons2, botweapons3;
	//
	extern float playernames1, playernames2, playernames3;
	extern float playerlines1, playerlines2, playerlines3;
	extern float playerBones1, playerBones2, playerBones3;
	extern float playerhealths1, playerhealths2, playerhealths3;
	extern float playercornerboxs1, playercornerboxs2, playercornerboxs3;
	extern float playerfullboxs1, playerfullboxs2, playerfullboxs3;
	extern float playerdistances1, playerdistances2, playerdistances3;
	extern float playerweaponFalses1, playerweaponFalses2, playerweaponFalses3;
	extern float playerweapons1, playerweapons2, playerweapons3;
	//
	extern float AimingAlerts1, AimingAlerts2, AimingAlerts3;
	extern float FlagTexts1, FlagTexts2, FlagTexts3;
	extern float AirDropBoxs1, AirDropBoxs2, AirDropBoxs3;
	extern float AirDropBoxItemss1, AirDropBoxItemss2, AirDropBoxItemss3;
	extern float deadboxs1, deadboxs2, deadboxs3;
	extern float deadboxItemss1, deadboxItemss2, deadboxItemss3;
	//
	extern float Vehicles, Vehicles1, Vehicles2, Vehicles3;


	/////////////////////////
	// Bot Color
	extern	ImVec4  botnamec1,  botnamec2,  botnamec3;
	extern	ImVec4  botlinec1,  botlinec2,  botlinec3;
	extern	ImVec4  botBonec1,  botBonec2,  botBonec3;
	extern	ImVec4  bothealthc1,  bothealthc2,  bothealthc3;
	extern	ImVec4  botcornerboxc1,  botcornerboxc2,  botcornerboxc3;
	extern	ImVec4  botfullboxc1,  botfullboxc2,  botfullboxc3;
	extern	ImVec4  botdistancec1,  botdistancec2,  botdistancec3;
	extern	ImVec4  botweaponFalsec1,  botweaponFalsec2,  botweaponFalsec3;
	extern	ImVec4  botweaponc1,  botweaponc2,  botweaponc3;
	/////////////////////////
	// Player Color
	extern	ImVec4  playernamec1,  playernamec2,  playernamec3;
	extern	ImVec4  playerlinec1,  playerlinec2,  playerlinec3;
	extern	ImVec4  playerBonec1,  playerBonec2,  playerBonec3;
	extern	ImVec4  playerhealthc1,  playerhealthc2,  playerhealthc3;
	extern	ImVec4  playercornerboxc1,  playercornerboxc2,  playercornerboxc3;
	extern	ImVec4  playerfullboxc1,  playerfullboxc2,  playerfullboxc3;
	extern	ImVec4  playerdistancec1,  playerdistancec2,  playerdistancec3;
	extern	ImVec4  playerweaponFalsec1,  playerweaponFalsec2,  playerweaponFalsec3;
	extern	ImVec4  playerweaponc1,  playerweaponc2,  playerweaponc3;
	//
	extern	ImVec4  FlagTextc1,  FlagTextc2,  FlagTextc3;
	extern	ImVec4  AirDropBoxc1,  AirDropBoxc2,  AirDropBoxc3;
	extern	ImVec4  AirDropBoxItemsc1,  AirDropBoxItemsc2,  AirDropBoxItemsc3;
	extern	ImVec4  deadboxc1,  deadboxc2,  deadboxc3;
	extern	ImVec4  deadboxItemsc1,  deadboxItemsc2,  deadboxItemsc3;
	//
	extern ImVec4  Vehiclec, Vehiclec1, Vehiclec2, Vehiclec3;

	//============================================


	extern ImVec4 colorcode;
	//=====================
	extern int SuperFront;
	extern int SuperUp;
	extern int SuperDown;
	extern int SuperRight;
	extern int SuperLeft;
	//======================
	//==================
	extern bool ShowMenu2;
	//====================
	extern bool antiscreen;
	//======================
	extern bool FastParachute;
	//======================
	//====================
	extern bool fackSetting1;
	extern bool fackSetting2;
	extern bool fackSetting3;
	extern bool fackSetting4;
	extern bool fackSetting5;
	extern bool fackSetting6;
	extern bool fackSetting7;
	extern bool fackSetting8;
	extern bool fackSetting9;
	extern bool fackSetting10;
	extern bool fackSetting11;
	extern bool fackSetting12;
	extern bool fackMoreOption;
	//======================
	extern bool VngGameEsp;

	extern int Flymankey;
	extern int Backcarkey;
	extern int Fastcarkey;
	extern int landspeed;
	extern int FastParachutekey;
	extern bool Luffy;
	extern bool SuperView;
	extern bool Legitrack;
	extern bool RandomTracking;
	extern bool SkipBots;
	extern bool Redzome;
	extern float fovcircleredus;
	extern bool fovcircle;
	extern bool fovcircle2;
	extern bool ScreenX;

	//======================
	extern bool viplogin;
	extern bool freelogin;
	//======================
	extern bool SafeMode;
	extern bool DangerMode;
	//======================
	extern bool knocked;
	extern int EnableKey;
	extern int MagicBulletKey;
	extern int AimbotKey;
	extern int AimbotPositionKey;
	extern int fastrunkey;
	extern int PositionKey;
	extern DWORD CurrentTargetAddress;

	extern	bool dots;
	extern	bool dots1;
	extern	bool dots2;
	extern	bool boxitemBagShadow;
	extern int  redioption;
	extern bool  redioption2;
	extern	bool IsMagicInitialize;
	extern FLOAT Aimspeed;
	extern bool aimbotposition;
	extern bool Magntic;
	extern bool AimHead;
	extern bool AimBody;
	extern int	curraim;
	extern bool	engine;
	extern bool	skele;
	extern bool MAgicline;
	extern float warning;

	extern char filename[];
	extern float Normalfontsize;
	extern float Normalfontsize2;
	extern float Normalfontsize3;
	extern float Normalfontsize4;
	extern float Normalfontsize5;
	extern float fontsize;

	extern bool Esp_Item_AirAttack;

	extern float AllItemsSize;

	extern float weaponsize;
	extern int psize1;
	extern float Namesize;
	extern	float overlaycolor;

	extern float IPADSIZE;
	extern float IPADSIZE1;

	extern bool silent;
	extern bool same;
	extern bool differnt;

	extern bool bortext;
	extern bool PESP;
	extern bool BESP;

	extern bool ShowMenu;
	extern bool profree;

	extern bool fightmode;
	extern int Fightmodekey;
	extern bool Name;
	extern bool TeamIdLine;
	extern bool Distance;
	extern bool TotalEnemy;
	extern bool TotalEnemyStyle1;
	extern bool TotalEnemyStyle2;
	extern bool TotalEnemyStyle3;
	extern bool Gameinfo;
	extern bool Line;
	extern bool Box;
	extern bool Bone;
	extern bool Health;
	extern bool BombAlert;
	extern bool Item;

	extern bool impitems;
	extern bool graned;
	extern bool healthitem;
	extern bool scope;
	extern bool allitemss;

	extern bool instanthit;
	extern bool instanthitDNG;
	extern bool fastrun;
	extern bool fly;
	extern bool carfly;
	extern bool speedcar;
	extern bool recoil;

	extern bool luffy;
	extern bool ipadview;
	extern bool noheadshot;
	extern bool smallcrosshair;

	extern float flyPower;
	extern int intV;
	extern int intGO;

	extern bool airdrop;
	extern bool airdropitem;

	extern bool itemrect;
	extern bool Bags;
	extern bool Helmat;
	extern bool Armer;

	extern	bool Esp_Item_M249;

	extern	bool Esp_Item_Mk12;

	extern bool MagicX;
	extern bool LegitTrack;

	extern bool MagicInsideFOV;
	extern bool Magic360deg;
	extern bool AimbotwithMagic;
	extern bool AimPrediction;
	extern bool MemoryAimbot;


	extern bool plan;
	extern ImVec4 plancolor;
	extern ImVec4 dotss;
	extern bool vahicle_item;
	extern bool Esp_Item_AKM;
	extern float Esp_Item_AKM_Color[4];
	extern float Esp_Item_AKM_TextSize;

	extern bool Esp_Item_ExplosiveBow;
	extern float Esp_Item_ExplosiveBow_Color[4];
	extern float Esp_Item_ExplosiveBow_TextSize;

	extern bool Esp_Item_HoneyBadger;
	extern float Esp_Item_HoneyBadger_Color[4];
	extern float Esp_Item_HoneyBadger_TextSize;

	extern bool Esp_Item_M762;
	extern float Esp_Item_M762_Color[4];
	extern float Esp_Item_M762_TextSize;

	extern bool Esp_Item_Mk47Mutant;
	extern float Esp_Item_Mk47Mutant_Color[4];
	extern float Esp_Item_Mk47Mutant_TextSize;

	extern bool Esp_Item_DP28;
	extern float Esp_Item_DP28_Color[4];
	extern float Esp_Item_DP28_TextSize;

	extern bool Esp_Item_SCARL;
	extern float Esp_Item_SCARL_Color[4];
	extern float Esp_Item_SCARL_TextSize;

	extern bool Esp_Item_M416;
	extern float Esp_Item_M416_Color[4];
	extern float Esp_Item_M416_TextSize;

	extern bool Esp_Item_M16A4;
	extern float Esp_Item_M16A4_Color[4];
	extern float Esp_Item_M16A4_TextSize;

	extern bool Esp_Item_G36C;
	extern float Esp_Item_G36C_Color[4];
	extern float Esp_Item_G36C_TextSize;

	extern bool Esp_Item_QBZ;
	extern float Esp_Item_QBZ_Color[4];
	extern float Esp_Item_QBZ_TextSize;

	extern bool Esp_Item_QBU;
	extern float Esp_Item_QBU_Color[4];
	extern float Esp_Item_QBU_TextSize;

	extern bool Esp_Item_SLR;
	extern float Esp_Item_SLR_Color[4];
	extern float Esp_Item_SLR_TextSize;

	extern bool Esp_Item_SKS;
	extern float Esp_Item_SKS_Color[4];
	extern float Esp_Item_SKS_TextSize;

	extern bool Esp_Item_Mini14;
	extern float Esp_Item_Mini14_Color[4];
	extern float Esp_Item_Mini14_TextSize;

	extern bool Esp_Item_M24;
	extern float Esp_Item_M24_Color[4];
	extern float Esp_Item_M24_TextSize;
	extern bool Esp_Item_Awm;
	extern bool Esp_Item_Awmimo;
	extern bool Esp_Item_Kar98k;
	extern float Esp_Item_Kar98k_Color[4];
	extern float Esp_Item_Kar98k_TextSize;

	extern bool Esp_Item_PP19;
	extern float Esp_Item_PP19_Color[4];
	extern float Esp_Item_PP19_TextSize;

	extern bool Esp_Item_TommyGun;
	extern float Esp_Item_TommyGun_Color[4];
	extern float Esp_Item_TommyGun_TextSize;

	extern bool Esp_Item_MP5K;
	extern float Esp_Item_MP5K_Color[4];
	extern float Esp_Item_MP5K_TextSize;

	extern bool Esp_Item_UMP9;
	extern float Esp_Item_UMP9_Color[4];
	extern float Esp_Item_UMP9_TextSize;

	extern bool Esp_Item_Vector;
	extern float Esp_Item_Vector_Color[4];
	extern float Esp_Item_Vector_TextSize;

	extern bool Esp_Item_Uzi;
	extern float Esp_Item_Uzi_Color[4];
	extern float Esp_Item_Uzi_TextSize;

	extern bool Esp_Item_762mm;
	extern float Esp_Item_762mm_Color[4];
	extern float Esp_Item_762mm_TextSize;

	extern bool Esp_Item_556mm;
	extern float Esp_Item_556mm_Color[4];
	extern float Esp_Item_556mm_TextSize;

	extern bool Esp_Item_9mm;
	extern float Esp_Item_9mm_Color[4];
	extern float Esp_Item_9mm_TextSize;

	extern bool Esp_Item_45ACP;
	extern float Esp_Item_45ACP_Color[4];
	extern float Esp_Item_45ACP_TextSize;

	extern bool Esp_Item_Holo;
	extern float Esp_Item_Holo_Color[4];
	extern float Esp_Item_Holo_TextSize;

	extern bool Esp_Item_x2;
	extern float Esp_Item_x2_Color[4];
	extern float Esp_Item_x2_TextSize;

	extern bool Esp_Item_x3;
	extern float Esp_Item_x3_Color[4];
	extern float Esp_Item_x3_TextSize;

	extern bool Esp_Item_x4;
	extern float Esp_Item_x4_Color[4];
	extern float Esp_Item_x4_TextSize;

	extern bool Esp_Item_x6;
	extern float Esp_Item_x6_Color[4];
	extern float Esp_Item_x6_TextSize;

	extern bool Esp_Item_x8;
	extern float Esp_Item_x8_Color[4];
	extern float Esp_Item_x8_TextSize;

	extern bool Esp_Item_Bag1;
	extern float Esp_Item_Bag1_Color[4];
	extern float Esp_Item_Bag1_TextSize;

	extern bool Esp_Item_Bag2;
	extern float Esp_Item_Bag2_Color[4];
	extern float Esp_Item_Bag2_TextSize;

	extern bool Esp_Item_Bag3;
	extern float Esp_Item_Bag3_Color[4];
	extern float Esp_Item_Bag3_TextSize;

	extern bool Esp_Item_Armor1;
	extern float Esp_Item_Armor1_Color[4];
	extern float Esp_Item_Armor1_TextSize;

	extern bool Esp_Item_Armor2;
	extern float Esp_Item_Armor2_Color[4];
	extern float Esp_Item_Armor2_TextSize;

	extern bool Esp_Item_Armor3;
	extern float Esp_Item_Armor3_Color[4];
	extern float Esp_Item_Armor3_TextSize;

	extern bool Esp_Item_Helmet1;
	extern float Esp_Item_Helmet1_Color[4];
	extern float Esp_Item_Helmet1_TextSize;

	extern bool Esp_Item_Helmet2;
	extern float Esp_Item_Helmet2_Color[4];
	extern float Esp_Item_Helmet2_TextSize;

	extern bool Esp_Item_Helmet3;
	extern float Esp_Item_Helmet3_Color[4];
	extern float Esp_Item_Helmet3_TextSize;

	extern bool Esp_Item_Frag;
	extern float Esp_Item_Frag_Color[4];
	extern float Esp_Item_Frag_TextSize;

	extern bool Esp_Item_Grenade;
	extern float Esp_Item_Grenade_Color[4];
	extern float Esp_Item_Grenade_TextSize;

	extern bool Esp_Item_Smoke;
	extern float Esp_Item_Smoke_Color[4];
	extern float Esp_Item_Smoke_TextSize;

	extern bool Esp_Item_Molotof;
	extern float Esp_Item_Molotof_Color[4];
	extern float Esp_Item_Molotof_TextSize;

	extern bool Esp_Item_MedKit;
	extern float Esp_Item_MedKit_Color[4];
	extern float Esp_Item_MedKit_TextSize;

	extern bool Esp_Item_FirstAidKit;
	extern float Esp_Item_FirstAidKit_Color[4];
	extern float Esp_Item_FirstAidKit_TextSize;

	extern bool Esp_Item_Painkiller;
	extern float Esp_Item_Painkiller_Color[4];
	extern float Esp_Item_Painkiller_TextSize;

	extern bool Esp_Item_EnergyDrink;
	extern float Esp_Item_EnergyDrink_Color[4];
	extern float Esp_Item_EnergyDrink_TextSize;

	extern bool Esp_Item_AdrenalineSyringe;
	extern float Esp_Item_AdrenalineSyringe_Color[4];
	extern float Esp_Item_AdrenalineSyringe_TextSize;

	extern bool Esp_Item_FlareGun;
	extern float Esp_Item_FlareGun_Color[4];
	extern float Esp_Item_FlareGun_TextSize;

	extern bool Esp_Item_Flare;
	extern float Esp_Item_Flare_Color[4];
	extern float Esp_Item_Flare_TextSize;

	extern bool Esp_Item_AirDrop;
	extern float Esp_Item_AirDrop_Color[4];
	extern float Esp_Item_AirDrop_TextSize;

	extern bool Esp_Item_LootBox;
	extern float Esp_Item_LootBox_Color[4];
	extern float Esp_Item_LootBox_TextSize;

	extern bool Aimbot;

	extern bool MagicBullet;
	extern bool MagicBulletDNG;

	extern bool borderlo;

	extern int intGO;
	extern bool SuperView1;
	extern float SuperViewPower;

	extern bool NINEFPS;
	extern bool Fps;
	extern bool Infomrmation;

	extern bool CameraCatch;

	extern bool SuperView;
	extern bool SuperViewDNG;
	extern bool SuperViewA;

	extern bool grw;
	extern bool GrenadeWarning;
	extern bool molow;
	//extern float hpt;
	extern int	magicv;
	extern int	flycarv;
	extern int	instantv;
	extern int	carsv;
	extern int	fastrv;
	extern bool magicb;


	extern bool ShopToken;
	extern ImVec4 ShopTokenC;
	extern float ShopTokenT;

	extern bool RedZoneBomb;
	extern ImVec4 RedZoneBombC;
	extern float RedZoneBombT;

	extern bool GasCan;
	extern ImVec4 GasCanC;
	extern float GasCanT;

	extern bool HideIconeMENU;
	extern ImVec4 HideIconeMENUC;
	extern float HideIconeMENUT;

	extern bool StatusDiscord;
	extern ImVec4 StatusDiscordC;
	extern float StatusDiscordT;

	extern bool ShowStatusMagicBullet;
	extern bool ShowCurrentAimPosition;

	extern float GrenadeSize;



	extern bool LowCpu;
	extern bool HighCpu;



	extern char PathSetting[];

	extern string GameState;
	extern string GameState1;
	extern int AlivePlayers;
	extern int TimeRemind;
	extern int AliveTeams;
	extern int RealPlayers;
	extern int PlayerNumPerTeam;
	extern int ZoneID;
	extern int MyTeamID;
	extern int GameID;

	extern int UpdateTick;

	extern bool MapType;
	extern bool WWCD;

}

namespace weapon1 
{


	extern ImVec4 m16;
	extern ImVec4 scarl;
	extern ImVec4 AKM;
	extern ImVec4 m762;
	extern ImVec4 DP28;
	extern ImVec4 GROZZA;
	extern ImVec4 Honey;


	extern ImVec4 AWM;
	extern ImVec4 AWMimmo;
	extern ImVec4 M24;
	extern ImVec4 kar98;

	extern ImVec4 Airdrop;
	extern ImVec4 Flare;
	extern ImVec4 Flaregun;

	extern ImVec4  ammo7;
	extern ImVec4  ammo5;
}

namespace Scope1 
{

	extern ImVec4 scope2x;
	extern ImVec4 scope3x;
	extern ImVec4 scope4x;
	extern ImVec4 scope6x;
	extern ImVec4 scope8x;
}

namespace Colors1 
{

	extern ImVec4 Smoke_Color;
	extern ImVec4 Grenade_Color;
	extern ImVec4 Molotof_Color;
	extern ImVec4 Burn_Color;

	extern ImVec4 ammo_5_56mm;
	extern ImVec4 ammo_7_62mm;
	extern ImVec4 ammo_9mm;
	extern ImVec4 ammo_45ACP;
	extern ImVec4 ammo_sniper;
	extern ImVec4 ammo_Flare_Gun;

	extern ImVec4 weapon_7mm;
	extern ImVec4 weapon_5mm;
	extern ImVec4 weapon_smg;
	extern ImVec4 weapon_sniper;
	extern ImVec4 weapon_Flare_Gun;

	extern ImVec4 Holo;
	extern ImVec4 Red_Dot;
	extern ImVec4 scope_2x;
	extern ImVec4 scope_3x;
	extern ImVec4 scope_4x;
	extern ImVec4 scope_6x;
	extern ImVec4 scope_8x;

	extern ImVec4 Bandage;
	extern ImVec4 EnergyDrink;
	extern ImVec4 Painkiller;
	extern ImVec4 Firstkit;
	extern ImVec4 Madkit;
	extern ImVec4 AdrenalineSyringe;

	extern ImVec4 Bag_lv1;
	extern ImVec4 Bag_lv2;
	extern ImVec4 Bag_lv3;

	extern ImVec4 Helmet_lv1;
	extern ImVec4 Helmet_lv2;
	extern ImVec4 Helmet_lv3;

	extern ImVec4 Armor_lv1;
	extern ImVec4 Armor_lv2;
	extern ImVec4 Armor_lv3;


	extern ImVec4  dp;
	extern ImVec4  mg3;

	extern ImVec4  bag;
	extern ImVec4  armer;
	extern ImVec4  helmat;
	extern ImVec4  mosin;
	extern ImVec4  aug;
	extern ImVec4  g36c;
	extern ImVec4  assm;

	extern ImVec4  Grandes;
	extern ImVec4  madkit;

	//extern ImVec4  madkit;
	//extern ImVec4  Firstkit;
	//extern ImVec4  Painkiller;
	//extern ImVec4  AdrenalineSyringe;

	/////////////////////////
	extern ImVec4 itemcolors;
	// ARGB playr
	extern	ImVec4  lotboxColor;
	// ARGB
	extern ImVec4  helthbar;
	extern ImVec4  boxColor;
	extern ImVec4  cornerColor;
	extern ImVec4  crosshairColor;

	extern ImVec4  skelec;
	extern ImVec4  skelec1;

	//RGB
	extern ImVec4 circle;
	extern ImVec4  enemy;
	extern ImVec4  bone;
	extern ImVec4  fillrect;
	extern ImVec4  nam;




	extern ImVec4  nambarColor;
	extern ImVec4  textColor;

	extern ImVec4 GranadesColor;
	extern ImVec4 healthColor;
	extern ImVec4 deadboxitemColor;
	extern ImVec4 airdropColor;
	extern ImVec4 airdropitemColor;
	extern ImVec4 scopetextColor;
	extern ImVec4 allitemColor;
	extern ImVec4 magiclineColor;
	extern ImVec4 bgcornerColor;
	extern ImVec4 fovcircleColor;
	extern ImVec4 M249Color;
	extern ImVec4 MK12Color;

	extern ImVec4 hptColor;

}
