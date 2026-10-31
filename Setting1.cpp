#include "Setting1.h"

bool Setting1::style1 = true;
bool Setting1::style2 = false;
bool Setting1::style3 = false;
bool Setting1::style4 = false;

////botOnOff======================================
bool Setting1::botname = true, Setting1::botline = true, Setting1::botBone = true, Setting1::bothealth = true, Setting1::botcornerbox = true,
Setting1::botfullbox = true, Setting1::botblood = true, Setting1::botdistance = true, Setting1::botweapon = true, Setting1::botWeapons_iconsH = true;
//bst1
bool Setting1::botst1name = true, Setting1::botst1line = true, Setting1::botst1Bone = true, Setting1::botst1health = true, Setting1::botst1cornerbox = true,
Setting1::botst1fullbox = false, Setting1::botst1blood = true, Setting1::botst1distance = true, Setting1::botst1weapon = true, Setting1::botst1Weapons_iconsH = false;
//bst2
bool Setting1::botst2name = true, Setting1::botst2line = true, Setting1::botst2Bone = true, Setting1::botst2health = true, Setting1::botst2cornerbox = false,
Setting1::botst2fullbox = false, Setting1::botst2blood = true, Setting1::botst2distance = true, Setting1::botst2weapon = true, Setting1::botst2Weapons_iconsH = false;
//bst3
bool Setting1::botst3name = true, Setting1::botst3line = true, Setting1::botst3Bone = true, Setting1::botst3health = true, Setting1::botst3cornerbox = true,
Setting1::botst3fullbox = false, Setting1::botst3blood = true, Setting1::botst3distance = true, Setting1::botst3weapon = true, Setting1::botst3Weapons_iconsH = false;

////playrOnOff===================================
bool Setting1::playername = true, Setting1::playerline = true, Setting1::playerBone = true, Setting1::playerhealth = true, Setting1::playercornerbox = true,
Setting1::playerfullbox = true, Setting1::playerblood = true, Setting1::playerdistance = true, Setting1::playerweapon = true, Setting1::playerWeapons_iconsH = true;
//pst1
bool Setting1::playerst1name = true, Setting1::playerst1line = true, Setting1::playerst1Bone = true, Setting1::playerst1health = true, Setting1::playerst1cornerbox = true,
Setting1::playerst1fullbox = false, Setting1::playerst1blood = true, Setting1::playerst1distance = true, Setting1::playerst1weapon = true, Setting1::playerst1Weapons_iconsH = false;
//pst2
bool Setting1::playerst2name = true, Setting1::playerst2line = true, Setting1::playerst2Bone = true, Setting1::playerst2health = true, Setting1::playerst2cornerbox = false,
Setting1::playerst2fullbox = false, Setting1::playerst2blood = true, Setting1::playerst2distance = true, Setting1::playerst2weapon = true, Setting1::playerst2Weapons_iconsH = false;
//pst3
bool Setting1::playerst3name = true, Setting1::playerst3line = true, Setting1::playerst3Bone = true, Setting1::playerst3health = true, Setting1::playerst3cornerbox = true,
Setting1::playerst3fullbox = false, Setting1::playerst3blood = true, Setting1::playerst3distance = true, Setting1::playerst3weapon = true, Setting1::playerst3Weapons_iconsH = false;
//------------------------------------------------
bool Setting1::Flags = false, Setting1::FlagText = false, Setting1::Flagimge = true;
bool Setting1::AimingAlert = true;
bool Setting1::AirDropBox = true, Setting1::AirDropBoxItems = true;
bool Setting1::deadbox = true, Setting1::deadboxItems = true;
//-----------------------------------------------
bool Setting1::Vehicle = true, Setting1::Vehiclest1 = true, Setting1::Vehiclest2 = true, Setting1::Vehiclest3 = true;
bool Setting1::VehicleFeul = true, Setting1::VehicleFeulst1 = true, Setting1::VehicleFeulst2 = true, Setting1::VehicleFeulst3 = true;
bool Setting1::VehicleHp = true, Setting1::VehicleHpst1 = true, Setting1::VehicleHpst2 = true, Setting1::VehicleHpst3 = true;
//

////botSize
float Setting1::botnames1 = 16.0f, Setting1::botnames2 = 16.0f, Setting1::botnames3 = 18.0f;
float Setting1::botlines1 = 1.5f, Setting1::botlines2 = 1.5f, Setting1::botlines3 = 1.8f;
float Setting1::botBones1 = 1.7f, Setting1::botBones2 = 1.7f, Setting1::botBones3 = 1.0f;
float Setting1::bothealths1 = 17.0f, Setting1::bothealths2 = 17.0f, Setting1::bothealths3 = 17.0f;
float Setting1::botcornerboxs1 = 1.0f, Setting1::botcornerboxs2 = 1.0f, Setting1::botcornerboxs3 = 1.0f;
float Setting1::botfullboxs1 = 1.0f, Setting1::botfullboxs2 = 1.0f, Setting1::botfullboxs3 = 1.0f;
float Setting1::botdistances1 = 14.0f, Setting1::botdistances2 = 14.0f, Setting1::botdistances3 = 16.0f;
float Setting1::botweaponFalses1 = 15.0f, Setting1::botweaponFalses2 = 15.0f, Setting1::botweaponFalses3 = 17.0f;
float Setting1::botweapons1 = 17.0f, Setting1::botweapons2 = 14.0f, Setting1::botweapons3 = 17.0f;
////playrSize
float Setting1::playernames1 = 16.0f, Setting1::playernames2 = 16.0f, Setting1::playernames3 = 16.0f;
float Setting1::playerlines1 = 1.5f, Setting1::playerlines2 = 1.5f, Setting1::playerlines3 = 1.8f;
float Setting1::playerBones1 = 1.0f, Setting1::playerBones2 = 1.0f, Setting1::playerBones3 = 1.0f;
float Setting1::playerhealths1 = 17.0f, Setting1::playerhealths2 = 17.0f, Setting1::playerhealths3 = 17.0f;
float Setting1::playercornerboxs1 = 1.0f, Setting1::playercornerboxs2 = 1.0f, Setting1::playercornerboxs3 = 1.0f;
float Setting1::playerfullboxs1 = 1.0f, Setting1::playerfullboxs2 = 1.0f, Setting1::playerfullboxs3 = 1.0f;
float Setting1::playerdistances1 = 14.0f, Setting1::playerdistances2 = 14.0f, Setting1::playerdistances3 = 16.0f;
float Setting1::playerweaponFalses1 = 17.0f, Setting1::playerweaponFalses2 = 15.0f, Setting1::playerweaponFalses3 = 17.0f;
float Setting1::playerweapons1 = 17.0f, Setting1::playerweapons2 = 14.0f, Setting1::playerweapons3 = 17.0f;
//
float Setting1::AimingAlerts1 = 22, Setting1::AimingAlerts2 = 22, Setting1::AimingAlerts3 = 22;
float Setting1::FlagTexts1 = 14, Setting1::FlagTexts2 = 14, Setting1::FlagTexts3 = 14;
float Setting1::AirDropBoxs1 = 15, Setting1::AirDropBoxs2 = 15, Setting1::AirDropBoxs3 = 15;
float Setting1::AirDropBoxItemss1 = 15, Setting1::AirDropBoxItemss2 = 15, Setting1::AirDropBoxItemss3 = 15;
float Setting1::deadboxs1 = 15, Setting1::deadboxs2 = 15, Setting1::deadboxs3 = 15;
float Setting1::deadboxItemss1 = 15, Setting1::deadboxItemss2 = 15, Setting1::deadboxItemss3 = 15;
//
float Setting1::Vehicles = 16, Setting1::Vehicles1 = 16, Setting1::Vehicles2 = 16, Setting1::Vehicles3 = 16;


