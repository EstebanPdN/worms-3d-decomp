// GWMP8P rev0 0x8001d590. Adds a grid region for a box: discards it when its
// floor area is under 250 or when an existing region absorbs it, otherwise
// appends it to the grid's list. The region's member arrays and destructor
// are real C++ and produce the array destruction loops. Names are inferred
// from the original instructions.
inline void *operator new(unsigned int, void *place) { return place; }
extern "C" void *w3d_handle_storage_allocate(unsigned int);
extern "C" void w3d_handle_storage_release(void *);
extern "C" void *memcpy_802eee50(void *, const void *, unsigned int, ...);
extern "C" void *w3d_auto_8001523c(unsigned int);
extern "C" void w3d_auto_80015264(void *);
extern "C" void w3d_auto_800152ac(void *);
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
template <class T> struct Array {
    T *start, *finish, *storage_end;
    int size() const { return finish - start; }
    T &operator[](int i) { return start[i]; }
    void grow() {
        unsigned int used = (char *)finish - (char *)start;
        int a = used + 1, b = used + (used >> 1);
        unsigned int bytes = Max(a, b) * 4;
        T *p = (T *)w3d_handle_storage_allocate(bytes);
        if (start) {
            memcpy_802eee50(p, start, Min(bytes, used));
            w3d_handle_storage_release(start);
        }
        start = p; finish = (T *)((char *)p + used); storage_end = (T *)((char *)p + bytes);
    }
    void push_back(const T &v) {
        if (finish == storage_end) grow();
        *finish = v;
        finish++;
    }
};
struct Proxy { int alloc; void *end; Proxy() { end = 0; } };
struct Store {
    void *start, *finish; Proxy proxy;
    Store() : start(0), finish(0) {}
    ~Store() { if (start) w3d_auto_800152ac(start); }
};
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Bounds { Vec lo, hi; Bounds() {} Bounds(const Vec &a, const Vec &b) : lo(a), hi(b) {} };
extern "C" void w3d_cx7a_grid_layer_shift_8001d1d8(struct Rect *);
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
inline void Destroy(Rect *r) { if (r) { r->~Rect(); w3d_auto_80015264(r); } }
struct Grid { char pad[88]; Array<Rect *> rects; };
extern int g_ready_804aa788;
extern "C" void w3d_auto_8001cb40(void *);
extern "C" int cc25a_bounds_merge_xz_8001d240(Rect *, Rect *);
extern "C" void w3d_d30a_grid_add_region_8001d590(Grid *self, const Vec *from, const Vec *to)
{
    if (!g_ready_804aa788) w3d_auto_8001cb40((void *)self);
    Rect *r = new (w3d_auto_8001523c(sizeof(Rect))) Rect;
    r->bounds = Bounds(*from, *to);
    if (r->Area() < 250.0f) { Destroy(r); return; }
    int n = self->rects.size();
    for (int i = 0; i < n; i++) {
        if (cc25a_bounds_merge_xz_8001d240(self->rects[i], r)) { Destroy(r); return; }
    }
    self->rects.push_back(r);
}
