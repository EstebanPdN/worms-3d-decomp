// Team spawn (Worms 3D GameCube PAL, 0x800a5a94, 568 bytes).
//
// Field names are inferred; the worm name uses the engine's reference-counted
// string (count at text - 6). Descriptor_80178474 has its second word witnessed
// by the original's stored tag 58280 at +4.

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) { x = a; y = b; z = c; }
};
struct String;
extern "C" void w3d_string_finish_8020c5c4(String *);
extern "C" void w3d_string_release_80341588(String *);
extern "C" void w3d_string_free_8020bb2c(void *);
struct String {
    char *text;
    String();
    String(const char *);
    String(const String &);
    ~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
    void operator=(const String &o) {
        *(unsigned short *)(o.text - 6) += 1;
        unsigned short *rep = (unsigned short *)(text - 6);
        if (--*rep == 0) w3d_string_free_8020bb2c(rep);
        text = o.text;
    }
};
extern "C" int fn_8020c510(String *, const char *, ...);
struct Descriptor_80178474 {
    void *value;
    unsigned tag;
    Descriptor_80178474() : value(0), tag(58280) {}
    ~Descriptor_80178474();
};
struct Worm;
struct WormVt { void *u[3]; void (*addref)(Worm *); void (*release)(Worm *); };
struct Worm {
    WormVt *vt;
    unsigned char u4[64];
    Vec3 velocity;   // +68
    Vec3 position;   // +80
    unsigned char u92[12];
    int m104;
    unsigned char u108[4];
    int m112;
    unsigned char u116[16];
    int m132;
    unsigned char u136[4];
    String name;     // +140
    unsigned char u144[26];
    unsigned short health;  // +170
    unsigned char u172[41];
    unsigned char team;     // +213
    unsigned char u214[2];
    int m216;
    int active;      // +220
};
struct Held {
    Worm *p;
    Held(Worm *o) : p(o) { if (p) p->vt->addref(p); }
    Held(const Held &);
    ~Held() { if (p) p->vt->release(p); }
    Worm *operator->() { return p; }
};
extern "C" Worm *fn_800fc710(int, Descriptor_80178474 *);
struct Arena;
extern Arena *lbl_804b1754;
extern "C" void *fn_801613f0(Arena *, unsigned);
struct Cache { unsigned short id; unsigned char u[6]; };
extern Cache lbl_804ae278;
extern "C" int fn_8015f5a0(Cache *, int);
extern "C" int fn_8016239c(void *);
extern "C" void *fn_800683fc(void *, unsigned short, const char *, int);
extern "C" void *fn_80342fa4(void *);
extern "C" Vec3 *fn_80178ec4(void *);
extern const char lbl_80381238[], lbl_80381240[];
extern const char *lbl_803f4bf8[];
struct Spawner { unsigned char u[28]; void *res; };
inline void Put(Vec3 &to, const Vec3 &from) { to = from; }
extern "C" void w3d_d25h_spawn_800a5a94(Spawner *self, int team, unsigned char colour) {
    String name;
    Vec3 where;
    Vec3 zero(0.0f, 0.0f, 0.0f);
    Descriptor_80178474 desc;
    fn_8020c510(&name, lbl_80381238, team + 1);
    void *m = fn_801613f0(lbl_804b1754, 12);
    fn_8016239c(fn_800683fc(m, fn_8015f5a0(&lbl_804ae278, 1), lbl_80381240, team));
    where = *fn_80178ec4(fn_80342fa4(self->res));
    Held worm(fn_800fc710(team, &desc));
    worm->active = 1;
    worm->name = String(lbl_803f4bf8[team]);
    Put(worm->position, where);
    Put(worm->velocity, zero);
    worm->team = colour;
    worm->health = 100;
    worm->m132 = 0;
    worm->m112 = 3;
    worm->m216 = 0;
    worm->m104 = 3;
}