// Bot Color
ImVec4  Setting1::botnamec1 = { ImColor(255, 255, 255, 255) },  Setting1::botnamec2 = { ImColor(0, 255, 255, 255) },  Setting1::botnamec3 = { ImColor(0, 255, 0, 255) };
ImVec4  Setting1::botlinec1 = { ImColor(233, 255, 147, 255) },  Setting1::botlinec2 = { ImColor(255, 255, 255, 255) },  Setting1::botlinec3 = { ImColor(216,0,0,255) };
ImVec4  Setting1::botBonec1 = { ImColor(255, 255, 255, 255) },  Setting1::botBonec2 = { ImColor(255, 255, 255, 255) },  Setting1::botBonec3 = { ImColor(216,0,0,255) };
ImVec4  Setting1::bothealthc1 = { ImColor(255, 255, 255, 255) },  Setting1::bothealthc2 = { ImColor(255, 255, 255, 255) },  Setting1::bothealthc3 = { ImColor(255, 255, 255, 255) };
ImVec4  Setting1::botcornerboxc1 = { ImColor(255, 255, 255, 255) },  Setting1::botcornerboxc2 = { ImColor(0, 255, 255, 255) },  Setting1::botcornerboxc3 = { ImColor(216,0,0,255) };
ImVec4  Setting1::botfullboxc1 = { ImColor(255, 255, 255, 255) },  Setting1::botfullboxc2 = { ImColor(0, 255, 255, 255) },  Setting1::botfullboxc3 = { ImColor(216,0,0,255) };
ImVec4  Setting1::botdistancec1 = { ImColor(0, 255, 0, 255) },  Setting1::botdistancec2 = { ImColor(0, 255, 0, 255) },  Setting1::botdistancec3 = { ImColor(255, 255, 255, 255) };
ImVec4  Setting1::botweaponFalsec1 = { ImColor(0, 255, 0, 255) },  Setting1::botweaponFalsec2 = { ImColor(0, 255, 0, 255) },  Setting1::botweaponFalsec3 = { ImColor(0, 220, 0, 255) };
ImVec4  Setting1::botweaponc1 = { ImColor(0, 255, 0, 255) },  Setting1::botweaponc2 = { ImColor(0, 255, 0, 255) },  Setting1::botweaponc3 = { ImColor(0, 255, 0, 255) };
// Player Color
ImVec4  Setting1::playernamec1 = { ImColor(255, 255, 255, 255) },  Setting1::playernamec2 = { ImColor(0, 255, 255, 255) },  Setting1::playernamec3 = { ImColor(255, 255, 255, 255) };
ImVec4  Setting1::playerlinec1 = { ImColor(233, 255, 147, 255) },  Setting1::playerlinec2 = { ImColor(255, 255, 255, 255) },  Setting1::playerlinec3 = { ImColor(216,0,0,255) };
ImVec4  Setting1::playerBonec1 = { ImColor(255, 255, 255, 255) },  Setting1::playerBonec2 = { ImColor(255, 255, 255, 255) },  Setting1::playerBonec3 = { ImColor(216,0,0,255) };
ImVec4  Setting1::playerhealthc1 = { ImColor(255, 255, 255, 255) },  Setting1::playerhealthc2 = { ImColor(255, 255, 255, 255) },  Setting1::playerhealthc3 = { ImColor(255, 255, 255, 255) };
ImVec4  Setting1::playercornerboxc1 = { ImColor(255, 255, 255, 255) },  Setting1::playercornerboxc2 = { ImColor(0, 255, 255, 255) },  Setting1::playercornerboxc3 = { ImColor(216,0,0,255) };
ImVec4  Setting1::playerfullboxc1 = { ImColor(255, 255, 255, 255) },  Setting1::playerfullboxc2 = { ImColor(0, 255, 255, 255) },  Setting1::playerfullboxc3 = { ImColor(216,0,0,255) };
ImVec4  Setting1::playerdistancec1 = { ImColor(0, 255, 0, 255) },  Setting1::playerdistancec2 = { ImColor(0, 255, 0, 255) },  Setting1::playerdistancec3 = { ImColor(255,255,255,255) };
ImVec4  Setting1::playerweaponFalsec1 = { ImColor(0, 255, 0, 255) },  Setting1::playerweaponFalsec2 = { ImColor(0, 255, 0, 255) },  Setting1::playerweaponFalsec3 = { ImColor(0, 220, 0, 255) };
ImVec4  Setting1::playerweaponc1 = { ImColor(0, 255, 0, 255) },  Setting1::playerweaponc2 = { ImColor(0, 255, 0, 255) },  Setting1::playerweaponc3 = { ImColor(0, 255, 0, 255) };
//
ImVec4  Setting1::FlagTextc1 = { ImColor(0, 255, 0, 255) },  Setting1::FlagTextc2 = { ImColor(0, 255, 255, 255) },  Setting1::FlagTextc3 = { ImColor(255, 0, 0, 255) };
ImVec4  Setting1::AirDropBoxc1 = { ImColor(0, 255, 0, 255) },  Setting1::AirDropBoxc2 = { ImColor(0, 255, 255, 255) },  Setting1::AirDropBoxc3 = { ImColor(255, 0, 0, 255) };
ImVec4  Setting1::AirDropBoxItemsc1 = { ImColor(0, 255, 0, 255) }, Setting1::AirDropBoxItemsc2 = { ImColor(0, 255, 255, 255) }, Setting1::AirDropBoxItemsc3 = { ImColor(255, 0, 0, 255) };
ImVec4  Setting1::deadboxc1 = { ImColor(0, 255, 0, 255) },  Setting1::deadboxc2 = { ImColor(0, 255, 255, 255) },  Setting1::deadboxc3 = { ImColor(255, 0, 0, 255) };
ImVec4  Setting1::deadboxItemsc1 = { ImColor(0, 255, 0, 255) },  Setting1::deadboxItemsc2 = { ImColor(0, 255, 255, 255) },  Setting1::deadboxItemsc3 = { ImColor(255, 0, 0, 255) };
//
ImVec4  Setting1::Vehiclec = { ImColor(255, 255, 0, 255) }, Setting1::Vehiclec1 = { ImColor(255, 255, 0, 255) }, Setting1::Vehiclec2 = { ImColor(255, 255,0, 255) }, Setting1::Vehiclec3 = { ImColor(255, 255, 0, 255) };


