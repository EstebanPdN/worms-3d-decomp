// Appears to construct a beam field object: runs the actor base constructor,
inline void *operator new(unsigned int, void *place) { return place; }
// installs the vtable, resets its state to an empty extent (+/-1e6 bounds),
// publishes itself in a global and allocates a 31 x 31 cell grid.
struct K10aVec3
{
    float x, y, z;
    K10aVec3(float v) { x = v; y = v; z = v; }
};

struct K10aSlot
{
    K10aSlot() {}
};

// Axis-aligned extent: inverted +/-1e6 corners and two enable flags.
struct K10aBounds
{
    K10aVec3 maximum;            // +0
    K10aVec3 minimum;            // +12
    char pad24[4];
    short enabled;               // +28
    short disabled;              // +30
    K10aBounds() : maximum(1000000.0f), minimum(-1000000.0f)
    {
        enabled = 1;
        disabled = 0;
    }
};

struct K10aTriple
{
    int first, second, third;
    K10aTriple()
    {
        third = 0;
        second = 0;
        first = 0;
    }
};

struct K10aBeamField
{
    void *vtable;                // +0
    char pad4[24];
    int state[10];               // +28
    int reserved;                // +68
    K10aBounds bounds;           // +72
    char pad104[12];
    K10aTriple triple;           // +116
    K10aSlot slots[1024];        // +128 (empty constructors)
    char pad1152[11392];
    int head;                    // +12544
    K10aVec3 origin;             // +12548
    K10aVec3 target;             // +12560
    void *grid;                  // +12572
};
extern "C" int w3d_actor_base_initialize(K10aBeamField *self);
extern "C" void *w3d_heap_allocate(void *pool, unsigned int size);
extern "C" void *fn_8002c2f8(void *where, int columns, int rows, int flags);
extern char w3d_vtable_8040f828[];
extern int w3d_pool_804af5bc;
extern K10aBeamField *w3d_beam_field_804b17e0;
extern int w3d_beam_a_804b182c;
extern int w3d_beam_b_804b1830;
extern int w3d_beam_c_804b1834;

extern "C" K10aBeamField *w3d_k10a_beam_field_ctor_800ba884(K10aBeamField *self)
{
    w3d_actor_base_initialize(self);
    self->vtable = w3d_vtable_8040f828;
    self->state[0] = 0;
    self->state[1] = 0;
    self->state[2] = 0;
    self->state[3] = 0;
    self->state[4] = 0;
    self->state[5] = 0;
    self->state[6] = 0;
    self->state[7] = 0;
    self->state[8] = 0;
    self->state[9] = 0;
    new (&self->bounds) K10aBounds;
    new (&self->triple) K10aTriple;
    for (int i = 0; i < 1024; i++)
        new (&self->slots[i]) K10aSlot;
    self->head = 0;
    w3d_beam_field_804b17e0 = self;
    self->grid = fn_8002c2f8(w3d_heap_allocate(&w3d_pool_804af5bc, 16), 31, 31, 0);
    self->reserved = 0;
    new (&self->origin) K10aVec3(0.0f);
    new (&self->target) K10aVec3(0.0f);
    w3d_beam_a_804b182c = 0;
    w3d_beam_b_804b1830 = 0;
    w3d_beam_c_804b1834 = 0;
    return self;
}
