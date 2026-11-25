// GWMP8P rev0 0x80009b04. Builds a queue for a hop to a target when weapon
// 42 is usable: the target must be far enough and on an empty grid cell, the
// fitted flight must be reachable, and three traced segments must all run
// their full length. Names are inferred from the original instructions.
inline void *operator new(unsigned int, void *place) { return place; }
extern "C" float sqrt_802e82c0(float);
struct Res;
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Res &o);
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Res operator-(const Vec &o) const;
    Vec operator/(float d) const { float f = 1.0f / d; Vec r; r.x = x * f; r.y = y * f; r.z = z * f; return r; }
    float Length() const { return sqrt_802e82c0(x * x + y * y + z * z); }
    float Length2() const { return x * x + y * y + z * z; }
};
struct Res {
    float x, y, z;
    Res(float a, float b, float c) { x = a; y = b; z = c; }
    Vec operator/(float d) const { float f = 1.0f / d; Vec r; r.x = x * f; r.y = y * f; r.z = z * f; return r; }
};
inline Vec::Vec(const Res &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
inline Res Vec::operator-(const Vec &o) const { return Res(x - o.x, y - o.y, z - o.z); }
inline Vec Plain(const Res &v) { return Vec(v.x, v.y, v.z); }
struct Grid;
struct Queue { char unknown00[16]; void **vtable; Queue(); };
extern float g_clock_804aa570;
extern Grid *w3d_grid_804b1758;
extern int w3d_game_804aa6dc, w3d_busy_804aa6e0, w3d_lock_804aa6e4;
extern unsigned int g_hit_time_804b1764;
extern Vec g_centre_8041d3a0;
extern "C" int w3d_ai_weapon_available(int);
extern "C" void *w3d_auto_8001523c(unsigned int);
extern "C" int cc26a_grid_select_layer_8001e328(Grid *, const Vec *, short *, short *, int *);
extern "C" unsigned char *cc26a_grid_byte_cell_8001dff8(Grid *, int, int, int);
extern "C" Vec k5a_vec_offset_8001bbb0(const Vec *);
extern "C" Vec fn_8001bc1c(const Vec *, const Vec *);
extern "C" Vec k2a_apply_fit_8001c0d8(const Vec *, const Vec *);
extern "C" void w3d_trace_800b0824(const Vec *, const Vec *, const Vec *, int, int);
extern "C" void w3d_d28a_command_vector_append_80003424(Queue *, const Vec *, int);
inline bool Ready() { return w3d_game_804aa6dc != 0 && w3d_busy_804aa6e0 == 0 && w3d_lock_804aa6e4 == 0; }
extern "C" int w3d_d29a_hop_path_build_80009b04(Queue **out, const Vec *from, const Vec *to)
{
    if (w3d_ai_weapon_available(42) && Ready()) {
        Vec p = Plain(*to - *from);
        g_clock_804aa570 += 100.0f;
        if (p.Length() < 30.0f) return 0;
        short cx, cy; int layer;
        if (cc26a_grid_select_layer_8001e328(w3d_grid_804b1758, to, &cx, &cy, &layer)
            && !*cc26a_grid_byte_cell_8001dff8(w3d_grid_804b1758, cx, cy, layer)) {
            Vec a = k5a_vec_offset_8001bbb0(from);
            Vec b = fn_8001bc1c(&a, to);
            if (!(b.Length2() > 1.0f)) {
                Vec u = (a - g_centre_8041d3a0) / 1000.0f;
                w3d_trace_800b0824(&g_centre_8041d3a0, &u, &Vec(0.0f, 0.0f, 0.0f), 1000, 1);
                if (g_hit_time_804b1764 > 999) {
                    Vec dir(b);
                    float n = dir.Length2();
                    if (n != 0.0f) {
                        float f = 1.0f / sqrt_802e82c0(n);
                        dir.x *= f; dir.y *= f; dir.z *= f;
                    }
                    Vec m = k2a_apply_fit_8001c0d8(&a, &dir);
                    Vec w = (m - a) / 1000.0f;
                    w3d_trace_800b0824(&a, &w, &Vec(0.0f, 0.0f, 0.0f), 1000, 1);
                    if (g_hit_time_804b1764 > 999) {
                        Vec v = (*to - m) / 1000.0f;
                        w3d_trace_800b0824(&m, &v, &Vec(0.0f, 0.0f, 0.0f), 1000, 1);
                        if (g_hit_time_804b1764 <= 999) return 0;
                        *out = new (w3d_auto_8001523c(48)) Queue;
                        w3d_d28a_command_vector_append_80003424(*out, to, 8);
                        w3d_d28a_command_vector_append_80003424(*out, &a, 6);
                        w3d_d28a_command_vector_append_80003424(*out, &m, 9);
                        w3d_d28a_command_vector_append_80003424(*out, to, 9);
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