//================================================

//-----------AR Auto Weapon
ImVec4 weapon1::m16 = { 255, 0, 0, 255 }; //= { 1.000f, 0.695f, 0.323f, 1.000f }; //{ 0.866f, 0.128f, 0.081f, 1.000f };
ImVec4  weapon1::scarl = { 255, 0, 0, 255 }; //= { 1.000f, 0.695f, 0.323f, 1.000f };
ImVec4  weapon1::AKM = { 255, 0, 0, 255 }; //= { 1.000f, 0.695f, 0.323f, 1.000f }; //{ 0.866f, 0.128f, 0.081f, 1.000f };
ImVec4  weapon1::m762 = { 255, 0, 0, 255 }; //= { 1.000f, 0.695f, 0.323f, 1.000f }; //{ 0.118f, 0.76f, 0.788f, 1.000f };
ImVec4  weapon1::DP28 = { 255, 0, 0, 255 }; //= { 1.000f, 0.695f, 0.323f, 1.000f }; //{ 0.118f, 0.76f, 0.788f, 1.000f };
ImVec4  weapon1::GROZZA = { 255, 0, 0, 255 }; //= { 1.000f, 0.695f, 0.323f, 1.000f }; //{ 0.279f, 0.990f, 0.812f, 1.000f };
ImVec4  weapon1::Honey = { 255, 0, 0, 255 }; //= { 1.000f, 0.695f, 0.323f, 1.000f }; //{ 0.279f, 0.990f, 0.812f, 1.000f };

//----------Sniper Weapon
ImVec4  weapon1::kar98 = { 255, 255, 0, 255 }; //= { 0.866f, 0.128f, 0.081f, 1.000f }; //{ 1.0f, 0.60f,0.05f, 1.0f };
ImVec4  weapon1::M24 = { 255, 255, 0, 255 }; //= { 0.866f, 0.128f, 0.081f, 1.000f }; //{ 0.844f, 0.066f, 1.000f, 1.000f };
ImVec4  weapon1::AWM = { 255, 255, 0, 255 }; //= { 0.866f, 0.128f, 0.081f, 1.000f }; //{ 1.000f, 0.089f, 0.089f, 1.000f };
ImVec4  weapon1::AWMimmo = { 235, 255, 204, 255 }; //= { 0.942f, 0.300f, 0.073f, 1.000f };

//----------Weapon Ammo
extern	ImVec4 weapon1::ammo7 = { ImColor(255, 211, 140, 255) }; //= { 0.500f, 1.000f, 0.000f, 1.000f };
extern	ImVec4 weapon1::ammo5 = { ImColor(178, 245, 142, 255) }; //= { 0.000f, 1.000f, 0.000f, 1.000f };




//---------------drop
ImVec4  weapon1::Airdrop = { ImColor(255, 255, 0, 255) }; //= { 0.279f, 0.990f, 0.812f, 1.000f };
ImVec4  weapon1::Flare = { ImColor(255, 0, 0, 255) }; //= { 0.866f, 0.128f, 0.081f, 1.000f }; //{ 0.866f, 0.128f, 0.081f, 1.000f };
ImVec4  weapon1::Flaregun = { ImColor(255, 0, 0, 255) }; //= { 0.866f, 0.128f, 0.081f, 1.000f }; //{ 1.0f, 0.60f,0.05f, 1.0f };

//---------------Scope
ImVec4 Scope1::scope2x = { 82, 194, 255, 255 }; //= { 0.874f, 0.484f, 0.106f, 1.000f };
ImVec4 Scope1::scope3x = { 82, 194, 255, 255 }; //= { 0.874f, 0.484f, 0.106f, 1.000f };
ImVec4 Scope1::scope4x = { 82, 194, 255, 255 }; //= { 0.937f, 0.063f, 0.937f, 1.000f };
ImVec4 Scope1::scope6x = { 247, 69, 117, 255 }; //= { 0.120f, 0.955f, 0.125f, 1.0f };
ImVec4 Scope1::scope8x = { 247, 69, 117, 255 }; //= { 0.866f, 0.128f, 0.081f, 1.000f };

ImVec4   Colors1::dp = { 255, 180, 0, 255 }; //= { 1.000f, 0.760f, 0.150f, 1.000f };
ImVec4   Colors1::mg3 = { 255, 180, 0, 255 }; //= { 0.373f, 0.966f, 0.391f, 1.000f};

ImVec4  Colors1::bag = { 0, 255, 242, 255 }; //= { 0.529f, 0.127f, 0.903f, 1.000f};
ImVec4  Colors1::armer = { 150, 100, 255, 255 }; //= {0.591f, 1.000f, 0.237f, 1.000f };
ImVec4  Colors1::helmat = { 150, 100, 255, 255 }; //= { 0.726f, 0.070f, 0.908f, 1.000f};
ImVec4  Colors1::mosin = { 240, 220, 0, 255 }; //= { 0.258f, 0.971f, 0.775f, 1.000f};
ImVec4   Colors1::aug = { 240, 220, 0, 255 }; //= { 0.442f, 0.971f, 0.122f, 1.000f};

