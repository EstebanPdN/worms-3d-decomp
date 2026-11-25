#include "w3d_ptr.h"
#line 1 "d30a_grid_add_region_8001d590.cpp"
// GWMP8P rev0 0x8001d590. Adds a grid region for a box: discards it when its
// floor area is under 250 or when an existing region absorbs it, otherwise
// appends it to the grid's list. The region's member arrays and destructor
// are real C++ and produce the array destruction loops. Names are inferred
// from the original instructions.
inline void *operator new(__SIZE_TYPE__, void *place) { return place; }
extern "C" Ptr32<void> w3d_handle_storage_allocate(unsigned int);
extern "C" void w3d_handle_storage_release(Ptr32<void>);
extern "C" Ptr32<void> memcpy_802eee50(Ptr32<void>, Ptr32<const void>, unsigned int, ...);
extern "C" Ptr32<void> w3d_auto_8001523c(unsigned int);
extern "C" void w3d_auto_80015264(Ptr32<void>);
extern "C" void w3d_auto_800152ac(Ptr32<void>);
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
template <class T> struct Array {
    Ptr32<T> start; Ptr32<T> finish; Ptr32<T> storage_end;
    int size() const { return finish - start; }
    T &operator[](int i) { return start[i]; }
    void grow() {
        unsigned int used = (Ptr32<char>)finish - (Ptr32<char>)start;
        int a = used + 1, b = used + (used >> 1);
        unsigned int bytes = Max(a, b) * 4;
        Ptr32<T> p = (Ptr32<T>)w3d_handle_storage_allocate(bytes);
        if (start) {
            memcpy_802eee50(p, start, Min(bytes, used));
            w3d_handle_storage_release(start);
        }
        start = p; finish = (Ptr32<T>)((Ptr32<char>)p + used); storage_end = (Ptr32<T>)((Ptr32<char>)p + bytes);
    }
    void push_back(const T &v) {
        if (finish == storage_end) grow();
        *finish = v;
        finish++;
    }
};
struct Proxy { int alloc; Ptr32<void> end; Proxy() { end = 0; } };
struct Store {
    Ptr32<void> start; Ptr32<void> finish; Proxy proxy;
    Store() : start(0), finish(0) {}
    ~Store() { if (start) w3d_auto_800152ac(start); }
};
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Bounds { Vec lo, hi; Bounds() {} Bounds(const Vec &a, const Vec &b) : lo(a), hi(b) {} };
extern "C" void w3d_cx7a_grid_layer_shift_8001d1d8(Ptr32<struct Rect>);
struct Rect {
    int pad0;
    Bounds bounds;
    int ix;
    short pad1;
    short pad2;
    Store bytes[2], low[2], high[2];
    Rect() { w3d_cx7a_grid_layer_shift_8001d1d8(this); }
    ~Rect() { w3d_cx7a_grid_layer_shift_8001d1d8(this); }
    float Area() const { return (bounds.hi.x - bounds.lo.x) * (bounds.hi.z - bounds.lo.z); }
};
inline void Destroy(Ptr32<Rect> r) { if (r) { r->~Rect(); w3d_auto_80015264(r); } }
struct Grid { char pad[88]; Array <Ptr32<Rect> > rects; };
extern int g_ready_804aa788;
extern "C" void w3d_auto_8001cb40(Ptr32<void>);
extern "C" int cc25a_bounds_merge_xz_8001d240(Ptr32<Rect>, Ptr32<Rect>);
extern "C" void w3d_d30a_grid_add_region_8001d590(Ptr32<Grid> self, Ptr32<const Vec> from, Ptr32<const Vec> to)
{
    if (!g_ready_804aa788) w3d_auto_8001cb40((Ptr32<void>)self);
    Ptr32<Rect> r = new (w3d_auto_8001523c(sizeof(Rect))) Rect;
    r->bounds = Bounds(*from, *to);
    if (r->Area() < 250.0f) { Destroy(r); return; }
    int n = self->rects.size();
    for (int i = 0; i < n; i++) {
        if (cc25a_bounds_merge_xz_8001d240(self->rects[i], r)) { Destroy(r); return; }
    }
    self->rects.push_back(r);
}


