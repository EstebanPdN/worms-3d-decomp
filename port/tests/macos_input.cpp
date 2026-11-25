// Real SDL virtual-device path: catches physical/Nintendo layout and signed-axis regressions.
#include "../platform/macos/controller_input.h"
#include "../platform/macos/dual_layout.h"
#include <assert.h>
#include <stdio.h>
#include <utility>
#include <initializer_list>
using namespace w3d::plat;
int main() {
    assert(SDL_Init(SDL_INIT_GAMEPAD));
    SDL_VirtualJoystickDesc d; SDL_INIT_INTERFACE(&d);
    d.type = SDL_JOYSTICK_TYPE_GAMEPAD; d.naxes = SDL_GAMEPAD_AXIS_COUNT;
    d.nbuttons = SDL_GAMEPAD_BUTTON_COUNT; d.name = "W3D input test";
    d.button_mask = (1u << SDL_GAMEPAD_BUTTON_COUNT) - 1;
    d.axis_mask = (1u << SDL_GAMEPAD_AXIS_COUNT) - 1;
    SDL_JoystickID id = SDL_AttachVirtualJoystick(&d); assert(id);
    SDL_Gamepad *g = SDL_OpenGamepad(id); assert(g);
    SDL_Joystick *j = SDL_GetGamepadJoystick(g);
    const SDL_GamepadButton buttons[] = {SDL_GAMEPAD_BUTTON_EAST, SDL_GAMEPAD_BUTTON_SOUTH, SDL_GAMEPAD_BUTTON_NORTH, SDL_GAMEPAD_BUTTON_WEST, SDL_GAMEPAD_BUTTON_START, SDL_GAMEPAD_BUTTON_LEFT_SHOULDER, SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER};
    const unsigned game[] = {0x100,0x200,0x400,0x800,0x1000,0x40,0x20};
    const unsigned ui[] = {1,2,4,8,16,64,128};
    for (int i=0;i<7;i++) {
        assert(SDL_SetJoystickVirtualButton(j, buttons[i], true)); SDL_UpdateGamepads();
        Pad p=controller_read(g,true); assert(p.buttons & game[i]); assert(controller_ui(p,false)&ui[i]);
        assert(SDL_SetJoystickVirtualButton(j, buttons[i], false)); SDL_UpdateGamepads();
        assert(!(controller_read(g,true).buttons & game[i]));
    }
    assert(controller_ui(controller_read(g,true),true)&32);
    assert(SDL_SetJoystickVirtualAxis(j, SDL_GAMEPAD_AXIS_LEFTX, -32768)); SDL_UpdateGamepads();
    Pad p=controller_read(g,true); assert(p.stick_x==-100); assert(controller_ui(p,false)&1024);
    assert(SDL_SetJoystickVirtualAxis(j, SDL_GAMEPAD_AXIS_LEFTX, 2000)); SDL_UpdateGamepads();
    assert(controller_read(g,true).stick_x==0);
    for (auto size : {std::pair<int,int>{800,960}, {240,300}, {2000,900}}) {
        DualLayout l(size.first,size.second); int x,y;
        assert(l.touch(l.x+200*l.scale,l.y+360*l.scale,x,y)); assert(x==160&&y==120);
        assert(!l.touch(l.x+39.9*l.scale,l.y+300*l.scale,x,y));
        assert(!l.touch(l.x+200*l.scale,l.y+239.9*l.scale,x,y));
    }
    SDL_CloseGamepad(g); SDL_DetachVirtualJoystick(id); SDL_Quit();
    puts("PASS: SDL gamepad buttons/release, UI mapping, deadzone, negative axis, touch bounds at three window sizes");
}
