#include "w3d_ptr.h"
#line 1 "d27i_weapon_icon_grid_8012fa4c.cpp"
// GWMP8P rev0 0x8012fa4c. Fills once the texture coordinates and sizes of
// the 8 by 8 weapon icon sheet FE.WeaponIcons, top row first, with half
// texel inset.
struct String {
    Ptr32<char> text;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &);
    ~String();
};
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
struct Object;
struct ObjectVt { char u0[12]; Ptr32<void (Ptr32<Object>)> add; Ptr32<void (Ptr32<Object>)> release; };
struct Object { Ptr32<ObjectVt> vt; char u4[40]; unsigned short w; unsigned short h; };
struct Ref {
    Ptr32<Object> p;
    template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Object *)w3d_p.get()) {}
 Ref(Object *q) { p = q; if (p) p->vt->add(p); }
    Ref(const Ref &);
    ~Ref() { if (p) p->vt->release(p); }
};
struct Self { char u0[212]; int ready; };
struct UV { float u, v; };
extern "C" Ptr32<void> find_8015ae3c(const String &);
extern "C" Ptr32<Object> cast_80343808(Ptr32<void>);
extern "C" Ptr32<UV> top_80171fa0(Ptr32<Object>);
extern "C" Ptr32<UV> bot_80171ff8(Ptr32<Object>);
extern const char name_8039dd20[];
extern "C" void d27i_weapon_icon_grid_8012fa4c(Ptr32<Self> self) {
    if (self->ready == 0) {
        Ref tex(cast_80343808(find_8015ae3c(String(name_8039dd20))));
        Ptr32<UV> a = top_80171fa0(tex.p);
        Ptr32<UV> b = bot_80171ff8(tex.p);
        float fw = (float)tex.p->w;
        float fh = (float)tex.p->h;
        float du = 1.0f / fw;
        float dv = 1.0f / fh;
        float su = 0.125f - du;
        float sv = 0.125f - dv;
        float ou = 0.5f / fw;
        float ov = 0.5f / fh;
        int i = 0;
        for (int row = 7; row >= 0; row--) {
            for (unsigned col = 0; col < 8; col++) {
                a[i].u = (float)col * 0.125f + ou;
                a[i].v = (float)row * 0.125f + ov;
                b[i].u = su;
                b[i].v = sv;
                i++;
            }
        }
        self->ready = 1;
    }
}


