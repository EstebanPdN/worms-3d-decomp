#include "w3d_ptr.h"
#line 1 "d26h_jetpack_graphics_init_800ade2c.cpp"
// GWMP8P rev0 0x800ade2c. Jetpack graphics setup. Names are inferred. Key is
// a one-word property name passed by address; the bound handle is one word
// with a user copy constructor. The handle and key live in an inline helper,
// which gives the frame its original block; the rotation vector is filled
// through a pointer, as the saved register in the original shows.
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) { x = a; y = b; z = c; }
    void Set(float a, float b, float c) { x = a; y = b; z = c; }
};
struct Obj;
struct ObjVt {
    Ptr32<void> u[3];
    Ptr32<void (Ptr32<Obj>)> addref;
    Ptr32<void (Ptr32<Obj>)> release;
    Ptr32<void> u20[15];
    Ptr32<void (Ptr32<Obj>, Ptr32<const Vec3>, int)> colour;  // +80
    Ptr32<void (Ptr32<Obj>, Ptr32<const Vec3>, int)> place;   // +84
    Ptr32<void (Ptr32<Obj>, int)> show;                  // +88
    Ptr32<void (Ptr32<Obj>, Ptr32<Obj>, Ptr32<void>)> attach;      // +92
};
struct Obj { Ptr32<ObjVt> vt; };
struct Ref { Ptr32<Obj> p; };
struct String;
extern "C" void w3d_string_finish_8020c5c4(Ptr32<String>);
extern "C" void w3d_string_release_80341588(Ptr32<String>);
struct String {
    Ptr32<void> p;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &);
    ~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
};
extern "C" int w3d_handle_load_8015adf4(Ptr32<const String>, Ptr32<Ref>, unsigned char);
struct Fx;
struct FxVt { Ptr32<void> u[23]; Ptr32<void (Ptr32<Fx>, Ptr32<const char>, Ptr32<void>)> sound; };
struct Fx { Ptr32<FxVt> vt; };
struct Services { unsigned char u0[108]; Ptr32<Fx> fx; };
extern Ptr32<Services> lbl_804b1788;
struct Message;
extern "C" Ptr32<Message> arena_alloc_801613f0(Ptr32<void>, int);
extern "C" unsigned message_id_8015f5a0(Ptr32<void>, int);
extern "C" Ptr32<Message> target_init_801190b4(Ptr32<Message>, unsigned short, int);
extern "C" int message_post_8016239c(Ptr32<Message>);
extern Ptr32<void> g_arena_804b1754;
extern unsigned char id_804ae3dc[8];
extern Ptr32<void> g_804aac84; extern Ptr32<void> g_804aac88;
struct Handle {
    Ptr32<Obj> p;
    Handle() { p = 0; }
    Handle(const Handle &);
    ~Handle() { if (p) p->vt->release(p); }
};
struct Key { Ptr32<const char> name; template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((const char *)w3d_p.get()) {}
 Key(const char *n) { name = n; } };
extern "C" int lookup_800fc1b0(Ptr32<Key>, Ptr32<Handle>);
extern "C" Ptr32<Obj> as_float_80342a74(Ptr32<Obj>);
inline void Bind(Ptr32<Obj> &slot, Ptr32<const char> name) {
    Key k(name);
    Handle h;
    lookup_800fc1b0(&k, &h);
    Ptr32<Obj> o = as_float_80342a74(h.p);
    if (o) o->vt->addref(o);
    if (slot) slot->vt->release(slot);
    slot = o;
}
struct Jet {
    unsigned char u0[20];
    int id;         // +20
    unsigned char u24[8];
    Ref body;       // +32
    Ref flameA;     // +36
    Ref flameB;     // +40
    Ref smokeA;     // +44
    Ref smokeB;     // +48
    int a[3];       // +52
    int b[3];       // +64
    int u76[2];
    int s84, s88, s92, s96; // +84
    Vec3 scale;     // +100
    Ptr32<Obj> thrust;    // +112
};
extern "C" void d26h_jetpack_graphics_init_800ade2c(Ptr32<Jet> self) {
    { String n("Jetpack"); w3d_handle_load_8015adf4(&n, &self->body, 255); }
    { String n("Jetpack.Afterburn"); w3d_handle_load_8015adf4(&n, &self->flameA, 255); }
    { String n("Jetpack.Afterburn"); w3d_handle_load_8015adf4(&n, &self->flameB, 255); }
    self->flameA.p->vt->show(self->flameA.p, 0);
    self->flameB.p->vt->show(self->flameB.p, 0);
    Vec3 off;
    Ptr32<Vec3> q = &off;
    q->x = 1.5707964f;
    float zero = 0.0f;
    q->y = zero;
    q->z = zero;
    self->flameA.p->vt->colour(self->flameA.p, q, 0);
    self->flameB.p->vt->colour(self->flameB.p, q, 0);
    self->body.p->vt->attach(self->body.p, self->flameA.p, g_804aac84);
    self->body.p->vt->attach(self->body.p, self->flameB.p, g_804aac88);
    { String n("Rocket.Flames"); w3d_handle_load_8015adf4(&n, &self->smokeA, 255); }
    { String n("Rocket.Flames"); w3d_handle_load_8015adf4(&n, &self->smokeB, 255); }
    float s = 10.0f;
    self->scale.Set(s, zero, s);
    self->smokeA.p->vt->place(self->smokeA.p, &self->scale, 0);
    self->smokeB.p->vt->place(self->smokeB.p, &self->scale, 0);
    self->body.p->vt->attach(self->body.p, self->smokeA.p, g_804aac84);
    self->body.p->vt->attach(self->body.p, self->smokeB.p, g_804aac88);
    {
        Ptr32<Message> m = arena_alloc_801613f0(g_arena_804b1754, 12);
        message_post_8016239c(target_init_801190b4(m, message_id_8015f5a0(id_804ae3dc, 1), self->id));
    }
    for (int i = 0; i < 3; i++) {
        self->a[i] = 0;
        self->b[i] = 0;
    }
    if (lbl_804b1788->fx) {
        lbl_804b1788->fx->vt->sound(lbl_804b1788->fx, "Jetpack.Loop1", &self->s84);
        lbl_804b1788->fx->vt->sound(lbl_804b1788->fx, "Jetpack.Loop2", &self->s88);
        lbl_804b1788->fx->vt->sound(lbl_804b1788->fx, "Jetpack.Start", &self->s92);
        lbl_804b1788->fx->vt->sound(lbl_804b1788->fx, "Jetpack.Super", &self->s96);
    }
    Bind(self->thrust, "Jetpack.SuperThrustMax");
}


