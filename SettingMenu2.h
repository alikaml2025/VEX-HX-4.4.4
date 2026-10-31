#pragma once

#include "Includes.h"
#include "imgui-docking/imgui.h"
#include "imgui-docking/imgui_impl_win32.h"
#include "imgui-docking/imgui_impl_dx11.h"
#include "imgui-docking/imgui_internal.h"
typedef struct
{
	DWORD R;
	DWORD G;
	DWORD B;
	DWORD A;
}RGBAMenu2;
///SAVE COLOR///

namespace weaponMenu2 {


	extern ImVec4 m16 ;
	extern ImVec4 scarl;
	extern ImVec4 AKM ;
	extern ImVec4 m762;
	extern ImVec4 DP28;
	extern ImVec4 GROZZA;
	extern ImVec4 M249Color;


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

namespace ScopeMenu2 {

	extern ImVec4 scope2x;
	extern ImVec4 scope3x;
	extern ImVec4 scope4x;
	extern ImVec4 scope6x;
	extern ImVec4 scope8x;
}

namespace ColorsMenu2 {

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
	extern ImVec4 AirDropBoxitemColor;
	extern ImVec4 airdropColor;
	extern ImVec4 airdropitemColor;
	extern ImVec4 scopetextColor;
	extern ImVec4 allitemColor;
	extern ImVec4 magiclineColor;
	extern ImVec4 bgcornerColor;
	extern ImVec4 fovcircleColor;
	extern ImVec4 MK12Color;

	extern ImVec4 hptColor;

	
}

namespace SettingMenu2
{
	/////////////////////////
	// Bot Color
	extern	ImVec4  botcorner;
	extern	ImVec4  botlineColor;
	extern	ImVec4  botfullboxColor;
	extern	ImVec4  botcornerboxColor;
	extern	ImVec4  bot;
	extern	ImVec4  botboneColor;
	extern	ImVec4  BotNameColorstyle1; extern	ImVec4  BotNameColorstyle2; extern	ImVec4  BotNameColorstyle3;
	extern	ImVec4  BotDistanceColorstyle1; extern	ImVec4  BotDistanceColorstyle2; extern	ImVec4  BotDistanceColorstyle3;
	extern	ImVec4  botweaponColorstyle1; extern	ImVec4  botweaponColorstyle2; extern	ImVec4  botweaponColorstyle3;
	extern	ImVec4  bothealthColor;



	/////////////////////////
	// Player Color
	extern	ImVec4  playerlineColor;
	extern	ImVec4  playerboneColor;
	extern	ImVec4  playercornerboxColor;
	extern	ImVec4  playerfullboxColor;
	extern	ImVec4  player;
	extern	ImVec4  PlayerNameColorstyle1; extern	ImVec4  PlayerNameColorstyle2; extern	ImVec4  PlayerNameColorstyle3;
	extern	ImVec4  PlayerDistanceColorstyle1; extern	ImVec4  PlayerDistanceColorstyle2; extern	ImVec4  PlayerDistanceColorstyle3;
	extern	ImVec4  playerweaponColorstyle1; extern	ImVec4  playerweaponColorstyle2; extern	ImVec4  playerweaponColorstyle3;
	extern	ImVec4  playerhealthColor;
	extern  ImVec4  PlayerDeadboxColor;

	extern  ImVec4  AirDropBoxColor;

	//bot
	extern bool botname, botnameShow, botline, botBone, bothealth, botdistance, botweapon, botfullbox, botcornerbox, botblood;

	//
	extern float BotNamesizestyle1; extern float BotNamesizestyle2; extern float BotNamesizestyle3;
	extern float botDistancesizestyle1; extern float botDistancesizestyle2; extern float botDistancesizestyle3;
	extern float botweaponsizestyle1; extern float botweaponsizestyle2; extern float botweaponsizestyle3;
	extern float BotDissize;
	extern float botlinesize;
	extern float botfullboxsize;
	extern float botcornerboxsize;
	extern float botbonesize;


	//playr
	extern bool playername, MeEnemyShow, playerTeamId, playernameBgColor, playerline, playerBone, playerhealth, playerdistance, playerfullbox, playercornerbox, playerblood;
	extern bool playerweapon;
	extern bool playerdeadbox;
	extern bool playerdeadboxitems;
	extern bool AirDropBox;
	extern bool AirDropBoxitems1;

