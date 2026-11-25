#pragma once
#include <SDL3/SDL.h>
#include "../platform.h"

namespace w3d { namespace plat {
inline int controller_axis(int v) {
    const int dead = 5000;
    int a = v < 0 ? -v : v;
    if (a <= dead) return 0;
    int scaled = (a - dead) * 100 / (32767 - dead);
    if (scaled > 100) scaled = 100;
    return v < 0 ? -scaled : scaled;
}
// Physical Nintendo layout in dual-screen mode; legacy desktop layout otherwise.
inline Pad controller_read(SDL_Gamepad *g, bool dual) {
    Pad p = {};
    if (!g || !SDL_GamepadConnected(g)) return p;
    p.connected = true;
    auto button = [&](SDL_GamepadButton b, unsigned gc) {
        if (SDL_GetGamepadButton(g, b)) p.buttons |= gc;
    };
    button(SDL_GAMEPAD_BUTTON_EAST, dual ? 0x100 : 0x200);
    button(SDL_GAMEPAD_BUTTON_SOUTH, dual ? 0x200 : 0x100);
    button(SDL_GAMEPAD_BUTTON_NORTH, dual ? 0x400 : 0x800);
    button(SDL_GAMEPAD_BUTTON_WEST, dual ? 0x800 : 0x400);
    button(SDL_GAMEPAD_BUTTON_START, 0x1000);
    button(SDL_GAMEPAD_BUTTON_DPAD_UP, 8); button(SDL_GAMEPAD_BUTTON_DPAD_DOWN, 4);
    button(SDL_GAMEPAD_BUTTON_DPAD_LEFT, 1); button(SDL_GAMEPAD_BUTTON_DPAD_RIGHT, 2);
    int l = SDL_GetGamepadAxis(g, SDL_GAMEPAD_AXIS_LEFT_TRIGGER);
    int r = SDL_GetGamepadAxis(g, SDL_GAMEPAD_AXIS_RIGHT_TRIGGER);
    if (dual) {
        button(SDL_GAMEPAD_BUTTON_LEFT_SHOULDER, 0x40);
        button(SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER, 0x20);
        if (l > 16000 || r > 16000) p.buttons |= 0x10;
        p.trigger_l = p.buttons & 0x40 ? 255 : 0;
        p.trigger_r = p.buttons & 0x20 ? 255 : 0;
    } else {
        button(SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER, 0x10);
        p.trigger_l = l > 0 ? l / 129 : 0; p.trigger_r = r > 0 ? r / 129 : 0;
        if (p.trigger_l > 200) p.buttons |= 0x40;
        if (p.trigger_r > 200) p.buttons |= 0x20;
    }
    p.stick_x = controller_axis(SDL_GetGamepadAxis(g, SDL_GAMEPAD_AXIS_LEFTX));
    p.stick_y = -controller_axis(SDL_GetGamepadAxis(g, SDL_GAMEPAD_AXIS_LEFTY));
    p.cstick_x = (dual ? -1 : 1) * controller_axis(SDL_GetGamepadAxis(g, SDL_GAMEPAD_AXIS_RIGHTX));
    p.cstick_y = (dual ? 1 : -1) * controller_axis(SDL_GetGamepadAxis(g, SDL_GAMEPAD_AXIS_RIGHTY));
    return p;
}
inline unsigned controller_ui(const Pad &p, bool select) {
    unsigned b = select ? 32 : 0;
    const unsigned gc[] = {0x100,0x200,0x400,0x800,0x1000,0x40,0x20,8,4,1,2};
    const unsigned ui[] = {1,2,4,8,16,64,128,256,512,1024,2048};
    for (int i = 0; i < 11; ++i) if (p.buttons & gc[i]) b |= ui[i];
    if (p.stick_x < -45) b |= 1024;
    if (p.stick_x > 45) b |= 2048;
    if (p.stick_y > 45) b |= 256;
    if (p.stick_y < -45) b |= 512;
    return b;
}
}}
