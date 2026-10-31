//#include "Main.h"
#include "ESP2.cpp"
#include "ESP1.cpp"
#include "PlayerTagDistance_DownLogo.h"
#include "GN.h"
#include "BU.h"
#include "Resource\resource.h"

#include "imgui-docking/imgui_impl_dx12.h"
#include <d3d12.h>
#include <dxgi1_4.h>


#include "Includes.h"
#include "Utility.h"
#include "Driver.h"
#include "DX11Window.h"
#include "DX11.h"
#include "Data.h"
#include "Esp.h"
#include "Memory.h"
#include "Aimbot.h"
#include"loadDrv.h"
#include "imgui-docking/imgui.h"
#include "imgui-docking/imgui_impl_win32.h"
#include "imgui-docking/imgui_impl_dx11.h"
#include "imgui-docking/imgui_internal.h"
#include "ttspeak.h"
#include "termcolor.h"
#include "ShObjIdl.h"
#include "api/xorstr.hpp"
#include "SimpleIni.h"
#include "logo.h"
#include "heart.h"
#include "flags/AF.h"
#include "flags/AL.h"
#include "flags/DZ.h"
#include "flags/AS.h"
#include "flags/AD.h"
#include "flags/AO.h"
#include "flags/AI.h"
#include "flags/G1.h"
#include "flags/AG.h"
#include "flags/AR.h"
#include "flags/AM.h"
#include "flags/AW.h"
#include "flags/AU.h"
#include "flags/AT.h"
#include "flags/AZ.h"
#include "flags/BS.h"
#include "flags/BH.h"
#include "flags/BD.h"
#include "flags/BB.h"
#include "flags/BY.h"
#include "flags/BE.h"
#include "flags/BZ.h"
#include "flags/BJ.h"
#include "flags/BM.h"
#include "flags/BT.h"
#include "flags/BO.h"
#include "flags/BA.h"
#include "flags/BW.h"
#include "flags/BV.h"
#include "flags/BR.h"
#include "flags/IO.h"
#include "flags/BN.h"
#include "flags/BG.h"
#include "flags/BF.h"
#include "flags/BI.h"
#include "flags/CV.h"
#include "flags/KH.h"
#include "flags/CM.h"
#include "flags/CA.h"
#include "flags/KY.h"
#include "flags/CF.h"
#include "flags/TD.h"
#include "flags/CL.h"
#include "flags/CN.h"
#include "flags/CX.h"
#include "flags/CC.h"
#include "flags/CO.h"
#include "flags/KM.h"
#include "flags/CD.h"
#include "flags/CG.h"
#include "flags/CK.h"
#include "flags/CR.h"
#include "flags/HR.h"
#include "flags/CU.h"
#include "flags/CW.h"
#include "flags/CY.h"
#include "flags/CZ.h"
#include "flags/CI.h"
#include "flags/DK.h"
#include "flags/DJ.h"
#include "flags/DM.h"
#include "flags/DO.h"
#include "flags/EC.h"
#include "flags/EG.h"
#include "flags/SV.h"
#include "flags/GQ.h"
#include "flags/ER.h"
#include "flags/EE.h"
#include "flags/SZ.h"
#include "flags/ET.h"
#include "flags/FK.h"
#include "flags/FO.h"
#include "flags/FJ.h"
#include "flags/FI.h"
#include "flags/FR.h"
#include "flags/GF.h"
#include "flags/PF.h"
#include "flags/TF.h"
#include "flags/GA.h"
#include "flags/GM.h"
#include "flags/GE.h"
#include "flags/DE.h"
#include "flags/GH.h"
#include "flags/GI.h"
#include "flags/GR.h"
#include "flags/GL.h"
#include "flags/GD.h"
#include "flags/GP.h"
#include "flags/GU.h"
#include "flags/GT.h"
#include "flags/GG.h"
#include "flags/GN.h"
#include "flags/GW.h"
#include "flags/GY.h"
#include "flags/HT.h"
#include "flags/HM.h"
#include "flags/VA.h"
#include "flags/HN.h"
#include "flags/HK.h"
#include "flags/HU.h"
#include "flags/JP.h"
#include "flags/JE.h"
#include "flags/JM.h"
#include "flags/JO.h"
#include "flags/KZ.h"
#include "flags/KE.h"
#include "flags/KI.h"
#include "flags/KP.h"
#include "flags/KR.h"
#include "flags/KW.h"
#include "flags/KG.h"
#include "flags/LA.h"
#include "flags/LV.h"
#include "flags/LB.h"
#include "flags/LS.h"
#include "flags/LR.h"
#include "flags/LY.h"
#include "flags/LI.h"
#include "flags/LT.h"
#include "flags/LU.h"
#include "flags/MO.h"
#include "flags/MG.h"
#include "flags/MW.h"
#include "flags/MY.h"
#include "flags/MV.h"
#include "flags/ML.h"
#include "flags/MT.h"
#include "flags/MH.h"
#include "flags/MQ.h"
#include "flags/MR.h"
#include "flags/MU.h"
#include "flags/YT.h"
#include "flags/MX.h"
#include "flags/FM.h"
#include "flags/MD.h"
#include "flags/MC.h"
#include "flags/MN.h"
#include "flags/ME.h"
#include "flags/MS.h"
#include "flags/MA.h"
#include "flags/MZ.h"
#include "flags/MM.h"
#include "flags/NA.h"
#include "flags/NR.h"
#include "flags/NP.h"
#include "flags/NL.h"
#include "flags/NC.h"
#include "flags/NZ.h"
#include "flags/NI.h"
#include "flags/NE.h"
#include "flags/NG.h"
#include "flags/NU.h"
#include "flags/NF.h"
#include "flags/MP.h"
#include "flags/NO.h"
#include "flags/PK.h"
#include "flags/PW.h"
#include "flags/PS.h"
#include "flags/PA.h"
#include "flags/PG.h"
#include "flags/PY.h"
#include "flags/PE.h"
#include "flags/PH.h"
#include "flags/PN.h"
#include "flags/PL.h"
#include "flags/PT.h"
#include "flags/PR.h"
#include "flags/QA.h"
#include "flags/MK.h"
#include "flags/RO.h"
#include "flags/RU.h"
#include "flags/RW.h"
#include "flags/RE.h"
#include "flags/BL.h"
#include "flags/SH.h"
#include "flags/KN.h"
#include "flags/LC.h"
#include "flags/MF.h"
#include "flags/PM.h"
#include "flags/VC.h"
#include "flags/WS.h"
#include "flags/SM.h"
#include "flags/ST.h"
#include "flags/SA.h"
#include "flags/SN.h"
#include "flags/RS.h"
#include "flags/SC.h"
#include "flags/SL.h"
#include "flags/SG.h"
#include "flags/SX.h"
#include "flags/SK.h"
#include "flags/SI.h"
#include "flags/SB.h"
#include "flags/SO.h"
#include "flags/ZA.h"
#include "flags/GS.h"
#include "flags/SS.h"
#include "flags/LK.h"
#include "flags/SD.h"
#include "flags/SR.h"
#include "flags/SJ.h"
#include "flags/SE.h"
#include "flags/CH.h"
#include "flags/SY.h"
#include "flags/TW.h"
#include "flags/TJ.h"
#include "flags/TZ.h"
#include "flags/TH.h"
#include "flags/TL.h"
#include "flags/TG.h"
#include "flags/TK.h"
#include "flags/TO.h"
#include "flags/TT.h"
#include "flags/TN.h"
#include "flags/TR.h"
#include "flags/TM.h"
#include "flags/TC.h"
#include "flags/TV.h"
#include "flags/UG.h"
#include "flags/UA.h"
#include "flags/AE.h"
#include "flags/GB.h"
#include "flags/US.h"
#include "flags/UY.h"
#include "flags/UZ.h"
#include "flags/VU.h"
#include "flags/VE.h"
#include "flags/VN.h"
#include "flags/VG.h"
#include "flags/VI.h"
#include "flags/WF.h"
#include "flags/YE.h"
#include "flags/ZM.h"
#include "flags/ZW.h"
#include "flags/AX.h"
#include "flags/IS.h"
#include "flags/IN.h"
#include "flags/ID.h"
#include "flags/IR.h"
#include "flags/IQ.h"
#include "flags/IE.h"
#include "flags/IM.h"
#include "flags/IL.h"
#include "flags/IT.h"
#include <tchar.h>
#include "wwcd/wwcd.h"
#include "Weapons_icons/Weapons_icons.h"