	extern bool PlayerAiming;
	extern bool PlayerStatus;
	extern bool PlayerUID;
	extern bool PlayerFlags;
	extern bool PlayerFlagText;
	extern bool PlayerFlagImage;
	//

	extern float Playerlinesize;
	extern float Playercornerboxsize;
	extern float Playerfullboxsize;
	extern float Playerbonesize;
	extern float PlayerNamesizestyle1; extern float PlayerNamesizestyle2; extern float PlayerNamesizestyle3;
	extern float PlayerDistancesizestyle1; extern float PlayerDistancesizestyle2; extern float PlayerDistancesizestyle3;
	extern float Playerweaponsizestyle1; extern float Playerweaponsizestyle2; extern float Playerweaponsizestyle3;
	extern float PlayerLootBoxSize;
	extern float PlayerLootBoxItemsSize;

	extern float AirDropBoxSize;
	extern float AirDropBoxItemsSize;

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
	extern int a45ACP;
	extern int a9mm;
	extern int a556mm;
	extern int a762mm;
	extern DWORD CurrentTargetAddress;

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
	extern bool fackMoreOptionHide;
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
	extern int AirAttack;

	extern bool Flags;
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
	extern int MagicBulletKey;
	extern int AimbotKey;
	extern int SniperModeKey;

	extern int fastrunkey;
	extern int PositionKey;
	extern	bool dots;
	extern	bool dots1;
	extern	bool dots2;
	extern	bool radar;
	extern int  RadarLength;
	extern int  RadarWidth;
	extern float PlayerMAxDistance;

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
	extern float fontsize;
	extern float AllItemsSize;
	extern float Normalfontsize;
	extern float Normalfontsize2;
	extern float Normalfontsize3;
	extern float Normalfontsize4;
	extern float Normalfontsize5;

	extern bool Esp_Item_AirAttack;


	extern float weaponsize;
	extern int psize1;
	extern float Namesize;
	extern int IpadViewValue;

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
	extern bool MyInfo;
	extern bool TrainingGrounds_ModelEsp;
	extern bool Line;
	extern bool Box;
	extern bool Bone;
	extern bool Health;
	extern bool BombAlert;
	extern bool Item;

	extern bool LionDanceCar;
	extern ImVec4 LionDanceCarC;
	extern float LionDanceCarT;

	extern bool BRDM;
	extern ImVec4 BRDMC;
	extern float BRDMT;

	extern bool Scooter;
	extern ImVec4 ScooterC;
	extern float ScooterT;

	extern bool Motorcycle;
	extern ImVec4 MotorcycleC;
	extern float MotorcycleT;

	extern bool Snowmobile;
	extern ImVec4 SnowmobileC;
	extern float SnowmobileT;

	extern bool Tuk;
	extern ImVec4 TukC;
	extern float TukT;

	extern bool Buggy;
	extern ImVec4 BuggyC;
	extern float BuggyT;

	extern bool Sportsa;
	extern ImVec4 SportsaC;
	extern float SportsaT;

	extern bool Sports;
	extern ImVec4 SportsC;
	extern float SportsT;

	extern bool Dacia;
	extern ImVec4 DaciaC;
	extern float DaciaT;

	extern bool Rony;
	extern ImVec4 RonyC;
	extern float RonyT;

	extern bool UAZ;
	extern ImVec4 UAZC;
	extern float UAZT;

	extern bool Minibus;
	extern ImVec4 MinibusC;
	extern float MinibusT;

	extern bool PG117;
	extern ImVec4 PG117C;
	extern float PG117T;

	extern bool Aquarail;
	extern ImVec4 AquarailC;
	extern float AquarailT;

	extern bool ModelYTesla;
	extern ImVec4 ModelYTeslaC;
	extern float ModelYTeslaT;

	extern bool GravityMotorcycle;
	extern ImVec4 GravityMotorcycleC;
	extern float GravityMotorcycleT;

	extern bool Glider;
	extern ImVec4 GliderC;
	extern float GliderT;

	extern bool UTV;
	extern ImVec4 UTVC;
	extern float UTVT;

	extern bool MonstarTruck;
	extern ImVec4 MonstarTruckC;
	extern float MonstarTruckT;

