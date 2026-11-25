// d24d: 0x8015115c (576 bytes). Start a worm's dying animation when the message's
// sender (0x801190d0) is this worm (+20): classes 0x80361860 and 0x803618f0 create
// the "Worm Dying" slot (0x80022e20). A random value (0x801610a0) picks one of six
// motions by sixths, each with its own end time (+668, engine ticks + 2000 to 5500).
// Mode +760 becomes 20, the velocity (+676) is cleared and 0x801506f8 runs. The
// float literals form this function's pool at 0x803a1894. Built with -mps-float (two
// saved FPRs); the unflagged build differs only by the frame gap.
struct d24d_Vec3 { float x, y, z; };
struct d24d_Class { char pad[20]; d24d_Class *base; };
inline int d24d_is_kind(const d24d_Class *c, const d24d_Class *t) {
    for (; c != t; c = c->base) if (c == c->base) return 0;
    return 1;
}
struct d24d_Engine { char pad[52]; unsigned ticks; };
struct d24d_DyingWorm { void **vtable; char pad[16]; int owner; char pad2[644]; unsigned f668; char pad3[4]; d24d_Vec3 vel; char pad4[72]; int mode; char pad5[40]; int f804;
  d24d_Class *cls() { return ((d24d_Class *(*)(d24d_DyingWorm *))vtable[5])(this); } };
extern "C" int d24d_sender_of_801190d0(void *);
extern "C" d24d_Engine *d24d_engine_80165254();
extern "C" float d24d_random_unit_801610a0(d24d_DyingWorm *);
extern "C" void d24d_set_motion_801492ec(d24d_DyingWorm *, int);
extern "C" void d24d_after_death_801506f8(d24d_DyingWorm *);
extern "C" int d24d_create_slot_80022e20(const char *, const char *, int, int *);
extern d24d_Class d24d_class_a_80361860[], d24d_class_c_803618f0[];
extern const char d24d_worm_dying_803a1888[], d24d_logic_entity_803a0e2c[];
extern "C" void d24d_worm_dying_8015115c(d24d_DyingWorm *self, int arg) {
    if (d24d_sender_of_801190d0((void *)arg) != self->owner) return;
    d24d_Vec3 *vel = &self->vel;
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