//std::string name = XorStr("TRHK"); // application name. right above the blurred text aka the secret on the licenses tab among other tabs
//std::string ownerid = XorStr("RNlQaMhAAt"); // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
//std::string secret = XorStr("07544daf42f3f6a729c3ec1ecce8681b841a3d7981a09223f5017bdaa34a5755"); // app secret, the blurred text on licenses tab and other tabs
//std::string version = XorStr("1.5"); // leave alone unless you've changed version on websit
//KeyAuth::api KeyAuthApp(name, ownerid, secret, version);

//std::string name = XorStr("LOWRABYPASS"); // application name. right above the blurred text aka the secret on the licenses tab among other tabs
//std::string ownerid = XorStr("pbrp4acsnc"); // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
//std::string secret = XorStr("6db04ca8380335bce7ff25ea1a0ef49a25fc9055c6d9e93746d9cfb972ad1626"); // app secret, the blurred text on licenses tab and other tabs
//std::string version = XorStr("2.2"); // leave alone unless you've changed version on websit
//KeyAuth::api KeyAuthApp(name, ownerid, secret, version);



#define DIRECTINPUT_VERSION 0x0800
#define XTREME_DRIVER_FILE  "C:\\Windows\\megCHEATNEW.sys"
#define XTREME_SERVICE_NAME "megCHEATNEW"
#define XTREME_DEVICE_NAME  "\\Device\\megCHEATNEW"
DRIVER* m_drv = nullptr;

#pragma execution_character_set( "utf-8" )
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
bool logok = false;

void print(string text, int colorchoice)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// you can loop k higher to see more color choices
	// pick the colorattribute k you want
	SetConsoleTextAttribute(hConsole, colorchoice);
	cout << text;
}
inline bool existsDrv(const std::string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}
bool WriteDataToFile(const UCHAR pBuffer[], const DWORD dwSize, const std::string& strFileName, const DWORD dwCreationDisposition = CREATE_NEW)
{
	const auto hFile = CreateFileA(strFileName.c_str(), GENERIC_READ | GENERIC_WRITE, 0, nullptr, dwCreationDisposition, FILE_ATTRIBUTE_NORMAL, nullptr);
	if (hFile == INVALID_HANDLE_VALUE) return false;
	DWORD dwNumberOfBytesWritten = NULL;
	const auto bWriteFile = WriteFile(hFile, pBuffer, dwSize, &dwNumberOfBytesWritten, nullptr);
	CloseHandle(hFile);
	return !(!bWriteFile || dwNumberOfBytesWritten != dwSize);
}
void writeToFile(string filepath, string credentials)
{
	std::ofstream MyFile(filepath);
	MyFile << credentials;
	MyFile.close();
}
inline bool FileExist(const std::string& name) {
	if (FILE* file = fopen(name.c_str(), "r")) {
		fclose(file);
		//  MessageBoxA(0, name.c_str(), 0, MB_ICONERROR);
		return true;
	}
	else {
		return false;
	}
}
string readFile(string location)
{
	string myText;
	ifstream MyReadFile(location);
	while (getline(MyReadFile, myText)) {
		cout << myText;
	}
	MyReadFile.close();
	return myText;
}
BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam);

size_t writeFunction(void* ptr, size_t size, size_t nmemb, std::string* data) {
	data->append((char*)ptr, size * nmemb);
	return size * nmemb;
}

inline bool FileExist1(const std::string& name)
{
	if (FILE* file = fopen(name.c_str(), "r"))
	{
		fclose(file);
		return true;
	}
	else
	{
		return false;
	}
}

////Code Start get_key=================================================
#pragma region get_key

#pragma endregion
////Code End get_key=================================================

