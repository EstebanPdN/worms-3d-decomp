#include "w3d_ptr.h"
#line 1 "d27a_fade_out_update_80043f00.cpp"
// GWMP8P rev0 0x80043f00. Fades an effect between two colours and positions
// over a global duration, then updates its object. Names are inferred from
// the original instructions.
extern "C" float w3d_cx9c_sinf_802e88ac(float);
struct Vec {
    float x, y, z;
};
struct Colour {
    float r, g, b, a;
};
struct Bytes {
    unsigned char r, g, b, a;
    Bytes(int x, int y, int z, int w) { r = x; a = w; g = y; b = z; }
    void Set(const Colour &c)
    {
        r = (unsigned char)(c.r * 255.0f);
        g = (unsigned char)(c.g * 255.0f);
        b = (unsigned char)(c.b * 255.0f);
        a = (unsigned char)(c.a * 255.0f);
    }
};
struct Object {
    void w3d_r_f0() __asm__(W3D_SYM("_ZN6Object2f0Ev")); void w3d_r_f1() __asm__(W3D_SYM("_ZN6Object2f1Ev")); void w3d_r_f2() __asm__(W3D_SYM("_ZN6Object2f2Ev")); void w3d_r_f3() __asm__(W3D_SYM("_ZN6Object2f3Ev"));
    void w3d_r_f4() __asm__(W3D_SYM("_ZN6Object2f4Ev")); void w3d_r_f5() __asm__(W3D_SYM("_ZN6Object2f5Ev")); void w3d_r_f6() __asm__(W3D_SYM("_ZN6Object2f6Ev")); void w3d_r_f7() __asm__(W3D_SYM("_ZN6Object2f7Ev"));
    int w3d_r_SetPosition(Ptr32<const Vec>) __asm__(W3D_SYM("_ZN6Object11SetPositionEPK3Vec"));
 __attribute__((always_inline)) inline void f0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void f1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void f2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void f3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void f4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void f5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void f6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void f7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int SetPosition(Ptr32<const Vec> w3d_a0) { return ((int (*)(w3d_u32, Ptr32<const Vec>))w3d::vfn(this->w3d_vptr_Object, 10))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Object; };
struct Fade {
    char unknown00[32];
    Colour from;       /* +32 */
    Colour to;         /* +48 */
    int active;        /* +64 */
    int handle;        /* +68 */
    char unknown48[16];
    unsigned start;    /* +88 */
    char unknown5c[20];
    Vec position;      /* +112 */
};
extern unsigned g_duration_804aa97c;
extern Vec g_a_80427468, g_b_8042745c;
struct Tag { int unknown00; };
extern Tag g_name_804af3b4;
extern "C" Ptr32<Object> w3d_s20_lookup_handle_object_80164fc8(int);
extern "C" void w3d_hud_properties_8011adf8(Ptr32<Object>, Ptr32<const Bytes>, Ptr32<const void>);
inline float Clamp01(float v) { if (v < 0.0f) v = 0.0f; if (v > 1.0f) v = 1.0f; return v; }
extern "C" void w3d_d27a_fade_out_update_80043f00(Ptr32<Fade> self, unsigned now)
{
    Colour c = self->to;
    unsigned start = self->start;
    Bytes col(0, 0, 0, 1);
    Ptr32<const Vec> p;
    if (now >= start + g_duration_804aa97c) {
        self->active = 0;
        self->start = now;
        self->position = g_a_80427468;
        p = &self->position;
    } else {
        float t = (float)(now - start) / (float)g_duration_804aa97c;
        float s = w3d_cx9c_sinf_802e88ac(t * 1.5707964f + 1.5707964f);
        float lo = 0.0f;
        self->position.x = g_a_80427468.x + (g_b_8042745c.x - g_a_80427468.x) * s;
        self->position.y = (g_b_8042745c.y - g_a_80427468.y) * s + g_a_80427468.y;
        self->position.z = (g_b_8042745c.z - g_a_80427468.z) * s + g_a_80427468.z;
        s = t;
        if (s < lo) s = lo;
        float hi = 1.0f;
        if (s > hi) s = hi;
        float q = hi - s;
        c.r = self->to.r * s + self->from.r * q;
        c.g = self->to.g * s + self->from.g * q;
        c.b = self->to.b * s + self->from.b * q;
        if (c.r < lo) c.r = lo;
        if (c.g < lo) c.g = lo;
        if (c.b < lo) c.b = lo;
        if (c.r > hi) c.r = hi;
        if (c.g > hi) c.g = hi;
        p = &self->position;
        if (c.b > hi) c.b = hi;
    }
    Ptr32<Object> o = w3d_s20_lookup_handle_object_80164fc8(self->handle);
    o->SetPosition(p);
    col.Set(c);
    w3d_hud_properties_8011adf8(o, &col, &g_name_804af3b4);
}


