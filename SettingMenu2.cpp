#include "SettingMenu2.h"


//-----------AR Auto Weapon
ImVec4 weaponMenu2::m16 = { 255, 255, 0, 255 }; //= { 1.000f, 0.695f, 0.323f, 1.000f }; //{ 0.866f, 0.128f, 0.081f, 1.000f };
ImVec4  weaponMenu2::scarl = { 255, 255, 0, 255 }; //= { 1.000f, 0.695f, 0.323f, 1.000f };
ImVec4  weaponMenu2::AKM = { 255, 255, 0, 255 }; //= { 1.000f, 0.695f, 0.323f, 1.000f }; //{ 0.866f, 0.128f, 0.081f, 1.000f };
ImVec4  weaponMenu2::m762 = { 255, 255, 0, 255 }; //= { 1.000f, 0.695f, 0.323f, 1.000f }; //{ 0.118f, 0.76f, 0.788f, 1.000f };
ImVec4  weaponMenu2::DP28 = { 255, 255, 0, 255 }; //= { 1.000f, 0.695f, 0.323f, 1.000f }; //{ 0.118f, 0.76f, 0.788f, 1.000f };
ImVec4  weaponMenu2::GROZZA = { 255, 255, 0, 255 }; //= { 1.000f, 0.695f, 0.323f, 1.000f }; //{ 0.279f, 0.990f, 0.812f, 1.000f };
ImVec4  weaponMenu2::M249Color = { 0, 255, 0, 255 }; //= { 1.000f, 0.695f, 0.323f, 1.000f }; //{ 0.279f, 0.990f, 0.812f, 1.000f };

//----------Sniper Weapon
ImVec4  weaponMenu2::kar98 = { 255, 255, 0, 255 }; //= { 0.866f, 0.128f, 0.081f, 1.000f }; //{ 1.0f, 0.60f,0.05f, 1.0f };
ImVec4  weaponMenu2::M24 = { 255, 255, 0, 255 }; //= { 0.866f, 0.128f, 0.081f, 1.000f }; //{ 0.844f, 0.066f, 1.000f, 1.000f };
ImVec4  weaponMenu2::AWM = { 255, 255, 0, 255 }; //= { 0.866f, 0.128f, 0.081f, 1.000f }; //{ 1.000f, 0.089f, 0.089f, 1.000f };
ImVec4  weaponMenu2::AWMimmo = { 235, 255, 204, 255 }; //= { 0.942f, 0.300f, 0.073f, 1.000f };

//----------Weapon Ammo
extern	ImVec4 weaponMenu2::ammo7 = { ImColor(255, 211, 140, 255) }; //= { 0.500f, 1.000f, 0.000f, 1.000f };
extern	ImVec4 weaponMenu2::ammo5 = { ImColor(178, 245, 142, 255) }; //= { 0.000f, 1.000f, 0.000f, 1.000f };




//---------------drop
ImVec4  weaponMenu2::Airdrop = { ImColor(255, 255, 0, 255) }; //= { 0.279f, 0.990f, 0.812f, 1.000f };
ImVec4  weaponMenu2::Flare = { ImColor(255, 0, 0, 255) }; //= { 0.866f, 0.128f, 0.081f, 1.000f }; //{ 0.866f, 0.128f, 0.081f, 1.000f };
ImVec4  weaponMenu2::Flaregun = { ImColor(255, 0, 0, 255) }; //= { 0.866f, 0.128f, 0.081f, 1.000f }; //{ 1.0f, 0.60f,0.05f, 1.0f };

//---------------Scope
ImVec4 ScopeMenu2::scope2x = { 82, 194, 255, 255 }; //= { 0.874f, 0.484f, 0.106f, 1.000f };
ImVec4 ScopeMenu2::scope3x = { 82, 194, 255, 255 }; //= { 0.874f, 0.484f, 0.106f, 1.000f };
ImVec4 ScopeMenu2::scope4x = { 82, 194, 255, 255 }; //= { 0.937f, 0.063f, 0.937f, 1.000f };
ImVec4 ScopeMenu2::scope6x = { 247, 69, 117, 255 }; //= { 0.120f, 0.955f, 0.125f, 1.0f };
ImVec4 ScopeMenu2::scope8x = { 247, 69, 117, 255 }; //= { 0.866f, 0.128f, 0.081f, 1.000f };

ImVec4   ColorsMenu2::dp = { 255, 180, 0, 255 }; //= { 1.000f, 0.760f, 0.150f, 1.000f };
ImVec4   ColorsMenu2::mg3 = { 255, 180, 0, 255 }; //= { 0.373f, 0.966f, 0.391f, 1.000f};

ImVec4  ColorsMenu2::bag = { 0, 255, 242, 255 }; //= { 0.529f, 0.127f, 0.903f, 1.000f};
ImVec4  ColorsMenu2::armer = { 150, 100, 255, 255 }; //= {0.591f, 1.000f, 0.237f, 1.000f };
ImVec4  ColorsMenu2::helmat = { 150, 100, 255, 255 }; //= { 0.726f, 0.070f, 0.908f, 1.000f};
ImVec4  ColorsMenu2::mosin = { 240, 220, 0, 255 }; //= { 0.258f, 0.971f, 0.775f, 1.000f};
ImVec4   ColorsMenu2::aug = { 240, 220, 0, 255 }; //= { 0.442f, 0.971f, 0.122f, 1.000f};

ImVec4   ColorsMenu2::g36c = { 255, 255, 255, 255 }; //= { 0.671f, 0.217f, 1.000f, 1.000f};
ImVec4   ColorsMenu2::assm = { 255, 255, 255, 255 }; //= { 1.000f, 0.217f, 0.762f, 1.000f};

extern	ImVec4 ColorsMenu2::Grandes = { 255, 220, 0, 255 }; //= { 1.000f, 0.396f, 0.357f, 1.000f};
 //extern ImVec4 ColorsMenu2::Firstkit = { 255, 180, 255, 255 }; //= { 0.952f, 0.558f, 0.129f, 1.000f};
 //extern ImVec4 ColorsMenu2::Painkiller = { 255, 138, 241, 255 }; //= { 0.952f, 0.558f, 0.129f, 1.000f};
 //extern ImVec4 ColorsMenu2::AdrenalineSyringe = { 255, 140, 255, 255 }; //= { 0.952f, 0.558f, 0.129f, 1.000f};

// color s

 /////////////////////////
 ////bot
bool SettingMenu2::botname = true;
bool SettingMenu2::botnameShow = false;
bool SettingMenu2::botline = false;
bool SettingMenu2::botBone = true;
bool SettingMenu2::bothealth = true;
bool SettingMenu2::botfullbox = false;
bool SettingMenu2::botcornerbox = false;
bool SettingMenu2::botblood = true;
bool SettingMenu2::botdistance = true;
bool SettingMenu2::botweapon = true;
//
extern float SettingMenu2::BotNamesizestyle1 = 15.0f; extern float SettingMenu2::BotNamesizestyle2 = 15.0f; extern float SettingMenu2::BotNamesizestyle3 = 15.0f;
extern float SettingMenu2::botDistancesizestyle1 = 15.0f; extern float SettingMenu2::botDistancesizestyle2 = 15.0f; extern float SettingMenu2::botDistancesizestyle3 = 15.0f;
extern float SettingMenu2::botweaponsizestyle1 = 15.0f; extern float SettingMenu2::botweaponsizestyle2 = 15.0f; extern float SettingMenu2::botweaponsizestyle3 = 15.0f;
extern float SettingMenu2::botlinesize = 1.0f;
extern float SettingMenu2::botfullboxsize = 1.0f;
extern float SettingMenu2::botcornerboxsize = 1.0f;
extern float SettingMenu2::botbonesize = 1.0f;

