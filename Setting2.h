#pragma once

#include "Includes.h"
#include "imgui-docking/imgui.h"
#include "imgui-docking/imgui_impl_win32.h"
#include "imgui-docking/imgui_impl_dx11.h"
#include "imgui-docking/imgui_internal.h"

namespace weapon2 {


	extern ImVec4 m16 ;
	extern ImVec4 scarl;
	extern ImVec4 AKM ;
	extern ImVec4 m762;
	extern ImVec4 DP28;
	extern ImVec4 GROZZA;


	extern ImVec4 AWM ;
	extern ImVec4 AWMimmo;
	extern ImVec4 M24 ;
	extern ImVec4 kar98 ;

	extern ImVec4 Airdrop;
	extern ImVec4 Flare;
	extern ImVec4 Flaregun;

	extern ImVec4  ammo7;
	extern ImVec4  ammo5;
}

namespace Scope2 {

	extern ImVec4 scope2x;
	extern ImVec4 scope3x;
	extern ImVec4 scope4x;
	extern ImVec4 scope6x;
	extern ImVec4 scope8x;
}

namespace Colors2 {

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
	extern ImVec4  g36;
	extern ImVec4  assm;

	extern ImVec4  Grandes;

	extern ImVec4  madkit;
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

	extern ImVec4  VehicleColor;
	//RGB
	extern ImVec4 circle ;
	extern ImVec4  enemy ;
	extern ImVec4  bone;
	extern ImVec4  fillrect ;
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

	/////////////////////////
	// Bot Color
	extern	ImVec4  botcorner;
	extern	ImVec4  botlineColor;
	extern	ImVec4  botfullboxColor;
	extern	ImVec4  botcornerboxColor;
	extern	ImVec4  bot;
	extern	ImVec4  botboneColor;
	extern	ImVec4  BotNameColor;
	extern	ImVec4  BotDistanceColor;
	extern	ImVec4  botweaponColor;
	extern	ImVec4  bothealthColor;



	/////////////////////////
	// Player Color
	extern	ImVec4  playerlineColor;
	extern	ImVec4  playerboneColor;
	extern	ImVec4  playercornerboxColor;
	extern	ImVec4  playerfullboxColor;
	extern	ImVec4  player;
	extern	ImVec4  PlayerNameColor;
	extern	ImVec4  PlayerDistanceColor;
	extern	ImVec4  playerweaponColor;
	extern	ImVec4  playerhealthColor;
	extern  ImVec4  PlayerDeadboxColor;

	extern ImVec4  skelecT;
	extern ImVec4  skelec1;


}

namespace Setting2
{
	//bot
	extern bool botname, botline, botBone, bothealth, botdistance, botweapon, botfullbox, botcornerbox, botblood;

	//
	extern float BotNamesize;
	extern float BotDissize;
	extern float botlinesize;
	extern float botfullboxsize;
	extern float botcornerboxsize;
	extern float botbonesize;
	extern float botDistancesize;
	extern float botweaponsize;


	//playr
	extern bool playername, playerline, playerBone, playerhealth, playerdistance, playerfullbox, playercornerbox, playerblood;
	extern bool playerweapon;
	extern bool playerdeadbox;

	extern bool PlayerAiming;
	extern bool PlayerFlagText;
	extern bool PlayerFlagimge;
	extern bool PlayerFlags;

	//
	extern float PlayerLootBoxSize;
	extern float PlayerLootBoxItemsSize;
	extern float Playerlinesize;
	extern float Playercornerboxsize;
	extern float Playerfullboxsize;
	extern float Playerbonesize;
	extern float PlayerNamesize;
	extern float PlayerDistancesize;
	extern float Playerweaponsize;


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
	extern bool FlagText;

	//======================
	extern bool viplogin;
	extern bool freelogin;
	//======================
	extern bool SafeMode;
	extern bool DangerMode;
	//======================
	extern bool knocked;
	extern int EnableKey;
	extern int AimbotKey;
	extern int fastrunkey;
	extern int PositionKey;
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
	extern char filename[];
	extern float Normalfontsize;
	extern float Normalfontsize2;
	extern float fontsize;

	extern bool Esp_Item_AirAttack;

	extern float AllItemsSize;

	extern float weaponsize;
	extern int psize1;
	extern float Namesize;

	extern int VehicleSize;

	extern int IPADSIZE;
	extern int IPADSIZE1;

	extern bool silent;
	extern bool bortext;


	extern bool style1;
	extern bool style2;
	extern bool style3;
	extern bool style4;


	extern bool ShowMenu;
	extern bool profree;

	extern bool fightmode;
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
	extern bool Vehicle;
	extern bool hp;
	extern bool feul;

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
	extern int IpadViewValue;
	extern bool noheadshot;
	extern bool smallcrosshair;

	extern float flyPower;
	extern int intV;
	extern int intGO;

	extern bool airdrop;
	extern bool airdropitem;

	extern bool itemrect ;
	extern bool Bags;
	extern bool Helmat;
	extern bool Armer;

	extern	bool Esp_Item_M249 ;

	extern	bool Esp_Item_Mk12;
	
	extern bool MagicX ;
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
	extern bool Esp_Item_Awmimo ;
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

	extern bool TrainingGrounds_ModelEsp;
	extern bool MeEnemyShow;
	extern bool botnameShow;
	extern DWORD CurrentTargetAddress;
	extern	ImVec4  botboneColor;

}