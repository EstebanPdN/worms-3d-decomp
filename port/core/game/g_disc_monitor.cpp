#include "w3d_ptr.h"
#line 1 "g_disc_monitor.cpp"
/* Disc status monitor and two small logic entities (0x800c6d20..0x800c88c4).
 *
 * Names are inferred from behavior; no original symbols survive.
 * Disc monitor (type 0x80360ae0, 252 bytes, also a function-local static at
 * 0x8043e464): +0x1c state (0..5), +0x20 eight 20-byte message entries,
 * +0xc0 eight held objects, +0xe0 entry count, +0xe4 start time,
 * +0xe8 animation phase, +0xec..+0xf4 held objects, +0xf8 flag bits.
 * States 1..5 look up "NGC.Disc.*" message texts; other states hide the panel.
 */
#include "g_types2.h"

/* Name argument passed by reference to the settings lookups. */
struct W3dGName {
    Ptr32<const char> text;
    template <class W3dU> W3dGName(Ptr32<W3dU> w3d_p) : W3dGName((const char *)w3d_p.get()) {}
 W3dGName(const char *name) : text(name) {}
};

extern "C" {

typedef struct W3dGDiscEntry {
    float a;
    float b;
    float c;
    int d;
    unsigned char unknown_10[4];
} W3dGDiscEntry;

typedef struct W3dGDiscFlags {
    unsigned int unknown_5:27; unsigned int flag_4:1; unsigned int frozen:1; unsigned int busy:1; unsigned int flag_1:1; unsigned int flag_0:1;
} W3dGDiscFlags;

typedef struct W3dGScreen W3dGScreen;
typedef struct W3dGScreenVtbl {
    Ptr32<void> unknown_00[16];
    Ptr32<void (Ptr32<W3dGScreen>, int)> present;
} W3dGScreenVtbl;
typedef struct W3dGScreenFlags {
    unsigned int unknown_4:28; unsigned int flag_3:1; unsigned int unknown_0:3;
} W3dGScreenFlags;
struct W3dGScreen {
    Ptr32<W3dGScreenVtbl> vtbl;
    unsigned char unknown_04[0x4c - 0x04];
    W3dGScreenFlags flags;
};

typedef struct W3dLogic_80360ae0 {
    Ptr32<void> vtable;
    unsigned short references;
    unsigned char unknown_06[0x1c - 0x06];
    int state;
    W3dGDiscEntry entries[8];
    Ptr32<W3dGIface> held[8];
    int count;
    unsigned int start_time;
    int phase;
    Ptr32<W3dGIface> held_ec;
    Ptr32<W3dGIface> panel;
    Ptr32<W3dGIface> held_f4;
    W3dGDiscFlags flags;
} W3dLogic_80360ae0;

typedef struct W3dLogic_80360b10 {
    Ptr32<void> vtable;
    unsigned short references;
    unsigned char unknown_06[0x1c - 0x06];
} W3dLogic_80360b10;

typedef struct W3dLogic_80360b40 {
    Ptr32<void> vtable;
    unsigned short references;
    unsigned char unknown_06[0x1c - 0x06];
} W3dLogic_80360b40;

extern W3dLogicType w3d_logic_type_80360ae0;
extern W3dLogicType w3d_logic_type_80360b10;
extern W3dLogicType w3d_logic_type_80360b40;
extern unsigned char w3d_vtable_8040faa8[];
extern unsigned char w3d_vtable_8040fae8[];
extern W3dLogic_80360ae0 w3d_disc_monitor_8043e464;
extern int w3d_disc_monitor_ready_804ae7f8;
extern Ptr32<W3dGScreen> w3d_game_804b1788;
extern W3dGCachedMessage w3d_message_804ae80c;
extern const float w3d_f32_80387a5c[];
extern const char w3d_str_80387984[];
extern const char w3d_str_80387998[];
extern const char w3d_str_803879a8[];
extern const char w3d_str_803879bc[];

void w3d_lookup_text_800fc2b0(const W3dGName &name, Ptr32<Ptr32<const char>> value);
void w3d_disc_show_800c71f8(Ptr32<W3dLogic_80360ae0> monitor, Ptr32<const char> text);
void w3d_disc_hide_800c770c(Ptr32<W3dLogic_80360ae0> monitor);
void w3d_disc_animate_800c7ff4(Ptr32<W3dLogic_80360ae0> monitor);
unsigned int w3d_time_now_801fe45c(void);
int w3d_panel_set_frame_80173f88(Ptr32<W3dGIface> panel, Ptr32<unsigned char> frame);
void w3d_disc_monitor_destroy_800c6cf4(void);
int atexit(Ptr32<void (void)> function);
int w3d_message_is_8015f620(Ptr32<W3dGCachedMessage> message, unsigned int id);
void w3d_logic_hook_800c8e90(Ptr32<W3dLogic_80360b40> object);
void w3d_logic_hook_800c88c4(Ptr32<W3dLogic_80360b40> object);

}


