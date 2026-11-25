// GWMP8P rev0 0x8003d9fc. Sets up the particle cloud: finds the Test.Cloud
// mesh and places it, finds Particle.Cloud, makes it visible, sizes its
// arrays by the item count, loads Cloudgr.tga and copies 256 colours from
// its pixels with zero alpha. Names are inferred from the strings.
struct String;
extern "C" void w3d_string_base_finish(String *);
extern "C" void w3d_string_release(String *);
struct String {
    const char *text;
    String(const char *);
    String(const String &o);
    ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct Vec { float x, y, z; Vec(float a, float b, float c) { x = a; y = b; z = c; } };
struct Mesh;
struct MeshTable { char pad[76]; int (*pos)(Mesh *, const Vec *, int); char pad2[8]; int (*vis)(Mesh *, int); };
struct Mesh { MeshTable *t; };
struct Colour { unsigned char r, g, b, a; };
struct Self { char pad[28]; Mesh *mesh; Colour colours[256]; };
struct ArrayHeader { char pad[4]; unsigned short kind; char pad2[18]; int count; unsigned short locks; char pad3[2]; unsigned char data[1]; };
struct ArrayRef { ArrayHeader *header; };
extern "C" unsigned char *w3d_k5b_array_ref_lock_801ef048(ArrayRef *, int, int, int);
inline unsigned char *Lock(ArrayRef *array) {
    ArrayHeader *header = array->header;
    int count = header->count;
    if (header->kind == 1) {
        ++header->locks;
        return header->data;
    }
    return w3d_k5b_array_ref_lock_801ef048(array, count, 1, 2);
}
struct Tex;
struct TexTable { char pad[16]; void (*release)(Tex *); };
struct Tex { TexTable *t; char pad[44]; ArrayRef pixels; };
struct TexRef { Tex *p; TexRef() { p = 0; } TexRef(const TexRef &); ~TexRef() { if (p) p->t->release(p); } };
struct Loader;
struct LoaderTable { char pad[32]; int (*load)(Loader *, const char *, TexRef *); };
struct Loader { LoaderTable *t; };
struct Root;
struct RootTable { char pad[92]; Loader *(*loader)(Root *, const void *); };
struct Root { RootTable *t; };
struct Item { char data[12]; };
struct Items { Item *start; Item *finish; };
extern Items g_items_804273d4[];
extern char g_key_804143e0[];
extern "C" int w3d_handle_set_name(const String &, Mesh **, int);
extern "C" void *w3d_empty_8034380c(Mesh *);
extern "C" int d29j_resize_mesh_arrays_8018920c(void *, int);
extern "C" Root *w3d_auto_8020b648();
extern "C" void w3d_d33a_cloud_setup_8003d9fc(Self *self)
{
    w3d_handle_set_name(String("Test.Cloud"), &self->mesh, 255);
    Mesh *m = self->mesh;
    MeshTable *t = m->t;
    Vec p(0.0f, 20.0f, -100.0f);
    t->pos(m, &p, 0);
    int n = g_items_804273d4->finish - g_items_804273d4->start;
    w3d_handle_set_name(String("Particle.Cloud"), &self->mesh, 255);
    self->mesh->t->vis(self->mesh, 1);
    d29j_resize_mesh_arrays_8018920c(w3d_empty_8034380c(self->mesh), n);
    TexRef tex;
    {
        const void *key = g_key_804143e0;
        Root *r = w3d_auto_8020b648();
        Loader *l = r->t->loader(r, key);
        l->t->load(l, "Cloudgr.tga", &tex);
    }
    unsigned char *s = Lock(&tex.p->pixels);
    for (int i = 0; i < 256; i++) {
        self->colours[i].a = 0;
        self->colours[i].r = s[0];
        self->colours[i].g = s[1];
        self->colours[i].b = s[2];
        s += 3;
    }
}
