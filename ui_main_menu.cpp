#include "imgui.h"
#include "ui.h"

void ui_main_menu() {
	ImVec2 window_size = {250, 400};
	ImGui::SetNextWindowSize(window_size);
	ImGui::SetNextWindowPos(ImVec2(50, 50));
	ImGui::Begin(ui_i18n_get("csp"), &ui_state.show_main,
				 ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoMove|ImGuiWindowFlags_NoCollapse);

	ImGui::Text(ui_i18n_get("main_menu"));

	ImVec2 button_size = { ImGui::GetContentRegionAvail().x, 0 };
	if (ImGui::Button(ui_i18n_get("instant_action"), button_size)) {
	}

	if(ImGui::Button(ui_i18n_get("tutorials"), button_size)) {
		ui_state.show_tutorials = true;
	}

	if(ImGui::Button(ui_i18n_get("missions"), button_size)) {
		ui_state.show_missions = true;
	}

	if(ImGui::Button(ui_i18n_get("multiplayer"), button_size)) {
		ui_state.show_multiplayer = true;
	}

	if(ImGui::Button(ui_i18n_get("options"), button_size)) {
		ui_state.show_settings = true;
	}

	if(ImGui::Button(ui_i18n_get("help"), button_size)) {
		ui_state.show_help = true;
	}

	if(ImGui::Button(ui_i18n_get("quit"), button_size)) {
		ui_state.show_main = false;
	}

	ImGui::End();
}