extern "C" {

}

/* Passes an animation frame to a panel by address. */
static inline void w3d_panel_show_frame(Ptr32<W3dGIface> panel, unsigned char frame)
{
    w3d_panel_set_frame_80173f88(panel, &frame);
}

extern "C" {

Ptr32<W3dLogicType> w3d_logic_type_get_800c6d20(void)
{
    return &w3d_logic_type_80360ae0;
}

void w3d_logic_unlink_800c6d2c(Ptr32<W3dLogic_80360ae0> object)
{
    w3d_owner_list_remove(&w3d_logic_type_80360ae0, &object->references);
    w3d_logic_type_80360ae0.count--;
}

Ptr32<W3dLogic_80360ae0> w3d_logic_construct_800c6e44(Ptr32<W3dLogic_80360ae0> object);
Ptr32<W3dLogic_80360ae0> w3d_logic_create_800c6d70(void)
{
    Ptr32<W3dLogic_80360ae0> object = w3d_logic_construct_800c6e44((Ptr32<W3dLogic_80360ae0>)w3d_heap_allocate_entry_a(252));
    w3d_state_register(&w3d_logic_type_80360ae0, object ? w3d::R(&object->references) : 0);
    w3d_logic_type_80360ae0.count++;
    return object;
}

void w3d_logic_unlink_800c6d2c(Ptr32<W3dLogic_80360ae0> object);
void w3d_logic_destroy_800c6f20(Ptr32<W3dLogic_80360ae0> object, int flags);
unsigned short w3d_logic_release_800c6dd0(Ptr32<W3dLogic_80360ae0> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_logic_unlink_800c6d2c(object);
        if (object)
            w3d_logic_destroy_800c6f20(object, 3);
    }
    return remaining;
}

unsigned short w3d_logic_retain_800c6e2c(Ptr32<W3dLogic_80360ae0> object)
{
    return object->references++;
}

#if 0 /* 0x800c6e44: the original keeps a reload-and-release of a just-cleared slot and a forward array loop; 2 attempts */
W3dLogic_80360ae0 *w3d_logic_construct_800c6e44(W3dLogic_80360ae0 *object)
{
    int index;
    w3d_logic_base_init_801628b0(object);
    object->vtable = w3d_vtable_8040faa8;
    for (index = 0; index < 8; index++)
        object->held[index] = 0;
    object->panel = 0;
    object->state = 0;
    object->held_f4 = 0;
    object->held_ec = 0;
    object->start_time = 0;
    if (object->panel)
        object->panel->vtbl->release(object->panel);
    object->panel = 0;
    for (index = 0; index < 8; index++) {
        if (object->held[index])
            object->held[index]->vtbl->release(object->held[index]);
        object->held[index] = 0;
    }
    object->count = 0;
    object->flags.flag_0 = 0;
    object->flags.flag_1 = 0;
    object->flags.busy = 0;
    object->flags.flag_4 = 0;
    return object;
}
#endif

