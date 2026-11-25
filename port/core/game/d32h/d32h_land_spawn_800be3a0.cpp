#include "w3d_ptr.h"
#line 1 "d32h_land_spawn_800be3a0.cpp"
// GWMP8P rev0 0x800be3a0. Creates a land object from a named model resource:
// loads the resource by name (0x8015adf4, flags 255), finds the owner's mesh
// entry through virtual slot 56, makes a maker object (key 0x80413b28) that
// yields the model, builds the land with its orientation and position
// (0x801a3eb0, 0x800b87d0), appends it to the global land vector, numbers
// it, publishes it to the land array and the selection service, and appends
// its 32-byte bounding box to the self vector at +116. Class layouts are
// partial views; names are inferred.
extern "C" float sqrt_802e82c0(float);
struct Object;
struct ObjectVtable { Ptr32<void> unknown00[3]; Ptr32<void (Ptr32<Object>)> retain; Ptr32<void (Ptr32<Object>)> release; };
struct Object { Ptr32<ObjectVtable> vtable; };
struct Ref {
    Ptr32<Object> p;
    Ref() { p = 0; }
    template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Object *)w3d_p.get()) {}
 Ref(Object *o) { p = o; if (p) p->vtable->retain(p); }
    Ref(const Ref &);
    ~Ref() { if (p) p->vtable->release(p); }
};
struct String { String(const String &); Ptr32<char> text; template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *t); ~String(); };
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
inline String::~String() { string_finish_8020c5c4(this); string_release_80341588(this); }
extern "C" int load_8015adf4(Ptr32<const String>, Ptr32<Ref>, unsigned char);
extern "C" Ptr32<Object> owner_80182150(Ptr32<Object>);
extern "C" Ptr32<Object> create_8020b680(Ptr32<void>);
extern char type_8040e078[], key_80413b28[];
typedef Ptr32<int (Ptr32<Object>, Ptr32<void>, int, Ptr32<Ref>)> LookupFn;
typedef Ptr32<void (Ptr32<Object>, int)> SetKindFn;
typedef Ptr32<void (Ptr32<Object>, Ptr32<Object>)> SetOwnerFn;
typedef Ptr32<Ptr32<Object> (Ptr32<Object>)> GetFn;
inline Ptr32<void> Slot(Ptr32<Object> o, int off) { return *(Ptr32<Ptr32<void>>)((Ptr32<char>)o->vtable + off); }
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float len() const { return sqrt_802e82c0(x * x + y * y + z * z); }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
struct Position { float x, y, z; };
extern "C" void position_ctor_80343740(Ptr32<Position>);
struct Transform {
    float axis[9]; Position position;
    Transform() { position_ctor_80343740(&position); }
};
struct Box {
    Vec low, high; float radius; short kind, used;
    Box() {
        low.x = 1000000.0f; high.y = -1000000.0f; high.x = -1000000.0f; high.z = -1000000.0f; low.y = 1000000.0f; low.z = 1000000.0f;
        used = 0; kind = 1;
    }
    void Update() {
        Vec d = high - low;
        radius = d.len() * 0.5f;
    }
};
struct Land;
extern int heap_804adde4;
extern "C" Ptr32<void> heap_allocate_802098d8(Ptr32<void>, unsigned);
extern "C" Ptr32<Land> land_ctor_800b12c8(Ptr32<void>);
extern "C" void euler_801a3eb0(Ptr32<const void>, int, Ptr32<Transform>);
extern "C" void attach_800b87d0(Ptr32<Land>, Ptr32<Object>, Ptr32<const Transform>);
extern "C" void set_index_800b7ebc(Ptr32<Land>, int);
extern "C" Ptr32<void> get_800b4d98(Ptr32<Land>);
extern "C" void append_801ef174(Ptr32<void>, int, int, Ptr32<void>);
extern "C" int select_800ba4c4(Ptr32<void>, Ptr32<Land>);
extern "C" void bounds_800b7ed0(Ptr32<Land>, Ptr32<Vec>, Ptr32<Vec>);
extern "C" Ptr32<char> allocate_80212fd4(unsigned);
extern "C" void release_802134fc(Ptr32<void>);
extern "C" Ptr32<void> copy_802eee50(...);
template <class T> inline const T &maximum(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &minimum(const T &a, const T &b) { return b < a ? b : a; }
struct LandVector {
    Ptr32<Ptr32<Land>> begin; Ptr32<Ptr32<Land>> end; Ptr32<Ptr32<Land>> capacity;
    void push(Ptr32<Land> const &value) {
        if (end == capacity) {
            unsigned old = (Ptr32<char>)end - (Ptr32<char>)begin;
            int one = old + 1, grow = old + (old >> 1);
            unsigned bytes = maximum(one, grow) << 2;
            Ptr32<char> p = allocate_80212fd4(bytes);
            if (begin) {
                copy_802eee50(w3d::VA(p), w3d::VA(begin), minimum(bytes, old));
                release_802134fc(begin);
            }
            begin = (Ptr32<Ptr32<Land>>)p;
            end = (Ptr32<Ptr32<Land>>)(p + old);
            capacity = (Ptr32<Ptr32<Land>>)(p + bytes);
        }
        *end = value;
        end++;
    }
};
struct BoxVector {
    Ptr32<Box> begin; Ptr32<Box> end; Ptr32<Box> capacity;
    void push(const Box &value) {
        if (end == capacity) {
            unsigned old = (Ptr32<char>)end - (Ptr32<char>)begin;
            int one = old + 1, grow = old + (old >> 1);
            unsigned bytes = maximum(one, grow) << 5;
            Ptr32<char> p = allocate_80212fd4(bytes);
            if (begin) {
                copy_802eee50(w3d::VA(p), w3d::VA(begin), minimum(bytes, old));
                release_802134fc(begin);
            }
            begin = (Ptr32<Box>)p;
            end = (Ptr32<Box>)(p + old);
            capacity = (Ptr32<Box>)(p + bytes);
        }
        *end = value;
        end++;
    }
};
extern LandVector lands_8043bb64;
extern Ptr32<void> array_804ae5e4;
extern Ptr32<void> selection_804aad30;
inline void Notify(Ptr32<Land> l) { if (selection_804aad30) select_800ba4c4(selection_804aad30, l); }
struct Self { char unknown0[68]; int count; char unknown72[44]; BoxVector boxes; };
extern "C" void d32h_land_spawn_800be3a0(Ptr32<Self> self, Ptr32<const char> name, Ptr32<const Position> pos, Ptr32<const void> orient) {
    Ref resource;
    {
        String s(name);
        load_8015adf4(&s, &resource, 255);
    }
    Ptr32<Object> owner = owner_80182150(resource.p);
    Ref found;
    ((LookupFn)Slot(owner, 56))(owner, type_8040e078, 0, &found);
    Ref held(found.p);
    Ref maker(create_8020b680(key_80413b28));
    ((SetKindFn)Slot(maker.p, 56))(maker.p, 2);
    ((SetOwnerFn)Slot(maker.p, 24))(maker.p, held.p);
    Ref model(((GetFn)Slot(maker.p, 64))(maker.p));
    Ptr32<Land> land = land_ctor_800b12c8(heap_allocate_802098d8(&heap_804adde4, 32));
    Transform t;
    euler_801a3eb0(orient, 0, &t);
    t.position.x = pos->x; t.position.y = pos->y; t.position.z = pos->z;
    attach_800b87d0(land, model.p, &t);
    lands_8043bb64.push(land);
    set_index_800b7ebc(land, self->count++);
    append_801ef174(array_804ae5e4, 44, 3, get_800b4d98(land));
    Notify(land);
    Vec low, high;
    bounds_800b7ed0(land, &low, &high);
    Box box;
    box.high = high;
    box.low = low;
    box.Update(); box.used = 1;
    self->boxes.push(box);
}


