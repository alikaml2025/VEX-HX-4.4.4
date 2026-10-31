#pragma once

static int skeleeb1 = 0, skeleeb2 = 0, skeleeb3 = 0;
static int skeleep1 = 0, skeleep2 = 1, skeleep3 = 1;
static int linneb1 = 0, linneb2 = 0, linneb3 = 0;
static int linnep1 = 0, linnep2 = 1, linnep3 = 1;
static int hpb1 = 0, hpb2 = 0, hpb3 = 0;
static int hpp1 = 0, hpp2 = 0, hpp3 = 0;
static int CornerBoxb1 = 0, CornerBoxb2 = 0, CornerBoxb3 = 0;
static int CornerBoxp1 = 0, CornerBoxp2 = 1, CornerBoxp3 = 1;
static int botfullboxb1 = 0, botfullboxb2 = 0, botfullboxb3 = 0;
static int botfullboxp1 = 0, botfullboxp2 = 1, botfullboxp3 = 1;

void WriteConfigurate(std::string Path)
{
	CSimpleIniA ini;
	ini.SetUnicode();
	SI_Error rc = ini.LoadFile(Path.c_str());
	if (rc < 0) { std::cout << "File not found"; };

	ini.SetDoubleValue("MenuTransparency", "MenuTransparency", Setting::MenuTransparency);
	ini.SetDoubleValue("SideMenuTransparencyBg", "SideMenuTransparencyBg", Setting::SideMenuTransparencyBg);
	ini.SetDoubleValue("SideMenuTransparencyBorder", "SideMenuTransparencyBorder", Setting::SideMenuTransparencyBorder);

	///style
	ini.SetBoolValue("style1", "style1", Setting1::style1);
	ini.SetBoolValue("style2", "style2", Setting1::style2);
	ini.SetBoolValue("style3", "style3", Setting1::style3);
	ini.SetBoolValue("style4", "style4", Setting1::style4);

	//==BOT
	ini.SetBoolValue("botname", "botname", Setting1::botname);
	ini.SetBoolValue("botline", "botline", Setting1::botline);
	ini.SetBoolValue("botBone", "botBone", Setting1::botBone);
	ini.SetBoolValue("bothealth", "bothealth", Setting1::bothealth);
	ini.SetBoolValue("botcornerbox", "botcornerbox", Setting1::botcornerbox);
	ini.SetBoolValue("botfullbox", "botfullbox", Setting1::botfullbox);
	ini.SetBoolValue("botblood", "botblood", Setting1::botblood);
	ini.SetBoolValue("botdistance", "botdistance", Setting1::botdistance);
	ini.SetBoolValue("botweapon", "botweapon", Setting1::botweapon);
	ini.SetBoolValue("botWeapons_iconsH", "botWeapons_iconsH", Setting1::botWeapons_iconsH);
	//==BOT ST1
	ini.SetBoolValue("botst1name", "botst1name", Setting1::botst1name);
	ini.SetBoolValue("botst1line", "botst1line", Setting1::botst1line);
	ini.SetBoolValue("botst1Bone", "botst1Bone", Setting1::botst1Bone);
	ini.SetBoolValue("botst1health", "botst1health", Setting1::botst1health);
	ini.SetBoolValue("botst1cornerbox", "botst1cornerbox", Setting1::botst1cornerbox);
	ini.SetBoolValue("botst1fullbox", "botst1fullbox", Setting1::botst1fullbox);
	ini.SetBoolValue("botst1blood", "botst1blood", Setting1::botst1blood);
	ini.SetBoolValue("botst1distance", "botst1distance", Setting1::botst1distance);
	ini.SetBoolValue("botst1weapon", "botst1weapon", Setting1::botst1weapon);
	ini.SetBoolValue("botst1Weapons_iconsH", "botst1Weapons_iconsH", Setting1::botst1Weapons_iconsH);
	//==BOT ST2
	ini.SetBoolValue("botst2name", "botst2name", Setting1::botst2name);
	ini.SetBoolValue("botst2line", "botst2line", Setting1::botst2line);
	ini.SetBoolValue("botst2Bone", "botst2Bone", Setting1::botst2Bone);
	ini.SetBoolValue("botst2health", "botst2health", Setting1::botst2health);
	ini.SetBoolValue("botst2cornerbox", "botst2cornerbox", Setting1::botst2cornerbox);
	ini.SetBoolValue("botst2fullbox", "botst2fullbox", Setting1::botst2fullbox);
	ini.SetBoolValue("botst2blood", "botst2blood", Setting1::botst2blood);
	ini.SetBoolValue("botst2distance", "botst2distance", Setting1::botst2distance);
	ini.SetBoolValue("botst2weapon", "botst2weapon", Setting1::botst2weapon);
	ini.SetBoolValue("botst2Weapons_iconsH", "botst2Weapons_iconsH", Setting1::botst2Weapons_iconsH);
	//==BOT ST3
	ini.SetBoolValue("botst3name", "botst3name", Setting1::botst3name);
	ini.SetBoolValue("botst3line", "botst3line", Setting1::botst3line);
	ini.SetBoolValue("botst3Bone", "botst3Bone", Setting1::botst3Bone);
	ini.SetBoolValue("botst3health", "botst3health", Setting1::botst3health);
	ini.SetBoolValue("botst3cornerbox", "botst3cornerbox", Setting1::botst3cornerbox);
	ini.SetBoolValue("botst3fullbox", "botst3fullbox", Setting1::botst3fullbox);
	ini.SetBoolValue("botst3blood", "botst3blood", Setting1::botst3blood);
	ini.SetBoolValue("botst3distance", "botst3distance", Setting1::botst3distance);
	ini.SetBoolValue("botst3weapon", "botst3weapon", Setting1::botst3weapon);
	ini.SetBoolValue("botst3Weapons_iconsH", "botst3Weapons_iconsH", Setting1::botst3Weapons_iconsH);
	//=======================================================================================================
	//==player
	ini.SetBoolValue("playername", "playername", Setting1::playername);
	ini.SetBoolValue("playerline", "playerline", Setting1::playerline);
	ini.SetBoolValue("playerBone", "playerBone", Setting1::playerBone);
	ini.SetBoolValue("playerhealth", "playerhealth", Setting1::playerhealth);
	ini.SetBoolValue("playercornerbox", "playercornerbox", Setting1::playercornerbox);
	ini.SetBoolValue("playerfullbox", "playerfullbox", Setting1::playerfullbox);
	ini.SetBoolValue("playerblood", "playerblood", Setting1::playerblood);
	ini.SetBoolValue("playerdistance", "playerdistance", Setting1::playerdistance);
	ini.SetBoolValue("playerweapon", "playerweapon", Setting1::playerweapon);
	ini.SetBoolValue("playerWeapons_iconsH", "playerWeapons_iconsH", Setting1::playerWeapons_iconsH);
	//==player ST1
	ini.SetBoolValue("playerst1name", "playerst1name", Setting1::playerst1name);
	ini.SetBoolValue("playerst1line", "playerst1line", Setting1::playerst1line);
	ini.SetBoolValue("playerst1Bone", "playerst1Bone", Setting1::playerst1Bone);
	ini.SetBoolValue("playerst1health", "playerst1health", Setting1::playerst1health);
	ini.SetBoolValue("playerst1cornerbox", "playerst1cornerbox", Setting1::playerst1cornerbox);
	ini.SetBoolValue("playerst1fullbox", "playerst1fullbox", Setting1::playerst1fullbox);
	ini.SetBoolValue("playerst1blood", "playerst1blood", Setting1::playerst1blood);
	ini.SetBoolValue("playerst1distance", "playerst1distance", Setting1::playerst1distance);
	ini.SetBoolValue("playerst1weapon", "playerst1weapon", Setting1::playerst1weapon);
	ini.SetBoolValue("playerst1Weapons_iconsH", "playerst1Weapons_iconsH", Setting1::playerst1Weapons_iconsH);
	//==player ST2
	ini.SetBoolValue("playerst2name", "playerst2name", Setting1::playerst2name);
	ini.SetBoolValue("playerst2line", "playerst2line", Setting1::playerst2line);
	ini.SetBoolValue("playerst2Bone", "playerst2Bone", Setting1::playerst2Bone);
	ini.SetBoolValue("playerst2health", "playerst2health", Setting1::playerst2health);
	ini.SetBoolValue("playerst2cornerbox", "playerst2cornerbox", Setting1::playerst2cornerbox);
	ini.SetBoolValue("playerst2fullbox", "playerst2fullbox", Setting1::playerst2fullbox);
	ini.SetBoolValue("playerst2blood", "playerst2blood", Setting1::playerst2blood);
	ini.SetBoolValue("playerst2distance", "playerst2distance", Setting1::playerst2distance);
	ini.SetBoolValue("playerst2weapon", "playerst2weapon", Setting1::playerst2weapon);
	ini.SetBoolValue("playerst2Weapons_iconsH", "playerst2Weapons_iconsH", Setting1::playerst2Weapons_iconsH);
	//==player ST3
	ini.SetBoolValue("playerst3name", "playerst3name", Setting1::playerst3name);
	ini.SetBoolValue("playerst3line", "playerst3line", Setting1::playerst3line);
	ini.SetBoolValue("playerst3Bone", "playerst3Bone", Setting1::playerst3Bone);
	ini.SetBoolValue("playerst3health", "playerst3health", Setting1::playerst3health);
	ini.SetBoolValue("playerst3cornerbox", "playerst3cornerbox", Setting1::playerst3cornerbox);
	ini.SetBoolValue("playerst3fullbox", "playerst3fullbox", Setting1::playerst3fullbox);
	ini.SetBoolValue("playerst3blood", "playerst3blood", Setting1::playerst3blood);
	ini.SetBoolValue("playerst3distance", "playerst3distance", Setting1::playerst3distance);
	ini.SetBoolValue("playerst3weapon", "playerst3weapon", Setting1::playerst3weapon);
	ini.SetBoolValue("playerst3Weapons_iconsH", "playerst3Weapons_iconsH", Setting1::playerst3Weapons_iconsH);
	//==============================================================================================
	//
	ini.SetBoolValue("Flags", "Flags", Setting1::Flags);
	ini.SetBoolValue("FlagText", "FlagText", Setting1::FlagText);
	ini.SetBoolValue("Flagimge", "Flagimge", Setting1::Flagimge);
	ini.SetBoolValue("AimingAlert", "AimingAlert", Setting1::AimingAlert);
	ini.SetBoolValue("AirDropBox", "AirDropBox", Setting1::AirDropBox);
	ini.SetBoolValue("AirDropBoxItems", "AirDropBoxItems", Setting1::AirDropBoxItems);
	ini.SetBoolValue("deadbox", "deadbox", Setting1::deadbox);
	ini.SetBoolValue("deadboxItems", "deadboxItems", Setting1::deadboxItems);
	//Vehicle---------------------------------------------------------------------------------------
	ini.SetBoolValue("Vehicle", "Vehicle", Setting1::Vehicle);
	ini.SetBoolValue("Vehiclest1", "Vehiclest1", Setting1::Vehiclest1);
	ini.SetBoolValue("Vehiclest2", "Vehiclest2", Setting1::Vehiclest2);
	ini.SetBoolValue("Vehiclest3", "Vehiclest3", Setting1::Vehiclest3);
	ini.SetBoolValue("VehicleFeul", "VehicleFeul", Setting1::VehicleFeul);
	ini.SetBoolValue("VehicleFeulst1", "VehicleFeulst1", Setting1::VehicleFeulst1);
	ini.SetBoolValue("VehicleFeulst2", "VehicleFeulst2", Setting1::VehicleFeulst2);
	ini.SetBoolValue("VehicleFeulst3", "VehicleFeulst3", Setting1::VehicleFeulst3);
	ini.SetBoolValue("VehicleHp", "VehicleHp", Setting1::VehicleHp);
	ini.SetBoolValue("VehicleHpst1", "VehicleHpst1", Setting1::VehicleHpst1);
	ini.SetBoolValue("VehicleHpst2", "VehicleHpst2", Setting1::VehicleHpst2);
	ini.SetBoolValue("VehicleHpst3", "VehicleHpst3", Setting1::VehicleHpst3);
	//
	//===========================================================================
	//bot Size
	ini.SetDoubleValue("botnames1", "botnames1", Setting1::botnames1);
	ini.SetDoubleValue("botnames2", "botnames2", Setting1::botnames2);
	ini.SetDoubleValue("botnames3", "botnames3", Setting1::botnames3);

	ini.SetDoubleValue("botlines1", "botlines1", Setting1::botlines1);
	ini.SetDoubleValue("botlines2", "botlines2", Setting1::botlines2);
	ini.SetDoubleValue("botlines3", "botlines3", Setting1::botlines3);

	ini.SetDoubleValue("botBones1", "botBones1", Setting1::botBones1);
	ini.SetDoubleValue("botBones2", "botBones2", Setting1::botBones2);
	ini.SetDoubleValue("botBones3", "botBones3", Setting1::botBones3);

	ini.SetDoubleValue("bothealths1", "bothealths1", Setting1::bothealths1);
	ini.SetDoubleValue("bothealths2", "bothealths2", Setting1::bothealths2);
	ini.SetDoubleValue("bothealths3", "bothealths3", Setting1::bothealths3);

	ini.SetDoubleValue("botcornerboxs1", "botcornerboxs1", Setting1::botcornerboxs1);
	ini.SetDoubleValue("botcornerboxs2", "botcornerboxs2", Setting1::botcornerboxs2);
	ini.SetDoubleValue("botcornerboxs3", "botcornerboxs3", Setting1::botcornerboxs3);

	ini.SetDoubleValue("botfullboxs1", "botfullboxs1", Setting1::botfullboxs1);
	ini.SetDoubleValue("botfullboxs2", "botfullboxs2", Setting1::botfullboxs2);
	ini.SetDoubleValue("botfullboxs3", "botfullboxs3", Setting1::botfullboxs3);

	ini.SetDoubleValue("botdistances1", "botdistances1", Setting1::botdistances1);
	ini.SetDoubleValue("botdistances2", "botdistances2", Setting1::botdistances2);
	ini.SetDoubleValue("botdistances3", "botdistances3", Setting1::botdistances3);

	ini.SetDoubleValue("botweaponFalses1", "botweaponFalses1", Setting1::botweaponFalses1);
	ini.SetDoubleValue("botweaponFalses2", "botweaponFalses2", Setting1::botweaponFalses2);
	ini.SetDoubleValue("botweaponFalses3", "botweaponFalses3", Setting1::botweaponFalses3);

	ini.SetDoubleValue("botweapons1", "botweapons1", Setting1::botweapons1);
	ini.SetDoubleValue("botweapons2", "botweapons3", Setting1::botweapons3);
	ini.SetDoubleValue("botweapons3", "botweapons3", Setting1::botweapons3);
	//
	// ===========================================================================
	//player Size
	ini.SetDoubleValue("playernames1", "playernames1", Setting1::playernames1);
	ini.SetDoubleValue("playernames2", "playernames2", Setting1::playernames2);
	ini.SetDoubleValue("playernames3", "playernames3", Setting1::playernames3);

	ini.SetDoubleValue("playerlines1", "playerlines1", Setting1::playerlines1);
	ini.SetDoubleValue("playerlines2", "playerlines2", Setting1::playerlines2);
	ini.SetDoubleValue("playerlines3", "playerlines3", Setting1::playerlines3);

	ini.SetDoubleValue("playerBones1", "playerBones1", Setting1::playerBones1);
	ini.SetDoubleValue("playerBones2", "playerBones2", Setting1::playerBones2);
	ini.SetDoubleValue("playerBones3", "playerBones3", Setting1::playerBones3);

	ini.SetDoubleValue("playerhealths1", "playerhealths1", Setting1::playerhealths1);
	ini.SetDoubleValue("playerhealths2", "playerhealths2", Setting1::playerhealths2);
	ini.SetDoubleValue("playerhealths3", "playerhealths3", Setting1::playerhealths3);

	ini.SetDoubleValue("playercornerboxs1", "playercornerboxs1", Setting1::playercornerboxs1);
	ini.SetDoubleValue("playercornerboxs2", "playercornerboxs2", Setting1::playercornerboxs2);
	ini.SetDoubleValue("playercornerboxs3", "playercornerboxs3", Setting1::playercornerboxs3);

	ini.SetDoubleValue("playerfullboxs1", "playerfullboxs1", Setting1::playerfullboxs1);
	ini.SetDoubleValue("playerfullboxs2", "playerfullboxs2", Setting1::playerfullboxs2);
	ini.SetDoubleValue("playerfullboxs3", "playerfullboxs3", Setting1::playerfullboxs3);

	ini.SetDoubleValue("playerdistances1", "playerdistances1", Setting1::playerdistances1);
	ini.SetDoubleValue("playerdistances2", "playerdistances2", Setting1::playerdistances2);
	ini.SetDoubleValue("playerdistances3", "playerdistances3", Setting1::playerdistances3);

	ini.SetDoubleValue("playerweaponFalses1", "playerweaponFalses1", Setting1::playerweaponFalses1);
	ini.SetDoubleValue("playerweaponFalses2", "playerweaponFalses2", Setting1::playerweaponFalses2);
	ini.SetDoubleValue("playerweaponFalses3", "playerweaponFalses3", Setting1::playerweaponFalses3);

	ini.SetDoubleValue("playerweapons1", "playerweapons1", Setting1::playerweapons1);
	ini.SetDoubleValue("playerweapons2", "playerweapons3", Setting1::playerweapons3);
	ini.SetDoubleValue("playerweapons3", "playerweapons3", Setting1::playerweapons3);
	//
	//===========================================================
	//Size
	ini.SetDoubleValue("AimingAlerts1", "AimingAlerts1", Setting1::AimingAlerts1);
	ini.SetDoubleValue("AimingAlerts2", "AimingAlerts3", Setting1::AimingAlerts2);
	ini.SetDoubleValue("AimingAlerts3", "AimingAlerts3", Setting1::AimingAlerts3);

	ini.SetDoubleValue("FlagTexts1", "FlagTexts1", Setting1::FlagTexts1);
	ini.SetDoubleValue("FlagTexts2", "FlagTexts2", Setting1::FlagTexts2);
	ini.SetDoubleValue("FlagTexts3", "FlagTexts3", Setting1::FlagTexts3);

	ini.SetDoubleValue("AirDropBoxs1", "AirDropBoxs1", Setting1::AirDropBoxs1);
	ini.SetDoubleValue("AirDropBoxs2", "AirDropBoxs2", Setting1::AirDropBoxs2);
	ini.SetDoubleValue("AirDropBoxs3", "AirDropBoxs3", Setting1::AirDropBoxs3);

	ini.SetDoubleValue("AirDropBoxItemss1", "AirDropBoxItemss1", Setting1::AirDropBoxItemss1);
	ini.SetDoubleValue("AirDropBoxItemss2", "AirDropBoxItemss2", Setting1::AirDropBoxItemss2);
	ini.SetDoubleValue("AirDropBoxItemss3", "AirDropBoxItemss3", Setting1::AirDropBoxItemss3);

	ini.SetDoubleValue("deadboxs1", "deadboxs1", Setting1::deadboxs1);
	ini.SetDoubleValue("deadboxs2", "deadboxs2", Setting1::deadboxs2);
	ini.SetDoubleValue("deadboxs3", "deadboxs3", Setting1::deadboxs3);

	ini.SetDoubleValue("deadboxItemss1", "deadboxItemss1", Setting1::deadboxItemss1);
	ini.SetDoubleValue("deadboxItemss2", "deadboxItemss2", Setting1::deadboxItemss2);
	ini.SetDoubleValue("deadboxItemss3", "deadboxItemss3", Setting1::deadboxItemss3);
	//
	ini.SetDoubleValue("Vehicles", "Vehicles", Setting1::Vehicles);
	ini.SetDoubleValue("Vehicles1", "Vehicles1", Setting1::Vehicles1);
	ini.SetDoubleValue("Vehicles2", "Vehicles2", Setting1::Vehicles2);
	ini.SetDoubleValue("Vehicles3", "Vehicles3", Setting1::Vehicles3);
	//========================================================================================
	//
	ini.SetDoubleValue("skeleeb1", "skeleeb1", skeleeb1);
	ini.SetDoubleValue("skeleeb2", "skeleeb2", skeleeb2);
	ini.SetDoubleValue("skeleeb3", "skeleeb3", skeleeb3);
	ini.SetDoubleValue("skeleep1", "skeleep1", skeleep1);
	ini.SetDoubleValue("skeleep2", "skeleep2", skeleep2);
	ini.SetDoubleValue("skeleep3", "skeleep3", skeleep3);
	//
	ini.SetDoubleValue("linneb1", "linneb1", linneb1);
	ini.SetDoubleValue("linneb2", "linneb2", linneb2);
	ini.SetDoubleValue("linneb3", "linneb3", linneb3);
	ini.SetDoubleValue("linnep1", "linnep1", linnep1);
	ini.SetDoubleValue("linnep2", "linnep2", linnep2);
	ini.SetDoubleValue("linnep3", "linnep3", linnep3);
	//
	ini.SetDoubleValue("hpb1", "hpb1", hpb1);
	ini.SetDoubleValue("hpb2", "hpb2", hpb2);
	ini.SetDoubleValue("hpb3", "hpb3", hpb3);
	ini.SetDoubleValue("hpp1", "hpp1", hpp1);
	ini.SetDoubleValue("hpp2", "hpp2", hpp2);
	ini.SetDoubleValue("hpp3", "hpp3", hpp3);
	//
	ini.SetDoubleValue("CornerBoxb1", "CornerBoxb1", CornerBoxb1);
	ini.SetDoubleValue("CornerBoxb2", "CornerBoxb2", CornerBoxb2);
	ini.SetDoubleValue("CornerBoxb3", "CornerBoxb3", CornerBoxb3);
	ini.SetDoubleValue("CornerBoxp1", "CornerBoxp1", CornerBoxp1);
	ini.SetDoubleValue("CornerBoxp2", "CornerBoxp2", CornerBoxp2);
	ini.SetDoubleValue("CornerBoxp3", "CornerBoxp3", CornerBoxp3);
	//
	ini.SetDoubleValue("botfullboxb1", "botfullboxb1", botfullboxb1);
	ini.SetDoubleValue("botfullboxb2", "botfullboxb2", botfullboxb2);
	ini.SetDoubleValue("botfullboxb3", "botfullboxb3", botfullboxb3);
	ini.SetDoubleValue("botfullboxp1", "botfullboxp1", botfullboxp1);
	ini.SetDoubleValue("botfullboxp2", "botfullboxp2", botfullboxp2);
	ini.SetDoubleValue("botfullboxp3", "botfullboxp3", botfullboxp3);

	//========================================================================================




	//==PLAYER
	/*ini.SetBoolValue("ESP PLAYER", "playername", Setting1::playername);
	ini.SetBoolValue("ESP PLAYER", "playerline", Setting1::playerline);
	ini.SetBoolValue("ESP PLAYER", "playerBone", Setting1::playerBone);
	ini.SetBoolValue("ESP PLAYER", "playercornerbox", Setting1::playercornerbox);
	ini.SetBoolValue("ESP PLAYER", "playerfullbox", Setting1::playerfullbox);
	ini.SetBoolValue("ESP PLAYER", "playerhealth", Setting1::playerhealth);
	ini.SetBoolValue("ESP PLAYER", "playerdistance", Setting1::playerdistance);
	ini.SetBoolValue("ESP PLAYER", "botWeapons_iconsH", Setting1::botWeapons_iconsH);
	ini.SetBoolValue("ESP PLAYER", "playerWeapons_iconsH", Setting1::playerWeapons_iconsH);
	ini.SetBoolValue("ESP PLAYER", "playerweapon", Setting1::playerweapon);*/
	//ini.SetBoolValue("ESP", "KEY8", Setting1::playerdistance);
	/// <summary>
	ini.SetBoolValue("ESP", "key0", Setting::pname);
	ini.SetBoolValue("ESP", "Key1", Setting::Item);
	ini.SetBoolValue("ESP", "Key2", Setting::phealth);
	ini.SetBoolValue("ESP", "Key3", Setting::pline);
	ini.SetBoolValue("ESP", "Key4", Setting::playerweapon);
	ini.SetBoolValue("ESP", "Keyb5", Setting1::botWeapons_iconsH);
	ini.SetBoolValue("ESP", "Keyp5", Setting1::playerWeapons_iconsH);
	ini.SetBoolValue("ESP", "Key6", Setting::playerBone);
	ini.SetBoolValue("ESP", "Key7", Setting::pfullbox);
	ini.SetBoolValue("ESP", "Key8", Setting::pcorner);
	ini.SetBoolValue("ESP", "Key9", Setting::MeEnemyShow);

	/// <summary>
	ini.SetBoolValue("ItemsSelection", "key0", Setting::allitemss);
	ini.SetBoolValue("ItemsSelection", "Key1", Setting::impitems);
	ini.SetBoolValue("ItemsSelection", "Key2", Setting::healthitem);
	ini.SetBoolValue("ItemsSelection", "Key3", Setting::scope);
	ini.SetBoolValue("ItemsSelection", "Key5", Setting::BombAlert);

	/// <summary>
	ini.SetBoolValue("MiscSettings", "key00", Setting::dots);
	ini.SetBoolValue("MiscSettings", "key0", Setting1::dots1);
	ini.SetBoolValue("MiscSettings", "Key1", Setting::AimLineCross);
	ini.SetBoolValue("MiscSettings", "Key2", Setting::AimLineBottm);
	ini.SetBoolValue("MiscSettings", "Key3", Setting::TotalEnemy);
	ini.SetBoolValue("MiscSettings", "Key4", Setting::ShowSideMenu);
	ini.SetBoolValue("MiscSettings", "Key5", Setting::MagicBulletd);
	ini.SetBoolValue("MiscSettings", "Key6", Setting::EnemyLineOfSight);

	///tab2
	////Importan Items
	ini.SetBoolValue("M416", "key0", Setting::Esp_Item_M416);
	ini.SetBoolValue("AKM", "key1", Setting::Esp_Item_AKM);
	ini.SetBoolValue("SCAR-L", "key2", Setting::Esp_Item_SCARL);
	ini.SetBoolValue("M762", "key3", Setting::Esp_Item_M762);
	ini.SetBoolValue("DP28", "key4", Setting::Esp_Item_DP28);
	ini.SetBoolValue("AWM", "key5", Setting::Esp_Item_Awm);
	ini.SetBoolValue("M24", "key6", Setting::Esp_Item_M24);
	ini.SetBoolValue("KAR98", "key7", Setting::Esp_Item_Kar98k);
	ini.SetBoolValue("FlareGun", "key8", Setting::Esp_Item_FlareGun);
	ini.SetBoolValue("Flare", "key9", Setting::Esp_Item_Flare);
	ini.SetBoolValue("AirDrop", "key10", Setting::airdrop);
	ini.SetBoolValue("Armor3", "key11", Setting::Esp_Item_Armor3);
	ini.SetBoolValue("Bag3", "key12", Setting::Esp_Item_Bag3);
	ini.SetBoolValue("Helmet3", "key13", Setting::Esp_Item_Helmet3);
	ini.SetBoolValue("AWMammo", "key14", Setting::Esp_Item_Awmimo);
	ini.SetBoolValue("Dead-Box", "key15", Setting::deadbox);
	ini.SetBoolValue("Dead-Box-list", "key16", Setting::playerdeadbox);
	ini.SetBoolValue("AirDrop-lists", "key17", Setting::airdropitem);
	ini.SetBoolValue("ExtendedQuickDraw", "key18", Setting::Esp_Item_exquic);

	///All Items
	ini.SetBoolValue("Helmet", "key0", Setting::Esp_Item_Helmet1);
	ini.SetBoolValue("Helmet2", "key1", Setting::Esp_Item_Helmet2);
	ini.SetBoolValue("Bag1", "key2", Setting::Esp_Item_Bag1);
	ini.SetBoolValue("Bag2", "key3", Setting::Esp_Item_Bag2);
	ini.SetBoolValue("Armor1", "key4", Setting::Esp_Item_Armor1);
	ini.SetBoolValue("Armor2", "key5", Setting::Esp_Item_Armor2);
	ini.SetBoolValue("G36C", "key6", Setting::Esp_Item_G36C);
	ini.SetBoolValue("QBZ", "key7", Setting::Esp_Item_QBZ);
	ini.SetBoolValue("QBU", "key8", Setting::Esp_Item_QBU);
	ini.SetBoolValue("SLR", "key9", Setting::Esp_Item_SLR);
	ini.SetBoolValue("SKS", "key10", Setting::Esp_Item_SKS);
	ini.SetBoolValue("Mini14", "key11", Setting::Esp_Item_Mini14);
	ini.SetBoolValue("PP19", "key12", Setting::Esp_Item_PP19);
	ini.SetBoolValue("TommyGun", "key13", Setting::Esp_Item_TommyGun);
	ini.SetBoolValue("MP5K", "key14", Setting::Esp_Item_MP5K);
	ini.SetBoolValue("UMP9", "key15", Setting::Esp_Item_UMP9);
	ini.SetBoolValue("Vector", "key16", Setting::Esp_Item_Vector);
	ini.SetBoolValue("Uzi", "key17", Setting::Esp_Item_Uzi);
	ini.SetBoolValue("7.62mm", "key18", Setting::Esp_Item_762mm);
	ini.SetBoolValue("556mm", "key19", Setting::Esp_Item_556mm);
	ini.SetBoolValue("9mm", "key20", Setting::Esp_Item_9mm);
	ini.SetBoolValue("45ACP", "key21", Setting::Esp_Item_45ACP);
	ini.SetBoolValue("Holo", "key22", Setting::Esp_Item_Holo);
	ini.SetBoolValue("Mk47-Mutant", "key23", Setting::Esp_Item_Mk47Mutant);

	///Bomb Items
	ini.SetBoolValue("Frag", "key0", Setting::Esp_Item_Frag);
	ini.SetBoolValue("Smoke", "key1", Setting::Esp_Item_Smoke);
	ini.SetBoolValue("Molotof", "key2", Setting::Esp_Item_Molotof);

	///Health items
	ini.SetBoolValue("MedKit", "key0", Setting::Esp_Item_MedKit);
	ini.SetBoolValue("FirstAidKit", "key1", Setting::Esp_Item_FirstAidKit);
	ini.SetBoolValue("Painkiller", "key2", Setting::Esp_Item_Painkiller);
	ini.SetBoolValue("EnergyDrink", "key3", Setting::Esp_Item_EnergyDrink);
	ini.SetBoolValue("AdrenalineSyringe", "key4", Setting::Esp_Item_AdrenalineSyringe);

	//Scope Items
	ini.SetBoolValue("x2", "key0", Setting::Esp_Item_x2);
	ini.SetBoolValue("x3", "key1", Setting::Esp_Item_x3);
	ini.SetBoolValue("x4", "key2", Setting::Esp_Item_x4);
	ini.SetBoolValue("x6", "key3", Setting::Esp_Item_x6);
	ini.SetBoolValue("x8", "key4", Setting::Esp_Item_x8);

	//TAB 4
	//MAGIC
	ini.SetBoolValue("MagicBullet", "Enabled", Setting::MagicBullet);
	ini.SetBoolValue("MagicBulletticked", "Enabled", Setting::MagicBulletticked);
	ini.SetBoolValue("MagicBulletd", "Enabled", Setting::MagicBulletd);
	ini.SetLongValue("AimPositon", "key0", Setting::curraim);
	ini.SetBoolValue("FOV", "key1", Setting::fovcircle);
	ini.SetDoubleValue("FOV Size", "Value", Setting::fovcircleredus); //For Writing Values
	ini.SetBoolValue("PREDICTION", "Enabled", Setting::PREDICTION);
	ini.SetBoolValue("Bullet Tracking Range", "Enabled", Setting::BulletTrackingRange);
	ini.SetDoubleValue("Tracking Range", "Value", Setting::magicrange); //For Writing Values
	ini.SetDoubleValue("Skip BOTs", "Enabled", Setting::SkipBots); //For Writing Values
	/// INSTANT
	ini.SetBoolValue("InstantHit", "Enabled", Setting::instanthit); //For Writing Bool
	ini.SetDoubleValue("InstantHit", "Value", Setting::instantv); //For Writing Values

	//CAMARA 
	ini.SetBoolValue("Cache360", "Enabled", Setting::CameraCatch); //For Writing Bool

	//Recoil 
	ini.SetBoolValue("Recoil", "Enabled", Setting::recoil); //For Writing Bool

	//Memory 
	ini.SetBoolValue("MemoryAimbot", "Enabled", Setting::CameraAimBot); //For Writing Bool

	///ipad
	ini.SetBoolValue("Ipad", "Enabled", Setting::IpadView); //For Writing Bool
	//ini.SetDoubleValue("Ipadvv", "Value", Setting::IpadViewValue); //For Writing Values

	//Force 
	ini.SetBoolValue("Force", "Enabled", Setting::ForceTPP); //For Writing Bool

	/// INSTANT
	ini.SetBoolValue("FastRun", "Enabled", Setting::fastrun);
	ini.SetDoubleValue("FastRunv", "Value", Setting::fastrv);
	ini.SetLongValue("FastRunvk", "Value", Setting::fastrunkey);

	//WeaponSwitch
	ini.SetBoolValue("WeaponSwitch", "Enabled", Setting::FastWeponSwith); //For Writing Bool

	///XEffect
	ini.SetBoolValue("XEffect", "Enabled", Setting::XEffect); //For Writing Bool
	ini.SetDoubleValue("XeffectColorhd", "Value", Setting::XEffectRandomHead); //For Writing Values
	ini.SetDoubleValue("Xeffect Color Body", "Value", Setting::XEffectRandomBody); //For Writing Values

	///Scopev
	ini.SetBoolValue("Scope", "Enabled", Setting::ScopeZoom); //For Writing Bool
	ini.SetDoubleValue("Scopev", "Value", Setting::scopefov); //For Writing Values
	
	///Fast Car
	ini.SetBoolValue("FastCar", "Enabled", Setting::speedcar); //For Writing Bool
	ini.SetDoubleValue("FastCarv", "Value", Setting::carsv); //For Writing Values
	ini.SetLongValue("Triggerv", "Value", Setting::FastCarKeys); //For Writing Values

	/// TAB5
	ini.SetLongValue("TextSize", "Value", Setting::Normalfontsize);//Same for saving item text sizes Sizes
	ini.SetLongValue("ImportantTextSize", "Value", Setting::fontsize);//Same for saving item text sizes Sizes
	ini.SetLongValue("UpdateThreadDelay", "Value", Setting::UpdateThreadDelay);
	ini.SetLongValue("EspThreadDelay", "Value", Setting::EspThreadDelay);
	ini.SetLongValue("AdreessGetterDelay", "Value", Setting::AdreessGetterDelay);
	ini.SetLongValue("Value", "overlaycolor", Setting::overlaycolor);

	ini.SetBoolValue("gameinfo", "gameinfo", Setting::gameinfo);

	ini.SetBoolValue("Snowflake", "Snowflake", Setting::Snowflake);
	ini.SetBoolValue("OverlayTransparency", "OverlayTransparency", Setting::OverlayTransparency);

	ini.SaveFile(Path.c_str());
}

