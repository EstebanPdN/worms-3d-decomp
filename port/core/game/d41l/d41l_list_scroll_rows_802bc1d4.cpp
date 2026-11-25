#include "w3d_ptr.h"
#line 1 "d41l_list_scroll_rows_802bc1d4.cpp"
// GWMP8P rev0 0x802bc1d4. Places the visible rows of a scrolling list:
// creates a row element when none is active for an index, positions and
// fades each. The element array grows through a raw byte-pointer array.
// Names are inferred.
extern "C" Ptr32<void> malloc(unsigned);
extern "C" void free_802134fc(Ptr32<void>);
extern "C" Ptr32<void> memcpy_802eee50(...);
inline void retain(Ptr32<void> p) { if (p) (*(Ptr32<Ptr32<Ptr32<void (Ptr32<void>)>>>)p)[3](p); }
struct Held {
    Ptr32<void> p;
    Held(const Held &a) : p(a.p) { retain(p); }
    // 0x802c0c24 y 0x802bdc88 sueltan su argumento en el PPC (GCC 2.95); aquí lo suelta quien llama.
    ~Held() { if (p) (*(Ptr32<Ptr32<Ptr32<void (Ptr32<void>)>>>)p)[4](p); }
};
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &a) { float u = a.x, v = a.y, w = a.z; x = u; y = v; z = w; }
};
struct Elem {
    unsigned u0[5]; int ready; unsigned u24[13]; float size; unsigned words80[15];
    Elem();
};
extern "C" void length_802bd3cc(Ptr32<Elem>, float);
extern "C" void select_802bd2c4(Ptr32<Elem>, int, int);
extern "C" void layer_802c0cac(Ptr32<Elem>, unsigned);
extern "C" void value_802bfb2c(Ptr32<Elem>, unsigned);
extern "C" void height_802bfb68(Ptr32<Elem>, float);
extern "C" void interface_802c0c24(Ptr32<Elem>, Held);
extern "C" void interface_802bdc88(Ptr32<Elem>, Held);
extern "C" void apply_802c0cb4(Ptr32<Elem>, unsigned);
extern "C" void property_802bfba4(Ptr32<Elem>, unsigned);
extern "C" void position_802bd430(Ptr32<Elem>, Vec);
extern "C" void fade_802bd360(Ptr32<Elem>, float, float);
extern "C" void setup_802bd158(Ptr32<Elem>);
extern "C" void active_802bd318(Ptr32<Elem>, int);
inline const int &Max(const int &a, const int &b) { return a < b ? b : a; }
inline const unsigned &Min(const unsigned &a, const unsigned &b) { return b < a ? b : a; }
struct Array {
    Ptr32<char> start; Ptr32<char> finish; Ptr32<char> limit;
    void push(Ptr32<Elem> const &x) {
        if (finish == limit) {
            unsigned size = finish - start;
            unsigned bytes = Max(size + 1, size + (size >> 1)) << 2;
            Ptr32<char> fresh = (Ptr32<char>)malloc(bytes);
            if (start) {
                memcpy_802eee50(w3d::VA(fresh), w3d::VA(start), Min(bytes, size));
                free_802134fc(start);
            }
            start = fresh;
            finish = fresh + size;
            limit = fresh + bytes;
        }
        *(Ptr32<Ptr32<Elem>>)finish = x;
        finish += 4;
    }
};
struct List {
    char u0[28]; Held face; Vec at; float length; float u48; char u52[4]; Array items; float scroll; int current; float pitch; char u80[4]; unsigned value; Held frame; float size; unsigned apply; unsigned property; unsigned layer;
};
extern "C" int count_802bc71c(Ptr32<List>);
extern "C" void each_802bc5ac(Ptr32<List>);
extern "C" int find_802bc6a8(Ptr32<List>, int);
extern "C" void prune_802bc600(Ptr32<List>);
extern "C" void d41l_list_scroll_rows_802bc1d4(Ptr32<List> self) {
    float step = self->pitch;
    float raw = self->scroll;
    int row = (int)raw;
    float y = self->u48 - step;
    float upper = y;
    float bottom = (0.0f - self->u48) + step;
    float pitch = step + step;
    y = pitch * (raw - (float)row) + y;
    Ptr32<Elem> e = 0;
    int count = count_802bc71c(self);
    each_802bc5ac(self);
    while (y > 0.0f - self->u48 - step) {
        Vec v;
        Ptr32<Vec> pv = &v;
        int idx = find_802bc6a8(self, row < count ? row : -1);
        if (idx == -1) {
            e = new Elem;
            if (self->layer) layer_802c0cac(e, self->layer);
            interface_802c0c24(e, self->frame);
            length_802bd3cc(e, self->length);
            select_802bd2c4(e, row, 0);
            value_802bfb2c(e, self->value);
            height_802bfb68(e, self->pitch);
            e->size = self->size;
            interface_802bdc88(e, self->face);
            apply_802c0cb4(e, self->apply);
            property_802bfba4(e, self->property);
            self->items.push(e);
        } else {
            e = *(Ptr32<Ptr32<Elem>>)(self->items.start + (idx << 2));
        }
        { float py = self->at.y; v.x = self->at.x; pv->y = py + y; pv->z = 1.0f; position_802bd430(e, v); }
        fade_802bd360(e, y > upper ? y - upper : 0.0f, y < bottom ? bottom - y : 0.0f);
        if (e->ready == 0) {
            setup_802bd158(e);
            if (count > row && self->current == row) active_802bd318(e, 1);
        }
        y -= pitch;
        row++;
    }
    prune_802bc600(self);
}


