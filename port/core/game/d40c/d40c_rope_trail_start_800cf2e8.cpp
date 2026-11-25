#include "w3d_ptr.h"
#line 1 "d40c_rope_trail_start_800cf2e8.cpp"
// d40c: 0x800cf2e8. Rope start: sets the attach point, builds the start
// orientation from the descriptor and seeds the trail with the first raised
// point.
struct V {
    float x, y, z;
    V() {}
    V(float a, float b, float c) { x = a; z = c; y = b; }
    V(const V &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Row { float x, y, z; };
struct Mat {
    Row r[3]; float w;
    const Row &R(int i) const { return r[i]; }
};
inline V same(V v) { return v; }
inline V raised(const V &v, float h) { float x = v.x; return V(x, v.y + h, v.z); }
struct Entry { V p; int w3, w4, w5, w6; };
extern "C" Ptr32<void> memcpy_802eee50(...);
extern "C" Ptr32<void> malloc(unsigned);
extern "C" void release_802134fc(Ptr32<void>);
template <class T> inline const T &mn(const T &a, const T &b) { return b < a ? b : a; }
template <class T> inline const T &mx(const T &a, const T &b) { return a < b ? b : a; }
struct Trail {
    Ptr32<char> start; Ptr32<char> finish; Ptr32<char> eos;
    void grow() {
        unsigned size = finish - start;
        unsigned bytes = mx<int>(size + 1, size + size / 2) * 28;
        Ptr32<char> mem = (Ptr32<char>)malloc(bytes);
        if (start != 0) {
            memcpy_802eee50(w3d::VA(mem), w3d::VA(start), mn(bytes, size));
            release_802134fc(start);
        }
        start = mem;
        finish = mem + size;
        eos = mem + bytes;
    }
    void push(const Entry &e) {
        if (finish == eos) grow();
        *(Ptr32<Entry>)finish = e;
        finish += 28;
    }
};
struct Data { char u0[44]; V v44; char u56[16]; float f72; char u76[4]; V v80; char u92[24]; float f116; };
struct Rope {
    char u0[28]; Trail trail; char u40[12]; V v52; char u64[12]; V v76; char u88[32]; int u120; char u124[148]; int u272; V v276;
};
struct Key { Ptr32<const char> name; };
extern V zero_8045e788[], k_8043fde8[];
extern char eye_803880c0[];
extern "C" Ptr32<Data> query_800fc6dc(int);
extern "C" float calc_800d1698(Ptr32<Rope>, float, Ptr32<V>);
extern "C" void euler_801a3eb0(const V &, int, Mat &);
extern "C" int read_800fc270(Ptr32<Key>, Ptr32<float>);
extern "C" void d40c_rope_trail_start_800cf2e8(Ptr32<Rope> self) {
    Ptr32<Data> d = query_800fc6dc(self->u272);
    V a;
    a = zero_8045e788[0];
    float t = d->f72;
    a.y = t;
    if (self->u120 == 0) a.x = -d->f116;
    else { t = calc_800d1698(self, t, &d->v44); a.x = -t; }
    self->v276 = zero_8045e788[0];
    self->v276.y = a.y;
    self->v276.x = a.x;
    V r;
    Mat m;
    euler_801a3eb0(a, 0, m);
    {
        float kx = k_8043fde8[0].x, ky = k_8043fde8[0].y, kz = k_8043fde8[0].z;
        const Row &p = m.R(0), &q = m.R(1), &t = m.R(2);
        r.x = kx * p.x + ky * q.x + kz * t.x;
        r.y = kx * p.y + ky * q.y + kz * t.y;
        r.z = kx * p.z + ky * q.z + kz * t.z;
    }
    self->v52 = same(r);
    float h;
    { Key k; k.name = eye_803880c0; read_800fc270(&k, &h); }
    self->v76 = d->v80;
    {
        Entry e;
        e.p = raised(self->v76, h);
        self->trail.push(e);
    }
}