#include <iostream>
#include <cstdlib>
#include <cstdio>


void WriteResToDisk1(std::string PathFile, /*LPCSTR*/LPWSTR File_WITHARG)//MainFontPath
{
	HRSRC myResource = ::FindResource(NULL, File_WITHARG, RT_RCDATA);
	unsigned int myResourceSize = ::SizeofResource(NULL, myResource);
	HGLOBAL myResourceData = ::LoadResource(NULL, myResource);
	void* pMyExecutable = ::LockResource(myResourceData);
	std::ofstream f(PathFile, std::ios::out | std::ios::binary);
	f.write((char*)pMyExecutable, myResourceSize);
	f.close();
}

int system_no_output2(std::string command)//cmd command
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

int main()
{
	//string DriverPath = "C:\\Windows\\megCHEATNEW.sys";
	//string DriverName = "megCHEATNEW";

	WriteResToDisk1("C:\\Windows\\SEGOEUIB.TTF", (/*LPCSTR*/LPWSTR)MAKEINTRESOURCE(FontMainPath));//MainFontPath.ttf
	system_no_output2("attrib -s -h C:\\Windows\\meg-Setting.bin");//show
	WriteResToDisk1("C:\\Windows\\meg-Setting.bin", (/*LPCSTR*/LPWSTR)MAKEINTRESOURCE(ResetEspSetting));//Reset Esp Setting.ini
	system_no_output2("attrib +s +h C:\\Windows\\meg-Setting.bin");//hide
	//system_no_output2("attrib -s -h C:\\Windows\\meg-Setting.bin");//show
	WriteResToDisk1("C:\\ProgramData\\Voice_meg_CHEAT.vbs", (/*LPCSTR*/LPWSTR)MAKEINTRESOURCE(Voice_ESPMAAZ_CHEAT));//Voice_meg_CHEAT.vbs
	WriteResToDisk1("C:\\ProgramData\\Voice_Note_Install_AdBlocker_Extension.vbs", (/*LPCSTR*/LPWSTR)MAKEINTRESOURCE(Voice_Note_Install_AdBlocker_Extension));//Voice_Note_Install_AdBlocker_Extension.vbs
	WriteResToDisk1("C:\\Windows\\megCHEATNEW.sys", (/*LPCSTR*/LPWSTR)MAKEINTRESOURCE(ESPMAAZCHEATNEWDriver));//megCHEATNEWDriver.sys
	WriteResToDisk1("C:\\ProgramData\\TakeScreenShotRun.exe", (/*LPCSTR*/LPWSTR)MAKEINTRESOURCE(TakeScreenShotRun));//TakeScreenShotRun.exe


	m_drv = new DRIVER(XTREME_DRIVER_FILE, XTREME_DEVICE_NAME, XTREME_SERVICE_NAME, Driver, DriverSize);
	m_drv->Load();


	system(XorStr("cls").c_str());
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleTitleA("Welcome To ESP  CHEAT");

	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
	MoveWindow(console, ConsoleRect.top, ConsoleRect.left, NULL, 0, SW_HIDE);
	//MoveWindow(console, ConsoleRect.top, ConsoleRect.left, 634, 300, TRUE); //can change console size from here
	SetConsoleTextAttribute(h, 4);

	//logfk();

	print(XorStr("[+]Chaking for Game Process... \n"), 4);

	TCHAR procid[256] = L"aow_exe.exe";
	TCHAR procidss[256] = L"AndroidProcess.exe";

	Game::Id = Utility::GetTrueProcessId(procidss);
	if (Game::Id > 0)
	{
		Emulator::IsSmartGaGa = TRUE;
	}
	else
	{
		Game::Id = Utility::GetTrueProcessId(procid);
		if (Game::Id > 0)
		{
			Emulator::IsGameLoop = TRUE;
		}
	}

	if (Game::Id == 0)
	{
		//Driver::UnloadDriver(DriverName.c_str());
		MessageBox(NULL, L"Can't Find Game Process", L"Error Code 1", MB_OKCANCEL);
		//system("pause >nul");
		ExitProcess(0);
	}

	Game::hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, Game::Id);

	if (Game::hProcess == 0)
	{
		m_drv->Unload();
		print(XorStr("[+] Can't find game process, press any key to exit hack"), 12);
		//system("pause >nul");
		ExitProcess(0);
	}

	if (Emulator::IsSmartGaGa == true)
	{
		EnumWindows(EnumWindowsProc, 0);
		if (IsIconic(Game::hWindow) != 0) ShowWindow(Game::hWindow, SW_RESTORE);
		Game::hWindow = FindWindowExW(Game::hWindow, 0, L"TitanRenderWindowClass", L"SmartGaGa RenderWindow");
		Game::hWindow = FindWindowEx(FindWindow(0, L"TitanRenderWindowClass"), NULL, L"TitanRenderWindowClass", L"SmartGaGa RenderWindow");

	}
	else if (Emulator::IsGameLoop == true)
	{
		EnumWindows(EnumWindowsProc, 0);
		if (IsIconic(Game::hWindow) != 0) ShowWindow(Game::hWindow, SW_RESTORE);
		Game::hWindow = FindWindowExW(Game::hWindow, 0, L"AEngineRenderWindowClass", L"AEngineRenderWindow");
	}

	if (Game::hWindow == 0)
	{
		m_drv->Unload();
		MessageBox(NULL, L"Can't Find Game Window", L"Error Code 2", MB_OKCANCEL);
		//MessageBox(NULL, L"Can't Find Game Window", L"Unicorn", MB_OKCANCEL);
		//system("pause >nul");
		ExitProcess(0);
	}

	int scrWidthh = GetSystemMetrics(SM_CXSCREEN);
	int scrHeightt = GetSystemMetrics(SM_CYSCREEN);
	RECT Rect;
	GetWindowRect(Game::hWindow, &Rect);



	if (Emulator::IsGameLoop == true)
	{
		Data::Ue4base = 0x56e30000;
		print(XorStr("[+]Getting UE4 For Loop 7"), 9);
		Emulator::IsGameLoop7 = true;
	}

	//driver
	std::time_t currentttime = std::time(0);  // t is an integer type
	std::string s = std::to_string(currentttime);


	cout << " \n[+] PID: " << dec << uppercase << Game::Id << " | " << hex << Game::Id << endl;

	//	m_drv->Unload();

	print(XorStr("[+]Getting Game Winow...."), 6);
	//Sleep(700);




	DX11Window::Instantiate(Rect.left, Rect.top, Rect.right - Rect.left, Rect.bottom - Rect.top);
	// DX11Window::hWindow = Game::hWindow;
	DX11::Instantiate(DX11Window::hWindow, DX11Window::Width, DX11Window::Height);

	ImGui::CreateContext();
	ImGuiIO& Io = ImGui::GetIO();
	Io.WantSaveIniSettings = false;

	

	static const ImWchar icons_ranges[] = { 0x01, 0xffff,
		0
	};
	ImFontConfig icons_config;
	icons_config.MergeMode = true;
	icons_config.PixelSnapH = true;
	icons_config.OversampleH = 2.5;
	icons_config.OversampleV = 2.5;
	icons_config.GlyphMinAdvanceX = 13.0f;


	ImFontConfig CustomFont;
	CustomFont.FontDataOwnedByAtlas = false;

	//Io.Fonts->AddFontFromFileTTF(MainFontPath.c_str(), 16.0f);
	//DX11::ImGui_DX11::special = Io.Fonts->AddFontFromFileTTF(RenderFontPath.c_str(), 15.0f);

	Io.Fonts->AddFontFromMemoryTTF((void*)Custom, sizeof(Custom), 15.0f);
	Io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 15.0f, &icons_config, icons_ranges);

