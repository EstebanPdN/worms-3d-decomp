// GWMP8P rev0 0x800bb548. Recursively builds land pieces from a node tree:
// for each child node creates a land object, appends it to the global land
// vector, numbers it, loads it (0x800b2408), attaches a girder graph when
// the piece is named EXPORTGIRDER, computes its bounding box, merges it into
// the self bounds and the parent box, records subtree index and size in the
// box vector at +116, and recurses with an offset from the child's grid
// cell. Class layouts are partial views; names are inferred.
extern "C" float sqrt_802e82c0(float);
extern "C" int strcmp(const char *, const char *);
struct Object;
struct ObjectVtable { void *unknown00[3]; void (*retain)(Object *); void (*release)(Object *); };
struct Object { ObjectVtable *vtable; };
struct Ref {
    Object *p;
    Ref() {}
    Ref(Object *o) { p = o; if (p) p->vtable->retain(p); }
    Ref(const Ref &);
    ~Ref() { if (p) p->vtable->release(p); }
};
struct String { String(const String &); char *text; String(const char *t); ~String(); };
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
inline String::~String() { string_finish_8020c5c4(this); string_release_80341588(this); }
struct Stream { unsigned words[6]; Stream(); ~Stream(); };
extern "C" void stream_finish_8020803c(Stream *, int);
inline Stream::~Stream() { stream_finish_8020803c(this, 2); }
extern "C" int stream_open_802080a0(Stream *, const char *, int);
extern "C" int stream_close_8020810c(Stream *);
extern "C" Object *create_8020b680(void *);
extern char key_80418f78[], key_80414160[], type_8040e078[];
typedef void (*Slot20Fn)(Object *, unsigned);
typedef void (*Slot32Fn)(Object *, Object *, int);
typedef void (*LoadFn)(Object *, void *, void *, String *);
inline void *Slot(Object *o, int off) { return *(void **)((char *)o->vtable + off); }
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float len() const { return sqrt_802e82c0(x * x + y * y + z * z); }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
struct Position { float x, y, z; };
extern "C" void position_ctor_80343740(Position *);
struct Axes { float m[9]; };
struct Transform {
    Axes axes; Position position;
    Transform() { position_ctor_80343740(&position); }
    Transform(const Transform &o) { position_ctor_80343740(&position); axes = o.axes; position = o.position; }
};
struct Box {
    Vec low, high; float radius; unsigned short kind, used;
    Box() {
        low.x = 1000000.0f; low.y = 1000000.0f; high.x = -1000000.0f; low.z = 1000000.0f; high.y = -1000000.0f; high.z = -1000000.0f;
kind = 1; used = 0;
    }
    void Recalc() {
        Vec d = high - low;
        radius = d.len() * 0.5f;
    }
    void Add(const Box &o) {
        if (low.x > o.low.x) low.x = o.low.x;
        if (low.y > o.low.y) low.y = o.low.y;
        if (low.z > o.low.z) low.z = o.low.z;
        if (high.x < o.high.x) high.x = o.high.x;
        if (high.y < o.high.y) high.y = o.high.y;
        if (high.z < o.high.z) high.z = o.high.z;
    }
};
struct Bounds { Position low, high;
    void Add(const Vec &l, const Vec &h) {
        if (low.x > l.x) low.x = l.x;
        if (low.y > l.y) low.y = l.y;
        if (low.z > l.z) low.z = l.z;
        if (high.x < h.x) high.x = h.x;
        if (high.y < h.y) high.y = h.y;
        if (high.z < h.z) high.z = h.z;
    }
};
struct Sphere { float x, y, z, r; void Set(float a, float b, float c, float d) { x = a; y = b; z = c; r = d; } };
extern Bounds empty_8045e690;
struct Volume { Bounds b; Sphere s; Volume() { b = empty_8045e690; } };
struct Land;
struct LandInfo { char unknown0[36]; char *name; char unknown40[411]; unsigned char solid451; char unknown452[16]; unsigned short count468; };
struct Node;
struct NodeList { char unknown0[24]; unsigned count; char unknown28[4]; Node *items[1]; };
struct Node { char unknown0[44]; NodeList *list; char unknown48[60]; Vec size; char unknown120[88]; unsigned char cell[3]; };
extern int heap_804adde4;
extern "C" void *heap_allocate_802098d8(void *, unsigned);
extern "C" Land *land_ctor_800b12c8(void *);
extern "C" void land_acquire_800b1394(Land *);
extern "C" void set_index_800b7ebc(Land *, int);
extern "C" int land_load_800b2408(Land *, Node *, const Transform &);
extern "C" LandInfo *get_800b4d98(Land *);
extern "C" void append_801ef174(void *, int, int, void *);
extern "C" int select_800ba4c4(void *, Land *);
extern "C" void bounds_800b7ed0(Land *, Vec *, Vec *);
extern "C" void copy_transform_800b8ca0(Land *, Transform *);
extern "C" unsigned count_800bb4e4(Node *);
extern "C" const Vec *position_800b7ec4(Land *);
extern "C" void * box_sphere_801f55ec(Sphere *, const Bounds *);
extern "C" Object *cast_80342a74(Object *);
extern "C" float value_80178df0(Object *);
extern "C" char *allocate_80212fd4(unsigned);
extern "C" void release_802134fc(void *);
extern "C" void *copy_802eee50(...);
template <class T> inline const T &maximum(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &minimum(const T &a, const T &b) { return b < a ? b : a; }
struct LandVector {
    Land **begin, **end, **capacity;
    int size() const { return end - begin; }
    void push(Land *const &value) {
        if (end == capacity) {
            unsigned old = (char *)end - (char *)begin;
            int one = old + 1, grow = old + (old >> 1);
            unsigned bytes = maximum(one, grow) << 2;
            char *p = allocate_80212fd4(bytes);
            if (begin) {
                copy_802eee50(p, begin, minimum(bytes, old));
                release_802134fc(begin);
            }
            begin = (Land **)p;
            end = (Land **)(p + old);
            capacity = (Land **)(p + bytes);
        }
        *end = value;
        end++;
    }
};
struct BoxVector {
    Box *begin, *end, *capacity;
    int size() const { return end - begin; }
    Box &operator[](int i) { return begin[i]; }
    void push2(const Box &value) {
        if (end == capacity) {
            unsigned used = (char *)end - (char *)begin;
            unsigned old = (char *)capacity - (char *)begin;
            int one = old + 1, grow = old + (old >> 1);
            unsigned bytes = maximum(one, grow) << 5;
            char *p = allocate_80212fd4(bytes);
            if (begin) {
                copy_802eee50(p, begin, minimum(bytes, used));
                release_802134fc(begin);
            }
            begin = (Box *)p;
            end = (Box *)(p + used);
            capacity = (Box *)(p + bytes);
        }
        *end = value;
        end++;
    }
    void push(const Box &value) {
        if (end == capacity) {
            unsigned old = (char *)end - (char *)begin;
            int one = old + 1, grow = old + (old >> 1);
            unsigned bytes = maximum(one, grow) << 5;
            char *p = allocate_80212fd4(bytes);
            if (begin) {
                copy_802eee50(p, begin, minimum(bytes, old));
                release_802134fc(begin);
            }
            begin = (Box *)p;
            end = (Box *)(p + old);
            capacity = (Box *)(p + bytes);
        }
        *end = value;
        end++;
    }
};
extern LandVector lands_8043bb64;

extern void *array_804ae5e4;
extern void *selection_804aad30;
extern Object *scale_804ae5d8;
inline void Notify(Land *l) { if (selection_804aad30) select_800ba4c4(selection_804aad30, l); }
struct Self { char unknown0[68]; int count; Box bounds; char unknown104[12]; BoxVector boxes; };
extern "C" int d32h_land_tree_build_800bb548(Self *self, Node *node, Vec at, Transform t, int parent) {
    NodeList *list = node->list;
    unsigned n = list->count;
    Node **items = list->items;
    Vec low, high;
    Box box;
    Volume v;
    Sphere *q = &v.s;
    q->x = 0.0f; q->y = 0.0f; q->z = 0.0f; q->r = 0.0f;
    for (unsigned i = 0; i < n; i++) {
        Node *child = items[i];
        Land *land = land_ctor_800b12c8(heap_allocate_802098d8(&heap_804adde4, 32));
        land_acquire_800b1394(land);
        lands_8043bb64.push(land);
        set_index_800b7ebc(land, self->count++);
        land_load_800b2408(land, child, t);
        LandInfo *i0 = get_800b4d98(land); const char *g0 = "EXPORTGIRDER"; int differs = strcmp(i0->name, g0);
        bool same = differs == 0; if (same) {
            Stream s;
            stream_open_802080a0(&s, "c:\\GirderTemplate.xom", 6);
            Ref a(create_8020b680(key_80418f78));
            ((Slot20Fn)Slot(a.p, 20))(a.p, s.words[5]);
            {
                Ref g(create_8020b680(key_80414160));
                Object *go = g.p;
                ObjectVtable *vt = go->vtable;
                LandInfo *info = get_800b4d98(land);
                {
                    String name("Girder Graph");
                    ((LoadFn)((void **)vt)[8])(go, type_8040e078, info, &name);
                }
                ((Slot32Fn)Slot(a.p, 32))(a.p, g.p, 0);
            }
            {
                Ref z(0);
                stream_close_8020810c(&s);
            }
        }
        append_801ef174(array_804ae5e4, 44, 3, get_800b4d98(land));
        Transform tt;
        copy_transform_800b8ca0(land, &tt);
        Notify(land);
        bounds_800b7ed0(land, &low, &high);
        box.high = high;
        box.low = low;
        box.Recalc();
        if (get_800b4d98(land)->count468 && get_800b4d98(land)->solid451) {
            self->bounds.Add(box);
            self->bounds.Recalc();
        }
        if (parent >= 0) {
            Box &p = self->boxes[parent];
            p.Add(box);
            p.Recalc();
        }
        short index = -1;
        if (count_800bb4e4(child) > 1) {
            self->boxes.push2(box);
            index = (short)(self->boxes.size() - 1);
            self->boxes[index].used = lands_8043bb64.size();
        }
        box.used = 1;
        self->boxes.push(box);
        if (v.b.low.x > low.x) v.b.low.x = low.x; if (v.b.low.y > low.y) v.b.low.y = low.y; if (v.b.low.z > low.z) v.b.low.z = low.z; if (v.b.high.x < high.x) v.b.high.x = high.x; if (v.b.high.y < high.y) v.b.high.y = high.y; if (v.b.high.z < high.z) v.b.high.z = high.z;
        float k = value_80178df0(cast_80342a74(scale_804ae5d8));
        const Vec &size = child->size;
        Vec q, d;
        float dx = (float)child->cell[2] * 0.5f * size.x * k;
        float dy = (float)child->cell[1] * 0.5f * size.y * k;
        float dz = (float)child->cell[0] * 0.5f * size.z * k;
        d.x = dx; d.y = dy; d.z = dz;
        q = *position_800b7ec4(land);
        q.x *= size.x * k;
        q.y *= size.y * k;
        q.z *= size.z * k;
        q.x -= d.x; q.y -= d.y; q.z -= d.z;
        box_sphere_801f55ec(&v.s, &v.b);
        if (index >= 0) d32h_land_tree_build_800bb548(self, child, q, tt, index);
        else d32h_land_tree_build_800bb548(self, child, q, tt, parent);
        if (index >= 0) {
            Box &e = self->boxes[index];
            e.Recalc();
            int sz = lands_8043bb64.size(); int u = self->boxes[index].used - 1; self->boxes[index].used = sz - u;
            self->boxes[index].kind = self->boxes.size() - index;
            if (parent >= 0) {
                Box &p = self->boxes[parent];
                p.Add(self->boxes[index]);
                p.Recalc();
            }
        }
    }
    return 0;
}