void LoadConfiggg(std::string Path)
{
	CSimpleIniA ini;
	ini.SetUnicode();
	SI_Error rc = ini.LoadFile(Path.c_str());
	if (rc < 0) { std::cout << "File not found"; };

	Setting::MenuTransparency = ini.GetDoubleValue("MenuTransparency", "MenuTransparency");
	Setting::SideMenuTransparencyBg = ini.GetDoubleValue("SideMenuTransparencyBg", "SideMenuTransparencyBg");
	Setting::SideMenuTransparencyBorder = ini.GetDoubleValue("SideMenuTransparencyBorder", "SideMenuTransparencyBorder");

	//style
	Setting1::style1 = ini.GetBoolValue("style1", "style1");
	Setting1::style2 = ini.GetBoolValue("style2", "style2");
	Setting1::style3 = ini.GetBoolValue("style3", "style3");
	Setting1::style4 = ini.GetBoolValue("style4", "style4");

	//bot
	Setting1::botname = ini.GetBoolValue("botname", "botname");
	Setting1::botline = ini.GetBoolValue("botline", "botline");
	Setting1::botBone = ini.GetBoolValue("botBone", "botBone");
	Setting1::bothealth = ini.GetBoolValue("bothealth", "bothealth");
	Setting1::botcornerbox = ini.GetBoolValue("botcornerbox", "botcornerbox");
	Setting1::botfullbox = ini.GetBoolValue("botfullbox", "botfullbox");
	Setting1::botblood = ini.GetBoolValue("botblood", "botblood");
	Setting1::botdistance = ini.GetBoolValue("botdistance", "botdistance");
	Setting1::botweapon = ini.GetBoolValue("botweapon", "botweapon");
	Setting1::botWeapons_iconsH = ini.GetBoolValue("botWeapons_iconsH", "botWeapons_iconsH");
	//bot ST1
	Setting1::botst1name = ini.GetBoolValue("botst1name", "botst1name");
	Setting1::botst1line = ini.GetBoolValue("botst1line", "botst1line");
	Setting1::botst1Bone = ini.GetBoolValue("botst1Bone", "botst1Bone");
	Setting1::botst1health = ini.GetBoolValue("botst1health", "botst1health");
	Setting1::botst1cornerbox = ini.GetBoolValue("botst1cornerbox", "botst1cornerbox");
	Setting1::botst1fullbox = ini.GetBoolValue("botst1fullbox", "botst1fullbox");
	Setting1::botst1blood = ini.GetBoolValue("botst1blood", "botst1blood");
	Setting1::botst1distance = ini.GetBoolValue("botst1distance", "botst1distance");
	Setting1::botst1weapon = ini.GetBoolValue("botst1weapon", "botst1weapon");
	Setting1::botst1Weapons_iconsH = ini.GetBoolValue("botst1Weapons_iconsH", "botst1Weapons_iconsH");
	//bot ST2
	Setting1::botst2name = ini.GetBoolValue("botst2name", "botst2name");
	Setting1::botst2line = ini.GetBoolValue("botst2line", "botst2line");
	Setting1::botst2Bone = ini.GetBoolValue("botst2Bone", "botst2Bone");
	Setting1::botst2health = ini.GetBoolValue("botst2health", "botst2health");
	Setting1::botst2cornerbox = ini.GetBoolValue("botst2cornerbox", "botst2cornerbox");
	Setting1::botst2fullbox = ini.GetBoolValue("botst2fullbox", "botst2fullbox");
	Setting1::botst2blood = ini.GetBoolValue("botst2blood", "botst2blood");
	Setting1::botst2distance = ini.GetBoolValue("botst2distance", "botst2distance");
	Setting1::botst2weapon = ini.GetBoolValue("botst2weapon", "botst2weapon");
	Setting1::botst2Weapons_iconsH = ini.GetBoolValue("botst2Weapons_iconsH", "botst2Weapons_iconsH");
	//bot ST3
	Setting1::botst3name = ini.GetBoolValue("botst3name", "botst3name");
	Setting1::botst3line = ini.GetBoolValue("botst3line", "botst3line");
	Setting1::botst3Bone = ini.GetBoolValue("botst3Bone", "botst3Bone");
	Setting1::botst3health = ini.GetBoolValue("botst3health", "botst3health");
	Setting1::botst3cornerbox = ini.GetBoolValue("botst3cornerbox", "botst3cornerbox");
	Setting1::botst3fullbox = ini.GetBoolValue("botst3fullbox", "botst3fullbox");
	Setting1::botst3blood = ini.GetBoolValue("botst3blood", "botst3blood");
	Setting1::botst3distance = ini.GetBoolValue("botst3distance", "botst3distance");
	Setting1::botst3weapon = ini.GetBoolValue("botst3weapon", "botst3weapon");
	Setting1::botst3Weapons_iconsH = ini.GetBoolValue("botst3Weapons_iconsH", "botst3Weapons_iconsH");
	//=====================================================================================
	//player
	Setting1::playername = ini.GetBoolValue("playername", "playername");
	Setting1::playerline = ini.GetBoolValue("playerline", "playerline");
	Setting1::playerBone = ini.GetBoolValue("playerBone", "playerBone");
	Setting1::playerhealth = ini.GetBoolValue("playerhealth", "playerhealth");
	Setting1::playercornerbox = ini.GetBoolValue("playercornerbox", "playercornerbox");
	Setting1::playerfullbox = ini.GetBoolValue("playerfullbox", "playerfullbox");
	Setting1::playerblood = ini.GetBoolValue("playerblood", "playerblood");
	Setting1::playerdistance = ini.GetBoolValue("playerdistance", "playerdistance");
	Setting1::playerweapon = ini.GetBoolValue("playerweapon", "playerweapon");
	Setting1::playerWeapons_iconsH = ini.GetBoolValue("playerWeapons_iconsH", "playerWeapons_iconsH");
	//player ST1
	Setting1::playerst1name = ini.GetBoolValue("playerst1name", "playerst1name");
	Setting1::playerst1line = ini.GetBoolValue("playerst1line", "playerst1line");
	Setting1::playerst1Bone = ini.GetBoolValue("playerst1Bone", "playerst1Bone");
	Setting1::playerst1health = ini.GetBoolValue("playerst1health", "playerst1health");
	Setting1::playerst1cornerbox = ini.GetBoolValue("playerst1cornerbox", "playerst1cornerbox");
	Setting1::playerst1fullbox = ini.GetBoolValue("playerst1fullbox", "playerst1fullbox");
	Setting1::playerst1blood = ini.GetBoolValue("playerst1blood", "playerst1blood");
	Setting1::playerst1distance = ini.GetBoolValue("playerst1distance", "playerst1distance");
	Setting1::playerst1weapon = ini.GetBoolValue("playerst1weapon", "playerst1weapon");
	Setting1::playerst1Weapons_iconsH = ini.GetBoolValue("playerst1Weapons_iconsH", "playerst1Weapons_iconsH");
	//player ST2
	Setting1::playerst2name = ini.GetBoolValue("playerst2name", "playerst2name");
	Setting1::playerst2line = ini.GetBoolValue("playerst2line", "playerst2line");
	Setting1::playerst2Bone = ini.GetBoolValue("playerst2Bone", "playerst2Bone");
	Setting1::playerst2health = ini.GetBoolValue("playerst2health", "playerst2health");
	Setting1::playerst2cornerbox = ini.GetBoolValue("playerst2cornerbox", "playerst2cornerbox");
	Setting1::playerst2fullbox = ini.GetBoolValue("playerst2fullbox", "playerst2fullbox");
	Setting1::playerst2blood = ini.GetBoolValue("playerst2blood", "playerst2blood");
	Setting1::playerst2distance = ini.GetBoolValue("playerst2distance", "playerst2distance");
	Setting1::playerst2weapon = ini.GetBoolValue("playerst2weapon", "playerst2weapon");
	Setting1::playerst2Weapons_iconsH = ini.GetBoolValue("playerst2Weapons_iconsH", "playerst2Weapons_iconsH");
	//player ST3
	Setting1::playerst3name = ini.GetBoolValue("playerst3name", "playerst3name");
	Setting1::playerst3line = ini.GetBoolValue("playerst3line", "playerst3line");
	Setting1::playerst3Bone = ini.GetBoolValue("playerst3Bone", "playerst3Bone");
	Setting1::playerst3health = ini.GetBoolValue("playerst3health", "playerst3health");
	Setting1::playerst3cornerbox = ini.GetBoolValue("playerst3cornerbox", "playerst3cornerbox");
	Setting1::playerst3fullbox = ini.GetBoolValue("playerst3fullbox", "playerst3fullbox");
	Setting1::playerst3blood = ini.GetBoolValue("playerst3blood", "playerst3blood");
	Setting1::playerst3distance = ini.GetBoolValue("playerst3distance", "playerst3distance");
	Setting1::playerst3weapon = ini.GetBoolValue("playerst3weapon", "playerst3weapon");
	Setting1::playerst3Weapons_iconsH = ini.GetBoolValue("playerst3Weapons_iconsH", "playerst3Weapons_iconsH");
	//==============================================================================================
	//
	Setting1::Flags = ini.GetBoolValue("Flags", "Flags");
	Setting1::FlagText = ini.GetBoolValue("FlagText", "FlagText");
	Setting1::Flagimge = ini.GetBoolValue("Flagimge", "Flagimge");
	Setting1::AimingAlert = ini.GetBoolValue("AimingAlert", "AimingAlert");
	Setting1::AirDropBox = ini.GetBoolValue("AirDropBox", "AirDropBox");
	Setting1::AirDropBoxItems = ini.GetBoolValue("AirDropBoxItems", "AirDropBoxItems");
	Setting1::deadbox = ini.GetBoolValue("deadbox", "deadbox");
	Setting1::deadboxItems = ini.GetBoolValue("deadboxItems", "deadboxItems");
	//
	Setting1::Vehicle = ini.GetBoolValue("Vehicle", "Vehicle");
	Setting1::Vehiclest1 = ini.GetBoolValue("Vehiclest1", "Vehiclest1");
	Setting1::Vehiclest2 = ini.GetBoolValue("Vehiclest2", "Vehiclest2");
	Setting1::Vehiclest3 = ini.GetBoolValue("Vehiclest3", "Vehiclest3");
	Setting1::VehicleFeul = ini.GetBoolValue("VehicleFeul", "VehicleFeul");
	Setting1::VehicleFeulst1 = ini.GetBoolValue("VehicleFeulst1", "VehicleFeulst1");
	Setting1::VehicleFeulst2 = ini.GetBoolValue("VehicleFeulst2", "VehicleFeulst2");
	Setting1::VehicleFeulst3 = ini.GetBoolValue("VehicleFeulst3", "VehicleFeulst3");
	Setting1::VehicleHp = ini.GetBoolValue("VehicleHp", "VehicleHp");
	Setting1::VehicleHpst1 = ini.GetBoolValue("VehicleHpst1", "VehicleHpst1");
	Setting1::VehicleHpst2 = ini.GetBoolValue("VehicleHpst2", "VehicleHpst2");
	Setting1::VehicleHpst3 = ini.GetBoolValue("VehicleHpst3", "VehicleHpst3");
	//
	//===========================================================================
	//bot Size
	Setting1::botnames1 = ini.GetDoubleValue("botnames1", "botnames1");
	Setting1::botnames2 = ini.GetDoubleValue("botnames2", "botnames2");
	Setting1::botnames3 = ini.GetDoubleValue("botnames3", "botnames3");

	Setting1::botlines1 = ini.GetDoubleValue("botlines1", "botlines1");
	Setting1::botlines2 = ini.GetDoubleValue("botlines2", "botlines2");
	Setting1::botlines3 = ini.GetDoubleValue("botlines3", "botlines3");

	Setting1::botBones1 = ini.GetDoubleValue("botBones1", "botBones1");
	Setting1::botBones2 = ini.GetDoubleValue("botBones2", "botBones2");
	Setting1::botBones3 = ini.GetDoubleValue("botBones3", "botBones3");

	Setting1::bothealths1 = ini.GetDoubleValue("bothealths1", "bothealths1");
	Setting1::bothealths2 = ini.GetDoubleValue("bothealths2", "bothealths2");
	Setting1::bothealths3 = ini.GetDoubleValue("bothealths3", "bothealths3");

	Setting1::botcornerboxs1 = ini.GetDoubleValue("botcornerboxs1", "botcornerboxs1");
	Setting1::botcornerboxs2 = ini.GetDoubleValue("botcornerboxs2", "botcornerboxs2");
	Setting1::botcornerboxs3 = ini.GetDoubleValue("botcornerboxs3", "botcornerboxs3");

	Setting1::botfullboxs1 = ini.GetDoubleValue("botfullboxs1", "botfullboxs1");
	Setting1::botfullboxs2 = ini.GetDoubleValue("botfullboxs2", "botfullboxs2");
	Setting1::botfullboxs3 = ini.GetDoubleValue("botfullboxs3", "botfullboxs3");

	Setting1::botdistances1 = ini.GetDoubleValue("botdistances1", "botdistances1");
	Setting1::botdistances2 = ini.GetDoubleValue("botdistances2", "botdistances2");
	Setting1::botdistances3 = ini.GetDoubleValue("botdistances3", "botdistances3");

	Setting1::botweaponFalses1 = ini.GetDoubleValue("botweaponFalses1", "botweaponFalses1");
	Setting1::botweaponFalses2 = ini.GetDoubleValue("botweaponFalses2", "botweaponFalses2");
	Setting1::botweaponFalses3 = ini.GetDoubleValue("botweaponFalses3", "botweaponFalses3");

	Setting1::botweapons1 = ini.GetDoubleValue("botweapons1", "botweapons1");
	Setting1::botweapons2 = ini.GetDoubleValue("botweapons2", "botweapons2");
	Setting1::botweapons3 = ini.GetDoubleValue("botweapons3", "botweapons3");
	//
	//===========================================================================
	//player Size
	Setting1::playernames1 = ini.GetDoubleValue("playernames1", "playernames1");
	Setting1::playernames2 = ini.GetDoubleValue("playernames2", "playernames2");
	Setting1::playernames3 = ini.GetDoubleValue("playernames3", "playernames3");

	Setting1::playerlines1 = ini.GetDoubleValue("playerlines1", "playerlines1");
	Setting1::playerlines2 = ini.GetDoubleValue("playerlines2", "playerlines2");
	Setting1::playerlines3 = ini.GetDoubleValue("playerlines3", "playerlines3");

	Setting1::playerBones1 = ini.GetDoubleValue("playerBones1", "playerBones1");
	Setting1::playerBones2 = ini.GetDoubleValue("playerBones2", "playerBones2");
	Setting1::playerBones3 = ini.GetDoubleValue("playerBones3", "playerBones3");

	Setting1::playerhealths1 = ini.GetDoubleValue("playerhealths1", "playerhealths1");
	Setting1::playerhealths2 = ini.GetDoubleValue("playerhealths2", "playerhealths2");
	Setting1::playerhealths3 = ini.GetDoubleValue("playerhealths3", "playerhealths3");

	Setting1::playercornerboxs1 = ini.GetDoubleValue("playercornerboxs1", "playercornerboxs1");
	Setting1::playercornerboxs2 = ini.GetDoubleValue("playercornerboxs2", "playercornerboxs2");
	Setting1::playercornerboxs3 = ini.GetDoubleValue("playercornerboxs3", "playercornerboxs3");

	Setting1::playerfullboxs1 = ini.GetDoubleValue("playerfullboxs1", "playerfullboxs1");
	Setting1::playerfullboxs2 = ini.GetDoubleValue("playerfullboxs2", "playerfullboxs2");
	Setting1::playerfullboxs3 = ini.GetDoubleValue("playerfullboxs3", "playerfullboxs3");

	Setting1::playerdistances1 = ini.GetDoubleValue("playerdistances1", "playerdistances1");
	Setting1::playerdistances2 = ini.GetDoubleValue("playerdistances2", "playerdistances2");
	Setting1::playerdistances3 = ini.GetDoubleValue("playerdistances3", "playerdistances3");

	Setting1::playerweaponFalses1 = ini.GetDoubleValue("playerweaponFalses1", "playerweaponFalses1");
	Setting1::playerweaponFalses2 = ini.GetDoubleValue("playerweaponFalses2", "playerweaponFalses2");
	Setting1::playerweaponFalses3 = ini.GetDoubleValue("playerweaponFalses3", "playerweaponFalses3");

	Setting1::playerweapons1 = ini.GetDoubleValue("playerweapons1", "playerweapons1");
	Setting1::playerweapons2 = ini.GetDoubleValue("playerweapons2", "playerweapons2");
	Setting1::playerweapons3 = ini.GetDoubleValue("playerweapons3", "playerweapons3");
	//
	//===========================================================
	//Size
	Setting1::AimingAlerts1 = ini.GetDoubleValue("AimingAlerts1", "AimingAlerts1");
	Setting1::AimingAlerts2 = ini.GetDoubleValue("AimingAlerts2", "AimingAlerts2");
	Setting1::AimingAlerts3 = ini.GetDoubleValue("AimingAlerts3", "AimingAlerts3");

	Setting1::FlagTexts1 = ini.GetDoubleValue("FlagTexts1", "FlagTexts1");
	Setting1::FlagTexts2 = ini.GetDoubleValue("FlagTexts2", "FlagTexts2");
	Setting1::FlagTexts3 = ini.GetDoubleValue("FlagTexts3", "FlagTexts3");

	Setting1::AirDropBoxs1 = ini.GetDoubleValue("AirDropBoxs1", "AirDropBoxs1");
	Setting1::AirDropBoxs2 = ini.GetDoubleValue("AirDropBoxs2", "AirDropBoxs2");
	Setting1::AirDropBoxs3 = ini.GetDoubleValue("AirDropBoxs3", "AirDropBoxs3");
	
	Setting1::AirDropBoxItemss1 = ini.GetDoubleValue("AirDropBoxItemss1", "AirDropBoxItemss1");
	Setting1::AirDropBoxItemss2 = ini.GetDoubleValue("AirDropBoxItemss2", "AirDropBoxItemss2");
	Setting1::AirDropBoxItemss3 = ini.GetDoubleValue("AirDropBoxItemss3", "AirDropBoxItemss3");

	Setting1::deadboxs1 = ini.GetDoubleValue("deadboxs1", "deadboxs1");
	Setting1::deadboxs2 = ini.GetDoubleValue("deadboxs2", "deadboxs2");
	Setting1::deadboxs3 = ini.GetDoubleValue("deadboxs3", "deadboxs3");

	Setting1::deadboxItemss1 = ini.GetDoubleValue("deadboxItemss1", "deadboxItemss1");
	Setting1::deadboxItemss2 = ini.GetDoubleValue("deadboxItemss2", "deadboxItemss2");
	Setting1::deadboxItemss3 = ini.GetDoubleValue("deadboxItemss3", "deadboxItemss3");
	//----------------
	Setting1::Vehicles = ini.GetDoubleValue("Vehicles", "Vehicles");
	Setting1::Vehicles1 = ini.GetDoubleValue("Vehicles1", "Vehicles1");
	Setting1::Vehicles2 = ini.GetDoubleValue("Vehicles2", "Vehicles2");
	Setting1::Vehicles3 = ini.GetDoubleValue("Vehicles3", "Vehicles3");
	//========================================================================================
	//
	skeleeb1 = ini.GetDoubleValue("skeleeb1", "skeleeb1");
	skeleeb2 = ini.GetDoubleValue("skeleeb2", "skeleeb2");
	skeleeb3 = ini.GetDoubleValue("skeleeb3", "skeleeb3");
	skeleep1 = ini.GetDoubleValue("skeleep1", "skeleep1");
	skeleep2 = ini.GetDoubleValue("skeleep2", "skeleep2");
	skeleep3 = ini.GetDoubleValue("skeleep3", "skeleep3");
	//
	linneb1 = ini.GetDoubleValue("linneb1", "linneb1");
	linneb2 = ini.GetDoubleValue("linneb2", "linneb2");
	linneb3 = ini.GetDoubleValue("linneb3", "linneb3");
	linnep1 = ini.GetDoubleValue("linnep1", "linnep1");
	linnep2 = ini.GetDoubleValue("linnep2", "linnep2");
	linnep3 = ini.GetDoubleValue("linnep3", "linnep3");
	//
	hpb1 = ini.GetDoubleValue("hpb1", "hpb1");
	hpb2 = ini.GetDoubleValue("hpb2", "hpb2");
	hpb3 = ini.GetDoubleValue("hpb3", "hpb3");
	hpp1 = ini.GetDoubleValue("hpp1", "hpp1");
	hpp2 = ini.GetDoubleValue("hpp2", "hpp2");
	hpp3 = ini.GetDoubleValue("hpp3", "hpp3");
	//
	CornerBoxb1 = ini.GetDoubleValue("CornerBoxb1", "CornerBoxb1");
	CornerBoxb2 = ini.GetDoubleValue("CornerBoxb2", "CornerBoxb2");
	CornerBoxb3 = ini.GetDoubleValue("CornerBoxb3", "CornerBoxb3");
	CornerBoxp1 = ini.GetDoubleValue("CornerBoxp1", "CornerBoxp1");
	CornerBoxp2 = ini.GetDoubleValue("CornerBoxp2", "CornerBoxp2");
	CornerBoxp3 = ini.GetDoubleValue("CornerBoxp3", "CornerBoxp3");
	//
	botfullboxb1 = ini.GetDoubleValue("botfullboxb1", "botfullboxb1");
	botfullboxb2 = ini.GetDoubleValue("botfullboxb2", "botfullboxb2");
	botfullboxb3 = ini.GetDoubleValue("botfullboxb3", "botfullboxb3");
	botfullboxp1 = ini.GetDoubleValue("botfullboxp1", "botfullboxp1");
	botfullboxp2 = ini.GetDoubleValue("botfullboxp2", "botfullboxp2");
	botfullboxp3 = ini.GetDoubleValue("botfullboxp3", "botfullboxp3");

	//========================================================================================



	///TAB1
	Setting::pname = ini.GetBoolValue("ESP", "key0");
	Setting::Item = ini.GetBoolValue("ESP", "Key1");
	Setting::phealth = ini.GetBoolValue("ESP", "Key2");
	Setting::pline = ini.GetBoolValue("ESP", "Key3");
	Setting::playerweapon = ini.GetBoolValue("ESP", "Key4");
	Setting1::botWeapons_iconsH = ini.GetBoolValue("ESP", "Keyb5");
	Setting1::playerWeapons_iconsH = ini.GetBoolValue("ESP", "Keyp5");
	Setting::playerBone = ini.GetBoolValue("ESP", "Key6");
	Setting::pfullbox = ini.GetBoolValue("ESP", "Key7");
	Setting::pcorner = ini.GetBoolValue("ESP", "Key8");
	Setting::MeEnemyShow = ini.GetBoolValue("ESP", "Key9");

	Setting::allitemss = ini.GetBoolValue("ItemsSelection", "key0");
	Setting::impitems = ini.GetBoolValue("ItemsSelection", "Key1");
	Setting::healthitem = ini.GetBoolValue("ItemsSelection", "Key2");
	Setting::scope = ini.GetBoolValue("ItemsSelection", "Key3");
	Setting::BombAlert = ini.GetBoolValue("ItemsSelection", "Key5");

	////
	Setting::dots = ini.GetBoolValue("MiscSettings", "key00");
	Setting1::dots1 = ini.GetBoolValue("MiscSettings", "key0");
	Setting::AimLineCross = ini.GetBoolValue("MiscSettings", "Key1");
	Setting::AimLineBottm = ini.GetBoolValue("MiscSettings", "Key2");
	Setting::TotalEnemy = ini.GetBoolValue("MiscSettings", "Key3");
	Setting::ShowSideMenu = ini.GetBoolValue("MiscSettings", "Key4");
	Setting::MagicBulletd = ini.GetBoolValue("MiscSettings", "Key5");
	Setting::EnemyLineOfSight = ini.GetBoolValue("MiscSettings", "Key6");

	/// TAB2
	Setting::Esp_Item_M416 = ini.GetBoolValue("M416", "key0");
	Setting::Esp_Item_AKM = ini.GetBoolValue("AKM", "key1");
	Setting::Esp_Item_SCARL = ini.GetBoolValue("SCAR-L", "key2");
	Setting::Esp_Item_M762 = ini.GetBoolValue("M762", "key3");
	Setting::Esp_Item_DP28 = ini.GetBoolValue("DP28", "key4");
	Setting::Esp_Item_Awm = ini.GetBoolValue("AWM", "key5");
	Setting::Esp_Item_M24 = ini.GetBoolValue("M24", "key6");
	Setting::Esp_Item_Kar98k = ini.GetBoolValue("KAR98", "key7");
	Setting::Esp_Item_FlareGun = ini.GetBoolValue("FlareGun", "key8");
	Setting::Esp_Item_Flare = ini.GetBoolValue("Flare", "key9");
	Setting::airdrop = ini.GetBoolValue("AirDrop", "key10");
	Setting::Esp_Item_Armor3 = ini.GetBoolValue("Armor3", "key11");
	Setting::Esp_Item_Bag3 = ini.GetBoolValue("Bag3", "key12");
	Setting::Esp_Item_Helmet3 = ini.GetBoolValue("Helmet3", "key13");
	Setting::Esp_Item_Awmimo = ini.GetBoolValue("AWMammo", "key14");
	Setting::deadbox = ini.GetBoolValue("Dead-Box", "key15");
	Setting::playerdeadbox = ini.GetBoolValue("Dead-Box-list", "key16");
	Setting::airdropitem = ini.GetBoolValue("AirDrop-lists", "key17");
	Setting::Esp_Item_exquic = ini.GetBoolValue("ExtendedQuickDraw", "key18");

	///All Items
	Setting::Esp_Item_Helmet1 = ini.GetBoolValue("Helmet1", "key0");
	Setting::Esp_Item_Helmet2 = ini.GetBoolValue("Helmet2", "key1");
	Setting::Esp_Item_Bag1 = ini.GetBoolValue("Bag1", "key2");
	Setting::Esp_Item_Bag2 = ini.GetBoolValue("Bag2", "key3");
	Setting::Esp_Item_Armor1 = ini.GetBoolValue("Armor1", "key4");
	Setting::Esp_Item_Armor2 = ini.GetBoolValue("Armor2", "key5");
	Setting::Esp_Item_G36C = ini.GetBoolValue("G36C", "key6");
	Setting::Esp_Item_QBZ = ini.GetBoolValue("QBZ", "key7");
	Setting::Esp_Item_QBU = ini.GetBoolValue("QBU", "key8");
	Setting::Esp_Item_SLR = ini.GetBoolValue("SLR", "key9");
	Setting::Esp_Item_SKS = ini.GetBoolValue("SKS", "key10");
	Setting::Esp_Item_Mini14 = ini.GetBoolValue("Mini14", "key11");
	Setting::Esp_Item_PP19 = ini.GetBoolValue("PP19", "key12");
	Setting::Esp_Item_TommyGun = ini.GetBoolValue("Tommy Gun", "key13");
	Setting::Esp_Item_MP5K = ini.GetBoolValue("MP5K", "key14");
	Setting::Esp_Item_UMP9 = ini.GetBoolValue("UMP9", "key15");
	Setting::Esp_Item_Vector = ini.GetBoolValue("Vector", "key16");
	Setting::Esp_Item_Uzi = ini.GetBoolValue("Uzi", "key17");
	Setting::Esp_Item_762mm = ini.GetBoolValue("7.62mm", "key18");
	Setting::Esp_Item_556mm = ini.GetBoolValue("556mm", "key19");
	Setting::Esp_Item_9mm = ini.GetBoolValue("9mm", "key20");
	Setting::Esp_Item_45ACP = ini.GetBoolValue("45ACP", "key21");
	Setting::Esp_Item_Holo = ini.GetBoolValue("Holo", "key22");
	Setting::Esp_Item_Mk47Mutant = ini.GetBoolValue("Mk47-Mutant", "key23");

	///Bomb Items
	Setting::Esp_Item_Frag = ini.GetBoolValue("Frag", "key0");
	Setting::Esp_Item_Smoke = ini.GetBoolValue("Smoke", "key1");
	Setting::Esp_Item_Molotof = ini.GetBoolValue("Molotof", "key2");

	///Health items
	Setting::Esp_Item_MedKit = ini.GetBoolValue("MedKit", "key0");
	Setting::Esp_Item_FirstAidKit = ini.GetBoolValue("FirstAidKit", "key1");
	Setting::Esp_Item_Painkiller = ini.GetBoolValue("Painkiller", "key2");
	Setting::Esp_Item_EnergyDrink = ini.GetBoolValue("EnergyDrink", "key3");
	Setting::Esp_Item_AdrenalineSyringe = ini.GetBoolValue("AdrenalineSyringe", "key4");

	//Scope Items
	Setting::Esp_Item_x2 = ini.GetBoolValue("x2", "key0");
	Setting::Esp_Item_x3 = ini.GetBoolValue("x3", "key1");
	Setting::Esp_Item_x4 = ini.GetBoolValue("x4", "key2");
	Setting::Esp_Item_x6 = ini.GetBoolValue("x6", "key3");
	Setting::Esp_Item_x8 = ini.GetBoolValue("x8", "key4");

	//TAB 4
	//MAGIC
	Setting::MagicBullet = ini.GetBoolValue("MagicBullet", "Enabled");
	Setting::MagicBulletticked = ini.GetBoolValue("MagicBulletticked", "Enabled");
	Setting::MagicBulletd = ini.GetBoolValue("MagicBulletd", "Enabled");
	Setting::curraim = ini.GetLongValue("AimPositon", "key0");
	Setting::fovcircle = ini.GetBoolValue("FOV", "key1");
	Setting::fovcircleredus = ini.GetDoubleValue("FOV Size", "Value"); //For Writing Values
	Setting::SkipBots = ini.GetBoolValue("Skip BOTs", "Enabled");
	Setting::PREDICTION = ini.GetBoolValue("PREDICTION", "Enabled");
	Setting::BulletTrackingRange = ini.GetBoolValue("Bullet Tracking Range", "Enabled");
	Setting::magicrange = ini.GetDoubleValue("Tracking Range", "Value"); //For Writing Values

	/// INSTANT
	Setting::instanthit = ini.GetBoolValue("InstantHit", "Enabled"); //For Writing Bool
	Setting::instantv = ini.GetDoubleValue("InstantHit", "Value"); //For Writing Values

	//CAMARA 
	Setting::CameraCatch = ini.GetBoolValue("Cache360", "Enabled"); //For Writing Bool

	//Recoil 
	Setting::recoil = ini.GetBoolValue("Recoil", "Enabled"); //For Writing Bool

	//Memory 
	Setting::CameraAimBot = ini.GetBoolValue("MemoryAimbot", "Enabled"); //For Writing Bool

	///ipad
	Setting::IpadView = ini.GetBoolValue("Ipad", "Enabled"); //For Writing Bool
	//Setting::IpadViewValue = ini.GetDoubleValue("Ipadvv", "Value"); //For Writing Values

	//force 
	Setting::ForceTPP = ini.GetBoolValue("Force", "Enabled"); //For Writing Bool

	/// INSTANT
	Setting::fastrun = ini.GetBoolValue("FastRun", "Enabled");
	Setting::fastrv = ini.GetDoubleValue("FastRunv", "Value");
	Setting::fastrunkey = ini.GetLongValue("FastRunvk", "Value");

	//WeaponSwitch
	Setting::FastWeponSwith = ini.GetBoolValue("WeaponSwitch", "Enabled"); //For Writing Bool


	///XEffect
	Setting::XEffect = ini.GetBoolValue("XEffect", "Enabled"); //For Writing Bool
	Setting::XEffectRandomHead = ini.GetDoubleValue("XeffectColorhd", "Value"); //For Writing Values
	Setting::XEffectRandomBody = ini.GetDoubleValue("XeffectColorBody", "Value"); //For Writing Values

	//Scopev
	Setting::ScopeZoom = ini.GetBoolValue("Scope", "Enabled"); //For Writing Bool
	Setting::scopefov = ini.GetDoubleValue("Scopev", "Value"); //For Writing Values

	///Fast Car
	Setting::speedcar = ini.GetBoolValue("FastCar", "Enabled"); //For Writing Bool
	Setting::carsv = ini.GetDoubleValue("FastCarv", "Value"); //For Writing Values
	Setting::FastCarKeys = ini.GetLongValue("Triggerv", "Value");

	/// TAB5
	Setting::Normalfontsize = ini.GetLongValue("TextSize", "Value");//Same for saving item text sizes Sizes
	Setting::fontsize = ini.GetLongValue("ImportantTextSize", "Value");//Same for saving item text sizes Sizes
	Setting::UpdateThreadDelay = ini.GetLongValue("UpdateThreadDelay", "Value");
	Setting::EspThreadDelay = ini.GetLongValue("EspThreadDelay", "Value");
	Setting::AdreessGetterDelay = ini.GetLongValue("AdreessGetterDelay", "Value");
	Setting::overlaycolor = ini.GetLongValue("Value", "overlaycolor");

	Setting::gameinfo = ini.GetBoolValue("gameinfo", "gameinfo");
	Setting::Snowflake = ini.GetBoolValue("Snowflake", "Snowflake");
	Setting::OverlayTransparency = ini.GetBoolValue("OverlayTransparency", "OverlayTransparency");


}