	extern bool Coupe_NewDacia;
	extern ImVec4 Coupe_NewDaciaC;
	extern float Coupe_NewDaciaT;

	extern bool Quad;
	extern ImVec4 QuadC;
	extern float QuadT;

	extern bool Snow_Bike;
	extern ImVec4 Snow_BikeC;
	extern float Snow_BikeT;

	extern bool PickUp;
	extern ImVec4 PickUpC;
	extern float PickUpT;

	extern bool hp;
	extern bool feul;

	extern bool scope;


	extern bool instanthit;
	extern bool instanthitDNG;
	extern bool fastrun;
	extern bool fly;
	extern bool carfly;
	extern bool speedcar;
	extern bool recoil;
	extern bool recoil2;
	
	extern bool luffy;
	extern bool ipadview;
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
	
	extern bool MagicX ;
	extern bool plan;
	extern ImVec4 plancolor;
	extern ImVec4 dotss;
	extern bool vahicle_item;



	extern float MoreItemSize;

	extern bool EmergencyCallPickup;
	extern ImVec4 EmergencyCallPickupC;
	extern float EmergencyCallPickupT;

	extern bool KungFuSteamedBun;
	extern ImVec4 KungFuSteamedBunC;
	extern float KungFuSteamedBunT;

	extern bool LionDance;
	extern ImVec4 LionDanceC;
	extern float LionDanceT;

	extern bool GrapplingHook;
	extern ImVec4 GrapplingHookC;
	extern float GrapplingHookT;

	extern bool ShopToken;
	extern ImVec4 ShopTokenC;
	extern float ShopTokenT;

	extern bool SupplyShop;
	extern ImVec4 SupplyShopC;
	extern float SupplyShopT;

	extern bool ZoneRadiation;
	extern ImVec4 ZoneRadiationC;
	extern float ZoneRadiationT;

	extern bool WINMVPStatue;
	extern ImVec4 WINMVPStatueC;
	extern float WINMVPStatueT;

	extern bool PlaceSelected;
	extern ImVec4 PlaceSelectedC;
	extern float PlaceSelectedT;

	extern bool ThumbGrip;
	extern ImVec4 ThumbGripC;
	extern float ThumbGripT;

	extern bool LightGrip;
	extern ImVec4 LightGripC;
	extern float LightGripT;

	extern bool FlashHiderSniper;
	extern ImVec4 FlashHiderSniperC;
	extern float FlashHiderSniperT;

	extern bool CompensatorSniper;
	extern ImVec4 CompensatorSniperC;
	extern float CompensatorSniperT;

	extern bool SuppressorSniper;
	extern ImVec4 SuppressorSniperC;
	extern float SuppressorSniperT;

	extern bool QuickdrawMagSniper;
	extern ImVec4 QuickdrawMagSniperC;
	extern float QuickdrawMagSniperT;

	extern bool ExtendedMagSniper;
	extern ImVec4 ExtendedMagSniperC;
	extern float ExtendedMagSniperT;

	extern bool ExtendedQuickdrawMagSniper;
	extern ImVec4 ExtendedQuickdrawMagSniperC;
	extern float ExtendedQuickdrawMagSniperT;

	extern bool TacticalStockSMG;
	extern ImVec4 TacticalStockSMGC;
	extern float TacticalStockSMGT;

	extern bool ChokeSG;
	extern ImVec4 ChokeSGC;
	extern float ChokeSGT;

	extern bool FlashHiderSMG;
	extern ImVec4 FlashHiderSMGC;
	extern float FlashHiderSMGT;

	extern bool CompensatorSMG;
	extern ImVec4 CompensatorSMGC;
	extern float CompensatorSMGT;

	extern bool SuppressorSMG;
	extern ImVec4 SuppressorSMGC;
	extern float SuppressorSMGT;

	extern bool FlashHiderAR;
	extern ImVec4 FlashHiderARC;
	extern float FlashHiderART;

	extern bool CompensatorAR;
	extern ImVec4 CompensatorARC;
	extern float CompensatorART;

	extern bool SuppressorAR;
	extern ImVec4 SuppressorARC;
	extern float SuppressorART;

	extern bool QuickdrawMagAR;
	extern ImVec4 QuickdrawMagARC;
	extern float QuickdrawMagART;

