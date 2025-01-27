#include "imgui.h"
#include "ui.h"

static void ui_pause_toolbar() {
#if 0
	Help
		Settings
		Quit
#endif
}

static void ui_pause() {
	ImVec2 window_size = {400, 100};
	ui_center_window(window_size);
	ImGui::Begin(ui_i18n_get("csp"), &ui_state.show_pause,
				 ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoMove|ImGuiWindowFlags_NoCollapse);

    ImVec2 buttonSize(100.0f, 30.0f);
    float buttonSpacing = ImGui::GetStyle().ItemSpacing.x;
    float totalWidth = (buttonSize.x * 2) + buttonSpacing;
    ImVec2 contentRegion = ImGui::GetContentRegionAvail();
    float offsetX = (contentRegion.x - totalWidth) / 2.0f;
    float offsetY = (contentRegion.y - buttonSize.y) / 2.0f;
    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + offsetY);
    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + offsetX);

    if (ImGui::Button("Resume", buttonSize)) {
    }

    ImGui::SameLine();
    if (ImGui::Button("Main menu", buttonSize)) {
		ui_screen_current = ui_screen_main;
    }

	ImGui::End();
}

void ui_screen_pause() {
	if(ui_state.show_pause) {
		ui_pause_toolbar();
		ui_pause();
	}
}