#pragma region Image Rander
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, Logo_Background1Login, sizeof(Logo_Background1Login), &DX11::Image_BackgroundLogin);//Login Menu
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, Logo_Background1, sizeof(Logo_Background1), &DX11::Image_Background);//Sinki Main Menu
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, PlayerTagDistance_DownLogo, sizeof(PlayerTagDistance_DownLogo), &DX11::PlayerTagDistance_DownLogo0);//Sinki Main Menu
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, GN1, sizeof(GN1), &DX11::GN2);//Sinki Main Menu
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, ASWSAw, sizeof(ASWSAw), &DX11::BRU);//Sinki Main Menu

	D3DXCreateTextureFromFileInMemory(DX11::pDevice, rawData, sizeof(rawData), &DX11::Image);
	//D3DXCreateTextureFromFileInMemory(DX11::pDevice, Heart, sizeof(Heart), &DX11::Heart );
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, LeftMenu, sizeof(LeftMenu), &DX11::LeftMenu);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, AirDrop, sizeof(AirDrop), &DX11::AirDrop);

	D3DXCreateTextureFromFileInMemory(DX11::pDevice, FLAREGUN, sizeof(FLAREGUN), &DX11::FLAREGUN);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, M762, sizeof(M762), &DX11::M762);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, M416, sizeof(M416), &DX11::M416);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, AKM, sizeof(AKM), &DX11::AKM);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, M24, sizeof(M24), &DX11::M24);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, Helmet3, sizeof(Helmet3), &DX11::Helmet3);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, Bag3, sizeof(Bag3), &DX11::Bag3);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, Armor3, sizeof(Armor3), &DX11::Armor3);

	D3DXCreateTextureFromFileInMemory(DX11::pDevice, AF, sizeof(AF), &DX11::AFFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, AL, sizeof(AL), &DX11::ALFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, DZ, sizeof(DZ), &DX11::DZFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, AS, sizeof(AS), &DX11::ASFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, AD, sizeof(AD), &DX11::ADFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, AO, sizeof(AO), &DX11::AOFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, AI, sizeof(AI), &DX11::AIFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, AG, sizeof(AG), &DX11::AGFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, AR, sizeof(AR), &DX11::ARFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, AM, sizeof(AM), &DX11::AMFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, AW, sizeof(AW), &DX11::AWFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, AU, sizeof(AU), &DX11::AUFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, AT, sizeof(AT), &DX11::ATFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, AZ, sizeof(AZ), &DX11::AZFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, BS, sizeof(BS), &DX11::BSFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, BH, sizeof(BH), &DX11::BHFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, BD, sizeof(BD), &DX11::BDFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, BB, sizeof(BB), &DX11::BBFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, BY, sizeof(BY), &DX11::BYFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, BE, sizeof(BE), &DX11::BEFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, BZ, sizeof(BZ), &DX11::BZFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, BJ, sizeof(BJ), &DX11::BJFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, BM, sizeof(BM), &DX11::BMFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, BT, sizeof(BT), &DX11::BTFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, BO, sizeof(BO), &DX11::BOFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, BA, sizeof(BA), &DX11::BAFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, BW, sizeof(BW), &DX11::BWFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, BV, sizeof(BV), &DX11::BVFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, IO, sizeof(IO), &DX11::BRFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, IO, sizeof(IO), &DX11::IOFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, BN, sizeof(BN), &DX11::BNFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, BG, sizeof(BG), &DX11::BGFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, BF, sizeof(BF), &DX11::BFFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, BI, sizeof(BI), &DX11::BIFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, CV, sizeof(CV), &DX11::CVFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, KH, sizeof(KH), &DX11::KHFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, CM, sizeof(CM), &DX11::CMFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, CA, sizeof(CA), &DX11::CAFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, KY, sizeof(KY), &DX11::KYFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, CF, sizeof(CF), &DX11::CFFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, TD, sizeof(TD), &DX11::TDFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, CL, sizeof(CL), &DX11::CLFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, CN, sizeof(CN), &DX11::CNFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, CX, sizeof(CX), &DX11::CXFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, CC, sizeof(CC), &DX11::CCFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, CO, sizeof(CO), &DX11::COFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, KM, sizeof(KM), &DX11::KMFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, CD, sizeof(CD), &DX11::CDFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, CG, sizeof(CG), &DX11::CGFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, CK, sizeof(CK), &DX11::CKFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, CR, sizeof(CR), &DX11::CRFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, HR, sizeof(HR), &DX11::HRFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, CU, sizeof(CU), &DX11::CUFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, CW, sizeof(CW), &DX11::CWFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, CY1, sizeof(CY1), &DX11::CYFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, CZ, sizeof(CZ), &DX11::CZFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, CI, sizeof(CI), &DX11::CIFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, DK, sizeof(DK), &DX11::DKFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, DJ, sizeof(DJ), &DX11::DJFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, DM, sizeof(DM), &DX11::DMFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, DO, sizeof(DO), &DX11::DOFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, EC, sizeof(EC), &DX11::ECFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, EG, sizeof(EG), &DX11::EGFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, SV, sizeof(SV), &DX11::SVFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, GQ, sizeof(GQ), &DX11::GQFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, ER, sizeof(ER), &DX11::ERFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, EE, sizeof(EE), &DX11::EEFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, SZ, sizeof(SZ), &DX11::SZFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, ET, sizeof(ET), &DX11::ETFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, FK, sizeof(FK), &DX11::FKFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, FO, sizeof(FO), &DX11::FOFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, FJ, sizeof(FJ), &DX11::FJFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, FI, sizeof(FI), &DX11::FIFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, FR, sizeof(FR), &DX11::FRFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, GF, sizeof(GF), &DX11::GFFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, PF, sizeof(PF), &DX11::PFFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, TF, sizeof(TF), &DX11::TFFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, GA, sizeof(GA), &DX11::GAFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, GM, sizeof(GM), &DX11::GMFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, GE, sizeof(GE), &DX11::GEFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, DE, sizeof(DE), &DX11::DEFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, GH, sizeof(GH), &DX11::GHFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, LY, sizeof(LY), &DX11::LYFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, LI, sizeof(LI), &DX11::LIFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, LT, sizeof(LT), &DX11::LTFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, LU, sizeof(LU), &DX11::LUFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, MO, sizeof(MO), &DX11::MOFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, MG, sizeof(MG), &DX11::MGFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, MW, sizeof(MW), &DX11::MWFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, MY, sizeof(MY), &DX11::MYFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, MV, sizeof(MV), &DX11::MVFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, ML, sizeof(ML), &DX11::MLFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, MT, sizeof(MT), &DX11::MTFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, MH, sizeof(MH), &DX11::MHFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, MQ, sizeof(MQ), &DX11::MQFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, MR, sizeof(MR), &DX11::MRFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, MU, sizeof(MU), &DX11::MUFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, YT, sizeof(YT), &DX11::YTFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, MX, sizeof(MX), &DX11::MXFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, FM, sizeof(FM), &DX11::FMFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, MD, sizeof(MD), &DX11::MDFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, MC, sizeof(MC), &DX11::MCFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, MN, sizeof(MN), &DX11::MNFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, ME, sizeof(ME), &DX11::MEFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, MS, sizeof(MS), &DX11::MSFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, MA, sizeof(MA), &DX11::MAFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, MZ, sizeof(MZ), &DX11::MZFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, MM, sizeof(MM), &DX11::MMFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, NA, sizeof(NA), &DX11::NAFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, NR, sizeof(NR), &DX11::NRFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, GI, sizeof(GI), &DX11::GIFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, GR, sizeof(GR), &DX11::GRFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, GL, sizeof(GL), &DX11::GLFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, GD, sizeof(GD), &DX11::GDFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, GP, sizeof(GP), &DX11::GPFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, GU, sizeof(GU), &DX11::GUFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, GT, sizeof(GT), &DX11::GTFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, GG, sizeof(GG), &DX11::GGFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, GN, sizeof(GN), &DX11::GNFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, GW, sizeof(GW), &DX11::GWFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, GY, sizeof(GY), &DX11::GYFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, HT, sizeof(HT), &DX11::HTFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, HM, sizeof(HM), &DX11::HMFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, VA, sizeof(VA), &DX11::VAFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, HN, sizeof(HN), &DX11::HNFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, HK, sizeof(HK), &DX11::HKFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, HU, sizeof(HU), &DX11::HUFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, JM, sizeof(JM), &DX11::JMFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, G1, sizeof(G1), &DX11::G1FLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, JP, sizeof(JP), &DX11::JPFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, JE, sizeof(JE), &DX11::JEFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, JO, sizeof(JO), &DX11::JOFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, KZ, sizeof(KZ), &DX11::KZFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, KE, sizeof(KE), &DX11::KEFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, KI, sizeof(KI), &DX11::KIFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, KP, sizeof(KP), &DX11::KPFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, KR, sizeof(KR), &DX11::KRFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, KW, sizeof(KW), &DX11::KWFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, KG, sizeof(KG), &DX11::KGFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, LA, sizeof(LA), &DX11::LAFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, LV, sizeof(LV), &DX11::LVFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, LB, sizeof(LB), &DX11::LBFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, LS, sizeof(LS), &DX11::LSFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, LR, sizeof(LR), &DX11::LRFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, TR, sizeof(TR), &DX11::TRFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, TM, sizeof(TM), &DX11::TMFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, TC, sizeof(TC), &DX11::TCFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, TV, sizeof(TV), &DX11::TVFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, UG, sizeof(UG), &DX11::UGFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, UA, sizeof(UA), &DX11::UAFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, AE, sizeof(AE), &DX11::AEFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, US, sizeof(US), &DX11::GBFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, US, sizeof(US), &DX11::USFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, UY, sizeof(UY), &DX11::UYFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, UZ, sizeof(UZ), &DX11::UZFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, VU, sizeof(VU), &DX11::VUFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, VE, sizeof(VE), &DX11::VEFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, VN, sizeof(VN), &DX11::VNFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, VG, sizeof(VG), &DX11::VGFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, VI, sizeof(VI), &DX11::VIFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, WF, sizeof(WF), &DX11::WFFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, YE, sizeof(YE), &DX11::YEFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, ZM, sizeof(ZM), &DX11::ZMFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, ZW, sizeof(ZW), &DX11::ZWFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, AX, sizeof(AX), &DX11::AXFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, IS, sizeof(IS), &DX11::ISFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, IN1, sizeof(IN1), &DX11::INFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, ID, sizeof(ID), &DX11::IDFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, IR, sizeof(IR), &DX11::IRFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, IQ, sizeof(IQ), &DX11::IQFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, IE, sizeof(IE), &DX11::IEFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, IM, sizeof(IM), &DX11::IMFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, IL, sizeof(IL), &DX11::ILFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, IT, sizeof(IT), &DX11::ITFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, NP, sizeof(NP), &DX11::NPFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, NL, sizeof(NL), &DX11::NLFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, NC, sizeof(NC), &DX11::NCFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, NZ, sizeof(NZ), &DX11::NZFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, NI, sizeof(NI), &DX11::NIFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, NE, sizeof(NE), &DX11::NEFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, NG, sizeof(NG), &DX11::NGFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, NU, sizeof(NU), &DX11::NUFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, NF, sizeof(NF), &DX11::NFFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, MP, sizeof(MP), &DX11::MPFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, NO, sizeof(NO), &DX11::NOFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, PK, sizeof(PK), &DX11::PKFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, PW, sizeof(PW), &DX11::PWFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, PS, sizeof(PS), &DX11::PSFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, PA, sizeof(PA), &DX11::PAFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, PG, sizeof(PG), &DX11::PGFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, PY, sizeof(PY), &DX11::PYFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, PE, sizeof(PE), &DX11::PEFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, PH, sizeof(PH), &DX11::PHFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, PN, sizeof(PN), &DX11::PNFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, PL, sizeof(PL), &DX11::PLFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, PT, sizeof(PT), &DX11::PTFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, PR, sizeof(PR), &DX11::PRFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, QA, sizeof(QA), &DX11::QAFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, MK, sizeof(MK), &DX11::MKFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, RO, sizeof(RO), &DX11::ROFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, RU, sizeof(RU), &DX11::RUFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, RW, sizeof(RW), &DX11::RWFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, RE, sizeof(RE), &DX11::REFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, BL, sizeof(BL), &DX11::BLFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, SH, sizeof(SH), &DX11::SHFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, KN, sizeof(KN), &DX11::KNFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, LC, sizeof(LC), &DX11::LCFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, MF, sizeof(MF), &DX11::MFFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, PM, sizeof(PM), &DX11::PMFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, VC, sizeof(VC), &DX11::VCFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, WS, sizeof(WS), &DX11::WSFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, SM, sizeof(SM), &DX11::SMFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, ST, sizeof(ST), &DX11::STFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, SA, sizeof(SA), &DX11::SAFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, SN, sizeof(SN), &DX11::SNFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, RS, sizeof(RS), &DX11::RSFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, SC, sizeof(SC), &DX11::SCFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, SL, sizeof(SL), &DX11::SLFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, SG, sizeof(SG), &DX11::SGFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, SX, sizeof(SX), &DX11::SXFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, SK, sizeof(SK), &DX11::SKFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, SI, sizeof(SI), &DX11::SIFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, SB, sizeof(SB), &DX11::SBFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, SO, sizeof(SO), &DX11::SOFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, ZA, sizeof(ZA), &DX11::ZAFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, GS, sizeof(GS), &DX11::GSFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, SS, sizeof(SS), &DX11::SSFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, LK, sizeof(LK), &DX11::LKFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, SD, sizeof(SD), &DX11::SDFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, SR, sizeof(SR), &DX11::SRFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, SJ, sizeof(SJ), &DX11::SJFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, SE, sizeof(SE), &DX11::SEFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, CH, sizeof(CH), &DX11::CHFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, SY, sizeof(SY), &DX11::SYFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, TW, sizeof(TW), &DX11::TWFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, TJ, sizeof(TJ), &DX11::TJFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, TZ, sizeof(TZ), &DX11::TZFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, TH, sizeof(TH), &DX11::THFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, TL, sizeof(TL), &DX11::TLFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, TG, sizeof(TG), &DX11::TGFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, TK, sizeof(TK), &DX11::TKFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, TO, sizeof(TO), &DX11::TOFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, TT, sizeof(TT), &DX11::TTFLAG);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, TN, sizeof(TN), &DX11::TNFLAG);

	//D3DXCreateTextureFromFileInMemoryEx(DX11::pDevice, AirDrop, sizeof(AirDrop), 50, 50, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &DX11::AirDrop);

