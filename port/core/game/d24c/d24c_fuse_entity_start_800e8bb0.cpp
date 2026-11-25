#include "w3d_ptr.h"
#line 1 "d24c_fuse_entity_start_800e8bb0.cpp"
// d24c: 0x800e8bb0 (816 bytes). Start a fused entity: read the "FuseTime"
// setting into +100 and subscribe eleven message handlers (+104..+144); read its
// settings and remember the engine tick (+164); release and clear the held
// references (+172, +168); call its virtual +44 reset; set +36 from the shared
// origin, fill +84 and derive +36 from it, copy +36 to +48; store the settings'
// +276 in +156; create the HUD entry (+96) from the 0x80410a10 descriptor,
// register it and hide it; attach the payload unless the settings' kind equals
// the 0x8038b1f8 text; rebuild the scene; and run the three per-tick updates
// once. Names are inferred. The null local declared after the first read is the
// zero kept in a saved register for the two clears; message ids are one-short
// structs. One-word String and handle classes with user copy constructors
// (d24r).
typedef unsigned int size_t;
struct String {
    Ptr32<char> text;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &);
    ~String();
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
struct Key { Ptr32<const char> text; };
extern "C" int read_800fc1b0(Ptr32<Key>, Ptr32<void>);

struct MessageId { short value; };
struct Vec3 {
    float x, y, z;
    Vec3(const Vec3 &o) : x(o.x), y(o.y), z(o.z) {}
};
struct Words { int a, b, c; };
struct Settings { unsigned char u0[276]; int fuse276; unsigned char u280[132]; Ptr32<const char> kind; };
struct Fuse {
    struct V { Ptr32<void> u[11]; Ptr32<void (Ptr32<Fuse>)> reset; }; Ptr32<struct V> vtable;   // +0
    unsigned char u4[16];
    int id;              // +20
    unsigned char u24[4];
    Ptr32<void> resource;      // +28
    unsigned char u32[4];
    Words a;             // +36
    Words b;             // +48
    unsigned char u60[24];
    Vec3 c;              // +84
    Ptr32<void> hud;           // +96
    int fuse;            // +100
    int m[11];           // +104..+144
    unsigned char u148[8];
    int fuse156;         // +156
    unsigned char u160[4];
    int tick;            // +164
    Ptr32<Object> held168;     // +168
    Ptr32<Object> held172;     // +172
};
struct Context { unsigned char u[52]; int tick; };
extern "C" short message_id_8015f5a0(Ptr32<int>, int);
extern "C" int subscribe_80162024(Ptr32<Fuse>, Ptr32<MessageId>, Ptr32<int>);
extern "C" Ptr32<void> identity_80341584(Ptr32<void>);
extern "C" Ptr32<Settings> settings_801797b4(Ptr32<void>);
extern "C" Ptr32<Context> context_80165254(void);
extern "C" void fn_800e96a0(Ptr32<Fuse>, Ptr32<Vec3>);
extern "C" void fn_800e9204(Ptr32<Fuse>, Ptr32<Vec3>, Ptr32<Words>);
extern "C" Ptr32<void> forward_8020b680(Ptr32<const void>);
extern "C" int fn_80164514(Ptr32<void>, Ptr32<void>, int);
extern "C" void hud_visible_8011afac(Ptr32<void>, int);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" void attach_800e9b88(Ptr32<Fuse>);
extern "C" void scene_800e9e04(Ptr32<Fuse>);
extern "C" void fn_800e9528(Ptr32<Fuse>, int);
extern "C" void fn_800e95e0(Ptr32<Fuse>, int);
extern "C" void fn_800e962c(Ptr32<Fuse>, int);
extern Ptr32<void> service_804b178c;
extern const Words origin_8045e788[];
extern const unsigned char key_80410a10[];
extern const char kind_8038b1f8[], fuse_8038b224[];
extern int c0_804aee58, c1_804aee60, c2_804aee68, c3_804aee78, c4_804aee80, c5_804aee88, c6_804aee90, c7_804aeea0, c8_804aee98, c9_804aeea8, c10_804aeeb0;
#define LISTEN(id, cache, field) \
    id.value = message_id_8015f5a0(&cache, 1); \
    subscribe_80162024(self, &id, &field);
inline int differs(Ptr32<const char> a, Ptr32<const char> b) { return strcmp(a, b) != 0; }
extern "C" void d24c_fuse_entity_start_800e8bb0(Ptr32<Fuse> self) {
    { Key k; k.text = fuse_8038b224; read_800fc1b0(&k, &self->fuse); }
    Ptr32<Object> none = 0;
    MessageId i0, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10;
    LISTEN(i0, c0_804aee58, self->m[0])
    LISTEN(i1, c1_804aee60, self->m[1])
    LISTEN(i2, c2_804aee68, self->m[2])
    LISTEN(i3, c3_804aee78, self->m[3])
    LISTEN(i4, c4_804aee80, self->m[5])
    LISTEN(i5, c5_804aee88, self->m[4])
    LISTEN(i6, c6_804aee90, self->m[6])
    LISTEN(i7, c7_804aeea0, self->m[7])
    LISTEN(i8, c8_804aee98, self->m[8])
    LISTEN(i9, c9_804aeea8, self->m[9])
    LISTEN(i10, c10_804aeeb0, self->m[10])
    Ptr32<Settings> t = settings_801797b4(identity_80341584(self->resource));
    self->tick = context_80165254()->tick;
    if (self->held172) self->held172->vtable->release(self->held172);
    self->held172 = none;
    if (self->held168) self->held168->vtable->release(self->held168);
    self->held168 = none;
    Ptr32<Words> a = &self->a;
    Ptr32<Vec3> c = &self->c;
    self->vtable->reset(self);
    self->a = origin_8045e788[0];
    fn_800e96a0(self, c);
    Vec3 v(*c);
    fn_800e9204(self, &v, a);
    self->b = *a;
    self->fuse156 = t->fuse276;
    self->hud = forward_8020b680(key_80410a10);
    fn_80164514(service_804b178c, self->hud, self->id);
    hud_visible_8011afac(self->hud, 0);
    if (differs(t->kind, kind_8038b1f8)) attach_800e9b88(self);
    scene_800e9e04(self);
    int tick = context_80165254()->tick;
    fn_800e9528(self, tick);
    fn_800e95e0(self, tick);
    fn_800e962c(self, tick);
}


