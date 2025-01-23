#include "imgui.h"
#include "ui.h"

void ui_main_menu() {
	ImVec2 window_size = {200, 400};
	ImGui::SetNextWindowSize(window_size);
	ImGui::SetNextWindowPos(ImVec2(50, 50));
	ImGui::Begin("Combat Simulator Project", &g_show_main, ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoMove|ImGuiWindowFlags_NoCollapse);

	ImGui::Text("Main menu");

	ImVec2 button_size = { ImGui::GetContentRegionAvail().x, 0 };
	if (ImGui::Button("Instant action", button_size)) {
	}

	if(ImGui::Button("Tutorials", button_size)) {
		g_show_tutorials = true;
	}

	if(ImGui::Button("Missions", button_size)) {
		g_show_missions = true;
	}

	if(ImGui::Button("Multiplayer", button_size)) {
		g_show_multiplayer = true;
	}

	if(ImGui::Button("Settings", button_size)) {
		g_show_settings = true;
	}

	if(ImGui::Button("Help", button_size)) {
		g_show_help = true;
	}

	if(ImGui::Button("Quit", button_size)) {
		g_show_main = false;
	}

	ImGui::End();
}
