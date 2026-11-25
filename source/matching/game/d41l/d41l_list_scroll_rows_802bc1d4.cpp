// GWMP8P rev0 0x802bc1d4. Places the visible rows of a scrolling list:
// creates a row element when none is active for an index, positions and
// fades each. The element array grows through a raw byte-pointer array.
// Names are inferred.
extern "C" void *malloc(unsigned);
extern "C" void free_802134fc(void *);
extern "C" void *memcpy_802eee50(...);
inline void retain(void *p) { if (p) (*(void (***)(void *))p)[3](p); }
struct Held {
    void *p;
    Held(const Held &a) : p(a.p) { retain(p); }
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
extern "C" void length_802bd3cc(Elem *, float);
extern "C" void select_802bd2c4(Elem *, int, int);
extern "C" void layer_802c0cac(Elem *, unsigned);
extern "C" void value_802bfb2c(Elem *, unsigned);
extern "C" void height_802bfb68(Elem *, float);
extern "C" void interface_802c0c24(Elem *, Held);
extern "C" void interface_802bdc88(Elem *, Held);
extern "C" void apply_802c0cb4(Elem *, unsigned);
extern "C" void property_802bfba4(Elem *, unsigned);
extern "C" void position_802bd430(Elem *, Vec);
extern "C" void fade_802bd360(Elem *, float, float);
extern "C" void setup_802bd158(Elem *);
extern "C" void active_802bd318(Elem *, int);
inline const int &Max(const int &a, const int &b) { return a < b ? b : a; }
inline const unsigned &Min(const unsigned &a, const unsigned &b) { return b < a ? b : a; }
struct Array {
    char *start, *finish, *limit;
    void push(Elem *const &x) {
        if (finish == limit) {
            unsigned size = finish - start;
            unsigned bytes = Max(size + 1, size + (size >> 1)) << 2;
            char *fresh = (char *)malloc(bytes);
            if (start) {
                memcpy_802eee50(fresh, start, Min(bytes, size));
                free_802134fc(start);
            }
            start = fresh;
            finish = fresh + size;
            limit = fresh + bytes;
        }
        *(Elem **)finish = x;
        finish += 4;
    }
};
struct List {
    char u0[28]; Held face; Vec at; float length; float u48; char u52[4]; Array items; float scroll; int current; float pitch; char u80[4]; unsigned value; Held frame; float size; unsigned apply; unsigned property; unsigned layer;
};
extern "C" int count_802bc71c(List *);
extern "C" void each_802bc5ac(List *);
extern "C" int find_802bc6a8(List *, int);
extern "C" void prune_802bc600(List *);
extern "C" void d41l_list_scroll_rows_802bc1d4(List *self) {
    float step = self->pitch;
    float raw = self->scroll;
    int row = (int)raw;
    float y = self->u48 - step;
    float upper = y;
    float bottom = (0.0f - self->u48) + step;
    float pitch = step + step;
    y = pitch * (raw - (float)row) + y;
    Elem *e = 0;
    int count = count_802bc71c(self);
    each_802bc5ac(self);
    while (y > 0.0f - self->u48 - step) {
        Vec v;
        Vec *pv = &v;
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
            e = *(Elem **)(self->items.start + (idx << 2));
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
