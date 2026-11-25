#include "w3d_ptr.h"
#line 1 "d24d_jetpack_update_8014d7c8.cpp"
// d24d: 0x8014d7c8 (568 bytes). Update a worm's jetpack (+784, cleared when stale):
// stop thrust when the worm is detached and blocked (+716, 0x801418c4 on +1152,
// 0x8014c89c on +1204) or +824 is negative and 0x80146b84 agrees, reporting that to
// 0x800ac14c. Without the flag the offset (+572) comes from 0x800aa628. If the jetpack
// has +168 set the velocity (+676) comes from 0x800aabbc with the height, and an
// active one (+72) with no +804 on classes 0x80361860 or 0x803618f0 creates the
// "Worm Jetpack Active" slot through 0x80022e20. Finally the jetpack is placed 22
// above the worm. Sibling of 0x8014da00.
struct d24d_Vec3 { float x, y, z; d24d_Vec3() {} d24d_Vec3(float a, float b, float c) { x = a; y = b; z = c; } };
struct d24d_Class { char pad[20]; Ptr32<d24d_Class> base; };
inline int d24d_is_kind(Ptr32<const d24d_Class> c, Ptr32<const d24d_Class> t) {
    for (; c != t; c = c->base) if (c == c->base) return 0;
    return 1;
}
struct d24d_Jetpack { char pad[72]; int active; char pad2[92]; int f168; };
struct d24d_JetpackWorm { Ptr32<Ptr32<void>> vtable; char pad[296]; int f300; int f304; char pad1[252]; d24d_Vec3 pos; d24d_Vec3 off; char pad2[92]; d24d_Vec3 vel; char pad3[28]; int f716; char pad4[64]; int target; char pad4b[4]; char pad5[12]; int f804; char pad6[16]; int f824; char pad7[324]; char col[52]; char comp[1];
  Ptr32<d24d_Class> cls() { return ((Ptr32<Ptr32<d24d_Class> (Ptr32<d24d_JetpackWorm>)>)vtable[5])(this); } };
extern "C" Ptr32<void> d24d_lookup_80164fc8(int);
extern d24d_Vec3 d24d_direction_of(Ptr32<d24d_JetpackWorm>);
extern "C" int d24d_owner_matches_8014c488(Ptr32<d24d_JetpackWorm>);
extern "C" int d24d_create_slot_80022e20(Ptr32<const char>, Ptr32<const char>, int, Ptr32<int>);
extern d24d_Class d24d_class_a_80361860[], d24d_class_c_803618f0[];
extern const char d24d_jetpack_active_803a1658[], d24d_logic_entity_803a0e2c[];
extern "C" int d24d_blocked_801418c4(Ptr32<char>);
extern "C" int d24d_component_8014c89c(Ptr32<char>);
extern "C" int d24d_can_stop_80146b84(Ptr32<d24d_JetpackWorm>);
extern "C" void d24d_set_thrust_off_800ac14c(Ptr32<d24d_Jetpack>, int);
extern d24d_Vec3 d24d_jet_offset(Ptr32<d24d_Jetpack>, Ptr32<d24d_Vec3>, Ptr32<d24d_Vec3>);
extern d24d_Vec3 d24d_jet_velocity(Ptr32<d24d_Jetpack>, Ptr32<d24d_Vec3>, Ptr32<d24d_Vec3>, float);
extern "C" void d24d_jet_place_800abbb4(Ptr32<d24d_Jetpack>, Ptr32<const d24d_Vec3>);
extern "C" void d24d_jetpack_update_8014d7c8(Ptr32<d24d_JetpackWorm> self) {
    if (self->target == -1) return;
    Ptr32<d24d_Jetpack> t = (Ptr32<d24d_Jetpack>)d24d_lookup_80164fc8(self->target);
    if (!t) { self->target = -1; return; }
    d24d_Vec3 dir = d24d_direction_of(self);
    int flag = 0;
    if ((self->f716 && d24d_blocked_801418c4(self->col) && d24d_component_8014c89c(self->comp)) || (self->f824 < 0 && d24d_can_stop_80146b84(self))) flag = 1;
    d24d_set_thrust_off_800ac14c(t, flag);
    if (!flag) self->off = d24d_jet_offset(t, &self->off, &dir);
    Ptr32<d24d_Vec3> pos = &self->pos;
    if (t->f168) {
        self->vel = d24d_jet_velocity(t, &self->vel, &dir, self->pos.y);
        if (t->active && !self->f804 && (d24d_is_kind(self->cls(), d24d_class_a_80361860) || d24d_is_kind(self->cls(), d24d_class_c_803618f0)))
            d24d_create_slot_80022e20(d24d_jetpack_active_803a1658, d24d_logic_entity_803a0e2c, 4410, &self->f804);
    }
    d24d_Vec3 p;
    p.x = self->pos.x; p.z = pos->z; p.y = pos->y + 22.0f;
    d24d_jet_place_800abbb4(t, &p);
}