// Bot Color
ImVec4  SettingMenu2::bot = { 0.900f, 0.025f, 0.025f, 1.0f };
ImVec4  SettingMenu2::botlineColor;// = { 0.591f, 1.000f, 0.237f, 1.000f };
ImVec4  SettingMenu2::botcornerboxColor;// = { 1.0f, 0.70f,0.30f, 1.0f };
ImVec4  SettingMenu2::botfullboxColor;// = { 1.0f, 1.0f,0.0f, 1.0f };
ImVec4  SettingMenu2::botcorner = { 0.050f, 0.125f, 0.925f, 1.0f };
ImVec4  SettingMenu2::BotNameColorstyle1 = { ImColor(255, 255, 255, 255) }; ImVec4  SettingMenu2::BotNameColorstyle2 = { ImColor(0, 255, 255, 255) }; ImVec4  SettingMenu2::BotNameColorstyle3 = { ImColor(0, 255, 255, 255) };
ImVec4  SettingMenu2::BotDistanceColorstyle1 = { ImColor(0, 255, 0, 255) }; ImVec4  SettingMenu2::BotDistanceColorstyle2 = { ImColor(0, 255, 0, 255) }; ImVec4  SettingMenu2::BotDistanceColorstyle3 = { ImColor(0, 255, 0, 255) };
ImVec4  SettingMenu2::botweaponColorstyle1 = { ImColor(0, 170, 255, 255) }; ImVec4  SettingMenu2::botweaponColorstyle2 = { ImColor(255, 200, 0, 255) }; ImVec4  SettingMenu2::botweaponColorstyle3 = { ImColor(255, 165, 0, 255) };
ImVec4  SettingMenu2::bothealthColor = { ImColor(255, 255, 255, 255) }; //= { 0.95f, 0.125f, 0.825f, 1.0f };
ImVec4  SettingMenu2::botboneColor = { ImColor(255, 255, 255, 255) }; //= { 0.050f, 0.025f, 0.925f, 1.0f };


/////////////////////////
////playr
bool SettingMenu2::playername = true;
bool SettingMenu2::MeEnemyShow = false;
bool SettingMenu2::playerTeamId = true;
bool SettingMenu2::playernameBgColor = true;
bool SettingMenu2::playerline = true;
bool SettingMenu2::playerBone = true;
bool SettingMenu2::playerhealth = true;
bool SettingMenu2::playerfullbox = false;
bool SettingMenu2::playercornerbox = false;
bool SettingMenu2::playerblood = true;
bool SettingMenu2::playerdeadbox = true;
bool SettingMenu2::playerdeadboxitems = true;
bool SettingMenu2::AirDropBox = true;
bool SettingMenu2::AirDropBoxitems1 = true;
bool SettingMenu2::playerdistance = true;
bool SettingMenu2::playerweapon = true;

bool SettingMenu2::PlayerAiming = true;
bool SettingMenu2::PlayerStatus = false;
bool SettingMenu2::PlayerUID = false;
bool SettingMenu2::PlayerFlags = true;
bool SettingMenu2::PlayerFlagText = false;
bool SettingMenu2::PlayerFlagImage = true;
//
extern float SettingMenu2::Playerlinesize = 1.0f;
extern float SettingMenu2::Playercornerboxsize = 1.0f;
extern float SettingMenu2::Playerfullboxsize = 1.0f;
extern float SettingMenu2::Playerbonesize = 1.0f;
extern float SettingMenu2::PlayerNamesizestyle1 = 15.0f; extern float SettingMenu2::PlayerNamesizestyle2 = 15.0f; extern float SettingMenu2::PlayerNamesizestyle3 = 15.0f;
extern float SettingMenu2::PlayerDistancesizestyle1 = 15.0f; extern float SettingMenu2::PlayerDistancesizestyle2 = 15.0f; extern float SettingMenu2::PlayerDistancesizestyle3 = 15.0f;
extern float SettingMenu2::Playerweaponsizestyle1 = 15.0f; extern float SettingMenu2::Playerweaponsizestyle2 = 15.0f; extern float SettingMenu2::Playerweaponsizestyle3 = 15.0f;
extern float SettingMenu2::PlayerLootBoxSize = 16;
extern float SettingMenu2::PlayerLootBoxItemsSize = 15;

extern float SettingMenu2::AirDropBoxSize = 16;
extern float SettingMenu2::AirDropBoxItemsSize = 15;

// Player Color
ImVec4  SettingMenu2::player = { ImColor(255, 255, 0, 255) }; //= { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4  SettingMenu2::playerlineColor;// = { ImColor(255, 255, 255, 255) }; //= { 0.591f, 1.000f, 0.237f, 1.000f };
ImVec4  SettingMenu2::playerboneColor = { ImColor(255, 255, 255, 255) }; //= { 0.591f, 1.000f, 0.237f, 1.000f };
ImVec4  SettingMenu2::playercornerboxColor;// = { ImColor(255, 255, 255, 255) }; //= { 1.0f, 0.70f,0.30f, 1.0f };
ImVec4  SettingMenu2::playerfullboxColor;// = { ImColor(255, 255, 255, 255) }; //= { 1.0f, 1.0f,0.0f, 1.0f };
ImVec4  SettingMenu2::PlayerNameColorstyle1 = { ImColor(255, 255, 255, 255) }; ImVec4  SettingMenu2::PlayerNameColorstyle2 = { ImColor(255, 255, 0, 255) }; ImVec4  SettingMenu2::PlayerNameColorstyle3 = { ImColor(0, 255, 255, 255) };
ImVec4  SettingMenu2::PlayerDistanceColorstyle1 = { ImColor(0, 255, 0, 255) }; ImVec4  SettingMenu2::PlayerDistanceColorstyle2 = { ImColor(0, 255, 0, 255) }; ImVec4  SettingMenu2::PlayerDistanceColorstyle3 = { ImColor(0, 255, 0, 255) };
ImVec4  SettingMenu2::playerweaponColorstyle1 = { ImColor(0, 170, 255, 255) };  ImVec4  SettingMenu2::playerweaponColorstyle2 = { ImColor(255, 200, 0, 255) }; ImVec4  SettingMenu2::playerweaponColorstyle3 = { ImColor(255, 165, 0, 255) };
ImVec4  SettingMenu2::playerhealthColor = { ImColor(255, 255, 255, 255) }; //= { 0.50f, 0.725f, 0.105f, 1.0f };
ImVec4  SettingMenu2::PlayerDeadboxColor = { ImColor(255, 0, 0, 255) }; //{ 0.737f, 1.000f, 0.000f, 1.000f };

ImVec4  SettingMenu2::AirDropBoxColor = { ImColor(255, 230, 130, 255) }; //{ 0.737f, 1.000f, 0.000f, 1.000f };


ImVec4  ColorsMenu2::itemcolors;// = { 1.000f, 0.100f, 0.401f, 1.000f };

