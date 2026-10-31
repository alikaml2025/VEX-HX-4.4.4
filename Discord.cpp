#include "Discord.h"
#include <time.h>
#include <chrono>
#include "Data.h"

//Discord* g_Discord;

static int64_t eptime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();

void Discord::Initialize()
{
	if (Setting::StatusDiscord == true)
	{
		DiscordEventHandlers Handle;
		memset(&Handle, 0, sizeof(Handle));
		Discord_Initialize("1246332149825671209", &Handle, 1, NULL);
	}
	else
	{
		DiscordEventHandlers Handle;
		memset(&Handle, 0, sizeof(Handle));
		Discord_Initialize("1246332149825671209", &Handle, 1, NULL);
	}
}

void Discord::Update()
{
	if (Setting::StatusDiscord == true)
	{
		DiscordRichPresence discordPresence;
		memset(&discordPresence, 0, sizeof(discordPresence));
		//AActor AActor;
		if (Data::NetDriver > 0)
		{
			

			//std::string Kills = "Map :  " + (Data::LocalPawn)+ " (" + (Data::GameType)+") "" - " + "Alive : " + (to_string(Data::AlivePlayerNum));
			std::string Kills = "Map :  " + (Data::LocalPawn)+ " (" + (Data::GameType)+") "/*" - " + "Alive : " + (to_string(Data::AlivePlayerNum))*/;
			discordPresence.details = Kills.c_str();

			std::string Enr = "Weap : " + (Data::Weapon)+" - " + "Kills : " + (to_string(Data::MyPlayerTotalKills) + " - " + "Alive : " + (to_string(Data::AlivePlayerNum)));
			discordPresence.state = Enr.c_str();
		}
		else
		{
			discordPresence.details = "WAITING IN LOBBY";
			//std::string Kill = " " + (Data::LocalPawn)+" . Kills : Null - Alive : Null";
			//discordPresence.state = Kill.c_str();
		}

		discordPresence.largeImageText = "Developed By meg";
		//discordPresence.largeImageKey = "https://share.creavite.co/X2j8vXs8pY4eO1rC.gif";
		//discordPresence.largeImageKey = "https://share.creavite.co/665ab3a3b5b565ba12593e56.gif";
		discordPresence.largeImageKey = "https://media.giphy.com/media/caBdQiFSieOqvOohav/giphy.gif";
		//discordPresence.largeImageKey = "https://i.imgur.com/MqXBb6K.gif";

		discordPresence.smallImageText = "Verified";
		discordPresence.smallImageKey = "https://c.tenor.com/TgKK6YKNkm0AAAAi/verified-verificado.gif";


		discordPresence.button1Label = "JOIN DISCORD";
		//discordPresence.button1Label = "Join Telegram";
		discordPresence.button1Url = "https://discord.gg/RYdUVZefCb";
		//discordPresence.button1Url = "https://t.me/+zQqIukZIc684NWJl";

		//discordPresence.button2Label = "Join Telegram";
		discordPresence.button2Label = "DOWNLOAD ESP  FREE HACK";
		discordPresence.button2Url = "https://drive.google.com/drive/folders/1NRo8cZn8-ZP69pSMdWrMlq8MZHvTkGXc?usp=sharing";
		/*discordPresence.button2Label = "JOIN DISCORD";
		discordPresence.button2Url = "https://discord.gg/PCkXvqpsxD";*/

		discordPresence.startTimestamp = eptime;
		Discord_UpdatePresence(&discordPresence);
	}
	else
	{
		DiscordRichPresence discordPresence;
		memset(&discordPresence, 0, sizeof(discordPresence));

		Discord_UpdatePresence(&discordPresence);
	}
}

void Discord::Update1()
{
	if (Setting::StatusDiscord == true)
	{
		DiscordRichPresence discordPresence;
		memset(&discordPresence, 0, sizeof(discordPresence));

		discordPresence.details = "IN LOGIN PAGE";

		discordPresence.largeImageText = "Developed By meg";
		//discordPresence.largeImageKey = "https://share.creavite.co/X2j8vXs8pY4eO1rC.gif";
		//discordPresence.largeImageKey = "https://share.creavite.co/665ab3a3b5b565ba12593e56.gif";
		discordPresence.largeImageKey = "https://media.giphy.com/media/caBdQiFSieOqvOohav/giphy.gif";
		//discordPresence.largeImageKey = "https://i.imgur.com/MqXBb6K.gif";

		discordPresence.smallImageText = "Verified";
		discordPresence.smallImageKey = "https://c.tenor.com/TgKK6YKNkm0AAAAi/verified-verificado.gif";


		discordPresence.button1Label = "JOIN DISCORD";
		//discordPresence.button1Label = "Join Telegram";
		discordPresence.button1Url = "https://discord.gg/RYdUVZefCb";
		//discordPresence.button1Url = "https://t.me/+zQqIukZIc684NWJl";

		//discordPresence.button2Label = "Join Telegram";
		discordPresence.button2Label = "DOWNLOAD ESP  CHEAT FREE";
		discordPresence.button2Url = "https://drive.google.com/drive/folders/1NRo8cZn8-ZP69pSMdWrMlq8MZHvTkGXc?usp=sharing";


		/*discordPresence.button2Label = "JOIN DISCORD";
		discordPresence.button2Url = "https://discord.gg/PCkXvqpsxD";*/

		discordPresence.startTimestamp = eptime;
		Discord_UpdatePresence(&discordPresence);
	}
	else
	{
		DiscordRichPresence discordPresence;
		memset(&discordPresence, 0, sizeof(discordPresence));

		Discord_UpdatePresence(&discordPresence);
	}
}