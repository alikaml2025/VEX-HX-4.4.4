#pragma once

namespace Settings
{
	static int Tab = 1;
}

bool unload = false;


inline bool FileExist(const std::string& name) {
	if (FILE* file = fopen(name.c_str(), "r")) {
		fclose(file);
		return true;
	}
	else {
		return false;
	}
}

int system_no_output1(std::string command)
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


static void HelpMarkerQuestionMark(const char* desc)
{
	ImGui::TextDisabled("(?)");
	if (ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(desc);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

ImVec4 to_vec4(float r, float g, float b, float a)
{
	return ImVec4(r / 255.0, g / 255.0, b / 255.0, a / 255.0);


}

void CustomImGUIStyle4()
{
	ImGuiIO& io = ImGui::GetIO();
	ImGuiStyle& style = ImGui::GetStyle();
	style.WindowPadding = ImVec2(4, 9);
	style.WindowRounding = 1.0f; //= 10.0f;
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

	//Window Opacity and colour===============================================================
	style.Colors[ImGuiCol_WindowBg] = ImColor(0, 0, 0, 200);
	style.Colors[ImGuiCol_Border] = ImColor(0, 110, 255, 200);
	//Main Window Back Color============================================================
	//style.Colors[ImGuiCol_ChildBg] = ImVec4(5.03399e-07, 4.41989e-07, 1e-06, 0.84530);
	style.Colors[ImGuiCol_ChildBg] = ImColor(0, 0, 0, 0);

	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 1.0f);
	style.Colors[ImGuiCol_FrameBg] = ImColor(0, 110, 255, 150);//CheckMark and Roll Bag
	style.Colors[ImGuiCol_FrameBgHovered] = ImColor(0, 110, 255, 100);
	style.Colors[ImGuiCol_FrameBgActive] = ImColor(0, 110, 255, 200);

	//Title Bar Color============================================================
	style.Colors[ImGuiCol_TitleBg] = ImColor(0, 0, 0, 250);
	style.Colors[ImGuiCol_TitleBgActive] = ImColor(0, 110, 255, 250);
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
	style.Colors[ImGuiCol_Button] = ImColor(0, 110, 255, 100);
	style.Colors[ImGuiCol_ButtonHovered] = ImColor(0, 110, 255, 150);
	style.Colors[ImGuiCol_ButtonActive] = ImColor(0, 110, 255, 200);


	colors[ImGuiCol_Header] = ImColor(0, 110, 255, 100);
	colors[ImGuiCol_HeaderHovered] = ImColor(0, 110, 255, 150);
	colors[ImGuiCol_HeaderActive] = ImColor(0, 110, 255, 200);

	colors[ImGuiCol_SeparatorHovered] = ImColor(0, 110, 255, 150);
	colors[ImGuiCol_SeparatorActive] = ImColor(0, 110, 255, 250);

	colors[ImGuiCol_ResizeGrip] = ImColor(0, 110, 255, 100);
	colors[ImGuiCol_ResizeGripHovered] = ImColor(0, 110, 255, 150);
	colors[ImGuiCol_ResizeGripActive] = ImColor(0, 110, 255, 200);


	style.Colors[ImGuiCol_PlotHistogram] = ImColor(66, 66, 66, 250);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImColor(66, 66, 66, 250);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImColor(66, 66, 66, 250);
	style.Colors[ImGuiCol_PlotLines] = ImColor(66, 66, 66, 250);

	colors[ImGuiCol_PlotHistogram] = ImColor(66, 66, 66, 250);
	colors[ImGuiCol_PlotHistogramHovered] = ImColor(66, 66, 66, 250);
	colors[ImGuiCol_PlotLinesHovered] = ImColor(66, 66, 66, 250);
	colors[ImGuiCol_PlotLines] = ImColor(66, 66, 66, 250);

	/*style.Colors[ImGuiCol_Tab] = ImColor(0, 110, 255, 100);
	style.Colors[ImGuiCol_TabHovered] = ImColor(0, 110, 255, 150);
	style.Colors[ImGuiCol_TabActive] = ImColor(0, 110, 255, 255);*/
	//colors[ImGuiCol_TabUnfocused] = ImVec4(0.038f, 0.050f, 0.136f, 1.000f);
	style.Colors[ImGuiCol_Tab] = ImColor(220, 140, 0, 250);
	style.Colors[ImGuiCol_TabHovered] = ImColor(130, 30, 0, 250);
	style.Colors[ImGuiCol_TabActive] = ImColor(255, 110, 0, 150);

	colors[ImGuiCol_TabUnfocusedActive] = ImColor(66, 66, 66, 250);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.98f, 0.26f, 0.26f, 0.35f);
	colors[ImGuiCol_NavHighlight] = ImColor(66, 66, 66, 250);
	//style.Colors[ImGuiCol_Node]

}


#pragma region Color
float m16[] = { 1.000f, 0.647f, 0.000f, 1.000f };
float AKM[] = { 1.000f, 0.647f, 0.000f, 1.000f };
float AWM[] = { 1.000f, 0.647f, 0.000f, 1.000f };
float AWMimmo[] = { 0.942f, 0.300f, 0.073f, 1.000f };
float AirAttack[] = { 1.000f, 0.000f, 0.000f, 1.000f };
float scarl[] = { 0.000f, 1.000f, 0.318f, 1.000f };
float m762[] = { 0.000f, 1.000f, 0.318f, 1.000f };
float M24[] = { 1.000f, 0.647f, 0.000f, 1.000f };
float GROZZA[] = { 1.000f, 0.647f, 0.000f, 1.000f };
float scope8x[] = { 0.866f, 0.128f, 0.081f, 1.000f };
float kar98[] = { 1.000f, 0.647f, 0.000f, 1.000f };
float Airdrop[] = { 0.279f, 0.990f, 0.812f, 1.000f };
float Flare[] = { 0.866f, 0.128f, 0.081f, 1.000f };
float Flaregun[] = { 1.0f, 0.60f,0.05f, 1.0f };

float dp[] = { 1.000f, 0.647f, 0.000f, 1.000f };
float mg3[] = { 1.000f, 0.647f, 0.000f, 1.000f };
float scope4x[] = { 0.937f, 0.063f, 0.937f, 1.000f };
float scope3x[] = { 0.874f, 0.484f, 0.106f, 1.000f };
float bag[] = { 0.529f, 0.127f, 0.903f, 1.000f };
float armer[] = { 0.591f, 1.000f, 0.237f, 1.000f };
float helmat[] = { 0.726f, 0.070f, 0.908f, 1.000f };
float mosin[] = { 1.000f, 0.647f, 0.000f, 1.000f };
float aug[] = { 1.000f, 0.647f, 0.000f, 1.000f };
float g36[] = { 0.671f, 0.217f, 1.000f, 1.000f };
float assm[] = { 1.000f, 0.217f, 0.762f, 1.000f };
float Grandes[] = { 1.000f, 0.396f, 0.357f, 1.000f };
float ammo7[] = { 0.984f, 0.871f, 0.043f, 1.000f };
float ammo5[] = { 0.000f, 1.000f, 0.318f, 1.000f };
float madkit[] = { 0.952f, 0.558f, 0.129f, 1.000f };
float playerline[] = { 0.591f, 1.000f, 0.237f, 1.000f };
float playercorner[] = { 1.0f, 0.70f,0.30f, 1.0f };
float playerbox[] = { 1.0f, 1.0f,0.0f, 1.0f };
float lotbox[] = { 1.0f, 1.0f,0.0f, 1.0f };
// ARGB
float helthbar[] = { 0.950f, 0.125f, 0.125f, 1.0f };
float boxColor[] = { 0.950f, 0.125f, 0.125f, 1.0f };
float cornerColor[] = { 0.950f, 0.125f, 0.125f, 1.0f };
float crosshairColor[] = { 0.950f, 0.125f, 0.125f, 1.0f };
float bot[] = { 0.016f, 0.725f, 0.929f, 1.0f };
float player[] = { 0.950f, 0.125f, 0.125f, 1.0f };
float vehicle[] = { 1.000f, 1.000f, 0.000f, 1.000f };
//RGB
float botcorner[] = { 0.050f, 0.125f, 0.925f, 1.0f };
float botline[] = { 0.050f, 0.025f, 0.925f, 1.0f };
float circle[] = { 0.950f, 0.125f, 0.125f, 1.0f };
float enemy[] = { 255, 255, 255, 255 };
float botbox[] = { 0.950f, 0.125f, 0.925f, 1.0f };
float bone[] = { 0.950f, 0.125f, 0.125f, 1.0f };
float fillrect[] = { 0.950f, 0.125f, 0.125f, 1.0f };
float nam[] = { 1.000f, 1.000f, 0.000f, 1.000f };
float nambar[] = { 0.880f, 0.185f, 0.25f, 1.0f };
float bothealth[] = { 0.95f, 0.125f, 0.825f, 1.0f };
float botname[] = { 0.050f, 0.825f, 0.185f, 1.0f };
float playerhealth[] = { 0.50f, 0.725f, 0.105f, 1.0f };
float textcolor[] = { 0.500f, 0.150f, 0.125f, 1.0f };
float skelec[] = { 255, 255, 255, 255 };

float Granades[] = { 0.990f, 0.995f, 0.995f, 1.0f };
float health[] = { 0.108f, 1.000f, 1.000f, 1.000f };
float deadbox[] = { 0.737f, 1.000f, 0.000f, 1.000f };
float deadboxitem[] = { 1.000f, 0.100f, 0.401f, 1.000f };
float airdrop[] = { 1.000f, 0.695f, 0.323f, 1.000f };
float airdropitem[] = { 0.300f, 0.695f, 0.323f, 1.000f };
float scopetextcolor[] = { 0.000f, 0.995f, 0.995f, 1.000f };
float allitem[] = { 0.034f, 1.000f, 0.040f, 1.000f };
float scope6x[] = { 0.120f, 0.955f, 0.125f, 1.0f };
float botbone[] = { 0.050f, 0.025f, 0.925f, 1.0f };
float playerbone[] = { 0.986f, 0.952f, 0.209f, 1.000f };
float magicline[] = { 255, 0, 0, 255 };
float bgcorner[] = { 0.000f, 1.000f, 0.964f, 1.000f };
float fovcirclecolor[] = { 255, 0, 0, 255 };
float fovcirclecolorq[] = { 255, 0, 0, 255 };
float fovcirclecolors[] = { 255, 0, 0, 255 };
float fovcirclecolorw[] = { 255, 0, 0, 255 };

