#include <string>
#include "ui.h"
#include "imgui.h"

bool g_show_main = true;
bool g_show_settings = false;
bool g_show_tutorials = false;
bool g_show_missions = false;
bool g_show_multiplayer = false;
bool g_show_help = false;

const float g_window_margin = 50.0f;

char g_username[50] = "";
float g_sound_volume = 1.0f;
char g_server_listen_ip[30] = "0::0";
char g_server_listen_port[30] = "3160";

void ui_center_window_with_margin(float margin) {
	ImVec2 display_size = ImGui::GetIO().DisplaySize;
    ImGui::SetNextWindowPos(ImVec2(margin, margin));
    ImGui::SetNextWindowSize(ImVec2(display_size.x - 2 * margin, display_size.y - 2 * margin));
}

void ui_render() {
	ui_theme_gray();

	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(10.0f, 10.0f));

	ui_main_menu();
	if(g_show_settings) {
		ui_settings_menu();
	}
	if(g_show_tutorials) {
		ui_tutorials_menu();
	}
	if(g_show_missions) {
		ui_missions_menu();
	}
	if(g_show_multiplayer) {
		ui_multiplayer_menu();
	}
	if(g_show_help) {
		ui_help_menu();
	}

	ImGui::PopStyleVar();
}
