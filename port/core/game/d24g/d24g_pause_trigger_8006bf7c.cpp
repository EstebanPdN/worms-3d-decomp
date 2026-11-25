#include "w3d_ptr.h"
#line 1 "d24g_pause_trigger_8006bf7c.cpp"
/* Worms 3D GameCube PAL 0x8006bf7c. Opens the pause menu: unless paused flags 0x00800000 or 0x00400000 are set or the scene timer is one, sets 0x00400000; in state 7 posts the pause messages, sets 0x00800000, selects the Menu slot, picks Pause or SpectatorPause by network team value, enters the application pause state and stops its sound when not spectating, and posts the menu name and FE.PauseMenu. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct String;
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
extern "C" Ptr32<void> string_assign_8020bd38(Ptr32<String>, Ptr32<const char>);
struct String {
    Ptr32<char> text;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    ~String() { string_finish_8020c5c4(this); string_release_80341588(this); }
    String(const String &);
};
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Message { unsigned short id; Ptr32<const void> vtable; };
struct Message12;
struct Sound { struct V { Ptr32<void> u[9]; Ptr32<void (Ptr32<Sound>, int)> stop; }; Ptr32<struct V> vtable; };
struct App { char u[108]; Ptr32<Sound> sound; };
struct Inner { char u[24]; Ptr32<void> team; };
struct Network { char u[36]; Ptr32<Inner> inner; };
struct Self { char u0[208]; int state; char u212[28]; unsigned flags; };
extern "C" int message_id_8015f5a0(Ptr32<MessageCache>, int);
extern "C" Ptr32<void> arena_alloc_801613f0(Ptr32<void>, int);
extern "C" int message_post_8016239c(Ptr32<void>);
extern "C" Ptr32<void> message_string_8010a8e0(Ptr32<void>, int, Ptr32<const char>);
extern "C" int timer_is_one_8006e71c(Ptr32<Self>);
extern "C" int select_slot_800a7e14(int, Ptr32<const char>);
extern "C" int team_value_8021eb00(Ptr32<void>);
extern "C" void pause_800fde38();
extern "C" void app_enter_80129878(Ptr32<App>);
extern Ptr32<void> arena_804b1754;
extern char vt_8040db38[];
extern Ptr32<App> app_804b1788;
extern Ptr32<Network> network_804abac0;
extern MessageCache msg_804ad85c, msg_804ad834, msg_804ad7f4, msg_804ad73c, msg_804ad80c, msg_804ad7fc;
extern const char s_8037bd3c[], s_8037bed4[], s_8037bedc[], s_8037beec[];
inline void post(Ptr32<MessageCache> cache) {
    Ptr32<Message> m = (Ptr32<Message>)arena_alloc_801613f0(arena_804b1754, 8);
    m->id = message_id_8015f5a0(cache, 1);
    m->vtable = vt_8040db38;
    message_post_8016239c(m);
}
#define POST_TEXT(cache, text) { \
    void *m = arena_alloc_801613f0(arena_804b1754, 12); \
    message_post_8016239c(message_string_8010a8e0(m, (unsigned short)message_id_8015f5a0(cache, 1), text)); \
}
extern "C" void w3d_d24g_pause_trigger_8006bf7c(Ptr32<Self> self)
{
    if (self->flags & 0x00800000) return;
    if (self->flags & 0x00400000) return;
    if (timer_is_one_8006e71c(self)) return;
    self->flags |= 0x00400000;
    if (self->state != 7) return;
    int enter = 1;
    post(&msg_804ad85c);
    self->flags |= 0x00800000;
    post(&msg_804ad834);
    select_slot_800a7e14(5, s_8037bd3c);
    String name(s_8037bed4);
    if (network_804abac0 && network_804abac0->inner->team && team_value_8021eb00(network_804abac0->inner->team) == 0) {
        string_assign_8020bd38(&name, s_8037bedc);
        enter = 0;
    }
    pause_800fde38();
    if (enter) {
        app_enter_80129878(app_804b1788);
        Ptr32<Sound> sound = app_804b1788->sound;
        if (sound) sound->vtable->stop(sound, 0);
    }
    POST_TEXT(&msg_804ad7f4, name.text)
    POST_TEXT(&msg_804ad73c, s_8037beec)
    post(&msg_804ad80c);
    post(&msg_804ad7fc);
}


