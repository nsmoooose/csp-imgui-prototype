#pragma once

void ui_render();

void ui_main_menu();
void ui_settings_menu();
void ui_tutorials_menu();
void ui_missions_menu();
void ui_multiplayer_menu();
void ui_help_menu();

void ui_theme_gray();

void ui_center_window_with_margin(float margin);

struct ui_state {
	ui_state();

	bool show_main;
	bool show_settings;
	bool show_tutorials;
	bool show_missions;
	bool show_multiplayer;
	bool show_help;

	char username[50];
	float sound_volume;
	char server_listen_ip[30];
	char server_listen_port[30];

	float window_margin;
};

extern struct ui_state ui_state;

extern char g_username[50];
extern float g_sound_volume;
extern char g_server_listen_ip[30];
extern char g_server_listen_port[30];
