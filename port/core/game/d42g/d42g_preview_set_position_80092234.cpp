#include "w3d_ptr.h"
#line 1 "d42g_preview_set_position_80092234.cpp"
// GWMP8P rev0 0x80092234. Preview camera placement: stores the position,
// projects it through two pairs of rows into two screen offsets, then resets
// the chunk cursor at the truncated position. Field names inferred.
struct Vec3 {
    float x, y, z;
    void Set(float a, float b, float c) { Ptr32<Vec3> p = this; x = a; p->y = b; p->z = c; }
};
struct Vec2 { float x, y; void Set(float a, float b) { x = a; y = b; } };
inline float Dot(const Vec3 &a, const Vec3 &b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
struct Cursor {
    int unknown00;
    int a, b, c;
    void Clear() { a = 0; b = 0; c = 0; }
};
extern "C" void w3d_cx9c_chunk_cursor_80343bc0(Ptr32<Cursor>, int, int, int);
struct Preview {
    char unknown00[28];
    Cursor cursor;
    char unknown44[356];
    Vec3 rowA, rowB, rowC, rowD;
    Vec2 off0, off1;
    Vec2 out0, out1;
    char unknown480[40];
    Vec3 position;
};
extern "C" void d42g_preview_set_position_80092234(Ptr32<Preview> self, Ptr32<const Vec2> a, Ptr32<const Vec2> b, float x, float y, float z)
{
 self->position.Set(x, y, z);
 { float u = Dot(self->position, self->rowA) + self->off0.x - a->x; float v = Dot(self->position, self->rowB) + self->off0.y - a->y; self->out0.Set(u, v); }
 { float u = Dot(self->position, self->rowC) + self->off1.x - b->x; float v = Dot(self->position, self->rowD) + self->off1.y - b->y; self->out1.Set(u, v); }
 Ptr32<Cursor> c = &self->cursor;
 int ix = (int)x, iy = (int)y, iz = (int)z;
 c->Clear();
 w3d_cx9c_chunk_cursor_80343bc0(c, ix, iy, iz);
 c->c = 0;
}


