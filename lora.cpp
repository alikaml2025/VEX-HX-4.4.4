#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#pragma warning(disable : 4996)
#include "api/xorstr.hpp"
#include "SimpleIni.h"
#include <D3DX11tex.h>
#define LOADER_BRAND "Loader base"
#include "Esp.h"
#include <iostream>
#include <fstream>
#include "imguipp.h"
#include "ESPMAAZPVTHAX.h"
#include "utf.h"
#include "Main.h"
#include "Discord.h"
//#include "wwcd/wwcd.h"

#include "imgui_notify/imgui_notify_Start.h"
#include "GetKeyAndOnlineLogin_imgui.h"
#include "MenuUI.h"
#include "Save_Load_Esp_Configurate.h"

//
#include "Snowflake.hpp"
#define TITLE "Snowflake.cpp"
#define WINDOW_WIDTH  1680
#define WINDOW_HEIGHT 1050
#define SNOW_LIMIT 300        ///check
std::vector<Snowflake::Snowflake> snow;

Discord* g_Discord;
bool fight = true;
//char key[60] = "";
std::string str = "ESPMAAZPVTHAX";
//bool login = false;
//bool SaveUsers = true;
//bool savekey = true;
bool loader_active = true;
D3DMATRIX Esp::ViewMatrix;
static bool Bot = true;
static bool Player = true;
std::string tim;
//char str1[60] = "";
float overlaycolor = 0.0f;
int teamid;
int teamids;
int TotalPlayers_RadioButton = 1;
int LootBoxItems_RadioButton = 2;
int TextItem_RadioButton = 1;
int ImageItem_RadioButton = 1;
float redzone = 40.0f;



bool watermark = true;
int currIndex;
float popcorn = 0.5f;
float popcorn2 = 0.450f;
ImVec4 colorr;
int Emu_Int = 0;
int item_current_Emu = 0;
int currentengine = 0;
int item_current_Aim = 0;
int skelesec = 0;
//  (DX11::pDevice, &logo, sizeof(logo), 462, 462, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &logggo);

///Settings
int nsize = 14;

static int aimbp = 0;
int dissize = 14;
int hp = 14;
int vehisize = 15;
bool marco1 = false;
bool nothingm = true;
bool nothinga = false;

bool styleM1 = false;
bool styleM2 = false;
bool styleM3 = false;
bool styleM4 = true;

ImVec4 bonescolors1;// = { 1.0f,1.0f,1.0f,1.0f };
ImVec4 RadarColorBoot = { ImColor(255, 255, 255, 150) };
ImVec4 RadarColorBoot100m = { ImColor(255, 255, 255, 250) };
ImVec4 linescolorsB = { ImColor(255, 255, 255, 250) };
ImVec4 linescolorsP;// = { 1.0f,1.0f,1.0f,1.0f };
ImVec4 linescolors;// = { 1.0f,1.0f,1.0f,1.0f };
ImVec4 bonescolors = { 1.0f,1.0f,1.0f,1.0f };
ImVec4 fullboxcolor;// = { 1.0f,1.0f,1.0f,1.0f };
ImVec4 cornerboxcolor;// = { 1.0f,1.0f,1.0f,1.0f };
ImVec4 whitecolr = { 1.0f,1.0f,1.0f,1.0f };

ImVec4 blinescolors;
ImVec4 bbonescolors;
ImVec4 bfullboxcolor;
ImVec4 bcornerboxcolor;
bool driving = true;
ImColor col;
static auto FlagsForHUD = ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar;
static auto Flags2 = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
static auto Flags21 = ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar;
static auto Flags22 = ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;





std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

std::string GetCurrentDirectory()
{
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	return std::string(buffer).substr(0, pos);
}

std::string ws2s(const std::wstring& wstr)
{
	using convert_typeX = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_typeX, wchar_t> converterX;

	return converterX.to_bytes(wstr);
}

bool dirExists(const std::string& dirName_in)
{
	DWORD ftyp = GetFileAttributesA(dirName_in.c_str());
	if (ftyp == INVALID_FILE_ATTRIBUTES)
		return false;  //something is wrong with your path!

	if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
		return true;   // this is a directory!

	return false;    // this is not a directory!
}

void WriteResToDisk(std::string PathFile, LPWSTR File_WITHARG)
{
	HRSRC myResource = ::FindResource(NULL, File_WITHARG, RT_RCDATA);
	unsigned int myResourceSize = ::SizeofResource(NULL, myResource);
	HGLOBAL myResourceData = ::LoadResource(NULL, myResource);
	void* pMyExecutable = ::LockResource(myResourceData);
	std::ofstream f(PathFile, std::ios::out | std::ios::binary);
	f.write((char*)pMyExecutable, myResourceSize);
	f.close();
}


std::string wideToMultiByte(std::wstring const& wideString)
{
	std::string ret;
	std::string buff(MB_CUR_MAX, '\0');

	for (wchar_t const& wc : wideString)
	{
		int mbCharLen = std::wctomb(&buff[0], wc);

		if (mbCharLen < 1) { break; }

		for (int i = 0; i < mbCharLen; ++i)
		{
			ret += buff[i];
		}
	}

	return ret;
}

bool ProcessInlineHexColor(const char* start, const char* end, ImVec4& color)
{
	const int hexCount = (int)(end - start);
	if (hexCount == 6 || hexCount == 8)
	{
		char hex[9];
		strncpy(hex, start, hexCount);
		hex[hexCount] = 0;

		unsigned int hexColor = 0;
		if (sscanf(hex, "%x", &hexColor) > 0)
		{
			color.x = static_cast<float>((hexColor & 0x00FF0000) >> 16) / 255.0f;
			color.y = static_cast<float>((hexColor & 0x0000FF00) >> 8) / 255.0f;
			color.z = static_cast<float>((hexColor & 0x000000FF)) / 255.0f;
			color.w = 1.0f;

			if (hexCount == 8)
			{
				color.w = static_cast<float>((hexColor & 0xFF000000) >> 24) / 255.0f;
			}

			return true;
		}
	}

	return false;
}

const char ColorMarkerStart = '{';
const char ColorMarkerEnd = '}';

void TextWithColors(const char* fmt, ...)
{
	char tempStr[4096];

	va_list argPtr;
	va_start(argPtr, fmt);
	_vsnprintf(tempStr, sizeof(tempStr), fmt, argPtr);
	va_end(argPtr);
	tempStr[sizeof(tempStr) - 1] = '\0';

	bool pushedColorStyle = false;
	const char* textStart = tempStr;
	const char* textCur = tempStr;
	while (textCur < (tempStr + sizeof(tempStr)) && *textCur != '\0')
	{
		if (*textCur == ColorMarkerStart)
		{
			// Print accumulated text
			if (textCur != textStart)
			{
				ImGui::TextUnformatted(textStart, textCur);
				ImGui::SameLine(0.0f, 0.0f);
			}

			// Process color code
			const char* colorStart = textCur + 1;
			do
			{
				++textCur;
			} while (*textCur != '\0' && *textCur != ColorMarkerEnd);

			// Change color
			if (pushedColorStyle)
			{
				ImGui::PopStyleColor();
				pushedColorStyle = false;
			}

			ImVec4 textColor;
			if (ProcessInlineHexColor(colorStart, textCur, textColor))
			{
				ImGui::PushStyleColor(ImGuiCol_Text, textColor);
				pushedColorStyle = true;
			}

			textStart = textCur + 1;
		}
		else if (*textCur == '\n')
		{
			// Print accumulated text an go to next line
			ImGui::TextUnformatted(textStart, textCur);
			textStart = textCur + 1;
		}

		++textCur;
	}

	if (textCur != textStart)
	{
		ImGui::TextUnformatted(textStart, textCur);
	}
	else
	{
		ImGui::NewLine();
	}

	if (pushedColorStyle)
	{
		ImGui::PopStyleColor();
	}
}

void NationFlag(VECTOR3 Screen, AActor& AActor, int PosX, int PosY, int X, int Y)
{
	if (AActor.IsBot)
	{
		if (Data::LocalPawn == "In Training")
		{
			DX11::ImGui_DX11::DrawImage(DX11::G1FLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
		}
	}
	if (AActor.Nation == "JM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::JMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "G1")
	{
		DX11::ImGui_DX11::DrawImage(DX11::G1FLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AF")
	{
		DX11::ImGui_DX11::DrawImage(DX11::AFFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AL")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ALFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "DZ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::DZFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AS")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ASFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AD")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ADFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AO")
	{
		DX11::ImGui_DX11::DrawImage(DX11::AOFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AI")
	{
		DX11::ImGui_DX11::DrawImage(DX11::AIFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AQ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::AQFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AG")
	{
		DX11::ImGui_DX11::DrawImage(DX11::AGFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AR")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ARFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::AMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AW")
	{
		DX11::ImGui_DX11::DrawImage(DX11::AWFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AU")
	{
		DX11::ImGui_DX11::DrawImage(DX11::AUFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AT")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ATFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AZ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::AZFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BS")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BSFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BH")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BHFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BD")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BDFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BB")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BBFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BY")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BYFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BE")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BEFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BZ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BZFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BJ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BJFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BT")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BTFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BO")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BOFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BQ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BQFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BA")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BAFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BW")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BWFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BV")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BVFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BR")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BRFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "IO")
	{
		DX11::ImGui_DX11::DrawImage(DX11::IOFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BN")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BNFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BG")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BGFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BF")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BFFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BI")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BIFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CV")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CVFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "KH")
	{
		DX11::ImGui_DX11::DrawImage(DX11::KHFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CA")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CAFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "KY")
	{
		DX11::ImGui_DX11::DrawImage(DX11::KYFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CF")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CFFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TD")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TDFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CL")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CLFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CN")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CNFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CX")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CXFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CC")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CCFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CO")
	{
		DX11::ImGui_DX11::DrawImage(DX11::COFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "KM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::KMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CD")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CDFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CG")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CGFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CK")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CKFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CR")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CRFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "HR")
	{
		DX11::ImGui_DX11::DrawImage(DX11::HRFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CU")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CUFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CW")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CWFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CY")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CYFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CZ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CZFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CI")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CIFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "DK")
	{
		DX11::ImGui_DX11::DrawImage(DX11::DKFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "DJ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::DJFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "DM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::DMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "DO")
	{
		DX11::ImGui_DX11::DrawImage(DX11::DOFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "EC")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ECFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "EG")
	{
		DX11::ImGui_DX11::DrawImage(DX11::EGFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SV")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SVFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GQ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GQFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "ER")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ERFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "EE")
	{
		DX11::ImGui_DX11::DrawImage(DX11::EEFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SZ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SZFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "ET")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ETFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "FK")
	{
		DX11::ImGui_DX11::DrawImage(DX11::FKFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "FO")
	{
		DX11::ImGui_DX11::DrawImage(DX11::FOFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "FJ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::FJFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "FI")
	{
		DX11::ImGui_DX11::DrawImage(DX11::FIFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "FR")
	{
		DX11::ImGui_DX11::DrawImage(DX11::FRFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GF")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GFFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "PF")
	{
		DX11::ImGui_DX11::DrawImage(DX11::PFFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TF")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TFFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GA")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GAFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GE")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GEFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "DE")
	{
		DX11::ImGui_DX11::DrawImage(DX11::DEFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GH")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GHFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GI")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GIFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GR")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GRFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GL")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GLFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GD")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GDFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GP")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GPFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GU")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GUFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GT")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GTFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GG")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GGFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GN")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GNFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GW")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GWFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GY")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GYFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "HT")
	{
		DX11::ImGui_DX11::DrawImage(DX11::HTFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "HM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::HMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "VA")
	{
		DX11::ImGui_DX11::DrawImage(DX11::VAFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "HN")
	{
		DX11::ImGui_DX11::DrawImage(DX11::HNFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "HK")
	{
		DX11::ImGui_DX11::DrawImage(DX11::HKFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "HU")
	{
		DX11::ImGui_DX11::DrawImage(DX11::HUFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "JP")
	{
		DX11::ImGui_DX11::DrawImage(DX11::JPFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "JE")
	{
		DX11::ImGui_DX11::DrawImage(DX11::JEFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "JO")
	{
		DX11::ImGui_DX11::DrawImage(DX11::JOFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "KZ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::KZFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "KE")
	{
		DX11::ImGui_DX11::DrawImage(DX11::KEFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "KI")
	{
		DX11::ImGui_DX11::DrawImage(DX11::KIFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "KP")
	{
		DX11::ImGui_DX11::DrawImage(DX11::KPFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "KR")
	{
		DX11::ImGui_DX11::DrawImage(DX11::KRFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "KW")
	{
		DX11::ImGui_DX11::DrawImage(DX11::KWFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "KG")
	{
		DX11::ImGui_DX11::DrawImage(DX11::KGFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "LA")
	{
		DX11::ImGui_DX11::DrawImage(DX11::LAFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "LV")
	{
		DX11::ImGui_DX11::DrawImage(DX11::LVFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "LB")
	{
		DX11::ImGui_DX11::DrawImage(DX11::LBFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "LS")
	{
		DX11::ImGui_DX11::DrawImage(DX11::LSFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "LR")
	{
		DX11::ImGui_DX11::DrawImage(DX11::LRFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "LY")
	{
		DX11::ImGui_DX11::DrawImage(DX11::LYFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "LI")
	{
		DX11::ImGui_DX11::DrawImage(DX11::LIFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "LT")
	{
		DX11::ImGui_DX11::DrawImage(DX11::LTFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "LU")
	{
		DX11::ImGui_DX11::DrawImage(DX11::LUFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MO")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MOFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MG")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MGFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MW")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MWFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MY")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MYFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MV")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MVFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "ML")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MLFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MT")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MTFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MH")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MHFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MQ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MQFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MR")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MRFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MU")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MUFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "YT")
	{
		DX11::ImGui_DX11::DrawImage(DX11::YTFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MX")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MXFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "FM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::FMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MD")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MDFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MC")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MCFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MN")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MNFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "ME")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MEFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MS")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MSFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MA")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MAFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MZ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MZFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "NA")
	{
		DX11::ImGui_DX11::DrawImage(DX11::NAFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "NR")
	{
		DX11::ImGui_DX11::DrawImage(DX11::NRFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "NP")
	{
		DX11::ImGui_DX11::DrawImage(DX11::NPFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "NL")
	{
		DX11::ImGui_DX11::DrawImage(DX11::NLFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "NC")
	{
		DX11::ImGui_DX11::DrawImage(DX11::NCFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "NZ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::NZFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "NI")
	{
		DX11::ImGui_DX11::DrawImage(DX11::NIFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "NE")
	{
		DX11::ImGui_DX11::DrawImage(DX11::NEFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "NG")
	{
		DX11::ImGui_DX11::DrawImage(DX11::NGFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "NU")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MUFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "NF")
	{
		DX11::ImGui_DX11::DrawImage(DX11::NFFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MP")
	{
		DX11::ImGui_DX11::DrawImage(DX11::NPFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "NO")
	{
		DX11::ImGui_DX11::DrawImage(DX11::NOFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "OM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::OMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "PK")
	{
		DX11::ImGui_DX11::DrawImage(DX11::PKFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "PW")
	{
		DX11::ImGui_DX11::DrawImage(DX11::PWFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "PS")
	{
		DX11::ImGui_DX11::DrawImage(DX11::PSFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "PA")
	{
		DX11::ImGui_DX11::DrawImage(DX11::PAFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "PG")
	{
		DX11::ImGui_DX11::DrawImage(DX11::PGFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "PY")
	{
		DX11::ImGui_DX11::DrawImage(DX11::PYFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "PE")
	{
		DX11::ImGui_DX11::DrawImage(DX11::PEFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "PH")
	{
		DX11::ImGui_DX11::DrawImage(DX11::PHFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "PN")
	{
		DX11::ImGui_DX11::DrawImage(DX11::PNFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "PL")
	{
		DX11::ImGui_DX11::DrawImage(DX11::PLFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "PT")
	{
		DX11::ImGui_DX11::DrawImage(DX11::PTFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "PR")
	{
		DX11::ImGui_DX11::DrawImage(DX11::PRFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "QA")
	{
		DX11::ImGui_DX11::DrawImage(DX11::QAFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MK")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MKFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "RO")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ROFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "RU")
	{
		DX11::ImGui_DX11::DrawImage(DX11::RUFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "RW")
	{
		DX11::ImGui_DX11::DrawImage(DX11::RWFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "RE")
	{
		DX11::ImGui_DX11::DrawImage(DX11::REFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BL")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BLFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SH")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SHFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "KN")
	{
		DX11::ImGui_DX11::DrawImage(DX11::KNFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "LC")
	{
		DX11::ImGui_DX11::DrawImage(DX11::LCFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MF")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MFFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "PM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::PMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "VC")
	{
		DX11::ImGui_DX11::DrawImage(DX11::VCFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "WS")
	{
		DX11::ImGui_DX11::DrawImage(DX11::WSFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "ST")
	{
		DX11::ImGui_DX11::DrawImage(DX11::STFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SA")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SAFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SN")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SNFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "RS")
	{
		DX11::ImGui_DX11::DrawImage(DX11::RSFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SC")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SCFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SL")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SLFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SG")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SGFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SX")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SXFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SK")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SKFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SI")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SIFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SB")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SBFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SO")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SOFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "ZA")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ZAFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GS")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GSFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SS")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SSFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "ES")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ESFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "LK")
	{
		DX11::ImGui_DX11::DrawImage(DX11::LKFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SD")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SDFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SR")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SRFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SJ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SJFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SE")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SEFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CH")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CHFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SY")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SYFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TW")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TWFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TJ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TJFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TZ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TZFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TH")
	{
		DX11::ImGui_DX11::DrawImage(DX11::THFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TL")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TLFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TG")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TGFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TK")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TKFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TO")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TOFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TT")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TTFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TN")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TNFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TR")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TRFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TC")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TCFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TV")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TVFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "UG")
	{
		DX11::ImGui_DX11::DrawImage(DX11::UGFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "UA")
	{
		DX11::ImGui_DX11::DrawImage(DX11::UAFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AE")
	{
		DX11::ImGui_DX11::DrawImage(DX11::AEFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GB")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GBFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "US")
	{
		DX11::ImGui_DX11::DrawImage(DX11::USFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "UY")
	{
		DX11::ImGui_DX11::DrawImage(DX11::UYFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "UZ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::UZFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "VU")
	{
		DX11::ImGui_DX11::DrawImage(DX11::VUFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "VE")
	{
		DX11::ImGui_DX11::DrawImage(DX11::VEFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "VN")
	{
		DX11::ImGui_DX11::DrawImage(DX11::VNFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "VG")
	{
		DX11::ImGui_DX11::DrawImage(DX11::VGFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "VI")
	{
		DX11::ImGui_DX11::DrawImage(DX11::VIFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "WF")
	{
		DX11::ImGui_DX11::DrawImage(DX11::WFFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "EH")
	{
		DX11::ImGui_DX11::DrawImage(DX11::EHFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "YE")
	{
		DX11::ImGui_DX11::DrawImage(DX11::YEFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "ZM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ZMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "ZW")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ZWFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AX")
	{
		DX11::ImGui_DX11::DrawImage(DX11::AXFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "IS")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ISFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "IN")
	{
		DX11::ImGui_DX11::DrawImage(DX11::INFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "ID")
	{
		DX11::ImGui_DX11::DrawImage(DX11::IDFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "IR")
	{
		DX11::ImGui_DX11::DrawImage(DX11::IRFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "IQ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::IQFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "IE")
	{
		DX11::ImGui_DX11::DrawImage(DX11::IEFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "IM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::IMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "IL")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ILFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "IT")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ITFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
}

void Weapons_iconsH_B(VECTOR3 Screen, AActor& AActor, int PosX, int PosY, int X, int Y)
{
	if (Setting1::botWeapons_iconsH)
	{
		if (Setting1::style1)
		{
			if (Setting1::botst1Weapons_iconsH)
			{

				if (AActor.Weapon == "AKM")
				{
					DX11::ImGui_DX11::DrawImage(DX11::akmiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "AUG")
				{
					DX11::ImGui_DX11::DrawImage(DX11::AUGiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "G36")
				{
					DX11::ImGui_DX11::DrawImage(DX11::G36Ciconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "Groza")
				{
					DX11::ImGui_DX11::DrawImage(DX11::grozaiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "M16A4")
				{
					DX11::ImGui_DX11::DrawImage(DX11::M16A4iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "M416")
				{
					DX11::ImGui_DX11::DrawImage(DX11::M416iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "M762")
				{
					DX11::ImGui_DX11::DrawImage(DX11::m762iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "Mk47")
				{
					DX11::ImGui_DX11::DrawImage(DX11::mk47_mutanticonha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "QBZ")
				{
					DX11::ImGui_DX11::DrawImage(DX11::QBZiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "SCAR")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SCARLiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}

				else if (AActor.Weapon == "Grenade")
				{
					DX11::ImGui_DX11::DrawImage(DX11::frag_grenadeiconha, Screen.X - 5, Screen.Y - 73, 30, 45);//ok
				}
				else if (AActor.Weapon == "Smoke")
				{
					DX11::ImGui_DX11::DrawImage(DX11::smoke_grenadeiconha, Screen.X - 5, Screen.Y - 73, 35, 40);//ok
				}

				else if (AActor.Weapon == "DP28")
				{
					DX11::ImGui_DX11::DrawImage(DX11::DP_28iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "M249")
				{
					DX11::ImGui_DX11::DrawImage(DX11::M249iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "MG3")
				{
					DX11::ImGui_DX11::DrawImage(DX11::MG3iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}

				else if (AActor.Weapon == "CrossBow")
				{
					DX11::ImGui_DX11::DrawImage(DX11::crossbowiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "Crowbar")
				{
					DX11::ImGui_DX11::DrawImage(DX11::crowbariconha, Screen.X - 35, Screen.Y - 73, 45, 25);
				}
				else if (AActor.Weapon == "Machete")
				{
					DX11::ImGui_DX11::DrawImage(DX11::macheteiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "Pan")
				{
					DX11::ImGui_DX11::DrawImage(DX11::PANiconha, Screen.X - 10, Screen.Y - 73, 45, 25);
				}
				else if (AActor.Weapon == "sickleiconha_")
				{
					DX11::ImGui_DX11::DrawImage(DX11::sickleiconha, Screen.X - 25, Screen.Y - 73, 45, 25);
				}

				else if (AActor.Weapon == "DesertEagle")
				{
					DX11::ImGui_DX11::DrawImage(DX11::Deagleiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "Flaregun")
				{
					DX11::ImGui_DX11::DrawImage(DX11::FLAREGUNiconha, Screen.X - 20, Screen.Y - 73, 45, 25);
				}
				else if (AActor.Weapon == "P18C")
				{
					DX11::ImGui_DX11::DrawImage(DX11::P18Ciconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "P92")
				{
					DX11::ImGui_DX11::DrawImage(DX11::p92iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "P1911")
				{
					DX11::ImGui_DX11::DrawImage(DX11::p1911iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "MP5K")
				{
					DX11::ImGui_DX11::DrawImage(DX11::Pistol_MP5Kiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "R45")
				{
					DX11::ImGui_DX11::DrawImage(DX11::R45iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "R1895")
				{
					DX11::ImGui_DX11::DrawImage(DX11::r1895iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "SawedOff")
				{
					DX11::ImGui_DX11::DrawImage(DX11::sawed_officonha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}

				else if (AActor.Weapon == "DP12")
				{
					DX11::ImGui_DX11::DrawImage(DX11::DBSiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "S1897")
				{
					DX11::ImGui_DX11::DrawImage(DX11::s1897iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "S12K")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SHOTGUN_S12Kiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "S686")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SHOTGUN_S686iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}

				else if (AActor.Weapon == "Uzi")
				{
					DX11::ImGui_DX11::DrawImage(DX11::micro_UZIiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "MP5K")
				{
					DX11::ImGui_DX11::DrawImage(DX11::MP5Kiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "PP19")
				{
					DX11::ImGui_DX11::DrawImage(DX11::PP_19_Bizoniconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "TommyGu")
				{
					DX11::ImGui_DX11::DrawImage(DX11::tommy_guniconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "UMP9")
				{
					DX11::ImGui_DX11::DrawImage(DX11::ump9iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "Vector")
				{
					DX11::ImGui_DX11::DrawImage(DX11::vectoriconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}

				else if (AActor.Weapon == "AWM")
				{
					DX11::ImGui_DX11::DrawImage(DX11::AWMiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "Kar98k")
				{
					DX11::ImGui_DX11::DrawImage(DX11::kar98kiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "M24")
				{
					DX11::ImGui_DX11::DrawImage(DX11::m24iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "Mini14")
				{
					DX11::ImGui_DX11::DrawImage(DX11::mini_14iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "MK12")
				{
					DX11::ImGui_DX11::DrawImage(DX11::Mk12iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "Mk14")
				{
					DX11::ImGui_DX11::DrawImage(DX11::MK14iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "QBU")
				{
					DX11::ImGui_DX11::DrawImage(DX11::QBUiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "SKS")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SKSiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "SLR")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SLRiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "Sniper_Lynx6iconha_")
				{
					DX11::ImGui_DX11::DrawImage(DX11::Sniper_Lynx6iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "VSS")
				{
					DX11::ImGui_DX11::DrawImage(DX11::VSSiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}

				else if (AActor.Weapon == "Fist")
				{
					DX11::ImGui_DX11::DrawImage(DX11::double_punchiconha, Screen.X - 15, Screen.Y - 73, 45, 20);

				}
				else if (AActor.Weapon == "Be Careful | Weapon Not Detect")
				{
					//DX11::ImGui_DX11::DrawImage(DX11::double_punchiconha, Screen.X - 15, Screen.Y - 53, 50, 20);
					//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::AR_Weaponsize, Text, Screen.X, Screen.Y, Setting::Esp_Item_AKMC, true);

					int dissize1 = 14;
					string wep = AActor.Weapon;

					if (Setting::playerweapon)
					{

						//	printf_s(temptext, xorstr_("%s (%d/%d)"), wep, AActor.Ammo, AActor.AmmoMax);

						/*string weapon; = wep AActor.Ammo, AActor.AmmoMax
							wep.append(" | ");
						wep.append(dista);*/

						/*wep.append(" | ");
						wep.append(to_string(AActor.Ammo) + ":");

						wep.append(to_string(AActor.AmmoMax));
						wep.append(AActor.ScopeFov);
						if (AActor.Ammo <= 200 && AActor.AmmoMax > 0)
						{
							DX11::ImGui_DX11::DrawBorderText(DX11::ImGui_DX11::pRegularFont, dissize1, wep, Screen.X + 5, (Screen.Y + Screen.Z) - 1, Colors::plyrweapon, true);
						}
						else
						{
							DX11::ImGui_DX11::DrawCharBorderText(DX11::ImGui_DX11::pRegularFont, dissize1, AActor.Weapon.c_str(), Screen.X + 5, (Screen.Y + Screen.Z) - 1, Colors::plyrweapon, true);
						}*/
					}
					//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, dissize1, wep, Screen.X + 5, (Screen.Y + Screen.Z) - 1, DX11::ImGui_DX11::Color::Red, true);

				}



			}

		}

		if (Setting1::style2)
		{
			if (Setting1::botst2Weapons_iconsH)
			{

				if (AActor.Weapon == "AKM")
				{
					DX11::ImGui_DX11::DrawImage(DX11::akmiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "AUG")
				{
					DX11::ImGui_DX11::DrawImage(DX11::AUGiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "G36")
				{
					DX11::ImGui_DX11::DrawImage(DX11::G36Ciconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Groza")
				{
					DX11::ImGui_DX11::DrawImage(DX11::grozaiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "M16A4")
				{
					DX11::ImGui_DX11::DrawImage(DX11::M16A4iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "M416")
				{
					DX11::ImGui_DX11::DrawImage(DX11::M416iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "M762")
				{
					DX11::ImGui_DX11::DrawImage(DX11::m762iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Mk47")
				{
					DX11::ImGui_DX11::DrawImage(DX11::mk47_mutanticonha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "QBZ")
				{
					DX11::ImGui_DX11::DrawImage(DX11::QBZiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "SCAR")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SCARLiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}

				else if (AActor.Weapon == "Grenade")
				{
					DX11::ImGui_DX11::DrawImage(DX11::frag_grenadeiconha, Screen.X - 5, Screen.Y - 67, 30, 45);//ok
				}
				else if (AActor.Weapon == "Smoke")
				{
					DX11::ImGui_DX11::DrawImage(DX11::smoke_grenadeiconha, Screen.X - 5, Screen.Y - 70, 35, 40);//ok
				}

				else if (AActor.Weapon == "DP28")
				{
					DX11::ImGui_DX11::DrawImage(DX11::DP_28iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "M249")
				{
					DX11::ImGui_DX11::DrawImage(DX11::M249iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "MG3")
				{
					DX11::ImGui_DX11::DrawImage(DX11::MG3iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}

				else if (AActor.Weapon == "CrossBow")
				{
					DX11::ImGui_DX11::DrawImage(DX11::crossbowiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Crowbar")
				{
					DX11::ImGui_DX11::DrawImage(DX11::crowbariconha, Screen.X - 35, Screen.Y - 57, 55, 25);
				}
				else if (AActor.Weapon == "Machete")
				{
					DX11::ImGui_DX11::DrawImage(DX11::macheteiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Pan")
				{
					DX11::ImGui_DX11::DrawImage(DX11::PANiconha, Screen.X - 10, Screen.Y - 55, 45, 25);
				}
				else if (AActor.Weapon == "sickleiconha_")
				{
					DX11::ImGui_DX11::DrawImage(DX11::sickleiconha, Screen.X - 25, Screen.Y - 55, 55, 25);
				}

				else if (AActor.Weapon == "DesertEagle")
				{
					DX11::ImGui_DX11::DrawImage(DX11::Deagleiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Flaregun")
				{
					DX11::ImGui_DX11::DrawImage(DX11::FLAREGUNiconha, Screen.X - 20, Screen.Y - 56, 40, 25);
				}
				else if (AActor.Weapon == "P18C")
				{
					DX11::ImGui_DX11::DrawImage(DX11::P18Ciconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "P92")
				{
					DX11::ImGui_DX11::DrawImage(DX11::p92iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "P1911")
				{
					DX11::ImGui_DX11::DrawImage(DX11::p1911iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "MP5K")
				{
					DX11::ImGui_DX11::DrawImage(DX11::Pistol_MP5Kiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "R45")
				{
					DX11::ImGui_DX11::DrawImage(DX11::R45iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "R1895")
				{
					DX11::ImGui_DX11::DrawImage(DX11::r1895iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "SawedOff")
				{
					DX11::ImGui_DX11::DrawImage(DX11::sawed_officonha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}

				else if (AActor.Weapon == "DP12")
				{
					DX11::ImGui_DX11::DrawImage(DX11::DBSiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "S1897")
				{
					DX11::ImGui_DX11::DrawImage(DX11::s1897iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "S12K")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SHOTGUN_S12Kiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "S686")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SHOTGUN_S686iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}

				else if (AActor.Weapon == "Uzi")
				{
					DX11::ImGui_DX11::DrawImage(DX11::micro_UZIiconha, Screen.X - 35, Screen.Y - 60, 45, 21);
				}
				else if (AActor.Weapon == "MP5K")
				{
					DX11::ImGui_DX11::DrawImage(DX11::MP5Kiconha, Screen.X - 35, Screen.Y - 60, 45, 21);
				}
				else if (AActor.Weapon == "PP19")
				{
					DX11::ImGui_DX11::DrawImage(DX11::PP_19_Bizoniconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "TommyGu")
				{
					DX11::ImGui_DX11::DrawImage(DX11::tommy_guniconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "UMP9")
				{
					DX11::ImGui_DX11::DrawImage(DX11::ump9iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Vector")
				{
					DX11::ImGui_DX11::DrawImage(DX11::vectoriconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}

				else if (AActor.Weapon == "AWM")
				{
					DX11::ImGui_DX11::DrawImage(DX11::AWMiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Kar98k")
				{
					DX11::ImGui_DX11::DrawImage(DX11::kar98kiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "M24")
				{
					DX11::ImGui_DX11::DrawImage(DX11::m24iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Mini14")
				{
					DX11::ImGui_DX11::DrawImage(DX11::mini_14iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "MK12")
				{
					DX11::ImGui_DX11::DrawImage(DX11::Mk12iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Mk14")
				{
					DX11::ImGui_DX11::DrawImage(DX11::MK14iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "QBU")
				{
					DX11::ImGui_DX11::DrawImage(DX11::QBUiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "SKS")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SKSiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "SLR")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SLRiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Sniper_Lynx6iconha_")
				{
					DX11::ImGui_DX11::DrawImage(DX11::Sniper_Lynx6iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "VSS")
				{
					DX11::ImGui_DX11::DrawImage(DX11::VSSiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}

				else if (AActor.Weapon == "Fist")
				{
					DX11::ImGui_DX11::DrawImage(DX11::double_punchiconha, Screen.X - 15, Screen.Y - 53, 45, 20);

				}
				else if (AActor.Weapon == "Be Careful | Weapon Not Detect")
				{
					//DX11::ImGui_DX11::DrawImage(DX11::double_punchiconha, Screen.X - 15, Screen.Y - 53, 50, 20);
					//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::AR_Weaponsize, Text, Screen.X, Screen.Y, Setting::Esp_Item_AKMC, true);

					int dissize1 = 14;
					string wep = AActor.Weapon;

					if (Setting::playerweapon)
					{

						//	printf_s(temptext, xorstr_("%s (%d/%d)"), wep, AActor.Ammo, AActor.AmmoMax);

						/*string weapon; = wep AActor.Ammo, AActor.AmmoMax
							wep.append(" | ");
						wep.append(dista);*/

						/*wep.append(" | ");
						wep.append(to_string(AActor.Ammo) + ":");

						wep.append(to_string(AActor.AmmoMax));
						wep.append(AActor.ScopeFov);
						if (AActor.Ammo <= 200 && AActor.AmmoMax > 0)
						{
							DX11::ImGui_DX11::DrawBorderText(DX11::ImGui_DX11::pRegularFont, dissize1, wep, Screen.X + 5, (Screen.Y + Screen.Z) - 1, Colors::plyrweapon, true);
						}
						else
						{
							DX11::ImGui_DX11::DrawCharBorderText(DX11::ImGui_DX11::pRegularFont, dissize1, AActor.Weapon.c_str(), Screen.X + 5, (Screen.Y + Screen.Z) - 1, Colors::plyrweapon, true);
						}*/
					}
					//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, dissize1, wep, Screen.X + 5, (Screen.Y + Screen.Z) - 1, DX11::ImGui_DX11::Color::Red, true);

				}



			}

		}

		if (Setting1::style3)
		{
			if (Setting1::botst3Weapons_iconsH)
			{

				if (AActor.Weapon == "AKM")
				{
					DX11::ImGui_DX11::DrawImage(DX11::akmiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "AUG")
				{
					DX11::ImGui_DX11::DrawImage(DX11::AUGiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "G36")
				{
					DX11::ImGui_DX11::DrawImage(DX11::G36Ciconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Groza")
				{
					DX11::ImGui_DX11::DrawImage(DX11::grozaiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "M16A4")
				{
					DX11::ImGui_DX11::DrawImage(DX11::M16A4iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "M416")
				{
					DX11::ImGui_DX11::DrawImage(DX11::M416iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "M762")
				{
					DX11::ImGui_DX11::DrawImage(DX11::m762iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Mk47")
				{
					DX11::ImGui_DX11::DrawImage(DX11::mk47_mutanticonha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "QBZ")
				{
					DX11::ImGui_DX11::DrawImage(DX11::QBZiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "SCAR")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SCARLiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}

				else if (AActor.Weapon == "Grenade")
				{
					DX11::ImGui_DX11::DrawImage(DX11::frag_grenadeiconha, Screen.X - 5, Screen.Y - 67, 30, 45);//ok
				}
				else if (AActor.Weapon == "Smoke")
				{
					DX11::ImGui_DX11::DrawImage(DX11::smoke_grenadeiconha, Screen.X - 5, Screen.Y - 70, 35, 40);//ok
				}

				else if (AActor.Weapon == "DP28")
				{
					DX11::ImGui_DX11::DrawImage(DX11::DP_28iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "M249")
				{
					DX11::ImGui_DX11::DrawImage(DX11::M249iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "MG3")
				{
					DX11::ImGui_DX11::DrawImage(DX11::MG3iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}

				else if (AActor.Weapon == "CrossBow")
				{
					DX11::ImGui_DX11::DrawImage(DX11::crossbowiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Crowbar")
				{
					DX11::ImGui_DX11::DrawImage(DX11::crowbariconha, Screen.X - 35, Screen.Y - 57, 55, 25);
				}
				else if (AActor.Weapon == "Machete")
				{
					DX11::ImGui_DX11::DrawImage(DX11::macheteiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Pan")
				{
					DX11::ImGui_DX11::DrawImage(DX11::PANiconha, Screen.X - 10, Screen.Y - 55, 45, 25);
				}
				else if (AActor.Weapon == "sickleiconha_")
				{
					DX11::ImGui_DX11::DrawImage(DX11::sickleiconha, Screen.X - 25, Screen.Y - 55, 55, 25);
				}

				else if (AActor.Weapon == "DesertEagle")
				{
					DX11::ImGui_DX11::DrawImage(DX11::Deagleiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Flaregun")
				{
					DX11::ImGui_DX11::DrawImage(DX11::FLAREGUNiconha, Screen.X - 20, Screen.Y - 56, 40, 25);
				}
				else if (AActor.Weapon == "P18C")
				{
					DX11::ImGui_DX11::DrawImage(DX11::P18Ciconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "P92")
				{
					DX11::ImGui_DX11::DrawImage(DX11::p92iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "P1911")
				{
					DX11::ImGui_DX11::DrawImage(DX11::p1911iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "MP5K")
				{
					DX11::ImGui_DX11::DrawImage(DX11::Pistol_MP5Kiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "R45")
				{
					DX11::ImGui_DX11::DrawImage(DX11::R45iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "R1895")
				{
					DX11::ImGui_DX11::DrawImage(DX11::r1895iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "SawedOff")
				{
					DX11::ImGui_DX11::DrawImage(DX11::sawed_officonha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}

				else if (AActor.Weapon == "DP12")
				{
					DX11::ImGui_DX11::DrawImage(DX11::DBSiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "S1897")
				{
					DX11::ImGui_DX11::DrawImage(DX11::s1897iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "S12K")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SHOTGUN_S12Kiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "S686")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SHOTGUN_S686iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}

				else if (AActor.Weapon == "Uzi")
				{
					DX11::ImGui_DX11::DrawImage(DX11::micro_UZIiconha, Screen.X - 35, Screen.Y - 60, 45, 21);
				}
				else if (AActor.Weapon == "MP5K")
				{
					DX11::ImGui_DX11::DrawImage(DX11::MP5Kiconha, Screen.X - 35, Screen.Y - 60, 45, 21);
				}
				else if (AActor.Weapon == "PP19")
				{
					DX11::ImGui_DX11::DrawImage(DX11::PP_19_Bizoniconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "TommyGu")
				{
					DX11::ImGui_DX11::DrawImage(DX11::tommy_guniconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "UMP9")
				{
					DX11::ImGui_DX11::DrawImage(DX11::ump9iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Vector")
				{
					DX11::ImGui_DX11::DrawImage(DX11::vectoriconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}

				else if (AActor.Weapon == "AWM")
				{
					DX11::ImGui_DX11::DrawImage(DX11::AWMiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Kar98k")
				{
					DX11::ImGui_DX11::DrawImage(DX11::kar98kiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "M24")
				{
					DX11::ImGui_DX11::DrawImage(DX11::m24iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Mini14")
				{
					DX11::ImGui_DX11::DrawImage(DX11::mini_14iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "MK12")
				{
					DX11::ImGui_DX11::DrawImage(DX11::Mk12iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Mk14")
				{
					DX11::ImGui_DX11::DrawImage(DX11::MK14iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "QBU")
				{
					DX11::ImGui_DX11::DrawImage(DX11::QBUiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "SKS")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SKSiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "SLR")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SLRiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Sniper_Lynx6iconha_")
				{
					DX11::ImGui_DX11::DrawImage(DX11::Sniper_Lynx6iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "VSS")
				{
					DX11::ImGui_DX11::DrawImage(DX11::VSSiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}

				else if (AActor.Weapon == "Fist")
				{
					DX11::ImGui_DX11::DrawImage(DX11::double_punchiconha, Screen.X - 15, Screen.Y - 53, 45, 20);

				}
				else if (AActor.Weapon == "Be Careful | Weapon Not Detect")
				{
					//DX11::ImGui_DX11::DrawImage(DX11::double_punchiconha, Screen.X - 15, Screen.Y - 53, 50, 20);
					//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::AR_Weaponsize, Text, Screen.X, Screen.Y, Setting::Esp_Item_AKMC, true);

					int dissize1 = 14;
					string wep = AActor.Weapon;

					if (Setting::playerweapon)
					{

						//	printf_s(temptext, xorstr_("%s (%d/%d)"), wep, AActor.Ammo, AActor.AmmoMax);

						/*string weapon; = wep AActor.Ammo, AActor.AmmoMax
							wep.append(" | ");
						wep.append(dista);*/

						/*wep.append(" | ");
						wep.append(to_string(AActor.Ammo) + ":");

						wep.append(to_string(AActor.AmmoMax));
						wep.append(AActor.ScopeFov);
						if (AActor.Ammo <= 200 && AActor.AmmoMax > 0)
						{
							DX11::ImGui_DX11::DrawBorderText(DX11::ImGui_DX11::pRegularFont, dissize1, wep, Screen.X + 5, (Screen.Y + Screen.Z) - 1, Colors::plyrweapon, true);
						}
						else
						{
							DX11::ImGui_DX11::DrawCharBorderText(DX11::ImGui_DX11::pRegularFont, dissize1, AActor.Weapon.c_str(), Screen.X + 5, (Screen.Y + Screen.Z) - 1, Colors::plyrweapon, true);
						}*/
					}
					//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, dissize1, wep, Screen.X + 5, (Screen.Y + Screen.Z) - 1, DX11::ImGui_DX11::Color::Red, true);

				}



			}

		}

	}
}

void Weapons_iconsH_P(VECTOR3 Screen, AActor& AActor, int PosX, int PosY, int X, int Y)
{

	if (Setting1::playerWeapons_iconsH)
	{
		if (Setting1::style1)
		{
			if (Setting1::playerst1Weapons_iconsH)
			{

				if (AActor.Weapon == "AKM")
				{
					DX11::ImGui_DX11::DrawImage(DX11::akmiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "AUG")
				{
					DX11::ImGui_DX11::DrawImage(DX11::AUGiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "G36")
				{
					DX11::ImGui_DX11::DrawImage(DX11::G36Ciconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "Groza")
				{
					DX11::ImGui_DX11::DrawImage(DX11::grozaiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "M16A4")
				{
					DX11::ImGui_DX11::DrawImage(DX11::M16A4iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "M416")
				{
					DX11::ImGui_DX11::DrawImage(DX11::M416iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "M762")
				{
					DX11::ImGui_DX11::DrawImage(DX11::m762iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "Mk47")
				{
					DX11::ImGui_DX11::DrawImage(DX11::mk47_mutanticonha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "QBZ")
				{
					DX11::ImGui_DX11::DrawImage(DX11::QBZiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "SCAR")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SCARLiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}

				else if (AActor.Weapon == "Grenade")
				{
					DX11::ImGui_DX11::DrawImage(DX11::frag_grenadeiconha, Screen.X - 35, Screen.Y - 73, 30, 45);//ok
				}
				else if (AActor.Weapon == "Smoke")
				{
					DX11::ImGui_DX11::DrawImage(DX11::smoke_grenadeiconha, Screen.X - 35, Screen.Y - 73, 0, 40);//ok
				}

				else if (AActor.Weapon == "DP28")
				{
					DX11::ImGui_DX11::DrawImage(DX11::DP_28iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "M249")
				{
					DX11::ImGui_DX11::DrawImage(DX11::M249iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "MG3")
				{
					DX11::ImGui_DX11::DrawImage(DX11::MG3iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}

				else if (AActor.Weapon == "CrossBow")
				{
					DX11::ImGui_DX11::DrawImage(DX11::crossbowiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "Crowbar")
				{
					DX11::ImGui_DX11::DrawImage(DX11::crowbariconha, Screen.X - 35, Screen.Y - 73, 55, 25);
				}
				else if (AActor.Weapon == "Machete")
				{
					DX11::ImGui_DX11::DrawImage(DX11::macheteiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "Pan")
				{
					DX11::ImGui_DX11::DrawImage(DX11::PANiconha, Screen.X - 35, Screen.Y - 73, 45, 25);
				}
				else if (AActor.Weapon == "sickleiconha_")
				{
					DX11::ImGui_DX11::DrawImage(DX11::sickleiconha, Screen.X - 35, Screen.Y - 73, 55, 25);
				}

				else if (AActor.Weapon == "DesertEagle")
				{
					DX11::ImGui_DX11::DrawImage(DX11::Deagleiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "Flaregun")
				{
					DX11::ImGui_DX11::DrawImage(DX11::FLAREGUNiconha, Screen.X - 35, Screen.Y - 73, 40, 25);
				}
				else if (AActor.Weapon == "P18C")
				{
					DX11::ImGui_DX11::DrawImage(DX11::P18Ciconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "P92")
				{
					DX11::ImGui_DX11::DrawImage(DX11::p92iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "P1911")
				{
					DX11::ImGui_DX11::DrawImage(DX11::p1911iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "MP5K")
				{
					DX11::ImGui_DX11::DrawImage(DX11::Pistol_MP5Kiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "R45")
				{
					DX11::ImGui_DX11::DrawImage(DX11::R45iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "R1895")
				{
					DX11::ImGui_DX11::DrawImage(DX11::r1895iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "SawedOff")
				{
					DX11::ImGui_DX11::DrawImage(DX11::sawed_officonha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}

				else if (AActor.Weapon == "DP12")
				{
					DX11::ImGui_DX11::DrawImage(DX11::DBSiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "S1897")
				{
					DX11::ImGui_DX11::DrawImage(DX11::s1897iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "S12K")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SHOTGUN_S12Kiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "S686")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SHOTGUN_S686iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}

				else if (AActor.Weapon == "Uzi")
				{
					DX11::ImGui_DX11::DrawImage(DX11::micro_UZIiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "MP5K")
				{
					DX11::ImGui_DX11::DrawImage(DX11::MP5Kiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "PP19")
				{
					DX11::ImGui_DX11::DrawImage(DX11::PP_19_Bizoniconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "TommyGu")
				{
					DX11::ImGui_DX11::DrawImage(DX11::tommy_guniconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "UMP9")
				{
					DX11::ImGui_DX11::DrawImage(DX11::ump9iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "Vector")
				{
					DX11::ImGui_DX11::DrawImage(DX11::vectoriconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}

				else if (AActor.Weapon == "AWM")
				{
					DX11::ImGui_DX11::DrawImage(DX11::AWMiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "Kar98k")
				{
					DX11::ImGui_DX11::DrawImage(DX11::kar98kiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "M24")
				{
					DX11::ImGui_DX11::DrawImage(DX11::m24iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "Mini14")
				{
					DX11::ImGui_DX11::DrawImage(DX11::mini_14iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "MK12")
				{
					DX11::ImGui_DX11::DrawImage(DX11::Mk12iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "Mk14")
				{
					DX11::ImGui_DX11::DrawImage(DX11::MK14iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "QBU")
				{
					DX11::ImGui_DX11::DrawImage(DX11::QBUiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "SKS")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SKSiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "SLR")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SLRiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "Sniper_Lynx6iconha_")
				{
					DX11::ImGui_DX11::DrawImage(DX11::Sniper_Lynx6iconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}
				else if (AActor.Weapon == "VSS")
				{
					DX11::ImGui_DX11::DrawImage(DX11::VSSiconha, Screen.X - 35, Screen.Y - 73, 45, 21);
				}

				else if (AActor.Weapon == "Fist")
				{
					DX11::ImGui_DX11::DrawImage(DX11::double_punchiconha, Screen.X - 35, Screen.Y - 73, 45, 20);

				}
				else if (AActor.Weapon == "Be Careful | Weapon Not Detect")
				{
					//DX11::ImGui_DX11::DrawImage(DX11::double_punchiconha, Screen.X - 15, Screen.Y - 53, 50, 20);
					//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::AR_Weaponsize, Text, Screen.X, Screen.Y, Setting::Esp_Item_AKMC, true);

					int dissize1 = 14;
					string wep = AActor.Weapon;

					if (Setting::playerweapon)
					{

						//	printf_s(temptext, xorstr_("%s (%d/%d)"), wep, AActor.Ammo, AActor.AmmoMax);

						/*string weapon; = wep AActor.Ammo, AActor.AmmoMax
							wep.append(" | ");
						wep.append(dista);*/

						/*wep.append(" | ");
						wep.append(to_string(AActor.Ammo) + ":");

						wep.append(to_string(AActor.AmmoMax));
						wep.append(AActor.ScopeFov);
						if (AActor.Ammo <= 200 && AActor.AmmoMax > 0)
						{
							DX11::ImGui_DX11::DrawBorderText(DX11::ImGui_DX11::pRegularFont, dissize1, wep, Screen.X + 5, (Screen.Y + Screen.Z) - 1, Colors::plyrweapon, true);
						}
						else
						{
							DX11::ImGui_DX11::DrawCharBorderText(DX11::ImGui_DX11::pRegularFont, dissize1, AActor.Weapon.c_str(), Screen.X + 5, (Screen.Y + Screen.Z) - 1, Colors::plyrweapon, true);
						}*/
					}
					//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, dissize1, wep, Screen.X + 5, (Screen.Y + Screen.Z) - 1, DX11::ImGui_DX11::Color::Red, true);
				}

			}

		}

		if (Setting1::style2)
		{
			if (Setting1::playerst2Weapons_iconsH)
			{

				if (AActor.Weapon == "AKM")
				{
					DX11::ImGui_DX11::DrawImage(DX11::akmiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "AUG")
				{
					DX11::ImGui_DX11::DrawImage(DX11::AUGiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "G36")
				{
					DX11::ImGui_DX11::DrawImage(DX11::G36Ciconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Groza")
				{
					DX11::ImGui_DX11::DrawImage(DX11::grozaiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "M16A4")
				{
					DX11::ImGui_DX11::DrawImage(DX11::M16A4iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "M416")
				{
					DX11::ImGui_DX11::DrawImage(DX11::M416iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "M762")
				{
					DX11::ImGui_DX11::DrawImage(DX11::m762iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Mk47")
				{
					DX11::ImGui_DX11::DrawImage(DX11::mk47_mutanticonha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "QBZ")
				{
					DX11::ImGui_DX11::DrawImage(DX11::QBZiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "SCAR")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SCARLiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}

				else if (AActor.Weapon == "Grenade")
				{
					DX11::ImGui_DX11::DrawImage(DX11::frag_grenadeiconha, Screen.X - 35, Screen.Y - 67, 30, 45);//ok
				}
				else if (AActor.Weapon == "Smoke")
				{
					DX11::ImGui_DX11::DrawImage(DX11::smoke_grenadeiconha, Screen.X - 35, Screen.Y - 70, 0, 40);//ok
				}

				else if (AActor.Weapon == "DP28")
				{
					DX11::ImGui_DX11::DrawImage(DX11::DP_28iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "M249")
				{
					DX11::ImGui_DX11::DrawImage(DX11::M249iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "MG3")
				{
					DX11::ImGui_DX11::DrawImage(DX11::MG3iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}

				else if (AActor.Weapon == "CrossBow")
				{
					DX11::ImGui_DX11::DrawImage(DX11::crossbowiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Crowbar")
				{
					DX11::ImGui_DX11::DrawImage(DX11::crowbariconha, Screen.X - 35, Screen.Y - 57, 55, 25);
				}
				else if (AActor.Weapon == "Machete")
				{
					DX11::ImGui_DX11::DrawImage(DX11::macheteiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Pan")
				{
					DX11::ImGui_DX11::DrawImage(DX11::PANiconha, Screen.X - 35, Screen.Y - 55, 45, 25);
				}
				else if (AActor.Weapon == "sickleiconha_")
				{
					DX11::ImGui_DX11::DrawImage(DX11::sickleiconha, Screen.X - 35, Screen.Y - 55, 55, 25);
				}

				else if (AActor.Weapon == "DesertEagle")
				{
					DX11::ImGui_DX11::DrawImage(DX11::Deagleiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Flaregun")
				{
					DX11::ImGui_DX11::DrawImage(DX11::FLAREGUNiconha, Screen.X - 35, Screen.Y - 56, 40, 25);
				}
				else if (AActor.Weapon == "P18C")
				{
					DX11::ImGui_DX11::DrawImage(DX11::P18Ciconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "P92")
				{
					DX11::ImGui_DX11::DrawImage(DX11::p92iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "P1911")
				{
					DX11::ImGui_DX11::DrawImage(DX11::p1911iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "MP5K")
				{
					DX11::ImGui_DX11::DrawImage(DX11::Pistol_MP5Kiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "R45")
				{
					DX11::ImGui_DX11::DrawImage(DX11::R45iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "R1895")
				{
					DX11::ImGui_DX11::DrawImage(DX11::r1895iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "SawedOff")
				{
					DX11::ImGui_DX11::DrawImage(DX11::sawed_officonha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}

				else if (AActor.Weapon == "DP12")
				{
					DX11::ImGui_DX11::DrawImage(DX11::DBSiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "S1897")
				{
					DX11::ImGui_DX11::DrawImage(DX11::s1897iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "S12K")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SHOTGUN_S12Kiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "S686")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SHOTGUN_S686iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}

				else if (AActor.Weapon == "Uzi")
				{
					DX11::ImGui_DX11::DrawImage(DX11::micro_UZIiconha, Screen.X - 35, Screen.Y - 60, 45, 21);
				}
				else if (AActor.Weapon == "MP5K")
				{
					DX11::ImGui_DX11::DrawImage(DX11::MP5Kiconha, Screen.X - 35, Screen.Y - 60, 45, 21);
				}
				else if (AActor.Weapon == "PP19")
				{
					DX11::ImGui_DX11::DrawImage(DX11::PP_19_Bizoniconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "TommyGu")
				{
					DX11::ImGui_DX11::DrawImage(DX11::tommy_guniconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "UMP9")
				{
					DX11::ImGui_DX11::DrawImage(DX11::ump9iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Vector")
				{
					DX11::ImGui_DX11::DrawImage(DX11::vectoriconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}

				else if (AActor.Weapon == "AWM")
				{
					DX11::ImGui_DX11::DrawImage(DX11::AWMiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Kar98k")
				{
					DX11::ImGui_DX11::DrawImage(DX11::kar98kiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "M24")
				{
					DX11::ImGui_DX11::DrawImage(DX11::m24iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Mini14")
				{
					DX11::ImGui_DX11::DrawImage(DX11::mini_14iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "MK12")
				{
					DX11::ImGui_DX11::DrawImage(DX11::Mk12iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Mk14")
				{
					DX11::ImGui_DX11::DrawImage(DX11::MK14iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "QBU")
				{
					DX11::ImGui_DX11::DrawImage(DX11::QBUiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "SKS")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SKSiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "SLR")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SLRiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Sniper_Lynx6iconha_")
				{
					DX11::ImGui_DX11::DrawImage(DX11::Sniper_Lynx6iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "VSS")
				{
					DX11::ImGui_DX11::DrawImage(DX11::VSSiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}

				else if (AActor.Weapon == "Fist")
				{
					DX11::ImGui_DX11::DrawImage(DX11::double_punchiconha, Screen.X - 35, Screen.Y - 53, 45, 20);

				}
				else if (AActor.Weapon == "Be Careful | Weapon Not Detect")
				{
					//DX11::ImGui_DX11::DrawImage(DX11::double_punchiconha, Screen.X - 15, Screen.Y - 53, 50, 20);
					//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::AR_Weaponsize, Text, Screen.X, Screen.Y, Setting::Esp_Item_AKMC, true);

					int dissize1 = 14;
					string wep = AActor.Weapon;

					if (Setting::playerweapon)
					{

						//	printf_s(temptext, xorstr_("%s (%d/%d)"), wep, AActor.Ammo, AActor.AmmoMax);

						/*string weapon; = wep AActor.Ammo, AActor.AmmoMax
							wep.append(" | ");
						wep.append(dista);*/

						/*wep.append(" | ");
						wep.append(to_string(AActor.Ammo) + ":");

						wep.append(to_string(AActor.AmmoMax));
						wep.append(AActor.ScopeFov);
						if (AActor.Ammo <= 200 && AActor.AmmoMax > 0)
						{
							DX11::ImGui_DX11::DrawBorderText(DX11::ImGui_DX11::pRegularFont, dissize1, wep, Screen.X + 5, (Screen.Y + Screen.Z) - 1, Colors::plyrweapon, true);
						}
						else
						{
							DX11::ImGui_DX11::DrawCharBorderText(DX11::ImGui_DX11::pRegularFont, dissize1, AActor.Weapon.c_str(), Screen.X + 5, (Screen.Y + Screen.Z) - 1, Colors::plyrweapon, true);
						}*/
					}
					//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, dissize1, wep, Screen.X + 5, (Screen.Y + Screen.Z) - 1, DX11::ImGui_DX11::Color::Red, true);
				}

			}

		}

		if (Setting1::style3)
		{
			if (Setting1::playerst3Weapons_iconsH)
			{

				if (AActor.Weapon == "AKM")
				{
					DX11::ImGui_DX11::DrawImage(DX11::akmiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "AUG")
				{
					DX11::ImGui_DX11::DrawImage(DX11::AUGiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "G36")
				{
					DX11::ImGui_DX11::DrawImage(DX11::G36Ciconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Groza")
				{
					DX11::ImGui_DX11::DrawImage(DX11::grozaiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "M16A4")
				{
					DX11::ImGui_DX11::DrawImage(DX11::M16A4iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "M416")
				{
					DX11::ImGui_DX11::DrawImage(DX11::M416iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "M762")
				{
					DX11::ImGui_DX11::DrawImage(DX11::m762iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Mk47")
				{
					DX11::ImGui_DX11::DrawImage(DX11::mk47_mutanticonha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "QBZ")
				{
					DX11::ImGui_DX11::DrawImage(DX11::QBZiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "SCAR")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SCARLiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}

				else if (AActor.Weapon == "Grenade")
				{
					DX11::ImGui_DX11::DrawImage(DX11::frag_grenadeiconha, Screen.X - 35, Screen.Y - 67, 30, 45);//ok
				}
				else if (AActor.Weapon == "Smoke")
				{
					DX11::ImGui_DX11::DrawImage(DX11::smoke_grenadeiconha, Screen.X - 35, Screen.Y - 70, 0, 40);//ok
				}

				else if (AActor.Weapon == "DP28")
				{
					DX11::ImGui_DX11::DrawImage(DX11::DP_28iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "M249")
				{
					DX11::ImGui_DX11::DrawImage(DX11::M249iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "MG3")
				{
					DX11::ImGui_DX11::DrawImage(DX11::MG3iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}

				else if (AActor.Weapon == "CrossBow")
				{
					DX11::ImGui_DX11::DrawImage(DX11::crossbowiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Crowbar")
				{
					DX11::ImGui_DX11::DrawImage(DX11::crowbariconha, Screen.X - 35, Screen.Y - 57, 55, 25);
				}
				else if (AActor.Weapon == "Machete")
				{
					DX11::ImGui_DX11::DrawImage(DX11::macheteiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Pan")
				{
					DX11::ImGui_DX11::DrawImage(DX11::PANiconha, Screen.X - 35, Screen.Y - 55, 45, 25);
				}
				else if (AActor.Weapon == "sickleiconha_")
				{
					DX11::ImGui_DX11::DrawImage(DX11::sickleiconha, Screen.X - 35, Screen.Y - 55, 55, 25);
				}

				else if (AActor.Weapon == "DesertEagle")
				{
					DX11::ImGui_DX11::DrawImage(DX11::Deagleiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Flaregun")
				{
					DX11::ImGui_DX11::DrawImage(DX11::FLAREGUNiconha, Screen.X - 35, Screen.Y - 56, 40, 25);
				}
				else if (AActor.Weapon == "P18C")
				{
					DX11::ImGui_DX11::DrawImage(DX11::P18Ciconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "P92")
				{
					DX11::ImGui_DX11::DrawImage(DX11::p92iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "P1911")
				{
					DX11::ImGui_DX11::DrawImage(DX11::p1911iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "MP5K")
				{
					DX11::ImGui_DX11::DrawImage(DX11::Pistol_MP5Kiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "R45")
				{
					DX11::ImGui_DX11::DrawImage(DX11::R45iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "R1895")
				{
					DX11::ImGui_DX11::DrawImage(DX11::r1895iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "SawedOff")
				{
					DX11::ImGui_DX11::DrawImage(DX11::sawed_officonha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}

				else if (AActor.Weapon == "DP12")
				{
					DX11::ImGui_DX11::DrawImage(DX11::DBSiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "S1897")
				{
					DX11::ImGui_DX11::DrawImage(DX11::s1897iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "S12K")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SHOTGUN_S12Kiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "S686")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SHOTGUN_S686iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}

				else if (AActor.Weapon == "Uzi")
				{
					DX11::ImGui_DX11::DrawImage(DX11::micro_UZIiconha, Screen.X - 35, Screen.Y - 60, 45, 21);
				}
				else if (AActor.Weapon == "MP5K")
				{
					DX11::ImGui_DX11::DrawImage(DX11::MP5Kiconha, Screen.X - 35, Screen.Y - 60, 45, 21);
				}
				else if (AActor.Weapon == "PP19")
				{
					DX11::ImGui_DX11::DrawImage(DX11::PP_19_Bizoniconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "TommyGu")
				{
					DX11::ImGui_DX11::DrawImage(DX11::tommy_guniconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "UMP9")
				{
					DX11::ImGui_DX11::DrawImage(DX11::ump9iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Vector")
				{
					DX11::ImGui_DX11::DrawImage(DX11::vectoriconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}

				else if (AActor.Weapon == "AWM")
				{
					DX11::ImGui_DX11::DrawImage(DX11::AWMiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Kar98k")
				{
					DX11::ImGui_DX11::DrawImage(DX11::kar98kiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "M24")
				{
					DX11::ImGui_DX11::DrawImage(DX11::m24iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Mini14")
				{
					DX11::ImGui_DX11::DrawImage(DX11::mini_14iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "MK12")
				{
					DX11::ImGui_DX11::DrawImage(DX11::Mk12iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Mk14")
				{
					DX11::ImGui_DX11::DrawImage(DX11::MK14iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "QBU")
				{
					DX11::ImGui_DX11::DrawImage(DX11::QBUiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "SKS")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SKSiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "SLR")
				{
					DX11::ImGui_DX11::DrawImage(DX11::SLRiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "Sniper_Lynx6iconha_")
				{
					DX11::ImGui_DX11::DrawImage(DX11::Sniper_Lynx6iconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}
				else if (AActor.Weapon == "VSS")
				{
					DX11::ImGui_DX11::DrawImage(DX11::VSSiconha, Screen.X - 35, Screen.Y - 53, 45, 21);
				}

				else if (AActor.Weapon == "Fist")
				{
					DX11::ImGui_DX11::DrawImage(DX11::double_punchiconha, Screen.X - 35, Screen.Y - 53, 45, 20);

				}
				else if (AActor.Weapon == "Be Careful | Weapon Not Detect")
				{
					//DX11::ImGui_DX11::DrawImage(DX11::double_punchiconha, Screen.X - 15, Screen.Y - 53, 50, 20);
					//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::AR_Weaponsize, Text, Screen.X, Screen.Y, Setting::Esp_Item_AKMC, true);

					int dissize1 = 14;
					string wep = AActor.Weapon;

					if (Setting::playerweapon)
					{

						//	printf_s(temptext, xorstr_("%s (%d/%d)"), wep, AActor.Ammo, AActor.AmmoMax);

						/*string weapon; = wep AActor.Ammo, AActor.AmmoMax
							wep.append(" | ");
						wep.append(dista);*/

						/*wep.append(" | ");
						wep.append(to_string(AActor.Ammo) + ":");

						wep.append(to_string(AActor.AmmoMax));
						wep.append(AActor.ScopeFov);
						if (AActor.Ammo <= 200 && AActor.AmmoMax > 0)
						{
							DX11::ImGui_DX11::DrawBorderText(DX11::ImGui_DX11::pRegularFont, dissize1, wep, Screen.X + 5, (Screen.Y + Screen.Z) - 1, Colors::plyrweapon, true);
						}
						else
						{
							DX11::ImGui_DX11::DrawCharBorderText(DX11::ImGui_DX11::pRegularFont, dissize1, AActor.Weapon.c_str(), Screen.X + 5, (Screen.Y + Screen.Z) - 1, Colors::plyrweapon, true);
						}*/
					}
					//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, dissize1, wep, Screen.X + 5, (Screen.Y + Screen.Z) - 1, DX11::ImGui_DX11::Color::Red, true);
				}
			}
		}
	}
	
}

////Opacity and colour===============================================================
void CustomImGUIStyle1()
{
	ImGuiIO& io = ImGui::GetIO();
	ImGuiStyle& style = ImGui::GetStyle();
	style.Alpha = 1.0f;
	style.WindowPadding = ImVec2(8, 8);
	style.WindowRounding = 1.0f; //= 10.0f;
	style.WindowBorderSize = 1.0f;
	style.WindowMinSize = ImVec2(32, 32);
	style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
	style.WindowMenuButtonPosition = ImGuiDir_Left;
	style.ChildRounding = 0.0f;
	style.ChildBorderSize = 1.0f;
	style.PopupRounding = 0.0f;
	style.PopupBorderSize = 1.0f;
	style.FramePadding = ImVec2(5, 3);
	style.FrameRounding = 1.0f;// Make all elements (checkboxes, etc) circles
	style.FrameBorderSize = 0.0f;
	style.ItemSpacing = ImVec2(8, 4);
	style.ItemInnerSpacing = ImVec2(4, 4);
	style.CellPadding = ImVec2(4, 2);
	style.TouchExtraPadding = ImVec2(0, 0);
	style.IndentSpacing = 17.0f;
	style.ColumnsMinSpacing = 6.0f;
	style.ScrollbarSize = 14.0f;
	style.ScrollbarRounding = 9.0f;
	style.GrabMinSize = 5.0f;// Make grab a circle
	style.GrabRounding = 3.0f;
	style.LogSliderDeadzone = 4.0f;
	style.TabRounding = 4.0f;
	style.TabBorderSize = 0.0f;
	style.TabMinWidthForCloseButton = 0.0f;
	style.ColorButtonPosition = ImGuiDir_Right;
	style.ButtonTextAlign = ImVec2(0.50f, 0.50f);
	style.SelectableTextAlign = ImVec2(0.0f, 0.0f);
	style.DisplayWindowPadding = ImVec2(19, 19);
	style.DisplaySafeAreaPadding = ImVec2(3, 3);
	style.MouseCursorScale = 1.0f;
	style.AntiAliasedLines = true;
	style.AntiAliasedLinesUseTex = true;
	style.AntiAliasedFill = true;
	style.CurveTessellationTol = 1.25f;
	style.CircleTessellationMaxError = 0.30f;


	ImVec4* colors = style.Colors;

	////-StyleColorsDark
	//colors[ImGuiCol_Text] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
	//colors[ImGuiCol_TextDisabled] = ImVec4(0.90f, 0.90f, 0.90f, 1.00f);
	//// colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	//colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 0.85f);
	//colors[ImGuiCol_ChildBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	//colors[ImGuiCol_PopupBg] = ImVec4(0.06f, 0.05f, 0.07f, 0.85f);
	//colors[ImGuiCol_Border] = ImVec4(0.80f, 0.80f, 0.83f, 0.88f);
	//colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
	//colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	//colors[ImGuiCol_FrameBgHovered] = ImVec4(0.55f, 0.40f, 0.0f, 0.75f);
	//colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	//colors[ImGuiCol_TitleBg] = ImVec4(0.148f, 0.148f, 0.148f, 1.000f);
	//colors[ImGuiCol_TitleBgActive] = ImVec4(0.148f, 0.148f, 0.148f, 1.000f);
	//colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.148f, 0.148f, 0.148f, 1.000f);
	//colors[ImGuiCol_MenuBarBg] = ImVec4(0.195f, 0.195f, 0.195f, 1.000f);
	//colors[ImGuiCol_ScrollbarBg] = ImVec4(0.160f, 0.160f, 0.160f, 1.000f);
	//colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.277f, 0.277f, 0.277f, 1.000f);
	//colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.300f, 0.300f, 0.300f, 1.000f);
	//colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	//colors[ImGuiCol_CheckMark] = ImVec4(0.000f, 1.00f, 0.000f, 1.000f);
	//colors[ImGuiCol_SliderGrab] = ImVec4(0.391f, 0.391f, 0.391f, 1.000f);
	//colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	//colors[ImGuiCol_Button] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	//colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	//colors[ImGuiCol_ButtonActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	//colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	//colors[ImGuiCol_HeaderHovered] = ImVec4(0.55f, 0.40f, 0.0f, 0.75f);
	//colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	//colors[ImGuiCol_Separator] = colors[ImGuiCol_Border];
	//colors[ImGuiCol_SeparatorHovered] = ImVec4(0.391f, 0.391f, 0.391f, 1.000f);
	//colors[ImGuiCol_SeparatorActive] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	//colors[ImGuiCol_ResizeGrip] = ImVec4(1.000f, 1.000f, 1.000f, 0.250f);
	//colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.000f, 1.000f, 1.000f, 0.670f);
	//colors[ImGuiCol_ResizeGripActive] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	//colors[ImGuiCol_Tab] = ImVec4(0.098f, 0.098f, 0.098f, 1.000f);
	//colors[ImGuiCol_TabHovered] = ImVec4(0.352f, 0.352f, 0.352f, 1.000f);
	//colors[ImGuiCol_TabActive] = ImVec4(0.195f, 0.195f, 0.195f, 1.000f);
	//colors[ImGuiCol_TabUnfocused] = ImVec4(0.098f, 0.098f, 0.098f, 1.000f);
	//colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.195f, 0.195f, 0.195f, 1.000f);
	//colors[ImGuiCol_PlotLines] = ImVec4(0.469f, 0.469f, 0.469f, 1.000f);
	//colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	//colors[ImGuiCol_PlotHistogram] = ImVec4(0.586f, 0.586f, 0.586f, 1.000f);
	//colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	//colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
	//colors[ImGuiCol_DragDropTarget] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	//colors[ImGuiCol_NavHighlight] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	//colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	//colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.000f, 0.000f, 0.000f, 0.586f);
	//colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.000f, 0.000f, 0.000f, 0.586f);


	//-StyleColorsClassic
	colors[ImGuiCol_Text] = ImVec4(0.90f, 0.90f, 0.90f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.85f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.11f, 0.11f, 0.14f, 0.92f);
	colors[ImGuiCol_Border] = ImVec4(0.50f, 0.50f, 0.50f, 0.50f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.43f, 0.43f, 0.43f, 0.39f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.47f, 0.47f, 0.69f, 0.40f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.42f, 0.41f, 0.64f, 0.69f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.27f, 0.27f, 0.54f, 0.83f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.32f, 0.32f, 0.63f, 0.87f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.40f, 0.40f, 0.80f, 0.20f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.40f, 0.40f, 0.55f, 0.80f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.20f, 0.25f, 0.30f, 0.60f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.40f, 0.40f, 0.80f, 0.30f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.40f, 0.40f, 0.80f, 0.40f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.41f, 0.39f, 0.80f, 0.60f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.90f, 0.90f, 0.90f, 0.50f);
	colors[ImGuiCol_SliderGrab] = ImVec4(1.00f, 1.00f, 1.00f, 0.30f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.41f, 0.39f, 0.80f, 0.60f);
	colors[ImGuiCol_Button] = ImVec4(0.35f, 0.40f, 0.61f, 0.62f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.40f, 0.48f, 0.71f, 0.79f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.46f, 0.54f, 0.80f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.40f, 0.40f, 0.90f, 0.45f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.45f, 0.45f, 0.90f, 0.80f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.53f, 0.53f, 0.87f, 0.80f);
	colors[ImGuiCol_Separator] = ImVec4(0.50f, 0.50f, 0.50f, 0.60f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.60f, 0.60f, 0.70f, 1.00f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.70f, 0.70f, 0.90f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.10f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.78f, 0.82f, 1.00f, 0.60f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.78f, 0.82f, 1.00f, 0.90f);
	colors[ImGuiCol_Tab] = ImLerp(colors[ImGuiCol_Header], colors[ImGuiCol_TitleBgActive], 0.80f);
	colors[ImGuiCol_TabHovered] = colors[ImGuiCol_HeaderHovered];
	colors[ImGuiCol_TabActive] = ImLerp(colors[ImGuiCol_HeaderActive], colors[ImGuiCol_TitleBgActive], 0.60f);
	colors[ImGuiCol_TabUnfocused] = ImLerp(colors[ImGuiCol_Tab], colors[ImGuiCol_TitleBg], 0.80f);
	colors[ImGuiCol_TabUnfocusedActive] = ImLerp(colors[ImGuiCol_TabActive], colors[ImGuiCol_TitleBg], 0.40f);
	colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	colors[ImGuiCol_TableHeaderBg] = ImVec4(0.27f, 0.27f, 0.38f, 1.00f);
	colors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.45f, 1.00f);   // Prefer using Alpha=1.0 here
	colors[ImGuiCol_TableBorderLight] = ImVec4(0.26f, 0.26f, 0.28f, 1.00f);   // Prefer using Alpha=1.0 here
	colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.07f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.00f, 0.00f, 1.00f, 0.35f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
	colors[ImGuiCol_NavHighlight] = colors[ImGuiCol_HeaderHovered];
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);


	////-StyleColorsLight
	//colors[ImGuiCol_Text] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	//colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
	//colors[ImGuiCol_WindowBg] = ImVec4(0.94f, 0.94f, 0.94f, 1.00f);
	//colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	//colors[ImGuiCol_PopupBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.98f);
	//colors[ImGuiCol_Border] = ImVec4(0.00f, 0.00f, 0.00f, 0.30f);
	//colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	//colors[ImGuiCol_FrameBg] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	//colors[ImGuiCol_FrameBgHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
	//colors[ImGuiCol_FrameBgActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
	//colors[ImGuiCol_TitleBg] = ImVec4(0.96f, 0.96f, 0.96f, 1.00f);
	//colors[ImGuiCol_TitleBgActive] = ImVec4(0.82f, 0.82f, 0.82f, 1.00f);
	//colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 1.00f, 1.00f, 0.51f);
	//colors[ImGuiCol_MenuBarBg] = ImVec4(0.86f, 0.86f, 0.86f, 1.00f);
	//colors[ImGuiCol_ScrollbarBg] = ImVec4(0.98f, 0.98f, 0.98f, 0.53f);
	//colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.69f, 0.69f, 0.69f, 0.80f);
	//colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.49f, 0.49f, 0.49f, 0.80f);
	//colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.49f, 0.49f, 0.49f, 1.00f);
	//colors[ImGuiCol_CheckMark] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	//colors[ImGuiCol_SliderGrab] = ImVec4(0.26f, 0.59f, 0.98f, 0.78f);
	//colors[ImGuiCol_SliderGrabActive] = ImVec4(0.46f, 0.54f, 0.80f, 0.60f);
	//colors[ImGuiCol_Button] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
	//colors[ImGuiCol_ButtonHovered] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	//colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
	//colors[ImGuiCol_Header] = ImVec4(0.26f, 0.59f, 0.98f, 0.31f);
	//colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
	//colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	//colors[ImGuiCol_Separator] = ImVec4(0.39f, 0.39f, 0.39f, 0.62f);
	//colors[ImGuiCol_SeparatorHovered] = ImVec4(0.14f, 0.44f, 0.80f, 0.78f);
	//colors[ImGuiCol_SeparatorActive] = ImVec4(0.14f, 0.44f, 0.80f, 1.00f);
	//colors[ImGuiCol_ResizeGrip] = ImVec4(0.35f, 0.35f, 0.35f, 0.17f);
	//colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
	//colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
	//colors[ImGuiCol_Tab] = ImLerp(colors[ImGuiCol_Header], colors[ImGuiCol_TitleBgActive], 0.90f);
	//colors[ImGuiCol_TabHovered] = colors[ImGuiCol_HeaderHovered];
	//colors[ImGuiCol_TabActive] = ImLerp(colors[ImGuiCol_HeaderActive], colors[ImGuiCol_TitleBgActive], 0.60f);
	//colors[ImGuiCol_TabUnfocused] = ImLerp(colors[ImGuiCol_Tab], colors[ImGuiCol_TitleBg], 0.80f);
	//colors[ImGuiCol_TabUnfocusedActive] = ImLerp(colors[ImGuiCol_TabActive], colors[ImGuiCol_TitleBg], 0.40f);
	//colors[ImGuiCol_PlotLines] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
	//colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
	//colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	//colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.45f, 0.00f, 1.00f);
	//colors[ImGuiCol_TableHeaderBg] = ImVec4(0.78f, 0.87f, 0.98f, 1.00f);
	//colors[ImGuiCol_TableBorderStrong] = ImVec4(0.57f, 0.57f, 0.64f, 1.00f);   // Prefer using Alpha=1.0 here
	//colors[ImGuiCol_TableBorderLight] = ImVec4(0.68f, 0.68f, 0.74f, 1.00f);   // Prefer using Alpha=1.0 here
	//colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	//colors[ImGuiCol_TableRowBgAlt] = ImVec4(0.30f, 0.30f, 0.30f, 0.09f);
	//colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
	//colors[ImGuiCol_DragDropTarget] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
	//colors[ImGuiCol_NavHighlight] = colors[ImGuiCol_HeaderHovered];
	//colors[ImGuiCol_NavWindowingHighlight] = ImVec4(0.70f, 0.70f, 0.70f, 0.70f);
	//colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.20f);
	//colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);


	////-StyleColorsMy
	////Window Opacity and colour===============================================================
	//style.Colors[ImGuiCol_WindowBg] = ImColor(0, 0, 0, 200);
	//style.Colors[ImGuiCol_Border] = ImColor(0, 80, 0, 200);
	////Main Window Back Color============================================================
	////style.Colors[ImGuiCol_ChildBg] = ImVec4(5.03399e-07, 4.41989e-07, 1e-06, 0.84530);
	//style.Colors[ImGuiCol_ChildBg] = ImColor(0, 0, 0, 0);

	//style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 1.0f);
	//style.Colors[ImGuiCol_FrameBg] = ImColor(0, 80, 0, 150);//CheckMark and Roll Bag
	//style.Colors[ImGuiCol_FrameBgHovered] = ImColor(0, 80, 0, 100);
	//style.Colors[ImGuiCol_FrameBgActive] = ImColor(0, 80, 0, 200);

	////Title Bar Color============================================================
	//style.Colors[ImGuiCol_TitleBg] = ImColor(0, 0, 0, 250);
	//style.Colors[ImGuiCol_TitleBgActive] = ImColor(0, 30, 0, 250);
	//style.Colors[ImGuiCol_TitleBgCollapsed] = ImColor(66, 66, 66, 250);

	////Menu Mix Color============================================================
	//style.Colors[ImGuiCol_CheckMark] = ImColor(0, 255, 0, 255);
	//style.Colors[ImGuiCol_MenuBarBg] = ImColor(66, 66, 66, 250);
	////colors[ImGuiCol_SliderGrabActive] = ImColor(133, 61, 224, 250);
	//style.Colors[ImGuiCol_SliderGrab] = ImColor(255, 255, 225, 150);
	//style.Colors[ImGuiCol_SliderGrabActive] = ImColor(255, 255, 225, 255);
	//style.Colors[ImGuiCol_Text] = ImVec4(255, 255, 255, 255);

	//style.Colors[ImGuiCol_Header] = ImColor(66, 66, 66, 250);
	//style.Colors[ImGuiCol_HeaderHovered] = ImColor(66, 66, 66, 250);
	//style.Colors[ImGuiCol_HeaderActive] = ImColor(66, 66, 66, 250);
	//style.Colors[ImGuiCol_TabHovered] = ImColor(66, 66, 66, 250);

	////Login Menu + Main Menu Button Color============================================================
	//style.Colors[ImGuiCol_Button] = ImColor(0, 80, 0, 100);
	//style.Colors[ImGuiCol_ButtonHovered] = ImColor(0, 80, 0, 150);
	//style.Colors[ImGuiCol_ButtonActive] = ImColor(0, 80, 0, 200);


	//colors[ImGuiCol_Header] = ImColor(0, 80, 0, 100);
	//colors[ImGuiCol_HeaderHovered] = ImColor(0, 80, 0, 150);
	//colors[ImGuiCol_HeaderActive] = ImColor(0, 80, 0, 200);

	//colors[ImGuiCol_SeparatorHovered] = ImColor(0, 80, 0, 150);
	//colors[ImGuiCol_SeparatorActive] = ImColor(0, 80, 0, 250);

	//colors[ImGuiCol_ResizeGrip] = ImColor(0, 80, 0, 100);
	//colors[ImGuiCol_ResizeGripHovered] = ImColor(0, 80, 0, 150);
	//colors[ImGuiCol_ResizeGripActive] = ImColor(0, 80, 0, 200);


	//style.Colors[ImGuiCol_PlotHistogram] = ImColor(66, 66, 66, 250);
	//style.Colors[ImGuiCol_PlotHistogramHovered] = ImColor(66, 66, 66, 250);
	//style.Colors[ImGuiCol_PlotLinesHovered] = ImColor(66, 66, 66, 250);
	//style.Colors[ImGuiCol_PlotLines] = ImColor(66, 66, 66, 250);

	//colors[ImGuiCol_PlotHistogram] = ImColor(66, 66, 66, 250);
	//colors[ImGuiCol_PlotHistogramHovered] = ImColor(66, 66, 66, 250);
	//colors[ImGuiCol_PlotLinesHovered] = ImColor(66, 66, 66, 250);
	//colors[ImGuiCol_PlotLines] = ImColor(66, 66, 66, 250);

	///*style.Colors[ImGuiCol_Tab] = ImColor(0, 80, 0, 100);
	//style.Colors[ImGuiCol_TabHovered] = ImColor(0, 80, 0, 150);
	//style.Colors[ImGuiCol_TabActive] = ImColor(0, 80, 0, 255);*/
	////colors[ImGuiCol_TabUnfocused] = ImVec4(0.038f, 0.050f, 0.136f, 1.000f);
	//style.Colors[ImGuiCol_Tab] = ImColor(0, 30, 0, 250);
	//style.Colors[ImGuiCol_TabHovered] = ImColor(0, 110, 0, 150);
	//style.Colors[ImGuiCol_TabActive] = ImColor(0, 110, 0, 250);

	//colors[ImGuiCol_TabUnfocusedActive] = ImColor(66, 66, 66, 250);
	//colors[ImGuiCol_TextSelectedBg] = ImVec4(0.98f, 0.26f, 0.26f, 0.35f);
	//colors[ImGuiCol_NavHighlight] = ImColor(66, 66, 66, 250);
	////style.Colors[ImGuiCol_Node]

}

////Opacity and colour===============================================================
void CustomImGUIStyle2()
{
	ImGuiIO& io = ImGui::GetIO();
	ImGuiStyle& style = ImGui::GetStyle();
	style.Alpha = 1.0f;
	style.WindowPadding = ImVec2(8, 8);
	style.WindowRounding = 1.0f; //= 10.0f;
	style.WindowBorderSize = 1.0f;
	style.WindowMinSize = ImVec2(32, 32);
	style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
	style.WindowMenuButtonPosition = ImGuiDir_Left;
	style.ChildRounding = 0.0f;
	style.ChildBorderSize = 1.0f;
	style.PopupRounding = 0.0f;
	style.PopupBorderSize = 1.0f;
	style.FramePadding = ImVec2(5, 3);
	style.FrameRounding = 1.0f;// Make all elements (checkboxes, etc) circles
	style.FrameBorderSize = 0.0f;
	style.ItemSpacing = ImVec2(8, 4);
	style.ItemInnerSpacing = ImVec2(4, 4);
	style.CellPadding = ImVec2(4, 2);
	style.TouchExtraPadding = ImVec2(0, 0);
	style.IndentSpacing = 17.0f;
	style.ColumnsMinSpacing = 6.0f;
	style.ScrollbarSize = 14.0f;
	style.ScrollbarRounding = 9.0f;
	style.GrabMinSize = 5.0f;// Make grab a circle
	style.GrabRounding = 3.0f;
	style.LogSliderDeadzone = 4.0f;
	style.TabRounding = 4.0f;
	style.TabBorderSize = 0.0f;
	style.TabMinWidthForCloseButton = 0.0f;
	style.ColorButtonPosition = ImGuiDir_Right;
	style.ButtonTextAlign = ImVec2(0.50f, 0.50f);
	style.SelectableTextAlign = ImVec2(0.0f, 0.0f);
	style.DisplayWindowPadding = ImVec2(19, 19);
	style.DisplaySafeAreaPadding = ImVec2(3, 3);
	style.MouseCursorScale = 1.0f;
	style.AntiAliasedLines = true;
	style.AntiAliasedLinesUseTex = true;
	style.AntiAliasedFill = true;
	style.CurveTessellationTol = 1.25f;
	style.CircleTessellationMaxError = 0.30f;


	ImVec4* colors = style.Colors;

	////-StyleColorsDark
	//colors[ImGuiCol_Text] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
	//colors[ImGuiCol_TextDisabled] = ImVec4(0.90f, 0.90f, 0.90f, 1.00f);
	//// colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	//colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 0.85f);
	//colors[ImGuiCol_ChildBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	//colors[ImGuiCol_PopupBg] = ImVec4(0.06f, 0.05f, 0.07f, 0.85f);
	//colors[ImGuiCol_Border] = ImVec4(0.80f, 0.80f, 0.83f, 0.88f);
	//colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
	//colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	//colors[ImGuiCol_FrameBgHovered] = ImVec4(0.55f, 0.40f, 0.0f, 0.75f);
	//colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	//colors[ImGuiCol_TitleBg] = ImVec4(0.148f, 0.148f, 0.148f, 1.000f);
	//colors[ImGuiCol_TitleBgActive] = ImVec4(0.148f, 0.148f, 0.148f, 1.000f);
	//colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.148f, 0.148f, 0.148f, 1.000f);
	//colors[ImGuiCol_MenuBarBg] = ImVec4(0.195f, 0.195f, 0.195f, 1.000f);
	//colors[ImGuiCol_ScrollbarBg] = ImVec4(0.160f, 0.160f, 0.160f, 1.000f);
	//colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.277f, 0.277f, 0.277f, 1.000f);
	//colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.300f, 0.300f, 0.300f, 1.000f);
	//colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	//colors[ImGuiCol_CheckMark] = ImVec4(0.80f, 1.00f, 0.80f, 1.000f);
	//colors[ImGuiCol_SliderGrab] = ImVec4(0.391f, 0.391f, 0.391f, 1.000f);
	//colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	//colors[ImGuiCol_Button] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	//colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	//colors[ImGuiCol_ButtonActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	//colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	//colors[ImGuiCol_HeaderHovered] = ImVec4(0.55f, 0.40f, 0.0f, 0.75f);
	//colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	//colors[ImGuiCol_Separator] = colors[ImGuiCol_Border];
	//colors[ImGuiCol_SeparatorHovered] = ImVec4(0.391f, 0.391f, 0.391f, 1.000f);
	//colors[ImGuiCol_SeparatorActive] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	//colors[ImGuiCol_ResizeGrip] = ImVec4(1.000f, 1.000f, 1.000f, 0.250f);
	//colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.000f, 1.000f, 1.000f, 0.670f);
	//colors[ImGuiCol_ResizeGripActive] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	//colors[ImGuiCol_Tab] = ImVec4(0.098f, 0.098f, 0.098f, 1.000f);
	//colors[ImGuiCol_TabHovered] = ImVec4(0.352f, 0.352f, 0.352f, 1.000f);
	//colors[ImGuiCol_TabActive] = ImVec4(0.195f, 0.195f, 0.195f, 1.000f);
	//colors[ImGuiCol_TabUnfocused] = ImVec4(0.098f, 0.098f, 0.098f, 1.000f);
	//colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.195f, 0.195f, 0.195f, 1.000f);
	//colors[ImGuiCol_PlotLines] = ImVec4(0.469f, 0.469f, 0.469f, 1.000f);
	//colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	//colors[ImGuiCol_PlotHistogram] = ImVec4(0.586f, 0.586f, 0.586f, 1.000f);
	//colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	//colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
	//colors[ImGuiCol_DragDropTarget] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	//colors[ImGuiCol_NavHighlight] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	//colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	//colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.000f, 0.000f, 0.000f, 0.586f);
	//colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.000f, 0.000f, 0.000f, 0.586f);


	////-StyleColorsClassic
	//colors[ImGuiCol_Text] = ImVec4(0.90f, 0.90f, 0.90f, 1.00f);
	//colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
	//colors[ImGuiCol_WindowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.85f);
	//colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	//colors[ImGuiCol_PopupBg] = ImVec4(0.11f, 0.11f, 0.14f, 0.92f);
	//colors[ImGuiCol_Border] = ImVec4(0.50f, 0.50f, 0.50f, 0.50f);
	//colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	//colors[ImGuiCol_FrameBg] = ImVec4(0.43f, 0.43f, 0.43f, 0.39f);
	//colors[ImGuiCol_FrameBgHovered] = ImVec4(0.47f, 0.47f, 0.69f, 0.40f);
	//colors[ImGuiCol_FrameBgActive] = ImVec4(0.42f, 0.41f, 0.64f, 0.69f);
	//colors[ImGuiCol_TitleBg] = ImVec4(0.27f, 0.27f, 0.54f, 0.83f);
	//colors[ImGuiCol_TitleBgActive] = ImVec4(0.32f, 0.32f, 0.63f, 0.87f);
	//colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.40f, 0.40f, 0.80f, 0.20f);
	//colors[ImGuiCol_MenuBarBg] = ImVec4(0.40f, 0.40f, 0.55f, 0.80f);
	//colors[ImGuiCol_ScrollbarBg] = ImVec4(0.20f, 0.25f, 0.30f, 0.60f);
	//colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.40f, 0.40f, 0.80f, 0.30f);
	//colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.40f, 0.40f, 0.80f, 0.40f);
	//colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.41f, 0.39f, 0.80f, 0.60f);
	//colors[ImGuiCol_CheckMark] = ImVec4(0.90f, 0.90f, 0.90f, 0.50f);
	//colors[ImGuiCol_SliderGrab] = ImVec4(1.00f, 1.00f, 1.00f, 0.30f);
	//colors[ImGuiCol_SliderGrabActive] = ImVec4(0.41f, 0.39f, 0.80f, 0.60f);
	//colors[ImGuiCol_Button] = ImVec4(0.35f, 0.40f, 0.61f, 0.62f);
	//colors[ImGuiCol_ButtonHovered] = ImVec4(0.40f, 0.48f, 0.71f, 0.79f);
	//colors[ImGuiCol_ButtonActive] = ImVec4(0.46f, 0.54f, 0.80f, 1.00f);
	//colors[ImGuiCol_Header] = ImVec4(0.40f, 0.40f, 0.90f, 0.45f);
	//colors[ImGuiCol_HeaderHovered] = ImVec4(0.45f, 0.45f, 0.90f, 0.80f);
	//colors[ImGuiCol_HeaderActive] = ImVec4(0.53f, 0.53f, 0.87f, 0.80f);
	//colors[ImGuiCol_Separator] = ImVec4(0.50f, 0.50f, 0.50f, 0.60f);
	//colors[ImGuiCol_SeparatorHovered] = ImVec4(0.60f, 0.60f, 0.70f, 1.00f);
	//colors[ImGuiCol_SeparatorActive] = ImVec4(0.70f, 0.70f, 0.90f, 1.00f);
	//colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.10f);
	//colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.78f, 0.82f, 1.00f, 0.60f);
	//colors[ImGuiCol_ResizeGripActive] = ImVec4(0.78f, 0.82f, 1.00f, 0.90f);
	//colors[ImGuiCol_Tab] = ImLerp(colors[ImGuiCol_Header], colors[ImGuiCol_TitleBgActive], 0.80f);
	//colors[ImGuiCol_TabHovered] = colors[ImGuiCol_HeaderHovered];
	//colors[ImGuiCol_TabActive] = ImLerp(colors[ImGuiCol_HeaderActive], colors[ImGuiCol_TitleBgActive], 0.60f);
	//colors[ImGuiCol_TabUnfocused] = ImLerp(colors[ImGuiCol_Tab], colors[ImGuiCol_TitleBg], 0.80f);
	//colors[ImGuiCol_TabUnfocusedActive] = ImLerp(colors[ImGuiCol_TabActive], colors[ImGuiCol_TitleBg], 0.40f);
	//colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	//colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	//colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	//colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	//colors[ImGuiCol_TableHeaderBg] = ImVec4(0.27f, 0.27f, 0.38f, 1.00f);
	//colors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.45f, 1.00f);   // Prefer using Alpha=1.0 here
	//colors[ImGuiCol_TableBorderLight] = ImVec4(0.26f, 0.26f, 0.28f, 1.00f);   // Prefer using Alpha=1.0 here
	//colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	//colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.07f);
	//colors[ImGuiCol_TextSelectedBg] = ImVec4(0.00f, 0.00f, 1.00f, 0.35f);
	//colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
	//colors[ImGuiCol_NavHighlight] = colors[ImGuiCol_HeaderHovered];
	//colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
	//colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
	//colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);


	////-StyleColorsLight
	//colors[ImGuiCol_Text] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	//colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
	//colors[ImGuiCol_WindowBg] = ImVec4(0.94f, 0.94f, 0.94f, 1.00f);
	//colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	//colors[ImGuiCol_PopupBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.98f);
	//colors[ImGuiCol_Border] = ImVec4(0.00f, 0.00f, 0.00f, 0.30f);
	//colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	//colors[ImGuiCol_FrameBg] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	//colors[ImGuiCol_FrameBgHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
	//colors[ImGuiCol_FrameBgActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
	//colors[ImGuiCol_TitleBg] = ImVec4(0.96f, 0.96f, 0.96f, 1.00f);
	//colors[ImGuiCol_TitleBgActive] = ImVec4(0.82f, 0.82f, 0.82f, 1.00f);
	//colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 1.00f, 1.00f, 0.51f);
	//colors[ImGuiCol_MenuBarBg] = ImVec4(0.86f, 0.86f, 0.86f, 1.00f);
	//colors[ImGuiCol_ScrollbarBg] = ImVec4(0.98f, 0.98f, 0.98f, 0.53f);
	//colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.69f, 0.69f, 0.69f, 0.80f);
	//colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.49f, 0.49f, 0.49f, 0.80f);
	//colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.49f, 0.49f, 0.49f, 1.00f);
	//colors[ImGuiCol_CheckMark] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	//colors[ImGuiCol_SliderGrab] = ImVec4(0.26f, 0.59f, 0.98f, 0.78f);
	//colors[ImGuiCol_SliderGrabActive] = ImVec4(0.46f, 0.54f, 0.80f, 0.60f);
	//colors[ImGuiCol_Button] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
	//colors[ImGuiCol_ButtonHovered] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	//colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
	//colors[ImGuiCol_Header] = ImVec4(0.26f, 0.59f, 0.98f, 0.31f);
	//colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
	//colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	//colors[ImGuiCol_Separator] = ImVec4(0.39f, 0.39f, 0.39f, 0.62f);
	//colors[ImGuiCol_SeparatorHovered] = ImVec4(0.14f, 0.44f, 0.80f, 0.78f);
	//colors[ImGuiCol_SeparatorActive] = ImVec4(0.14f, 0.44f, 0.80f, 1.00f);
	//colors[ImGuiCol_ResizeGrip] = ImVec4(0.35f, 0.35f, 0.35f, 0.17f);
	//colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
	//colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
	//colors[ImGuiCol_Tab] = ImLerp(colors[ImGuiCol_Header], colors[ImGuiCol_TitleBgActive], 0.90f);
	//colors[ImGuiCol_TabHovered] = colors[ImGuiCol_HeaderHovered];
	//colors[ImGuiCol_TabActive] = ImLerp(colors[ImGuiCol_HeaderActive], colors[ImGuiCol_TitleBgActive], 0.60f);
	//colors[ImGuiCol_TabUnfocused] = ImLerp(colors[ImGuiCol_Tab], colors[ImGuiCol_TitleBg], 0.80f);
	//colors[ImGuiCol_TabUnfocusedActive] = ImLerp(colors[ImGuiCol_TabActive], colors[ImGuiCol_TitleBg], 0.40f);
	//colors[ImGuiCol_PlotLines] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
	//colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
	//colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	//colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.45f, 0.00f, 1.00f);
	//colors[ImGuiCol_TableHeaderBg] = ImVec4(0.78f, 0.87f, 0.98f, 1.00f);
	//colors[ImGuiCol_TableBorderStrong] = ImVec4(0.57f, 0.57f, 0.64f, 1.00f);   // Prefer using Alpha=1.0 here
	//colors[ImGuiCol_TableBorderLight] = ImVec4(0.68f, 0.68f, 0.74f, 1.00f);   // Prefer using Alpha=1.0 here
	//colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	//colors[ImGuiCol_TableRowBgAlt] = ImVec4(0.30f, 0.30f, 0.30f, 0.09f);
	//colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
	//colors[ImGuiCol_DragDropTarget] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
	//colors[ImGuiCol_NavHighlight] = colors[ImGuiCol_HeaderHovered];
	//colors[ImGuiCol_NavWindowingHighlight] = ImVec4(0.70f, 0.70f, 0.70f, 0.70f);
	//colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.20f);
	//colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);


	//-StyleColorsMy
	//Window Opacity and colour===============================================================
	style.Colors[ImGuiCol_WindowBg] = ImColor(0, 0, 0, 200);
	style.Colors[ImGuiCol_Border] = ImColor(0, 80, 0, 200);
	//Main Window Back Color============================================================
	//style.Colors[ImGuiCol_ChildBg] = ImVec4(5.03399e-07, 4.41989e-07, 1e-06, 0.84530);
	style.Colors[ImGuiCol_ChildBg] = ImColor(0, 0, 0, 0);

	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 1.0f);
	style.Colors[ImGuiCol_FrameBg] = ImColor(0, 80, 0, 150);//CheckMark and Roll Bag
	style.Colors[ImGuiCol_FrameBgHovered] = ImColor(0, 80, 0, 100);
	style.Colors[ImGuiCol_FrameBgActive] = ImColor(0, 80, 0, 200);

	//Title Bar Color============================================================
	style.Colors[ImGuiCol_TitleBg] = ImColor(0, 0, 0, 250);
	style.Colors[ImGuiCol_TitleBgActive] = ImColor(0, 30, 0, 250);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImColor(66, 66, 66, 250);

	//Menu Mix Color============================================================
	style.Colors[ImGuiCol_CheckMark] = ImColor(0, 255, 0, 255);
	style.Colors[ImGuiCol_MenuBarBg] = ImColor(66, 66, 66, 250);
	//colors[ImGuiCol_SliderGrabActive] = ImColor(133, 61, 224, 250);
	style.Colors[ImGuiCol_SliderGrab] = ImColor(255, 255, 225, 150);
	style.Colors[ImGuiCol_SliderGrabActive] = ImColor(255, 255, 225, 255);
	style.Colors[ImGuiCol_Text] = ImVec4(255, 255, 255, 255);

	style.Colors[ImGuiCol_Header] = ImColor(66, 66, 66, 250);
	style.Colors[ImGuiCol_HeaderHovered] = ImColor(66, 66, 66, 250);
	style.Colors[ImGuiCol_HeaderActive] = ImColor(66, 66, 66, 250);
	style.Colors[ImGuiCol_TabHovered] = ImColor(66, 66, 66, 250);

	//Login Menu + Main Menu Button Color============================================================
	style.Colors[ImGuiCol_Button] = ImColor(0, 80, 0, 100);
	style.Colors[ImGuiCol_ButtonHovered] = ImColor(0, 80, 0, 150);
	style.Colors[ImGuiCol_ButtonActive] = ImColor(0, 80, 0, 200);


	colors[ImGuiCol_Header] = ImColor(0, 80, 0, 100);
	colors[ImGuiCol_HeaderHovered] = ImColor(0, 80, 0, 150);
	colors[ImGuiCol_HeaderActive] = ImColor(0, 80, 0, 200);

	colors[ImGuiCol_SeparatorHovered] = ImColor(0, 80, 0, 150);
	colors[ImGuiCol_SeparatorActive] = ImColor(0, 80, 0, 250);

	colors[ImGuiCol_ResizeGrip] = ImColor(0, 80, 0, 100);
	colors[ImGuiCol_ResizeGripHovered] = ImColor(0, 80, 0, 150);
	colors[ImGuiCol_ResizeGripActive] = ImColor(0, 80, 0, 200);


	style.Colors[ImGuiCol_PlotHistogram] = ImColor(66, 66, 66, 250);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImColor(66, 66, 66, 250);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImColor(66, 66, 66, 250);
	style.Colors[ImGuiCol_PlotLines] = ImColor(66, 66, 66, 250);

	colors[ImGuiCol_PlotHistogram] = ImColor(66, 66, 66, 250);
	colors[ImGuiCol_PlotHistogramHovered] = ImColor(66, 66, 66, 250);
	colors[ImGuiCol_PlotLinesHovered] = ImColor(66, 66, 66, 250);
	colors[ImGuiCol_PlotLines] = ImColor(66, 66, 66, 250);

	/*style.Colors[ImGuiCol_Tab] = ImColor(0, 80, 0, 100);
	style.Colors[ImGuiCol_TabHovered] = ImColor(0, 80, 0, 150);
	style.Colors[ImGuiCol_TabActive] = ImColor(0, 80, 0, 255);*/
	//colors[ImGuiCol_TabUnfocused] = ImVec4(0.038f, 0.050f, 0.136f, 1.000f);
	style.Colors[ImGuiCol_Tab] = ImColor(0, 30, 0, 250);
	style.Colors[ImGuiCol_TabHovered] = ImColor(0, 110, 0, 150);
	style.Colors[ImGuiCol_TabActive] = ImColor(0, 110, 0, 250);

	colors[ImGuiCol_TabUnfocusedActive] = ImColor(66, 66, 66, 250);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.98f, 0.26f, 0.26f, 0.35f);
	colors[ImGuiCol_NavHighlight] = ImColor(66, 66, 66, 250);
	//style.Colors[ImGuiCol_Node]

}

////Opacity and colour===============================================================
void CustomImGUIStyle3()
{

	ImGuiIO& io = ImGui::GetIO();
	ImGuiStyle& style = ImGui::GetStyle();
	style.WindowPadding = ImVec2(8, 8);
	style.WindowRounding = 1.0f;
	style.FramePadding = ImVec2(3, 3);
	style.FrameRounding = 1.0f; // Make all elements (checkboxes, etc) circles
	style.ItemSpacing = ImVec2(8, 4);
	style.ItemInnerSpacing = ImVec2(1, 6);
	style.CellPadding = ImVec2(5, 5);
	style.IndentSpacing = 23.0f;
	style.ScrollbarSize = 11.0f;
	style.ScrollbarRounding = 9.0f;
	style.GrabMinSize = 5.0f; // Make grab a circle
	style.GrabRounding = 3.0f;
	style.PopupRounding = 2.f;
	style.Alpha = 1.0;
	style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
	style.TouchExtraPadding = ImVec2(0, 0);
	style.TabRounding = 7.0f;

	style.ChildRounding = 7.0f;

	style.ButtonTextAlign = ImVec2(0.50f, 0.50f);

	style.ChildBorderSize = 0.100f;

	style.DisplayWindowPadding = ImVec2(22, 22);
	style.DisplaySafeAreaPadding = ImVec2(4, 4);
	style.AntiAliasedLines = true;
	style.CurveTessellationTol = 1.f;
	style.TabBorderSize = 0.000f;
	ImVec4* colors = style.Colors;

	style.Colors[ImGuiCol_WindowBg] = ImColor(0, 0, 0, 235);
	style.Colors[ImGuiCol_Border] = ImColor(50, 50, 50, 255);
	// style.Colors[ImGuiCol_ChildBg] = ImVec4(5.03399e-07, 4.41989e-07, 1e-06, 0.84530);
	//style.Colors[ImGuiCol_Border] = ImColor(255, 0, 0, 255);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 1.0f);
	style.Colors[ImGuiCol_FrameBg] = ImColor(66, 66, 66, 250);
	style.Colors[ImGuiCol_FrameBgHovered] = ImColor(66, 66, 66, 250);
	style.Colors[ImGuiCol_FrameBgActive] = ImColor(66, 66, 66, 250);
	style.Colors[ImGuiCol_TitleBg] = ImColor(66, 66, 66, 255);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImColor(66, 66, 66, 250);
	style.Colors[ImGuiCol_TitleBgActive] = ImColor(66, 66, 66, 255);


	style.Colors[ImGuiCol_CheckMark] = ImColor(255, 255, 255, 255);
	style.Colors[ImGuiCol_MenuBarBg] = ImColor(66, 66, 66, 250);
	style.Colors[ImGuiCol_SliderGrab] = ImColor(61, 133, 224, 250);
	style.Colors[ImGuiCol_SliderGrabActive] = ImColor(61, 133, 224, 250);
	style.Colors[ImGuiCol_Text] = ImVec4(0.98f, 0.97f, 0.93f, 1.00f);

	style.Colors[ImGuiCol_Header] = ImColor(66, 66, 66, 250);
	style.Colors[ImGuiCol_HeaderHovered] = ImColor(66, 66, 66, 250);
	style.Colors[ImGuiCol_HeaderActive] = ImColor(66, 66, 66, 250);
	style.Colors[ImGuiCol_TabHovered] = ImColor(66, 66, 66, 250);
	colors[ImGuiCol_SliderGrabActive] = ImColor(61, 133, 224, 250);

	style.Colors[ImGuiCol_Button] = ImColor(66, 66, 66, 250);
	style.Colors[ImGuiCol_ButtonHovered] = ImColor(158, 158, 158, 250);
	style.Colors[ImGuiCol_ButtonActive] = ImColor(66, 66, 66, 250);
	colors[ImGuiCol_Header] = ImColor(66, 66, 66, 250);
	colors[ImGuiCol_HeaderHovered] = ImColor(66, 66, 66, 250);
	colors[ImGuiCol_HeaderActive] = ImColor(66, 66, 66, 250);
	colors[ImGuiCol_SeparatorHovered] = ImColor(66, 66, 66, 250);
	colors[ImGuiCol_SeparatorActive] = ImColor(66, 66, 66, 250);
	colors[ImGuiCol_ResizeGrip] = ImColor(66, 66, 66, 250);
	colors[ImGuiCol_ResizeGripHovered] = ImColor(66, 66, 66, 250);
	colors[ImGuiCol_ResizeGripActive] = ImColor(66, 66, 66, 250);

	style.Colors[ImGuiCol_PlotHistogram] = ImColor(66, 66, 66, 250);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImColor(66, 66, 66, 250);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImColor(66, 66, 66, 250);
	style.Colors[ImGuiCol_PlotLines] = ImColor(66, 66, 66, 250);

	colors[ImGuiCol_PlotHistogram] = ImColor(66, 66, 66, 250);
	colors[ImGuiCol_PlotHistogramHovered] = ImColor(66, 66, 66, 250);
	colors[ImGuiCol_PlotLinesHovered] = ImColor(66, 66, 66, 250);
	colors[ImGuiCol_PlotLines] = ImColor(66, 66, 66, 250);

	style.Colors[ImGuiCol_Tab] = ImColor(33, 33, 33, 255);
	style.Colors[ImGuiCol_TabHovered] = ImColor(66, 66, 66, 255);
	style.Colors[ImGuiCol_TabActive] = ImColor(66, 66, 66, 255);
	// colors[ImGuiCol_TabUnfocused] = ImVec4(0.038f, 0.050f, 0.136f, 1.000f);

	colors[ImGuiCol_TabUnfocusedActive] = ImColor(66, 66, 66, 250);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.98f, 0.26f, 0.26f, 0.35f);
	colors[ImGuiCol_NavHighlight] = ImColor(66, 66, 66, 250);
	//style.Colors[ImGuiCol_Node]
}

////Opacity and colour===============================================================
void CustomImGUIStyle()
{
	ImGuiIO& io = ImGui::GetIO();
	ImGuiStyle& style = ImGui::GetStyle();
	style.Alpha = 1.0f;
	style.WindowPadding = ImVec2(8, 8);
	style.WindowRounding = 1.0f; //= 10.0f;
	style.WindowBorderSize = 1.0f;
	style.WindowMinSize = ImVec2(32, 32);
	style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
	style.WindowMenuButtonPosition = ImGuiDir_Left;
	style.ChildRounding = 0.0f;
	style.ChildBorderSize = 1.0f;
	style.PopupRounding = 0.0f;
	style.PopupBorderSize = 1.0f;
	style.FramePadding = ImVec2(5, 3);
	style.FrameRounding = 1.0f;// Make all elements (checkboxes, etc) circles
	style.FrameBorderSize = 0.0f;
	style.ItemSpacing = ImVec2(8, 4);
	style.ItemInnerSpacing = ImVec2(4, 4);
	style.CellPadding = ImVec2(4, 2);
	style.TouchExtraPadding = ImVec2(0, 0);
	style.IndentSpacing = 17.0f;
	style.ColumnsMinSpacing = 6.0f;
	style.ScrollbarSize = 14.0f;
	style.ScrollbarRounding = 9.0f;
	style.GrabMinSize = 5.0f;// Make grab a circle
	style.GrabRounding = 3.0f;
	style.LogSliderDeadzone = 4.0f;
	style.TabRounding = 4.0f;
	style.TabBorderSize = 0.0f;
	style.TabMinWidthForCloseButton = 0.0f;
	style.ColorButtonPosition = ImGuiDir_Right;
	style.ButtonTextAlign = ImVec2(0.50f, 0.50f);
	style.SelectableTextAlign = ImVec2(0.0f, 0.0f);
	style.DisplayWindowPadding = ImVec2(19, 19);
	style.DisplaySafeAreaPadding = ImVec2(3, 3);
	style.MouseCursorScale = 1.0f;
	style.AntiAliasedLines = true;
	style.AntiAliasedLinesUseTex = true;
	style.AntiAliasedFill = true;
	style.CurveTessellationTol = 1.25f;
	style.CircleTessellationMaxError = 0.30f;


	ImVec4* colors = style.Colors;

	//-StyleColorsDark
	colors[ImGuiCol_Text] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.90f, 0.90f, 0.90f, 1.00f);
	// colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 0.85f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.06f, 0.05f, 0.07f, 0.85f);
	colors[ImGuiCol_Border] = ImVec4(0.80f, 0.80f, 0.83f, 0.88f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.55f, 0.40f, 0.0f, 0.75f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.148f, 0.148f, 0.148f, 1.000f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.148f, 0.148f, 0.148f, 1.000f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.148f, 0.148f, 0.148f, 1.000f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.195f, 0.195f, 0.195f, 1.000f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.160f, 0.160f, 0.160f, 1.000f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.277f, 0.277f, 0.277f, 1.000f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.300f, 0.300f, 0.300f, 1.000f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.000f, 1.00f, 0.000f, 1.000f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.391f, 0.391f, 0.391f, 1.000f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	colors[ImGuiCol_Button] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.55f, 0.40f, 0.0f, 0.75f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	colors[ImGuiCol_Separator] = colors[ImGuiCol_Border];
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.391f, 0.391f, 0.391f, 1.000f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(1.000f, 1.000f, 1.000f, 0.250f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.000f, 1.000f, 1.000f, 0.670f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	colors[ImGuiCol_Tab] = ImVec4(0.098f, 0.098f, 0.098f, 1.000f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.352f, 0.352f, 0.352f, 1.000f);
	colors[ImGuiCol_TabActive] = ImVec4(0.195f, 0.195f, 0.195f, 1.000f);
	colors[ImGuiCol_TabUnfocused] = ImVec4(0.098f, 0.098f, 0.098f, 1.000f);
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.195f, 0.195f, 0.195f, 1.000f);
	colors[ImGuiCol_PlotLines] = ImVec4(0.469f, 0.469f, 0.469f, 1.000f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(0.586f, 0.586f, 0.586f, 1.000f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	colors[ImGuiCol_NavHighlight] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.000f, 0.000f, 0.000f, 0.586f);
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.000f, 0.000f, 0.000f, 0.586f);


	////-StyleColorsClassic
	//colors[ImGuiCol_Text] = ImVec4(0.90f, 0.90f, 0.90f, 1.00f);
	//colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
	//colors[ImGuiCol_WindowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.85f);
	//colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	//colors[ImGuiCol_PopupBg] = ImVec4(0.11f, 0.11f, 0.14f, 0.92f);
	//colors[ImGuiCol_Border] = ImVec4(0.50f, 0.50f, 0.50f, 0.50f);
	//colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	//colors[ImGuiCol_FrameBg] = ImVec4(0.43f, 0.43f, 0.43f, 0.39f);
	//colors[ImGuiCol_FrameBgHovered] = ImVec4(0.47f, 0.47f, 0.69f, 0.40f);
	//colors[ImGuiCol_FrameBgActive] = ImVec4(0.42f, 0.41f, 0.64f, 0.69f);
	//colors[ImGuiCol_TitleBg] = ImVec4(0.27f, 0.27f, 0.54f, 0.83f);
	//colors[ImGuiCol_TitleBgActive] = ImVec4(0.32f, 0.32f, 0.63f, 0.87f);
	//colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.40f, 0.40f, 0.80f, 0.20f);
	//colors[ImGuiCol_MenuBarBg] = ImVec4(0.40f, 0.40f, 0.55f, 0.80f);
	//colors[ImGuiCol_ScrollbarBg] = ImVec4(0.20f, 0.25f, 0.30f, 0.60f);
	//colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.40f, 0.40f, 0.80f, 0.30f);
	//colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.40f, 0.40f, 0.80f, 0.40f);
	//colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.41f, 0.39f, 0.80f, 0.60f);
	//colors[ImGuiCol_CheckMark] = ImVec4(0.90f, 0.90f, 0.90f, 0.50f);
	//colors[ImGuiCol_SliderGrab] = ImVec4(1.00f, 1.00f, 1.00f, 0.30f);
	//colors[ImGuiCol_SliderGrabActive] = ImVec4(0.41f, 0.39f, 0.80f, 0.60f);
	//colors[ImGuiCol_Button] = ImVec4(0.35f, 0.40f, 0.61f, 0.62f);
	//colors[ImGuiCol_ButtonHovered] = ImVec4(0.40f, 0.48f, 0.71f, 0.79f);
	//colors[ImGuiCol_ButtonActive] = ImVec4(0.46f, 0.54f, 0.80f, 1.00f);
	//colors[ImGuiCol_Header] = ImVec4(0.40f, 0.40f, 0.90f, 0.45f);
	//colors[ImGuiCol_HeaderHovered] = ImVec4(0.45f, 0.45f, 0.90f, 0.80f);
	//colors[ImGuiCol_HeaderActive] = ImVec4(0.53f, 0.53f, 0.87f, 0.80f);
	//colors[ImGuiCol_Separator] = ImVec4(0.50f, 0.50f, 0.50f, 0.60f);
	//colors[ImGuiCol_SeparatorHovered] = ImVec4(0.60f, 0.60f, 0.70f, 1.00f);
	//colors[ImGuiCol_SeparatorActive] = ImVec4(0.70f, 0.70f, 0.90f, 1.00f);
	//colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.10f);
	//colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.78f, 0.82f, 1.00f, 0.60f);
	//colors[ImGuiCol_ResizeGripActive] = ImVec4(0.78f, 0.82f, 1.00f, 0.90f);
	//colors[ImGuiCol_Tab] = ImLerp(colors[ImGuiCol_Header], colors[ImGuiCol_TitleBgActive], 0.80f);
	//colors[ImGuiCol_TabHovered] = colors[ImGuiCol_HeaderHovered];
	//colors[ImGuiCol_TabActive] = ImLerp(colors[ImGuiCol_HeaderActive], colors[ImGuiCol_TitleBgActive], 0.60f);
	//colors[ImGuiCol_TabUnfocused] = ImLerp(colors[ImGuiCol_Tab], colors[ImGuiCol_TitleBg], 0.80f);
	//colors[ImGuiCol_TabUnfocusedActive] = ImLerp(colors[ImGuiCol_TabActive], colors[ImGuiCol_TitleBg], 0.40f);
	//colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	//colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	//colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	//colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	//colors[ImGuiCol_TableHeaderBg] = ImVec4(0.27f, 0.27f, 0.38f, 1.00f);
	//colors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.45f, 1.00f);   // Prefer using Alpha=1.0 here
	//colors[ImGuiCol_TableBorderLight] = ImVec4(0.26f, 0.26f, 0.28f, 1.00f);   // Prefer using Alpha=1.0 here
	//colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	//colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.07f);
	//colors[ImGuiCol_TextSelectedBg] = ImVec4(0.00f, 0.00f, 1.00f, 0.35f);
	//colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
	//colors[ImGuiCol_NavHighlight] = colors[ImGuiCol_HeaderHovered];
	//colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
	//colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
	//colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);


	////-StyleColorsLight
	//colors[ImGuiCol_Text] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	//colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
	//colors[ImGuiCol_WindowBg] = ImVec4(0.94f, 0.94f, 0.94f, 1.00f);
	//colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	//colors[ImGuiCol_PopupBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.98f);
	//colors[ImGuiCol_Border] = ImVec4(0.00f, 0.00f, 0.00f, 0.30f);
	//colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	//colors[ImGuiCol_FrameBg] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	//colors[ImGuiCol_FrameBgHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
	//colors[ImGuiCol_FrameBgActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
	//colors[ImGuiCol_TitleBg] = ImVec4(0.96f, 0.96f, 0.96f, 1.00f);
	//colors[ImGuiCol_TitleBgActive] = ImVec4(0.82f, 0.82f, 0.82f, 1.00f);
	//colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 1.00f, 1.00f, 0.51f);
	//colors[ImGuiCol_MenuBarBg] = ImVec4(0.86f, 0.86f, 0.86f, 1.00f);
	//colors[ImGuiCol_ScrollbarBg] = ImVec4(0.98f, 0.98f, 0.98f, 0.53f);
	//colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.69f, 0.69f, 0.69f, 0.80f);
	//colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.49f, 0.49f, 0.49f, 0.80f);
	//colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.49f, 0.49f, 0.49f, 1.00f);
	//colors[ImGuiCol_CheckMark] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	//colors[ImGuiCol_SliderGrab] = ImVec4(0.26f, 0.59f, 0.98f, 0.78f);
	//colors[ImGuiCol_SliderGrabActive] = ImVec4(0.46f, 0.54f, 0.80f, 0.60f);
	//colors[ImGuiCol_Button] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
	//colors[ImGuiCol_ButtonHovered] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	//colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
	//colors[ImGuiCol_Header] = ImVec4(0.26f, 0.59f, 0.98f, 0.31f);
	//colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
	//colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	//colors[ImGuiCol_Separator] = ImVec4(0.39f, 0.39f, 0.39f, 0.62f);
	//colors[ImGuiCol_SeparatorHovered] = ImVec4(0.14f, 0.44f, 0.80f, 0.78f);
	//colors[ImGuiCol_SeparatorActive] = ImVec4(0.14f, 0.44f, 0.80f, 1.00f);
	//colors[ImGuiCol_ResizeGrip] = ImVec4(0.35f, 0.35f, 0.35f, 0.17f);
	//colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
	//colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
	//colors[ImGuiCol_Tab] = ImLerp(colors[ImGuiCol_Header], colors[ImGuiCol_TitleBgActive], 0.90f);
	//colors[ImGuiCol_TabHovered] = colors[ImGuiCol_HeaderHovered];
	//colors[ImGuiCol_TabActive] = ImLerp(colors[ImGuiCol_HeaderActive], colors[ImGuiCol_TitleBgActive], 0.60f);
	//colors[ImGuiCol_TabUnfocused] = ImLerp(colors[ImGuiCol_Tab], colors[ImGuiCol_TitleBg], 0.80f);
	//colors[ImGuiCol_TabUnfocusedActive] = ImLerp(colors[ImGuiCol_TabActive], colors[ImGuiCol_TitleBg], 0.40f);
	//colors[ImGuiCol_PlotLines] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
	//colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
	//colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	//colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.45f, 0.00f, 1.00f);
	//colors[ImGuiCol_TableHeaderBg] = ImVec4(0.78f, 0.87f, 0.98f, 1.00f);
	//colors[ImGuiCol_TableBorderStrong] = ImVec4(0.57f, 0.57f, 0.64f, 1.00f);   // Prefer using Alpha=1.0 here
	//colors[ImGuiCol_TableBorderLight] = ImVec4(0.68f, 0.68f, 0.74f, 1.00f);   // Prefer using Alpha=1.0 here
	//colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	//colors[ImGuiCol_TableRowBgAlt] = ImVec4(0.30f, 0.30f, 0.30f, 0.09f);
	//colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
	//colors[ImGuiCol_DragDropTarget] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
	//colors[ImGuiCol_NavHighlight] = colors[ImGuiCol_HeaderHovered];
	//colors[ImGuiCol_NavWindowingHighlight] = ImVec4(0.70f, 0.70f, 0.70f, 0.70f);
	//colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.20f);
	//colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);


	////-StyleColorsMy
	////Window Opacity and colour===============================================================
	//style.Colors[ImGuiCol_WindowBg] = ImColor(0, 0, 0, 200);
	//style.Colors[ImGuiCol_Border] = ImColor(0, 80, 0, 200);
	////Main Window Back Color============================================================
	////style.Colors[ImGuiCol_ChildBg] = ImVec4(5.03399e-07, 4.41989e-07, 1e-06, 0.84530);
	//style.Colors[ImGuiCol_ChildBg] = ImColor(0, 0, 0, 0);

	//style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 1.0f);
	//style.Colors[ImGuiCol_FrameBg] = ImColor(0, 80, 0, 150);//CheckMark and Roll Bag
	//style.Colors[ImGuiCol_FrameBgHovered] = ImColor(0, 80, 0, 100);
	//style.Colors[ImGuiCol_FrameBgActive] = ImColor(0, 80, 0, 200);

	////Title Bar Color============================================================
	//style.Colors[ImGuiCol_TitleBg] = ImColor(0, 0, 0, 250);
	//style.Colors[ImGuiCol_TitleBgActive] = ImColor(0, 30, 0, 250);
	//style.Colors[ImGuiCol_TitleBgCollapsed] = ImColor(66, 66, 66, 250);

	////Menu Mix Color============================================================
	//style.Colors[ImGuiCol_CheckMark] = ImColor(0, 255, 0, 255);
	//style.Colors[ImGuiCol_MenuBarBg] = ImColor(66, 66, 66, 250);
	////colors[ImGuiCol_SliderGrabActive] = ImColor(133, 61, 224, 250);
	//style.Colors[ImGuiCol_SliderGrab] = ImColor(255, 255, 225, 150);
	//style.Colors[ImGuiCol_SliderGrabActive] = ImColor(255, 255, 225, 255);
	//style.Colors[ImGuiCol_Text] = ImVec4(255, 255, 255, 255);

	//style.Colors[ImGuiCol_Header] = ImColor(66, 66, 66, 250);
	//style.Colors[ImGuiCol_HeaderHovered] = ImColor(66, 66, 66, 250);
	//style.Colors[ImGuiCol_HeaderActive] = ImColor(66, 66, 66, 250);
	//style.Colors[ImGuiCol_TabHovered] = ImColor(66, 66, 66, 250);

	////Login Menu + Main Menu Button Color============================================================
	//style.Colors[ImGuiCol_Button] = ImColor(0, 80, 0, 100);
	//style.Colors[ImGuiCol_ButtonHovered] = ImColor(0, 80, 0, 150);
	//style.Colors[ImGuiCol_ButtonActive] = ImColor(0, 80, 0, 200);


	//colors[ImGuiCol_Header] = ImColor(0, 80, 0, 100);
	//colors[ImGuiCol_HeaderHovered] = ImColor(0, 80, 0, 150);
	//colors[ImGuiCol_HeaderActive] = ImColor(0, 80, 0, 200);

	//colors[ImGuiCol_SeparatorHovered] = ImColor(0, 80, 0, 150);
	//colors[ImGuiCol_SeparatorActive] = ImColor(0, 80, 0, 250);

	//colors[ImGuiCol_ResizeGrip] = ImColor(0, 80, 0, 100);
	//colors[ImGuiCol_ResizeGripHovered] = ImColor(0, 80, 0, 150);
	//colors[ImGuiCol_ResizeGripActive] = ImColor(0, 80, 0, 200);


	//style.Colors[ImGuiCol_PlotHistogram] = ImColor(66, 66, 66, 250);
	//style.Colors[ImGuiCol_PlotHistogramHovered] = ImColor(66, 66, 66, 250);
	//style.Colors[ImGuiCol_PlotLinesHovered] = ImColor(66, 66, 66, 250);
	//style.Colors[ImGuiCol_PlotLines] = ImColor(66, 66, 66, 250);

	//colors[ImGuiCol_PlotHistogram] = ImColor(66, 66, 66, 250);
	//colors[ImGuiCol_PlotHistogramHovered] = ImColor(66, 66, 66, 250);
	//colors[ImGuiCol_PlotLinesHovered] = ImColor(66, 66, 66, 250);
	//colors[ImGuiCol_PlotLines] = ImColor(66, 66, 66, 250);

	///*style.Colors[ImGuiCol_Tab] = ImColor(0, 80, 0, 100);
	//style.Colors[ImGuiCol_TabHovered] = ImColor(0, 80, 0, 150);
	//style.Colors[ImGuiCol_TabActive] = ImColor(0, 80, 0, 255);*/
	////colors[ImGuiCol_TabUnfocused] = ImVec4(0.038f, 0.050f, 0.136f, 1.000f);
	//style.Colors[ImGuiCol_Tab] = ImColor(0, 30, 0, 250);
	//style.Colors[ImGuiCol_TabHovered] = ImColor(0, 110, 0, 150);
	//style.Colors[ImGuiCol_TabActive] = ImColor(0, 110, 0, 250);

	//colors[ImGuiCol_TabUnfocusedActive] = ImColor(66, 66, 66, 250);
	//colors[ImGuiCol_TextSelectedBg] = ImVec4(0.98f, 0.26f, 0.26f, 0.35f);
	//colors[ImGuiCol_NavHighlight] = ImColor(66, 66, 66, 250);
	////style.Colors[ImGuiCol_Node]

}




void RotateTriangle(std::array<VECTOR3, 3>& points, float rotation)
{
	const auto points_center = (points.at(0) + points.at(1) + points.at(2)) / 3;
	for (auto& point : points)
	{
		point = point - points_center;

		const auto temp_x = point.X;
		const auto temp_y = point.Y;

		const auto theta = DEG2RAD(rotation);
		const auto c = cosf(theta);
		const auto s = sinf(theta);

		point.X = temp_x * c - temp_y * s;
		point.Y = temp_x * s + temp_y * c;

		point = point + points_center;
	}
}

LinearColor RandomColor(float Rate) {

	static float x = 0, y = 0;
	static float r = 0, g = 0, b = 0;

	if (y >= 0.0f && y < 255.0f) {
		r = 255.0f;
		g = 0.0f;
		b = x;
	}
	else if (y >= 255.0f && y < 510.0f) {
		r = 255.0f - x;
		g = 0.0f;
		b = 255.0f;
	}
	else if (y >= 510.0f && y < 765.0f) {
		r = 0.0f;
		g = x;
		b = 255.0f;
	}
	else if (y >= 765.0f && y < 1020.0f) {
		r = 0.0f;
		g = 255.0f;
		b = 255.0f - x;
	}
	else if (y >= 1020.0f && y < 1275.0f) {
		r = x;
		g = 255.0f;
		b = 0.0f;
	}
	else if (y >= 1275.0f && y < 1530.0f) {
		r = 255.0f;
		g = 255.0f - x;
		b = 0.0f;
	}

	x += Rate; //increase this value to switch colors faster
	if (x >= 255.0f)
		x = 0.0f;

	y += Rate; //increase this value to switch colors faster
	if (y > 1530.0f)
		y = 0.0f;


	return { (float)r, (float)g, (float)b, 255 };
}

void ImGuiTextRGB(const char* fmt)
{


	static float isRed = 0.0f, isGreen = 0.01f, isBlue = 0.0f;


	auto isFrames = ImGui::GetFrameCount();

	if (isFrames % 1 == 0) {

		if (isGreen == 0.01f && isBlue == 0.0f) {
			isRed += 0.01f;
		}

		if (isRed > 0.99f && isBlue == 0.0f) {
			isRed = 1.0f;
			isGreen += 0.01f;
		}

		if (isGreen > 0.99f && isBlue == 0.0f) {
			isGreen = 1.0f;
			isRed -= 0.01f;
		}

		if (isRed < 0.01f && isGreen == 1.0f) {
			isRed = 0.0f;
			isBlue += 0.01f;
		}

		if (isBlue > 0.99f && isRed == 0.0f) {
			isBlue = 1.0f;
			isGreen -= 0.01f;
		}
		if (isGreen < 0.01f && isBlue == 1.0f) {
			isGreen = 0.0f;
			isRed += 0.01f;
		}
		if (isRed > 0.99f && isGreen == 0.0f) {
			isRed = 1.0f;
			isBlue -= 0.01f;
		}
		if (isBlue < 0.01f && isGreen == 0.0f) {
			isBlue = 0.0f;
			isRed -= 0.01f;
			if (isRed < 0.01f)
				isGreen = 0.01f;
		}
		ImGui::PushFont(DX11::ImGui_DX11::pic);
		ImGui::PushStyleColor(ImGuiCol_Text, ImColor(isRed, isBlue, isGreen, 8.0f).Value);
		ImGui::Text(fmt);

		ImGui::PopFont();
		ImGui::PopStyleColor();

	}
}

void ImGuiTextRGBGameInfo(const char* fmt)
{


	static float isRed = 0.0f, isGreen = 0.01f, isBlue = 0.0f;


	auto isFrames = ImGui::GetFrameCount();

	if (isFrames % 1 == 0) {

		if (isGreen == 0.01f && isBlue == 0.0f) {
			isRed += 0.01f;
		}

		if (isRed > 0.99f && isBlue == 0.0f) {
			isRed = 1.0f;
			isGreen += 0.01f;
		}

		if (isGreen > 0.99f && isBlue == 0.0f) {
			isGreen = 1.0f;
			isRed -= 0.01f;
		}

		if (isRed < 0.01f && isGreen == 1.0f) {
			isRed = 0.0f;
			isBlue += 0.01f;
		}

		if (isBlue > 0.99f && isRed == 0.0f) {
			isBlue = 1.0f;
			isGreen -= 0.01f;
		}
		if (isGreen < 0.01f && isBlue == 1.0f) {
			isGreen = 0.0f;
			isRed += 0.01f;
		}
		if (isRed > 0.99f && isGreen == 0.0f) {
			isRed = 1.0f;
			isBlue -= 0.01f;
		}
		if (isBlue < 0.01f && isGreen == 0.0f) {
			isBlue = 0.0f;
			isRed -= 0.01f;
			if (isRed < 0.01f)
				isGreen = 0.01f;
		}
		ImGui::PushFont(DX11::ImGui_DX11::picgameinfo);
		ImGui::PushStyleColor(ImGuiCol_Text, ImColor(isRed, isBlue, isGreen, 8.0f).Value);
		ImGui::Text(fmt);
		ImGui::PopFont();
		ImGui::PopStyleColor();

	}
}

void ImGuiTextRGBBigMenu(const char* fmt)
{


	static float isRed = 0.0f, isGreen = 0.01f, isBlue = 0.0f;


	auto isFrames = ImGui::GetFrameCount();

	if (isFrames % 1 == 0) {

		if (isGreen == 0.01f && isBlue == 0.0f) {
			isRed += 0.01f;
		}

		if (isRed > 0.99f && isBlue == 0.0f) {
			isRed = 1.0f;
			isGreen += 0.01f;
		}

		if (isGreen > 0.99f && isBlue == 0.0f) {
			isGreen = 1.0f;
			isRed -= 0.01f;
		}

		if (isRed < 0.01f && isGreen == 1.0f) {
			isRed = 0.0f;
			isBlue += 0.01f;
		}

		if (isBlue > 0.99f && isRed == 0.0f) {
			isBlue = 1.0f;
			isGreen -= 0.01f;
		}
		if (isGreen < 0.01f && isBlue == 1.0f) {
			isGreen = 0.0f;
			isRed += 0.01f;
		}
		if (isRed > 0.99f && isGreen == 0.0f) {
			isRed = 1.0f;
			isBlue -= 0.01f;
		}
		if (isBlue < 0.01f && isGreen == 0.0f) {
			isBlue = 0.0f;
			isRed -= 0.01f;
			if (isRed < 0.01f)
				isGreen = 0.01f;
		}
		ImGui::PushFont(DX11::ImGui_DX11::FontBigMenu);
		ImGui::PushStyleColor(ImGuiCol_Text, ImColor(isRed, isBlue, isGreen, 8.0f).Value);
		ImGui::Text(fmt);

		ImGui::PopFont();
		ImGui::PopStyleColor();

	}
}

static int64_t eptime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
void DrawTotalEnemies()
{
	int AliveTeamNum;
	int botcount;
	int playercount;
	if (Setting1::TotalEnemy)
	{

		// ESP Style1 Total Enemy--------------------------------------------------------------
		if (Setting1::style1)
		{
			if (Data::AActorList.size() != 0)
			{
				//AliveTeamNum = 0;
				botcount = 0;
				playercount = 0;
				for (int i = 0; i < Data::AActorList.size(); i++)
				{
					if (Data::AActorList[i].Name == "BOT")
					{
						botcount = botcount + 1;
					}
					else
					{
						playercount = playercount + 1;
						//AliveTeamNum = AliveTeamNum + 1;
					}
				}

				std::string Text = "Enemy : " + to_string(Data::AActorList.size()); +"  |";
				DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 15, Text, DX11Window::Width / 2 - 0, DX11Window::Height / 2 + 180, DX11::ImGui_DX11::Color::Green, true);
			}
			else
			{
				//AliveTeamNum = 0;
				botcount = 0;
				playercount = 0;
				for (int i = 0; i < Data::AActorList.size(); i++)
				{
					if (Data::AActorList[i].Name == "BOT")
					{
						botcount = botcount + 1;
					}
					else
					{
						playercount = playercount + 1;
						//AliveTeamNum = AliveTeamNum + 1;
					}
				}

				std::string Text = "Enemy : " + to_string(Data::AActorList.size()); +"  |";
				DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 15, Text, DX11Window::Width / 2 - 0, DX11Window::Height / 2 + 180, DX11::ImGui_DX11::Color::Green, true);
			}
		}
		// ESP Style2 Total Enemy--------------------------------------------------------------
		if (Setting1::style2)
		{
			if (Setting1::TotalEnemyStyle1)
			{
				//TotalEnemyStyle1
				if (Data::AActorList.size() != 0)
				{
					botcount = 0;
					playercount = 0;
					for (int i = 0; i < Data::AActorList.size(); i++)
					{
						if (Data::AActorList[i].Name == "BOT")
						{
							botcount = botcount + 1;
						}
						else
						{
							playercount = playercount + 1;
						}
					}

					ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 1.0f);
					ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 170, 75));
					ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(255, 255, 0, 255));
					ImGui::SetNextWindowSize(ImVec2(165.0f, 30.0f));
					ImGuiIO& Io = ImGui::GetIO();
					//ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));
					ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 82, (DX11Window::Height / 3.0f) - 180 });
					if (ImGui::Begin("ene", 0, Flags21))
					{
						if (Data::NetDriver > 0)
						{

							std::string player = ICON_FA_USER" PLAYERS: ";
							player.append(std::to_string(playercount));
							std::string bot = ICON_FA_USER" BOTS: ";
							bot.append(std::to_string(botcount));
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
							ImGui::SetCursorPos({ 5,8 });
							ImGui::Text(player.c_str());
							ImGui::PopStyleColor();
							//ImGui::SameLine();
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 255, 255));
							ImGui::SetCursorPos({ 95,8 });
							ImGui::Text(bot.c_str());
							ImGui::PopStyleColor();
						}
						else
						{
							ImGui::SetCursorPos({ 12.5,8 });
							std::string playerA = " NO ONE IS";
							std::string botA = " NEAR YOU";
							/* ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(115, 255, 0, 255));
							ImGui::Text(Text.c_str());
							ImGui::PopStyleColor();
							ImGui::SameLine(); */
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
							ImGui::Text(playerA.c_str());
							ImGui::PopStyleColor();
							ImGui::SameLine();
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 255, 255));
							ImGui::Text(botA.c_str());
							ImGui::PopStyleColor();
						}
						ImGui::End();
					}
					ImGui::PopStyleVar(1);
					ImGui::PopStyleColor();
					ImGui::PopStyleColor();
				}
				else
				{

					ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 1.0f);
					ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 170, 75));
					ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(255, 255, 0, 255));
					ImGui::SetNextWindowSize(ImVec2(165.0f, 30.0f));
					ImGuiIO& Io = ImGui::GetIO();
					//ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));
					ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 82, (DX11Window::Height / 3.0f) - 180 });
					if (ImGui::Begin("ene", 0, Flags21))
					{
						/*ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 125, (DX11Window::Height / 2.0f) - 125 });
						ImGui::Image((PVOID)ImageVip, ImVec2(140, 250));*/

						std::string Text1 = "";
						//std::string Text2 = "";
						if (Data::NetDriver > 0)
						{
							ImGui::SetCursorPos({ 12.5,8 });
							std::string playerA = " NO ONE IS";
							std::string botA = " NEAR YOU";
							/* ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(115, 255, 0, 255));
							ImGui::Text(Text.c_str());
							ImGui::PopStyleColor();
							ImGui::SameLine(); */
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
							ImGui::Text(playerA.c_str());
							ImGui::PopStyleColor();
							ImGui::SameLine();
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 255, 255));
							ImGui::Text(botA.c_str());
							ImGui::PopStyleColor();
						}
						else
						{
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
							ImGui::SetCursorPos({ 10,8 });
							ImGui::Text(ICON_FA_HOME" WELCOME  TO");
							ImGui::PopStyleColor();

							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 240, 255));
							ImGui::SetCursorPos({ 117,8 });
							ImGui::Text("LOBBY");
							ImGui::PopStyleColor();
						}
						ImGui::Text(Text1.c_str());
						ImGui::End();
					}
					ImGui::PopStyleColor();
					ImGui::PopStyleColor();
					ImGui::PopStyleVar(1);
				}
			}

			if (Setting1::TotalEnemyStyle2)
			{
				//TotalEnemyStyle2
				if (Data::AActorList.size() != 0)
				{
					botcount = 0;
					playercount = 0;
					for (int i = 0; i < Data::AActorList.size(); i++)
					{
						if (Data::AActorList[i].Name == "BOT")
						{
							botcount = botcount + 1;
						}
						else
						{
							playercount = playercount + 1;
						}
					}
					ImGuiStyle* stylest2 = &ImGui::GetStyle();
					stylest2->WindowRounding = 2.0f;

					ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 1.0f);
					ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 150, 75));
					ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(255, 255, 255, 255));
					ImGui::SetNextWindowSize(ImVec2(155.0f, 30.0f));
					ImGuiIO& Io = ImGui::GetIO();
					//ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));
					ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 77, (DX11Window::Height / 3.0f) - 145 });
					if (ImGui::Begin("ene", 0, Flags21))
					{
						if (Data::NetDriver > 0)
						{

							std::string player = " PLAYERS : ";
							//player.append(std::to_string(playercount));//For Check
							player.append(std::to_string(playercount));
							std::string bot = " BOTS : ";
							//bot.append(std::to_string(playercount));//For Check
							bot.append(std::to_string(botcount));
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
							ImGui::SetCursorPos({ 7,8 });
							ImGui::Text(player.c_str());
							ImGui::PopStyleColor();
							//ImGui::SameLine();
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 255, 255));
							ImGui::SetCursorPos({ 88,8 });
							ImGui::Text(bot.c_str());
							ImGui::PopStyleColor();
						}
						else
						{
							////ImGui::SetCursorPos({ 12.5,8 });
							////std::string playerA = " NO ONE IS";
							////std::string botA = " NEAR YOU";
							/////* ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(115, 255, 0, 255));
							////ImGui::Text(Text.c_str());
							////ImGui::PopStyleColor();
							////ImGui::SameLine(); */
							////ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
							////ImGui::Text(playerA.c_str());
							////ImGui::PopStyleColor();
							////ImGui::SameLine();
							////ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 255, 255));
							////ImGui::Text(botA.c_str());
							////ImGui::PopStyleColor();

							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
							ImGui::SetCursorPos({ 13,8 });
							ImGui::Text("NO ONE IS");
							/*ImGui::SetCursorPos({ 13,8 });
							ImGui::Text("NO ONE IS");*/
							ImGui::PopStyleColor();

							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 240, 255));
							ImGui::SetCursorPos({ 80,8 });
							ImGui::Text("NEAR YOU");
							/*ImGui::SetCursorPos({ 80,8 });
							ImGui::Text("NEAR YOU");*/
							ImGui::PopStyleColor();

							//Text1 = "NO ONE IS  NEAR YOU";
						}
						ImGui::End();
					}
					ImGui::PopStyleColor();
					ImGui::PopStyleColor();
					ImGui::PopStyleVar(1);
				}
				else
				{
					ImGuiStyle* stylest2 = &ImGui::GetStyle();
					stylest2->WindowRounding = 2.0f;

					ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 1.0f);
					ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 150, 75));
					ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(255, 255, 255, 255));
					ImGui::SetNextWindowSize(ImVec2(155.0f, 30.0f));
					ImGuiIO& Io = ImGui::GetIO();
					//ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));
					ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 77, (DX11Window::Height / 3.0f) - 145 });
					if (ImGui::Begin("ene", 0, Flags21))
					{
						/*ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 125, (DX11Window::Height / 2.0f) - 125 });
						ImGui::Image((PVOID)ImageVip, ImVec2(140, 250));*/

						std::string Text1 = "";
						//std::string Text2 = "";
						if (Data::NetDriver > 0)
						{
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
							ImGui::SetCursorPos({ 13,8 });
							ImGui::Text("NO ONE IS");
							/*ImGui::SetCursorPos({ 13,8 });
							ImGui::Text("NO ONE IS");*/
							ImGui::PopStyleColor();

							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 240, 255));
							ImGui::SetCursorPos({ 80,8 });
							ImGui::Text("NEAR YOU");
							/*ImGui::SetCursorPos({ 80,8 });
							ImGui::Text("NEAR YOU");*/
							ImGui::PopStyleColor();

							//Text1 = "NO ONE IS  NEAR YOU";
						}
						else
						{
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
							ImGui::SetCursorPos({ 15,8 });
							ImGui::Text("WELCOME TO");
							ImGui::PopStyleColor();

							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 240, 255));
							ImGui::SetCursorPos({ 100,8 });
							ImGui::Text("LOBBY");
							ImGui::PopStyleColor();

							//Text1 = "WELCOME TO LOBBY";
						}
						ImGui::Text(Text1.c_str());
						ImGui::End();
					}
					ImGui::PopStyleColor();
					ImGui::PopStyleColor();
					ImGui::PopStyleVar(1);
				}
			}

			if (Setting1::TotalEnemyStyle3)
			{
				//TotalEnemyStyle3
				if (Data::AActorList.size() != 0)
				{
					botcount = 0;
					playercount = 0;
					for (int i = 0; i < Data::AActorList.size(); i++)
					{
						if (Data::AActorList[i].Name == "BOT")
						{
							botcount = botcount + 1;
						}
						else
						{
							playercount = playercount + 1;
						}
					}

					ImGui::SetNextWindowSize(ImVec2(155.0f, 30.0f));
					ImGuiIO& Io = ImGui::GetIO();

					ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 1.0f);
					ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 170, 75));
					ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(255, 255, 0, 255));
					//ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));
					ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 77, (DX11Window::Height / 3.0f) - 145 });
					if (ImGui::Begin("ene", 0, Flags21))
					{
						std::string Text2 = "";
						if (Data::NetDriver > 0)
						{
							ImGui::PushStyleColor(ImGuiCol_Text, to_vec4(255, 0, 0, 255));
							ImGui::SetCursorPos({ 7,8 });
							ImGui::Text("ENEMY :");
							//Text2.append(std::to_string(playercount));
							ImGui::PopStyleColor();


							ImGui::PushStyleColor(ImGuiCol_Text, to_vec4(0, 255, 240, 255));
							ImGui::SetCursorPos({ 77,8 });
							ImGui::Text("|  BOTS :");
							//Text2.append(std::to_string(botcount));
							ImGui::PopStyleColor();
						}

						std::string Text1 = "";
						if (Data::NetDriver > 0)
						{
							ImGui::PushStyleColor(ImGuiCol_Text, to_vec4(255, 0, 0, 255));
							ImGui::SetCursorPos({ 1,8 });
							Text1 = "                  ";
							//Text1 = "ENEMY : ";
							Text1.append(std::to_string(playercount));
							ImGui::PopStyleColor();


							ImGui::PushStyleColor(ImGuiCol_Text, to_vec4(0, 255, 240, 255));
							ImGui::SetCursorPos({ 1,8 });
							Text1.append("                  ");
							//Text1.append("  |  BOTS : ");
							Text1.append(std::to_string(botcount));
							ImGui::PopStyleColor();
						}
						else
						{
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
							ImGui::SetCursorPos({ 13,8 });
							ImGui::Text("NO ONE IS");
							ImGui::PopStyleColor();

							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 240, 255));
							ImGui::SetCursorPos({ 80,8 });
							ImGui::Text("NEAR YOU");
							ImGui::PopStyleColor();

							//Text1 = "NO ONE IS  NEAR YOU";
						}
						ImGui::Text(Text1.c_str());
						ImGui::End();
					}
					ImGui::PopStyleColor();
					ImGui::PopStyleColor();
					ImGui::PopStyleVar(1);
				}
				else
				{
					ImGui::SetNextWindowSize(ImVec2(155.0f, 30.0f));
					ImGuiIO& Io = ImGui::GetIO();

					ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 1.0f);
					ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 170, 75));
					ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(255, 255, 0, 255));
					//ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));
					ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 77, (DX11Window::Height / 3.0f) - 145 });
					if (ImGui::Begin("ene", 0, Flags21))
					{
						/*ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 125, (DX11Window::Height / 2.0f) - 125 });
						ImGui::Image((PVOID)ImageVip, ImVec2(140, 250));*/

						std::string Text1 = "";
						//std::string Text2 = "";
						if (Data::NetDriver > 0)
						{
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
							ImGui::SetCursorPos({ 13,8 });
							ImGui::Text("NO ONE IS");
							/*ImGui::SetCursorPos({ 13,8 });
							ImGui::Text("NO ONE IS");*/
							ImGui::PopStyleColor();

							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 240, 255));
							ImGui::SetCursorPos({ 80,8 });
							ImGui::Text("NEAR YOU");
							/*ImGui::SetCursorPos({ 80,8 });
							ImGui::Text("NEAR YOU");*/
							ImGui::PopStyleColor();

							//Text1 = "NO ONE IS  NEAR YOU";
						}
						else
						{
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
							ImGui::SetCursorPos({ 15,8 });
							ImGui::Text("WELCOME TO");
							ImGui::PopStyleColor();

							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 240, 255));
							ImGui::SetCursorPos({ 100,8 });
							ImGui::Text("LOBBY");
							ImGui::PopStyleColor();

							//Text1 = "WELCOME TO LOBBY";
						}
						ImGui::Text(Text1.c_str());
						ImGui::End();
					}
					ImGui::PopStyleColor();
					ImGui::PopStyleColor();
					ImGui::PopStyleVar(1);
				}
			}
		}
		// ESP Style3 Total Enemy--------------------------------------------------------------
		if (Setting1::style3)
		{
			if (Setting1::TotalEnemyStyle1)
			{
				//TotalEnemyStyle1
				if (Data::AActorList.size() != 0)
				{
					botcount = 0;
					playercount = 0;
					for (int i = 0; i < Data::AActorList.size(); i++)
					{
						if (Data::AActorList[i].Name == "BOT")
						{
							botcount = botcount + 1;
						}
						else
						{
							playercount = playercount + 1;
						}
					}

					ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 1.0f);
					ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 170, 75));
					ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(255, 255, 0, 255));
					ImGui::SetNextWindowSize(ImVec2(165.0f, 30.0f));
					ImGuiIO& Io = ImGui::GetIO();
					//ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));
					ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 82, (DX11Window::Height / 3.0f) - 180 });
					if (ImGui::Begin("ene", 0, Flags21))
					{
						if (Data::NetDriver > 0)
						{

							std::string player = ICON_FA_USER" PLAYERS: ";
							player.append(std::to_string(playercount));
							std::string bot = ICON_FA_USER" BOTS: ";
							bot.append(std::to_string(botcount));
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
							ImGui::SetCursorPos({ 5,8 });
							ImGui::Text(player.c_str());
							ImGui::PopStyleColor();
							//ImGui::SameLine();
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 255, 255));
							ImGui::SetCursorPos({ 95,8 });
							ImGui::Text(bot.c_str());
							ImGui::PopStyleColor();
						}
						else
						{
							ImGui::SetCursorPos({ 12.5,8 });
							std::string playerA = " NO ONE IS";
							std::string botA = " NEAR YOU";
							/* ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(115, 255, 0, 255));
							ImGui::Text(Text.c_str());
							ImGui::PopStyleColor();
							ImGui::SameLine(); */
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
							ImGui::Text(playerA.c_str());
							ImGui::PopStyleColor();
							ImGui::SameLine();
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 255, 255));
							ImGui::Text(botA.c_str());
							ImGui::PopStyleColor();
						}
						ImGui::End();
					}
					ImGui::PopStyleVar(1);
					ImGui::PopStyleColor();
					ImGui::PopStyleColor();
				}
				else
				{

					ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 1.0f);
					ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 170, 75));
					ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(255, 255, 0, 255));
					ImGui::SetNextWindowSize(ImVec2(165.0f, 30.0f));
					ImGuiIO& Io = ImGui::GetIO();
					//ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));
					ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 82, (DX11Window::Height / 3.0f) - 180 });
					if (ImGui::Begin("ene", 0, Flags21))
					{
						/*ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 125, (DX11Window::Height / 2.0f) - 125 });
						ImGui::Image((PVOID)ImageVip, ImVec2(140, 250));*/

						std::string Text1 = "";
						//std::string Text2 = "";
						if (Data::NetDriver > 0)
						{
							ImGui::SetCursorPos({ 12.5,8 });
							std::string playerA = " NO ONE IS";
							std::string botA = " NEAR YOU";
							/* ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(115, 255, 0, 255));
							ImGui::Text(Text.c_str());
							ImGui::PopStyleColor();
							ImGui::SameLine(); */
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
							ImGui::Text(playerA.c_str());
							ImGui::PopStyleColor();
							ImGui::SameLine();
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 255, 255));
							ImGui::Text(botA.c_str());
							ImGui::PopStyleColor();
						}
						else
						{
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
							ImGui::SetCursorPos({ 10,8 });
							ImGui::Text(ICON_FA_HOME" WELCOME  TO");
							ImGui::PopStyleColor();

							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 240, 255));
							ImGui::SetCursorPos({ 117,8 });
							ImGui::Text("LOBBY");
							ImGui::PopStyleColor();
						}
						ImGui::Text(Text1.c_str());
						ImGui::End();
					}
					ImGui::PopStyleColor();
					ImGui::PopStyleColor();
					ImGui::PopStyleVar(1);
				}
			}

			if (Setting1::TotalEnemyStyle2)
			{
				//TotalEnemyStyle2
				if (Data::AActorList.size() != 0)
				{
					botcount = 0;
					playercount = 0;
					for (int i = 0; i < Data::AActorList.size(); i++)
					{
						if (Data::AActorList[i].Name == "BOT")
						{
							botcount = botcount + 1;
						}
						else
						{
							playercount = playercount + 1;
						}
					}
					ImGuiStyle* stylest3 = &ImGui::GetStyle();
					stylest3->WindowRounding = 8.0f;

					ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 1.7f);
					ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 0, 180));
					ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(220, 0, 0, 255));
					ImGui::SetNextWindowSize(ImVec2(155.0f, 32.0f));
					ImGuiIO& Io = ImGui::GetIO();
					//ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));
					ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 77, (DX11Window::Height / 3.0f) - 145 });
					if (ImGui::Begin("ene", 0, Flags21))
					{
						if (Data::NetDriver > 0)
						{
							
							std::string player = " PLAYERS : ";
							//player.append(std::to_string(playercount));//For Check
							player.append(std::to_string(playercount));
							std::string bot = " BOTS : ";
							//bot.append(std::to_string(playercount));//For Check
							bot.append(std::to_string(botcount));
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
							ImGui::SetCursorPos({ 7,9 });
							ImGui::Text(player.c_str());
							ImGui::PopStyleColor();
							//ImGui::SameLine();
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 255, 255));
							ImGui::SetCursorPos({ 88,9 });
							ImGui::Text(bot.c_str());
							ImGui::PopStyleColor();
						}
						else
						{
							////ImGui::SetCursorPos({ 12.5,8 });
							////std::string playerA = " NO ONE IS";
							////std::string botA = " NEAR YOU";
							/////* ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(115, 255, 0, 255));
							////ImGui::Text(Text.c_str());
							////ImGui::PopStyleColor();
							////ImGui::SameLine(); */
							////ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
							////ImGui::Text(playerA.c_str());
							////ImGui::PopStyleColor();
							////ImGui::SameLine();
							////ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 255, 255));
							////ImGui::Text(botA.c_str());
							////ImGui::PopStyleColor();

							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
							ImGui::SetCursorPos({ 13,9 });
							ImGui::Text("NO ONE IS");
							/*ImGui::SetCursorPos({ 13,8 });
							ImGui::Text("NO ONE IS");*/
							ImGui::PopStyleColor();

							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 255, 255));
							ImGui::SetCursorPos({ 80,9 });
							ImGui::Text("NEAR YOU");
							/*ImGui::SetCursorPos({ 80,8 });
							ImGui::Text("NEAR YOU");*/
							ImGui::PopStyleColor();

							//Text1 = "NO ONE IS  NEAR YOU";
						}
						ImGui::End();
					}
					ImGui::PopStyleColor();
					ImGui::PopStyleColor();
					ImGui::PopStyleVar(1);
				}
				else
				{
					ImGuiStyle* stylest3 = &ImGui::GetStyle();
					stylest3->WindowRounding = 8.0f;

					ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 1.7f);
					ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 0, 180));
					ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(220, 0, 0, 255));
					ImGui::SetNextWindowSize(ImVec2(155.0f, 32.0f));
					ImGuiIO& Io = ImGui::GetIO();
					//ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));
					ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 77, (DX11Window::Height / 3.0f) - 145 });
					if (ImGui::Begin("ene", 0, Flags21))
					{
						/*ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 125, (DX11Window::Height / 2.0f) - 125 });
						ImGui::Image((PVOID)ImageVip, ImVec2(140, 250));*/

						std::string Text1 = "";
						//std::string Text2 = "";
						if (Data::NetDriver > 0)
						{
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
							ImGui::SetCursorPos({ 13,9 });
							ImGui::Text("NO ONE IS");
							/*ImGui::SetCursorPos({ 13,8 });
							ImGui::Text("NO ONE IS");*/
							ImGui::PopStyleColor();

							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 255, 255));
							ImGui::SetCursorPos({ 80,9 });
							ImGui::Text("NEAR YOU");
							/*ImGui::SetCursorPos({ 80,8 });
							ImGui::Text("NEAR YOU");*/
							ImGui::PopStyleColor();

							//Text1 = "NO ONE IS  NEAR YOU";
						}
						else
						{
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
							ImGui::SetCursorPos({ 15,9 });
							ImGui::Text("WELCOME TO");
							ImGui::PopStyleColor();

							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 255, 255));
							ImGui::SetCursorPos({ 100,9 });
							ImGui::Text("LOBBY");
							ImGui::PopStyleColor();

							//Text1 = "WELCOME TO LOBBY";
						}
						ImGui::Text(Text1.c_str());
						ImGui::End();
					}
					ImGui::PopStyleColor();
					ImGui::PopStyleColor();
					ImGui::PopStyleVar(1);
				}
			}

			if (Setting1::TotalEnemyStyle3)
			{
				//TotalEnemyStyle3
				if (Data::AActorList.size() != 0)
				{
					botcount = 0;
					playercount = 0;
					for (int i = 0; i < Data::AActorList.size(); i++)
					{
						if (Data::AActorList[i].Name == "BOT")
						{
							botcount = botcount + 1;
						}
						else
						{
							playercount = playercount + 1;
						}
					}

					ImGui::SetNextWindowSize(ImVec2(155.0f, 30.0f));
					ImGuiIO& Io = ImGui::GetIO();

					ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 1.0f);
					ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 170, 75));
					ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(255, 255, 0, 255));
					//ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));
					ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 77, (DX11Window::Height / 3.0f) - 145 });
					if (ImGui::Begin("ene", 0, Flags21))
					{
						std::string Text2 = "";
						if (Data::NetDriver > 0)
						{
							ImGui::PushStyleColor(ImGuiCol_Text, to_vec4(255, 0, 0, 255));
							ImGui::SetCursorPos({ 7,8 });
							ImGui::Text("ENEMY :");
							//Text2.append(std::to_string(playercount));
							ImGui::PopStyleColor();


							ImGui::PushStyleColor(ImGuiCol_Text, to_vec4(0, 255, 240, 255));
							ImGui::SetCursorPos({ 77,8 });
							ImGui::Text("|  BOTS :");
							//Text2.append(std::to_string(botcount));
							ImGui::PopStyleColor();
						}

						std::string Text1 = "";
						if (Data::NetDriver > 0)
						{
							ImGui::PushStyleColor(ImGuiCol_Text, to_vec4(255, 0, 0, 255));
							ImGui::SetCursorPos({ 1,8 });
							Text1 = "                  ";
							//Text1 = "ENEMY : ";
							Text1.append(std::to_string(playercount));
							ImGui::PopStyleColor();


							ImGui::PushStyleColor(ImGuiCol_Text, to_vec4(0, 255, 240, 255));
							ImGui::SetCursorPos({ 1,8 });
							Text1.append("                  ");
							//Text1.append("  |  BOTS : ");
							Text1.append(std::to_string(botcount));
							ImGui::PopStyleColor();
						}
						else
						{
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
							ImGui::SetCursorPos({ 13,8 });
							ImGui::Text("NO ONE IS");
							ImGui::PopStyleColor();

							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 240, 255));
							ImGui::SetCursorPos({ 80,8 });
							ImGui::Text("NEAR YOU");
							ImGui::PopStyleColor();

							//Text1 = "NO ONE IS  NEAR YOU";
						}
						ImGui::Text(Text1.c_str());
						ImGui::End();
					}
					ImGui::PopStyleColor();
					ImGui::PopStyleColor();
					ImGui::PopStyleVar(1);
				}
				else
				{
					ImGui::SetNextWindowSize(ImVec2(155.0f, 30.0f));
					ImGuiIO& Io = ImGui::GetIO();

					ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 1.0f);
					ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 170, 75));
					ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(255, 255, 0, 255));
					//ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));
					ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 77, (DX11Window::Height / 3.0f) - 145 });
					if (ImGui::Begin("ene", 0, Flags21))
					{
						/*ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 125, (DX11Window::Height / 2.0f) - 125 });
						ImGui::Image((PVOID)ImageVip, ImVec2(140, 250));*/

						std::string Text1 = "";
						//std::string Text2 = "";
						if (Data::NetDriver > 0)
						{
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
							ImGui::SetCursorPos({ 13,8 });
							ImGui::Text("NO ONE IS");
							/*ImGui::SetCursorPos({ 13,8 });
							ImGui::Text("NO ONE IS");*/
							ImGui::PopStyleColor();

							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 240, 255));
							ImGui::SetCursorPos({ 80,8 });
							ImGui::Text("NEAR YOU");
							/*ImGui::SetCursorPos({ 80,8 });
							ImGui::Text("NEAR YOU");*/
							ImGui::PopStyleColor();

							//Text1 = "NO ONE IS  NEAR YOU";
						}
						else
						{
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
							ImGui::SetCursorPos({ 15,8 });
							ImGui::Text("WELCOME TO");
							ImGui::PopStyleColor();

							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 240, 255));
							ImGui::SetCursorPos({ 100,8 });
							ImGui::Text("LOBBY");
							ImGui::PopStyleColor();

							//Text1 = "WELCOME TO LOBBY";
						}
						ImGui::Text(Text1.c_str());
						ImGui::End();
					}
					ImGui::PopStyleColor();
					ImGui::PopStyleColor();
					ImGui::PopStyleVar(1);
				}
			}
		}
	}

	//////ImGui::SetNextWindowSize(ImVec2(155.0f, 35.0f));
	////ImGuiIO& Io = ImGui::GetIO();
	////ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(10, 10));
	////if (Data::NetDriver > 0)
	////{
	////	if (Data::AActorList.size() > 0)
	////	{

	////		ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 0, 255));
	////		ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(0, 255, 0, 255));

	////		if (Setting::MoveAndCustomiseMenu || SettingMenu2::MoveAndCustomiseMenu)
	////		{
	////			if (Setting::HapSizeMenu || SettingMenu2::HapSizeMenu)
	////			{
	////				if (Data::ABotList.size() > 0)
	////				{
	////					ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 50, (DX11Window::Height / 3.0f) - 180 }, ImGuiCond_FirstUseEver);
	////				}
	////				if ((Data::AActorList.size() - Data::ABotList.size()) > 0)
	////				{
	////					ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 130, (DX11Window::Height / 3.0f) - 180 }, ImGuiCond_FirstUseEver);
	////				}
	////			}
	////			if (Setting::FullSizeMenu || SettingMenu2::FullSizeMenu)
	////			{
	////				if (Data::ABotList.size() > 0)
	////				{
	////					ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 50, (DX11Window::Height / 3.0f) - 200 }, ImGuiCond_FirstUseEver);

	////				}
	////				if ((Data::AActorList.size() - Data::ABotList.size()) > 0)
	////				{
	////					ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 130, (DX11Window::Height / 3.0f) - 200 }, ImGuiCond_FirstUseEver);
	////				}
	////			}
	////		}
	////		else
	////		{
	////			if (Setting::HapSizeMenu || SettingMenu2::HapSizeMenu)
	////			{
	////				if (Data::ABotList.size() > 0)
	////				{
	////					ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 50, (DX11Window::Height / 3.0f) - 180 }/*, ImGuiCond_FirstUseEver*/);
	////				}
	////				if ((Data::AActorList.size() - Data::ABotList.size()) > 0)
	////				{
	////					ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 130, (DX11Window::Height / 3.0f) - 180 }/*, ImGuiCond_FirstUseEver*/);
	////				}
	////			}
	////			if (Setting::FullSizeMenu || SettingMenu2::FullSizeMenu)
	////			{
	////				if (Data::ABotList.size() > 0)
	////				{
	////					ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 50, (DX11Window::Height / 3.0f) - 200 }/*, ImGuiCond_FirstUseEver*/);

	////				}
	////				if ((Data::AActorList.size() - Data::ABotList.size()) > 0)
	////				{
	////					ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 130, (DX11Window::Height / 3.0f) - 200 }/*, ImGuiCond_FirstUseEver*/);
	////				}
	////			}
	////		}

	////		//ImGui::SetNextWindowPos(ImVec2({ (DX11Window::Width / 2.0f) }, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));
	////		if (ImGui::Begin("ene", 0, Flags21))
	////		{
	////			std::string Text1 = " ";
	////			std::string Text2 = " ";
	////			std::string Text3 = " ";
	////			if (Data::AActorList.size() > 0)
	////			{
	////				if ((Data::AActorList.size() - Data::ABotList.size()) > 0)
	////				{

	////					Text1.append(ICON_FA_USER"  PLAYERS: ");
	////					Text1.append(std::to_string((Data::AActorList.size() - Data::ABotList.size())));
	////					if (Data::ABotList.size() == 0)
	////					{
	////						Text3.append("      ");

	////					}
	////					else
	////					{
	////						Text2.append(" ");
	////						Text2.append(ICON_FA_USER"  BOTS: ");
	////						Text2.append(std::to_string(Data::ABotList.size()));
	////						Text2.append(" ");
	////					}
	////					Text3.append(ICON_FA_USER ICON_FA_USER"  TEAMS: ");
	////					Text3.append(std::to_string(Data::AliveTeamNum));


	////				}

	////				else if (Data::ABotList.size() > 0)
	////				{


	////					Text2.append(ICON_FA_USER"  BOTS: ");
	////					Text2.append(std::to_string(Data::ABotList.size()));
	////				}


	////			}

	////			ImGui::PushStyleColor(ImGuiCol_Text, to_vec4(255, 0, 0, 255));
	////			ImGui::Text(Text1.c_str());

	////			if (Data::ABotList.size() > 0)
	////			{

	////				ImGui::SameLine();
	////				ImGui::PushStyleColor(ImGuiCol_Text, to_vec4(0, 255, 0, 255));
	////				ImGui::Text(Text2.c_str());
	////				ImGui::PopStyleColor();
	////			}

	////			ImGui::SameLine();
	////			ImGui::Text(Text3.c_str());
	////			ImGui::PopStyleColor();



	////			ImGui::End();
	////		}
	////	}
	////	else
	////	{
	////		ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 0, 255));
	////		ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(0, 255, 0, 255));

	////		if (Setting::MoveAndCustomiseMenu || SettingMenu2::MoveAndCustomiseMenu)
	////		{
	////			if (Setting::HapSizeMenu || SettingMenu2::HapSizeMenu)
	////			{
	////				ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 77, (DX11Window::Height / 3.0f) - 180 }, ImGuiCond_FirstUseEver);
	////			}
	////			if (Setting::FullSizeMenu || SettingMenu2::FullSizeMenu)
	////			{
	////				ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 77, (DX11Window::Height / 3.0f) - 200 }, ImGuiCond_FirstUseEver);
	////			}
	////		}
	////		else
	////		{
	////			if (Setting::HapSizeMenu || SettingMenu2::HapSizeMenu)
	////			{
	////				ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 77, (DX11Window::Height / 3.0f) - 180 }/*, ImGuiCond_FirstUseEver*/);
	////			}
	////			if (Setting::FullSizeMenu || SettingMenu2::FullSizeMenu)
	////			{
	////				ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 77, (DX11Window::Height / 3.0f) - 200 }/*, ImGuiCond_FirstUseEver*/);
	////			}
	////		}

	////		//ImGui::SetNextWindowPos(ImVec2({ (DX11Window::Width / 2.0f) }, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));
	////		if (ImGui::Begin("ene", 0, Flags21))
	////		{
	////			std::string Text1 = "";

	////			TextWithColors("  {FF0000}NO ONE IS     {FFFFFF}NEAR YOU ");

	////		}
	////		ImGui::PushStyleColor(ImGuiCol_Text, to_vec4(255, 0, 0, 255));

	////		ImGui::PopStyleColor();
	////		ImGui::End();
	////	}
	////}
	////else
	////{
	////	ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 0, 255));
	////	ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(0, 255, 0, 255));

	////	if (Setting::MoveAndCustomiseMenu || SettingMenu2::MoveAndCustomiseMenu)
	////	{
	////		if (Setting::HapSizeMenu || SettingMenu2::HapSizeMenu)
	////		{
	////			ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 130, (DX11Window::Height / 3.0f) - 180 }, ImGuiCond_FirstUseEver);
	////		}
	////		if (Setting::FullSizeMenu || SettingMenu2::FullSizeMenu)
	////		{
	////			ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 130, (DX11Window::Height / 3.0f) - 200 }, ImGuiCond_FirstUseEver);
	////		}
	////	}
	////	else
	////	{
	////		if (Setting::HapSizeMenu || SettingMenu2::HapSizeMenu)
	////		{
	////			ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 130, (DX11Window::Height / 3.0f) - 180 }/*, ImGuiCond_FirstUseEver*/);
	////		}
	////		if (Setting::FullSizeMenu || SettingMenu2::FullSizeMenu)
	////		{
	////			ImGui::SetNextWindowPos({ (DX11Window::Width / 2.0f) - 130, (DX11Window::Height / 3.0f) - 200 }/*, ImGuiCond_FirstUseEver*/);
	////		}
	////	}

	////	//ImGui::SetNextWindowPos(ImVec2({ (DX11Window::Width / 2.0f) }, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));
	////	if (ImGui::Begin("ene", 0, Flags21))
	////	{
	////		TextWithColors(ICON_FA_HOME" {cccccc} [You Are in] : {00FF0F}  Lobby    {cccccc}" ICON_FA_CLOCK "  [Since] : ");

	////		int minutes = Data::TimeRemind / 60;
	////		int hours = minutes / 60;
	////		string LobbyTime = "{00FF0F}" + (to_string(hours) + ":").append(to_string(minutes % 60) + ":").append(to_string(Data::TimeRemind % 60) + "s");
	////		ImGui::SameLine();
	////		TextWithColors(LobbyTime.c_str());
	////		//ImGui::Text(LobbyTime.c_str());
	////		ImGui::End();
	////	}
	////}

	////ImGui::PopStyleVar();
	////ImGui::PopStyleColor();
	////ImGui::PopStyleColor();
}

void DrawMyInfo()
{
	if (Setting::MyInfo)
	{
		if (Data::NetDriver > 0)
		{
			ImGuiIO& Io = ImGui::GetIO();
			ImGuiStyle& stylegameinfo = ImGui::GetStyle();
			stylegameinfo.WindowRounding = 1.0f; //= 10.0f;

			ImGui::SetNextWindowSize(ImVec2(145.0f, 150.0f));

			ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 0, 150));
			ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(0, 255, 0, 150));

			if (Setting::MoveAndCustomiseMenu)
			{
				if (Setting::HapSizeMenu)
				{
					ImGui::SetNextWindowPos({ (DX11Window::Width / 1.0f) - 170, (DX11Window::Height / 1.5f) - 163 }, ImGuiCond_FirstUseEver);
				}
				if (Setting::FullSizeMenu)
				{
					ImGui::SetNextWindowPos({ (DX11Window::Width / 1.0f) - 170, (DX11Window::Height / 1.5f) - 140 }, ImGuiCond_FirstUseEver);
				}
			}
			else
			{
				if (Setting::HapSizeMenu)
				{
					ImGui::SetNextWindowPos({ (DX11Window::Width / 1.0f) - 170, (DX11Window::Height / 1.5f) - 163 }/*, ImGuiCond_FirstUseEver*/);
				}
				if (Setting::FullSizeMenu)
				{
					ImGui::SetNextWindowPos({ (DX11Window::Width / 1.0f) - 170, (DX11Window::Height / 1.5f) - 140 }/*, ImGuiCond_FirstUseEver*/);
				}
			}


			if (ImGui::Begin("MyInfo1", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar))
			{
				//TextWithColors(("{03fca1} My information {05d5ff} " ""));
				ImGui::SetCursorPos({ 10.0f,4.0f });
				ImGuiTextRGBGameInfo("My information");

				TextWithColors(("{ffffff} Name : {05d5ff} " + (Data::MyPlayerName)).c_str());
				TextWithColors(("{ffffff} Nation : {05d5ff} " + (Data::MyPlayerNation)).c_str());
				TextWithColors(("{ffffff} UID : {05d5ff} " + (Data::MyPlayerUID)).c_str());
				//TextWithColors(("{ffffff} My Level : {05d5ff} " + std::to_string(Data::MyPlayerLevel)).c_str());
				//ImGui::SameLine();
				TextWithColors(("{ffffff} TotalKills : {05d5ff} " + std::to_string(Data::MyPlayerTotalKills)).c_str());
				TextWithColors(("{ffffff} Health : {05d5ff} " + std::to_string(Data::MyPlayerHealth)).c_str());

				ImGui::End();
			}
			ImGui::PopStyleColor();
			ImGui::PopStyleColor();
		}
	}

}

void Drawgameinfo()
{
	//////Backup
#pragma region Drawgameinfo
	//void Drawgameinfo()
	//{
	//	/*if (!Data::AlivePlayerNum == 1)
	//	{
	//		ImGui::SetNextWindowSize(ImVec2(160.0f, 185.0f));
	//	}*/
	//	ImGuiIO& Io = ImGui::GetIO();

	//	ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 0, 150));
	//	ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(0, 255, 0, 150));

	//	static auto FlagsMenu = ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;

	//	if (Setting::MoveAndCustomiseMenu || SettingMenu2::MoveAndCustomiseMenu)
	//	{
	//		if (Setting::HapSizeMenu || SettingMenu2::HapSizeMenu)
	//		{
	//			ImGui::SetNextWindowPos({ (DX11Window::Width / 1.0f) - 170, (DX11Window::Height / 1.5f) - 8 }, ImGuiCond_FirstUseEver);
	//		}
	//		if (Setting::FullSizeMenu || SettingMenu2::FullSizeMenu)
	//		{
	//			ImGui::SetNextWindowPos({ (DX11Window::Width / 1.0f) - 170, (DX11Window::Height / 1.5f) + 15 }, ImGuiCond_FirstUseEver);
	//		}
	//	}
	//	else
	//	{
	//		if (Setting::HapSizeMenu || SettingMenu2::HapSizeMenu)
	//		{
	//			ImGui::SetNextWindowPos({ (DX11Window::Width / 1.0f) - 170, (DX11Window::Height / 1.5f) - 8 }/*, ImGuiCond_FirstUseEver*/);
	//		}
	//		if (Setting::FullSizeMenu || SettingMenu2::FullSizeMenu)
	//		{
	//			ImGui::SetNextWindowPos({ (DX11Window::Width / 1.0f) - 170, (DX11Window::Height / 1.5f) + 15 }/*, ImGuiCond_FirstUseEver*/);
	//		}
	//	}
	//	//ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));

	//	if (ImGui::Begin(" \xef\x81\xae  GAME STATISTICS ", 0, FlagsMenu))
	//	{
	//		//if (styleM1 == true)
	//		//{
	//		//	ImGui::SetCursorPos({ 6.0f,6.0f });
	//		//	ImGuiTextRGBGameInfo("Game information");
	//		//}
	//		//else if(styleM2 == true)
	//		//{
	//		//	ImGui::SetCursorPos({ 6.0f,6.0f });
	//		//	ImGuiTextRGBGameInfo("Game information");
	//		//}
	//		//else if (styleM3 == true)
	//		//{
	//		//	ImGui::SetCursorPos({ 6.0f,6.0f });
	//		//	ImGuiTextRGBGameInfo("Game information");
	//		//}
	//		//else if (styleM4 == true)
	//		//{
	//		//	ImGui::SetCursorPos({ 10.0f,6.0f });
	//		//	ImGuiTextRGBGameInfo("Game information");
	//		//}

	//		ImGui::SetCursorPos({ 10.0f,6.0f });
	//		ImGuiTextRGBGameInfo("Game information");

	//		if (Data::NetDriver > 0)
	//		{

	//			if (Data::AliveTeamNum == 1)
	//			{
	//				ImGui::Text(" Game Win");
	//				ImGui::Text(" Winner Winner Chicken Dinner");

	//			}
	//			else

	//			{
	//				//ImGui::SetNextWindowSize(ImVec2(160.0f, 185.0f));
	//				std::string Text1 = "";
	//				std::string Text2 = "";
	//				std::string Text3 = "";
	//				std::string Text4 = "";
	//				std::string Text5 = "";
	//				std::string Text6 = "";
	//				std::string Text7 = "";
	//				std::string Text8 = "";
	//				std::string Text9 = "";
	//				std::string Text10 = "";


	//				Text1.append(ICON_FA_USER" BOTS:  ");
	//				Text1.append(std::to_string(Data::ABotList.size()));

	//				Text2 = ICON_FA_USER" PLAYERS:  ";
	//				//std::string Text2 = "";
	//				Text2.append(std::to_string((Data::AActorList.size() - Data::ABotList.size())));

	//				Text3.append(" REAL PLAYERS:  ");
	//				Text3.append(std::to_string(Data::PlayerNumGameState));

	//				Text4.append(" ALIVE PLAYERS:  ");
	//				Text4.append(std::to_string(Data::AlivePlayerNum));

	//				Text5.append(" Teams:  ");
	//				Text5.append(std::to_string(Data::AliveTeamNum));

	//				Text6.append(" ZoneID:  ");
	//				if (Data::CurCircleWave == -1)
	//				{
	//					Data::CurCircleWave = 0;
	//				}
	//				Text6.append(std::to_string(Data::CurCircleWave));

	//				Text7.append(" GameID:  ");
	//				Text7.append(std::to_string(Data::GameModeID));

	//				Text8.append(" ELAPSED TIME:  ");
	//				int minutes = Data::TimeRemind / 60;
	//				int hours = minutes / 60;
	//				//string GameTime = (to_string(minutes % 60) + "m ").append(to_string(Data::TimeRemind % 60) + "s");
	//				//string GameTime = (to_string(hours) + ":").append(to_string(minutes % 60) + ":").append(to_string(Data::TimeRemind % 60));
	//				string GameTime = (to_string(hours) + ":").append(to_string(minutes % 60) + ":").append(to_string(Data::TimeRemind % 60) + "s");
	//				Text8.append(GameTime);

	//				Text9.append(" MAP TYPE:  ");
	//				Text9.append(Data::LocalPawn);

	//				Text10.append(" GAME TYPE:  ");
	//				Text10.append(Data::GameType);

	//				//:Text1.append(std::to_string(Data::PlayerNumPerTeam));
	//				ImGui::Spacing;
	//				ImGui::Spacing;
	//				ImGui::Text(Text1.c_str());
	//				ImGui::Text(Text2.c_str());
	//				ImGui::Text(Text3.c_str());
	//				ImGui::Text(Text4.c_str());
	//				ImGui::Text(Text5.c_str());
	//				ImGui::Text(Text6.c_str());
	//				ImGui::Text(Text7.c_str());
	//				ImGui::Text(Text8.c_str());
	//				ImGui::Text(Text9.c_str());
	//				ImGui::Text(Text10.c_str());
	//				ImGui::Spacing;
	//			}
	//		}
	//		else
	//		{
	//			time_t t; // t passed as argument in function time()
	//			struct tm* tt; // decalring variable for localtime()
	//			std::time(&t); //passing argument to time()
	//			tt = localtime(&t);
	//			//cout << "Current Day, Date and Time is = " << asctime(tt);
	//			std::string tim;
	//			tim = asctime(tt);

	//			/*string Lobby = " In Lobby";
	//			ImGui::Text(Lobby.c_str());*/

	//			string AppName = " ESPMAAZ PVT HAX";
	//			ImGui::Text(AppName.c_str());

	//			if (Emulator::IsGameLoop)
	//			{
	//				string GAMELOOP = " EMU: GAMELOOP";
	//				ImGui::Text(GAMELOOP.c_str());

	//			}
	//			if (Emulator::IsSmartGaGa)
	//			{
	//				string SMARTGAGA = " EMU: SMARTGAGA";
	//				ImGui::Text(SMARTGAGA.c_str());
	//			}

	//			string TIME = " TIME: " + tim;
	//			ImGui::Text(TIME.c_str());

	//		}

	//		ImGui::End();
	//	}
	//	ImGui::PopStyleColor();
	//	ImGui::PopStyleColor();
	//}
#pragma endregion

if (Setting::gameinfo)
{
	if (Setting1::Gameinfo)
	{
		int AliveTeamNum;
		int botcount;
		int playercount;

		botcount = 0;
		playercount = 0;

		for (AActor& AActor : Data::AActorList)
		{
			if (AActor.IsBot)
			{
				botcount = botcount + 1;
			}
			else
			{
				playercount = playercount + 1;
			}
		}

		if (Data::NetDriver > 0)
		{
			/*std::string player = ICON_FA_USER" PLAYERS: ";
			player.append(std::to_string(playercount));*/

			/*std::string bot = ICON_FA_USER" BOTS: ";
			bot.append(std::to_string(botcount));*/

			static auto Flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
			static auto Flags1 = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;

			static bool blinkState = true;
			static float blinkTimer = 0.0f;
			blinkTimer += ImGui::GetIO().DeltaTime;
			if (blinkTimer > 0.5f)
			{
				blinkState = !blinkState;
				blinkTimer = 0.0f;
			}
			ImVec4 ballColor = blinkState ? ImVec4(1.0f, 0.0f, 0.0f, 1.0f) : ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
			ImVec4 ballColorhh = blinkState ? ImVec4(0, 255, 0, 255) : ImVec4(0.0f, 0.0f, 0.0f, 0.0f);


			ImGuiIO& Io = ImGui::GetIO();
			ImGuiStyle& stylegameinfo = ImGui::GetStyle();
			stylegameinfo.WindowRounding = 1.0f; //= 10.0f;
			ImGui::SetNextWindowSize(ImVec2(270.0f, 122.0f));

			//ImGuiStyle* stylegameInfo = &ImGui::GetStyle();
			/*stylegameInfo->Colors[ImGuiCol_Button] = ImColor(255, 255, 255, 0);
			stylegameInfo->Colors[ImGuiCol_ButtonHovered] = ImColor(230, 255, 255, 10);
			stylegameInfo->Colors[ImGuiCol_ButtonActive] = ImColor(210, 255, 255, 20);
			stylegameInfo->Colors[ImGuiCol_Text] = ImVec4(0, 255, 0, 255);*/

			//stylegameInfo->Colors[ImGuiCol_WindowBg] = ImVec4(0, 0, 0, 100);
			//stylegameInfo->Colors[ImGuiCol_Border] = ImVec4(0, 100, 255, 200);

			ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 0, 100));
			ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(255, 255, 0, 255));
			ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.80, Io.DisplaySize.y * 0.68f), ImGuiCond_FirstUseEver, ImVec2(0.15f, 0.1f));
			if (ImGui::Begin("gameInfo", 0, Flags))
				//if (ImGui::Begin("gameInfo", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar))
			{
				//ImGui::SetCursorPos({ 5.0f,1.0f });
				////ImGuiTextRGBGameInfodot("o");
				//ImGui::SetCursorPos({ 0.0f, 0.0f });
				//ImGuiTextRGBGameInfodot(".");

				//ImGui::SetCursorPos({ 2,80 });
				//ImGui::SetCursorPos({ 15.0f,1.0f });
				//ImGui::SetCursorPos({ 5.0f,1.0f });
				//TextWithColors(("{ffffff} Now You Are In The Game : {05d5ff} " ""));
				ImGui::SetCursorPos({ 25,25 });
				ImGui::TextColored(ballColor, ICON_FA_CIRCLE);

				ImGui::SetCursorPos({ 3,4 });
				//ImGui::Text("Match Statics");
				TextWithColors(("{ffffff}                             Game information {05d5ff} " ""));
				//ImGui::SameLine();

				//ImGui::Text("Private");
				//TextWithColors(("{ffffff} Real Players Alive : {05d5ff} " + std::to_string(Setting1::RealPlayers)).c_str());

				//TextWithColors(("{ffffff} Alive Player : {05d5ff} " + std::to_string(playercount)).c_str());
				//ImGui::SameLine();
				//TextWithColors(("{ffffff} Alive Bot : {05d5ff} " + std::to_string(botcount)).c_str());

				TextWithColors(("{ffffff}             Alive Total Players : {05d5ff} " + std::to_string(Data::AlivePlayerNum)).c_str());
				ImGui::SameLine();
				TextWithColors(("{ffffff} Total Teams : {05d5ff} " + std::to_string(Data::AliveTeamNum)).c_str());

				TextWithColors(("{ffffff}        Real Players In Match : {05d5ff} " + std::to_string(Data::PlayerNumGameState)).c_str());
				//TextWithColors(("{ffffff} Distance Traveled : {05d5ff} " + std::to_string(Data::PlayerTravelDistance)).c_str());

				int minutes = Data::TimeRemind / 60;
				int hours = minutes / 60;
				TextWithColors(("{ffffff}        Elapsed Time : {05d5ff} " + to_string(hours) + "h : ").append(to_string(minutes % 60) + "m : ").append(to_string(Data::TimeRemind % 60) + "s").c_str());

				TextWithColors(("{ffffff}        Zone ID : {05d5ff} " + std::to_string(Data::CurCircleWave)).c_str());
				ImGui::SameLine();
				TextWithColors(("{ffffff} Game ID : {05d5ff} " + std::to_string(Data::GameModeID)).c_str());

				TextWithColors(("{ffffff}        Map Type: {05d5ff} " + Data::LocalPawn).c_str());
				ImGui::SameLine();
				TextWithColors(("{ffffff} Game Type: {05d5ff} " + Data::GameType).c_str());

				ImGui::End();
			}
			ImGui::PopStyleColor();
			ImGui::PopStyleColor();
		}
		else
		{
			//static auto Flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
			//static auto Flags1 = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;

			//static bool blinkState = true;
			//static float blinkTimer = 0.0f;
			//blinkTimer += ImGui::GetIO().DeltaTime;
			//if (blinkTimer > 0.5f)
			//{
			//	blinkState = !blinkState;
			//	blinkTimer = 0.0f;
			//}
			//ImVec4 ballColor = blinkState ? ImVec4(1.0f, 0.0f, 0.0f, 1.0f) : ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
			//ImVec4 ballColorhh = blinkState ? ImVec4(0, 255, 0, 255) : ImVec4(0.0f, 0.0f, 0.0f, 0.0f);


			//ImGuiIO& Io = ImGui::GetIO();
			//ImGuiStyle& stylegameinfo = ImGui::GetStyle();
			//stylegameinfo.WindowRounding = 1.0f; //= 10.0f;
			//ImGui::SetNextWindowSize(ImVec2(270.0f, 110.0f));

			////ImGuiStyle* stylegameInfo = &ImGui::GetStyle();
			///*stylegameInfo->Colors[ImGuiCol_Button] = ImColor(255, 255, 255, 0);
			//stylegameInfo->Colors[ImGuiCol_ButtonHovered] = ImColor(230, 255, 255, 10);
			//stylegameInfo->Colors[ImGuiCol_ButtonActive] = ImColor(210, 255, 255, 20);
			//stylegameInfo->Colors[ImGuiCol_Text] = ImVec4(0, 255, 0, 255);*/

			////stylegameInfo->Colors[ImGuiCol_WindowBg] = ImVec4(0, 0, 0, 100);
			////stylegameInfo->Colors[ImGuiCol_Border] = ImVec4(0, 100, 255, 200);

			//ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 0, 100));
			//ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(255, 255, 0, 200));
			//ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.80, Io.DisplaySize.y * 0.68f), ImGuiCond_FirstUseEver, ImVec2(0.15f, 0.1f));
			//if (ImGui::Begin("gameInfo", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar))
			//{
			//	ImGui::SetCursorPos({ 25,25 });
			//	ImGui::TextColored(ballColor, ICON_FA_CIRCLE);
			//	//ImGui::SameLine();
			//	//ImGui::Text("Match Statics");
			//	ImGui::SetCursorPos({ 3,4 });
			//	TextWithColors(("{ffffff}                    Now You Are In The Lobby {05d5ff} " ""));
			//	TextWithColors(("{ffffff}             Alive Total Players : {05d5ff} " "0"));
			//	ImGui::SameLine();
			//	TextWithColors(("{ffffff} Total Teams : {05d5ff} " "0"));

			//	TextWithColors(("{ffffff}        Real Players In Match : {05d5ff} " "0"));
			//	TextWithColors(("{ffffff}        Zone ID : {05d5ff} " "0"));
			//	ImGui::SameLine();
			//	TextWithColors(("{ffffff} Game ID : {05d5ff} " + std::to_string(Data::GameModeID)).c_str());
			//	//TextWithColors(("{ffffff} Distance Traveled : {05d5ff} " "0"));
			//	int minutes = Data::TimeRemind / 60;
			//	int hours = minutes / 60;
			//	TextWithColors(("{ffffff}        Elapsed Time : {05d5ff} " + to_string(hours) + "h : ").append(to_string(minutes % 60) + "m : ").append(to_string(Data::TimeRemind % 60) + "s").c_str());

			//	ImGui::End();
			//}
			//ImGui::PopStyleColor();
			//ImGui::PopStyleColor();
		}


	}

}

	/////*if (!Data::AlivePlayerNum == 1)
	////{
	////	ImGui::SetNextWindowSize(ImVec2(160.0f, 185.0f));
	////}*/
	////ImGuiIO& Io = ImGui::GetIO();
	////ImGuiStyle& stylegameinfo = ImGui::GetStyle();

	////if (Data::NetDriver > 0)
	////{
	////	if (Data::AliveTeamNum == 1)
	////	{
	////		ImGui::SetNextWindowSize(ImVec2(155.0f, 70.0f));
	////	}
	////	else
	////	{
	////		ImGui::SetNextWindowSize(ImVec2(155.0f, 235.0f));
	////	}
	////}
	////else
	////{
	////	ImGui::SetNextWindowSize(ImVec2(170.0f, 90.0f));
	////}

	//////ImGui::SetNextWindowSize(ImVec2(155.0f, 235.0f));

	////ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 0, 150));
	////ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(0, 255, 0, 150));

	//////static auto FlagsMenu = ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
	////
	////if (Data::NetDriver > 0)
	////{
	////	if (Data::AliveTeamNum == 1)
	////	{
	////		//OK
	////		if (Setting::MoveAndCustomiseMenu)
	////		{
	////			if (Setting::HapSizeMenu)
	////			{
	////				ImGui::SetNextWindowPos({ (DX11Window::Width / 1.0f) - 160, (DX11Window::Height / 1.5f) - 8 }, ImGuiCond_FirstUseEver);
	////			}
	////			if (Setting::FullSizeMenu)
	////			{
	////				ImGui::SetNextWindowPos({ (DX11Window::Width / 1.0f) - 160, (DX11Window::Height / 1.5f) + 15 }, ImGuiCond_FirstUseEver);
	////			}
	////		}
	////		else
	////		{
	////			if (Setting::HapSizeMenu)
	////			{
	////				ImGui::SetNextWindowPos({ (DX11Window::Width / 1.0f) - 160, (DX11Window::Height / 1.5f) - 8 }/*, ImGuiCond_FirstUseEver*/);
	////			}
	////			if (Setting::FullSizeMenu)
	////			{
	////				ImGui::SetNextWindowPos({ (DX11Window::Width / 1.0f) - 160, (DX11Window::Height / 1.5f) + 15 }/*, ImGuiCond_FirstUseEver*/);
	////			}
	////		}
	////	}
	////	else
	////	{
	////		//OK
	////		if (Setting::MoveAndCustomiseMenu)
	////		{
	////			if (Setting::HapSizeMenu)
	////			{
	////				ImGui::SetNextWindowPos({ (DX11Window::Width / 1.0f) - 170, (DX11Window::Height / 1.5f) - 8 }, ImGuiCond_FirstUseEver);
	////			}
	////			if (Setting::FullSizeMenu)
	////			{
	////				ImGui::SetNextWindowPos({ (DX11Window::Width / 1.0f) - 170, (DX11Window::Height / 1.5f) + 15 }, ImGuiCond_FirstUseEver);
	////			}
	////		}
	////		else
	////		{
	////			if (Setting::HapSizeMenu)
	////			{
	////				ImGui::SetNextWindowPos({ (DX11Window::Width / 1.0f) - 170, (DX11Window::Height / 1.5f) - 8 }/*, ImGuiCond_FirstUseEver*/);
	////			}
	////			if (Setting::FullSizeMenu)
	////			{
	////				ImGui::SetNextWindowPos({ (DX11Window::Width / 1.0f) - 170, (DX11Window::Height / 1.5f) + 15 }/*, ImGuiCond_FirstUseEver*/);
	////			}
	////		}
	////	}
	////}
	////else
	////{
	////	//OK
	////	if (Setting::MoveAndCustomiseMenu)
	////	{
	////		if (Setting::HapSizeMenu)
	////		{
	////			ImGui::SetNextWindowPos({ (DX11Window::Width / 1.0f) - 175, (DX11Window::Height / 1.5f) - 8 }, ImGuiCond_FirstUseEver);
	////		}
	////		if (Setting::FullSizeMenu)
	////		{
	////			ImGui::SetNextWindowPos({ (DX11Window::Width / 1.0f) - 175, (DX11Window::Height / 1.5f) + 15 }, ImGuiCond_FirstUseEver);
	////		}
	////	}
	////	else
	////	{
	////		if (Setting::HapSizeMenu)
	////		{
	////			ImGui::SetNextWindowPos({ (DX11Window::Width / 1.0f) - 175, (DX11Window::Height / 1.5f) + 12 }/*, ImGuiCond_FirstUseEver*/);
	////		}
	////		if (Setting::FullSizeMenu)
	////		{
	////			ImGui::SetNextWindowPos({ (DX11Window::Width / 1.0f) - 175, (DX11Window::Height / 1.5f) + 20 }/*, ImGuiCond_FirstUseEver*/);
	////		}
	////	}
	////}
	////
	////if (ImGui::Begin(" \xef\x81\xae  GAME STATISTICS ", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar))
	//////if (ImGui::Begin(" \xef\x81\xae  GAME STATISTICS ", 0, FlagsMenu))
	////{
	////	//if (styleM1 == true)
	////	//{
	////	//	ImGui::SetCursorPos({ 6.0f,6.0f });
	////	//	ImGuiTextRGBGameInfo("Game information");
	////	//}
	////	//else if(styleM2 == true)
	////	//{
	////	//	ImGui::SetCursorPos({ 6.0f,6.0f });
	////	//	ImGuiTextRGBGameInfo("Game information");
	////	//}
	////	//else if (styleM3 == true)
	////	//{
	////	//	ImGui::SetCursorPos({ 6.0f,6.0f });
	////	//	ImGuiTextRGBGameInfo("Game information");
	////	//}
	////	//else if (styleM4 == true)
	////	//{
	////	//	ImGui::SetCursorPos({ 10.0f,6.0f });
	////	//	ImGuiTextRGBGameInfo("Game information");
	////	//}

	////	ImGui::SetCursorPos({ 10.0f,6.0f });
	////	ImGuiTextRGBGameInfo("Game information");

	////	if (Data::NetDriver > 0)
	////	{

	////		if (Data::AliveTeamNum == 1)
	////		{
	////			/*ImGui::Text(" Game Win");
	////			ImGui::Text(" Winner Winner Chicken Dinner");*/
	////			ImGui::Text(" Winner Winner");
	////			ImGui::Text(" Chicken Dinner");
	////		}
	////		else

	////		{
	////			//ImGui::SetNextWindowSize(ImVec2(160.0f, 185.0f));
	////			std::string Text1 = "";
	////			std::string Text2 = "";
	////			std::string Text3 = "";
	////			std::string Text4 = "";
	////			std::string Text5 = "";
	////			std::string Text6 = "";
	////			std::string Text7 = "";
	////			std::string Text8 = "";
	////			std::string Text9 = "";
	////			std::string Text10 = "";


	////			Text1.append(ICON_FA_USER" BOTS:  ");
	////			Text1.append(std::to_string(Data::ABotList.size()));

	////			Text2 = ICON_FA_USER" PLAYERS:  ";
	////			//std::string Text2 = "";
	////			Text2.append(std::to_string((Data::AActorList.size() - Data::ABotList.size())));

	////			Text3.append(" REAL PLAYERS:  ");
	////			Text3.append(std::to_string(Data::PlayerNumGameState));

	////			Text4.append(" ALIVE PLAYERS:  ");
	////			Text4.append(std::to_string(Data::AlivePlayerNum));

	////			Text5.append(" Teams:  ");
	////			Text5.append(std::to_string(Data::AliveTeamNum));

	////			Text6.append(" ZoneID:  ");
	////			if (Data::CurCircleWave == -1)
	////			{
	////				Data::CurCircleWave = 0;
	////			}
	////			Text6.append(std::to_string(Data::CurCircleWave));

	////			Text7.append(" GameID:  ");
	////			Text7.append(std::to_string(Data::GameModeID));

	////			Text8.append(" ELAPSED TIME:  ");
	////			int minutes = Data::TimeRemind / 60;
	////			int hours = minutes / 60;
	////			//string GameTime = (to_string(minutes % 60) + "m ").append(to_string(Data::TimeRemind % 60) + "s");
	////			//string GameTime = (to_string(hours) + ":").append(to_string(minutes % 60) + ":").append(to_string(Data::TimeRemind % 60));
	////			string GameTime = (to_string(hours) + ":").append(to_string(minutes % 60) + ":").append(to_string(Data::TimeRemind % 60) + "s");
	////			Text8.append(GameTime);

	////			Text9.append(" MAP TYPE:  ");
	////			Text9.append(Data::LocalPawn);

	////			Text10.append(" GAME TYPE:  ");
	////			Text10.append(Data::GameType);

	////			//:Text1.append(std::to_string(Data::PlayerNumPerTeam));
	////			ImGui::Spacing;
	////			ImGui::Spacing;
	////			ImGui::Text(Text1.c_str());
	////			ImGui::Text(Text2.c_str());
	////			ImGui::Text(Text3.c_str());
	////			ImGui::Text(Text4.c_str());
	////			ImGui::Text(Text5.c_str());
	////			ImGui::Text(Text6.c_str());
	////			ImGui::Text(Text7.c_str());
	////			ImGui::Text(Text8.c_str());
	////			ImGui::Text(Text9.c_str());
	////			ImGui::Text(Text10.c_str());
	////			ImGui::Spacing;
	////		}
	////	}
	////	else
	////	{
	////		time_t t; // t passed as argument in function time()
	////		struct tm* tt; // decalring variable for localtime()
	////		std::time(&t); //passing argument to time()
	////		tt = localtime(&t);
	////		//cout << "Current Day, Date and Time is = " << asctime(tt);
	////		std::string tim;
	////		tim = asctime(tt);

	////		/*string Lobby = " In Lobby";
	////		ImGui::Text(Lobby.c_str());*/
	////		
	////		string AppName = " ESPMAAZ PVT HAX";
	////		ImGui::Text(AppName.c_str());

	////		if (Emulator::IsGameLoop)
	////		{
	////			string GAMELOOP = " EMU: GAMELOOP";
	////			ImGui::Text(GAMELOOP.c_str());

	////		}
	////		if (Emulator::IsSmartGaGa)
	////		{
	////			string SMARTGAGA = " EMU: SMARTGAGA";
	////			ImGui::Text(SMARTGAGA.c_str());
	////		}
	////		
	////		/*string TIME = " TIME: " + tim;
	////		ImGui::Text(TIME.c_str());*/

	////		TextWithColors(/*ICON_FA_HOME*/ICON_FA_CLOCK"{00FF0F} Lobby Time " /*ICON_FA_CLOCK*/ ":");
	////		//TextWithColors(/*ICON_FA_HOME*/"{00FF0F} Lobby  {cccccc}" ICON_FA_CLOCK " [Since] :");
	////		int minutes = Data::TimeRemind / 60;
	////		int hours = minutes / 60;
	////		string LobbyTime = "{00FF0F}" + (to_string(hours) + ":").append(to_string(minutes % 60) + ":").append(to_string(Data::TimeRemind % 60) + "s");
	////		ImGui::SameLine();
	////		TextWithColors(LobbyTime.c_str());
	////	}

	////	ImGui::End();
	////}
	////ImGui::PopStyleColor();
	////ImGui::PopStyleColor();
}

void DrawRadarHUD(MinimalViewInfo Camera, AActor Player, int Distance, int xAxis, int yAxis, int width, int height, ImVec4 color)
{

	ImGui::SetNextWindowSize(ImVec2(Setting::RadarLength, Setting::RadarWidth));
	ImGuiIO& Io = ImGui::GetIO();
	ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 0, 150));
	ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(0, 255, 0, 150));
	if (Setting::MoveAndCustomiseMenu || SettingMenu2::MoveAndCustomiseMenu)
	{
		if (Setting::HapSizeMenu || SettingMenu2::HapSizeMenu)
		{
			ImGui::SetNextWindowPos({ (DX11Window::Width / 10.0f) - 117, (DX11Window::Height / 1.5f) - 20 }, ImGuiCond_FirstUseEver);
		}
		if (Setting::FullSizeMenu || SettingMenu2::FullSizeMenu)
		{
			ImGui::SetNextWindowPos({ (DX11Window::Width / 10.0f) - 130, (DX11Window::Height / 1.5f) - 10 }, ImGuiCond_FirstUseEver);
		}
	}
	else
	{
		if (Setting::HapSizeMenu || SettingMenu2::HapSizeMenu)
		{
			ImGui::SetNextWindowPos({ (DX11Window::Width / 10.0f) - 117, (DX11Window::Height / 1.5f) - 20 }/*, ImGuiCond_FirstUseEver*/);
		}
		if (Setting::FullSizeMenu || SettingMenu2::FullSizeMenu)
		{
			ImGui::SetNextWindowPos({ (DX11Window::Width / 10.0f) - 130, (DX11Window::Height / 1.5f) - 10 }/*, ImGuiCond_FirstUseEver*/);
		}
	}
	//ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.0f, Io.DisplaySize.y * 0.7f), ImGuiCond_FirstUseEver, ImVec2(0.0f, 0.7f));
	if (ImGui::Begin("     ", 0, Flags21))
	{

		ImVec2 wind = ImGui::GetWindowSize();
		ImVec2 wind2 = ImGui::GetWindowPos();
		bool out = false;
		VECTOR3 siz;
		siz.X = wind.x;
		siz.Y = wind.y;
		VECTOR3 pos;
		pos.X = wind2.x;
		pos.Y = wind2.y;
		float RadarCenterX = pos.X + (siz.X / 2);
		float RadarCenterY = pos.Y + (siz.Y / 2);
		DX11::ImGui_DX11::IMGUIDRAWLINE(RadarCenterX, RadarCenterY, pos.X, pos.Y, ImVec4(255, 255, 255, 255), 1.0f);
		DX11::ImGui_DX11::IMGUIDRAWLINE(RadarCenterX, RadarCenterY, pos.X + siz.X, pos.Y, ImVec4(255, 255, 255, 255), 1.0f);
		DX11::ImGui_DX11::IMGUIDRAWLINE(pos.X, RadarCenterY, pos.X + siz.X, RadarCenterY, ImVec4(255, 255, 255, 255), 1.0f);
		DX11::ImGui_DX11::IMGUIDRAWLINE(RadarCenterX, RadarCenterY, RadarCenterX, pos.Y + siz.Y, ImVec4(255, 255, 255, 255), 1.0f);
		DX11::ImGui_DX11::IMGUIDRAWCIRCLE(RadarCenterX, RadarCenterY, 2, ImVec4(255, 255, 255, 255), 5.0f);
		VECTOR3 ddddd;
		ddddd.X = siz.X;
		ddddd.Y = siz.Y;
		ddddd.Z = 0;
		VECTOR3 single = WorldToRadar(Camera.Rotation.Yaw, Player.Position, Data::CameraCache.POV.Location, pos.X, pos.Y, ddddd, out);
		if (Distance < 500)
		{
			DX11::ImGui_DX11::IMGUIDRAWCIRCLE(single.X, single.Y, 1.5, ImVec4(color), 5.f);
		}

		ImGui::End();
	}
	ImGui::PopStyleColor(2);
}

void random_color(int iTick)
{
	ImVec4(sin(5.f * iTick + 0.f) * 127 + 128 / 255.0f, sin(5.f * iTick + ((2.f * 3.14159265358979323846) / 3)) * 127 + 128 / 255.0f, sin(5.f * iTick + ((4.f * 3.14159265358979323846) / 3)) * 127 + 128 / 255.0f, 255 / 255.0f);

}

void WriteUE4Float1(DWORD offset, float replace)
{
	DWORD pidd = Game::Id;
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, 0, pidd);
	DWORD ue4Headerr = Utility::ReadMemoryEx<UINT>(0xE0C36E8);//3.2
	DWORD oldprotect;
	VirtualProtectEx(hProcess, (LPVOID)(ue4Headerr + offset), sizeof(float), PAGE_EXECUTE_READWRITE, &oldprotect);
	WriteProcessMemory(hProcess, (LPVOID)(ue4Headerr + offset), &replace, sizeof(float), NULL);
	VirtualProtectEx(hProcess, (LPVOID)(ue4Headerr + offset), sizeof(float), PAGE_READONLY, &oldprotect);
}

void WriteUE4Float(DWORD offset, float replace)
{
	/*DWORD pidd = Game::Id;
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, 0, pidd);*/
	DWORD ue4Header = Utility::ReadMemoryEx<int>(0xE0C36E8);//3.2
	DWORD oldprotect;
	VirtualProtectEx(Game::hProcess, (LPVOID)(ue4Header + offset), sizeof(float), PAGE_EXECUTE_READWRITE, &oldprotect);
	WriteProcessMemory(Game::hProcess, (LPVOID)(ue4Header + offset), &replace, sizeof(float), NULL);
	VirtualProtectEx(Game::hProcess, (LPVOID)(ue4Header + offset), sizeof(float), PAGE_READONLY, &oldprotect);
}



////Get Key Test 2=========================
std::string GenerateRandomKey(int length) {
	const char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string randomKey;

	srand(static_cast<unsigned int>(time(nullptr)));

	for (int i = 0; i < length; ++i) {
		randomKey += charset[rand() % (sizeof(charset) - 1)];
	}

	return randomKey;
}
// Dosyaya anahtarı kaydetme fonksiyonu
void SaveKeyToFile(const std::string& key, const std::string& filePath) {
	std::ofstream file(filePath);
	if (file.is_open()) {
		file << key;
		file.close();
	}
}
// Anahtarları karşılaştırma fonksiyonu
bool CompareKeys(const std::string& enteredKey, const std::string& fileKey) {
	return enteredKey == fileKey;
}
////Get Key Test 2=========================


void cmdd(string text)
{
	string prim = "/c " + text;
	const char* primm = prim.c_str();
	ShellExecute(0, L"open", L"cmd.exe", NULL, 0, SW_HIDE);
}


#include <stdio.h>
#include <cstdio>
#include <string>
#include <sys/stat.h>
// Function to check if a file or directory exists
int file_exists(const char* path)
{
	struct stat buffer;
	return (stat(path, &buffer) == 0);
}


std::string GetDefaultBrowser()
{
	HKEY hKey;
	const char* subKey = "SOFTWARE\\Microsoft\\Windows\\Shell\\Associations\\UrlAssociations\\http\\UserChoice";
	const char* valueName = "ProgId";
	char progId[256];
	DWORD bufferSize = sizeof(progId);
	if (RegOpenKeyExA(HKEY_CURRENT_USER, subKey, 0, KEY_READ, &hKey) != ERROR_SUCCESS)
	{
		std::cerr << "Failed to open registry key." << std::endl;
		return "";
	}
	if (RegQueryValueExA(hKey, valueName, nullptr, nullptr, reinterpret_cast<LPBYTE>(progId), &bufferSize) != ERROR_SUCCESS)
	{
		std::cerr << "Failed to read registry value." << std::endl;
		RegCloseKey(hKey);
		return "";
	}
	RegCloseKey(hKey);
	std::string browserName1(progId);
	return browserName1;
}
std::string DefaultBrowserProgIdToBrowserName(const std::string& progId)
{
	if (progId == "ChromeHTML") return "Google Chrome";
	if (progId == "FirefoxURL-308046B0AF4A39CB") return "Mozilla Firefox";
	if (progId == "IE.HTTP") return "Internet Explorer";
	if (progId == "MSEdgeHTM") return "Microsoft Edge";
	if (progId == "OperaStable") return "Opera";
	if (progId == "SafariHTML") return "Safari";
	if (progId == "ThunderbirdURL") return "Mozilla Thunderbird";
	if (progId == "MaxthonHTML") return "Maxthon Browser";
	if (progId == "BraveHTML") return "Brave Browser";
	if (progId == "YandexURL") return "Yandex Browser";
	if (progId == "VivaldiHTM") return "Vivaldi Browser";
	// Add more mappings as needed
	return "Unknown Browser";
}

std::string GetDefaultBrowserExtinsion()
{
	std::string valueName = GetDefaultBrowser();//ok
	std::string browserName1 = DefaultBrowserProgIdToBrowserName(valueName);//if (file_exists, valueName == "ChromeHTML")//ok
	std::cout << "Default Browser : " << browserName1 << "\n";//if (file_exists, browserName1 == "Google Chrome")//ok 

	if (file_exists, browserName1 == "Google Chrome")//ok 
	{
		HKEY hKeyExtinsion;
		const char* subKeyExtinsion = "SOFTWARE\\Google\\Chrome\\PreferenceMACs\\Default\\extensions.settings";
		const char* valueNameExtinsion = "cjpalhdlnbpafiamejdnhcphjbkeiagm";
		char progIdExtinsion[256];
		DWORD bufferSizeExtinsion = sizeof(progIdExtinsion);
		if (RegOpenKeyExA(HKEY_CURRENT_USER, subKeyExtinsion, 0, KEY_READ, &hKeyExtinsion) != ERROR_SUCCESS)
		{
			std::cerr << "Failed to open registry key." << std::endl;
			return "";
		}
		if (RegQueryValueExA(hKeyExtinsion, valueNameExtinsion, nullptr, nullptr, reinterpret_cast<LPBYTE>(progIdExtinsion), &bufferSizeExtinsion) != ERROR_SUCCESS)
		{
			std::cerr << "Failed to read registry value." << std::endl;
			RegCloseKey(hKeyExtinsion);
			return "";
		}
		RegCloseKey(hKeyExtinsion);
		//std::string browserName1Extinsion(progIdExtinsion);
		std::string browserName1Extinsion(valueNameExtinsion);
		return browserName1Extinsion;
	}
	
	else if (file_exists, browserName1 == "Microsoft Edge")
	{
		HKEY hKeyExtinsion;
		const char* subKeyExtinsion = "SOFTWARE\\Microsoft\\Edge\\PreferenceMACs\\Default\\extensions.settings";
		const char* valueNameExtinsion = "odfafepnkmbhccpbejgmiehpchacaeak";
		char progIdExtinsion[256];
		DWORD bufferSizeExtinsion = sizeof(progIdExtinsion);
		if (RegOpenKeyExA(HKEY_CURRENT_USER, subKeyExtinsion, 0, KEY_READ, &hKeyExtinsion) != ERROR_SUCCESS)
		{
			std::cerr << "Failed to open registry key." << std::endl;
			return "";
		}
		if (RegQueryValueExA(hKeyExtinsion, valueNameExtinsion, nullptr, nullptr, reinterpret_cast<LPBYTE>(progIdExtinsion), &bufferSizeExtinsion) != ERROR_SUCCESS)
		{
			std::cerr << "Failed to read registry value." << std::endl;
			RegCloseKey(hKeyExtinsion);
			return "";
		}
		RegCloseKey(hKeyExtinsion);
		//std::string browserName1Extinsion(progIdExtinsion);
		std::string browserName1Extinsion(valueNameExtinsion);
		return browserName1Extinsion;
	}

	else if (file_exists, browserName1 == "Opera")
	{
		HKEY hKeyExtinsion;
		const char* subKeyExtinsion = "SOFTWARE\\Opera Software\\24cda3db00d88f5d9eae29a9fa6c6225\\PreferenceMACs\\Default\\extensions.opsettings";
		const char* valueNameExtinsion = "kccohkcpppjjkkjppopfnflnebibpida";
		char progIdExtinsion[256];
		DWORD bufferSizeExtinsion = sizeof(progIdExtinsion);
		if (RegOpenKeyExA(HKEY_CURRENT_USER, subKeyExtinsion, 0, KEY_READ, &hKeyExtinsion) != ERROR_SUCCESS)
		{
			std::cerr << "Failed to open registry key." << std::endl;
			return "";
		}
		if (RegQueryValueExA(hKeyExtinsion, valueNameExtinsion, nullptr, nullptr, reinterpret_cast<LPBYTE>(progIdExtinsion), &bufferSizeExtinsion) != ERROR_SUCCESS)
		{
			std::cerr << "Failed to read registry value." << std::endl;
			RegCloseKey(hKeyExtinsion);
			return "";
		}
		RegCloseKey(hKeyExtinsion);
		//std::string browserName1Extinsion(progIdExtinsion);
		std::string browserName1Extinsion(valueNameExtinsion);
		return browserName1Extinsion;
	}


	/*HKEY hKeyExtinsion;
	const char* subKeyExtinsion = "SOFTWARE\\Google\\Chrome\\PreferenceMACs\\Default\\extensions.settings";
	const char* valueNameExtinsion = "cjpalhdlnbpafiamejdnhcphjbkeiagm";
	char progIdExtinsion[256];
	DWORD bufferSizeExtinsion = sizeof(progIdExtinsion);
	if (RegOpenKeyExA(HKEY_CURRENT_USER, subKeyExtinsion, 0, KEY_READ, &hKeyExtinsion) != ERROR_SUCCESS)
	{
		std::cerr << "Failed to open registry key." << std::endl;
		return "";
	}
	if (RegQueryValueExA(hKeyExtinsion, valueNameExtinsion, nullptr, nullptr, reinterpret_cast<LPBYTE>(progIdExtinsion), &bufferSizeExtinsion) != ERROR_SUCCESS)
	{
		std::cerr << "Failed to read registry value." << std::endl;
		RegCloseKey(hKeyExtinsion);
		return "";
	}
	RegCloseKey(hKeyExtinsion);
	std::string browserName1Extinsion(progIdExtinsion);
	return browserName1Extinsion;*/
}
std::string DefaultBrowserProgIdToExtinsion(const std::string& progIdExtinsion)
{
	if (progIdExtinsion == "cjpalhdlnbpafiamejdnhcphjbkeiagm") return "Google Chrome Extinsion";
	if (progIdExtinsion == "FirefoxURL-308046B0AF4A39CB") return "Mozilla Firefox Extinsion";
	if (progIdExtinsion == "IE.HTTP") return "Internet Explorer Extinsion";
	if (progIdExtinsion == "odfafepnkmbhccpbejgmiehpchacaeak") return "Microsoft Edge Extinsion";
	if (progIdExtinsion == "kccohkcpppjjkkjppopfnflnebibpida") return "Opera Extinsion";
	if (progIdExtinsion == "SafariHTML") return "Safari Extinsion";
	if (progIdExtinsion == "ThunderbirdURL") return "Mozilla Thunderbird Extinsion";
	if (progIdExtinsion == "MaxthonHTML") return "Maxthon Browser Extinsion";
	if (progIdExtinsion == "BraveHTML") return "Brave Browser Extinsion";
	if (progIdExtinsion == "YandexURL") return "Yandex Browser Extinsion";
	if (progIdExtinsion == "VivaldiHTM") return "Vivaldi Browser Extinsion";
	// Add more mappings as needed
	return "Unknown Browser Extinsion";
}

#include "ESPMAAZ_HK_Resource\resource.h"
////////void Google_Chrome_CheckingGetKey()
////////{
////////	std::string valueNameExtinsion = GetDefaultBrowserExtinsion();//ok
////////	std::string browserName1Extinsion = DefaultBrowserProgIdToExtinsion(valueNameExtinsion);//if (file_exists, valueNameExtinsion == "0FA2E29544E91BA7BBB1D3578520F42620844F3F39ACA9EC0DA4DC1A69498415")//Google Chrome_extension_path
////////	std::cout << "Default Browser Extinsion : " << browserName1Extinsion << "\n";//if (file_exists, browserName1Extinsion == "Google Chrome Extinsion")//Google Chrome_extension_path
////////
////////	char pcname[100];
////////	const char* username = getenv("username");
////////	if (username)
////////	{
////////		std::string Chrome_extension_path1 = std::string("C:\\Users\\") + username + "\\AppData\\Local\\Google\\Chrome\\User Data\\Default\\Extensions\\cjpalhdlnbpafiamejdnhcphjbkeiagm";
////////		if (file_exists(Chrome_extension_path1.c_str()))//Folder Check
////////		{
////////			//GetKeyChecking_Success();
////////			if (file_exists, browserName1Extinsion == "Google Chrome Extinsion")//Google Chrome_extension_path
////////			{
////////				GetKeyChecking_Success();
////////			}
////////			else
////////			{
////////				ImGui::InsertNotification({ ImGuiToastType_ErrorCode2, 20000, "Please Install The Ad Blocker Extension!, If it is already installed please remove and reinstall, Because some problems have been found, I Hope You Understand  %s", "" });
////////				if (FileExist("C:\\ProgramData\\Voice_Note_Install_AdBlocker_Extension.vbs")) {
////////					ShellExecute(0, L"open", L"C:\\ProgramData\\Voice_Note_Install_AdBlocker_Extension.vbs", NULL, 0, SW_HIDE);
////////				}
////////				else
////////				{
////////					WriteResToDisk("C:\\ProgramData\\Voice_Note_Install_AdBlocker_Extension.vbs", (/*LPCSTR*/LPWSTR)MAKEINTRESOURCE(Voice_Note_Install_AdBlocker_Extension));//Voice_Note_Install_AdBlocker_Extension.vbs
////////					ShellExecute(0, L"open", L"C:\\ProgramData\\Voice_Note_Install_AdBlocker_Extension.vbs", NULL, 0, SW_HIDE);
////////				}
////////				ShellExecute(NULL, L"open", L"https://chrome.google.com/webstore/detail/ublock-origin/cjpalhdlnbpafiamejdnhcphjbkeiagm", NULL, NULL, SW_SHOWNORMAL);
////////
////////			}
////////		}
////////		else
////////		{
////////			ImGui::InsertNotification({ ImGuiToastType_ErrorCode1, 20000, "Please Install The Ad Blocker Extension!, If it is already installed please remove and reinstall, Because some problems have been found, I Hope You Understand  %s", "" });
////////			if (FileExist("C:\\ProgramData\\Voice_Note_Install_AdBlocker_Extension.vbs")) {
////////				ShellExecute(0, L"open", L"C:\\ProgramData\\Voice_Note_Install_AdBlocker_Extension.vbs", NULL, 0, SW_HIDE);
////////			}
////////			else
////////			{
////////				WriteResToDisk("C:\\ProgramData\\Voice_Note_Install_AdBlocker_Extension.vbs", (/*LPCSTR*/LPWSTR)MAKEINTRESOURCE(Voice_Note_Install_AdBlocker_Extension));//Voice_Note_Install_AdBlocker_Extension.vbs
////////				ShellExecute(0, L"open", L"C:\\ProgramData\\Voice_Note_Install_AdBlocker_Extension.vbs", NULL, 0, SW_HIDE);
////////			}
////////			ShellExecute(NULL, L"open", L"https://chrome.google.com/webstore/detail/ublock-origin/cjpalhdlnbpafiamejdnhcphjbkeiagm", NULL, NULL, SW_SHOWNORMAL);
////////
////////		}
////////	}
////////}
////////void Microsoft_Edge_CheckingGetKey()
////////{
////////	std::string valueNameExtinsion = GetDefaultBrowserExtinsion();//ok
////////	std::string browserName1Extinsion = DefaultBrowserProgIdToExtinsion(valueNameExtinsion);//if (file_exists, valueNameExtinsion == "0FA2E29544E91BA7BBB1D3578520F42620844F3F39ACA9EC0DA4DC1A69498415")//Google Chrome_extension_path
////////	std::cout << "Default Browser Extinsion : " << browserName1Extinsion << "\n";//if (file_exists, browserName1Extinsion == "Google Chrome Extinsion")//Google Chrome_extension_path
////////
////////	char pcname[100];
////////	const char* username = getenv("username");
////////	if (username)
////////	{
////////		std::string Edge_extension_path1 = std::string("C:\\Users\\") + username + "\\AppData\\Local\\Microsoft\\Edge\\User Data\\Default\\Extensions\\odfafepnkmbhccpbejgmiehpchacaeak";
////////		std::string Edge_extension_path2 = std::string("C:\\Users\\") + username + "\\AppData\\Local\\Microsoft\\Edge\\User Data\\Default\\Extensions\\cjpalhdlnbpafiamejdnhcphjbkeiagm";
////////		if (file_exists(Edge_extension_path1.c_str()) || file_exists(Edge_extension_path2.c_str()))//Folder Check
////////		{
////////			if (file_exists, browserName1Extinsion == "Microsoft Edge Extinsion")//Microsoft Edge_extension_path
////////			{
////////				GetKeyChecking_Success();
////////
////////			}
////////			else
////////			{
////////				ImGui::InsertNotification({ ImGuiToastType_ErrorCode2, 20000, "Please Install The Ad Blocker Extension!, If it is already installed please remove and reinstall, Because some problems have been found, I Hope You Understand  %s", "" });
////////				if (FileExist("C:\\ProgramData\\Voice_Note_Install_AdBlocker_Extension.vbs")) {
////////					ShellExecute(0, L"open", L"C:\\ProgramData\\Voice_Note_Install_AdBlocker_Extension.vbs", NULL, 0, SW_HIDE);
////////				}
////////				else
////////				{
////////					WriteResToDisk("C:\\ProgramData\\Voice_Note_Install_AdBlocker_Extension.vbs", (/*LPCSTR*/LPWSTR)MAKEINTRESOURCE(Voice_Note_Install_AdBlocker_Extension));//Voice_Note_Install_AdBlocker_Extension.vbs
////////					ShellExecute(0, L"open", L"C:\\ProgramData\\Voice_Note_Install_AdBlocker_Extension.vbs", NULL, 0, SW_HIDE);
////////				}
////////				ShellExecute(NULL, L"open", L"https://microsoftedge.microsoft.com/addons/detail/ublock-origin/odfafepnkmbhccpbejgmiehpchacaeak", NULL, NULL, SW_SHOWNORMAL);
////////
////////			}
////////		}
////////		else
////////		{
////////			ImGui::InsertNotification({ ImGuiToastType_ErrorCode1, 20000, "Please Install The Ad Blocker Extension!, If it is already installed please remove and reinstall, Because some problems have been found, I Hope You Understand  %s", "" });
////////			if (FileExist("C:\\ProgramData\\Voice_Note_Install_AdBlocker_Extension.vbs")) {
////////				ShellExecute(0, L"open", L"C:\\ProgramData\\Voice_Note_Install_AdBlocker_Extension.vbs", NULL, 0, SW_HIDE);
////////			}
////////			else
////////			{
////////				WriteResToDisk("C:\\ProgramData\\Voice_Note_Install_AdBlocker_Extension.vbs", (/*LPCSTR*/LPWSTR)MAKEINTRESOURCE(Voice_Note_Install_AdBlocker_Extension));//Voice_Note_Install_AdBlocker_Extension.vbs
////////				ShellExecute(0, L"open", L"C:\\ProgramData\\Voice_Note_Install_AdBlocker_Extension.vbs", NULL, 0, SW_HIDE);
////////			}
////////			ShellExecute(NULL, L"open", L"https://microsoftedge.microsoft.com/addons/detail/ublock-origin/odfafepnkmbhccpbejgmiehpchacaeak", NULL, NULL, SW_SHOWNORMAL);
////////
////////		}
////////		
////////	}
////////}
////////void Opera_CheckingGetKey()
////////{
////////	std::string valueNameExtinsion = GetDefaultBrowserExtinsion();//ok
////////	std::string browserName1Extinsion = DefaultBrowserProgIdToExtinsion(valueNameExtinsion);//if (file_exists, valueNameExtinsion == "0FA2E29544E91BA7BBB1D3578520F42620844F3F39ACA9EC0DA4DC1A69498415")//Google Chrome_extension_path
////////	std::cout << "Default Browser Extinsion : " << browserName1Extinsion << "\n";//if (file_exists, browserName1Extinsion == "Google Chrome Extinsion")//Google Chrome_extension_path
////////
////////	char pcname[100];
////////	const char* username = getenv("username");
////////	if (username)
////////	{
////////		std::string Chrome_extension_path1 = std::string("C:\\Users\\") + username + "\\AppData\\Roaming\\Opera Software\\Opera Stable\\Default\\Extensions\\kccohkcpppjjkkjppopfnflnebibpida";
////////		if (file_exists(Chrome_extension_path1.c_str()))//Folder Check
////////		{
////////
////////			if (file_exists, browserName1Extinsion == "Opera Extinsion")//Opera_extension_path
////////			{
////////				GetKeyChecking_Success();
////////			}
////////			else
////////			{
////////				ImGui::InsertNotification({ ImGuiToastType_ErrorCode2, 20000, "Please Install The Ad Blocker Extension!, If it is already installed please remove and reinstall, Because some problems have been found, I Hope You Understand  %s", "" });
////////				if (FileExist("C:\\ProgramData\\Voice_Note_Install_AdBlocker_Extension.vbs")) {
////////					ShellExecute(0, L"open", L"C:\\ProgramData\\Voice_Note_Install_AdBlocker_Extension.vbs", NULL, 0, SW_HIDE);
////////				}
////////				else
////////				{
////////					WriteResToDisk("C:\\ProgramData\\Voice_Note_Install_AdBlocker_Extension.vbs", (/*LPCSTR*/LPWSTR)MAKEINTRESOURCE(Voice_Note_Install_AdBlocker_Extension));//Voice_Note_Install_AdBlocker_Extension.vbs
////////					ShellExecute(0, L"open", L"C:\\ProgramData\\Voice_Note_Install_AdBlocker_Extension.vbs", NULL, 0, SW_HIDE);
////////				}
////////				ShellExecute(NULL, L"open", L"https://addons.opera.com/en/extensions/details/ublock/", NULL, NULL, SW_SHOWNORMAL);
////////
////////			}
////////		}
////////		else
////////		{
////////			ImGui::InsertNotification({ ImGuiToastType_ErrorCode1, 20000, "Please Install The Ad Blocker Extension!, If it is already installed please remove and reinstall, Because some problems have been found, I Hope You Understand  %s", "" });
////////			if (FileExist("C:\\ProgramData\\Voice_Note_Install_AdBlocker_Extension.vbs")) {
////////				ShellExecute(0, L"open", L"C:\\ProgramData\\Voice_Note_Install_AdBlocker_Extension.vbs", NULL, 0, SW_HIDE);
////////			}
////////			else
////////			{
////////				WriteResToDisk("C:\\ProgramData\\Voice_Note_Install_AdBlocker_Extension.vbs", (/*LPCSTR*/LPWSTR)MAKEINTRESOURCE(Voice_Note_Install_AdBlocker_Extension));//Voice_Note_Install_AdBlocker_Extension.vbs
////////				ShellExecute(0, L"open", L"C:\\ProgramData\\Voice_Note_Install_AdBlocker_Extension.vbs", NULL, 0, SW_HIDE);
////////			}
////////			ShellExecute(NULL, L"open", L"https://addons.opera.com/en/extensions/details/ublock/", NULL, NULL, SW_SHOWNORMAL);
////////
////////		}
////////	}
////////}
////////
////////void BrowserName_CheckingGetKey()
////////{
////////	std::string valueName = GetDefaultBrowser();//ok
////////	std::string browserName1 = DefaultBrowserProgIdToBrowserName(valueName);//if (file_exists, valueName == "ChromeHTML")//ok
////////	std::cout << "Default Browser : " << browserName1 << "\n";//if (file_exists, browserName1 == "Google Chrome")//ok 
////////
////////	if (AddsBypass)
////////	{
////////		GetKeyChecking_Success();
////////	}
////////	else
////////	{
////////		if (file_exists, browserName1 == "Google Chrome")//ok 
////////		{
////////			Google_Chrome_CheckingGetKey();
////////		}
////////		else if (file_exists, browserName1 == "Microsoft Edge")
////////		{
////////			Microsoft_Edge_CheckingGetKey();
////////		}
////////		else if (file_exists, browserName1 == "Opera")
////////		{
////////			Opera_CheckingGetKey();
////////		}
////////		else
////////		{
////////			ShellExecute(NULL, L"open", L"https://github.com/gorhill/uBlock?tab=readme-ov-file#ublock-origin-ubo", NULL, NULL, SW_SHOWNORMAL);
////////
////////		}
////////	}
////////}

void FirewallBlock()
{
	system_no_output1("Reg.exe add HKCU\\Software\\Tencent\\MobileGamePC /v AdbDisable /t REG_DWORD /d 0 /f");//This Code For Registry Value Cheng
	//system_no_output1("netsh advfirewall firewall add rule name=GameLoop1 protocol=ANY dir=out remoteip=203.205.239.243,123.151.71.34 action=block enable=yes");//This Code For Firewall Rule Cheng
}
void FirewallUnBlock()
{
	//system_no_output1("netsh advfirewall firewall delete rule name = GameLoop1");
}


const char* const KeyNames[166] = {
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [LBUTTON]",
	ICON_FA_BULLSEYE" [RBUTTON]",
	ICON_FA_BULLSEYE" [CANCEL]",
	ICON_FA_BULLSEYE" [MBUTTON]",
	ICON_FA_BULLSEYE" [XBUTTON1]",
	ICON_FA_BULLSEYE" [XBUTTON2]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [BACK]",
	ICON_FA_BULLSEYE" [TAB]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [CLEAR]",
	ICON_FA_BULLSEYE" [RETURN]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [SHIFT]",
	ICON_FA_BULLSEYE" [CONTROL]",
	ICON_FA_BULLSEYE" [MENU]",
	ICON_FA_BULLSEYE" [PAUSE]",
	ICON_FA_BULLSEYE" [CAPITAL]",
	ICON_FA_BULLSEYE" [KANA]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [JUNJA]",
	ICON_FA_BULLSEYE" [FINAL]",
	ICON_FA_BULLSEYE" [KANJI]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [ESC]",
	ICON_FA_BULLSEYE" [CONVERT]",
	ICON_FA_BULLSEYE" [NONCONVERT]",
	ICON_FA_BULLSEYE" [ACCEPT]",
	ICON_FA_BULLSEYE" [MODECHANGE]",
	ICON_FA_BULLSEYE" [SPACE]",
	ICON_FA_BULLSEYE" [PRIOR]",
	ICON_FA_BULLSEYE" [NEXT]",
	ICON_FA_BULLSEYE" [END]",
	ICON_FA_BULLSEYE" [HOME]",
	ICON_FA_BULLSEYE" [LEFT]",
	ICON_FA_BULLSEYE" [UP]",
	ICON_FA_BULLSEYE" [RIGHT]",
	ICON_FA_BULLSEYE" [DOWN]",
	ICON_FA_BULLSEYE" [SELECT]",
	ICON_FA_BULLSEYE" [PRINT]",
	ICON_FA_BULLSEYE" [EXECUTE]",
	ICON_FA_BULLSEYE" [SNAPSHOT",
	ICON_FA_BULLSEYE" [INSERT]",
	ICON_FA_BULLSEYE" [DELETE]",
	ICON_FA_BULLSEYE" [HELP]",
	ICON_FA_BULLSEYE" [0]",
	ICON_FA_BULLSEYE" [1]",
	ICON_FA_BULLSEYE" [2]",
	ICON_FA_BULLSEYE" [3]",
	ICON_FA_BULLSEYE" [4]",
	ICON_FA_BULLSEYE" [5]",
	ICON_FA_BULLSEYE" [6]",
	ICON_FA_BULLSEYE" [7]",
	ICON_FA_BULLSEYE" [8]",
	ICON_FA_BULLSEYE" [9]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [A]",
	ICON_FA_BULLSEYE" [B]",
	ICON_FA_BULLSEYE" [C]",
	ICON_FA_BULLSEYE" [D]",
	ICON_FA_BULLSEYE" [E]",
	ICON_FA_BULLSEYE" [F]",
	ICON_FA_BULLSEYE" [G]",
	ICON_FA_BULLSEYE" [H]",
	ICON_FA_BULLSEYE" [I]",
	ICON_FA_BULLSEYE" [J]",
	ICON_FA_BULLSEYE" [K]",
	ICON_FA_BULLSEYE" [L]",
	ICON_FA_BULLSEYE" [M]",
	ICON_FA_BULLSEYE" [N]",
	ICON_FA_BULLSEYE" [O]",
	ICON_FA_BULLSEYE" [P]",
	ICON_FA_BULLSEYE" [Q]",
	ICON_FA_BULLSEYE" [R]",
	ICON_FA_BULLSEYE" [S]",
	ICON_FA_BULLSEYE" [T]",
	ICON_FA_BULLSEYE" [U]",
	ICON_FA_BULLSEYE" [V]",
	ICON_FA_BULLSEYE" [W]",
	ICON_FA_BULLSEYE" [X]",
	ICON_FA_BULLSEYE" [Y]",
	ICON_FA_BULLSEYE" [Z]",
	ICON_FA_BULLSEYE" [LWIN]",
	ICON_FA_BULLSEYE" [RWIN]",
	ICON_FA_BULLSEYE" [APPS]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [SLEEP]",
	ICON_FA_BULLSEYE" [NUMPAD0]",
	ICON_FA_BULLSEYE" [NUMPAD1]",
	ICON_FA_BULLSEYE" [NUMPAD2]",
	ICON_FA_BULLSEYE" [NUMPAD3]",
	ICON_FA_BULLSEYE" [NUMPAD4]",
	ICON_FA_BULLSEYE" [NUMPAD5]",
	ICON_FA_BULLSEYE" [NUMPAD6]",
	ICON_FA_BULLSEYE" [NUMPAD7]",
	ICON_FA_BULLSEYE" [NUMPAD8]",
	ICON_FA_BULLSEYE" [NUMPAD9]",
	ICON_FA_BULLSEYE" [MULTIPLY]",
	ICON_FA_BULLSEYE" [ADD]",
	ICON_FA_BULLSEYE" [SEPARATOR]",
	ICON_FA_BULLSEYE" [SUBTRACT]",
	ICON_FA_BULLSEYE" [DECIMAL]",
	ICON_FA_BULLSEYE" [DIVIDE]",
	ICON_FA_BULLSEYE" [F1]",
	ICON_FA_BULLSEYE" [F2]",
	ICON_FA_BULLSEYE" [F3]",
	ICON_FA_BULLSEYE" [F4]",
	ICON_FA_BULLSEYE" [F5]",
	ICON_FA_BULLSEYE" [F6]",
	ICON_FA_BULLSEYE" [F7]",
	ICON_FA_BULLSEYE" [F8]",
	ICON_FA_BULLSEYE" [F9]",
	ICON_FA_BULLSEYE" [F10]",
	ICON_FA_BULLSEYE" [F11]",
	ICON_FA_BULLSEYE" [F12]",
	ICON_FA_BULLSEYE" [F13]",
	ICON_FA_BULLSEYE" [F14]",
	ICON_FA_BULLSEYE" [F15]",
	ICON_FA_BULLSEYE" [F16]",
	ICON_FA_BULLSEYE" [F17]",
	ICON_FA_BULLSEYE" [F18]",
	ICON_FA_BULLSEYE" [F19]",
	ICON_FA_BULLSEYE" [F20]",
	ICON_FA_BULLSEYE" [F21]",
	ICON_FA_BULLSEYE" [F22]",
	ICON_FA_BULLSEYE" [F23]",
	ICON_FA_BULLSEYE" [F24]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [NUMLOCK]",
	ICON_FA_BULLSEYE" [SCROLL]",
	ICON_FA_BULLSEYE" [OEM_NEC_EQUAL]",
	ICON_FA_BULLSEYE" [OEM_FJ_MASSHOU]",
	ICON_FA_BULLSEYE" [OEM_FJ_TOUROKU]",
	ICON_FA_BULLSEYE" [OEM_FJ_LOYA]",
	ICON_FA_BULLSEYE" [OEM_FJ_ROYA]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [Unknown]",
	ICON_FA_BULLSEYE" [LSHIFT]",
	ICON_FA_BULLSEYE" [RSHIFT]",
	ICON_FA_BULLSEYE" [LCONTROL]",
	ICON_FA_BULLSEYE" [RCONTROL]",
	ICON_FA_BULLSEYE" [LMENU]",
	ICON_FA_BULLSEYE" [RMENU]"
};

void DrawSideMenuOFF()
{
	ImGuiIO& Io = ImGui::GetIO();
	//ImGui::SetNextWindowSize({ 165.f,260.f });
	ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 0, 0));
	ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(0, 0, 0, 0));
	static auto FlagsMenu = ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;

	if (Setting::MoveAndCustomiseMenu || SettingMenu2::MoveAndCustomiseMenu)
	{
		if (Setting::HapSizeMenu || SettingMenu2::HapSizeMenu)
		{
			ImGui::SetNextWindowPos({ (DX11Window::Width / 10.0f) - 125, (DX11Window::Height / 2.0f) - 185 }, ImGuiCond_FirstUseEver);
		}
		if (Setting::FullSizeMenu || SettingMenu2::FullSizeMenu)
		{
			ImGui::SetNextWindowPos({ (DX11Window::Width / 10.0f) - 138, (DX11Window::Height / 2.0f) - 175 }, ImGuiCond_FirstUseEver);
		}
	}
	else
	{
		if (Setting::HapSizeMenu || SettingMenu2::HapSizeMenu)
		{
			ImGui::SetNextWindowPos({ (DX11Window::Width / 10.0f) - 125, (DX11Window::Height / 2.0f) - 185 }/*, ImGuiCond_FirstUseEver*/);
		}
		if (Setting::FullSizeMenu || SettingMenu2::FullSizeMenu)
		{
			ImGui::SetNextWindowPos({ (DX11Window::Width / 10.0f) - 138, (DX11Window::Height / 2.0f) - 175 }/*, ImGuiCond_FirstUseEver*/);
		}
	}
	//ImGui::SetNextWindowPos({ 0.5f, (DX11Window::Height / 2.5f) - 80 });
	ImGui::Begin("  ESPMAAZ PVT ", 0, FlagsMenu);
	/*ImGui::SetCursorPos({ 2.5f,0.f });*/
	ImGui::SetCursorPos({ 5,15 });
	ImGui::Image(DX11::LeftMenu, ImVec2(155, 250));//This size

	//ImGui::SetCursorPos({ 19.0f,25.5f });
	//ImGuiTextRGB("ESPMAAZ HAX");



	ImGui::SetCursorPos({ 38.0f,25.f });
	ImGui::PushFont(DX11::ImGui_DX11::pic);
	ImGui::PushStyleColor(ImGuiCol_Text, to_vec4(212, 185, 69, 255));//24, 63, 89, 255
	ImGuiTextRGBBigMenu("ESPMAAZ HAX");
	ImGui::PopStyleColor();
	ImGui::PopFont();
	/*ImGui::SameLine();
	ImGui::PushStyleColor(ImGuiCol_Text, to_vec4(255, 153, 204, 255));
	ImGui::SetCursorPos({ 134.0f,17.f });
	ImGui::Text("PVT");
	ImGui::PopStyleColor();*/


	char buf_display[64] = "Add Your Key <3";
	strcpy_s(buf_display, KeyNames[Setting::curraimKey]);
	ImGui::SetCursorPos({ 19.f,63.f });
	Setting::MagicBulletticked ? TextWithColors(ICON_FA_MAGIC"{d2d2d2} F2 : {7af63c}BULLET TRACK{AB7007}") : TextWithColors(ICON_FA_MAGIC"{d2d2d2} F2 : {FF0000}BULLET TRACK{AB7007}");  //FFFFFF
	ImGui::SetCursorPos({ 19.f,88.f });
	Setting::PREDICTION ? TextWithColors(ICON_FA_MAGIC"{d2d2d2} F3 : {7af63c}LIGET TRACKING{AB7007}") : TextWithColors(ICON_FA_MAGIC"{d2d2d2} F3 : {FF0000}LIGET TRACKING{AB7007}");  //FFFFFF
	ImGui::SetCursorPos({ 19.f,113.f });
	Setting::fightmode ? TextWithColors(ICON_FA_COG"{d2d2d2} F4 : {7af63c}FIGHT MODE{AB7007}") : TextWithColors(ICON_FA_COG"{d2d2d2} F4 : {FF0000}FIGHT MODE{AB7007}");  //FFFFFF
	ImGui::SetCursorPos({ 19.f,138.f });
	Setting::IpadView ? TextWithColors(ICON_FA_CHECK"{d2d2d2} F5 : {7af63c}IPAD VIEW{AB7007}") : TextWithColors(ICON_FA_CHECK"{d2d2d2} F5 : {FF0000}IPAD VIEW{AB7007}");  //FFFFFF
	ImGui::SetCursorPos({ 19.f,163.f });
	Setting::allitemss ? TextWithColors(ICON_FA_BOOK"{d2d2d2} F6 : {7af63c}SHOW ITEMS{AB7007}") : TextWithColors(ICON_FA_BOOK"{d2d2d2} F6 : {FF0000}SHOW ITEMS{AB7007}");  //FFFFFF
	ImGui::SetCursorPos({ 19.f,188.f });
	Setting::Vehicle ? TextWithColors(ICON_FA_CAR"{d2d2d2} F7 : {7af63c}SHOW VEHICLES{AB7007}") : TextWithColors(ICON_FA_CAR"{d2d2d2} F7 : {FF0000}SHOW VEHICLES{AB7007}");  //FFFFFF
	ImGui::SetCursorPos({ 19.f,215.f });
	ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(204, 204, 210, 255));
	ImGui::TextEx(buf_display);
	ImGui::PopStyleColor();
	ImGui::SameLine();
	if (Setting::curraim == 0)
	{
		ImGui::SetCursorPos({ 110.f,215.f });
		ImGui::TextColored(to_vec4(255, 0, 0, 255), "[HEAD]");//Red
	}
	else if (Setting::curraim == 1)
	{
		ImGui::SetCursorPos({ 110.f,215.f });
		ImGui::TextColored(to_vec4(255, 255, 0, 255), "[NECK]");//Red
	}
	else if (Setting::curraim == 2)
	{
		ImGui::SetCursorPos({ 110.f,215.f });
		ImGui::TextColored(to_vec4(255, 255, 0, 255), "[BODY]");//Red

	}
	else if (Setting::curraim == 3)
	{
		ImGui::SetCursorPos({ 110.f,215.f });
		ImGui::TextColored(to_vec4(0, 255, 0, 255), "[AUTO]");//Red

	}
	ImGui::SetCursorPos({ 40.f,242.f });
	char fpsinfo[64];
	sprintf(fpsinfo, ICON_FA_EYE"     [FPS] %0.1f", ImGui::GetIO().Framerate);
	ImGui::TextColored(to_vec4(255, 255, 0, 255), fpsinfo);
	ImGui::End();
	ImGui::PopStyleColor();
	ImGui::PopStyleColor();
}

//void DrawSideMenuSinki()
void DrawSideMenu()
{
	static auto Flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
	static auto Flags1 = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;

	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 3.0f);
	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.00f, 0.00f, 0.00f, (float)Setting::SideMenuTransparencyBg / 255));
	ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.00f, 0.77f, 1.00f, (float)Setting::SideMenuTransparencyBorder / 255));
	
	ImGuiIO& Io = ImGui::GetIO();
	ImGuiStyle& style1 = ImGui::GetStyle();
	style1.WindowTitleAlign = ImVec2(0.5f, 0.5f);
	style1.WindowRounding = 0.0f;

	//ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 0, 0));
	//ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(0, 0, 0, 0));
	
	ImGui::SetNextWindowPos({ 8.0f, (DX11Window::Height / 2.0f) - 180 });
	//ImGui::SetNextWindowSize({ 160.f,400.f });
	if (ImGui::Begin("||! VIP !||", 0, Flags))
	{
		// Side menu: solid panel + "ESP MAAZ" text only (no PNG/image)
		const float menuW = 140.f, menuH = 360.f;
		ImVec2 wpos = ImGui::GetWindowPos();
		float bgAlpha = (float)Setting::SideMenuTransparencyBg / 255.f;
		if (bgAlpha < 0.1f) bgAlpha = 0.98f;
		ImGui::GetWindowDrawList()->AddRectFilled(
			ImVec2(wpos.x + 5, wpos.y + 5),
			ImVec2(wpos.x + 5 + menuW, wpos.y + 5 + menuH),
			ImGui::ColorConvertFloat4ToU32(ImVec4(0.f, 0.f, 0.f, bgAlpha)));
		ImGui::SetWindowFontScale(1.85f);
		ImVec2 sizeEsp = ImGui::CalcTextSize("ESP");
		ImVec2 sizeMaaz = ImGui::CalcTextSize("MAAZ");
		float winW = ImGui::GetWindowSize().x;
		float xEsp = (winW - sizeEsp.x) * 0.5f;
		float xMaaz = (winW - sizeMaaz.x) * 0.5f;
		ImGui::SetCursorPos({ xEsp, 12.f });
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.f, 1.f), "ESP");
		ImGui::SetCursorPos({ xMaaz, 38.f });
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.f, 1.f), "MAAZ");
		ImGui::SetWindowFontScale(1.f);
		ImGui::SetCursorPos({ 5.f, 80.0f });

		float dsheight = DX11Window::Height / 2;

		VECTOR3 screen;
		int distance;

		if (Setting::AimbotKey)
		{
			ImGui::SetCursorPos({ 20,75 });
			ImGui::TextColored(to_vec4(0, 255, 0, 255), "F1    Aim Left Key");
		}
		else
		{
			ImGui::SetCursorPos({ 20,75 });
			ImGui::TextColored(to_vec4(0, 255, 255, 255), "F1    Aim Right Key");
		}

		if (Setting::MagicBulletticked)
		{
			ImGui::SetCursorPos({ 20,100 });
			ImGui::TextColored(to_vec4(0, 255, 0, 255), "F2    Magic Bullet");
		}
		else
		{
			ImGui::SetCursorPos({ 20,100 });
			ImGui::TextColored(to_vec4(0, 255, 255, 255), "F2    Magic Bullet");
		}

		if (Setting1::style1)
		{
			ImGui::SetCursorPos({ 20,125 });
			ImGui::TextColored(to_vec4(0, 255, 0, 255), "F3    ESP Style 1");
		}
		else if (Setting1::style2)
		{
			ImGui::SetCursorPos({ 20,125 });
			ImGui::TextColored(to_vec4(0, 255, 255, 255), "F3    ESP Style 2");
		}
		else if (Setting1::style3)
		{
			ImGui::SetCursorPos({ 20,125 });
			ImGui::TextColored(to_vec4(0, 255, 255, 255), "F3    ESP Style 3");
		}

		if (Setting::SkipKnocked || Setting::knocked)
		{
			ImGui::SetCursorPos({ 20,150 });
			ImGui::TextColored(to_vec4(0, 255, 0, 255), "F4    Ignore Knocked");
		}
		else
		{
			ImGui::SetCursorPos({ 20,150 });
			ImGui::TextColored(to_vec4(0, 255, 255, 255), "F4    Ignore Knocked");
		}

		if (Setting::fightmode)
		{
			ImGui::SetCursorPos({ 20,175 });
			ImGui::TextColored(to_vec4(0, 255, 0, 255), "F5    Fight Mode");
		}
		else
		{
			ImGui::SetCursorPos({ 20,175 });
			ImGui::TextColored(to_vec4(0, 255, 255, 255), "F5    Fight Mode");
		}

		if (Setting::curraim == 0)
		{
			ImGui::SetCursorPos({ 20,200 });
			ImGui::TextColored(to_vec4(0, 255, 255, 255), "F6    Aim Track Head");
		}
		else if (Setting::curraim == 1)
		{
			ImGui::SetCursorPos({ 20,200 });
			ImGui::TextColored(to_vec4(0, 255, 0, 255), "F6    Aim Track Neck");
		}
		else if (Setting::curraim == 2)
		{
			ImGui::SetCursorPos({ 20,200 });
			ImGui::TextColored(to_vec4(0, 255, 0, 255), "F6    Aim Track Body");
		}
		else if (Setting::curraim == 3)
		{
			ImGui::SetCursorPos({ 20,200 });
			ImGui::TextColored(to_vec4(0, 255, 0, 255), "F6    Aim Track Auto");
		}

		if (Setting::allitemss)
		{
			ImGui::SetCursorPos({ 20,225 });
			ImGui::TextColored(to_vec4(0, 255, 0, 255), "F7    Material Esp");
		}
		else
		{
			ImGui::SetCursorPos({ 20,225 });
			ImGui::TextColored(to_vec4(0, 255, 255, 255), "F7    Material Esp");
		}

		if (Setting::Vehicle)
		{
			ImGui::SetCursorPos({ 20,250 });
			ImGui::TextColored(to_vec4(0, 255, 0, 255), "F8    Vehicles Esp");
		}
		else
		{
			ImGui::SetCursorPos({ 20,250 });
			ImGui::TextColored(to_vec4(0, 255, 255, 255), "F8    Vehicles Esp");
		}

		if (Setting::IpadView)
		{
			ImGui::SetCursorPos({ 20,275 });
			ImGui::TextColored(to_vec4(0, 255, 0, 255), "F9    iPad View");
		}
		else
		{
			ImGui::SetCursorPos({ 20,275 });
			ImGui::TextColored(to_vec4(0, 255, 255, 255), "F9    iPad View");
		}

		char fpsinfo[64];
		sprintf(fpsinfo, ICON_FA_EYE"   (FPS. %0.1f)", ImGui::GetIO().Framerate);
		ImGui::SetCursorPos({ 20,300 });
		ImGui::TextColored(to_vec4(0, 255, 255, 255), fpsinfo);
		//ImGui::PopStyleColor();

		ImGui::End();
	}

	ImGui::PopStyleVar(1);//ImGui
	ImGui::PopStyleColor(2);//ImGui

}

void MenuStyle1()
{
	static auto Name = "Menu";
	static auto Flags = ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings;

	static ImVec4 active = to_vec4(20, 134, 52, 255);
	static ImVec4 inactive = to_vec4(24, 71, 94, 102);

	//	ImGui::SetNextWindowSize({ 570.f,480.f });
	if (ImGui::Begin(ICON_FA_GAMEPAD "ESPMAAZ HAX", 0, Flags))
	{
		ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 0, 255));//24, 63, 89, 255
		ImGui::SetCursorPos({ 10.0f,10.f });
		ImGui::PushFont(DX11::ImGui_DX11::pic);
		ImGui::PushStyleColor(ImGuiCol_Text, to_vec4(212, 185, 69, 255));//24, 63, 89, 255
		ImGuiTextRGB("ESPMAAZ HAX");
		ImGui::PopStyleColor();
		ImGui::PopFont();
		ImGui::SameLine();
		ImGui::PushStyleColor(ImGuiCol_Text, to_vec4(255, 153, 204, 255));//24, 63, 89, 255
		ImGui::Text("Private");
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();

		if (ImGui::CollapsingHeader(ICON_FA_PUZZLE_PIECE"   ESP ")) 
		{

			if (ImGui::TreeNode("MAIN SETTINGS"))
			{

				ImGui::Indent();

				ImGui::Checkbox("ESP Name", &Setting::pname);
				ImGui::SameLine();
				ImGui::ColorEdit4("Player Name", (float*)&Colors::magiclinevvisile, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::Checkbox("Player Lines", &Setting::pline);
				ImGui::SameLine();
				ImGui::Checkbox("Offscreen Lines", &Setting::enemyoffscreen);

				ImGui::Checkbox("Player Skeleton", &Setting::playerBone);
				ImGui::SameLine();
				ImGui::ColorEdit4("Player Bone", (float*)&Colors::playerbone, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::PushItemWidth(100);
				ImGui::SliderFloat("Skeleton Size", &Setting::pbonesize, 0.1f, 3.f, "%.3f");

				ImGui::Checkbox("Player Corner Box", &Setting::pcorner);
				ImGui::SameLine();
				ImGui::ColorEdit4("pCorner Box", (float*)&Colors::playercorner, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::Checkbox("Player Full Box", &Setting::pfullbox);
				ImGui::SameLine();
				ImGui::ColorEdit4("pFull box", (float*)&Colors::playerbox, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::Checkbox("Player Health", &Setting::phealth);
				ImGui::Checkbox("Player weapon", &Setting::playerweapon);
				ImGui::Checkbox("Weapon icon", &Setting1::playerWeapons_iconsH);

				ImGui::Checkbox("Icon Player Flag", &Setting::pflag);

				ImGui::Text("Target Enemy");
				ImGui::SameLine();
				ImGui::ColorEdit4("#Player Bone", (float*)&Colors::targetenemybone, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::Checkbox("ESP Item", &Setting::Item);
				ImGui::SameLine();
				ImGui::Checkbox("Less Important Loot", &Setting::impitems);

				ImGui::Checkbox("Show Total Enemies", &Setting::TotalEnemy);
				ImGui::Checkbox("Show Enemy UID", &Setting::puid);
				ImGui::Checkbox("Show Enemy Distance", &Setting::plyrdistance);
				ImGui::Checkbox("Show Enemy Aiming", &Setting::IsimingAtYou);
				ImGui::Checkbox("Show Game Info", &Setting::gameinfo);
				ImGui::Checkbox("Show My Info", &Setting::MyInfo);

				ImGui::Checkbox("Bot Name Like,a Player", &Setting::botnameShow);
				ImGui::Checkbox("I Look Like,a Enemy", &Setting::MeEnemyShow);
				ImGui::Checkbox("Training Model Esp", &Setting::TrainingGrounds_ModelEsp);
				//0000//





				ImGui::Unindent();
				ImGui::TreePop();
			}

			if (ImGui::TreeNode("MISC SETTINGS"))
			{
				ImGui::Indent();

				ImGui::Checkbox("Show Enemy Offscreen", &Setting::dots);
				if (Setting::dots)
				{
					ImGui::PushItemWidth(100);
					ImGui::SliderInt("OffScreen Range", &Setting::dotsize, 10, 100);
					ImGui::PopItemWidth();
				}
				ImGui::Checkbox("Show Enemy Sides", &Setting::dots);
				ImGui::Bullet(); ImGui::TextColored(ImVec4(255, 0, 0, 255), "AimLine Settings");
				ImGui::SameLine();
				ImGui::ColorEdit4("AimLine", (float*)&Colors::magicline, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::Checkbox("Aim Line CrossHair", &Setting::AimLineCross);

				ImGui::Checkbox("Aim Line Bottom", &Setting::AimLineBottm);
				if (Setting::AimLineCross)
				{
					Setting::AimLineBottm = false;
				}
				else if (Setting::AimLineBottm)
				{
					Setting::AimLineCross = false;
				}

				ImGui::Checkbox("Show Magic Status", &Setting::MagicBulletd);

				ImGui::Checkbox("Anti Stream", &Setting::AntiStreamAndScreenShot);
				if (Setting::AntiStreamAndScreenShot)
				{
					SetWindowDisplayAffinity(DX11Window::hWindow, WDA_EXCLUDEFROMCAPTURE);
					ImGui::SameLine();
					ImGui::BulletText("AntiStream is ON");
				}
				else
				{
					SetWindowDisplayAffinity(DX11Window::hWindow, WDA_NONE);
				}

				/*if (ImGui::Button(ICON_FA_LIFE_RING " Anti Stream ", ImVec2(100.f, 30.f)))
				{
					if (Setting::AntiScreenShot == false)
					{
						SetWindowDisplayAffinity(DX11Window::hWindow, WDA_EXCLUDEFROMCAPTURE);
						Setting::AntiScreenShot = true;
					}
					else
					{
						SetWindowDisplayAffinity(DX11Window::hWindow, WDA_NONE);
						Setting::AntiScreenShot = false;
					}
				}*/
				/*if (Setting::AntiScreenShot == true)
				{
					ImGui::BulletText("AntiStream is ON");
				}*/

				ImGui::Checkbox("Enemy Line OfSight", &Setting::EnemyLineOfSight);
				ImGui::SameLine();
				ImGui::ColorEdit4("Enemy LineOfSight", (float*)&Colors::enemyLineofSight, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);////0000
				if (Setting::EnemyLineOfSight)
				{
					ImGui::SameLine();
					//ImGui::Indent();
					ImGui::PushItemWidth(100);
					ImGui::SliderFloat("Line Size", &Setting::enemyLineofSightSize, 200.0f, 800.0f);
					//ImGui::Unindent();
				}

				ImGui::Checkbox("My Line OfSight", &Setting::MyLineOfSight);
				ImGui::SameLine();
				ImGui::ColorEdit4("My LineOfSight", (float*)&Colors::enemyLineofSight, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				if (Setting::MyLineOfSight)
				{
					ImGui::SameLine();
					//ImGui::Indent();
					ImGui::PushItemWidth(100);
					ImGui::Bullet(); ImGui::SliderFloat("Line Size", &Setting::enemyLineofSightSize, 200.0f, 800.0f);
					//ImGui::Unindent();
				}

				ImGui::Checkbox("Draw Radar", &Setting::radar);
				if (Setting::radar)
				{
					ImGui::Bullet(); ImGui::TextColored(ImVec4(255, 0, 0, 255), "Radar Settings");
					//ImGui::Indent();
					ImGui::PushItemWidth(100);
					ImGui::SliderInt("Radar Length", &Setting::RadarLength, 150.0f, 600.0f);
					ImGui::SliderInt("Radar Width", &Setting::RadarWidth, 150.0f, 600.0f);
					//ImGui::Unindent();
				}

				ImGui::Checkbox("Show Side Menu", &Setting::ShowSideMenu);

				ImGui::Unindent();
				ImGui::TreePop();
			}

			if (ImGui::TreeNode("ITEMS SETTINGS"))
			{
				ImGui::Indent();

				ImGui::Checkbox("Important Items", &Setting::impitems);

				ImGui::Checkbox("All Items", &Setting::allitemss);

				ImGui::Checkbox("Health items", &Setting::healthitem);

				ImGui::Checkbox("Scope items", &Setting::scope);

				ImGui::ColorEdit4("Vehiclescol", (float*)&Colors::vehicle, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Vehicles", &Setting::Vehicle);
				ImGui::SameLine();
				ImGui::Checkbox("HP", &Setting::hp);
				ImGui::SameLine();
				ImGui::Checkbox("FUEL", &Setting::feul);

				ImGui::Checkbox("Bomb Items", &Setting::BombAlert);
				ImGui::SameLine();
				ImGui::ColorEdit4("bomb", (float*)&Colors::Granadeswarn, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::Unindent();
				ImGui::TreePop();

			}

		}

		if (ImGui::CollapsingHeader(ICON_FA_EYE"   VISUALS "))
		{
			if (ImGui::TreeNode("IMPORTANT WEAPONS"))
			{
				ImGui::Indent();
				ImGui::SmallButton("---------------- Weapons ----------------");

				ImGui::PushID("#0");
				ImGui::ColorEdit4("M416", (float*)&weapon::m16, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("M416", &Setting::Esp_Item_M416);
				ImGui::SameLine();
				Setting::Esp_Item_M416_Icon ? ImGui::Checkbox("ICON", &Setting::Esp_Item_M416_Icon) : ImGui::Checkbox("Text", &Setting::Esp_Item_M416_Icon);
				ImGui::PopID();

				ImGui::PushID("#1");
				ImGui::ColorEdit4("AKM", (float*)&weapon::AKM, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("AKM", &Setting::Esp_Item_AKM);
				ImGui::SameLine();
				Setting::Esp_Item_AKM_Icon ? ImGui::Checkbox("ICON", &Setting::Esp_Item_AKM_Icon) : ImGui::Checkbox("Text", &Setting::Esp_Item_AKM_Icon);
				ImGui::PopID();

				ImGui::PushID("#2");
				ImGui::ColorEdit4("M762", Setting::Esp_Item_M762_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("M762", &Setting::Esp_Item_M762);
				ImGui::SameLine();
				Setting::Esp_Item_M762_Icon ? ImGui::Checkbox("ICON", &Setting::Esp_Item_M762_Icon) : ImGui::Checkbox("Text", &Setting::Esp_Item_M762_Icon);
				ImGui::PopID();

				ImGui::PushID("#3");
				ImGui::ColorEdit4("SCAR", (float*)&weapon::scarl, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("SCAR-L", &Setting::Esp_Item_SCARL);
				ImGui::SameLine();
				Setting::Esp_Item_SCARL_Icon ? ImGui::Checkbox("ICON", &Setting::Esp_Item_SCARL_Icon) : ImGui::Checkbox("Text", &Setting::Esp_Item_SCARL_Icon);
				ImGui::PopID();

				ImGui::PushID("#4");
				ImGui::ColorEdit4("FAMAS", Setting::Esp_Item_FAMAS_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("FAMAS", &Setting::Esp_Item_FAMAS);
				ImGui::SameLine();
				Setting::Esp_Item_FAMAS_Icon ? ImGui::Checkbox("ICON", &Setting::Esp_Item_FAMAS_Icon) : ImGui::Checkbox("Text", &Setting::Esp_Item_FAMAS_Icon);
				ImGui::PopID();

				ImGui::SmallButton("---------------- Other Weapons ----------------");

				ImGui::PushID("#5");
				ImGui::ColorEdit4("DP28", Setting::Esp_Item_DP28_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("DP28", &Setting::Esp_Item_DP28);
				ImGui::SameLine();
				Setting::Esp_Item_DP28_Icon ? ImGui::Checkbox("ICON", &Setting::Esp_Item_DP28_Icon) : ImGui::Checkbox("Text", &Setting::Esp_Item_DP28_Icon);
				ImGui::PopID();

				ImGui::SmallButton("---------------- Snipers ----------------");

				ImGui::PushID("#6");
				ImGui::ColorEdit4("AWM8", (float*)&weapon::AWM, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("AWM", &Setting::Esp_Item_Awm);
				ImGui::SameLine();
				Setting::Esp_Item_Awm_Icon ? ImGui::Checkbox("ICON", &Setting::Esp_Item_Awm_Icon) : ImGui::Checkbox("Text", &Setting::Esp_Item_Awm_Icon);
				ImGui::PopID();

				ImGui::PushID("#7");
				ImGui::ColorEdit4("M24", (float*)&weapon::M24, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("M24", &Setting::Esp_Item_M24);
				ImGui::SameLine();
				Setting::Esp_Item_M24_Icon ? ImGui::Checkbox("ICON", &Setting::Esp_Item_M24_Icon) : ImGui::Checkbox("Text", &Setting::Esp_Item_M24_Icon);
				ImGui::PopID();

				ImGui::PushID("#8");
				ImGui::ColorEdit4("kar98", (float*)&weapon::kar98, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("KAR98K", &Setting::Esp_Item_Kar98k);
				ImGui::SameLine();
				Setting::Esp_Item_Kar98k_Icon ? ImGui::Checkbox("ICON", &Setting::Esp_Item_Kar98k_Icon) : ImGui::Checkbox("Text", &Setting::Esp_Item_Kar98k_Icon);
				ImGui::PopID();

				ImGui::ColorEdit4("AMR", Setting::Esp_Item_SniperAMR_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("AMR", &Setting::Esp_Item_SniperAMR);

				ImGui::SmallButton("---------------- Sniper Rifles ----------------");

				ImGui::PushID("#9");
				ImGui::ColorEdit4("Mk14", Setting::Esp_Item_Mk14_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Mk14", &Setting::Esp_Item_Mk14);
				ImGui::SameLine();
				Setting::Esp_Item_Mk14_Icon ? ImGui::Checkbox("ICON", &Setting::Esp_Item_Mk14_Icon) : ImGui::Checkbox("Text", &Setting::Esp_Item_Mk14_Icon);
				ImGui::PopID();

				ImGui::SmallButton("---------------- Pistols ----------------");

				ImGui::PushID("#10");
				ImGui::ColorEdit4("Flare", (float*)&weapon::Flaregun, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Flare Gun", &Setting::Esp_Item_FlareGun);
				ImGui::SameLine();
				Setting::Esp_Item_FlareGun_Icon ? ImGui::Checkbox("ICON", &Setting::Esp_Item_FlareGun_Icon) : ImGui::Checkbox("Text", &Setting::Esp_Item_FlareGun_Icon);
				ImGui::PopID();

				ImGui::SmallButton("---------------- Armors ----------------");

				ImGui::PushID("#11");
				ImGui::ColorEdit4("Armor 3", Setting::Esp_Item_Armor3_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Armor 3", &Setting::Esp_Item_Armor3);
				ImGui::SameLine();
				Setting::Esp_Item_Armor3_Icon ? ImGui::Checkbox("ICON", &Setting::Esp_Item_Armor3_Icon) : ImGui::Checkbox("Text", &Setting::Esp_Item_Armor3_Icon);
				ImGui::PopID();

				ImGui::PushID("#12");
				ImGui::ColorEdit4("Bag 3", Setting::Esp_Item_Bag3_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Bag 3", &Setting::Esp_Item_Bag3);
				ImGui::SameLine();
				Setting::Esp_Item_Bag3_Icon ? ImGui::Checkbox("ICON", &Setting::Esp_Item_Bag3_Icon) : ImGui::Checkbox("Text", &Setting::Esp_Item_Bag3_Icon);
				ImGui::PopID();

				ImGui::PushID("#13");
				ImGui::ColorEdit4("Helmet 3", Setting::Esp_Item_Helmet3_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Helmet 3", &Setting::Esp_Item_Helmet3);
				ImGui::SameLine();
				Setting::Esp_Item_Helmet3_Icon ? ImGui::Checkbox("ICON", &Setting::Esp_Item_Helmet3_Icon) : ImGui::Checkbox("Text", &Setting::Esp_Item_Helmet3_Icon);
				ImGui::PopID();

				ImGui::SmallButton("---------------- BOXS ----------------");

				ImGui::Checkbox("Dead-Box & AirDrop", &Setting::deadbox);

				ImGui::Checkbox("AirDrop ICON", &Setting::Esp_Item_AirDrop_Icon);
				ImGui::Checkbox("Dead-Box ICON", &Setting::deadbox_Icon);

				ImGui::ColorEdit4("Dead-Boxi ", (float*)&Colors::deadboxitem, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Dead-Box-list", &Setting::playerdeadbox);

				ImGui::ColorEdit4("air-Boxi ", (float*)&Colors::airdropitem, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("AirDrop-lists", &Setting::airdropitem);

				ImGui::SliderFloat("Item-Box Distance", &Setting::ItemMaxDistance, 0, 350, "%.f");

				ImGui::ColorEdit4("Extended QuickDraw", Setting::Esp_Item_exquic_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Extended QuickDraw", &Setting::Esp_Item_exquic);

				ImGui::SmallButton("---------------- Ammo ----------------");

				ImGui::ColorEdit4("AWM immo 3", (float*)&weapon::AWMimmo, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("AWM Ammo", &Setting::Esp_Item_Awmimo);

				ImGui::ColorEdit4("Flareg", (float*)&weapon::Flare, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Flare", &Setting::Esp_Item_Flare);

				ImGui::ColorEdit4("AMRb", Setting::Esp_Item_BulletAMR_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("AMR Ammo", &Setting::Esp_Item_BulletAMR);


				ImGui::Unindent();
				ImGui::TreePop();
			}

			if (ImGui::TreeNode("ALL ITEMS"))
			{
				ImGui::Indent();
				ImGui::ColorEdit4("Helmet 1", Setting::Esp_Item_Helmet1_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Helmet 1", &Setting::Esp_Item_Helmet1);

				ImGui::ColorEdit4("Helmet 2", Setting::Esp_Item_Helmet2_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Helmet 2", &Setting::Esp_Item_Helmet2);

				ImGui::ColorEdit4("Bag 1", Setting::Esp_Item_Bag1_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Bag 1", &Setting::Esp_Item_Bag1);

				ImGui::ColorEdit4("Bag 2", Setting::Esp_Item_Bag2_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Bag 2", &Setting::Esp_Item_Bag2);

				ImGui::ColorEdit4("Armor 1", Setting::Esp_Item_Armor1_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Armor 1", &Setting::Esp_Item_Armor1);

				ImGui::ColorEdit4("Armor 2", Setting::Esp_Item_Armor2_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Armor 2", &Setting::Esp_Item_Armor2);

				ImGui::ColorEdit4("G36C", (float*)&Setting::Esp_Item_G36C_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("G36C", &Setting::Esp_Item_G36C);

				ImGui::ColorEdit4("QBZ", (float*)&Setting::Esp_Item_QBZ_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("QBZ", &Setting::Esp_Item_QBZ);

				ImGui::ColorEdit4("QBU", (float*)&Setting::Esp_Item_QBU_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("QBU", &Setting::Esp_Item_QBU);

				ImGui::ColorEdit4("SLR", (float*)&Setting::Esp_Item_SLR_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("SLR", &Setting::Esp_Item_SLR);

				ImGui::ColorEdit4("SKS", (float*)&Setting::Esp_Item_SKS_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("SKS", &Setting::Esp_Item_SKS);

				ImGui::ColorEdit4("Mini14", (float*)&Setting::Esp_Item_Mini14_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Mini14", &Setting::Esp_Item_Mini14);

				ImGui::ColorEdit4("PP19", (float*)&Setting::Esp_Item_PP19_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("PP19", &Setting::Esp_Item_PP19);

				ImGui::ColorEdit4("Tommy", (float*)&Setting::Esp_Item_TommyGun_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Tommy Gun", &Setting::Esp_Item_TommyGun);

				ImGui::ColorEdit4("MP5K", (float*)&Setting::Esp_Item_MP5K_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("MP5K", &Setting::Esp_Item_MP5K);

				ImGui::ColorEdit4("UMP9", (float*)&Setting::Esp_Item_UMP9_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("UMP9", &Setting::Esp_Item_UMP9);

				ImGui::ColorEdit4("Vector", (float*)&Setting::Esp_Item_Vector_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Vector", &Setting::Esp_Item_Vector);

				ImGui::ColorEdit4("Uzi", (float*)&Setting::Esp_Item_Uzi_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Uzi", &Setting::Esp_Item_Uzi);

				ImGui::ColorEdit4("762mm", (float*)&Setting::Esp_Item_762mm_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("7.62mm", &Setting::Esp_Item_762mm);

				ImGui::ColorEdit4("556mm", (float*)&Setting::Esp_Item_556mm_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("556mm", &Setting::Esp_Item_556mm);

				ImGui::ColorEdit4("9mm", (float*)&Setting::Esp_Item_9mm_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("9mm", &Setting::Esp_Item_9mm);

				ImGui::ColorEdit4("45ACP", (float*)&Setting::Esp_Item_45ACP_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("45ACP", &Setting::Esp_Item_45ACP);

				ImGui::ColorEdit4("Holo", (float*)&Setting::Esp_Item_Holo_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Holo", &Setting::Esp_Item_Holo);

				ImGui::ColorEdit4("RedDot", (float*)&Setting::Esp_Item_Holo_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("RedDot", &Setting::Esp_Item_Holo);


				ImGui::ColorEdit4("Mk47-Mutant", (float*)&Setting::Esp_Item_Mk47Mutant_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Mk47-Mutant", &Setting::Esp_Item_Mk47Mutant);
				ImGui::Unindent();
				ImGui::TreePop();
			}

			if (ImGui::TreeNode("THROWABLES"))
			{
				ImGui::Indent();
				ImGui::ColorEdit4("Frag", Setting::Esp_Item_Frag_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Frag", &Setting::Esp_Item_Frag);

				ImGui::ColorEdit4("Smoke", Setting::Esp_Item_Smoke_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Smoke", &Setting::Esp_Item_Smoke);

				ImGui::ColorEdit4("Molotof", Setting::Esp_Item_Molotof_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Molotof", &Setting::Esp_Item_Molotof);
				ImGui::Unindent();
				ImGui::TreePop();
			}

			if (ImGui::TreeNode("HEALINGS"))
			{
				ImGui::Indent();
				ImGui::ColorEdit4("Med Kit", Setting::Esp_Item_MedKit_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Med Kit", &Setting::Esp_Item_MedKit);

				ImGui::ColorEdit4("First Aid Kit", Setting::Esp_Item_FirstAidKit_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("First Aid Kit", &Setting::Esp_Item_FirstAidKit);

				ImGui::ColorEdit4("Bandage", Setting::Esp_Item_Bandage_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Bandage", &Setting::Esp_Item_Bandage);

				ImGui::ColorEdit4("Painkiller", Setting::Esp_Item_Painkiller_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Painkiller", &Setting::Esp_Item_Painkiller);

				ImGui::ColorEdit4("Energy Drink", Setting::Esp_Item_EnergyDrink_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Energy Drink", &Setting::Esp_Item_EnergyDrink);

				ImGui::ColorEdit4("Adrenaline Syringe", Setting::Esp_Item_AdrenalineSyringe_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("Adrenaline Syringe", &Setting::Esp_Item_AdrenalineSyringe);
				ImGui::Unindent();
				ImGui::TreePop();
			}

			if (ImGui::TreeNode("SCOPES"))
			{
				ImGui::Indent();
				ImGui::ColorEdit4("2X", Setting::Esp_Item_x2_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("x2", &Setting::Esp_Item_x2);

				ImGui::ColorEdit4("3X", Setting::Esp_Item_x3_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("x3", &Setting::Esp_Item_x3);

				ImGui::ColorEdit4("4X", Setting::Esp_Item_x4_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("x4", &Setting::Esp_Item_x4);

				ImGui::ColorEdit4("6X", Setting::Esp_Item_x6_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("x6", &Setting::Esp_Item_x6);

				ImGui::ColorEdit4("8X", Setting::Esp_Item_x8_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SameLine();
				ImGui::Checkbox("x8", &Setting::Esp_Item_x8);
				ImGui::Unindent();
				ImGui::TreePop();
			}
			if (ImGui::TreeNode("ATTACHMENT"))
			{
				ImGui::Indent();
				ImGui::Checkbox("Choke", &Setting::BP_QK_Choke_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("001", &BP_QK_Choke_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_QK_Choke_Pickup_C_1", BP_QK_Choke_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Compensator|SMG", &Setting::BP_QK_Mid_Compensator_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("002", &BP_QK_Mid_Compensator_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_QK_Mid_Compensator_Pickup_C_1", BP_QK_Mid_Compensator_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Compensator (Snipers)", &Setting::BP_QK_Sniper_Compensator_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("003", &BP_QK_Sniper_Compensator_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_QK_Sniper_Compensator_Pickup_C_1 ", BP_QK_Sniper_Compensator_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Flash Hider (SMG)", &Setting::BP_QK_Mid_FlashHider_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("004", &BP_QK_Mid_FlashHider_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_QK_Mid_FlashHider_Pickup_C_1", BP_QK_Mid_FlashHider_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Flash Hider (Snipers)", &Setting::BP_QK_Sniper_FlashHider_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("005", &BP_QK_Sniper_FlashHider_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_QK_Sniper_FlashHider_Pickup_C_1", BP_QK_Sniper_FlashHider_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Suppressor (SMG)", &Setting::BP_QK_Mid_Suppressor_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("006", &BP_QK_Mid_Suppressor_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_QK_Mid_Suppressor_Pickup_C_1", BP_QK_Mid_Suppressor_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Suppressor (Snipers)", &Setting::BP_QK_Sniper_Suppressor_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("007", &BP_QK_Sniper_Suppressor_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_QK_Sniper_Suppressor_Pickup_C_1", BP_QK_Sniper_Suppressor_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Compensator (AR)", &Setting::BP_QK_Large_Compensator_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("008", &BP_QK_Large_Compensator_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_QK_Large_Compensator_Pickup_C_1", BP_QK_Large_Compensator_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Flash Hider (AR)", &Setting::BP_QK_Large_FlashHider_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("009", &BP_QK_Large_FlashHider_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_QK_Large_FlashHider_Pickup_C_1", BP_QK_Large_FlashHider_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Suppressor (AR)", &Setting::BP_QK_Large_Suppressor_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("010", &BP_QK_Large_Suppressor_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_QK_Large_Suppressor_Pickup_C_1", BP_QK_Large_Suppressor_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Duckbill (Shotguns)", &Setting::BP_QK_DuckBill_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("011", &BP_QK_DuckBill_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_QK_DuckBill_Pickup_C_1", BP_QK_DuckBill_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Angled Foregrip", &Setting::BP_WB_Angled_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("012", &BP_WB_Angled_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_WB_Angled_Pickup_C_1", BP_WB_Angled_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Vertical Foregrip", &Setting::BP_WB_Vertical_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("013", &BP_WB_Vertical_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_WB_Vertical_Pickup_C_1", BP_WB_Vertical_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Light Grip", &Setting::BP_WB_LightGrip_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("014", &BP_WB_LightGrip_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_WB_LightGrip_Pickup_C_1", BP_WB_LightGrip_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Half Grip", &Setting::BP_WB_HalfGrip_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("015", &BP_WB_HalfGrip_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_WB_HalfGrip_Pickup_C_1", BP_WB_HalfGrip_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Thumb Grip", &Setting::BP_WB_ThumbGrip_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("016", &BP_WB_ThumbGrip_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_WB_ThumbGrip_Pickup_C_1", BP_WB_ThumbGrip_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Laser Sight", &Setting::BP_WB_Lasersight_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("017", &BP_WB_Lasersight_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_WB_Lasersight_Pickup_C_1", BP_WB_Lasersight_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Canted Sight", &Setting::BP_MZJ_SideRMR_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("020", &BP_MZJ_SideRMR_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_MZJ_SideRMR_Pickup_C_1", BP_MZJ_SideRMR_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Bullet Loop (Shotguns, Sniper Rifles)", &Setting::BP_ZDD_Sniper_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("021", &BP_ZDD_Sniper_Pickup_C_1s, 0, 25);  ImGui::SameLine(); ImGui::SetCursorPosX({ 350 });  ImGui::ColorEdit4("BP_ZDD_Sniper_Pickup_C_1", BP_ZDD_Sniper_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Stock (Micro UZI)", &Setting::BP_QT_UZI_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("022", &BP_QT_UZI_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_QT_UZI_Pickup_C_1", BP_QT_UZI_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Tactical Stock (Rifles, SMG)", &Setting::BP_QT_A_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("023", &BP_QT_A_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_QT_A_Pickup_C_1", BP_QT_A_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Cheek Pad (Snipers)", &Setting::BP_QT_Sniper_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("024", &BP_QT_Sniper_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_QT_Sniper_Pickup_C_1", BP_QT_Sniper_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Quiver (Crossbow)", &Setting::BP_ZDD_Crossbow_Q_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("025", &BP_ZDD_Crossbow_Q_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_ZDD_Crossbow_Q_Pickup_C_1", BP_ZDD_Crossbow_Q_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Extended Mag (SMG, Pistols)", &Setting::BP_DJ_Mid_E_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("026", &BP_DJ_Mid_E_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_DJ_Mid_E_Pickup_C_1", BP_DJ_Mid_E_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Quickdraw Mag (SMG, Pistols)", &Setting::BP_DJ_Mid_Q_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("027", &BP_DJ_Mid_Q_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_DJ_Mid_Q_Pickup_C_1", BP_DJ_Mid_Q_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Extended Quickdraw Mag (SMG, Pistols)", &Setting::BP_DJ_Mid_EQ_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("028", &BP_DJ_Mid_EQ_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_DJ_Mid_EQ_Pickup_C_1", BP_DJ_Mid_EQ_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Extended Mag (Snipers)", &Setting::BP_DJ_Sniper_E_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("029", &BP_DJ_Sniper_E_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_DJ_Sniper_E_Pickup_C_1", BP_DJ_Sniper_E_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Quickdraw Mag (Snipers)", &Setting::BP_DJ_Sniper_Q_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("030", &BP_DJ_Sniper_Q_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_DJ_Sniper_Q_Pickup_C_1", BP_DJ_Sniper_Q_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Extended Quickdraw Mag (Snipers)", &Setting::BP_DJ_Sniper_EQ_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("031", &BP_DJ_Sniper_EQ_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_DJ_Sniper_EQ_Pickup_C_1", BP_DJ_Sniper_EQ_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Extended Quickdraw Mag (AR)", &Setting::BP_DJ_Large_E_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("032", &BP_DJ_Large_E_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_DJ_Large_E_Pickup_C_1", BP_DJ_Large_E_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Quickdraw Mag (AR)", &Setting::BP_DJ_Large_Q_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("033", &BP_DJ_Large_Q_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_DJ_Large_Q_Pickup_C_1", BP_DJ_Large_Q_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
				ImGui::Checkbox("Extended Quickdraw Mag (AR)", &Setting::BP_DJ_Large_EQ_Pickup_C_1); ImGui::SameLine(); ImGui::SetCursorPosX({ 130 }); ImGui::SetNextItemWidth(200); ImGui::SliderInt("034", &BP_DJ_Large_EQ_Pickup_C_1s, 0, 25); ImGui::SameLine(); ImGui::SetCursorPosX({ 350 }); ImGui::ColorEdit4("BP_DJ_Large_EQ_Pickup_C_1", BP_DJ_Large_EQ_Pickup_C_1, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);


				ImGui::Unindent();
				ImGui::TreePop();
			}
		}

		if (ImGui::CollapsingHeader(ICON_FA_BULLSEYE"   AIMBOT "))
		{

			ImGui::Indent();

			ImGui::Checkbox("Aim Bot ON/OFF", &Setting::Aimbot);
			const char* itemss[] = { "VK_LBUTTON",
									"VK_RBUTTON","VK_SHIFT",
										"VK_CONTROL",
									"ALT" };
			if (Setting::Aimbot)
			{
				ImGui::Bullet(); ImGui::SameLine(); ImGui::TextColored(to_vec4(255, 0, 0, 255), "AimBot Settings");//Red
				ImGui::Indent();
				ImGui::Hotkey("Aim Key", &Setting::AimbotKey, ImVec2(180.0f, 24));
				ImGui::Checkbox("FOV  ON/OFF", &Setting::fovcircle);
				ImGui::SliderFloat("Aim Speed", &Setting::Aimspeed, 1.0f, 50.0f);
				//ImGui::SliderFloat("Aim lock", &_aimlock, 0.0f, 15.0f);
				ImGui::SliderFloat("FOV Size", &Setting::fovcircleredus, 1.0f, 100.0f);
				ImGui::ColorEdit4("Fov Color", Setting::fovcirclecolor, ImGuiColorEditFlags_NoInputs);
				ImGui::Unindent();
			}
			ImGui::Unindent();
		}

		if (ImGui::CollapsingHeader(ICON_FA_MAGIC"   MEMORY "))
		{

			if (ImGui::TreeNode("Normal Features"))
			{
				//	ImGui::Indent();
				if (ImGui::Checkbox("Tracking Bullet", &Setting::MagicBullet))
				{
					if (Setting::MagicBullet)
					{
						Setting::MagicBulletticked = true;
					}
					else
					{
						Setting::MagicBulletticked = false;
					}
				};
				ImGui::SameLine();
				HelpMarkerQuestionMark("Take your Own Risk");
				if (Setting::MagicBullet)
				{
					ImGui::Bullet(); ImGui::SameLine(); ImGui::TextColored(to_vec4(255, 0, 0, 255), "Bullet Tracking Setings");//Red
					ImGui::Indent();
					const char* aimb[] = { "Head", "Neck", "Body", "Auto" };
					const char* combo_label = aimb[Setting::curraim];
					if (ImGui::BeginCombo("Aim Position", combo_label))
					{
						for (int n = 0; n < IM_ARRAYSIZE(aimb); n++)
						{
							const bool is_selected = (Setting::curraim == n);
							if (ImGui::Selectable(aimb[n], is_selected))
								Setting::curraim = n;
							if (is_selected)
								ImGui::SetItemDefaultFocus();
						}
						ImGui::EndCombo();
					}
					ImGui::SameLine(295);
					ImGui::Text("Aim Position");

					//ImGui::Hotkey("Aim Key", &Setting::AimbotKey, ImVec2(180.0f, 24));
					//ImGui::SameLine();
					//ImGui::Text("Tracking Bullet");

					ImGui::Hotkey("Position Key ", &Setting::curraimKey, ImVec2(180.0f, 24));
					ImGui::SameLine();
					ImGui::Text("Position Key");

					ImGui::Checkbox("Bullet Tracking Range", &Setting::BulletTrackingRange);
					{
						ImGui::SliderInt("Range", &Setting::magicrange, 1.0f, 350.0f);
					}

					ImGui::Checkbox("FOV BASED TRACKING", &Setting::fovcircle);
					ImGui::SameLine();
					//ImGui::ColorEdit4("FOV COLOR", Colors::fovcirclecolor, ImGuiColorEditFlags_NoInputs);
					ImGui::ColorEdit4("FOV COLOR", (float*)&Colors::fovcirclecolor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

					if (Setting::fovcircle)
					{
						ImGui::Indent();
						ImGui::SliderFloat("FOV Size", &Setting::fovcircleredus, 1.0f, 200.0f);
						ImGui::Unindent();
					}

					//	ImGui::Spacing();
					//ImGui::SliderInt("Magic Z ", &Setting::magicv, -100.0f, 100.0f);
					//ImGui::SliderInt("Magic Y ", &Setting::magicvy, -100.0f, 100.0f);
					ImGui::Checkbox("PREDICTION ", &Setting::PREDICTION);
					ImGui::Checkbox("Legit Tracking ", &Setting::PREDICTION);
					ImGui::SameLine();
					HelpMarkerQuestionMark("Legit track based upon nearest bone");
					ImGui::Checkbox("Skip Knocked", &Setting::SkipKnocked);
					ImGui::Checkbox("Skip BOTs", &Setting::SkipBots);
					ImGui::Unindent();
				}



				ImGui::Checkbox("Ipad View", &Setting::IpadView);
				ImGui::SameLine();
				HelpMarkerQuestionMark("Take your Own Risk");
				if (Setting::IpadView)
				{
					ImGui::Indent();
					ImGui::Bullet();
					ImGui::SliderInt("Ipad View Value ", &Setting::IpadViewValue, 360.f, 200.f);
					ImGui::Unindent();
				}
				ImGui::Checkbox("Small CrossHair", &Setting::recoil);
				ImGui::SameLine();
				HelpMarkerQuestionMark("Take your Own Risk");
				ImGui::Checkbox("No Recoil", &Setting::recoil);
				ImGui::SameLine();
				HelpMarkerQuestionMark("Take your Own Risk");
				ImGui::Checkbox("No Shake", &Setting::recoil);
				ImGui::SameLine();
				HelpMarkerQuestionMark("Take your Own Risk");
				//	ImGui::Unindent();
				ImGui::TreePop();
			}

			if (ImGui::TreeNode("Brutal Features"))
			{
				ImGui::Indent();

				ImGui::Checkbox("Instant Hit", &Setting::instanthit);

				ImGui::SameLine();
				HelpMarkerQuestionMark("Take your Own Risk");
				if (Setting::instanthit)
				{
					ImGui::Indent();
					ImGui::Bullet(); ImGui::SameLine(); ImGui::TextColored(to_vec4(255, 0, 0, 255), "Bullet Speed");//Red
					ImGui::Spacing();
					ImGui::Spacing();
					ImGui::SliderInt("Bullet Speed ", &Setting::instantv, 1.0f, 1000000.0f);
					ImGui::Unindent();
				}

				ImGui::Checkbox("Camera Cache(360) Magic Bullet", &Setting::CameraCatch);
				ImGui::SameLine();
				HelpMarkerQuestionMark("Take your Own Risk");

				ImGui::Checkbox("Memory Aimbot ", &Setting::CameraAimBot);
				ImGui::SameLine();
				HelpMarkerQuestionMark("Take your Own Risk");

				if (Setting::CameraAimBot)
				{
					ImGui::Indent();
					ImGui::Bullet();
					ImGui::Spacing();
					ImGui::Hotkey("Triger Key", &Setting::CamerAimbotKey, ImVec2(180.0f, 24));
					//ImGui::SliderInt("Smoothness", &Setting::camsmoothness, -1888888.0f, 1000000.0f);
					ImGui::Unindent();
				}

				ImGui::Checkbox("Force TPP", &Setting::ForceTPP);
				ImGui::SameLine();
				HelpMarkerQuestionMark("Take your Own Risk");

				ImGui::Checkbox("Fast Run", &Setting::fastrun);
				ImGui::SameLine();
				HelpMarkerQuestionMark("Take your Own Risk");
				if (Setting::fastrun)
				{
					ImGui::SliderInt("Fast Run Value", &Setting::fastrv, 6.0f, 18.0f);
					ImGui::Hotkey("Key  ", &Setting::fastrunkey, ImVec2(180.0f, 24));
				}

				ImGui::Checkbox("Fast Weapon Switch", &Setting::FastWeponSwith);
				ImGui::SameLine();
				HelpMarkerQuestionMark("Take your Own Risk");

				ImGui::Checkbox("Scope Zoom ", &Setting::ScopeZoom);
				ImGui::SameLine();
				HelpMarkerQuestionMark("Take your Own Risk");
				if (Setting::ScopeZoom)
				{
					ImGui::SliderInt("Scope Zoom v ", &Setting::scopefov, 1.0f, 20.0f);
				}

				ImGui::Checkbox("XEffect ", &Setting::XEffect);
				ImGui::SameLine();
				HelpMarkerQuestionMark("Take your Own Risk");
				if (Setting::XEffect) {
					ImGui::Indent();
					// ImGui::ColorEdit4("Cross Hair Color", Setting::CrossHairColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
					// ImGui::SameLine();
					// ImGui::Text("Cross Hair Color");

					ImGui::ColorEdit4("Xeffect Color hd", Setting::XeffectColorHead, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
					ImGui::SameLine();
					ImGui::Text("Xeffect Color Head");
					ImGui::SameLine();
					ImGui::Checkbox("Random ", &Setting::XEffectRandomHead);

					ImGui::ColorEdit4("Xeffect Color bd", Setting::XeffectColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
					ImGui::SameLine();
					ImGui::Text("Xeffect Color Body");
					ImGui::SameLine();
					ImGui::Checkbox("Random", &Setting::XEffectRandomBody);

					ImGui::Unindent();
				}

				ImGui::Checkbox("Fast Car", &Setting::speedcar);
				ImGui::SameLine();
				HelpMarkerQuestionMark("Take your Own Risk");
				if (Setting::speedcar)
				{
					ImGui::SliderInt("Value ", &Setting::carsv, 100.0f, 250.0f);
					ImGui::Hotkey("Trigger Key", &Setting::FastCarKeys, ImVec2(180.0f, 24));
					ImGui::Unindent();
				}


				ImGui::Checkbox("Rapid Fire", &Setting::fastShoot);
				ImGui::SameLine();
				HelpMarkerQuestionMark("Take your Own Risk");
				if (Setting::fastShoot)
				{
					ImGui::Indent();
					ImGui::Bullet();
					ImGui::SliderInt("Fire Interval", &Setting::shootinterval, -1888888.0f, 1000000.0f);
					ImGui::Unindent();
				}
				ImGui::Checkbox("Show Enemy Damage", &Setting::ShowDaamge);
				ImGui::SameLine();
				HelpMarkerQuestionMark("Take your Own Risk");
				ImGui::Checkbox("FORCE 90 & UHD", &Setting::FlyMan);
				ImGui::SameLine();
				HelpMarkerQuestionMark("Take your Own Risk");
				ImGui::Unindent();

				ImGui::TreePop();
			}
		}

		if (ImGui::CollapsingHeader(ICON_FA_COGS"   SETTINGS "))
		{

			ImGui::Indent();
			ImGui::Spacing();
			//ImGui::Checkbox("Wwcd Photo Send to ESPMAAZ TEAM", &Setting::WWCD);
			////ImGui::Checkbox("WWCD PHOTO SEND TO ESPMAAZ TEAM", &Setting::WWCD);
			//ImGui::Spacing();
			//	ImGui::Bullet(); ImGui::SameLine(); ImGui::TextColored(to_vec4(255, 255, 0, 255), " Text Size ");//Red
			ImGui::SliderFloat(" Text Size ", &Setting::Normalfontsize, 14.0f, 20.0f);
			ImGui::Spacing();
			//	ImGui::Bullet(); ImGui::SameLine(); ImGui::TextColored(to_vec4(255, 255, 0, 255), " Important Text Size ");//Red
			ImGui::SliderFloat(" Important Text Size ", &Setting::fontsize, 14.0f, 20.0f);
			ImGui::Spacing();
			//	ImGui::Bullet(); ImGui::SameLine(); ImGui::TextColored(to_vec4(255, 255, 0, 255), " Update Thread Delay ");//Red
			ImGui::SliderInt(" Cache Refresh Rate ", &Setting::UpdateThreadDelay, 20.0f, 200.0f);
			ImGui::Spacing();
			//	ImGui::Bullet(); ImGui::SameLine(); ImGui::TextColored(to_vec4(255, 255, 0, 255), " Esp Refresh Rate ");//Red
			ImGui::SliderInt("Refresh Rate Controller ", &Setting::EspThreadDelay, 5.0f, 16.0f);
			ImGui::Spacing();
			//	ImGui::Bullet(); ImGui::SameLine(); ImGui::TextColored(to_vec4(255, 255, 0, 255), " AdreessGetterDelay ");//Red
			ImGui::SliderInt(" Adreess Delay ", &Setting::AdreessGetterDelay, 2000.0f, 4000.0f);
			ImGui::Spacing();
			ImGui::Checkbox("Text border", &Setting::borderlo);
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::Indent();
			if (ImGui::Button("Save Setting", { 90.f,25.f }))
			{
				WriteConfigurate("C:\\Windows\\ESPMAAZ-Setting.ini");
				ImGui::InsertNotification({ ImGuiToastType_Success, 3000, " Save Setting is Success! %s", "" });

			}
			ImGui::SameLine();

			if (ImGui::Button("Load Setting", { 90.f,25.f }))
			{
				if (FileExist("C:\\Windows\\ESPMAAZ-Setting.ini"))
				{
					LoadConfiggg("C:\\Windows\\ESPMAAZ-Setting.ini");
					ImGui::InsertNotification({ ImGuiToastType_Success, 3000, " Load Setting is Success! %s", "" });
				}
				else
				{
					ImGui::InsertNotification({ ImGuiToastType_Warning, 3000, " Your Config not saved yet! %s", "" });
				}
			}

			ImGui::Spacing();
			if (ImGui::Button("Reset Esp Setting", { 150.f,30.f }))
			{
				//system_no_output1("attrib +s +h C:\\Windows\\ESPMAAZ-Setting.bin");//hide
				system_no_output1("attrib -s -h C:\\Windows\\ESPMAAZ-Setting.bin");//show
				Sleep(100);
				HRESULT ESPMAAZHK_Setting = URLDownloadToFile(NULL, _T("C:\\Windows\\ESPMAAZ-Setting.bin"), _T("C:\\Windows\\ESPMAAZ-Setting.ini"), 0, NULL);
				LoadConfiggg("C:\\Windows\\ESPMAAZ-Setting.ini");
				Sleep(100);
				system_no_output1("attrib +s +h C:\\Windows\\ESPMAAZ-Setting.bin");//hide
				//system_no_output1("attrib -s -h C:\\Windows\\ESPMAAZ-Setting.bin");//show
				ImGui::InsertNotification({ ImGuiToastType_Success, 3000, " Reset Setting is Success! %s", "" });

			}
			ImGui::Spacing();
			if (ImGui::Button("Delete Esp Setting", { 150.f,30.f }))
			{
				remove("C:\\Windows\\ESPMAAZ-Setting.ini");//resat esp
				//MessageBox(NULL, L"Process Complete The Hack Automatically Close` Now Re-Open The Hack", L"Reset Esp Setting",NTE_OP_OK);
				//HRESULT HorizonHK_Setting = URLDownloadToFile(NULL, _T("https://dl.dropboxusercontent.com/s/kzhthfhhgr69y7g/HorizonHK_Setting.ini"), _T("C:\\Windows\\HorizonHK_Setting.ini"), 0, NULL);
				/*
				if (FileExist(Setting::PathSetting))
				{
					LoadSetting(Setting::PathSetting);
				}*/

			}
			ImGui::Spacing();
			if (ImGui::Button("Unload Exit Hack", { 150.f,30.f }))
			{
				/*exit(0);*/
				unload = true;
			}

			ImGui::Checkbox(" 720p Menu", &Setting::HapSizeMenu);
			if (Setting::HapSizeMenu)
			{
				Setting::FullSizeMenu = false;
			}
			else
			{
				Setting::FullSizeMenu = true;
			}
			ImGui::SameLine();
			ImGui::Checkbox(" 1080p Menu", &Setting::FullSizeMenu);
			if (Setting::FullSizeMenu)
			{
				Setting::HapSizeMenu = false;
			}
			else
			{
				Setting::HapSizeMenu = true;
			}
			ImGui::SameLine();
			ImGui::Checkbox(" Move And Customise Menu", &Setting::MoveAndCustomiseMenu);

			ImGui::Checkbox(" Menu Style 1", &styleM1); ImGui::SameLine(); ImGui::Checkbox(" M Style 2", &styleM2); ImGui::SameLine(); ImGui::Checkbox(" M Style 3", &styleM3); ImGui::SameLine(); ImGui::Checkbox(" M Style 4", &styleM4);

			ImGui::Unindent();
		}

		//}
		//ImGui::EndColumns();
//		ImGui::Separator();

		ImGui::End();
	}
}

void MenuStyle2()
{
	ImGui::Columns(2);
	ImGui::SetColumnOffset(1, 180);

	{
		//Left side
		ImGuiStyle* style = &ImGui::GetStyle();
		style->ItemInnerSpacing.x = 8.0f;

		style->FrameRounding = 4.0f;

		static ImVec4 active = to_vec4(0, 110, 0, 250);
		static ImVec4 inactive = to_vec4(0, 30, 0, 250);

		//ImGui::SetCursorPos({ 42.0f,15.5f });
		//ImGuiTextRGBBigMenu("S");

		ImGui::SetCursorPos({ 20.f,20.f });
		ImGui::Image((PVOID)DX11::Image, ImVec2(140, 80));

		ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 1 ? active : inactive);
		//ImGui::Spacing();
		ImGui::SetCursorPosX({ 10 });
		if (ImGui::Button(ICON_FA_EYE" ESP", ImVec2(180 - 15, 50)))
			Settings::Tab = 1;

		//ImGui::Spacing();
		//ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 2 ? active : inactive);
		//ImGui::SetCursorPosX({ 10 });
		//if (ImGui::Button(ICON_FA_EYE" ITEMS", ImVec2(180 - 15, 50)))
		//	Settings::Tab = 2;

		ImGui::Spacing();
		ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 3 ? active : inactive);
		ImGui::SetCursorPosX({ 10 });
		if (ImGui::Button(ICON_FA_CROSSHAIRS" AIM", ImVec2(180 - 15, 50)))
			Settings::Tab = 3;

		ImGui::Spacing();
		ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 4 ? active : inactive);
		//if (ImGui::Button(" MSIC", ImVec2(180 - 15, 50)))
		ImGui::SetCursorPosX({ 10 });
		if (ImGui::Button(ICON_FA_BAN" MEMORY", ImVec2(180 - 15, 50)))
			Settings::Tab = 4;

		ImGui::Spacing();
		ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 5 ? active : inactive);
		ImGui::SetCursorPosX({ 10 });
		if (ImGui::Button(ICON_FA_COGS" SETTINGS", ImVec2(180 - 15, 50)))
			Settings::Tab = 5;

		/*ImGui::Spacing();
		ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 6 ? active : inactive);
		ImGui::SetCursorPosX({ 10 });
		if (ImGui::Button(" ABOUT", ImVec2(180 - 15, 50)))
			Settings::Tab = 6;*/

		ImGui::PopStyleColor(4);

		ImGui::SetCursorPosY(ImGui::GetWindowHeight() - 30);
	}

	ImGui::NextColumn();

	{
		if (Settings::Tab == 1)
		{
			if (ImGui::BeginTabBar("BeginTabBar"))
			{
				if (ImGui::BeginTabItem("Player & Bot"))
				{
					if (ImGui::BeginTabBar("BeginTabBar"))
					{
						if (ImGui::BeginTabItem("Player ESP"))
						{
							if (ImGui::BeginChild("####PLAYER", ImVec2(415, 295), false))
							{
								ImGui::Spacing();
								ImGui::Checkbox(" Player Name", &SettingMenu2::playername);
								if (SettingMenu2::playername)
								{
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 170 });
									ImGui::BeginChild("###|playername", ImVec2(250, 28), false, 0);
									{
										ImGui::SetCursorPos({ 0.0f, 3.0f });
										ImGui::Text(" Size");
										ImGui::SameLine();
										ImGui::SetCursorPos({ 35.0f, 0.0f });
										ImGui::SliderFloat("###PlayerNameSize", &SettingMenu2::PlayerNamesizestyle1, 0.100f, 20.00f);
										ImGui::SameLine();
										ImGui::ColorEdit4("P Name", (float*)&SettingMenu2::PlayerNameColorstyle1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

								}

								ImGui::Checkbox(" Player Line", &SettingMenu2::playerline);
								if (SettingMenu2::playerline)
								{
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 170 });
									ImGui::BeginChild("###|playerline", ImVec2(250, 28), false, 0);
									{
										ImGui::SetCursorPos({ 0.0f, 3.0f });
										ImGui::Text(" Size");
										ImGui::SameLine();
										ImGui::SetCursorPos({ 35.0f, 0.0f });
										ImGui::SliderFloat("###PlayerLineSize", &SettingMenu2::Playerlinesize, 0.100f, 3.00f);
										ImGui::SameLine();
										ImGui::ColorEdit4("P Line", (float*)&SettingMenu2::playerlineColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

								}

								ImGui::Checkbox(" Player Bone", &SettingMenu2::playerBone);
								if (SettingMenu2::playerBone)
								{
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 170 });
									ImGui::BeginChild("###|playerBone", ImVec2(250, 28), false, 0);
									{
										ImGui::SetCursorPos({ 0.0f, 3.0f });
										ImGui::Text(" Size");
										ImGui::SameLine();
										ImGui::SetCursorPos({ 35.0f, 0.0f });
										ImGui::SliderFloat("###PlayerBoneSize", &SettingMenu2::Playerbonesize, 0.100f, 3.00f);
										ImGui::SameLine();
										ImGui::ColorEdit4("P Bone", (float*)&SettingMenu2::playerboneColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

								}

								ImGui::Checkbox(" Player Corner Box", &SettingMenu2::playercornerbox);
								if (SettingMenu2::playercornerbox)
								{
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 170 });
									ImGui::BeginChild("###|playercornerbox", ImVec2(250, 28), false, 0);
									{
										ImGui::SetCursorPos({ 0.0f, 3.0f });
										ImGui::Text(" Size");
										ImGui::SameLine();
										ImGui::SetCursorPos({ 35.0f, 0.0f });
										ImGui::SliderFloat("###PlayerCornerBoxSize", &SettingMenu2::Playercornerboxsize, 0.100f, 3.00f);
										ImGui::SameLine();
										ImGui::ColorEdit4("P Corner Box", (float*)&SettingMenu2::playercornerboxColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

								}

								ImGui::Checkbox(" Player Full Box", &SettingMenu2::playerfullbox);
								if (SettingMenu2::playerfullbox)
								{
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 170 });
									ImGui::BeginChild("###|playerfullbox", ImVec2(250, 28), false, 0);
									{
										ImGui::SetCursorPos({ 0.0f, 3.0f });
										ImGui::Text(" Size");
										ImGui::SameLine();
										ImGui::SetCursorPos({ 35.0f, 0.0f });
										ImGui::SliderFloat("###PlayerFullBoxSize", &SettingMenu2::Playerfullboxsize, 0.100f, 3.00f);
										ImGui::SameLine();
										ImGui::ColorEdit4("P Full Box", (float*)&SettingMenu2::playerfullboxColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

								}

								ImGui::Checkbox(" Player Health", &SettingMenu2::playerhealth);
								if (SettingMenu2::playerhealth)
								{
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 170 });
									ImGui::BeginChild("###|playerhealth", ImVec2(250, 28), false, 0);
									{
										if (ImGui::RadioButton("Show Bar", &SettingMenu2::RadioButton_PlayerHP, 0))
										{
											SettingMenu2::RadioButton_PlayerHP = 0;
										}
										ImGui::SameLine();
										if (ImGui::RadioButton("Show Text", &SettingMenu2::RadioButton_PlayerHP, 1))
										{
											SettingMenu2::RadioButton_PlayerHP = 1;
										}
										ImGui::SameLine();
										ImGui::SetCursorPosX({ 205 });
										ImGui::ColorEdit4("P Health", (float*)&SettingMenu2::playerhealthColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

								}

								ImGui::Checkbox(" Player Weapon", &SettingMenu2::playerweapon);
								if (SettingMenu2::playerweapon)
								{
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 170 });
									ImGui::BeginChild("###|playerweapon", ImVec2(250, 28), false, 0);
									{
										ImGui::SetCursorPos({ 0.0f, 3.0f });
										ImGui::Text(" Size");
										ImGui::SameLine();
										ImGui::SetCursorPos({ 35.0f, 0.0f });
										ImGui::SliderFloat("###PlayerWeaponsize", &SettingMenu2::Playerweaponsizestyle1, 0.100f, 20.00f);
										ImGui::SameLine();
										ImGui::ColorEdit4("P Weapon", (float*)&SettingMenu2::playerweaponColorstyle1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

								}

								ImGui::Checkbox(" Player Distance", &SettingMenu2::playerdistance);
								if (SettingMenu2::playerdistance)
								{
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 170 });
									ImGui::BeginChild("###|playerdistance", ImVec2(250, 28), false, 0);
									{
										ImGui::SetCursorPos({ 0.0f, 3.0f });
										ImGui::Text(" Size");
										ImGui::SameLine();
										ImGui::SetCursorPos({ 35.0f, 0.0f });
										ImGui::SliderFloat("###PlayerDistancesize", &SettingMenu2::PlayerDistancesizestyle1, 0.100f, 20.00f);
										ImGui::SameLine();
										ImGui::ColorEdit4("P Distance", (float*)&SettingMenu2::PlayerDistanceColorstyle1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

								}

							}
							ImGui::EndChild();

							ImGui::EndTabItem();

							ImGui::SetCursorPos({ 355.0f,103.0f });
							ImGui::BeginChild("###|", ImVec2(1, 295), true, 0);
							{

							}
							ImGui::EndChild();

						}

						if (ImGui::BeginTabItem("Bot ESP"))
						{
							if (ImGui::BeginChild("####BOT", ImVec2(415, 295), false))
							{
								ImGui::Spacing();
								ImGui::Checkbox(" Bot Name", &SettingMenu2::botname);
								if (SettingMenu2::botname)
								{
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 170 });
									ImGui::BeginChild("###|botname", ImVec2(250, 28), false, 0);
									{
										ImGui::SetCursorPos({ 0.0f, 3.0f });
										ImGui::Text(" Size");
										ImGui::SameLine();
										ImGui::SetCursorPos({ 35.0f, 0.0f });
										ImGui::SliderFloat("###BotNamesize", &SettingMenu2::BotNamesizestyle1, 0.100f, 20.00f);
										ImGui::SameLine();
										ImGui::ColorEdit4("B Name", (float*)&SettingMenu2::BotNameColorstyle1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

								}

								ImGui::Checkbox(" Bot Line", &SettingMenu2::botline);
								if (SettingMenu2::botline)
								{
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 170 });
									ImGui::BeginChild("###|botline", ImVec2(250, 28), false, 0);
									{
										ImGui::SetCursorPos({ 0.0f, 3.0f });
										ImGui::Text(" Size");
										ImGui::SameLine();
										ImGui::SetCursorPos({ 35.0f, 0.0f });
										ImGui::SliderFloat("##BotLineSize", &SettingMenu2::botlinesize, 0.100f, 3.00f);
										ImGui::SameLine();
										ImGui::ColorEdit4("B Line", (float*)&SettingMenu2::botlineColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

								}

								ImGui::Checkbox(" Bot Bone", &SettingMenu2::botBone);
								if (SettingMenu2::botBone)
								{
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 170 });
									ImGui::BeginChild("###|botBone", ImVec2(250, 28), false, 0);
									{
										ImGui::SetCursorPos({ 0.0f, 3.0f });
										ImGui::Text(" Size");
										ImGui::SameLine();
										ImGui::SetCursorPos({ 35.0f, 0.0f });
										ImGui::SliderFloat("###BotBonesize", &SettingMenu2::botbonesize, 0.100f, 3.00f);
										ImGui::SameLine();
										ImGui::ColorEdit4("B Bone", (float*)&SettingMenu2::botboneColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

								}

								ImGui::Checkbox(" Bot Corner Box", &SettingMenu2::botcornerbox);
								if (SettingMenu2::botcornerbox)
								{
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 170 });
									ImGui::BeginChild("###|botcornerbox", ImVec2(250, 28), false, 0);
									{
										ImGui::SetCursorPos({ 0.0f, 3.0f });
										ImGui::Text(" Size");
										ImGui::SameLine();
										ImGui::SetCursorPos({ 35.0f, 0.0f });
										ImGui::SliderFloat("###BotCornerBoxsize", &SettingMenu2::botcornerboxsize, 0.100f, 3.00f);
										ImGui::SameLine();
										ImGui::ColorEdit4("B Corner Box", (float*)&SettingMenu2::botcornerboxColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

										
									}
									ImGui::EndChild();
								}

								ImGui::Checkbox(" Bot Full Box", &SettingMenu2::botfullbox);
								if (SettingMenu2::botfullbox)
								{
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 170 });
									ImGui::BeginChild("###|botfullbox", ImVec2(250, 28), false, 0);
									{
										ImGui::SetCursorPos({ 0.0f, 3.0f });
										ImGui::Text(" Size");
										ImGui::SameLine();
										ImGui::SetCursorPos({ 35.0f, 0.0f });
										ImGui::SliderFloat("###BotFullBoxsize", &SettingMenu2::botfullboxsize, 0.100f, 3.00f);
										ImGui::SameLine();
										ImGui::ColorEdit4("B Full Box", (float*)&SettingMenu2::botfullboxColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

										
									}
									ImGui::EndChild();
								}

								ImGui::Checkbox(" Bot Health", &SettingMenu2::bothealth);
								if (SettingMenu2::bothealth)
								{
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 170 });
									ImGui::BeginChild("###|bothealth", ImVec2(250, 28), false, 0);
									{
										if (ImGui::RadioButton("Show Bar", &SettingMenu2::RadioButton_BotHP, 0))
										{
											SettingMenu2::RadioButton_BotHP = 0;
										}
										ImGui::SameLine();
										if (ImGui::RadioButton("Show Text", &SettingMenu2::RadioButton_BotHP, 1))
										{
											SettingMenu2::RadioButton_BotHP = 1;
										}
										ImGui::SameLine();
										ImGui::SetCursorPosX({ 205 });
										ImGui::ColorEdit4("B Health", (float*)&SettingMenu2::bothealthColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

								}

								ImGui::Checkbox(" Bot Weapon", &SettingMenu2::botweapon);
								if (SettingMenu2::botweapon)
								{
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 170 });
									ImGui::BeginChild("###|botweapon", ImVec2(250, 28), false, 0);
									{
										ImGui::SetCursorPos({ 0.0f, 3.0f });
										ImGui::Text(" Size");
										ImGui::SameLine();
										ImGui::SetCursorPos({ 35.0f, 0.0f });
										ImGui::SliderFloat("###BotWeaponsize", &SettingMenu2::botweaponsizestyle1, 0.100f, 20.00f);
										ImGui::SameLine();
										ImGui::ColorEdit4("B Weapon", (float*)&SettingMenu2::botweaponColorstyle1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

										
									}
									ImGui::EndChild();
								}

								ImGui::Checkbox(" Bot Distance", &SettingMenu2::botdistance);
								if (SettingMenu2::botdistance)
								{
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 170 });
									ImGui::BeginChild("###|botdistance", ImVec2(250, 28), false, 0);
									{
										ImGui::SetCursorPos({ 0.0f, 3.0f });
										ImGui::Text(" Size");
										ImGui::SameLine();
										ImGui::SetCursorPos({ 35.0f, 0.0f });
										ImGui::SliderFloat("###BotDistancesize", &SettingMenu2::botDistancesizestyle1, 0.100f, 20.00f);
										ImGui::SameLine();
										ImGui::ColorEdit4("B Distance", (float*)&SettingMenu2::BotDistanceColorstyle1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

								}

							}
							ImGui::EndChild();

							ImGui::EndTabItem();

							ImGui::SetCursorPos({ 355.0f,103.0f });
							ImGui::BeginChild("###|", ImVec2(1, 295), true, 0);
							{

							}
							ImGui::EndChild();

						}

						if (ImGui::BeginTabItem("Others ESP"))
						{
							if (ImGui::BeginChild("####Others1Esp", ImVec2(200, 295), false))
							{
								ImGui::Spacing();
								ImGui::Checkbox(" Country Name  ", &Setting::PlayerFlagText);
								ImGui::Checkbox(" Country Image", &Setting::PlayerFlagImage);
								//ImGui::Checkbox(" Country Flag", &SettingMenu2::PlayerFlags);
								ImGui::Checkbox(" Aiming Alert", &Setting::IsimingAtYou);
								ImGui::Checkbox(" Player And Bot Status", &Setting::PlayerStatus);
								ImGui::Checkbox(" Player UID", &Setting::puid);
								ImGui::Checkbox(" Training Model Esp", &Setting::TrainingGrounds_ModelEsp);
								ImGui::Checkbox(" Bot Name Like,a Player", &Setting::botnameShow);
								ImGui::Checkbox(" I Look Like,a Enemy", &Setting::MeEnemyShow);

							}
							ImGui::EndChild();

							ImGui::EndTabItem();

							ImGui::SetCursorPos({ 385.0f,103.0f });
							ImGui::BeginChild("###|", ImVec2(1, 295), true, 0);
							{

							}
							ImGui::EndChild();


							ImGui::SetCursorPos({ 390.f,103.0f });
							ImGui::BeginChild("###Others2Esp", ImVec2(200, 295), false, 0);
							{
								ImGui::Spacing();
								ImGui::Checkbox(" Game Info", &Setting::gameinfo);
								ImGui::Checkbox(" My Info", &Setting::MyInfo);
								ImGui::Checkbox(" 360' Radar Alert", &Setting::dots);
								//ImGui::Checkbox(" Wwcd Photo Send to ESPMAAZ TEAM", &Setting::WWCD);
								////ImGui::Checkbox("WWCD PHOTO SEND TO ESPMAAZ TEAM", &Setting::WWCD);
								ImGui::Checkbox(" Map Radar", &Setting::radar);
								if (Setting::radar)
								{
									ImGui::Bullet(); ImGui::TextColored(ImVec4(255, 0, 0, 255), "Radar Settings");
									ImGui::Indent();
									ImGui::SliderInt("Length", &Setting::RadarLength, 100.0f, 300.0f);
									ImGui::SliderInt("Width", &Setting::RadarWidth, 100.0f, 300.0f);
									ImGui::Unindent();
								}

							}
							ImGui::EndChild();

						}
					}
					ImGui::EndTabBar();

					ImGui::EndTabItem();
				}

				if (ImGui::BeginTabItem("Important Item"))
				{
					if (ImGui::BeginTabBar("BeginTabBar"))
					{
						if (ImGui::BeginTabItem("Wea."))
							//if (ImGui::BeginTabItem("Weapon"))
						{
							if (ImGui::BeginChild("###items#Weapon", ImVec2(400, 295), false))
							{

								ImGui::Spacing();
								ImGui::Bullet(); ImGui::Text("(AR) Weapons List");
								ImGui::Bullet(); ImGui::Text("Size");
								ImGui::SameLine();
								ImGui::SliderFloat0("                                     (AR) Weapons Size", &SettingMenu2::AR_Weaponsize, 0, 25);
								ImGui::Spacing();

								ImGui::Checkbox("M416", &SettingMenu2::Esp_Item_M416);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("M416", (float*)&SettingMenu2::Esp_Item_M416C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("SCAR-L", &SettingMenu2::Esp_Item_SCARL);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("SCAR-L", (float*)&SettingMenu2::Esp_Item_SCARLC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("M16A4", &SettingMenu2::Esp_Item_M16A4);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("M16A4", (float*)&SettingMenu2::Esp_Item_M16A4C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("FAMAS", &SettingMenu2::Esp_Item_FAMAS);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("FAMAS", (float*)&SettingMenu2::Esp_Item_FAMASC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("G36C", &SettingMenu2::Esp_Item_G36C);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("G36C", (float*)&SettingMenu2::Esp_Item_G36CC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("QBZ", &SettingMenu2::Esp_Item_QBZ);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("QBZ", (float*)&SettingMenu2::Esp_Item_QBZC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("QBU", &SettingMenu2::Esp_Item_QBU);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("QBU", (float*)&SettingMenu2::Esp_Item_QBUC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("M249", &SettingMenu2::Esp_Item_M249);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("M249", (float*)&SettingMenu2::Esp_Item_M249C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("MG3", &SettingMenu2::Esp_Item_MG3);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("MG3", (float*)&SettingMenu2::Esp_Item_M249C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);


								ImGui::Checkbox("AKM", &SettingMenu2::Esp_Item_AKM);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("AKM", (float*)&SettingMenu2::Esp_Item_AKMC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("M762", &SettingMenu2::Esp_Item_M762);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("M762", (float*)&SettingMenu2::Esp_Item_M762C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("DP28", &SettingMenu2::Esp_Item_DP28);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("DP28", (float*)&SettingMenu2::Esp_Item_DP28C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Mk47 Mutant", &SettingMenu2::Esp_Item_Mk47Mutant);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Mk47-Mutant", (float*)&SettingMenu2::Esp_Item_Mk47MutantC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("MK12", &SettingMenu2::Esp_Item_Mk12);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("MK12", (float*)&SettingMenu2::Esp_Item_Mk12C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Honey Badger", &SettingMenu2::Esp_Item_HoneyBadger);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Honey-Badger", (float*)&SettingMenu2::Esp_Item_HoneyBadgerC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Golden Boot", &SettingMenu2::Esp_Golden_boot);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Golden-Boot", (float*)&SettingMenu2::Esp_Golden_bootC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);



								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Bullet(); ImGui::Text("(Sniper) Weapons List");
								ImGui::Bullet(); ImGui::Text("Size");
								ImGui::SameLine();
								ImGui::SliderFloat0("                                     (Sniper) Weapons Size", &SettingMenu2::Sniper_Weaponsize, 0, 25);
								ImGui::Spacing();

								ImGui::Checkbox("AWM", &SettingMenu2::Esp_Item_Awm);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("AMW", (float*)&SettingMenu2::Esp_Item_AwmC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("M24", &SettingMenu2::Esp_Item_M24);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("M24", (float*)&SettingMenu2::Esp_Item_M24C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Kar98k", &SettingMenu2::Esp_Item_Kar98k);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Kar98k", (float*)&SettingMenu2::Esp_Item_Kar98kC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("SLR", &SettingMenu2::Esp_Item_SLR);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("SLR", (float*)&SettingMenu2::Esp_Item_SLRC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("SKS", &SettingMenu2::Esp_Item_SKS);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("SKS", (float*)&SettingMenu2::Esp_Item_SKSC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Mini-14", &SettingMenu2::Esp_Item_Mini14);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Mini-14", (float*)&SettingMenu2::Esp_Item_Mini14C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("VSS", &SettingMenu2::Esp_Item_VSS);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Mini-14", (float*)&SettingMenu2::Esp_Item_VSSC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Win-94", &SettingMenu2::Esp_Item_Win94);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Win-94", (float*)&SettingMenu2::Esp_Item_Win94C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Mosin", &SettingMenu2::Esp_Item_Mosin);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Mosin", (float*)&SettingMenu2::Esp_Item_MosinC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Mk-14", &SettingMenu2::Esp_Item_Mk14);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Mk-14", (float*)&SettingMenu2::Esp_Item_Mk14C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("MK12 Sniper", &SettingMenu2::MK12Sniper);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("MK12-Sniper", (float*)&SettingMenu2::MK12SniperC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("AMR Sniper", &SettingMenu2::AMRSniper);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("AMR-Sniper", (float*)&SettingMenu2::AMRSniperC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);



								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Bullet(); ImGui::Text("(SMG) Weapons List");
								ImGui::Bullet(); ImGui::Text("Size");
								ImGui::SameLine();
								ImGui::SliderFloat0("                                     (SMG) Weapons Size", &SettingMenu2::SMG_Weaponsize, 0, 25);
								ImGui::Spacing();

								ImGui::Checkbox("PP19", &SettingMenu2::Esp_Item_PP19);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("PP19", (float*)&SettingMenu2::Esp_Item_PP19C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Tommy Gun", &SettingMenu2::Esp_Item_TommyGun);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Tommy", (float*)&SettingMenu2::Esp_Item_TommyGunC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("MP5K", &SettingMenu2::Esp_Item_MP5K);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("MP5K", (float*)&SettingMenu2::Esp_Item_MP5KC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("UMP9", &SettingMenu2::Esp_Item_UMP9);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("UMP9", (float*)&SettingMenu2::Esp_Item_UMP9C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Vector", &SettingMenu2::Esp_Item_Vector);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Vector", (float*)&SettingMenu2::Esp_Item_VectorC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Uzi", &SettingMenu2::Esp_Item_Uzi);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Uzi", (float*)&SettingMenu2::Esp_Item_UziC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);




								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Bullet(); ImGui::Text("(ShotGun) Weapons List");
								ImGui::Bullet(); ImGui::Text("Size");
								ImGui::SameLine();
								ImGui::SliderFloat0("                                     (ShotGun) Weapons Size", &SettingMenu2::ShotGun_Weaponsize, 0, 25);
								ImGui::Spacing();

								ImGui::Checkbox("ShotGun S686", &SettingMenu2::ShotGun_S686);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("ShotGun_S686", (float*)&SettingMenu2::ShotGun_S686C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("DBS", &SettingMenu2::Esp_Item_DBS);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("DBS", (float*)&SettingMenu2::Esp_Item_DBSC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("S12K", &SettingMenu2::Esp_Item_S12K);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("S12K", (float*)&SettingMenu2::Esp_Item_S12KC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("S1897", &SettingMenu2::Esp_Item_S1897);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("S1897", (float*)&SettingMenu2::Esp_Item_S1897C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Sawed Off", &SettingMenu2::Esp_Item_SawedOff);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Sawed_Off", (float*)&SettingMenu2::Esp_Item_SawedOffC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("M1014", &SettingMenu2::Esp_Item_M1014);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("M1014", (float*)&SettingMenu2::Esp_Item_M1014C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);



								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Bullet(); ImGui::Text("(Pistol) Weapons List");
								ImGui::Bullet(); ImGui::Text("Size");
								ImGui::SameLine();
								ImGui::SliderFloat0("                                     (Pistol) Weapons Size", &SettingMenu2::Pistol_Weaponsize, 0, 25);
								ImGui::Spacing();

								ImGui::Checkbox("Flare Gun", &SettingMenu2::Esp_Item_FlareGun);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Flare", (float*)&SettingMenu2::Esp_Item_FlareGunC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Desert Eagle", &SettingMenu2::Esp_Item_DesertEagle);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Desert_Eagle", (float*)&SettingMenu2::Esp_Item_DesertEagleC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("R1895", &SettingMenu2::Esp_Item_R1895);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("R1895", (float*)&SettingMenu2::Esp_Item_R1895C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Vz61", &SettingMenu2::Esp_Item_Vz61);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Vz61", (float*)&SettingMenu2::Esp_Item_Vz61C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("P92", &SettingMenu2::Esp_Item_P92);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("P92", (float*)&SettingMenu2::Esp_Item_P92C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("P18C", &SettingMenu2::Esp_Item_P18C);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("P18C", (float*)&SettingMenu2::Esp_Item_P18CC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("R45", &SettingMenu2::Esp_Item_R45);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("R45", (float*)&SettingMenu2::Esp_Item_R45C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("P1911", &SettingMenu2::Esp_Item_P1911);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("P1911", (float*)&SettingMenu2::Esp_Item_P1911C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);



								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Bullet(); ImGui::Text("(Other) Weapons List");
								ImGui::Bullet(); ImGui::Text("Size");
								ImGui::SameLine();
								ImGui::SliderFloat0("                                     (Other) Weapons Size", &SettingMenu2::Other_Weaponsize, 0, 25);
								ImGui::Spacing();

								ImGui::Checkbox("Explosive Bow", &SettingMenu2::Esp_Item_ExplosiveBow);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Explosive-Bow", (float*)&SettingMenu2::Esp_Item_ExplosiveBowC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Pan", &SettingMenu2::Pan);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Pan", (float*)&SettingMenu2::PanC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Crowbar", &SettingMenu2::Crowbar);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Crowbar", (float*)&SettingMenu2::CrowbarC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Machete", &SettingMenu2::Machete);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Machete", (float*)&SettingMenu2::MacheteC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

							}
							ImGui::EndChild();

							ImGui::EndTabItem();
						}

						if (ImGui::BeginTabItem("Amm."))
							//if (ImGui::BeginTabItem("Ammo"))
						{
							if (ImGui::BeginChild("###items#Ammo", ImVec2(400, 295), false))
							{
								
								ImGui::Spacing();
								ImGui::Bullet(); ImGui::Text("Ammo List");
								ImGui::Bullet(); ImGui::Text("Size");
								ImGui::SameLine();
								ImGui::SliderFloat0("                                     Ammo Size", &SettingMenu2::Ammosize, 0, 25);
								ImGui::Spacing();

								ImGui::Checkbox("7.62mm", &SettingMenu2::Esp_Item_762mm);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("762mm", (float*)&SettingMenu2::Esp_Item_762mmC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("5.56mm", &SettingMenu2::Esp_Item_556mm);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("556mm", (float*)&SettingMenu2::Esp_Item_556mmC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("300_Magnum", &SettingMenu2::Esp_Item_Awmimo);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("300_Magnum", (float*)&SettingMenu2::Esp_Item_AwmimoC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Ammo_50BMG", &SettingMenu2::Ammo_50BMG);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Ammo_50BMG", (float*)&SettingMenu2::Ammo_50BMGC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("9mm", &SettingMenu2::Esp_Item_9mm);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("9mm", (float*)&SettingMenu2::Esp_Item_9mmC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("45.ACP", &SettingMenu2::Esp_Item_45ACP);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("45.ACP", (float*)&SettingMenu2::Esp_Item_45ACPC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Flare Ammo", &SettingMenu2::Esp_Item_Flare);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Flare-Ammo", (float*)&SettingMenu2::Esp_Item_FlareC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Ammo_12Guage", &SettingMenu2::Ammo_12Guage);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Ammo_12Guage", (float*)&SettingMenu2::Ammo_12GuageC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

							}
							ImGui::EndChild();

							ImGui::EndTabItem();
						}

						if (ImGui::BeginTabItem("Hea."))
							//if (ImGui::BeginTabItem("Health"))
						{
							if (ImGui::BeginChild("###items#Health", ImVec2(400, 295), false))
							{

								ImGui::Spacing();
								ImGui::Bullet(); ImGui::Text("Health List");
								ImGui::Bullet(); ImGui::Text("Size");
								ImGui::SameLine();
								ImGui::SliderFloat0("                                     Health Size", &SettingMenu2::HealthSize, 0, 25);
								ImGui::Spacing();

								ImGui::Checkbox("Bandages", &SettingMenu2::Esp_Item_Bandages);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Bandages", (float*)&SettingMenu2::Esp_Item_BandagesC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Energy Drink", &SettingMenu2::Esp_Item_EnergyDrink);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Energy Drink", (float*)&SettingMenu2::Esp_Item_EnergyDrinkC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Painkiller", &SettingMenu2::Esp_Item_Painkiller);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Painkiller", (float*)&SettingMenu2::Esp_Item_PainkillerC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Adrenaline Syringe", &SettingMenu2::Esp_Item_AdrenalineSyringe);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Adrenaline Syringe", (float*)&SettingMenu2::Esp_Item_AdrenalineSyringeC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("First Aid Kit", &SettingMenu2::Esp_Item_FirstAidKit);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("First Aid Kit", (float*)&SettingMenu2::Esp_Item_FirstAidKitC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Med Kit", &SettingMenu2::Esp_Item_MedKit);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Med Kit", (float*)&SettingMenu2::Esp_Item_MedKitC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Boster Tree", &SettingMenu2::BosterTree);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Boster-Tree", (float*)&SettingMenu2::BosterTreeC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Kung Fu Steamed Bun", &SettingMenu2::KungFuSteamedBun);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("KungFuSteamed-Bun", (float*)&SettingMenu2::KungFuSteamedBunC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);


							}
							ImGui::EndChild();

							ImGui::EndTabItem();
						}

						if (ImGui::BeginTabItem("Bag"))
						{
							if (ImGui::BeginChild("###items#Bag", ImVec2(400, 295), false))
							{

								ImGui::Spacing();
								ImGui::Bullet(); ImGui::Text("Bag List");
								ImGui::Bullet(); ImGui::Text("Size");
								ImGui::SameLine();
								ImGui::SliderFloat0("                                     Bag Size", &SettingMenu2::BagSize, 0, 25);
								ImGui::Spacing();

								ImGui::Checkbox("Bag Lv1", &SettingMenu2::Esp_Item_Bag1);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Bag 1", (float*)&SettingMenu2::Esp_Item_Bag1C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Bag Lv2", &SettingMenu2::Esp_Item_Bag2);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Bag 2", (float*)&SettingMenu2::Esp_Item_Bag2C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Bag Lv3", &SettingMenu2::Esp_Item_Bag3);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Bag 3", (float*)&SettingMenu2::Esp_Item_Bag3C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

							}
							ImGui::EndChild();

							ImGui::EndTabItem();
						}

						if (ImGui::BeginTabItem("Hel."))
							//if (ImGui::BeginTabItem("Helmet"))
						{
							if (ImGui::BeginChild("###items#Helmet", ImVec2(400, 295), false))
							{

								ImGui::Spacing();
								ImGui::Bullet(); ImGui::Text("Helmet List");
								ImGui::Bullet(); ImGui::Text("Size");
								ImGui::SameLine();
								ImGui::SliderFloat0("                                     Helmet Size", &SettingMenu2::HelmetSize, 0, 25);
								ImGui::Spacing();

								ImGui::Checkbox("Helmet Lv1", &SettingMenu2::Esp_Item_Helmet1);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Helmet 1", (float*)&SettingMenu2::Esp_Item_Helmet1C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Helmet Lv2", &SettingMenu2::Esp_Item_Helmet2);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Helmet 2", (float*)&SettingMenu2::Esp_Item_Helmet2C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Helmet Lv3", &SettingMenu2::Esp_Item_Helmet3);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Helmet 3", (float*)&SettingMenu2::Esp_Item_Helmet3C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

							}
							ImGui::EndChild();

							ImGui::EndTabItem();
						}

						if (ImGui::BeginTabItem("Arm."))
							//if (ImGui::BeginTabItem("Armor"))
						{
							if (ImGui::BeginChild("###items#Armor", ImVec2(400, 295), false))
							{

								ImGui::Spacing();
								ImGui::Bullet(); ImGui::Text("Armor List");
								ImGui::Bullet(); ImGui::Text("Size");
								ImGui::SameLine();
								ImGui::SliderFloat0("                                     Armor Size", &SettingMenu2::ArmorSize, 0, 25);
								ImGui::Spacing();

								ImGui::Checkbox("Armor Lv1", &SettingMenu2::Esp_Item_Armor1);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Armor 1", (float*)&SettingMenu2::Esp_Item_Armor1C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Armor Lv2", &SettingMenu2::Esp_Item_Armor2);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Armor 2", (float*)&SettingMenu2::Esp_Item_Armor2C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Armor Lv3", &SettingMenu2::Esp_Item_Armor3);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Armor 3", (float*)&SettingMenu2::Esp_Item_Armor3C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

							}
							ImGui::EndChild();

							ImGui::EndTabItem();
						}

						if (ImGui::BeginTabItem("Sco."))
							//if (ImGui::BeginTabItem("Scope"))
						{
							if (ImGui::BeginChild("###items#Scope", ImVec2(400, 295), false))
							{

								ImGui::Spacing();
								ImGui::Bullet(); ImGui::Text("Scope List");
								ImGui::Bullet(); ImGui::Text("Size");
								ImGui::SameLine();
								ImGui::SliderFloat0("                                     Scope Size", &SettingMenu2::ScopeSize, 0, 25);
								ImGui::Spacing();

								ImGui::Checkbox("Red Dot", &SettingMenu2::RedDot);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Red-Dot", (float*)&SettingMenu2::RedDotC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Holo", &SettingMenu2::Esp_Item_Holo);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Holo", (float*)&SettingMenu2::Esp_Item_HoloC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("x2", &SettingMenu2::Esp_Item_x2);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("2X", (float*)&SettingMenu2::Esp_Item_x2C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("x3", &SettingMenu2::Esp_Item_x3);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("3X", (float*)&SettingMenu2::Esp_Item_x3C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("x4", &SettingMenu2::Esp_Item_x4);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("4X", (float*)&SettingMenu2::Esp_Item_x4C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("x6", &SettingMenu2::Esp_Item_x6);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("6X", (float*)&SettingMenu2::Esp_Item_x6C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("x8", &SettingMenu2::Esp_Item_x8);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("8X", (float*)&SettingMenu2::Esp_Item_x8C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

							}
							ImGui::EndChild();

							ImGui::EndTabItem();
						}

						if (ImGui::BeginTabItem("Gre."))
							//if (ImGui::BeginTabItem("Grenade"))
						{
							if (ImGui::BeginChild("###items#Grenade", ImVec2(400, 295), false))
							{

								ImGui::Spacing();
								ImGui::Bullet(); ImGui::Text("Grenade List");
								ImGui::Bullet(); ImGui::Text("Size");
								ImGui::SameLine();
								ImGui::SliderFloat0("                                     Grenade Size", &SettingMenu2::GrenadeSize, 0, 25);
								ImGui::Spacing();


								ImGui::Checkbox("RedZone Bomb", &SettingMenu2::RedZoneBomb);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("RedZoneBomb", (float*)&SettingMenu2::RedZoneBombC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("Grenade", &SettingMenu2::Esp_Item_Frag);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Grenade", (float*)&SettingMenu2::Esp_Item_FragC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("Grenade Warning", &SettingMenu2::Grenade_Warning);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Grenade_Warning", (float*)&SettingMenu2::Grenade_WarningC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("Molotov Cocktail", &SettingMenu2::Esp_Item_Molotof);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Molotov-Cocktail", (float*)&SettingMenu2::Esp_Item_MolotofC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("Molotov Warning", &SettingMenu2::Molotov_Warning);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Molotov_Warning", (float*)&SettingMenu2::Molotov_WarningC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("Stun Grenade", &SettingMenu2::StunGrenade);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Stun-Grenade", (float*)&SettingMenu2::StunGrenadeC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("Stun Grenade Warning", &SettingMenu2::StunGrenade_Warning);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Stun-Grenade_Warning", (float*)&SettingMenu2::StunGrenade_WarningC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("Smoke", &SettingMenu2::Esp_Item_Smoke);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Smoke", (float*)&SettingMenu2::Esp_Item_SmokeC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("Smoke Warning", &SettingMenu2::Smoke_Warning);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Smoke_Warning", (float*)&SettingMenu2::Smoke_WarningC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);


							}
							ImGui::EndChild();

							ImGui::EndTabItem();
						}

						/*if (ImGui::BeginTabItem("Weapon 2"))
						{
							if (ImGui::BeginChild("###items#Weapon", ImVec2(400, 322), false))
							{

								
							}
							ImGui::EndChild();
							ImGui::EndTabItem();
						}*/
					}
					ImGui::EndTabBar();

					ImGui::EndTabItem();
				}

				if (ImGui::BeginTabItem("Others Item"))
				{
					if (ImGui::BeginTabBar("BeginTabBar"))
					{
						if (ImGui::BeginTabItem("Vehicle"))
							//if (ImGui::BeginTabItem("Grenade"))
						{
							if (ImGui::BeginChild("###items#Vehicle", ImVec2(400, 295), false))
							{

								ImGui::Spacing();
								ImGui::Bullet(); ImGui::Text("Vehicle List");
								ImGui::Bullet(); ImGui::Text("Size");
								ImGui::SameLine();
								ImGui::SliderFloat0("                                     Vehicle Size", &SettingMenu2::VehicleSize, 0.100, 25);
								ImGui::Spacing();

								ImGui::Checkbox(" Show All Vehicle", &SettingMenu2::Vehicle);
								//ImGui::Spacing();
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("VehicleC", (float*)&SettingMenu2::VehicleColor, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								/*ImGui::Checkbox("Lion Dance Car", &SettingMenu2::LionDanceCar);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("LionDanceCar", (float*)&SettingMenu2::LionDanceCarC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("BRDM", &SettingMenu2::BRDM);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("BRDM", (float*)&SettingMenu2::BRDMC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("Scooter", &SettingMenu2::Scooter);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Scooter", (float*)&SettingMenu2::ScooterC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("Motorcycle", &SettingMenu2::Motorcycle);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Motorcycle", (float*)&SettingMenu2::MotorcycleC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("Snowmobile", &SettingMenu2::Snowmobile);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Snowmobile", (float*)&SettingMenu2::SnowmobileC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("Tuk", &SettingMenu2::Tuk);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Tuk", (float*)&SettingMenu2::TukC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("Buggy", &SettingMenu2::Buggy);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Buggy", (float*)&SettingMenu2::BuggyC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("Sportsa", &SettingMenu2::Sportsa);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Sportsa", (float*)&SettingMenu2::SportsaC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("Sports", &SettingMenu2::Sports);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Sports", (float*)&SettingMenu2::SportsC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("Dacia", &SettingMenu2::Dacia);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Dacia", (float*)&SettingMenu2::DaciaC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("Rony", &SettingMenu2::Rony);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Rony", (float*)&SettingMenu2::RonyC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("UAZ", &SettingMenu2::UAZ);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("UAZ", (float*)&SettingMenu2::UAZC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("Minibus", &SettingMenu2::Minibus);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Minibus", (float*)&SettingMenu2::MinibusC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("PG117", &SettingMenu2::PG117);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("PG117", (float*)&SettingMenu2::PG117C, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("Aquarail", &SettingMenu2::Aquarail);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Aquarail", (float*)&SettingMenu2::AquarailC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("ModelY Tesla", &SettingMenu2::ModelYTesla);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("ModelYTesla", (float*)&SettingMenu2::ModelYTeslaC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("Gravity Motorcycle", &SettingMenu2::GravityMotorcycle);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("GravityMotorcycle", (float*)&SettingMenu2::GravityMotorcycleC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("Glider", &SettingMenu2::Glider);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Glider", (float*)&SettingMenu2::GliderC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("UTV", &SettingMenu2::UTV);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("UTV", (float*)&SettingMenu2::UTVC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("Monstar Truck", &SettingMenu2::MonstarTruck);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("MonstarTruck", (float*)&SettingMenu2::MonstarTruckC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("Coupe_New Dacia", &SettingMenu2::Coupe_NewDacia);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Coupe_NewDacia", (float*)&SettingMenu2::Coupe_NewDaciaC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("Quad", &SettingMenu2::Quad);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Quad", (float*)&SettingMenu2::QuadC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("Snow Bike", &SettingMenu2::Snow_Bike);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Snow_Bike", (float*)&SettingMenu2::Snow_BikeC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

								ImGui::Checkbox("PickUp", &SettingMenu2::PickUp);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("PickUp", (float*)&SettingMenu2::PickUpC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);*/

							}
							ImGui::EndChild();

							ImGui::EndTabItem();
						}

						if (ImGui::BeginTabItem("Airplan"))
							//if (ImGui::BeginTabItem("Ammo"))
						{
							if (ImGui::BeginChild("###items#Airplan", ImVec2(400, 295), false))
							{
								ImGui::Spacing();
								ImGui::Bullet(); ImGui::Text("Airplan List");
								ImGui::Bullet(); ImGui::Text("Size");
								ImGui::SameLine();
								ImGui::SliderFloat0("                                     Airplan Size", &SettingMenu2::AirplanT, 0, 25);
								ImGui::Spacing();

								ImGui::Checkbox("AirDrop Plane", &SettingMenu2::Airplan);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("AirDropPlane", (float*)&SettingMenu2::AirplanC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

							}
							ImGui::EndChild();

							ImGui::EndTabItem();
						}

						if (ImGui::BeginTabItem("AirDrop"))
							//if (ImGui::BeginTabItem("Ammo"))
						{
							if (ImGui::BeginChild("###items#AirDropBoxItem", ImVec2(400, 295), false))
							{
								ImGui::Spacing();
								ImGui::Bullet(); ImGui::Text("AirDropBox Item List");
								/*ImGui::Bullet(); ImGui::Text("Size");
								ImGui::SameLine();
								ImGui::SliderFloat0("                                     AirDropBox Item Size", &SettingMenu2::AirDropBoxSize, 0, 25);*/
								ImGui::Spacing();

								ImGui::Checkbox(" AirDrop Box", &SettingMenu2::AirDropBox);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 355 });
								ImGui::ColorEdit4("AirDrop-Box", (float*)&SettingMenu2::AirDropBoxColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
								//if (SettingMenu2::Esp_Item_LootBox)
								{
									if (ImGui::TreeNodeEx("  AirDrop-Box Size"))
									{
										ImGui::Indent();

										//ImGui::SameLine();
										ImGui::SliderFloat("                                          AirDrop-Box Size", &SettingMenu2::AirDropBoxSize, 0.100f, 20.00f);

										ImGui::Unindent();
										ImGui::TreePop();
									}
								}


								//ImGui::Checkbox(" AirDrop Box Items", &SettingMenu2::AirDropBoxitems1);
								//ImGui::SameLine();
								//ImGui::SetCursorPosX({ 355 });
								//ImGui::ColorEdit4("AirDrop-Box Items", (float*)&Colors::AirDropBoxitemColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
								////if (SettingMenu2::playerdeadbox)
								//{
								//	if (ImGui::TreeNodeEx("  AirDrop Box Items Size"))
								//	{
								//		ImGui::Indent();

								//		//ImGui::SameLine();
								//		ImGui::SliderFloat("                                          AirDrop Box Items size", &SettingMenu2::AirDropBoxItemsSize, 0.100f, 20.00f);

								//		ImGui::Unindent();
								//		ImGui::TreePop();
								//	}
								//}

								//ImGui::Checkbox("AirDrop Box Items Line Color", &SettingMenu2::itemrect);
								//ImGui::SameLine();
								//ImGui::SetCursorPosX({ 355 });
								//ImGui::ColorEdit4("AirDrop-Box-Items Shadow", (float*)&Colors::bgcornerColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
								////if (SettingMenu2::itemrect)
								//{
								//	if (ImGui::TreeNodeEx("  AirDrop Box Items Line Setting"))
								//	{
								//		ImGui::Indent();

								//		if (ImGui::RadioButton("Full-Line", &LootBoxItems_RadioButton, 2))
								//		{
								//			item_current_Emu = 0;
								//			SettingMenu2::redioption = 1;
								//		}
								//		ImGui::SameLine();
								//		if (ImGui::RadioButton("Corner-Line", &LootBoxItems_RadioButton, 1))
								//		{
								//			item_current_Emu = 1;
								//			SettingMenu2::redioption = 2;
								//			ImGui::SetItemDefaultFocus();
								//		}


								//		ImGui::Unindent();
								//		ImGui::TreePop();
								//	}
								//}

							}
							ImGui::EndChild();

							ImGui::EndTabItem();
						}

						if (ImGui::BeginTabItem("Loot-Box"))
							//if (ImGui::BeginTabItem("Ammo"))
						{
							if (ImGui::BeginChild("###items#Loot-BoxItem", ImVec2(400, 295), false))
							{
								ImGui::Spacing();
								ImGui::Bullet(); ImGui::Text("Loot-Box Item List");
								/*ImGui::Bullet(); ImGui::Text("Size");
								ImGui::SameLine();
								ImGui::SliderFloat0("                                     Loot-Box Item Size", &SettingMenu2::PlayerLootBoxSize, 0, 25);*/
								ImGui::Spacing();

								ImGui::Checkbox(" Loot-Box", &SettingMenu2::playerdeadbox);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 355 });
								ImGui::ColorEdit4("P Loot-Box", (float*)&SettingMenu2::PlayerDeadboxColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
								//if (SettingMenu2::Esp_Item_LootBox)
								{
									if (ImGui::TreeNodeEx("  Loot-Box Size"))
									{
										ImGui::Indent();

										//ImGui::SameLine();
										ImGui::SliderFloat("                                          Loot-Box Size", &SettingMenu2::PlayerLootBoxSize, 0.100f, 20.00f);

										ImGui::Unindent();
										ImGui::TreePop();
									}
								}


								ImGui::Checkbox(" Loot-Box Items", &SettingMenu2::playerdeadboxitems);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 355 });
								ImGui::ColorEdit4("Loot-Box Items", (float*)&ColorsMenu2::deadboxitemColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
								//if (SettingMenu2::playerdeadbox)
								{
									if (ImGui::TreeNodeEx("  Loot-Box Items Size"))
									{
										ImGui::Indent();

										//ImGui::SameLine();
										ImGui::SliderFloat("                                          Loot-Box Items size", &SettingMenu2::PlayerLootBoxItemsSize, 0.100f, 20.00f);

										ImGui::Unindent();
										ImGui::TreePop();
									}
								}


								ImGui::Checkbox("Loot-Box Items Line Color", &SettingMenu2::itemrect);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 355 });
								ImGui::ColorEdit4("Loot-Box-Items Shadow", (float*)&ColorsMenu2::bgcornerColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
								//if (SettingMenu2::itemrect)
								{
									if (ImGui::TreeNodeEx("  Loot-Box Items Line Setting"))
									{
										ImGui::Indent();

										if (ImGui::RadioButton("Full-Line", &LootBoxItems_RadioButton, 2))
										{
											item_current_Emu = 0;
											SettingMenu2::redioption = 1;
										}
										ImGui::SameLine();
										if (ImGui::RadioButton("Corner-Line", &LootBoxItems_RadioButton, 1))
										{
											item_current_Emu = 1;
											SettingMenu2::redioption = 2;
											ImGui::SetItemDefaultFocus();
										}


										ImGui::Unindent();
										ImGui::TreePop();
									}
								}

							}
							ImGui::EndChild();

							ImGui::EndTabItem();
						}

						if (ImGui::BeginTabItem("More Item"))
							//if (ImGui::BeginTabItem("Ammo"))
						{
							if (ImGui::BeginChild("###items#MoreItem", ImVec2(400, 295), false))
							{
								ImGui::Spacing();
								ImGui::Bullet(); ImGui::Text("More Item List");
								ImGui::Bullet(); ImGui::Text("Size");
								ImGui::SameLine();
								ImGui::SliderFloat0("                                     More Item Size", &SettingMenu2::MoreItemSize, 0, 25);
								ImGui::Spacing();

								ImGui::Checkbox("Zone Radiation", &SettingMenu2::ZoneRadiation);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Zone_Radiation", (float*)&SettingMenu2::ZoneRadiationC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("WIN MVP Statue", &SettingMenu2::WINMVPStatue);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("WINMVP_Statue", (float*)&SettingMenu2::WINMVPStatueC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Place Selected", &SettingMenu2::PlaceSelected);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Place_elected", (float*)&SettingMenu2::PlaceSelectedC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("EmergencyCall Pickup", &SettingMenu2::EmergencyCallPickup);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("EmergencyCall_Pickup", (float*)&SettingMenu2::EmergencyCallPickupC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Lion Dance", &SettingMenu2::LionDance);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Lion_Dance", (float*)&SettingMenu2::LionDanceC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Grappling Hook", &SettingMenu2::GrapplingHook);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Grappling_Hook", (float*)&SettingMenu2::GrapplingHookC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Shop Token", &SettingMenu2::ShopToken);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Shop_Token", (float*)&SettingMenu2::ShopTokenC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Supply Shop", &SettingMenu2::SupplyShop);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Supply_Shop", (float*)&SettingMenu2::PlaceSelectedC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);


								ImGui::Spacing();
								ImGui::Bullet(); ImGui::Text("(AR) Necessary Equipment");
								ImGui::Spacing();
								ImGui::Checkbox("Flash Hider (AR)", &SettingMenu2::FlashHiderAR);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("FlashHider(AR)", (float*)&SettingMenu2::FlashHiderARC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Compensator (AR)", &SettingMenu2::CompensatorAR);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Compensator(AR)", (float*)&SettingMenu2::CompensatorARC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Suppressor (AR)", &SettingMenu2::SuppressorAR);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Suppressor(AR)", (float*)&SettingMenu2::SuppressorARC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Quickdraw Mag (AR)", &SettingMenu2::QuickdrawMagAR);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Quickdraw Mag (AR)", (float*)&SettingMenu2::QuickdrawMagARC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Extended Mag (AR)", &SettingMenu2::ExtendedMagAR);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("ExtendedMag(AR)", (float*)&SettingMenu2::ExtendedMagARC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Extended Quickdraw Mag (AR)", &SettingMenu2::ExtendedQuickdrawMagAR);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("ExtendedQuickdrawMag(AR)", (float*)&SettingMenu2::ExtendedQuickdrawMagARC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);


								ImGui::Spacing();
								ImGui::Bullet(); ImGui::Text("(Sniper) Necessary Equipment");
								ImGui::Spacing();
								ImGui::Checkbox("FlashHider (Sniper)", &SettingMenu2::FlashHiderSniper);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("FlashHider(Sniper)", (float*)&SettingMenu2::FlashHiderSniperC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Compensator (Sniper)", &SettingMenu2::CompensatorSniper);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Compensator(Sniper)", (float*)&SettingMenu2::CompensatorSniperC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Suppressor (Sniper)", &SettingMenu2::SuppressorSniper);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Suppressor(Sniper)", (float*)&SettingMenu2::SuppressorSniperC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Quickdraw Mag (Sniper)", &SettingMenu2::QuickdrawMagSniper);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("QuickdrawMag(Sniper)", (float*)&SettingMenu2::QuickdrawMagSniperC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Extended Mag (Sniper)", &SettingMenu2::ExtendedMagSniper);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("ExtendedMag(Sniper)", (float*)&SettingMenu2::ExtendedMagSniperC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Extended Quickdraw Mag (Sniper)", &SettingMenu2::ExtendedQuickdrawMagSniper);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("ExtendedQuickdrawMag(Sniper)", (float*)&SettingMenu2::ExtendedQuickdrawMagSniperC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);


								ImGui::Spacing();
								ImGui::Bullet(); ImGui::Text("(SMG) Necessary Equipment");
								ImGui::Spacing();
								ImGui::Checkbox("FlashHider (SMG)", &SettingMenu2::FlashHiderSMG);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("FlashHider(SMG)", (float*)&SettingMenu2::FlashHiderSMGC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Compensator (SMG)", &SettingMenu2::CompensatorSMG);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Compensator(SMG)", (float*)&SettingMenu2::CompensatorSMGC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Suppressor (SMG)", &SettingMenu2::SuppressorSMG);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Suppressor(SMG)", (float*)&SettingMenu2::SuppressorSMGC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Tactical Stock (SMG)", &SettingMenu2::TacticalStockSMG);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("TacticalStock(SMG)", (float*)&SettingMenu2::TacticalStockSMGC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Choke (SG)", &SettingMenu2::ChokeSG);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("Choke(SG)", (float*)&SettingMenu2::ChokeSGC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Thumb Grip", &SettingMenu2::ThumbGrip);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("ThumbGrip", (float*)&SettingMenu2::ThumbGripC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								ImGui::Checkbox("Light Grip", &SettingMenu2::LightGrip);
								ImGui::SameLine();
								ImGui::SetCursorPosX({ 345 });
								ImGui::ColorEdit4("LightGrip", (float*)&SettingMenu2::LightGripC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

							}
							ImGui::EndChild();

							ImGui::EndTabItem();
						}
					}
					ImGui::EndTabBar();

					ImGui::EndTabItem();
				}

				if (ImGui::BeginTabItem("More Option"))
				{
					if (ImGui::BeginChild("###others", ImVec2(400, 325), false))
					{
						ImGui::Spacing();

						ImGui::Checkbox(" Fight Mode", &SettingMenu2::fightmode);
						//if (SettingMenu2::fightmode)
						{
							if (ImGui::TreeNodeEx("  Fight Mode Setting"))
							{
								ImGui::Indent();

								/*ImGui::SameLine();
								ImGui::SliderFloat("                    Distance size", &SettingMenu2::Dissize, 0.100f, 20.00f);*/

								ImGui::Unindent();
								ImGui::TreePop();
							}
						}


						ImGui::Checkbox(" All Items", &SettingMenu2::Item);
						//if (SettingMenu2::Item)
						{
							if (ImGui::TreeNodeEx("  All Items Size"))
							{
								ImGui::Indent();

								//ImGui::SameLine();
								ImGui::SliderFloat("                                          All Items Size", &SettingMenu2::allitemssT, 0.100f, 20.00f);

								ImGui::Unindent();
								ImGui::TreePop();
							}
						}


						ImGui::Checkbox(" Total Players Number", &SettingMenu2::TotalEnemy);
						//if (SettingMenu2::TotalEnemy)
						{
							if (ImGui::TreeNodeEx("  Total Players Number Setting"))
							{
								ImGui::Indent();

								if (ImGui::RadioButton("Style 1", &TotalPlayers_RadioButton, 1))
								{
									SettingMenu2::TotalEnemyStyle1 = true;
									SettingMenu2::TotalEnemyStyle2 = false;
									SettingMenu2::TotalEnemyStyle2 = false;
								}
								ImGui::SameLine();
								if (ImGui::RadioButton("Style 2", &TotalPlayers_RadioButton, 2))
								{
									SettingMenu2::TotalEnemyStyle1 = false;
									SettingMenu2::TotalEnemyStyle2 = true;
									SettingMenu2::TotalEnemyStyle3 = false;
								}
								ImGui::SameLine();
								if (ImGui::RadioButton("Style 3", &TotalPlayers_RadioButton, 3))
								{
									SettingMenu2::TotalEnemyStyle1 = false;
									SettingMenu2::TotalEnemyStyle2 = false;
									SettingMenu2::TotalEnemyStyle3 = true;
								}

								ImGui::Unindent();
								ImGui::TreePop();
							}
						}


						ImGui::Checkbox(" Show Text Border", &SettingMenu2::borderlo);
						//if (SettingMenu2::borderlo)
						{
							if (ImGui::TreeNodeEx(" Text Border Setting"))
							{
								ImGui::Indent();

								////ImGui::SameLine();
								//ImGui::SliderFloat("                                          Bot Name size", &SettingMenu2::BotNamesize, 0.100f, 20.00f);

								ImGui::Unindent();
								ImGui::TreePop();
							}
						}


						ImGui::Checkbox(" Show Watermark", &SettingMenu2::watermark);
						ImGui::SameLine();
						ImGui::SetCursorPosX({ 355 });
						ImGui::ColorEdit4("Watermark Text Color", (float*)&SettingMenu2::watermarkC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
						//if (SettingMenu2::watermark)
						{
							if (ImGui::TreeNodeEx(" Watermark Setting"))
							{
								ImGui::Indent();

								////ImGui::SameLine();
								ImGui::SliderFloat("                                          Watermark Size", &SettingMenu2::watermarkT, 0, 25);

								ImGui::Unindent();
								ImGui::TreePop();
							}
						}


						ImGui::Checkbox(" Show Expred Date", &SettingMenu2::Expred_Date);
						ImGui::SameLine();
						ImGui::SetCursorPosX({ 355 });
						ImGui::ColorEdit4("Expred Date Text Color", (float*)&SettingMenu2::Expred_DateC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
						//if (SettingMenu2::Expred_Date)
						{
							if (ImGui::TreeNodeEx(" Expred Date Setting"))
							{
								ImGui::Indent();

								////ImGui::SameLine();
								ImGui::SliderFloat("                                          Expred Date Size", &SettingMenu2::Expred_DateT, 0, 25);

								ImGui::Unindent();
								ImGui::TreePop();
							}
						}


					}
					ImGui::EndChild();

					ImGui::EndTabItem();
				}

			}
			ImGui::EndTabBar();
		}

		if (Settings::Tab == 2)
		{

		}

		if (Settings::Tab == 3)
		{
			/*ImGui::BeginChild("###2", ImVec2(408, 355), true, 0);
			{

			}
			ImGui::EndChild();*/
			if (ImGui::BeginTabBar("BeginTabBar"))
			{
				if (ImGui::BeginTabItem("Magic Bullet"))
				{
					if (ImGui::BeginChild("##SafeMemory", ImVec2(400, 325), false))
					{
						ImGui::Checkbox(" Safe Bullet Track", &Setting::MagicBullet);
						ImGui::Spacing();
						if (Setting::MagicBullet)
						{
							Setting::MagicBulletticked = true;
						}
						else
						{
							Setting::MagicBulletticked = false;
						}

						ImGui::Checkbox(" Brutal Bullet Track", &SettingMenu2::MagicBulletDNG);
						ImGui::Spacing();
						if (SettingMenu2::MagicBulletDNG)
						{
							SettingMenu2::MagicBullet = false;
						}

						ImGui::Checkbox(" Instant Hit", &SettingMenu2::instanthit);
						//ImGui::Spacing();
						if (SettingMenu2::instanthit)
						{
							SettingMenu2::instanthitDNG = false;
						}

						ImGui::Bullet(); ImGui::Text("Bullet Tracking Settings");
						ImGui::Spacing();

						//ImGui::SetCursorPosX({ 170 });
						ImGui::Checkbox(" Legit Tracking", &SettingMenu2::Legitrack);
						//ImGui::Spacing
						if (SettingMenu2::Legitrack)
						{
							SettingMenu2::fovcircle = true;
							SettingMenu2::fovcircle2 = true;
						}
						ImGui::SameLine();
						ImGui::Checkbox(" Random Tracking", &SettingMenu2::RandomTracking);
						ImGui::Spacing();

						if (SettingMenu2::curraim == 0)
						{
							ImGui::Checkbox(" Aim Head", &SettingMenu2::AimHead);
							ImGui::Spacing();
							if (SettingMenu2::AimHead)
							{

							}
							else
							{
								SettingMenu2::AimBody = true;
								SettingMenu2::curraim = 1;
							}
						}
						else if (SettingMenu2::curraim == 1)
						{
							ImGui::Checkbox(" Aim Body", &SettingMenu2::AimBody);
							ImGui::Spacing();
							if (SettingMenu2::AimBody)
							{

							}
							else
							{
								SettingMenu2::AimHead = true;
								SettingMenu2::curraim = 0;
							}
						}


						ImGui::Checkbox(" Skip Knock", &SettingMenu2::knocked);
						//ImGui::Spacing();
						ImGui::SameLine();
						ImGui::Checkbox(" Skip Bots ", &SettingMenu2::SkipBots);
						ImGui::Spacing();

						ImGui::Checkbox(" Fov Based Tracking ", &SettingMenu2::fovcircle2);
						ImGui::Spacing();
						if (SettingMenu2::fovcircle2)
						{
							SettingMenu2::fovcircle = true;

							ImGui::Checkbox(" Show Fov ", &SettingMenu2::fovcircle);
							ImGui::SameLine();
							//ImGui::SetCursorPos({ 255.0f,203.0f });
							ImGui::BeginChild("###|", ImVec2(280, 30), false, 0);
							{
								//ImGui::Spacing();
								ImGui::SetCursorPos({ 0.0f, 0.0f });
								ImGui::SliderFloat("###fovFOVsize", &SettingMenu2::fovcircleredus, 0.0f, 2000.0f); ImGui::SameLine(); ImGui::Text("Fov Size");
								ImGui::SameLine();
								//ImGui::SetCursorPosX({ 365 });
								ImGui::ColorEdit4(" fovcolor", (float*)&ColorsMenu2::fovcircleColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
								/*if (SettingMenu2::fovcircle)
								{
									ImGui::SliderFloat("###fovFOVsize", &SettingMenu2::fovcircleredus, 1.0f, 2000.0f);  			ImGui::SameLine(); 			ImGui::Text("Fov Size");
								}*/
							}
							ImGui::EndChild();





						}
						else
						{
							SettingMenu2::fovcircle = false;
						}
						//Code End
					}
					ImGui::EndChild();

					ImGui::EndTabItem();
				}

				if (SettingMenu2::MagicBulletDNG)
				{
					//if (ImGui::BeginTabItem("Brutal Option"))
					//{
					//	if (ImGui::BeginChild("##BrutalMemory", ImVec2(400, 325), false))
					//	{
					//		//ImGui::Checkbox(" Magic Bullet Track Safe", &SettingMenu2::MagicBullet);
					//		/*ImGui::Checkbox(" Safe Bullet Track", &SettingMenu2::MagicBullet);
					//		ImGui::Spacing();
					//		if (SettingMenu2::MagicBullet)
					//		{
					//			SettingMenu2::MagicBulletDNG = false;
					//		}*/
					//		//ImGui::Checkbox(" Magic Bullet Track Danger", &SettingMenu2::MagicBulletDNG);
					//		ImGui::Spacing();
					//		ImGui::Checkbox(" Brutal Bullet Track", &SettingMenu2::MagicBulletDNG);
					//		ImGui::Spacing();
					//		if (SettingMenu2::MagicBulletDNG)
					//		{
					//			SettingMenu2::MagicBullet = false;
					//		}

					//		//ImGui::Checkbox(" Instant Hit Danger", &SettingMenu2::instanthit);
					//		ImGui::Checkbox(" Instant Hit Danger", &SettingMenu2::instanthitDNG);
					//		//ImGui::Spacing();
					//		if (SettingMenu2::instanthitDNG)
					//		{
					//			SettingMenu2::instanthit = false;
					//		}

					//		ImGui::Bullet(); ImGui::Text("Bullet Tracking Settings");
					//		ImGui::Spacing();

					//		//ImGui::SetCursorPosX({ 170 });
					//		ImGui::Checkbox(" Legit Tracking", &SettingMenu2::Legitrack);
					//		//ImGui::Spacing();
					//		if (SettingMenu2::Legitrack)
					//		{
					//			SettingMenu2::fovcircle = true;
					//			SettingMenu2::fovcircle2 = true;
					//		}
					//		ImGui::SameLine();
					//		ImGui::Checkbox(" Random Tracking", &SettingMenu2::RandomTracking);
					//		ImGui::Spacing();

					//		if (SettingMenu2::curraim == 0)
					//		{
					//			ImGui::Checkbox(" Aim Head", &SettingMenu2::AimHead);
					//			ImGui::Spacing();
					//			if (SettingMenu2::AimHead)
					//			{

					//			}
					//			else
					//			{
					//				SettingMenu2::AimBody = true;
					//				SettingMenu2::curraim = 1;
					//			}
					//		}
					//		else if (SettingMenu2::curraim == 1)
					//		{
					//			ImGui::Checkbox(" Aim Body", &SettingMenu2::AimBody);
					//			ImGui::Spacing();
					//			if (SettingMenu2::AimBody)
					//			{

					//			}
					//			else
					//			{
					//				SettingMenu2::AimHead = true;
					//				SettingMenu2::curraim = 0;
					//			}
					//		}


					//		ImGui::Checkbox(" Skip Knock", &SettingMenu2::knocked);
					//		//ImGui::Spacing();
					//		ImGui::SameLine();
					//		ImGui::Checkbox(" Skip Bots ", &SettingMenu2::SkipBots);
					//		ImGui::Spacing();

					//		ImGui::Checkbox(" Fov Based Tracking ", &SettingMenu2::fovcircle2);
					//		ImGui::Spacing();
					//		if (SettingMenu2::fovcircle2)
					//		{
					//			SettingMenu2::fovcircle = true;

					//			ImGui::Checkbox(" Show Fov ", &SettingMenu2::fovcircle);
					//			ImGui::Spacing();
					//			ImGui::SliderFloat("###fovFOVsize", &SettingMenu2::fovcircleredus, 1.0f, 2000.0f); ImGui::SameLine(); ImGui::Text("Fov Size");
					//			ImGui::SameLine();
					//			//ImGui::SetCursorPosX({ 365 });
					//			ImGui::ColorEdit4(" fovcolor", (float*)&Colors::fovcircleColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
					//			/*if (SettingMenu2::fovcircle)
					//			{
					//				ImGui::SliderFloat("###fovFOVsize", &SettingMenu2::fovcircleredus, 1.0f, 2000.0f);  			ImGui::SameLine(); 			ImGui::Text("Fov Size");
					//			}*/
					//		}
					//		else
					//		{
					//			SettingMenu2::fovcircle = false;
					//		}
					//		//Code End
					//		
					//	}
					//	ImGui::EndChild();
					//	ImGui::EndTabItem();
					//}
				}

				if (ImGui::BeginTabItem("Aimbot"))
				{
					if (ImGui::BeginChild("###aimbot", ImVec2(400, 325), false))
					{
						/*ImGui::Text(" !! Dangerous options are closed for now for security");*/

									//ImGui::SetCursorPos({ 30.f,30.0f });
									//ImGui::Checkbox("Aimbot", &SettingMenu2::Aimbot);
						ImGui::Spacing();
						ImGui::Checkbox(" Aimbot", &SettingMenu2::Aimbot);
						ImGui::SameLine();
						ImGui::Checkbox(" Marco 50m + Scope", &SettingMenu2::SniperMode);
						ImGui::Spacing();
						if (SettingMenu2::Aimbot)
						{
							SettingMenu2::fovcircle = true;

							if (ImGui::TreeNodeEx(" Aimbot Setting"))
							{
								ImGui::Indent();

								const char* Emu[] = { "Head", "Body" };
								//const char* Emu[] = { "Head", "Body", "Pelvis" };

								const char* combo_label = Emu[SettingMenu2::curraim];

								const char* enginetype[] = { "Mouse Event","Silent Aimbot" };

								const char* enginelabel = enginetype[SettingMenu2::engine];

								//ImGui::SetCursorPos({ 30.f,60.0f });
								ImGui::Checkbox(" Skip Knocked Enemies", &SettingMenu2::knocked);
								ImGui::Spacing();

								//ImGui::SetCursorPos({ 30.f,90.0f });
								ImGui::Bullet(); ImGui::Text(" Fov Circle Size : ");
								/*ImGui::Checkbox(" Show FOV Circle", &SettingMenu2::fovcircle);*/
								ImGui::Spacing();
								//ImGui::SameLine();
								ImGui::SliderFloat("###FovSizeAimbot", &SettingMenu2::fovcircleredus, 1.0f, 350.0f); ImGui::SameLine(); ImGui::Text("Fov Size");
								ImGui::SameLine();
								//ImGui::SetCursorPosX({ 365 });
								ImGui::ColorEdit4(" fovcolor", (float*)&ColorsMenu2::fovcircleColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
								//ImGui::Spacing();

								ImGui::Bullet(); ImGui::Text(" Aimbot Speed : ");
								//ImGui::Spacing();
								//ImGui::SameLine();
								ImGui::SliderFloat("                                                              Aimbot Speede", &SettingMenu2::Aimspeed, 6.0f, 30.0f);
								//ImGui::SliderFloat("Aimbot Speede", &SettingMenu2::Aimspeed, 6.0f, 30.0f);
								ImGui::Spacing();

								ImGui::Bullet(); ImGui::Text(" Aim Position : ");
								ImGui::SameLine();
								ImGui::SetNextItemWidth(180.0f);
								ImGui::SetCursorPosX({ 220 });
								if (ImGui::BeginCombo(" AimcPositon", combo_label, ImGuiComboFlags_HeightSmall))
								{
									for (int n = 0; n < IM_ARRAYSIZE(Emu); n++)
									{
										const bool is_selected = (SettingMenu2::curraim == n);
										if (ImGui::Selectable(Emu[n], is_selected))
											SettingMenu2::curraim = n;
										if (is_selected)
											ImGui::SetItemDefaultFocus();
									}
									ImGui::EndCombo();
								}
								ImGui::Spacing();


								ImGui::Bullet(); ImGui::Text(" Aimbot Engine : ");
								ImGui::SameLine();
								ImGui::SetNextItemWidth(180.0f);
								ImGui::SetCursorPosX({ 220 });
								if (ImGui::BeginCombo(" AimcEngine", enginelabel, ImGuiComboFlags_HeightSmall))
								{
									for (int n = 0; n < IM_ARRAYSIZE(enginetype); n++)
									{
										const bool is_selectedd = (item_current_Aim == n);
										if (ImGui::Selectable(enginetype[n], is_selectedd))
											SettingMenu2::engine = n;
										if (is_selectedd)
											ImGui::SetItemDefaultFocus();
									}

									ImGui::EndCombo();
								}
								ImGui::Spacing();

								ImGui::Bullet(); ImGui::Text(" Aimbot Hootkey : ");
								ImGui::SameLine();
								ImGui::SetNextItemWidth(200.0f);
								ImGui::SetCursorPosX({ 211 });
								ImGui::Hotkey("##AimbotKey ", &SettingMenu2::AimbotKey, ImVec2(189.0f, 28));
								ImGui::Spacing();


								/*ImGui::Text("Aimbot Enable/Disable Hootkey:");
								ImGui::SameLine();
								ImGui::SetNextItemWidth(180.0f);
								ImGui::Hotkey("###Enable ", &SettingMenu2::EnableKey, ImVec2(180.0f, 24));
								ImGui::Spacing();

								ImGui::Text("Aimbot Positon Switch Key:");
								ImGui::SameLine();
								ImGui::SetNextItemWidth(180.0f);
								ImGui::Hotkey("##PositionKey ", &SettingMenu2::PositionKey, ImVec2(180.0f, 24));
								ImGui::Spacing();*/


								ImGui::Unindent();
								ImGui::TreePop();
							}
							//ImGui::EndChild();

						}
						else
						{
							if (SettingMenu2::Legitrack == 1)
							{
								SettingMenu2::fovcircle = true;
							}
							else
							{
								SettingMenu2::fovcircle = false;
							}
						}

					}
					ImGui::EndChild();

					ImGui::EndTabItem();
				}
			}
			ImGui::EndTabBar();
		}

		if (Settings::Tab == 4)
		{
			/*if (ImGui::BeginTabBar("BeginTabBar"))
			{

			}
			ImGui::EndTabBar();*/
			if (ImGui::BeginTabBar("BeginTabBar"))
			{
				if (ImGui::BeginTabItem("Memory Danger"))
				{
					if (ImGui::BeginChild("###memoryDanger", ImVec2(400, 325), false))
					{
						ImGui::Spacing();
						ImGui::Bullet(); ImGui::Text(">>> Not Use This Danger Memory Option");
						ImGui::Bullet(); ImGui::Text(">>> Use Safe Memory Option");
						ImGui::Spacing();

						/*ImGui::Checkbox(" Anti Stream", &SettingMenu2::antiscreen);
						ImGui::Spacing();*/

						/*if (SettingMenu2::ScreenX)
						{
							SetWindowDisplayAffinity(DX11Window::hWindow, WDA_EXCLUDEFROMCAPTURE);
						}
						else
						{
							SetWindowDisplayAffinity(DX11Window::hWindow, WDA_NONE);
						}*/

						ImGui::Checkbox(" Car Fly", &SettingMenu2::carfly);
						ImGui::Spacing();

						ImGui::Checkbox(" Car Speed", &SettingMenu2::speedcar);
						ImGui::Spacing();

						ImGui::Checkbox(" Fast Run", &SettingMenu2::fastrun);
						ImGui::Spacing();

						ImGui::Checkbox(" Fast Run V2", &SettingMenu2::fackSetting1);
						ImGui::Spacing();

						ImGui::Checkbox(" No recoil", &SettingMenu2::recoil);
						ImGui::Spacing();

						ImGui::Checkbox(" No recoil 2", &SettingMenu2::recoil2);
						ImGui::Spacing();

						ImGui::Checkbox(" Force Tpp Mod", &SettingMenu2::fackSetting2);
						ImGui::Spacing();

						ImGui::Checkbox(" Super View", &SettingMenu2::SuperView);
						ImGui::Spacing();
						if (SettingMenu2::SuperView)
						{
							if (ImGui::TreeNodeEx(" Super View Setting"))
							{
								ImGui::Indent();

								ImGui::Text("SuperView Front Key");
								ImGui::SameLine();
								ImGui::Hotkey("##SuperView Front ", &SettingMenu2::SuperFront, ImVec2(180.0f, 24));

								ImGui::Text("SuperView Up Key");
								ImGui::SameLine();
								ImGui::Hotkey("##SuperView UP ", &SettingMenu2::SuperUp, ImVec2(180.0f, 24));


								ImGui::Text("SuperView Down Key");
								ImGui::SameLine();
								ImGui::Hotkey("##SuperView Down ", &SettingMenu2::SuperDown, ImVec2(180.0f, 24));

								ImGui::Text("SuperView Left Key");
								ImGui::SameLine();
								ImGui::Hotkey("##SuperView Left ", &SettingMenu2::SuperLeft, ImVec2(180.0f, 24));

								ImGui::Text("SuperView Right Key");
								ImGui::SameLine();
								ImGui::Hotkey("##SuperView Right ", &SettingMenu2::SuperRight, ImVec2(180.0f, 24));

								ImGui::Spacing();
								ImGui::Text("__________________________________________________________");
								ImGui::Text("[?]  If possible, do not change the button set here");
								ImGui::Text("[?]  But you can change it if you want");
								ImGui::SameLine();

								ImGui::Unindent();
								ImGui::TreePop();
							}
						}
					}
					ImGui::EndChild();

					ImGui::EndTabItem();
				}

				if (ImGui::BeginTabItem("Memory Safe"))
				{
					if (ImGui::BeginChild("###memorySafe", ImVec2(400, 325), false))
					{
						/*ImGui::Spacing();
						ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 0, 255));
						ImGui::Text("Coming Soon...");
						ImGui::PopStyleColor();*/
						ImGui::Spacing();
						ImGui::Checkbox(" Anti Stream", &SettingMenu2::antiscreen);
						ImGui::Spacing();
						//ImGui::SetCursorPos({ 200.f,65.0f });
						/*ImGui::Bullet(); ImGui::Text(" Safe Memory Option Coming Soon...");
						ImGui::Spacing();*/

						ImGui::Checkbox(" iPad View Super", &SettingMenu2::ipadview);
						if (SettingMenu2::ipadview)
						{
							/*ImGui::Text("iPAD View Value");
							ImGui::SameLine();
							ImGui::SliderInt("###7754334", &SettingMenu2::IPADSIZE, 1, 300);*/

							ImGui::PushItemWidth(250);
							ImGui::SameLine();
							if (ImGui::SliderInt("##IpadSize", &SettingMenu2::IpadViewValue, 360.0f, 200.0f))
							{
								
							}
						}

						ImGui::Spacing();
						ImGui::Checkbox(" X Effect", &SettingMenu2::MagicX);
						ImGui::Spacing();
						/*ImGui::Spacing();

						ImGui::Checkbox(" Unlock 90FPS + UltraHD", &SettingMenu2::NINEFPS);
						if (SettingMenu2::NINEFPS)
						{
							ImGui::Text("Unlock 90FPS + UltraHD Activated");
						}*/
					}
					ImGui::EndChild();

					ImGui::EndTabItem();
				}
			}
			ImGui::EndTabBar();
		}

		if (Settings::Tab == 5)
		{
			/*if (ImGui::BeginTabBar("BeginTabBar"))
			{

			}
			ImGui::EndTabBar();*/

			if (ImGui::Button("Save Esp Setting", { 150.f,30.f }))
			{
				WriteConfigurate("C:\\Windows\\ESPMAAZ-Setting.ini");
			}
			ImGui::Spacing();
			if (ImGui::Button("Load Esp Setting", { 150.f,30.f }))
			{
				/*if (FileExist(SettingMenu2::PathSetting))
				{
					LoadConfiggg(SettingMenu2::PathSetting);
				}*/
				if (FileExist("C:\\Windows\\ESPMAAZ-Setting.ini"))
				{
					LoadConfiggg("C:\\Windows\\ESPMAAZ-Setting.ini");
					ImGui::InsertNotification({ ImGuiToastType_Success, 3000, " Load Setting is Success! %s", "" });
				}
				else
				{
					ImGui::InsertNotification({ ImGuiToastType_Warning, 3000, " Your Config not saved yet! %s", "" });
				}
			}
			ImGui::Spacing();
			if (ImGui::Button("Reset Esp Setting", { 150.f,30.f }))
			{
				//system_no_output1("attrib +s +h C:\\Windows\\ESPMAAZ-Setting.bin");//hide
				system_no_output1("attrib -s -h C:\\Windows\\ESPMAAZ-Setting.bin");//show
				Sleep(100);
				HRESULT ESPMAAZHK_Setting = URLDownloadToFile(NULL, _T("C:\\Windows\\ESPMAAZ-Setting.bin"), _T("C:\\Windows\\ESPMAAZ-Setting.ini"), 0, NULL);
				LoadConfiggg("C:\\Windows\\ESPMAAZ-Setting.ini");
				Sleep(100);
				system_no_output1("attrib +s +h C:\\Windows\\ESPMAAZ-Setting.bin");//hide
				//system_no_output1("attrib -s -h C:\\Windows\\ESPMAAZ-Setting.bin");//show
				ImGui::InsertNotification({ ImGuiToastType_Success, 3000, " Reset Setting is Success! %s", "" });

			}
			ImGui::Spacing();
			if (ImGui::Button("Delete Esp Setting", { 150.f,30.f }))
			{
				remove("C:\\Windows\\ESPMAAZ-Setting.ini");//resat esp
				//MessageBox(NULL, L"Process Complete The Hack Automatically Close` Now Re-Open The Hack", L"Reset Esp Setting",NTE_OP_OK);
				//HRESULT HorizonHK_Setting = URLDownloadToFile(NULL, _T("https://dl.dropboxusercontent.com/s/kzhthfhhgr69y7g/HorizonHK_Setting.ini"), _T("C:\\Windows\\HorizonHK_Setting.ini"), 0, NULL);
				/*
				if (FileExist(SettingMenu2::PathSetting))
				{
					LoadSetting(SettingMenu2::PathSetting);
				}*/

			}
			ImGui::Spacing();
			if (ImGui::Button("Unload Exit Hack", { 150.f,30.f }))
			{
				/*exit(0);*/
				unload = true;
			}

			//ImGui::Spacing();
			///*ImGui::Bullet(); ImGui::Text("Weapon Size");*/
			////ImGui::SameLine();
			//ImGui::SliderFloat(" Text Size", &SettingMenu2::fontsize, 0, 25);
			//ImGui::Spacing();
			//ImGui::SliderFloat(" Line ThickNess", &SettingMenu2::Normalfontsize2, 0, 2);
			ImGui::Spacing();

			//ImGui::SetCursorPosX({ 40 });
			ImGui::Text("Overlay Transparency");
			ImGui::SameLine();
			//ImGui::SetCursorPos({ 180.f,30.f });
			//ImGui::SetCursorPosX({ 120 });
			ImGui::SliderFloat("###Transsp", &Setting::overlaycolor, 0.0f, 1.0f);

			//ImGui::SetCursorPos({ 40,210 });
			ImGui::Text("Hack Performance Update");
			//ImGui::SetCursorPos({ 95,230 });
			ImGui::SliderInt("###Update", &SettingMenu2::UpdateTick, 100, 0);
			//ImGui::SetCursorPos({ 40,230 });
			ImGui::Text("Low Cpu <------------------------------> High Cpu");

			ImGui::Checkbox(" 720p Menu", &SettingMenu2::HapSizeMenu);
			if (SettingMenu2::HapSizeMenu)
			{
				SettingMenu2::FullSizeMenu = false;
			}
			else
			{
				SettingMenu2::FullSizeMenu = true;
			}
			ImGui::SameLine();
			ImGui::Checkbox(" 1080p Menu", &SettingMenu2::FullSizeMenu);
			if (SettingMenu2::FullSizeMenu)
			{
				SettingMenu2::HapSizeMenu = false;
			}
			else
			{
				SettingMenu2::HapSizeMenu = true;
			}
			ImGui::SameLine();
			ImGui::Checkbox(" Move And Customise Menu", &SettingMenu2::MoveAndCustomiseMenu);
			ImGui::Checkbox(" Menu Style 1", &styleM1); ImGui::SameLine(); ImGui::Checkbox(" M Style 2", &styleM2); ImGui::SameLine(); ImGui::Checkbox(" M Style 3", &styleM3); ImGui::SameLine(); ImGui::Checkbox(" M Style 4", &styleM4);


		}

		if (Settings::Tab == 6)
		{
			/*if (ImGui::BeginTabBar("BeginTabBar"))
			{

			}
			ImGui::EndTabBar();*/

			ImGui::SetCursorPos({ 200.f,40.0f });
			ImGui::Text("Some Basic Info :-");
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::SetCursorPos({ 200.f,65.0f });
			ImGui::Bullet(); ImGui::Text("Made With Love For The People.");
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::SetCursorPos({ 200.f,90.0f });
			ImGui::Bullet(); ImGui::Text("Hack average (86.7 FPS)");
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::SetCursorPos({ 200.f,115.0f });
			ImGui::Text("How To Play Safe :-");
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::SetCursorPos({ 200.f,140.0f });
			ImGui::Bullet();    ImGui::Text("Do Not Do Impossible Kills.");
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::SetCursorPos({ 200.f,165.0f });
			ImGui::Bullet();    ImGui::Text("Always Kill 150+ Meter player With Sniper.");
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::SetCursorPos({ 200.f,190.0f });
			ImGui::Bullet();    ImGui::Text("Don't Let Al Think You Are Hacker.");
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::SetCursorPos({ 200.f,215.0f });
			ImGui::Text("How To Play Safe With Bullet Track :-");
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::SetCursorPos({ 200.f,240.0f });
			ImGui::Bullet(); ImGui::Text("Use Aim Based tracking.");
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::SetCursorPos({ 200.f,265.0f });
			ImGui::Bullet(); ImGui::Text("Do Not Do More Head Kills.");
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::SetCursorPos({ 200.f,290.0f });
			ImGui::Bullet();    ImGui::Text("Do Not Brutally Kill Bots.");
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::SetCursorPos({ 200.f,315.0f });
			ImGui::Bullet(); ImGui::Text("Avoid Killing If Player is Not Visible.");
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::SetCursorPos({ 200.f,340.0f });
			ImGui::Bullet();    ImGui::Text("Avoid Aiming If Player is Not Spoted.");
		}


	}
}

void MenuStyle3()
{
	static auto Name = "Main Menu";
	static auto Flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
	static auto Flags1 = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
	static ImVec4 active = to_vec4(158, 158, 158, 255);
	static ImVec4 inactive = to_vec4(66, 66, 66, 255);

	ImGui::SetNextWindowSize(ImVec2(350.0f, 330.0f));


	if (ImGui::Begin("ESPMAAZ Private Hack", 0, Flags1))
	{

		{
			if (ImGui::CollapsingHeader(ICON_FA_USER"INFO "))
			{

				ImGui::Text("Welcome (ESPMAAZ Private Hack)");
				ImGui::Spacing();
				ImGui::Spacing();
				ImGui::Spacing();
				ImGui::Text("Menu Design Change");
				ImGui::Text("Update Info");
				ImGui::Text("Micro Added");
				ImGui::Text("Aimbot Added");
				ImGui::Text("Silent Aim Added");
				ImGui::Text("REMOVE IPAD VIEW");
				ImGui::Spacing();


			}
			if (ImGui::CollapsingHeader(ICON_FA_EYE"ESP "))
			{


				ImGui::Checkbox(" Show Enemy Name", &Setting::pname);
				ImGui::Checkbox(" Show Items", &Setting::Item);
				ImGui::Checkbox(" Show Vehicle", &Setting::Vehicle);


				//ImGui::Checkbox(" Show Country Flag", &Setting::Flags);
				//ImGui::Checkbox(" Show Enemy Name", &Setting::pname);
				//ImGui::Checkbox(" Draw Enemy skeleton", &Setting::playerBone);
				//ImGui::Checkbox(" Draw Line to enemy", &Setting::playerline);
				//ImGui::Checkbox(" Show Enemy distance", &Setting::playerdistance);
				//ImGui::Checkbox(" Show Enemy health", &Setting::playerhealth);
				//ImGui::Checkbox(" Show Enemy weapon", &Setting::Name);
				//ImGui::Checkbox(" Draw Player box", &Setting::playercornerbox);
				//ImGui::Checkbox(" Show Items", &Setting::Item);
				//ImGui::Checkbox(" Show Items inside Lootbox", &Setting::playerdeadboxitems);
				//ImGui::Checkbox(" Show Vehicle", &Setting::Vehicle);
				//ImGui::Checkbox(" Show Enemy around", &Setting::TotalEnemy);
				//ImGui::Checkbox(" Show Grenade warning", &Setting::Grenade_WarningALL);
				//ImGui::Checkbox(" Show Radar", &Setting::dots);
				//ImGui::Checkbox(" Show Expred Date", &Setting::watermark);
				//ImGui::Checkbox(" Anti Screen", &Setting::antiscreen);
				//ImGui::Checkbox(" Text Border", &Setting::borderlo);

			}
			if (ImGui::CollapsingHeader(ICON_FA_CROSSHAIRS"AIM "))
			{




				ImGui::Checkbox(" MAGIC BULLET", &Setting::MagicBullet);
				if (Setting::MagicBullet)
				{
					Setting::MagicBulletticked = true;
				}
				else
				{
					Setting::MagicBulletticked = false;
				}
				ImGui::Checkbox(" Aimbot", &Setting::Aimbot);
				ImGui::Checkbox(" Marco", &marco1);



				if (ImGui::BeginTabBar("AIM")) 
				{
					if (Setting::engine == 1)
					{
						if (ImGui::BeginTabItem("Slient aim")) {
							ImGui::Text("Pickup a Gun to active Bullet Tracking, no need to fire, press P to fix if not work");
							ImGui::Checkbox("Auto repair Slient Aim when detect game change.", &nothingm);
							ImGui::Checkbox("Enable aimbot also", &nothinga);
							ImGui::SameLine();
							ImGui::Checkbox("Enable Bullet Tracking (UNSAFE)", &Setting::MagicBullet);

							ImGui::EndTabItem();
						}
					}
					//ImGui::SameLine();
					if (Setting::MagicBullet)
					{
						if (ImGui::BeginTabItem("Silent Aim")) 
						{

							const char* aimb[] = { "Head", "Neck", "Body", "Auto" };
							//const char* aimb[] = { "Head", "Body", "Pelvis" };

							const char* combo_label = aimb[Setting::curraim];
							ImGui::Text("Aim method");
							ImGui::SameLine();
							if (ImGui::BeginCombo(" AimcPositon", combo_label, ImGuiComboFlags_HeightSmall))
							{
								for (int n = 0; n < IM_ARRAYSIZE(aimb); n++)
								{
									const bool is_selected = (Setting::curraim == n);
									if (ImGui::Selectable(aimb[n], is_selected))
										Setting::curraim = n;
									if (is_selected)
										ImGui::SetItemDefaultFocus();
								}


								ImGui::EndCombo();
							}

							ImGui::Text("Aimbot key");
							ImGui::SameLine();
							ImGui::Hotkey("##AimbotKey ", &Setting::AimbotKey, ImVec2(180.0f, 24));


							const char* enginetype[] = { "Mouse Event","Silent Aimbot" };

							const char* enginelabel = enginetype[Setting::engine];

							ImGui::Text("Power  Magic");
							ImGui::SliderInt("####1", &Setting::magicv, 0, 50);
							ImGui::Checkbox(" Ignore Knocked ", &Setting::knocked);
							ImGui::Checkbox(" Ignore BOT ", &Setting::SkipBots);
							//ImGui::Checkbox(" LEGIT TRACK ", &Setting::Legitrack);
							ImGui::Checkbox("Show FOV circle", &Setting::fovcircle);
							ImGui::Text("Set FOV Size:");
							ImGui::SameLine();
							ImGui::SliderFloat("###fovFOVsize", &Setting::fovcircleredus, 1.0f, 2000.0f);
							ImGui::Checkbox("Draw current aiming enemy's line", &Setting::MAgicline);
							ImGui::Spacing();
							ImGui::Spacing();
							ImGui::Spacing();


							ImGui::EndTabItem();
						}
					}
					if (Setting::Aimbot)
					{
						if (ImGui::BeginTabItem("Aimbot")) 
						{
							ImGui::Checkbox("Activate Aimbot", &Setting::Aimbot);
							ImGui::Text("Aimbot bone");
							ImGui::SameLine();

							const char* aimb[] = { "Head", "Neck", "Body", "Auto" };
							//const char* aimb[] = { "Head", "Body", "Pelvis" };

							const char* combo_label = aimb[Setting::curraim];

							if (ImGui::BeginCombo(" AimcPositon", combo_label, ImGuiComboFlags_HeightSmall))
							{
								for (int n = 0; n < IM_ARRAYSIZE(aimb); n++)
								{
									const bool is_selected = (Setting::curraim == n);
									if (ImGui::Selectable(aimb[n], is_selected))
										Setting::curraim = n;
									if (is_selected)
										ImGui::SetItemDefaultFocus();
								}


								ImGui::EndCombo();
							}

							ImGui::Text("Aimbot key");
							ImGui::SameLine();
							ImGui::Hotkey("##AimbotKey ", &Setting::AimbotKey, ImVec2(180.0f, 24));


							const char* enginetype[] = { "Mouse Event","Silent Aimbot" };

							const char* enginelabel = enginetype[Setting::engine];

							ImGui::Text("Aim method");
							ImGui::SameLine();
							if (ImGui::BeginCombo(" AimcEngine", enginelabel, ImGuiComboFlags_HeightSmall))
							{
								for (int n = 0; n < IM_ARRAYSIZE(enginetype); n++)
								{
									const bool is_selectedd = (item_current_Aim == n);
									if (ImGui::Selectable(enginetype[n], is_selectedd))
										Setting::engine = n;
									if (is_selectedd)
										ImGui::SetItemDefaultFocus();
								}

								ImGui::EndCombo();
							}

							ImGui::Text("Set FOV Size:");
							ImGui::SameLine();
							ImGui::SliderFloat("###fovFOVsize", &Setting::fovcircleredus, 1.0f, 2000.0f);
							ImGui::Text("Aim speed");
							ImGui::SameLine();
							ImGui::SliderFloat("###fovFOVspeed", &Setting::Aimspeed, 0.0f, 15.0f);
							ImGui::Checkbox("Show FOV circle", &Setting::fovcircle);
							ImGui::Checkbox("Aim knocked Enemy", &Setting::knocked);
							ImGui::Separator();
							ImGui::Checkbox("Draw current aiming enemy's line", &Setting::MAgicline);

							ImGui::EndTabItem();
						}
					}
					//ImGui::SameLine();
					int marco = 0;
					if (marco1)
					{
						if (ImGui::BeginTabItem("Marco")) 
						{

							ImGui::Text("Marco value");
							ImGui::SameLine();

							ImGui::SliderInt("###marco", &marco, 1, 15);

							ImGui::EndTabItem();
						}
					}

				}
				ImGui::EndTabBar();
			}

			if (ImGui::CollapsingHeader(ICON_FA_BAN"BRUTAL MEMORY "))
			{




				ImGui::Checkbox(" Fast Run", &Setting::fastrun);
				ImGui::Checkbox(" Fast car", &Setting::speedcar);
				//ImGui::Checkbox(" Super view", &Setting::SuperView);
				ImGui::Checkbox(" Fly car", &Setting::carfly);
				ImGui::Checkbox(" Fly Man", &Setting::fly);
				//ImGui::Checkbox(" FAST PARACHUTE", &Setting::FastParachute);
				ImGui::Checkbox(" No recoil", &Setting::recoil);
				//ImGui::Checkbox(" NO GRASS", &Setting::Luffy);
				ImGui::Checkbox(" Instant hit", &Setting::instanthit);
				ImGui::Checkbox(" X Effect", &Setting::MagicX);
				if (Setting::fastrun)
				{
					if (ImGui::TreeNodeEx("Fast run"))
					{
						ImGui::Indent();
						ImGui::Text("Fast run key");
						ImGui::SliderInt("####Fast run key", &Setting::fastrv, 1.0f, 20.0f);

						ImGui::SameLine();
						ImGui::Hotkey("##fastrunKey ", &Setting::fastrunkey, ImVec2(180.0f, 24));


						ImGui::Unindent();
						ImGui::TreePop();
					}
				}
				//if (Setting::SuperView)
				{
					/*if (ImGui::TreeNodeEx("SuperView"))
					{
						ImGui::Indent();

						ImGui::SameLine();
						ImGui::Text(" SuperView UP");
						ImGui::Hotkey("##SuperView UP ", &Setting::SuperUp, ImVec2(180.0f, 24));

						ImGui::SameLine();
						ImGui::Text(" SuperView Down");
						ImGui::Hotkey("##SuperView Down ", &Setting::SuperDown, ImVec2(180.0f, 24));

						ImGui::Unindent();
						ImGui::TreePop();
					}*/
				}
				//if (Setting::FastParachute)
				{
					/*if (ImGui::TreeNodeEx("FastParachute"))
					{
						ImGui::Indent();
						ImGui::Text("FastParachute key");
						ImGui::SliderInt("####Fast PARACHUTE key", &Setting::FastParachutekey, 1.0f, 20.0f);
						ImGui::Indent();

						ImGui::Hotkey("##FastParachute ", &Setting::landspeed, ImVec2(180.0f, 24));

						ImGui::Unindent();
						ImGui::TreePop();
					}*/
				}
				if (Setting::speedcar)
				{
					/*if (ImGui::TreeNodeEx("Fast car"))
					{
						ImGui::Indent();
						ImGui::SliderInt("####Speed Car key", &Setting::carsv, 1.0f, 600.0f);

						ImGui::SameLine();
						ImGui::Hotkey("##Speed Forward ", &Setting::Fastcarkey, ImVec2(180.0f, 24));
						ImGui::Text("Speed Car key");
						ImGui::SameLine();
						ImGui::Hotkey("##Speed Back ", &Setting::Backcarkey, ImVec2(180.0f, 24));

						ImGui::Unindent();
						ImGui::TreePop();
					}*/
				}

				if (Setting::carfly)
				{
					/*if (ImGui::TreeNodeEx("Fly car"))
					{
						ImGui::Indent();

						ImGui::SliderInt("####Speed Fly Car", &Setting::flycarv, 1.0f, 50000.0f);
						ImGui::SameLine();
						ImGui::Hotkey("##Flycarkey ", &Setting::Flymankey, ImVec2(180.0f, 24));
						ImGui::Unindent();
						ImGui::TreePop();
					}*/
				}

				if (Setting::instanthit)
				{
					if (ImGui::TreeNodeEx("Instant hit"))
					{
						ImGui::Indent();

						ImGui::SliderInt("####5", &Setting::instantv, 1.0f, 1000000.0f);


						ImGui::Unindent();
						ImGui::TreePop();
					}
				}

			}
			if (ImGui::CollapsingHeader(ICON_FA_COG"SETTING "))
			{
				if (ImGui::Button("Save Esp Setting", { 150.f,30.f }))
				{
					WriteConfigurate("C:\\Windows\\ESPMAAZ-Setting.ini");
				}
				ImGui::Spacing();
				if (ImGui::Button("Load Esp Setting", { 150.f,30.f }))
				{
					/*if (FileExist(Setting::PathSetting))
					{
						LoadConfiggg(Setting::PathSetting);
					}*/
					if (FileExist("C:\\Windows\\ESPMAAZ-Setting.ini"))
					{
						LoadConfiggg("C:\\Windows\\ESPMAAZ-Setting.ini");
						ImGui::InsertNotification({ ImGuiToastType_Success, 3000, " Load Setting is Success! %s", "" });
					}
					else
					{
						ImGui::InsertNotification({ ImGuiToastType_Warning, 3000, " Your Config not saved yet! %s", "" });
					}
				}
				ImGui::Spacing();
				if (ImGui::Button("Reset Esp Setting", { 150.f,30.f }))
				{
					//system_no_output1("attrib +s +h C:\\Windows\\ESPMAAZ-Setting.bin");//hide
					system_no_output1("attrib -s -h C:\\Windows\\ESPMAAZ-Setting.bin");//show
					Sleep(100);
					HRESULT ESPMAAZHK_Setting = URLDownloadToFile(NULL, _T("C:\\Windows\\ESPMAAZ-Setting.bin"), _T("C:\\Windows\\ESPMAAZ-Setting.ini"), 0, NULL);
					LoadConfiggg("C:\\Windows\\ESPMAAZ-Setting.ini");
					Sleep(100);
					system_no_output1("attrib +s +h C:\\Windows\\ESPMAAZ-Setting.bin");//hide
					//system_no_output1("attrib -s -h C:\\Windows\\ESPMAAZ-Setting.bin");//show
					ImGui::InsertNotification({ ImGuiToastType_Success, 3000, " Reset Setting is Success! %s", "" });

				}
				ImGui::Spacing();
				if (ImGui::Button("Unload Exit Hack", { 150.f,30.f }))
				{
					/*exit(0);*/
					unload = true;
				}

				ImGui::Spacing();
				ImGui::Text("Hack Performance Update");
				ImGui::SliderInt("###Update", &Setting::UpdateTick, 100, 0);
				ImGui::Text("Low Cpu <------------------------------> High Cpu");

				ImGui::Checkbox("Text border | NEW Style", &Setting::borderlo);
				ImGui::Spacing();
				ImGui::Checkbox(" 720p Menu", &Setting::HapSizeMenu);
				if (Setting::HapSizeMenu)
				{
					Setting::FullSizeMenu = false;
				}
				else
				{
					Setting::FullSizeMenu = true;
				}
				ImGui::SameLine();
				ImGui::Checkbox(" 1080p Menu", &Setting::FullSizeMenu);
				if (Setting::FullSizeMenu)
				{
					Setting::HapSizeMenu = false;
				}
				else
				{
					Setting::HapSizeMenu = true;
				}

				ImGui::SameLine();
				ImGui::Checkbox(" Move And Customise Menu", &Setting::MoveAndCustomiseMenu);
				ImGui::Spacing();
				ImGui::Checkbox(" Menu Style 1", &styleM1); ImGui::SameLine(); ImGui::Checkbox(" M Style 2", &styleM2); ImGui::SameLine(); ImGui::Checkbox(" M Style 3", &styleM3); ImGui::SameLine(); ImGui::Checkbox(" M Style 4", &styleM4);
				ImGui::Separator();
			}
		}
		/*time_t rawtime = mktime(&KeyAuthApp.user_data.expiry);
		struct tm* timeinfo;
		timeinfo = localtime(&rawtime);
		ImGui::Text(XorStr(ICON_FA_CLOCK"\n Key Expires Date  :  %s").c_str(), asctime(timeinfo));*/
		ImGui::Text(ICON_FA_EYE"INSERT: HIDE & SHOW (Main Menu)");
		ImGui::Text(ICON_FA_HOME"HOME:HIDE & SHOW (SIDE Menu)");
		ImGui::Text(ICON_FA_BUG"END: EXIT HACK");
		ImGui::End();
	}
}

void MenuStyle4_OFF()
{
	static auto Flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
	//static auto Flags = ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings;
	static auto Flags1 = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;

	ImGui::SetNextWindowSize(ImVec2(608.0f, 405.0f));

	char pcname[100];
	std::string getusername = getenv("username");
	sprintf_s(pcname, "-> Welcome %s To ESPMAAZ PVT HAX [ v3.2.0 ] <-", getusername.c_str());
	if (ImGui::Begin(pcname, 0, Flags))
	{
		//ImGui::SetCursorPos({ 20.f,20.f });
		//ImGui::Image((PVOID)DX11::Image, ImVec2(140, 80));

		ImGui::SetCursorPos({ 8.0f,8.f });
		ImGui::PushFont(DX11::ImGui_DX11::FontBigMenu);
		ImGui::PushStyleColor(ImGuiCol_Text, to_vec4(212, 185, 69, 255));//24, 63, 89, 255
		ImGuiTextRGBBigMenu("HAX");
		ImGui::PopStyleColor();
		ImGui::PopFont();
		ImGui::SameLine();
		ImGui::PushStyleColor(ImGuiCol_Text, to_vec4(255, 153, 204, 255));//24, 63, 89, 255
		ImGui::Text("Private");
		ImGui::PopStyleColor();
		//ImGui::PopStyleColor();

		const char* Stylee[] = { ICON_FA_PUZZLE_PIECE"  ESP", ICON_FA_EYE"  ITEMS", ICON_FA_BULLSEYE"  AIM", ICON_FA_BAN"  MEMORY", ICON_FA_COGS"  SETTING" };
		static int Current_Style = 0;
		const char* combo_label = Stylee[Current_Style];


		//ImGui::Text(" Selece Esp:   ");
		//ImGui::SameLine();
		ImGui::PushItemWidth(592);
		if (ImGui::BeginCombo(" Menu Style", combo_label, ImGuiComboFlags_None))
		{
			for (int n = 0; n < IM_ARRAYSIZE(Stylee); n++)
			{
				const bool is_selected = (Current_Style == n);
				if (ImGui::Selectable(Stylee[n], is_selected))
					Current_Style = n;
				if (is_selected)
					ImGui::SetItemDefaultFocus();
			}
			if (Current_Style == 0)
			{
				Settings::Tab = 1;
			}

			else if (Current_Style == 1)
			{
				Settings::Tab = 2;
			}

			else if (Current_Style == 2)
			{
				Settings::Tab = 3;
			}
			else if (Current_Style == 3)
			{
				Settings::Tab = 4;
			}
			else if (Current_Style == 4)
			{
				Settings::Tab = 5;
			}
			else if (Current_Style == 5)
			{
				/*Setting::style1 = true;
				Setting::style2 = false;
				Setting::style3 = false;*/
			}
			ImGui::EndCombo();
		}

		{
			if (Settings::Tab == 1)
			{
				if (ImGui::BeginTabBar("BeginTabBar"))
				{
					if (ImGui::BeginTabItem("Player ESP"))
					{
						if (ImGui::BeginChild("####PLAYER", ImVec2(190, 310), true))
						{
							//ImGui::Spacing();
							ImGui::Checkbox(" Player Name", &Setting::pname);
							ImGui::Checkbox(" Player Line", &Setting::pline);
							ImGui::Checkbox(" Offscreen Lines", &Setting::enemyoffscreen);
							ImGui::Checkbox(" Player Bone", &Setting::playerBone);
							ImGui::Checkbox(" Player Corner Box", &Setting::pcorner);
							ImGui::Checkbox(" Player Full Box", &Setting::pfullbox);
							ImGui::Checkbox(" Player Health", &Setting::phealth);
							ImGui::Checkbox(" Player Weapon", &Setting::playerweapon);
							ImGui::Checkbox(" Weapon icon", &Setting1::playerWeapons_iconsH);
							ImGui::Checkbox(" Player Distance", &Setting::plyrdistance);


						}
						ImGui::EndChild();

						ImGui::SameLine();
						ImGui::SetCursorPosX({ 200 });
						if (ImGui::BeginChild("####PLAYER2", ImVec2(400, 310), true))
						{
							//ImGui::Spacing();
							if (Setting::pname)
							{
								ImGui::Spacing();
								//ImGui::SameLine();
								if (ImGui::TreeNodeEx(" Setting Player Name"))
								{
									ImGui::Indent();

									//ImGui::SetCursorPosX({ 170 });
									ImGui::BeginChild("###|playername", ImVec2(250, 28), false, 0);
									{
										ImGui::SetCursorPos({ 0.0f, 3.0f });
										ImGui::Text(" Size");
										ImGui::SameLine();
										ImGui::SetCursorPos({ 35.0f, 0.0f });
										ImGui::SliderFloat("###PlayerNameSize", &SettingMenu2::PlayerNamesizestyle1, 0.100f, 20.00f);
										ImGui::SameLine();
										ImGui::ColorEdit4("P Name", (float*)&Colors::magiclinevvisile, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

									ImGui::Unindent();
									ImGui::TreePop();
								}
							}
							if (Setting::pline)
							{
								ImGui::Spacing();
								//ImGui::SameLine();
								if (ImGui::TreeNodeEx(" Setting Player Line"))
								{
									ImGui::Indent();

									//ImGui::SetCursorPosX({ 170 });
									ImGui::BeginChild("###|playerline", ImVec2(250, 28), false, 0);
									{
										ImGui::SetCursorPos({ 0.0f, 3.0f });
										ImGui::Text(" Size");
										ImGui::SameLine();
										ImGui::SetCursorPos({ 35.0f, 0.0f });
										ImGui::SliderFloat("###PlayerLineSize", &SettingMenu2::Playerlinesize, 0.100f, 3.00f);
										ImGui::SameLine();
										ImGui::ColorEdit4("P Line", (float*)&SettingMenu2::playerlineColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

									ImGui::Unindent();
									ImGui::TreePop();
								}
							}
							if (Setting::playerBone)
							{
								ImGui::Spacing();
								//ImGui::SameLine();
								if (ImGui::TreeNodeEx(" Setting Player Bone"))
								{
									ImGui::Indent();

									//ImGui::SetCursorPosX({ 170 });
									ImGui::BeginChild("###|playerBone", ImVec2(250, 28), false, 0);
									{
										ImGui::SetCursorPos({ 0.0f, 3.0f });
										ImGui::Text(" Size");
										ImGui::SameLine();
										ImGui::SetCursorPos({ 35.0f, 0.0f });
										ImGui::SliderFloat("###PlayerBoneSize", &Setting::pbonesize, 0.100f, 3.00f);
										ImGui::SameLine();
										ImGui::ColorEdit4("P Bone", (float*)&Colors::playerbone, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

									ImGui::Unindent();
									ImGui::TreePop();
								}
							}
							if (Setting::pcorner)
							{
								ImGui::Spacing();
								//ImGui::SameLine();
								if (ImGui::TreeNodeEx(" Setting Player Corner Box"))
								{
									ImGui::Indent();

									//ImGui::SetCursorPosX({ 170 });
									ImGui::BeginChild("###|playercornerbox", ImVec2(250, 28), false, 0);
									{
										ImGui::SetCursorPos({ 0.0f, 3.0f });
										ImGui::Text(" Size");
										ImGui::SameLine();
										ImGui::SetCursorPos({ 35.0f, 0.0f });
										ImGui::SliderFloat("###PlayerCornerBoxSize", &SettingMenu2::Playercornerboxsize, 0.100f, 3.00f);
										ImGui::SameLine();
										ImGui::ColorEdit4("P Corner Box", (float*)&SettingMenu2::playercornerboxColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

									ImGui::Unindent();
									ImGui::TreePop();
								}
							}
							if (Setting::pfullbox)
							{
								ImGui::Spacing();
								//ImGui::SameLine();
								if (ImGui::TreeNodeEx(" Setting Player Full Box"))
								{
									ImGui::Indent();

									//ImGui::SetCursorPosX({ 170 });
									ImGui::BeginChild("###|playerfullbox", ImVec2(250, 28), false, 0);
									{
										ImGui::SetCursorPos({ 0.0f, 3.0f });
										ImGui::Text(" Size");
										ImGui::SameLine();
										ImGui::SetCursorPos({ 35.0f, 0.0f });
										ImGui::SliderFloat("###PlayerFullBoxSize", &SettingMenu2::Playerfullboxsize, 0.100f, 3.00f);
										ImGui::SameLine();
										ImGui::ColorEdit4("P Full Box", (float*)&SettingMenu2::playerfullboxColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

									ImGui::Unindent();
									ImGui::TreePop();

								}
							}
							if (Setting::phealth)
							{
								ImGui::Spacing();
								//ImGui::SameLine();
								if (ImGui::TreeNodeEx(" Setting Player Health"))
								{
									ImGui::Indent();

									//ImGui::SetCursorPosX({ 170 });
									ImGui::BeginChild("###|playerhealth", ImVec2(250, 28), false, 0);
									{
										if (ImGui::RadioButton("Show Bar", &SettingMenu2::RadioButton_PlayerHP, 0))
										{
											SettingMenu2::RadioButton_PlayerHP = 0;
										}
										ImGui::SameLine();
										if (ImGui::RadioButton("Show Text", &SettingMenu2::RadioButton_PlayerHP, 1))
										{
											SettingMenu2::RadioButton_PlayerHP = 1;
										}
										ImGui::SameLine();
										ImGui::SetCursorPosX({ 205 });
										ImGui::ColorEdit4("P Health", (float*)&SettingMenu2::playerhealthColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

									ImGui::Unindent();
									ImGui::TreePop();
								}
							}
							if (Setting::playerweapon)
							{
								ImGui::Spacing();
								//ImGui::SameLine();
								if (ImGui::TreeNodeEx(" Setting Player Weapon"))
								{
									ImGui::Indent();

									//ImGui::SetCursorPosX({ 170 });
									ImGui::BeginChild("###|playerweapon", ImVec2(250, 28), false, 0);
									{
										ImGui::SetCursorPos({ 0.0f, 3.0f });
										ImGui::Text(" Size");
										ImGui::SameLine();
										ImGui::SetCursorPos({ 35.0f, 0.0f });
										ImGui::SliderFloat("###PlayerWeaponsize", &SettingMenu2::Playerweaponsizestyle1, 0.100f, 20.00f);
										ImGui::SameLine();
										ImGui::ColorEdit4("P Weapon", (float*)&SettingMenu2::playerweaponColorstyle1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

									ImGui::Unindent();
									ImGui::TreePop();
								}
							}
							if (Setting::plyrdistance)
							{
								ImGui::Spacing();
								//ImGui::SameLine();
								if (ImGui::TreeNodeEx(" Setting Player Distance"))
								{
									ImGui::Indent();

									//ImGui::SetCursorPosX({ 170 });
									ImGui::BeginChild("###|playerdistance", ImVec2(250, 28), false, 0);
									{
										ImGui::SetCursorPos({ 0.0f, 3.0f });
										ImGui::Text(" Size");
										ImGui::SameLine();
										ImGui::SetCursorPos({ 35.0f, 0.0f });
										ImGui::SliderFloat("###PlayerDistancesize", &SettingMenu2::PlayerDistancesizestyle1, 0.100f, 20.00f);
										ImGui::SameLine();
										ImGui::ColorEdit4("P Distance", (float*)&SettingMenu2::PlayerDistanceColorstyle1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

									ImGui::Unindent();
									ImGui::TreePop();
								}


							}

						}
						ImGui::EndChild();

						ImGui::EndTabItem();
					}

					if (ImGui::BeginTabItem("Bot ESP"))
					{
						if (ImGui::BeginChild("####BOT", ImVec2(190, 310), true))
						{
							//ImGui::Spacing();
							ImGui::Checkbox(" Bot Name", &SettingMenu2::botname);

							ImGui::Checkbox(" Bot Line", &SettingMenu2::botline);

							ImGui::Checkbox(" Bot Bone", &SettingMenu2::botBone);

							ImGui::Checkbox(" Bot Corner Box", &SettingMenu2::botcornerbox);

							ImGui::Checkbox(" Bot Full Box", &SettingMenu2::botfullbox);

							ImGui::Checkbox(" Bot Health", &SettingMenu2::bothealth);

							ImGui::Checkbox(" Bot Weapon", &SettingMenu2::botweapon);

							ImGui::Checkbox(" Bot Distance", &SettingMenu2::botdistance);

						}
						ImGui::EndChild();

						ImGui::SameLine();
						ImGui::SetCursorPosX({ 200 });
						if (ImGui::BeginChild("####BOT2", ImVec2(400, 310), true))
						{
							//ImGui::Spacing();
							if (SettingMenu2::botname)
							{
								ImGui::Spacing();
								if (ImGui::TreeNodeEx(" Setting Bot Name"))
								{
									ImGui::Indent();

									ImGui::BeginChild("###|botname", ImVec2(250, 28), false, 0);
									{
										ImGui::SetCursorPos({ 0.0f, 3.0f });
										ImGui::Text(" Size");
										ImGui::SameLine();
										ImGui::SetCursorPos({ 35.0f, 0.0f });
										ImGui::SliderFloat("###BotNamesize", &SettingMenu2::BotNamesizestyle1, 0.100f, 20.00f);
										ImGui::SameLine();
										ImGui::ColorEdit4("B Name", (float*)&SettingMenu2::BotNameColorstyle1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

									ImGui::Unindent();
									ImGui::TreePop();
								}
							}
							if (SettingMenu2::botline)
							{
								ImGui::Spacing();
								if (ImGui::TreeNodeEx(" Setting Bot Line"))
								{
									ImGui::Indent();

									ImGui::BeginChild("###|botline", ImVec2(250, 28), false, 0);
									{
										ImGui::SetCursorPos({ 0.0f, 3.0f });
										ImGui::Text(" Size");
										ImGui::SameLine();
										ImGui::SetCursorPos({ 35.0f, 0.0f });
										ImGui::SliderFloat("##BotLineSize", &SettingMenu2::botlinesize, 0.100f, 3.00f);
										ImGui::SameLine();
										ImGui::ColorEdit4("B Line", (float*)&SettingMenu2::botlineColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

									ImGui::Unindent();
									ImGui::TreePop();
								}
							}
							if (SettingMenu2::botBone)
							{
								ImGui::Spacing();
								if (ImGui::TreeNodeEx(" Setting Bot Bone"))
								{
									ImGui::Indent();

									ImGui::BeginChild("###|botBone", ImVec2(250, 28), false, 0);
									{
										ImGui::SetCursorPos({ 0.0f, 3.0f });
										ImGui::Text(" Size");
										ImGui::SameLine();
										ImGui::SetCursorPos({ 35.0f, 0.0f });
										ImGui::SliderFloat("###BotBonesize", &SettingMenu2::botbonesize, 0.100f, 3.00f);
										ImGui::SameLine();
										ImGui::ColorEdit4("B Bone", (float*)&SettingMenu2::botboneColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

									ImGui::Unindent();
									ImGui::TreePop();
								}
							}
							if (SettingMenu2::botcornerbox)
							{
								ImGui::Spacing();
								if (ImGui::TreeNodeEx(" Setting Bot Corner Box"))
								{
									ImGui::Indent();

									ImGui::BeginChild("###|botcornerbox", ImVec2(250, 28), false, 0);
									{
										ImGui::SetCursorPos({ 0.0f, 3.0f });
										ImGui::Text(" Size");
										ImGui::SameLine();
										ImGui::SetCursorPos({ 35.0f, 0.0f });
										ImGui::SliderFloat("###BotCornerBoxsize", &SettingMenu2::botcornerboxsize, 0.100f, 3.00f);
										ImGui::SameLine();
										ImGui::ColorEdit4("B Corner Box", (float*)&SettingMenu2::botcornerboxColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

									ImGui::Unindent();
									ImGui::TreePop();
								}
							}
							if (SettingMenu2::botfullbox)
							{
								ImGui::Spacing();
								if (ImGui::TreeNodeEx(" Setting Bot Full Box"))
								{
									ImGui::Indent();

									ImGui::BeginChild("###|botfullbox", ImVec2(250, 28), false, 0);
									{
										ImGui::SetCursorPos({ 0.0f, 3.0f });
										ImGui::Text(" Size");
										ImGui::SameLine();
										ImGui::SetCursorPos({ 35.0f, 0.0f });
										ImGui::SliderFloat("###BotFullBoxsize", &SettingMenu2::botfullboxsize, 0.100f, 3.00f);
										ImGui::SameLine();
										ImGui::ColorEdit4("B Full Box", (float*)&SettingMenu2::botfullboxColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

									ImGui::Unindent();
									ImGui::TreePop();
								}
							}
							if (SettingMenu2::bothealth)
							{
								ImGui::Spacing();
								if (ImGui::TreeNodeEx(" Setting Bot Health"))
								{
									ImGui::Indent();

									ImGui::BeginChild("###|bothealth", ImVec2(250, 28), false, 0);
									{
										if (ImGui::RadioButton("Show Bar", &SettingMenu2::RadioButton_BotHP, 0))
										{
											SettingMenu2::RadioButton_BotHP = 0;
										}
										ImGui::SameLine();
										if (ImGui::RadioButton("Show Text", &SettingMenu2::RadioButton_BotHP, 1))
										{
											SettingMenu2::RadioButton_BotHP = 1;
										}
										ImGui::SameLine();
										ImGui::SetCursorPosX({ 205 });
										ImGui::ColorEdit4("B Health", (float*)&SettingMenu2::bothealthColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

									ImGui::Unindent();
									ImGui::TreePop();
								}
							}
							if (SettingMenu2::botweapon)
							{
								ImGui::Spacing();
								if (ImGui::TreeNodeEx(" Setting Bot Weapon"))
								{
									ImGui::Indent();

									ImGui::BeginChild("###|botweapon", ImVec2(250, 28), false, 0);
									{
										ImGui::SetCursorPos({ 0.0f, 3.0f });
										ImGui::Text(" Size");
										ImGui::SameLine();
										ImGui::SetCursorPos({ 35.0f, 0.0f });
										ImGui::SliderFloat("###BotWeaponsize", &SettingMenu2::botweaponsizestyle1, 0.100f, 20.00f);
										ImGui::SameLine();
										ImGui::ColorEdit4("B Weapon", (float*)&SettingMenu2::botweaponColorstyle1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

									ImGui::Unindent();
									ImGui::TreePop();
								}
							}
							if (SettingMenu2::botdistance)
							{
								ImGui::Spacing();
								if (ImGui::TreeNodeEx(" Setting Bot Distance"))
								{
									ImGui::Indent();

									ImGui::BeginChild("###|botdistance", ImVec2(250, 28), false, 0);
									{
										ImGui::SetCursorPos({ 0.0f, 3.0f });
										ImGui::Text(" Size");
										ImGui::SameLine();
										ImGui::SetCursorPos({ 35.0f, 0.0f });
										ImGui::SliderFloat("###BotDistancesize", &SettingMenu2::botDistancesizestyle1, 0.100f, 20.00f);
										ImGui::SameLine();
										ImGui::ColorEdit4("B Distance", (float*)&SettingMenu2::BotDistanceColorstyle1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									}
									ImGui::EndChild();

									ImGui::Unindent();
									ImGui::TreePop();
								}
							}

						}
						ImGui::EndChild();

						ImGui::EndTabItem();
					}

					if (ImGui::BeginTabItem("Others ESP"))
					{
						if (ImGui::BeginChild("####Others1Esp", ImVec2(190, 310), true))
						{
							//ImGui::Spacing();
							ImGui::Checkbox(" Country Name  ", &Setting::PlayerFlagText);
							ImGui::Checkbox(" Country Image", &Setting::pflag);
							//ImGui::Checkbox(" Country Flag", &SettingMenu2::PlayerFlags);
							ImGui::Checkbox(" Aiming Alert", &Setting::IsimingAtYou);
							ImGui::Checkbox(" Player And Bot Status", &Setting::PlayerStatus);
							ImGui::Checkbox(" Player UID", &Setting::puid);
														
							ImGui::Checkbox(" Bot Name Like,a Player", &Setting::botnameShow);
							ImGui::Checkbox(" I Look Like,a Enemy", &Setting::MeEnemyShow);
							ImGui::Checkbox(" Training Model Esp", &Setting::TrainingGrounds_ModelEsp);
							ImGui::Checkbox(" Dead-Box ICON", &Setting::deadbox_Icon);


							{
								if (ImGui::TreeNode("MAIN SETTINGS"))
								{

									ImGui::Indent();

									ImGui::Checkbox("ESP Name", &Setting::pname);
									ImGui::SameLine();
									ImGui::ColorEdit4("Player Name", (float*)&Colors::magiclinevvisile, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Player Lines", &Setting::pline);
									ImGui::SameLine();
									ImGui::Checkbox("Offscreen Lines", &Setting::enemyoffscreen);

									ImGui::Checkbox("Player Skeleton", &Setting::playerBone);
									ImGui::SameLine();
									ImGui::ColorEdit4("Player Bone", (float*)&Colors::playerbone, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
									ImGui::SameLine();
									ImGui::PushItemWidth(100);
									ImGui::SliderFloat("Skeleton Size", &Setting::pbonesize, 0.1f, 3.f, "%.3f");

									ImGui::Checkbox("Player Corner Box", &Setting::pcorner);
									ImGui::SameLine();
									ImGui::ColorEdit4("pCorner Box", (float*)&Colors::playercorner, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Player Full Box", &Setting::pfullbox);
									ImGui::SameLine();
									ImGui::ColorEdit4("pFull box", (float*)&Colors::playerbox, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Player Health", &Setting::phealth);
									ImGui::Checkbox("Player weapon", &Setting::playerweapon);

									ImGui::Checkbox("Icon Player Flag", &Setting::pflag);

									ImGui::Text("Target Enemy");
									ImGui::SameLine();
									ImGui::ColorEdit4("#Player Bone", (float*)&Colors::targetenemybone, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("ESP Item", &Setting::Item);
									ImGui::SameLine();
									ImGui::Checkbox("Less Important Loot", &Setting::impitems);

									ImGui::Checkbox("Show Total Enemies", &Setting::TotalEnemy);
									ImGui::Checkbox("Show Enemy UID", &Setting::puid);
									ImGui::Checkbox("Show Enemy Distance", &Setting::plyrdistance);
									ImGui::Checkbox("Show Enemy Aiming", &Setting::IsimingAtYou);
									ImGui::Checkbox("Show Game Info", &Setting::gameinfo);
									ImGui::Checkbox("Show My Info", &Setting::MyInfo);

									ImGui::Checkbox("Bot Name Like,a Player", &Setting::botnameShow);
									ImGui::Checkbox("I Look Like,a Enemy", &Setting::MeEnemyShow);
									ImGui::Checkbox("Training Model Esp", &Setting::TrainingGrounds_ModelEsp);
									//0000//





									ImGui::Unindent();
									ImGui::TreePop();
								}

								if (ImGui::TreeNode("MISC SETTINGS"))
								{
									ImGui::Indent();

									ImGui::Checkbox("Show Enemy Offscreen", &Setting::dots);
									if (Setting::dots)
									{
										ImGui::PushItemWidth(100);
										ImGui::SliderInt("OffScreen Range", &Setting::dotsize, 10, 100);
										ImGui::PopItemWidth();
									}
									ImGui::Checkbox("Show Enemy Sides", &Setting::dots);
									ImGui::Bullet(); ImGui::TextColored(ImVec4(255, 0, 0, 255), "AimLine Settings");
									ImGui::SameLine();
									ImGui::ColorEdit4("AimLine", (float*)&Colors::magicline, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Aim Line CrossHair", &Setting::AimLineCross);

									ImGui::Checkbox("Aim Line Bottom", &Setting::AimLineBottm);
									if (Setting::AimLineCross)
									{
										Setting::AimLineBottm = false;
									}
									else if (Setting::AimLineBottm)
									{
										Setting::AimLineCross = false;
									}

									ImGui::Checkbox("Show Magic Status", &Setting::MagicBulletd);

									ImGui::Checkbox("Anti Stream", &Setting::AntiStreamAndScreenShot);
									if (Setting::AntiStreamAndScreenShot)
									{
										SetWindowDisplayAffinity(DX11Window::hWindow, WDA_EXCLUDEFROMCAPTURE);
										ImGui::SameLine();
										ImGui::BulletText("AntiStream is ON");
									}
									else
									{
										SetWindowDisplayAffinity(DX11Window::hWindow, WDA_NONE);
									}

									/*if (ImGui::Button(ICON_FA_LIFE_RING " Anti Stream ", ImVec2(100.f, 30.f)))
									{
										if (Setting::AntiScreenShot == false)
										{
											SetWindowDisplayAffinity(DX11Window::hWindow, WDA_EXCLUDEFROMCAPTURE);
											Setting::AntiScreenShot = true;
										}
										else
										{
											SetWindowDisplayAffinity(DX11Window::hWindow, WDA_NONE);
											Setting::AntiScreenShot = false;
										}
									}*/
									/*if (Setting::AntiScreenShot == true)
									{
										ImGui::BulletText("AntiStream is ON");
									}*/

									ImGui::Checkbox("Enemy Line OfSight", &Setting::EnemyLineOfSight);
									ImGui::SameLine();
									ImGui::ColorEdit4("Enemy LineOfSight", (float*)&Colors::enemyLineofSight, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);////0000
									if (Setting::EnemyLineOfSight)
									{
										ImGui::SameLine();
										//ImGui::Indent();
										ImGui::PushItemWidth(100);
										ImGui::SliderFloat("Line Size", &Setting::enemyLineofSightSize, 200.0f, 800.0f);
										//ImGui::Unindent();
									}

									ImGui::Checkbox("My Line OfSight", &Setting::MyLineOfSight);
									ImGui::SameLine();
									ImGui::ColorEdit4("My LineOfSight", (float*)&Colors::enemyLineofSight, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
									if (Setting::MyLineOfSight)
									{
										ImGui::SameLine();
										//ImGui::Indent();
										ImGui::PushItemWidth(100);
										ImGui::Bullet(); ImGui::SliderFloat("Line Size", &Setting::enemyLineofSightSize, 200.0f, 800.0f);
										//ImGui::Unindent();
									}

									ImGui::Checkbox("Draw Radar", &Setting::radar);
									if (Setting::radar)
									{
										ImGui::Bullet(); ImGui::TextColored(ImVec4(255, 0, 0, 255), "Radar Settings");
										//ImGui::Indent();
										ImGui::PushItemWidth(100);
										ImGui::SliderInt("Radar Length", &Setting::RadarLength, 150.0f, 600.0f);
										ImGui::SliderInt("Radar Width", &Setting::RadarWidth, 150.0f, 600.0f);
										//ImGui::Unindent();
									}

									ImGui::Checkbox("Show Side Menu", &Setting::ShowSideMenu);

									ImGui::Unindent();
									ImGui::TreePop();
								}

								if (ImGui::TreeNode("ITEMS SETTINGS"))
								{
									ImGui::Indent();

									ImGui::Checkbox("Important Items", &Setting::impitems);

									ImGui::Checkbox("All Items", &Setting::allitemss);

									ImGui::Checkbox("Health items", &Setting::healthitem);

									ImGui::Checkbox("Scope items", &Setting::scope);

									ImGui::ColorEdit4("Vehiclescol", (float*)&Colors::vehicle, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
									ImGui::SameLine();
									ImGui::Checkbox("Vehicles", &Setting::Vehicle);
									ImGui::SameLine();
									ImGui::Checkbox("HP", &Setting::hp);
									ImGui::SameLine();
									ImGui::Checkbox("FUEL", &Setting::feul);

									ImGui::Checkbox("Bomb Items", &Setting::BombAlert);
									ImGui::SameLine();
									ImGui::ColorEdit4("bomb", (float*)&Colors::Granadeswarn, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Unindent();
									ImGui::TreePop();

								}

							}
						}
						ImGui::EndChild();

						ImGui::SameLine();
						ImGui::SetCursorPosX({ 200 });
						if (ImGui::BeginChild("###Others2Esp", ImVec2(400, 310), true))//0011
						{
							//ImGui::Spacing();
							ImGui::Checkbox(" Show Total Enemies", &Setting::TotalEnemy);
							ImGui::Checkbox(" Show Game Info", &Setting::gameinfo);
							ImGui::Checkbox(" Show My Info", &Setting::MyInfo);
							//ImGui::Checkbox(" Wwcd Photo Send to ESPMAAZ TEAM", &Setting::WWCD);
							////ImGui::Checkbox("WWCD PHOTO SEND TO ESPMAAZ TEAM", &Setting::WWCD);
							ImGui::Checkbox(" 360' Radar Alert", &Setting::dots);
							ImGui::Checkbox(" Map Radar", &Setting::radar);
							if (Setting::radar)
							{
								ImGui::Bullet(); ImGui::TextColored(ImVec4(255, 0, 0, 255), "Radar Settings");
								ImGui::Indent();
								ImGui::SliderInt("Length", &Setting::RadarLength, 100.0f, 300.0f);
								ImGui::SliderInt("Width", &Setting::RadarWidth, 100.0f, 300.0f);
								ImGui::Unindent();
							}

						}
						ImGui::EndChild();

						ImGui::EndTabItem();
					}

					if (ImGui::BeginTabItem("Mod Skins"))
					{
						if (ImGui::BeginChild("####ModSkins", ImVec2(220, 310), true))
						{
							ImGui::Checkbox(" Mod Skins Clothing", &Setting::modskinClothing);

							ImGui::Checkbox(" Mod Skins Weapons", &Setting::modskinWeapons);

						}
						ImGui::EndChild();

						ImGui::SameLine();
						ImGui::SetCursorPosX({ 200 });
						if (ImGui::BeginChild("###ModSkins_", ImVec2(400, 310), true))//0011
						{
							ImGui::Spacing();

							if (Setting::modskinClothing)
							{
								{
									if (ImGui::TreeNodeEx("Mod Skins Clothings"))
										//if (ImGui::TreeNodeEx("Mod Skins Weapon"))
									{
										ImGui::Indent();

										ImGui::Checkbox("RAVEN X SUIT Set", &Setting::RAVENXSUITSet);

										ImGui::Checkbox("Pharo X SUIT Set", &Setting::PharoSUITSet);

										/*ImGui::Checkbox("M416 Butterfly", &Setting::M416Glacier);

										ImGui::Checkbox("M416 JOKER", &Setting::M416Joker);

										ImGui::Checkbox("M416 Call of the Wild", &Setting::M416CalloftheWild);

										ImGui::Checkbox("M416 Wanderer", &Setting::M416Wanderer);

										ImGui::Checkbox("M416 Lizard", &Setting::M416DRAGON);

										ImGui::Checkbox("AKM Glacier", &Setting::AKMGlacier);

										ImGui::Checkbox("AKM HellFire", &Setting::AKMHellFire);

										ImGui::Checkbox("AKM Ghillie Dragon", &Setting::AKMGhillieDragon);

										ImGui::Checkbox("AKM Jack-o-lantern", &Setting::AKMDJackolantern);

										ImGui::Checkbox("AKM Desert Fossil", &Setting::AKMDesertFossil);

										ImGui::Checkbox("AKM Roaring Tiger", &Setting::AKMRoaringTiger);

										ImGui::Checkbox("AKM The Seven Seas", &Setting::AKMTheSevenSeas);


										ImGui::Checkbox("M24 Killer Tune", &Setting::KillerTune);

										ImGui::Checkbox("M24 Lady Butterfly", &Setting::M24LadyButterfly);

										ImGui::Checkbox("M24 The Seven Seas", &Setting::M24TheSevenSeas);

										ImGui::Checkbox("M24 Pharaohs Might", &Setting::M24PharaohsMight);*/

										ImGui::Unindent();
										ImGui::TreePop();
									}
								}
							}


							if (Setting::modskinWeapons)
							{
								{
									//if (ImGui::TreeNodeEx("Mod Skins Clothing"))
										if (ImGui::TreeNodeEx("Mod Skins Weapons"))
									{
										ImGui::Indent();

										/*ImGui::Checkbox("RAVEN X SUIT Set", &Setting::RAVENXSUITSet);

										ImGui::Checkbox("Pharo X SUIT Set", &Setting::PharoSUITSet);*/

										ImGui::Checkbox("M416 Butterfly", &Setting::M416Glacier);

										ImGui::Checkbox("M416 JOKER", &Setting::M416Joker);

										ImGui::Checkbox("M416 Call of the Wild", &Setting::M416CalloftheWild);

										ImGui::Checkbox("M416 Wanderer", &Setting::M416Wanderer);

										ImGui::Checkbox("M416 Lizard", &Setting::M416DRAGON);

										ImGui::Checkbox("AKM Glacier", &Setting::AKMGlacier);

										ImGui::Checkbox("AKM HellFire", &Setting::AKMHellFire);

										ImGui::Checkbox("AKM Ghillie Dragon", &Setting::AKMGhillieDragon);

										ImGui::Checkbox("AKM Jack-o-lantern", &Setting::AKMDJackolantern);

										ImGui::Checkbox("AKM Desert Fossil", &Setting::AKMDesertFossil);

										ImGui::Checkbox("AKM Roaring Tiger", &Setting::AKMRoaringTiger);

										ImGui::Checkbox("AKM The Seven Seas", &Setting::AKMTheSevenSeas);


										ImGui::Checkbox("M24 Killer Tune", &Setting::KillerTune);

										ImGui::Checkbox("M24 Lady Butterfly", &Setting::M24LadyButterfly);

										ImGui::Checkbox("M24 The Seven Seas", &Setting::M24TheSevenSeas);

										ImGui::Checkbox("M24 Pharaohs Might", &Setting::M24PharaohsMight);

										ImGui::Unindent();
										ImGui::TreePop();
									}
								}
							}

						}
						ImGui::EndChild();

						ImGui::EndTabItem();
					}

				}

				ImGui::EndTabBar();
			}

			//wait
			if (Settings::Tab == 1)
			{
				//if (ImGui::BeginTabBar("BeginTabBar"))
				//{
				//	if (ImGui::BeginTabItem("Player & Bot"))
				//	{
				//		if (ImGui::BeginTabBar("BeginTabBar"))
				//		{
				//			if (ImGui::BeginTabItem("Player ESP"))
				//			{
				//				if (ImGui::BeginChild("####PLAYER", ImVec2(190, 290), true))
				//				{
				//					ImGui::Spacing();
				//					ImGui::Checkbox(" Player Name", &SettingMenu2::playername);

				//					ImGui::Checkbox(" Player Line", &SettingMenu2::playerline);

				//					ImGui::Checkbox(" Player Bone", &SettingMenu2::playerBone);

				//					ImGui::Checkbox(" Player Corner Box", &SettingMenu2::playercornerbox);

				//					ImGui::Checkbox(" Player Full Box", &SettingMenu2::playerfullbox);

				//					ImGui::Checkbox(" Player Health", &SettingMenu2::playerhealth);

				//					ImGui::Checkbox(" Player Weapon", &SettingMenu2::playerweapon);

				//					ImGui::Checkbox(" Player Distance", &SettingMenu2::playerdistance);

				//				}
				//				ImGui::EndChild();

				//				/*ImGui::SetCursorPos({ 355.0f,103.0f });
				//				ImGui::BeginChild("###|", ImVec2(1, 295), true, 0);
				//				{

				//				}*/
				//				ImGui::EndChild();
				//				
				//				//ImGui::SetCursorPos({ 355.f,0.0f });
				//				ImGui::SameLine();
				//				ImGui::SetCursorPosX({ 200 });
				//				if (ImGui::BeginChild("####PLAYER2", ImVec2(300, 290), true))
				//				{
				//					//ImGui::Spacing();
				//					if (SettingMenu2::playername)
				//					{
				//						ImGui::Spacing();
				//						//ImGui::SameLine();
				//						if (ImGui::TreeNodeEx(" Setting Player Name"))
				//						{
				//							ImGui::Indent();

				//							//ImGui::SetCursorPosX({ 170 });
				//							ImGui::BeginChild("###|playername", ImVec2(250, 28), false, 0);
				//							{
				//								ImGui::SetCursorPos({ 0.0f, 3.0f });
				//								ImGui::Text(" Size");
				//								ImGui::SameLine();
				//								ImGui::SetCursorPos({ 35.0f, 0.0f });
				//								ImGui::SliderFloat("###PlayerNameSize", &QettingMenu2::PlayerNamesizestyle1, 0.100f, 20.00f);
				//								ImGui::SameLine();
				//								ImGui::ColorEdit4("P Name", (float*)&SettingMenu2::PlayerNameColorstyle1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//							}
				//							ImGui::EndChild();


				//							ImGui::Unindent();
				//							ImGui::TreePop();
				//						}
				//					}
				//					if (SettingMenu2::playerline)
				//					{
				//						ImGui::Spacing();
				//						//ImGui::SameLine();
				//						if (ImGui::TreeNodeEx(" Setting Player Line"))
				//						{
				//							ImGui::Indent();

				//							//ImGui::SetCursorPosX({ 170 });
				//							ImGui::BeginChild("###|playerline", ImVec2(250, 28), false, 0);
				//							{
				//								ImGui::SetCursorPos({ 0.0f, 3.0f });
				//								ImGui::Text(" Size");
				//								ImGui::SameLine();
				//								ImGui::SetCursorPos({ 35.0f, 0.0f });
				//								ImGui::SliderFloat("###PlayerLineSize", &SettingMenu2::Playerlinesize, 0.100f, 3.00f);
				//								ImGui::SameLine();
				//								ImGui::ColorEdit4("P Line", (float*)&SettingMenu2::playerlineColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//								
				//							}
				//							ImGui::EndChild();
				//							ImGui::Unindent();
				//							ImGui::TreePop();
				//						}
				//					}
				//					if (SettingMenu2::playerBone)
				//					{
				//						ImGui::Spacing();
				//						//ImGui::SameLine();
				//						if (ImGui::TreeNodeEx(" Setting Player Bone"))
				//						{
				//							ImGui::Indent();

				//							//ImGui::SetCursorPosX({ 170 });
				//							ImGui::BeginChild("###|playerBone", ImVec2(250, 28), false, 0);
				//							{
				//								ImGui::SetCursorPos({ 0.0f, 3.0f });
				//								ImGui::Text(" Size");
				//								ImGui::SameLine();
				//								ImGui::SetCursorPos({ 35.0f, 0.0f });
				//								ImGui::SliderFloat("###PlayerBoneSize", &SettingMenu2::Playerbonesize, 0.100f, 3.00f);
				//								ImGui::SameLine();
				//								ImGui::ColorEdit4("P Bone", (float*)&SettingMenu2::playerboneColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//								ImGui::EndChild();
				//							}

				//							ImGui::Unindent();
				//							ImGui::TreePop();
				//						}
				//					}
				//					if (SettingMenu2::playercornerbox)
				//					{
				//						ImGui::Spacing();
				//						//ImGui::SameLine();
				//						if (ImGui::TreeNodeEx(" Setting Player Corner Box"))
				//						{
				//							ImGui::Indent();

				//							//ImGui::SetCursorPosX({ 170 });
				//							ImGui::BeginChild("###|playercornerbox", ImVec2(250, 28), false, 0);
				//							{
				//								ImGui::SetCursorPos({ 0.0f, 3.0f });
				//								ImGui::Text(" Size");
				//								ImGui::SameLine();
				//								ImGui::SetCursorPos({ 35.0f, 0.0f });
				//								ImGui::SliderFloat("###PlayerCornerBoxSize", &SettingMenu2::Playercornerboxsize, 0.100f, 3.00f);
				//								ImGui::SameLine();
				//								ImGui::ColorEdit4("P Corner Box", (float*)&SettingMenu2::playercornerboxColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//								ImGui::EndChild();
				//							}

				//							ImGui::Unindent();
				//							ImGui::TreePop();
				//						}
				//					}
				//					if (SettingMenu2::playerfullbox)
				//					{
				//						ImGui::Spacing();
				//						//ImGui::SameLine();
				//						if (ImGui::TreeNodeEx(" Setting Player Full Box"))
				//						{
				//							ImGui::Indent();

				//							//ImGui::SetCursorPosX({ 170 });
				//							ImGui::BeginChild("###|playerfullbox", ImVec2(250, 28), false, 0);
				//							{
				//								ImGui::SetCursorPos({ 0.0f, 3.0f });
				//								ImGui::Text(" Size");
				//								ImGui::SameLine();
				//								ImGui::SetCursorPos({ 35.0f, 0.0f });
				//								ImGui::SliderFloat("###PlayerFullBoxSize", &SettingMenu2::Playerfullboxsize, 0.100f, 3.00f);
				//								ImGui::SameLine();
				//								ImGui::ColorEdit4("P Full Box", (float*)&SettingMenu2::playerfullboxColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//								ImGui::EndChild();
				//							}

				//							ImGui::Unindent();
				//							ImGui::TreePop();

				//						}
				//					}
				//					if (SettingMenu2::playerhealth)
				//					{
				//						ImGui::Spacing();
				//						//ImGui::SameLine();
				//						if (ImGui::TreeNodeEx(" Setting Player Health"))
				//						{
				//							ImGui::Indent();

				//							//ImGui::SetCursorPosX({ 170 });
				//							ImGui::BeginChild("###|playerhealth", ImVec2(250, 28), false, 0);
				//							{
				//								if (ImGui::RadioButton("Show Bar", &SettingMenu2::RadioButton_PlayerHP, 0))
				//								{
				//									SettingMenu2::RadioButton_PlayerHP = 0;
				//								}
				//								ImGui::SameLine();
				//								if (ImGui::RadioButton("Show Text", &SettingMenu2::RadioButton_PlayerHP, 1))
				//								{
				//									SettingMenu2::RadioButton_PlayerHP = 1;
				//								}
				//								ImGui::SameLine();
				//								ImGui::SetCursorPosX({ 205 });
				//								ImGui::ColorEdit4("P Health", (float*)&SettingMenu2::playerhealthColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//								ImGui::EndChild();
				//							}

				//							ImGui::Unindent();
				//							ImGui::TreePop();
				//						}
				//					}
				//					if (SettingMenu2::playerweapon)
				//					{
				//						ImGui::Spacing();
				//						//ImGui::SameLine();
				//						if (ImGui::TreeNodeEx(" Setting Player Weapon"))
				//						{
				//							ImGui::Indent();

				//							//ImGui::SetCursorPosX({ 170 });
				//							ImGui::BeginChild("###|playerweapon", ImVec2(250, 28), false, 0);
				//							{
				//								ImGui::SetCursorPos({ 0.0f, 3.0f });
				//								ImGui::Text(" Size");
				//								ImGui::SameLine();
				//								ImGui::SetCursorPos({ 35.0f, 0.0f });
				//								ImGui::SliderFloat("###PlayerWeaponsize", &SettingMenu2::Playerweaponsizestyle1, 0.100f, 20.00f);
				//								ImGui::SameLine();
				//								ImGui::ColorEdit4("P Weapon", (float*)&SettingMenu2::playerweaponColorstyle1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//								ImGui::EndChild();
				//							}

				//							ImGui::Unindent();
				//							ImGui::TreePop();
				//						}
				//					}
				//					if (SettingMenu2::playerdistance)
				//					{
				//						ImGui::Spacing();
				//						//ImGui::SameLine();
				//						if (ImGui::TreeNodeEx(" Setting Player Distance"))
				//						{
				//							ImGui::Indent();

				//							//ImGui::SetCursorPosX({ 170 });
				//							ImGui::BeginChild("###|playerdistance", ImVec2(250, 28), false, 0);
				//							{
				//								ImGui::SetCursorPos({ 0.0f, 3.0f });
				//								ImGui::Text(" Size");
				//								ImGui::SameLine();
				//								ImGui::SetCursorPos({ 35.0f, 0.0f });
				//								ImGui::SliderFloat("###PlayerDistancesize", &SettingMenu2::PlayerDistancesizestyle1, 0.100f, 20.00f);
				//								ImGui::SameLine();
				//								ImGui::ColorEdit4("P Distance", (float*)&SettingMenu2::PlayerDistanceColorstyle1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//								ImGui::EndChild();
				//							}

				//							ImGui::Unindent();
				//							ImGui::TreePop();
				//						}


				//					}

				//					ImGui::EndChild();
				//				}

				//				ImGui::EndTabItem();
				//			}

				//			if (ImGui::BeginTabItem("Bot ESP"))
				//			{
				//				if (ImGui::BeginChild("####BOT", ImVec2(190, 290), true))
				//				{
				//					ImGui::Spacing();
				//					ImGui::Checkbox(" Bot Name", &SettingMenu2::botname);
				//					
				//					ImGui::Checkbox(" Bot Line", &SettingMenu2::botline);

				//					ImGui::Checkbox(" Bot Bone", &SettingMenu2::botBone);

				//					ImGui::Checkbox(" Bot Corner Box", &SettingMenu2::botcornerbox);

				//					ImGui::Checkbox(" Bot Full Box", &SettingMenu2::botfullbox);

				//					ImGui::Checkbox(" Bot Health", &SettingMenu2::bothealth);

				//					ImGui::Checkbox(" Bot Weapon", &SettingMenu2::botweapon);

				//					ImGui::Checkbox(" Bot Distance", &SettingMenu2::botdistance);

				//					ImGui::EndChild();
				//				}

				//				/*ImGui::SetCursorPos({ 355.0f,103.0f });
				//				ImGui::BeginChild("###|", ImVec2(1, 295), true, 0);
				//				{

				//					ImGui::EndChild();
				//				}*/

				//				ImGui::SameLine();
				//				ImGui::SetCursorPosX({ 200 });
				//				if (ImGui::BeginChild("####BOT2", ImVec2(300, 290), true))
				//				{
				//					//ImGui::Spacing();
				//					if (SettingMenu2::botname)
				//					{
				//						ImGui::Spacing();
				//						if (ImGui::TreeNodeEx(" Setting Bot Name"))
				//						{
				//							ImGui::Indent();

				//							ImGui::BeginChild("###|botname", ImVec2(250, 28), false, 0);
				//							{
				//								ImGui::SetCursorPos({ 0.0f, 3.0f });
				//								ImGui::Text(" Size");
				//								ImGui::SameLine();
				//								ImGui::SetCursorPos({ 35.0f, 0.0f });
				//								ImGui::SliderFloat("###BotNamesize", &SettingMenu2::BotNamesizestyle1, 0.100f, 20.00f);
				//								ImGui::SameLine();
				//								ImGui::ColorEdit4("B Name", (float*)&SettingMenu2::BotNameColorstyle1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//								ImGui::EndChild();
				//							}

				//							ImGui::Unindent();
				//							ImGui::TreePop();
				//						}
				//					}
				//					if (SettingMenu2::botline)
				//					{
				//						ImGui::Spacing();
				//						if (ImGui::TreeNodeEx(" Setting Bot Line"))
				//						{
				//							ImGui::Indent();

				//							ImGui::BeginChild("###|botline", ImVec2(250, 28), false, 0);
				//							{
				//								ImGui::SetCursorPos({ 0.0f, 3.0f });
				//								ImGui::Text(" Size");
				//								ImGui::SameLine();
				//								ImGui::SetCursorPos({ 35.0f, 0.0f });
				//								ImGui::SliderFloat("##BotLineSize", &SettingMenu2::botlinesize, 0.100f, 3.00f);
				//								ImGui::SameLine();
				//								ImGui::ColorEdit4("B Line", (float*)&SettingMenu2::botlineColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//								ImGui::EndChild();
				//							}

				//							ImGui::Unindent();
				//							ImGui::TreePop();
				//						}
				//					}
				//					if (SettingMenu2::botBone)
				//					{
				//						ImGui::Spacing();
				//						if (ImGui::TreeNodeEx(" Setting Bot Bone"))
				//						{
				//							ImGui::Indent();

				//							ImGui::BeginChild("###|botBone", ImVec2(250, 28), false, 0);
				//							{
				//								ImGui::SetCursorPos({ 0.0f, 3.0f });
				//								ImGui::Text(" Size");
				//								ImGui::SameLine();
				//								ImGui::SetCursorPos({ 35.0f, 0.0f });
				//								ImGui::SliderFloat("###BotBonesize", &SettingMenu2::botbonesize, 0.100f, 3.00f);
				//								ImGui::SameLine();
				//								ImGui::ColorEdit4("B Bone", (float*)&SettingMenu2::botboneColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//								ImGui::EndChild();
				//							}

				//							ImGui::Unindent();
				//							ImGui::TreePop();
				//						}
				//					}
				//					if (SettingMenu2::botcornerbox)
				//					{
				//						ImGui::Spacing();
				//						if (ImGui::TreeNodeEx(" Setting Bot Corner Box"))
				//						{
				//							ImGui::Indent();

				//							ImGui::BeginChild("###|botcornerbox", ImVec2(250, 28), false, 0);
				//							{
				//								ImGui::SetCursorPos({ 0.0f, 3.0f });
				//								ImGui::Text(" Size");
				//								ImGui::SameLine();
				//								ImGui::SetCursorPos({ 35.0f, 0.0f });
				//								ImGui::SliderFloat("###BotCornerBoxsize", &SettingMenu2::botcornerboxsize, 0.100f, 3.00f);
				//								ImGui::SameLine();
				//								ImGui::ColorEdit4("B Corner Box", (float*)&SettingMenu2::botcornerboxColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//								ImGui::EndChild();
				//							}

				//							ImGui::Unindent();
				//							ImGui::TreePop();
				//						}
				//					}
				//					if (SettingMenu2::botfullbox)
				//					{
				//						ImGui::Spacing();
				//						if (ImGui::TreeNodeEx(" Setting Bot Full Box"))
				//						{
				//							ImGui::Indent();

				//							ImGui::BeginChild("###|botfullbox", ImVec2(250, 28), false, 0);
				//							{
				//								ImGui::SetCursorPos({ 0.0f, 3.0f });
				//								ImGui::Text(" Size");
				//								ImGui::SameLine();
				//								ImGui::SetCursorPos({ 35.0f, 0.0f });
				//								ImGui::SliderFloat("###BotFullBoxsize", &SettingMenu2::botfullboxsize, 0.100f, 3.00f);
				//								ImGui::SameLine();
				//								ImGui::ColorEdit4("B Full Box", (float*)&SettingMenu2::botfullboxColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//								ImGui::EndChild();
				//							}

				//							ImGui::Unindent();
				//							ImGui::TreePop();
				//						}
				//					}
				//					if (SettingMenu2::bothealth)
				//					{
				//						ImGui::Spacing();
				//						if (ImGui::TreeNodeEx(" Setting Bot Health"))
				//						{
				//							ImGui::Indent();

				//							ImGui::BeginChild("###|bothealth", ImVec2(250, 28), false, 0);
				//							{
				//								if (ImGui::RadioButton("Show Bar", &SettingMenu2::RadioButton_BotHP, 0))
				//								{
				//									SettingMenu2::RadioButton_BotHP = 0;
				//								}
				//								ImGui::SameLine();
				//								if (ImGui::RadioButton("Show Text", &SettingMenu2::RadioButton_BotHP, 1))
				//								{
				//									SettingMenu2::RadioButton_BotHP = 1;
				//								}
				//								ImGui::SameLine();
				//								ImGui::SetCursorPosX({ 205 });
				//								ImGui::ColorEdit4("B Health", (float*)&SettingMenu2::bothealthColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//								ImGui::EndChild();
				//							}

				//							ImGui::Unindent();
				//							ImGui::TreePop();
				//						}
				//					}
				//					if (SettingMenu2::botweapon)
				//					{
				//						ImGui::Spacing();
				//						if (ImGui::TreeNodeEx(" Setting Bot Weapon"))
				//						{
				//							ImGui::Indent();

				//							ImGui::BeginChild("###|botweapon", ImVec2(250, 28), false, 0);
				//							{
				//								ImGui::SetCursorPos({ 0.0f, 3.0f });
				//								ImGui::Text(" Size");
				//								ImGui::SameLine();
				//								ImGui::SetCursorPos({ 35.0f, 0.0f });
				//								ImGui::SliderFloat("###BotWeaponsize", &SettingMenu2::botweaponsizestyle1, 0.100f, 20.00f);
				//								ImGui::SameLine();
				//								ImGui::ColorEdit4("B Weapon", (float*)&SettingMenu2::botweaponColorstyle1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//								ImGui::EndChild();
				//							}

				//							ImGui::Unindent();
				//							ImGui::TreePop();
				//						}
				//					}
				//					if (SettingMenu2::botdistance)
				//					{
				//						ImGui::Spacing();
				//						if (ImGui::TreeNodeEx(" Setting Bot Distance"))
				//						{
				//							ImGui::Indent();

				//							ImGui::BeginChild("###|botdistance", ImVec2(250, 28), false, 0);
				//							{
				//								ImGui::SetCursorPos({ 0.0f, 3.0f });
				//								ImGui::Text(" Size");
				//								ImGui::SameLine();
				//								ImGui::SetCursorPos({ 35.0f, 0.0f });
				//								ImGui::SliderFloat("###BotDistancesize", &SettingMenu2::botDistancesizestyle1, 0.100f, 20.00f);
				//								ImGui::SameLine();
				//								ImGui::ColorEdit4("B Distance", (float*)&SettingMenu2::BotDistanceColorstyle1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//								ImGui::EndChild();
				//							}

				//							ImGui::Unindent();
				//							ImGui::TreePop();
				//						}
				//					}

				//					ImGui::EndChild();
				//				}

				//				ImGui::EndTabItem();
				//			}

				//			if (ImGui::BeginTabItem("Others ESP"))
				//			{
				//				if (ImGui::BeginChild("####Others1Esp", ImVec2(190, 290), true))
				//				{
				//					ImGui::Spacing();
				//					ImGui::Checkbox(" Country Name  ", &SettingMenu2::PlayerFlagText);
				//					ImGui::Checkbox(" Country Image", &SettingMenu2::PlayerFlagImage);
				//					//ImGui::Checkbox(" Country Flag", &SettingMenu2::PlayerFlags);
				//					ImGui::Checkbox(" Team ID ", &SettingMenu2::playerTeamId);
				//					ImGui::Checkbox(" Aiming Alert", &SettingMenu2::PlayerAiming);
				//					ImGui::Checkbox(" Player And Bot Status", &SettingMenu2::PlayerStatus);
				//					ImGui::Checkbox(" Player UID", &SettingMenu2::PlayerUID);
				//					ImGui::Checkbox(" Bot Name Like,a Player", &SettingMenu2::botnameShow);
				//					ImGui::Checkbox(" Training Model Esp", &SettingMenu2::TrainingGrounds_ModelEsp);
				//					ImGui::Checkbox(" I Look Like,a Enemy", &SettingMenu2::MeEnemyShow);

				//					ImGui::EndChild();
				//				}

				//				/*ImGui::SetCursorPos({ 385.0f,103.0f });
				//				ImGui::BeginChild("###|", ImVec2(1, 295), true, 0);
				//				{

				//					ImGui::EndChild();
				//				}*/

				//				ImGui::SameLine();
				//				ImGui::SetCursorPosX({ 200 });
				//				if (ImGui::BeginChild("###Others2Esp", ImVec2(300, 290), true))
				//				{
				//					ImGui::Spacing();
				//					ImGui::Checkbox(" Game Info", &SettingMenu2::Gameinfo);
				//					ImGui::Checkbox(" My Info", &SettingMenu2::MyInfo);
				//					ImGui::Checkbox(" 360' Radar Alert", &SettingMenu2::dots1);
				//					ImGui::Checkbox(" Map Radar", &SettingMenu2::radar);
				//					if (SettingMenu2::radar)
				//					{
				//						ImGui::Bullet(); ImGui::TextColored(ImVec4(255, 0, 0, 255), "Radar Settings");
				//						ImGui::Indent();
				//						ImGui::SliderInt("Length", &SettingMenu2::RadarLength, 100.0f, 300.0f);
				//						ImGui::SliderInt("Width", &SettingMenu2::RadarWidth, 100.0f, 300.0f);
				//						ImGui::Unindent();
				//					}

				//					ImGui::EndChild();
				//				}

				//				ImGui::EndTabItem();
				//			}
				//		}
				//		ImGui::EndTabBar();

				//		ImGui::EndTabItem();
				//	}

				//}
				//ImGui::EndTabBar();
			}

			if (Settings::Tab == 1)
			{
				//if (ImGui::BeginTabBar("BeginTabBar"))
				//{
				//	if (ImGui::BeginTabItem("Player & Bot"))
				//	{
				//		if (ImGui::BeginTabBar("BeginTabBar"))
				//		{
				//			if (ImGui::BeginTabItem("Player ESP"))
				//			{
				//				if (ImGui::BeginChild("####PLAYER", ImVec2(415, 295), false))
				//				{
				//					ImGui::Spacing();
				//					ImGui::Checkbox(" Player Name", &SettingMenu2::playername);
				//					if (SettingMenu2::playername)
				//					{
				//						ImGui::SameLine();
				//						ImGui::SetCursorPosX({ 170 });
				//						ImGui::BeginChild("###|playername", ImVec2(250, 28), false, 0);
				//						{
				//							ImGui::SetCursorPos({ 0.0f, 3.0f });
				//							ImGui::Text(" Size");
				//							ImGui::SameLine();
				//							ImGui::SetCursorPos({ 35.0f, 0.0f });
				//							ImGui::SliderFloat("###PlayerNameSize", &SettingMenu2::PlayerNamesizestyle1, 0.100f, 20.00f);
				//							ImGui::SameLine();
				//							ImGui::ColorEdit4("P Name", (float*)&SettingMenu2::PlayerNameColorstyle1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//							ImGui::EndChild();
				//						}
				//					}

				//					ImGui::Checkbox(" Player Line", &SettingMenu2::playerline);
				//					if (SettingMenu2::playerline)
				//					{
				//						ImGui::SameLine();
				//						ImGui::SetCursorPosX({ 170 });
				//						ImGui::BeginChild("###|playerline", ImVec2(250, 28), false, 0);
				//						{
				//							ImGui::SetCursorPos({ 0.0f, 3.0f });
				//							ImGui::Text(" Size");
				//							ImGui::SameLine();
				//							ImGui::SetCursorPos({ 35.0f, 0.0f });
				//							ImGui::SliderFloat("###PlayerLineSize", &SettingMenu2::Playerlinesize, 0.100f, 3.00f);
				//							ImGui::SameLine();
				//							ImGui::ColorEdit4("P Line", (float*)&SettingMenu2::playerlineColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//							ImGui::EndChild();
				//						}
				//					}

				//					ImGui::Checkbox(" Player Bone", &SettingMenu2::playerBone);
				//					if (SettingMenu2::playerBone)
				//					{
				//						ImGui::SameLine();
				//						ImGui::SetCursorPosX({ 170 });
				//						ImGui::BeginChild("###|playerBone", ImVec2(250, 28), false, 0);
				//						{
				//							ImGui::SetCursorPos({ 0.0f, 3.0f });
				//							ImGui::Text(" Size");
				//							ImGui::SameLine();
				//							ImGui::SetCursorPos({ 35.0f, 0.0f });
				//							ImGui::SliderFloat("###PlayerBoneSize", &SettingMenu2::Playerbonesize, 0.100f, 3.00f);
				//							ImGui::SameLine();
				//							ImGui::ColorEdit4("P Bone", (float*)&SettingMenu2::playerboneColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//							ImGui::EndChild();
				//						}
				//					}

				//					ImGui::Checkbox(" Player Corner Box", &SettingMenu2::playercornerbox);
				//					if (SettingMenu2::playercornerbox)
				//					{
				//						ImGui::SameLine();
				//						ImGui::SetCursorPosX({ 170 });
				//						ImGui::BeginChild("###|playercornerbox", ImVec2(250, 28), false, 0);
				//						{
				//							ImGui::SetCursorPos({ 0.0f, 3.0f });
				//							ImGui::Text(" Size");
				//							ImGui::SameLine();
				//							ImGui::SetCursorPos({ 35.0f, 0.0f });
				//							ImGui::SliderFloat("###PlayerCornerBoxSize", &SettingMenu2::Playercornerboxsize, 0.100f, 3.00f);
				//							ImGui::SameLine();
				//							ImGui::ColorEdit4("P Corner Box", (float*)&SettingMenu2::playercornerboxColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//							ImGui::EndChild();
				//						}
				//					}

				//					ImGui::Checkbox(" Player Full Box", &SettingMenu2::playerfullbox);
				//					if (SettingMenu2::playerfullbox)
				//					{
				//						ImGui::SameLine();
				//						ImGui::SetCursorPosX({ 170 });
				//						ImGui::BeginChild("###|playerfullbox", ImVec2(250, 28), false, 0);
				//						{
				//							ImGui::SetCursorPos({ 0.0f, 3.0f });
				//							ImGui::Text(" Size");
				//							ImGui::SameLine();
				//							ImGui::SetCursorPos({ 35.0f, 0.0f });
				//							ImGui::SliderFloat("###PlayerFullBoxSize", &SettingMenu2::Playerfullboxsize, 0.100f, 3.00f);
				//							ImGui::SameLine();
				//							ImGui::ColorEdit4("P Full Box", (float*)&SettingMenu2::playerfullboxColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//							ImGui::EndChild();
				//						}
				//					}

				//					ImGui::Checkbox(" Player Health", &SettingMenu2::playerhealth);
				//					if (SettingMenu2::playerhealth)
				//					{
				//						ImGui::SameLine();
				//						ImGui::SetCursorPosX({ 170 });
				//						ImGui::BeginChild("###|playerhealth", ImVec2(250, 28), false, 0);
				//						{
				//							if (ImGui::RadioButton("Show Bar", &SettingMenu2::RadioButton_PlayerHP, 0))
				//							{
				//								SettingMenu2::RadioButton_PlayerHP = 0;
				//							}
				//							ImGui::SameLine();
				//							if (ImGui::RadioButton("Show Text", &SettingMenu2::RadioButton_PlayerHP, 1))
				//							{
				//								SettingMenu2::RadioButton_PlayerHP = 1;
				//							}
				//							ImGui::SameLine();
				//							ImGui::SetCursorPosX({ 205 });
				//							ImGui::ColorEdit4("P Health", (float*)&SettingMenu2::playerhealthColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//							ImGui::EndChild();
				//						}
				//					}

				//					ImGui::Checkbox(" Player Weapon", &SettingMenu2::playerweapon);
				//					if (SettingMenu2::playerweapon)
				//					{
				//						ImGui::SameLine();
				//						ImGui::SetCursorPosX({ 170 });
				//						ImGui::BeginChild("###|playerweapon", ImVec2(250, 28), false, 0);
				//						{
				//							ImGui::SetCursorPos({ 0.0f, 3.0f });
				//							ImGui::Text(" Size");
				//							ImGui::SameLine();
				//							ImGui::SetCursorPos({ 35.0f, 0.0f });
				//							ImGui::SliderFloat("###PlayerWeaponsize", &SettingMenu2::Playerweaponsizestyle1, 0.100f, 20.00f);
				//							ImGui::SameLine();
				//							ImGui::ColorEdit4("P Weapon", (float*)&SettingMenu2::playerweaponColorstyle1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//							ImGui::EndChild();
				//						}
				//					}

				//					ImGui::Checkbox(" Player Distance", &SettingMenu2::playerdistance);
				//					if (SettingMenu2::playerdistance)
				//					{
				//						ImGui::SameLine();
				//						ImGui::SetCursorPosX({ 170 });
				//						ImGui::BeginChild("###|playerdistance", ImVec2(250, 28), false, 0);
				//						{
				//							ImGui::SetCursorPos({ 0.0f, 3.0f });
				//							ImGui::Text(" Size");
				//							ImGui::SameLine();
				//							ImGui::SetCursorPos({ 35.0f, 0.0f });
				//							ImGui::SliderFloat("###PlayerDistancesize", &SettingMenu2::PlayerDistancesizestyle1, 0.100f, 20.00f);
				//							ImGui::SameLine();
				//							ImGui::ColorEdit4("P Distance", (float*)&SettingMenu2::PlayerDistanceColorstyle1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//							ImGui::EndChild();
				//						}
				//					}

				//					ImGui::EndChild();
				//				}
				//				ImGui::EndTabItem();

				//				ImGui::SetCursorPos({ 355.0f,103.0f });
				//				ImGui::BeginChild("###|", ImVec2(1, 295), true, 0);
				//				{

				//					ImGui::EndChild();
				//				}
				//			}

				//			if (ImGui::BeginTabItem("Bot ESP"))
				//			{
				//				if (ImGui::BeginChild("####BOT", ImVec2(415, 295), false))
				//				{
				//					ImGui::Spacing();
				//					ImGui::Checkbox(" Bot Name", &SettingMenu2::botname);
				//					if (SettingMenu2::botname)
				//					{
				//						ImGui::SameLine();
				//						ImGui::SetCursorPosX({ 170 });
				//						ImGui::BeginChild("###|botname", ImVec2(250, 28), false, 0);
				//						{
				//							ImGui::SetCursorPos({ 0.0f, 3.0f });
				//							ImGui::Text(" Size");
				//							ImGui::SameLine();
				//							ImGui::SetCursorPos({ 35.0f, 0.0f });
				//							ImGui::SliderFloat("###BotNamesize", &SettingMenu2::BotNamesizestyle1, 0.100f, 20.00f);
				//							ImGui::SameLine();
				//							ImGui::ColorEdit4("B Name", (float*)&SettingMenu2::BotNameColorstyle1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//							ImGui::EndChild();
				//						}
				//					}

				//					ImGui::Checkbox(" Bot Line", &SettingMenu2::botline);
				//					if (SettingMenu2::botline)
				//					{
				//						ImGui::SameLine();
				//						ImGui::SetCursorPosX({ 170 });
				//						ImGui::BeginChild("###|botline", ImVec2(250, 28), false, 0);
				//						{
				//							ImGui::SetCursorPos({ 0.0f, 3.0f });
				//							ImGui::Text(" Size");
				//							ImGui::SameLine();
				//							ImGui::SetCursorPos({ 35.0f, 0.0f });
				//							ImGui::SliderFloat("##BotLineSize", &SettingMenu2::botlinesize, 0.100f, 3.00f);
				//							ImGui::SameLine();
				//							ImGui::ColorEdit4("B Line", (float*)&SettingMenu2::botlineColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//							ImGui::EndChild();
				//						}
				//					}

				//					ImGui::Checkbox(" Bot Bone", &SettingMenu2::botBone);
				//					if (SettingMenu2::botBone)
				//					{
				//						ImGui::SameLine();
				//						ImGui::SetCursorPosX({ 170 });
				//						ImGui::BeginChild("###|botBone", ImVec2(250, 28), false, 0);
				//						{
				//							ImGui::SetCursorPos({ 0.0f, 3.0f });
				//							ImGui::Text(" Size");
				//							ImGui::SameLine();
				//							ImGui::SetCursorPos({ 35.0f, 0.0f });
				//							ImGui::SliderFloat("###BotBonesize", &SettingMenu2::botbonesize, 0.100f, 3.00f);
				//							ImGui::SameLine();
				//							ImGui::ColorEdit4("B Bone", (float*)&SettingMenu2::botboneColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//							ImGui::EndChild();
				//						}
				//					}

				//					ImGui::Checkbox(" Bot Corner Box", &SettingMenu2::botcornerbox);
				//					if (SettingMenu2::botcornerbox)
				//					{
				//						ImGui::SameLine();
				//						ImGui::SetCursorPosX({ 170 });
				//						ImGui::BeginChild("###|botcornerbox", ImVec2(250, 28), false, 0);
				//						{
				//							ImGui::SetCursorPos({ 0.0f, 3.0f });
				//							ImGui::Text(" Size");
				//							ImGui::SameLine();
				//							ImGui::SetCursorPos({ 35.0f, 0.0f });
				//							ImGui::SliderFloat("###BotCornerBoxsize", &SettingMenu2::botcornerboxsize, 0.100f, 3.00f);
				//							ImGui::SameLine();
				//							ImGui::ColorEdit4("B Corner Box", (float*)&SettingMenu2::botcornerboxColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//							ImGui::EndChild();
				//						}
				//					}

				//					ImGui::Checkbox(" Bot Full Box", &SettingMenu2::botfullbox);
				//					if (SettingMenu2::botfullbox)
				//					{
				//						ImGui::SameLine();
				//						ImGui::SetCursorPosX({ 170 });
				//						ImGui::BeginChild("###|botfullbox", ImVec2(250, 28), false, 0);
				//						{
				//							ImGui::SetCursorPos({ 0.0f, 3.0f });
				//							ImGui::Text(" Size");
				//							ImGui::SameLine();
				//							ImGui::SetCursorPos({ 35.0f, 0.0f });
				//							ImGui::SliderFloat("###BotFullBoxsize", &SettingMenu2::botfullboxsize, 0.100f, 3.00f);
				//							ImGui::SameLine();
				//							ImGui::ColorEdit4("B Full Box", (float*)&SettingMenu2::botfullboxColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//							ImGui::EndChild();
				//						}
				//					}

				//					ImGui::Checkbox(" Bot Health", &SettingMenu2::bothealth);
				//					if (SettingMenu2::bothealth)
				//					{
				//						ImGui::SameLine();
				//						ImGui::SetCursorPosX({ 170 });
				//						ImGui::BeginChild("###|bothealth", ImVec2(250, 28), false, 0);
				//						{
				//							if (ImGui::RadioButton("Show Bar", &SettingMenu2::RadioButton_BotHP, 0))
				//							{
				//								SettingMenu2::RadioButton_BotHP = 0;
				//							}
				//							ImGui::SameLine();
				//							if (ImGui::RadioButton("Show Text", &SettingMenu2::RadioButton_BotHP, 1))
				//							{
				//								SettingMenu2::RadioButton_BotHP = 1;
				//							}
				//							ImGui::SameLine();
				//							ImGui::SetCursorPosX({ 205 });
				//							ImGui::ColorEdit4("B Health", (float*)&SettingMenu2::bothealthColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//							ImGui::EndChild();
				//						}
				//					}

				//					ImGui::Checkbox(" Bot Weapon", &SettingMenu2::botweapon);
				//					if (SettingMenu2::botweapon)
				//					{
				//						ImGui::SameLine();
				//						ImGui::SetCursorPosX({ 170 });
				//						ImGui::BeginChild("###|botweapon", ImVec2(250, 28), false, 0);
				//						{
				//							ImGui::SetCursorPos({ 0.0f, 3.0f });
				//							ImGui::Text(" Size");
				//							ImGui::SameLine();
				//							ImGui::SetCursorPos({ 35.0f, 0.0f });
				//							ImGui::SliderFloat("###BotWeaponsize", &SettingMenu2::botweaponsizestyle1, 0.100f, 20.00f);
				//							ImGui::SameLine();
				//							ImGui::ColorEdit4("B Weapon", (float*)&SettingMenu2::botweaponColorstyle1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//							ImGui::EndChild();
				//						}
				//					}

				//					ImGui::Checkbox(" Bot Distance", &SettingMenu2::botdistance);
				//					if (SettingMenu2::botdistance)
				//					{
				//						ImGui::SameLine();
				//						ImGui::SetCursorPosX({ 170 });
				//						ImGui::BeginChild("###|botdistance", ImVec2(250, 28), false, 0);
				//						{
				//							ImGui::SetCursorPos({ 0.0f, 3.0f });
				//							ImGui::Text(" Size");
				//							ImGui::SameLine();
				//							ImGui::SetCursorPos({ 35.0f, 0.0f });
				//							ImGui::SliderFloat("###BotDistancesize", &SettingMenu2::botDistancesizestyle1, 0.100f, 20.00f);
				//							ImGui::SameLine();
				//							ImGui::ColorEdit4("B Distance", (float*)&SettingMenu2::BotDistanceColorstyle1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//							ImGui::EndChild();
				//						}
				//					}

				//					ImGui::EndChild();
				//				}
				//				ImGui::EndTabItem();

				//				ImGui::SetCursorPos({ 355.0f,103.0f });
				//				ImGui::BeginChild("###|", ImVec2(1, 295), true, 0);
				//				{

				//					ImGui::EndChild();
				//				}
				//			}

				//			if (ImGui::BeginTabItem("Others ESP"))
				//			{
				//				if (ImGui::BeginChild("####Others1Esp", ImVec2(200, 295), false))
				//				{
				//					ImGui::Spacing();
				//					ImGui::Checkbox(" Country Name  ", &SettingMenu2::PlayerFlagText);
				//					ImGui::Checkbox(" Country Image", &SettingMenu2::PlayerFlagImage);
				//					//ImGui::Checkbox(" Country Flag", &SettingMenu2::PlayerFlags);
				//					ImGui::Checkbox(" Team ID ", &SettingMenu2::playerTeamId);
				//					ImGui::Checkbox(" Aiming Alert", &SettingMenu2::PlayerAiming);
				//					ImGui::Checkbox(" Player And Bot Status", &SettingMenu2::PlayerStatus);
				//					ImGui::Checkbox(" Player UID", &SettingMenu2::PlayerUID);
				//					ImGui::Checkbox(" Bot Name Like,a Player", &SettingMenu2::botnameShow);
				//					ImGui::Checkbox(" I Look Like,a Enemy", &SettingMenu2::MeEnemyShow);

				//					ImGui::EndChild();
				//				}
				//				ImGui::EndTabItem();

				//				ImGui::SetCursorPos({ 385.0f,103.0f });
				//				ImGui::BeginChild("###|", ImVec2(1, 295), true, 0);
				//				{

				//					ImGui::EndChild();
				//				}

				//				ImGui::SetCursorPos({ 390.f,103.0f });
				//				ImGui::BeginChild("###Others2Esp", ImVec2(200, 295), false, 0);
				//				{
				//					ImGui::Spacing();
				//					ImGui::Checkbox(" Game Info", &SettingMenu2::Gameinfo);
				//					ImGui::Checkbox(" My Info", &SettingMenu2::MyInfo);
				//					ImGui::Checkbox(" Training Model Esp", &SettingMenu2::TrainingGrounds_ModelEsp);
				//					ImGui::Checkbox(" 360' Radar Alert", &SettingMenu2::dots1);
				//					ImGui::Checkbox(" Map Radar", &SettingMenu2::radar);
				//					if (SettingMenu2::radar)
				//					{
				//						ImGui::Bullet(); ImGui::TextColored(ImVec4(255, 0, 0, 255), "Radar Settings");
				//						ImGui::Indent();
				//						ImGui::SliderInt("Length", &SettingMenu2::RadarLength, 100.0f, 300.0f);
				//						ImGui::SliderInt("Width", &SettingMenu2::RadarWidth, 100.0f, 300.0f);
				//						ImGui::Unindent();
				//					}

				//					ImGui::EndChild();
				//				}
				//			}
				//		}
				//		ImGui::EndTabBar();

				//		ImGui::EndTabItem();
				//	}

				//	if (ImGui::BeginTabItem("Important Item"))
				//	{
				//		if (ImGui::BeginTabBar("BeginTabBar"))
				//		{
				//			if (ImGui::BeginTabItem("Wea."))
				//				//if (ImGui::BeginTabItem("Weapon"))
				//			{
				//				if (ImGui::BeginChild("###items#Weapon", ImVec2(400, 295), false))
				//				{


				//					ImGui::Spacing();
				//					ImGui::Bullet(); ImGui::Text("(AR) Weapons List");
				//					ImGui::Bullet(); ImGui::Text("Size");
				//					ImGui::SameLine();
				//					ImGui::SliderFloat0("                                     (AR) Weapons Size", &SettingMenu2::AR_Weaponsize, 0, 25);
				//					ImGui::Spacing();

				//					ImGui::Checkbox("M416", &SettingMenu2::Esp_Item_M416);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("M416", (float*)&SettingMenu2::Esp_Item_M416C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("SCAR-L", &SettingMenu2::Esp_Item_SCARL);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("SCAR-L", (float*)&SettingMenu2::Esp_Item_SCARLC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("M16A4", &SettingMenu2::Esp_Item_M16A4);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("M16A4", (float*)&SettingMenu2::Esp_Item_M16A4C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("FAMAS", &SettingMenu2::Esp_Item_FAMAS);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("FAMAS", (float*)&SettingMenu2::Esp_Item_FAMASC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("G36C", &SettingMenu2::Esp_Item_G36C);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("G36C", (float*)&SettingMenu2::Esp_Item_G36CC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("QBZ", &SettingMenu2::Esp_Item_QBZ);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("QBZ", (float*)&SettingMenu2::Esp_Item_QBZC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("QBU", &SettingMenu2::Esp_Item_QBU);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("QBU", (float*)&SettingMenu2::Esp_Item_QBUC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("M249", &SettingMenu2::Esp_Item_M249);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("M249", (float*)&SettingMenu2::Esp_Item_M249C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("MG3", &SettingMenu2::Esp_Item_MG3);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("MG3", (float*)&SettingMenu2::Esp_Item_M249C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);


				//					ImGui::Checkbox("AKM", &SettingMenu2::Esp_Item_AKM);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("AKM", (float*)&SettingMenu2::Esp_Item_AKMC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("M762", &SettingMenu2::Esp_Item_M762);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("M762", (float*)&SettingMenu2::Esp_Item_M762C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("DP28", &SettingMenu2::Esp_Item_DP28);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("DP28", (float*)&SettingMenu2::Esp_Item_DP28C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Mk47 Mutant", &SettingMenu2::Esp_Item_Mk47Mutant);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Mk47-Mutant", (float*)&SettingMenu2::Esp_Item_Mk47MutantC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("MK12", &SettingMenu2::Esp_Item_Mk12);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("MK12", (float*)&SettingMenu2::Esp_Item_Mk12C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Honey Badger", &SettingMenu2::Esp_Item_HoneyBadger);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Honey-Badger", (float*)&SettingMenu2::Esp_Item_HoneyBadgerC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Golden Boot", &SettingMenu2::Esp_Golden_boot);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Golden-Boot", (float*)&SettingMenu2::Esp_Golden_bootC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);



				//					ImGui::Spacing();
				//					ImGui::Spacing();
				//					ImGui::Bullet(); ImGui::Text("(Sniper) Weapons List");
				//					ImGui::Bullet(); ImGui::Text("Size");
				//					ImGui::SameLine();
				//					ImGui::SliderFloat0("                                     (Sniper) Weapons Size", &SettingMenu2::Sniper_Weaponsize, 0, 25);
				//					ImGui::Spacing();

				//					ImGui::Checkbox("AWM", &SettingMenu2::Esp_Item_Awm);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("AMW", (float*)&SettingMenu2::Esp_Item_AwmC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("M24", &SettingMenu2::Esp_Item_M24);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("M24", (float*)&SettingMenu2::Esp_Item_M24C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Kar98k", &SettingMenu2::Esp_Item_Kar98k);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Kar98k", (float*)&SettingMenu2::Esp_Item_Kar98kC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("SLR", &SettingMenu2::Esp_Item_SLR);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("SLR", (float*)&SettingMenu2::Esp_Item_SLRC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("SKS", &SettingMenu2::Esp_Item_SKS);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("SKS", (float*)&SettingMenu2::Esp_Item_SKSC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Mini-14", &SettingMenu2::Esp_Item_Mini14);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Mini-14", (float*)&SettingMenu2::Esp_Item_Mini14C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("VSS", &SettingMenu2::Esp_Item_VSS);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Mini-14", (float*)&SettingMenu2::Esp_Item_VSSC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Win-94", &SettingMenu2::Esp_Item_Win94);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Win-94", (float*)&SettingMenu2::Esp_Item_Win94C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Mosin", &SettingMenu2::Esp_Item_Mosin);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Mosin", (float*)&SettingMenu2::Esp_Item_MosinC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Mk-14", &SettingMenu2::Esp_Item_Mk14);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Mk-14", (float*)&SettingMenu2::Esp_Item_Mk14C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("MK12 Sniper", &SettingMenu2::MK12Sniper);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("MK12-Sniper", (float*)&SettingMenu2::MK12SniperC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("AMR Sniper", &SettingMenu2::AMRSniper);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("AMR-Sniper", (float*)&SettingMenu2::AMRSniperC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);



				//					ImGui::Spacing();
				//					ImGui::Spacing();
				//					ImGui::Bullet(); ImGui::Text("(SMG) Weapons List");
				//					ImGui::Bullet(); ImGui::Text("Size");
				//					ImGui::SameLine();
				//					ImGui::SliderFloat0("                                     (SMG) Weapons Size", &SettingMenu2::SMG_Weaponsize, 0, 25);
				//					ImGui::Spacing();

				//					ImGui::Checkbox("PP19", &SettingMenu2::Esp_Item_PP19);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("PP19", (float*)&SettingMenu2::Esp_Item_PP19C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Tommy Gun", &SettingMenu2::Esp_Item_TommyGun);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Tommy", (float*)&SettingMenu2::Esp_Item_TommyGunC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("MP5K", &SettingMenu2::Esp_Item_MP5K);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("MP5K", (float*)&SettingMenu2::Esp_Item_MP5KC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("UMP9", &SettingMenu2::Esp_Item_UMP9);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("UMP9", (float*)&SettingMenu2::Esp_Item_UMP9C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Vector", &SettingMenu2::Esp_Item_Vector);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Vector", (float*)&SettingMenu2::Esp_Item_VectorC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Uzi", &SettingMenu2::Esp_Item_Uzi);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Uzi", (float*)&SettingMenu2::Esp_Item_UziC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);




				//					ImGui::Spacing();
				//					ImGui::Spacing();
				//					ImGui::Bullet(); ImGui::Text("(ShotGun) Weapons List");
				//					ImGui::Bullet(); ImGui::Text("Size");
				//					ImGui::SameLine();
				//					ImGui::SliderFloat0("                                     (ShotGun) Weapons Size", &SettingMenu2::ShotGun_Weaponsize, 0, 25);
				//					ImGui::Spacing();

				//					ImGui::Checkbox("ShotGun S686", &SettingMenu2::ShotGun_S686);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("ShotGun_S686", (float*)&SettingMenu2::ShotGun_S686C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("DBS", &SettingMenu2::Esp_Item_DBS);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("DBS", (float*)&SettingMenu2::Esp_Item_DBSC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("S12K", &SettingMenu2::Esp_Item_S12K);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("S12K", (float*)&SettingMenu2::Esp_Item_S12KC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("S1897", &SettingMenu2::Esp_Item_S1897);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("S1897", (float*)&SettingMenu2::Esp_Item_S1897C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Sawed Off", &SettingMenu2::Esp_Item_SawedOff);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Sawed_Off", (float*)&SettingMenu2::Esp_Item_SawedOffC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("M1014", &SettingMenu2::Esp_Item_M1014);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("M1014", (float*)&SettingMenu2::Esp_Item_M1014C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);



				//					ImGui::Spacing();
				//					ImGui::Spacing();
				//					ImGui::Bullet(); ImGui::Text("(Pistol) Weapons List");
				//					ImGui::Bullet(); ImGui::Text("Size");
				//					ImGui::SameLine();
				//					ImGui::SliderFloat0("                                     (Pistol) Weapons Size", &SettingMenu2::Pistol_Weaponsize, 0, 25);
				//					ImGui::Spacing();

				//					ImGui::Checkbox("Flare Gun", &SettingMenu2::Esp_Item_FlareGun);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Flare", (float*)&SettingMenu2::Esp_Item_FlareGunC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Desert Eagle", &SettingMenu2::Esp_Item_DesertEagle);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Desert_Eagle", (float*)&SettingMenu2::Esp_Item_DesertEagleC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("R1895", &SettingMenu2::Esp_Item_R1895);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("R1895", (float*)&SettingMenu2::Esp_Item_R1895C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Vz61", &SettingMenu2::Esp_Item_Vz61);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Vz61", (float*)&SettingMenu2::Esp_Item_Vz61C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("P92", &SettingMenu2::Esp_Item_P92);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("P92", (float*)&SettingMenu2::Esp_Item_P92C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("P18C", &SettingMenu2::Esp_Item_P18C);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("P18C", (float*)&SettingMenu2::Esp_Item_P18CC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("R45", &SettingMenu2::Esp_Item_R45);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("R45", (float*)&SettingMenu2::Esp_Item_R45C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("P1911", &SettingMenu2::Esp_Item_P1911);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("P1911", (float*)&SettingMenu2::Esp_Item_P1911C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);



				//					ImGui::Spacing();
				//					ImGui::Spacing();
				//					ImGui::Bullet(); ImGui::Text("(Other) Weapons List");
				//					ImGui::Bullet(); ImGui::Text("Size");
				//					ImGui::SameLine();
				//					ImGui::SliderFloat0("                                     (Other) Weapons Size", &SettingMenu2::Other_Weaponsize, 0, 25);
				//					ImGui::Spacing();

				//					ImGui::Checkbox("Explosive Bow", &SettingMenu2::Esp_Item_ExplosiveBow);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Explosive-Bow", (float*)&SettingMenu2::Esp_Item_ExplosiveBowC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Pan", &SettingMenu2::Pan);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Pan", (float*)&SettingMenu2::PanC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Crowbar", &SettingMenu2::Crowbar);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Crowbar", (float*)&SettingMenu2::CrowbarC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Machete", &SettingMenu2::Machete);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Machete", (float*)&SettingMenu2::MacheteC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::EndChild();
				//				}
				//				ImGui::EndTabItem();
				//			}

				//			if (ImGui::BeginTabItem("Amm."))
				//				//if (ImGui::BeginTabItem("Ammo"))
				//			{
				//				if (ImGui::BeginChild("###items#Ammo", ImVec2(400, 295), false))
				//				{

				//					ImGui::Spacing();
				//					ImGui::Bullet(); ImGui::Text("Ammo List");
				//					ImGui::Bullet(); ImGui::Text("Size");
				//					ImGui::SameLine();
				//					ImGui::SliderFloat0("                                     Ammo Size", &SettingMenu2::Ammosize, 0, 25);
				//					ImGui::Spacing();

				//					ImGui::Checkbox("7.62mm", &SettingMenu2::Esp_Item_762mm);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("762mm", (float*)&SettingMenu2::Esp_Item_762mmC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("5.56mm", &SettingMenu2::Esp_Item_556mm);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("556mm", (float*)&SettingMenu2::Esp_Item_556mmC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("300_Magnum", &SettingMenu2::Esp_Item_Awmimo);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("300_Magnum", (float*)&SettingMenu2::Esp_Item_AwmimoC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Ammo_50BMG", &SettingMenu2::Ammo_50BMG);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Ammo_50BMG", (float*)&SettingMenu2::Ammo_50BMGC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("9mm", &SettingMenu2::Esp_Item_9mm);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("9mm", (float*)&SettingMenu2::Esp_Item_9mmC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("45.ACP", &SettingMenu2::Esp_Item_45ACP);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("45.ACP", (float*)&SettingMenu2::Esp_Item_45ACPC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Flare Ammo", &SettingMenu2::Esp_Item_Flare);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Flare-Ammo", (float*)&SettingMenu2::Esp_Item_FlareC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Ammo_12Guage", &SettingMenu2::Ammo_12Guage);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Ammo_12Guage", (float*)&SettingMenu2::Ammo_12GuageC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::EndChild();
				//				}
				//				ImGui::EndTabItem();
				//			}

				//			if (ImGui::BeginTabItem("Hea."))
				//				//if (ImGui::BeginTabItem("Health"))
				//			{
				//				if (ImGui::BeginChild("###items#Health", ImVec2(400, 295), false))
				//				{


				//					ImGui::Spacing();
				//					ImGui::Bullet(); ImGui::Text("Health List");
				//					ImGui::Bullet(); ImGui::Text("Size");
				//					ImGui::SameLine();
				//					ImGui::SliderFloat0("                                     Health Size", &SettingMenu2::HealthSize, 0, 25);
				//					ImGui::Spacing();

				//					ImGui::Checkbox("Bandages", &SettingMenu2::Esp_Item_Bandages);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Bandages", (float*)&SettingMenu2::Esp_Item_BandagesC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Energy Drink", &SettingMenu2::Esp_Item_EnergyDrink);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Energy Drink", (float*)&SettingMenu2::Esp_Item_EnergyDrinkC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Painkiller", &SettingMenu2::Esp_Item_Painkiller);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Painkiller", (float*)&SettingMenu2::Esp_Item_PainkillerC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Adrenaline Syringe", &SettingMenu2::Esp_Item_AdrenalineSyringe);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Adrenaline Syringe", (float*)&SettingMenu2::Esp_Item_AdrenalineSyringeC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("First Aid Kit", &SettingMenu2::Esp_Item_FirstAidKit);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("First Aid Kit", (float*)&SettingMenu2::Esp_Item_FirstAidKitC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Med Kit", &SettingMenu2::Esp_Item_MedKit);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Med Kit", (float*)&SettingMenu2::Esp_Item_MedKitC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Boster Tree", &SettingMenu2::BosterTree);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Boster-Tree", (float*)&SettingMenu2::BosterTreeC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Kung Fu Steamed Bun", &SettingMenu2::KungFuSteamedBun);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("KungFuSteamed-Bun", (float*)&SettingMenu2::KungFuSteamedBunC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);


				//					ImGui::EndChild();
				//				}
				//				ImGui::EndTabItem();
				//			}

				//			if (ImGui::BeginTabItem("Bag"))
				//			{
				//				if (ImGui::BeginChild("###items#Bag", ImVec2(400, 295), false))
				//				{


				//					ImGui::Spacing();
				//					ImGui::Bullet(); ImGui::Text("Bag List");
				//					ImGui::Bullet(); ImGui::Text("Size");
				//					ImGui::SameLine();
				//					ImGui::SliderFloat0("                                     Bag Size", &SettingMenu2::BagSize, 0, 25);
				//					ImGui::Spacing();

				//					ImGui::Checkbox("Bag Lv1", &SettingMenu2::Esp_Item_Bag1);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Bag 1", (float*)&SettingMenu2::Esp_Item_Bag1C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Bag Lv2", &SettingMenu2::Esp_Item_Bag2);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Bag 2", (float*)&SettingMenu2::Esp_Item_Bag2C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Bag Lv3", &SettingMenu2::Esp_Item_Bag3);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Bag 3", (float*)&SettingMenu2::Esp_Item_Bag3C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::EndChild();
				//				}
				//				ImGui::EndTabItem();
				//			}

				//			if (ImGui::BeginTabItem("Hel."))
				//				//if (ImGui::BeginTabItem("Helmet"))
				//			{
				//				if (ImGui::BeginChild("###items#Helmet", ImVec2(400, 295), false))
				//				{


				//					ImGui::Spacing();
				//					ImGui::Bullet(); ImGui::Text("Helmet List");
				//					ImGui::Bullet(); ImGui::Text("Size");
				//					ImGui::SameLine();
				//					ImGui::SliderFloat0("                                     Helmet Size", &SettingMenu2::HelmetSize, 0, 25);
				//					ImGui::Spacing();

				//					ImGui::Checkbox("Helmet Lv1", &SettingMenu2::Esp_Item_Helmet1);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Helmet 1", (float*)&SettingMenu2::Esp_Item_Helmet1C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Helmet Lv2", &SettingMenu2::Esp_Item_Helmet2);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Helmet 2", (float*)&SettingMenu2::Esp_Item_Helmet2C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Helmet Lv3", &SettingMenu2::Esp_Item_Helmet3);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Helmet 3", (float*)&SettingMenu2::Esp_Item_Helmet3C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::EndChild();
				//				}
				//				ImGui::EndTabItem();
				//			}

				//			if (ImGui::BeginTabItem("Arm."))
				//				//if (ImGui::BeginTabItem("Armor"))
				//			{
				//				if (ImGui::BeginChild("###items#Armor", ImVec2(400, 295), false))
				//				{

				//					ImGui::Spacing();
				//					ImGui::Bullet(); ImGui::Text("Armor List");
				//					ImGui::Bullet(); ImGui::Text("Size");
				//					ImGui::SameLine();
				//					ImGui::SliderFloat0("                                     Armor Size", &SettingMenu2::ArmorSize, 0, 25);
				//					ImGui::Spacing();

				//					ImGui::Checkbox("Armor Lv1", &SettingMenu2::Esp_Item_Armor1);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Armor 1", (float*)&SettingMenu2::Esp_Item_Armor1C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Armor Lv2", &SettingMenu2::Esp_Item_Armor2);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Armor 2", (float*)&SettingMenu2::Esp_Item_Armor2C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Armor Lv3", &SettingMenu2::Esp_Item_Armor3);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Armor 3", (float*)&SettingMenu2::Esp_Item_Armor3C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::EndChild();
				//				}
				//				ImGui::EndTabItem();
				//			}

				//			if (ImGui::BeginTabItem("Sco."))
				//				//if (ImGui::BeginTabItem("Scope"))
				//			{
				//				if (ImGui::BeginChild("###items#Scope", ImVec2(400, 295), false))
				//				{

				//					ImGui::Spacing();
				//					ImGui::Bullet(); ImGui::Text("Scope List");
				//					ImGui::Bullet(); ImGui::Text("Size");
				//					ImGui::SameLine();
				//					ImGui::SliderFloat0("                                     Scope Size", &SettingMenu2::ScopeSize, 0, 25);
				//					ImGui::Spacing();

				//					ImGui::Checkbox("Red Dot", &SettingMenu2::RedDot);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Red-Dot", (float*)&SettingMenu2::RedDotC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Holo", &SettingMenu2::Esp_Item_Holo);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Holo", (float*)&SettingMenu2::Esp_Item_HoloC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("x2", &SettingMenu2::Esp_Item_x2);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("2X", (float*)&SettingMenu2::Esp_Item_x2C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("x3", &SettingMenu2::Esp_Item_x3);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("3X", (float*)&SettingMenu2::Esp_Item_x3C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("x4", &SettingMenu2::Esp_Item_x4);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("4X", (float*)&SettingMenu2::Esp_Item_x4C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("x6", &SettingMenu2::Esp_Item_x6);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("6X", (float*)&SettingMenu2::Esp_Item_x6C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("x8", &SettingMenu2::Esp_Item_x8);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("8X", (float*)&SettingMenu2::Esp_Item_x8C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::EndChild();
				//				}
				//				ImGui::EndTabItem();
				//			}

				//			if (ImGui::BeginTabItem("Gre."))
				//				//if (ImGui::BeginTabItem("Grenade"))
				//			{
				//				if (ImGui::BeginChild("###items#Grenade", ImVec2(400, 295), false))
				//				{


				//					ImGui::Spacing();
				//					ImGui::Bullet(); ImGui::Text("Grenade List");
				//					ImGui::Bullet(); ImGui::Text("Size");
				//					ImGui::SameLine();
				//					ImGui::SliderFloat0("                                     Grenade Size", &SettingMenu2::GrenadeSize, 0, 25);
				//					ImGui::Spacing();


				//					ImGui::Checkbox("RedZone Bomb", &SettingMenu2::RedZoneBomb);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("RedZoneBomb", (float*)&SettingMenu2::RedZoneBombC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("Grenade", &SettingMenu2::Esp_Item_Frag);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Grenade", (float*)&SettingMenu2::Esp_Item_FragC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("Grenade Warning", &SettingMenu2::Grenade_Warning);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Grenade_Warning", (float*)&SettingMenu2::Grenade_WarningC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("Molotov Cocktail", &SettingMenu2::Esp_Item_Molotof);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Molotov-Cocktail", (float*)&SettingMenu2::Esp_Item_MolotofC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("Molotov Warning", &SettingMenu2::Molotov_Warning);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Molotov_Warning", (float*)&SettingMenu2::Molotov_WarningC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("Stun Grenade", &SettingMenu2::StunGrenade);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Stun-Grenade", (float*)&SettingMenu2::StunGrenadeC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("Stun Grenade Warning", &SettingMenu2::StunGrenade_Warning);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Stun-Grenade_Warning", (float*)&SettingMenu2::StunGrenade_WarningC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("Smoke", &SettingMenu2::Esp_Item_Smoke);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Smoke", (float*)&SettingMenu2::Esp_Item_SmokeC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("Smoke Warning", &SettingMenu2::Smoke_Warning);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Smoke_Warning", (float*)&SettingMenu2::Smoke_WarningC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);


				//					ImGui::EndChild();
				//				}
				//				ImGui::EndTabItem();
				//			}

				//			/*if (ImGui::BeginTabItem("Weapon 2"))
				//			{
				//				if (ImGui::BeginChild("###items#Weapon", ImVec2(400, 322), false))
				//				{

				//					ImGui::EndChild();
				//				}
				//				ImGui::EndTabItem();
				//			}*/
				//		}
				//		ImGui::EndTabBar();

				//		ImGui::EndTabItem();
				//	}

				//	if (ImGui::BeginTabItem("Others Item"))
				//	{
				//		if (ImGui::BeginTabBar("BeginTabBar"))
				//		{
				//			if (ImGui::BeginTabItem("Vehicle"))
				//				//if (ImGui::BeginTabItem("Grenade"))
				//			{
				//				if (ImGui::BeginChild("###items#Vehicle", ImVec2(400, 295), false))
				//				{


				//					ImGui::Spacing();
				//					ImGui::Bullet(); ImGui::Text("Vehicle List");
				//					ImGui::Bullet(); ImGui::Text("Size");
				//					ImGui::SameLine();
				//					ImGui::SliderFloat0("                                     Vehicle Size", &SettingMenu2::VehicleSize, 0.100, 25);
				//					ImGui::Spacing();

				//					ImGui::Checkbox(" Show All Vehicle", &SettingMenu2::Vehicle);
				//					//ImGui::Spacing();
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("VehicleC", (float*)&SettingMenu2::VehicleColor, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					/*ImGui::Checkbox("Lion Dance Car", &SettingMenu2::LionDanceCar);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("LionDanceCar", (float*)&SettingMenu2::LionDanceCarC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("BRDM", &SettingMenu2::BRDM);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("BRDM", (float*)&SettingMenu2::BRDMC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("Scooter", &SettingMenu2::Scooter);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Scooter", (float*)&SettingMenu2::ScooterC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("Motorcycle", &SettingMenu2::Motorcycle);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Motorcycle", (float*)&SettingMenu2::MotorcycleC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("Snowmobile", &SettingMenu2::Snowmobile);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Snowmobile", (float*)&SettingMenu2::SnowmobileC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("Tuk", &SettingMenu2::Tuk);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Tuk", (float*)&SettingMenu2::TukC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("Buggy", &SettingMenu2::Buggy);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Buggy", (float*)&SettingMenu2::BuggyC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("Sportsa", &SettingMenu2::Sportsa);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Sportsa", (float*)&SettingMenu2::SportsaC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("Sports", &SettingMenu2::Sports);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Sports", (float*)&SettingMenu2::SportsC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("Dacia", &SettingMenu2::Dacia);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Dacia", (float*)&SettingMenu2::DaciaC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("Rony", &SettingMenu2::Rony);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Rony", (float*)&SettingMenu2::RonyC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("UAZ", &SettingMenu2::UAZ);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("UAZ", (float*)&SettingMenu2::UAZC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("Minibus", &SettingMenu2::Minibus);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Minibus", (float*)&SettingMenu2::MinibusC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("PG117", &SettingMenu2::PG117);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("PG117", (float*)&SettingMenu2::PG117C, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("Aquarail", &SettingMenu2::Aquarail);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Aquarail", (float*)&SettingMenu2::AquarailC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("ModelY Tesla", &SettingMenu2::ModelYTesla);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("ModelYTesla", (float*)&SettingMenu2::ModelYTeslaC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("Gravity Motorcycle", &SettingMenu2::GravityMotorcycle);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("GravityMotorcycle", (float*)&SettingMenu2::GravityMotorcycleC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("Glider", &SettingMenu2::Glider);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Glider", (float*)&SettingMenu2::GliderC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("UTV", &SettingMenu2::UTV);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("UTV", (float*)&SettingMenu2::UTVC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("Monstar Truck", &SettingMenu2::MonstarTruck);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("MonstarTruck", (float*)&SettingMenu2::MonstarTruckC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("Coupe_New Dacia", &SettingMenu2::Coupe_NewDacia);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Coupe_NewDacia", (float*)&SettingMenu2::Coupe_NewDaciaC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("Quad", &SettingMenu2::Quad);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Quad", (float*)&SettingMenu2::QuadC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("Snow Bike", &SettingMenu2::Snow_Bike);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Snow_Bike", (float*)&SettingMenu2::Snow_BikeC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

				//					ImGui::Checkbox("PickUp", &SettingMenu2::PickUp);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("PickUp", (float*)&SettingMenu2::PickUpC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);*/

				//					ImGui::EndChild();
				//				}
				//				ImGui::EndTabItem();
				//			}

				//			if (ImGui::BeginTabItem("Airplan"))
				//				//if (ImGui::BeginTabItem("Ammo"))
				//			{
				//				if (ImGui::BeginChild("###items#Airplan", ImVec2(400, 295), false))
				//				{
				//					ImGui::Spacing();
				//					ImGui::Bullet(); ImGui::Text("Airplan List");
				//					ImGui::Bullet(); ImGui::Text("Size");
				//					ImGui::SameLine();
				//					ImGui::SliderFloat0("                                     Airplan Size", &SettingMenu2::AirplanT, 0, 25);
				//					ImGui::Spacing();

				//					ImGui::Checkbox("AirDrop Plane", &SettingMenu2::Airplan);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("AirDropPlane", (float*)&SettingMenu2::AirplanC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::EndChild();
				//				}
				//				ImGui::EndTabItem();
				//			}

				//			if (ImGui::BeginTabItem("AirDrop"))
				//				//if (ImGui::BeginTabItem("Ammo"))
				//			{
				//				if (ImGui::BeginChild("###items#AirDropBoxItem", ImVec2(400, 295), false))
				//				{
				//					ImGui::Spacing();
				//					ImGui::Bullet(); ImGui::Text("AirDropBox Item List");
				//					/*ImGui::Bullet(); ImGui::Text("Size");
				//					ImGui::SameLine();
				//					ImGui::SliderFloat0("                                     AirDropBox Item Size", &SettingMenu2::AirDropBoxSize, 0, 25);*/
				//					ImGui::Spacing();

				//					ImGui::Checkbox(" AirDrop Box", &SettingMenu2::AirDropBox);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 355 });
				//					ImGui::ColorEdit4("AirDrop-Box", (float*)&SettingMenu2::AirDropBoxColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				//					//if (SettingMenu2::Esp_Item_LootBox)
				//					{
				//						if (ImGui::TreeNodeEx("  AirDrop-Box Size"))
				//						{
				//							ImGui::Indent();

				//							//ImGui::SameLine();
				//							ImGui::SliderFloat("                                          AirDrop-Box Size", &SettingMenu2::AirDropBoxSize, 0.100f, 20.00f);

				//							ImGui::Unindent();
				//							ImGui::TreePop();
				//						}
				//					}


				//					//ImGui::Checkbox(" AirDrop Box Items", &SettingMenu2::AirDropBoxitems1);
				//					//ImGui::SameLine();
				//					//ImGui::SetCursorPosX({ 355 });
				//					//ImGui::ColorEdit4("AirDrop-Box Items", (float*)&Colors::AirDropBoxitemColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				//					////if (SettingMenu2::playerdeadbox)
				//					//{
				//					//	if (ImGui::TreeNodeEx("  AirDrop Box Items Size"))
				//					//	{
				//					//		ImGui::Indent();

				//					//		//ImGui::SameLine();
				//					//		ImGui::SliderFloat("                                          AirDrop Box Items size", &SettingMenu2::AirDropBoxItemsSize, 0.100f, 20.00f);

				//					//		ImGui::Unindent();
				//					//		ImGui::TreePop();
				//					//	}
				//					//}

				//					//ImGui::Checkbox("AirDrop Box Items Line Color", &SettingMenu2::itemrect);
				//					//ImGui::SameLine();
				//					//ImGui::SetCursorPosX({ 355 });
				//					//ImGui::ColorEdit4("AirDrop-Box-Items Shadow", (float*)&Colors::bgcornerColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				//					////if (SettingMenu2::itemrect)
				//					//{
				//					//	if (ImGui::TreeNodeEx("  AirDrop Box Items Line Setting"))
				//					//	{
				//					//		ImGui::Indent();

				//					//		if (ImGui::RadioButton("Full-Line", &LootBoxItems_RadioButton, 2))
				//					//		{
				//					//			item_current_Emu = 0;
				//					//			SettingMenu2::redioption = 1;
				//					//		}
				//					//		ImGui::SameLine();
				//					//		if (ImGui::RadioButton("Corner-Line", &LootBoxItems_RadioButton, 1))
				//					//		{
				//					//			item_current_Emu = 1;
				//					//			SettingMenu2::redioption = 2;
				//					//			ImGui::SetItemDefaultFocus();
				//					//		}


				//					//		ImGui::Unindent();
				//					//		ImGui::TreePop();
				//					//	}
				//					//}

				//					ImGui::EndChild();
				//				}
				//				ImGui::EndTabItem();
				//			}

				//			if (ImGui::BeginTabItem("Loot-Box"))
				//				//if (ImGui::BeginTabItem("Ammo"))
				//			{
				//				if (ImGui::BeginChild("###items#Loot-BoxItem", ImVec2(400, 295), false))
				//				{
				//					ImGui::Spacing();
				//					ImGui::Bullet(); ImGui::Text("Loot-Box Item List");
				//					/*ImGui::Bullet(); ImGui::Text("Size");
				//					ImGui::SameLine();
				//					ImGui::SliderFloat0("                                     Loot-Box Item Size", &SettingMenu2::PlayerLootBoxSize, 0, 25);*/
				//					ImGui::Spacing();

				//					ImGui::Checkbox(" Loot-Box", &SettingMenu2::playerdeadbox);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 355 });
				//					ImGui::ColorEdit4("P Loot-Box", (float*)&SettingMenu2::PlayerDeadboxColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				//					//if (SettingMenu2::Esp_Item_LootBox)
				//					{
				//						if (ImGui::TreeNodeEx("  Loot-Box Size"))
				//						{
				//							ImGui::Indent();

				//							//ImGui::SameLine();
				//							ImGui::SliderFloat("                                          Loot-Box Size", &SettingMenu2::PlayerLootBoxSize, 0.100f, 20.00f);

				//							ImGui::Unindent();
				//							ImGui::TreePop();
				//						}
				//					}


				//					ImGui::Checkbox(" Loot-Box Items", &SettingMenu2::playerdeadboxitems);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 355 });
				//					ImGui::ColorEdit4("Loot-Box Items", (float*)&ColorsMenu2::deadboxitemColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				//					//if (SettingMenu2::playerdeadbox)
				//					{
				//						if (ImGui::TreeNodeEx("  Loot-Box Items Size"))
				//						{
				//							ImGui::Indent();

				//							//ImGui::SameLine();
				//							ImGui::SliderFloat("                                          Loot-Box Items size", &SettingMenu2::PlayerLootBoxItemsSize, 0.100f, 20.00f);

				//							ImGui::Unindent();
				//							ImGui::TreePop();
				//						}
				//					}


				//					ImGui::Checkbox("Loot-Box Items Line Color", &SettingMenu2::itemrect);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 355 });
				//					ImGui::ColorEdit4("Loot-Box-Items Shadow", (float*)&ColorsMenu2::bgcornerColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				//					//if (SettingMenu2::itemrect)
				//					{
				//						if (ImGui::TreeNodeEx("  Loot-Box Items Line Setting"))
				//						{
				//							ImGui::Indent();

				//							if (ImGui::RadioButton("Full-Line", &LootBoxItems_RadioButton, 2))
				//							{
				//								item_current_Emu = 0;
				//								SettingMenu2::redioption = 1;
				//							}
				//							ImGui::SameLine();
				//							if (ImGui::RadioButton("Corner-Line", &LootBoxItems_RadioButton, 1))
				//							{
				//								item_current_Emu = 1;
				//								SettingMenu2::redioption = 2;
				//								ImGui::SetItemDefaultFocus();
				//							}


				//							ImGui::Unindent();
				//							ImGui::TreePop();
				//						}
				//					}

				//					ImGui::EndChild();
				//				}
				//				ImGui::EndTabItem();
				//			}

				//			if (ImGui::BeginTabItem("More Item"))
				//				//if (ImGui::BeginTabItem("Ammo"))
				//			{
				//				if (ImGui::BeginChild("###items#MoreItem", ImVec2(400, 295), false))
				//				{
				//					ImGui::Spacing();
				//					ImGui::Bullet(); ImGui::Text("More Item List");
				//					ImGui::Bullet(); ImGui::Text("Size");
				//					ImGui::SameLine();
				//					ImGui::SliderFloat0("                                     More Item Size", &SettingMenu2::MoreItemSize, 0, 25);
				//					ImGui::Spacing();

				//					ImGui::Checkbox("Zone Radiation", &SettingMenu2::ZoneRadiation);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Zone_Radiation", (float*)&SettingMenu2::ZoneRadiationC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("WIN MVP Statue", &SettingMenu2::WINMVPStatue);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("WINMVP_Statue", (float*)&SettingMenu2::WINMVPStatueC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Place Selected", &SettingMenu2::PlaceSelected);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Place_elected", (float*)&SettingMenu2::PlaceSelectedC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("EmergencyCall Pickup", &SettingMenu2::EmergencyCallPickup);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("EmergencyCall_Pickup", (float*)&SettingMenu2::EmergencyCallPickupC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Lion Dance", &SettingMenu2::LionDance);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Lion_Dance", (float*)&SettingMenu2::LionDanceC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Grappling Hook", &SettingMenu2::GrapplingHook);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Grappling_Hook", (float*)&SettingMenu2::GrapplingHookC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Shop Token", &SettingMenu2::ShopToken);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Shop_Token", (float*)&SettingMenu2::ShopTokenC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Supply Shop", &SettingMenu2::SupplyShop);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Supply_Shop", (float*)&SettingMenu2::PlaceSelectedC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);


				//					ImGui::Spacing();
				//					ImGui::Bullet(); ImGui::Text("(AR) Necessary Equipment");
				//					ImGui::Spacing();
				//					ImGui::Checkbox("Flash Hider (AR)", &SettingMenu2::FlashHiderAR);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("FlashHider(AR)", (float*)&SettingMenu2::FlashHiderARC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Compensator (AR)", &SettingMenu2::CompensatorAR);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Compensator(AR)", (float*)&SettingMenu2::CompensatorARC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Suppressor (AR)", &SettingMenu2::SuppressorAR);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Suppressor(AR)", (float*)&SettingMenu2::SuppressorARC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Quickdraw Mag (AR)", &SettingMenu2::QuickdrawMagAR);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Quickdraw Mag (AR)", (float*)&SettingMenu2::QuickdrawMagARC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Extended Mag (AR)", &SettingMenu2::ExtendedMagAR);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("ExtendedMag(AR)", (float*)&SettingMenu2::ExtendedMagARC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Extended Quickdraw Mag (AR)", &SettingMenu2::ExtendedQuickdrawMagAR);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("ExtendedQuickdrawMag(AR)", (float*)&SettingMenu2::ExtendedQuickdrawMagARC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);


				//					ImGui::Spacing();
				//					ImGui::Bullet(); ImGui::Text("(Sniper) Necessary Equipment");
				//					ImGui::Spacing();
				//					ImGui::Checkbox("FlashHider (Sniper)", &SettingMenu2::FlashHiderSniper);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("FlashHider(Sniper)", (float*)&SettingMenu2::FlashHiderSniperC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Compensator (Sniper)", &SettingMenu2::CompensatorSniper);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Compensator(Sniper)", (float*)&SettingMenu2::CompensatorSniperC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Suppressor (Sniper)", &SettingMenu2::SuppressorSniper);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Suppressor(Sniper)", (float*)&SettingMenu2::SuppressorSniperC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Quickdraw Mag (Sniper)", &SettingMenu2::QuickdrawMagSniper);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("QuickdrawMag(Sniper)", (float*)&SettingMenu2::QuickdrawMagSniperC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Extended Mag (Sniper)", &SettingMenu2::ExtendedMagSniper);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("ExtendedMag(Sniper)", (float*)&SettingMenu2::ExtendedMagSniperC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Extended Quickdraw Mag (Sniper)", &SettingMenu2::ExtendedQuickdrawMagSniper);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("ExtendedQuickdrawMag(Sniper)", (float*)&SettingMenu2::ExtendedQuickdrawMagSniperC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);


				//					ImGui::Spacing();
				//					ImGui::Bullet(); ImGui::Text("(SMG) Necessary Equipment");
				//					ImGui::Spacing();
				//					ImGui::Checkbox("FlashHider (SMG)", &SettingMenu2::FlashHiderSMG);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("FlashHider(SMG)", (float*)&SettingMenu2::FlashHiderSMGC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Compensator (SMG)", &SettingMenu2::CompensatorSMG);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Compensator(SMG)", (float*)&SettingMenu2::CompensatorSMGC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Suppressor (SMG)", &SettingMenu2::SuppressorSMG);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Suppressor(SMG)", (float*)&SettingMenu2::SuppressorSMGC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Tactical Stock (SMG)", &SettingMenu2::TacticalStockSMG);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("TacticalStock(SMG)", (float*)&SettingMenu2::TacticalStockSMGC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Choke (SG)", &SettingMenu2::ChokeSG);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("Choke(SG)", (float*)&SettingMenu2::ChokeSGC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Thumb Grip", &SettingMenu2::ThumbGrip);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("ThumbGrip", (float*)&SettingMenu2::ThumbGripC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::Checkbox("Light Grip", &SettingMenu2::LightGrip);
				//					ImGui::SameLine();
				//					ImGui::SetCursorPosX({ 345 });
				//					ImGui::ColorEdit4("LightGrip", (float*)&SettingMenu2::LightGripC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				//					ImGui::EndChild();
				//				}
				//				ImGui::EndTabItem();
				//			}
				//		}
				//		ImGui::EndTabBar();

				//		ImGui::EndTabItem();
				//	}

				//	if (ImGui::BeginTabItem("More Option"))
				//	{
				//		if (ImGui::BeginChild("###others", ImVec2(400, 325), false))
				//		{
				//			ImGui::Spacing();

				//			ImGui::Checkbox(" Fight Mode", &SettingMenu2::fightmode);
				//			//if (SettingMenu2::fightmode)
				//			{
				//				if (ImGui::TreeNodeEx("  Fight Mode Setting"))
				//				{
				//					ImGui::Indent();

				//					/*ImGui::SameLine();
				//					ImGui::SliderFloat("                    Distance size", &SettingMenu2::Dissize, 0.100f, 20.00f);*/

				//					ImGui::Unindent();
				//					ImGui::TreePop();
				//				}
				//			}


				//			ImGui::Checkbox(" All Items", &SettingMenu2::Item);
				//			//if (SettingMenu2::Item)
				//			{
				//				if (ImGui::TreeNodeEx("  All Items Size"))
				//				{
				//					ImGui::Indent();

				//					//ImGui::SameLine();
				//					ImGui::SliderFloat("                                          All Items Size", &SettingMenu2::allitemssT, 0.100f, 20.00f);

				//					ImGui::Unindent();
				//					ImGui::TreePop();
				//				}
				//			}


				//			ImGui::Checkbox(" Total Players Number", &SettingMenu2::TotalEnemy);
				//			//if (SettingMenu2::TotalEnemy)
				//			{
				//				if (ImGui::TreeNodeEx("  Total Players Number Setting"))
				//				{
				//					ImGui::Indent();

				//					if (ImGui::RadioButton("Style 1", &TotalPlayers_RadioButton, 1))
				//					{
				//						SettingMenu2::TotalEnemyStyle1 = true;
				//						SettingMenu2::TotalEnemyStyle2 = false;
				//						SettingMenu2::TotalEnemyStyle2 = false;
				//					}
				//					ImGui::SameLine();
				//					if (ImGui::RadioButton("Style 2", &TotalPlayers_RadioButton, 2))
				//					{
				//						SettingMenu2::TotalEnemyStyle1 = false;
				//						SettingMenu2::TotalEnemyStyle2 = true;
				//						SettingMenu2::TotalEnemyStyle3 = false;
				//					}
				//					ImGui::SameLine();
				//					if (ImGui::RadioButton("Style 3", &TotalPlayers_RadioButton, 3))
				//					{
				//						SettingMenu2::TotalEnemyStyle1 = false;
				//						SettingMenu2::TotalEnemyStyle2 = false;
				//						SettingMenu2::TotalEnemyStyle3 = true;
				//					}

				//					ImGui::Unindent();
				//					ImGui::TreePop();
				//				}
				//			}


				//			ImGui::Checkbox(" Show Text Border", &SettingMenu2::borderlo);
				//			//if (SettingMenu2::borderlo)
				//			{
				//				if (ImGui::TreeNodeEx(" Text Border Setting"))
				//				{
				//					ImGui::Indent();

				//					////ImGui::SameLine();
				//					//ImGui::SliderFloat("                                          Bot Name size", &SettingMenu2::BotNamesize, 0.100f, 20.00f);

				//					ImGui::Unindent();
				//					ImGui::TreePop();
				//				}
				//			}


				//			ImGui::Checkbox(" Show Watermark", &SettingMenu2::watermark);
				//			ImGui::SameLine();
				//			ImGui::SetCursorPosX({ 355 });
				//			ImGui::ColorEdit4("Watermark Text Color", (float*)&SettingMenu2::watermarkC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				//			//if (SettingMenu2::watermark)
				//			{
				//				if (ImGui::TreeNodeEx(" Watermark Setting"))
				//				{
				//					ImGui::Indent();

				//					////ImGui::SameLine();
				//					ImGui::SliderFloat("                                          Watermark Size", &SettingMenu2::watermarkT, 0, 25);

				//					ImGui::Unindent();
				//					ImGui::TreePop();
				//				}
				//			}


				//			ImGui::Checkbox(" Show Expred Date", &SettingMenu2::Expred_Date);
				//			ImGui::SameLine();
				//			ImGui::SetCursorPosX({ 355 });
				//			ImGui::ColorEdit4("Expred Date Text Color", (float*)&SettingMenu2::Expred_DateC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				//			//if (SettingMenu2::Expred_Date)
				//			{
				//				if (ImGui::TreeNodeEx(" Expred Date Setting"))
				//				{
				//					ImGui::Indent();

				//					////ImGui::SameLine();
				//					ImGui::SliderFloat("                                          Expred Date Size", &SettingMenu2::Expred_DateT, 0, 25);

				//					ImGui::Unindent();
				//					ImGui::TreePop();
				//				}
				//			}


				//			ImGui::EndChild();
				//		}
				//		ImGui::EndTabItem();
				//	}

				//}
				//ImGui::EndTabBar();
			}

			if (Settings::Tab == 2)
			{
				if (ImGui::BeginTabBar("BeginTabBar"))
				{
					if (ImGui::BeginTabItem("Important Item"))
					{
						if (ImGui::BeginTabBar("BeginTabBar"))
						{
							if (ImGui::BeginTabItem("Wea."))
								//if (ImGui::BeginTabItem("Weapon"))
							{
								if (ImGui::BeginChild("###items#Weapon", ImVec2(592, 285), true))
								{

									ImGui::Spacing();
									ImGui::Bullet(); ImGui::Text("(AR) Weapons List");
									ImGui::Bullet(); ImGui::Text("Size");
									ImGui::SameLine();
									ImGui::SliderFloat0("                                     (AR) Weapons Size", &SettingMenu2::AR_Weaponsize, 0, 25);
									ImGui::Spacing();

									ImGui::Checkbox("M416", &SettingMenu2::Esp_Item_M416);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("M416", (float*)&SettingMenu2::Esp_Item_M416C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("SCAR-L", &SettingMenu2::Esp_Item_SCARL);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("SCAR-L", (float*)&SettingMenu2::Esp_Item_SCARLC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("M16A4", &SettingMenu2::Esp_Item_M16A4);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("M16A4", (float*)&SettingMenu2::Esp_Item_M16A4C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("FAMAS", &SettingMenu2::Esp_Item_FAMAS);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("FAMAS", (float*)&SettingMenu2::Esp_Item_FAMASC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("G36C", &SettingMenu2::Esp_Item_G36C);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("G36C", (float*)&SettingMenu2::Esp_Item_G36CC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("QBZ", &SettingMenu2::Esp_Item_QBZ);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("QBZ", (float*)&SettingMenu2::Esp_Item_QBZC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("QBU", &SettingMenu2::Esp_Item_QBU);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("QBU", (float*)&SettingMenu2::Esp_Item_QBUC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("M249", &SettingMenu2::Esp_Item_M249);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("M249", (float*)&SettingMenu2::Esp_Item_M249C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("MG3", &SettingMenu2::Esp_Item_MG3);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("MG3", (float*)&SettingMenu2::Esp_Item_M249C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);


									ImGui::Checkbox("AKM", &SettingMenu2::Esp_Item_AKM);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("AKM", (float*)&SettingMenu2::Esp_Item_AKMC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("M762", &SettingMenu2::Esp_Item_M762);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("M762", (float*)&SettingMenu2::Esp_Item_M762C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("DP28", &SettingMenu2::Esp_Item_DP28);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("DP28", (float*)&SettingMenu2::Esp_Item_DP28C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Mk47 Mutant", &SettingMenu2::Esp_Item_Mk47Mutant);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Mk47-Mutant", (float*)&SettingMenu2::Esp_Item_Mk47MutantC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("MK12", &SettingMenu2::Esp_Item_Mk12);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("MK12", (float*)&SettingMenu2::Esp_Item_Mk12C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Honey Badger", &SettingMenu2::Esp_Item_HoneyBadger);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Honey-Badger", (float*)&SettingMenu2::Esp_Item_HoneyBadgerC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Golden Boot", &SettingMenu2::Esp_Golden_boot);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Golden-Boot", (float*)&SettingMenu2::Esp_Golden_bootC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);



									ImGui::Spacing();
									ImGui::Spacing();
									ImGui::Bullet(); ImGui::Text("(Sniper) Weapons List");
									ImGui::Bullet(); ImGui::Text("Size");
									ImGui::SameLine();
									ImGui::SliderFloat0("                                     (Sniper) Weapons Size", &SettingMenu2::Sniper_Weaponsize, 0, 25);
									ImGui::Spacing();

									ImGui::Checkbox("AWM", &SettingMenu2::Esp_Item_Awm);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("AMW", (float*)&SettingMenu2::Esp_Item_AwmC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("M24", &SettingMenu2::Esp_Item_M24);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("M24", (float*)&SettingMenu2::Esp_Item_M24C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Kar98k", &SettingMenu2::Esp_Item_Kar98k);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Kar98k", (float*)&SettingMenu2::Esp_Item_Kar98kC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("SLR", &SettingMenu2::Esp_Item_SLR);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("SLR", (float*)&SettingMenu2::Esp_Item_SLRC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("SKS", &SettingMenu2::Esp_Item_SKS);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("SKS", (float*)&SettingMenu2::Esp_Item_SKSC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Mini-14", &SettingMenu2::Esp_Item_Mini14);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Mini-14", (float*)&SettingMenu2::Esp_Item_Mini14C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("VSS", &SettingMenu2::Esp_Item_VSS);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Mini-14", (float*)&SettingMenu2::Esp_Item_VSSC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Win-94", &SettingMenu2::Esp_Item_Win94);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Win-94", (float*)&SettingMenu2::Esp_Item_Win94C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Mosin", &SettingMenu2::Esp_Item_Mosin);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Mosin", (float*)&SettingMenu2::Esp_Item_MosinC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Mk-14", &SettingMenu2::Esp_Item_Mk14);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Mk-14", (float*)&SettingMenu2::Esp_Item_Mk14C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("MK12 Sniper", &SettingMenu2::MK12Sniper);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("MK12-Sniper", (float*)&SettingMenu2::MK12SniperC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("AMR Sniper", &SettingMenu2::AMRSniper);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("AMR-Sniper", (float*)&SettingMenu2::AMRSniperC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);



									ImGui::Spacing();
									ImGui::Spacing();
									ImGui::Bullet(); ImGui::Text("(SMG) Weapons List");
									ImGui::Bullet(); ImGui::Text("Size");
									ImGui::SameLine();
									ImGui::SliderFloat0("                                     (SMG) Weapons Size", &SettingMenu2::SMG_Weaponsize, 0, 25);
									ImGui::Spacing();

									ImGui::Checkbox("PP19", &SettingMenu2::Esp_Item_PP19);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("PP19", (float*)&SettingMenu2::Esp_Item_PP19C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Tommy Gun", &SettingMenu2::Esp_Item_TommyGun);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Tommy", (float*)&SettingMenu2::Esp_Item_TommyGunC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("MP5K", &SettingMenu2::Esp_Item_MP5K);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("MP5K", (float*)&SettingMenu2::Esp_Item_MP5KC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("UMP9", &SettingMenu2::Esp_Item_UMP9);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("UMP9", (float*)&SettingMenu2::Esp_Item_UMP9C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Vector", &SettingMenu2::Esp_Item_Vector);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Vector", (float*)&SettingMenu2::Esp_Item_VectorC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Uzi", &SettingMenu2::Esp_Item_Uzi);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Uzi", (float*)&SettingMenu2::Esp_Item_UziC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);




									ImGui::Spacing();
									ImGui::Spacing();
									ImGui::Bullet(); ImGui::Text("(ShotGun) Weapons List");
									ImGui::Bullet(); ImGui::Text("Size");
									ImGui::SameLine();
									ImGui::SliderFloat0("                                     (ShotGun) Weapons Size", &SettingMenu2::ShotGun_Weaponsize, 0, 25);
									ImGui::Spacing();

									ImGui::Checkbox("ShotGun S686", &SettingMenu2::ShotGun_S686);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("ShotGun_S686", (float*)&SettingMenu2::ShotGun_S686C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("DBS", &SettingMenu2::Esp_Item_DBS);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("DBS", (float*)&SettingMenu2::Esp_Item_DBSC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("S12K", &SettingMenu2::Esp_Item_S12K);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("S12K", (float*)&SettingMenu2::Esp_Item_S12KC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("S1897", &SettingMenu2::Esp_Item_S1897);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("S1897", (float*)&SettingMenu2::Esp_Item_S1897C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Sawed Off", &SettingMenu2::Esp_Item_SawedOff);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Sawed_Off", (float*)&SettingMenu2::Esp_Item_SawedOffC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("M1014", &SettingMenu2::Esp_Item_M1014);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("M1014", (float*)&SettingMenu2::Esp_Item_M1014C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);



									ImGui::Spacing();
									ImGui::Spacing();
									ImGui::Bullet(); ImGui::Text("(Pistol) Weapons List");
									ImGui::Bullet(); ImGui::Text("Size");
									ImGui::SameLine();
									ImGui::SliderFloat0("                                     (Pistol) Weapons Size", &SettingMenu2::Pistol_Weaponsize, 0, 25);
									ImGui::Spacing();

									ImGui::Checkbox("Flare Gun", &SettingMenu2::Esp_Item_FlareGun);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Flare", (float*)&SettingMenu2::Esp_Item_FlareGunC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Desert Eagle", &SettingMenu2::Esp_Item_DesertEagle);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Desert_Eagle", (float*)&SettingMenu2::Esp_Item_DesertEagleC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("R1895", &SettingMenu2::Esp_Item_R1895);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("R1895", (float*)&SettingMenu2::Esp_Item_R1895C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Vz61", &SettingMenu2::Esp_Item_Vz61);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Vz61", (float*)&SettingMenu2::Esp_Item_Vz61C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("P92", &SettingMenu2::Esp_Item_P92);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("P92", (float*)&SettingMenu2::Esp_Item_P92C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("P18C", &SettingMenu2::Esp_Item_P18C);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("P18C", (float*)&SettingMenu2::Esp_Item_P18CC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("R45", &SettingMenu2::Esp_Item_R45);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("R45", (float*)&SettingMenu2::Esp_Item_R45C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("P1911", &SettingMenu2::Esp_Item_P1911);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("P1911", (float*)&SettingMenu2::Esp_Item_P1911C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);



									ImGui::Spacing();
									ImGui::Spacing();
									ImGui::Bullet(); ImGui::Text("(Other) Weapons List");
									ImGui::Bullet(); ImGui::Text("Size");
									ImGui::SameLine();
									ImGui::SliderFloat0("                                     (Other) Weapons Size", &SettingMenu2::Other_Weaponsize, 0, 25);
									ImGui::Spacing();

									ImGui::Checkbox("Explosive Bow", &SettingMenu2::Esp_Item_ExplosiveBow);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Explosive-Bow", (float*)&SettingMenu2::Esp_Item_ExplosiveBowC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Pan", &SettingMenu2::Pan);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Pan", (float*)&SettingMenu2::PanC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Crowbar", &SettingMenu2::Crowbar);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Crowbar", (float*)&SettingMenu2::CrowbarC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Machete", &SettingMenu2::Machete);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Machete", (float*)&SettingMenu2::MacheteC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								}
								ImGui::EndChild();

								ImGui::EndTabItem();
							}

							if (ImGui::BeginTabItem("Amm."))
								//if (ImGui::BeginTabItem("Ammo"))
							{
								if (ImGui::BeginChild("###items#Ammo", ImVec2(592, 285), true))
								{

									ImGui::Spacing();
									ImGui::Bullet(); ImGui::Text("Ammo List");
									ImGui::Bullet(); ImGui::Text("Size");
									ImGui::SameLine();
									ImGui::SliderFloat0("                                     Ammo Size", &SettingMenu2::Ammosize, 0, 25);
									ImGui::Spacing();

									ImGui::Checkbox("7.62mm", &SettingMenu2::Esp_Item_762mm);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("762mm", (float*)&SettingMenu2::Esp_Item_762mmC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("5.56mm", &SettingMenu2::Esp_Item_556mm);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("556mm", (float*)&SettingMenu2::Esp_Item_556mmC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("300_Magnum", &SettingMenu2::Esp_Item_Awmimo);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("300_Magnum", (float*)&SettingMenu2::Esp_Item_AwmimoC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Ammo_50BMG", &SettingMenu2::Ammo_50BMG);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Ammo_50BMG", (float*)&SettingMenu2::Ammo_50BMGC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("9mm", &SettingMenu2::Esp_Item_9mm);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("9mm", (float*)&SettingMenu2::Esp_Item_9mmC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("45.ACP", &SettingMenu2::Esp_Item_45ACP);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("45.ACP", (float*)&SettingMenu2::Esp_Item_45ACPC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Flare Ammo", &SettingMenu2::Esp_Item_Flare);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Flare-Ammo", (float*)&SettingMenu2::Esp_Item_FlareC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Ammo_12Guage", &SettingMenu2::Ammo_12Guage);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Ammo_12Guage", (float*)&SettingMenu2::Ammo_12GuageC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								}
								ImGui::EndChild();

								ImGui::EndTabItem();
							}

							if (ImGui::BeginTabItem("Hea."))
								//if (ImGui::BeginTabItem("Health"))
							{
								if (ImGui::BeginChild("###items#Health", ImVec2(592, 285), true))
								{

									ImGui::Spacing();
									ImGui::Bullet(); ImGui::Text("Health List");
									ImGui::Bullet(); ImGui::Text("Size");
									ImGui::SameLine();
									ImGui::SliderFloat0("                                     Health Size", &SettingMenu2::HealthSize, 0, 25);
									ImGui::Spacing();

									ImGui::Checkbox("Bandages", &SettingMenu2::Esp_Item_Bandages);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Bandages", (float*)&SettingMenu2::Esp_Item_BandagesC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Energy Drink", &SettingMenu2::Esp_Item_EnergyDrink);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Energy Drink", (float*)&SettingMenu2::Esp_Item_EnergyDrinkC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Painkiller", &SettingMenu2::Esp_Item_Painkiller);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Painkiller", (float*)&SettingMenu2::Esp_Item_PainkillerC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Adrenaline Syringe", &SettingMenu2::Esp_Item_AdrenalineSyringe);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Adrenaline Syringe", (float*)&SettingMenu2::Esp_Item_AdrenalineSyringeC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("First Aid Kit", &SettingMenu2::Esp_Item_FirstAidKit);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("First Aid Kit", (float*)&SettingMenu2::Esp_Item_FirstAidKitC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Med Kit", &SettingMenu2::Esp_Item_MedKit);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Med Kit", (float*)&SettingMenu2::Esp_Item_MedKitC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Boster Tree", &SettingMenu2::BosterTree);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Boster-Tree", (float*)&SettingMenu2::BosterTreeC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Kung Fu Steamed Bun", &SettingMenu2::KungFuSteamedBun);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("KungFuSteamed-Bun", (float*)&SettingMenu2::KungFuSteamedBunC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);


								}
								ImGui::EndChild();

								ImGui::EndTabItem();
							}

							if (ImGui::BeginTabItem("Bag"))
							{
								if (ImGui::BeginChild("###items#Bag", ImVec2(592, 285), true))
								{

									ImGui::Spacing();
									ImGui::Bullet(); ImGui::Text("Bag List");
									ImGui::Bullet(); ImGui::Text("Size");
									ImGui::SameLine();
									ImGui::SliderFloat0("                                     Bag Size", &SettingMenu2::BagSize, 0, 25);
									ImGui::Spacing();

									ImGui::Checkbox("Bag Lv1", &SettingMenu2::Esp_Item_Bag1);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Bag 1", (float*)&SettingMenu2::Esp_Item_Bag1C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Bag Lv2", &SettingMenu2::Esp_Item_Bag2);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Bag 2", (float*)&SettingMenu2::Esp_Item_Bag2C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Bag Lv3", &SettingMenu2::Esp_Item_Bag3);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Bag 3", (float*)&SettingMenu2::Esp_Item_Bag3C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								}
								ImGui::EndChild();

								ImGui::EndTabItem();
							}

							if (ImGui::BeginTabItem("Hel."))
								//if (ImGui::BeginTabItem("Helmet"))
							{
								if (ImGui::BeginChild("###items#Helmet", ImVec2(592, 285), true))
								{

									ImGui::Spacing();
									ImGui::Bullet(); ImGui::Text("Helmet List");
									ImGui::Bullet(); ImGui::Text("Size");
									ImGui::SameLine();
									ImGui::SliderFloat0("                                     Helmet Size", &SettingMenu2::HelmetSize, 0, 25);
									ImGui::Spacing();

									ImGui::Checkbox("Helmet Lv1", &SettingMenu2::Esp_Item_Helmet1);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Helmet 1", (float*)&SettingMenu2::Esp_Item_Helmet1C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Helmet Lv2", &SettingMenu2::Esp_Item_Helmet2);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Helmet 2", (float*)&SettingMenu2::Esp_Item_Helmet2C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Helmet Lv3", &SettingMenu2::Esp_Item_Helmet3);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Helmet 3", (float*)&SettingMenu2::Esp_Item_Helmet3C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								}
								ImGui::EndChild();

								ImGui::EndTabItem();
							}

							if (ImGui::BeginTabItem("Arm."))
								//if (ImGui::BeginTabItem("Armor"))
							{
								if (ImGui::BeginChild("###items#Armor", ImVec2(592, 285), true))
								{


									ImGui::Spacing();
									ImGui::Bullet(); ImGui::Text("Armor List");
									ImGui::Bullet(); ImGui::Text("Size");
									ImGui::SameLine();
									ImGui::SliderFloat0("                                     Armor Size", &SettingMenu2::ArmorSize, 0, 25);
									ImGui::Spacing();

									ImGui::Checkbox("Armor Lv1", &SettingMenu2::Esp_Item_Armor1);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Armor 1", (float*)&SettingMenu2::Esp_Item_Armor1C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Armor Lv2", &SettingMenu2::Esp_Item_Armor2);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Armor 2", (float*)&SettingMenu2::Esp_Item_Armor2C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Armor Lv3", &SettingMenu2::Esp_Item_Armor3);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Armor 3", (float*)&SettingMenu2::Esp_Item_Armor3C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								}
								ImGui::EndChild();

								ImGui::EndTabItem();
							}

							if (ImGui::BeginTabItem("Sco."))
								//if (ImGui::BeginTabItem("Scope"))
							{
								if (ImGui::BeginChild("###items#Scope", ImVec2(592, 285), true))
								{


									ImGui::Spacing();
									ImGui::Bullet(); ImGui::Text("Scope List");
									ImGui::Bullet(); ImGui::Text("Size");
									ImGui::SameLine();
									ImGui::SliderFloat0("                                     Scope Size", &SettingMenu2::ScopeSize, 0, 25);
									ImGui::Spacing();

									ImGui::Checkbox("Red Dot", &SettingMenu2::RedDot);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Red-Dot", (float*)&SettingMenu2::RedDotC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Holo", &SettingMenu2::Esp_Item_Holo);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Holo", (float*)&SettingMenu2::Esp_Item_HoloC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("x2", &SettingMenu2::Esp_Item_x2);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("2X", (float*)&SettingMenu2::Esp_Item_x2C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("x3", &SettingMenu2::Esp_Item_x3);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("3X", (float*)&SettingMenu2::Esp_Item_x3C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("x4", &SettingMenu2::Esp_Item_x4);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("4X", (float*)&SettingMenu2::Esp_Item_x4C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("x6", &SettingMenu2::Esp_Item_x6);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("6X", (float*)&SettingMenu2::Esp_Item_x6C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("x8", &SettingMenu2::Esp_Item_x8);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("8X", (float*)&SettingMenu2::Esp_Item_x8C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								}
								ImGui::EndChild();

								ImGui::EndTabItem();
							}

							if (ImGui::BeginTabItem("Gre."))
								//if (ImGui::BeginTabItem("Grenade"))
							{
								if (ImGui::BeginChild("###items#Grenade", ImVec2(592, 285), true))
								{

									ImGui::Spacing();
									ImGui::Bullet(); ImGui::Text("Grenade List");
									ImGui::Bullet(); ImGui::Text("Size");
									ImGui::SameLine();
									ImGui::SliderFloat0("                                     Grenade Size", &SettingMenu2::GrenadeSize, 0, 25);
									ImGui::Spacing();


									ImGui::Checkbox("RedZone Bomb", &SettingMenu2::RedZoneBomb);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("RedZoneBomb", (float*)&SettingMenu2::RedZoneBombC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("Grenade", &SettingMenu2::Esp_Item_Frag);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Grenade", (float*)&SettingMenu2::Esp_Item_FragC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("Grenade Warning", &SettingMenu2::Grenade_Warning);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Grenade_Warning", (float*)&SettingMenu2::Grenade_WarningC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("Molotov Cocktail", &SettingMenu2::Esp_Item_Molotof);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Molotov-Cocktail", (float*)&SettingMenu2::Esp_Item_MolotofC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("Molotov Warning", &SettingMenu2::Molotov_Warning);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Molotov_Warning", (float*)&SettingMenu2::Molotov_WarningC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("Stun Grenade", &SettingMenu2::StunGrenade);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Stun-Grenade", (float*)&SettingMenu2::StunGrenadeC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("Stun Grenade Warning", &SettingMenu2::StunGrenade_Warning);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Stun-Grenade_Warning", (float*)&SettingMenu2::StunGrenade_WarningC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("Smoke", &SettingMenu2::Esp_Item_Smoke);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Smoke", (float*)&SettingMenu2::Esp_Item_SmokeC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("Smoke Warning", &SettingMenu2::Smoke_Warning);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Smoke_Warning", (float*)&SettingMenu2::Smoke_WarningC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);


								}
								ImGui::EndChild();

								ImGui::EndTabItem();
							}

							/*if (ImGui::BeginTabItem("Weapon 2"))
							{
								if (ImGui::BeginChild("###items#Weapon", ImVec2(400, 322), true))
								{

								}
								ImGui::EndChild();
								ImGui::EndTabItem();
							}*/
						}
						ImGui::EndTabBar();

						ImGui::EndTabItem();
					}

					if (ImGui::BeginTabItem("Others Item"))
					{
						if (ImGui::BeginTabBar("BeginTabBar"))
						{
							if (ImGui::BeginTabItem("Vehicle"))
								//if (ImGui::BeginTabItem("Grenade"))
							{
								if (ImGui::BeginChild("###items#Vehicle", ImVec2(592, 285), true))
								{

									ImGui::Spacing();
									ImGui::Bullet(); ImGui::Text("Vehicle List");
									ImGui::Bullet(); ImGui::Text("Size");
									ImGui::SameLine();
									ImGui::SliderFloat0("                                     Vehicle Size", &SettingMenu2::VehicleSize, 0.100, 25);
									ImGui::Spacing();

									ImGui::Checkbox(" Show All Vehicle", &SettingMenu2::Vehicle);
									//ImGui::Spacing();
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("VehicleC", (float*)&SettingMenu2::VehicleColor, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									/*ImGui::Checkbox("Lion Dance Car", &SettingMenu2::LionDanceCar);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("LionDanceCar", (float*)&SettingMenu2::LionDanceCarC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("BRDM", &SettingMenu2::BRDM);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("BRDM", (float*)&SettingMenu2::BRDMC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("Scooter", &SettingMenu2::Scooter);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Scooter", (float*)&SettingMenu2::ScooterC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("Motorcycle", &SettingMenu2::Motorcycle);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Motorcycle", (float*)&SettingMenu2::MotorcycleC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("Snowmobile", &SettingMenu2::Snowmobile);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Snowmobile", (float*)&SettingMenu2::SnowmobileC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("Tuk", &SettingMenu2::Tuk);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Tuk", (float*)&SettingMenu2::TukC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("Buggy", &SettingMenu2::Buggy);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Buggy", (float*)&SettingMenu2::BuggyC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("Sportsa", &SettingMenu2::Sportsa);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Sportsa", (float*)&SettingMenu2::SportsaC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("Sports", &SettingMenu2::Sports);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Sports", (float*)&SettingMenu2::SportsC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("Dacia", &SettingMenu2::Dacia);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Dacia", (float*)&SettingMenu2::DaciaC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("Rony", &SettingMenu2::Rony);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Rony", (float*)&SettingMenu2::RonyC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("UAZ", &SettingMenu2::UAZ);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("UAZ", (float*)&SettingMenu2::UAZC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("Minibus", &SettingMenu2::Minibus);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Minibus", (float*)&SettingMenu2::MinibusC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("PG117", &SettingMenu2::PG117);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("PG117", (float*)&SettingMenu2::PG117C, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("Aquarail", &SettingMenu2::Aquarail);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Aquarail", (float*)&SettingMenu2::AquarailC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("ModelY Tesla", &SettingMenu2::ModelYTesla);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("ModelYTesla", (float*)&SettingMenu2::ModelYTeslaC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("Gravity Motorcycle", &SettingMenu2::GravityMotorcycle);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("GravityMotorcycle", (float*)&SettingMenu2::GravityMotorcycleC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("Glider", &SettingMenu2::Glider);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Glider", (float*)&SettingMenu2::GliderC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("UTV", &SettingMenu2::UTV);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("UTV", (float*)&SettingMenu2::UTVC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("Monstar Truck", &SettingMenu2::MonstarTruck);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("MonstarTruck", (float*)&SettingMenu2::MonstarTruckC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("Coupe_New Dacia", &SettingMenu2::Coupe_NewDacia);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Coupe_NewDacia", (float*)&SettingMenu2::Coupe_NewDaciaC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("Quad", &SettingMenu2::Quad);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Quad", (float*)&SettingMenu2::QuadC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("Snow Bike", &SettingMenu2::Snow_Bike);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Snow_Bike", (float*)&SettingMenu2::Snow_BikeC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);

									ImGui::Checkbox("PickUp", &SettingMenu2::PickUp);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("PickUp", (float*)&SettingMenu2::PickUpC, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs);*/

								}
								ImGui::EndChild();

								ImGui::EndTabItem();
							}

							if (ImGui::BeginTabItem("Airplan"))
								//if (ImGui::BeginTabItem("Ammo"))
							{
								if (ImGui::BeginChild("###items#Airplan", ImVec2(592, 285), true))
								{
									ImGui::Spacing();
									ImGui::Bullet(); ImGui::Text("Airplan List");
									ImGui::Bullet(); ImGui::Text("Size");
									ImGui::SameLine();
									ImGui::SliderFloat0("                                     Airplan Size", &SettingMenu2::AirplanT, 0, 25);
									ImGui::Spacing();

									ImGui::Checkbox("AirDrop Plane", &SettingMenu2::Airplan);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("AirDropPlane", (float*)&SettingMenu2::AirplanC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								}
								ImGui::EndChild();

								ImGui::EndTabItem();
							}

							if (ImGui::BeginTabItem("AirDrop"))
								//if (ImGui::BeginTabItem("Ammo"))
							{
								if (ImGui::BeginChild("###items#AirDropBoxItem", ImVec2(592, 285), true))
								{
									ImGui::Spacing();
									ImGui::Bullet(); ImGui::Text("AirDropBox Item List");
									/*ImGui::Bullet(); ImGui::Text("Size");
									ImGui::SameLine();
									ImGui::SliderFloat0("                                     AirDropBox Item Size", &SettingMenu2::AirDropBoxSize, 0, 25);*/
									ImGui::Spacing();

									ImGui::Checkbox(" AirDrop Box", &SettingMenu2::AirDropBox);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 355 });
									ImGui::ColorEdit4("AirDrop-Box", (float*)&SettingMenu2::AirDropBoxColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
									//if (SettingMenu2::Esp_Item_LootBox)
									{
										if (ImGui::TreeNodeEx("  AirDrop-Box Size"))
										{
											ImGui::Indent();

											//ImGui::SameLine();
											ImGui::SliderFloat("                                          AirDrop-Box Size", &SettingMenu2::AirDropBoxSize, 0.100f, 20.00f);

											ImGui::Unindent();
											ImGui::TreePop();
										}
									}


									//ImGui::Checkbox(" AirDrop Box Items", &SettingMenu2::AirDropBoxitems1);
									//ImGui::SameLine();
									//ImGui::SetCursorPosX({ 355 });
									//ImGui::ColorEdit4("AirDrop-Box Items", (float*)&Colors::AirDropBoxitemColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
									////if (SettingMenu2::playerdeadbox)
									//{
									//	if (ImGui::TreeNodeEx("  AirDrop Box Items Size"))
									//	{
									//		ImGui::Indent();

									//		//ImGui::SameLine();
									//		ImGui::SliderFloat("                                          AirDrop Box Items size", &SettingMenu2::AirDropBoxItemsSize, 0.100f, 20.00f);

									//		ImGui::Unindent();
									//		ImGui::TreePop();
									//	}
									//}

									//ImGui::Checkbox("AirDrop Box Items Line Color", &SettingMenu2::itemrect);
									//ImGui::SameLine();
									//ImGui::SetCursorPosX({ 355 });
									//ImGui::ColorEdit4("AirDrop-Box-Items Shadow", (float*)&Colors::bgcornerColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
									////if (SettingMenu2::itemrect)
									//{
									//	if (ImGui::TreeNodeEx("  AirDrop Box Items Line Setting"))
									//	{
									//		ImGui::Indent();

									//		if (ImGui::RadioButton("Full-Line", &LootBoxItems_RadioButton, 2))
									//		{
									//			item_current_Emu = 0;
									//			SettingMenu2::redioption = 1;
									//		}
									//		ImGui::SameLine();
									//		if (ImGui::RadioButton("Corner-Line", &LootBoxItems_RadioButton, 1))
									//		{
									//			item_current_Emu = 1;
									//			SettingMenu2::redioption = 2;
									//			ImGui::SetItemDefaultFocus();
									//		}


									//		ImGui::Unindent();
									//		ImGui::TreePop();
									//	}
									//}

								}
								ImGui::EndChild();

								ImGui::EndTabItem();
							}

							if (ImGui::BeginTabItem("Loot-Box"))
								//if (ImGui::BeginTabItem("Ammo"))
							{
								if (ImGui::BeginChild("###items#Loot-BoxItem", ImVec2(592, 285), true))
								{
									ImGui::Spacing();
									ImGui::Bullet(); ImGui::Text("Loot-Box Item List");
									/*ImGui::Bullet(); ImGui::Text("Size");
									ImGui::SameLine();
									ImGui::SliderFloat0("                                     Loot-Box Item Size", &SettingMenu2::PlayerLootBoxSize, 0, 25);*/
									ImGui::Spacing();

									ImGui::Checkbox(" Loot-Box", &SettingMenu2::playerdeadbox);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 355 });
									ImGui::ColorEdit4("P Loot-Box", (float*)&SettingMenu2::PlayerDeadboxColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
									//if (SettingMenu2::Esp_Item_LootBox)
									{
										if (ImGui::TreeNodeEx("  Loot-Box Size"))
										{
											ImGui::Indent();

											//ImGui::SameLine();
											ImGui::SliderFloat("                                          Loot-Box Size", &SettingMenu2::PlayerLootBoxSize, 0.100f, 20.00f);

											ImGui::Unindent();
											ImGui::TreePop();
										}
									}


									ImGui::Checkbox(" Loot-Box Items", &SettingMenu2::playerdeadboxitems);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 355 });
									ImGui::ColorEdit4("Loot-Box Items", (float*)&ColorsMenu2::deadboxitemColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
									//if (SettingMenu2::playerdeadbox)
									{
										if (ImGui::TreeNodeEx("  Loot-Box Items Size"))
										{
											ImGui::Indent();

											//ImGui::SameLine();
											ImGui::SliderFloat("                                          Loot-Box Items size", &SettingMenu2::PlayerLootBoxItemsSize, 0.100f, 20.00f);

											ImGui::Unindent();
											ImGui::TreePop();
										}
									}


									ImGui::Checkbox("Loot-Box Items Line Color", &SettingMenu2::itemrect);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 355 });
									ImGui::ColorEdit4("Loot-Box-Items Shadow", (float*)&ColorsMenu2::bgcornerColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
									//if (SettingMenu2::itemrect)
									{
										if (ImGui::TreeNodeEx("  Loot-Box Items Line Setting"))
										{
											ImGui::Indent();

											if (ImGui::RadioButton("Full-Line", &LootBoxItems_RadioButton, 2))
											{
												item_current_Emu = 0;
												SettingMenu2::redioption = 1;
											}
											ImGui::SameLine();
											if (ImGui::RadioButton("Corner-Line", &LootBoxItems_RadioButton, 1))
											{
												item_current_Emu = 1;
												SettingMenu2::redioption = 2;
												ImGui::SetItemDefaultFocus();
											}


											ImGui::Unindent();
											ImGui::TreePop();
										}
									}

								}
								ImGui::EndChild();

								ImGui::EndTabItem();
							}

							if (ImGui::BeginTabItem("More Item"))
								//if (ImGui::BeginTabItem("Ammo"))
							{
								if (ImGui::BeginChild("###items#MoreItem", ImVec2(592, 285), true))
								{
									ImGui::Spacing();
									ImGui::Bullet(); ImGui::Text("More Item List");
									ImGui::Bullet(); ImGui::Text("Size");
									ImGui::SameLine();
									ImGui::SliderFloat0("                                     More Item Size", &SettingMenu2::MoreItemSize, 0, 25);
									ImGui::Spacing();

									ImGui::Checkbox("Zone Radiation", &SettingMenu2::ZoneRadiation);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Zone_Radiation", (float*)&SettingMenu2::ZoneRadiationC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("WIN MVP Statue", &SettingMenu2::WINMVPStatue);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("WINMVP_Statue", (float*)&SettingMenu2::WINMVPStatueC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Place Selected", &SettingMenu2::PlaceSelected);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Place_elected", (float*)&SettingMenu2::PlaceSelectedC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("EmergencyCall Pickup", &SettingMenu2::EmergencyCallPickup);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("EmergencyCall_Pickup", (float*)&SettingMenu2::EmergencyCallPickupC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Lion Dance", &SettingMenu2::LionDance);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Lion_Dance", (float*)&SettingMenu2::LionDanceC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Grappling Hook", &SettingMenu2::GrapplingHook);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Grappling_Hook", (float*)&SettingMenu2::GrapplingHookC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Shop Token", &SettingMenu2::ShopToken);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Shop_Token", (float*)&SettingMenu2::ShopTokenC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Supply Shop", &SettingMenu2::SupplyShop);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Supply_Shop", (float*)&SettingMenu2::PlaceSelectedC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);


									ImGui::Spacing();
									ImGui::Bullet(); ImGui::Text("(AR) Necessary Equipment");
									ImGui::Spacing();
									ImGui::Checkbox("Flash Hider (AR)", &SettingMenu2::FlashHiderAR);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("FlashHider(AR)", (float*)&SettingMenu2::FlashHiderARC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Compensator (AR)", &SettingMenu2::CompensatorAR);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Compensator(AR)", (float*)&SettingMenu2::CompensatorARC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Suppressor (AR)", &SettingMenu2::SuppressorAR);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Suppressor(AR)", (float*)&SettingMenu2::SuppressorARC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Quickdraw Mag (AR)", &SettingMenu2::QuickdrawMagAR);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Quickdraw Mag (AR)", (float*)&SettingMenu2::QuickdrawMagARC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Extended Mag (AR)", &SettingMenu2::ExtendedMagAR);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("ExtendedMag(AR)", (float*)&SettingMenu2::ExtendedMagARC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Extended Quickdraw Mag (AR)", &SettingMenu2::ExtendedQuickdrawMagAR);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("ExtendedQuickdrawMag(AR)", (float*)&SettingMenu2::ExtendedQuickdrawMagARC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);


									ImGui::Spacing();
									ImGui::Bullet(); ImGui::Text("(Sniper) Necessary Equipment");
									ImGui::Spacing();
									ImGui::Checkbox("FlashHider (Sniper)", &SettingMenu2::FlashHiderSniper);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("FlashHider(Sniper)", (float*)&SettingMenu2::FlashHiderSniperC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Compensator (Sniper)", &SettingMenu2::CompensatorSniper);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Compensator(Sniper)", (float*)&SettingMenu2::CompensatorSniperC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Suppressor (Sniper)", &SettingMenu2::SuppressorSniper);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Suppressor(Sniper)", (float*)&SettingMenu2::SuppressorSniperC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Quickdraw Mag (Sniper)", &SettingMenu2::QuickdrawMagSniper);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("QuickdrawMag(Sniper)", (float*)&SettingMenu2::QuickdrawMagSniperC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Extended Mag (Sniper)", &SettingMenu2::ExtendedMagSniper);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("ExtendedMag(Sniper)", (float*)&SettingMenu2::ExtendedMagSniperC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Extended Quickdraw Mag (Sniper)", &SettingMenu2::ExtendedQuickdrawMagSniper);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("ExtendedQuickdrawMag(Sniper)", (float*)&SettingMenu2::ExtendedQuickdrawMagSniperC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);


									ImGui::Spacing();
									ImGui::Bullet(); ImGui::Text("(SMG) Necessary Equipment");
									ImGui::Spacing();
									ImGui::Checkbox("FlashHider (SMG)", &SettingMenu2::FlashHiderSMG);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("FlashHider(SMG)", (float*)&SettingMenu2::FlashHiderSMGC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Compensator (SMG)", &SettingMenu2::CompensatorSMG);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Compensator(SMG)", (float*)&SettingMenu2::CompensatorSMGC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Suppressor (SMG)", &SettingMenu2::SuppressorSMG);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Suppressor(SMG)", (float*)&SettingMenu2::SuppressorSMGC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Tactical Stock (SMG)", &SettingMenu2::TacticalStockSMG);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("TacticalStock(SMG)", (float*)&SettingMenu2::TacticalStockSMGC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Choke (SG)", &SettingMenu2::ChokeSG);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("Choke(SG)", (float*)&SettingMenu2::ChokeSGC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Thumb Grip", &SettingMenu2::ThumbGrip);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("ThumbGrip", (float*)&SettingMenu2::ThumbGripC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

									ImGui::Checkbox("Light Grip", &SettingMenu2::LightGrip);
									ImGui::SameLine();
									ImGui::SetCursorPosX({ 345 });
									ImGui::ColorEdit4("LightGrip", (float*)&SettingMenu2::LightGripC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

								}
								ImGui::EndChild();

								ImGui::EndTabItem();
							}
						}
						ImGui::EndTabBar();

						ImGui::EndTabItem();
					}

					if (ImGui::BeginTabItem("More Option"))
					{
						if (ImGui::BeginChild("###others", ImVec2(592, 310), true))
						{
							ImGui::Spacing();

							ImGui::Checkbox(" Fight Mode", &SettingMenu2::fightmode);
							//if (SettingMenu2::fightmode)
							{
								if (ImGui::TreeNodeEx("  Fight Mode Setting"))
								{
									ImGui::Indent();

									/*ImGui::SameLine();
									ImGui::SliderFloat("                    Distance size", &SettingMenu2::Dissize, 0.100f, 20.00f);*/

									ImGui::Unindent();
									ImGui::TreePop();
								}
							}


							ImGui::Checkbox(" All Items", &SettingMenu2::Item);
							//if (SettingMenu2::Item)
							{
								if (ImGui::TreeNodeEx("  All Items Size"))
								{
									ImGui::Indent();

									//ImGui::SameLine();
									ImGui::SliderFloat("                                          All Items Size", &SettingMenu2::allitemssT, 0.100f, 20.00f);

									ImGui::Unindent();
									ImGui::TreePop();
								}
							}


							ImGui::Checkbox(" Total Players Number", &SettingMenu2::TotalEnemy);
							//if (SettingMenu2::TotalEnemy)
							{
								if (ImGui::TreeNodeEx("  Total Players Number Setting"))
								{
									ImGui::Indent();

									if (ImGui::RadioButton("Style 1", &TotalPlayers_RadioButton, 1))
									{
										SettingMenu2::TotalEnemyStyle1 = true;
										SettingMenu2::TotalEnemyStyle2 = false;
										SettingMenu2::TotalEnemyStyle2 = false;
									}
									ImGui::SameLine();
									if (ImGui::RadioButton("Style 2", &TotalPlayers_RadioButton, 2))
									{
										SettingMenu2::TotalEnemyStyle1 = false;
										SettingMenu2::TotalEnemyStyle2 = true;
										SettingMenu2::TotalEnemyStyle3 = false;
									}
									ImGui::SameLine();
									if (ImGui::RadioButton("Style 3", &TotalPlayers_RadioButton, 3))
									{
										SettingMenu2::TotalEnemyStyle1 = false;
										SettingMenu2::TotalEnemyStyle2 = false;
										SettingMenu2::TotalEnemyStyle3 = true;
									}

									ImGui::Unindent();
									ImGui::TreePop();
								}
							}


							ImGui::Checkbox(" Show Text Border", &SettingMenu2::borderlo);
							//if (SettingMenu2::borderlo)
							{
								if (ImGui::TreeNodeEx(" Text Border Setting"))
								{
									ImGui::Indent();

									////ImGui::SameLine();
									//ImGui::SliderFloat("                                          Bot Name size", &SettingMenu2::BotNamesize, 0.100f, 20.00f);

									ImGui::Unindent();
									ImGui::TreePop();
								}
							}


							ImGui::Checkbox(" Show Watermark", &SettingMenu2::watermark);
							ImGui::SameLine();
							ImGui::SetCursorPosX({ 355 });
							ImGui::ColorEdit4("Watermark Text Color", (float*)&SettingMenu2::watermarkC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
							//if (SettingMenu2::watermark)
							{
								if (ImGui::TreeNodeEx(" Watermark Setting"))
								{
									ImGui::Indent();

									////ImGui::SameLine();
									ImGui::SliderFloat("                                          Watermark Size", &SettingMenu2::watermarkT, 0, 25);

									ImGui::Unindent();
									ImGui::TreePop();
								}
							}


							ImGui::Checkbox(" Show Expred Date", &SettingMenu2::Expred_Date);
							ImGui::SameLine();
							ImGui::SetCursorPosX({ 355 });
							ImGui::ColorEdit4("Expred Date Text Color", (float*)&SettingMenu2::Expred_DateC, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
							//if (SettingMenu2::Expred_Date)
							{
								if (ImGui::TreeNodeEx(" Expred Date Setting"))
								{
									ImGui::Indent();

									////ImGui::SameLine();
									ImGui::SliderFloat("                                          Expred Date Size", &SettingMenu2::Expred_DateT, 0, 25);

									ImGui::Unindent();
									ImGui::TreePop();
								}
							}


						}
						ImGui::EndChild();

						ImGui::EndTabItem();
					}

				}
				ImGui::EndTabBar();
			}

			if (Settings::Tab == 3)
			{
				/*ImGui::BeginChild("###2", ImVec2(408, 355), true, 0);
				{

				}
				ImGui::EndChild();*/
				if (ImGui::BeginTabBar("BeginTabBar"))
				{
					if (ImGui::BeginTabItem("Magic Bullet"))
					{
						if (ImGui::BeginChild("##SafeMemory", ImVec2(592, 310), true))
						{
							ImGui::Checkbox(" Safe Bullet Track", &Setting::MagicBullet);
							ImGui::Spacing();
							if (Setting::MagicBullet)
							{
								Setting::MagicBulletticked = true;
							}
							else
							{
								Setting::MagicBulletticked = false;
							}

							ImGui::Checkbox(" Brutal Bullet Track", &SettingMenu2::MagicBulletDNG);
							ImGui::Spacing();
							if (SettingMenu2::MagicBulletDNG)
							{
								SettingMenu2::MagicBullet = false;
							}

							ImGui::Checkbox(" Instant Hit", &SettingMenu2::instanthit);
							//ImGui::Spacing();
							if (SettingMenu2::instanthit)
							{
								SettingMenu2::instanthitDNG = false;
							}

							ImGui::Bullet(); ImGui::Text("Bullet Tracking Settings");
							ImGui::Spacing();

							//ImGui::SetCursorPosX({ 170 });
							ImGui::Checkbox(" Legit Tracking", &SettingMenu2::Legitrack);
							//ImGui::Spacing
							if (SettingMenu2::Legitrack)
							{
								SettingMenu2::fovcircle = true;
								SettingMenu2::fovcircle2 = true;
							}
							ImGui::SameLine();
							ImGui::Checkbox(" Random Tracking", &SettingMenu2::RandomTracking);
							ImGui::Spacing();

							if (SettingMenu2::curraim == 0)
							{
								ImGui::Checkbox(" Aim Head", &SettingMenu2::AimHead);
								ImGui::Spacing();
								if (SettingMenu2::AimHead)
								{

								}
								else
								{
									SettingMenu2::AimBody = true;
									SettingMenu2::curraim = 1;
								}
							}
							else if (SettingMenu2::curraim == 1)
							{
								ImGui::Checkbox(" Aim Body", &SettingMenu2::AimBody);
								ImGui::Spacing();
								if (SettingMenu2::AimBody)
								{

								}
								else
								{
									SettingMenu2::AimHead = true;
									SettingMenu2::curraim = 0;
								}
							}


							ImGui::Checkbox(" Skip Knock", &SettingMenu2::knocked);
							//ImGui::Spacing();
							ImGui::SameLine();
							ImGui::Checkbox(" Skip Bots ", &SettingMenu2::SkipBots);
							ImGui::Spacing();

							ImGui::Checkbox(" Fov Based Tracking ", &SettingMenu2::fovcircle2);
							ImGui::Spacing();
							if (SettingMenu2::fovcircle2)
							{
								SettingMenu2::fovcircle = true;

								ImGui::Checkbox(" Show Fov ", &SettingMenu2::fovcircle);
								ImGui::SameLine();
								//ImGui::SetCursorPos({ 255.0f,203.0f });
								ImGui::BeginChild("###|", ImVec2(280, 30), false, 0);
								{
									//ImGui::Spacing();
									ImGui::SetCursorPos({ 0.0f, 0.0f });
									ImGui::SliderFloat("###fovFOVsize", &SettingMenu2::fovcircleredus, 0.0f, 2000.0f); ImGui::SameLine(); ImGui::Text("Fov Size");
									ImGui::SameLine();
									//ImGui::SetCursorPosX({ 365 });
									ImGui::ColorEdit4(" fovcolor", (float*)&ColorsMenu2::fovcircleColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
									/*if (SettingMenu2::fovcircle)
									{
										ImGui::SliderFloat("###fovFOVsize", &SettingMenu2::fovcircleredus, 1.0f, 2000.0f);  			ImGui::SameLine(); 			ImGui::Text("Fov Size");
									}*/
								}
								ImGui::EndChild();




							}
							else
							{
								SettingMenu2::fovcircle = false;
							}
							//Code End
						}
						ImGui::EndChild();

						ImGui::EndTabItem();
					}

					if (SettingMenu2::MagicBulletDNG)
					{
						//if (ImGui::BeginTabItem("Brutal Option"))
						//{
						//	if (ImGui::BeginChild("##BrutalMemory", ImVec2(592, 310), true))
						//	{
						//		//ImGui::Checkbox(" Magic Bullet Track Safe", &SettingMenu2::MagicBullet);
						//		/*ImGui::Checkbox(" Safe Bullet Track", &SettingMenu2::MagicBullet);
						//		ImGui::Spacing();
						//		if (SettingMenu2::MagicBullet)
						//		{
						//			SettingMenu2::MagicBulletDNG = false;
						//		}*/
						//		//ImGui::Checkbox(" Magic Bullet Track Danger", &SettingMenu2::MagicBulletDNG);
						//		ImGui::Spacing();
						//		ImGui::Checkbox(" Brutal Bullet Track", &SettingMenu2::MagicBulletDNG);
						//		ImGui::Spacing();
						//		if (SettingMenu2::MagicBulletDNG)
						//		{
						//			SettingMenu2::MagicBullet = false;
						//		}

						//		//ImGui::Checkbox(" Instant Hit Danger", &SettingMenu2::instanthit);
						//		ImGui::Checkbox(" Instant Hit Danger", &SettingMenu2::instanthitDNG);
						//		//ImGui::Spacing();
						//		if (SettingMenu2::instanthitDNG)
						//		{
						//			SettingMenu2::instanthit = false;
						//		}

						//		ImGui::Bullet(); ImGui::Text("Bullet Tracking Settings");
						//		ImGui::Spacing();

						//		//ImGui::SetCursorPosX({ 170 });
						//		ImGui::Checkbox(" Legit Tracking", &SettingMenu2::Legitrack);
						//		//ImGui::Spacing();
						//		if (SettingMenu2::Legitrack)
						//		{
						//			SettingMenu2::fovcircle = true;
						//			SettingMenu2::fovcircle2 = true;
						//		}
						//		ImGui::SameLine();
						//		ImGui::Checkbox(" Random Tracking", &SettingMenu2::RandomTracking);
						//		ImGui::Spacing();

						//		if (SettingMenu2::curraim == 0)
						//		{
						//			ImGui::Checkbox(" Aim Head", &SettingMenu2::AimHead);
						//			ImGui::Spacing();
						//			if (SettingMenu2::AimHead)
						//			{

						//			}
						//			else
						//			{
						//				SettingMenu2::AimBody = true;
						//				SettingMenu2::curraim = 1;
						//			}
						//		}
						//		else if (SettingMenu2::curraim == 1)
						//		{
						//			ImGui::Checkbox(" Aim Body", &SettingMenu2::AimBody);
						//			ImGui::Spacing();
						//			if (SettingMenu2::AimBody)
						//			{

						//			}
						//			else
						//			{
						//				SettingMenu2::AimHead = true;
						//				SettingMenu2::curraim = 0;
						//			}
						//		}


						//		ImGui::Checkbox(" Skip Knock", &SettingMenu2::knocked);
						//		//ImGui::Spacing();
						//		ImGui::SameLine();
						//		ImGui::Checkbox(" Skip Bots ", &SettingMenu2::SkipBots);
						//		ImGui::Spacing();

						//		ImGui::Checkbox(" Fov Based Tracking ", &SettingMenu2::fovcircle2);
						//		ImGui::Spacing();
						//		if (SettingMenu2::fovcircle2)
						//		{
						//			SettingMenu2::fovcircle = true;

						//			ImGui::Checkbox(" Show Fov ", &SettingMenu2::fovcircle);
						//			ImGui::Spacing();
						//			ImGui::SliderFloat("###fovFOVsize", &SettingMenu2::fovcircleredus, 1.0f, 2000.0f); ImGui::SameLine(); ImGui::Text("Fov Size");
						//			ImGui::SameLine();
						//			//ImGui::SetCursorPosX({ 365 });
						//			ImGui::ColorEdit4(" fovcolor", (float*)&Colors::fovcircleColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
						//			/*if (SettingMenu2::fovcircle)
						//			{
						//				ImGui::SliderFloat("###fovFOVsize", &SettingMenu2::fovcircleredus, 1.0f, 2000.0f);  			ImGui::SameLine(); 			ImGui::Text("Fov Size");
						//			}*/
						//		}
						//		else
						//		{
						//			SettingMenu2::fovcircle = false;
						//		}
						//		//Code End
						//		
						//	}
						//	ImGui::EndChild();
						//	ImGui::EndTabItem();
						//}
					}

					if (ImGui::BeginTabItem("Aimbot"))
					{
						if (ImGui::BeginChild("###aimbot", ImVec2(592, 310), true))
						{
							/*ImGui::Text(" !! Dangerous options are closed for now for security");*/

										//ImGui::SetCursorPos({ 30.f,30.0f });
										//ImGui::Checkbox("Aimbot", &SettingMenu2::Aimbot);
							ImGui::Spacing();
							ImGui::Checkbox(" Aimbot", &SettingMenu2::Aimbot);
							ImGui::SameLine();
							ImGui::Checkbox(" Marco 50m + Scope", &SettingMenu2::SniperMode);
							ImGui::Spacing();
							if (SettingMenu2::Aimbot)
							{
								SettingMenu2::fovcircle = true;

								if (ImGui::TreeNodeEx(" Aimbot Setting"))
								{
									ImGui::Indent();

									const char* Emu[] = { "Head", "Body" };
									//const char* Emu[] = { "Head", "Body", "Pelvis" };

									const char* combo_label = Emu[SettingMenu2::curraim];

									const char* enginetype[] = { "Mouse Event","Silent Aimbot" };

									const char* enginelabel = enginetype[SettingMenu2::engine];

									//ImGui::SetCursorPos({ 30.f,60.0f });
									ImGui::Checkbox(" Skip Knocked Enemies", &SettingMenu2::knocked);
									ImGui::Spacing();

									//ImGui::SetCursorPos({ 30.f,90.0f });
									ImGui::Bullet(); ImGui::Text(" Fov Circle Size : ");
									/*ImGui::Checkbox(" Show FOV Circle", &SettingMenu2::fovcircle);*/
									ImGui::Spacing();
									//ImGui::SameLine();
									ImGui::SliderFloat("###FovSizeAimbot", &SettingMenu2::fovcircleredus, 1.0f, 350.0f); ImGui::SameLine(); ImGui::Text("Fov Size");
									ImGui::SameLine();
									//ImGui::SetCursorPosX({ 365 });
									ImGui::ColorEdit4(" fovcolor", (float*)&ColorsMenu2::fovcircleColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
									//ImGui::Spacing();

									ImGui::Bullet(); ImGui::Text(" Aimbot Speed : ");
									//ImGui::Spacing();
									//ImGui::SameLine();
									ImGui::SliderFloat("                                                              Aimbot Speede", &SettingMenu2::Aimspeed, 6.0f, 30.0f);
									//ImGui::SliderFloat("Aimbot Speede", &SettingMenu2::Aimspeed, 6.0f, 30.0f);
									ImGui::Spacing();

									ImGui::Bullet(); ImGui::Text(" Aim Position : ");
									ImGui::SameLine();
									ImGui::SetNextItemWidth(180.0f);
									ImGui::SetCursorPosX({ 220 });
									if (ImGui::BeginCombo(" AimcPositon", combo_label, ImGuiComboFlags_HeightSmall))
									{
										for (int n = 0; n < IM_ARRAYSIZE(Emu); n++)
										{
											const bool is_selected = (SettingMenu2::curraim == n);
											if (ImGui::Selectable(Emu[n], is_selected))
												SettingMenu2::curraim = n;
											if (is_selected)
												ImGui::SetItemDefaultFocus();
										}
										ImGui::EndCombo();
									}
									ImGui::Spacing();


									ImGui::Bullet(); ImGui::Text(" Aimbot Engine : ");
									ImGui::SameLine();
									ImGui::SetNextItemWidth(180.0f);
									ImGui::SetCursorPosX({ 220 });
									if (ImGui::BeginCombo(" AimcEngine", enginelabel, ImGuiComboFlags_HeightSmall))
									{
										for (int n = 0; n < IM_ARRAYSIZE(enginetype); n++)
										{
											const bool is_selectedd = (item_current_Aim == n);
											if (ImGui::Selectable(enginetype[n], is_selectedd))
												SettingMenu2::engine = n;
											if (is_selectedd)
												ImGui::SetItemDefaultFocus();
										}

										ImGui::EndCombo();
									}
									ImGui::Spacing();

									ImGui::Bullet(); ImGui::Text(" Aimbot Hootkey : ");
									ImGui::SameLine();
									ImGui::SetNextItemWidth(200.0f);
									ImGui::SetCursorPosX({ 211 });
									ImGui::Hotkey("##AimbotKey ", &SettingMenu2::AimbotKey, ImVec2(189.0f, 28));
									ImGui::Spacing();


									/*ImGui::Text("Aimbot Enable/Disable Hootkey:");
									ImGui::SameLine();
									ImGui::SetNextItemWidth(180.0f);
									ImGui::Hotkey("###Enable ", &SettingMenu2::EnableKey, ImVec2(180.0f, 24));
									ImGui::Spacing();

									ImGui::Text("Aimbot Positon Switch Key:");
									ImGui::SameLine();
									ImGui::SetNextItemWidth(180.0f);
									ImGui::Hotkey("##PositionKey ", &SettingMenu2::PositionKey, ImVec2(180.0f, 24));
									ImGui::Spacing();*/

									

									ImGui::Unindent();
									ImGui::TreePop();
								}
								//ImGui::EndChild();
							}
							else
							{
								if (SettingMenu2::Legitrack == 1)
								{
									SettingMenu2::fovcircle = true;
								}
								else
								{
									SettingMenu2::fovcircle = false;
								}
							}

						}
						ImGui::EndChild();

						ImGui::EndTabItem();
					}
				}
				ImGui::EndTabBar();
			}

			if (Settings::Tab == 4)
			{
				/*if (ImGui::BeginTabBar("BeginTabBar"))
				{

				}
				ImGui::EndTabBar();*/
				if (ImGui::BeginTabBar("BeginTabBar"))
				{
					if (ImGui::BeginTabItem("Memory Danger"))
					{
						if (ImGui::BeginChild("###memoryDanger", ImVec2(592, 310), true))
						{
							ImGui::Spacing();
							/*ImGui::Bullet(); ImGui::Text(">>> Not Use This Danger Memory Option");
							ImGui::Bullet(); ImGui::Text(">>> Use Safe Memory Option");
							ImGui::Spacing();*/

							/*ImGui::Checkbox(" Anti Stream", &SettingMenu2::antiscreen);
							ImGui::Spacing();*/

							/*if (SettingMenu2::ScreenX)
							{
								SetWindowDisplayAffinity(DX11Window::hWindow, WDA_EXCLUDEFROMCAPTURE);
							}
							else
							{
								SetWindowDisplayAffinity(DX11Window::hWindow, WDA_NONE);
							}*/

							ImGui::Checkbox(" Car Fly", &SettingMenu2::carfly);
							ImGui::Spacing();

							ImGui::Checkbox(" Car Speed", &SettingMenu2::speedcar);
							ImGui::Spacing();

							ImGui::Checkbox(" Fast Run", &SettingMenu2::fastrun);
							ImGui::Spacing();

							ImGui::Checkbox(" Fast Run V2", &SettingMenu2::fackSetting1);
							ImGui::Spacing();

							ImGui::Checkbox(" No recoil", &SettingMenu2::recoil);
							ImGui::Spacing();

							ImGui::Checkbox(" No recoil 2", &SettingMenu2::recoil2);
							ImGui::Spacing();

							ImGui::Checkbox(" Force Tpp Mod", &SettingMenu2::fackSetting2);
							ImGui::Spacing();

							ImGui::Checkbox(" Super View", &SettingMenu2::SuperView);
							ImGui::Spacing();
							if (SettingMenu2::SuperView)
							{
								if (ImGui::TreeNodeEx(" Super View Setting"))
								{
									ImGui::Indent();

									ImGui::Text("SuperView Front Key");
									ImGui::SameLine();
									ImGui::Hotkey("##SuperView Front ", &SettingMenu2::SuperFront, ImVec2(180.0f, 24));

									ImGui::Text("SuperView Up Key");
									ImGui::SameLine();
									ImGui::Hotkey("##SuperView UP ", &SettingMenu2::SuperUp, ImVec2(180.0f, 24));


									ImGui::Text("SuperView Down Key");
									ImGui::SameLine();
									ImGui::Hotkey("##SuperView Down ", &SettingMenu2::SuperDown, ImVec2(180.0f, 24));

									ImGui::Text("SuperView Left Key");
									ImGui::SameLine();
									ImGui::Hotkey("##SuperView Left ", &SettingMenu2::SuperLeft, ImVec2(180.0f, 24));

									ImGui::Text("SuperView Right Key");
									ImGui::SameLine();
									ImGui::Hotkey("##SuperView Right ", &SettingMenu2::SuperRight, ImVec2(180.0f, 24));

									ImGui::Spacing();
									ImGui::Text("__________________________________________________________");
									ImGui::Text("[?]  If possible, do not change the button set here");
									ImGui::Text("[?]  But you can change it if you want");
									ImGui::SameLine();

									ImGui::Unindent();
									ImGui::TreePop();
								}
							}
						}
						ImGui::EndChild();
						ImGui::EndTabItem();
					}

					if (ImGui::BeginTabItem("Memory Safe"))
					{
						if (ImGui::BeginChild("###memorySafe", ImVec2(592, 310), true))
						{
							/*ImGui::Spacing();
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 0, 255));
							ImGui::Text("Coming Soon...");
							ImGui::PopStyleColor();*/
							ImGui::Spacing();
							ImGui::Checkbox(" Anti Stream", &SettingMenu2::antiscreen);
							ImGui::Spacing();
							//ImGui::SetCursorPos({ 200.f,65.0f });
							/*ImGui::Bullet(); ImGui::Text(" Safe Memory Option Coming Soon...");
							ImGui::Spacing();*/

							ImGui::Checkbox(" iPad View Super", &SettingMenu2::ipadview);
							if (SettingMenu2::ipadview)
							{
								/*ImGui::Text("iPAD View Value");
								ImGui::SameLine();
								ImGui::SliderInt("###7754334", &SettingMenu2::IPADSIZE, 1, 300);*/

								ImGui::PushItemWidth(250);
								ImGui::SameLine();
								if (ImGui::SliderInt("##IpadSize", &Setting::IpadViewValue, 360.0f, 200.0f))
								{
									
								}
							}

							ImGui::Spacing();
							ImGui::Checkbox(" X Effect", &SettingMenu2::MagicX);
							ImGui::Spacing();
							/*ImGui::Spacing();

							ImGui::Checkbox(" Unlock 90FPS + UltraHD", &SettingMenu2::NINEFPS);
							if (SettingMenu2::NINEFPS)
							{
								ImGui::Text("Unlock 90FPS + UltraHD Activated");
							}*/
						}
						ImGui::EndChild();
						ImGui::EndTabItem();
					}
				}
				ImGui::EndTabBar();
			}

			if (Settings::Tab == 5)
			{
				/*if (ImGui::BeginTabBar("BeginTabBar"))
				{

				}
				ImGui::EndTabBar();*/
				//ImGui::Spacing();
				if (ImGui::Button("Save Config", { 292.f,30.f }))
				{
					WriteConfigurate("C:\\Windows\\ESPMAAZ-Setting.ini");
					//WriteConfigurate("C:\\Windows\\ESPMAAZ-Setting.ini");
				}
				ImGui::SameLine();
				if (ImGui::Button("Reset Config", { 292.f,30.f }))
				{
					//system_no_output1("attrib +s +h C:\\Windows\\ESPMAAZ-Setting.bin");//hide
					system_no_output1("attrib -s -h C:\\Windows\\ESPMAAZ-Setting.bin");//show
					Sleep(100);
					HRESULT ESPMAAZHK_Setting = URLDownloadToFile(NULL, _T("C:\\Windows\\ESPMAAZ-Setting.bin"), _T("C:\\Windows\\ESPMAAZ-Setting.ini"), 0, NULL);
					LoadConfiggg("C:\\Windows\\ESPMAAZ-Setting.ini");
					Sleep(100);
					system_no_output1("attrib +s +h C:\\Windows\\ESPMAAZ-Setting.bin");//hide
					//system_no_output1("attrib -s -h C:\\Windows\\ESPMAAZ-Setting.bin");//show
					ImGui::InsertNotification({ ImGuiToastType_Success, 3000, " Reset Setting is Success! %s", "" });


				}
				//ImGui::Spacing();

				if (ImGui::Button("Load Config", { 292.f,30.f }))
				{
					/*if (FileExist(SettingMenu2::PathSetting))
					{
						LoadConfiggg(SettingMenu2::PathSetting);
					}*/
					if (FileExist("C:\\Windows\\ESPMAAZ-Setting.ini"))
					{
						LoadConfiggg("C:\\Windows\\ESPMAAZ-Setting.ini");
						ImGui::InsertNotification({ ImGuiToastType_Success, 3000, " Load Setting is Success! %s", "" });
					}
					else
					{
						ImGui::InsertNotification({ ImGuiToastType_Warning, 3000, " Your Config not saved yet! %s", "" });
					}
				}
				ImGui::SameLine();
				if (ImGui::Button("Unload Exit Hack", { 292.f,30.f }))
				{
					/*exit(0);*/
					unload = true;
				}
				//if (ImGui::Button("Delete Config Setting", { 292.f,30.f }))
				//{
				//	remove("C:\\Windows\\ESPMAAZ_PVTHAX_Setting.ini");//resat esp
				//	//MessageBox(NULL, L"Process Complete The Hack Automatically Close` Now Re-Open The Hack", L"Reset Esp Setting",NTE_OP_OK);
				//	//HRESULT HorizonHK_Setting = URLDownloadToFile(NULL, _T("https://dl.dropboxusercontent.com/s/kzhthfhhgr69y7g/HorizonHK_Setting.ini"), _T("C:\\Windows\\HorizonHK_Setting.ini"), 0, NULL);
				//	/*
				//	if (FileExist(SettingMenu2::PathSetting))
				//	{
				//		LoadSetting(SettingMenu2::PathSetting);
				//	}*/

				//}
				
				

				//ImGui::Indent();
				//ImGui::SetCursorPosX({ 150 });
				ImGui::Spacing();
				ImGui::Text("Adreess Delay");
				ImGui::SameLine();
				ImGui::PushItemWidth(220);
				ImGui::SliderInt("### Adreess Delay ", &Setting::AdreessGetterDelay, 0.0f, 5000.0f);
				ImGui::SameLine();
				ImGui::Text("Hack Performance");
				ImGui::SameLine();
				ImGui::PushItemWidth(220);
				ImGui::SliderInt("### HackPerformanceUpdate", &Setting::EspThreadDelay, 100, 0);
				
				ImGui::Spacing();
				ImGui::Checkbox("Show Game Info", &Setting::gameinfo);
				ImGui::SameLine();
				ImGui::Checkbox("Show My Info", &Setting::MyInfo);
				ImGui::SameLine();
				ImGui::Checkbox("Anti Screen", &Setting::AntiStreamAndScreenShot);
				if (Setting::AntiStreamAndScreenShot)
				{
					SetWindowDisplayAffinity(DX11Window::hWindow, WDA_EXCLUDEFROMCAPTURE);
					ImGui::SameLine();
					ImGui::Bullet(); ImGui::TextColored(to_vec4(0, 255, 0, 255), "AntiScreen is ON");
				}
				else
				{
					SetWindowDisplayAffinity(DX11Window::hWindow, WDA_NONE);
				}

				ImGui::Spacing();
				ImGui::Checkbox(" Move And Customise Menu", &Setting::MoveAndCustomiseMenu); ImGui::SameLine(); ImGui::Checkbox(" Menu Style 1", &styleM1); ImGui::SameLine(); ImGui::Checkbox(" M Style 2", &styleM2); ImGui::SameLine(); ImGui::Checkbox(" M Style 3", &styleM3); ImGui::SameLine(); ImGui::Checkbox(" M Style 4", &styleM4);
				
				ImGui::Spacing();
				ImGui::SetCursorPosX({ 0 });
				if (ImGui::BeginChild("####Setting------", ImVec2(592, 1), true))
				{

				}
				ImGui::EndChild();

				ImGui::Spacing();
				ImGui::Text("Pubg v3.2"); ImGui::SameLine(); ImGui::TextColored(to_vec4(0, 255, 0, 255), "Supports");
				ImGui::SameLine();
				ImGui::Text(" /    Hack Version 3.2"); /*ImGui::SameLine(); ImGui::TextColored(to_vec4(0, 255, 0, 255), "2.0.1");*/
				ImGui::SameLine();
				ImGui::Text(" /    Developed By ESPMAAZ"); /*ImGui::SameLine(); ImGui::TextColored(to_vec4(255, 0, 0, 255), "ESPMAAZ");*/

				ImGui::Spacing();
				ImGui::PushFont(DX11::ImGui_DX11::LanguageStyle);
				const char* Stylee[] = { ICON_FA_LANGUAGE"  English", ICON_FA_LANGUAGE"  Arabic Coming Soon" };
				//const char* Stylee[] = { ICON_FA_LANGUAGE"  ?????????? ???", ICON_FA_LANGUAGE"  ??? ??????" };
				static int Current_Style = 0;
				const char* combo_label = Stylee[Current_Style];

				ImGui::PushItemWidth(592);
				if (ImGui::BeginCombo(" Language Style1", combo_label, ImGuiComboFlags_None))
				{
					for (int n = 0; n < IM_ARRAYSIZE(Stylee); n++)
					{
						const bool is_selected = (Current_Style == n);
						if (ImGui::Selectable(Stylee[n], is_selected))
							Current_Style = n;
						if (is_selected)
							ImGui::SetItemDefaultFocus();
					}
					if (Current_Style == 0)
					{
						//Setting::gameinfo = true;
					}

					else if (Current_Style == 1)
					{
						//Setting::gameinfo = false;
					}
					ImGui::EndCombo();
				}
				ImGui::PopFont();

			}

			if (Settings::Tab == 6)
			{
				/*if (ImGui::BeginTabBar("BeginTabBar"))
				{

				}
				ImGui::EndTabBar();*/

				ImGui::SetCursorPos({ 200.f,40.0f });
				ImGui::Text("Some Basic Info :-");
				ImGui::Spacing();
				ImGui::Spacing();
				ImGui::SetCursorPos({ 200.f,65.0f });
				ImGui::Bullet(); ImGui::Text("Made With Love For The People.");
				ImGui::Spacing();
				ImGui::Spacing();
				ImGui::SetCursorPos({ 200.f,90.0f });
				ImGui::Bullet(); ImGui::Text("Hack average (86.7 FPS)");
				ImGui::Spacing();
				ImGui::Spacing();
				ImGui::SetCursorPos({ 200.f,115.0f });
				ImGui::Text("How To Play Safe :-");
				ImGui::Spacing();
				ImGui::Spacing();
				ImGui::SetCursorPos({ 200.f,140.0f });
				ImGui::Bullet();    ImGui::Text("Do Not Do Impossible Kills.");
				ImGui::Spacing();
				ImGui::Spacing();
				ImGui::SetCursorPos({ 200.f,165.0f });
				ImGui::Bullet();    ImGui::Text("Always Kill 150+ Meter player With Sniper.");
				ImGui::Spacing();
				ImGui::Spacing();
				ImGui::SetCursorPos({ 200.f,190.0f });
				ImGui::Bullet();    ImGui::Text("Don't Let Al Think You Are Hacker.");
				ImGui::Spacing();
				ImGui::Spacing();
				ImGui::SetCursorPos({ 200.f,215.0f });
				ImGui::Text("How To Play Safe With Bullet Track :-");
				ImGui::Spacing();
				ImGui::Spacing();
				ImGui::SetCursorPos({ 200.f,240.0f });
				ImGui::Bullet(); ImGui::Text("Use Aim Based tracking.");
				ImGui::Spacing();
				ImGui::Spacing();
				ImGui::SetCursorPos({ 200.f,265.0f });
				ImGui::Bullet(); ImGui::Text("Do Not Do More Head Kills.");
				ImGui::Spacing();
				ImGui::Spacing();
				ImGui::SetCursorPos({ 200.f,290.0f });
				ImGui::Bullet();    ImGui::Text("Do Not Brutally Kill Bots.");
				ImGui::Spacing();
				ImGui::Spacing();
				ImGui::SetCursorPos({ 200.f,315.0f });
				ImGui::Bullet(); ImGui::Text("Avoid Killing If Player is Not Visible.");
				ImGui::Spacing();
				ImGui::Spacing();
				ImGui::SetCursorPos({ 200.f,340.0f });
				ImGui::Bullet();    ImGui::Text("Avoid Aiming If Player is Not Spoted.");
			}


		}
	}
	ImGui::End();
}

VOID Esp::EspThread()
{
	VECTOR3 Screen;
	INT Distance = 0;
	INT EnemyCount = 0;
	VECTOR3 HeadPos;
	VECTOR2 Head;
	VECTOR2 Chest;
	VECTOR2 Pelvis;
	VECTOR2 lSholder;
	VECTOR2 rSholder;
	VECTOR2 lElbow;
	VECTOR2 rElbow;
	VECTOR2 lWrist;
	VECTOR2 rWrist;
	VECTOR2 lThigh;
	VECTOR2 rThigh;
	VECTOR2 lKnee;
	VECTOR2 rKnee;
	VECTOR2 lAnkle;
	VECTOR2 rAnkle;
	std::string temp = "";
	std::string dist = "";
	string weapon = "";
	string Text = "ssssssss";
	vector<AActor> TempAActorList = {};
	vector<Deadbox> TempBoxesList = {};
	vector<Vehicle> TempVehicalList = {};
	vector<Item> TempItemList = {};
	vector<BombAlert> TempBombAlertList = {};

	static char str0[25] = "";
	std::string key;
	std::string Ques = "";
	std::string licenseKey = "";
	std::ifstream InFile(("C:\\Windows\\?ESPMAAZ_HK.lic"), std::ios::in);
	std::getline(InFile, licenseKey);
	strcpy_s(str1, licenseKey.c_str());

	LoadConfig("C:\\Windows\\ESPMAAZ_HK.lic");

	if (FileExist("C:\\Windows\\ESPMAAZ-Setting.ini"))
	{
		if (login == true)
		{
			LoadConfiggg("C:\\Windows\\ESPMAAZ-Setting.ini");
			ImGui::InsertNotification({ ImGuiToastType_Success, 7000, " Load Setting is Success! %s", "" });
		}
	}
	else
	{
		if (login == true)
		{
			ImGui::InsertNotification({ ImGuiToastType_Warning, 7000, " Your Config not saved yet! %s", "" });
		}
	}

	FirewallBlock();//ADB reset for game not opening with bypass

	//Login_Page_Bypass_CheckingCode1();////Login_Page_ON/OFF_Checking...From//www.dropbox.com
	//Login_Page_Bypass();//Login_Page_OFF Directly


	Snowflake::CreateSnowFlakes(snow, SNOW_LIMIT, 1.f, 5.f, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, Snowflake::vec3(0.f, 0.010f), IM_COL32(255, 255, 255, 180));
	POINT mouse;
	RECT rc = { 0 };

	while (true)
	{

		try
		{

			RECT Rect;
			GetWindowRect(Game::hWindow, &Rect);
			DX11Window::Left = Rect.left;
			DX11Window::Top = Rect.top;
			DX11Window::Width = Rect.right - Rect.left;
			DX11Window::Height = Rect.bottom - Rect.top;
			MoveWindow(DX11Window::hWindow, DX11Window::Left, DX11Window::Top, DX11Window::Width, DX11Window::Height, true);

			ImGui_ImplDX9_NewFrame();
			ImGui_ImplWin32_NewFrame();
			ImGui::NewFrame();
			{

				imgui_notify_Start();

				g_Discord->Initialize();
				if (login == false)
				{
					g_Discord->Update1();
				}
				else if (login == true)
				{
					g_Discord->Update();
				}

				/*time_t rawtime = mktime(&KeyAuthApp.user_data.expiry);
				struct tm* timeinfo;
				timeinfo = localtime(&rawtime);*/
				if (Setting::ShowMenu)
				{
					if (login == true)
					{
						if (Setting::Snowflake)
						{
							GetCursorPos(&mouse);
							// render this before anything else so it is the background
							Snowflake::Update(snow, Snowflake::vec3(mouse.x, mouse.y)/*mouse x and y*/, Snowflake::vec3(rc.left, rc.top)/*hWnd x and y positions*/); // you can change a few things inside the update function
							//Snowflake::Update(snow, Snowflake::vec3(mouse.x, mouse.y), Snowflake::vec3(DX11Window::Width, DX11Window::Height));
						}
					}

					if (!login)
					{
						static auto Flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
						static auto Flags1 = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;

						ImGuiIO& Io = ImGui::GetIO();
						ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.5f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.5f));
						ImGui::SetNextWindowSize(ImVec2(350.0f, 550.0f));

						/*char pcname[100];
						std::string getusername = getenv("username");
						sprintf_s(pcname, "-> Welcome %s To ESP MAAZ-PVT NEW LOOK <-", getusername.c_str());
						if (ImGui::Begin(pcname, 0, Flags1))*/
						if (ImGui::Begin("|!! ESP MAAZ PVT CHEAT !!|", 0, Flags))
						{
							ImGui::Image((void*)DX11::Image_BackgroundLogin, ImVec2(340, 520));

							ImGuiIO& Io = ImGui::GetIO();
							ImGuiStyle* style = &ImGui::GetStyle();
							style->WindowTitleAlign = ImVec2(0.5, 0.5);

							style->WindowPadding = ImVec2(4, 9);
							style->WindowRounding = 1.0f; //= 10.0f;

							style->Colors[ImGuiCol_FrameBg] = ImColor(0, 110, 255, 0);//CheckMark and Roll Bag
							style->Colors[ImGuiCol_FrameBgHovered] = ImColor(0, 110, 255, 0);
							style->Colors[ImGuiCol_FrameBgActive] = ImColor(0, 110, 255, 0);

							style->Colors[ImGuiCol_Button] = ImColor(255, 0, 0, 255);
							style->Colors[ImGuiCol_ButtonHovered] = ImColor(230, 0, 0, 255);
							style->Colors[ImGuiCol_ButtonActive] = ImColor(210, 0, 0, 255);

							style->Colors[ImGuiCol_WindowBg] = ImColor(15, 13, 18, 0);
							style->Colors[ImGuiCol_Border] = ImColor(255, 255, 255, 0);

							style->Colors[ImGuiCol_Text] = ImVec4(255, 255, 255, 255);

							ImGui::SetCursorPos({ 33,352 });
							//ImGui::InputText("###Key", str1, IM_ARRAYSIZE(str1));
							ImGui::SetNextItemWidth(250);
							//ImGui::InputTextWithHint(("###Key"), "Enter Your License Key", str1, IM_ARRAYSIZE(str1));
							ImGui::InputTextWithHint(("###Key"), "Enter Your License Key", str1, IM_ARRAYSIZE(str1), (hideKey) ? ImGuiInputTextFlags_Password : ImGuiInputTextFlags_None);
							ImGui::SameLine();
							//ImGui::SetCursorPosX({ 83 });
							ImGui::SetCursorPos({ 290,350 });
							if (ImGui::Button(ICON_FA_EYE "", { 30.0f,27.0f }))
							{
								hideKey = !hideKey;
							}
							/*if (hideKey)
							{

							}*/

							ImGui::Spacing();

							//Login Page............................................................................................................
							ImGui::SetCursorPos({ 28,390 });
							if (ImGui::Button(" Login ", { 290.0f,35.0f }))
							{
								//Login_Bypass = true;
								main_GetKeyAndOnlineLogin_imgui();
							}

							ImGui::SetCursorPos({ 28,430 });
							if (ImGui::Button(" Get Key ", { 290.0f,35.0f }))
							{
								//AddsBypass = true;
								////BrowserName_CheckingGetKey();
								main_GetKey_Generate_Offline_Online();
								//main_GetKey_Generate_Online_SellerApi();
							}


							//ImGui::SetCursorPos({ 60,430 });
							//ImGui::Checkbox(" Low Cpu User", &Setting1::LowCpu);
							//ImGui::SameLine();
							//ImGui::Checkbox(" HIgh Cpu User", &Setting1::HighCpu);

							ImGuiStyle* style1 = &ImGui::GetStyle();
							style1->Colors[ImGuiCol_Button] = ImColor(255, 255, 255, 0);
							style1->Colors[ImGuiCol_ButtonHovered] = ImColor(230, 255, 255, 10);
							style1->Colors[ImGuiCol_ButtonActive] = ImColor(210, 255, 255, 20);
							style1->Colors[ImGuiCol_Text] = ImVec4(255, 255, 255, 255);

							ImGui::SetCursorPos({ 30,480 });
							if (ImGui::Button(" Discord ", { 70.0f,35.0f }))
							{
								ShellExecute(NULL, L"open", L"https://discord.gg/PCkXvqpsxD", NULL, NULL, SW_SHOWNORMAL);
							}

							ImGuiStyle* style2 = &ImGui::GetStyle();
							style2->Colors[ImGuiCol_Button] = ImColor(255, 255, 255, 0);
							style2->Colors[ImGuiCol_ButtonHovered] = ImColor(230, 255, 255, 10);
							style2->Colors[ImGuiCol_ButtonActive] = ImColor(210, 255, 255, 20);
							style2->Colors[ImGuiCol_Text] = ImVec4(255, 0, 0, 255);

							ImGui::SetCursorPos({ 140,480 });
							if (ImGui::Button(" Buy Key ", { 70.0f,35.0f }))
							{
								ShellExecute(NULL, L"open", L"https://t.me/md01alvi", NULL, NULL, SW_SHOWNORMAL);
							}

							ImGuiStyle* style3 = &ImGui::GetStyle();
							style3->Colors[ImGuiCol_Button] = ImColor(255, 255, 255, 0);
							style3->Colors[ImGuiCol_ButtonHovered] = ImColor(230, 255, 255, 10);
							style3->Colors[ImGuiCol_ButtonActive] = ImColor(210, 255, 255, 20);
							style3->Colors[ImGuiCol_Text] = ImVec4(0, 255, 0, 255);

							ImGui::SetCursorPos({ 250,480 });
							if (ImGui::Button(" Close ", { 70.0f,35.0f }))
							{
								Memory::RestoreHook();

								Sleep(100);
								//ShellExecute(0, L"open", L"C:\\Windows\\sc_stop_driver.bat", NULL, 0, SW_HIDE);
								ExitProcess(1);
							}

							if (SaveUsers)
							{
								//WriteConfig("C:\\Windows\\ESPMAAZ_HK.lic", str1, true);
							}
							else
							{
								//WriteConfig("C:\\Windows\\ESPMAAZ_HK.lic", str1, false);
							}
							ImGui::End();
						}

					}

					if (login && styleM1)
					{
						if (styleM1)
						{
							styleM2 = false;
							styleM3 = false;
							styleM4 = false;
						}
						
						MenuStyle1();
						CustomImGUIStyle1();
					}

					if (login && styleM2)
					{
						if (styleM2)
						{
							styleM1 = false;
							styleM3 = false;
							styleM4 = false;
						}
						
						static auto Flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
						static auto Flags1 = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;

						ImGui::SetNextWindowSize(ImVec2(610.0f, 410.0f));

						char pcname[100];
						std::string getusername = getenv("username");
						sprintf_s(pcname, "-> Welcome %s To ESPMAAZ PVT HAX [ v2.5.0 ] <-", getusername.c_str());
						if (ImGui::Begin(pcname, 0, Flags1))

							//if (ImGui::Begin("-> Welcome User To ESPMAAZ-VIP [ v2.0 ] <-", 0, Flags))
							//ImGui::Begin(">> Hi User Welcome to (ESPMAAZ VIP HAK - IS FREE) v2.0 <<", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | (ImGuiStyleVar_ScrollbarSize * 2));
							//ImGui::Begin(">> Hi ESPMAAZ Welcome to (OFF VIP) v2.0 <<", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | (ImGuiStyleVar_ScrollbarSize * 2));
							//ImGui::Begin(">> Hi ESPMAAZ Welcome to (SubhanAllah Private Hack) v2.3 <<", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | (ImGuiStyleVar_ScrollbarSize * 2));
							//ImGui::Begin("Insert To (SubhanAllah Private Hack) | v2.3", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | (ImGuiStyleVar_ScrollbarSize * 2));
						{
							//ImGui::SetCursorPos({ 5,00 });
							//ImGui::Image((PVOID)Image_MainMenuBag, ImVec2(600, 410));
							//ImGui::SetCursorPos({ 0.f,37.0f });
							////ImGui::SetNextWindowBgAlpha(0.60f);//// Problam Shadow

							//ImGui::SetCursorPos({ 190, 5 });
							//ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 255, 255));
							//ImGui::Text(" ");
							////ImGui::Text("-> Welcome User To ESPMAAZ-VIP [ v2.0 ] <-");
							//ImGui::Spacing();
							//ImGui::Spacing();
							//ImGui::Spacing();
							//ImGui::PopStyleColor();

							////////ImGuiStyle* style = &ImGui::GetStyle();

							//////////style->WindowBorderSize = 0;
							////////style->WindowTitleAlign = ImVec2(0.5, 0.5);
							/////////*ImGuiCol_ScrollbarBg,
							////////	ImGuiCol_ScrollbarGrab,
							////////	ImGuiCol_ScrollbarGrabHovered,
							////////	ImGuiCol_ScrollbarGrabActive,*/
							////////ImGuiIO& Io = ImGui::GetIO();

							////////style->FramePadding = ImVec2(8, 6);
							/////////*style->Colors[ImGuiCol_Button] = ImColor(31, 30, 31, 200);
							////////style->Colors[ImGuiCol_ButtonActive] = ImColor(31, 30, 31, 255);*/
							////////style->Colors[ImGuiCol_Button] = ImColor(0, 100, 0, 200);
							////////style->Colors[ImGuiCol_ButtonActive] = ImColor(0, 80, 0, 150);

							/////////*style->Colors[ImGuiCol_ButtonHovered] = ImColor(41, 40, 41, 255);
							////////style->Colors[ImGuiCol_WindowBg] = ImColor(15, 13, 18, 200);*/
							////////style->Colors[ImGuiCol_ButtonHovered] = ImColor(0, 110, 0, 150);
							////////style->Colors[ImGuiCol_WindowBg] = ImColor(0, 0, 0, 200);
							////////style->Colors[ImGuiCol_Border] = ImColor(0, 80, 0, 200);

							////////style->Colors[ImGuiCol_Separator] = ImColor(0, 255, 0, 60);
							////////style->Colors[ImGuiCol_SeparatorHovered] = ImColor(0, 255, 0, 80);
							////////style->Colors[ImGuiCol_SeparatorActive] = ImColor(0, 255, 0, 100);

							////////style->Colors[ImGuiCol_Header] = ImColor(0, 0, 0, 0);
							////////style->Colors[ImGuiCol_HeaderActive] = ImColor(0, 0, 0, 0);
							////////style->Colors[ImGuiCol_HeaderHovered] = ImColor(46, 46, 46, 255);

							MenuStyle2();
						}
						ImGui::End();
						CustomImGUIStyle2();
					}
					
					if (login && styleM3)
					{
						if (styleM3)
						{
							styleM1 = false;
							styleM2 = false;
							styleM4 = false;
						}						
						
						MenuStyle3();
						CustomImGUIStyle3();
					}

					if (login && styleM4)
					{
						if (styleM4)
						{
							styleM1 = false;
							styleM2 = false;
							styleM3 = false;
						}

						

						MenuStyle4();
					}
					
				}

				if (login)
				{
					

					////Overlay Transparency Color
					////ImVec4 clear_colo = ImVec4(0.0f, 0.0f, 0.0f, 0.400f);
					//ImVec4 clear_colo = ImVec4(0.0f, 0.0f, 0.0f, Setting::overlaycolor);
					//const float clear_color_with_alphaa[4] = { clear_colo.x * clear_colo.w, clear_colo.y * clear_colo.w, clear_colo.z * clear_colo.w, clear_colo.w };
					//DX11::pImmediateContext->ClearRenderTargetView(DX11::pRenderTargetView, clear_color_with_alphaa);//1212

					if (unload)
					{
						ImGuiIO& Io = ImGui::GetIO();

						//ImGui::SetNextWindowSize(ImVec2(400.0f, 115.0f));
						ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.5f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.5f));
						ImGui::SetNextWindowSize(ImVec2(250.0f, 100.0f));
						ImGui::SetNextWindowFocus();  // Ensure this window gets focus and stays on top
						if (ImGui::Begin("####11", 0, Flags2))
						{
							imguipp::CenterText("Are you sure?", 0, 0);
							if (ImGui::Button("OK", { 115.f,25.f }))
							{
								Memory::RestoreHook();

								Sleep(100);
								//ShellExecute(0, L"open", L"C:\\Windows\\sc_stop_driver.bat", NULL, 0, SW_HIDE);
								ExitProcess(1);
							}
							ImGui::SameLine();
							if (ImGui::Button("Cancel", { 115.f,25.f }))
							{
								unload = false;
								ImGui::InsertNotification({ ImGuiToastType_Info, 3000, " You canceled, maybe you changed your mind. %s", " " });

								/*Utility::ChangeClickability(FALSE, DX11Window::hWindow);
								DX11Window::IsClickable = !DX11Window::IsClickable;
								Setting::ShowMenu = !Setting::ShowMenu;

								MessageBox(NULL, L"You canceled, maybe you changed your mind.", L"Info Code 1", MB_OK | MB_ICONINFORMATION | MB_TOPMOST);

								Utility::ChangeClickability(TRUE, DX11Window::hWindow);
								DX11Window::IsClickable = !DX11Window::IsClickable;
								Setting::ShowMenu = !Setting::ShowMenu;*/
							}

							ImGui::End();
						}
					}

					////GetAsyncKeyState
					{//GetAsyncKeyState
						
						if (GetAsyncKeyState(VK_LCONTROL) & 1)
						{
							Setting::CRPTPressed = !Setting::CRPTPressed;
						}
						if (GetAsyncKeyState(VK_F1) & 1)
						{
							Setting::AimbotKey = !Setting::AimbotKey;
						}
						/*if (Setting::MagicBullet)
						{

						}*/
						if (GetAsyncKeyState(VK_F2) & 1)
						{
							Setting::MagicBullet = !Setting::MagicBullet;
							Setting::MagicBulletticked = !Setting::MagicBulletticked;

							if (Setting::MagicBullet || Setting::MagicBulletticked)
							{
								ImGui::InsertNotification({ ImGuiToastType_Success, 3000, " MagicBullet is ON! %s", " " });

							}
							else
							{
								ImGui::InsertNotification({ ImGuiToastType_Error, 3000, " MagicBullet is OFF! %s", " " });

							}

						}
						if (GetAsyncKeyState(VK_F3) & 1)
						{
							if (Setting1::style1 == true)
							{
								Setting1::style2 = true;
								Setting1::style1 = false;
							}
							else if (Setting1::style2 == true)
							{
								Setting1::style3 = true;
								Setting1::style2 = false;

							}
							else if (Setting1::style3 == true)
							{
								Setting1::style1 = true;
								Setting1::style3 = false;

							}
							/*else if (Setting1::style3 == true)
							{
								Setting1::style1 = true;
							}*/
							

							/*Setting1::style1 = !Setting1::style1;
							Setting1::style3 = !Setting1::style3;*/
						}
						if (GetAsyncKeyState(VK_F4) & 1)
						{
							Setting::SkipKnocked = !Setting::SkipKnocked; Setting::knocked = !Setting::knocked;
						}
						if (GetAsyncKeyState(VK_F5) & 1)
						{
							Setting::fightmode = !Setting::fightmode;
							/*Setting::deadbox = !Setting::deadbox;
							Setting::Vehicle = !Setting::Vehicle;
							Setting::allitemss = !Setting::allitemss;*/

						}
						if (GetAsyncKeyState(VK_F6) & 1)
						{
							//Setting::curraim = !Setting::curraim;
							if (Setting::curraim == 0)
							{
								Setting::curraim++;
							}
							else
							{
								if (Setting::curraim == 1)
								{
									Setting::curraim = 2;
								}
								else if (Setting::curraim == 2)
								{
									Setting::curraim = 3;
								}
								else if (Setting::curraim == 3)
								{
									Setting::curraim = 0;
								}
							}
						}
						if (GetAsyncKeyState(VK_F7) & 1)
						{
							Setting::allitemss = !Setting::allitemss;
						}
						if (GetAsyncKeyState(VK_F8) & 1)
						{
							Setting::Vehicle = !Setting::Vehicle;
						}
						if (GetAsyncKeyState(Setting::curraimKey) & 1)//T
						{
							if (Setting::curraim == 0)
							{
								Setting::curraim++;
							}
							else
							{
								if (Setting::curraim == 1) {
									Setting::curraim = 2;
								}
								else if (Setting::curraim == 2) {
									Setting::curraim = 3;
								}
								else if (Setting::curraim == 3) {
									Setting::curraim = 0;
								}
							}
						}
						/*if (GetAsyncKeyState(VK_HOME) & 0x1)
						{

							Setting::ShowSideMenu = !Setting::ShowSideMenu;
						}*/
						if (GetAsyncKeyState(VK_F10) & 1)
						{
							Setting::UselessShow = !Setting::UselessShow;
							//Setting::IpadView = !Setting::IpadView;
						}
						if (GetAsyncKeyState(VK_F9) & 1)
						{
							//Setting::UselessShow = !Setting::UselessShow;
							Setting::IpadView = !Setting::IpadView;
						}
						if (GetAsyncKeyState(VK_F11) & 1)
						{
							Setting::HapSizeMenu = !Setting::HapSizeMenu; Setting::FullSizeMenu = !Setting::FullSizeMenu;
						}

					}

					bool IsWeaponFiring = Utility::ReadMemoryEx<BOOL>(Data::LocalPlayer + 0x1074);//0xfb8//bool bIsWeaponFiring;//(ByteOffset: 0, ByteMask: 1, FieldMask: 255)[Offset:
					if (IsWeaponFiring == true) {
						Setting::autocurraim++;
						if (Setting::autocurraim == 4)
							Setting::autocurraim = 0;

					}

					if (Setting::ShowSideMenu)
					{
						DrawSideMenu();
					}
					if (Setting::IpadView)
					{
						////VNG
						//WriteUE4Float1(0x60B8948, Setting::IpadViewValue);
						////GL
						WriteUE4Float1(0x6081618, Setting::IpadViewValue);
					}
					else
					{
						////VNG
						//WriteUE4Float1(0x60B8948, 360.0f);
						////GL
						WriteUE4Float1(0x6081618, 360.0f);
					}

					ViewMatrix = Utility::ReadMemoryEx<D3DMATRIX>(Utility::ReadMemoryEx<DWORD>(Utility::ReadMemoryEx<DWORD>(Data::ViewMatrixBase) + 0x20) + 0x200);
					Data::CameraCache = Utility::ReadMemoryEx<CameraCacheEntry>(Data::PlayerCameraManager + Offset::PlayerCameraManager1::CameraCache);
					TempAActorList.clear();
					TempAActorList = Data::AActorList;
					DWORD MeshAddv1 = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::Mesh);
					DWORD BodyAddv1 = MeshAddv1 + Offset::BodyAddv;
					DWORD BoneAddv1 = Utility::ReadMemoryEx<DWORD>(MeshAddv1 + Offset::MinLOD) + 48;


					Data::lOCALPLAYERHEAD = Algorithm::GetBoneWorldPosition(BodyAddv1, BoneAddv1 + 5 * 48);
					Data::lOCALPLAYERPosotion = Utility::ReadMemoryEx<VECTOR3>(Utility::ReadMemoryEx<DWORD>(Data::LocalPlayerAddr + Offset::RootComponent) + Offset::Position);
					if (Data::AActorList.size() != 0)
					{

						for (AActor& AActor : Data::AActorList)
						{
							int _dist;
							AActor.Position = Utility::ReadMemoryEx<VECTOR3>(Utility::ReadMemoryEx<DWORD>(AActor.Address + Offset::RootComponent) + Offset::Position);

							teamids = AActor.TeamId;
							col = ImColor(teamids, teamids, teamids, 255);

							linescolors = ImVec4(sin(5.f * teamids + 0.f) * 127 + 128 / 255.0f, sin(5.f * teamids + ((2.f * 3.14159265358979323846) / 3)) * 127 + 128 / 255.0f, sin(5.f * teamids + ((4.f * 3.14159265358979323846) / 3)) * 127 + 128 / 255.0f, 255 / 255.0f);
							//linescolors = Colors::playerline;
							bonescolors = Colors::playerbone;
							fullboxcolor = Colors::playerbox;
							cornerboxcolor = Colors::playercorner;
							if (!Algorithm::WorldToScreenPlayer(Data::lOCALPLAYERPosotion, AActor.Position, Screen, &_dist, ViewMatrix)) continue;

							if (SettingMenu2::TeamIdLine)
							{
								////400 Teams Colors
								switch (teamid = teamids)
								{
#pragma region TeamIdLine
								/*case 0:
									linescolors = { 1.000f, 0.033f, 0.129f, 0.500f };
									break;
								case 1:
									linescolors = { 1.000f, 0.033f, 0.129f, 0.500f };
									break;
								case 2:
									linescolors = { 1.000f, 1.000f, 0.000f, 0.500f };
									break;
								case 3:
									linescolors = { 0.866f, 0.128f, 0.081f, 0.500f };
									break;
								case 4:
									linescolors = { 0.844f, 0.066f, 1.000f, 0.500f };
									break;
								case 5:
									linescolors = { 0.737f, 1.000f, 0.000f, 0.500f };
									break;
								case 6:
									linescolors = { 0.000f, 1.000f, 0.964f, 0.500f };
									break;
								case 7:
									linescolors = { 0.610f, 0.190f, 1.000f, 0.500f };
									break;
								case 8:
									linescolors = { 1.000f, 0.100f, 0.401f, 0.500f };
									break;
								case 9:
									linescolors = { 0.610f, 0.190f, 1.000f, 0.500f };
									break;
								case 10:
									linescolors = { 0.033f, 0.696f, 1.000f, 0.500f };
									break;
								case 11:
									linescolors = { 0.033f, 1.000f, 0.952f, 0.500f };
									break;
								case 12:
									linescolors = { 0.033f, 1.000f, 0.535f, 0.500f };
									break;
								case 13:
									linescolors = { 0.044f, 1.000f, 0.033f, 0.500f };
									break;
								case 14:
									linescolors = { 0.428f, 1.000f, 0.033f, 0.500f };
									break;
								case 15:
									linescolors = { 0.749f, 1.000f, 0.033f, 0.500f };
									break;
								case 16:
									linescolors = { 0.941f, 1.000f, 0.033f, 0.500f };
									break;
								case 17:
									linescolors = { 1.000f, 0.866f, 0.033f, 0.500f };
									break;
								case 18:
									linescolors = { 1.000f, 0.642f, 0.033f, 0.500f };
									break;
								case 19:
									linescolors = { 1.000f, 0.386f, 0.033f, 0.500f };
									break;
								case 20:
									linescolors = { 1.000f, 0.033f, 0.033f, 0.500f };
									break;
								case 21:
									linescolors = { 0.126f, 0.430f, 1.000f, 0.500f };
									break;
								case 22:
									linescolors = { 0.639f, 0.879f, 0.008f, 0.500f };
									break;
								case 23:
									linescolors = { 0.639f, 0.879f, 0.008f, 0.500f };
									break;
								case 24:
									linescolors = { 1.000f, 0.859f, 0.251f, 0.500f };
									break;
								case 25:
									linescolors = { 0.053f, 0.355f, 1.000f, 0.500f };
									break;
								case 26:
									linescolors = { 1.000f, 0.70f, 0.000f, 0.500f };
									break;
								case 27:
									linescolors = { 1.000f, 1.000f, 0.000f, 0.500f };
									break;
								case 28:
									linescolors = { 0.866f, 0.128f, 0.081f, 0.500f };
									break;
								case 29:
									linescolors = { 0.844f, 0.066f, 1.000f, 0.500f };
									break;
								case 30:
									linescolors = { 0.033f, 0.696f, 1.000f, 0.500f };
									break;
								case 31:
									linescolors = { 0.033f, 1.000f, 0.952f, 0.500f };
									break;
								case 32:
									linescolors = { 0.033f, 1.000f, 0.535f, 0.500f };
									break;
								case 33:
									linescolors = { 0.044f, 1.000f, 0.033f, 0.500f };
									break;
								case 34:
									linescolors = { 0.428f, 1.000f, 0.033f, 0.500f };
									break;
								case 35:
									linescolors = { 0.749f, 1.000f, 0.033f, 0.500f };
									break;
								case 36:
									linescolors = { 0.941f, 1.000f, 0.033f, 0.500f };
									break;
								case 37:
									linescolors = { 1.000f, 0.866f, 0.033f, 0.500f };
									break;
								case 38:
									linescolors = { 1.000f, 0.642f, 0.033f, 0.500f };
									break;
								case 39:
									linescolors = { 1.000f, 0.386f, 0.033f, 0.500f };
									break;
								case 40:
									linescolors = { 1.000f, 0.033f, 0.033f, 0.500f };
									break;
								case 41:
									linescolors = { 0.126f, 0.430f, 1.000f, 0.500f };
									break;
								case 42:
									linescolors = { 0.639f, 0.879f, 0.008f, 0.500f };
									break;
								case 43:
									linescolors = { 0.639f, 0.879f, 0.008f, 0.500f };
									break;
								case 44:
									linescolors = { 1.000f, 0.859f, 0.251f, 0.500f };
									break;
								case 45:
									linescolors = { 0.053f, 0.355f, 1.000f, 0.500f };
									break;
								case 46:
									linescolors = { 0.126f, 0.430f, 1.000f, 0.500f };
									break;
								case 47:
									linescolors = { 0.639f, 0.879f, 0.008f, 0.500f };
									break;
								case 48:
									linescolors = { 0.639f, 0.879f, 0.008f, 0.500f };
									break;
								case 49:
									linescolors = { 1.000f, 0.859f, 0.251f, 0.500f };
									break;
								case 50:
									linescolors = { 0.033f, 0.696f, 1.000f, 0.500f };
									break;
								case 51:
									linescolors = { 0.033f, 1.000f, 0.952f, 0.500f };
									break;
								case 52:
									linescolors = { 0.033f, 1.000f, 0.535f, 0.500f };
									break;
								case 53:
									linescolors = { 0.044f, 1.000f, 0.033f, 0.500f };
									break;
								case 54:
									linescolors = { 0.428f, 1.000f, 0.033f, 0.500f };
									break;
								case 55:
									linescolors = { 0.749f, 1.000f, 0.033f, 0.500f };
									break;
								case 56:
									linescolors = { 0.941f, 1.000f, 0.033f, 0.500f };
									break;
								case 57:
									linescolors = { 1.000f, 0.866f, 0.033f, 0.500f };
									break;
								case 58:
									linescolors = { 1.000f, 0.642f, 0.033f, 0.500f };
									break;
								case 59:
									linescolors = { 1.000f, 0.386f, 0.033f, 0.500f };
									break;
								case 60:
									linescolors = { 1.000f, 0.033f, 0.033f, 0.500f };
									break;
								case 61:
									linescolors = { 0.399f, 0.720f, 0.122f, 0.500f };
									break;
								case 62:
									linescolors = { 1.000f, 0.960f, 0.560f, 0.500f };
									break;
								case 63:
									linescolors = { 0.874f, 0.301f, 0.068f, 0.500f };
									break;
								case 64:
									linescolors = { 0.110f, 0.845f, 0.174f, 0.500f };
									break;
								case 65:
									linescolors = { 0.802f, 0.267f, 0.077f, 0.500f };
									break;
								case 66:
									linescolors = { 0.129f, 0.774f, 0.986f, 0.500f };
									break;
								case 67:
									linescolors = { 0.168f, 0.792f, 0.792f, 0.500f };
									break;
								case 68:
									linescolors = { 1.000f, 0.237f, 0.945f, 0.500f };
									break;
								case 69:
									linescolors = { 1.000f, 0.126f, 0.430f, 0.500f };
									break;
								case 70:
									linescolors = { 0.033f, 0.696f, 1.000f, 0.500f };
									break;
								case 71:
									linescolors = { 0.033f, 1.000f, 0.952f, 0.500f };
									break;
								case 72:
									linescolors = { 0.033f, 1.000f, 0.535f, 0.500f };
									break;
								case 73:
									linescolors = { 0.044f, 1.000f, 0.033f, 0.500f };
									break;
								case 74:
									linescolors = { 0.428f, 1.000f, 0.033f, 0.500f };
									break;
								case 75:
									linescolors = { 0.749f, 1.000f, 0.033f, 0.500f };
									break;
								case 76:
									linescolors = { 0.941f, 1.000f, 0.033f, 0.500f };
									break;
								case 77:
									linescolors = { 1.000f, 0.866f, 0.033f, 0.500f };
									break;
								case 78:
									linescolors = { 1.000f, 0.642f, 0.033f, 0.500f };
									break;
								case 79:
									linescolors = { 1.000f, 0.386f, 0.033f, 0.500f };
									break;
								case 80:
									linescolors = { 1.000f, 0.033f, 0.033f, 0.500f };
									break;
								case 81:
									linescolors = { 1.000f, 0.033f, 0.129f, 0.500f };
									break;
								case 82:
									linescolors = { 1.000f, 0.033f, 0.290f, 0.500f };
									break;
								case 83:
									linescolors = { 1.000f, 0.033f, 0.450f, 0.500f };
									break;
								case 84:
									linescolors = { 1.000f, 0.033f, 0.578f, 0.500f };
									break;
								case 85:
									linescolors = { 1.000f, 0.033f, 0.802f, 0.500f };
									break;
								case 86:
									linescolors = { 0.973f, 0.033f, 1.000f, 0.500f };
									break;
								case 87:
									linescolors = { 0.781f, 0.033f, 1.000f, 0.500f };
									break;
								case 88:
									linescolors = { 0.557f, 0.033f, 1.000f, 0.500f };
									break;
								case 89:
									linescolors = { 0.033f, 0.375f, 1.000f, 0.500f };
									break;
								case 90:
									linescolors = { 0.033f, 0.696f, 1.000f, 0.500f };
									break;
								case 91:
									linescolors = { 0.033f, 1.000f, 0.952f, 0.500f };
									break;
								case 92:
									linescolors = { 0.033f, 1.000f, 0.535f, 0.500f };
									break;
								case 93:
									linescolors = { 0.044f, 1.000f, 0.033f, 0.500f };
									break;
								case 94:
									linescolors = { 0.428f, 1.000f, 0.033f, 0.500f };
									break;
								case 95:
									linescolors = { 0.749f, 1.000f, 0.033f, 0.500f };
									break;
								case 96:
									linescolors = { 0.941f, 1.000f, 0.033f, 0.500f };
									break;
								case 97:
									linescolors = { 1.000f, 0.866f, 0.033f, 0.500f };
									break;
								case 98:
									linescolors = { 1.000f, 0.642f, 0.033f, 0.500f };
									break;
								case 99:
									linescolors = { 1.000f, 0.386f, 0.033f, 0.500f };
									break;
								case 100:
									linescolors = { 1.000f, 0.033f, 0.033f, 0.500f };
									break;

								case 101:
									linescolors = { 1.000f, 0.033f, 0.129f, 0.500f };
									break;
								case 102:
									linescolors = { 1.000f, 1.000f, 0.000f, 0.500f };
									break;
								case 103:
									linescolors = { 0.866f, 0.128f, 0.081f, 0.500f };
									break;
								case 104:
									linescolors = { 0.844f, 0.066f, 1.000f, 0.500f };
									break;
								case 105:
									linescolors = { 0.737f, 1.000f, 0.000f, 0.500f };
									break;
								case 106:
									linescolors = { 0.000f, 1.000f, 0.964f, 0.500f };
									break;
								case 107:
									linescolors = { 0.610f, 0.190f, 1.000f, 0.500f };
									break;
								case 108:
									linescolors = { 1.000f, 0.100f, 0.401f, 0.500f };
									break;
								case 109:
									linescolors = { 0.610f, 0.190f, 1.000f, 0.500f };
									break;
								case 110:
									linescolors = { 0.033f, 0.696f, 1.000f, 0.500f };
									break;
								case 111:
									linescolors = { 0.033f, 1.000f, 0.952f, 0.500f };
									break;
								case 112:
									linescolors = { 0.033f, 1.000f, 0.535f, 0.500f };
									break;
								case 113:
									linescolors = { 0.044f, 1.000f, 0.033f, 0.500f };
									break;
								case 114:
									linescolors = { 0.428f, 1.000f, 0.033f, 0.500f };
									break;
								case 115:
									linescolors = { 0.749f, 1.000f, 0.033f, 0.500f };
									break;
								case 116:
									linescolors = { 0.941f, 1.000f, 0.033f, 0.500f };
									break;
								case 117:
									linescolors = { 1.000f, 0.866f, 0.033f, 0.500f };
									break;
								case 118:
									linescolors = { 1.000f, 0.642f, 0.033f, 0.500f };
									break;
								case 119:
									linescolors = { 1.000f, 0.386f, 0.033f, 0.500f };
									break;
								case 120:
									linescolors = { 1.000f, 0.033f, 0.033f, 0.500f };
									break;
								case 121:
									linescolors = { 0.126f, 0.430f, 1.000f, 0.500f };
									break;
								case 122:
									linescolors = { 0.639f, 0.879f, 0.008f, 0.500f };
									break;
								case 123:
									linescolors = { 0.639f, 0.879f, 0.008f, 0.500f };
									break;
								case 124:
									linescolors = { 1.000f, 0.859f, 0.251f, 0.500f };
									break;
								case 125:
									linescolors = { 0.053f, 0.355f, 1.000f, 0.500f };
									break;
								case 126:
									linescolors = { 1.000f, 0.70f, 0.000f, 0.500f };
									break;
								case 127:
									linescolors = { 1.000f, 1.000f, 0.000f, 0.500f };
									break;
								case 128:
									linescolors = { 0.866f, 0.128f, 0.081f, 0.500f };
									break;
								case 129:
									linescolors = { 0.844f, 0.066f, 1.000f, 0.500f };
									break;
								case 130:
									linescolors = { 0.033f, 0.696f, 1.000f, 0.500f };
									break;
								case 131:
									linescolors = { 0.033f, 1.000f, 0.952f, 0.500f };
									break;
								case 132:
									linescolors = { 0.033f, 1.000f, 0.535f, 0.500f };
									break;
								case 133:
									linescolors = { 0.044f, 1.000f, 0.033f, 0.500f };
									break;
								case 134:
									linescolors = { 0.428f, 1.000f, 0.033f, 0.500f };
									break;
								case 135:
									linescolors = { 0.749f, 1.000f, 0.033f, 0.500f };
									break;
								case 136:
									linescolors = { 0.941f, 1.000f, 0.033f, 0.500f };
									break;
								case 137:
									linescolors = { 1.000f, 0.866f, 0.033f, 0.500f };
									break;
								case 138:
									linescolors = { 1.000f, 0.642f, 0.033f, 0.500f };
									break;
								case 139:
									linescolors = { 1.000f, 0.386f, 0.033f, 0.500f };
									break;
								case 140:
									linescolors = { 1.000f, 0.033f, 0.033f, 0.500f };
									break;
								case 141:
									linescolors = { 0.126f, 0.430f, 1.000f, 0.500f };
									break;
								case 142:
									linescolors = { 0.639f, 0.879f, 0.008f, 0.500f };
									break;
								case 143:
									linescolors = { 0.639f, 0.879f, 0.008f, 0.500f };
									break;
								case 144:
									linescolors = { 1.000f, 0.859f, 0.251f, 0.500f };
									break;
								case 145:
									linescolors = { 0.053f, 0.355f, 1.000f, 0.500f };
									break;
								case 146:
									linescolors = { 0.126f, 0.430f, 1.000f, 0.500f };
									break;
								case 147:
									linescolors = { 0.639f, 0.879f, 0.008f, 0.500f };
									break;
								case 148:
									linescolors = { 0.639f, 0.879f, 0.008f, 0.500f };
									break;
								case 149:
									linescolors = { 1.000f, 0.859f, 0.251f, 0.500f };
									break;
								case 150:
									linescolors = { 0.033f, 0.696f, 1.000f, 0.500f };
									break;
								case 151:
									linescolors = { 0.033f, 1.000f, 0.952f, 0.500f };
									break;
								case 152:
									linescolors = { 0.033f, 1.000f, 0.535f, 0.500f };
									break;
								case 153:
									linescolors = { 0.044f, 1.000f, 0.033f, 0.500f };
									break;
								case 154:
									linescolors = { 0.428f, 1.000f, 0.033f, 0.500f };
									break;
								case 155:
									linescolors = { 0.749f, 1.000f, 0.033f, 0.500f };
									break;
								case 156:
									linescolors = { 0.941f, 1.000f, 0.033f, 0.500f };
									break;
								case 157:
									linescolors = { 1.000f, 0.866f, 0.033f, 0.500f };
									break;
								case 158:
									linescolors = { 1.000f, 0.642f, 0.033f, 0.500f };
									break;
								case 159:
									linescolors = { 1.000f, 0.386f, 0.033f, 0.500f };
									break;
								case 160:
									linescolors = { 1.000f, 0.033f, 0.033f, 0.500f };
									break;
								case 161:
									linescolors = { 0.399f, 0.720f, 0.122f, 0.500f };
									break;
								case 162:
									linescolors = { 1.000f, 0.960f, 0.560f, 0.500f };
									break;
								case 163:
									linescolors = { 0.874f, 0.301f, 0.068f, 0.500f };
									break;
								case 164:
									linescolors = { 0.110f, 0.845f, 0.174f, 0.500f };
									break;
								case 165:
									linescolors = { 0.802f, 0.267f, 0.077f, 0.500f };
									break;
								case 166:
									linescolors = { 0.129f, 0.774f, 0.986f, 0.500f };
									break;
								case 167:
									linescolors = { 0.168f, 0.792f, 0.792f, 0.500f };
									break;
								case 168:
									linescolors = { 1.000f, 0.237f, 0.945f, 0.500f };
									break;
								case 169:
									linescolors = { 1.000f, 0.126f, 0.430f, 0.500f };
									break;
								case 170:
									linescolors = { 0.033f, 0.696f, 1.000f, 0.500f };
									break;
								case 171:
									linescolors = { 0.033f, 1.000f, 0.952f, 0.500f };
									break;
								case 172:
									linescolors = { 0.033f, 1.000f, 0.535f, 0.500f };
									break;
								case 173:
									linescolors = { 0.044f, 1.000f, 0.033f, 0.500f };
									break;
								case 174:
									linescolors = { 0.428f, 1.000f, 0.033f, 0.500f };
									break;
								case 175:
									linescolors = { 0.749f, 1.000f, 0.033f, 0.500f };
									break;
								case 176:
									linescolors = { 0.941f, 1.000f, 0.033f, 0.500f };
									break;
								case 177:
									linescolors = { 1.000f, 0.866f, 0.033f, 0.500f };
									break;
								case 178:
									linescolors = { 1.000f, 0.642f, 0.033f, 0.500f };
									break;
								case 179:
									linescolors = { 1.000f, 0.386f, 0.033f, 0.500f };
									break;
								case 180:
									linescolors = { 1.000f, 0.033f, 0.033f, 0.500f };
									break;
								case 181:
									linescolors = { 1.000f, 0.033f, 0.129f, 0.500f };
									break;
								case 182:
									linescolors = { 1.000f, 0.033f, 0.290f, 0.500f };
									break;
								case 183:
									linescolors = { 1.000f, 0.033f, 0.450f, 0.500f };
									break;
								case 184:
									linescolors = { 1.000f, 0.033f, 0.578f, 0.500f };
									break;
								case 185:
									linescolors = { 1.000f, 0.033f, 0.802f, 0.500f };
									break;
								case 186:
									linescolors = { 0.973f, 0.033f, 1.000f, 0.500f };
									break;
								case 187:
									linescolors = { 0.781f, 0.033f, 1.000f, 0.500f };
									break;
								case 188:
									linescolors = { 0.557f, 0.033f, 1.000f, 0.500f };
									break;
								case 189:
									linescolors = { 0.033f, 0.375f, 1.000f, 0.500f };
									break;
								case 190:
									linescolors = { 0.033f, 0.696f, 1.000f, 0.500f };
									break;
								case 191:
									linescolors = { 0.033f, 1.000f, 0.952f, 0.500f };
									break;
								case 192:
									linescolors = { 0.033f, 1.000f, 0.535f, 0.500f };
									break;
								case 193:
									linescolors = { 0.044f, 1.000f, 0.033f, 0.500f };
									break;
								case 194:
									linescolors = { 0.428f, 1.000f, 0.033f, 0.500f };
									break;
								case 195:
									linescolors = { 0.749f, 1.000f, 0.033f, 0.500f };
									break;
								case 196:
									linescolors = { 0.941f, 1.000f, 0.033f, 0.500f };
									break;
								case 197:
									linescolors = { 1.000f, 0.866f, 0.033f, 0.500f };
									break;
								case 198:
									linescolors = { 1.000f, 0.642f, 0.033f, 0.500f };
									break;
								case 199:
									linescolors = { 1.000f, 0.386f, 0.033f, 0.500f };
									break;
								case 200:
									linescolors = { 1.000f, 0.033f, 0.033f, 0.500f };
									break;

								case 201:
									linescolors = { 1.000f, 0.033f, 0.129f, 0.500f };
									break;
								case 202:
									linescolors = { 1.000f, 1.000f, 0.000f, 0.500f };
									break;
								case 203:
									linescolors = { 0.866f, 0.128f, 0.081f, 0.500f };
									break;
								case 204:
									linescolors = { 0.844f, 0.066f, 1.000f, 0.500f };
									break;
								case 205:
									linescolors = { 0.737f, 1.000f, 0.000f, 0.500f };
									break;
								case 206:
									linescolors = { 0.000f, 1.000f, 0.964f, 0.500f };
									break;
								case 207:
									linescolors = { 0.610f, 0.190f, 1.000f, 0.500f };
									break;
								case 208:
									linescolors = { 1.000f, 0.100f, 0.401f, 0.500f };
									break;
								case 209:
									linescolors = { 0.610f, 0.190f, 1.000f, 0.500f };
									break;
								case 210:
									linescolors = { 0.033f, 0.696f, 1.000f, 0.500f };
									break;
								case 211:
									linescolors = { 0.033f, 1.000f, 0.952f, 0.500f };
									break;
								case 212:
									linescolors = { 0.033f, 1.000f, 0.535f, 0.500f };
									break;
								case 213:
									linescolors = { 0.044f, 1.000f, 0.033f, 0.500f };
									break;
								case 214:
									linescolors = { 0.428f, 1.000f, 0.033f, 0.500f };
									break;
								case 215:
									linescolors = { 0.749f, 1.000f, 0.033f, 0.500f };
									break;
								case 216:
									linescolors = { 0.941f, 1.000f, 0.033f, 0.500f };
									break;
								case 217:
									linescolors = { 1.000f, 0.866f, 0.033f, 0.500f };
									break;
								case 218:
									linescolors = { 1.000f, 0.642f, 0.033f, 0.500f };
									break;
								case 219:
									linescolors = { 1.000f, 0.386f, 0.033f, 0.500f };
									break;
								case 220:
									linescolors = { 1.000f, 0.033f, 0.033f, 0.500f };
									break;
								case 221:
									linescolors = { 0.126f, 0.430f, 1.000f, 0.500f };
									break;
								case 222:
									linescolors = { 0.639f, 0.879f, 0.008f, 0.500f };
									break;
								case 223:
									linescolors = { 0.639f, 0.879f, 0.008f, 0.500f };
									break;
								case 224:
									linescolors = { 1.000f, 0.859f, 0.251f, 0.500f };
									break;
								case 225:
									linescolors = { 0.053f, 0.355f, 1.000f, 0.500f };
									break;
								case 226:
									linescolors = { 1.000f, 0.70f, 0.000f, 0.500f };
									break;
								case 227:
									linescolors = { 1.000f, 1.000f, 0.000f, 0.500f };
									break;
								case 228:
									linescolors = { 0.866f, 0.128f, 0.081f, 0.500f };
									break;
								case 229:
									linescolors = { 0.844f, 0.066f, 1.000f, 0.500f };
									break;
								case 230:
									linescolors = { 0.033f, 0.696f, 1.000f, 0.500f };
									break;
								case 231:
									linescolors = { 0.033f, 1.000f, 0.952f, 0.500f };
									break;
								case 232:
									linescolors = { 0.033f, 1.000f, 0.535f, 0.500f };
									break;
								case 233:
									linescolors = { 0.044f, 1.000f, 0.033f, 0.500f };
									break;
								case 234:
									linescolors = { 0.428f, 1.000f, 0.033f, 0.500f };
									break;
								case 235:
									linescolors = { 0.749f, 1.000f, 0.033f, 0.500f };
									break;
								case 236:
									linescolors = { 0.941f, 1.000f, 0.033f, 0.500f };
									break;
								case 237:
									linescolors = { 1.000f, 0.866f, 0.033f, 0.500f };
									break;
								case 238:
									linescolors = { 1.000f, 0.642f, 0.033f, 0.500f };
									break;
								case 239:
									linescolors = { 1.000f, 0.386f, 0.033f, 0.500f };
									break;
								case 240:
									linescolors = { 1.000f, 0.033f, 0.033f, 0.500f };
									break;
								case 241:
									linescolors = { 0.126f, 0.430f, 1.000f, 0.500f };
									break;
								case 242:
									linescolors = { 0.639f, 0.879f, 0.008f, 0.500f };
									break;
								case 243:
									linescolors = { 0.639f, 0.879f, 0.008f, 0.500f };
									break;
								case 244:
									linescolors = { 1.000f, 0.859f, 0.251f, 0.500f };
									break;
								case 245:
									linescolors = { 0.053f, 0.355f, 1.000f, 0.500f };
									break;
								case 246:
									linescolors = { 0.126f, 0.430f, 1.000f, 0.500f };
									break;
								case 247:
									linescolors = { 0.639f, 0.879f, 0.008f, 0.500f };
									break;
								case 248:
									linescolors = { 0.639f, 0.879f, 0.008f, 0.500f };
									break;
								case 249:
									linescolors = { 1.000f, 0.859f, 0.251f, 0.500f };
									break;
								case 250:
									linescolors = { 0.033f, 0.696f, 1.000f, 0.500f };
									break;
								case 251:
									linescolors = { 0.033f, 1.000f, 0.952f, 0.500f };
									break;
								case 252:
									linescolors = { 0.033f, 1.000f, 0.535f, 0.500f };
									break;
								case 253:
									linescolors = { 0.044f, 1.000f, 0.033f, 0.500f };
									break;
								case 254:
									linescolors = { 0.428f, 1.000f, 0.033f, 0.500f };
									break;
								case 255:
									linescolors = { 0.749f, 1.000f, 0.033f, 0.500f };
									break;
								case 256:
									linescolors = { 0.941f, 1.000f, 0.033f, 0.500f };
									break;
								case 257:
									linescolors = { 1.000f, 0.866f, 0.033f, 0.500f };
									break;
								case 258:
									linescolors = { 1.000f, 0.642f, 0.033f, 0.500f };
									break;
								case 259:
									linescolors = { 1.000f, 0.386f, 0.033f, 0.500f };
									break;
								case 260:
									linescolors = { 1.000f, 0.033f, 0.033f, 0.500f };
									break;
								case 261:
									linescolors = { 0.399f, 0.720f, 0.122f, 0.500f };
									break;
								case 262:
									linescolors = { 1.000f, 0.960f, 0.560f, 0.500f };
									break;
								case 263:
									linescolors = { 0.874f, 0.301f, 0.068f, 0.500f };
									break;
								case 264:
									linescolors = { 0.110f, 0.845f, 0.174f, 0.500f };
									break;
								case 265:
									linescolors = { 0.802f, 0.267f, 0.077f, 0.500f };
									break;
								case 266:
									linescolors = { 0.129f, 0.774f, 0.986f, 0.500f };
									break;
								case 267:
									linescolors = { 0.168f, 0.792f, 0.792f, 0.500f };
									break;
								case 268:
									linescolors = { 1.000f, 0.237f, 0.945f, 0.500f };
									break;
								case 269:
									linescolors = { 1.000f, 0.126f, 0.430f, 0.500f };
									break;
								case 270:
									linescolors = { 0.033f, 0.696f, 1.000f, 0.500f };
									break;
								case 271:
									linescolors = { 0.033f, 1.000f, 0.952f, 0.500f };
									break;
								case 272:
									linescolors = { 0.033f, 1.000f, 0.535f, 0.500f };
									break;
								case 273:
									linescolors = { 0.044f, 1.000f, 0.033f, 0.500f };
									break;
								case 274:
									linescolors = { 0.428f, 1.000f, 0.033f, 0.500f };
									break;
								case 275:
									linescolors = { 0.749f, 1.000f, 0.033f, 0.500f };
									break;
								case 276:
									linescolors = { 0.941f, 1.000f, 0.033f, 0.500f };
									break;
								case 277:
									linescolors = { 1.000f, 0.866f, 0.033f, 0.500f };
									break;
								case 278:
									linescolors = { 1.000f, 0.642f, 0.033f, 0.500f };
									break;
								case 279:
									linescolors = { 1.000f, 0.386f, 0.033f, 0.500f };
									break;
								case 280:
									linescolors = { 1.000f, 0.033f, 0.033f, 0.500f };
									break;
								case 281:
									linescolors = { 1.000f, 0.033f, 0.129f, 0.500f };
									break;
								case 282:
									linescolors = { 1.000f, 0.033f, 0.290f, 0.500f };
									break;
								case 283:
									linescolors = { 1.000f, 0.033f, 0.450f, 0.500f };
									break;
								case 284:
									linescolors = { 1.000f, 0.033f, 0.578f, 0.500f };
									break;
								case 285:
									linescolors = { 1.000f, 0.033f, 0.802f, 0.500f };
									break;
								case 286:
									linescolors = { 0.973f, 0.033f, 1.000f, 0.500f };
									break;
								case 287:
									linescolors = { 0.781f, 0.033f, 1.000f, 0.500f };
									break;
								case 288:
									linescolors = { 0.557f, 0.033f, 1.000f, 0.500f };
									break;
								case 289:
									linescolors = { 0.033f, 0.375f, 1.000f, 0.500f };
									break;
								case 290:
									linescolors = { 0.033f, 0.696f, 1.000f, 0.500f };
									break;
								case 291:
									linescolors = { 0.033f, 1.000f, 0.952f, 0.500f };
									break;
								case 292:
									linescolors = { 0.033f, 1.000f, 0.535f, 0.500f };
									break;
								case 293:
									linescolors = { 0.044f, 1.000f, 0.033f, 0.500f };
									break;
								case 294:
									linescolors = { 0.428f, 1.000f, 0.033f, 0.500f };
									break;
								case 295:
									linescolors = { 0.749f, 1.000f, 0.033f, 0.500f };
									break;
								case 296:
									linescolors = { 0.941f, 1.000f, 0.033f, 0.500f };
									break;
								case 297:
									linescolors = { 1.000f, 0.866f, 0.033f, 0.500f };
									break;
								case 298:
									linescolors = { 1.000f, 0.642f, 0.033f, 0.500f };
									break;
								case 299:
									linescolors = { 1.000f, 0.386f, 0.033f, 0.500f };
									break;
								case 300:
									linescolors = { 1.000f, 0.033f, 0.033f, 0.500f };
									break;

								case 301:
									linescolors = { 1.000f, 0.033f, 0.129f, 0.500f };
									break;
								case 302:
									linescolors = { 1.000f, 1.000f, 0.000f, 0.500f };
									break;
								case 303:
									linescolors = { 0.866f, 0.128f, 0.081f, 0.500f };
									break;
								case 304:
									linescolors = { 0.844f, 0.066f, 1.000f, 0.500f };
									break;
								case 305:
									linescolors = { 0.737f, 1.000f, 0.000f, 0.500f };
									break;
								case 306:
									linescolors = { 0.000f, 1.000f, 0.964f, 0.500f };
									break;
								case 307:
									linescolors = { 0.610f, 0.190f, 1.000f, 0.500f };
									break;
								case 308:
									linescolors = { 1.000f, 0.100f, 0.401f, 0.500f };
									break;
								case 309:
									linescolors = { 0.610f, 0.190f, 1.000f, 0.500f };
									break;
								case 310:
									linescolors = { 0.033f, 0.696f, 1.000f, 0.500f };
									break;
								case 311:
									linescolors = { 0.033f, 1.000f, 0.952f, 0.500f };
									break;
								case 312:
									linescolors = { 0.033f, 1.000f, 0.535f, 0.500f };
									break;
								case 313:
									linescolors = { 0.044f, 1.000f, 0.033f, 0.500f };
									break;
								case 314:
									linescolors = { 0.428f, 1.000f, 0.033f, 0.500f };
									break;
								case 315:
									linescolors = { 0.749f, 1.000f, 0.033f, 0.500f };
									break;
								case 316:
									linescolors = { 0.941f, 1.000f, 0.033f, 0.500f };
									break;
								case 317:
									linescolors = { 1.000f, 0.866f, 0.033f, 0.500f };
									break;
								case 318:
									linescolors = { 1.000f, 0.642f, 0.033f, 0.500f };
									break;
								case 319:
									linescolors = { 1.000f, 0.386f, 0.033f, 0.500f };
									break;
								case 320:
									linescolors = { 1.000f, 0.033f, 0.033f, 0.500f };
									break;
								case 321:
									linescolors = { 0.126f, 0.430f, 1.000f, 0.500f };
									break;
								case 322:
									linescolors = { 0.639f, 0.879f, 0.008f, 0.500f };
									break;
								case 323:
									linescolors = { 0.639f, 0.879f, 0.008f, 0.500f };
									break;
								case 324:
									linescolors = { 1.000f, 0.859f, 0.251f, 0.500f };
									break;
								case 325:
									linescolors = { 0.053f, 0.355f, 1.000f, 0.500f };
									break;
								case 326:
									linescolors = { 1.000f, 0.70f, 0.000f, 0.500f };
									break;
								case 327:
									linescolors = { 1.000f, 1.000f, 0.000f, 0.500f };
									break;
								case 328:
									linescolors = { 0.866f, 0.128f, 0.081f, 0.500f };
									break;
								case 329:
									linescolors = { 0.844f, 0.066f, 1.000f, 0.500f };
									break;
								case 330:
									linescolors = { 0.033f, 0.696f, 1.000f, 0.500f };
									break;
								case 331:
									linescolors = { 0.033f, 1.000f, 0.952f, 0.500f };
									break;
								case 332:
									linescolors = { 0.033f, 1.000f, 0.535f, 0.500f };
									break;
								case 333:
									linescolors = { 0.044f, 1.000f, 0.033f, 0.500f };
									break;
								case 334:
									linescolors = { 0.428f, 1.000f, 0.033f, 0.500f };
									break;
								case 335:
									linescolors = { 0.749f, 1.000f, 0.033f, 0.500f };
									break;
								case 336:
									linescolors = { 0.941f, 1.000f, 0.033f, 0.500f };
									break;
								case 337:
									linescolors = { 1.000f, 0.866f, 0.033f, 0.500f };
									break;
								case 338:
									linescolors = { 1.000f, 0.642f, 0.033f, 0.500f };
									break;
								case 339:
									linescolors = { 1.000f, 0.386f, 0.033f, 0.500f };
									break;
								case 340:
									linescolors = { 1.000f, 0.033f, 0.033f, 0.500f };
									break;
								case 341:
									linescolors = { 0.126f, 0.430f, 1.000f, 0.500f };
									break;
								case 342:
									linescolors = { 0.639f, 0.879f, 0.008f, 0.500f };
									break;
								case 343:
									linescolors = { 0.639f, 0.879f, 0.008f, 0.500f };
									break;
								case 344:
									linescolors = { 1.000f, 0.859f, 0.251f, 0.500f };
									break;
								case 345:
									linescolors = { 0.053f, 0.355f, 1.000f, 0.500f };
									break;
								case 346:
									linescolors = { 0.126f, 0.430f, 1.000f, 0.500f };
									break;
								case 347:
									linescolors = { 0.639f, 0.879f, 0.008f, 0.500f };
									break;
								case 348:
									linescolors = { 0.639f, 0.879f, 0.008f, 0.500f };
									break;
								case 349:
									linescolors = { 1.000f, 0.859f, 0.251f, 0.500f };
									break;
								case 350:
									linescolors = { 0.033f, 0.696f, 1.000f, 0.500f };
									break;
								case 351:
									linescolors = { 0.033f, 1.000f, 0.952f, 0.500f };
									break;
								case 352:
									linescolors = { 0.033f, 1.000f, 0.535f, 0.500f };
									break;
								case 353:
									linescolors = { 0.044f, 1.000f, 0.033f, 0.500f };
									break;
								case 354:
									linescolors = { 0.428f, 1.000f, 0.033f, 0.500f };
									break;
								case 355:
									linescolors = { 0.749f, 1.000f, 0.033f, 0.500f };
									break;
								case 356:
									linescolors = { 0.941f, 1.000f, 0.033f, 0.500f };
									break;
								case 357:
									linescolors = { 1.000f, 0.866f, 0.033f, 0.500f };
									break;
								case 358:
									linescolors = { 1.000f, 0.642f, 0.033f, 0.500f };
									break;
								case 359:
									linescolors = { 1.000f, 0.386f, 0.033f, 0.500f };
									break;
								case 360:
									linescolors = { 1.000f, 0.033f, 0.033f, 0.500f };
									break;
								case 361:
									linescolors = { 0.399f, 0.720f, 0.122f, 0.500f };
									break;
								case 362:
									linescolors = { 1.000f, 0.960f, 0.560f, 0.500f };
									break;
								case 363:
									linescolors = { 0.874f, 0.301f, 0.068f, 0.500f };
									break;
								case 364:
									linescolors = { 0.110f, 0.845f, 0.174f, 0.500f };
									break;
								case 365:
									linescolors = { 0.802f, 0.267f, 0.077f, 0.500f };
									break;
								case 366:
									linescolors = { 0.129f, 0.774f, 0.986f, 0.500f };
									break;
								case 367:
									linescolors = { 0.168f, 0.792f, 0.792f, 0.500f };
									break;
								case 368:
									linescolors = { 1.000f, 0.237f, 0.945f, 0.500f };
									break;
								case 369:
									linescolors = { 1.000f, 0.126f, 0.430f, 0.500f };
									break;
								case 370:
									linescolors = { 0.033f, 0.696f, 1.000f, 0.500f };
									break;
								case 371:
									linescolors = { 0.033f, 1.000f, 0.952f, 0.500f };
									break;
								case 372:
									linescolors = { 0.033f, 1.000f, 0.535f, 0.500f };
									break;
								case 373:
									linescolors = { 0.044f, 1.000f, 0.033f, 0.500f };
									break;
								case 374:
									linescolors = { 0.428f, 1.000f, 0.033f, 0.500f };
									break;
								case 375:
									linescolors = { 0.749f, 1.000f, 0.033f, 0.500f };
									break;
								case 376:
									linescolors = { 0.941f, 1.000f, 0.033f, 0.500f };
									break;
								case 377:
									linescolors = { 1.000f, 0.866f, 0.033f, 0.500f };
									break;
								case 378:
									linescolors = { 1.000f, 0.642f, 0.033f, 0.500f };
									break;
								case 379:
									linescolors = { 1.000f, 0.386f, 0.033f, 0.500f };
									break;
								case 380:
									linescolors = { 1.000f, 0.033f, 0.033f, 0.500f };
									break;
								case 381:
									linescolors = { 1.000f, 0.033f, 0.129f, 0.500f };
									break;
								case 382:
									linescolors = { 1.000f, 0.033f, 0.290f, 0.500f };
									break;
								case 383:
									linescolors = { 1.000f, 0.033f, 0.450f, 0.500f };
									break;
								case 384:
									linescolors = { 1.000f, 0.033f, 0.578f, 0.500f };
									break;
								case 385:
									linescolors = { 1.000f, 0.033f, 0.802f, 0.500f };
									break;
								case 386:
									linescolors = { 0.973f, 0.033f, 1.000f, 0.500f };
									break;
								case 387:
									linescolors = { 0.781f, 0.033f, 1.000f, 0.500f };
									break;
								case 388:
									linescolors = { 0.557f, 0.033f, 1.000f, 0.500f };
									break;
								case 389:
									linescolors = { 0.033f, 0.375f, 1.000f, 0.500f };
									break;
								case 390:
									linescolors = { 0.033f, 0.696f, 1.000f, 0.500f };
									break;
								case 391:
									linescolors = { 0.033f, 1.000f, 0.952f, 0.500f };
									break;
								case 392:
									linescolors = { 0.033f, 1.000f, 0.535f, 0.500f };
									break;
								case 393:
									linescolors = { 0.044f, 1.000f, 0.033f, 0.500f };
									break;
								case 394:
									linescolors = { 0.428f, 1.000f, 0.033f, 0.500f };
									break;
								case 395:
									linescolors = { 0.749f, 1.000f, 0.033f, 0.500f };
									break;
								case 396:
									linescolors = { 0.941f, 1.000f, 0.033f, 0.500f };
									break;
								case 397:
									linescolors = { 1.000f, 0.866f, 0.033f, 0.500f };
									break;
								case 398:
									linescolors = { 1.000f, 0.642f, 0.033f, 0.500f };
									break;
								case 399:
									linescolors = { 1.000f, 0.386f, 0.033f, 0.500f };
									break;
								case 400:
									linescolors = { 1.000f, 0.033f, 0.033f, 0.500f };
									break;*/
#pragma endregion
							case 0:
								linescolors = { 0.000f, 0.000f, 1.000f, 1.000f };
								break;
							case 1:
								linescolors = { 1.000f, 0.033f, 0.129f, 1.000f };
								break;
							case 2:
								linescolors = { 1.000f, 1.000f, 0.000f, 1.000f };
								break;
							case 3:
								linescolors = { 0.866f, 0.128f, 0.081f, 1.000f };
								break;
							case 4:
								linescolors = { 0.844f, 0.066f, 1.000f, 1.000f };
								break;
							case 5:
								linescolors = { 0.737f, 1.000f, 0.000f, 1.000f };
								break;
							case 6:
								linescolors = { 0.000f, 1.000f, 0.964f, 1.000f };
								break;
							case 7:
								linescolors = { 0.610f, 0.190f, 1.000f, 1.000f };
								break;
							case 8:
								linescolors = { 1.000f, 0.100f, 0.401f, 1.000f };
								break;
							case 9:
								linescolors = { 0.610f, 0.190f, 1.000f, 1.000f };
								break;
							case  10:
								linescolors = { 0.033f, 0.696f, 1.000f, 1.000f };
								break;
							case 11:
								linescolors = { 0.033f, 1.000f, 0.952f, 1.000f };
								break;
							case 12:
								linescolors = { 0.033f, 1.000f, 0.535f, 1.000f };
								break;
							case 13:
								linescolors = { 0.044f, 1.000f, 0.033f, 1.000f };
								break;
							case 14:
								linescolors = { 0.428f, 1.000f, 0.033f, 1.000f };
								break;
							case 15:
								linescolors = { 0.749f, 1.000f, 0.033f, 1.000f };
								break;
							case 16:
								linescolors = { 0.941f, 1.000f, 0.033f, 1.000f };
								break;
							case 17:
								linescolors = { 1.000f, 0.866f, 0.033f, 1.000f };
								break;
							case 18:
								linescolors = { 1.000f, 0.642f, 0.033f, 1.000f };
								break;
							case 19:
								linescolors = { 1.000f, 0.386f, 0.033f, 1.000f };
								break;
							case  20:
								linescolors = { 1.000f, 0.033f, 0.033f, 1.000f };
								break;
							case 21:
								linescolors = { 0.126f, 0.430f, 1.000f, 1.000f };
								break;
							case 22:
								linescolors = { 0.639f, 0.879f, 0.008f, 1.000f };
								break;
							case 23:
								linescolors = { 0.639f, 0.879f, 0.008f, 1.000f };
								break;
							case 24:
								linescolors = { 1.000f, 0.859f, 0.251f, 1.000f };
								break;
							case 25:
								linescolors = { 0.053f, 0.355f, 1.000f, 1.000f };
								break;
							case 26:
								linescolors = { 1.000f, 0.70f, 0.000f, 1.000f };
								break;
							case 27:
								linescolors = { 1.000f, 1.000f, 0.000f, 1.000f };
								break;
							case 28:
								linescolors = { 0.866f, 0.128f, 0.081f, 1.000f };
								break;
							case 29:
								linescolors = { 0.844f, 0.066f, 1.000f, 1.000f };
								break;
							case 30:
								linescolors = { 0.033f, 0.696f, 1.000f, 1.000f };
								break;
							case 31:
								linescolors = { 0.033f, 1.000f, 0.952f, 1.000f };
								break;
							case 32:
								linescolors = { 0.033f, 1.000f, 0.535f, 1.000f };
								break;
							case 33:
								linescolors = { 0.044f, 1.000f, 0.033f, 1.000f };
								break;
							case 34:
								linescolors = { 0.428f, 1.000f, 0.033f, 1.000f };
								break;
							case 35:
								linescolors = { 0.749f, 1.000f, 0.033f, 1.000f };
								break;
							case 36:
								linescolors = { 0.941f, 1.000f, 0.033f, 1.000f };
								break;
							case 37:
								linescolors = { 1.000f, 0.866f, 0.033f, 1.000f };
								break;
							case 38:
								linescolors = { 1.000f, 0.642f, 0.033f, 1.000f };
								break;
							case 39:
								linescolors = { 1.000f, 0.386f, 0.033f, 1.000f };
								break;
							case  40:
								linescolors = { 1.000f, 0.033f, 0.033f, 1.000f };
								break;
							case 41:
								linescolors = { 0.126f, 0.430f, 1.000f, 1.000f };
								break;
							case 42:
								linescolors = { 0.639f, 0.879f, 0.008f, 1.000f };
								break;
							case 43:
								linescolors = { 0.639f, 0.879f, 0.008f, 1.000f };
								break;
							case 44:
								linescolors = { 1.000f, 0.859f, 0.251f, 1.000f };
								break;
							case 45:
								linescolors = { 0.053f, 0.355f, 1.000f, 1.000f };
								break;
							case 46:
								linescolors = { 0.126f, 0.430f, 1.000f, 1.000f };
								break;
							case 47:
								linescolors = { 0.639f, 0.879f, 0.008f, 1.000f };
								break;
							case 48:
								linescolors = { 0.639f, 0.879f, 0.008f, 1.000f };
								break;
							case 49:
								linescolors = { 1.000f, 0.859f, 0.251f, 1.000f };
								break;
							case 50:
								linescolors = { 0.033f, 0.696f, 1.000f, 1.000f };
								break;
							case 51:
								linescolors = { 0.033f, 1.000f, 0.952f, 1.000f };
								break;
							case 52:
								linescolors = { 0.033f, 1.000f, 0.535f, 1.000f };
								break;
							case 53:
								linescolors = { 0.044f, 1.000f, 0.033f, 1.000f };
								break;
							case 54:
								linescolors = { 0.428f, 1.000f, 0.033f, 1.000f };
								break;
							case 55:
								linescolors = { 0.749f, 1.000f, 0.033f, 1.000f };

								break;
							case 56:
								linescolors = { 0.941f, 1.000f, 0.033f, 1.000f };

								break;
							case 57:
								linescolors = { 1.000f, 0.866f, 0.033f, 1.000f };

								break;
							case 58:
								linescolors = { 1.000f, 0.642f, 0.033f, 1.000f };

								break;
							case 59:
								linescolors = { 1.000f, 0.386f, 0.033f, 1.000f };
								break;
							case  60:
								linescolors = { 1.000f, 0.033f, 0.033f, 1.000f };

								break;
							case 61:
								linescolors = { 0.399f, 0.720f, 0.122f, 1.000f };

								break;
							case 62:
								linescolors = { 1.000f, 0.960f, 0.560f, 1.000f };

								break;
							case 63:
								linescolors = { 0.874f, 0.301f, 0.068f, 1.000f };

								break;
							case 64:
								linescolors = { 0.110f, 0.845f, 0.174f, 1.000f };

								break;
							case 65:
								linescolors = { 0.802f, 0.267f, 0.077f, 1.000f };

								break;

							case 66:
								linescolors = { 0.129f, 0.774f, 0.986f, 1.000f };

								break;
							case 67:
								linescolors = { 0.168f, 0.792f, 0.792f, 1.000f };

								break;
							case 68:
								linescolors = { 1.000f, 0.237f, 0.945f, 1.000f };

								break;
							case 69:
								linescolors = { 1.000f, 0.126f, 0.430f, 1.000f };

								break;
							case  70:
								linescolors = { 0.033f, 0.696f, 1.000f, 1.000f };

								break;
							case 71:
								linescolors = { 0.033f, 1.000f, 0.952f, 1.000f };

								break;
							case 72:
								linescolors = { 0.033f, 1.000f, 0.535f, 1.000f };

								break;
							case 73:
								linescolors = { 0.044f, 1.000f, 0.033f, 1.000f };

								break;
							case 74:
								linescolors = { 0.428f, 1.000f, 0.033f, 1.000f };

								break;
							case 75:
								linescolors = { 0.749f, 1.000f, 0.033f, 1.000f };

								break;
							case 76:
								linescolors = { 0.941f, 1.000f, 0.033f, 1.000f };

								break;
							case 77:
								linescolors = { 1.000f, 0.866f, 0.033f, 1.000f };

								break;
							case 78:
								linescolors = { 1.000f, 0.642f, 0.033f, 1.000f };

								break;
							case 79:
								linescolors = { 1.000f, 0.386f, 0.033f, 1.000f };

								break;
							case 80:
								linescolors = { 1.000f, 0.033f, 0.033f, 1.000f };

								break;
							case 81:
								linescolors = { 1.000f, 0.033f, 0.129f, 1.000f };

								break;
							case 82:
								linescolors = { 1.000f, 0.033f, 0.290f, 1.000f };

								break;
							case 83:
								linescolors = { 1.000f, 0.033f, 0.450f, 1.000f };

								break;
							case 84:
								linescolors = { 1.000f, 0.033f, 0.578f, 1.000f };

								break;
							case 85:
								linescolors = { 1.000f, 0.033f, 0.802f, 1.000f };

								break;

							case 86:
								linescolors = { 0.973f, 0.033f, 1.000f, 1.000f };

								break;
							case 87:
								linescolors = { 0.781f, 0.033f, 1.000f, 1.000f };

								break;
							case 88:
								linescolors = { 0.557f, 0.033f, 1.000f, 1.000f };

								break;
							case 89:
								linescolors = { 0.033f, 0.375f, 1.000f, 1.000f };

								break;
							case  90:
								linescolors = { 0.033f, 0.696f, 1.000f, 1.000f };

								break;
							case 91:
								linescolors = { 0.033f, 1.000f, 0.952f, 1.000f };

								break;
							case 92:
								linescolors = { 0.033f, 1.000f, 0.535f, 1.000f };

								break;
							case 93:
								linescolors = { 0.044f, 1.000f, 0.033f, 1.000f };

								break;
							case 94:
								linescolors = { 0.428f, 1.000f, 0.033f, 1.000f };

								break;
							case 95:
								linescolors = { 0.749f, 1.000f, 0.033f, 1.000f };

								break;

							case 96:
								linescolors = { 0.941f, 1.000f, 0.033f, 1.000f };

								break;
							case 97:
								linescolors = { 1.000f, 0.866f, 0.033f, 1.000f };

								break;
							case 98:
								linescolors = { 1.000f, 0.642f, 0.033f, 1.000f };

								break;
							case 99:
								linescolors = { 1.000f, 0.386f, 0.033f, 1.000f };

								break;
							case  100:
								linescolors = { 1.000f, 0.033f, 0.033f, 1.000f };

							break;
							default:

									linescolors = SettingMenu2::playerlineColor = SettingMenu2::botlineColor;
									bonescolors = SettingMenu2::playerboneColor = SettingMenu2::botboneColor;
									fullboxcolor = SettingMenu2::playerfullboxColor = SettingMenu2::botfullboxColor;
									cornerboxcolor = SettingMenu2::playercornerboxColor = SettingMenu2::botcornerboxColor;
									break;
								}

							}

							if (Setting::dots)
							{
								float S_height = DX11Window::Height;
								float S_width = DX11Window::Width;
								bool shit = false;
								VECTOR3 EntityPos = WorldToRadar(Data::CameraCache.POV.Rotation.Yaw, AActor.Position, Data::CameraCache.POV.Location, NULL, NULL, ToVECTOR3(S_width, S_height, 0), shit);
								int radar_range = 25;//
								int x, y;
								x = EntityPos.X;
								y = EntityPos.Y;

								VECTOR3 angle{};
								VECTOR3 temmp = ToVECTOR3((float)(S_width / 2) - x, (float)(S_height / 2) - y, 0.f);

								VectorAnglesRadar(temmp, angle);

								const auto angle_yaw_rad = DEG2RAD(angle.Y + 180.f);
								const auto new_point_x = (S_width / 2) + (radar_range) / 2 * 8 * cosf(angle_yaw_rad);
								const auto new_point_y = (S_height / 2) + (radar_range) / 2 * 8 * sinf(angle_yaw_rad);

								std::array<VECTOR3, 3> points
								{
									ToVECTOR3(new_point_x - ((90) / 4 + 3.5f) / 2, new_point_y - ((radar_range) / 4 + 3.5f) / 2, 0.f),
										ToVECTOR3(new_point_x + ((90) / 4 + 3.5f) / 4, new_point_y, 0.f),
										ToVECTOR3(new_point_x - ((90) / 4 + 3.5f) / 2, new_point_y + ((radar_range) / 4 + 3.5f) / 2, 0.f)
								};
								RotateTriangle(points, angle.Y + 180.f);
								/*if (AActor.IsBot) {
									DX11::ImGui_DX11::DrawCircle(points.at(1).X, points.at(1).Y, 5, Colors::bot, 2.3f);
								}
								else {
									DX11::ImGui_DX11::DrawCircle(points.at(1).X, points.at(1).Y, 6, linescolors, 3.3f);
								}*/
								if (AActor.IsBot) 
								{
									DX11::ImGui_DX11::DrawTriangle(points.at(0).X, points.at(0).Y, points.at(1).X, points.at(1).Y, points.at(2).X, points.at(2).Y, 2, Colors::bot);
								}
								else
								{
									DX11::ImGui_DX11::DrawTriangle(points.at(0).X, points.at(0).Y, points.at(1).X, points.at(1).Y, points.at(2).X, points.at(2).Y, 2, linescolors);
								}
								if (Setting::radar)
								{
									float S_height = DX11Window::Height;
									float S_width = DX11Window::Width;
									if (AActor.IsBot)
									{
										DrawRadarHUD(Data::CameraCache.POV, AActor, Distance, 20, 50, 100, 200, Colors::bot);
									}
									else
									{
										DrawRadarHUD(Data::CameraCache.POV, AActor, Distance, 20, 50, 100, 200, linescolors);
									}
								}

								/*	if (Screen.Z < 0.001f)
										continue;*/
								temp = AActor.Name.c_str();
								std::string lol1;
								lol1 = to_string(_dist) + "M";
								if (Screen.X > DX11Window::Width && Screen.Y > 0 && Screen.Y < DX11Window::Height)//Right
								{
									//	DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - 20, Screen.Y + Screen.Z, 7, 10, ImColor(0.0f, 0.f, 0.f, 0.200f));
									//	DX11::ImGui_DX11::DrawCircle(DX11Window::Width - 20, Screen.Y + Screen.Z, 7, linescolors, 4.0f);
									DX11::ImGui_DX11::DrawBorderText(DX11::ImGui_DX11::pRegularFont, 20, lol1, DX11Window::Width - 20, Screen.Y + Screen.Z, linescolors, true);
									//	DX11::ImGui_DX11::DrawFilledRectangle(DX11Window::Width - 20, Screen.Y + Screen.Z, 50, 30, ImColor(0.0f, 0.f, 0.f, 0.200f));
									if (Setting::enemyoffscreen)
									{
										if (Setting::pline)
										{
											DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, linescolors, Setting::plinesize);
										}
									}

								}
								if (Screen.X < 0 && Screen.Y  >0 && Screen.Y < DX11Window::Height)//Left
								{

									if (Setting::enemyoffscreen)
									{
										if (Setting::pline)
										{
											DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, linescolors, Setting::plinesize);
										}
									}

									//DX11::ImGui_DX11::DrawCircle(20, Screen.Y + Screen.Z, 7, linescolors, 4.0f);
									DX11::ImGui_DX11::DrawBorderText(DX11::ImGui_DX11::pRegularFont, 20, lol1, 20, Screen.Y + Screen.Z, linescolors, true);

								}
								// std::string lol1;  
								// lol1 = "Player"; 
							  //   if (Screen.X > DX11Window::Width && Screen.Y > 0 && Screen.Y < DX11Window::Height)//Right
								 //{
									// DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - 20, Screen.Y + Screen.Z, 7, 10, ImColor(0.0f, 0.f, 0.f, 0.200f));
									// DX11::ImGui_DX11::DrawCircle(DX11Window::Width - 20, Screen.Y + Screen.Z, 7, linescolors, 4.0f);
									// DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 15, lol1, DX11Window::Width - 20, Screen.Y + Screen.Z, Colors::nam, false);
									// DX11::ImGui_DX11::DrawFilledRectangle(DX11Window::Width - 20, Screen.Y + Screen.Z, 50, 30, ImColor(0.0f, 0.f, 0.f, 0.200f));

								 //}
								 //if (Screen.X < 0 && Screen.Y  >0 && Screen.Y < DX11Window::Height)//Left
								 //{

									// DX11::ImGui_DX11::DrawCircle(20, Screen.Y + Screen.Z, 7, linescolors, 4.0f);
									// DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 15, lol1, 20, Screen.Y + Screen.Z, Colors::nam, false);

								 //}
								if (Screen.Y < 0 && Screen.X>0 && Screen.X < DX11Window::Width)//Top
								{
									// DX11::ImGui_DX11::DrawCircle(Screen.X, 20, 7, linescolors, 4.0f);
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 20, lol1, Screen.X, 0, linescolors, true);
									if (Setting::enemyoffscreen)
									{
										if (Setting::pline)
										{
											DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, linescolors, Setting::plinesize);
										}
									}

								}
								if (Screen.Y > DX11Window::Height && Screen.X > 0 && Screen.X < DX11Window::Width)//Bottom
								{
									//	 DX11::ImGui_DX11::DrawCircle(Screen.X, DX11Window::Height - 20, 7, linescolors, 4.0f);
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 20, lol1, Screen.X, DX11Window::Height - 20, linescolors, true);
									if (Setting::enemyoffscreen)
									{
										if (Setting::pline)
										{
											DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, linescolors, Setting::plinesize);
										}
									}

								}
								if (Screen.X < 0 && Screen.Y < 0)//top left
								{
									// DX11::ImGui_DX11::DrawCircle(20, 20, 7, linescolors, 4.0f);
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 20, lol1, 0, 0, linescolors, true);
									if (Setting::enemyoffscreen)
									{
										if (Setting::pline)
										{
											DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, linescolors, Setting::plinesize);
										}
									}

								}
								if (Screen.X > DX11Window::Width && Screen.Y > DX11Window::Height)//bottom right
								{
									// DX11::ImGui_DX11::DrawCircle(DX11Window::Width - 20, DX11Window::Height - 20, 7, linescolors, 4.0f);
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 20, lol1, DX11Window::Width - 40, DX11Window::Height - 20, linescolors, true);
									if (Setting::enemyoffscreen)
									{
										if (Setting::pline)
										{
											DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, linescolors, Setting::plinesize);
										}
									}

								}
								if (Screen.X > DX11Window::Width && Screen.Y < 0)//top right
								{
									// DX11::ImGui_DX11::DrawCircle(DX11Window::Width - 20, 20, 7, linescolors, 4.0f);
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 20, lol1, DX11Window::Width - 40, 0, linescolors, true);
									if (Setting::enemyoffscreen)
									{
										if (Setting::pline)
										{
											DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, linescolors, Setting::plinesize);
										}
									}

								}
								if (Screen.X<0 && Screen.Y >DX11Window::Width)//bottom left
								{
									// DX11::ImGui_DX11::DrawCircle(20, DX11Window::Height - 20, 7, linescolors, 4.0f);
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 20, lol1, 0, DX11Window::Height - 20, linescolors, true);
									if (Setting::enemyoffscreen)
									{
										if (Setting::pline)
										{
											DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, linescolors, Setting::plinesize);
										}
									}

								}
							}

							if (Setting1::dots1)
							{
								float S_height = DX11Window::Height;
								float S_width = DX11Window::Width;
								bool shit = false;
								VECTOR3 EntityPos = WorldToRadar(Data::CameraCache.POV.Rotation.Yaw, AActor.Position, Data::CameraCache.POV.Location, NULL, NULL, ToVECTOR3(S_width, S_height, 0), shit);
								int radar_range = 25;
								int x, y;
								x = EntityPos.X;
								y = EntityPos.Y;

								VECTOR3 angle{};
								VECTOR3 temmp = ToVECTOR3((float)(S_width / 2) - x, (float)(S_height / 2) - y, 0.f);

								VectorAnglesRadar(temmp, angle);

								const auto angle_yaw_rad = DEG2RAD(angle.Y + 180.f);
								const auto new_point_x = (S_width / 2) + (radar_range) / 2 * 8 * cosf(angle_yaw_rad);
								const auto new_point_y = (S_height / 2) + (radar_range) / 2 * 8 * sinf(angle_yaw_rad);

								std::array<VECTOR3, 3> points
								{
									ToVECTOR3(new_point_x - ((90) / 4 + 3.5f) / 2, new_point_y - ((radar_range) / 4 + 3.5f) / 2, 0.f),
									ToVECTOR3(new_point_x + ((90) / 4 + 3.5f) / 4, new_point_y, 0.f),
									ToVECTOR3(new_point_x - ((90) / 4 + 3.5f) / 2, new_point_y + ((radar_range) / 4 + 3.5f) / 2, 0.f)
								};
								if (AActor.IsBot)
								{
									if (Distance < 100)
									{
										DX11::ImGui_DX11::DrawCircle(points.at(1).X, points.at(1).Y, 3, RadarColorBoot100m, 4.5f);
									}
									DX11::ImGui_DX11::DrawCircle(points.at(1).X, points.at(1).Y, 3, RadarColorBoot, 4.5f);
									//DX11::ImGui_DX11::DrawCircle(points.at(1).X, points.at(1).Y, 3, linescolors, 4.5f);
								}
								else
								{
									if (Distance < 100)
									{
										DX11::ImGui_DX11::DrawCircle(points.at(1).X, points.at(1).Y, 3, linescolors, 4.5f);
									}
									DX11::ImGui_DX11::DrawCircle(points.at(1).X, points.at(1).Y, 3, linescolorsP, 4.5f);
									//DX11::ImGui_DX11::DrawCircle(points.at(1).X, points.at(1).Y, 3, linescolors, 4.5f);
								}
							}


							DWORD MeshAddv;
							DWORD BodyAddv;
							DWORD BoneAddv;
							if (Setting::Bone || Setting::MagicBullet)
							{
								MeshAddv = Utility::ReadMemoryEx<DWORD>(AActor.Address + Offset::Mesh);
								BodyAddv = MeshAddv + Offset::BodyAddv;
								BoneAddv = Utility::ReadMemoryEx<DWORD>(MeshAddv + Offset::MinLOD) + 48;
								AActor.HeadPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 5 * 48);



							}
							if (Setting::Bone)
							{
								AActor.ChestPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 4 * 48);
								//if (!ISUseFulVector(AActor.ChestPos))continue;
								AActor.PelvisPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 1 * 48);
								//if (!ISUseFulVector(AActor.PelvisPos))continue;
								AActor.lSholderPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 11 * 48);
								AActor.rSholderPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 32 * 48);
								AActor.lElbowPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 12 * 48);
								AActor.rElbowPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 33 * 48);
								AActor.lWristPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 63 * 48);
								//if (!ISUseFulVector(AActor.lWristPos))continue;
								AActor.rWristPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 62 * 48);
								AActor.lThighPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 52 * 48);
								if (AActor.rWristPos == AActor.lThighPos)continue;
								if (AActor.rElbowPos == AActor.lSholderPos)continue;
								//if (!ISUseFulVector(AActor.lThighPos))continue;
								AActor.rThighPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 56 * 48);
								AActor.lKneePos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 53 * 48);
								AActor.rKneePos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 57 * 48);
								AActor.lAnklePos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 54 * 48);
								//if (!ISUseFulVector(AActor.lAnklePos))continue;
								AActor.rAnklePos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 58 * 48);
							}
							HeadPos = AActor.HeadPos;
							HeadPos.Z += 7;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, HeadPos, Head, &Distance)) continue;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.ChestPos, Chest, &Distance)) continue;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.PelvisPos, Pelvis, &Distance)) continue;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lSholderPos, lSholder, &Distance)) continue;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rSholderPos, rSholder, &Distance)) continue;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lElbowPos, lElbow, &Distance)) continue;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rElbowPos, rElbow, &Distance)) continue;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lWristPos, lWrist, &Distance)) continue;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rWristPos, rWrist, &Distance)) continue;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lThighPos, lThigh, &Distance)) continue;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rThighPos, rThigh, &Distance)) continue;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lKneePos, lKnee, &Distance)) continue;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rKneePos, rKnee, &Distance)) continue;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lAnklePos, lAnkle, &Distance)) continue;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rAnklePos, rAnkle, &Distance)) continue;
							//	if (Chest.X <= 0)continue;


							if (Distance < Setting::PlayerMAxDistance)
							{
								
								if (Setting::MyLineOfSight)
								{
									CameraCacheEntry CameraCache = Data::CameraCache;
									VECTOR3 currentViewLocation = Data::CameraCache.POV.Location;//Data::lOCALPLAYERHEAD;
									VECTOR3 currentViewRotation = FRotatorToVector(Data::CameraCache.POV.Rotation);
									VECTOR3 end = ADDVECTORS(currentViewLocation, MULTIPLYVECT(currentViewRotation, Setting::enemyLineofSightSize));

									VECTOR3 screen_start, screen_end;
									int dis;
									if (Algorithm::WorldToScreen(Data::lOCALPLAYERPosotion, currentViewLocation, screen_start, &dis, ViewMatrix) && Algorithm::WorldToScreen(Data::lOCALPLAYERPosotion, end, screen_end, &dis, ViewMatrix)) {
										DX11::ImGui_DX11::DrawLine(screen_start.X, screen_start.Y, screen_end.X, screen_end.Y, Colors::enemyLineofSight, 0.001);
										DX11::ImGui_DX11::DrawCircle(screen_end.X, screen_end.Y, 1.f, linescolors, 1.0f);

									}

								}

								if (Setting::EnemyLineOfSight)
								{
									VECTOR3 hed = AActor.HeadPos;
									hed.Z += 7.0f;
									VECTOR3 SightAngle = FRotatorToVector(AActor.RelativeRotation);
									VECTOR3 end = ADDVECTORS(hed, MULTIPLYVECT(SightAngle, Setting::enemyLineofSightSize));

									VECTOR3 screen_start, screen_end;
									int dis;
									if (Algorithm::WorldToScreen(Data::lOCALPLAYERPosotion, hed, screen_start, &dis, ViewMatrix) && Algorithm::WorldToScreen(Data::lOCALPLAYERPosotion, end, screen_end, &dis, ViewMatrix)) {
										DX11::ImGui_DX11::DrawLine(screen_start.X, screen_start.Y, screen_end.X, screen_end.Y, Colors::enemyLineofSight, 2);
										DX11::ImGui_DX11::DrawCircle(screen_end.X, screen_end.Y, 1.f, linescolors, 1.0f);

									}
								}
								//	string TemID = "[" + std::to_string(teamids) + "]";
								string TemID = std::to_string(teamids) + ". " + AActor.Nation;
								std::string dist = std::to_string(_dist) + "M";
								
								if (AActor.IsBot)
								{
									//linescolors = Colors::bot;
									temp = "[BOT]";

									if (!Setting::enemyoffscreen)
									{
										if (Setting1::botline)
										{
											if (Setting1::style1)
											{
												if (Setting1::botst1line)
												{
													if (linneb1 == 0)
													{
														DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, Setting1::botlinec1, Setting1::botlines1);
													}
													else if (linneb1 == 1)
													{
														DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, linescolors, Setting1::botlines1);
													}
												}
											}

											if (Setting1::style2)
											{
												if (Setting1::botst2line)
												{
													if (linneb2 == 0)
													{
														DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 25, Setting1::botlinec2, Setting1::botlines2);
													}
													else if (linneb2 == 1)
													{
														DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 25, linescolors, Setting1::botlines2);
													}
												}
											}

											if (Setting1::style3)
											{
												if (Setting1::botst3line)
												{
													if (linneb3 == 0)
													{
														DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 25, Setting1::botlinec3, Setting1::botlines3);
													}
													else if (linneb3 == 1)
													{
														DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 25, linescolors, Setting1::botlines3);
													}
												}
											}
										}
									}

									if (Setting1::botname)
									{

										if (Setting1::style1)
										{
											if (Setting1::botst1name)
											{
												std::string BotTagAlive;
												std::string BotTagFall;
												std::string BotAlive;
												std::string BotDown;
												std::string PlayerTagAlive;
												std::string PlayerTagFall;
												std::string PlayerAlive;
												std::string PlayerDown;
												if (AActor.IsBot)
												{
													//Player Name Back Sadow For P+B TAG, BOT
													DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - 35.5, Screen.Y - 34, 35, 16, ImColor(255.0f, 255.0f, 0.0f, 255.0f));
													BotTagAlive = "Bot";
													BotTagFall = "Fall";
													BotAlive = ("Computer (P) ") + to_string(AActor.TeamId);// +"   " + to_string(Distance) + "M ";
													BotDown = ("Computer (P) ") + to_string(AActor.TeamId);// +"   " + to_string(Distance) + "M ";

													//Player Name Back Sadow
													DX11::ImGui_DX11::DrawFilledRectangle(Screen.X + 70, Screen.Y - 34, 107, 16, ImColor(0.0f, 0.0f, 255.0f, 255.0f));

													if (AActor.Health <= 0)
													{
														// ESP Style1 Player Name.........
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::botnames1, BotTagFall, Screen.X - 63, Screen.Y - 49, DX11::ImGui_DX11::Color::White, true);

														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::botnames1, BotDown, Screen.X - 30, Screen.Y - 51, DX11::ImGui_DX11::Color::White, true);
													}
													else
													{
														// ESP Style1 Player Name.........
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::botnames1, BotTagAlive, Screen.X - 63, Screen.Y - 49, DX11::ImGui_DX11::Color::White, false);

														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::botnames1, BotAlive, Screen.X - 30, Screen.Y - 51, Setting1::botnamec1, true); //DX11::ImGui_DX11::Color::White, false);
													}
												}
											}
										}

										if (Setting1::style2)
										{
											if (Setting1::botst2name)
											{
												std::string BotAlive;
												std::string BotDown;
												std::string PlayerAlive;
												std::string PlayerDown;
												if (AActor.IsBot)
												{
													BotAlive = to_string(AActor.TeamId) + "." + " " + "[BOT]";// +"   " + to_string(Distance) + "M ";
													BotDown = to_string(AActor.TeamId) + "." + " " + "[BOT]";// +"   " + to_string(Distance) + "M ";

													if (AActor.Health <= 0)
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::botnames2, BotDown, Screen.X - 20, (Screen.Y - 30), DX11::ImGui_DX11::Color::Red, true);

													}
													else
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::botnames2, BotAlive, Screen.X - 20, (Screen.Y - 30), Setting1::botnamec2, true); //DX11::ImGui_DX11::Color::BotColor, true);

													}
												}
											}
										}

										if (Setting1::style3)
										{
											if (Setting1::botst3name)
											{
												std::string BotTagAlive;
												std::string BotTagFall;
												std::string PlayerTagAlive;
												std::string PlayerTagFall;

												std::string BotAlive;
												std::string BotDown;
												std::string PlayerAlive;
												std::string PlayerDown;
												if (AActor.IsBot)
												{
													BotAlive = /*to_string(AActor.TeamId) + "." + " " +*/ "Robot";// +"   " + to_string(Distance) + "M ";
													BotDown = /*to_string(AActor.TeamId) + "." + " " +*/ "Robot";// +"   " + to_string(Distance) + "M ";

													if (AActor.Health <= 0)
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::botnames3, BotDown, Screen.X - 20, (Screen.Y - 30), DX11::ImGui_DX11::Color::Red, true);

													}
													else
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::botnames3, BotAlive, Screen.X - 20, (Screen.Y - 30), Setting1::botnamec3, true); //DX11::ImGui_DX11::Color::BotColor, true);

													}
												}
											}											
										}

									}

									if (Setting::bflag)
									{
										if (AActor.IsBot)
										{
											if (Setting1::style1)
											{
												NationFlag(Screen, AActor, -50, 66, 20, 14);
											}
											if (Setting1::style2)
											{
												NationFlag(Screen, AActor, 50, 40, 20, 10);
											}
											if (Setting1::style3)
											{
												NationFlag(Screen, AActor, 50, 40, 20, 10);
											}
										}
									}

									if (Setting1::botcornerbox)
									{
										if (Setting1::style1)
										{
											if (Setting1::botst1cornerbox)
											{
												if (CornerBoxb1 == 0)
												{
													DX11::ImGui_DX11::CornerBox(Screen.X - Screen.Z / 4 - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, Setting1::botcornerboxs1, popcorn / 2, Setting1::botcornerboxc1);
												}
												else if (CornerBoxb1 == 1)
												{
													DX11::ImGui_DX11::CornerBox(Screen.X - Screen.Z / 4 - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, Setting1::botcornerboxs1, popcorn / 2, linescolors);
												}
											}
										}

										if (Setting1::style2)
										{
											if (Setting1::botst2cornerbox)
											{
												if (CornerBoxb2 == 0)
												{
													DX11::ImGui_DX11::CornerBox(Screen.X - Screen.Z / 4 - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, Setting1::botcornerboxs2, popcorn / 2, Setting1::botcornerboxc2);
												}
												else if (CornerBoxb2 == 1)
												{
													DX11::ImGui_DX11::CornerBox(Screen.X - Screen.Z / 4 - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, Setting1::botcornerboxs2, popcorn / 2, linescolors);
												}
											}
										}


										if (Setting1::style3)
										{
											if (Setting1::botst3cornerbox)
											{
												if (CornerBoxb3 == 0)
												{
													DX11::ImGui_DX11::CornerBox(Screen.X - Screen.Z / 4 - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, Setting1::botcornerboxs3, popcorn / 2, Setting1::botcornerboxc3);
												}
												else if (CornerBoxb3 == 1)
												{
													DX11::ImGui_DX11::CornerBox(Screen.X - Screen.Z / 4 - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, Setting1::botcornerboxs3, popcorn / 2, linescolors);
												}
											}
										}
									}

									if (Setting1::botfullbox)
									{
										if (Setting1::style1)
										{
											if (Setting1::botst1fullbox)
											{
												if (botfullboxb1 == 0)
												{
													DX11::ImGui_DX11::DrawRectangle(Screen.X - (Screen.Z / 4) - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, Setting1::botfullboxc1, Setting1::botfullboxs1);

												}
												else if (botfullboxb1 == 0)
												{
													DX11::ImGui_DX11::DrawRectangle(Screen.X - (Screen.Z / 4) - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, linescolors, Setting1::botfullboxs1);

												}
											}
										}

										if (Setting1::style2)
										{
											if (Setting1::botst2fullbox)
											{
												if (botfullboxb2 == 0)
												{
													DX11::ImGui_DX11::DrawRectangle(Screen.X - (Screen.Z / 4) - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, Setting1::botfullboxc2, Setting1::botfullboxs2);

												}
												else if (botfullboxb2 == 0)
												{
													DX11::ImGui_DX11::DrawRectangle(Screen.X - (Screen.Z / 4) - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, linescolors, Setting1::botfullboxs2);

												}
											}
										}

										if (Setting1::style3)
										{
											if (Setting1::botst3fullbox)
											{
												if (botfullboxb3 == 0)
												{
													DX11::ImGui_DX11::DrawRectangle(Screen.X - (Screen.Z / 4) - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, Setting1::botfullboxc3, Setting1::botfullboxs3);

												}
												else if (botfullboxb3 == 0)
												{
													DX11::ImGui_DX11::DrawRectangle(Screen.X - (Screen.Z / 4) - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, linescolors, Setting1::botfullboxs3);

												}
											}
										}
									}

									if (Setting::buid)
									{
										if (AActor.IsBot)
										{
											if (AActor.Health <= 0)
											{
												DX11::ImGui_DX11::DrawBorderText(DX11::ImGui_DX11::pRegularFont, dissize, AActor.UID, Screen.X + 17, (Screen.Y + Screen.Z) + 30, DX11::ImGui_DX11::Color::Red, true);

											}
											else
											{
												DX11::ImGui_DX11::DrawBorderText(DX11::ImGui_DX11::pRegularFont, dissize, AActor.UID, Screen.X + 17, (Screen.Y + Screen.Z) + 30, Colors::plyerdistance, true);

											}
										}
									}

									if (Setting1::bothealth)
									{
										if (Setting1::style1)
										{
											if (Setting1::botst1health)
											{
												if (AActor.IsBot)
												{
													if (hpb1 == 0)
													{
														if (AActor.TeamId == 1 || AActor.TeamId == 2 || AActor.TeamId == 3 || AActor.TeamId == 4
															|| AActor.TeamId == 5 || AActor.TeamId == 6 || AActor.TeamId == 7 || AActor.TeamId == 8
															|| AActor.TeamId == 9 || AActor.TeamId == 10 || AActor.TeamId == 11 || AActor.TeamId == 12
															|| AActor.TeamId == 13 || AActor.TeamId == 14 || AActor.TeamId == 15 || AActor.TeamId == 16
															|| AActor.TeamId == 17 || AActor.TeamId == 18 || AActor.TeamId == 19 || AActor.TeamId == 20
															|| AActor.TeamId == 21 || AActor.TeamId == 22 || AActor.TeamId == 23 || AActor.TeamId == 24
															|| AActor.TeamId == 25 || AActor.TeamId == 26 || AActor.TeamId == 27 || AActor.TeamId == 28
															|| AActor.TeamId == 29 || AActor.TeamId == 30 || AActor.TeamId == 31 || AActor.TeamId == 32
															|| AActor.TeamId == 33 || AActor.TeamId == 34 || AActor.TeamId == 35 || AActor.TeamId == 36
															|| AActor.TeamId == 37 || AActor.TeamId == 38 || AActor.TeamId == 39 || AActor.TeamId == 40
															|| AActor.TeamId == 41 || AActor.TeamId == 42 || AActor.TeamId == 43 || AActor.TeamId == 44
															|| AActor.TeamId == 45 || AActor.TeamId == 46 || AActor.TeamId == 47 || AActor.TeamId == 48
															|| AActor.TeamId == 49 || AActor.TeamId == 50 || AActor.TeamId == 51 || AActor.TeamId == 52
															|| AActor.TeamId == 43 || AActor.TeamId == 54 || AActor.TeamId == 55 || AActor.TeamId == 56
															|| AActor.TeamId == 57 || AActor.TeamId == 58 || AActor.TeamId == 59 || AActor.TeamId == 60
															|| AActor.TeamId == 61 || AActor.TeamId == 62 || AActor.TeamId == 63 || AActor.TeamId == 64
															|| AActor.TeamId == 65 || AActor.TeamId == 66 || AActor.TeamId == 67 || AActor.TeamId == 68
															|| AActor.TeamId == 67 || AActor.TeamId == 68 || AActor.TeamId == 69 || AActor.TeamId == 70
															|| AActor.TeamId == 71 || AActor.TeamId == 72 || AActor.TeamId == 73 || AActor.TeamId == 74
															|| AActor.TeamId == 75 || AActor.TeamId == 76 || AActor.TeamId == 77 || AActor.TeamId == 78
															|| AActor.TeamId == 79 || AActor.TeamId == 80 || AActor.TeamId == 81 || AActor.TeamId == 82
															|| AActor.TeamId == 83 || AActor.TeamId == 84 || AActor.TeamId == 85 || AActor.TeamId == 86
															|| AActor.TeamId == 87 || AActor.TeamId == 88 || AActor.TeamId == 99 || AActor.TeamId == 90
															|| AActor.TeamId == 91 || AActor.TeamId == 92 || AActor.TeamId == 93 || AActor.TeamId == 94
															|| AActor.TeamId == 95 || AActor.TeamId == 96 || AActor.TeamId == 97 || AActor.TeamId == 98
															|| AActor.TeamId == 99 || AActor.TeamId == 100)
														{

															DX11::ImGui_DX11::DrawBlood(Screen.X - 70, Screen.Y - 34, 140, 3.0, AActor.Health);
														}
														else
														{
															if (Data::CharacterModel_Health == "CharacterModel"/* || Data::LocalPawn == "In Training" || Data::LocalPawn == "In Lobby"*/)
															{
																DX11::ImGui_DX11::DrawBlood3(Screen.X - 70, Screen.Y - 34, 140, 3.0, AActor.Health);
															}
															else
															{
																DX11::ImGui_DX11::DrawBlood(Screen.X - 70, Screen.Y - 34, 140, 3.0, AActor.Health);
															}
														}
													}
													else if (hpb1 == 1)
													{
														std::string hp100 = "HP : 100";
														std::string hp90 = "HP : 90";
														std::string hp80 = "HP : 80";
														std::string hp60 = "HP : 60";
														std::string hp40 = "HP : 40";
														std::string hp20 = "HP : 20";
														std::string hp10 = "HP : 10";
														std::string hp0 = "HP : 0";

														if (AActor.Health > 99.0)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::bothealths1, hp100, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::bothealthc1, true);

														}
														if (AActor.Health > 90.0 && AActor.Health <= 99.0)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::bothealths1, hp90, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::bothealthc1, true);

														}
														if (AActor.Health > 80.0 && AActor.Health <= 90.0)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::bothealths1, hp80, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::bothealthc1, true);

														}
														if (AActor.Health > 60.0 && AActor.Health <= 80.0)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::bothealths1, hp60, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::bothealthc1, true);

														}
														if (AActor.Health > 40.0 && AActor.Health <= 60.0)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::bothealths1, hp40, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::bothealthc1, true);

														}
														if (AActor.Health > 20.0 && AActor.Health <= 40.0)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::bothealths1, hp20, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::bothealthc1, true);

														}
														if (AActor.Health > 10.0 && AActor.Health <= 20.0)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::bothealths1, hp10, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::bothealthc1, true);

														}
														if (AActor.Health > 0.0 && AActor.Health <= 10.0)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::bothealths1, hp0, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::bothealthc1, true);

														}
													}

												}

											}
										}

										if (Setting1::style2)
										{
											if (Setting1::botst2health)
											{
												if (AActor.IsBot)
												{
													if (hpb2 == 0)
													{
														DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - (Screen.Z / 4) - 2.5, (Screen.Y - 4) + (Screen.Z + 5), 5, (Screen.Z + 8), DX11::ImGui_DX11::Color::Black);

														if (AActor.Health > 70.0)
														{
															DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 2, (Screen.Z + 5) * AActor.Health / AActor.HealthMax, DX11::ImGui_DX11::Color::Green);
														}
														if (AActor.Health > 30.0 && AActor.Health <= 70.0)
														{
															DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 2, (Screen.Z + 5) * AActor.Health / AActor.HealthMax, DX11::ImGui_DX11::Color::Yellow);
														}
														if (AActor.Health > 0.0 && AActor.Health <= 30.0)
														{
															DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 2, (Screen.Z + 5) * AActor.Health / AActor.HealthMax, DX11::ImGui_DX11::Color::Red);

														}
													}
													else if (hpb2 == 1)
													{
														std::string hp100 = "HP : 100";
														std::string hp90 = "HP : 90";
														std::string hp80 = "HP : 80";
														std::string hp60 = "HP : 60";
														std::string hp40 = "HP : 40";
														std::string hp20 = "HP : 20";
														std::string hp10 = "HP : 10";
														std::string hp0 = "HP : 0";

														if (AActor.Health > 99.0)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::bothealths2, hp100, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::bothealthc2, true);

														}
														if (AActor.Health > 90.0 && AActor.Health <= 99.0)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::bothealths2, hp90, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::bothealthc2, true);

														}
														if (AActor.Health > 80.0 && AActor.Health <= 90.0)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::bothealths2, hp80, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::bothealthc2, true);

														}
														if (AActor.Health > 60.0 && AActor.Health <= 80.0)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::bothealths2, hp60, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::bothealthc2, true);

														}
														if (AActor.Health > 40.0 && AActor.Health <= 60.0)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::bothealths2, hp40, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::bothealthc2, true);

														}
														if (AActor.Health > 20.0 && AActor.Health <= 40.0)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::bothealths2, hp20, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::bothealthc2, true);

														}
														if (AActor.Health > 10.0 && AActor.Health <= 20.0)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::bothealths2, hp10, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::bothealthc2, true);

														}
														if (AActor.Health > 0.0 && AActor.Health <= 10.0)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::bothealths2, hp0, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::bothealthc2, true);

														}
													}
												}

											}											
										}

										if (Setting1::style3)
										{
											if (Setting1::botst3health)
											{
												if (AActor.IsBot)
												{
													if (hpb3 == 0)
													{
														if (AActor.TeamId == 1 || AActor.TeamId == 2 || AActor.TeamId == 3 || AActor.TeamId == 4
															|| AActor.TeamId == 5 || AActor.TeamId == 6 || AActor.TeamId == 7 || AActor.TeamId == 8
															|| AActor.TeamId == 9 || AActor.TeamId == 10 || AActor.TeamId == 11 || AActor.TeamId == 12
															|| AActor.TeamId == 13 || AActor.TeamId == 14 || AActor.TeamId == 15 || AActor.TeamId == 16
															|| AActor.TeamId == 17 || AActor.TeamId == 18 || AActor.TeamId == 19 || AActor.TeamId == 20
															|| AActor.TeamId == 21 || AActor.TeamId == 22 || AActor.TeamId == 23 || AActor.TeamId == 24
															|| AActor.TeamId == 25 || AActor.TeamId == 26 || AActor.TeamId == 27 || AActor.TeamId == 28
															|| AActor.TeamId == 29 || AActor.TeamId == 30 || AActor.TeamId == 31 || AActor.TeamId == 32
															|| AActor.TeamId == 33 || AActor.TeamId == 34 || AActor.TeamId == 35 || AActor.TeamId == 36
															|| AActor.TeamId == 37 || AActor.TeamId == 38 || AActor.TeamId == 39 || AActor.TeamId == 40
															|| AActor.TeamId == 41 || AActor.TeamId == 42 || AActor.TeamId == 43 || AActor.TeamId == 44
															|| AActor.TeamId == 45 || AActor.TeamId == 46 || AActor.TeamId == 47 || AActor.TeamId == 48
															|| AActor.TeamId == 49 || AActor.TeamId == 50 || AActor.TeamId == 51 || AActor.TeamId == 52
															|| AActor.TeamId == 43 || AActor.TeamId == 54 || AActor.TeamId == 55 || AActor.TeamId == 56
															|| AActor.TeamId == 57 || AActor.TeamId == 58 || AActor.TeamId == 59 || AActor.TeamId == 60
															|| AActor.TeamId == 61 || AActor.TeamId == 62 || AActor.TeamId == 63 || AActor.TeamId == 64
															|| AActor.TeamId == 65 || AActor.TeamId == 66 || AActor.TeamId == 67 || AActor.TeamId == 68
															|| AActor.TeamId == 67 || AActor.TeamId == 68 || AActor.TeamId == 69 || AActor.TeamId == 70
															|| AActor.TeamId == 71 || AActor.TeamId == 72 || AActor.TeamId == 73 || AActor.TeamId == 74
															|| AActor.TeamId == 75 || AActor.TeamId == 76 || AActor.TeamId == 77 || AActor.TeamId == 78
															|| AActor.TeamId == 79 || AActor.TeamId == 80 || AActor.TeamId == 81 || AActor.TeamId == 82
															|| AActor.TeamId == 83 || AActor.TeamId == 84 || AActor.TeamId == 85 || AActor.TeamId == 86
															|| AActor.TeamId == 87 || AActor.TeamId == 88 || AActor.TeamId == 99 || AActor.TeamId == 90
															|| AActor.TeamId == 91 || AActor.TeamId == 92 || AActor.TeamId == 93 || AActor.TeamId == 94
															|| AActor.TeamId == 95 || AActor.TeamId == 96 || AActor.TeamId == 97 || AActor.TeamId == 98
															|| AActor.TeamId == 99 || AActor.TeamId == 100)
														{

															DX11::ImGui_DX11::DrawBlood(Screen.X - 30, Screen.Y - 14, 60, 3.0, AActor.Health);
														}
														else
														{
															if (Data::CharacterModel_Health == "CharacterModel"/* || Data::LocalPawn == "In Training" || Data::LocalPawn == "In Lobby"*/)
															{
																DX11::ImGui_DX11::DrawBlood3(Screen.X - 30, Screen.Y - 14, 60, 3.0, AActor.Health);
															}
															else
															{
																DX11::ImGui_DX11::DrawBlood(Screen.X - 30, Screen.Y - 14, 60, 3.0, AActor.Health);
															}
														}
													}
													else if (hpb3 == 0)
													{
														std::string hp100 = "HP : 100";
														std::string hp90 = "HP : 90";
														std::string hp80 = "HP : 80";
														std::string hp60 = "HP : 60";
														std::string hp40 = "HP : 40";
														std::string hp20 = "HP : 20";
														std::string hp10 = "HP : 10";
														std::string hp0 = "HP : 0";

														if (AActor.Health > 99.0)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::bothealths3, hp100, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::bothealthc3, true);

														}
														if (AActor.Health > 90.0 && AActor.Health <= 99.0)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::bothealths3, hp90, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::bothealthc3, true);

														}
														if (AActor.Health > 80.0 && AActor.Health <= 90.0)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::bothealths3, hp80, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::bothealthc3, true);

														}
														if (AActor.Health > 60.0 && AActor.Health <= 80.0)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::bothealths3, hp60, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::bothealthc3, true);

														}
														if (AActor.Health > 40.0 && AActor.Health <= 60.0)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::bothealths3, hp40, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::bothealthc3, true);

														}
														if (AActor.Health > 20.0 && AActor.Health <= 40.0)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::bothealths3, hp20, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::bothealthc3, true);

														}
														if (AActor.Health > 10.0 && AActor.Health <= 20.0)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::bothealths3, hp10, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::bothealthc3, true);

														}
														if (AActor.Health > 0.0 && AActor.Health <= 10.0)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::bothealths3, hp0, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::bothealthc3, true);

														}
													}
												}

											}
										}

									}

									if (Setting1::botBone)
									{
										if (Setting1::style1)
										{
											if (Setting1::botst1Bone)
											{
												HeadPos = AActor.HeadPos;
												HeadPos.Z += 7;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, HeadPos, Head, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.ChestPos, Chest, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.PelvisPos, Pelvis, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lSholderPos, lSholder, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rSholderPos, rSholder, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lElbowPos, lElbow, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rElbowPos, rElbow, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lWristPos, lWrist, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rWristPos, rWrist, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lThighPos, lThigh, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rThighPos, rThigh, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lKneePos, lKnee, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rKneePos, rKnee, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lAnklePos, lAnkle, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rAnklePos, rAnkle, &Distance)) continue;

												if (skeleeb1 == 0)
												{
													if (AActor.Address == Setting1::CurrentTargetAddress)
													{
														Setting1::botBonec1 = DX11::ImGui_DX11::Color::Red;
													}
													else
													{
														Setting1::botBonec1 = Setting1::botBonec1;
													}
													DX11::ImGui_DX11::DrawCircle(Head.X, Head.Y, Screen.Z / 12, Setting1::botBonec1, Setting1::botBones1);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, Pelvis.X, Pelvis.Y, Setting1::botBonec1, Setting1::botBones1);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, lSholder.X, lSholder.Y, Setting1::botBonec1, Setting1::botBones1);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, rSholder.X, rSholder.Y, Setting1::botBonec1, Setting1::botBones1);
													DX11::ImGui_DX11::DrawLine(lSholder.X, lSholder.Y, lElbow.X, lElbow.Y, Setting1::botBonec1, Setting1::botBones1);
													DX11::ImGui_DX11::DrawLine(rSholder.X, rSholder.Y, rElbow.X, rElbow.Y, Setting1::botBonec1, Setting1::botBones1);
													DX11::ImGui_DX11::DrawLine(lElbow.X, lElbow.Y, lWrist.X, lWrist.Y, Setting1::botBonec1, Setting1::botBones1);
													DX11::ImGui_DX11::DrawLine(rElbow.X, rElbow.Y, rWrist.X, rWrist.Y, Setting1::botBonec1, Setting1::botBones1);
													DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, lThigh.X, lThigh.Y, Setting1::botBonec1, Setting1::botBones1);
													DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, rThigh.X, rThigh.Y, Setting1::botBonec1, Setting1::botBones1);
													DX11::ImGui_DX11::DrawLine(lThigh.X, lThigh.Y, lKnee.X, lKnee.Y, Setting1::botBonec1, Setting1::botBones1);
													DX11::ImGui_DX11::DrawLine(rThigh.X, rThigh.Y, rKnee.X, rKnee.Y, Setting1::botBonec1, Setting1::botBones1);
													DX11::ImGui_DX11::DrawLine(lKnee.X, lKnee.Y, lAnkle.X, lAnkle.Y, Setting1::botBonec1, Setting1::botBones1);
													DX11::ImGui_DX11::DrawLine(rKnee.X, rKnee.Y, rAnkle.X, rAnkle.Y, Setting1::botBonec1, Setting1::botBones1);
												}
												else if (skeleeb1 == 1)
												{
													if (AActor.Address == Setting1::CurrentTargetAddress)
													{
														linescolors = DX11::ImGui_DX11::Color::Red;
													}
													else
													{
														linescolors = linescolors;
													}
													DX11::ImGui_DX11::DrawCircle(Head.X, Head.Y, Screen.Z / 12, linescolors, Setting1::botBones1);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, Pelvis.X, Pelvis.Y, linescolors, Setting1::botBones1);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, lSholder.X, lSholder.Y, linescolors, Setting1::botBones1);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, rSholder.X, rSholder.Y, linescolors, Setting1::botBones1);
													DX11::ImGui_DX11::DrawLine(lSholder.X, lSholder.Y, lElbow.X, lElbow.Y, linescolors, Setting1::botBones1);
													DX11::ImGui_DX11::DrawLine(rSholder.X, rSholder.Y, rElbow.X, rElbow.Y, linescolors, Setting1::botBones1);
													DX11::ImGui_DX11::DrawLine(lElbow.X, lElbow.Y, lWrist.X, lWrist.Y, linescolors, Setting1::botBones1);
													DX11::ImGui_DX11::DrawLine(rElbow.X, rElbow.Y, rWrist.X, rWrist.Y, linescolors, Setting1::botBones1);
													DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, lThigh.X, lThigh.Y, linescolors, Setting1::botBones1);
													DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, rThigh.X, rThigh.Y, linescolors, Setting1::botBones1);
													DX11::ImGui_DX11::DrawLine(lThigh.X, lThigh.Y, lKnee.X, lKnee.Y, linescolors, Setting1::botBones1);
													DX11::ImGui_DX11::DrawLine(rThigh.X, rThigh.Y, rKnee.X, rKnee.Y, linescolors, Setting1::botBones1);
													DX11::ImGui_DX11::DrawLine(lKnee.X, lKnee.Y, lAnkle.X, lAnkle.Y, linescolors, Setting1::botBones1);
													DX11::ImGui_DX11::DrawLine(rKnee.X, rKnee.Y, rAnkle.X, rAnkle.Y, linescolors, Setting1::botBones1);
												}
											}
										}

										if (Setting1::style2)
										{
											if (Setting1::botst2Bone)
											{
												HeadPos = AActor.HeadPos;
												HeadPos.Z += 7;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, HeadPos, Head, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.ChestPos, Chest, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.PelvisPos, Pelvis, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lSholderPos, lSholder, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rSholderPos, rSholder, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lElbowPos, lElbow, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rElbowPos, rElbow, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lWristPos, lWrist, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rWristPos, rWrist, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lThighPos, lThigh, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rThighPos, rThigh, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lKneePos, lKnee, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rKneePos, rKnee, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lAnklePos, lAnkle, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rAnklePos, rAnkle, &Distance)) continue;

												if (skeleeb2 == 0)
												{
													if (AActor.Address == Setting1::CurrentTargetAddress)
													{
														Setting1::botBonec2 = DX11::ImGui_DX11::Color::Red;
													}
													else
													{
														Setting1::botBonec2 = Setting1::botBonec2;
													}
													DX11::ImGui_DX11::DrawCircle(Head.X, Head.Y, Screen.Z / 12, Setting1::botBonec2, Setting1::botBones2);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, Pelvis.X, Pelvis.Y, Setting1::botBonec2, Setting1::botBones2);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, lSholder.X, lSholder.Y, Setting1::botBonec2, Setting1::botBones2);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, rSholder.X, rSholder.Y, Setting1::botBonec2, Setting1::botBones2);
													DX11::ImGui_DX11::DrawLine(lSholder.X, lSholder.Y, lElbow.X, lElbow.Y, Setting1::botBonec2, Setting1::botBones2);
													DX11::ImGui_DX11::DrawLine(rSholder.X, rSholder.Y, rElbow.X, rElbow.Y, Setting1::botBonec2, Setting1::botBones2);
													DX11::ImGui_DX11::DrawLine(lElbow.X, lElbow.Y, lWrist.X, lWrist.Y, Setting1::botBonec2, Setting1::botBones2);
													DX11::ImGui_DX11::DrawLine(rElbow.X, rElbow.Y, rWrist.X, rWrist.Y, Setting1::botBonec2, Setting1::botBones2);
													DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, lThigh.X, lThigh.Y, Setting1::botBonec2, Setting1::botBones2);
													DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, rThigh.X, rThigh.Y, Setting1::botBonec2, Setting1::botBones2);
													DX11::ImGui_DX11::DrawLine(lThigh.X, lThigh.Y, lKnee.X, lKnee.Y, Setting1::botBonec2, Setting1::botBones2);
													DX11::ImGui_DX11::DrawLine(rThigh.X, rThigh.Y, rKnee.X, rKnee.Y, Setting1::botBonec2, Setting1::botBones2);
													DX11::ImGui_DX11::DrawLine(lKnee.X, lKnee.Y, lAnkle.X, lAnkle.Y, Setting1::botBonec2, Setting1::botBones2);
													DX11::ImGui_DX11::DrawLine(rKnee.X, rKnee.Y, rAnkle.X, rAnkle.Y, Setting1::botBonec2, Setting1::botBones2);
												}
												else if (skeleeb2 == 1)
												{
													if (AActor.Address == Setting1::CurrentTargetAddress)
													{
														linescolors = DX11::ImGui_DX11::Color::Red;
													}
													else
													{
														linescolors = linescolors;
													}
													DX11::ImGui_DX11::DrawCircle(Head.X, Head.Y, Screen.Z / 12, linescolors, Setting1::botBones2);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, Pelvis.X, Pelvis.Y, linescolors, Setting1::botBones2);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, lSholder.X, lSholder.Y, linescolors, Setting1::botBones2);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, rSholder.X, rSholder.Y, linescolors, Setting1::botBones2);
													DX11::ImGui_DX11::DrawLine(lSholder.X, lSholder.Y, lElbow.X, lElbow.Y, linescolors, Setting1::botBones2);
													DX11::ImGui_DX11::DrawLine(rSholder.X, rSholder.Y, rElbow.X, rElbow.Y, linescolors, Setting1::botBones2);
													DX11::ImGui_DX11::DrawLine(lElbow.X, lElbow.Y, lWrist.X, lWrist.Y, linescolors, Setting1::botBones2);
													DX11::ImGui_DX11::DrawLine(rElbow.X, rElbow.Y, rWrist.X, rWrist.Y, linescolors, Setting1::botBones2);
													DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, lThigh.X, lThigh.Y, linescolors, Setting1::botBones2);
													DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, rThigh.X, rThigh.Y, linescolors, Setting1::botBones2);
													DX11::ImGui_DX11::DrawLine(lThigh.X, lThigh.Y, lKnee.X, lKnee.Y, linescolors, Setting1::botBones2);
													DX11::ImGui_DX11::DrawLine(rThigh.X, rThigh.Y, rKnee.X, rKnee.Y, linescolors, Setting1::botBones2);
													DX11::ImGui_DX11::DrawLine(lKnee.X, lKnee.Y, lAnkle.X, lAnkle.Y, linescolors, Setting1::botBones2);
													DX11::ImGui_DX11::DrawLine(rKnee.X, rKnee.Y, rAnkle.X, rAnkle.Y, linescolors, Setting1::botBones2);
												}
											}
										}

										if (Setting1::style3)
										{
											if (Setting1::botst3Bone)
											{
												HeadPos = AActor.HeadPos;
												HeadPos.Z += 7;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, HeadPos, Head, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.ChestPos, Chest, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.PelvisPos, Pelvis, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lSholderPos, lSholder, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rSholderPos, rSholder, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lElbowPos, lElbow, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rElbowPos, rElbow, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lWristPos, lWrist, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rWristPos, rWrist, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lThighPos, lThigh, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rThighPos, rThigh, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lKneePos, lKnee, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rKneePos, rKnee, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lAnklePos, lAnkle, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rAnklePos, rAnkle, &Distance)) continue;

												if (skeleeb3 == 0)
												{
													if (AActor.Address == Setting1::CurrentTargetAddress)
													{
														Setting1::botBonec3 = DX11::ImGui_DX11::Color::Red;
													}
													else
													{
														Setting1::botBonec3 = Setting1::botBonec3;
													}
													DX11::ImGui_DX11::DrawCircle(Head.X, Head.Y, Screen.Z / 12, Setting1::botBonec3, Setting1::botBones3);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, Pelvis.X, Pelvis.Y, Setting1::botBonec3, Setting1::botBones3);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, lSholder.X, lSholder.Y, Setting1::botBonec3, Setting1::botBones3);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, rSholder.X, rSholder.Y, Setting1::botBonec3, Setting1::botBones3);
													DX11::ImGui_DX11::DrawLine(lSholder.X, lSholder.Y, lElbow.X, lElbow.Y, Setting1::botBonec3, Setting1::botBones3);
													DX11::ImGui_DX11::DrawLine(rSholder.X, rSholder.Y, rElbow.X, rElbow.Y, Setting1::botBonec3, Setting1::botBones3);
													DX11::ImGui_DX11::DrawLine(lElbow.X, lElbow.Y, lWrist.X, lWrist.Y, Setting1::botBonec3, Setting1::botBones3);
													DX11::ImGui_DX11::DrawLine(rElbow.X, rElbow.Y, rWrist.X, rWrist.Y, Setting1::botBonec3, Setting1::botBones3);
													DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, lThigh.X, lThigh.Y, Setting1::botBonec3, Setting1::botBones3);
													DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, rThigh.X, rThigh.Y, Setting1::botBonec3, Setting1::botBones3);
													DX11::ImGui_DX11::DrawLine(lThigh.X, lThigh.Y, lKnee.X, lKnee.Y, Setting1::botBonec3, Setting1::botBones3);
													DX11::ImGui_DX11::DrawLine(rThigh.X, rThigh.Y, rKnee.X, rKnee.Y, Setting1::botBonec3, Setting1::botBones3);
													DX11::ImGui_DX11::DrawLine(lKnee.X, lKnee.Y, lAnkle.X, lAnkle.Y, Setting1::botBonec3, Setting1::botBones3);
													DX11::ImGui_DX11::DrawLine(rKnee.X, rKnee.Y, rAnkle.X, rAnkle.Y, Setting1::botBonec3, Setting1::botBones3);
												}
												else if (skeleeb3 == 1)
												{
													if (AActor.Address == Setting1::CurrentTargetAddress)
													{
														linescolors = DX11::ImGui_DX11::Color::Red;
													}
													else
													{
														linescolors = linescolors;
													}
													DX11::ImGui_DX11::DrawCircle(Head.X, Head.Y, Screen.Z / 12, linescolors, Setting1::botBones3);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, Pelvis.X, Pelvis.Y, linescolors, Setting1::botBones3);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, lSholder.X, lSholder.Y, linescolors, Setting1::botBones3);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, rSholder.X, rSholder.Y, linescolors, Setting1::botBones3);
													DX11::ImGui_DX11::DrawLine(lSholder.X, lSholder.Y, lElbow.X, lElbow.Y, linescolors, Setting1::botBones3);
													DX11::ImGui_DX11::DrawLine(rSholder.X, rSholder.Y, rElbow.X, rElbow.Y, linescolors, Setting1::botBones3);
													DX11::ImGui_DX11::DrawLine(lElbow.X, lElbow.Y, lWrist.X, lWrist.Y, linescolors, Setting1::botBones3);
													DX11::ImGui_DX11::DrawLine(rElbow.X, rElbow.Y, rWrist.X, rWrist.Y, linescolors, Setting1::botBones3);
													DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, lThigh.X, lThigh.Y, linescolors, Setting1::botBones3);
													DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, rThigh.X, rThigh.Y, linescolors, Setting1::botBones3);
													DX11::ImGui_DX11::DrawLine(lThigh.X, lThigh.Y, lKnee.X, lKnee.Y, linescolors, Setting1::botBones3);
													DX11::ImGui_DX11::DrawLine(rThigh.X, rThigh.Y, rKnee.X, rKnee.Y, linescolors, Setting1::botBones3);
													DX11::ImGui_DX11::DrawLine(lKnee.X, lKnee.Y, lAnkle.X, lAnkle.Y, linescolors, Setting1::botBones3);
													DX11::ImGui_DX11::DrawLine(rKnee.X, rKnee.Y, rAnkle.X, rAnkle.Y, linescolors, Setting1::botBones3);
												}
											}
										}

									}

									if (Setting1::botweapon)
									{
										if (Setting1::style1)
										{
											if (Setting1::botst1weapon)
											{
												if (Setting1::botst1Weapons_iconsH)
												{
													if (AActor.IsBot)
													{
														Weapons_iconsH_B(Screen, AActor, 50, 40, 20, 10);
													}
												}
												else
												{
													if (Setting1::botst1weapon)
													{
														if (AActor.IsBot)
														{
															//Text = (AActor.Weapon);
															weapon = AActor.Weapon;

															if (AActor.Health <= 0)
															{
																if (AActor.Weapon == "Fist")
																{
																	DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::botweaponFalses1, weapon, Screen.X - 10, (Screen.Y - 70), DX11::ImGui_DX11::Color::Red, true);

																}
																else
																{
																	DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::botweapons1, weapon, Screen.X - 10, (Screen.Y - 70), DX11::ImGui_DX11::Color::Red, true);

																}
															}
															else
															{
																if (AActor.Weapon == "Fist")
																{
																	DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::botweaponFalses1, weapon, Screen.X - 10, (Screen.Y - 70), Setting1::botweaponFalsec1, false); //DX11::ImGui_DX11::Color::Green, false);

																}
																else
																{
																	DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::botweapons1, weapon, Screen.X - 10, (Screen.Y - 70), Setting1::botweaponc1, false); //DX11::ImGui_DX11::Color::Green, false);

																}
															}
														}
													}
												}
											}
										}

										if (Setting1::style2)
										{
											if (Setting1::botst2weapon)
											{
												if (Setting1::botst2Weapons_iconsH)
												{
													if (AActor.IsBot)
													{
														Weapons_iconsH_B(Screen, AActor, 50, 40, 20, 10);
													}
												}
												else
												{
													if (Setting1::botst2weapon)
													{
														if (AActor.IsBot)
														{
															Text = (AActor.Weapon + " | ") + (dist);
															//weapon = AActor.Weapon;

															if (AActor.Health <= 0)
															{
																if (AActor.Weapon == "Fist")
																{
																	DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::botweaponFalses2, Text, Screen.X - 32, (Screen.Y + Screen.Z), DX11::ImGui_DX11::Color::Red, true);

																}
																else
																{
																	DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::botweapons2, Text, Screen.X - 32, (Screen.Y + Screen.Z), DX11::ImGui_DX11::Color::Red, true);

																}
															}
															else
															{
																if (AActor.Weapon == "Fist")
																{
																	DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::botweaponFalses2, Text, Screen.X - 32, (Screen.Y + Screen.Z), Setting1::botweaponFalsec2, false); //DX11::ImGui_DX11::Color::Green, false);

																}
																else
																{
																	DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::botweapons2, Text, Screen.X - 32, (Screen.Y + Screen.Z), Setting1::botweaponc2, false); //DX11::ImGui_DX11::Color::Green, false);

																}
															}
														}
													}
												}
											}
										}

										if (Setting1::style3)
										{
											if (Setting1::botst3weapon)
											{
												if (Setting1::botst3Weapons_iconsH)
												{
													if (AActor.IsBot)
													{
														Weapons_iconsH_B(Screen, AActor, 50, 40, 20, 10);
													}
												}
												else
												{
													if (Setting1::botst3weapon)
													{
														if (AActor.IsBot)
														{
															//Text = (AActor.Weapon + " | ") + (dist);
															weapon = AActor.Weapon;

															if (AActor.Health <= 0)
															{
																if (AActor.Weapon == "Fist")
																{
																	DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::botweaponFalses3, weapon, Screen.X - 10, (Screen.Y + Screen.Z + 25), DX11::ImGui_DX11::Color::Red, true);

																}
																else
																{
																	DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::botweapons3, weapon, Screen.X - 10, (Screen.Y + Screen.Z + 25), DX11::ImGui_DX11::Color::Red, true);

																}
															}
															else
															{
																if (AActor.Weapon == "Fist")
																{
																	DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::botweaponFalses3, weapon, Screen.X - 10, (Screen.Y + Screen.Z + 25), Setting1::botweaponFalsec3, false); //DX11::ImGui_DX11::Color::Green, false);

																}
																else
																{
																	DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::botweapons3, weapon, Screen.X - 10, (Screen.Y + Screen.Z + 25), Setting1::botweaponc3, false); //DX11::ImGui_DX11::Color::Green, false);

																}
															}
														}

													}
												}
											}
										}
										
									}

									if (Setting1::botdistance)
									{
										if (Setting1::style1)
										{
											if (Setting1::botst1distance)
											{
												if (AActor.IsBot)
												{
													//Text = (dist);
													Text = dist = std::to_string(Distance);
													if (AActor.Health <= 0)
													{
														DX11::ImGui_DX11::DrawImage(DX11::PlayerTagDistance_DownLogo0, Screen.X - 10, Screen.Y - 14, 13, 7);
														//Player Name Back Sadow For Distance
														DX11::ImGui_DX11::DrawFilledRectangle(Screen.X + 12, Screen.Y - 15, 30, 15, ImColor(0.0f, 0.0f, 0.0f, 255.0f));

														
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::botdistances1, Text, Screen.X - 10, (Screen.Y - 32), DX11::ImGui_DX11::Color::Red, true);

													}
													else
													{

														DX11::ImGui_DX11::DrawImage(DX11::PlayerTagDistance_DownLogo0, Screen.X - 10, Screen.Y - 14, 13, 7);
														//Player Name Back Sadow For Distance
														DX11::ImGui_DX11::DrawFilledRectangle(Screen.X + 12, Screen.Y - 15, 30, 15, ImColor(0.0f, 0.0f, 0.0f, 255.0f));

														
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::botdistances1, Text, Screen.X - 10, (Screen.Y - 32), Setting1::botdistancec1, false); //DX11::ImGui_DX11::Color::Green, false);

													}
												}

											}
											
											
										}

										if (Setting1::style2)
										{
											if (Setting1::botst2distance)
											{
												if (AActor.IsBot)
												{
													//Text = dist;
													if (AActor.Health <= 0)
													{
														//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::botdistances2, Text, Screen.X - 10, (Screen.Y + Screen.Z + 10), DX11::ImGui_DX11::Color::Red, true);

													}
													else
													{
														//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::botdistances2, Text, Screen.X - 10, (Screen.Y + Screen.Z + 10), Setting1::botdistancec2, false); //DX11::ImGui_DX11::Color::Green, false);

													}
												}

											}
											
										}

										if (Setting1::style3)
										{
											if (Setting1::botst3distance)
											{
												if (AActor.IsBot)
												{
													Text = dist;
													if (AActor.Health <= 0)
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::botdistances3, Text, Screen.X - 10, (Screen.Y + Screen.Z + 10), DX11::ImGui_DX11::Color::Red, true);

													}
													else
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::botdistances3, Text, Screen.X - 10, (Screen.Y + Screen.Z + 10), Setting1::botdistancec3, false); //DX11::ImGui_DX11::Color::Green, false);

													}
												}
											}
											
										}
									}

									if (Setting::botStatus)
									{

										if (Setting::botStatus)//3 working
										{
											std::string playerstatus = AActor.playerstatus.c_str();
											if (playerstatus == "Aiming" || playerstatus == "Knocked" || playerstatus == "Driving Vehicle" || playerstatus == "Driving Boat")//00ff
											{
												DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 14, playerstatus, Screen.X - 20, (Screen.Y + 25 + Screen.Z), DX11::ImGui_DX11::Color::enem, false);
											}
											else
											{
												DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 12, playerstatus, Screen.X - 20, (Screen.Y + 25 + Screen.Z), DX11::ImGui_DX11::Color::White, false);
											}
										}
									}

								}

								if (!AActor.IsBot)
								{
									if (!Setting::enemyoffscreen)
									{
										if (Setting1::playerline)
										{
											if (Setting1::style1)
											{
												if (Setting1::playerst1line)
												{
													if (linnep1 == 0)
													{
														DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, Setting1::playerlinec1, Setting1::playerlines1);

													}
													else if (linnep1 == 1)
													{
														DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, linescolors, Setting1::playerlines1);

													}
												}
												
												
											}

											if (Setting1::style2)
											{
												if (Setting1::playerst2line)
												{
													if (linnep2 == 0)
													{
														DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 25, Setting1::playerlinec2, Setting1::playerlines2);
													}
													else if (linnep2 == 1)
													{
														DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 25, linescolors, Setting1::playerlines2);
													}
												}
												
												

											}

											if (Setting1::style3)
											{
												if (Setting1::playerst3line)
												{
													if (linnep3 == 0)
													{
														DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 25, Setting1::playerlinec3, Setting1::playerlines3);
													}
													else if (linnep3 == 1)
													{
														DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 25, linescolors, Setting1::playerlines3);
													}
												}
												

											}

										}
									}

									if (Setting1::playername)
									{

										if (Setting1::style1)
										{
											if (Setting1::playerst1name)
											{
												std::string BotTagAlive;
												std::string BotTagFall;
												std::string BotAlive;
												std::string BotDown;
												std::string PlayerTagAlive;
												std::string PlayerTagFall;
												std::string PlayerAlive;
												std::string PlayerDown;

												//Player Name Back Sadow For P+B TAG, Player
												DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - 35.5, Screen.Y - 34, 35, 16, ImColor(255.0f, 225.0f, 0.0f, 255.0f));
												PlayerTagAlive = "Man";
												PlayerTagFall = "Fall";
												PlayerAlive = (AActor.Name) + " | " + to_string(AActor.TeamId).c_str();// +"   " + to_string(Distance) + "M ";
												PlayerDown = (AActor.Name) + " | " + to_string(AActor.TeamId).c_str();// +"   " + to_string(Distance) + "M ";

												//Player Name Back Sadow
												DX11::ImGui_DX11::DrawFilledRectangle(Screen.X + 70, Screen.Y - 34, 107, 16, ImColor(0.0f, 0.0f, 255.0f, 255.0f));

												if (AActor.Health <= 0)
												{
													// ESP Style1 Player Name.........
													DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playernames1, PlayerTagFall, Screen.X - 63, Screen.Y - 50, DX11::ImGui_DX11::Color::Red, true);

													DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playernames1, PlayerDown, Screen.X - 30, Screen.Y - 51, DX11::ImGui_DX11::Color::Red, true);
												}
												else
												{
													// ESP Style1 Player Name.........
													DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playernames1, PlayerTagAlive, Screen.X - 63, Screen.Y - 50, DX11::ImGui_DX11::Color::Red, false);

													DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playernames1, PlayerAlive, Screen.X - 30, Screen.Y - 51, Setting1::playernamec1, true); //DX11::ImGui_DX11::Color::White, false);
												}
											}
											
										}

										if (Setting1::style2)
										{
											if (Setting1::playerst2name)
											{
												std::string BotAlive;
												std::string BotDown;
												std::string PlayerAlive;
												std::string PlayerDown;

												PlayerAlive = to_string(AActor.TeamId) + "." + " " + AActor.Name.c_str();// +"   " + to_string(Distance) + "M ";
												PlayerDown = to_string(AActor.TeamId) + "." + " " + AActor.Name.c_str();// +"   " + to_string(Distance) + "M ";

												if (AActor.Health <= 0)
												{
													DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playernames2, PlayerDown, Screen.X - 40, (Screen.Y - 30), DX11::ImGui_DX11::Color::Red, true);
												}
												else
												{
													DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playernames2, PlayerAlive, Screen.X - 40, (Screen.Y - 30), Setting1::playernamec2, true); //DX11::ImGui_DX11::Color::Yellow, true);
												}
											}
											
											
										}

										if (Setting1::style3)
										{
											if (Setting1::playerst3name)
											{
												std::string BotTagAlive;
												std::string BotTagFall;
												std::string PlayerTagAlive;
												std::string PlayerTagFall;

												std::string BotAlive;
												std::string BotDown;
												std::string PlayerAlive;
												std::string PlayerDown;

												PlayerAlive = /*to_string(AActor.TeamId) + "." + " " +*/ AActor.Name.c_str();// +"   " + to_string(Distance) + "M ";
												PlayerDown = /*to_string(AActor.TeamId) + "." + " " +*/ AActor.Name.c_str();// +"   " + to_string(Distance) + "M ";

												if (Setting1::playerhealth)
												{
													//DX11::ImGui_DX11::DrawBlood_BackShadow(Screen.X - 70, Screen.Y - 31, 130, 18.0, AActor.Health);

												}

												if (AActor.Health <= 0)
												{
													DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playernames3, PlayerDown, Screen.X - 60, (Screen.Y - 30), DX11::ImGui_DX11::Color::Red, true);
												}
												else
												{
													DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playernames3, PlayerAlive, Screen.X - 60, (Screen.Y - 30), Setting1::playernamec3, true); //DX11::ImGui_DX11::Color::Yellow, true);
												}
											}
											
										}

									}

									if (Setting::pflag)
									{
										if (Setting1::style1)
										{
											NationFlag(Screen, AActor, -50, 66, 20, 14);
										}
										if (Setting1::style2)
										{
											NationFlag(Screen, AActor, 50, 40, 20, 10);
										}
										if (Setting1::style3)
										{
											NationFlag(Screen, AActor, 50, 40, 20, 10);
										}
									}

									if (Setting1::playercornerbox)
									{
										if (Setting1::style1)
										{
											if (Setting1::playerst1cornerbox)
											{
												if (CornerBoxp1 == 0)
												{
													DX11::ImGui_DX11::CornerBox(Screen.X - Screen.Z / 4 - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, Setting1::playercornerboxs1, popcorn / 2, Setting1::playercornerboxc1);
												}
												else if (CornerBoxp1 == 1)
												{
													DX11::ImGui_DX11::CornerBox(Screen.X - Screen.Z / 4 - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, Setting1::playercornerboxs1, popcorn / 2, linescolors);
												}
											}
										}

										if (Setting1::style2)
										{
											if (Setting1::playerst2cornerbox)
											{
												if (CornerBoxp2 == 0)
												{
													DX11::ImGui_DX11::CornerBox(Screen.X - Screen.Z / 4 - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, Setting1::playercornerboxs2, popcorn / 2, Setting1::playercornerboxc2);
												}
												else if (CornerBoxp2 == 1)
												{
													DX11::ImGui_DX11::CornerBox(Screen.X - Screen.Z / 4 - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, Setting1::playercornerboxs2, popcorn / 2, linescolors);
												}
											}											
										}


										if (Setting1::style3)
										{
											if (Setting1::playerst3cornerbox)
											{
												if (CornerBoxp3 == 0)
												{
													DX11::ImGui_DX11::CornerBox(Screen.X - Screen.Z / 4 - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, Setting1::playercornerboxs3, popcorn / 2, Setting1::playercornerboxc3);
												}
												else if (CornerBoxp3 == 1)
												{
													DX11::ImGui_DX11::CornerBox(Screen.X - Screen.Z / 4 - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, Setting1::playercornerboxs3, popcorn / 2, linescolors);
												}
											}
										}
									}

									if (Setting1::playerfullbox)
									{
										if (Setting1::style1)
										{
											if (Setting1::playerst1fullbox)
											{
												if (botfullboxp1 == 0)
												{
													DX11::ImGui_DX11::DrawRectangle(Screen.X - (Screen.Z / 4) - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, Setting1::playerfullboxc1, Setting1::playerfullboxs1);

												}
												else if (botfullboxp1 == 1)
												{
													DX11::ImGui_DX11::DrawRectangle(Screen.X - (Screen.Z / 4) - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, linescolors, Setting1::playerfullboxs1);

												}
											}
										}

										if (Setting1::style2)
										{
											if (Setting1::playerst2fullbox)
											{
												if (botfullboxp2 == 0)
												{
													DX11::ImGui_DX11::DrawRectangle(Screen.X - (Screen.Z / 4) - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, Setting1::playerfullboxc2, Setting1::playerfullboxs2);

												}
												else if (botfullboxp2 == 1)
												{
													DX11::ImGui_DX11::DrawRectangle(Screen.X - (Screen.Z / 4) - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, linescolors, Setting1::playerfullboxs2);

												}
											}
										}

										if (Setting1::style3)
										{
											if (Setting1::playerst3fullbox)
											{
												if (botfullboxp3 == 0)
												{
													DX11::ImGui_DX11::DrawRectangle(Screen.X - (Screen.Z / 4) - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, Setting1::playerfullboxc3, Setting1::playerfullboxs3);

												}
												else if (botfullboxp3 == 1)
												{
													DX11::ImGui_DX11::DrawRectangle(Screen.X - (Screen.Z / 4) - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, linescolors, Setting1::playerfullboxs3);

												}
											}
										}
									}

									if (Setting::puid)
									{
										
										if (AActor.Health <= 0)
										{
											DX11::ImGui_DX11::DrawBorderText(DX11::ImGui_DX11::pRegularFont, dissize, AActor.UID, Screen.X + 17, (Screen.Y + Screen.Z) + 30, DX11::ImGui_DX11::Color::Red, true);

										}
										else
										{
											DX11::ImGui_DX11::DrawBorderText(DX11::ImGui_DX11::pRegularFont, dissize, AActor.UID, Screen.X + 17, (Screen.Y + Screen.Z) + 30, Colors::plyerdistance, true);

										}
									}

									if (Setting1::playerhealth)
									{
										if (Setting1::style1)
										{
											if (Setting1::playerst1health)
											{
												if (hpp1 == 0)
												{
													DX11::ImGui_DX11::DrawBlood(Screen.X - 70, Screen.Y - 34, 140, 3.0, AActor.Health);
												}
												else if (hpp1 == 1)
												{
													std::string hp100 = "HP : 100";
													std::string hp90 = "HP : 90";
													std::string hp80 = "HP : 80";
													std::string hp60 = "HP : 60";
													std::string hp40 = "HP : 40";
													std::string hp20 = "HP : 20";
													std::string hp10 = "HP : 10";
													std::string hp0 = "HP : 0";

													if (AActor.Health > 99.0)
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerhealths1, hp100, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::playerhealthc1, true);

													}
													if (AActor.Health > 90.0 && AActor.Health <= 99.0)
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerhealths1, hp90, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::playerhealthc1, true);

													}
													if (AActor.Health > 80.0 && AActor.Health <= 90.0)
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerhealths1, hp80, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::playerhealthc1, true);

													}
													if (AActor.Health > 60.0 && AActor.Health <= 80.0)
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerhealths1, hp60, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::playerhealthc1, true);

													}
													if (AActor.Health > 40.0 && AActor.Health <= 60.0)
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerhealths1, hp40, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::playerhealthc1, true);

													}
													if (AActor.Health > 20.0 && AActor.Health <= 40.0)
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerhealths1, hp20, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::playerhealthc1, true);

													}
													if (AActor.Health > 10.0 && AActor.Health <= 20.0)
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerhealths1, hp10, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::playerhealthc1, true);

													}
													if (AActor.Health > 0.0 && AActor.Health <= 10.0)
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerhealths1, hp0, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::playerhealthc1, true);

													}
												}
											}
										}

										if (Setting1::style2)
										{
											if (Setting1::playerst2health)
											{
												if (hpp2 == 0)
												{
													DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - (Screen.Z / 4) - 2.5, (Screen.Y - 4) + (Screen.Z + 5), 5, (Screen.Z + 8), DX11::ImGui_DX11::Color::Black);

													if (AActor.Health > 70.0)
													{
														DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 2, (Screen.Z + 5) * AActor.Health / AActor.HealthMax, DX11::ImGui_DX11::Color::Green);
													}
													if (AActor.Health > 30.0 && AActor.Health <= 70.0)
													{
														DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 2, (Screen.Z + 5) * AActor.Health / AActor.HealthMax, DX11::ImGui_DX11::Color::Yellow);
													}
													if (AActor.Health > 0.0 && AActor.Health <= 30.0)
													{
														DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 2, (Screen.Z + 5) * AActor.Health / AActor.HealthMax, DX11::ImGui_DX11::Color::Red);

													}
												}
												else if (hpp2 == 1)
												{
													std::string hp100 = "HP : 100";
													std::string hp90 = "HP : 90";
													std::string hp80 = "HP : 80";
													std::string hp60 = "HP : 60";
													std::string hp40 = "HP : 40";
													std::string hp20 = "HP : 20";
													std::string hp10 = "HP : 10";
													std::string hp0 = "HP : 0";

													if (AActor.Health > 99.0)
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerhealths2, hp100, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::playerhealthc2, true);

													}
													if (AActor.Health > 90.0 && AActor.Health <= 99.0)
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerhealths2, hp90, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::playerhealthc2, true);

													}
													if (AActor.Health > 80.0 && AActor.Health <= 90.0)
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerhealths2, hp80, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::playerhealthc2, true);

													}
													if (AActor.Health > 60.0 && AActor.Health <= 80.0)
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerhealths2, hp60, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::playerhealthc2, true);

													}
													if (AActor.Health > 40.0 && AActor.Health <= 60.0)
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerhealths2, hp40, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::playerhealthc2, true);

													}
													if (AActor.Health > 20.0 && AActor.Health <= 40.0)
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerhealths2, hp20, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::playerhealthc2, true);

													}
													if (AActor.Health > 10.0 && AActor.Health <= 20.0)
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerhealths2, hp10, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::playerhealthc2, true);

													}
													if (AActor.Health > 0.0 && AActor.Health <= 10.0)
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerhealths2, hp0, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::playerhealthc2, true);

													}
												}
											}
										}

										if (Setting1::style3)
										{
											if (Setting1::playerst3health)
											{
												if (hpp3 == 0)
												{
													DX11::ImGui_DX11::DrawBlood_BackShadow(Screen.X - 70, Screen.Y - 31, 130, 18.0, AActor.Health);
												}
												else if (hpp3 == 1)
												{
													std::string hp100 = "HP : 100";
													std::string hp90 = "HP : 90";
													std::string hp80 = "HP : 80";
													std::string hp60 = "HP : 60";
													std::string hp40 = "HP : 40";
													std::string hp20 = "HP : 20";
													std::string hp10 = "HP : 10";
													std::string hp0 = "HP : 0";

													if (AActor.Health > 99.0)
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerhealths3, hp100, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::playerhealthc3, true);

													}
													if (AActor.Health > 90.0 && AActor.Health <= 99.0)
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerhealths3, hp90, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::playerhealthc3, true);

													}
													if (AActor.Health > 80.0 && AActor.Health <= 90.0)
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerhealths3, hp80, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::playerhealthc3, true);

													}
													if (AActor.Health > 60.0 && AActor.Health <= 80.0)
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerhealths3, hp60, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::playerhealthc3, true);

													}
													if (AActor.Health > 40.0 && AActor.Health <= 60.0)
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerhealths3, hp40, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::playerhealthc3, true);

													}
													if (AActor.Health > 20.0 && AActor.Health <= 40.0)
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerhealths3, hp20, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::playerhealthc3, true);

													}
													if (AActor.Health > 10.0 && AActor.Health <= 20.0)
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerhealths3, hp10, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::playerhealthc3, true);

													}
													if (AActor.Health > 0.0 && AActor.Health <= 10.0)
													{
														DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerhealths3, hp0, Screen.X, (Screen.Y + 30 + Screen.Z), Setting1::playerhealthc3, true);

													}
												}
											}
										}
									}

									if (Setting1::playerBone)
									{
										if (Setting1::style1)
										{
											if (Setting1::playerst1Bone)
											{
												HeadPos = AActor.HeadPos;
												HeadPos.Z += 7;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, HeadPos, Head, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.ChestPos, Chest, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.PelvisPos, Pelvis, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lSholderPos, lSholder, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rSholderPos, rSholder, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lElbowPos, lElbow, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rElbowPos, rElbow, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lWristPos, lWrist, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rWristPos, rWrist, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lThighPos, lThigh, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rThighPos, rThigh, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lKneePos, lKnee, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rKneePos, rKnee, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lAnklePos, lAnkle, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rAnklePos, rAnkle, &Distance)) continue;

												if (skeleep1 == 0)
												{
													if (AActor.Address == Setting1::CurrentTargetAddress)
													{
														Setting1::playerBonec1 = DX11::ImGui_DX11::Color::Red;
													}
													else
													{
														Setting1::playerBonec1 = Setting1::playerBonec1;
													}
													DX11::ImGui_DX11::DrawCircle(Head.X, Head.Y, Screen.Z / 12, Setting1::playerBonec1, Setting1::playerBones1);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, Pelvis.X, Pelvis.Y, Setting1::playerBonec1, Setting1::playerBones1);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, lSholder.X, lSholder.Y, Setting1::playerBonec1, Setting1::playerBones1);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, rSholder.X, rSholder.Y, Setting1::playerBonec1, Setting1::playerBones1);
													DX11::ImGui_DX11::DrawLine(lSholder.X, lSholder.Y, lElbow.X, lElbow.Y, Setting1::playerBonec1, Setting1::playerBones1);
													DX11::ImGui_DX11::DrawLine(rSholder.X, rSholder.Y, rElbow.X, rElbow.Y, Setting1::playerBonec1, Setting1::playerBones1);
													DX11::ImGui_DX11::DrawLine(lElbow.X, lElbow.Y, lWrist.X, lWrist.Y, Setting1::playerBonec1, Setting1::playerBones1);
													DX11::ImGui_DX11::DrawLine(rElbow.X, rElbow.Y, rWrist.X, rWrist.Y, Setting1::playerBonec1, Setting1::playerBones1);
													DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, lThigh.X, lThigh.Y, Setting1::playerBonec1, Setting1::playerBones1);
													DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, rThigh.X, rThigh.Y, Setting1::playerBonec1, Setting1::playerBones1);
													DX11::ImGui_DX11::DrawLine(lThigh.X, lThigh.Y, lKnee.X, lKnee.Y, Setting1::playerBonec1, Setting1::playerBones1);
													DX11::ImGui_DX11::DrawLine(rThigh.X, rThigh.Y, rKnee.X, rKnee.Y, Setting1::playerBonec1, Setting1::playerBones1);
													DX11::ImGui_DX11::DrawLine(lKnee.X, lKnee.Y, lAnkle.X, lAnkle.Y, Setting1::playerBonec1, Setting1::playerBones1);
													DX11::ImGui_DX11::DrawLine(rKnee.X, rKnee.Y, rAnkle.X, rAnkle.Y, Setting1::playerBonec1, Setting1::playerBones1);
												}
												else if (skeleep1 == 1)
												{
													if (AActor.Address == Setting1::CurrentTargetAddress)
													{
														linescolors = DX11::ImGui_DX11::Color::Red;
													}
													else
													{
														linescolors = linescolors;
													}
													DX11::ImGui_DX11::DrawCircle(Head.X, Head.Y, Screen.Z / 12, linescolors, Setting1::playerBones1);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, Pelvis.X, Pelvis.Y, linescolors, Setting1::playerBones1);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, lSholder.X, lSholder.Y, linescolors, Setting1::playerBones1);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, rSholder.X, rSholder.Y, linescolors, Setting1::playerBones1);
													DX11::ImGui_DX11::DrawLine(lSholder.X, lSholder.Y, lElbow.X, lElbow.Y, linescolors, Setting1::playerBones1);
													DX11::ImGui_DX11::DrawLine(rSholder.X, rSholder.Y, rElbow.X, rElbow.Y, linescolors, Setting1::playerBones1);
													DX11::ImGui_DX11::DrawLine(lElbow.X, lElbow.Y, lWrist.X, lWrist.Y, linescolors, Setting1::playerBones1);
													DX11::ImGui_DX11::DrawLine(rElbow.X, rElbow.Y, rWrist.X, rWrist.Y, linescolors, Setting1::playerBones1);
													DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, lThigh.X, lThigh.Y, linescolors, Setting1::playerBones1);
													DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, rThigh.X, rThigh.Y, linescolors, Setting1::playerBones1);
													DX11::ImGui_DX11::DrawLine(lThigh.X, lThigh.Y, lKnee.X, lKnee.Y, linescolors, Setting1::playerBones1);
													DX11::ImGui_DX11::DrawLine(rThigh.X, rThigh.Y, rKnee.X, rKnee.Y, linescolors, Setting1::playerBones1);
													DX11::ImGui_DX11::DrawLine(lKnee.X, lKnee.Y, lAnkle.X, lAnkle.Y, linescolors, Setting1::playerBones1);
													DX11::ImGui_DX11::DrawLine(rKnee.X, rKnee.Y, rAnkle.X, rAnkle.Y, linescolors, Setting1::playerBones1);
												}
											}											
										}

										if (Setting1::style2)
										{
											if (Setting1::playerst2Bone)
											{
												HeadPos = AActor.HeadPos;
												HeadPos.Z += 7;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, HeadPos, Head, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.ChestPos, Chest, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.PelvisPos, Pelvis, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lSholderPos, lSholder, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rSholderPos, rSholder, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lElbowPos, lElbow, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rElbowPos, rElbow, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lWristPos, lWrist, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rWristPos, rWrist, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lThighPos, lThigh, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rThighPos, rThigh, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lKneePos, lKnee, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rKneePos, rKnee, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lAnklePos, lAnkle, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rAnklePos, rAnkle, &Distance)) continue;

												if (skeleep2 == 0)
												{
													if (AActor.Address == Setting1::CurrentTargetAddress)
													{
														Setting1::playerBonec2 = DX11::ImGui_DX11::Color::Red;
													}
													else
													{
														Setting1::playerBonec2 = Setting1::playerBonec2;
													}
													DX11::ImGui_DX11::DrawCircle(Head.X, Head.Y, Screen.Z / 12, Setting1::playerBonec2, Setting1::playerBones2);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, Pelvis.X, Pelvis.Y, Setting1::playerBonec2, Setting1::playerBones2);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, lSholder.X, lSholder.Y, Setting1::playerBonec2, Setting1::playerBones2);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, rSholder.X, rSholder.Y, Setting1::playerBonec2, Setting1::playerBones2);
													DX11::ImGui_DX11::DrawLine(lSholder.X, lSholder.Y, lElbow.X, lElbow.Y, Setting1::playerBonec2, Setting1::playerBones2);
													DX11::ImGui_DX11::DrawLine(rSholder.X, rSholder.Y, rElbow.X, rElbow.Y, Setting1::playerBonec2, Setting1::playerBones2);
													DX11::ImGui_DX11::DrawLine(lElbow.X, lElbow.Y, lWrist.X, lWrist.Y, Setting1::playerBonec2, Setting1::playerBones2);
													DX11::ImGui_DX11::DrawLine(rElbow.X, rElbow.Y, rWrist.X, rWrist.Y, Setting1::playerBonec2, Setting1::playerBones2);
													DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, lThigh.X, lThigh.Y, Setting1::playerBonec2, Setting1::playerBones2);
													DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, rThigh.X, rThigh.Y, Setting1::playerBonec2, Setting1::playerBones2);
													DX11::ImGui_DX11::DrawLine(lThigh.X, lThigh.Y, lKnee.X, lKnee.Y, Setting1::playerBonec2, Setting1::playerBones2);
													DX11::ImGui_DX11::DrawLine(rThigh.X, rThigh.Y, rKnee.X, rKnee.Y, Setting1::playerBonec2, Setting1::playerBones2);
													DX11::ImGui_DX11::DrawLine(lKnee.X, lKnee.Y, lAnkle.X, lAnkle.Y, Setting1::playerBonec2, Setting1::playerBones2);
													DX11::ImGui_DX11::DrawLine(rKnee.X, rKnee.Y, rAnkle.X, rAnkle.Y, Setting1::playerBonec2, Setting1::playerBones2);
												}
												else if (skeleep2 == 1)
												{
													if (AActor.Address == Setting1::CurrentTargetAddress)
													{
														linescolors = DX11::ImGui_DX11::Color::Red;
													}
													else
													{
														linescolors = linescolors;
													}
													DX11::ImGui_DX11::DrawCircle(Head.X, Head.Y, Screen.Z / 12, linescolors, Setting1::playerBones2);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, Pelvis.X, Pelvis.Y, linescolors, Setting1::playerBones2);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, lSholder.X, lSholder.Y, linescolors, Setting1::playerBones2);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, rSholder.X, rSholder.Y, linescolors, Setting1::playerBones2);
													DX11::ImGui_DX11::DrawLine(lSholder.X, lSholder.Y, lElbow.X, lElbow.Y, linescolors, Setting1::playerBones2);
													DX11::ImGui_DX11::DrawLine(rSholder.X, rSholder.Y, rElbow.X, rElbow.Y, linescolors, Setting1::playerBones2);
													DX11::ImGui_DX11::DrawLine(lElbow.X, lElbow.Y, lWrist.X, lWrist.Y, linescolors, Setting1::playerBones2);
													DX11::ImGui_DX11::DrawLine(rElbow.X, rElbow.Y, rWrist.X, rWrist.Y, linescolors, Setting1::playerBones2);
													DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, lThigh.X, lThigh.Y, linescolors, Setting1::playerBones2);
													DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, rThigh.X, rThigh.Y, linescolors, Setting1::playerBones2);
													DX11::ImGui_DX11::DrawLine(lThigh.X, lThigh.Y, lKnee.X, lKnee.Y, linescolors, Setting1::playerBones2);
													DX11::ImGui_DX11::DrawLine(rThigh.X, rThigh.Y, rKnee.X, rKnee.Y, linescolors, Setting1::playerBones2);
													DX11::ImGui_DX11::DrawLine(lKnee.X, lKnee.Y, lAnkle.X, lAnkle.Y, linescolors, Setting1::playerBones2);
													DX11::ImGui_DX11::DrawLine(rKnee.X, rKnee.Y, rAnkle.X, rAnkle.Y, linescolors, Setting1::playerBones2);
												}
											}											
										}

										if (Setting1::style3)
										{
											if (Setting1::playerst3Bone)
											{
												HeadPos = AActor.HeadPos;
												HeadPos.Z += 7;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, HeadPos, Head, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.ChestPos, Chest, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.PelvisPos, Pelvis, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lSholderPos, lSholder, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rSholderPos, rSholder, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lElbowPos, lElbow, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rElbowPos, rElbow, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lWristPos, lWrist, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rWristPos, rWrist, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lThighPos, lThigh, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rThighPos, rThigh, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lKneePos, lKnee, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rKneePos, rKnee, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lAnklePos, lAnkle, &Distance)) continue;
												if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rAnklePos, rAnkle, &Distance)) continue;

												if (skeleep3 == 0)
												{
													if (AActor.Address == Setting1::CurrentTargetAddress)
													{
														Setting1::playerBonec3 = DX11::ImGui_DX11::Color::Red;
													}
													else
													{
														Setting1::playerBonec3 = Setting1::playerBonec3;
													}
													DX11::ImGui_DX11::DrawCircle(Head.X, Head.Y, Screen.Z / 12, Setting1::playerBonec3, Setting1::playerBones3);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, Pelvis.X, Pelvis.Y, Setting1::playerBonec3, Setting1::playerBones3);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, lSholder.X, lSholder.Y, Setting1::playerBonec3, Setting1::playerBones3);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, rSholder.X, rSholder.Y, Setting1::playerBonec3, Setting1::playerBones3);
													DX11::ImGui_DX11::DrawLine(lSholder.X, lSholder.Y, lElbow.X, lElbow.Y, Setting1::playerBonec3, Setting1::playerBones3);
													DX11::ImGui_DX11::DrawLine(rSholder.X, rSholder.Y, rElbow.X, rElbow.Y, Setting1::playerBonec3, Setting1::playerBones3);
													DX11::ImGui_DX11::DrawLine(lElbow.X, lElbow.Y, lWrist.X, lWrist.Y, Setting1::playerBonec3, Setting1::playerBones3);
													DX11::ImGui_DX11::DrawLine(rElbow.X, rElbow.Y, rWrist.X, rWrist.Y, Setting1::playerBonec3, Setting1::playerBones3);
													DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, lThigh.X, lThigh.Y, Setting1::playerBonec3, Setting1::playerBones3);
													DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, rThigh.X, rThigh.Y, Setting1::playerBonec3, Setting1::playerBones3);
													DX11::ImGui_DX11::DrawLine(lThigh.X, lThigh.Y, lKnee.X, lKnee.Y, Setting1::playerBonec3, Setting1::playerBones3);
													DX11::ImGui_DX11::DrawLine(rThigh.X, rThigh.Y, rKnee.X, rKnee.Y, Setting1::playerBonec3, Setting1::playerBones3);
													DX11::ImGui_DX11::DrawLine(lKnee.X, lKnee.Y, lAnkle.X, lAnkle.Y, Setting1::playerBonec3, Setting1::playerBones3);
													DX11::ImGui_DX11::DrawLine(rKnee.X, rKnee.Y, rAnkle.X, rAnkle.Y, Setting1::playerBonec3, Setting1::playerBones3);
												}
												else if (skeleep3 == 1)
												{
													if (AActor.Address == Setting1::CurrentTargetAddress)
													{
														linescolors = DX11::ImGui_DX11::Color::Red;
													}
													else
													{
														linescolors = linescolors;
													}
													DX11::ImGui_DX11::DrawCircle(Head.X, Head.Y, Screen.Z / 12, linescolors, Setting1::playerBones3);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, Pelvis.X, Pelvis.Y, linescolors, Setting1::playerBones3);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, lSholder.X, lSholder.Y, linescolors, Setting1::playerBones3);
													DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, rSholder.X, rSholder.Y, linescolors, Setting1::playerBones3);
													DX11::ImGui_DX11::DrawLine(lSholder.X, lSholder.Y, lElbow.X, lElbow.Y, linescolors, Setting1::playerBones3);
													DX11::ImGui_DX11::DrawLine(rSholder.X, rSholder.Y, rElbow.X, rElbow.Y, linescolors, Setting1::playerBones3);
													DX11::ImGui_DX11::DrawLine(lElbow.X, lElbow.Y, lWrist.X, lWrist.Y, linescolors, Setting1::playerBones3);
													DX11::ImGui_DX11::DrawLine(rElbow.X, rElbow.Y, rWrist.X, rWrist.Y, linescolors, Setting1::playerBones3);
													DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, lThigh.X, lThigh.Y, linescolors, Setting1::playerBones3);
													DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, rThigh.X, rThigh.Y, linescolors, Setting1::playerBones3);
													DX11::ImGui_DX11::DrawLine(lThigh.X, lThigh.Y, lKnee.X, lKnee.Y, linescolors, Setting1::playerBones3);
													DX11::ImGui_DX11::DrawLine(rThigh.X, rThigh.Y, rKnee.X, rKnee.Y, linescolors, Setting1::playerBones3);
													DX11::ImGui_DX11::DrawLine(lKnee.X, lKnee.Y, lAnkle.X, lAnkle.Y, linescolors, Setting1::playerBones3);
													DX11::ImGui_DX11::DrawLine(rKnee.X, rKnee.Y, rAnkle.X, rAnkle.Y, linescolors, Setting1::playerBones3);
												}
											}
										}
									}

									if (Setting1::playerweapon)
									{
										if (Setting1::style1)
										{
											if (Setting1::playerst1weapon)
											{
												if (Setting1::playerst1Weapons_iconsH)
												{
													Weapons_iconsH_P(Screen, AActor, 50, 40, 20, 10);
												}
												else
												{
													if (Setting1::playerst1weapon)
													{
														//Text = (weapon);
														weapon = AActor.Weapon;
														if (AActor.Health <= 0)
														{
															if (AActor.Weapon == "Fist")
															{
																DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerweaponFalses1, weapon, Screen.X - 10, (Screen.Y - 70), DX11::ImGui_DX11::Color::Red, true);

															}
															else
															{
																DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerweapons1, weapon, Screen.X - 10, (Screen.Y - 70), DX11::ImGui_DX11::Color::Red, true);

															}
														}
														else
														{
															if (AActor.Weapon == "Fist")
															{
																DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerweaponFalses1, weapon, Screen.X - 10, (Screen.Y - 70), Setting1::playerweaponFalsec1, false); //DX11::ImGui_DX11::Color::Green, false);

															}
															else
															{

																string wep = AActor.Weapon;

																wep.append(" | ");
																wep.append(to_string(AActor.Ammo) + "");

																//wep.append(to_string(AActor.AmmoMax));
																wep.append(AActor.ScopeFov);
																if (AActor.Ammo <= 200 && AActor.AmmoMax > 0)
																{
																	DX11::ImGui_DX11::DrawBorderText(DX11::ImGui_DX11::pRegularFont, Setting1::playerweapons1, wep, Screen.X - 0, (Screen.Y - 70), Setting1::playerweaponc1, true);
																}
																else
																{
																	DX11::ImGui_DX11::DrawCharBorderText(DX11::ImGui_DX11::pRegularFont, Setting1::playerweapons1, AActor.Weapon.c_str(), Screen.X - 0, (Screen.Y - 70), Setting1::playerweaponc1, true);
																}

																//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerweapons1, weapon, Screen.X - 10, (Screen.Y - 70), Setting1::playerweaponc1, false); //DX11::ImGui_DX11::Color::Green, false);

															}

														}
													}
												}
											}
											
										}

										if (Setting1::style2)
										{
											if (Setting1::playerst2weapon)
											{
												if (Setting1::playerst2Weapons_iconsH)
												{
													Weapons_iconsH_P(Screen, AActor, 50, 40, 20, 10);
												}
												else
												{
													if (Setting1::playerst2weapon)
													{
														Text = (AActor.Weapon + " | ") + (dist);
														//weapon = AActor.Weapon;
														if (AActor.Health <= 0)
														{
															if (AActor.Weapon == "Fist")
															{
																DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerweaponFalses2, Text, Screen.X - 32, (Screen.Y + Screen.Z), DX11::ImGui_DX11::Color::Red, true);

															}
															else
															{
																DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerweapons2, Text, Screen.X - 32, (Screen.Y + Screen.Z), DX11::ImGui_DX11::Color::Red, true);

															}
														}
														else
														{
															if (AActor.Weapon == "Fist")
															{
																DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerweaponFalses2, Text, Screen.X - 32, (Screen.Y + Screen.Z), Setting1::playerweaponFalsec2, false); //DX11::ImGui_DX11::Color::Green, false);

															}
															else
															{
																DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerweapons2, Text, Screen.X - 32, (Screen.Y + Screen.Z), Setting1::playerweaponc2, false); //DX11::ImGui_DX11::Color::Green, false);

															}
														}
													}

												}
											}
											
										}

										if (Setting1::style3)
										{
											if (Setting1::playerst3weapon)
											{
												if (Setting1::playerst3Weapons_iconsH)
												{
													Weapons_iconsH_P(Screen, AActor, 50, 40, 20, 10);
												}
												else
												{
													if (Setting1::playerst3weapon)
													{
														//Text = (weapon + " | ") + (dist);
														weapon = AActor.Weapon;
														if (AActor.Health <= 0)
														{
															if (AActor.Weapon == "Fist")
															{
																DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerweaponFalses3, weapon, Screen.X - 10, (Screen.Y + Screen.Z + 25), DX11::ImGui_DX11::Color::Red, true);

															}
															else
															{
																DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerweapons3, weapon, Screen.X - 10, (Screen.Y + Screen.Z + 25), DX11::ImGui_DX11::Color::Red, true);

															}
														}
														else
														{
															if (AActor.Weapon == "Fist")
															{
																DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerweaponFalses3, weapon, Screen.X - 10, (Screen.Y + Screen.Z + 25), Setting1::playerweaponFalsec3, false); //DX11::ImGui_DX11::Color::Green, false);

															}
															else
															{
																DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerweapons3, weapon, Screen.X - 10, (Screen.Y + Screen.Z + 25), Setting1::playerweaponc3, false); //DX11::ImGui_DX11::Color::Green, false);

															}
														}
													}
												}
											}
											
										}
									}

									if (Setting1::playerdistance)
									{
										if (Setting1::style1)
										{
											if (Setting1::playerst1distance)
											{
												//Text = (dist);
												Text = dist = std::to_string(Distance);
												if (AActor.Health <= 0)
												{
													DX11::ImGui_DX11::DrawImage(DX11::PlayerTagDistance_DownLogo0, Screen.X - 10, Screen.Y - 14, 13, 7);
													//Player Name Back Sadow For Distance
													DX11::ImGui_DX11::DrawFilledRectangle(Screen.X + 12, Screen.Y - 15, 30, 15, ImColor(0.0f, 0.0f, 0.0f, 255.0f));


													DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerdistances1, Text, Screen.X - 10, (Screen.Y - 32), DX11::ImGui_DX11::Color::Red, true);

												}
												else
												{

													DX11::ImGui_DX11::DrawImage(DX11::PlayerTagDistance_DownLogo0, Screen.X - 10, Screen.Y - 14, 13, 7);
													//Player Name Back Sadow For Distance
													DX11::ImGui_DX11::DrawFilledRectangle(Screen.X + 12, Screen.Y - 15, 30, 15, ImColor(0.0f, 0.0f, 0.0f, 255.0f));


													DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerdistances1, Text, Screen.X - 10, (Screen.Y - 32), Setting1::playerdistancec1, false); //DX11::ImGui_DX11::Color::Green, false);

												}
											}
										}

										if (Setting1::style2)
										{
											if (Setting1::playerst2distance)
											{
												//Text = dist;
												if (AActor.Health <= 0)
												{
													//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerdistances2, Text, Screen.X - 10, (Screen.Y + Screen.Z + 10), DX11::ImGui_DX11::Color::Red, true);

												}
												else
												{
													//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerdistances2, Text, Screen.X - 10, (Screen.Y + Screen.Z + 10), Setting1::playerdistancec2, false); //DX11::ImGui_DX11::Color::Green, false);

												}
											}											
										}

										if (Setting1::style3)
										{
											if (Setting1::playerst3distance)
											{
												Text = dist;
												if (AActor.Health <= 0)
												{
													DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerdistances3, Text, Screen.X - 10, (Screen.Y + Screen.Z + 10), DX11::ImGui_DX11::Color::Red, true);

												}
												else
												{
													DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::playerdistances3, Text, Screen.X - 10, (Screen.Y + Screen.Z + 10), Setting1::playerdistancec3, false); //DX11::ImGui_DX11::Color::Green, false);

												}
											}											
										}
									}

									if (Setting::PlayerStatus)
									{
										if (Setting::PlayerStatus)//3 working
										{
											std::string playerstatus = AActor.playerstatus.c_str();
											if (playerstatus == "Aiming" || playerstatus == "Knocked" || playerstatus == "Driving Vehicle" || playerstatus == "Driving Boat")//00ff
											{
												//DX11::ImGui_DX11::DrawStringText(Font16, 14, player.weapon.c_str(), playerScreen.x - 5, playerScreen.y - 20, ImColor(0, 255, 0, 255), true);
												//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 14, Textt1, Screen.X - 17, Screen.Y + 15, DX11::ImGui_DX11::Color::enem, false);

												DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 14, playerstatus, Screen.X - 20, (Screen.Y + 25 + Screen.Z), DX11::ImGui_DX11::Color::enem, false);
											}
											else
											{
												DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 12, playerstatus, Screen.X - 20, (Screen.Y + 25 + Screen.Z), DX11::ImGui_DX11::Color::White, false);
											}
										}										
									}

								}

								if (Setting::AimLineBottm)
								{
									Setting::AimLineCross = false;
									if (AActor.Address == Setting::CurrentTargetAddress)
									{
										//DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, DX11Window::Height, Screen.X, Screen.Y + 30, Colors::magicline, 0.5f);
										DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, DX11Window::Height, Screen.X + 5, (Screen.Y + 15 + Screen.Z) - 10, Colors::magicline, 0.5f);
									}
								}

								if (Setting::AimLineCross)
								{
									Setting::AimLineBottm = false;

									if (AActor.Address == Setting::CurrentTargetAddress)
									{
										if (Setting::curraim == 0)
										{
											DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, DX11Window::Height / 2, Head.X, Head.Y, Colors::magicline, 0.7f);
										}
										else if (Setting::curraim == 1)
										{
											DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, DX11Window::Height / 2, Chest.X, Chest.Y, Colors::magicline, 0.7f);
										}
										else if (Setting::curraim == 2)
										{
											DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, DX11Window::Height / 2, Pelvis.X, Pelvis.Y, Colors::magicline, 0.7f);
										}
										else if (Setting::curraim == 3)
										{
											DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, DX11Window::Height / 2, Pelvis.X, Pelvis.Y, Colors::magicline, 0.7f);
										}
									}
								}
							}
						}
					}

					if (Setting::IsimingAtYou) 
					{

						if (!Data::AimingAtMePlayersList.empty()) 
						{
							const char* Aim = ("\xef\x81\xb1  !! AIM ALERT !! \xef\x81\xb1  ");


							ImColor warncolor;
							int randomNum = (rand() % 2) + 1;
							if (randomNum == 1)
							{
								warncolor = DX11::ImGui_DX11::Color::Red;
							}
							if (randomNum == 2)
							{
								warncolor = DX11::ImGui_DX11::Color::Yellow;
							}



							DX11::ImGui_DX11::DrawStringchar(DX11::ImGui_DX11::pRegularFont, 40, Aim, (DX11Window::Width / 2) - 180, (DX11Window::Height / 9), warncolor, 0);
							for (AActor Aming : Data::AimingAtMePlayersList) {
								Aming.Position = Utility::ReadMemoryEx<VECTOR3>(Utility::ReadMemoryEx<DWORD>(Aming.Address + Offset::RootComponent) + Offset::Position);

								VECTOR2 Screen;



								//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 40, Aim, (DX11Window::Width / 2) - 180, (DX11Window::Height / 9), DX11::ImGui_DX11::Color::Red, 0);
								if (!Algorithm::WorldToScreenBone(ViewMatrix, Aming.Position, Screen, &Distance)) continue;
								if (Aming.isAimingAtMe)
								{
									string SIMI = "AIMING";
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, nsize, SIMI, Screen.X + 5, (Screen.Y + 25) - 10, DX11::ImGui_DX11::Color::Red, false);

								}
							}
						}

					}

					if (Setting::MagicBulletticked)
					{
						if (Data::NetDriver > 0)
						{
							if (Setting::Legitrack)
							{
								srand(time(0));
								int random = rand() % 3;
								Setting::curraim = random;
							}

							if (Setting::MagicBulletd)//head neck body
							{
								if (Data::AActorList.size() != 0)
								{
									const char* aimb[] = { "HEAD", "NECK", "BODY", "AUTO" };
									const char* combo_label = aimb[Setting::curraim];

									std::string Aim = combo_label;

									//Setting::MagicBullet = true;

									if (Setting::curraim == 3)
									{
										//Text = "            Tracking ON [ AUTO ]";
										Text = "  Tracking ON [ " + Aim + "] [" + to_string(Setting::magicrange) + "]M";
									}
									else
									{
										Text = "  Tracking ON [ " + Aim + "] [" + to_string(Setting::magicrange) + "]M";
									}
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 15, Text, DX11Window::Width / 2.2, DX11Window::Height / 2 + 220, DX11::ImGui_DX11::Color::Green, true);
								}
								else
								{
									/*Setting::MagicBullet = false;
									Text = "  Tracking Bullet [OFF]";
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 15, Text, DX11Window::Width / 2.2, DX11Window::Height / 2 + 220, DX11::ImGui_DX11::Color::Red, true);*/


									const char* aimb[] = { "HEAD", "NECK", "BODY", "AUTO" };
									const char* combo_label = aimb[Setting::curraim];

									std::string Aim = combo_label;

									//Setting::MagicBullet = false;

									if (Setting::curraim == 3)
									{
										//Text = "            Tracking ON [ AUTO ]";
										Text = "  Tracking ON [ " + Aim + "] [" + to_string(Setting::magicrange) + "]M";
									}
									else
									{
										Text = "  Tracking ON [ " + Aim + "] [" + to_string(Setting::magicrange) + "]M";
									}
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 15, Text, DX11Window::Width / 2.2, DX11Window::Height / 2 + 220, DX11::ImGui_DX11::Color::Red, true);


								}
							}
						}
						else
						{
							//Setting::MagicBullet = false;
							Text = "  MagicBullet ON | You Not In Game";//m0011
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 15, Text, DX11Window::Width / 2.2, DX11Window::Height / 2 + 220, DX11::ImGui_DX11::Color::Red, true);

						}
						
					}
					else
					{
						//Setting::MagicBullet = false;
						Text = "  Bullet Tracking [OFF]";//m0011
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 15, Text, DX11Window::Width / 2.1, DX11Window::Height / 2 + 220, DX11::ImGui_DX11::Color::Red, true);

					}

					if (Setting::TotalEnemy)
					{
						DrawTotalEnemies();

					}

					if (Setting::gameinfo && !Setting::fightmode)
					{
						Drawgameinfo();
					}

					if (Setting::MyInfo && !Setting::fightmode)
					{
						DrawMyInfo();
					}

					if (Setting::fovcircle)
					{


						//DrawCircle(OverlayWindowWidth / 2, OverlayScreenHeight / 2, 100.0f/*FovRadius*/
						DX11::ImGui_DX11::DrawCircle(DX11Window::Width / 2, DX11Window::Height / 2, Setting::fovcircleredus, Colors::fovcirclecolor);

					}

					if (Setting::allitemss && !Setting::fightmode)
					{
						if (Setting::impitems || Setting::healthitem || Setting::scope || Setting::allitemss && !Setting::fightmode)
						{
							if (Data::ItemList.size() != 0)
							{
								TempItemList.clear();
								TempItemList = Data::ItemList;
								for (Item& Item : Data::ItemList)
								{
									if (!Algorithm::WorldToScreen(Data::lOCALPLAYERPosotion, Item.Position, Screen, &Distance, ViewMatrix)) continue;

									std::string	Textt = Item.Name;
									Text = Item.Name;
									std::string air = Item.Name + " " + to_string(Distance) + "M";

									if (Distance < 1 || Distance > 150)
									{
										continue;
									}
									else
									{
										if (Setting::UselessShow)
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Textt, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Bag1_Color[0], Setting::Esp_Item_Bag1_Color[1], Setting::Esp_Item_Bag1_Color[2], Setting::Esp_Item_Bag1_Color[3]), true);

										}

										if (Setting::plan && Item.Name == "[AIR-PLANE]")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Setting1::plancolor, true);
										}

									}

									if (Setting::impitems)
									{
										if (Setting::Esp_Item_Armor3 && Item.Name == "Armor Lv.3")
										{
											//DrawImage(AR3, Screen.X - 10, Screen.Y - 20, 30, 25);
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::Armor_lv3, true);//ImColor(Setting1::Esp_Item_Armor3_Color[0], Setting1::Esp_Item_Armor3_Color[1], Setting1::Esp_Item_Armor3_Color[2], Setting1::Esp_Item_Armor3_Color[3]), true);
										}
										if (Setting::Esp_Item_Bag3 && Item.Name == "Bag Lv.3")
										{
											//DrawImage(BG3, Screen.X - 10, Screen.Y - 20, 30, 25);
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::Bag_lv3, true); //ImColor(Setting1::Esp_Item_Bag3_Color[0], Setting1::Esp_Item_Bag3_Color[1], Setting1::Esp_Item_Bag3_Color[2], Setting1::Esp_Item_Bag3_Color[3]), true);
										}
										if (Setting::Esp_Item_Helmet3 && Item.Name == "Helmet Lv.3")
										{
											//DrawImage(HA3, Screen.X - 10, Screen.Y - 20, 30, 25);
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::Helmet_lv3, true); //ImColor(Setting1::Esp_Item_Helmet3_Color[0], Setting1::Esp_Item_Helmet3_Color[1], Setting1::Esp_Item_Helmet3_Color[2], Setting1::Esp_Item_Helmet3_Color[3]), true);
										}



										if (Setting::Esp_Item_PP19 && Item.Name == "PP19")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::weapon_smg, true); //ImColor(Setting1::Esp_Item_PP19_Color[0], Setting1::Esp_Item_PP19_Color[1], Setting1::Esp_Item_PP19_Color[2], Setting1::Esp_Item_PP19_Color[3]), true);
										}
										if (Setting::Esp_Item_TommyGun && Item.Name == "Tommy Gun")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::weapon_smg, true); //ImColor(Setting1::Esp_Item_TommyGun_Color[0], Setting1::Esp_Item_TommyGun_Color[1], Setting1::Esp_Item_TommyGun_Color[2], Setting1::Esp_Item_TommyGun_Color[3]), true);
										}
										if (Setting::Esp_Item_MP5K && Item.Name == "MP5K")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::weapon_smg, true); //ImColor(Setting1::Esp_Item_MP5K_Color[0], Setting1::Esp_Item_MP5K_Color[1], Setting1::Esp_Item_MP5K_Color[2], Setting1::Esp_Item_MP5K_Color[3]), true);
										}
										if (Setting::Esp_Item_UMP9 && Item.Name == "UMP9")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::weapon_smg, true); //ImColor(Setting1::Esp_Item_UMP9_Color[0], Setting1::Esp_Item_UMP9_Color[1], Setting1::Esp_Item_UMP9_Color[2], Setting1::Esp_Item_UMP9_Color[3]), true);
										}
										if (Setting::Esp_Item_Vector && Item.Name == "Vector")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::weapon_smg, true); //ImColor(Setting1::Esp_Item_Vector_Color[0], Setting1::Esp_Item_Vector_Color[1], Setting1::Esp_Item_Vector_Color[2], Setting1::Esp_Item_Vector_Color[3]), true);
										}
										if (Setting::Esp_Item_Uzi && Item.Name == "Uzi")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::weapon_smg, true); //ImColor(Setting1::Esp_Item_Uzi_Color[0], Setting1::Esp_Item_Uzi_Color[1], Setting1::Esp_Item_Uzi_Color[2], Setting1::Esp_Item_Uzi_Color[3]), true);
										}



										if (Setting::Esp_Item_Mk47Mutant && Item.Name == "Mk47 Mutant")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::weapon_7mm, true); //ImColor(Setting1::Esp_Item_Mk47Mutant_Color[0], Setting1::Esp_Item_Mk47Mutant_Color[1], Setting1::Esp_Item_Mk47Mutant_Color[2], Setting1::Esp_Item_Mk47Mutant_Color[3]), true);
										}
										if (Setting::Esp_Item_Mk12 && Item.Name == "MK12")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::weapon_7mm, true);
										}



										if (Setting::Esp_Item_M16A4 && Item.Name == "M16A4")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::weapon_5mm, true); //ImColor(Setting1::Esp_Item_M16A4_Color[0], Setting1::Esp_Item_M16A4_Color[1], Setting1::Esp_Item_M16A4_Color[2], Setting1::Esp_Item_M16A4_Color[3]), true);
										}
										if (Setting::Esp_Item_G36C && Item.Name == "G36C")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::weapon_5mm, true); //ImColor(Setting1::Esp_Item_G36C_Color[0], Setting1::Esp_Item_G36C_Color[1], Setting1::Esp_Item_G36C_Color[2], Setting1::Esp_Item_G36C_Color[3]), true);
										}
										if (Setting::Esp_Item_QBZ && Item.Name == "QBZ")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::weapon_5mm, true); //ImColor(Setting1::Esp_Item_QBZ_Color[0], Setting1::Esp_Item_QBZ_Color[1], Setting1::Esp_Item_QBZ_Color[2], Setting1::Esp_Item_QBZ_Color[3]), true);
										}
										if (Setting::Esp_Item_QBU && Item.Name == "QBU")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::weapon_5mm, true); //ImColor(Setting1::Esp_Item_QBU_Color[0], Setting1::Esp_Item_QBU_Color[1], Setting1::Esp_Item_QBU_Color[2], Setting1::Esp_Item_QBU_Color[3]), true);
										}
										if (Setting::Esp_Item_M249 && Item.Name == "M249")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::weapon_5mm, true);
										}



										if (Setting::Esp_Item_SLR && Item.Name == "SLR")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::weapon_sniper, true); //ImColor(Setting1::Esp_Item_SLR_Color[0], Setting1::Esp_Item_SLR_Color[1], Setting1::Esp_Item_SLR_Color[2], Setting1::Esp_Item_SLR_Color[3]), true);
										}
										if (Setting::Esp_Item_Mini14 && Item.Name == "Mini-14")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::weapon_sniper, true); //ImColor(Setting1::Esp_Item_Mini14_Color[0], Setting1::Esp_Item_Mini14_Color[1], Setting1::Esp_Item_Mini14_Color[2], Setting1::Esp_Item_Mini14_Color[3]), true);
										}


										if (Setting1::Esp_Item_ExplosiveBow && Item.Name == "Explosive-Bow")
										{
											//DrawImage(Ak1, Screen.X - 10, Screen.Y - 20, 30, 25);
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::weapon_7mm, true);
										}
										if (Setting::Esp_Item_HoneyBadger && Item.Name == "Honey-Badger")
										{
											//DrawImage(Ak1, Screen.X - 10, Screen.Y - 20, 30, 25);
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, weapon1::Honey, true);
										}
										if (Setting::Esp_Item_AKM && Item.Name == "AKM")
										{
											//DrawImage(Ak1, Screen.X - 10, Screen.Y - 20, 30, 25);
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, weapon::AKM, true);
										}
										if (Setting::Esp_Item_DP28 && Item.Name == "DP28")
										{
											//DrawImage(DP1, Screen.X - 10, Screen.Y - 20, 30, 25);
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, weapon1::DP28, true); //ImColor(Setting1::Esp_Item_DP28_Color[0], Setting1::Esp_Item_DP28_Color[1], Setting1::Esp_Item_DP28_Color[2], Setting1::Esp_Item_DP28_Color[3]), true);
										}
										if (Setting::Esp_Item_M762 && Item.Name == "M762")
										{
											//DrawImage(M71, Screen.X - 10, Screen.Y - 20, 30, 25);
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, weapon::m762, true); //ImColor(Setting1::Esp_Item_M762_Color[0], Setting1::Esp_Item_M762_Color[1], Setting1::Esp_Item_M762_Color[2], Setting1::Esp_Item_M762_Color[3]), true);
										}



										if (Setting::Esp_Item_SCARL && Item.Name == "SCAR-L")
										{
											//DrawImage(sk1, Screen.X - 10, Screen.Y - 20, 30, 25);
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, weapon::scarl, true);
										}
										if (Setting::Esp_Item_M416 && Item.Name == "M416")
										{
											//DrawImage(M45, Screen.X - 10, Screen.Y - 20, 30, 25);
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, weapon::m16, true);
										}



										if (Setting::Esp_Item_Kar98k && Item.Name == "Kar98k")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::weapon_sniper, true);
										}
										if (Setting::Esp_Item_M24 && Item.Name == "M24")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::weapon_sniper, true);
										}
										if (Setting::Esp_Item_Awm && Item.Name == "AWM")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, air, Screen.X, Screen.Y, Colors1::weapon_sniper, true);
										}




										if (Setting::Esp_Item_Flare && Item.Name == "Flare Ammo")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, air, Screen.X, Screen.Y, Colors1::ammo_Flare_Gun, true);
										}
										if (Setting::Esp_Item_FlareGun && Item.Name == "Flare Gun")
										{
											//DrawImage(FLARE, Screen.X - 10, Screen.Y - 20, 30, 25);
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, air, Screen.X, Screen.Y, Colors1::weapon_Flare_Gun, true);
										}


										/*if (Setting::Esp_Item_AKM && Item.Name == "AKM")
										{
											if (Setting::Esp_Item_AKM_Icon)
											{
												DX11::ImGui_DX11::DrawImage(DX11::AKM, Screen.X - 50, Screen.Y - 20, 40, 35);
												continue;
											}
											else
											{
												DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, weapon::AKM, true);
												continue;
											}
										}

										if (Setting::Esp_Item_SCARL && Item.Name == "SCAR-L")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, weapon::scarl, true);
											continue;
										}

										if (Setting::Esp_Item_M416 && Item.Name == "M416")
										{
											if (Setting::Esp_Item_M416_Icon)
											{
												DX11::ImGui_DX11::DrawImage(DX11::M416, Screen.X - 50, Screen.Y - 20, 40, 35);
												continue;
											}
											else
											{

												DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, weapon::m16, true);
												continue;
											}
										}

										if (Setting::Esp_Item_M24 && Item.Name == "M24")
										{
											if (Setting::Esp_Item_M24_Icon)
											{
												DX11::ImGui_DX11::DrawImage(DX11::M24, Screen.X - 50, Screen.Y - 20, 40, 35);
												continue;
											}
											else
											{

												DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, weapon::M24, true);
												continue;
											}
										}*/

										if (Setting::token && Item.Name == "FalierInAir")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, air, Screen.X, Screen.Y + 15, ImColor(Esp_Item_Tokenf_Color[0], Esp_Item_Tokenf_Color[1], Esp_Item_Tokenf_Color[2], Esp_Item_Tokenf_Color[3]), true);
										}
									}

									if (Setting::healthitem) 
									{
										Text = Item.Name + "  (" + to_string(Distance) + "M)";

										if (Setting1::Esp_Item_EnergyDrink && Item.Name == "Energy Drink")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::EnergyDrink, true); //ImColor(Setting1::Esp_Item_EnergyDrink_Color[0], Setting1::Esp_Item_EnergyDrink_Color[1], Setting1::Esp_Item_EnergyDrink_Color[2], Setting1::Esp_Item_EnergyDrink_Color[3]), true);
										}
										if (Setting1::Esp_Item_Painkiller && Item.Name == "Painkiller")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::Painkiller, true); //ImColor(Setting1::Esp_Item_Painkiller_Color[0], Setting1::Esp_Item_Painkiller_Color[1], Setting1::Esp_Item_Painkiller_Color[2], Setting1::Esp_Item_Painkiller_Color[3]), true);
										}
										if (Setting1::Esp_Item_FirstAidKit && Item.Name == "First Aid Kit")
										{
											//DrawImage(KID, Screen.X - 10, Screen.Y - 20, 30, 25);
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::Firstkit, true); //ImColor(Setting1::Esp_Item_FirstAidKit_Color[0], Setting1::Esp_Item_FirstAidKit_Color[1], Setting1::Esp_Item_FirstAidKit_Color[2], Setting1::Esp_Item_FirstAidKit_Color[3]), true);
										}
										if (Setting1::Esp_Item_MedKit && Item.Name == "Med Kit")
										{
											//DrawImage(AID, Screen.X - 10, Screen.Y - 20, 30, 25);
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::Madkit, true); //ImColor(Setting1::Esp_Item_MedKit_Color[0], Setting1::Esp_Item_MedKit_Color[1], Setting1::Esp_Item_MedKit_Color[2], Setting1::Esp_Item_MedKit_Color[3]), true);
										}
										if (Setting1::Esp_Item_AdrenalineSyringe && Item.Name == "Adrenaline Syringe")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::AdrenalineSyringe, true); //ImColor(Setting1::Esp_Item_AdrenalineSyringe_Color[0], Setting1::Esp_Item_AdrenalineSyringe_Color[1], Setting1::Esp_Item_AdrenalineSyringe_Color[2], Setting1::Esp_Item_AdrenalineSyringe_Color[3]), true);
										}

										/*if (Setting::Esp_Item_MedKit && Item.Name == "Med Kit")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_MedKit_Color[0], Setting::Esp_Item_MedKit_Color[1], Setting::Esp_Item_MedKit_Color[2], Setting::Esp_Item_MedKit_Color[3]), true);
											continue;
										}

										if (Setting::Esp_Item_FirstAidKit && Item.Name == "First Aid Kit")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_FirstAidKit_Color[0], Setting::Esp_Item_FirstAidKit_Color[1], Setting::Esp_Item_FirstAidKit_Color[2], Setting::Esp_Item_FirstAidKit_Color[3]), true);
											continue;
										}
										if (Setting::Esp_Item_Painkiller && Item.Name == "Painkiller")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Painkiller_Color[0], Setting::Esp_Item_Painkiller_Color[1], Setting::Esp_Item_Painkiller_Color[2], Setting::Esp_Item_Painkiller_Color[3]), true);
											continue;
										}

										if (Setting::Esp_Item_EnergyDrink && Item.Name == "Energy Drink")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_EnergyDrink_Color[0], Setting::Esp_Item_EnergyDrink_Color[1], Setting::Esp_Item_EnergyDrink_Color[2], Setting::Esp_Item_EnergyDrink_Color[3]), true);
											continue;
										}

										if (Setting::Esp_Item_AdrenalineSyringe && Item.Name == "Adrenaline Syringe")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_AdrenalineSyringe_Color[0], Setting::Esp_Item_AdrenalineSyringe_Color[1], Setting::Esp_Item_AdrenalineSyringe_Color[2], Setting::Esp_Item_AdrenalineSyringe_Color[3]), true);
											continue;
										}*/
									}

									if (Setting1::graned)
									{
										if (Setting1::GrenadeWarning)
										{
											ImColor warncolor;
											int randomNum = (rand() % 6) + 1;
											if (randomNum == 1)
											{
												warncolor = DX11::ImGui_DX11::Color::Red;
											}
											if (randomNum == 2)
											{
												warncolor = DX11::ImGui_DX11::Color::Black;
											}
											if (randomNum == 3)
											{
												warncolor = DX11::ImGui_DX11::Color::Blue;
											}
											if (randomNum == 4)
											{
												warncolor = DX11::ImGui_DX11::Color::Yellow;
											}
											if (randomNum == 5)
											{
												warncolor = DX11::ImGui_DX11::Color::White;
											}
											if (randomNum == 6)
											{
												warncolor = DX11::ImGui_DX11::Color::Orange;
											}
											if (Setting1::Esp_Item_Grenade && Item.Name == "Grenade_Warning")
											{
												std::string	Textt = Item.Name + "(" + to_string(Distance) + "m)";
												string bombnot = "BE CareFul Frag Grenade";
												DX11::ImGui_DX11::DrawCircle(Screen.X - 15, Screen.Y, 30, 15, ImColor(0.000f, 0.00f, 0.00f, 0.250f));
												/*DX11::ImGui_DX11::DrawFilledRect(Screen.X - 15, Screen.Y, 30, 15, ImColor(0.000f, 0.00f, 0.00f, 0.250f));
												DX11::ImGui_DX11::CornerBox(Screen.X - 15, Screen.Y, 30, 15, 0.9f, popcorn2, DX11::ImGui_DX11::Color::Red);*/
												DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 30, bombnot, DX11Window::Width / 2 - 10, DX11Window::Height / 130 * 20.5f, warncolor, true);
												DX11::ImGui_DX11::DrawImage(DX11::GN2, Screen.X - 10, Screen.Y - 20, 30, 25);
												DX11::ImGui_DX11::DrawCircle(Screen.X, Screen.Y, redzone, DX11::ImGui_DX11::Color::Red);
											}

											if (Setting1::Esp_Item_Molotof && Item.Name == "Molotov_Warning")
											{
												std::string	Textt = Item.Name + "(" + to_string(Distance) + "m)";
												string bombnot = "BE CareFul Molotov Cocktail";
												DX11::ImGui_DX11::DrawCircle(Screen.X - 15, Screen.Y, 30, 15, ImColor(0.000f, 0.00f, 0.00f, 0.250f));
												/*DX11::ImGui_DX11::DrawFilledRect(Screen.X - 15, Screen.Y, 30, 15, ImColor(0.000f, 0.00f, 0.00f, 0.250f));
												DX11::ImGui_DX11::CornerBox(Screen.X - 15, Screen.Y, 30, 15, 0.9f, popcorn2, DX11::ImGui_DX11::Color::Red);*/
												DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 30, bombnot, DX11Window::Width / 2 - 10, DX11Window::Height / 100 * 22.5f, warncolor, true);
												DX11::ImGui_DX11::DrawImage(DX11::BRU, Screen.X - 10, Screen.Y - 20, 30, 25);
												DX11::ImGui_DX11::DrawCircle(Screen.X, Screen.Y, redzone, DX11::ImGui_DX11::Color::Red);
											}
										}

										if (Setting1::Esp_Item_Frag && Item.Name == "Grenade")
										{
											std::string	Text = Item.Name + "(" + to_string(Distance) + "m)";
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Normalfontsize, Text, Screen.X, Screen.Y, Colors1::Grenade_Color, true); //DX11::ImGui_DX11::Color::Red, true);
											//DrawImage(GN2, Screen.X - 10, Screen.Y - 20, 30, 25);
											//DX11::ImGui_DX11::DrawCircle(Screen.X, Screen.Y, redzone, DX11::ImGui_DX11::Color::Red);
										}
										if (Setting1::Esp_Item_Smoke && Item.Name == "Smoke")
										{
											std::string	Text = Item.Name + "(" + to_string(Distance) + "m)";
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, SMOKES, Text, Screen.X, Screen.Y, Colors1::Smoke_Color, true); //ImColor(Esp_Item_Smoke_Color[0], Esp_Item_Smoke_Color[1], Esp_Item_Smoke_Color[2], Esp_Item_Smoke_Color[3]), true);
											//DrawImage(Smk, Screen.X - 10, Screen.Y - 20, 30, 25);
											//DX11::ImGui_DX11::DrawCircle(Screen.X, Screen.Y, redzone, DX11::ImGui_DX11::Color::Red);
										}
										if (Setting1::Esp_Item_Molotof && Item.Name == "Molotov Cocktail")
										{
											std::string	Text = Item.Name + "(" + to_string(Distance) + "m)";
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, MOLOS, Text, Screen.X, Screen.Y, Colors1::Molotof_Color, true); //ImColor(Esp_Item_Molotof_Color[0], Esp_Item_Molotof_Color[1], Esp_Item_Molotof_Color[2], Esp_Item_Molotof_Color[3]), true);
											//DrawImage(BRU, Screen.X - 10, Screen.Y - 20, 30, 25);
											//DX11::ImGui_DX11::DrawCircle(Screen.X, Screen.Y, redzone, DX11::ImGui_DX11::Color::Red);
										}
									}

									if (Setting::scope) 
									{
										Text = Item.Name + "  (" + to_string(Distance) + "m)";

										if (Setting1::Esp_Item_Holo && Item.Name == "Holo")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::Holo, true); //ImColor(Setting1::Esp_Item_Holo_Color[0], Setting1::Esp_Item_Holo_Color[1], Setting1::Esp_Item_Holo_Color[2], Setting1::Esp_Item_Holo_Color[3]), true);
										}

										if (Setting1::Esp_Item_Holo && Item.Name == "Red_Dot")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::Red_Dot, true); //ImColor(Setting1::Esp_Item_Holo_Color[0], Setting1::Esp_Item_Holo_Color[1], Setting1::Esp_Item_Holo_Color[2], Setting1::Esp_Item_Holo_Color[3]), true);
										}

										if (Setting1::Esp_Item_x2 && Item.Name == "2x")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::scope_2x, true); //ImColor(Setting1::Esp_Item_x2_Color[0], Setting1::Esp_Item_x2_Color[1], Setting1::Esp_Item_x2_Color[2], Setting1::Esp_Item_x2_Color[3]), true);
										}

										if (Setting1::Esp_Item_x3 && Item.Name == "3x")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::scope_3x, true); //ImColor(Setting1::Esp_Item_x3_Color[0], Setting1::Esp_Item_x3_Color[1], Setting1::Esp_Item_x3_Color[2], Setting1::Esp_Item_x3_Color[3]), true);
										}

										if (Setting1::Esp_Item_x4 && Item.Name == "4x")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::scope_4x, true); //ImColor(Setting1::Esp_Item_x4_Color[0], Setting1::Esp_Item_x4_Color[1], Setting1::Esp_Item_x4_Color[2], Setting1::Esp_Item_x4_Color[3]), true);
										}

										if (Setting1::Esp_Item_x6 && Item.Name == "6x")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::scope_6x, true); //ImColor(Setting1::Esp_Item_x6_Color[0], Setting1::Esp_Item_x6_Color[1], Setting1::Esp_Item_x6_Color[2], Setting1::Esp_Item_x6_Color[3]), true);
										}

										if (Setting1::Esp_Item_x8 && Item.Name == "8x")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Colors1::scope_8x, true); //ImColor(Setting1::Esp_Item_x8_Color[0], Setting1::Esp_Item_x8_Color[1], Setting1::Esp_Item_x8_Color[2], Setting1::Esp_Item_x8_Color[3]), true);
										}

										/*if (Setting::Esp_Item_x2 && Item.Name == "2x")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_x2_Color[0], Setting::Esp_Item_x2_Color[1], Setting::Esp_Item_x2_Color[2], Setting::Esp_Item_x2_Color[3]), true);
											continue;
										}

										if (Setting::Esp_Item_x3 && Item.Name == "3x")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_x3_Color[0], Setting::Esp_Item_x3_Color[1], Setting::Esp_Item_x3_Color[2], Setting::Esp_Item_x3_Color[3]), true);
											continue;
										}

										if (Setting::Esp_Item_x4 && Item.Name == "4x")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_x4_Color[0], Setting::Esp_Item_x4_Color[1], Setting::Esp_Item_x4_Color[2], Setting::Esp_Item_x4_Color[3]), true);
											continue;
										}

										if (Setting::Esp_Item_x6 && Item.Name == "6x")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_x6_Color[0], Setting::Esp_Item_x6_Color[1], Setting::Esp_Item_x6_Color[2], Setting::Esp_Item_x6_Color[3]), true);
											continue;
										}

										if (Setting::Esp_Item_x8 && Item.Name == "8x")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_x8_Color[0], Setting::Esp_Item_x8_Color[1], Setting::Esp_Item_x8_Color[2], Setting::Esp_Item_x8_Color[3]), true);
											continue;
										}*/
									}

									if (Setting::allitemss)//espds
									{
										if (Setting::Esp_Item_Bag1 && Item.Name == "Bag L.1")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Bag1_Color[0], Setting::Esp_Item_Bag1_Color[1], Setting::Esp_Item_Bag1_Color[2], Setting::Esp_Item_Bag1_Color[3]), true);
											continue;
										}

										if (Setting::Esp_Item_Bag2 && Item.Name == "Bag L.2")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Bag2_Color[0], Setting::Esp_Item_Bag2_Color[1], Setting::Esp_Item_Bag2_Color[2], Setting::Esp_Item_Bag2_Color[3]), true);
											continue;
										}

										if (Setting::Esp_Item_Helmet1 && Item.Name == "Helmet L.1")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Helmet1_Color[0], Setting::Esp_Item_Helmet1_Color[1], Setting::Esp_Item_Helmet1_Color[2], Setting::Esp_Item_Helmet1_Color[3]), true);
											continue;
										}

										if (Setting::Esp_Item_Helmet2 && Item.Name == "Helmet L.2")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Helmet2_Color[0], Setting::Esp_Item_Helmet2_Color[1], Setting::Esp_Item_Helmet2_Color[2], Setting::Esp_Item_Helmet2_Color[3]), true);
											continue;
										}

										if (Setting::Esp_Item_Armor1 && Item.Name == "Armor L.1")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Armor1_Color[0], Setting::Esp_Item_Armor1_Color[1], Setting::Esp_Item_Armor1_Color[2], Setting::Esp_Item_Armor1_Color[3]), true);
											continue;
										}

										if (Setting::Esp_Item_Armor2 && Item.Name == "Armor L.2")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Armor2_Color[0], Setting::Esp_Item_Armor2_Color[1], Setting::Esp_Item_Armor2_Color[2], Setting::Esp_Item_Armor2_Color[3]), true);
											continue;
										}


										if (Setting::Esp_Item_Mk47Mutant && Item.Name == "Mk47 Mutant")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Mk47Mutant_Color[0], Setting::Esp_Item_Mk47Mutant_Color[1], Setting::Esp_Item_Mk47Mutant_Color[2], Setting::Esp_Item_Mk47Mutant_Color[3]), true);
											continue;
										}

										if (Setting::Esp_Item_M16A4 && Item.Name == "M16A4")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_M16A4_Color[0], Setting::Esp_Item_M16A4_Color[1], Setting::Esp_Item_M16A4_Color[2], Setting::Esp_Item_M16A4_Color[3]), true);
											continue;
										}

										if (Setting::Esp_Item_G36C && Item.Name == "G36C")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_G36C_Color[0], Setting::Esp_Item_G36C_Color[1], Setting::Esp_Item_G36C_Color[2], Setting::Esp_Item_G36C_Color[3]), true);
											continue;
										}

										if (Setting::Esp_Item_QBZ && Item.Name == "QBZ")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_QBZ_Color[0], Setting::Esp_Item_QBZ_Color[1], Setting::Esp_Item_QBZ_Color[2], Setting::Esp_Item_QBZ_Color[3]), true);
											continue;
										}

										if (Setting::Esp_Item_QBU && Item.Name == "QBU")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_QBU_Color[0], Setting::Esp_Item_QBU_Color[1], Setting::Esp_Item_QBU_Color[2], Setting::Esp_Item_QBU_Color[3]), true);
											continue;
										}

										if (Setting::Esp_Item_SLR && Item.Name == "SLR")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_SLR_Color[0], Setting::Esp_Item_SLR_Color[1], Setting::Esp_Item_SLR_Color[2], Setting::Esp_Item_SLR_Color[3]), true);
											continue;
										}

										if (Setting::Esp_Item_Mini14 && Item.Name == "Mini-14")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Mini14_Color[0], Setting::Esp_Item_Mini14_Color[1], Setting::Esp_Item_Mini14_Color[2], Setting::Esp_Item_Mini14_Color[3]), true);
											continue;
										}

										if (Setting::Esp_Item_SKS && Item.Name == "SKS")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_SKS_Color[0], Setting::Esp_Item_SKS_Color[1], Setting::Esp_Item_SKS_Color[2], Setting::Esp_Item_SKS_Color[3]), true);
											continue;
										}


										if (Setting::Esp_Item_PP19 && Item.Name == "PP19")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_PP19_Color[0], Setting::Esp_Item_PP19_Color[1], Setting::Esp_Item_PP19_Color[2], Setting::Esp_Item_PP19_Color[3]), true);
											continue;
										}

										if (Setting::Esp_Item_TommyGun && Item.Name == "Tommy Gun")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_TommyGun_Color[0], Setting::Esp_Item_TommyGun_Color[1], Setting::Esp_Item_TommyGun_Color[2], Setting::Esp_Item_TommyGun_Color[3]), true);
											continue;
										}

										if (Setting::Esp_Item_MP5K && Item.Name == "MP5K")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_MP5K_Color[0], Setting::Esp_Item_MP5K_Color[1], Setting::Esp_Item_MP5K_Color[2], Setting::Esp_Item_MP5K_Color[3]), true);
											continue;
										}

										if (Setting::Esp_Item_UMP9 && Item.Name == "UMP9")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_UMP9_Color[0], Setting::Esp_Item_UMP9_Color[1], Setting::Esp_Item_UMP9_Color[2], Setting::Esp_Item_UMP9_Color[3]), true);
											continue;
										}

										if (Setting::Esp_Item_Vector && Item.Name == "Vector")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Vector_Color[0], Setting::Esp_Item_Vector_Color[1], Setting::Esp_Item_Vector_Color[2], Setting::Esp_Item_Vector_Color[3]), true);
											continue;
										}

										if (Setting::Esp_Item_Uzi && Item.Name == "Uzi")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Uzi_Color[0], Setting::Esp_Item_Uzi_Color[1], Setting::Esp_Item_Uzi_Color[2], Setting::Esp_Item_Uzi_Color[3]), true);
											continue;
										}

										if (Setting::Esp_Item_762mm && Item.Name == "7.62mm")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_762mm_Color[0], Setting::Esp_Item_762mm_Color[1], Setting::Esp_Item_762mm_Color[2], Setting::Esp_Item_762mm_Color[3]), true);
											continue;
										}

										if (Setting::Esp_Item_556mm && Item.Name == "5.56mm")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_556mm_Color[0], Setting::Esp_Item_556mm_Color[1], Setting::Esp_Item_556mm_Color[2], Setting::Esp_Item_556mm_Color[3]), true);
											continue;
										}

										if (Setting::Esp_Item_9mm && Item.Name == "9mm")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_9mm_Color[0], Setting::Esp_Item_9mm_Color[1], Setting::Esp_Item_9mm_Color[2], Setting::Esp_Item_9mm_Color[3]), true);
											continue;
										}
										if (Setting::Esp_Item_45ACP && Item.Name == "45ACP")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_45ACP_Color[0], Setting::Esp_Item_45ACP_Color[1], Setting::Esp_Item_45ACP_Color[2], Setting::Esp_Item_45ACP_Color[3]), true);
											continue;
										}

										if (Setting::Esp_Item_Holo && Item.Name == "Holo")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Holo_Color[0], Setting::Esp_Item_Holo_Color[1], Setting::Esp_Item_Holo_Color[2], Setting::Esp_Item_Holo_Color[3]), true);
											continue;
										}
										if (Setting::Esp_Item_M249 && Item.Name == "M249")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, Colors::M249, true);
											continue;
										}

										if (Setting::Esp_Item_Mk12 && Item.Name == "MK12")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, Colors::MK12, true);
											continue;
										}
										if (Setting::Esp_Item_SniperAMR && Item.Name == "Sniper-AMR")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_SniperAMR_Color[0], Setting::Esp_Item_SniperAMR_Color[1], Setting::Esp_Item_SniperAMR_Color[2], Setting::Esp_Item_SniperAMR_Color[3]), true);
											continue;
										}
										if (Setting::Esp_Item_BulletAMR && Item.Name == "Ammo-50BMG")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_BulletAMR_Color[0], Setting::Esp_Item_BulletAMR_Color[1], Setting::Esp_Item_BulletAMR_Color[2], Setting::Esp_Item_BulletAMR_Color[3]), true);
											continue;
										}
									}

								}
							}
						}

						if (!Setting::fightmode)
						{
							if (Setting1::AirDropBox)
							{
								for (Item& Item : Data::ItemList)
								{
									if (!Algorithm::WorldToScreen(Data::lOCALPLAYERPosotion, Item.Position, Screen, &Distance, ViewMatrix)) continue;
									if (Distance < 5 || Distance > 2000)
									{
										continue;
									}

									Text = Item.Name + "  (" + to_string(Distance) + "m)";
									std::string air = Item.Name + " (" + to_string(Distance) + "M)";

									if (Setting1::style1)
									{
										if (Setting1::AirDropBox && Item.Name == "Air Drop")
										{
											//DrawImage(DROP, Screen.X, Screen.Y, 18, 12);
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::AirDropBoxs1, air, Screen.X - 20, Screen.Y + 15, Setting1::AirDropBoxc1, true);
										}
									}
									if (Setting1::style2)
									{
										if (Setting1::AirDropBox && Item.Name == "Air Drop")
										{
											//DrawImage(DROP, Screen.X, Screen.Y, 18, 12);
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::AirDropBoxs2, air, Screen.X - 20, Screen.Y + 15, Setting1::AirDropBoxc2, true);
										}
									}
									if (Setting1::style3)
									{
										if (Setting1::AirDropBox && Item.Name == "Air Drop")
										{
											//DrawImage(DROP, Screen.X, Screen.Y, 18, 12);
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::AirDropBoxs3, air, Screen.X - 20, Screen.Y + 15, Setting1::AirDropBoxc3, true);
										}
									}

								}
								
							}

							if (Setting1::deadbox)
							{
								for (Item& Item : Data::ItemList)
								{
									if (!Algorithm::WorldToScreen(Data::lOCALPLAYERPosotion, Item.Position, Screen, &Distance, ViewMatrix)) continue;
									if (Distance < 5 || Distance > 120)
									{
										continue;
									}

									Text = Item.Name + "  (" + to_string(Distance) + "m)";
									std::string air = Item.Name + " (" + to_string(Distance) + "M)";

									if (Setting1::style1)
									{
										if (Setting1::deadbox && Item.Name == "Death Box")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::deadboxs1, air, Screen.X - 20, Screen.Y + 15, Setting1::deadboxc1, true);
										}
									}
									if (Setting1::style2)
									{
										if (Setting1::deadbox && Item.Name == "Death Box")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::deadboxs2, air, Screen.X - 20, Screen.Y + 15, Setting1::deadboxc2, true);
										}
									}
									if (Setting1::style3)
									{
										if (Setting1::deadbox && Item.Name == "Death Box")
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::deadboxs3, air, Screen.X + 20, Screen.Y + 15, Setting1::deadboxc3, true);
										}
									}
								}
							}

							if (Setting1::deadboxItems)
							{
								ImColor color;
								for (int i = 0; i < g_pEsp->lootboxr.size(); i++)
								{

									if (!Algorithm::WorldToScreen(Data::lOCALPLAYERPosotion, g_pEsp->lootboxr[i].Position, Screen, &Distance, ViewMatrix)) continue;
									if (Distance < 5 || Distance > 120)
									{
										continue;
									}

									for (int k = 0; k < g_pEsp->lootboxr[i].boxitem.size(); k++)
									{
										color = g_pEsp->lootboxr[i].boxitem[k].colorcod;
										std::string text = g_pEsp->lootboxr[i].boxitem[k].Displayname;


										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, text, Screen.X, Screen.Y - 15 * (k), g_pEsp->lootboxr[i].boxitem[k].colorcod, false);

										if (Setting1::boxitemBagShadow)
										{
											DX11::ImGui_DX11::DrawFilledRect(Screen.X - 10, Screen.Y - 15 * (k), 100, 15, ImColor(0.000f, 0.00f, 0.00f, 0.100f));
											////DX11::ImGui_DX11::DrawFilledRect(Screen.X - 10, Screen.Y - 15 * (k), 100, 15, ImColor(0.000f, 0.00f, 0.00f, 0.200f));
										}
										if (Setting1::itemrect)
										{
											/*if (Setting1::redioption == 1)
											{
												DX11::ImGui_DX11::CornerBox(Screen.X - 10, Screen.Y - 15 * (k), 110, 15, 0.6f, popcorn2, Colors1::bgcornerColor);
											}

											if (Setting1::redioption == 2)
											{
												DX11::ImGui_DX11::DrawRectangle(Screen.X - 10, Screen.Y - 15 * (k), 100, 15, Colors1::bgcornerColor, 0.6f);
											}*/
											if (Setting1::redioption == 1)
											{
												DX11::ImGui_DX11::CornerBox(Screen.X - 10, Screen.Y - 15 * (k), 1, 15, 0.6f, popcorn2, Colors1::bgcornerColor);
											}

											if (Setting1::redioption == 2)
											{
												DX11::ImGui_DX11::DrawRectangle(Screen.X - 10, Screen.Y - 15 * (k), 1, 12, Colors1::bgcornerColor, 0.6f);
											}
										}
									}
								}
							}
						}

					}

					if (!Setting::fightmode)
					{
						if (Setting1::Vehicle)
						{
							if (Setting1::style1)
							{
								if (Setting1::Vehiclest1)
								{
									if (Data::VehicleList.size() != 0)
									{
										TempVehicalList.clear();
										TempVehicalList = Data::VehicleList;
										for (Vehicle& Vehicle : Data::VehicleList)
										{
											Vehicle.Position = Utility::ReadMemoryEx<VECTOR3>(Utility::ReadMemoryEx<DWORD>(Vehicle.Address + Offset::RootComponent) + Offset::Position);
											if (!Algorithm::WorldToScreen(Data::lOCALPLAYERPosotion, Vehicle.Position, Screen, &Distance, ViewMatrix)) continue;
											if (Distance < 12 || Distance > 700)
											{
												continue;
											}

											/*Text = Vehicle.Name + "  (" + to_string(Distance) + "M)";
											ImVec4 color;
											if (Vehicle.driving)
											{
												color = DX11::ImGui_DX11::Color::Red;
											}
											else
											{
												color = Setting1::Vehiclec1;
											}
											ImVec2 TextSize = DX11::ImGui_DX11::pRegularFont->CalcTextSizeA(Setting1::Vehicles1, FLT_MAX, 0.0f, Text.c_str());

											std::string hp;
											if (Setting1::VehicleHpst1)
											{
												hp.append("Gas : ").append(std::to_string((int)(Vehicle.oil)).append(" - HP : ").append(std::to_string((int)(Vehicle.hp)).append("")));
												DX11::ImGui_DX11::DrawBloodCarhp(Screen.X - 55, Screen.Y + 17, 115.0f, 2.0f, Vehicle.hp);
											}

											if (Setting1::VehicleFeulst1)
											{
												DX11::ImGui_DX11::DrawBloodCaroil(Screen.X - 55, Screen.Y + 20, 115.0f, 2.0f, Vehicle.oil);

											}

											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Text, Screen.X - 50, Screen.Y, color, true);
											continue;*/

											if (Setting1::Vehiclest1)
											{
												if (Setting1::Vehiclest1)
												{
													Text = Vehicle.Name + "  (" + to_string(Distance) + "M)";

													std::string hp;
													if (Setting1::VehicleHpst1)
													{
														hp.append("Gas : ").append(std::to_string((int)(Vehicle.oil)).append(" - HP : ").append(std::to_string((int)(Vehicle.hp)).append("")));
														DX11::ImGui_DX11::DrawBloodCarhp(Screen.X - 55, Screen.Y + 17, 115.0f, 2.0f, Vehicle.hp);
													}

													if (Setting1::VehicleFeulst1)
													{
														DX11::ImGui_DX11::DrawBloodCaroil(Screen.X - 55, Screen.Y + 20, 115.0f, 2.0f, Vehicle.oil);
													}

													if (Setting1::vahicle_item && Vehicle.Name == "BRDM")
													{
														Text = Vehicle.Name;
														std::string Textv = "| Seat  4  | Car " + to_string(Distance) + " M";

														if (Vehicle.driving)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

														}
														else
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, Setting1::Vehiclec1, true);

														}
													}
													if (Setting1::Esp_Item_AKM && Vehicle.Name == "Minibus")
													{
														Text = Vehicle.Name;
														std::string Textv = "| Seat  4  | Car " + to_string(Distance) + " M";

														if (Vehicle.driving)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

														}
														else
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, Setting1::Vehiclec1, true);

														}
													}
													if (Setting1::vahicle_item && Vehicle.Name == "UTV")
													{
														Text = Vehicle.Name;
														std::string Textv = "| Seat  4  | Car " + to_string(Distance) + " M";

														if (Vehicle.driving)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

														}
														else
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, Setting1::Vehiclec1, true);

														}
													}
													if (Setting1::vahicle_item && Vehicle.Name == "Monster Truck")
													{
														Text = Vehicle.Name;
														std::string Textv = "| Seat  4  | Car " + to_string(Distance) + " M";

														if (Vehicle.driving)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

														}
														else
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, Setting1::Vehiclec1, true);

														}
													}

													if (Setting1::vahicle_item && Vehicle.Name == "Scooter")
													{
														Text = Vehicle.Name;
														std::string Textv = "| Seat  2  | Car " + to_string(Distance) + " M";

														if (Vehicle.driving)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

														}
														else
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, Setting1::Vehiclec1, true);

														}
													}
													if (Setting1::vahicle_item && Vehicle.Name == "Motorcycle")
													{
														Text = Vehicle.Name;
														std::string Textv = "| Seat  2  | Car " + to_string(Distance) + " M";

														if (Vehicle.driving)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

														}
														else
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, Setting1::Vehiclec1, true);

														}
													}
													if (Setting1::vahicle_item && Vehicle.Name == "Snowmobile" || Vehicle.Name == "SnowBike")
													{
														Text = Vehicle.Name;
														std::string Textv = "| Seat  2  | Car " + to_string(Distance) + " M";

														if (Vehicle.driving)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

														}
														else
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, Setting1::Vehiclec1, true);

														}
													}
													if (Setting1::vahicle_item && Vehicle.Name == "Tuk")
													{
														Text = Vehicle.Name;
														std::string Textv = "| Seat  4  | Car " + to_string(Distance) + " M";

														if (Vehicle.driving)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

														}
														else
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, Setting1::Vehiclec1, true);

														}
													}
													if (Setting1::vahicle_item && Vehicle.Name == "Buggy")
													{
														Text = Vehicle.Name;
														std::string Textv = "| Seat  2  | Car " + to_string(Distance) + " M";

														if (Vehicle.driving)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

														}
														else
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, Setting1::Vehiclec1, true);

														}
													}
													if (Setting1::vahicle_item && Vehicle.Name == "Sportsa")
													{
														Text = Vehicle.Name;
														std::string Textv = "| Seat  2  | Car " + to_string(Distance) + " M";

														if (Vehicle.driving)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

														}
														else
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, Setting1::Vehiclec1, true);

														}
													}
													if (Setting1::vahicle_item && Vehicle.Name == "Sports")
													{
														Text = Vehicle.Name;
														std::string Textv = "| Seat  2  | Car " + to_string(Distance) + " M";

														if (Vehicle.driving)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

														}
														else
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, Setting1::Vehiclec1, true);

														}
													}
													if (Setting1::vahicle_item && Vehicle.Name == "Dacia")
													{
														Text = Vehicle.Name;
														std::string Textv = "| Seat  4  | Car " + to_string(Distance) + " M";

														if (Vehicle.driving)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

														}
														else
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, Setting1::Vehiclec1, true);

														}
													}
													if (Setting1::vahicle_item && Vehicle.Name == "Rony")
													{
														Text = Vehicle.Name;
														std::string Textv = "| Seat  4  | Car " + to_string(Distance) + " M";

														if (Vehicle.driving)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

														}
														else
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, Setting1::Vehiclec1, true);

														}
													}
													if (Setting1::Esp_Item_AKM && Vehicle.Name == "UAZ")
													{
														Text = Vehicle.Name;
														std::string Textv = "| Seat  4  | Car " + to_string(Distance) + " M";

														if (Vehicle.driving)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

														}
														else
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, Setting1::Vehiclec1, true);

														}
													}

													if (Setting1::Esp_Item_AKM && Vehicle.Name == "PG117")
													{
														Text = Vehicle.Name;
														std::string Textv = "| Seat  4  | Ship " + to_string(Distance) + " M";

														if (Vehicle.driving)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

														}
														else
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, Setting1::Vehiclec1, true);

														}
													}
													if (Setting1::Esp_Item_AKM && Vehicle.Name == "Aquarail")
													{
														Text = Vehicle.Name;
														std::string Textv = "| Seat  2  | Ship " + to_string(Distance) + " M";

														if (Vehicle.driving)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

														}
														else
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, Setting1::Vehiclec1, true);

														}
													}
													if (Setting1::Esp_Item_AKM && Vehicle.Name == "Plane")
													{
														if (Vehicle.driving)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Text, Screen.X - 50, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

														}
														else
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Text, Screen.X - 50, Screen.Y, Setting1::Vehiclec1, true);

														}
													}

													if (Setting1::vahicle_item && Vehicle.Name == "Coupe-RB")
													{
														Text = Vehicle.Name;
														std::string Textv = "| Seat  2  | Car " + to_string(Distance) + " M";

														if (Vehicle.driving)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

														}
														else
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, Setting1::Vehiclec1, true);

														}
													}
													
													if (Setting1::vahicle_item && Vehicle.Name == "Motorglider")
													{
														Text = Vehicle.Name;
														std::string Textv = "| Seat  2  | Car " + to_string(Distance) + " M";

														if (Vehicle.driving)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

														}
														else
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, Setting1::Vehiclec1, true);

														}
													}
													
													if (Setting1::vahicle_item && Vehicle.Name == "PickUp Truck")
													{
														Text = Vehicle.Name;
														std::string Textv = "| Seat  4  | Car " + to_string(Distance) + " M";

														if (Vehicle.driving)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

														}
														else
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, Setting1::Vehiclec1, true);

														}
													}
													
													if (Setting1::vahicle_item && Vehicle.Name == "Quad")
													{
														Text = Vehicle.Name;
														std::string Textv = "| Seat  2  | Car " + to_string(Distance) + " M";

														if (Vehicle.driving)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

														}
														else
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, Setting1::Vehiclec1, true);

														}
													}
													
													if (Setting1::vahicle_item && Vehicle.Name == "Tuk Tuk")
													{
														Text = Vehicle.Name;
														std::string Textv = "| Seat  3  | Car " + to_string(Distance) + " M";

														if (Vehicle.driving)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

														}
														else
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, Setting1::Vehiclec1, true);

														}
													}

													if (Setting1::vahicle_item && Vehicle.Name == "Bike")
													{
														Text = Vehicle.Name;
														std::string Textv = "| Seat  2  | Car " + to_string(Distance) + " M";

														if (Vehicle.driving)
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

														}
														else
														{
															DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles1, Textv, Screen.X - 50, Screen.Y, Setting1::Vehiclec1, true);

														}
													}
																									
												}
											}
										}
									}
								}
							}

							if (Setting1::style2)
							{
								if (Setting1::Vehiclest2)
								{
									if (Data::VehicleList.size() != 0)
									{
										TempVehicalList.clear();
										TempVehicalList = Data::VehicleList;
										for (Vehicle& Vehicle : Data::VehicleList)
										{
											Vehicle.Position = Utility::ReadMemoryEx<VECTOR3>(Utility::ReadMemoryEx<DWORD>(Vehicle.Address + Offset::RootComponent) + Offset::Position);
											if (!Algorithm::WorldToScreen(Data::lOCALPLAYERPosotion, Vehicle.Position, Screen, &Distance, ViewMatrix)) continue;
											if (Distance < 12 || Distance > 700)
											{
												continue;
											}
											Text = Vehicle.Name + " | " + to_string(Distance) + "m";
											std::string hp;
											ImVec4 color;
											if (Vehicle.driving)
											{
												color = DX11::ImGui_DX11::Color::Red;
											}
											else
											{
												color = Setting1::Vehiclec2;
											}
											ImVec2 TextSize = DX11::ImGui_DX11::pRegularFont->CalcTextSizeA(Setting1::Vehicles2, FLT_MAX, 0.0f, Text.c_str());

											if (Setting1::VehicleHpst2)
											{
												hp.append("Gas : ").append(std::to_string((int)(Vehicle.oil)).append(" - HP : ").append(std::to_string((int)(Vehicle.hp)).append("")));
												DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles2, hp, Screen.X - 0, Screen.Y + 20, color, true);

											}
											if (Setting1::VehicleFeulst2)
											{
												//DX11::ImGui_DX11::DrawBlood(Screen.X - 30, Screen.Y + 17, 20.00f, 2.0, Vehicle.oil);
											}

											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles2, Text, Screen.X, Screen.Y, color, true);
											continue;
										}
									}

								}
							}

							if (Setting1::style3)
							{
								if (Setting1::Vehiclest3)
								{
									if (Data::VehicleList.size() != 0)
									{
										TempVehicalList.clear();
										TempVehicalList = Data::VehicleList;
										for (Vehicle& Vehicle : Data::VehicleList)
										{
											Vehicle.Position = Utility::ReadMemoryEx<VECTOR3>(Utility::ReadMemoryEx<DWORD>(Vehicle.Address + Offset::RootComponent) + Offset::Position);
											if (!Algorithm::WorldToScreen(Data::lOCALPLAYERPosotion, Vehicle.Position, Screen, &Distance, ViewMatrix)) continue;
											if (Distance < 12 || Distance > 700)
											{
												continue;
											}
											Text = Vehicle.Name + " | " + to_string(Distance) + "m";
											std::string hp;
											ImVec4 color;
											if (Vehicle.driving)
											{
												color = DX11::ImGui_DX11::Color::Red;
											}
											else
											{
												color = Setting1::Vehiclec3;
											}
											ImVec2 TextSize = DX11::ImGui_DX11::pRegularFont->CalcTextSizeA(Setting1::Vehicles3, FLT_MAX, 0.0f, Text.c_str());

											if (Setting1::VehicleHpst3)
											{
												hp.append("Gas : ").append(std::to_string((int)(Vehicle.oil)).append(" - HP : ").append(std::to_string((int)(Vehicle.hp)).append("")));
												DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles3, hp, Screen.X - 0, Screen.Y + 20, color, true);

											}
											if (Setting1::VehicleFeulst3)
											{
												//DX11::ImGui_DX11::DrawBlood(Screen.X - 30, Screen.Y + 17, 20.00f, 2.0, Vehicle.oil);
											}

											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::Vehicles3, Text, Screen.X, Screen.Y, color, true);
											continue;
										}
									}

								}
							}
						}

						if (Setting1::Vehicle)
						{
							{
								//if (Data::VehicleList.size() != 0)
								//{
								//	TempVehicalList.clear();
								//	TempVehicalList = Data::VehicleList;

								//	for (Vehicle& Vehicle : Data::VehicleList)
								//	{
								//		Vehicle.Position = Utility::ReadMemoryEx<VECTOR3>(Utility::ReadMemoryEx<DWORD>(Vehicle.Address + Offset::RootComponent) + Offset::Position);
								//		if (!Algorithm::WorldToScreen(Data::lOCALPLAYERPosotion, Vehicle.Position, Screen, &Distance, ViewMatrix)) continue;
								//		if (Distance < 12 || Distance > 700)
								//		{
								//			continue;
								//		}
								//		Text = Vehicle.Name + " | " + to_string(Distance) + "m";
								//		std::string hp;
								//		ImVec4 color;
								//		if (Vehicle.driving)
								//		{
								//			color = DX11::ImGui_DX11::Color::Red;
								//		}
								//		else
								//		{
								//			color = Colors::vehicle;
								//		}
								//		ImVec2 TextSize = DX11::ImGui_DX11::pRegularFont->CalcTextSizeA(vehisize, FLT_MAX, 0.0f, Text.c_str());

								//		if (Setting::hp)
								//		{
								//			const char* Fuel = ("%d ", ICON_FA_BATTERY_FULL);
								//			if (Vehicle.oil == 100.0) {
								//				Fuel = ("%d ", ICON_FA_BATTERY_FULL);
								//			}
								//			else if (Vehicle.oil > 75.0) {
								//				Fuel = ("%d ", ICON_FA_BATTERY_THREE_QUARTERS);
								//			}
								//			else if (Vehicle.oil > 50.0 && Vehicle.oil <= 75.0) {
								//				Fuel = ("%d ", ICON_FA_BATTERY_HALF);
								//			}
								//			else 	if (Vehicle.oil > 25.0 && Vehicle.oil <= 50.0)
								//			{
								//				Fuel = ("%d ", ICON_FA_BATTERY_QUARTER);

								//			}
								//			else if (Vehicle.oil <= 0) {
								//				Fuel = ("%d ", ICON_FA_BATTERY_EMPTY);
								//			}
								//			else {
								//				continue;
								//			}
								//			string OIL = std::to_string((int)(Vehicle.oil));







								//			// hp.append("%d :-", ICON_FA_HEART).append(std::to_string((int)(Vehicle.oil)).append(" ?:-").append(std::to_string((int)(Vehicle.hp)).append("")));


								//			// DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - 5, Screen.Y + 23, Vehicle.hp, 2.0f, Colors::vehicle);
								//		//	 DX11::ImGui_DX11::DrawUnFilledRectangle2(Screen.X - 2, Screen.Y + 13, TextSize.x, 2.0f, DX11::ImGui_DX11::Color::Cyan);
								//			// DX11::ImGui_DX11::DrawUnFilledRectangle2(Screen.X - 5, Screen.Y + 23, Vehicle.oil, 2.0f, DX11::ImGui_DX11::Color::Olive);

								//			DX11::ImGui_DX11::DrawStringchar(DX11::ImGui_DX11::pRegularFont, 12, Fuel, Screen.X + 48, Screen.Y + 23, DX11::ImGui_DX11::Color::Yellow, true);
								//			DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 12, OIL, Screen.X + 58, Screen.Y + 23, DX11::ImGui_DX11::Color::enem2, true);
								//			//	 DX11::ImGui_DX11::DrawBlood(Screen.X - 5, Screen.Y + 23, 2, 4.0f, Vehicle.hp);
								//				//DX11::ImGui_DX11::DrawBlood(Screen.X - 5, Screen.Y + 31, 80.0f, 4.0f, Vehicle.oil);
								//				// DX11::ImGui_DX11::DrawImage(DX11::Heart, Screen.X  -5, Screen.Y + 20, 15, 15);

								//				//DX11::ImGui_DX11::DrawLine(Screen.X - 5, Screen.Y + 23, screen_end.X, screen_end.Y, Colors::enemyLineofSight, 2);
								//		}

								//		if (Setting::feul)
								//		{
								//			const char* Heart = ("%d ", ICON_FA_HEARTBEAT);
								//			string HPP = std::to_string((int)(Vehicle.hp));
								//			DX11::ImGui_DX11::DrawStringchar(DX11::ImGui_DX11::pRegularFont, 12, Heart, Screen.X + 10, Screen.Y + 23, DX11::ImGui_DX11::Color::Green, true);
								//			DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 12, HPP, Screen.X + 18, Screen.Y + 23, DX11::ImGui_DX11::Color::enem2, true);
								//		}

								//		//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, vehisize, Text, Screen.X, Screen.Y, color, true);
								//		DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, SettingMenu2::VehicleSize, Text, Screen.X, Screen.Y, color, true);
								//		continue;

								//	}
								//}
							}
						}
					}

					if (Setting::BombAlert)
					{
						TempBombAlertList.clear();
						TempBombAlertList = Data::BombAlertList;
						for (BombAlert& bomb : TempBombAlertList) {
							bomb.Position = Utility::ReadMemoryEx<VECTOR3>(Utility::ReadMemoryEx<DWORD>(bomb.Address + Offset::RootComponent) + Offset::Position);
							//bomb.Position = Utility::ReadMemoryEx<VECTOR3>(Data::RootComponent + Offset::Position);
							if (!Algorithm::WorldToScreen(Data::lOCALPLAYERPosotion, bomb.Position, Screen, &Distance, ViewMatrix)) continue;
							if (Distance < 1 || Distance > 350)
							{
								continue;
							}

							//if (Distance > 210)continue;

							string  Name = bomb.Name + " [" + to_string(Distance) + "m]";
							const char* Aim;
							//string time = to_string(bomb.timeLeft);
							//DX11::ImGui_DX11::DrawCircle(Screen.X, Screen.Y, 12.0f, Colors::Granadeswarn);
							
							if (bomb.Name == "Smoke" || bomb.Name == "[ALERT] !Flash Granade" || bomb.Name == "Air Bomb !")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Name, Screen.X, Screen.Y - 5, DX11::ImGui_DX11::Color::Red, true);


							}
							if (bomb.Name == "Frag")
							{
								Aim = ("\xef\x87\xa2 ");
								DX11::ImGui_DX11::DrawStringchar(DX11::ImGui_DX11::pRegularFont, 16, Aim, Screen.X, Screen.Y - 4, DX11::ImGui_DX11::Color::Red, true);
								//Algorithm::Draw3Dcircle(ViewMatrix, Data::lOCALPLAYERPosotion, bomb.Position, 42, 500.0f, 1.0f, DX11::ImGui_DX11::Color::Green);
							}
							if (bomb.Name == "Burn")
							{
								Aim = ("\xef\x81\xad ");
								DX11::ImGui_DX11::DrawStringchar(DX11::ImGui_DX11::pRegularFont, 16, Aim, Screen.X, Screen.Y - 4, DX11::ImGui_DX11::Color::Red, true);

							}
							Algorithm::Draw3Dcircle(ViewMatrix, Data::lOCALPLAYERPosotion, bomb.Position, 42, 600.0f, 1.0f, DX11::ImGui_DX11::Color::Green);
							Algorithm::Draw3Dcircle(ViewMatrix, Data::lOCALPLAYERPosotion, bomb.Position, 42, 500.0f, 1.0f, DX11::ImGui_DX11::Color::Yellow);
							Algorithm::Draw3Dcircle(ViewMatrix, Data::lOCALPLAYERPosotion, bomb.Position, 42, 300.0f, 1.0f, DX11::ImGui_DX11::Color::Red);
							Algorithm::Draw3Dcircle(ViewMatrix, Data::lOCALPLAYERPosotion, bomb.Position, 42, 150.0f, 1.0f, DX11::ImGui_DX11::Color::Red);
							continue;
							
						}

					}

					/*if (Setting::fightmode)
					{
						Text = " ";
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 1, Text, DX11Window::Width / 2 + 0, DX11Window::Height / 1 - 25, DX11::ImGui_DX11::Color::Green, true);

					}
					else
					{
						Text = " ";
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 1, Text, DX11Window::Width / 2 + 0, DX11Window::Height / 1 - 25, DX11::ImGui_DX11::Color::Green, true);
					}*/
				}
			}

			ImGui::EndFrame();

			DX11::BeginDraw();
			ImGui::Render();
			ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
			DX11::EndDraw();


			DX11Window::IsDrawing = false;


			DX11Window::IsDrawing = true;
		}
		catch (int e)
		{
			//std::cout << e << std::endl;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}


}