ImVec4  ColorsMenu2::lotboxColor = { 1.0f, 1.0f,0.0f, 1.0f };
// ARGB
ImVec4  ColorsMenu2::helthbar = { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4  ColorsMenu2::boxColor = { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4  ColorsMenu2::cornerColor = { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4  ColorsMenu2::crosshairColor = { 0.950f, 0.125f, 0.125f, 1.0f };


//ImVec4  ColorsMenu2::vehicle = { 0.737f, 1.000f, 0.000f, 1.000f };
//ImVec4  ColorsMenu2::vehicle = { 255, 255, 0, 255 };
//RGB
ImVec4 ColorsMenu2::circle = { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4 ColorsMenu2::enemy = { 0, 255, 255, 255 };
ImVec4 ColorsMenu2::bone = { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4 ColorsMenu2::fillrect = { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4 ColorsMenu2::nam = { 247, 255, 0, 255 };






ImVec4 ColorsMenu2::nambarColor = { 0.880f, 0.185f, 0.25f, 1.0f };

ImVec4 ColorsMenu2::textColor = { 240, 220, 0, 255 }; //= { 0.500f, 0.150f, 0.125f, 1.0f };

ImVec4 ColorsMenu2::GranadesColor = { 0.990f, 0.995f, 0.995f, 1.0f };
ImVec4 ColorsMenu2::healthColor = { 0.108f, 1.000f, 1.000f, 1.000f };
ImVec4 ColorsMenu2::deadboxitemColor = { 1.000f, 0.100f, 0.401f, 1.000f };
ImVec4 ColorsMenu2::AirDropBoxitemColor = { 1.000f, 0.100f, 0.401f, 1.000f };
ImVec4 ColorsMenu2::airdropColor = { 255, 255, 0, 255 }; //= { 1.000f, 0.695f, 0.323f, 1.000f };
ImVec4 ColorsMenu2::airdropitemColor = { 0.300f, 0.695f, 0.323f, 1.000f };
ImVec4 ColorsMenu2::scopetextColor = { 0.000f, 0.995f, 0.995f, 1.000f };
ImVec4 ColorsMenu2::allitemColor = { 0.034f, 1.000f, 0.040f, 1.000f };
ImVec4 ColorsMenu2::magiclineColor = { 255, 0, 0, 255 };
ImVec4 ColorsMenu2::bgcornerColor = { 255, 0, 0, 255 };
ImVec4 ColorsMenu2::fovcircleColor = { ImColor(255, 255, 255, 80) }; //= { 255, 0, 0, 255 };


ImVec4 ColorsMenu2::skelec = { 255, 255, 255, 255 };
ImVec4 ColorsMenu2::skelec1;/* = { 255, 255, 255, 255 };*/

ImVec4  ColorsMenu2::hptColor = { 255, 255, 255, 255 };

//if (GetAsyncKeyState(VK_F5) & 1)
//{
//	SettingMenu2::Aimbot = !SettingMenu2::Aimbot;
//}


//int SettingMenu2::AimbotKey = 0 + (VK_RBUTTON);
//int SettingMenu2::AimbotKey = 0;
//int SettingMenu2::fastrunkey = 0 + (VK_LSHIFT);

ImVec4  SettingMenu2::plancolor = { 255, 230, 130, 255 }; //= { 0.737f, 1.000f, 0.000f, 1.000f };
ImVec4  SettingMenu2::dotss = { 0.950f, 0.125f, 0.925f, 1.0f };


ImVec4 ColorsMenu2::Smoke_Color = { ImColor(255, 125, 125, 255) };
ImVec4 ColorsMenu2::Grenade_Color = { ImColor(255, 0, 0, 255) };
ImVec4 ColorsMenu2::Molotof_Color = { ImColor(255, 65, 51, 255) };
ImVec4 ColorsMenu2::Burn_Color = { ImColor(255, 65, 51, 255) };

ImVec4 ColorsMenu2::ammo_5_56mm = { ImColor(22, 174, 0, 255) };
ImVec4 ColorsMenu2::ammo_7_62mm = { ImColor(172, 108, 0, 255) };
ImVec4 ColorsMenu2::ammo_9mm = { ImColor(0, 171, 154, 255) };
ImVec4 ColorsMenu2::ammo_45ACP = { ImColor(0, 171, 154, 255) };
ImVec4 ColorsMenu2::ammo_sniper = { ImColor(174, 174, 0, 255) };
ImVec4 ColorsMenu2::ammo_Flare_Gun = { ImColor(174, 12, 0, 255) };

ImVec4 ColorsMenu2::weapon_7mm = { ImColor(255, 198, 0, 255) };
ImVec4 ColorsMenu2::weapon_5mm = { ImColor(0, 255, 0, 255) };
ImVec4 ColorsMenu2::weapon_smg = { ImColor(182, 253, 255, 255) };
ImVec4 ColorsMenu2::weapon_sniper = { ImColor(255, 255, 0, 255) };
ImVec4 ColorsMenu2::weapon_Flare_Gun = { ImColor(255, 0, 0, 255) };

ImVec4 ColorsMenu2::Holo = { ImColor(169, 206, 255, 255) };
ImVec4 ColorsMenu2::Red_Dot = { ImColor(169, 206, 255, 255) };
ImVec4 ColorsMenu2::scope_2x = { ImColor(79, 207, 255, 255) };
ImVec4 ColorsMenu2::scope_3x = { ImColor(79, 180, 255, 255) };
ImVec4 ColorsMenu2::scope_4x = { ImColor(0, 153, 227, 255) };
ImVec4 ColorsMenu2::scope_6x = { ImColor(255, 91, 79, 255) };
ImVec4 ColorsMenu2::scope_8x = { ImColor(255, 91, 79, 255) };

ImVec4 ColorsMenu2::Bandage = { ImColor(0, 255, 153, 255) };
ImVec4 ColorsMenu2::EnergyDrink = { ImColor(209, 145, 255, 255) };
ImVec4 ColorsMenu2::Painkiller = { ImColor(255, 79, 242, 255) };
ImVec4 ColorsMenu2::Firstkit = { ImColor(255, 125, 242, 255) };
ImVec4 ColorsMenu2::Madkit = { ImColor(255, 0, 0, 255) };
ImVec4 ColorsMenu2::AdrenalineSyringe = { ImColor(255, 0, 0, 255) };

ImVec4 ColorsMenu2::Bag_lv1 = { ImColor(151, 151, 255, 255) };
ImVec4 ColorsMenu2::Bag_lv2 = { ImColor(133, 133, 255, 255) };
ImVec4 ColorsMenu2::Bag_lv3 = { ImColor(255, 121, 121, 255) };

ImVec4 ColorsMenu2::Helmet_lv1 = { ImColor(107, 174, 206, 255) };
ImVec4 ColorsMenu2::Helmet_lv2 = { ImColor(112, 191, 225, 255) };
ImVec4 ColorsMenu2::Helmet_lv3 = { ImColor(255, 91, 79, 255) };

ImVec4 ColorsMenu2::Armor_lv1 = { ImColor(124, 157, 255, 255) };
ImVec4 ColorsMenu2::Armor_lv2 = { ImColor(119, 153, 255, 255) };
ImVec4 ColorsMenu2::Armor_lv3 = { ImColor(255, 91, 79, 255) };

ImVec4 ColorsMenu2::MK12Color = { 1.00f, 0.796f, 0.715f, 1.0f };



float SettingMenu2::AR_Weaponsize = 15.0f;

bool SettingMenu2::Esp_Item_M416 = true;
ImVec4 SettingMenu2::Esp_Item_M416C = { ImColor(0, 255, 0, 255) };
float SettingMenu2::Esp_Item_M416T = 15.0f;

bool SettingMenu2::Esp_Item_SCARL = true;
ImVec4 SettingMenu2::Esp_Item_SCARLC = { ImColor(0, 255, 0, 255) };
float SettingMenu2::Esp_Item_SCARLT = 15.0f;

bool SettingMenu2::Esp_Item_M16A4 = true;
ImVec4 SettingMenu2::Esp_Item_M16A4C = { ImColor(0, 255, 0, 255) };
float SettingMenu2::Esp_Item_M16A4T = 15.0f;

bool SettingMenu2::Esp_Item_FAMAS = true;
ImVec4 SettingMenu2::Esp_Item_FAMASC = { ImColor(0, 255, 0, 255) };
float SettingMenu2::Esp_Item_FAMAST = 15.0f;

bool SettingMenu2::Esp_Item_G36C = true;
ImVec4 SettingMenu2::Esp_Item_G36CC = { ImColor(0, 255, 0, 255) };
float SettingMenu2::Esp_Item_G36CT = 15.0f;

bool SettingMenu2::Esp_Item_QBZ = true;
ImVec4 SettingMenu2::Esp_Item_QBZC = { ImColor(0, 255, 0, 255) };
float SettingMenu2::Esp_Item_QBZT = 15.0f;

bool SettingMenu2::Esp_Item_QBU = true;
ImVec4 SettingMenu2::Esp_Item_QBUC = { ImColor(0, 255, 0, 255) };
float SettingMenu2::Esp_Item_QBUT = 15.0f;

bool SettingMenu2::Esp_Item_M249 = true;
ImVec4 SettingMenu2::Esp_Item_M249C = { ImColor(0, 255, 0, 255) };
float SettingMenu2::Esp_Item_M249T = 15.0f;

bool SettingMenu2::Esp_Item_MG3 = true;
ImVec4 SettingMenu2::Esp_Item_MG3C = { ImColor(0, 255, 0, 255) };
float SettingMenu2::Esp_Item_MG3T = 15.0f;


bool SettingMenu2::Esp_Item_AKM = true;
ImVec4 SettingMenu2::Esp_Item_AKMC = { ImColor(255, 170, 0, 255) };
float SettingMenu2::Esp_Item_AKMT = 15.0f;

bool SettingMenu2::Esp_Item_M762 = true;
ImVec4 SettingMenu2::Esp_Item_M762C = { ImColor(255, 170, 0, 255) };
float SettingMenu2::Esp_Item_M762T = 15.0f;

bool SettingMenu2::Esp_Item_DP28 = true;
ImVec4 SettingMenu2::Esp_Item_DP28C = { ImColor(255, 170, 0, 255) };
float SettingMenu2::Esp_Item_DP28T = 15.0f;

bool SettingMenu2::Esp_Item_Mk47Mutant = true;
ImVec4 SettingMenu2::Esp_Item_Mk47MutantC = { ImColor(255, 170, 0, 255) };
float SettingMenu2::Esp_Item_Mk47MutantT = 15.0f;

bool SettingMenu2::Esp_Item_Mk12 = true;
ImVec4 SettingMenu2::Esp_Item_Mk12C = { ImColor(255, 170, 0, 255) };
float SettingMenu2::Esp_Item_Mk12T = 15.0f;

bool SettingMenu2::Esp_Item_HoneyBadger = true;
ImVec4 SettingMenu2::Esp_Item_HoneyBadgerC = { ImColor(255, 170, 0, 255) };
float SettingMenu2::Esp_Item_HoneyBadgerT = 15.0f;

bool SettingMenu2::Esp_Golden_boot = true;
ImVec4 SettingMenu2::Esp_Golden_bootC = { ImColor(255, 170, 0, 255) };
float SettingMenu2::Esp_Golden_bootT = 15.0f;



float SettingMenu2::Sniper_Weaponsize = 15.0f;

bool SettingMenu2::Esp_Item_Awm = true;
ImVec4 SettingMenu2::Esp_Item_AwmC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::Esp_Item_AwmT = 15.0f;

bool SettingMenu2::Esp_Item_M24 = true;
ImVec4 SettingMenu2::Esp_Item_M24C = { ImColor(255, 255, 0, 255) };
float SettingMenu2::Esp_Item_M24T = 15.0f;

bool SettingMenu2::Esp_Item_Kar98k = true;
ImVec4 SettingMenu2::Esp_Item_Kar98kC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::Esp_Item_Kar98kT = 15.0f;

bool SettingMenu2::Esp_Item_SLR = true;
ImVec4 SettingMenu2::Esp_Item_SLRC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::Esp_Item_SLRT = 15.0f;

bool SettingMenu2::Esp_Item_SKS = true;
ImVec4 SettingMenu2::Esp_Item_SKSC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::Esp_Item_SKST = 15.0f;

bool SettingMenu2::Esp_Item_Mini14 = true;
ImVec4 SettingMenu2::Esp_Item_Mini14C = { ImColor(255, 255, 0, 255) };
float SettingMenu2::Esp_Item_Mini14T = 15.0f;

bool SettingMenu2::Esp_Item_VSS = true;
ImVec4 SettingMenu2::Esp_Item_VSSC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::Esp_Item_VSST = 15.0f;

bool SettingMenu2::Esp_Item_Win94 = true;
ImVec4 SettingMenu2::Esp_Item_Win94C = { ImColor(255, 255, 0, 255) };
float SettingMenu2::Esp_Item_Win94T = 15.0f;

bool SettingMenu2::Esp_Item_Mosin = true;
ImVec4 SettingMenu2::Esp_Item_MosinC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::Esp_Item_MosinT = 15.0f;

bool SettingMenu2::Esp_Item_Mk14 = true;
ImVec4 SettingMenu2::Esp_Item_Mk14C = { ImColor(255, 255, 0, 255) };
float SettingMenu2::Esp_Item_Mk14T = 15.0f;

bool SettingMenu2::MK12Sniper = true;
ImVec4 SettingMenu2::MK12SniperC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::MK12SniperT = 15.0f;

bool SettingMenu2::AMRSniper = true;
ImVec4 SettingMenu2::AMRSniperC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::AMRSniperT = 15.0f;


float SettingMenu2::SMG_Weaponsize = 15.0f;

bool SettingMenu2::Esp_Item_PP19 = false;
ImVec4 SettingMenu2::Esp_Item_PP19C = { ImColor(204, 222, 205, 255) };
float SettingMenu2::Esp_Item_PP19T = 15.0f;

bool SettingMenu2::Esp_Item_TommyGun = false;
ImVec4 SettingMenu2::Esp_Item_TommyGunC = { ImColor(204, 222, 205, 255) };
float SettingMenu2::Esp_Item_TommyGunT = 15.0f;

bool SettingMenu2::Esp_Item_MP5K = false;
ImVec4 SettingMenu2::Esp_Item_MP5KC = { ImColor(204, 222, 205, 255) };
float SettingMenu2::Esp_Item_MP5KT = 15.0f;

bool SettingMenu2::Esp_Item_UMP9 = false;
ImVec4 SettingMenu2::Esp_Item_UMP9C = { ImColor(204, 222, 205, 255) };
float SettingMenu2::Esp_Item_UMP9T = 15.0f;

bool SettingMenu2::Esp_Item_Vector = false;
ImVec4 SettingMenu2::Esp_Item_VectorC = { ImColor(204, 222, 205, 255) };
float SettingMenu2::Esp_Item_VectorT = 15.0f;

bool SettingMenu2::Esp_Item_Uzi = false;
ImVec4 SettingMenu2::Esp_Item_UziC = { ImColor(204, 222, 205, 255) };
float SettingMenu2::Esp_Item_UziT = 15.0f;


float SettingMenu2::ShotGun_Weaponsize = 15.0f;

bool SettingMenu2::ShotGun_S686 = false;
ImVec4 SettingMenu2::ShotGun_S686C = { ImColor(222, 204, 204, 255) };
float SettingMenu2::ShotGun_S686T = 15.0f;

bool SettingMenu2::Esp_Item_DBS = false;
ImVec4 SettingMenu2::Esp_Item_DBSC = { ImColor(222, 204, 204, 255) };
float SettingMenu2::Esp_Item_DBST = 15.0f;

bool SettingMenu2::Esp_Item_S12K = false;
ImVec4 SettingMenu2::Esp_Item_S12KC = { ImColor(222, 204, 204, 255) };
float SettingMenu2::Esp_Item_S12KT = 15.0f;

bool SettingMenu2::Esp_Item_S1897 = false;
ImVec4 SettingMenu2::Esp_Item_S1897C = { ImColor(222, 204, 204, 255) };
float SettingMenu2::Esp_Item_S1897T = 15.0f;

bool SettingMenu2::Esp_Item_SawedOff = false;
ImVec4 SettingMenu2::Esp_Item_SawedOffC = { ImColor(222, 204, 204, 255) };
float SettingMenu2::Esp_Item_SawedOffT = 15.0f;

bool SettingMenu2::Esp_Item_M1014 = false;
ImVec4 SettingMenu2::Esp_Item_M1014C = { ImColor(222, 204, 204, 255) };
float SettingMenu2::Esp_Item_M1014T = 15.0f;


float SettingMenu2::Pistol_Weaponsize = 15.0f;

bool SettingMenu2::Esp_Item_FlareGun = true;
ImVec4 SettingMenu2::Esp_Item_FlareGunC = { ImColor(255, 0, 0, 255) };
float SettingMenu2::Esp_Item_FlareGunT = 15.0f;

bool SettingMenu2::Esp_Item_DesertEagle = false;
ImVec4 SettingMenu2::Esp_Item_DesertEagleC = { ImColor(204, 222, 222, 255) };
float SettingMenu2::Esp_Item_DesertEagleT = 15.0f;

bool SettingMenu2::Esp_Item_R1895 = false;
ImVec4 SettingMenu2::Esp_Item_R1895C = { ImColor(204, 222, 222, 255) };
float SettingMenu2::Esp_Item_R1895T = 15.0f;

bool SettingMenu2::Esp_Item_Vz61 = false;
ImVec4 SettingMenu2::Esp_Item_Vz61C = { ImColor(204, 222, 222, 255) };
float SettingMenu2::Esp_Item_Vz61T = 15.0f;

bool SettingMenu2::Esp_Item_P92 = false;
ImVec4 SettingMenu2::Esp_Item_P92C = { ImColor(204, 222, 222, 255) };
float SettingMenu2::Esp_Item_P92T = 15.0f;

bool SettingMenu2::Esp_Item_P18C = false;
ImVec4 SettingMenu2::Esp_Item_P18CC = { ImColor(204, 222, 222, 255) };
float SettingMenu2::Esp_Item_P18CT = 15.0f;

bool SettingMenu2::Esp_Item_R45 = false;
ImVec4 SettingMenu2::Esp_Item_R45C = { ImColor(204, 222, 222, 255) };
float SettingMenu2::Esp_Item_R45T = 15.0f;

bool SettingMenu2::Esp_Item_P1911 = false;
ImVec4 SettingMenu2::Esp_Item_P1911C = { ImColor(204, 222, 222, 255) };
float SettingMenu2::Esp_Item_P1911T = 15.0f;


float SettingMenu2::Other_Weaponsize = 15.0f;

bool SettingMenu2::Esp_Item_ExplosiveBow = false;
ImVec4 SettingMenu2::Esp_Item_ExplosiveBowC = { ImColor(204, 222, 222, 255) };
float SettingMenu2::Esp_Item_ExplosiveBowT = 15.0f;

bool SettingMenu2::Pan = false;
ImVec4 SettingMenu2::PanC = { ImColor(204, 222, 222, 255) };
float SettingMenu2::PanT = 15.0f;

bool SettingMenu2::Crowbar = false;
ImVec4 SettingMenu2::CrowbarC = { ImColor(204, 222, 222, 255) };
float SettingMenu2::CrowbarT = 15.0f;

bool SettingMenu2::Machete = false;
ImVec4 SettingMenu2::MacheteC = { ImColor(204, 222, 222, 255) };
float SettingMenu2::MacheteT = 15.0f;



float SettingMenu2::Ammosize = 15.0f;

bool SettingMenu2::Esp_Item_762mm = true;
ImVec4 SettingMenu2::Esp_Item_762mmC = { ImColor(226, 207, 150, 255) };
float SettingMenu2::Esp_Item_762mmT = 15.0f;

bool SettingMenu2::Esp_Item_556mm = true;
ImVec4 SettingMenu2::Esp_Item_556mmC = { ImColor(150, 220, 150, 255) };
float SettingMenu2::Esp_Item_556mmT = 15.0f;

bool SettingMenu2::Esp_Item_Awmimo = false;
ImVec4 SettingMenu2::Esp_Item_AwmimoC = { ImColor(200, 200, 150, 255) };
float SettingMenu2::Esp_Item_AwmimoT = 15.0f;

bool SettingMenu2::Ammo_50BMG = false;
ImVec4 SettingMenu2::Ammo_50BMGC = { ImColor(200, 200, 150, 255) };
float SettingMenu2::Ammo_50BMGT = 15.0f;

bool SettingMenu2::Esp_Item_9mm = false;
ImVec4 SettingMenu2::Esp_Item_9mmC = { ImColor(140, 160, 160, 255) };
float SettingMenu2::Esp_Item_9mmT = 15.0f;

bool SettingMenu2::Esp_Item_45ACP = false;
ImVec4 SettingMenu2::Esp_Item_45ACPC = { ImColor(140, 160, 160, 255) };
float SettingMenu2::Esp_Item_45ACPT = 15.0f;

bool SettingMenu2::Ammo_12Guage = false;
ImVec4 SettingMenu2::Ammo_12GuageC = { ImColor(140, 160, 160, 255) };
float SettingMenu2::Ammo_12GuageT = 15.0f;

bool SettingMenu2::Esp_Item_Flare = true;
ImVec4 SettingMenu2::Esp_Item_FlareC = { ImColor(220, 150, 150, 255) };
float SettingMenu2::Esp_Item_FlareT = 15.0f;



float SettingMenu2::HealthSize = 15.0f;

bool SettingMenu2::Esp_Item_Bandages = false;
ImVec4 SettingMenu2::Esp_Item_BandagesC = { ImColor(100, 220, 150, 255) };
float SettingMenu2::Esp_Item_BandagesT = 15.0f;

bool SettingMenu2::Esp_Item_EnergyDrink = true;
ImVec4 SettingMenu2::Esp_Item_EnergyDrinkC = { ImColor(220, 140, 255, 255) };
float SettingMenu2::Esp_Item_EnergyDrinkT = 15.0f;

bool SettingMenu2::Esp_Item_Painkiller = true;
ImVec4 SettingMenu2::Esp_Item_PainkillerC = { ImColor(240, 100, 255, 255) };
float SettingMenu2::Esp_Item_PainkillerT = 15.0f;

bool SettingMenu2::Esp_Item_FirstAidKit = true;
ImVec4 SettingMenu2::Esp_Item_FirstAidKitC = { ImColor(255, 100, 220, 255) };
float SettingMenu2::Esp_Item_FirstAidKitT = 15.0f;

bool SettingMenu2::Esp_Item_MedKit = true;
ImVec4 SettingMenu2::Esp_Item_MedKitC = { ImColor(255, 80, 150, 255) };
float SettingMenu2::Esp_Item_MedKitT = 15.0f;

bool SettingMenu2::Esp_Item_AdrenalineSyringe = true;
ImVec4 SettingMenu2::Esp_Item_AdrenalineSyringeC = { ImColor(240, 100, 255, 255) };
float SettingMenu2::Esp_Item_AdrenalineSyringeT = 15.0f;

bool SettingMenu2::BosterTree = true;
ImVec4 SettingMenu2::BosterTreeC = { ImColor(100, 220, 150, 255) };
float SettingMenu2::BosterTreeT = 15.0f;



float SettingMenu2::BagSize = 15.0f;

bool SettingMenu2::Esp_Item_Bag1 = false;
ImVec4 SettingMenu2::Esp_Item_Bag1C = { ImColor(151, 151, 255, 255) };
float SettingMenu2::Esp_Item_Bag1T = 15.0f;

bool SettingMenu2::Esp_Item_Bag2 = false;
ImVec4 SettingMenu2::Esp_Item_Bag2C = { ImColor(133, 133, 255, 255) };
float SettingMenu2::Esp_Item_Bag2T = 15.0f;

bool SettingMenu2::Esp_Item_Bag3 = true;
ImVec4 SettingMenu2::Esp_Item_Bag3C = { ImColor(0, 187, 255, 255) };
float SettingMenu2::Esp_Item_Bag3T = 15.0f;



float SettingMenu2::HelmetSize = 15.0f;

bool SettingMenu2::Esp_Item_Helmet1 = false;
ImVec4 SettingMenu2::Esp_Item_Helmet1C = { ImColor(107, 174, 206, 255) };
float SettingMenu2::Esp_Item_Helmet1T = 15.0f;

bool SettingMenu2::Esp_Item_Helmet2 = false;
ImVec4 SettingMenu2::Esp_Item_Helmet2C = { ImColor(112, 191, 225, 255) };
float SettingMenu2::Esp_Item_Helmet2T = 15.0f;

bool SettingMenu2::Esp_Item_Helmet3 = true;
ImVec4 SettingMenu2::Esp_Item_Helmet3C = { ImColor(0, 187, 255, 255) };
float SettingMenu2::Esp_Item_Helmet3T = 15.0f;



float SettingMenu2::ArmorSize = 15.0f;

bool SettingMenu2::Esp_Item_Armor1 = false;
ImVec4 SettingMenu2::Esp_Item_Armor1C = { ImColor(124, 157, 255, 255) };
float SettingMenu2::Esp_Item_Armor1T = 15.0f;

bool SettingMenu2::Esp_Item_Armor2 = false;
ImVec4 SettingMenu2::Esp_Item_Armor2C = { ImColor(119, 153, 255, 255) };
float SettingMenu2::Esp_Item_Armor2T = 15.0f;

bool SettingMenu2::Esp_Item_Armor3 = true;
ImVec4 SettingMenu2::Esp_Item_Armor3C = { ImColor(0, 187, 255, 255) };
float SettingMenu2::Esp_Item_Armor3T = 15.0f;



float SettingMenu2::ScopeSize = 15.0f;

bool SettingMenu2::RedDot = false;
ImVec4 SettingMenu2::RedDotC = { ImColor(126, 152, 255, 255) };
float SettingMenu2::RedDotT = 15.0f;

bool SettingMenu2::Esp_Item_Holo = false;
ImVec4 SettingMenu2::Esp_Item_HoloC = { ImColor(126, 152, 255, 255) };
float SettingMenu2::Esp_Item_HoloT = 15.0f;

bool SettingMenu2::Esp_Item_x2 = true;
ImVec4 SettingMenu2::Esp_Item_x2C = { ImColor(49, 137, 255, 255) };
float SettingMenu2::Esp_Item_x2T = 15.0f;

bool SettingMenu2::Esp_Item_x3 = true;
ImVec4 SettingMenu2::Esp_Item_x3C = { ImColor(49, 137, 255, 255) };
float SettingMenu2::Esp_Item_x3T = 15.0f;

bool SettingMenu2::Esp_Item_x4 = true;
ImVec4 SettingMenu2::Esp_Item_x4C = { ImColor(49, 137, 255, 255) };
float SettingMenu2::Esp_Item_x4T = 15.0f;

bool SettingMenu2::Esp_Item_x6 = true;
ImVec4 SettingMenu2::Esp_Item_x6C = { ImColor(255, 100, 100, 255) };
float SettingMenu2::Esp_Item_x6T = 15.0f;

bool SettingMenu2::Esp_Item_x8 = true;
ImVec4 SettingMenu2::Esp_Item_x8C = { ImColor(255, 55, 55, 255) };
float SettingMenu2::Esp_Item_x8T = 15.0f;



float SettingMenu2::GrenadeSize = 15.0f;

bool SettingMenu2::RedZoneBomb = true;
ImVec4 SettingMenu2::RedZoneBombC = { ImColor(255, 0, 0, 255) };
float SettingMenu2::RedZoneBombT = 15.0f;

bool SettingMenu2::GranedALL = true;

bool SettingMenu2::Esp_Item_Frag = true;
ImVec4 SettingMenu2::Esp_Item_FragC = { ImColor(255, 0, 0, 255) };
float SettingMenu2::Esp_Item_FragT = 15.0f;

bool SettingMenu2::Esp_Item_Grenade = true;
ImVec4 SettingMenu2::Esp_Item_GrenadeC = { ImColor(255, 0, 0, 255) };
float SettingMenu2::Esp_Item_GrenadeT = 15.0f;

bool SettingMenu2::Grenade_WarningALL = true;
ImVec4 SettingMenu2::Grenade_WarningALLC = { ImColor(255, 0, 0, 255) };
float SettingMenu2::Grenade_WarningALLT = 15.0f;

bool SettingMenu2::Grenade_Warning = true;
ImVec4 SettingMenu2::Grenade_WarningC = { ImColor(255, 0, 0, 255) };
float SettingMenu2::Grenade_WarningT = 15.0f;

bool SettingMenu2::Esp_Item_Molotof = true;
ImVec4 SettingMenu2::Esp_Item_MolotofC = { ImColor(255, 60, 120, 255) };
float SettingMenu2::Esp_Item_MolotofT = 15.0f;

bool SettingMenu2::Molotov_Warning = true;
ImVec4 SettingMenu2::Molotov_WarningC = { ImColor(255, 60, 120, 255) };
float SettingMenu2::Molotov_WarningT = 15.0f;

bool SettingMenu2::StunGrenade = true;
ImVec4 SettingMenu2::StunGrenadeC = { ImColor(59, 118, 212, 255) };
float SettingMenu2::StunGrenadeT = 15.0f;

bool SettingMenu2::StunGrenade_Warning = true;
ImVec4 SettingMenu2::StunGrenade_WarningC = { ImColor(255, 180, 220, 255) };
float SettingMenu2::StunGrenade_WarningT = 15.0f;

bool SettingMenu2::Esp_Item_Smoke = true;
ImVec4 SettingMenu2::Esp_Item_SmokeC = { ImColor(226, 200, 100, 255) };
float SettingMenu2::Esp_Item_SmokeT = 15.0f;

bool SettingMenu2::Smoke_Warning = true;
ImVec4 SettingMenu2::Smoke_WarningC = { ImColor(226, 200, 100, 255) };
float SettingMenu2::Smoke_WarningT = 15.0f;



bool SettingMenu2::allitemss = true;
ImVec4 SettingMenu2::allitemssC = { ImColor(255, 255, 255, 255) };
float SettingMenu2::allitemssT = 15;

bool SettingMenu2::impitems = true;
ImVec4 SettingMenu2::impitemsC = { ImColor(255, 255, 255, 255) };
float SettingMenu2::impitemsT = 15;

bool SettingMenu2::allweapons = true;
ImVec4 SettingMenu2::allweaponsC = { ImColor(255, 255, 255, 255) };
float SettingMenu2::allweaponsT = 15.0f;

bool SettingMenu2::allAmmos = true;
ImVec4 SettingMenu2::allAmmosC = { ImColor(255, 255, 255, 255) };
float SettingMenu2::allAmmosT = 15.0f;

bool SettingMenu2::allHealths = true;
ImVec4 SettingMenu2::allHealthsC = { ImColor(255, 255, 255, 255) };
float SettingMenu2::allHealthsT = 15.0f;

bool SettingMenu2::allBags = true;
ImVec4 SettingMenu2::allBagsC = { ImColor(255, 255, 255, 255) };
float SettingMenu2::allBagsT = 15.0f;

bool SettingMenu2::allHelmets = true;
ImVec4 SettingMenu2::allHelmetsC = { ImColor(255, 255, 255, 255) };
float SettingMenu2::allHelmetsT = 15.0f;

bool SettingMenu2::allArmors = true;
ImVec4 SettingMenu2::allArmorsC = { ImColor(255, 255, 255, 255) };
float SettingMenu2::allArmorsT = 15.0f;

bool SettingMenu2::allScopes = true;
ImVec4 SettingMenu2::allScopesC = { ImColor(255, 255, 255, 255) };
float SettingMenu2::allScopesT = 15.0f;

bool SettingMenu2::allGrenades = true;
ImVec4 SettingMenu2::allGrenadesC = { ImColor(255, 255, 255, 255) };
float SettingMenu2::allGrenadesT = 15.0f;

bool SettingMenu2::OthersItem = true;
ImVec4 SettingMenu2::OthersItemC = { ImColor(255, 255, 255, 255) };
float SettingMenu2::OthersItemT = 15.0f;

bool SettingMenu2::Vehicle = true;
ImVec4 SettingMenu2::VehicleColor = { ImColor(255, 255, 255, 255) };
float SettingMenu2::VehicleSize = 15;

bool SettingMenu2::Airplan = true;
ImVec4 SettingMenu2::AirplanC = { ImColor(255, 230, 130, 255) };
float SettingMenu2::AirplanT = 15.0f;

bool SettingMenu2::MoreItem = true;
ImVec4 SettingMenu2::MoreItemC = { ImColor(255, 255, 255, 255) };
float SettingMenu2::MoreItemT = 15.0f;

bool SettingMenu2::healthitem = true;
ImVec4 SettingMenu2::healthitemC = { ImColor(255, 255, 255, 255) };
float SettingMenu2::healthitemT = 15.0f;


bool SettingMenu2::Esp_Item_AirDrop = true;
ImVec4 SettingMenu2::Esp_Item_AirDropC = { ImColor(255, 91, 79, 255) };
float SettingMenu2::Esp_Item_AirDropT = 15.0f;

bool SettingMenu2::Esp_Item_LootBoxALL = true;
ImVec4 SettingMenu2::Esp_Item_LootBoxALLC = { ImColor(255, 91, 79, 255) };
float SettingMenu2::Esp_Item_LootBoxALLT = 15.0f;


//New Add
bool SettingMenu2::LionDanceCar = true;
ImVec4 SettingMenu2::LionDanceCarC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::LionDanceCarT = 15.0f;

bool SettingMenu2::BRDM = true;
ImVec4 SettingMenu2::BRDMC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::BRDMT = 15.0f;

bool SettingMenu2::Scooter = true;
ImVec4 SettingMenu2::ScooterC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::ScooterT = 15.0f;

bool SettingMenu2::Motorcycle = true;
ImVec4 SettingMenu2::MotorcycleC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::MotorcycleT = 15.0f;

bool SettingMenu2::Snowmobile = true;
ImVec4 SettingMenu2::SnowmobileC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::SnowmobileT = 15.0f;

bool SettingMenu2::Tuk = true;
ImVec4 SettingMenu2::TukC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::TukT = 15.0f;

bool SettingMenu2::Buggy = true;
ImVec4 SettingMenu2::BuggyC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::BuggyT = 15.0f;

bool SettingMenu2::Sportsa = true;
ImVec4 SettingMenu2::SportsaC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::SportsaT = 15.0f;

bool SettingMenu2::Sports = true;
ImVec4 SettingMenu2::SportsC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::SportsT = 15.0f;

bool SettingMenu2::Dacia = true;
ImVec4 SettingMenu2::DaciaC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::DaciaT = 15.0f;

bool SettingMenu2::Rony = true;
ImVec4 SettingMenu2::RonyC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::RonyT = 15.0f;

bool SettingMenu2::UAZ = true;
ImVec4 SettingMenu2::UAZC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::UAZT = 15.0f;

bool SettingMenu2::Minibus = true;
ImVec4 SettingMenu2::MinibusC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::MinibusT = 15.0f;

bool SettingMenu2::PG117 = true;
ImVec4 SettingMenu2::PG117C = { ImColor(255, 255, 0, 255) };
float SettingMenu2::PG117T = 15.0f;

bool SettingMenu2::Aquarail = true;
ImVec4 SettingMenu2::AquarailC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::AquarailT = 15.0f;

bool SettingMenu2::ModelYTesla = true;
ImVec4 SettingMenu2::ModelYTeslaC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::ModelYTeslaT = 15.0f;

bool SettingMenu2::GravityMotorcycle = true;
ImVec4 SettingMenu2::GravityMotorcycleC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::GravityMotorcycleT = 15.0f;

bool SettingMenu2::Glider = true;
ImVec4 SettingMenu2::GliderC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::GliderT = 15.0f;

bool SettingMenu2::UTV = true;
ImVec4 SettingMenu2::UTVC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::UTVT = 15.0f;

bool SettingMenu2::MonstarTruck = true;
ImVec4 SettingMenu2::MonstarTruckC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::MonstarTruckT = 15.0f;

bool SettingMenu2::Coupe_NewDacia = true;
ImVec4 SettingMenu2::Coupe_NewDaciaC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::Coupe_NewDaciaT = 15.0f;

bool SettingMenu2::Quad = true;
ImVec4 SettingMenu2::QuadC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::QuadT = 15.0f;

bool SettingMenu2::Snow_Bike = true;
ImVec4 SettingMenu2::Snow_BikeC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::Snow_BikeT = 15.0f;

bool SettingMenu2::PickUp = true;
ImVec4 SettingMenu2::PickUpC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::PickUpT = 15.0f;



float SettingMenu2::MoreItemSize = 15.0f;

bool SettingMenu2::EmergencyCallPickup = false;
ImVec4 SettingMenu2::EmergencyCallPickupC = { ImColor(0, 255, 255, 255) };
float SettingMenu2::EmergencyCallPickupT = 15.0f;

bool SettingMenu2::KungFuSteamedBun = true;
ImVec4 SettingMenu2::KungFuSteamedBunC = { ImColor(212, 212, 212, 255) };
float SettingMenu2::KungFuSteamedBunT = 15.0f;

bool SettingMenu2::LionDance = false;
ImVec4 SettingMenu2::LionDanceC = { ImColor(255, 255, 0, 255) };
float SettingMenu2::LionDanceT = 15.0f;

bool SettingMenu2::GrapplingHook = false;
ImVec4 SettingMenu2::GrapplingHookC = { ImColor(212, 212, 212, 255) };
float SettingMenu2::GrapplingHookT = 15.0f;

bool SettingMenu2::ShopToken = false;
ImVec4 SettingMenu2::ShopTokenC = { ImColor(231, 237, 190, 255) };
float SettingMenu2::ShopTokenT = 15.0f;

bool SettingMenu2::SupplyShop = false;
ImVec4 SettingMenu2::SupplyShopC = { ImColor(255, 255, 255, 255) };
float SettingMenu2::SupplyShopT = 15.0f;

bool SettingMenu2::ZoneRadiation = true;
ImVec4 SettingMenu2::ZoneRadiationC = { ImColor(0, 255, 0, 255) };
float SettingMenu2::ZoneRadiationT = 15.0f;

bool SettingMenu2::WINMVPStatue = true;
ImVec4 SettingMenu2::WINMVPStatueC = { ImColor(255, 255, 255, 255) };
float SettingMenu2::WINMVPStatueT = 15.0f;

bool SettingMenu2::PlaceSelected = true;
ImVec4 SettingMenu2::PlaceSelectedC = { ImColor(255, 255, 255, 255) };
float SettingMenu2::PlaceSelectedT = 15.0f;

bool SettingMenu2::ThumbGrip = false;
ImVec4 SettingMenu2::ThumbGripC = { ImColor(212, 212, 212, 255) };
float SettingMenu2::ThumbGripT = 15.0f;

bool SettingMenu2::LightGrip = false;
ImVec4 SettingMenu2::LightGripC = { ImColor(212, 212, 212, 255) };
float SettingMenu2::LightGripT = 15.0f;

bool SettingMenu2::FlashHiderSniper = false;
ImVec4 SettingMenu2::FlashHiderSniperC = { ImColor(212, 212, 212, 255) };
float SettingMenu2::FlashHiderSniperT = 15.0f;

bool SettingMenu2::CompensatorSniper = false;
ImVec4 SettingMenu2::CompensatorSniperC = { ImColor(212, 212, 212, 255) };
float SettingMenu2::CompensatorSniperT = 15.0f;

bool SettingMenu2::SuppressorSniper = false;
ImVec4 SettingMenu2::SuppressorSniperC = { ImColor(212, 212, 212, 255) };
float SettingMenu2::SuppressorSniperT = 15.0f;

bool SettingMenu2::QuickdrawMagSniper = false;
ImVec4 SettingMenu2::QuickdrawMagSniperC = { ImColor(212, 212, 212, 255) };
float SettingMenu2::QuickdrawMagSniperT = 15.0f;

bool SettingMenu2::ExtendedMagSniper = false;
ImVec4 SettingMenu2::ExtendedMagSniperC = { ImColor(212, 212, 212, 255) };
float SettingMenu2::ExtendedMagSniperT = 15.0f;

bool SettingMenu2::ExtendedQuickdrawMagSniper = false;
ImVec4 SettingMenu2::ExtendedQuickdrawMagSniperC = { ImColor(255, 255, 255, 255) };
float SettingMenu2::ExtendedQuickdrawMagSniperT = 15.0f;

bool SettingMenu2::TacticalStockSMG = false;
ImVec4 SettingMenu2::TacticalStockSMGC = { ImColor(212, 212, 212, 255) };
float SettingMenu2::TacticalStockSMGT = 15.0f;

bool SettingMenu2::ChokeSG = false;
ImVec4 SettingMenu2::ChokeSGC = { ImColor(212, 212, 212, 255) };
float SettingMenu2::ChokeSGT = 15.0f;

bool SettingMenu2::FlashHiderSMG = false;
ImVec4 SettingMenu2::FlashHiderSMGC = { ImColor(212, 212, 212, 255) };
float SettingMenu2::FlashHiderSMGT = 15.0f;

bool SettingMenu2::CompensatorSMG = false;
ImVec4 SettingMenu2::CompensatorSMGC = { ImColor(212, 212, 212, 255) };
float SettingMenu2::CompensatorSMGT = 15.0f;

bool SettingMenu2::SuppressorSMG = false;
ImVec4 SettingMenu2::SuppressorSMGC = { ImColor(212, 212, 212, 255) };
float SettingMenu2::SuppressorSMGT = 15.0f;

bool SettingMenu2::FlashHiderAR = false;
ImVec4 SettingMenu2::FlashHiderARC = { ImColor(212, 212, 212, 255) };
float SettingMenu2::FlashHiderART = 15.0f;

bool SettingMenu2::CompensatorAR = false;
ImVec4 SettingMenu2::CompensatorARC = { ImColor(212, 212, 212, 255) };
float SettingMenu2::CompensatorART = 15.0f;

bool SettingMenu2::SuppressorAR = false;
ImVec4 SettingMenu2::SuppressorARC = { ImColor(212, 212, 212, 255) };
float SettingMenu2::SuppressorART = 15.0f;

bool SettingMenu2::QuickdrawMagAR = false;
ImVec4 SettingMenu2::QuickdrawMagARC = { ImColor(212, 212, 212, 255) };
float SettingMenu2::QuickdrawMagART = 15.0f;

bool SettingMenu2::ExtendedMagAR = false;
ImVec4 SettingMenu2::ExtendedMagARC = { ImColor(212, 212, 212, 255) };
float SettingMenu2::ExtendedMagART = 15.0f;

bool SettingMenu2::ExtendedQuickdrawMagAR = false;
ImVec4 SettingMenu2::ExtendedQuickdrawMagARC = { ImColor(255, 255, 255, 255) };
float SettingMenu2::ExtendedQuickdrawMagART = 15.0f;


bool SettingMenu2::watermark = false;
ImVec4 SettingMenu2::watermarkC = { ImColor(255, 255, 255, 255) };
float SettingMenu2::watermarkT = 15.0f;

bool SettingMenu2::Expred_Date = false;
ImVec4 SettingMenu2::Expred_DateC = { ImColor(255, 255, 255, 255) };
float SettingMenu2::Expred_DateT = 15.0f;

int SettingMenu2::MagicBulletKey = 0 + (VK_LBUTTON);
int SettingMenu2::AimbotKey = 0 + (VK_RBUTTON);
int SettingMenu2::SniperModeKey = 0 + (VK_LBUTTON);
int SettingMenu2::fastrunkey = 0;
int SettingMenu2::PositionKey = 0;
int SettingMenu2::EnableKey = 0;
bool  SettingMenu2::plan = true;
bool SettingMenu2::ShowMenu2 = false;
int SettingMenu2::a45ACP = 12;
int SettingMenu2::a9mm = 12;
int SettingMenu2::a556mm = 12;
extern int a556mm;
int SettingMenu2::a762mm = 12;
DWORD SettingMenu2::CurrentTargetAddress = 0;
bool SettingMenu2::dots = false;
bool SettingMenu2::dots1 = true;
bool SettingMenu2::dots2 = false;
bool SettingMenu2::radar = true;
int	SettingMenu2::RadarLength = 150;
int	SettingMenu2::RadarWidth = 150;
extern float SettingMenu2::PlayerMAxDistance = 350.0f;

int SettingMenu2::redioption = 1;
bool SettingMenu2::redioption2 = false;
bool SettingMenu2::IsMagicInitialize = false;
bool SettingMenu2::Magntic = false;
bool SettingMenu2::AimHead = true;
bool SettingMenu2::AimBody = true;
float SettingMenu2::Aimspeed = 11;
int	SettingMenu2::curraim = 0;
char  SettingMenu2::filename[] = "C:\\megHack.ini";
float SettingMenu2::fontsize = 15;
float SettingMenu2::AllItemsSize = 15;
float SettingMenu2::Normalfontsize = 15;
float SettingMenu2::Normalfontsize2 = 1.700;
float SettingMenu2::Normalfontsize3 = 200;
float SettingMenu2::Normalfontsize4 = 80;
float SettingMenu2::Normalfontsize5 = 300;
extern float SettingMenu2::weaponsize = 15.0f;
int SettingMenu2::psize1 = 17;

bool SettingMenu2::Esp_Item_AirAttack = true;
int SettingMenu2::SuperUp = 0 + ('X');
int SettingMenu2::SuperDown = 0 + (VK_DOWN);
int SettingMenu2::SuperRight = 0 + (VK_RIGHT);
int SettingMenu2::SuperLeft = 0 + (VK_LEFT);
int SettingMenu2::SuperFront = 0 + (VK_UP);
bool SettingMenu2::antiscreen = false;
bool SettingMenu2::FastParachute = false;
bool SettingMenu2::fackSetting1 = false;
bool SettingMenu2::fackSetting2 = false;
bool SettingMenu2::fackSetting3 = false;
bool SettingMenu2::fackSetting4 = false;
bool SettingMenu2::fackSetting5 = false;
bool SettingMenu2::fackSetting6 = false;
bool SettingMenu2::fackSetting7 = false;
bool SettingMenu2::fackSetting8 = false;
bool SettingMenu2::fackSetting9 = false;
bool SettingMenu2::fackSetting10 = false;
bool SettingMenu2::fackSetting11 = false;
bool SettingMenu2::fackSetting12 = false;
bool SettingMenu2::fackMoreOption = false;
bool SettingMenu2::fackMoreOptionHide = false;
bool SettingMenu2::VngGameEsp = false;
int SettingMenu2::Flymankey = 0;
int SettingMenu2::Backcarkey = 0;
int SettingMenu2::Fastcarkey = 0;
int SettingMenu2::landspeed = 0;
int SettingMenu2::FastParachutekey = 0;
bool SettingMenu2::Luffy = false;
bool SettingMenu2::Legitrack = false;
bool SettingMenu2::RandomTracking = true;
bool SettingMenu2::SkipBots = false;
bool SettingMenu2::Redzome = true;
int SettingMenu2::AirAttack = 15;
bool SettingMenu2::Flags = true;
bool SettingMenu2::ScreenX = false;
bool SettingMenu2::FlagText = false;
bool SettingMenu2::viplogin = true;
bool SettingMenu2::freelogin = false;
bool SettingMenu2::SafeMode = false;
bool SettingMenu2::DangerMode = true;
bool SettingMenu2::MagicX = false;
bool SettingMenu2::bortext = true;
bool SettingMenu2::TeamIdLine = true;
int SettingMenu2::IPADSIZE = 110;
int SettingMenu2::IPADSIZE1 = 80;
extern float SettingMenu2::Namesize = 15.0f;
int SettingMenu2::IpadViewValue = 360.0f;
bool SettingMenu2::knocked = true;
bool SettingMenu2::aimbotposition = true;
float SettingMenu2::fovcircleredus = 80.0f;
bool SettingMenu2::fovcircle = false;
bool SettingMenu2::fovcircle2 = false;
ImVec4 SettingMenu2::colorcode;
bool SettingMenu2::boxitemBagShadow = false;
bool SettingMenu2::SuperView1 = false;
float SettingMenu2::SuperViewPower = 420.0f;
int SettingMenu2::intGO = 1.0f;
int SettingMenu2::intV = 550.0f;
bool SettingMenu2::fightmode = false;
bool SettingMenu2::MAgicline = true;
bool SettingMenu2::feul = true;
bool SettingMenu2::hp = true;
bool SettingMenu2::style1 = true;
bool SettingMenu2::style2 = false;
bool SettingMenu2::style3 = false;
bool SettingMenu2::style4 = false;
bool SettingMenu2::Bags = true;
bool SettingMenu2::Armer = false;
bool SettingMenu2::Helmat = true;
bool SettingMenu2::airdrop = false;
bool SettingMenu2::airdropitem = true;
bool SettingMenu2::itemrect = true;
bool SettingMenu2::ShowMenu = true;
bool SettingMenu2::profree = false;
bool SettingMenu2::Name = true;
bool SettingMenu2::Distance = true;
bool SettingMenu2::TotalEnemy = true;
bool SettingMenu2::TotalEnemyStyle1 = true;
bool SettingMenu2::TotalEnemyStyle2 = false;
bool SettingMenu2::TotalEnemyStyle3 = false;
bool SettingMenu2::Gameinfo = true;
bool SettingMenu2::MyInfo = false;
bool SettingMenu2::TrainingGrounds_ModelEsp = false;
bool SettingMenu2::Line = false;
bool SettingMenu2::Box = false;
bool SettingMenu2::Bone = true;
bool SettingMenu2::Health = false;
bool SettingMenu2::BombAlert = false;
bool SettingMenu2::Item = true;
bool SettingMenu2::luffy = false;
bool SettingMenu2::ipadview = false;
bool SettingMenu2::noheadshot = false;
bool SettingMenu2::smallcrosshair = false;
bool SettingMenu2::engine = 0;
bool SettingMenu2::skele = 0;
bool SettingMenu2::scope = true;
bool SettingMenu2::instanthit = false;
bool SettingMenu2::instanthitDNG = false;
bool SettingMenu2::fastrun = false;
bool SettingMenu2::fly = false;
bool SettingMenu2::carfly = false;
bool SettingMenu2::speedcar = false;
bool SettingMenu2::recoil = false;
bool SettingMenu2::recoil2 = false;
bool SettingMenu2::vahicle_item = true;
bool SettingMenu2::Aimbot = false;
bool SettingMenu2::SniperMode = false;
bool SettingMenu2::MagicBullet_E_D = false;
bool SettingMenu2::MagicBullet = false;
bool SettingMenu2::ShowStatusMagicBullet = true;
bool SettingMenu2::ShowStatusAimPosition = false;
bool SettingMenu2::MagicBulletDNG = false;
bool SettingMenu2::silent = false;
bool SettingMenu2::borderlo = true;
bool SettingMenu2::CameraCatch = false;
bool SettingMenu2::SuperView = false;
bool SettingMenu2::SuperViewDNG = false;
bool SettingMenu2::SuperViewA = false;
bool SettingMenu2::grw = true;
bool SettingMenu2::molow = true;;
bool SettingMenu2::magicb = false;
bool SettingMenu2::NINEFPS = false;
float SettingMenu2::flyPower = 900.0f;
int	SettingMenu2::magicv = 7;
int	SettingMenu2::flycarv = 300.0f;
int	SettingMenu2::instantv = 700.0f;
int	SettingMenu2::carsv = 300.0f;
int	SettingMenu2::fastrv = 3.0f;

char  SettingMenu2::PathSetting[] = "C:\\Windows\\meg_VIP_Setting.ini";

string SettingMenu2::GameState;
string SettingMenu2::GameState1;
int SettingMenu2::AlivePlayers;
int SettingMenu2::TimeRemind;
int SettingMenu2::AliveTeams;
int SettingMenu2::RealPlayers;
int SettingMenu2::ZoneID;
int SettingMenu2::MyTeamID;
int SettingMenu2::GameID;
bool SettingMenu2::StatusDiscord = true;

int SettingMenu2::UpdateTick = 10;
int SettingMenu2::hpbt = 0;
int SettingMenu2::RadioButton_BotHP = 0;
int SettingMenu2::RadioButton_PlayerHP = 0;
int SettingMenu2::RadioButton_CarHP = 0;

bool SettingMenu2::HapSizeMenu = true;
bool SettingMenu2::FullSizeMenu = false;
bool SettingMenu2::MoveAndCustomiseMenu = false;


