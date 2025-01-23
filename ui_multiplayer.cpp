#include <string>
#include "imgui.h"
#include "ui.h"

void ui_multiplayer_menu() {
	ImGui::OpenPopup("Multiplayer");
	ui_center_window_with_margin(ui_state.window_margin);
	if(ImGui::BeginPopupModal("Multiplayer", &ui_state.show_multiplayer, ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoMove|ImGuiWindowFlags_NoCollapse)) {
		static int selectedTab = 0;

		const char* tabs[] = {
			"Server list",
			"Server",
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
			if (ImGui::BeginTable("MyTable", 2, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg)) {
				static int selected_row = -1;
				ImGui::TableSetupColumn("Servername", ImGuiTableColumnFlags_WidthStretch);
				ImGui::TableSetupColumn("IP address", ImGuiTableColumnFlags_WidthStretch);
				ImGui::TableHeadersRow();

				for (int row = 0; row < 5; row++) {
					ImGui::TableNextRow();
					for (int column = 0; column < 2; column++) {
						std::string server = "Server " + std::to_string(row);
						ImGui::TableSetColumnIndex(column);
						if(column == 0) {
							if (ImGui::Selectable(server.c_str(), selected_row == row, ImGuiSelectableFlags_SpanAllColumns)) {
								selected_row = (selected_row == row) ? -1 : row;
							}
						} else {
							ImGui::Text("Row %d, Col %d", row, column);
						}
					}
				}
				ImGui::EndTable();
			}
			ImGui::EndChild();
			if(ImGui::Button("Add server")) {
			}
			ImGui::SameLine();
			if(ImGui::Button("Delete server")) {
			}
			ImGui::SameLine();
			if(ImGui::Button("Join server")) {
			}
			break;
		case 1:
			ImGui::Text("Listen address:");
			ImGui::SetNextItemWidth(-1.0f);
			ImGui::InputText("##Listen address", ui_state.server_listen_ip, sizeof(ui_state.server_listen_ip));

			ImGui::Text("Listen port:");
			ImGui::SetNextItemWidth(-1.0f);
			ImGui::InputText("##Listen port", ui_state.server_listen_port, sizeof(ui_state.server_listen_port));
			ImGui::EndChild();
			if(ImGui::Button("Start server")) {
			}
			break;
		}

		ImGui::EndGroup();

		ImGui::EndPopup();
	}
}
