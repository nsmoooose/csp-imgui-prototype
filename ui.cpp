#include "ui.h"
#include "imgui.h"

static bool g_show_settings = false;
static bool g_show_tutorials = false;
static bool g_show_missions = false;
static bool g_show_multiplayer = false;
static bool g_show_help = false;

void ui_render() {
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
}

void ui_main_menu() {
	static bool show_another_window = true;

	ImVec2 window_size = {200, 400};
	ImGui::SetNextWindowSize(window_size);
	ImGui::SetNextWindowPos(ImVec2(50, 50));
	ImGui::Begin("Main menu", &show_another_window, ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoMove|ImGuiWindowFlags_NoCollapse);

	ImGui::Text("CSP");

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
	}

	ImGui::End();
}

void ui_settings_menu() {
	ImGui::OpenPopup("Settings");
	if(ImGui::BeginPopupModal("Settings", &g_show_settings)) {
		ImGui::Text("CSP");

		ImGui::EndPopup();
	}
}

void ui_tutorials_menu() {
	ImGui::OpenPopup("Tutorials");
	if(ImGui::BeginPopupModal("Tutorials", &g_show_tutorials)) {
		ImGui::EndPopup();
	}
}

void ui_missions_menu() {
	ImGui::OpenPopup("Missions");
	if(ImGui::BeginPopupModal("Missions", &g_show_missions)) {
		ImGui::End();
	}
}

void ui_multiplayer_menu() {
	ImGui::OpenPopup("Multiplayer");
	if(ImGui::BeginPopupModal("Multiplayer", &g_show_multiplayer)) {
		ImGui::End();
	}
}

void ui_help_menu() {
	ImGui::OpenPopup("Help");
	if(ImGui::BeginPopupModal("Help", &g_show_help)) {
		ImGui::End();
	}
}
