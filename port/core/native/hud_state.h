// Read-only snapshot shared by the game bridge and the two platform renderers.
#pragma once
struct W3dHudTeam { int used, total, maximum, colour, cpu; char name[64]; };
struct W3dHudDot { float x, y; int visible; };
struct W3dHud {
    int in_match, clock_mode, turn_ms, round_ms, hotseat_ms, active_worm, active_team;
    float wind_speed, wind_max, wind_dir, wind_anim;   // wind_anim: Wind.AnimScaler (velocidad del rotor de la veleta)
    W3dHudTeam teams[4];
    unsigned match_ms;
    int health, weapon, icon, can_aim, charged, charging;
    float elevation, power, wind_yaw;
    W3dHudDot dots[16];
    unsigned char worm_team[16];
};
extern "C" int w3d_hud_read(W3dHud *);
extern "C" int w3d_ui_panel_active();