ImVec4   Colors1::g36c = { 255, 255, 255, 255 }; //= { 0.671f, 0.217f, 1.000f, 1.000f};
ImVec4   Colors1::assm = { 255, 255, 255, 255 }; //= { 1.000f, 0.217f, 0.762f, 1.000f};

extern	ImVec4 Colors1::Grandes = { 255, 220, 0, 255 }; //= { 1.000f, 0.396f, 0.357f, 1.000f};
extern ImVec4 Colors1::madkit = { 255, 140, 255, 255 }; //= { 0.952f, 0.558f, 0.129f, 1.000f};
 //extern ImVec4 Colors1::Firstkit = { 255, 180, 255, 255 }; //= { 0.952f, 0.558f, 0.129f, 1.000f};
 //extern ImVec4 Colors1::Painkiller = { 255, 138, 241, 255 }; //= { 0.952f, 0.558f, 0.129f, 1.000f};
 //extern ImVec4 Colors1::AdrenalineSyringe = { 255, 140, 255, 255 }; //= { 0.952f, 0.558f, 0.129f, 1.000f};


ImVec4  Colors1::itemcolors;// = { 1.000f, 0.100f, 0.401f, 1.000f };

ImVec4  Colors1::lotboxColor = { 1.0f, 1.0f,0.0f, 1.0f };
// ARGB
ImVec4  Colors1::helthbar = { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4  Colors1::boxColor = { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4  Colors1::cornerColor = { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4  Colors1::crosshairColor = { 0.950f, 0.125f, 0.125f, 1.0f };


//ImVec4  Colors1::vehicle = { 0.737f, 1.000f, 0.000f, 1.000f };
//ImVec4  Colors1::vehicle = { 255, 255, 0, 255 };
//RGB
ImVec4 Colors1::circle = { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4 Colors1::enemy = { 0, 255, 255, 255 };
ImVec4 Colors1::bone = { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4 Colors1::fillrect = { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4 Colors1::nam = { 247, 255, 0, 255 };






ImVec4 Colors1::nambarColor = { 0.880f, 0.185f, 0.25f, 1.0f };

ImVec4 Colors1::textColor = { 240, 220, 0, 255 }; //= { 0.500f, 0.150f, 0.125f, 1.0f };

ImVec4 Colors1::GranadesColor = { 0.990f, 0.995f, 0.995f, 1.0f };
ImVec4 Colors1::healthColor = { 0.108f, 1.000f, 1.000f, 1.000f };
ImVec4 Colors1::deadboxitemColor = { 1.000f, 0.100f, 0.401f, 1.000f };
ImVec4 Colors1::airdropColor = { 255, 255, 0, 255 }; //= { 1.000f, 0.695f, 0.323f, 1.000f };
ImVec4 Colors1::airdropitemColor = { 0.300f, 0.695f, 0.323f, 1.000f };
ImVec4 Colors1::scopetextColor = { 0.000f, 0.995f, 0.995f, 1.000f };
ImVec4 Colors1::allitemColor = { 0.034f, 1.000f, 0.040f, 1.000f };
ImVec4 Colors1::magiclineColor = { ImColor(255, 0, 0, 255) };
ImVec4 Colors1::bgcornerColor = { ImColor(0, 255, 0, 255) };
ImVec4 Colors1::fovcircleColor = { ImColor(255, 0, 0, 150) }; //= { 255, 0, 0, 255 };


//ImVec4 Colors1::skelec = { 255, 255, 255, 255 };
ImVec4 Colors1::skelec = { ImColor(216,0,0,255) };
ImVec4 Colors1::skelec1;/* = { 255, 255, 255, 255 };*/

ImVec4  Colors1::hptColor = { 255, 255, 255, 255 };






//if (GetAsyncKeyState(VK_F5) & 1)
//{
//	Setting1::Aimbot = !Setting1::Aimbot;
//}
int Setting1::MagicBulletKey = 0 + (VK_LBUTTON);
int Setting1::AimbotKey = 0 + (VK_RBUTTON);
int Setting1::AimbotPositionKey = 0;
//int Setting1::AimbotKey = 0 + (VK_RBUTTON);
//int Setting1::AimbotKey = 0;
//int Setting1::fastrunkey = 0 + (VK_LSHIFT);
int Setting1::fastrunkey = 0;
int Setting1::PositionKey = 0;
int Setting1::EnableKey = 0;
bool  Setting1::plan = true;
ImVec4  Setting1::plancolor = { 0, 255, 255, 255 }; //= { 0.737f, 1.000f, 0.000f, 1.000f };
ImVec4  Setting1::dotss = { 0.950f, 0.125f, 0.925f, 1.0f };

DWORD Setting1::CurrentTargetAddress = 0;

//====================
bool Setting1::ShowMenu2 = false;
//=====================
bool Setting1::dots = false;
bool Setting1::dots1 = true;
bool Setting1::dots2 = false;
int Setting1::redioption = 2;
bool Setting1::redioption2 = false;
bool Setting1::IsMagicInitialize = false;
bool Setting1::Magntic = false;
bool Setting1::AimHead = true;
bool Setting1::AimBody = true;
float Setting1::Aimspeed = 11;
int	Setting1::curraim = 0;
char  Setting1::filename[] = "C:\\megHack.ini";
float Setting1::fontsize = 15;

bool Setting1::Esp_Item_AirAttack = true;


float Setting1::AllItemsSize = 15;
float Setting1::Normalfontsize = 15;
float Setting1::Normalfontsize2 = 1.700;
float Setting1::Normalfontsize3 = 200;
float Setting1::Normalfontsize4 = 80;
float Setting1::Normalfontsize5 = 300;
extern float Setting1::weaponsize = 15.0f;
int Setting1::psize1 = 17;
float Setting1::overlaycolor = 0.000f;

//==================
//int Setting1::SuperUp = 0;
//int Setting1::SuperDown = 0;
//int Setting1::SuperLeft = 0;
//int Setting1::SuperRight = 0;
//int Setting1::SuperFront = 0;

int Setting1::SuperUp = 0 + ('X');
int Setting1::SuperDown = 0 + (VK_DOWN);
int Setting1::SuperRight = 0 + (VK_RIGHT);
int Setting1::SuperLeft = 0 + (VK_LEFT);
int Setting1::SuperFront = 0 + (VK_UP);
//============================
bool Setting1::antiscreen = false;
//=====================
bool Setting1::FastParachute = false;
//=====================
//============================
bool Setting1::fackSetting1 = false;
bool Setting1::fackSetting2 = false;
bool Setting1::fackSetting3 = false;
bool Setting1::fackSetting4 = false;
bool Setting1::fackSetting5 = false;
bool Setting1::fackSetting6 = false;
bool Setting1::fackSetting7 = false;
bool Setting1::fackSetting8 = false;
bool Setting1::fackSetting9 = false;
bool Setting1::fackSetting10 = false;
bool Setting1::fackSetting11 = false;
bool Setting1::fackSetting12 = false;
bool Setting1::fackMoreOption = false;
//=====================
bool Setting1::VngGameEsp = false;

int Setting1::Flymankey = 0;
int Setting1::Backcarkey = 0;
int Setting1::Fastcarkey = 0;
int Setting1::landspeed = 0;
int Setting1::FastParachutekey = 0;
bool Setting1::Luffy = false;
//bool Setting1::SuperView = false;
bool Setting1::Legitrack = false;
bool Setting1::RandomTracking = false;
bool Setting1::SkipBots = false;
bool Setting1::Redzome = true;
bool Setting1::ScreenX = false;


//=====================
bool Setting1::viplogin = true;
bool Setting1::freelogin = false;
//=====================
bool Setting1::SafeMode = false;
bool Setting1::DangerMode = true;
//=====================

bool Setting1::MagicX = false;
bool Setting1::LegitTrack = false;

bool  Setting1::MagicInsideFOV = false;
bool  Setting1::Magic360deg = false;
bool  Setting1::AimbotwithMagic = false;
bool  Setting1::AimPrediction = true;
bool  Setting1::MemoryAimbot = false;

bool Setting1::differnt = true;
bool Setting1::same = false;
bool Setting1::PESP = true;
bool Setting1::BESP = true; 
bool Setting1::bortext = true;

bool Setting1::TeamIdLine = true;

float Setting1::IPADSIZE = 110;
float Setting1::IPADSIZE1 = 80;


extern float Setting1::Namesize = 15.0f;

bool Setting1::knocked = true;
bool Setting1::aimbotposition = true;

float Setting1::fovcircleredus = 50.0f;
bool Setting1::fovcircle = false;
bool Setting1::fovcircle2 = false;
ImVec4 Setting1::colorcode;







bool Setting1::boxitemBagShadow = false;

bool Setting1::SuperView1 = false;
float Setting1::SuperViewPower = 420.0f;
int Setting1::intGO = 1.0f;

int Setting1::intV = 550.0f;
//int Setting1::intV = 550000.0f;

bool Setting1::fightmode = false;
int Setting1::Fightmodekey = 0;
bool Setting1::MAgicline = false;
float Setting1::warning = 25.0f;

bool Setting1::Bags = true;
bool Setting1::Armer = false;
bool Setting1::Helmat = true;

bool  Setting1::airdrop = false;
bool  Setting1::airdropitem = true;

bool  Setting1::itemrect = true;
bool Setting1::ShowMenu = true;


bool Setting1::profree = false;


bool Setting1::Name = true;
bool Setting1::Distance = true;



bool Setting1::TotalEnemy = true;
bool Setting1::TotalEnemyStyle1 = false;
bool Setting1::TotalEnemyStyle2 = true;
bool Setting1::TotalEnemyStyle3 = false;
bool Setting1::Gameinfo = true;

bool Setting1::Line = false;
bool Setting1::Box = false;
bool Setting1::Bone = true;
bool Setting1::Health = false;
bool Setting1::BombAlert = false;
bool Setting1::Item = true;

bool Setting1::luffy = false;
bool Setting1::ipadview = false;
bool Setting1::noheadshot = false;
bool Setting1::smallcrosshair = false;


bool Setting1::engine = 0;
bool Setting1::skele = 0;
bool Setting1::impitems = true;
bool Setting1::scope = true;
bool Setting1::graned = true;
bool Setting1::healthitem = true;
bool Setting1::allitemss = true;
bool Setting1::instanthit = false;
bool Setting1::instanthitDNG = false;
bool Setting1::fastrun = false;
bool Setting1::fly = false;
bool Setting1::carfly = false;
bool Setting1::speedcar = false;
bool Setting1::recoil = false;
bool Setting1::vahicle_item = true;

ImVec4 Colors1::Smoke_Color = { ImColor(255, 125, 125, 255) };
ImVec4 Colors1::Grenade_Color = { ImColor(255, 0, 0, 255) };
ImVec4 Colors1::Molotof_Color = { ImColor(255, 65, 51, 255) };
ImVec4 Colors1::Burn_Color = { ImColor(255, 65, 51, 255) };

ImVec4 Colors1::ammo_5_56mm = { ImColor(0, 255, 0, 255) };
ImVec4 Colors1::ammo_7_62mm = { ImColor(255, 178, 54, 255) };
ImVec4 Colors1::ammo_9mm = { ImColor(0, 171, 154, 255) };
ImVec4 Colors1::ammo_45ACP = { ImColor(0, 171, 154, 255) };
ImVec4 Colors1::ammo_sniper = { ImColor(174, 174, 0, 255) };
ImVec4 Colors1::ammo_Flare_Gun = { ImColor(174, 12, 0, 255) };

ImVec4 Colors1::weapon_7mm = { ImColor(255, 198, 0, 255) };
ImVec4 Colors1::weapon_5mm = { ImColor(0, 255, 0, 255) };
ImVec4 Colors1::weapon_smg = { ImColor(182, 253, 255, 255) };
ImVec4 Colors1::weapon_sniper = { ImColor(255, 255, 0, 255) };
ImVec4 Colors1::weapon_Flare_Gun = { ImColor(255, 0, 0, 255) };

ImVec4 Colors1::Holo = { ImColor(169, 206, 255, 255) };
ImVec4 Colors1::Red_Dot = { ImColor(169, 206, 255, 255) };
ImVec4 Colors1::scope_2x = { ImColor(79, 207, 255, 255) };
ImVec4 Colors1::scope_3x = { ImColor(79, 180, 255, 255) };
ImVec4 Colors1::scope_4x = { ImColor(0, 153, 227, 255) };
ImVec4 Colors1::scope_6x = { ImColor(255, 91, 79, 255) };
ImVec4 Colors1::scope_8x = { ImColor(255, 91, 79, 255) };

ImVec4 Colors1::Bandage = { ImColor(0, 255, 153, 255) };
ImVec4 Colors1::EnergyDrink = { ImColor(209, 145, 255, 255) };
ImVec4 Colors1::Painkiller = { ImColor(255, 79, 242, 255) };
ImVec4 Colors1::Firstkit = { ImColor(255, 125, 242, 255) };
ImVec4 Colors1::Madkit = { ImColor(255, 0, 0, 255) };
ImVec4 Colors1::AdrenalineSyringe = { ImColor(255, 0, 0, 255) };

ImVec4 Colors1::Bag_lv1 = { ImColor(151, 151, 255, 255) };
ImVec4 Colors1::Bag_lv2 = { ImColor(133, 133, 255, 255) };
ImVec4 Colors1::Bag_lv3 = { ImColor(255, 121, 121, 255) };

ImVec4 Colors1::Helmet_lv1 = { ImColor(107, 174, 206, 255) };
ImVec4 Colors1::Helmet_lv2 = { ImColor(112, 191, 225, 255) };
ImVec4 Colors1::Helmet_lv3 = { ImColor(255, 91, 79, 255) };

ImVec4 Colors1::Armor_lv1 = { ImColor(124, 157, 255, 255) };
ImVec4 Colors1::Armor_lv2 = { ImColor(119, 153, 255, 255) };
ImVec4 Colors1::Armor_lv3 = { ImColor(255, 91, 79, 255) };


bool Setting1::Esp_Item_AKM = true;
float Setting1::Esp_Item_AKM_Color[4] = { 1.00f, 0.76f, 0.15f, 1.0f };
float Setting1::Esp_Item_AKM_TextSize = 20.0f;

bool Setting1::Esp_Item_ExplosiveBow = true;
float Setting1::Esp_Item_ExplosiveBow_Color[4] = { 1.00f, 0.76f, 0.15f, 1.0f };
float Setting1::Esp_Item_ExplosiveBow_TextSize = 20.0f;

bool Setting1::Esp_Item_HoneyBadger = true;
float Setting1::Esp_Item_HoneyBadger_Color[4] = { 1.00f, 0.76f, 0.15f, 1.0f };
float Setting1::Esp_Item_HoneyBadger_TextSize = 20.0f;

bool Setting1::Esp_Item_M249 = true;
ImVec4 Colors1::M249Color = { 1.00f, 0.76f, 0.15f, 1.0f };

bool Setting1::Esp_Item_Mk12 = true;
ImVec4 Colors1::MK12Color = { 1.00f, 0.796f, 0.715f, 1.0f };

bool Setting1::Esp_Item_M762 = true;
float Setting1::Esp_Item_M762_Color[4] = { 1.00f, 0.76f, 0.15f, 1.0f };
float Setting1::Esp_Item_M762_TextSize = 20.0f;

bool Setting1::Esp_Item_Mk47Mutant = true;
float Setting1::Esp_Item_Mk47Mutant_Color[4] = { 1.00f, 0.76f, 0.15f, 1.0f };
float Setting1::Esp_Item_Mk47Mutant_TextSize = 20.0f;

bool Setting1::Esp_Item_DP28 = true;
float Setting1::Esp_Item_DP28_Color[4] = { 1.00f, 0.76f, 0.15f, 1.0f };
float Setting1::Esp_Item_DP28_TextSize = 20.0f;

bool Setting1::Esp_Item_SCARL = true;
float Setting1::Esp_Item_SCARL_Color[4] = { 0.00f, 1.0f, 0.0f, 1.0f };
float Setting1::Esp_Item_SCARL_TextSize = 20.0f;

bool Setting1::Esp_Item_M416 = true;
float Setting1::Esp_Item_M416_Color[4] = { 0.00f, 1.0f, 0.0f, 1.0f };
float Setting1::Esp_Item_M416_TextSize = 20.0f;

bool Setting1::Esp_Item_M16A4 = true;
float Setting1::Esp_Item_M16A4_Color[4] = { 0.00f, 1.0f, 0.0f, 1.0f };
float Setting1::Esp_Item_M16A4_TextSize = 20.0f;

bool Setting1::Esp_Item_G36C = true;
float Setting1::Esp_Item_G36C_Color[4] = { 0.00f, 1.0f, 0.0f, 1.0f };
float Setting1::Esp_Item_G36C_TextSize = 20.0f;

bool Setting1::Esp_Item_QBZ = true;
float Setting1::Esp_Item_QBZ_Color[4] = { 0.00f, 1.0f, 0.0f, 1.0f };
float Setting1::Esp_Item_QBZ_TextSize = 20.0f;

bool Setting1::Esp_Item_QBU = true;
float Setting1::Esp_Item_QBU_Color[4] = { 0.75f, 1.00f, 0.24f, 1.0f };
float Setting1::Esp_Item_QBU_TextSize = 20.0f;

bool Setting1::Esp_Item_SLR = true;
float Setting1::Esp_Item_SLR_Color[4] = { 0.75f, 1.00f, 0.24f, 1.0f };
float Setting1::Esp_Item_SLR_TextSize = 20.0f;

bool Setting1::Esp_Item_SKS = true;
float Setting1::Esp_Item_SKS_Color[4] = { 0.75f, 1.00f, 0.24f, 1.0f };
float Setting1::Esp_Item_SKS_TextSize = 20.0f;

bool Setting1::Esp_Item_Mini14 = true;
float Setting1::Esp_Item_Mini14_Color[4] = { 0.75f, 1.00f, 0.24f, 1.0f };
float Setting1::Esp_Item_Mini14_TextSize = 20.0f;

bool Setting1::Esp_Item_M24 = true;
float Setting1::Esp_Item_M24_Color[4] = { 0.75f, 1.00f, 0.24f, 1.0f };
float Setting1::Esp_Item_M24_TextSize = 20.0f;
bool Setting1::Esp_Item_Awm = true;
bool Setting1::Esp_Item_Awmimo = true;
bool Setting1::Esp_Item_Kar98k = true;
float Setting1::Esp_Item_Kar98k_Color[4] = { 0.75f, 1.00f, 0.24f, 1.0f };
float Setting1::Esp_Item_Kar98k_TextSize = 20.0f;

bool Setting1::Esp_Item_PP19 = false;
float Setting1::Esp_Item_PP19_Color[4] = { 1.00f, 0.96f, 0.56f, 1.0f };
float Setting1::Esp_Item_PP19_TextSize = 20.0f;

bool Setting1::Esp_Item_TommyGun = false;
float Setting1::Esp_Item_TommyGun_Color[4] = { 1.00f, 0.96f, 0.56f, 1.0f };
float Setting1::Esp_Item_TommyGun_TextSize = 20.0f;

bool Setting1::Esp_Item_MP5K = false;
float Setting1::Esp_Item_MP5K_Color[4] = { 1.00f, 0.96f, 0.56f, 1.0f };
float Setting1::Esp_Item_MP5K_TextSize = 20.0f;

bool Setting1::Esp_Item_UMP9 = true;
float Setting1::Esp_Item_UMP9_Color[4] = { 1.00f, 0.96f, 0.56f, 1.0f };
float Setting1::Esp_Item_UMP9_TextSize = 20.0f;

bool Setting1::Esp_Item_Vector = false;
float Setting1::Esp_Item_Vector_Color[4] = { 1.00f, 0.96f, 0.56f, 1.0f };
float Setting1::Esp_Item_Vector_TextSize = 20.0f;

bool Setting1::Esp_Item_Uzi = false;
float Setting1::Esp_Item_Uzi_Color[4] = { 1.00f, 0.96f, 0.56f, 1.0f };
float Setting1::Esp_Item_Uzi_TextSize = 20.0f;

bool Setting1::Esp_Item_762mm = false;
float Setting1::Esp_Item_762mm_Color[4] = { 1.00f, 0.76f, 0.15f, 1.0f };
float Setting1::Esp_Item_762mm_TextSize = 20.0f;

bool Setting1::Esp_Item_556mm = false;
float Setting1::Esp_Item_556mm_Color[4] = { 0.00f, 1.0f, 0.0f, 1.0f };
float Setting1::Esp_Item_556mm_TextSize = 20.0f;

bool Setting1::Esp_Item_9mm = false;
float Setting1::Esp_Item_9mm_Color[4] = { 0.75f, 1.00f, 0.24f, 1.0f };
float Setting1::Esp_Item_9mm_TextSize = 20.0f;

bool Setting1::Esp_Item_45ACP = false;
float Setting1::Esp_Item_45ACP_Color[4] = { 1.00f, 0.96f, 0.56f, 1.0f };
float Setting1::Esp_Item_45ACP_TextSize = 20.0f;

bool Setting1::Esp_Item_Holo = false;
float Setting1::Esp_Item_Holo_Color[4] = { 1.00f, 0.0f, 1.0f, 1.0f };
float Setting1::Esp_Item_Holo_TextSize = 20.0f;

bool Setting1::Esp_Item_x2 = false;
float Setting1::Esp_Item_x2_Color[4] = { 1.00f, 0.0f, 1.0f, 1.0f };
float Setting1::Esp_Item_x2_TextSize = 20.0f;

bool Setting1::Esp_Item_x3 = true;
float Setting1::Esp_Item_x3_Color[4] = { 1.00f, 0.0f, 1.0f, 1.0f };
float Setting1::Esp_Item_x3_TextSize = 20.0f;

bool Setting1::Esp_Item_x4 = true;
float Setting1::Esp_Item_x4_Color[4] = { 1.00f, 0.0f, 1.0f, 1.0f };
float Setting1::Esp_Item_x4_TextSize = 20.0f;

bool Setting1::Esp_Item_x6 = true;
float Setting1::Esp_Item_x6_Color[4] = { 1.00f, 0.0f, 1.0f, 1.0f };
float Setting1::Esp_Item_x6_TextSize = 20.0f;

bool Setting1::Esp_Item_x8 = true;
float Setting1::Esp_Item_x8_Color[4] = { 1.00f, 0.0f, 1.0f, 1.0f };
float Setting1::Esp_Item_x8_TextSize = 20.0f;

bool Setting1::Esp_Item_Bag1 = false;
float Setting1::Esp_Item_Bag1_Color[4] = { 0.61f, 0.19f, 1.00f, 1.0f };
float Setting1::Esp_Item_Bag1_TextSize = 20.0f;

bool Setting1::Esp_Item_Bag2 = true;
float Setting1::Esp_Item_Bag2_Color[4] = { 0.61f, 0.19f, 1.00f, 1.0f };
float Setting1::Esp_Item_Bag2_TextSize = 20.0f;

bool Setting1::Esp_Item_Bag3 = true;
float Setting1::Esp_Item_Bag3_Color[4] = { 0.61f, 0.19f, 1.00f, 1.0f };
float Setting1::Esp_Item_Bag3_TextSize = 20.0f;

bool Setting1::Esp_Item_Armor1 = false;
float Setting1::Esp_Item_Armor1_Color[4] = { 0.61f, 0.19f, 1.00f, 1.0f };
float Setting1::Esp_Item_Armor1_TextSize = 20.0f;

bool Setting1::Esp_Item_Armor2 = true;
float Setting1::Esp_Item_Armor2_Color[4] = { 0.61f, 0.19f, 1.00f, 1.0f };
float Setting1::Esp_Item_Armor2_TextSize = 20.0f;

bool Setting1::Esp_Item_Armor3 = true;
float Setting1::Esp_Item_Armor3_Color[4] = { 0.61f, 0.19f, 1.00f, 1.0f };
float Setting1::Esp_Item_Armor3_TextSize = 20.0f;

bool Setting1::Esp_Item_Helmet1 = false;
float Setting1::Esp_Item_Helmet1_Color[4] = { 0.61f, 0.19f, 1.00f, 1.0f };
float Setting1::Esp_Item_Helmet1_TextSize = 20.0f;

bool Setting1::Esp_Item_Helmet2 = true;
float Setting1::Esp_Item_Helmet2_Color[4] = { 0.61f, 0.19f, 1.00f, 1.0f };
float Setting1::Esp_Item_Helmet2_TextSize = 20.0f;

bool Setting1::Esp_Item_Helmet3 = true;
float Setting1::Esp_Item_Helmet3_Color[4] = { 0.61f, 0.19f, 1.00f, 1.0f };
float Setting1::Esp_Item_Helmet3_TextSize = 20.0f;

bool Setting1::Esp_Item_Frag = true;
float Setting1::Esp_Item_Frag_Color[4] = { 1.00f, 0.20f, 0.70f, 1.0f };
float Setting1::Esp_Item_Frag_TextSize = 20.0f;

bool Setting1::Esp_Item_Grenade = true;
float Setting1::Esp_Item_Grenade_Color[4] = { 1.00f, 0.20f, 0.70f, 1.0f };
float Setting1::Esp_Item_Grenade_TextSize = 20.0f;

bool Setting1::Esp_Item_Smoke = true;
float Setting1::Esp_Item_Smoke_Color[4] = { 1.00f, 0.20f, 0.70f, 1.0f };
float Setting1::Esp_Item_Smoke_TextSize = 20.0f;

bool Setting1::Esp_Item_Molotof = true;
float Setting1::Esp_Item_Molotof_Color[4] = { 1.00f, 0.20f, 0.70f, 1.0f };
float Setting1::Esp_Item_Molotof_TextSize = 20.0f;

bool Setting1::Esp_Item_MedKit = true;
float Setting1::Esp_Item_MedKit_Color[4] = { 1.00f, 0.27f, 0.00f, 1.0f };
float Setting1::Esp_Item_MedKit_TextSize = 20.0f;

bool Setting1::Esp_Item_FirstAidKit = true;
float Setting1::Esp_Item_FirstAidKit_Color[4] = { 1.00f, 0.27f, 0.00f, 1.0f };
float Setting1::Esp_Item_FirstAidKit_TextSize = 20.0f;

bool Setting1::Esp_Item_Painkiller = true;
float Setting1::Esp_Item_Painkiller_Color[4] = { 1.00f, 0.27f, 0.00f, 1.0f };
float Setting1::Esp_Item_Painkiller_TextSize = 20.0f;

bool Setting1::Esp_Item_EnergyDrink = true;
float Setting1::Esp_Item_EnergyDrink_Color[4] = { 1.00f, 0.27f, 0.00f, 1.0f };
float Setting1::Esp_Item_EnergyDrink_TextSize = 20.0f;

bool Setting1::Esp_Item_AdrenalineSyringe = true;
float Setting1::Esp_Item_AdrenalineSyringe_Color[4] = { 1.00f, 0.27f, 0.00f, 1.0f };
float Setting1::Esp_Item_AdrenalineSyringe_TextSize = 20.0f;

bool Setting1::Esp_Item_FlareGun = true;
float Setting1::Esp_Item_FlareGun_Color[4] = { 1.00f, 0.00f, 0.00f, 1.0f };
float Setting1::Esp_Item_FlareGun_TextSize = 20.0f;

bool Setting1::Esp_Item_Flare = true;
float Setting1::Esp_Item_Flare_Color[4] = { 1.00f, 0.00f, 0.00f, 1.0f };
float Setting1::Esp_Item_Flare_TextSize = 20.0f;

bool Setting1::Esp_Item_AirDrop = true;
float Setting1::Esp_Item_AirDrop_Color[4] = { 1.00f, 0.00f, 0.00f, 1.0f };
float Setting1::Esp_Item_AirDrop_TextSize = 20.0f;


bool Setting1::Esp_Item_LootBox = true;
float Setting1::Esp_Item_LootBox_Color[4] = { 1.00f, 0.00f, 0.00f, 1.0f };
float Setting1::Esp_Item_LootBox_TextSize = 20.0f;


bool Setting1::Aimbot = false;

bool Setting1::MagicBullet = false;
bool Setting1::MagicBulletDNG = false;
bool Setting1::silent = false;

bool Setting1::borderlo = true;

bool Setting1::CameraCatch = false;

bool Setting1::SuperView = false;
bool Setting1::SuperViewDNG = false;
bool Setting1::SuperViewA = false;

bool Setting1::grw = true;
bool Setting1::GrenadeWarning = true;
bool Setting1::molow = true;;
bool Setting1::magicb = false;

//int Setting1::intGO = 1.0f;

bool Setting1::NINEFPS = false;
bool Setting1::Fps = true;
bool Setting1::Infomrmation = false;

float Setting1::flyPower = 900.0f;
//float Setting1::flyPower = 90000.0f;

int	Setting1::magicv = 7;
int	Setting1::flycarv = 300.0f;
//int	Setting1::flycarv = 30000.0f;
int	Setting1::instantv = 700.0f;
//int	Setting1::instantv = 700000.0f;
int	Setting1::carsv = 300.0f;
int	Setting1::fastrv = 3.0f;
//float Setting1::skelec[4] = { 255, 255, 255, 255 };



bool Setting1::ShopToken = true;
ImVec4 Setting1::ShopTokenC = { ImColor(255, 91, 79, 255) };
float Setting1::ShopTokenT = 15.0f;

bool Setting1::RedZoneBomb = true;
ImVec4 Setting1::RedZoneBombC = { ImColor(255, 91, 79, 255) };
float Setting1::RedZoneBombT = 15.0f;

bool Setting1::GasCan = true;
ImVec4 Setting1::GasCanC = { ImColor(255, 91, 79, 255) };
float Setting1::GasCanT = 15.0f;

bool Setting1::HideIconeMENU = true;
ImVec4 Setting1::HideIconeMENUC = { ImColor(255, 91, 79, 255) };
float Setting1::HideIconeMENUT = 15.0f;

bool Setting1::StatusDiscord = true;
ImVec4 Setting1::StatusDiscordC = { ImColor(255, 91, 79, 255) };
float Setting1::StatusDiscordT = 15.0f;

bool Setting1::ShowStatusMagicBullet = false;
bool Setting1::ShowCurrentAimPosition = false;

float Setting1::GrenadeSize = 15.0f;

bool Setting1::LowCpu = true;
bool Setting1::HighCpu = false;

char  Setting1::PathSetting[] = "C:\\Windows\\meg_PVT_Setting.ini";

string Setting1::GameState;
string Setting1::GameState1;
int Setting1::AlivePlayers;
int Setting1::TimeRemind;
int Setting1::AliveTeams;
int Setting1::RealPlayers;
int Setting1::PlayerNumPerTeam;
int Setting1::ZoneID;
int Setting1::MyTeamID;
int Setting1::GameID;

int Setting1::UpdateTick = 10;

bool Setting1::MapType = true;
bool Setting1::WWCD = true;
