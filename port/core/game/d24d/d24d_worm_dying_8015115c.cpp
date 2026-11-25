#include "w3d_ptr.h"
#line 1 "d24d_worm_dying_8015115c.cpp"
// d24d: 0x8015115c (576 bytes). Start a worm's dying animation when the message's
// sender (0x801190d0) is this worm (+20): classes 0x80361860 and 0x803618f0 create
// the "Worm Dying" slot (0x80022e20). A random value (0x801610a0) picks one of six
// motions by sixths, each with its own end time (+668, engine ticks + 2000 to 5500).
// Mode +760 becomes 20, the velocity (+676) is cleared and 0x801506f8 runs. The
// float literals form this function's pool at 0x803a1894. Built with -mps-float (two
// saved FPRs); the unflagged build differs only by the frame gap.
// v26 (Ultimate Mayhem drowning, core/native/ahogo.cpp): a worm floating like in UM ignores the message, as UM's
// StartDying (0x5ADBF0) does for a worm in kWPS_DrownFloat. It explodes when its float ends.
struct d24d_Vec3 { float x, y, z; };
struct d24d_Class { char pad[20]; Ptr32<d24d_Class> base; };
inline int d24d_is_kind(Ptr32<const d24d_Class> c, Ptr32<const d24d_Class> t) {
    for (; c != t; c = c->base) if (c == c->base) return 0;
    return 1;
}
struct d24d_Engine { char pad[52]; unsigned ticks; };
struct d24d_DyingWorm { Ptr32<Ptr32<void>> vtable; char pad[16]; int owner; char pad2[560]; int index; char pad2b[80]; unsigned f668; char pad3[4]; d24d_Vec3 vel; char pad4[72]; int mode; char pad5[40]; int f804;
  Ptr32<d24d_Class> cls() { return ((Ptr32<Ptr32<d24d_Class> (Ptr32<d24d_DyingWorm>)>)vtable[5])(this); } };
extern "C" int d24d_sender_of_801190d0(Ptr32<void>);
extern "C" Ptr32<d24d_Engine> d24d_engine_80165254();
extern "C" float d24d_random_unit_801610a0(Ptr32<d24d_DyingWorm>);
extern "C" void d24d_set_motion_801492ec(Ptr32<d24d_DyingWorm>, int);
extern "C" void d24d_after_death_801506f8(Ptr32<d24d_DyingWorm>);
extern "C" int d24d_create_slot_80022e20(Ptr32<const char>, Ptr32<const char>, int, Ptr32<int>);
extern d24d_Class d24d_class_a_80361860[], d24d_class_c_803618f0[];
extern const char d24d_worm_dying_803a1888[], d24d_logic_entity_803a0e2c[];
extern "C" int w3d_ahogo_um_flotando(int);
extern "C" void d24d_worm_dying_8015115c(Ptr32<d24d_DyingWorm> self, int arg) {
    if (d24d_sender_of_801190d0((Ptr32<void>)w3d::G(arg)) != self->owner) return;
    if (self->mode == 27 && w3d_ahogo_um_flotando(self->index)) return;
    Ptr32<d24d_Vec3> vel = &self->vel;
    if (d24d_is_kind(self->cls(), d24d_class_a_80361860) || d24d_is_kind(self->cls(), d24d_class_c_803618f0))
        d24d_create_slot_80022e20(d24d_worm_dying_803a1888, d24d_logic_entity_803a0e2c, 5902, &self->f804);
    float v = d24d_random_unit_801610a0(self);
    float u = 0.16666667f;
    self->f668 = d24d_engine_80165254()->ticks + 4375;
    if (v < u) { self->f668 = d24d_engine_80165254()->ticks + 2000; d24d_set_motion_801492ec(self, 12); }
    else if (v < u + u) { self->f668 = d24d_engine_80165254()->ticks + 5500; d24d_set_motion_801492ec(self, 29); }
    else if (v < u * 3.0f) { self->f668 = d24d_engine_80165254()->ticks + 3500; d24d_set_motion_801492ec(self, 30); }
    else if (v < u * 4.0f) { self->f668 = d24d_engine_80165254()->ticks + 4800; d24d_set_motion_801492ec(self, 39); }
    else if (v < u * 5.0f) { self->f668 = d24d_engine_80165254()->ticks + 4375; d24d_set_motion_801492ec(self, 40); }
    else { self->f668 = d24d_engine_80165254()->ticks + 3125; d24d_set_motion_801492ec(self, 41); }
    self->mode = 20;
    self->vel.x = 0.0f;
    vel->y = 0.0f;
    vel->z = 0.0f;
    d24d_after_death_801506f8(self);
}


