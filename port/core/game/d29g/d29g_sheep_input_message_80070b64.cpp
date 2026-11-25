#include "w3d_ptr.h"
#line 1 "d29g_sheep_input_message_80070b64.cpp"
/* Worms 3D GameCube PAL 0x80070b64. Super sheep message handler: starts on message 64 after the base handler succeeds, cancels on 66; otherwise it matches the id against twelve cached ids in press and release pairs for six movement directions, setting a direction and clearing its opposite on press, clearing it on release and stamping the idle time at +352 once all six are clear; unknown ids go to the base handler. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct Ctx { char u[52]; int now; };
struct Msg { unsigned short id; };
struct MessageSlot { int a, b; };
struct Sheep { char u0[308]; int up, down, left, right, fwd, back; char u332[352 - 332]; int idle; };
extern "C" {
Ptr32<Ctx> w3d_engine_get_context();
int w3d_auto_800ea62c(Ptr32<Sheep>, Ptr32<Msg>);
void w3d_d24g_super_sheep_start_80070fec(Ptr32<Sheep>);
void w3d_auto_80071368(Ptr32<Sheep>);
int w3d_message_id_equals_cache(unsigned, Ptr32<MessageSlot>);
}
extern MessageSlot
s0_804ad8c4, s1_804ad8cc, s2_804ad8d4, s3_804ad8dc, s4_804ad8e4, s5_804ad8ec, s6_804ad8f4, s7_804ad8fc, s8_804ad904, s9_804ad90c, s10_804ad914, s11_804ad91c;
extern "C" int w3d_d29g_sheep_input_message_80070b64(Ptr32<Sheep> self, Ptr32<Msg> m)
{
    unsigned id = m->id;
    int now = w3d_engine_get_context()->now;
    switch (m->id) {
    case 64:
        if (w3d_auto_800ea62c(self, m) >= 0) {
            w3d_d24g_super_sheep_start_80070fec(self);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_auto_80071368(self);
        return w3d_auto_800ea62c(self, m);
    }
    if (w3d_message_id_equals_cache(id, &s0_804ad8c4)) { self->up = 1; self->down = 0; }
    else if (w3d_message_id_equals_cache(id, &s1_804ad8cc)) { self->up = 0; if (!self->down && !self->left && !self->right && !self->fwd && !self->back) self->idle = now; }
    else if (w3d_message_id_equals_cache(id, &s2_804ad8d4)) { self->down = 1; self->up = 0; }
    else if (w3d_message_id_equals_cache(id, &s3_804ad8dc)) { self->down = 0; if (!self->up && !self->left && !self->right && !self->fwd && !self->back) self->idle = now; }
    else if (w3d_message_id_equals_cache(id, &s4_804ad8e4)) { self->left = 1; self->right = 0; }
    else if (w3d_message_id_equals_cache(id, &s5_804ad8ec)) { self->left = 0; if (!self->right && !self->up && !self->down && !self->fwd && !self->back) self->idle = now; }
    else if (w3d_message_id_equals_cache(id, &s6_804ad8f4)) { self->right = 1; self->left = 0; }
    else if (w3d_message_id_equals_cache(id, &s7_804ad8fc)) { self->right = 0; if (!self->left && !self->up && !self->down && !self->fwd && !self->back) self->idle = now; }
    else if (w3d_message_id_equals_cache(id, &s8_804ad904)) { self->fwd = 1; self->back = 0; }
    else if (w3d_message_id_equals_cache(id, &s9_804ad90c)) { self->fwd = 0; if (!self->back && !self->up && !self->down && !self->left && !self->right) self->idle = now; }
    else if (w3d_message_id_equals_cache(id, &s10_804ad914)) { self->back = 1; self->fwd = 0; }
    else if (w3d_message_id_equals_cache(id, &s11_804ad91c)) { self->back = 0; if (!self->fwd && !self->up && !self->down && !self->left && !self->right) self->idle = now; }
    else return w3d_auto_800ea62c(self, m);
    return 0;
}