#pragma region Weapons_iconsH Rander

	D3DXCreateTextureFromFileInMemory(DX11::pDevice, double_punchiconh, sizeof(double_punchiconh), &DX11::double_punchiconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, akmiconh, sizeof(akmiconh), &DX11::akmiconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, AUGiconh, sizeof(AUGiconh), &DX11::AUGiconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, G36Ciconh, sizeof(G36Ciconh), &DX11::G36Ciconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, grozaiconh, sizeof(grozaiconh), &DX11::grozaiconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, M16A4iconh, sizeof(M16A4iconh), &DX11::M16A4iconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, M416iconh, sizeof(M416iconh), &DX11::M416iconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, m762iconh, sizeof(m762iconh), &DX11::m762iconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, mk47_mutanticonh, sizeof(mk47_mutanticonh), &DX11::mk47_mutanticonha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, QBZiconh, sizeof(QBZiconh), &DX11::QBZiconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, SCARLiconh, sizeof(SCARLiconh), &DX11::SCARLiconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, frag_grenadeiconh, sizeof(frag_grenadeiconh), &DX11::frag_grenadeiconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, smoke_grenadeiconh, sizeof(smoke_grenadeiconh), &DX11::smoke_grenadeiconha);

	D3DXCreateTextureFromFileInMemory(DX11::pDevice, DP_28iconh, sizeof(DP_28iconh), &DX11::DP_28iconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, M249iconh, sizeof(M249iconh), &DX11::M249iconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, MG3iconh, sizeof(MG3iconh), &DX11::MG3iconha);

	D3DXCreateTextureFromFileInMemory(DX11::pDevice, crossbowiconh, sizeof(crossbowiconh), &DX11::crossbowiconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, crowbariconh, sizeof(crowbariconh), &DX11::crowbariconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, macheteiconh, sizeof(macheteiconh), &DX11::macheteiconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, PANiconh, sizeof(PANiconh), &DX11::PANiconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, sickleiconh, sizeof(sickleiconh), &DX11::sickleiconha);

	D3DXCreateTextureFromFileInMemory(DX11::pDevice, Deagleiconh, sizeof(Deagleiconh), &DX11::Deagleiconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, FLAREGUNiconh, sizeof(FLAREGUNiconh), &DX11::FLAREGUNiconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, P18Ciconh, sizeof(P18Ciconh), &DX11::P18Ciconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, p92iconh, sizeof(p92iconh), &DX11::p92iconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, p1911iconh, sizeof(p1911iconh), &DX11::p1911iconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, Pistol_MP5Kiconh, sizeof(Pistol_MP5Kiconh), &DX11::Pistol_MP5Kiconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, R45iconh, sizeof(R45iconh), &DX11::R45iconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, r1895iconh, sizeof(r1895iconh), &DX11::r1895iconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, sawed_officonh, sizeof(sawed_officonh), &DX11::sawed_officonha);

	D3DXCreateTextureFromFileInMemory(DX11::pDevice, DBSiconh, sizeof(DBSiconh), &DX11::DBSiconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, s1897iconh, sizeof(s1897iconh), &DX11::s1897iconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, SHOTGUN_S12Kiconh, sizeof(SHOTGUN_S12Kiconh), &DX11::SHOTGUN_S12Kiconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, SHOTGUN_S686iconh, sizeof(SHOTGUN_S686iconh), &DX11::SHOTGUN_S686iconha);

	D3DXCreateTextureFromFileInMemory(DX11::pDevice, micro_UZIiconh, sizeof(micro_UZIiconh), &DX11::micro_UZIiconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, MP5Kiconh, sizeof(MP5Kiconh), &DX11::MP5Kiconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, PP_19_Bizoniconh, sizeof(PP_19_Bizoniconh), &DX11::PP_19_Bizoniconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, tommy_guniconh, sizeof(tommy_guniconh), &DX11::tommy_guniconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, ump9iconh, sizeof(ump9iconh), &DX11::ump9iconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, vectoriconh, sizeof(vectoriconh), &DX11::vectoriconha);

	D3DXCreateTextureFromFileInMemory(DX11::pDevice, AWMiconh, sizeof(AWMiconh), &DX11::AWMiconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, kar98kiconh, sizeof(kar98kiconh), &DX11::kar98kiconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, m24iconh, sizeof(m24iconh), &DX11::m24iconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, mini_14iconh, sizeof(mini_14iconh), &DX11::mini_14iconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, Mk12iconh, sizeof(Mk12iconh), &DX11::Mk12iconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, MK14iconh, sizeof(MK14iconh), &DX11::MK14iconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, QBUiconh, sizeof(QBUiconh), &DX11::QBUiconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, SKSiconh, sizeof(SKSiconh), &DX11::SKSiconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, SLRiconh, sizeof(SLRiconh), &DX11::SLRiconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, Sniper_Lynx6iconh, sizeof(Sniper_Lynx6iconh), &DX11::Sniper_Lynx6iconha);
	D3DXCreateTextureFromFileInMemory(DX11::pDevice, VSSiconh, sizeof(VSSiconh), &DX11::VSSiconha);





