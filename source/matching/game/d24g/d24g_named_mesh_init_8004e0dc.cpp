/* Worms 3D GameCube PAL 0x8004e0dc. Initialises a named mesh object: loads two resources by name through one reference (types 0x80343584 and 0x8034357c) into +28 and +32 with retain/release, attaches the second to the first with the mode argument (slot +92), positions it at 0x8045e788 (slot +76), assigns four name strings at +60..+72 and stores 0x8004e544's result in +76. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct String {
    char *text;
    String(const char *);
    ~String();
    String(const String &);
};
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
struct Object;
struct ObjectVtable {
    void *unknown00[3];
    void (*retain)(Object *);       // +12
    void (*release)(Object *);      // +16
};
struct Object { ObjectVtable *vtable; };
struct Ref {
    Object *value;
    ~Ref() { if (value) value->vtable->release(value); }
    Ref() {}
    Ref(const Ref &);
};
struct Named;
struct Mesh {
    struct V {
        void *u[19];
        void (*set_position)(Mesh *, void *, int);  /* +76 */
        void *u80[3];
        void (*attach)(Mesh *, Object *, int);      /* +92 */
    } *vtable;
};
struct Self {
    char u0[28];
    Object *mesh;       /* +28 */
    Object *material;   /* +32 */
    char u36[24];
    char name60[4], name64[4], name68[4], name72[4];
    float value;        /* +76 */
};
extern "C" int load_8015adf4(const String *, Ref *, unsigned char);
extern "C" Object *as_80343584(Object *);
extern "C" Object *as_8034357c(Object *);
extern "C" void *string_assign_8020bd38(void *, const char *);
extern "C" float value_8004e544(Self *, const char *, const char *);
extern char position_8045e788[];
extern "C" void w3d_d24g_named_mesh_init_8004e0dc(Self *self, const char *a, const char *b, int mode, const char *c, const char *d, const char *e)
{
    Ref r;
    r.value = 0;
    Ref *h = &r;
    { String name(a); load_8015adf4(&name, h, 255); }
    {
        Object *o = as_80343584(r.value);
        if (o) o->vtable->retain(o);
        if (self->mesh) self->mesh->vtable->release(self->mesh);
        self->mesh = o;
    }
    { String name(b); load_8015adf4(&name, h, 255); }
    {
        Object *o = as_8034357c(r.value);
        if (o) o->vtable->retain(o);
        if (self->material) self->material->vtable->release(self->material);
        self->material = o;
    }
    ((Mesh *)self->mesh)->vtable->attach((Mesh *)self->mesh, self->material, mode);
    ((Mesh *)self->mesh)->vtable->set_position((Mesh *)self->mesh, position_8045e788, 0);
    string_assign_8020bd38(self->name60, a);
    string_assign_8020bd38(self->name64, c);
    string_assign_8020bd38(self->name68, d);
    string_assign_8020bd38(self->name72, e);
    self->value = value_8004e544(self, a, c);
}
