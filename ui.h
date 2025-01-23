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

extern bool g_show_main;
extern const float g_window_margin;
extern bool g_show_settings;
extern bool g_show_tutorials;
extern bool g_show_missions;
extern bool g_show_multiplayer;
extern bool g_show_help;

extern char g_username[50];
extern float g_sound_volume;
extern char g_server_listen_ip[30];
extern char g_server_listen_port[30];
