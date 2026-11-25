#include "w3d_ptr.h"
#line 1 "d24g_named_mesh_init_8004e0dc.cpp"
/* Worms 3D GameCube PAL 0x8004e0dc. Initialises a named mesh object: loads two resources by name through one reference (types 0x80343584 and 0x8034357c) into +28 and +32 with retain/release, attaches the second to the first with the mode argument (slot +92), positions it at 0x8045e788 (slot +76), assigns four name strings at +60..+72 and stores 0x8004e544's result in +76. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct String {
    Ptr32<char> text;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    ~String();
    String(const String &);
};
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;       // +12
    Ptr32<void (Ptr32<Object>)> release;      // +16
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Ref {
    Ptr32<Object> value;
    ~Ref() { if (value) value->vtable->release(value); }
    Ref() {}
    Ref(const Ref &);
};
struct Named;
struct Mesh {
    struct V {
        Ptr32<void> u[19];
        Ptr32<void (Ptr32<Mesh>, Ptr32<void>, int)> set_position;  /* +76 */
        Ptr32<void> u80[3];
        Ptr32<void (Ptr32<Mesh>, Ptr32<Object>, int)> attach;      /* +92 */
    }; Ptr32<struct V> vtable;
};
struct Self {
    char u0[28];
    Ptr32<Object> mesh;       /* +28 */
    Ptr32<Object> material;   /* +32 */
    char u36[24];
    char name60[4], name64[4], name68[4], name72[4];
    float value;        /* +76 */
};
extern "C" int load_8015adf4(Ptr32<const String>, Ptr32<Ref>, unsigned char);
extern "C" Ptr32<Object> as_80343584(Ptr32<Object>);
extern "C" Ptr32<Object> as_8034357c(Ptr32<Object>);
extern "C" Ptr32<void> string_assign_8020bd38(Ptr32<void>, Ptr32<const char>);
extern "C" float value_8004e544(Ptr32<Self>, Ptr32<const char>, Ptr32<const char>);
extern char position_8045e788[];
extern "C" void w3d_d24g_named_mesh_init_8004e0dc(Ptr32<Self> self, Ptr32<const char> a, Ptr32<const char> b, int mode, Ptr32<const char> c, Ptr32<const char> d, Ptr32<const char> e)
{
    Ref r;
    r.value = 0;
    Ptr32<Ref> h = &r;
    { String name(a); load_8015adf4(&name, h, 255); }
    {
        Ptr32<Object> o = as_80343584(r.value);
        if (o) o->vtable->retain(o);
        if (self->mesh) self->mesh->vtable->release(self->mesh);
        self->mesh = o;
    }
    { String name(b); load_8015adf4(&name, h, 255); }
    {
        Ptr32<Object> o = as_8034357c(r.value);
        if (o) o->vtable->retain(o);
        if (self->material) self->material->vtable->release(self->material);
        self->material = o;
    }
    ((Ptr32<Mesh>)self->mesh)->vtable->attach((Ptr32<Mesh>)self->mesh, self->material, mode);
    ((Ptr32<Mesh>)self->mesh)->vtable->set_position((Ptr32<Mesh>)self->mesh, position_8045e788, 0);
    string_assign_8020bd38(self->name60, a);
    string_assign_8020bd38(self->name64, c);
    string_assign_8020bd38(self->name68, d);
    string_assign_8020bd38(self->name72, e);
    self->value = value_8004e544(self, a, c);
}


