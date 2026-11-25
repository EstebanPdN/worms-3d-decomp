#include "w3d_ptr.h"
#line 1 "d24g_mode_start_8006af38.cpp"
/* Worms 3D GameCube PAL 0x8006af38. Starts the next application mode: logs FCS:Init with a counter, releases the press-start text, ends an in-game mode, reports Loading Resources, loads the assets flagged by 0x8006ac90 (pausing the session when the mode has a slot table entry), posts one pending message on flag 0x08000000, resets three cameras from the shared vectors, then per mode (license, publisher logo, Team17 logo, memory card check, W3D logo, title screen, main menu, in game, award movie, unlock, custom) shows its screen and sets its state, resumes and finishes. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct String;
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
extern "C" void string_init_8020c5c0(Ptr32<String>);
extern "C" Ptr32<unsigned short> string_header_80341884(Ptr32<String>);
struct String {
    Ptr32<char> text;
    String();
    String(const String &o) {
        string_init_8020c5c0(this);
        text = o.text;
        ++*string_header_80341884(this);
    }
    ~String() { string_finish_8020c5c4(this); string_release_80341588(this); }
};
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Message { unsigned short id; Ptr32<const void> vtable; };
struct Object;
struct ObjectVtable { Ptr32<void> u[4]; Ptr32<void (Ptr32<Object>)> release; };
struct Object { Ptr32<ObjectVtable> vtable; };
struct Camera {
    struct V { Ptr32<void> u[11]; Ptr32<int (Ptr32<Camera>, Ptr32<void>)> set_a; Ptr32<int (Ptr32<Camera>, Ptr32<void>)> set_b; Ptr32<int (Ptr32<Camera>, Ptr32<void>)> set_c; }; Ptr32<struct V> vtable;
};
struct App { char u0[48]; Ptr32<Camera> a; char u52[84]; Ptr32<Camera> b; Ptr32<Camera> c; };
struct Stage { struct V { Ptr32<void> u[18]; Ptr32<void (Ptr32<Stage>)> step; }; Ptr32<struct V> vtable; };
struct Context { char u[52]; int time; };
struct Monitor { char u[248]; unsigned flags; };
struct Self { char u0[20]; unsigned id; char u24[184]; int state; int mode; char u216[20]; int waitUntil; unsigned flags; char u244[12]; Ptr32<Object> text; };
extern Ptr32<void> g_804b17f0;
extern Ptr32<App> app_804b1788;
extern Ptr32<void> arena_804b1754;
extern Ptr32<void> service_804b178c;
extern char vt_8040db38[];
extern char pos_8045e788[], pos_8045e7ac[], pos_8045e7a0[];
extern unsigned char t_804100a8[], t_80410aa0[];
extern int count_804aaac0[1];
extern MessageCache msg_804ad814, msg_804ad77c, msg_804ad754, msg_804ad74c, msg_804ad79c;
extern const char s_8037bbcc[], s_8037bbd8[], s_8037bbec[], s_8037bc20[], s_8037bc5c[], s_8037bc94[], s_8037bcd4[], s_8037bd04[], s_8037bb14[], s_8037bd3c[], s_8037bd44[], s_8037bd74[], s_8037bda4[], s_8037bdb4[], s_8037bdec[], s_8037be00[];
extern "C" Ptr32<Stage> stage_80160e2c(Ptr32<void>);
extern "C" void string_format_8020c510(Ptr32<String>, Ptr32<const char>, ...);
extern "C" void progress_80207ca4(Ptr32<const char>);
extern "C" void end_load_8006d550(Ptr32<Self>);
extern "C" void maintain_8006e6c8(Ptr32<Self>);
extern "C" Ptr32<int> flags_8006ac90(Ptr32<Self>);
extern "C" Ptr32<void> slot_table_8006bcd0(int);
extern "C" void pause_80069c14();
extern "C" void resume_80069c54();
extern "C" void load_assets_8006be14(Ptr32<Self>, Ptr32<int>);
extern "C" Ptr32<Context> context_80165254();
extern "C" int message_id_8015f5a0(Ptr32<MessageCache>, int);
extern "C" Ptr32<void> arena_alloc_801613f0(Ptr32<void>, int);
extern "C" int message_post_8016239c(Ptr32<void>);
extern "C" Ptr32<void> message_string_8010a8e0(Ptr32<void>, int, Ptr32<const char>);
extern "C" void show_b53c_8006b53c(Ptr32<Self>);
extern "C" void show_b5fc_8006b5fc(Ptr32<Self>);
extern "C" void show_b6bc_8006b6bc(Ptr32<Self>);
extern "C" void show_b77c_8006b77c(Ptr32<Self>);
extern "C" void show_b8a0_8006b8a0(Ptr32<Self>);
extern "C" Ptr32<Monitor> monitor_800c8120();
extern "C" void step_800a7ea0();
extern "C" Ptr32<void> type_8020b680(Ptr32<void>);
extern "C" Ptr32<void> create_80164514(Ptr32<void>, Ptr32<void>, unsigned);
extern "C" void pause_800fde38();
extern "C" void round_reset_8006e6f4(Ptr32<Self>, int);
extern "C" void main_menu_8006ba08(Ptr32<Self>);
extern "C" void ingame_8006e004(Ptr32<Self>, int);
extern "C" void game_start_8006cecc(Ptr32<Self>, Ptr32<void>);
extern "C" void press_start_8006ef24(Ptr32<Self>);
extern "C" void finish_8006eebc(Ptr32<Self>);
#define POST_TEXT(cache, text) { \
    void *m = arena_alloc_801613f0(arena_804b1754, 12); \
    message_post_8016239c(message_string_8010a8e0(m, (unsigned short)message_id_8015f5a0(cache, 1), text)); \
}
#define POST(cache) { \
    Message *m = (Message *)arena_alloc_801613f0(arena_804b1754, 8); \
    m->id = message_id_8015f5a0(cache, 1); \
    m->vtable = vt_8040db38; \
    message_post_8016239c(m); \
}
#define CREATE(t) { void *type = type_8020b680(t); create_80164514(service_804b178c, type, self->id); }
#define CAMERA(c) { Camera *cam = c; cam->vtable->set_a(cam, pos_8045e788); cam->vtable->set_b(cam, pos_8045e7ac); cam->vtable->set_c(cam, pos_8045e7a0); }
extern "C" void w3d_fe_mode_started(int mode, unsigned *flow_flags);   // core/native/fe_bridge.cpp (v28): arranque y título para la UI de 3DS
extern "C" void w3d_d24g_mode_start_8006af38(Ptr32<Self> self)
{
    w3d_fe_mode_started(self->mode, &self->flags);
    Ptr32<Stage> stage = stage_80160e2c(g_804b17f0);
    String s;
    string_format_8020c510(&s, s_8037bbcc, count_804aaac0[0]++);
    progress_80207ca4(s.text);
    { String copy(s); }
    if (self->text) self->text->vtable->release(self->text);
    self->text = 0;
    if ((unsigned)(self->state - 6) <= 1) {
        end_load_8006d550(self);
        maintain_8006e6c8(self);
    }
    progress_80207ca4(s_8037bbd8);
    Ptr32<int> flags = flags_8006ac90(self);
    Ptr32<void> slot = slot_table_8006bcd0(self->mode);
    if (slot) pause_80069c14();
    load_assets_8006be14(self, flags);
    if (self->flags & 0x08000000) {
        POST(&msg_804ad814)
        self->flags = (self->flags | 0x10000000) & ~0x08000000;
    }
    CAMERA(app_804b1788->a)
    CAMERA(app_804b1788->b)
    CAMERA(app_804b1788->c)
    int mode = self->mode;
    switch (mode) {
    case 0:
        progress_80207ca4(s_8037bbec);
        self->flags &= ~0x00200000;
        { int time = context_80165254()->time; self->state = mode; self->waitUntil = time + 3000; }
        break;
    case 1:
        progress_80207ca4(s_8037bc20);
        self->flags &= ~0x00200000;
        show_b53c_8006b53c(self);
        break;
    case 2:
        progress_80207ca4(s_8037bc5c);
        self->flags &= ~0x00200000;
        show_b5fc_8006b5fc(self);
        monitor_800c8120()->flags |= 0x08000000;
        break;
    case 4:
        progress_80207ca4(s_8037bc94);
        self->flags &= ~0x00200000;
        POST(&msg_804ad77c)
        self->state = mode;
        break;
    case 3:
        progress_80207ca4(s_8037bcd4);
        self->flags &= ~0x00200000;
        show_b6bc_8006b6bc(self);
        break;
    case 5:
        progress_80207ca4(s_8037bd04);
        self->flags &= ~0x00200000;
        if (stage) stage->vtable->step(stage);
        step_800a7ea0();
        POST_TEXT(&msg_804ad754, s_8037bb14)
        POST_TEXT(&msg_804ad74c, s_8037bd3c)
        CREATE(t_804100a8)
        CREATE(t_80410aa0)
        self->state = mode;
        break;
    case 6:
        progress_80207ca4(s_8037bd44);
        self->flags &= ~0x00200000;
        pause_800fde38();
        round_reset_8006e6f4(self, 6);
        main_menu_8006ba08(self);
        break;
    case 7:
        progress_80207ca4(s_8037bd74);
        self->state = mode;
        round_reset_8006e6f4(self, 7);
        ingame_8006e004(self, 0);
        game_start_8006cecc(self, 0);
        POST_TEXT(&msg_804ad79c, s_8037bda4)
        if (self->flags & 0x00200000)
            press_start_8006ef24(self);
        break;
    case 8:
        progress_80207ca4(s_8037bdb4);
        self->flags &= ~0x00200000;
        show_b77c_8006b77c(self);
        break;
    case 9:
        progress_80207ca4(s_8037bdec);
        self->flags &= ~0x00200000;
        show_b8a0_8006b8a0(self);
        break;
    case 10:
        progress_80207ca4(s_8037be00);
        self->state = mode;
        self->flags &= ~0x00200000;
        break;
    }
    if (slot) resume_80069c54();
    finish_8006eebc(self);
}