	extern bool ExtendedMagAR;
	extern ImVec4 ExtendedMagARC;
	extern float ExtendedMagART;

	extern bool ExtendedQuickdrawMagAR;
	extern ImVec4 ExtendedQuickdrawMagARC;
	extern float ExtendedQuickdrawMagART;

	extern bool watermark;
	extern ImVec4 watermarkC;
	extern float watermarkT;

	extern bool Expred_Date;
	extern ImVec4 Expred_DateC;
	extern float Expred_DateT;



	extern float AR_Weaponsize;

	extern bool Esp_Item_M416;
	extern ImVec4 Esp_Item_M416C;
	extern float Esp_Item_M416T;

	extern bool Esp_Item_SCARL;
	extern ImVec4 Esp_Item_SCARLC;
	extern float Esp_Item_SCARLT;

	extern bool Esp_Item_M16A4;
	extern ImVec4 Esp_Item_M16A4C;
	extern float Esp_Item_M16A4T;

	extern bool Esp_Item_FAMAS;
	extern ImVec4 Esp_Item_FAMASC;
	extern float Esp_Item_FAMAST;

	extern bool Esp_Item_G36C;
	extern ImVec4 Esp_Item_G36CC;
	extern float Esp_Item_G36CT;

	extern bool Esp_Item_QBZ;
	extern ImVec4 Esp_Item_QBZC;
	extern float Esp_Item_QBZT;

	extern bool Esp_Item_QBU;
	extern ImVec4 Esp_Item_QBUC;
	extern float Esp_Item_QBUT;

	extern bool Esp_Item_M249;
	extern ImVec4 Esp_Item_M249C;
	extern float Esp_Item_M249T;

	extern bool Esp_Item_MG3;
	extern ImVec4 Esp_Item_MG3C;
	extern float Esp_Item_MG3T;


	extern bool Esp_Item_AKM;
	extern ImVec4 Esp_Item_AKMC;
	extern float Esp_Item_AKMT;

	extern bool Esp_Item_M762;
	extern ImVec4 Esp_Item_M762C;
	extern float Esp_Item_M762T;

	extern bool Esp_Item_DP28;
	extern ImVec4 Esp_Item_DP28C;
	extern float Esp_Item_DP28T;

	extern bool Esp_Item_Mk47Mutant;
	extern ImVec4 Esp_Item_Mk47MutantC;
	extern float Esp_Item_Mk47MutantT;

	extern bool Esp_Item_Mk12;
	extern ImVec4 Esp_Item_Mk12C;

	extern float Esp_Item_Mk12T;
	extern bool Esp_Item_HoneyBadger;
	extern ImVec4 Esp_Item_HoneyBadgerC;
	extern float Esp_Item_HoneyBadgerT;

	extern bool Esp_Golden_boot;
	extern ImVec4 Esp_Golden_bootC;
	extern float Esp_Golden_bootT;


	extern float Sniper_Weaponsize;

	extern bool Esp_Item_Awm;
	extern ImVec4 Esp_Item_AwmC;
	extern float Esp_Item_AwmT;

	extern bool Esp_Item_M24;
	extern ImVec4 Esp_Item_M24C;
	extern float Esp_Item_M24T;

	extern bool Esp_Item_Kar98k;
	extern ImVec4 Esp_Item_Kar98kC;
	extern float Esp_Item_Kar98kT;

	extern bool Esp_Item_SLR;
	extern ImVec4 Esp_Item_SLRC;
	extern float Esp_Item_SLRT;

	extern bool Esp_Item_SKS;
	extern ImVec4 Esp_Item_SKSC;
	extern float Esp_Item_SKST;

	extern bool Esp_Item_Mini14;
	extern ImVec4 Esp_Item_Mini14C;
	extern float Esp_Item_Mini14T;

	extern bool Esp_Item_VSS;
	extern ImVec4 Esp_Item_VSSC;
	extern float Esp_Item_VSST;

	extern bool Esp_Item_Win94;
	extern ImVec4 Esp_Item_Win94C;
	extern float Esp_Item_Win94T;

	extern bool Esp_Item_Mosin;
	extern ImVec4 Esp_Item_MosinC;
	extern float Esp_Item_MosinT;

	extern bool Esp_Item_Mk14;
	extern ImVec4 Esp_Item_Mk14C;
	extern float Esp_Item_Mk14T;

