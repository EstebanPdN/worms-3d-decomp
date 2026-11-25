#include "w3d_ptr.h"
#line 1 "d24i_teleport_message_80119470.cpp"
// d24i: 0x80119470 (280 bytes). Teleport weapon message handler. Message 64
// forwards to the base handler and, on success, runs setup (0x80119590);
// a failed base call returns 0x80004005. Message 66 runs shutdown (0x801196d8)
// and then forwards to the base handler. The cached "fire" message either
// starts the jump (0x80119794) when the state test 0x80119aa8 passes, or posts
// an 8-byte notification allocated from the message arena. The second cached
// message runs 0x8015fd1c; anything else goes to the base handler.
struct d24i_Message {
    unsigned short id;
    unsigned short Id() const { return id; }
};
struct d24i_Notification {
    unsigned short id;
    Ptr32<const void> vtable;
};
extern "C" int d24i_base_handle_8015fb34(Ptr32<void>, Ptr32<d24i_Message>);
extern "C" void d24i_setup_80119590(Ptr32<void>);
extern "C" void d24i_shutdown_801196d8(Ptr32<void>);
extern "C" int d24i_id_equals_8015f65c(unsigned short, Ptr32<void>);
extern "C" int d24i_can_jump_80119aa8(Ptr32<void>);
extern "C" void d24i_jump_80119794(Ptr32<void>);
extern "C" Ptr32<void> d24i_arena_alloc_801613f0(Ptr32<void>, int);
extern "C" unsigned short d24i_cached_id_8015f5a0(Ptr32<void>, int);
extern "C" int d24i_post_8016239c(Ptr32<d24i_Notification>);
extern "C" void d24i_finish_8015fd1c(Ptr32<void>);
extern unsigned int d24i_fire_804af32c;
extern unsigned int d24i_stop_804af31c;
extern unsigned int d24i_notify_804af35c;
extern Ptr32<void> d24i_arena_804b1754;
extern Ptr32<const void> const d24i_notification_vtable_8040db38[];

extern "C" int d24i_teleport_message_80119470(Ptr32<void> self, Ptr32<d24i_Message> message) {
    unsigned short id = message->Id();
    switch (message->Id()) {
    case 64:
        if (d24i_base_handle_8015fb34(self, message) >= 0)
            d24i_setup_80119590(self);
        else
            return 0x80004005;
        break;
    case 66:
        d24i_shutdown_801196d8(self);
        return d24i_base_handle_8015fb34(self, message);
    default:
        if (d24i_id_equals_8015f65c(id, &d24i_fire_804af32c)) {
            if (d24i_can_jump_80119aa8(self)) {
                d24i_jump_80119794(self);
            } else {
                Ptr32<d24i_Notification> note = (Ptr32<d24i_Notification>)d24i_arena_alloc_801613f0(d24i_arena_804b1754, 8);
                note->id = d24i_cached_id_8015f5a0(&d24i_notify_804af35c, 1);
                note->vtable = d24i_notification_vtable_8040db38;
                d24i_post_8016239c(note);
            }
        } else if (!d24i_id_equals_8015f65c(id, &d24i_stop_804af31c)) {
            return d24i_base_handle_8015fb34(self, message);
        } else {
            d24i_finish_8015fd1c(self);
        }
        break;
    }
    return 0;
}