void w3d_logic_hook_800c70dc(Ptr32<W3dLogic_80360ae0> object);
void w3d_logic_hook_800c70e0(Ptr32<W3dLogic_80360ae0> object);
int w3d_logic_handle_800c704c(Ptr32<W3dLogic_80360ae0> object, Ptr32<W3dGMessage> message)
{
    switch (message->id) {
    case 64:
        if (w3d_logic_base_handle_8016293c(object, message) >= 0) {
            w3d_logic_hook_800c70dc(object);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_logic_hook_800c70e0(object);
        break;
    }
    return w3d_logic_base_handle_8016293c(object, message);
}

int w3d_logic_kind_800c70d4(void)
{
    return -1;
}

void w3d_logic_hook_800c70dc(Ptr32<W3dLogic_80360ae0> object)
{
}

void w3d_logic_hook_800c70e0(Ptr32<W3dLogic_80360ae0> object)
{
}

#if 0 /* 0x800c70e4: frame layout matches; only the r3/r4 address set-up order in each case differs (4 attempts) */
void w3d_disc_set_state_800c70e4(W3dLogic_80360ae0 *monitor, int state)
{
    if (!monitor->flags.busy) {
        w3d_disc_animate_800c7ff4(monitor);
        if (state != monitor->state) {
            const char *text;
            monitor->state = state;
            switch (state) {
            case 1:
                w3d_lookup_text_800fc2b0(W3dGName(w3d_str_80387984), &text);
                w3d_disc_show_800c71f8(monitor, text);
                break;
            case 2:
                w3d_lookup_text_800fc2b0(W3dGName(w3d_str_80387998), &text);
                w3d_disc_show_800c71f8(monitor, text);
                break;
            case 3:
                w3d_lookup_text_800fc2b0(W3dGName(w3d_str_80387998), &text);
                w3d_disc_show_800c71f8(monitor, text);
                break;
            case 4:
                w3d_lookup_text_800fc2b0(W3dGName(w3d_str_803879a8), &text);
                w3d_disc_show_800c71f8(monitor, text);
                break;
            case 5:
                w3d_lookup_text_800fc2b0(W3dGName(w3d_str_803879bc), &text);
                w3d_disc_show_800c71f8(monitor, text);
                break;
            case 0:
            default:
                w3d_disc_hide_800c770c(monitor);
                break;
            }
        }
    }
}
#endif

Ptr32<W3dGDiscEntry> w3d_disc_add_entry_800c7c40(Ptr32<W3dLogic_80360ae0> monitor)
{
    Ptr32<W3dGDiscEntry> entry = &monitor->entries[monitor->count];
    entry->a = w3d_f32_80387a5c[0];
    entry->b = w3d_f32_80387a5c[0];
    entry->c = w3d_f32_80387a5c[0];
    entry->d = 0;
    monitor->count++;
    return entry;
}

void w3d_screen_present_three_800c7c84(void)
{
    Ptr32<W3dGScreen> screen = w3d_game_804b1788;
    int pass;
    for (pass = 0; pass < 3; pass++)
        screen->vtbl->present(screen, 0);
}

void w3d_disc_set_flag1_800c7fe4(Ptr32<W3dLogic_80360ae0> monitor, unsigned int value)
{
    monitor->flags.flag_1 = value;
}

void w3d_disc_animate_800c7ff4(Ptr32<W3dLogic_80360ae0> monitor)
{
    if (monitor->panel && !monitor->flags.frozen) {
        Ptr32<W3dGScreen> screen = w3d_game_804b1788;
        int phase = (w3d_time_now_801fe45c() - monitor->start_time) / 50 % 4;
        w3d_panel_show_frame(monitor->panel, phase);
        if (phase != monitor->phase) {
            monitor->flags.busy = 1;
            screen->flags.flag_3 = 0;
            screen->vtbl->present(screen, 0);
            monitor->phase = phase;
            screen->flags.flag_3 = 1;
            monitor->flags.busy = 0;
        }
    }
}

Ptr32<W3dLogic_80360ae0> w3d_disc_monitor_instance_800c8120(void)
{
    if (!w3d_disc_monitor_ready_804ae7f8) {
        w3d_logic_construct_800c6e44(&w3d_disc_monitor_8043e464);
        w3d_disc_monitor_ready_804ae7f8 = 1;
        atexit(w3d_disc_monitor_destroy_800c6cf4);
    }
    return &w3d_disc_monitor_8043e464;
}

Ptr32<W3dLogicType> w3d_logic_type_get_800c819c(void)
{
    return &w3d_logic_type_80360b10;
}

void w3d_logic_unlink_800c81a8(Ptr32<W3dLogic_80360b10> object)
{
    w3d_owner_list_remove(&w3d_logic_type_80360b10, &object->references);
    w3d_logic_type_80360b10.count--;
}

Ptr32<W3dLogic_80360b10> w3d_logic_construct_800c82c0(Ptr32<W3dLogic_80360b10> object);
Ptr32<W3dLogic_80360b10> w3d_logic_create_800c81ec(void)
{
    Ptr32<W3dLogic_80360b10> object = w3d_logic_construct_800c82c0((Ptr32<W3dLogic_80360b10>)w3d_heap_allocate_entry_a(28));
    w3d_state_register(&w3d_logic_type_80360b10, object ? w3d::R(&object->references) : 0);
    w3d_logic_type_80360b10.count++;
    return object;
}

void w3d_logic_unlink_800c81a8(Ptr32<W3dLogic_80360b10> object);
void w3d_logic_destroy_800c82fc(Ptr32<W3dLogic_80360b10> object, int flags);
unsigned short w3d_logic_release_800c824c(Ptr32<W3dLogic_80360b10> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_logic_unlink_800c81a8(object);
        if (object)
            w3d_logic_destroy_800c82fc(object, 3);
    }
    return remaining;
}

