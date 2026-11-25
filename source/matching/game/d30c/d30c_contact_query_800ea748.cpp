// d30c: 0x800ea748. Walks a physics query, keeps contacts already in the list and reports the first new one (normal, position, key, tag), then replaces the list with the contacts seen. Names are inferred; classes are partial views.
extern "C" void *memcpy_802eee50(...);
extern "C" void *alloc_80212fd4(unsigned);
extern "C" void release_802134fc(void *);
extern "C" void *resize_80213750(void *, unsigned);
extern "C" float sqrt_802e82c0(float);
template <class T> inline const T &mn(const T &a, const T &b) { return b < a ? b : a; }
template <class T> inline const T &mx(const T &a, const T &b) { return a < b ? b : a; }
struct V {
    float x, y, z;
    V() {}
    V(float a, float b, float c) { x = a; y = b; z = c; }
    V(const V &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
inline V operator*(const V &v, float k) { return V(v.x * k, v.y * k, v.z * k); }
inline V operator+(const V &a, const V &b) { V r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
struct IntList {
    char *start, *finish, *eos;
    IntList() { eos = 0; finish = 0; start = 0; }
    ~IntList() { if (start) release_802134fc(start); }
    int size() const { return (int *)finish - (int *)start; }
    int &operator[](int i) { return ((int *)start)[i]; }
    void push(const unsigned &e) {
        if (finish == eos) {
            unsigned used = finish - start;
            unsigned cap = eos - start;
            unsigned bytes = mx<int>(cap + 1, cap + cap / 2) * 4;
            char *mem = (char *)alloc_80212fd4(bytes);
            if (start != 0) {
                memcpy_802eee50(mem, start, mn(bytes, used));
                release_802134fc(start);
            }
            start = mem;
            finish = mem + used;
            eos = mem + bytes;
        }
        *(unsigned *)finish = e;
        finish += 4;
    }
    void clear() { char *last = finish; int n = last - start; memcpy_802eee50(start, last, 0); finish -= n; }
    void assign(const IntList &o) {
        unsigned n = o.finish - o.start;
        start = (char *)resize_80213750(start, n);
        eos = finish = start + n;
        memcpy_802eee50(start, o.start, n);
    }
};
struct Handle;
struct Info { char u0[20]; unsigned u20; int u24; };
struct Pair { int a, b; };
struct Self { char u0[192]; void *u192; char u196[56]; Handle *h252; char u256[4]; IntList list; };
extern unsigned short id_804aa95e;
extern int flag_804aa964;
extern float scale_804b17a4;
extern "C" void *empty_80341584(void *);
extern "C" int step_801797b4(void *);
extern "C" int call_80126384(Handle *, V *, int);
extern "C" int clock_801264fc(Handle *);
extern "C" void done_80126524(Handle *);
extern "C" Info *info_8003f240(unsigned short);
extern "C" V *delta_800418ac();
extern "C" bool d30c_contact_query_800ea748(Self *self, V *from, V *dir, V *normal, V *pos, int *keyOut, unsigned long long *pair) {
    step_801797b4(empty_80341584(self->u192));
    bool hit = false;
    IntList seen;
    call_80126384(self->h252, dir, 20);
    if (clock_801264fc(self->h252) != 0xffff) do {
        int key = info_8003f240(id_804aa95e)->u24;
        int found = 0;
        for (unsigned i = 0; i < self->list.size(); i++) {
            if (key == self->list[i]) {
                if (flag_804aa964) seen.push(key);
                found = 1;
            }
        }
        if (!found) {
            hit = true;
            *normal = *delta_800418ac();
            float len = 1.0f / sqrt_802e82c0(normal->x * normal->x + normal->y * normal->y + normal->z * normal->z);
            normal->x *= len;
            normal->y *= len;
            normal->z *= len;
            *pos = *from + *dir * scale_804b17a4;
            *keyOut = key;
            *pair = info_8003f240(id_804aa95e)->u20;
            seen.push(key);
        }
    } while (clock_801264fc(self->h252) != 0xffff);
    done_80126524(self->h252);
    self->list.clear();
    self->list.assign(seen);
    return hit;
}
