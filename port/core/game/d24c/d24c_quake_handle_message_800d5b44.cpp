#include "w3d_ptr.h"
#line 1 "d24c_quake_handle_message_800d5b44.cpp"
// d24c: 0x800d5b44 (292 bytes). Message handler of the quake object. Message 64:
// forward to the base and start on success, or return the failure code 0x80004005.
// Message 66: stop, then forward. Others: dispatch the four cached message ids to their
// handlers (the second and fourth set the done flag +92), otherwise forward to the
// base. Names are inferred. Id() is an inline accessor: the id local and the switch
// read the same field, which gives the original's register copy.
struct Message {
    unsigned short id;
    unsigned short Id() const { return id; }
};
struct Quake { unsigned char u[92]; int done; };
extern "C" int base_8015fb34(Ptr32<Quake>, Ptr32<Message>);
extern "C" void start_800d5d44(Ptr32<Quake>);
extern "C" void stop_800d5f98(Ptr32<Quake>);
extern "C" int id_equals_8015f65c(unsigned short, Ptr32<int>);
extern "C" void h1_800d6424(Ptr32<Quake>, Ptr32<Message>);
extern "C" int h2_800d6788(Ptr32<Quake>);
extern "C" void h3_800d67d8(Ptr32<Quake>, Ptr32<Message>);
extern "C" void h4_800d6904(Ptr32<Quake>);
extern int a_804aea58, b_804aea60, c_804aea68, d_804aea78;
extern "C" int d24c_quake_handle_message_800d5b44(Ptr32<Quake> self, Ptr32<Message> m) {
    unsigned short id = m->Id();
    switch (m->Id()) {
    case 64:
        if (base_8015fb34(self, m) >= 0) {
            start_800d5d44(self);
            goto handled;
        }
        return 0x80004005;
    case 66:
        stop_800d5f98(self);
        break;
    default:
        if (id_equals_8015f65c(id, &a_804aea58)) {
            h1_800d6424(self, m);
            goto handled;
        }
        if (id_equals_8015f65c(id, &b_804aea60) && h2_800d6788(self)) goto finished;
        if (id_equals_8015f65c(id, &c_804aea68)) {
            h3_800d67d8(self, m);
            goto handled;
        }
        if (id_equals_8015f65c(id, &d_804aea78)) goto quake;
        break;
    }
    return base_8015fb34(self, m);
quake:
    h4_800d6904(self);
finished:
    self->done = 1;
handled:
    return 0;
}


