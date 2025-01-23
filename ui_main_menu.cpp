#include "imgui.h"
#include "ui.h"

void ui_main_menu() {
	ImVec2 window_size = {200, 400};
	ImGui::SetNextWindowSize(window_size);
	ImGui::SetNextWindowPos(ImVec2(50, 50));
	ImGui::Begin("Combat Simulator Project", &ui_state.show_main, ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoMove|ImGuiWindowFlags_NoCollapse);

	ImGui::Text("Main menu");

	ImVec2 button_size = { ImGui::GetContentRegionAvail().x, 0 };
	if (ImGui::Button(ui_i18n_get("Instant action"), button_size)) {
	}

	if(ImGui::Button(ui_i18n_get("Tutorials"), button_size)) {
		ui_state.show_tutorials = true;
	}

	if(ImGui::Button(ui_i18n_get("Missions"), button_size)) {
		ui_state.show_missions = true;
	}

	if(ImGui::Button(ui_i18n_get("Multiplayer"), button_size)) {
		ui_state.show_multiplayer = true;
	}

	if(ImGui::Button(ui_i18n_get("Settings"), button_size)) {
		ui_state.show_settings = true;
	}

	if(ImGui::Button(ui_i18n_get("Help"), button_size)) {
		ui_state.show_help = true;
	}

	if(ImGui::Button(ui_i18n_get("Quit"), button_size)) {
		ui_state.show_main = false;
	}

	ImGui::End();
}
