#pragma once
#include "imgui_notify/imgui_notify.h"
#include "imgui_notify/tahoma.h" // <-- Required font!

void imgui_notify_Start()
{
	{//imgui_notify Start

		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 5.f);
		//ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(43.f / 255.f, 43.f / 255.f, 43.f / 255.f, 100.f / 255.f));
		ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.100f, 0.100f, 0.100f, 0.100f));
		ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.0f, 0.431f, 1.0f, 0.784f));
		ImGui::PushStyleColor(ImGuiCol_Separator, ImVec4(0.0f, 0.431f, 1.0f, 0.784f));
		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
		ImGui::RenderNotifications();
		ImGui::PopStyleVar(1); // Don't forget to Pop()
		ImGui::PopStyleColor(4);

		////
		//static char title[4096] = "A wonderful quote!";
		//ImGui::InputTextMultiline("Title", title, sizeof(title));

		//static char content[4096] = "Goodbye, my brother. \n- Dembe Zuma";
		//ImGui::InputTextMultiline("Content", content, sizeof(content));

		//static int duration = 5000; // 5 seconds
		//ImGui::InputInt("Duration (ms)", &duration, 100);
		//if (duration < 0) duration = 0; // Shouldn't be negative

		//static ImGuiToastType type = ImGuiToastType_Success;
		//IM_ASSERT(type < ImGuiToastType_COUNT);

		//static bool enable_title = true, enable_content = true;
		//ImGui::Checkbox("Enable title", &enable_title);
		//ImGui::SameLine();
		//ImGui::Checkbox("Enable content", &enable_content);

		//ImGuiToast toast(type, duration);

		//if (enable_title)
		//	toast.set_title(title);

		//if (enable_content)
		//	toast.set_content(content);

		////ImGui::InsertNotification(toast);

	}//imgui_notify End

	////////if (imgui_notify_Start)
	////////{
	////////	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	////////}
	////////else
	////////{
	////////	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	////////}
}