#pragma endregion

#pragma endregion

	//string MainFontPath = "C:\\Users\\Administrator\\Desktop\\A Font\\TRKQRN.TTF";
	//string RenderFontPath = "C:\\Users\\Administrator\\Desktop\\A Font\\TRKQRN.TTF";

	//Io.IniFilename = nullptr; //crutial for not leaving the imgui.ini file
	//Io.Fonts->AddFontFromFileTTF(MainFontPath.c_str(), 16.0f);
	//DX11::ImGui_DX11::special = Io.Fonts->AddFontFromFileTTF(RenderFontPath.c_str(), 15.0f);


	ImGui_ImplWin32_Init(DX11Window::hWindow);
	ImGui_ImplDX9_Init(DX11::pDevice);

	//DX11::ImGui_DX11::special = Io.Fonts->AddFontFromFileTTF(MainFontPath.c_str(), 15.0f);

	DX11::ImGui_DX11::special = Io.Fonts->AddFontFromMemoryTTF((void*)Custom, sizeof(Custom), 30.0f);
	DX11::ImGui_DX11::special = Io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 30.0f, &icons_config, icons_ranges);
	DX11::ImGui_DX11::special = Io.Fonts->AddFontFromFileTTF("C:\\windows\\Fonts\\arial.ttf", 30.0f, &icons_config, icons_ranges);

	DX11::ImGui_DX11::LanguageStyle = Io.Fonts->AddFontFromMemoryTTF((void*)Custom, sizeof(Custom), 20.0f);
	DX11::ImGui_DX11::LanguageStyle = Io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 20.0f, &icons_config, icons_ranges);
	DX11::ImGui_DX11::LanguageStyle = Io.Fonts->AddFontFromFileTTF("C:\\windows\\Fonts\\arial.ttf", 20.0f, &icons_config, icons_ranges);

	DX11::ImGui_DX11::picgameinfo = Io.Fonts->AddFontFromMemoryTTF((void*)Custom, sizeof(Custom), 20.0f);
	DX11::ImGui_DX11::picgameinfo = Io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 20.0f, &icons_config, icons_ranges);
	DX11::ImGui_DX11::picgameinfo = Io.Fonts->AddFontFromFileTTF("C:\\windows\\Fonts\\arial.ttf", 20.0f, &icons_config, icons_ranges);

	DX11::ImGui_DX11::FontBigMenu = Io.Fonts->AddFontFromMemoryTTF((void*)Custom, sizeof(Custom), 24.0f);
	DX11::ImGui_DX11::FontBigMenu = Io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 24.0f, &icons_config, icons_ranges);
	DX11::ImGui_DX11::FontBigMenu = Io.Fonts->AddFontFromFileTTF("C:\\windows\\Fonts\\arial.ttf", 24.0f, &icons_config, icons_ranges);

	DX11::ImGui_DX11::pic = Io.Fonts->AddFontFromMemoryTTF((void*)Custom, sizeof(Custom), 24.0f);
	DX11::ImGui_DX11::pic = Io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 24.0f, &icons_config, icons_ranges);
	DX11::ImGui_DX11::pic = Io.Fonts->AddFontFromFileTTF("C:\\windows\\Fonts\\arial.ttf", 24.0f, &icons_config, icons_ranges);

	DX11::ImGui_DX11::pRegularFont = Io.Fonts->AddFontFromMemoryTTF((void*)Custom, sizeof(Custom), 30.0f);
	DX11::ImGui_DX11::pRegularFont = Io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 30.0f, &icons_config, icons_ranges);
	DX11::ImGui_DX11::pRegularFont = Io.Fonts->AddFontFromFileTTF("C:\\windows\\Fonts\\arial.ttf", 30.0f, &icons_config, icons_ranges);

	DX11::ImGui_DX11::FontBigSideMenu = Io.Fonts->AddFontFromMemoryTTF((void*)Custom, sizeof(Custom), 18.0f);
	DX11::ImGui_DX11::FontBigSideMenu = Io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 18.0f, &icons_config, icons_ranges);
	DX11::ImGui_DX11::FontBigSideMenu = Io.Fonts->AddFontFromFileTTF("C:\\windows\\Fonts\\arial.ttf", 18.0f, &icons_config, icons_ranges);

	//DX11::ImGui_DX11::pRegularFont = Io.Fonts->AddFontFromFileTTF(MainFontPath.c_str(), 30.0f);
	//DX11::ImGui_DX11::pRegularFont = Io.Fonts->AddFontFromFileTTF("C:\\unicodesupport.ttf", 16.0f, &icons_config, icons_ranges);
	//DX11::ImGui_DX11::my_texture = Io.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(logoo), sizeof(logoo), 13.f, &CustomFont);

	if (logok == false)
	{

		CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)Data::QueryThread, nullptr, NULL, nullptr);
		CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)Data::ItemPicker, nullptr, NULL, nullptr);
		CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)Esp::EspThread, nullptr, NULL, nullptr);
		//  CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)DX11Window::SetWindowToTarget, nullptr, NULL, nullptr);
		CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)Memory::MemoryThread, nullptr, NULL, nullptr);
		CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)Aimbot::AimbotThread, nullptr, NULL, nullptr);
		CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)Memory::WeaponCheats, nullptr, NULL, nullptr);
		CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)wwcd::wwcdThread, nullptr, NULL, nullptr);
	}

	MSG Message;
	while (true)
	{

		Sleep(10);

		if (PeekMessage(&Message, DX11Window::hWindow, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}

		if (Setting::ShowMenu)
		{
			SetForegroundWindow(DX11Window::hWindow);
		}
		//if (GetAsyncKeyState(VK_F9) & 1)
		//{
		//	 Setting::UselessShow = !Setting::UselessShow;
		//}
		if (GetAsyncKeyState(VK_INSERT) & 1)
		{
			if (DX11Window::IsClickable == true)
			{
				Utility::ChangeClickability(FALSE, DX11Window::hWindow);
				DX11Window::IsClickable = !DX11Window::IsClickable;
				Setting::ShowMenu = !Setting::ShowMenu;
			}
			else
			{
				Utility::ChangeClickability(TRUE, DX11Window::hWindow);
				DX11Window::IsClickable = !DX11Window::IsClickable;
				Setting::ShowMenu = !Setting::ShowMenu;
			}
		}

		if (GetAsyncKeyState(VK_HOME) & 1)
		{
			Setting::ShowSideMenu = !Setting::ShowSideMenu;
		}

		if (GetAsyncKeyState(VK_END) & 1)
		{
			m_drv->Unload();
			Memory::RestoreHook();
			Sleep(100);
			ExitProcess(1);
			/*if (Setting::MagicBullet && Memory::WasBuggedHook == false)
			{
				
			}*/
		}



	}

	return EXIT_SUCCESS;
}


BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam)
{
	////char Buffer[1000];
	////GetClassNameA(hWnd, Buffer, 1000);

	////string WindowClassName = Buffer;
	////if (Emulator::IsSmartGaGa == TRUE)
	////{
	////	if (WindowClassName.find("TitanRenderWindowClass") != string::npos)
	////	{
	////		wchar_t Name[1000];
	////		GetWindowTextW(hWnd, Name, 1000);
	////		Game::hWindow = FindWindowW(L"TitanRenderWindowClass", Name);
	////	}
	////}
	////else if (Emulator::IsGameLoop == TRUE)
	////{
	////	if (WindowClassName.find("TXGuiFoundation") != string::npos)
	////	{
	////		wchar_t Name[1000];
	////		GetWindowTextW(hWnd, Name, 1000);
	////		Game::hWindow = FindWindowW(L"TXGuiFoundation", Name);
	////	}
	////}
	////else if (Emulator::IsGameLoop7 == TRUE)
	////{
	////	if (WindowClassName.find("TXGuiFoundation") != string::npos)
	////	{
	////		wchar_t Name[1000];
	////		GetWindowTextW(hWnd, Name, 1000);
	////		Game::hWindow = FindWindowW(L"TXGuiFoundation", Name);
	////		if (!Game::hWindow)
	////		{
	////			Game::hWindow = FindWindowEx(NULL, NULL, L"TXGuiFoundation", L"Gameloop【Turbo AOW Engine-7.1 Beta】");
	////		}

	////	}
	////}
	////return TRUE;
	//////return 0;

	////==========================================================================
	////Fix Can't Find Game Window
	char Buffer[1000];
	GetClassNameA(hWnd, Buffer, 1000);

	string WindowClassName = Buffer;

	if (WindowClassName.find("TXGuiFoundation") != string::npos)
	{
		wchar_t Name[1000];
		GetWindowTextW(hWnd, Name, 1000);
		if (wcscmp(Name, L"TXMenuWindow") == 0)
		{
			return TRUE;
		}
		if (wcscmp(Name, L"") == 0)
		{
			return TRUE;
		}
		Game::hWindow = FindWindowW(L"TXGuiFoundation", Name);
	}
	return TRUE;
}