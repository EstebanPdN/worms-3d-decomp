#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_misc_c.c"
extern int w3d_auto_80178d1c(Ptr32<void>);
extern void s8_visibility_800a3c24(Ptr32<void>);

struct S19A { char pad0[96]; Ptr32<void> handle; };

int s19_handle_is_one_800a14f4(Ptr32<struct S19A> p) {
    return w3d_auto_80178d1c(p->handle) == 1;
}

struct S19Vis { char pad0[28]; int visible; };

void s19_visibility_hide_800a3bb4(Ptr32<struct S19Vis> p) {
    if (p->visible) {
        p->visible = 0;
        s8_visibility_800a3c24(p);
    }
}

void s19_visibility_show_800a3bec(Ptr32<struct S19Vis> p) {
    if (!p->visible) {
        p->visible = 1;
        s8_visibility_800a3c24(p);
    }
}

struct S19Mode { char pad0[44]; int mode; };

int s19_mode_is_two_800cfc98(Ptr32<struct S19Mode> p) {
    return p->mode == 2;
}

struct S19V3 { float x, y, z; };
struct S19Pts { char pad0[28]; Ptr32<struct S19V3> items; };
struct S19PtsRec { char pad0[28]; Ptr32<char> items; };

Ptr32<struct S19V3> s19_vec3_copy_800d0f74(Ptr32<struct S19V3> dst, Ptr32<struct S19PtsRec> src, int i) {
    Ptr32<struct S19V3> s = (Ptr32<struct S19V3>)(src->items + i * 28);
    float x = s->x;
    float y = s->y;
    float z = s->z;
    dst->x = x;
    dst->y = y;
    dst->z = z;
    return dst;
}

struct S19Pair { char pad0[84]; struct S19V3 a; struct S19V3 b; };

void s19_set_vec_pair_800dc3dc(Ptr32<struct S19Pair> p, Ptr32<struct S19V3> va, Ptr32<struct S19V3> vb) {
    p->b = *va;
    p->a = *vb;
}

struct S19Inner { int x, y, z; };
struct S19Reset { int pad0; int a, b, pad12, c; struct S19Inner in; };

static inline void s19_clear_inner(Ptr32<struct S19Inner> q) {
    q->z = 0;
    q->y = 0;
    q->x = 0;
}

Ptr32<struct S19Reset> s19_reset_800b12c8(Ptr32<struct S19Reset> p) {
    p->a = 0;
    p->b = 0;
    p->c = 0;
    s19_clear_inner(&p->in);
    return p;
}

}
