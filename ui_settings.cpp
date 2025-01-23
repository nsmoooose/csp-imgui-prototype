#include "imgui.h"
#include "ui.h"

const char* l_languages[] = { "English", "Swedish", "German" };

void ui_settings_menu() {
	ImGui::OpenPopup("Settings");
	ui_center_window_with_margin(ui_state.window_margin);
	if(ImGui::BeginPopupModal("Settings", &ui_state.show_settings, ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoMove|ImGuiWindowFlags_NoCollapse)) {

		static int selectedTab = 0;

		const char* tabs[] = {
			"Profile",
			"User interface",
			"Controls",
			"Display",
			"Sound",
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

		ImGui::BeginGroup();

		ImGui::BeginChild("Content", ImVec2(0, ImGui::GetContentRegionAvail().y - ImGui::GetFrameHeightWithSpacing()), true);
		switch (selectedTab) {
		case 0:
			ImGui::Text("Username:");
			ImGui::SetNextItemWidth(-1.0f);
			ImGui::InputText("##Username", ui_state.username, sizeof(ui_state.username));
			break;
		case 1:
			ImGui::Text("Theme:");
			ImGui::SetNextItemWidth(-1.0f);
			// TODO Listbox
			ImGui::Text("Language:");
			ImGui::SetNextItemWidth(-1.0f);
			// TODO Listbox

			static int selected_language = 0;
			if (ImGui::ListBox("##listbox", &selected_language, l_languages, IM_ARRAYSIZE(l_languages))) {
				switch(selected_language) {
				case 0: ui_i18n_set_language("en"); break;
				case 1: ui_i18n_set_language("sv"); break;
				case 2: ui_i18n_set_language("de"); break;
				}
			}

			break;
		case 2:
			break;
		case 3:
			ImGui::Text("Fullscreen:");
			ImGui::SetNextItemWidth(-1.0f);
			// TODO Listbox

			ImGui::Text("Window size:");
			ImGui::SetNextItemWidth(-1.0f);
			// TODO Listbox
			break;
		case 4:
			ImGui::Text("Volume:");
			ImGui::SetNextItemWidth(-1.0f);
			ImGui::SliderFloat("##Volume", &ui_state.sound_volume, 0.0f, 1.0f);
			break;
		}
		ImGui::EndChild();

		if(ImGui::Button("Apply")) {
			ui_state.show_settings = false;
		}
		ImGui::SameLine();
		if(ImGui::Button("Cancel")) {
			ui_state.show_settings = false;
		}

		ImGui::EndGroup();

		ImGui::EndPopup();
	}
}
