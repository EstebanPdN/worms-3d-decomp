/* Worms 3D GameCube PAL 0x8004b7e0. Starts a launched body: initialises position +40 from the two vectors with the 9000000 limit (0x800b0824); when the global 0x804b1764 exceeds the limit, stores setting +184 in the Y position, sets +128 and runs 0x8004cd08; otherwise copies the start position 0x8043ae20, sets +100, advances Y by +64 and runs 0x8004b8f4; then clears +112, releases the reference at +244 and clears +256. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct Object;
struct ObjectVtable { void *u[4]; void (*release)(Object *); };
struct Object { ObjectVtable *vtable; };
struct Vec3 { float x, y, z; Vec3() {} void set(float a, float b, float c) { x = a; y = b; z = c; } };
struct Words { float x, y, z; };
struct Self {
    char u0[40];
    Words position;
    char u52[12];
    float delta;
    char u68[32];
    int a100;
    char u104[8];
    int a112;
    char u116[12];
    int a128;
    char u132[52];
    Object *value;
    char u188[56];
    Object *ref;
    char u248[8];
    int a256;
};
extern "C" void init_800b0824(Words *, Vec3 *, Vec3 *, int, int);
extern "C" float value_80178df0(Object *);
extern "C" void next_8004cd08(Self *);
extern "C" void next_8004b8f4(Self *);
extern unsigned g_804b1764;
extern Words start_8043ae20[];
extern "C" void w3d_d24g_body_launch_8004b7e0(Self *self)
{
    Vec3 a, b;
    a.set(0.0f, -1.0f, 0.0f);
    b.set(0.0f, 0.0f, 0.0f);
    init_800b0824(&self->position, &a, &b, 9000000, 1);
    unsigned limit = 9000000;
    if (g_804b1764 > limit) {
        self->position.y = value_80178df0(self->value);
        self->a128 = 1;
        next_8004cd08(self);
    } else {
        self->position = start_8043ae20[0];
        self->a100 = 1;
        self->position.y += self->delta;
        next_8004b8f4(self);
    }
    self->a112 = 0;
    if (self->ref) self->ref->vtable->release(self->ref);
    self->ref = 0;
    self->a256 = 0;
}