float weapont[] = { 255,255,0,255 };
float hpt[] = { 255, 255, 255, 255 };
float plancolor[] = { 0.737f, 1.000f, 0.000f, 1.000f };
float dotss[] = { 0.950f, 0.125f, 0.925f, 1.0f };
float Esp_Item_AKM_Color[] = { 1.000f, 0.647f, 0.000f, 1.000f };
float M249[] = { 1.000f, 0.647f, 0.000f, 1.000f };
float MK12[] = { 1.00f, 0.796f, 0.715f, 1.0f };

float Esp_Item_M762_Color[] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Esp_Item_Mk47Mutant_Color[] = { 1.00f, 0.76f, 0.15f, 1.0f };
float Esp_Item_DP28_Color[] = { 1.000f, 0.647f, 0.000f, 1.000f };
float Esp_Item_SCARL_Color[] = { 0.00f, 1.0f, 0.0f, 1.0f };
float Esp_Item_M416_Color[] = { 1.000f, 0.647f, 0.000f, 1.000f };
float Esp_Item_M16A4_Color[] = { 0.00f, 1.0f, 0.0f, 1.0f };
float Esp_Item_G36C_Color[] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Esp_Item_QBZ_Color[] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Esp_Item_QBU_Color[] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Esp_Item_SLR_Color[] = { 0.627f, 0.102f, 0.941f, 1.000f };
float Esp_Item_SKS_Color[] = { 0.627f, 0.102f, 0.941f, 1.000f };
float Esp_Item_Mini14_Color[] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Esp_Item_M24_Color[] = { 1.000f, 0.647f, 0.000f, 1.000f };
float Esp_Item_Kar98k_Color[] = { 1.000f, 0.647f, 0.000f, 1.000f };
float Esp_Item_PP19_Color[] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Esp_Item_TommyGun_Color[] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Esp_Item_MP5K_Color[] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Esp_Item_UMP9_Color[] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Esp_Item_Vector_Color[] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Esp_Item_Uzi_Color[] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Esp_Item_762mm_Color[] = { 0.984f, 0.871f, 0.043f, 1.000f };
float Esp_Item_556mm_Color[] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Esp_Item_9mm_Color[] = { 1.000f, 0.000f, 0.337f, 1.000f };
float Esp_Item_45ACP_Color[] = { 1.00f, 0.96f, 0.56f, 1.0f };
float Esp_Item_Holo_Color[] = { 0.000f, 0.682f, 1.000f, 1.000f };
float Esp_Item_x2_Color[] = { 0.000f, 0.682f, 1.000f, 1.000f };
float Esp_Item_x3_Color[] = { 0.000f, 0.682f, 1.000f, 1.000f };
float Esp_Item_x4_Color[] = { 0.000f, 0.682f, 1.000f, 1.000f };

float Esp_Item_x6_Color[] = { 1.000f, 0.000f, 0.000f, 1.000f };

float Esp_Item_x8_Color[] = { 1.000f, 0.000f, 0.000f, 1.000f };

float Esp_Item_Bag1_Color[] = { 0.000f, 0.682f, 1.000f, 1.000f };

float Esp_Item_Bag2_Color[] = { 0.627f, 0.102f, 0.941f, 1.000f };

float Esp_Item_Bag3_Color[] = { 1.000f, 0.647f, 0.000f, 1.000f };

float Esp_Item_Armor1_Color[] = { 0.000f, 0.682f, 1.000f, 1.000f };

float Esp_Item_Armor2_Color[] = { 0.627f, 0.102f, 0.941f, 1.000f };

float Esp_Item_Armor3_Color[] = { 1.000f, 0.647f, 0.000f, 1.000f };

float Esp_Item_Helmet1_Color[] = { 0.000f, 0.682f, 1.000f, 1.000f };

float Esp_Item_Helmet2_Color[] = { 0.627f, 0.102f, 0.941f, 1.000f };

float Esp_Item_Helmet3_Color[] = { 1.000f, 0.647f, 0.000f, 1.000f };

float Esp_Item_Frag_Color[] = { 1.000f, 1.000f, 0.000f, 1.000f };

float Esp_Item_Smoke_Color[] = { 1.000f, 1.000f, 0.000f, 1.000f };

float Esp_Item_Molotof_Color[] = { 1.000f, 1.000f, 0.000f, 1.000f };

float Esp_Item_MedKit_Color[] = { 1.000f, 0.753f, 0.796f, 1.000f };

float Esp_Item_FirstAidKit_Color[] = { 1.000f, 0.753f, 0.796f, 1.000f };

float Esp_Item_Painkiller_Color[] = { 1.000f, 0.753f, 0.796f, 1.000f };

float Esp_Item_EnergyDrink_Color[] = { 1.000f, 0.753f, 0.796f, 1.000f };

float Esp_Item_AdrenalineSyringe_Color[] = { 1.000f, 0.753f, 0.796f, 1.000f };

float Esp_Item_FlareGun_Color[] = { 1.000f, 0.000f, 0.000f, 1.000f };

float Esp_Item_Flare_Color[] = { 1.000f, 0.000f, 0.000f, 1.000f };

float Esp_Item_AirDrop_Color[] = { 1.000f, 0.647f, 0.000f, 1.000f };

#pragma endregion

#pragma region fount size
int AWMS = 15;
int M416S = 15;
int SCARS = 15;
int M762S = 15;
int KARS = 15;
int VECTORS = 15;
int UZIS = 15;
int UMP9S = 15;
int SKSS = 15;
int QBZS = 15;
int QBUS = 15;
int PPS = 15;
int SLRS = 15;
int TOMMYS = 15;
int MP5KS = 15;
int M249s = 15;
int MINIS = 15;
int M24S = 15;
int MK47S = 15;
int DPS = 15;
int G36CS = 15;
int AUGS = 15;
int AKMS = 15;
int Bag3S = 15;
int Helmet3S = 15;
int FLARES = 15;
int FLAREGS = 15;
int Armor3S = 15;
int MK12S = 15;
int M249S = 15;
int Armor2S = 15;
int Armor1S = 15;
int Helmet2S = 15;
int Helmet1S = 15;
int M16A4S = 15;
int HOLOS = 15;
int Bag2S = 15;
int Bag1S = 15;
int AMO9S = 15;
int AMO7S = 15;
int AMO5S = 15;
int AMO45S = 15;
int AMO300S = 15;
int SCOPE2S = 15;
int SCOPE3S = 15;
int SCOPE4S = 15;
int SCOPE6S = 15;
int SCOPE8S = 15;
int PAINS = 15;
int MEDS = 15;
int FIRSTS = 15;
int ADRES = 15;
int ENRES = 15;
int SMOKES = 15;
int MOLOS = 15;
int FRAGS = 15;

#pragma endregion

#pragma region font size Attchment
static int BP_QK_Choke_Pickup_C_1s = 15;
static int BP_QK_Mid_Compensator_Pickup_C_1s = 15;
static int BP_QK_Sniper_Compensator_Pickup_C_1s = 15;
static int BP_QK_Mid_FlashHider_Pickup_C_1s = 15;
static int BP_QK_Sniper_FlashHider_Pickup_C_1s = 15;
static int BP_QK_Mid_Suppressor_Pickup_C_1s = 15;
static int BP_QK_Sniper_Suppressor_Pickup_C_1s = 15;
static int BP_QK_Large_Compensator_Pickup_C_1s = 15;
static int BP_QK_Large_FlashHider_Pickup_C_1s = 15;
static int BP_QK_Large_Suppressor_Pickup_C_1s = 15;
static int BP_QK_DuckBill_Pickup_C_1s = 15;
static int BP_WB_Angled_Pickup_C_1s = 15;
static int BP_WB_Vertical_Pickup_C_1s = 15;
static int BP_WB_LightGrip_Pickup_C_1s = 15;
static int BP_WB_HalfGrip_Pickup_C_1s = 15;
static int BP_WB_ThumbGrip_Pickup_C_1s = 15;
static int BP_WB_Lasersight_Pickup_C_1s = 15;
static int BP_MZJ_HD_Pickup_C_1s = 15;
static int BP_MZJ_QX_Pickup_C_1s = 15;
static int BP_MZJ_SideRMR_Pickup_C_1s = 15;
static int BP_ZDD_Sniper_Pickup_C_1s = 15;
static int BP_QT_UZI_Pickup_C_1s = 15;
static int BP_QT_A_Pickup_C_1s = 15;
static int BP_QT_Sniper_Pickup_C_1s = 15;
static int BP_ZDD_Crossbow_Q_Pickup_C_1s = 15;
static int BP_DJ_Mid_E_Pickup_C_1s = 15;
static int BP_DJ_Mid_Q_Pickup_C_1s = 15;
static int BP_DJ_Mid_EQ_Pickup_C_1s = 15;
static int BP_DJ_Sniper_E_Pickup_C_1s = 15;
static int BP_DJ_Sniper_Q_Pickup_C_1s = 15;
static int BP_DJ_Sniper_EQ_Pickup_C_1s = 15;
static int BP_DJ_Large_E_Pickup_C_1s = 15;
static int BP_DJ_Large_Q_Pickup_C_1s = 15;
static int BP_DJ_Large_EQ_Pickup_C_1s = 15;
////////////////////////////////////////////
static int BP_Pistol_P92_Wrapper_C_1s = 15;
static int BP_Pistol_P1911_Wrapper_C_1s = 15;
static int BP_Pistol_R1895_Wrapper_C_1s = 15;
static int BP_Pistol_P18C_Wrapper_C_1s = 15;
static int BP_Pistol_R45_Wrapper_C_1s = 15;
static int BP_Pistol_Vz61_Wrapper_C_1s = 15;
static int BP_Pistol_DesertEagle_Wrapper_C_1s = 15;
static int BP_ShotGun_SawedOff_Wrapper_C_1s = 15;
//////////////////////////////////////////////
static int BP_ShotGun_S686_Wrapper_C_1s = 15;
static int BP_ShotGun_S1897_Wrapper_C_1s = 15;
static int BP_ShotGun_S12K_Wrapper_C_1s = 15;
static int BP_ShotGun_DP12_Wrapper_C_1s = 15;
static int BP_ShotGun_M1014_Wrapper_C_1s = 15;
/////////////////////////////////////////////
static int BP_WEP_Machete_Pickup_C_1s = 15;
static int BP_WEP_Cowbar_Pickup_C_1s = 15;
static int BP_WEP_Sickle_Pickup_C_1s = 15;
static int BP_WEP_Pan_Pickup_C_1s = 15;
////////////////////////////////////////////
static int BP_Sniper_VSS_Wrapper_C_1s = 15;
static int BP_WEP_Mk14_Pickup_C_1s = 15;
static int BP_Sniper_Win94_Wrapper_C_1s = 15;
static int BP_Sniper_QBU_Wrapper_C_1s = 15;
static int BP_Sniper_Mosin_Wrapper_C_1s = 15;
static int BP_Sniper_MK12_Wrapper_C_1s = 15;
#pragma endregion

