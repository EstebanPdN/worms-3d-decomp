// d24c cleaner source for 0x800d25e4 (424 bytes), one-word holder with a real release:
// the firing block is an inline helper. Same behaviour as d24c_nuclear_trigger_800d25e4.
typedef unsigned int size_t;
struct String {
    char *text;
    unsigned opaque;
    String(const char *);
    ~String();
};
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
struct Object;
struct ObjectVtable {
    void *unknown00[3];
    void (*retain)(Object *);       // +12
    void (*release)(Object *);      // +16
};
struct Object { ObjectVtable *vtable; };
struct Key { const char *text; };
extern "C" int read_800fc1b0(Key *, void *);

struct Holder {
    Object *value;
    ~Holder() { if (value) value->vtable->release(value); }
};
struct Type { unsigned char unknown00[20]; const Type *parent; };
struct Settings {
    unsigned char u0[52];
    int w52;
    unsigned char u56[96];
    unsigned char a152, a153;
};
struct Bomb {
    struct V { void *u[5]; const Type *(*type)(Bomb *); } *vtable;
    unsigned char u4[52];
    int w56;      // +56
    int state;    // +60
    unsigned char u64[4];
    unsigned char arg[4];  // +68
    unsigned deadline;     // +72
    unsigned char u76[8];
    int done;     // +84
};
extern "C" int timer_8006e71c(Bomb *);
extern "C" void assert_80022e20(const char *, const char *, int, void *);
extern "C" void fn_800d2924(void);
extern "C" void *identity_80341584(void *);
extern "C" Settings *settings_801797b4(void *);
extern "C" void fn_800fdd80(int, int, const void *, int, int);
extern "C" void fn_8002ae70(Bomb *);
extern int flag_804aae44;
extern const Type type_80361860[], type_803618f0[];
extern const char title_80388b34[], file_80388b48[], weapon_803887bc[];
extern const unsigned char origin_8045e788[];
inline bool is_a(const Type *t, const Type *target) {
    while (t != target) {
        if (t == t->parent) return false;
        t = t->parent;
    }
    return true;
}
inline void fire(Bomb *self) {
        self->state = 2;
        Holder h;
        Key key;
        Holder *out = &h;
        Key *kp = &key;
        if (is_a(self->vtable->type(self), type_80361860) || is_a(self->vtable->type(self), type_803618f0))
            assert_80022e20(title_80388b34, file_80388b48, 128, self->arg);
        int one = 1;
        flag_804aae44 = one;
        fn_800d2924();
        h.value = 0;
        key.text = weapon_803887bc;
        read_800fc1b0(kp, out);
        Settings *s = settings_801797b4(identity_80341584(h.value));
        self->w56 = s->w52;
        fn_800fdd80(s->a153, s->a152, origin_8045e788, 4000, 0);
        self->done = one;
        fn_8002ae70(self);
    }
extern "C" int d24c_v2_nuclear_trigger_800d25e4(Bomb *self, unsigned now) {
    if (timer_8006e71c(self)) return 20;
    if (self->state == 1 && now > self->deadline) {
        fire(self);
    }
    return 20;
}
