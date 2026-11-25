// Destructor for a game object whose observed layout has one held interface at
// +0x1c, a two-element held-interface array at +0x30 and one held interface at
// +0x38. The class name and member meanings are inferred from the instructions;
// only the observed offsets, the release order and the forwarded flags are
// claimed. Held interfaces are released through vtable slot +16.
#define E15D_FIELD(p,T,o) (*(T*)((char*)(p)+(o)))

struct E15dHeld {
    void *held;
    ~E15dHeld() { if (held) ((void(*)(void*))(*(void**)(*(char**)held+16)))(held); }
};

struct E15dTwoPairs {
    const void *table;      // +0x00
    char reserved[24];      // +0x04..+0x1b
    E15dHeld field1c;       // +0x1c
    char gap20[16];         // +0x20..+0x2f
    E15dHeld pair30[2];     // +0x30..+0x37
    E15dHeld field38;       // +0x38
    ~E15dTwoPairs() {}
};

extern const void *e15d_table_8041c920[];
extern "C" void e15d_base_destroy_8015ff2c(void*,int);

// Install the class table, destroy the members in reverse declaration order
// (held interface at +0x38, the two-element array high index first, then the
// held interface at +0x1c) and forward the caller's flags to the base
// destructor.
extern "C" void w3d_e15d_two_pair_destroy_802c5e10(void *self,int flags) {
    E15dTwoPairs *owner=(E15dTwoPairs*)self;
    owner->table=e15d_table_8041c920;
    owner->~E15dTwoPairs();
    e15d_base_destroy_8015ff2c(self,flags);
}
