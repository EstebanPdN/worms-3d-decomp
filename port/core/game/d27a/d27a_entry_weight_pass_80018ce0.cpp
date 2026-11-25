#include "w3d_ptr.h"
#line 1 "d27a_entry_weight_pass_80018ce0.cpp"
// GWMP8P rev0 0x80018ce0. Updates every table entry's weight: entries of
// opposite sign within 100 units lower it, and an entry with none nearer
// than 1000 gains a settings-scaled share. Names are inferred from the
// original instructions.
extern "C" float sqrt_802e82c0(float);
struct Vec { float x, y, z; };
struct Entry { char unknown00[12]; float weight; Vec position; };
struct List {
    Ptr32<Ptr32<Entry>> begin; Ptr32<Ptr32<Entry>> end;
    int size() const { return end - begin; }
    Ptr32<Entry> & operator[](int i) { return begin[i]; }
};
struct Settings { char unknown00[104]; float a; char unknown6c[56]; float b; };
extern Ptr32<List> w3d_table_804aa750;
extern Ptr32<Settings> w3d_settings_804aa6d8;
extern float g_score_8041d3b8[];
inline float Distance(const Vec &a, const Vec &b)
{
    float dx = a.x - b.x, dy = a.y - b.y, dz = a.z - b.z;
    return sqrt_802e82c0(dx * dx + dy * dy + dz * dz);
}
extern "C" void w3d_d27a_entry_weight_pass_80018ce0()
{
    int n = w3d_table_804aa750->size();
    for (int i = 0; i < n; i++) {
        float nearest = 33554432.0f;
        Ptr32<Entry> a = (*w3d_table_804aa750)[i];
        g_score_8041d3b8[i] = 0.0f;
        const Vec &pa = a->position;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            Ptr32<Entry> b = (*w3d_table_804aa750)[j];
            float d = Distance(pa, b->position);
            if ((a->weight > 0.0f) != (b->weight > 0.0f)) {
                if (d < nearest) nearest = d;
                if (d < 100.0f)
                    g_score_8041d3b8[i] -= (1.0f - d / 100.0f) * b->weight * w3d_settings_804aa6d8->a;
            }
        }
        if (nearest >= 1000.0f)
            g_score_8041d3b8[i] += a->weight * w3d_settings_804aa6d8->b;
    }
    for (int i = 0; i < n; i++)
        (*w3d_table_804aa750)[i]->weight += g_score_8041d3b8[i];
}


