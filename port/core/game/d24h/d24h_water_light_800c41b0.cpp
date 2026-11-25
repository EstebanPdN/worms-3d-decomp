#include "w3d_ptr.h"
#line 1 "d24h_water_light_800c41b0.cpp"
// Water light update (Worms 3D GameCube PAL, 0x800c41b0, 504 bytes).
//
// Rotates the water light with time and hands two vectors to three services,
// then posts a message. Built with -mps-float (two saved FPRs in a non-leaf
// function). Service and field names are inferred; the literal pool at
// 0x80383480 follows first use.

struct Vec3 {
    float x, y, z;
    Vec3(float ax, float ay, float az) { x = ax; y = ay; z = az; }
};
struct Light;
struct LightVt { Ptr32<void> u0[11]; Ptr32<void (Ptr32<Light>, Ptr32<Vec3>)> setA; Ptr32<void (Ptr32<Light>, Ptr32<Vec3>)> setB; };
struct Light { Ptr32<LightVt> vt; };
struct Services { unsigned char u0[48]; Ptr32<Light> l48; unsigned char u52[84]; Ptr32<Light> l136; Ptr32<Light> l140; };
extern Ptr32<Services> lbl_804b1788;
extern float lbl_804aade8;
extern float lbl_804aadec;
struct Key {
    Ptr32<const char> name;
    template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((const char *)w3d_p.get()) {}
 Key(const char *n) { name = n; }
    inline void SetFloat(float value);
};
extern "C" int w3d_float_write_800fc4c8(Ptr32<Key>, float);
inline void Key::SetFloat(float value) { w3d_float_write_800fc4c8(this, value); }
extern "C" float fn_802e86d4(float);
extern "C" float fn_802e88ac(float);
struct Arena;
extern Ptr32<Arena> lbl_804b1754;
extern "C" Ptr32<void> fn_801613f0(Ptr32<Arena>, unsigned);
struct Cache { unsigned short id; unsigned char u[6]; };
extern Cache lbl_804ae78c;
extern "C" unsigned short fn_8015f5a0(Ptr32<Cache>, int);
extern "C" int fn_8016239c(Ptr32<void>);
extern Ptr32<void> lbl_8040db38[];
struct Message { unsigned short id; Ptr32<void> vt; };
extern const char lbl_80383470[];   // "Water.Level"
struct Water { unsigned char u0[32]; float angle; };
extern "C" int w3d_d24h_water_light_800c41b0(Ptr32<Water> self, unsigned time) {
    self->angle = (float)(time % 300000) * 6.2831855f / 300000.0f;
    Key(lbl_80383470).SetFloat(lbl_804aade8);
    float c = fn_802e86d4(self->angle) * 120.0f;
    Vec3 a(c, 80.0f, fn_802e88ac(self->angle) * 120.0f);
    float c2 = fn_802e86d4(self->angle) * 240.0f;
    Vec3 b(c2, lbl_804aadec, fn_802e88ac(self->angle) * 240.0f);
    lbl_804b1788->l48->vt->setA(lbl_804b1788->l48, &a);
    lbl_804b1788->l48->vt->setB(lbl_804b1788->l48, &b);
    lbl_804b1788->l136->vt->setA(lbl_804b1788->l136, &a);
    lbl_804b1788->l136->vt->setB(lbl_804b1788->l136, &b);
    lbl_804b1788->l140->vt->setA(lbl_804b1788->l140, &a);
    lbl_804b1788->l140->vt->setB(lbl_804b1788->l140, &b);
    Ptr32<Message> m = (Ptr32<Message>)fn_801613f0(lbl_804b1754, 8);
    m->id = fn_8015f5a0(&lbl_804ae78c, 1);
    m->vt = lbl_8040db38;
    fn_8016239c(m);
    return 0;
}


