#include "w3d_ptr.h"
#line 1 "d29a_side_step_plan_8000feb8.cpp"
// GWMP8P rev0 0x8000feb8. Looks for a side step: from the worm's position
// along the path direction it tries rotated targets on the grid until a
// queue reaches one, then prepends the origin and stores the queue on the
// plan. Names are inferred from the original instructions.
inline void *operator new(__SIZE_TYPE__, void *place) { return place; }
extern "C" float sqrt_802e82c0(float);
struct Res;
struct Vec {
    float x, y, z;
    Vec() {}
    void Sum(const Vec &a, const Vec &b) { x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; }
    void Copy(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void Set(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Res &o);
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Res operator-(const Vec &o) const;
    float Length() const { return sqrt_802e82c0(x * x + y * y + z * z); }
};
struct Res { float x, y, z; Res(const Vec &a, const Vec &b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; } };
inline Vec::Vec(const Res &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
inline Res Vec::operator-(const Vec &o) const { return Res(*this, o); }
struct Words { int x, y, z; bool operator==(const Words &o) const { return x == o.x && y == o.y && z == o.z; } };
inline bool Same(const Vec &a, const Vec &b) { return *(Ptr32<const Words>)&a == *(Ptr32<const Words>)&b; }
struct Row { float x, y, z; };
struct Rotation;
extern "C" void w3d_construct_801f6034(Ptr32<Rotation>);
extern "C" void w3d_rotate_rows_y_801f61a0(Ptr32<Rotation>, float);
struct Rotation {
    Row row[3];
    void Init() { w3d_construct_801f6034(this); }
    void RotateY(float a) { w3d_rotate_rows_y_801f61a0(this, a); }
    const Row &R(int i) const { return row[i]; }
};
inline Vec &Ref(Vec &v) { return v; }
inline void Mul(Vec &o, const Rotation &m, const Vec &v)
{
    o.x = v.x * m.R(0).x + v.y * m.R(1).x + v.z * m.R(2).x;
    o.y = v.x * m.R(0).y + v.y * m.R(1).y + v.z * m.R(2).y;
    o.z = v.x * m.R(0).z + v.y * m.R(1).z + v.z * m.R(2).z;
}
struct Grid;
struct Queue {
    char unknown00[20];
    Ptr32<Ptr32<void>> start; Ptr32<Ptr32<void>> finish;
    char unknown1c[16];
    int refs;           /* +44 */
    int Count() const { return finish - start; }
};
struct Handle { int kind; Ptr32<Queue> object; Ptr32<Queue> Get() const { return object; } };
struct Worm { char unknown00[16]; Vec position; };
struct Bodies { Ptr32<Ptr32<Worm>> items; Ptr32<Worm> & operator[](int i) { return items[i]; } };
struct Plan {
    char unknown00[16];
    int index;           /* +16 */
    char unknown14[52];
    Handle first;        /* +72 */
    Handle second;       /* +80 */
};
extern int w3d_game_804aa6dc, w3d_busy_804aa6e0;
extern Ptr32<Bodies> w3d_bodies_804aa750;
extern Ptr32<Grid> w3d_grid_804b1758;
extern "C" Ptr32<const Vec> w3d_move_queue_current_step(Ptr32<Queue>);
// k2a_grid_position_8001f9f0 devuelve una estructura trivial de tres floats (K2aVec3): en ARM va en s0-s2. Declarada con
// este Vec (constructor de copia propio), el resultado iba por un puntero oculto en r0 y los argumentos se corrían:
// la rejilla llegaba como "celda" y 8001e328 leía basura de la pila (cuelgue de la rejilla de rutas de la IA, v18-v21).
struct GridPos { float x, y, z; };
extern "C" GridPos k2a_grid_position_8001f9f0(Ptr32<Grid>, Ptr32<const Vec>);
extern "C" int w3d_d28a_path_queue_build_timed_80009674(Ptr32<Ptr32<Queue>>, Ptr32<const Vec>, Ptr32<const Vec>, int, float);
extern "C" void w3d_d28a_command_vector_prepend_80003834(Ptr32<Queue>, Ptr32<const Vec>, int);
inline bool Ready() { return w3d_game_804aa6dc != 0 && w3d_busy_804aa6e0 == 0; }
extern "C" int w3d_d29a_side_step_plan_8000feb8(Ptr32<Plan> self, float radius)
{
    if (!Ready() || !self->first.Get() || !self->first.Get()->Count()) return 0;
    Vec pos((*w3d_bodies_804aa750)[self->index]->position);
    Vec d(*w3d_move_queue_current_step(self->first.Get()) - pos);
    Vec at(0.0f, 0.0f, 0.0f);
    Vec target;
    if (Same(at, d)) { target.Set(1.0f, 0.0f, 0.0f); d = target; }
    float f = 1.0f / d.Length();
    float dx = d.x * f, dy = d.y * f, dz = d.z * f;
    target.x = dx * radius; target.y = dy * radius; target.z = dz * radius;
    Vec t;
    t.Sum(pos, target);
    at.Copy(t);
    d.x = dx * 160.0f; d.y = dy * 160.0f; d.z = dz * 160.0f;
    Ptr32<Queue> q = 0;
    int found;
    float s;
    for (float a = 0.0f; a <= 0.7853982f; a += 0.31415927f) {
        for (s = -1.0f; s <= 1.0f; s += 2.0f) {
            float angle = a * s;
            Rotation m;
            Rotation &rm = m;
            rm.Init();
            rm.RotateY(angle);
            Vec r;
            Mul(Ref(r), rm, d);
            t.Copy(r);
            r.Sum(pos, t);
            target.x = r.x; target.y = r.y; target.z = r.z;
            { GridPos g = k2a_grid_position_8001f9f0(w3d_grid_804b1758, &target); new (&t) Vec(g.x, g.y, g.z); }
            target = t;
            found = w3d_d28a_path_queue_build_timed_80009674(&q, &at, &target, 50, 0.0f);
            if (found) break;
        }
        s = a;
        if (found) goto hit;
    }
    goto done;
hit:
    w3d_d28a_command_vector_prepend_80003834(q, &at, 2);
done:
    if (q) { self->second.object = q; q->refs++; }
    return q != 0;
}


