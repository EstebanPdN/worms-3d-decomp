#include "w3d_ptr.h"
#line 1 "d25c_weapon_trail_update_800cd834.cpp"
// d25c: 0x800cd834. Create the weapon trail on first use, then write the segment from the spawn point to the
// last point of the path. Names are inferred. Name has no destructor: the original never destroys this
// object, though its constructor is the engine string's (0x8020bb54).
struct Object;
struct ObjectVtable { Ptr32<void> u[3]; Ptr32<void (Ptr32<Object>)> retain; Ptr32<void (Ptr32<Object>)> release; };
struct Object { Ptr32<ObjectVtable> vtable; };
struct Ref {
    Ptr32<Object> value;
    template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Object *)w3d_p.get()) {}
 Ref(Object *o) : value(o) { if (value) value->vtable->retain(value); }
    ~Ref() { if (value) value->vtable->release(value); }
};
struct Name { int h; template <class W3dU> Name(Ptr32<W3dU> w3d_p) : Name((const char *)w3d_p.get()) {}
 Name(const char *); Name(const Name &); };
struct Vec3 { float x, y, z; Vec3(const Vec3 &o); };
struct Entity;
struct Path;
struct Self { char u0[20]; int f20; char u24[8]; int handle; };
extern "C" Ptr32<Object> forward_8020b680(Ptr32<const void>);
extern Ptr32<void> graphics_804b178c;
extern const unsigned char key_80410b08[];
extern "C" int create_80164514(Ptr32<void>, Ptr32<Object>, int);
extern "C" void init_801222cc(Ptr32<Object>, const Name &, int, int, int);
extern "C" Ptr32<Entity> lookup_80164fc8(int);
extern "C" int count_800d0f54(Ptr32<Path>);
extern "C" Vec3 spawn_800ccc14(Ptr32<Self>);
extern "C" Vec3 at_800d0f74(Ptr32<Path>, int);
extern "C" void seg_80122800(Ptr32<Entity>, const Vec3 &, const Vec3 &, int);
extern "C" void d25c_weapon_trail_update_800cd834(Ptr32<Self> self, Ptr32<Path> p) {
    bool first = false;
    if (self->handle == -1) {
        Ref r(forward_8020b680(key_80410b08));
        first = true;
        self->handle = create_80164514(graphics_804b178c, r.value, self->f20);
        Name n("Weapon.Trail");
        init_801222cc(r.value, n, 10, 0, 1);
    }
    Ptr32<Entity> e = lookup_80164fc8(self->handle);
    if (e == 0) {
        self->handle = -1;
        return;
    }
    int n = count_800d0f54(p);
    Vec3 start = spawn_800ccc14(self);
    if (first) {
        for (int i = 0; i < 10; i++) seg_80122800(e, start, start, 0);
    }
    int last = n - 1;
    if (last < 0) last = 0;
    Vec3 end = at_800d0f74(p, last);
    seg_80122800(e, start, end, 0);
}