#pragma region Attichment collors
float Esp_Item_Tokenf_Color[] = { 1.000f, 1.000f, 0.000f, 1.000f };
float BP_QK_Choke_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_QK_Mid_Compensator_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_QK_Sniper_Compensator_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_QK_Mid_FlashHider_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_QK_Sniper_FlashHider_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_QK_Mid_Suppressor_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_QK_Sniper_Suppressor_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_QK_Large_Compensator_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_QK_Large_FlashHider_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_QK_Large_Suppressor_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_QK_DuckBill_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_WB_Angled_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_WB_Vertical_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_WB_LightGrip_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_WB_HalfGrip_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_WB_ThumbGrip_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_WB_Lasersight_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_MZJ_HD_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_MZJ_QX_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_MZJ_SideRMR_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_ZDD_Sniper_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_QT_UZI_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_QT_A_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_QT_Sniper_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_ZDD_Crossbow_Q_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_DJ_Mid_E_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_DJ_Mid_Q_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_DJ_Mid_EQ_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_DJ_Sniper_E_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_DJ_Sniper_Q_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_DJ_Sniper_EQ_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_DJ_Large_E_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_DJ_Large_Q_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_DJ_Large_EQ_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
///////////////////////////////////////////////////////////////
float BP_Pistol_P92_Wrapper_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_Pistol_P1911_Wrapper_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_Pistol_R1895_Wrapper_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_Pistol_P18C_Wrapper_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_Pistol_R45_Wrapper_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_Pistol_Vz61_Wrapper_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_Pistol_DesertEagle_Wrapper_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_ShotGun_SawedOff_Wrapper_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_ShotGun_S686_Wrapper_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_ShotGun_S1897_Wrapper_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_ShotGun_S12K_Wrapper_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_ShotGun_DP12_Wrapper_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_ShotGun_M1014_Wrapper_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_WEP_Machete_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_WEP_Cowbar_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_WEP_Sickle_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_WEP_Pan_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_Sniper_VSS_Wrapper_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_WEP_Mk14_Pickup_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_Sniper_Win94_Wrapper_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_Sniper_QBU_Wrapper_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_Sniper_Mosin_Wrapper_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
float BP_Sniper_MK12_Wrapper_C_1[] = { 1.0f, 0.60f,0.05f, 1.0f };
#pragma endregion