unsigned short w3d_logic_retain_800c82a8(Ptr32<W3dLogic_80360b10> object)
{
    return object->references++;
}

Ptr32<W3dLogic_80360b10> w3d_logic_construct_800c82c0(Ptr32<W3dLogic_80360b10> object)
{
    w3d_logic_base_init_801628b0(object);
    object->vtable = w3d_vtable_8040fae8;
    return object;
}

void w3d_logic_destroy_800c82fc(Ptr32<W3dLogic_80360b10> object, int flags)
{
    object->vtable = w3d_vtable_8040fae8;
    w3d_logic_base_destroy_801628ec(object, flags);
}

void w3d_logic_hook_800c83bc(Ptr32<W3dLogic_80360b10> object);
void w3d_logic_hook_800c83c0(Ptr32<W3dLogic_80360b10> object);
int w3d_logic_handle_800c832c(Ptr32<W3dLogic_80360b10> object, Ptr32<W3dGMessage> message)
{
    switch (message->id) {
    case 64:
        if (w3d_logic_base_handle_8016293c(object, message) >= 0) {
            w3d_logic_hook_800c83bc(object);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_logic_hook_800c83c0(object);
        break;
    }
    return w3d_logic_base_handle_8016293c(object, message);
}

int w3d_logic_query_800c83b4(void)
{
    return 0;
}

void w3d_logic_hook_800c83bc(Ptr32<W3dLogic_80360b10> object)
{
}

void w3d_logic_hook_800c83c0(Ptr32<W3dLogic_80360b10> object)
{
}

Ptr32<W3dLogicType> w3d_logic_type_get_800c8450(void)
{
    return &w3d_logic_type_80360b40;
}

void w3d_logic_unlink_800c845c(Ptr32<W3dLogic_80360b40> object)
{
    w3d_owner_list_remove(&w3d_logic_type_80360b40, &object->references);
    w3d_logic_type_80360b40.count--;
}

Ptr32<W3dLogic_80360b40> w3d_logic_construct_800c8574(Ptr32<W3dLogic_80360b40> object);
Ptr32<W3dLogic_80360b40> w3d_logic_create_800c84a0(void)
{
    Ptr32<W3dLogic_80360b40> object = w3d_logic_construct_800c8574((Ptr32<W3dLogic_80360b40>)w3d_heap_allocate_entry_a(384));
    w3d_state_register(&w3d_logic_type_80360b40, object ? w3d::R(&object->references) : 0);
    w3d_logic_type_80360b40.count++;
    return object;
}

void w3d_logic_unlink_800c845c(Ptr32<W3dLogic_80360b40> object);
void w3d_logic_destroy_800c8630(Ptr32<W3dLogic_80360b40> object, int flags);
unsigned short w3d_logic_release_800c8500(Ptr32<W3dLogic_80360b40> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_logic_unlink_800c845c(object);
        if (object)
            w3d_logic_destroy_800c8630(object, 3);
    }
    return remaining;
}

unsigned short w3d_logic_retain_800c855c(Ptr32<W3dLogic_80360b40> object)
{
    return object->references++;
}

int w3d_logic_handle_800c883c(Ptr32<W3dLogic_80360b40> object, Ptr32<W3dGMessage> message)
{
    unsigned short id = message->id;
    if (id == 64) {
        if (w3d_actor_handle_8015fb34(object, message) >= 0) {
            w3d_logic_hook_800c8e90(object);
            return 0;
        }
        return 0x80004005;
    }
    if (w3d_message_is_8015f620(&w3d_message_804ae80c, id))
        w3d_logic_hook_800c88c4(object);
    return w3d_actor_handle_8015fb34(object, message);
}

void w3d_logic_hook_800c88c4(Ptr32<W3dLogic_80360b40> object)
{
}

}


