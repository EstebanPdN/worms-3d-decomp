#include "w3d_ptr.h"
#line 1 "d24d_track_target_8014da00.cpp"
// d24d: 0x8014da00 (516 bytes). Keep an actor aimed at its tracked target (+792,
// cleared when stale). With an inactive target (+72 clear) only store whether the
// actor is detached (+716 set or +824 negative) in the target's +68. Otherwise a
// missing +804 of an actor whose class derives from 0x80361860 or 0x803618f0 is
// created by 0x80022e20; a detached actor stops there. The offset (+572) comes from
// 0x800db194 with flag 1 when +304, +300 and the owner match hold, else flag 0; then
// 0x800db60c runs with +560 and +676 and +68 is copied to +716. 0x8014c260 and
// 0x800db194 return vectors by value. Names are inferred.
struct d24d_Vec3 { float x, y, z; };
struct d24d_Class { char pad[20]; Ptr32<d24d_Class> base; };
inline int d24d_is_kind(Ptr32<const d24d_Class> c, Ptr32<const d24d_Class> t) {
    for (; c != t; c = c->base) if (c == c->base) return 0;
    return 1;
}
struct d24d_Target { char pad[68]; int attached; int active; };
struct d24d_Tracker { Ptr32<Ptr32<void>> vtable; char pad[296]; int f300; int f304; char pad1[252]; d24d_Vec3 pos; d24d_Vec3 off; char pad2[92]; d24d_Vec3 vel; char pad3[28]; int f716; char pad4[72]; int target; char pad5[8]; int f804; char pad6[16]; int f824;
  Ptr32<d24d_Class> cls() { return ((Ptr32<Ptr32<d24d_Class> (Ptr32<d24d_Tracker>)>)vtable[5])(this); } };
extern "C" Ptr32<void> d24d_lookup_80164fc8(int);
extern d24d_Vec3 d24d_direction_of(Ptr32<d24d_Tracker>);
extern "C" int d24d_owner_matches_8014c488(Ptr32<d24d_Tracker>);
extern "C" int d24d_create_slot_80022e20(Ptr32<const char>, Ptr32<const char>, int, Ptr32<int>);
extern d24d_Vec3 d24d_offset_towards(Ptr32<d24d_Target>, Ptr32<d24d_Vec3>, Ptr32<d24d_Vec3>, int);
extern "C" void d24d_apply_motion_800db60c(Ptr32<d24d_Target>, Ptr32<d24d_Vec3>, Ptr32<d24d_Vec3>);
extern d24d_Class d24d_class_a_80361860[], d24d_class_c_803618f0[];
extern const char d24d_text_803a1670[], d24d_text_803a0e2c[];
extern "C" void d24d_track_target_8014da00(Ptr32<d24d_Tracker> self) {
    if (self->target == -1) return;
    Ptr32<d24d_Target> t = (Ptr32<d24d_Target>)d24d_lookup_80164fc8(self->target);
    if (!t) { self->target = -1; return; }
    d24d_Vec3 dir = d24d_direction_of(self);
    if (t->active == 0) {
        t->attached = self->f716 != 0 || self->f824 < 0;
        return;
    }
    if (self->f804 == 0 && (d24d_is_kind(self->cls(), d24d_class_a_80361860) || d24d_is_kind(self->cls(), d24d_class_c_803618f0)))
        d24d_create_slot_80022e20(d24d_text_803a1670, d24d_text_803a0e2c, 4442, &self->f804);
    if (self->f716 != 0 || self->f824 < 0) return;
    if (self->f304 && self->f300 && d24d_owner_matches_8014c488(self))
        self->off = d24d_offset_towards(t, &self->off, &dir, 1);
    else
        self->off = d24d_offset_towards(t, &self->off, &dir, 0);
    d24d_apply_motion_800db60c(t, &self->pos, &self->vel);
    self->f716 = t->attached;
}


