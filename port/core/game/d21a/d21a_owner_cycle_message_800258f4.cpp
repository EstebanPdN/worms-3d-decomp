#include "w3d_ptr.h"
#line 1 "d21a_owner_cycle_message_800258f4.cpp"
/* Owner-cycling component message handler (0x800258f4). Message 64: run the
 * base component handler 0x8015fb34 and, when it succeeds, the set-up
 * 0x80025a1c (returns 0, or E_FAIL 0x80004005 when the base handler fails).
 * Message 66: run the stop routine 0x80025b34. The message matching cache
 * 0x804acad4 advances the owner index to the next one, wrapping to 1 after
 * min(0x800fcea0(), 5), and posts an 8-byte notification (cached id
 * 0x804acadc, vtable 0x8040db38). Except for message 64, the message is then
 * passed to the base handler, whose status is returned. Field and type
 * names are inferred from the original instructions; the unit owns no data. */
struct Message {
    unsigned short id;
    unsigned short unknown02;
    Ptr32<void> vtable;
    unsigned short Id() const { return id; }
};
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Listener;
extern "C" int w3d_component_handle_8015fb34(Ptr32<Listener>, Ptr32<Message>);
extern "C" void w3d_listener_setup_80025a1c(Ptr32<Listener>);
extern "C" void w3d_listener_stop_80025b34(Ptr32<Listener>);
extern "C" int w3d_message_id_equals_cache_8015f65c(unsigned short, Ptr32<MessageCache>);
extern "C" unsigned w3d_listener_owner_80025b04(Ptr32<Listener>);
extern "C" unsigned w3d_team_count_800fcea0(void);
extern "C" void w3d_set_handle_owner_80025aa0(Ptr32<Listener>, unsigned);
extern "C" Ptr32<Message> w3d_arena_alloc_801613f0(Ptr32<void>, int);
extern "C" int w3d_cached_message_id_8015f5a0(Ptr32<MessageCache>, int);
extern "C" int w3d_message_post_8016239c(Ptr32<Message>);
extern Ptr32<void> w3d_message_arena_804b1754;
extern MessageCache w3d_message_804acad4, w3d_message_804acadc;
extern unsigned char w3d_vtable_8040db38[];
/* Reference-returning minimum: the original compares through the
 * addresses of both operands. */
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }

extern "C" int w3d_d21a_owner_cycle_message_800258f4(Ptr32<Listener> self, Ptr32<Message> message)
{
    unsigned short id = message->Id();
    switch (message->Id()) {
    case 64:
        if (w3d_component_handle_8015fb34(self, message) >= 0) {
            w3d_listener_setup_80025a1c(self);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_listener_stop_80025b34(self);
        break;
    default:
        if (w3d_message_id_equals_cache_8015f65c(id, &w3d_message_804acad4)) {
            unsigned owner = w3d_listener_owner_80025b04(self);
            w3d_set_handle_owner_80025aa0(self, owner < Min(w3d_team_count_800fcea0(), 5u) ? owner + 1 : 1);
            Ptr32<Message> changed = w3d_arena_alloc_801613f0(w3d_message_arena_804b1754, 8);
            changed->id = w3d_cached_message_id_8015f5a0(&w3d_message_804acadc, 1);
            changed->vtable = w3d_vtable_8040db38;
            w3d_message_post_8016239c(changed);
        }
        break;
    }
    return w3d_component_handle_8015fb34(self, message);
}


