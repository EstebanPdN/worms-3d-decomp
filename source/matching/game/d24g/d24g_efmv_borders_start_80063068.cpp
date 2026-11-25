/* Worms 3D GameCube PAL 0x80063068. EFMV border bars start-up: subscribes to one message with slot +28, posts two value messages with table 0x8040db38, loads the EFMV.Borders mesh into +40 and three settings into +44..+52 with retain/release, sets EFMV.Active, stores the on-time and its end time, then fills two mesh sprites with black opaque colour, position and half height. The original reuses the String slot at sp+8 for its references. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
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
struct Key { const char *text; };
struct Vec3 { float x, y, z; void set(float a, float b, float c) { x = a; y = b; z = c; } };
struct Rgba {
    unsigned char r, g, b, a;
    Rgba() {}
    Rgba(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) { r = red; g = green; b = blue; a = alpha; }
};
struct Vec2 { float x, y; Vec2() {} };
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Message { unsigned short id; const void *vtable; };
struct Context { char u[48]; int time; };
struct Borders {
    char u0[28];
    char slot28[4];
    int a32, a36;
    Object *mesh;        /* +40 */
    Object *height;      /* +44 */
    Object *onTime;      /* +48 */
    Object *offTime;     /* +52 */
    int endTime;         /* +56 */
    int duration;        /* +60 */
    float x;             /* +64 */
    float h;             /* +68 */
};
extern "C" int load_8015adf4(const String *, void *, unsigned char);
extern "C" int read_800fc1b0(Key *, void *);
extern "C" int write_bool_800fc43c(Key *, int);
extern "C" Object *as_80342a74(Object *);
extern "C" Object *as_80342a78(Object *);
extern "C" Object *as_mesh_8034380c(Object *);
extern "C" int count_80178d1c(Object *);
extern "C" Context *context_80165254();
extern "C" int mesh_alloc_8018920c(Object *, int);
extern "C" Vec2 *mesh_a_8018963c(Object *);
extern "C" Vec3 *mesh_b_80189518(Object *);
extern "C" Rgba *mesh_c_80189760(Object *);
extern "C" unsigned char *mesh_flags_80189704(Object *);
extern "C" int message_id_8015f5a0(MessageCache *, int);
extern "C" int subscribe_80162024(Borders *, const unsigned short &, void *);
extern "C" void *arena_alloc_801613f0(void *, int);
extern "C" int message_post_8016239c(Message *);
extern void *arena_804b1754;
extern char vt_8040db38[];
extern MessageCache msg_804ad528, msg_804ad538, msg_804ad548;
extern const char s_80379b2c[], s_80379b3c[], s_80379b50[], s_80379b64[], s_80379b78[];
#define READ(slot, name, cast) { \
    Ref r; \
    r.value = 0; \
    Key key; \
    key.text = name; \
    read_800fc1b0(&key, &r); \
    Object *o = cast(r.value); \
    if (o) o->vtable->retain(o); \
    if (self->slot) self->slot->vtable->release(self->slot); \
    self->slot = o; \
}
inline void load_mesh(Borders *self, const String *name) {
    Ref r;
    r.value = 0;
    load_8015adf4(name, &r, 255);
    Object *o = as_mesh_8034380c(r.value);
    if (o) o->vtable->retain(o);
    if (self->mesh) self->mesh->vtable->release(self->mesh);
    self->mesh = o;
}
inline void post(MessageCache *cache) {
    Message *m = (Message *)arena_alloc_801613f0(arena_804b1754, 8);
    m->id = message_id_8015f5a0(cache, 1);
    m->vtable = vt_8040db38;
    message_post_8016239c(m);
}
extern "C" void w3d_d24g_efmv_borders_start_80063068(Borders *self)
{
    subscribe_80162024(self, message_id_8015f5a0(&msg_804ad528, 1), self->slot28);
    post(&msg_804ad538);
    post(&msg_804ad548);
    self->a32 = 0;
    self->a36 = 0;
    {
        String name(s_80379b2c);
        load_mesh(self, &name);
    }
    READ(height, s_80379b3c, as_80342a74)
    READ(onTime, s_80379b50, as_80342a78)
    READ(offTime, s_80379b64, as_80342a78)
    {
        Key key;
        key.text = s_80379b78;
        write_bool_800fc43c(&key, 1);
    }
    self->duration = count_80178d1c(self->onTime);
    self->endTime = context_80165254()->time + self->duration;
    Vec2 pos;
    pos.x = self->x;
    pos.y = 0.0f;
    Rgba colour(0, 0, 0, 255);
    mesh_alloc_8018920c(self->mesh, 2);
    Vec2 *a = mesh_a_8018963c(self->mesh);
    Vec3 *b = mesh_b_80189518(self->mesh);
    Rgba *c = mesh_c_80189760(self->mesh);
    unsigned char *flags = mesh_flags_80189704(self->mesh);
    a[0] = pos;
    a[1] = pos;
    b[0].set(0.0f, self->h, 0.0f);
    b[1].set(0.0f, -self->h, 0.0f);
    c[0] = colour;
    c[1] = colour;
    flags[0] = 1;
    flags[1] = 1;
}
