/* Worms 3D GameCube PAL 0x8006e124. Wormpot setup: loads the WormPot object, resets it from a fresh prototype, reads the three FE.Wormpot.Reel values (17 when absent) and turns each reel's symbol into an option flag on the object. Field names are inferred from the original instructions; strings and globals are external views of original data. */
struct Object;
struct ObjectVtable { void *u[3]; void (*retain)(Object *); void (*release)(Object *); };
struct Object { ObjectVtable *vtable; };
struct Descriptor_80178474 { int zero; unsigned type; Descriptor_80178474() : zero(0), type(58280) {} ~Descriptor_80178474(); };
struct Pot : Object { char u4[16]; float f20, f24, f28, f32, f36; int opt40; int opt44; int opt48; int opt52; int opt56; int opt60; int opt64; int opt68; int opt72; int opt76; int opt80; int opt84; int opt88; char u92[4]; int opt96; int opt100; int opt104; int opt108; int opt112; char u116[4]; int opt120; int opt124; int opt128; int opt132; int opt136; int opt140; int opt144; int opt148; };
template <class T> struct Ref {
    T *value;
    Ref() : value(0) {}
    Ref(T *p) { value = p; if (p) p->vtable->retain(p); }
    Ref(const Ref &);
    ~Ref() { if (value) value->vtable->release(value); }
    Ref &operator=(const Ref &o) {
        T *n = o.value;
        if (n) {
            n->vtable->retain(n);
            if (value) value->vtable->release(value);
            value = n;
        }
        return *this;
    }
    T *operator->() const { return value; }
    void clear() { if (value) value->vtable->release(value); value = 0; }
};
struct Key { const char *text_; };
extern unsigned char type_8041b170[];
extern const char s_8037c3d4[], s_8037c3fc[], s_8037c410[], s_8037c424[];
extern "C" int lookup_800fc1b0(Key *, void *);
extern "C" Object *cast_80341584(Object *);
extern "C" Pot *pot_80179598(Object *, Descriptor_80178474 *);
extern "C" Pot *type_8020b680(void *);
extern "C" void tags_801ea4c8(Pot *, Pot *);
extern "C" Object *native_80342a78(Object *);
extern "C" int reel_80178d1c(Object *);
#define READ(slot, text) { Key k; k.text_ = text; if (lookup_800fc1b0(&k, &w) < 0) reels[slot] = 17; else reels[slot] = reel_80178d1c(native_80342a78(w.value)); }
extern "C" void w3d_d30g_wormpot_setup_8006e124()
{
    Descriptor_80178474 desc;
    Ref<Object> h;
    { Key k; k.text_ = s_8037c3d4; if (lookup_800fc1b0(&k, &h) < 0) return; }
    Ref<Pot> pot;
    pot = Ref<Pot>(pot_80179598(cast_80341584(h.value), &desc));
    void *proto = type_8041b170;
    Ref<Pot> a(type_8020b680(proto));
    Ref<Pot> b(type_8020b680(proto));
    tags_801ea4c8(a.value, pot.value);
    tags_801ea4c8(pot.value, b.value);
    pot->f36 = a->f36;
    pot->f32 = a->f32;
    pot->f28 = a->f28;
    pot->f24 = a->f24;
    pot->f20 = a->f20;
    a.clear();
    b.clear();
    Ref<Object> w;
    int reels[3];
    READ(0, s_8037c3fc)
    READ(1, s_8037c410)
    READ(2, s_8037c424)
    for (int i = 0; i < 3; i++) {
        switch (reels[i]) {
        case 0: pot->opt136 = 1; break;
        case 1: pot->opt80 = 1; break;
        case 2: pot->opt124 = 1; break;
        case 3: pot->opt128 = 1; break;
        case 4: pot->opt112 = 1; break;
        case 5: pot->opt132 = 1; break;
        case 6: pot->opt120 = 1; break;
        case 7: pot->opt40 = 1; break;
        case 8: pot->opt148 = 1; break;
        case 9: pot->opt96 = 1; break;
        case 10: pot->opt84 = 1; break;
        case 11: pot->opt104 = 1; break;
        case 12: pot->opt108 = 1; break;
        case 13: pot->opt64 = 1; break;
        case 14: pot->opt76 = 1; break;
        case 15: pot->opt48 = 1; break;
        case 16: pot->opt52 = 1; break;
        case 17: break;
        case 18: pot->opt68 = 1; break;
        case 19: pot->opt60 = 1; break;
        case 20: pot->opt100 = 1; break;
        case 21: pot->opt56 = 1; break;
        case 22: break;
        case 23: pot->opt140 = 1; break;
        case 24: pot->opt44 = 1; break;
        case 25: pot->opt72 = 1; break;
        case 26: pot->opt144 = 1; break;
        case 27: pot->opt88 = 1; break;
        }
    }
}
