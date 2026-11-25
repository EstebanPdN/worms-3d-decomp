#include "w3d_ptr.h"
#line 1 "d33a_cloud_setup_8003d9fc.cpp"
// GWMP8P rev0 0x8003d9fc. Sets up the particle cloud: finds the Test.Cloud
// mesh and places it, finds Particle.Cloud, makes it visible, sizes its
// arrays by the item count, loads Cloudgr.tga and copies 256 colours from
// its pixels with zero alpha. Names are inferred from the strings.
struct String;
extern "C" void w3d_string_base_finish(Ptr32<String>);
extern "C" void w3d_string_release(Ptr32<String>);
struct String {
    Ptr32<const char> text;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &o);
    ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct Vec { float x, y, z; Vec(float a, float b, float c) { x = a; y = b; z = c; } };
struct Mesh;
struct MeshTable { char pad[76]; Ptr32<int (Ptr32<Mesh>, Ptr32<const Vec>, int)> pos; char pad2[8]; Ptr32<int (Ptr32<Mesh>, int)> vis; };
struct Mesh { Ptr32<MeshTable> t; };
struct Colour { unsigned char r, g, b, a; };
struct Self { char pad[28]; Ptr32<Mesh> mesh; Colour colours[256]; };
struct ArrayHeader { char pad[4]; unsigned short kind; char pad2[18]; int count; unsigned short locks; char pad3[2]; unsigned char data[1]; };
struct ArrayRef { Ptr32<ArrayHeader> header; };
extern "C" Ptr32<unsigned char> w3d_k5b_array_ref_lock_801ef048(Ptr32<ArrayRef>, int, int, int);
inline Ptr32<unsigned char> Lock(Ptr32<ArrayRef> array) {
    Ptr32<ArrayHeader> header = array->header;
    int count = header->count;
    if (header->kind == 1) {
        ++header->locks;
        return header->data;
    }
    return w3d_k5b_array_ref_lock_801ef048(array, count, 1, 2);
}
struct Tex;
struct TexTable { char pad[16]; Ptr32<void (Ptr32<Tex>)> release; };
struct Tex { Ptr32<TexTable> t; char pad[44]; ArrayRef pixels; };
struct TexRef { Ptr32<Tex> p; TexRef() { p = 0; } TexRef(const TexRef &); ~TexRef() { if (p) p->t->release(p); } };
struct Loader;
struct LoaderTable { char pad[32]; Ptr32<int (Ptr32<Loader>, Ptr32<const char>, Ptr32<TexRef>)> load; };
struct Loader { Ptr32<LoaderTable> t; };
struct Root;
struct RootTable { char pad[92]; Ptr32<Ptr32<Loader> (Ptr32<Root>, Ptr32<const void>)> loader; };
struct Root { Ptr32<RootTable> t; };
struct Item { char data[12]; };
struct Items { Ptr32<Item> start; Ptr32<Item> finish; };
extern Items g_items_804273d4[];
extern char g_key_804143e0[];
extern "C" int w3d_handle_set_name(const String &, Ptr32<Ptr32<Mesh>>, int);
extern "C" Ptr32<void> w3d_empty_8034380c(Ptr32<Mesh>);
extern "C" int d29j_resize_mesh_arrays_8018920c(Ptr32<void>, int);
extern "C" Ptr32<Root> w3d_auto_8020b648();
extern "C" void w3d_d33a_cloud_setup_8003d9fc(Ptr32<Self> self)
{
    w3d_handle_set_name(String("Test.Cloud"), &self->mesh, 255);
    Ptr32<Mesh> m = self->mesh;
    Ptr32<MeshTable> t = m->t;
    Vec p(0.0f, 20.0f, -100.0f);
    t->pos(m, &p, 0);
    int n = g_items_804273d4->finish - g_items_804273d4->start;
    w3d_handle_set_name(String("Particle.Cloud"), &self->mesh, 255);
    self->mesh->t->vis(self->mesh, 1);
    d29j_resize_mesh_arrays_8018920c(w3d_empty_8034380c(self->mesh), n);
    TexRef tex;
    {
        Ptr32<const void> key = g_key_804143e0;
        Ptr32<Root> r = w3d_auto_8020b648();
        Ptr32<Loader> l = r->t->loader(r, key);
        l->t->load(l, "Cloudgr.tga", &tex);
    }
    Ptr32<unsigned char> s = Lock(&tex.p->pixels);
    for (int i = 0; i < 256; i++) {
        self->colours[i].a = 0;
        self->colours[i].r = s[0];
        self->colours[i].g = s[1];
        self->colours[i].b = s[2];
        s += 3;
    }
}


