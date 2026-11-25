#include "w3d_ptr.h"
#line 1 "d28b_water_construct_8008fb3c.cpp"
/* Water mesh constructor (0x8008fb3c, counterpart of the destructor 0x8009081c): the vptr at +2792
 * comes from the real virtual destructor; members are the lists +60 to +180 (0x801f2678), the held
 * objects, the storage records and an empty 16-entry array. The body publishes the object in
 * 0x804aab68, allocates the buffers from the heap 0x804adde4, creates the held objects through
 * 0x8020b680, sets their fields and dirty bits, fills the three static colours under their guards
 * and sets the material +224 from them, builds the group at +192 through 0x801ef174, runs the table
 * builders 0x8008f410, 0x8008f478, 0x8008f7c4, and reads Water.Density, GlobalLight.Ambient,
 * GlobalLight.Diffuse and Water.TweakName. Class layouts are partial views; names are inferred from
 * the original instructions. Owns the property strings and float literals from 0x8037e808. */
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;   /* +12 */
    Ptr32<void (Ptr32<Object>)> release;  /* +16 */
};
struct Sub { char unknown00[4]; unsigned char flags; char w3d_tag_rest[3]; void Mark(int bit) { flags |= bit; } };
struct ArrayHeader { char unknown00[4]; unsigned short refs; char unknown06[18]; int count; unsigned short gen; char unknown30[2]; char data[1]; };
struct Array { Ptr32<ArrayHeader> header; };
extern "C" Ptr32<void> w3d_array_ref_lock_801ef048(Ptr32<Array>, int, int, int);
struct Color { unsigned a, b, c, d; };
struct Object {
    Ptr32<ObjectVtable> vtable; Sub sub; char unknown12[8]; Array array;
    int i24; int i28; int i32;
    void SetA(int v) { i24 = v; sub.Mark(2); }
    void SetB(int v) { i28 = v; sub.Mark(2); }
    void SetC(int v) { i32 = v; sub.Mark(2); }
    void SetF(float v);
    };