	extern bool MK12Sniper;
	extern ImVec4 MK12SniperC;
	extern float MK12SniperT;

	extern bool AMRSniper;
	extern ImVec4 AMRSniperC;
	extern float AMRSniperT;


	extern float SMG_Weaponsize;

	extern bool Esp_Item_PP19;
	extern ImVec4 Esp_Item_PP19C;
	extern float Esp_Item_PP19T;

	extern bool Esp_Item_TommyGun;
	extern ImVec4 Esp_Item_TommyGunC;
	extern float Esp_Item_TommyGunT;

	extern bool Esp_Item_MP5K;
	extern ImVec4 Esp_Item_MP5KC;
	extern float Esp_Item_MP5KT;

	extern bool Esp_Item_UMP9;
	extern ImVec4 Esp_Item_UMP9C;
	extern float Esp_Item_UMP9T;

	extern bool Esp_Item_Vector;
	extern ImVec4 Esp_Item_VectorC;
	extern float Esp_Item_VectorT;

	extern bool Esp_Item_Uzi;
	extern ImVec4 Esp_Item_UziC;
	extern float Esp_Item_UziT;

	
	extern float ShotGun_Weaponsize;

	extern bool ShotGun_S686;
	extern ImVec4 ShotGun_S686C;
	extern float ShotGun_S686T;

	extern bool Esp_Item_DBS;
	extern ImVec4 Esp_Item_DBSC;
	extern float Esp_Item_DBST;

	extern bool Esp_Item_S12K;
	extern ImVec4 Esp_Item_S12KC;
	extern float Esp_Item_S12KT;

	extern bool Esp_Item_S1897;
	extern ImVec4 Esp_Item_S1897C;
	extern float Esp_Item_S1897T;

	extern bool Esp_Item_SawedOff;
	extern ImVec4 Esp_Item_SawedOffC;
	extern float Esp_Item_SawedOffT;

	extern bool Esp_Item_M1014;
	extern ImVec4 Esp_Item_M1014C;
	extern float Esp_Item_M1014T;


	extern float Pistol_Weaponsize;

	extern bool Esp_Item_FlareGun;
	extern ImVec4 Esp_Item_FlareGunC;
	extern float Esp_Item_FlareGunT;

	extern bool Esp_Item_DesertEagle;
	extern ImVec4 Esp_Item_DesertEagleC;
	extern float Esp_Item_DesertEagleT;

	extern bool Esp_Item_R1895;
	extern ImVec4 Esp_Item_R1895C;
	extern float Esp_Item_R1895T;

	extern bool Esp_Item_Vz61;
	extern ImVec4 Esp_Item_Vz61C;
	extern float Esp_Item_Vz61T;

	extern bool Esp_Item_P92;
	extern ImVec4 Esp_Item_P92C;
	extern float Esp_Item_P92T;

	extern bool Esp_Item_P18C;
	extern ImVec4 Esp_Item_P18CC;
	extern float Esp_Item_P18CT;

	extern bool Esp_Item_R45;
	extern ImVec4 Esp_Item_R45C;
	extern float Esp_Item_R45T;

	extern bool Esp_Item_P1911;
	extern ImVec4 Esp_Item_P1911C;
	extern float Esp_Item_P1911T;


	extern float Other_Weaponsize;

	extern bool Esp_Item_ExplosiveBow;
	extern ImVec4 Esp_Item_ExplosiveBowC;
	extern float Esp_Item_ExplosiveBowT;

	extern bool Pan;
	extern ImVec4 PanC;
	extern float PanT;

	extern bool Crowbar;
	extern ImVec4 CrowbarC;
	extern float CrowbarT;

	extern bool Machete;
	extern ImVec4 MacheteC;
	extern float MacheteT;



	extern float Ammosize;

	extern bool Esp_Item_762mm;
	extern ImVec4 Esp_Item_762mmC;
	extern float Esp_Item_762mmT;

	extern bool Esp_Item_556mm;
	extern ImVec4 Esp_Item_556mmC;
	extern float Esp_Item_556mmT;

	extern bool Esp_Item_Awmimo;
	extern ImVec4 Esp_Item_AwmimoC;
	extern float Esp_Item_AwmimoT;

