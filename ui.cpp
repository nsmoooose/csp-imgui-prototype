#include "ui.h"
#include "imgui.h"

bool g_show_main = true;
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
	ImVec2 window_size = {200, 400};
	ImGui::SetNextWindowSize(window_size);
	ImGui::SetNextWindowPos(ImVec2(50, 50));
	ImGui::Begin("Main menu", &g_show_main, ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoMove|ImGuiWindowFlags_NoCollapse);

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
		g_show_main = false;
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
		ImGui::EndPopup();
	}
}

void ui_multiplayer_menu() {
	ImGui::OpenPopup("Multiplayer");
	if(ImGui::BeginPopupModal("Multiplayer", &g_show_multiplayer)) {
		ImGui::EndPopup();
	}
}

void ui_help_menu() {
	ImGui::OpenPopup("Help");

	ImVec2 display_size = ImGui::GetIO().DisplaySize;
    float margin = 50.0f;
    ImGui::SetNextWindowPos(ImVec2(margin, margin));
    ImGui::SetNextWindowSize(ImVec2(display_size.x - 2 * margin, display_size.y - 2 * margin));

	if(ImGui::BeginPopupModal("Help", &g_show_help, ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoMove|ImGuiWindowFlags_NoCollapse)) {
		static int selectedTab = 0; // Track the selected tab

		const char* tabs[] = {
			"Welcome",
			"F16 first steps",
			"Aircraft controls",
			"View controls",
			"Mouse",
			"Joystick",
		};
		const int tabCount = IM_ARRAYSIZE(tabs);

		ImGui::BeginChild("Tabs", ImVec2(150, 0), true);
		for (int i = 0; i < tabCount; i++) {
			if (ImGui::Selectable(tabs[i], selectedTab == i)) {
				selectedTab = i;
			}
		}
		ImGui::EndChild();

		ImGui::SameLine();

		ImGui::BeginChild("Content", ImVec2(0, 0), true);
		ImGui::Text("Content for %s", tabs[selectedTab]);
		switch (selectedTab) {
		case 0:
			ImGui::Text("This is the content for Tab 1.");
			break;
		case 1:
			ImGui::Text("This is the content for Tab 2.");
			break;
		case 2:
			ImGui::Text("This is the content for Tab 3.");
			break;
		case 3:
			ImGui::Text("This is the content for Tab 4.");
			break;
		}
		ImGui::EndChild();

		ImGui::EndPopup();
	}
}
