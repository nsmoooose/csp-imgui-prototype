#include <string>
#include "ui.h"
#include "imgui.h"

struct ui_state ui_state;

ui_state::ui_state() {
	show_main = true;
	show_settings = false;
	show_tutorials = false;
	show_missions = false;
	show_multiplayer = false;
	show_help = false;

	username[0] = '\0';
	sound_volume = 1.0f;
	strcpy(server_listen_ip, "0::0");
	strcpy(server_listen_port, "3160");

	window_margin = 50.0f;
}

void ui_center_window_with_margin(float margin) {
	ImVec2 display_size = ImGui::GetIO().DisplaySize;
    ImGui::SetNextWindowPos(ImVec2(margin, margin));
    ImGui::SetNextWindowSize(ImVec2(display_size.x - 2 * margin, display_size.y - 2 * margin));
}

void ui_render() {
	ui_theme_gray();

	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(10.0f, 10.0f));

	ui_main_menu();
	if(ui_state.show_settings) {
		ui_settings_menu();
	}
	if(ui_state.show_tutorials) {
		ui_tutorials_menu();
	}
	if(ui_state.show_missions) {
		ui_missions_menu();
	}
	if(ui_state.show_multiplayer) {
		ui_multiplayer_menu();
	}
	if(ui_state.show_help) {
		ui_help_menu();
	}

	ImGui::PopStyleVar();
}