	extern bool Ammo_50BMG;
	extern ImVec4 Ammo_50BMGC;
	extern float Ammo_50BMGT;

	extern bool Esp_Item_9mm;
	extern ImVec4 Esp_Item_9mmC;
	extern float Esp_Item_9mmT;

	extern bool Esp_Item_45ACP;
	extern ImVec4 Esp_Item_45ACPC;
	extern float Esp_Item_45ACPT;

	extern bool Ammo_12Guage;
	extern ImVec4 Ammo_12GuageC;
	extern float Ammo_12GuageT;

	extern bool Esp_Item_Flare;
	extern ImVec4 Esp_Item_FlareC;
	extern float Esp_Item_FlareT;



	extern float HealthSize;

	extern bool Esp_Item_Bandages;
	extern ImVec4 Esp_Item_BandagesC;
	extern float Esp_Item_BandagesT;

	extern bool Esp_Item_EnergyDrink;
	extern ImVec4 Esp_Item_EnergyDrinkC;
	extern float Esp_Item_EnergyDrinkT;

	extern bool Esp_Item_Painkiller;
	extern ImVec4 Esp_Item_PainkillerC;
	extern float Esp_Item_PainkillerT;

	extern bool Esp_Item_AdrenalineSyringe;
	extern ImVec4 Esp_Item_AdrenalineSyringeC;
	extern float Esp_Item_AdrenalineSyringeT;

	extern bool Esp_Item_FirstAidKit;
	extern ImVec4 Esp_Item_FirstAidKitC;
	extern float Esp_Item_FirstAidKitT;

	extern bool Esp_Item_MedKit;
	extern ImVec4 Esp_Item_MedKitC;
	extern float Esp_Item_MedKitT;

	extern bool BosterTree;
	extern ImVec4 BosterTreeC;
	extern float BosterTreeT;



	extern float BagSize;

	extern bool Esp_Item_Bag1;
	extern ImVec4 Esp_Item_Bag1C;
	extern float Esp_Item_Bag1T;

	extern bool Esp_Item_Bag2;
	extern ImVec4 Esp_Item_Bag2C;
	extern float Esp_Item_Bag2T;

	extern bool Esp_Item_Bag3;
	extern ImVec4 Esp_Item_Bag3C;
	extern float Esp_Item_Bag3T;



	extern float HelmetSize;

	extern bool Esp_Item_Helmet1;
	extern ImVec4 Esp_Item_Helmet1C;
	extern float Esp_Item_Helmet1T;

	extern bool Esp_Item_Helmet2;
	extern ImVec4 Esp_Item_Helmet2C;
	extern float Esp_Item_Helmet2T;

	extern bool Esp_Item_Helmet3;
	extern ImVec4 Esp_Item_Helmet3C;



	extern float ArmorSize;

	extern float Esp_Item_Helmet3T;
	extern bool Esp_Item_Armor1;
	extern ImVec4 Esp_Item_Armor1C;
	extern float Esp_Item_Armor1T;

	extern bool Esp_Item_Armor2;
	extern ImVec4 Esp_Item_Armor2C;
	extern float Esp_Item_Armor2T;

	extern bool Esp_Item_Armor3;
	extern ImVec4 Esp_Item_Armor3C;
	extern float Esp_Item_Armor3T;



	extern float ScopeSize;

	extern bool RedDot;
	extern ImVec4 RedDotC;
	extern float RedDotT;

	extern bool Esp_Item_Holo;
	extern ImVec4 Esp_Item_HoloC;
	extern float Esp_Item_HoloT;

	extern bool Esp_Item_x2;
	extern ImVec4 Esp_Item_x2C;
	extern float Esp_Item_x2T;

	extern bool Esp_Item_x3;
	extern ImVec4 Esp_Item_x3C;
	extern float Esp_Item_x3T;

	extern bool Esp_Item_x4;
	extern ImVec4 Esp_Item_x4C;
	extern float Esp_Item_x4T;

	extern bool Esp_Item_x6;
	extern ImVec4 Esp_Item_x6C;
	extern float Esp_Item_x6T;

	extern bool Esp_Item_x8;
	extern ImVec4 Esp_Item_x8C;
	extern float Esp_Item_x8T;



	extern float GrenadeSize;

	extern bool RedZoneBomb;
	extern ImVec4 RedZoneBombC;
	extern float RedZoneBombT;

