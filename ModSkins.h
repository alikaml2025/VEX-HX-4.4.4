#pragma once
//#include <imguipp.h>
//#include <imgui_notify/imgui_notify.h>

bool XSuit = false;

struct ImVec2;
void ImGui::SetNextWindowPos(const ImVec2& pos, ImGuiCond cond, const ImVec2& pivot);
void ImGui::SetNextWindowSize(const ImVec2& size, ImGuiCond cond);

void X_Suit()
{
	if (XSuit)
	{
		static auto Flags2 = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;

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
				/*Memory::RestoreHook();*/

				//Sleep(100);
				//ShellExecute(0, L"open", L"C:\\Windows\\sc_stop_driver.bat", NULL, 0, SW_HIDE);
				ExitProcess(1);
			}
			ImGui::SameLine();
			if (ImGui::Button("Cancel", { 115.f,25.f }))
			{
				XSuit = false;
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

}