struct Shade { char unknown00[24]; float f24; };
inline void Object::SetF(float v) { ((Ptr32<Shade>)this)->f24 = v; sub.Mark(2); }
struct Colored { char unknown00[4]; Sub sub; char unknown12[12]; Color c24; Color c40; Color c56; Color c72; float f88;
    void SetC24(const Color &v) { c24 = v; sub.Mark(2); }
    void SetC40(const Color &v) { c40 = v; sub.Mark(2); }
    void SetC56(const Color &v) { c56 = v; sub.Mark(2); }
    void SetC72(const Color &v) { c72 = v; sub.Mark(2); }
    void SetF88(float v) { f88 = v; sub.Mark(2); }
};
extern "C" Ptr32<Object> w3d_create_8020b680(Ptr32<void>);
struct Held {
    Ptr32<Object> object;
    Held() : object(0) {}
    Held(const Held &o);
    ~Held() { if (object) object->vtable->release(object); }
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Object *)w3d_p.get()); }
 void operator=(Object *n) {
        if (n) n->vtable->retain(n);
        if (object) object->vtable->release(object);
        object = n;
    }
    void operator=(const Held &o) {
        if (o.object) o.object->vtable->retain(o.object);
        if (object) object->vtable->release(object);
        object = o.object;
    }
    Ptr32<Object> operator->() const { return object; }
    Ptr32<struct Colored> c() const { return (Ptr32<struct Colored>)object; }
};
struct Storage { Ptr32<void> begin; Ptr32<void> middle; Ptr32<void> end; Storage() { end = 0; middle = 0; begin = 0; } };
struct List_801f2678 { char unknown00[12]; List_801f2678(); };
struct Empty16 { float v[4]; Empty16() {} };
struct Vec3 { float x, y, z; void Set(float a, float b, float c) { Ptr32<Vec3> p = this; x = a; p->y = b; p->z = c; } };
struct Mat48 { unsigned v[12]; };
struct Inner { int value; int a; int b; int c; Inner() { a = 0; c = 0; b = 0; } };
struct PropertyKey { Ptr32<const char> name; };
struct Scheme { char unknown00[120]; int value; };
extern "C" Ptr32<void> w3d_heap_alloc_802098d8(Ptr32<void>, unsigned);
extern "C" void w3d_append_801ef174(Ptr32<Object>, int, int, Ptr32<Object>);
extern "C" int w3d_read_800fc1b0(Ptr32<PropertyKey>, Ptr32<void>);
extern "C" int w3d_read_800fc2b0(Ptr32<PropertyKey>, Ptr32<Ptr32<const char>>);
extern "C" int w3d_read_800fc330(Ptr32<PropertyKey>, Ptr32<Ptr32<Scheme>>);
struct D28bWater;
extern "C" void w3d_bit_table_8008f410(Ptr32<D28bWater>);
extern "C" void w3d_unit_table_8008f478();
extern "C" void w3d_light_tables_8008f7c4();
extern char lbl_80414840[], lbl_80415c00[], lbl_80415cb0[], lbl_80415c10[], lbl_80415c30[], lbl_80415bb0[], lbl_80415ba0[], lbl_80415bd0[], lbl_80415b00[];
extern Mat48 lbl_8045e748[];
extern char lbl_804adde4;
extern Ptr32<D28bWater> lbl_804aab68;
extern Ptr32<void> lbl_804b1800;
extern int lbl_804b1804, lbl_804b1808, lbl_804b17f8;
extern int lbl_804addb4, lbl_804addb8, lbl_804addbc;
extern Color lbl_80431e58[], lbl_80431e68[], lbl_80431e78[];
struct D28bWater {
    char unknown00[12]; int i12; int i16; int i20; int i24; Inner inner; char unknown44[8]; Ptr32<void> buffer52; int unknown56;
    List_801f2678 list60; List_801f2678 list72; List_801f2678 list84; List_801f2678 list96; List_801f2678 list108;
    List_801f2678 list120; List_801f2678 list132; List_801f2678 list144; List_801f2678 list156; List_801f2678 list168; List_801f2678 list180;
    Held held192; Held held196; Held held200; Held held204; Held held208; Held held212; Held held216;
    Held held220; Held held224; Held held228; Held held232; Held held236; Held held240;
    int unknown244; Vec3 v248; char unknown260[12]; Mat48 m272; char unknown320[48];
    Held held368; Ptr32<void> locked372; char unknown376[144]; Vec3 v520; int proto532; int value536; char unknown540[16];
    Held held556; Held held560; char unknown564[108];
    Ptr32<void> b672; Ptr32<void> b676; Ptr32<void> b680; Ptr32<void> b684; Ptr32<void> b688; Ptr32<void> b692; Ptr32<void> b696; int unknown700;
    Ptr32<void> b704; Ptr32<void> b708; Ptr32<void> b712; Ptr32<void> b716; Ptr32<void> v720; Ptr32<void> a724[1]; char unknown728[36]; int value764; char unknown768[1536];
    Storage s2304; Storage s2316; Storage s2328; Storage s2340; Storage s2352; Storage s2364; Storage s2376;
    Storage s2388; Storage s2400; Storage s2412; Storage s2424; Storage s2436; Storage s2448; Storage s2460;
    Ptr32<void> b2472; char unknown2476[12]; int value2488; Ptr32<void> v2492; Ptr32<void> b2496[1]; char unknown2500[12]; Empty16 grid[16];
    Storage s2768; Held held2780; Held held2784; Held held2788;
    D28bWater();
    ~D28bWater();
 __attribute__((always_inline)) inline void w3d_vdt(int w3d_in) const { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_D28bWater, 2))(w3d::h2g(this), w3d_in); }  Ptr32<void> w3d_vptr_D28bWater; };
