// GWMP8P rev0 0x8001fa68. Builds the two AI jump reach tables
// (Worm.Jump.Forward and Worm.Jump.Backflip) from the jump velocity, gravity
// and walk speed properties: sizes each square table from the time of
// flight, then for every cell solves the ballistic range for the first and
// second arrival heights, marking cells that cannot be reached. Names are
// inferred.
extern "C" float sqrt_802e82c0(float);
extern const char s_gravity_8036b9ec[];
extern const char s_forward_8036b9f4[];
struct Vec { float x, y, z; Vec() {} float lenSq() const { return z * z + (x * x + y * y); } };
struct Object { void **table; };
typedef void (*Slot)(Object *);
struct Ref {
    Object *p;
    Ref() : p(0) {}
    Ref(const Ref &);
    ~Ref() { if (p) ((Slot)p->table[4])(p); }
    void operator=(Object *q) { if (q) ((Slot)q->table[3])(q); if (p) ((Slot)p->table[4])(p); p = q; }
};
struct Key { const char *text; Key(const char *t) : text(t) {} };
extern "C" int w3d_resource_property_800fc1b0(Key *, Ref *);
extern "C" Object *w3d_empty_80342a74(Object *);
extern "C" Object *w3d_empty_80342fa4(Object *);
extern "C" float w3d_value_80178df0(Object *);
extern "C" const Vec *w3d_auto_80178ec4(Object *);
extern "C" void *w3d_heap_alloc_801fe220(int);
struct Cell { int ok; float a; float b; };
struct Jump { char u00[52]; int size[2]; Cell *cells[2]; char u44[36]; float step; };
inline void LoadFloat(Ref &d, const char *name) { Key k(name); Ref t; w3d_resource_property_800fc1b0(&k, &t); d = w3d_empty_80342a74(t.p); }
inline void LoadVec(Ref &d, const char *name) { Key k(name); Ref t; w3d_resource_property_800fc1b0(&k, &t); d = w3d_empty_80342fa4(t.p); }
extern "C" void w3d_d41a_jump_reach_tables_8001fa68(Jump *self)
{
    Ref speedRef;
    Ref unused;
    LoadFloat(speedRef, s_gravity_8036b9ec);
    float speed = w3d_value_80178df0(speedRef.p);
    Vec dir[2];
    Ref a;
    LoadVec(a, s_forward_8036b9f4);
    dir[0] = *w3d_auto_80178ec4(a.p);
    Ref b;
    LoadVec(b, "Worm.Jump.Backflip");
    dir[1] = *w3d_auto_80178ec4(b.p);
    Ref c;
    LoadFloat(c, "Worm.JumpAftertouch.Multiplier");
    float k1 = w3d_value_80178df0(c.p);
    Ref t;
    { Key k("Worm.Walk.Speed"); w3d_resource_property_800fc1b0(&k, &t); }
    float g = w3d_value_80178df0(w3d_empty_80342a74(t.p)) * k1 * 0.5f;
    g = g * 0.85f;
    for (int i = 0; i <= 1; i++) {
        float y0 = dir[i].y;
        float v = __builtin_fabsf(dir[i].x);
        float t0 = (-0.25f - y0) / speed;
        int n = (int)((g * 0.5f * t0 + v) * t0 / self->step);
        self->size[i] = n;
        self->cells[i] = (Cell *)w3d_heap_alloc_801fe220(n * n * 12);
        for (int x = 0; x < n; x++) {
            for (int z = 0; z < n; z++) {
                Cell *c1 = &self->cells[i][x + z * self->size[i]];
                c1->ok = 1;
                float *pa = &c1->a;
                float *pb = &c1->b;
                if (x == 0 && z == 0) {
                    *pa = 0.0f;
                    *pb = 0.0f;
                    c1->ok = 0;
                    continue;
                }
                float zero = 0.0f;
                Vec d;
                float cs = self->step;
                float v2 = v * v;
                float fx = (float)x;
                Vec *pd = &d;
                d.x = fx * cs;
                pd->y = zero;
                d.z = (float)z * cs;
                float dist = sqrt_802e82c0(d.lenSq());
                float span = (g + g) * dist;
                float disc = v2 + span;
                if (disc < zero) {
                    *pa = -1000000.0f;
                    *pb = -1000000.0f;
                    c1->ok = 0;
                    continue;
                }
                float s = sqrt_802e82c0(disc);
                float top = -0.25f;
                float t1 = (-v + s) / g;
                float y1 = speed * t1 + y0;
                if (y1 < top) { *pa = -1000000.0f; *pb = -1000000.0f; c1->ok = 0; }
                if (y1 > zero) t1 = -y0 / speed;
                float hs = speed * 0.5f;
                *pa = (hs * t1 + y0) * t1;
                float disc2 = v2 - span;
                float gg = g;
                if (disc2 < zero) { gg = v2 / (dist + dist); disc2 = zero; }
                float t2 = (v - sqrt_802e82c0(disc2)) / gg;
                float y2 = speed * t2 + y0;
                if (y2 > zero) c1->ok = 0;
                if (y2 < top) t2 = (top - y0) / speed;
                *pb = (hs * t2 + y0) * t2;
            }
        }
    }
}
