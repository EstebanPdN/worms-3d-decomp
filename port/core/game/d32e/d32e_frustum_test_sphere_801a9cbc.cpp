#include "w3d_ptr.h"
#line 1 "d32e_frustum_test_sphere_801a9cbc.cpp"
// (Worms 3D GameCube PAL, 0x801a9cbc).
//
// Tests a sphere against a view frustum: transforms it into view space, then
// checks six planes (a general plane loop, or the axis-aligned symmetric
// form when the ortho flag at +60 is set). Returns 0 outside, 1 intersecting
// (and sets the flag at +44), 2 fully inside.

struct Sphere { float x, y, z, r; };
struct Plane { float a, b, c, d; };
extern "C" void w3d_d24e_transform_sphere_801f5214(Ptr32<Sphere> out, Ptr32<void> m, Ptr32<const Sphere> in);
// Partial view: a culling camera. Field names are inferred from their use.
struct Frustum {
    char u0[44]; int outside; char u48[8]; Ptr32<void> xf; int ortho;
    Plane plane[6];
};
static inline float Abs(float v) { *(Ptr32<int>)&v &= 0x7fffffff; return v; }
// Port de dos pantallas (Mac, W3D_DUAL): en los menús el lienzo sigue una pantalla más por debajo de la de arriba (la de
// abajo), pero la cámara del FE solo ve la de arriba. Los marcos del FE que acaban abajo y tienen caja de medida propia
// se descartaban y no se dibujaban (los fondos de Land Objects y Sudden Death, Team Members, los marcos de los
// desplegables; pedido del dueño, 2026-11-07). Ahí todo cuenta como dentro: los menús son pocas piezas y lo que cae
// fuera del lienzo lo recorta la GPU. core/native/fe_layout.cpp, w3d_cull_tall.
extern "C" int w3d_cull_tall(void);
extern "C" int w3d_d32e_frustum_test_sphere_801a9cbc(Ptr32<Frustum> self, Ptr32<const Sphere> in)
{
    if (w3d_cull_tall()) { self->outside = false; return 2; }   // como la salida «dentro» de abajo
    Sphere s;
    w3d_d24e_transform_sphere_801f5214(&s, self->xf, in);
    bool inside = true;
    if (self->ortho) {
        float d = self->plane[4].d - s.z;
        if (Abs(d) < s.r) inside = false; else if (d < 0.0f) return 0;
        d = s.z + self->plane[5].d;
        if (Abs(d) < s.r) inside = false; else if (d < 0.0f) return 0;
        float e;
        {
            float a = self->plane[0].c * s.z, b = self->plane[0].a * s.x;
            d = a - b; e = a + b;
        }
        if (Abs(d) < s.r) inside = false; else if (d < 0.0f) return 0;
        if (Abs(e) < s.r) inside = false; else if (e < 0.0f) return 0;
        {
            float a = self->plane[2].c * s.z, b = self->plane[2].b * s.y;
            d = a - b; e = a + b;
        }
        if (Abs(d) < s.r) inside = false; else if (d < 0.0f) return 0;
        if (Abs(e) < s.r) inside = false; else if (e < 0.0f) return 0;
    } else {
        s.z = -s.z;
        Ptr32<Sphere> c = &s;
        Ptr32<Plane> p = self->plane;
        for (int i = 0; i < 6; i++, p++) {
            float d = c->x * p->a + c->y * p->b + c->z * p->c + p->d;
            if (Abs(d) < s.r) inside = false; else if (d < 0.0f) return 0;
        }
    }
    self->outside = inside ? false : true;
    if (inside) return 2;
    return 1;
}