	extern bool GranedALL;

	extern bool Esp_Item_Frag;
	extern ImVec4 Esp_Item_FragC;
	extern float Esp_Item_FragT;

	extern bool Esp_Item_Grenade;
	extern ImVec4 Esp_Item_GrenadeC;
	extern float Esp_Item_GrenadeT;

	extern bool Grenade_WarningALL;
	extern ImVec4 Grenade_WarningALLC;
	extern float Grenade_WarningALLT;

	extern bool Grenade_Warning;
	extern ImVec4 Grenade_WarningC;
	extern float Grenade_WarningT;

	extern bool Esp_Item_Molotof;
	extern ImVec4 Esp_Item_MolotofC;
	extern float Esp_Item_MolotofT;

	extern bool Molotov_Warning;
	extern ImVec4 Molotov_WarningC;
	extern float Molotov_WarningT;

	extern bool StunGrenade;
	extern ImVec4 StunGrenadeC;
	extern float StunGrenadeT;

	extern bool StunGrenade_Warning;
	extern ImVec4 StunGrenade_WarningC;
	extern float StunGrenade_WarningT;

	extern bool Esp_Item_Smoke;
	extern ImVec4 Esp_Item_SmokeC;
	extern float Esp_Item_SmokeT;

	extern bool Smoke_Warning;
	extern ImVec4 Smoke_WarningC;
	extern float Smoke_WarningT;



	extern bool allitemss;
	extern ImVec4 allitemssC;
	extern float allitemssT;

	extern bool impitems;
	extern ImVec4 impitemsC;
	extern float impitemsT;

	extern bool allweapons;
	extern ImVec4 allweaponsC;
	extern float allweaponsT;

	extern bool allAmmos;
	extern ImVec4 allAmmosC;
	extern float allAmmosT;

	extern bool allHealths;
	extern ImVec4 allHealthsC;
	extern float allHealthsT;

	extern bool allBags;
	extern ImVec4 allBagsC;
	extern float allBagsT;

	extern bool allHelmets;
	extern ImVec4 allHelmetsC;
	extern float allHelmetsT;

	extern bool allArmors;
	extern ImVec4 allArmorsC;
	extern float allArmorsT;

	extern bool allScopes;
	extern ImVec4 allScopesC;
	extern float allScopesT;

	extern bool allGrenades;
	extern ImVec4 allGrenadesC;
	extern float allGrenadesT;

	extern bool OthersItem;
	extern ImVec4 OthersItemC;
	extern float OthersItemT;

	extern bool Vehicle;
	extern ImVec4 VehicleColor;
	extern float VehicleSize;

	extern bool Airplan;
	extern ImVec4 AirplanC;
	extern float AirplanT;

	extern bool MoreItem;
	extern ImVec4 MoreItemC;
	extern float MoreItemT;

	extern bool healthitem;
	extern ImVec4 healthitemC;
	extern float healthitemT;


	extern bool Esp_Item_AirDrop;
	extern ImVec4 Esp_Item_AirDropC;
	extern float Esp_Item_AirDropT;

	extern bool Esp_Item_LootBoxALL;
	extern ImVec4 Esp_Item_LootBoxALLC;
	extern float Esp_Item_LootBoxALLT;


	extern bool Aimbot;
	extern bool SniperMode;
	extern bool MagicBullet_E_D;
	extern bool MagicBullet;
	extern bool ShowStatusMagicBullet;
	extern bool ShowStatusAimPosition;
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
	extern bool molow;
	extern int	magicv;
	extern int	flycarv;
	extern int	instantv;
	extern int	carsv;
	extern int	fastrv;
	extern bool magicb;
	extern char PathSetting[];

	extern string GameState;
	extern string GameState1;
	extern int AlivePlayers;
	extern int TimeRemind;
	extern int AliveTeams;
	extern int RealPlayers;
	extern int ZoneID;
	extern int MyTeamID;
	extern int GameID;
	extern bool StatusDiscord;

	extern int UpdateTick;
	extern int hpbt;
	extern int RadioButton_BotHP;
	extern int RadioButton_PlayerHP;
	extern int RadioButton_CarHP;

	extern bool HapSizeMenu;
	extern bool FullSizeMenu;
	extern bool MoveAndCustomiseMenu;
}

