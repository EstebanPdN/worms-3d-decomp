#include "w3d_ptr.h"
#line 1 "d41d_worm_attachment_animation_v2_801388cc.cpp"
// d41d: 0x801388cc. Starts a worm's held attachment for its current weapon
// when the weapon resource is of the wanted class and has a name, then plays
// two named animations with a null name that is tested each time. Class
// fields are partial views.
struct Class { char pad[20]; Ptr32<Class> base; };
inline int isa(Ptr32<const Class> c, Ptr32<const Class> t) {
    for (; c != t; c = c->base) if (c == c->base) return 0;
    return 1;
}
struct Obj { Ptr32<Ptr32<void>> vtable; };
struct Res { Ptr32<Ptr32<void>> vtable; char pad[264]; Ptr32<const char> a; Ptr32<const char> b; Ptr32<Class> cls() { return ((Ptr32<Ptr32<Class> (Ptr32<Res>)>)vtable[5])(this); } };
struct Info { char pad[132]; int type; };
struct Self { char pad[28]; Ptr32<Obj> mesh; char pad1[80]; int worm; char pad2[48]; Ptr32<Obj> att; char pad3[304]; int c472; char pad4[12]; int c488; char pad5[76]; int f568; };
extern "C" Ptr32<Info> s8_index_query_800fc6dc(int);
extern "C" int w3d_auto_800fc330(Ptr32<Ptr32<const char>>, Ptr32<Ptr32<Res>>);
extern "C" void w3d_auto_8013f08c(Ptr32<Self>);
extern "C" int w3d_s20_forward_global5_800e5cf0(Ptr32<Obj>, Ptr32<const char>, Ptr32<const char>, int, int);
extern "C" int w3d_worm_play_801359ec(Ptr32<Self>, Ptr32<Obj>, Ptr32<const char>, Ptr32<int>, float, float, float);
extern Class cls_80368468[];
extern Ptr32<const char> lbl_803eb63c[];
inline Ptr32<Res> res_for(Ptr32<Ptr32<const char>> key) { Ptr32<Res> r; w3d_auto_800fc330(key, &r); return r; }

inline void anim(Ptr32<Self> self, Ptr32<const char> name) {
    if (self->att) {
        if (name)
        w3d_worm_play_801359ec(self, self->att, name, &self->c488, 1.0f, 0.0f, 0.0f);
    }
    if (name) w3d_worm_play_801359ec(self, self->mesh, name, &self->c472, 1.0f, -1.0f, 0.0f);
}
extern "C" void w3d_d41d_worm_attachment_animation_v2_801388cc(Ptr32<Self> self) {    Ptr32<const char> n = 0;

    Ptr32<Res> r = res_for(&lbl_803eb63c[s8_index_query_800fc6dc(self->worm)->type]);
    if (isa(r->cls(), cls_80368468) && ((Ptr32<unsigned short>)r->b)[-2] != 0) {
        w3d_auto_8013f08c(self);
        self->f568 = w3d_s20_forward_global5_800e5cf0(self->att, r->a, r->b, -1, 0);
    }
    anim(self, n);
}


