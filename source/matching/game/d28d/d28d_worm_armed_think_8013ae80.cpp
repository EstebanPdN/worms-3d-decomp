// GWMP8P rev0 0x8013ae80. Armed worm reaction to the active worm, twin of
// 0x8013aa58. Names are inferred from use. The play callee's argument order
// is chosen for the argument moves.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float distSqX(float ox, const Vec &o) const { float dx = x - ox, dy = y - o.y, dz = z - o.z; return dx * dx + dy * dy + dz * dz; }
    float distSq(const Vec &o) const { float dx = x - o.x, dy = y - o.y, dz = z - o.z; return dx * dx + dy * dy + dz * dz; }
};
struct Obj { void **vtable; };
struct Mesh;
struct Info { char u0[68]; Vec dir; Vec pos; };
struct Worm { char u0[52]; Vec eye; Vec look; char u4c[8]; void *colour; char u58[24]; int index; char u74[48]; struct Mesh *f164; char ua8[304]; int cue472; char u1dc[12]; int cue488; int cue492; char u1f0[44]; Obj *f540; char u220[8]; void *f552; char u22c[104]; int aiming; float f664; float f668; };
struct Vec3Src;
struct Cam { void **vtable; };
struct System { char u0[48]; Cam *cam; };
extern System *system_804b1788;
extern "C" float sqrt_802e82c0(float);
extern "C" int firing_8013f4dc(Worm *);
extern "C" int armed_8013e9a8(Worm *);
extern "C" int ready_8013e8f8(Worm *);
extern "C" void stop_800e5bb8(void *);
extern "C" void *get_803426b4(void *);
extern "C" int target_80178c48(void *);
extern "C" Info *query_800fc6dc(int);
extern "C" int in_range_8013b5bc(Worm *, const Vec *, const Vec *, const Vec *, float *);
extern "C" float angle_8013b898(Worm *, const Vec *, const Vec *);
extern "C" void apply_8013c21c(Worm *, Mesh *, float, float);
extern "C" int facing_8013b3b8(Worm *, const Vec *, const Vec *, const Vec *);
extern "C" int visible_8013b91c(Worm *, Info *);
extern "C" unsigned rand_80162c20();
extern "C" int play_801359ec(Worm *, Mesh *, const char *, float, float, int *, float);
extern "C" void idle_8013a158(Worm *, Mesh *, int);
extern "C" void turn_8013b948(Worm *, const Vec *, Mesh *);
extern const char fire_8039f4f4[];
extern const char *a_804ab16c, *c_804ab2c4, *d_804ab2c8, *e_804ab2cc, *g_804ab2b8;
extern "C" void d28d_worm_armed_think_8013ae80(Worm *self, Mesh *mesh) {
    if (self->f552) {
        stop_800e5bb8(self->f552);
        Obj *o = self->f540;
        self->f552 = 0;
        if (o) ((void (*)(Obj *))o->vtable[6])(o);
    }
    int other = target_80178c48(get_803426b4(self->colour));
    if (other == self->index) return;
    query_800fc6dc(self->index);
    Info *him = query_800fc6dc(other);
    if (firing_8013f4dc(self)) {
        play_801359ec(self, mesh, fire_8039f4f4, 1.0f, 0.0f, &self->cue472, 0.0f);
        if (self->f164) play_801359ec(self, self->f164, fire_8039f4f4, 1.0f, 0.0f, &self->cue488, 0.0f);
        return;
    }
    float a = 0.0f;
    const Vec *hp = &him->pos;
    const Vec *eye = &self->eye;
    if (self->aiming) {
        if (in_range_8013b5bc(self, hp, eye, &self->look, &a) && a > 0.1f) {
            float b = angle_8013b898(self, hp, eye);
            apply_8013c21c(self, mesh, a, b);
        } else {
            a = 0.0f;
            apply_8013c21c(self, mesh, a, a);
            if (__builtin_fabsf(self->f664) < 0.01f) self->aiming = 0;
        }
    }
    float dx = self->eye.x - him->pos.x, dy = eye->y - hp->y, dz = eye->z - hp->z;
    float d = dx * dx + dy * dy + dz * dz;
    if (d > 202500.0f) {
        play_801359ec(self, mesh, a_804ab16c, 1.0f, 0.0f, &self->cue472, 0.0f);
        return;
    }
    if (d > 40000.0f) {
        Vec t = *((const Vec *(*)(Cam *))system_804b1788->cam->vtable[14])(system_804b1788->cam);
        bool far = sqrt_802e82c0(t.distSqX(self->eye.x, *eye)) < 70.0f;
        float c;
        if (far && in_range_8013b5bc(self, &t, eye, &self->look, &c)) {
            float b = angle_8013b898(self, &t, eye);
            apply_8013c21c(self, mesh, c, b);
            return;
        }
        idle_8013a158(self, mesh, far);
        return;
    }
    if (d < 6400.0f) {
        if (facing_8013b3b8(self, hp, &him->dir, eye)) {
            if (!visible_8013b91c(self, him)) { turn_8013b948(self, hp, mesh); return; }
            if (armed_8013e9a8(self)) {
                if (!(d <= 1225.0f)) goto rest;
                unsigned n = rand_80162c20() % 3;
                switch ((int)n) {
                case 0: play_801359ec(self, mesh, c_804ab2c4, 1.0f, 0.0f, &self->cue472, 0.0f); break;
                case 1: play_801359ec(self, mesh, d_804ab2c8, 1.0f, 0.0f, &self->cue472, 0.0f); break;
                case 2: play_801359ec(self, mesh, e_804ab2cc, 1.0f, 0.0f, &self->cue472, 0.0f); break;
                }
                return;
            }
            if (ready_8013e8f8(self)) {
                play_801359ec(self, mesh, g_804ab2b8, 1.0f, 0.0f, &self->cue472, 0.0f);
                return;
            }
            idle_8013a158(self, mesh, 1);
            return;
        }
        float e;
        if (in_range_8013b5bc(self, hp, eye, &self->look, &e)) {
            float b = angle_8013b898(self, hp, eye);
            apply_8013c21c(self, mesh, e, b);
            return;
        }
        if (self->aiming) goto turn;
        goto rest;
    }
    if (!in_range_8013b5bc(self, hp, eye, &self->look, &a)) goto busy;
    if (__builtin_fabsf(a) > 0.1f) {
        float b = angle_8013b898(self, hp, eye);
        apply_8013c21c(self, mesh, a, b);
        return;
    }
    if (!(a <= 0.1f)) goto turn;
rest:
    idle_8013a158(self, mesh, 0);
    return;
turn:
    turn_8013b948(self, hp, mesh);
    return;
busy:
    idle_8013a158(self, mesh, 1);
}