inline Ptr32<void> Lock(Ptr32<Array> a, int count, int size, int flag) {
    Ptr32<ArrayHeader> h = a->header;
    if (h->refs == 1 && h->count == count) { h->gen++; return h->data; }
    return w3d_array_ref_lock_801ef048(a, count, size, flag);
}
inline Ptr32<void> Alloc(unsigned n) { return w3d_heap_alloc_802098d8(&lbl_804adde4, n); }
D28bWater::D28bWater() { W3D_SET_VPTR(this->w3d_vptr_D28bWater, w3d_vt___vt_9D28bWater, "__vt_9D28bWater"); 
    lbl_804aab68 = this;
    value764 = 0;
    for (unsigned i = 0; i < 1; i++) {
        a724[i] = Alloc(729);
        b2496[i] = Alloc(11664);
    }
    buffer52 = Alloc(6144);
    lbl_804b1800 = Alloc(256);
    b2472 = Alloc(32928);
    b672 = Alloc(36864);
    b692 = Alloc(12288);
    b696 = Alloc(2916);
    b676 = Alloc(24576);
    b680 = Alloc(12288);
    b684 = Alloc(12288);
    b688 = Alloc(12288);
    b704 = Alloc(65856);
    b716 = Alloc(10976);
    b708 = Alloc(43904);
    Ptr32<void> last = Alloc(21952);
    v720 = a724[0];
    b712 = last;
    v2492 = b2496[0];
    held368 = w3d_create_8020b680(lbl_80414840);
    locked372 = Lock(&held368.object->array, 256, 2, 1);
    v248.Set(0.0f, -1.0f, 0.0f);
    v520.Set(0.0f, 0.0f, 0.0f);
    m272 = lbl_8045e748[0];
    held240 = w3d_create_8020b680(lbl_80415c00);
    { Ptr32<char> type = lbl_80415cb0;
      held196 = w3d_create_8020b680(type);
      held200 = w3d_create_8020b680(type);
      held204 = w3d_create_8020b680(type); }
    held208 = w3d_create_8020b680(lbl_80415c10);
    { Ptr32<char> type = lbl_80415c30;
      held212 = w3d_create_8020b680(type);
      held216 = w3d_create_8020b680(type);
      held220 = w3d_create_8020b680(type);
      held228 = w3d_create_8020b680(type); }
    held232 = w3d_create_8020b680(lbl_80415bb0);
    held224 = w3d_create_8020b680(lbl_80415ba0);
    held236 = w3d_create_8020b680(lbl_80415bd0);
    held196->SetB(6);
    held196->SetA(7);
    held200->SetB(7);
    held200->SetA(1);
    held204->SetB(6);
    held204->SetA(1);
    held208->SetC(3);
    held240->SetA(0);
    held212->SetA(1);
    held216->SetA(2);
    held220->SetA(0);
    held228->SetA(0);
    held232->SetB(4);
    held232->SetF(0.0f);
    held232->SetC(1);
    held236->SetA(1);
    if (lbl_804addb4 == 0) {
        lbl_804addb4 = 1;
        ((Ptr32<float>)&lbl_80431e58)[0] = 1.0f; ((Ptr32<float>)&lbl_80431e58)[1] = 1.0f; ((Ptr32<float>)&lbl_80431e58)[2] = 1.0f; ((Ptr32<float>)&lbl_80431e58)[3] = 1.0f;
    }
    if (lbl_804addb8 == 0) {
        lbl_804addb8 = 1;
        ((Ptr32<float>)&lbl_80431e68)[0] = 0.0f; ((Ptr32<float>)&lbl_80431e68)[1] = 0.0f; ((Ptr32<float>)&lbl_80431e68)[2] = 0.0f; ((Ptr32<float>)&lbl_80431e68)[3] = 0.0f;
    }
    if (lbl_804addbc == 0) {
        ((Ptr32<float>)&lbl_80431e78)[0] = 0.75f; ((Ptr32<float>)&lbl_80431e78)[1] = 0.75f; ((Ptr32<float>)&lbl_80431e78)[2] = 0.75f; ((Ptr32<float>)&lbl_80431e78)[3] = 0.0f;
        lbl_804addbc = 1;
    }
    held224.c()->SetC56(lbl_80431e58[0]);
    held224.c()->SetC72(lbl_80431e58[0]);
    held224.c()->SetC24(lbl_80431e68[0]);
    held224.c()->SetC40(lbl_80431e68[0]);
    held224.c()->SetF88(20.0f);
    held224->sub.Mark(1);
    Held local;
    local = w3d_create_8020b680(lbl_80415b00);
    w3d_append_801ef174(local.object, 28, 3, held224.object);
    w3d_append_801ef174(local.object, 28, 3, held216.object);
    w3d_append_801ef174(local.object, 28, 3, held208.object);
    w3d_append_801ef174(local.object, 28, 3, held196.object);
    held192 = local;
    local = (Ptr32<Object>)0;
    w3d_bit_table_8008f410(this);
    w3d_unit_table_8008f478();
    w3d_light_tables_8008f7c4();
    PropertyKey density; density.name = "Water.Density";
    w3d_read_800fc1b0(&density, &held2780);
    PropertyKey ambient; ambient.name = "GlobalLight.Ambient";
    w3d_read_800fc1b0(&ambient, &held2784);
    PropertyKey diffuse; diffuse.name = "GlobalLight.Diffuse";
    w3d_read_800fc1b0(&diffuse, &held2788);
    value536 = 1;
    proto532 = 0;
    lbl_804b1804 = 0;
    lbl_804b1808 = 0;
    lbl_804b17f8 = 0;
    i20 = 0; i12 = 0; i24 = 0; i16 = 0;
    PropertyKey tweak; tweak.name = "Water.TweakName";
    PropertyKey name;
    w3d_read_800fc2b0(&tweak, &name.name);
    Ptr32<Scheme> scheme = 0;
    w3d_read_800fc330(&name, &scheme);
    value2488 = scheme->value;
    ((Ptr32<unsigned char>)&value2488)[3] = 0;
}


