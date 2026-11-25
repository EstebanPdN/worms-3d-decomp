#include "w3d_ptr.h"
#line 1 "d40a_grid_finish_setup_8001d9ac.cpp"
// GWMP8P rev0 0x8001d9ac. Finishes the grid after loading: merges
// overlapping layers (0x8001d240), deleting the merged layer and closing the
// gap in the list, sums the layer areas into a cell size with a minimum,
// reads the two vectors from their property values, sets up each layer,
// refreshes the radius and drains the update queue, then computes the jump
// ranges (0x8001fa68). Layer members are real arrays of a class with a
// destructor; the two by-value copies in the area loop are written by the
// original and never read. Names are inferred.
//
// GWMP8P rev0 0x8001dd28 follows in the same source file: its literals start
// at 0x8036b80c, directly after this function's, 4 past an 8-byte boundary.
// It picks a random layer weighted by area, then a random cell of that layer
// and a random level, and retries up to 500 times until the cell is empty.
struct Vec {
    float x, y, z;
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Tint { int r, g, b; };
struct Rect { short x0, y0, x1, y1; };
extern "C" void entry_free_800152ac(Ptr32<void>);
extern "C" void heap_free_80015264(Ptr32<void>);
struct Entry {
    Ptr32<unsigned char> data;
    int unknown[3];
    ~Entry() { if (data) entry_free_800152ac(data); }
};
struct Layer {
    int unknown00;
    Vec lo;
    Vec hi;
    Rect rect;
    Entry a[2];
    Entry b[2];
    Entry c[2];
    ~Layer();
    Ptr32<unsigned char> Cells(int level) { return ((Ptr32<Entry>)w3d::G(((level << 4) + (unsigned)w3d::H(this) + 36)))->data; }
};
extern "C" void layer_shift_8001d1d8(Ptr32<Layer>);
inline Layer::~Layer() { layer_shift_8001d1d8(this); }
extern "C" void memcpy_802eee50(...);
struct LayerList {
    Ptr32<Ptr32<Layer>> first; Ptr32<Ptr32<Layer>> last;
    int size() const { return last - first; }
    Ptr32<Layer> & operator[](int i) { return first[i]; }
    void erase(Ptr32<Ptr32<Layer>> at)
    {
        if (at + 1 != last) { Ptr32<char> e = (Ptr32<char>)last - 4; int n = e - (Ptr32<char>)at; memcpy_802eee50(w3d::VA(at), w3d::VA(at + 1), n); }
        last--;
    }
};
struct Queue {
    Ptr32<int> first; Ptr32<int> last;
    bool empty() const { return first == last; }
};
extern "C" Ptr32<void> w3d_empty_80342fa4(Ptr32<void>);
extern "C" Ptr32<Tint> w3d_vector_80178ec4(Ptr32<void>);
struct Grid {
    char unknown00[28];
    Ptr32<Layer> top;
    char unknown20[40];
    Queue queue;
    char unknown50[8];
    LayerList layers;
    char unknown60[8];
    float size;
    char unknown6c[8];
    Tint low;
    Tint high;
    float area;
    char unknown90[8];
    Ptr32<void> low_value;
    Ptr32<void> high_value;
};
extern "C" int bounds_merge_8001d240(Ptr32<Layer>, Ptr32<Layer>);
extern "C" float sqrt_802e82c0(float);
extern "C" void layer_setup_8001d388(Ptr32<Layer>, Ptr32<Grid>);
extern "C" void refresh_radius_8001e49c(Ptr32<Grid>);
extern "C" void grid_8001f2cc(Ptr32<Grid>);
extern "C" void update_queue_8001ea34(Ptr32<Grid>);
extern "C" void jump_ranges_8001fa68(Ptr32<Grid>);
extern int g_804aa788;
extern "C" void w3d_d40a_grid_finish_setup_8001d9ac(Ptr32<Grid> self)
{
    int i;
    for (i = 0; i < self->layers.size(); i++) {
        Ptr32<Layer> first = self->layers[i];
        for (int j = i + 1; j < self->layers.size(); j++) {
            Ptr32<Layer> other = self->layers[j];
            if (bounds_merge_8001d240(first, other)) {
                if (other) {
                    other->~Layer();
                    heap_free_80015264(other);
                }
                self->layers.erase(&self->layers[j]);
                i = -1;
                break;
            }
        }
    }
    self->area = 0.0f;
    for (int k = 0; k < self->layers.size(); k++) {
        Ptr32<Layer> r = self->layers[k];
        self->area = (r->hi.x - r->lo.x) * (r->hi.z - r->lo.z) + self->area;
        Vec lo(r->lo);
        Vec hi(r->hi);
    }
    self->size = sqrt_802e82c0(self->area / 10000.0f);
    if (self->size < 25.0f) self->size = 25.0f;
    self->low = *w3d_vector_80178ec4(w3d_empty_80342fa4(self->low_value));
    self->high = *w3d_vector_80178ec4(w3d_empty_80342fa4(self->high_value));
    for (int n = 0; n < self->layers.size(); n++) layer_setup_8001d388(self->layers[n], self);
    self->top = self->layers[0];
    refresh_radius_8001e49c(self);
    grid_8001f2cc(self);
    while (!self->queue.empty()) update_queue_8001ea34(self);
    jump_ranges_8001fa68(self);
    g_804aa788 = 0;
}
extern "C" float s19_random_unit_80015810();
extern "C" int w3d_auto_80015860(int);
extern "C" int w3d_d43p_grid_pick_empty_cell_8001dd28(Ptr32<Grid> self, Ptr32<short> col, Ptr32<short> row, Ptr32<int> layer)
{
    int n = self->layers.size();
    for (int tries = 0; tries < 500; tries++) {
        float r = self->area * s19_random_unit_80015810();
        int i = 0;
        Ptr32<Layer> room = *self->layers.first;
        const float zero = 0.0f;
        if (r > zero) {
            do {
                Ptr32<Layer> c = self->layers[i];
                r -= (c->hi.x - c->lo.x) * (c->hi.z - c->lo.z);
                if (r <= zero) { room = c; break; }
                i++; if (i == n) { room = c; break; }
            } while (r > zero);
        }
        Rect &q = room->rect;
        short x0 = q.x0, x1 = q.x1;
        short x = (short)(x0 + s19_random_unit_80015810() * (x1 - x0));
        if (x == x1) x--;
        short y0 = q.y0, y1 = q.y1;
        short y = (short)(y0 + s19_random_unit_80015810() * (y1 - y0));
        if (y == y1) y--;
        int l = w3d_auto_80015860(2);
        if (room->Cells(l)[(y - room->rect.y0) * (room->rect.x1 - room->rect.x0) + x - room->rect.x0] == 0) {
            *col = x;
            *row = y;
            *layer = l;
            return 1;
        }
    }
    return 0;
}


