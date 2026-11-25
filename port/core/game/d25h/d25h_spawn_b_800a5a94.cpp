#include "w3d_ptr.h"
#line 1 "d25h_spawn_b_800a5a94.cpp"
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
extern "C" void w3d_string_finish_8020c5c4(Ptr32<String>);
extern "C" void w3d_string_release_80341588(Ptr32<String>);
extern "C" void w3d_string_free_8020bb2c(Ptr32<void>);
struct String {
    Ptr32<char> text;
    String();
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &);
    ~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
    void operator=(const String &o) {
        *(Ptr32<unsigned short>)(o.text - 6) += 1;
        Ptr32<unsigned short> rep = (Ptr32<unsigned short>)(text - 6);
        if (--*rep == 0) w3d_string_free_8020bb2c(rep);
        text = o.text;
    }
};
extern "C" int fn_8020c510(Ptr32<String>, Ptr32<const char>, ...);
struct Descriptor_80178474 {
    Ptr32<void> value;
    unsigned tag;
    Descriptor_80178474() : value(0), tag(58280) {}
    ~Descriptor_80178474();
};
struct Worm;
struct WormVt { Ptr32<void> u[3]; Ptr32<void (Ptr32<Worm>)> addref; Ptr32<void (Ptr32<Worm>)> release; };
struct Worm {
    Ptr32<WormVt> vt;
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
    Ptr32<Worm> p;
    template <class W3dU> Held(Ptr32<W3dU> w3d_p) : Held((Worm *)w3d_p.get()) {}
 Held(Worm *o) : p(o) { if (p) p->vt->addref(p); }
    Held(const Held &);
    ~Held() { if (p) p->vt->release(p); }
    Ptr32<Worm> operator->() { return p; }
};
extern "C" Ptr32<Worm> fn_800fc710(int, Ptr32<Descriptor_80178474>);
struct Arena;
extern Ptr32<Arena> lbl_804b1754;
extern "C" Ptr32<void> fn_801613f0(Ptr32<Arena>, unsigned);
struct Cache { unsigned short id; unsigned char u[6]; };
extern Cache lbl_804ae278;
extern "C" int fn_8015f5a0(Ptr32<Cache>, int);
extern "C" int fn_8016239c(Ptr32<void>);
extern "C" Ptr32<void> fn_800683fc(Ptr32<void>, unsigned short, Ptr32<const char>, int);
extern "C" Ptr32<void> fn_80342fa4(Ptr32<void>);
extern "C" Ptr32<Vec3> fn_80178ec4(Ptr32<void>);
extern const char lbl_80381238[], lbl_80381240[];
extern Ptr32<const char> lbl_803f4bf8[];
struct Spawner { unsigned char u[28]; Ptr32<void> res; };
inline void Put(Vec3 &to, const Vec3 &from) { to = from; }
extern "C" void w3d_d25h_spawn_800a5a94(Ptr32<Spawner> self, int team, unsigned char colour) {
    String name;
    Vec3 where;
    Vec3 zero(0.0f, 0.0f, 0.0f);
    Descriptor_80178474 desc;
    fn_8020c510(&name, lbl_80381238, team + 1);
    Ptr32<void> m = fn_801613f0(lbl_804b1754, 12);
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


