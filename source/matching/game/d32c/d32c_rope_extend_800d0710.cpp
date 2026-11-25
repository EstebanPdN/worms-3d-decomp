// d32c: 0x800d0710. Extends the rope when the free end is blocked: bisects towards the target with the probe, moves the new node one unit along the blocked direction, drops the rope if the gap is under the limit, otherwise appends a segment and re-tensions the old last segment. Names are inferred; classes are partial views.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec operator-(const Vec &o) const { Vec r; r.x = x - o.x; r.y = y - o.y; r.z = z - o.z; return r; }
    Vec operator+(const Vec &o) const { Vec r; r.x = x + o.x; r.y = y + o.y; r.z = z + o.z; return r; }
    Vec operator*(float k) const { Vec r; r.x = x * k; r.y = y * k; r.z = z * k; return r; }
    int operator==(const Vec &o) const { const int *a = (const int *)this, *b = (const int *)&o; return a[0] == b[0] && a[1] == b[1] && a[2] == b[2]; }
};
extern "C" float sqrt_802e82c0(float);
inline float dist(const Vec &a, const Vec &b) { float x = a.x - b.x, y = a.y - b.y, z = a.z - b.z; return sqrt_802e82c0(x * x + y * y + z * z); }
struct Prop;
extern "C" float read_80178df0(Prop *);
extern "C" int count_80178c48(Prop *);
struct Seg { Vec pos; float len; Vec dir; };
extern "C" char *allocate_80212fd4(unsigned);
extern "C" void release_802134fc(void *);
extern "C" void *memcpy_802eee50(...);
template <class T> inline const T &maximum(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &minimum(const T &a, const T &b) { return b < a ? b : a; }
struct SegList {
    Seg *begin, *end, *capacity;
    void push(const Seg &value) {
        if (end == capacity) {
            unsigned old = (char *)end - (char *)begin;
            int one = old + 1, grow = old + (old >> 1);
            unsigned bytes = maximum(one, grow) * 28;
            char *p = allocate_80212fd4(bytes);
            if (begin) {
                memcpy_802eee50(p, begin, minimum(bytes, old));
                release_802134fc(begin);
            }
            begin = (Seg *)p;
            end = (Seg *)(p + old);
            capacity = (Seg *)(p + bytes);
        }
        *end = value;
        end++;
    }
};
struct Rope;
extern "C" int drain_800d0058(Rope *, Vec *);
extern "C" int probe_800d066c(Rope *, Vec *);
extern "C" void finish_800d00f0(Rope *);
extern "C" void rescale_800d1628(Rope *, float, float);
extern Vec middle_8043ae20, zero_8045e788;
extern float one_8038815c[];
struct Rope {
    char u0[28]; SegList list; int u40; char u44[172]; Prop *p216, *p220;
    Seg &at(int i) { return list.begin[i]; }
    void grow(const Vec *from, const Vec *to);
};
void Rope::grow(const Vec *from, const Vec *to) {
    int last = (list.end - list.begin) - 1;
    Vec a(at(last).pos);
    Vec b(*from);
    if (drain_800d0058(this, &b)) { finish_800d00f0(this); return; }
    if (!probe_800d066c(this, &b)) return;
    Vec mid(middle_8043ae20);
    int found = 0;
    int n = count_80178c48(p220);
    for (int i = 0; i < n; i++) {
        b = (b + *to) * 0.5f;
        found = probe_800d066c(this, &b);
        if (!found) break;
        mid = middle_8043ae20;
    }
    if (found) b = *to;
    Vec d = b - mid;
    if (!(d == zero_8045e788)) {
        float k = one_8038815c[0] / sqrt_802e82c0(d.x * d.x + d.y * d.y + d.z * d.z);
        d.x *= k; d.y *= k; d.z *= k;
        mid.x += d.x; mid.y += d.y; mid.z += d.z;
    }
    if (dist(mid, b) < read_80178df0(p216)) { u40 = 1; finish_800d00f0(this); return; }
    Seg s;
    s.pos = mid;
    s.len = dist(mid, *from);
    s.dir = zero_8045e788;
    rescale_800d1628(this, at(last).len, s.len);
    float len = dist(a, mid);
    at(last).len = len;
    at(last).dir = *to - *from;
    list.push(s);
}
