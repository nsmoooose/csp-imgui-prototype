#include "imgui.h"
#include "ui.h"

void ui_missions_menu() {
	ImGui::OpenPopup("Missions");
	ui_center_window_with_margin(ui_state.window_margin);
	if(ImGui::BeginPopupModal("Missions", &ui_state.show_missions, ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoMove|ImGuiWindowFlags_NoCollapse)) {
		static int selectedTab = 0; // Track the selected tab

		const char* tabs[] = {
			"Land at airfield X",
			"Incoming bogey",
			"Bombing run",
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
			ImGui::Text("Not yet implemented");
			break;
		case 1:
			ImGui::Text("Not yet implemented");
			break;
		case 2:
			ImGui::Text("Not yet implemented");
			break;
		}
		ImGui::EndChild();

		if(ImGui::Button("Start")) {
		}

		ImGui::EndGroup();

		ImGui::EndPopup();
	}
}