void MenuStyle4()
{
	static auto Flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
	static auto Flags1 = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;

	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.00f, 0.00f, 0.00f, (float)Setting::MenuTransparency / 255));
	ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.00f, 0.43f, 1.00f, (float)Setting::MenuTransparency / 255));

	ImGuiStyle& style = ImGui::GetStyle();
	style.WindowRounding = 3.0f;

	ImGuiIO& Io = ImGui::GetIO();
	ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.5f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.5f));
	ImGui::SetNextWindowSize(ImVec2(600.0f, 436.0f));

	char pcname[100];
	std::string getusername = getenv("username");
	sprintf_s(pcname, "Welcome %s To [ ESP  Pvt Cheat | For Pubg v4.2.1.1 ]", getusername.c_str());
	if (ImGui::Begin(pcname, 0, Flags1))
	{
		ImGui::BeginChild("###main12", ImVec2(590, 370), false, 0);
		{

			ImGuiStyle* style = &ImGui::GetStyle();

			//style->WindowBorderSize = 0;
			style->WindowTitleAlign = ImVec2(0.5, 0.5);
			/*ImGuiCol_ScrollbarBg,
				ImGuiCol_ScrollbarGrab,
				ImGuiCol_ScrollbarGrabHovered,
				ImGuiCol_ScrollbarGrabActive,*/
			ImGuiIO& Io = ImGui::GetIO();

			style->FramePadding = ImVec2(8, 6);
			/*style->Colors[ImGuiCol_Button] = ImColor(31, 30, 31, 200);
			style->Colors[ImGuiCol_ButtonActive] = ImColor(31, 30, 31, 255);*/
			style->Colors[ImGuiCol_Button] = ImColor(117, 117, 117, 200);
			style->Colors[ImGuiCol_ButtonActive] = ImColor(0, 110, 255, 150);

			/*style->Colors[ImGuiCol_ButtonHovered] = ImColor(41, 40, 41, 255);
			style->Colors[ImGuiCol_WindowBg] = ImColor(15, 13, 18, 200);*/
			style->Colors[ImGuiCol_ButtonHovered] = ImColor(0, 110, 255, 100);
			style->Colors[ImGuiCol_WindowBg] = ImColor(15, 13, 18, 200);
			style->Colors[ImGuiCol_Border] = ImColor(0, 110, 255, 200);

			style->Colors[ImGuiCol_Separator] = ImColor(0, 0, 255, 150);
			style->Colors[ImGuiCol_SeparatorHovered] = ImColor(0, 0, 255, 200);
			style->Colors[ImGuiCol_SeparatorActive] = ImColor(0, 0, 255, 255);

			style->Colors[ImGuiCol_Header] = ImColor(0, 0, 0, 0);
			style->Colors[ImGuiCol_HeaderActive] = ImColor(0, 0, 0, 0);
			style->Colors[ImGuiCol_HeaderHovered] = ImColor(46, 46, 46, 255);


			ImGui::Columns(2);
			ImGui::SetColumnOffset(1, 180);

			{
				//Left side
				ImGuiStyle* style = &ImGui::GetStyle();
				style->ItemInnerSpacing.x = 5.0f;

				style->FrameRounding = 4.0f;

				static ImVec4 active = to_vec4(0, 110, 255, 150);
				static ImVec4 inactive = to_vec4(117, 117, 117, 200);

				ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 1 ? active : inactive);
				//ImGui::Spacing();
				ImGui::SetCursorPosX({ 10 });
				if (ImGui::Button(" ESP", ImVec2(180 - 15, 50)))
					Settings::Tab = 1;

				ImGui::Spacing();
				ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 2 ? active : inactive);
				ImGui::SetCursorPosX({ 10 });
				if (ImGui::Button(" AIM", ImVec2(180 - 15, 50)))
					Settings::Tab = 2;

				ImGui::Spacing();
				ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 3 ? active : inactive);
				//if (ImGui::Button(" MSIC", ImVec2(180 - 15, 50)))
				ImGui::SetCursorPosX({ 10 });
				if (ImGui::Button(" MEMORY", ImVec2(180 - 15, 50)))
					Settings::Tab = 3;

				ImGui::Spacing();
				ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 4 ? active : inactive);
				ImGui::SetCursorPosX({ 10 });
				if (ImGui::Button(" SETTINGS", ImVec2(180 - 15, 50)))
					Settings::Tab = 4;

				ImGui::Spacing();
				ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 5 ? active : inactive);
				ImGui::SetCursorPosX({ 10 });
				if (ImGui::Button(" ABOUT", ImVec2(180 - 15, 50)))
					Settings::Tab = 5;

				ImGui::PopStyleColor(5);

				ImGui::SetCursorPosY(ImGui::GetWindowHeight() - 30);
			}

			ImGui::NextColumn();

			{
				//ImGui::BeginChild("###12", ImVec2(), false, 0);
				{
					{
						if (Settings::Tab == 1)
						{
							/*ImGui::BeginChild("###2", ImVec2(408, 355), true, 0);
							{
								if (ImGui::BeginTabBar("ESP"))
								{

								}
								ImGui::EndTabBar();
							}
							ImGui::EndChild();*/
							if (ImGui::BeginTabBar("BeginTabBar"))
							{
								{
									if (ImGui::BeginTabItem("PLAYER"))
									{
										if (ImGui::BeginChild("###player", ImVec2(400, 325), false))
										{
											ImGui::Spacing();
											//ImGui::Checkbox(" I Look Like,a Enemy", &Setting::MeEnemyShow);

											if (Setting1::style1)
											{
												ImGui::Checkbox(" Player Name", &Setting1::playerst1name); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###playernamec1", (float*)&Setting1::playernamec1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
											
												ImGui::Checkbox(" Player Line", &Setting1::playerst1line);
												ImGui::SameLine();
												ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###playerlinec1", (float*)&Setting1::playerlinec1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

												ImGui::Checkbox(" Player Bone", &Setting1::playerst1Bone); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###playerBonec1", (float*)&Setting1::playerBonec1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

												ImGui::Checkbox(" Player Corner Box", &Setting1::playerst1cornerbox); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###playercornerboxc1", (float*)&Setting1::playercornerboxc1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												if (Setting1::playerst1cornerbox)
												{
													Setting1::playerst1fullbox = false;
												}
												ImGui::Checkbox(" Player Full Box", &Setting1::playerst1fullbox); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###playerfullboxc1", (float*)&Setting1::playerfullboxc1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												if (Setting1::playerst1fullbox)
												{
													Setting1::playerst1cornerbox = false;
												}
												ImGui::Checkbox(" Player Health", &Setting1::playerst1health);

												ImGui::Checkbox(" Weapon icon", &Setting1::playerst1Weapons_iconsH);
											
												ImGui::Checkbox(" Player Weapon", &Setting1::playerst1weapon); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###playerweaponc1", (float*)&Setting1::playerweaponc1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

												ImGui::Checkbox(" Player Distance", &Setting1::playerst1distance); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###playerdistancec1", (float*)&Setting1::playerdistancec1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);


											}

											if (Setting1::style2)
											{
												ImGui::Checkbox(" Player Name", &Setting1::playerst2name); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###playernamec2", (float*)&Setting1::playernamec2, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

												ImGui::Checkbox(" Player Line", &Setting1::playerst2line);
												ImGui::SameLine();
												ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###playerlinec2", (float*)&Setting1::playerlinec2, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

												ImGui::Checkbox(" Player Bone", &Setting1::playerst2Bone); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###playerBonec2", (float*)&Setting1::playerBonec2, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

												ImGui::Checkbox(" Player Corner Box", &Setting1::playerst2cornerbox); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###playercornerboxc2", (float*)&Setting1::playercornerboxc2, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												if (Setting1::playerst2cornerbox)
												{
													Setting1::playerst2fullbox = false;
												}
												ImGui::Checkbox(" Player Full Box", &Setting1::playerst2fullbox); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###playerfullboxc2", (float*)&Setting1::playerfullboxc2, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												if (Setting1::playerst2fullbox)
												{
													Setting1::playerst2cornerbox = false;
												}
												ImGui::Checkbox(" Player Health", &Setting1::playerst2health);

												ImGui::Checkbox(" Weapon icon", &Setting1::playerst2Weapons_iconsH);

												ImGui::Checkbox(" Player Weapon", &Setting1::playerst2weapon); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###playerweaponc2", (float*)&Setting1::playerweaponc2, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

												ImGui::Checkbox(" Player Distance", &Setting1::playerst2distance); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###playerdistancec2", (float*)&Setting1::playerdistancec2, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);


											}
											
											if (Setting1::style3)
											{
												ImGui::Checkbox(" Player Name", &Setting1::playerst3name); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###playernamec3", (float*)&Setting1::playernamec3, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

												ImGui::Checkbox(" Player Line", &Setting1::playerst3line);
												ImGui::SameLine();
												ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###playerlinec3", (float*)&Setting1::playerlinec3, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

												ImGui::Checkbox(" Player Bone", &Setting1::playerst3Bone); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###playerBonec3", (float*)&Setting1::playerBonec3, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

												ImGui::Checkbox(" Player Corner Box", &Setting1::playerst3cornerbox); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###playercornerboxc3", (float*)&Setting1::playercornerboxc3, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												if (Setting1::playerst3cornerbox)
												{
													Setting1::playerst3fullbox = false;
												}
												ImGui::Checkbox(" Player Full Box", &Setting1::playerst3fullbox); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###playerfullboxc3", (float*)&Setting1::playerfullboxc3, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												if (Setting1::playerst3fullbox)
												{
													Setting1::playerst3cornerbox = false;
												}
												ImGui::Checkbox(" Player Health", &Setting1::playerst3health);

												ImGui::Checkbox(" Weapon icon", &Setting1::playerst3Weapons_iconsH);

												ImGui::Checkbox(" Player Weapon", &Setting1::playerst3weapon); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###playerweaponc3", (float*)&Setting1::playerweaponc3, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

												ImGui::Checkbox(" Player Distance", &Setting1::playerst3distance); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###playerdistancec3", (float*)&Setting1::playerdistancec3, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);


											}

										}
										ImGui::EndChild();

										ImGui::EndTabItem();
									}

									if (ImGui::BeginTabItem("  BOT  "))
									{
										if (ImGui::BeginChild("###bot", ImVec2(400, 325), false))
										{
											ImGui::Spacing();
											//ImGui::Checkbox(" I Look Like,a Enemy", &Setting::MeEnemyShow);

											if (Setting1::style1)
											{
												ImGui::Checkbox(" Bot Name", &Setting1::botst1name); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###botnamec1", (float*)&Setting1::botnamec1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
											
												ImGui::Checkbox(" Bot Line", &Setting1::botst1line);
												ImGui::SameLine();
												ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###botlinec1", (float*)&Setting1::botlinec1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

												ImGui::Checkbox(" Bot Bone", &Setting1::botst1Bone); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###botBonec1", (float*)&Setting1::botBonec1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

												ImGui::Checkbox(" Bot Corner Box", &Setting1::botst1cornerbox); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###botcornerboxc1", (float*)&Setting1::botcornerboxc1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												if (Setting1::botst1cornerbox)
												{
													Setting1::botst1fullbox = false;
												}
												ImGui::Checkbox(" Bot Full Box", &Setting1::botst1fullbox); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###botfullboxc1", (float*)&Setting1::botfullboxc1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												if (Setting1::botst1fullbox)
												{
													Setting1::botst1cornerbox = false;
												}
												ImGui::Checkbox(" Bot Health", &Setting1::botst1health);
												/*if (hpb1 = 0)
												{
													Setting1::botst1cornerbox = false;
												}
												else if (hpb1 = 1)
												{

												}*/

												ImGui::Checkbox(" Weapon icon", &Setting1::botst1Weapons_iconsH);
											
												ImGui::Checkbox(" Bot Weapon", &Setting1::botst1weapon); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###botweaponc1", (float*)&Setting1::botweaponc1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

												ImGui::Checkbox(" Bot Distance", &Setting1::botst1distance); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###botdistancec1", (float*)&Setting1::botdistancec1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

											}

											if (Setting1::style2)
											{
												ImGui::Checkbox(" Bot Name", &Setting1::botst2name); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###botnamec2", (float*)&Setting1::botnamec2, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

												ImGui::Checkbox(" Bot Line", &Setting1::botst2line);
												ImGui::SameLine();
												ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###botlinec2", (float*)&Setting1::botlinec2, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

												ImGui::Checkbox(" Bot Bone", &Setting1::botst2Bone); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###botBonec2", (float*)&Setting1::botBonec2, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

												ImGui::Checkbox(" Bot Corner Box", &Setting1::botst2cornerbox); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###botcornerboxc2", (float*)&Setting1::botcornerboxc2, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												if (Setting1::botst2cornerbox)
												{
													Setting1::botst2fullbox = false;
												}
												ImGui::Checkbox(" Bot Full Box", &Setting1::botst2fullbox); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###botfullboxc2", (float*)&Setting1::botfullboxc2, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												if (Setting1::botst2fullbox)
												{
													Setting1::botst2cornerbox = false;
												}
												ImGui::Checkbox(" Bot Health", &Setting1::botst2health);

												ImGui::Checkbox(" Weapon icon", &Setting1::botst2Weapons_iconsH);

												ImGui::Checkbox(" Bot Weapon", &Setting1::botst2weapon); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###botweaponc2", (float*)&Setting1::botweaponc2, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

												ImGui::Checkbox(" Bot Distance", &Setting1::botst2distance); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###botdistancec2", (float*)&Setting1::botdistancec2, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);


											}
											
											if (Setting1::style3)
											{
												ImGui::Checkbox(" Bot Name", &Setting1::botst3name); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###botnamec3", (float*)&Setting1::botnamec3, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

												ImGui::Checkbox(" Bot Line", &Setting1::botst3line);
												ImGui::SameLine();
												ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###botlinec3", (float*)&Setting1::botlinec3, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

												ImGui::Checkbox(" Bot Bone", &Setting1::botst3Bone); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###botBonec3", (float*)&Setting1::botBonec3, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

												ImGui::Checkbox(" Bot Corner Box", &Setting1::botst3cornerbox); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###botcornerboxc3", (float*)&Setting1::botcornerboxc3, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												if (Setting1::botst3cornerbox)
												{
													Setting1::botst3fullbox = false;
												}
												ImGui::Checkbox(" Bot Full Box", &Setting1::botst3fullbox); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###botfullboxc3", (float*)&Setting1::botfullboxc3, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												if (Setting1::botst3fullbox)
												{
													Setting1::botst3cornerbox = false;
												}
												ImGui::Checkbox(" Bot Health", &Setting1::botst3health);

												ImGui::Checkbox(" Weapon icon", &Setting1::botst3Weapons_iconsH);

												ImGui::Checkbox(" Bot Weapon", &Setting1::botst3weapon); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###botweaponc3", (float*)&Setting1::botweaponc3, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

												ImGui::Checkbox(" Bot Distance", &Setting1::botst3distance); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("###botdistancec3", (float*)&Setting1::botdistancec3, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);


											}

										}
										ImGui::EndChild();

										ImGui::EndTabItem();
									}

									if (ImGui::BeginTabItem("OTHERS"))
									{
										if (ImGui::BeginChild("###others", ImVec2(400, 325), false))
										{
											ImGui::Spacing();
											ImGui::Checkbox("Icon Player Flag", &Setting::pflag);

											ImGui::Checkbox("ESP Item", &Setting::Item);
											/*ImGui::SameLine();
											ImGui::Checkbox("Less Important Loot", &Setting::impitems);*/

											ImGui::Checkbox("Show Total Enemies", &Setting::TotalEnemy);
											ImGui::Checkbox("Show Enemy UID", &Setting::puid);
											ImGui::Checkbox("Show Enemy Distance", &Setting::plyrdistance);
											ImGui::Checkbox("Show Enemy Aiming", &Setting::IsimingAtYou);
											ImGui::Checkbox("Show Game Info", &Setting::gameinfo);
											ImGui::Checkbox("Show My Info", &Setting::MyInfo);

											ImGui::Checkbox("Bot Name Like,a Player", &Setting::botnameShow);
											ImGui::Checkbox("I Look Like,a Enemy", &Setting::MeEnemyShow);
											ImGui::Checkbox("Training Model Esp", &Setting::TrainingGrounds_ModelEsp);

											/*ImGui::Checkbox("Show Enemy Offscreen", &Setting::dots);
											if (Setting::dots)
											{
												ImGui::PushItemWidth(100);
												ImGui::SliderInt("OffScreen Range", &Setting::dotsize, 10, 100);
												ImGui::PopItemWidth();
											}
											ImGui::Checkbox("Show Enemy Sides", &Setting::dots);*/
											//ImGui::Bullet(); ImGui::TextColored(ImVec4(255, 0, 0, 255), "AimLine Settings"); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
											////ImGui::SameLine();
											//ImGui::ColorEdit4("AimLine", (float*)&Colors::magicline, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

											ImGui::Checkbox("Aim Line CrossHair", &Setting::AimLineCross);
											if (Setting::AimLineCross)
											{
												Setting::AimLineBottm = false;
											}
											ImGui::Checkbox("Aim Line Bottom", &Setting::AimLineBottm);
											if (Setting::AimLineBottm)
											{
												Setting::AimLineCross = false;
											}

											ImGui::Checkbox("Show Magic Status", &Setting::MagicBulletd);

											ImGui::Checkbox("Enemy Line OfSight", &Setting::EnemyLineOfSight); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
											//ImGui::SameLine();
											ImGui::ColorEdit4("Enemy LineOfSight", (float*)&Colors::enemyLineofSight, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);////0000
											if (Setting::EnemyLineOfSight)
											{
												ImGui::SameLine();
												//ImGui::Indent();
												ImGui::PushItemWidth(100);
												ImGui::SliderFloat("Line Size", &Setting::enemyLineofSightSize, 200.0f, 800.0f);
												//ImGui::Unindent();
											}

											ImGui::Checkbox("My Line OfSight", &Setting::MyLineOfSight); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
											//ImGui::SameLine();
											ImGui::ColorEdit4("My LineOfSight", (float*)&Colors::enemyLineofSight, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
											if (Setting::MyLineOfSight)
											{
												ImGui::SameLine();
												//ImGui::Indent();
												ImGui::PushItemWidth(100);
												ImGui::Bullet(); ImGui::SliderFloat("Line Size", &Setting::enemyLineofSightSize, 200.0f, 800.0f);
												//ImGui::Unindent();
											}

											ImGui::Checkbox("360' Radar", &Setting1::dots1);

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

										}
										ImGui::EndChild();

										ImGui::EndTabItem();
									}

									if (ImGui::BeginTabItem("ITEMS"))
									{
										if (ImGui::BeginChild("###ITEMS", ImVec2(400, 325), false))
										{
											ImGui::Spacing();

											ImGui::Checkbox("All Items", &Setting::allitemss);

											ImGui::Checkbox("Important Items", &Setting::impitems);

											ImGui::Checkbox("Health items", &Setting::healthitem);

											ImGui::Checkbox("Scope items", &Setting::scope);

											ImGui::Checkbox("Bomb Items", &Setting::BombAlert); ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
											//ImGui::SameLine();
											ImGui::ColorEdit4("bomb", (float*)&Colors::Granadeswarn, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

											if (Setting1::style1)
											{
												ImGui::Checkbox("Vehicles", &Setting1::Vehiclest1);
												ImGui::SameLine();
												ImGui::Checkbox("HP", &Setting1::VehicleHpst1);
												ImGui::SameLine();
												ImGui::Checkbox("FUEL", &Setting1::VehicleFeulst1);
												ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("Vehiclescol", (float*)&Setting1::Vehiclec1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SliderFloat("Vehicle Size", &Setting1::Vehicles1, 1.0f, 50.0f);
											}
											
											if (Setting1::style2)
											{
												ImGui::Checkbox("Vehicles", &Setting1::Vehiclest2);
												ImGui::SameLine();
												ImGui::Checkbox("HP + FUEL", &Setting1::VehicleHpst2);
												/*ImGui::SameLine();
												ImGui::Checkbox("FUEL", &Setting1::VehicleFeulst2);*/
												ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("Vehiclescol", (float*)&Setting1::Vehiclec2, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SliderFloat("Vehicle Size", &Setting1::Vehicles2, 1.0f, 50.0f);
											}
											
											if (Setting1::style3)
											{
												ImGui::Checkbox("Vehicles", &Setting1::Vehiclest3);
												ImGui::SameLine();
												ImGui::Checkbox("HP + FUEL", &Setting1::VehicleHpst3);
												/*ImGui::SameLine();
												ImGui::Checkbox("FUEL", &Setting1::VehicleFeulst3);*/
												ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });
												ImGui::ColorEdit4("Vehiclescol", (float*)&Setting1::Vehiclec3, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SliderFloat("Vehicle Size", &Setting1::Vehicles3, 1.0f, 50.0f);
											}
											
											ImGui::Spacing();
											ImGui::Spacing();
											ImGui::SmallButton("---------------- All ITEMS ----------------");
											ImGui::Spacing();

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
										ImGui::EndChild();


										ImGui::EndTabItem();
									}

								}


							}
							ImGui::EndTabBar();
						}

						if (Settings::Tab == 2)
						{
							/*ImGui::BeginChild("###2", ImVec2(408, 355), true, 0);
							{

							}
							ImGui::EndChild();*/
							if (ImGui::BeginTabBar("BeginTabBar"))
							{
								if (ImGui::BeginTabItem("MagicBullet"))
								{
									if (ImGui::BeginChild("##SafeMemory", ImVec2(400, 325), false))
									{
										ImGui::Spacing();
										if (ImGui::Checkbox(" Magic Bullet ON/OFF", &Setting::MagicBullet))
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

										ImGui::Spacing();
										ImGui::Bullet(); ImGui::Text("Bullet Tracking Settings");

										const char* aimb[] = { "HEAD", "NECK", "BODY", "AUTO" };
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

										ImGui::Checkbox("Bullet Tracking Range", &Setting::BulletTrackingRange);
										if (Setting::BulletTrackingRange)
										{
											ImGui::SliderInt("Range", &Setting::magicrange, 1.0f, 350.0f);
										}

										ImGui::Spacing();
										ImGui::Checkbox(" Legit Tracking", &Setting::PREDICTION);
										ImGui::Spacing();
										ImGui::Checkbox("Skip Knocked", &Setting::SkipKnocked);
										ImGui::Spacing();
										ImGui::Checkbox("Skip BOTs", &Setting::SkipBots);
										ImGui::Spacing();
										ImGui::Checkbox("FOV BASED TRACKING", &Setting::fovcircle); /*ImGui::SameLine(); ImGui::SetCursorPosX({ 355 });*/
										ImGui::SameLine();
										ImGui::ColorEdit4("FOV COLOR", (float*)&Colors::fovcirclecolor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
										if (Setting::fovcircle)
										{
											ImGui::Indent();
											ImGui::SliderFloat("FOV Size", &Setting::fovcircleredus, 1.0f, 200.0f);
											ImGui::Unindent();
										}

									}
									ImGui::EndChild();

									ImGui::EndTabItem();
								}

								if (ImGui::BeginTabItem("Aimbot"))
								{
									if (ImGui::BeginChild("###aimbot", ImVec2(400, 325), false))
									{
										ImGui::Spacing();
										ImGui::Checkbox(" Aim Bot ON/OFF", &Setting::Aimbot); 
										ImGui::SameLine();
										HelpMarkerQuestionMark("Take your Own Risk");

										const char* itemss[] = { "VK_LBUTTON",
																"VK_RBUTTON","VK_SHIFT",
																	"VK_CONTROL",
																"ALT" };

										//ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 0.0f); // Set alpha to zero (invisible)
										//ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true); // Disable the slider
										if (Setting::Aimbot)
										{
											if (Setting::Aimbot)
											{
												Setting::fovcircle = true;
											}

											ImGui::Bullet(); ImGui::SameLine(); ImGui::TextColored(to_vec4(255, 0, 0, 255), "AimBot Settings");//Red
											//ImGui::Indent();
											ImGui::Spacing();
											ImGui::Text("Aim Key");
											ImGui::SameLine();
											ImGui::Hotkey("### Aim Key", &Setting::AimbotKey, ImVec2(180.0f, 24));

											ImGui::Spacing();
											ImGui::Text("Aim Speed");
											/*ImGui::Bullet();
											ImGui::SameLine();*/
											ImGui::SliderFloat("### Aim Speed", &Setting::Aimspeed, 1.0f, 50.0f);
											//ImGui::SliderFloat("Aim lock", &_aimlock, 0.0f, 15.0f);

											ImGui::Spacing();
											ImGui::Checkbox("Fov  ON/OFF", &Setting::fovcircle);

											ImGui::Spacing();
											ImGui::Text("Fov Size");
											/*ImGui::Bullet();
											ImGui::SameLine();*/
											ImGui::SliderFloat("### Fov Size", &Setting::fovcircleredus, 1.0f, 500.0f);
											ImGui::SameLine();
											ImGui::Text("Fov Color");
											ImGui::SameLine();
											ImGui::ColorEdit4("### Fov Color", (float*)&Colors::fovcirclecolor, ImGuiColorEditFlags_NoInputs);
										}
										//ImGui::PopItemFlag(); // Re-enable widgets
										//ImGui::PopStyleVar(); // Restore alpha
									}
									ImGui::EndChild();

									ImGui::EndTabItem();
								}

							}
							ImGui::EndTabBar();

						}

						if (Settings::Tab == 3)
						{
							/*if (ImGui::BeginTabBar("BeginTabBar"))
							{

							}
							ImGui::EndTabBar();*/
							if (ImGui::BeginTabBar("BeginTabBar"))
							{
								if (ImGui::BeginTabItem("MEMORY SAFE"))
								{
									if (ImGui::BeginChild("###memorySafe", ImVec2(400, 325), false))
									{
										ImGui::Spacing();
										ImGui::SetCursorPosX({ 5 });
										ImGui::Checkbox(" Anti Stream", &Setting2::ScreenX);
										if (Setting2::ScreenX)
										{
											SetWindowDisplayAffinity(DX11Window::hWindow, WDA_EXCLUDEFROMCAPTURE);
										}
										else
										{
											SetWindowDisplayAffinity(DX11Window::hWindow, WDA_NONE);
										}

										ImGui::Spacing();
										ImGui::SetCursorPosX({ 5 });
										ImGui::Checkbox(" iPad View", &Setting::IpadView);
										ImGui::SameLine();
										HelpMarkerQuestionMark("Take your Own Risk");
										if (Setting::IpadView)
										{
											ImGui::Indent();
											ImGui::Bullet();
											ImGui::SliderInt("Ipad View Value ", &Setting::IpadViewValue, 360.f, 200.f);
											ImGui::Unindent();
										}
										/*ImGui::Checkbox(" iPad View Super", & Setting2::ipadview);
										if ( Setting2::ipadview)
										{
											ImGui::PushItemWidth(250);
											ImGui::SameLine();
											if (ImGui::SliderInt("##IpadSize", & Setting2::IpadViewValue, 360.0f, 200.0f))
											{
												if ( Setting2::ipadview)
												{
													WriteUE4Float(0x5F5F5C4,  Setting2::IpadViewValue);
												}
												else if (! Setting2::ipadview)
												{
													WriteUE4Float(0x5F5F5C4, 360);
												}
											}
										}*/
										ImGui::Spacing();
										ImGui::SetCursorPosX({ 5 });
										ImGui::Checkbox(" X Effect ", &Setting::XEffect);
										ImGui::SameLine();
										HelpMarkerQuestionMark("Take your Own Risk");
										if (Setting::XEffect)
										{
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

									}
									ImGui::EndChild();

									ImGui::EndTabItem();
								}

								if (ImGui::BeginTabItem("MEMORY DANGER"))
								{
									if (ImGui::BeginChild("###DangerSafe", ImVec2(400, 325), false))
									{
										//ImGui::Spacing();
										//ImGui::Checkbox(" Camera Cache(360) Magic Bullet", &Setting::CameraCatch);
										//ImGui::SameLine();
										//HelpMarkerQuestionMark("Take your Own Risk");

										//ImGui::Spacing();
										//ImGui::Checkbox(" Memory Aimbot ", &Setting::CameraAimBot);
										//ImGui::SameLine();
										//HelpMarkerQuestionMark("Take your Own Risk");

										//if (Setting::CameraAimBot)
										//{
										//	ImGui::Indent();
										//	ImGui::Bullet();
										//	ImGui::Spacing();
										//	ImGui::Hotkey("Triger Key", &Setting::CamerAimbotKey, ImVec2(180.0f, 24));
										//	//ImGui::SliderInt("Smoothness", &Setting::camsmoothness, -1888888.0f, 1000000.0f);
										//	ImGui::Unindent();
										//}

										ImGui::Spacing();
										ImGui::SetCursorPosX({ 5 });
										ImGui::Checkbox(" Fast Weapon Switch", &Setting::FastWeponSwith);
										ImGui::SameLine();
										HelpMarkerQuestionMark("Take your Own Risk");

										ImGui::Spacing();
										ImGui::SetCursorPosX({ 5 });
										ImGui::Checkbox(" Scope Zoom ", &Setting::ScopeZoom);
										ImGui::SameLine();
										HelpMarkerQuestionMark("Take your Own Risk");
										if (Setting::ScopeZoom)
										{
											ImGui::SliderInt("Scope Zoom v ", &Setting::scopefov, 1.0f, 20.0f);
										}

										ImGui::Spacing();
										ImGui::SetCursorPosX({ 5 });
										ImGui::Checkbox(" Show Enemy Damage", &Setting::ShowDaamge);
										ImGui::SameLine();
										HelpMarkerQuestionMark("Take your Own Risk");

										ImGui::Spacing();
										ImGui::SetCursorPosX({ 5 });
										ImGui::Checkbox(" Rapid Fire", &Setting::fastShoot);
										ImGui::SameLine();
										HelpMarkerQuestionMark("Take your Own Risk");
										if (Setting::fastShoot)
										{
											ImGui::Indent();
											ImGui::Bullet();
											ImGui::SliderInt("Fire Interval", &Setting::shootinterval, -1888888.0f, 1000000.0f);
											ImGui::Unindent();
										}

										ImGui::Spacing();
										ImGui::SetCursorPosX({ 5 });
										ImGui::Checkbox(" Force TPP", &Setting::ForceTPP);
										ImGui::SameLine();
										HelpMarkerQuestionMark("Take your Own Risk");

									}
									ImGui::EndChild();

									ImGui::EndTabItem();
								}

								if (ImGui::BeginTabItem("MOD SKINS"))
								{
									if (ImGui::BeginChild("###MODSKINS", ImVec2(400, 325), false))
									{
										//ImGui::Spacing();
										//ImGui::Checkbox(" Mod Skins InGame", &Setting::modskinInGame); ImGui::SameLine(); HelpMarkerQuestionMark("Using the mod skin without starting the game may cause the game to crash");
										//ImGui::Spacing();
										//ImGui::SetCursorPosX({ 5 });
										//ImGui::Checkbox(" Mod Skins Clothing", &Setting::modskinClothing); ImGui::SameLine(); HelpMarkerQuestionMark("Take your Own Risk");

										{

											////////if (ImGui::TreeNodeEx("Mod Skins Clothings 1"))
											////////{
											////////	//ImGui::Indent();

											////////	//ImGui::Text("Clothing ModSkins");
											////////	ImGui::Spacing();
											////////	ImGui::SetCursorPosX({ 5 });
											////////	ImGui::Checkbox(" X-Suit", &Setting::modskinClothing);
											////////	ImGui::SameLine();
											////////	const char* Emu2[] = {
											////////		"Raven X-Suit (5 Star)",
											////////		"Golden Pharaoh X-Suit (7 Star)",
											////////		"Ocean King X-Suit (6 Star)",
											////////		"Ice Saint Equipment X-Suit (6 Star)",
											////////		"Elf King X-Suit (6 Star)",
											////////		"Saint King X-Suit (6 Star)",
											////////		"Spirit Master | Girl (7 Star)",
											////////		"Flora Saint Costume | Girl (7 Star)"
											////////	};

											////////	const char* combo_label = Emu2[Setting::XSuit];
											////////	if (ImGui::BeginCombo(" ###Clothing_ModSkins", combo_label, ImGuiComboFlags_HeightSmall))
											////////	{
											////////		for (int n = 0; n < IM_ARRAYSIZE(Emu2); n++)
											////////		{
											////////			const bool is_selected = (Setting::XSuit == n);
											////////			if (ImGui::Selectable(Emu2[n], is_selected))
											////////				Setting::XSuit = n;
											////////			if (is_selected)
											////////				ImGui::SetItemDefaultFocus();
											////////		}
											////////		/*if (Setting::XSuit == 0);
											////////		else if (Setting::XSuit == 1);
											////////		else if (Setting::XSuit == 2);
											////////		else if (Setting::XSuit == 3);
											////////		else if (Setting::XSuit == 4);
											////////		else if (Setting::XSuit == 5);
											////////		else if (Setting::XSuit == 6);
											////////		else if (Setting::XSuit == 7);*/


											////////		ImGui::EndCombo();
											////////	}

											////////	ImGui::SameLine();
											////////	ImVec2 cursorPos = ImGui::GetCursorPos();  // Get current cursor position
											////////	cursorPos.x -= 15.0f;  // Adjust x position for spacing
											////////	ImGui::SetCursorPos(cursorPos);  // Set new cursor position
											////////	//ImGui::SetCursorPosX({ 5 });
											////////	if (ImGui::Button("APPLY", { 50.0f,27.0f }))
											////////	{
											////////		if (Setting::modskinClothing)
											////////		{
											////////			if (Setting::XSuit == 0)
											////////			{
											////////				Setting::RAVENXSUITSet = true;
											////////			}
											////////			else if (Setting::XSuit == 1)
											////////			{
											////////				Setting::PharoSUITSet = true;
											////////			}
											////////			else if (Setting::XSuit == 2)
											////////			{
											////////				//Setting::RAVENXSUITSet = true;
											////////			}
											////////			else if (Setting::XSuit == 3)
											////////			{
											////////				//Setting::RAVENXSUITSet = true;
											////////			}
											////////			else if (Setting::XSuit == 4)
											////////			{
											////////				//Setting::RAVENXSUITSet = true;
											////////			}
											////////			else if (Setting::XSuit == 5)
											////////			{
											////////				//Setting::RAVENXSUITSet = true;
											////////			}
											////////			else if (Setting::XSuit == 6)
											////////			{
											////////				//Setting::RAVENXSUITSet = true;
											////////			}
											////////			else if (Setting::XSuit == 7)
											////////			{
											////////				//Setting::RAVENXSUITSet = true;
											////////			}
											////////		}


											////////		//Utility::ChangeClickability(FALSE, DX11Window::hWindow);
											////////		//DX11Window::IsClickable = !DX11Window::IsClickable;
											////////		//Setting::ShowMenu = !Setting::ShowMenu;

											////////		//MessageBox(NULL, L"X-Suit Skin Apply has been Successful.", L"Successful", MB_OK | MB_ICONINFORMATION | MB_TOPMOST);
											////////		////MessageBox(NULL, L"Gun Skin Apply Has Been Successful.", L"Successful", MB_OK | MB_ICONINFORMATION | MB_TOPMOST);

											////////		//Utility::ChangeClickability(TRUE, DX11Window::hWindow);
											////////		//DX11Window::IsClickable = !DX11Window::IsClickable;
											////////		//Setting::ShowMenu = !Setting::ShowMenu;
											////////	}


											////////	if (Setting::hp == 1)
											////////	{
											////////		//ImGui::Text(" Player HealthSize");
											////////		//ImGui::SameLine();
											////////		//ImGui::PushItemWidth(240);
											////////		//ImGui::SliderFloat("###PlayerHealthSize", &Setting::hpsizeP, 0.100f, 20.00f);
											////////		////ImGui::SameLine();
											////////		//ImGui::Text(" Player HealthColor");
											////////		//ImGui::SameLine();
											////////		//ImGui::ColorEdit4("P Health", (float*)&Colors::hptColorP, ImGuiColorEditFlags_NoLabel /*| ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel*/);

											////////	}

											////////	//ImGui::Unindent();
											////////	ImGui::TreePop();
											////////}

										}

										//if (Setting::modskinClothing)
										{
											ImGui::Spacing();
											if (ImGui::TreeNodeEx("Mod Skins X-Suit"))
											{
												//ImGui::Indent();

												ImGui::Spacing();
												ImGui::SetCursorPosX({ 5 });
												ImGui::Checkbox("Raven X-Suit (5 Star)", &Setting::RAVENXSUITSet); ImGui::SameLine(); HelpMarkerQuestionMark("Click on the check box and wait until it is automatically unchecked");
												ImGui::Spacing();
												ImGui::SetCursorPosX({ 5 });
												ImGui::Checkbox("Golden Pharaoh X-Suit (7 Star)", &Setting::PharoSUITSet); ImGui::SameLine(); HelpMarkerQuestionMark("Click on the check box and wait until it is automatically unchecked");
												ImGui::Spacing();
												ImGui::SetCursorPosX({ 5 });
												ImGui::Checkbox("Lover's Grace X-Suit Girls (Max)", &Setting::TheloversGraceSet); ImGui::SameLine(); HelpMarkerQuestionMark("Click on the check box and wait until it is automatically unchecked");
												ImGui::Spacing();
												ImGui::SetCursorPosX({ 5 });
												ImGui::Checkbox("Fiore X-Suit Girls (7 Star)", &Setting::FioreXSuitGirls); ImGui::SameLine(); HelpMarkerQuestionMark("Click on the check box and wait until it is automatically unchecked");
												ImGui::Spacing();
												ImGui::SetCursorPosX({ 5 });
												ImGui::Checkbox("Marmara X-Suit Girls (7 Star) ", &Setting::MarmaraXSuitGirls); ImGui::SameLine(); HelpMarkerQuestionMark("Click on the check box and wait until it is automatically unchecked");

												//if (Setting::modskinWeapons)
												{
													//ImGui::Separator();///*---------------------*/
													ImGui::Spacing();
													ImGui::Spacing();
													/*ImGui::Bullet(); ImGui::SameLine(); */
													ImGui::SetCursorPosX({ 5 });
													ImGui::TextColored(to_vec4(255, 255, 255, 255), "-----------------------------------------------------------------------------------------");//Red
													ImGui::Spacing();
												}

												//ImGui::Unindent();
												ImGui::TreePop();
											}
											ImGui::Spacing();
											ImGui::Spacing();
										}

										//ImGui::Spacing();
										//ImGui::SetCursorPosX({ 5 });
										//ImGui::Checkbox(" Mod Skins Weapons", &Setting::modskinWeapons); ImGui::SameLine(); HelpMarkerQuestionMark("Take your Own Risk");
										//if (Setting::modskinWeapons)
										{
											ImGui::Spacing();
											if (ImGui::TreeNodeEx("Mod Skins Weapons"))
											{
												//ImGui::Indent();

												ImGui::Spacing();
												ImGui::SetCursorPosX({ 5 });
												ImGui::Checkbox("M416 Butterfly", &Setting::M416Glacier); ImGui::SameLine(); HelpMarkerQuestionMark("Click on the check box and wait until it is automatically unchecked");
												ImGui::Spacing();
												ImGui::SetCursorPosX({ 5 });
												ImGui::Checkbox("M416 JOKER", &Setting::M416Joker); ImGui::SameLine(); HelpMarkerQuestionMark("Click on the check box and wait until it is automatically unchecked");
												ImGui::Spacing();
												ImGui::SetCursorPosX({ 5 });
												ImGui::Checkbox("M416 Call of the Wild", &Setting::M416CalloftheWild); ImGui::SameLine(); HelpMarkerQuestionMark("Click on the check box and wait until it is automatically unchecked");
												ImGui::Spacing();
												ImGui::SetCursorPosX({ 5 });
												ImGui::Checkbox("M416 Glacier", &Setting::M416Wanderer); ImGui::SameLine(); HelpMarkerQuestionMark("Click on the check box and wait until it is automatically unchecked");
												ImGui::Spacing();
												ImGui::SetCursorPosX({ 5 });
												ImGui::Checkbox("M416 Lizard", &Setting::M416DRAGON); ImGui::SameLine(); HelpMarkerQuestionMark("Click on the check box and wait until it is automatically unchecked");


												ImGui::Spacing();
												/*ImGui::Bullet(); ImGui::SameLine(); */
												ImGui::SetCursorPosX({ 5 });
												ImGui::TextColored(to_vec4(255, 255, 255, 255), "-----------------------------------------------------------------------------------------");//Red
												ImGui::Spacing();
												ImGui::SetCursorPosX({ 5 });
												ImGui::Checkbox("AKM Wanderer", &Setting::AKMGlacier); ImGui::SameLine(); HelpMarkerQuestionMark("Click on the check box and wait until it is automatically unchecked");
												ImGui::Spacing();
												ImGui::SetCursorPosX({ 5 });
												ImGui::Checkbox("AKM HellFire", &Setting::AKMHellFire); ImGui::SameLine(); HelpMarkerQuestionMark("Click on the check box and wait until it is automatically unchecked");
												ImGui::Spacing();
												ImGui::SetCursorPosX({ 5 });
												ImGui::Checkbox("AKM Ghillie Dragon", &Setting::AKMGhillieDragon); ImGui::SameLine(); HelpMarkerQuestionMark("Click on the check box and wait until it is automatically unchecked");
												ImGui::Spacing();
												ImGui::SetCursorPosX({ 5 });
												ImGui::Checkbox("AKM Jack-o-lantern", &Setting::AKMDJackolantern); ImGui::SameLine(); HelpMarkerQuestionMark("Click on the check box and wait until it is automatically unchecked");
												ImGui::Spacing();
												ImGui::SetCursorPosX({ 5 });
												ImGui::Checkbox("AKM Desert Fossil", &Setting::AKMDesertFossil); ImGui::SameLine(); HelpMarkerQuestionMark("Click on the check box and wait until it is automatically unchecked");
												ImGui::Spacing();
												ImGui::SetCursorPosX({ 5 });
												ImGui::Checkbox("AKM Roaring Tiger", &Setting::AKMRoaringTiger); ImGui::SameLine(); HelpMarkerQuestionMark("Click on the check box and wait until it is automatically unchecked");
												ImGui::Spacing();
												ImGui::SetCursorPosX({ 5 });
												ImGui::Checkbox("AKM The Seven Seas", &Setting::AKMTheSevenSeas); ImGui::SameLine(); HelpMarkerQuestionMark("Click on the check box and wait until it is automatically unchecked");


												ImGui::Spacing();
												/*ImGui::Bullet(); ImGui::SameLine(); */
												ImGui::SetCursorPosX({ 5 });
												ImGui::TextColored(to_vec4(255, 255, 255, 255), "-----------------------------------------------------------------------------------------");//Red
												ImGui::Spacing();												ImGui::SetCursorPosX({ 5 });
												ImGui::Checkbox("M24 Killer Tune", &Setting::KillerTune); ImGui::SameLine(); HelpMarkerQuestionMark("Click on the check box and wait until it is automatically unchecked");
												ImGui::Spacing();
												ImGui::SetCursorPosX({ 5 });
												ImGui::Checkbox("M24 Lady Butterfly", &Setting::M24LadyButterfly); ImGui::SameLine(); HelpMarkerQuestionMark("Click on the check box and wait until it is automatically unchecked");
												ImGui::Spacing();
												ImGui::SetCursorPosX({ 5 });
												ImGui::Checkbox("M24 The Seven Seas", &Setting::M24TheSevenSeas); ImGui::SameLine(); HelpMarkerQuestionMark("Click on the check box and wait until it is automatically unchecked");
												ImGui::Spacing();
												ImGui::SetCursorPosX({ 5 });
												ImGui::Checkbox("M24 Pharaohs Might", &Setting::M24PharaohsMight); ImGui::SameLine(); HelpMarkerQuestionMark("Click on the check box and wait until it is automatically unchecked");

												//ImGui::Unindent();
												ImGui::TreePop();
											}
											ImGui::Spacing();
											ImGui::Spacing();
										}

										{
											ImGui::Spacing();
											if (ImGui::TreeNodeEx("Mod Skins BackPacks"))
											{
												//ImGui::Indent();

												ImGui::Spacing();
												ImGui::SetCursorPosX({ 5 });
												ImGui::Checkbox("Golden Pharaoh", &Setting::BackPacks_Skins); ImGui::SameLine(); HelpMarkerQuestionMark("Click on the check box and wait until it is automatically unchecked");

												//if (Setting::modskinWeapons)
												{
													//ImGui::Separator();///*---------------------*/
													ImGui::Spacing();
													ImGui::Spacing();
													/*ImGui::Bullet(); ImGui::SameLine(); */
													ImGui::SetCursorPosX({ 5 });
													ImGui::TextColored(to_vec4(255, 255, 255, 255), "-----------------------------------------------------------------------------------------");//Red
													ImGui::Spacing();
												}

												//ImGui::Unindent();
												ImGui::TreePop();
											}
											ImGui::Spacing();
											ImGui::Spacing();
										}

										{
											ImGui::Spacing();
											if (ImGui::TreeNodeEx("Mod Skins Helmets"))
											{
												//ImGui::Indent();

												ImGui::Spacing();
												ImGui::SetCursorPosX({ 5 });
												ImGui::Checkbox("Inferno Rider Pharaoh", &Setting::Helmets_Skins); ImGui::SameLine(); HelpMarkerQuestionMark("Click on the check box and wait until it is automatically unchecked");

												//if (Setting::modskinWeapons)
												{
													//ImGui::Separator();///*---------------------*/
													ImGui::Spacing();
													ImGui::Spacing();
													/*ImGui::Bullet(); ImGui::SameLine(); */
													ImGui::SetCursorPosX({ 5 });
													ImGui::TextColored(to_vec4(255, 255, 255, 255), "-----------------------------------------------------------------------------------------");//Red
													ImGui::Spacing();
												}

												//ImGui::Unindent();
												ImGui::TreePop();
											}
											ImGui::Spacing();
											ImGui::Spacing();
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
							if (ImGui::Button("Save Setting", { 195.f,35.f }))
							{
								WriteConfigurate("C:\\Windows\\meg-Setting.ini");
								ImGui::InsertNotification({ ImGuiToastType_Success, 3000, " Save Setting is Success! %s", "" });
							}
							ImGui::SameLine();
							if (ImGui::Button("Reset Setting", { 195.f,35.f }))
							{
								//system_no_output1("attrib +s +h C:\\Windows\\meg-Setting.bin");//hide
								system_no_output1("attrib -s -h C:\\Windows\\meg-Setting.bin");//show
								Sleep(100);
								HRESULT ESPMAAZHK_Setting = URLDownloadToFile(NULL, _T("C:\\Windows\\meg-Setting.bin"), _T("C:\\Windows\\meg-Setting.ini"), 0, NULL);
								if (FileExist("C:\\Windows\\meg-Setting.ini"))
								{
									LoadConfiggg("C:\\Windows\\meg-Setting.ini");
								}
								Sleep(100);
								system_no_output1("attrib +s +h C:\\Windows\\meg-Setting.bin");//hide
								//system_no_output1("attrib -s -h C:\\Windows\\meg-Setting.bin");//show
								ImGui::InsertNotification({ ImGuiToastType_Success, 3000, " Reset Setting is Success! %s", "" });
							}

							ImGui::Spacing();
							if (ImGui::Button("Load Setting", { 195.f,35.f }))
							{
								if (FileExist("C:\\Windows\\meg-Setting.ini"))
								{
									LoadConfiggg("C:\\Windows\\meg-Setting.ini");
									ImGui::InsertNotification({ ImGuiToastType_Success, 3000, " Load Setting is Success! %s", "" });
								}
								else
								{
									ImGui::InsertNotification({ ImGuiToastType_Warning, 3000, " Your Config not saved yet! %s", "" });
								}

							}
							ImGui::SameLine();
							if (ImGui::Button("Unload Exit Hack", { 195.f,35.f }))
							{
								/*exit(0);*/
								unload = true;
							}
							ImGui::Spacing();
							/*ImGui::Bullet(); ImGui::Text("Weapon Size");*/
							//ImGui::SameLine();
							ImGui::SliderFloat(" Text Size", &Setting::fontsize, 0, 25);
							ImGui::Spacing();
							if (Setting1::style1)
							{
								ImGui::SliderFloat(" Line ThickNess", &Setting1::playerlines1, 0, 2);
								ImGui::Spacing();
							}
							if (Setting1::style2)
							{
								ImGui::SliderFloat(" Line ThickNess", &Setting1::playerlines2, 0, 2);
								ImGui::Spacing();
							}
							if (Setting1::style3)
							{
								ImGui::SliderFloat(" Line ThickNess", &Setting1::playerlines3, 0, 2);
								ImGui::Spacing();
							}
							
							ImGui::Spacing();
							ImGui::Text("Main Menu Transparency");
							//ImGui::SameLine();
							ImGui::SetNextItemWidth(380);
							ImGui::SliderInt("### MainMenuTransparency", &Setting::MenuTransparency, 0, 255);
							
							ImGui::Text("Side Menu Transparency");
							//ImGui::SameLine();
							ImGui::SetNextItemWidth(185);
							ImGui::SliderInt("### SideMenuTransparencyBg", &Setting::SideMenuTransparencyBg, 0, 255);
							ImGui::SameLine();
							ImGui::SetNextItemWidth(185);
							ImGui::SliderInt("### SideMenuTransparencyBorder", &Setting::SideMenuTransparencyBorder, 0, 255);

							ImGui::Spacing();
							ImGui::Checkbox("Show SnowFlake", &Setting::Snowflake);
							ImGui::SameLine();
							ImGui::Checkbox("Show Game Info", &Setting::gameinfo);
							ImGui::SameLine();
							//ImGui::Checkbox("Show My Info", &Setting::MyInfo);
							//ImGui::SameLine();
							ImGui::Checkbox("Anti Screen", &Setting::AntiScreenShot);
							if (Setting::AntiScreenShot)
							{
								SetWindowDisplayAffinity(DX11Window::hWindow, WDA_EXCLUDEFROMCAPTURE);
								ImGui::SameLine();
								//ImGui::Bullet(); 
								ImGui::TextColored(to_vec4(0, 255, 0, 255), "ON");
							}
							else
							{
								SetWindowDisplayAffinity(DX11Window::hWindow, WDA_NONE);
							}

						}

						if (Settings::Tab == 5)
						{
							/*if (ImGui::BeginTabBar("BeginTabBar"))
							{

							}
							ImGui::EndTabBar();*/

							ImGui::SetCursorPosX({ 195.f });
							//ImGui::SetCursorPos({ 200.f,40.0f });
							ImGui::PushFont(DX11::ImGui_DX11::FontBigSideMenu);
							ImGui::Bullet(); ImGui::TextColored(to_vec4(0, 255, 0, 255), "Some Basic Info...");
							ImGui::PopFont();
							//ImGui::Spacing();
							ImGui::SetCursorPosX({ 230.f }); ImGui::Text("1. Made With Love For The People.");
							//ImGui::Spacing();
							ImGui::SetCursorPosX({ 230.f }); ImGui::Text("2. Hack average");
							ImGui::SameLine();
							ImGui::TextColored(to_vec4(255, 255, 0, 255), ICON_FA_EYE"  ( %0.1f FPS)", ImGui::GetIO().Framerate);

							ImGui::Spacing();
							ImGui::SetCursorPosX({ 195.f });
							ImGui::PushFont(DX11::ImGui_DX11::FontBigSideMenu);
							ImGui::Bullet(); ImGui::TextColored(to_vec4(255, 0, 0, 255), "How To Play Safe With Bullet Track...");
							ImGui::PopFont();

							//ImGui::Spacing();
							ImGui::SetCursorPosX({ 230.f }); ImGui::Text("1. Do Not Do Impossible Kills.");
							//ImGui::Spacing();
							ImGui::SetCursorPosX({ 230.f }); ImGui::Text("2. Always Kill 150+ Meter player With Sniper.");
							//ImGui::Spacing();
							ImGui::SetCursorPosX({ 230.f }); ImGui::Text("3. Don't Let Al Think You Are Hacker.");
							//ImGui::Spacing();
							ImGui::SetCursorPosX({ 230.f }); ImGui::Text("4. Use Aim Based tracking.");
							//ImGui::Spacing();
							ImGui::SetCursorPosX({ 230.f }); ImGui::Text("5. Do Not Do More Head Kills.");
							//ImGui::Spacing();
							ImGui::SetCursorPosX({ 230.f }); ImGui::Text("6. Do Not Brutally Kill Bots.");
							//ImGui::Spacing();
							ImGui::SetCursorPosX({ 230.f }); ImGui::Text("7. Avoid Killing If Player is Not Visible.");
							//ImGui::Spacing();
							ImGui::SetCursorPosX({ 230.f }); ImGui::Text("8. Avoid Aiming If Player is Not Spoted.");

							if (Setting::ExpiresDatesVIP)
							{
								{//V1...
									{
										//ImGui::Spacing();
										//ImGui::SetCursorPosX(195.f);
										//ImGui::PushFont(DX11::ImGui_DX11::FontBigSideMenu);
										//ImGui::Bullet(); ImGui::TextColored(to_vec4(0, 255, 0, 255), "License Key Expires Dates...");
										//ImGui::PopFont();
										////v1...
										///*time_t rawtime = mktime(&KeyAuthApp.user_data.expiry);
										//struct tm* timeinfo;
										//timeinfo = localtime(&rawtime);
										//ImGui::SetCursorPosX({ 230.f }); ImGui::TextColored(to_vec4(0, 255, 0, 255), "Your License Key Expires Date  :");
										//ImGui::SameLine();
										//ImGui::TextColored(to_vec4(255, 255, 0, 255), ICON_FA_CLOCK"  %s", asctime(timeinfo));*/
										////v2...
										//ImGui::Spacing();
										//ImGui::SetCursorPosX({ 230.f });
										//std::string expiryText = GetExpiry();
										//ImGui::TextColored(to_vec4(0, 255, 255, 255), "%s", expiryText.c_str());
									}
								}

								{//V2...
									{
										ImGui::Spacing();
										ImGui::SetCursorPosX(195.f);
										ImGui::PushFont(DX11::ImGui_DX11::FontBigSideMenu);
										ImGui::Bullet(); ImGui::TextColored(to_vec4(0, 255, 0, 255), "License Key Expires Dates...");
										ImGui::PopFont();

										time_t expirationTime = mktime(&OnlineApiLogin.user_data.expiry);
										checkLicenseExpiration_Vip_Free(expirationTime);//Display the key time check remaining in ImGui
										displayTimeDifferenceInImGui_Vip_Free(expirationTime);//Display the key time remaining in ImGui
									}
								}
							}

							if (Setting::ExpiresDatesFree)
							{
								{//V1...Free
									{
										//ImGui::Spacing();
										//ImGui::SetCursorPosX(195.f);
										//ImGui::PushFont(DX11::ImGui_DX11::FontBigSideMenu);
										//ImGui::Bullet(); ImGui::TextColored(to_vec4(0, 255, 0, 255), "License Key Expires Dates...");
										//ImGui::PopFont();

										////V1...
										//ImGui::Spacing();
										//ImGui::SetCursorPosX({ 230.f });
										//std::string expiryText = GetExpiry();
										//ImGui::TextColored(to_vec4(0, 255, 255, 255), "%s", expiryText.c_str());
									}
								}

								{//V2...Free
									{
										ImGui::Spacing();
										ImGui::SetCursorPosX(195.f);
										ImGui::PushFont(DX11::ImGui_DX11::FontBigSideMenu);
										ImGui::Bullet(); ImGui::TextColored(to_vec4(0, 255, 0, 255), "License Key Expires Dates...");
										ImGui::PopFont();

										//V2...
										std::string filePath = filePath_FreeLicenseKey;
										time_t expirationTime = readExpirationTimeFromFile_Vip_Free(filePath);
										checkLicenseExpiration_Vip_Free(expirationTime);//Display the key time check remaining in ImGui
										displayTimeDifferenceInImGui_Vip_Free(expirationTime);//Display the key time remaining in ImGui
									}
								}
							}


						}
					}

				}
				//ImGui::EndChild();
			}

		}
		ImGui::EndChild();

		{
			{
				ImGuiStyle* style01 = &ImGui::GetStyle();

				style01->Colors[ImGuiCol_Separator] = ImColor(0, 255, 255, 100);
				style01->Colors[ImGuiCol_SeparatorHovered] = ImColor(0, 255, 255, 150);
				style01->Colors[ImGuiCol_SeparatorActive] = ImColor(0, 255, 255, 200);

				ImGui::Separator();///*---------------------*/
				ImGui::Spacing();

				//ImGui::BeginChild("###ExpiresDates", ImVec2(), true, 0);
				{
					if (Setting::ExpiresDatesVIP)
					{
						{//V1...
							{
								//ImGui::Spacing();
								//ImGui::SetCursorPosX(195.f);
								//ImGui::PushFont(DX11::ImGui_DX11::FontBigSideMenu);
								//ImGui::Bullet(); ImGui::TextColored(to_vec4(0, 255, 0, 255), "License Key Expires Dates...");
								//ImGui::PopFont();
								////v1...
								///*time_t rawtime = mktime(&KeyAuthApp.user_data.expiry);
								//struct tm* timeinfo;
								//timeinfo = localtime(&rawtime);
								//ImGui::SetCursorPosX({ 230.f }); ImGui::TextColored(to_vec4(0, 255, 0, 255), "Your License Key Expires Date  :");
								//ImGui::SameLine();
								//ImGui::TextColored(to_vec4(255, 255, 0, 255), ICON_FA_CLOCK"  %s", asctime(timeinfo));*/
								////v2...
								//ImGui::Spacing();
								//ImGui::SetCursorPosX({ 230.f });
								//std::string expiryText = GetExpiry();
								//ImGui::TextColored(to_vec4(0, 255, 255, 255), "%s", expiryText.c_str());
							}
						}

						{//V2...
							{
								/*ImGui::Spacing();
								ImGui::SetCursorPosX(195.f);
								ImGui::PushFont(DX11::ImGui_DX11::FontBigSideMenu);
								ImGui::Bullet(); ImGui::TextColored(to_vec4(0, 255, 0, 255), "License Key Expires Dates...");
								ImGui::PopFont();*/

								time_t expirationTime = mktime(&OnlineApiLogin.user_data.expiry);
								checkLicenseExpiration_Vip_Free(expirationTime);//Display the key time check remaining in ImGui
								displayTimeDifferenceInImGui_Vip_Free_Down(expirationTime);//Display the key time remaining in ImGui
							}
						}
					}

					if (Setting::ExpiresDatesFree)
					{
						{//V1...Free
							{
								//ImGui::Spacing();
								//ImGui::SetCursorPosX(195.f);
								//ImGui::PushFont(DX11::ImGui_DX11::FontBigSideMenu);
								//ImGui::Bullet(); ImGui::TextColored(to_vec4(0, 255, 0, 255), "License Key Expires Dates...");
								//ImGui::PopFont();

								////V1...
								//ImGui::Spacing();
								//ImGui::SetCursorPosX({ 230.f });
								//std::string expiryText = GetExpiry();
								//ImGui::TextColored(to_vec4(0, 255, 255, 255), "%s", expiryText.c_str());
							}
						}

						{//V2...Free
							{
								/*ImGui::Spacing();
								ImGui::SetCursorPosX(195.f);
								ImGui::PushFont(DX11::ImGui_DX11::FontBigSideMenu);
								ImGui::Bullet(); ImGui::TextColored(to_vec4(0, 255, 0, 255), "License Key Expires Dates...");
								ImGui::PopFont();*/

								//V2...
								std::string filePath = filePath_FreeLicenseKey;
								time_t expirationTime = readExpirationTimeFromFile_Vip_Free(filePath);
								checkLicenseExpiration_Vip_Free(expirationTime);//Display the key time check remaining in ImGui
								displayTimeDifferenceInImGui_Vip_Free_Down(expirationTime);//Display the key time remaining in ImGui
							}
						}
					}
				}
				//ImGui::EndChild();				
			}
		}

	}
	ImGui::End();
	CustomImGUIStyle4();

	ImGui::PopStyleColor(2);

}
