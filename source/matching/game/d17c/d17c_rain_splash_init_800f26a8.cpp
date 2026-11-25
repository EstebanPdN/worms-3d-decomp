// d17c: 0x800f26a8 (356 bytes). Initialise a water surface's rain splashes:
// load the "Particle.RainSplash" mesh into the owner's mesh slot (+28,
// retained; the previous mesh is released), read the "Water.Level" setting
// into +1040, size the mesh for 50 splashes, clear their flags, set every
// splash UV pair to 0.1 and colour to (255, 255, 255, 200), and remember the
// engine context tick (+1036).
// 0x8015adf4 forwards the resource manager's virtual load result, so it is
// declared with a status return. The named string is handed to the inline
// loader by address, so its address is kept in a register after construction.
// The 0.1f literal forms this function's constant pool at 0x8038c4a0.
struct d17c_String_8020bb54 {
 d17c_String_8020bb54(const d17c_String_8020bb54 &);
    char *text;
    d17c_String_8020bb54(const char *);
    ~d17c_String_8020bb54();
};
extern "C" void d17c_string_finish_8020c5c4(d17c_String_8020bb54 *);
extern "C" void d17c_string_release_80341588(d17c_String_8020bb54 *);
inline d17c_String_8020bb54::~d17c_String_8020bb54() {
    d17c_string_finish_8020c5c4(this);
    d17c_string_release_80341588(this);
}
struct d17c_Object;
struct d17c_ObjectVtable {
    void *unknown00[3];
    void (*retain)(d17c_Object *);       // +12
    void (*release)(d17c_Object *);      // +16
};
struct d17c_Object { d17c_ObjectVtable *vtable; };
// Retaining reference (one pointer); released when it goes out of scope.
struct d17c_Ref {
    d17c_Object *value;
    ~d17c_Ref() { if (value) value->vtable->release(value); }
};
// Settings key: a pointer to the setting's name.
struct d17c_Key { const char *text; };
struct d17c_Context { unsigned char unknown00[52]; int tick; };
struct d17c_Water {
    unsigned char unknown000[28];
    d17c_Object *mesh;                   // +28
    unsigned char unknown032[1004];
    int tick;                            // +1036
    float level;                         // +1040
};
struct d17c_Uv { float u, v; };
struct d17c_Rgba { signed char r, g, b, a; };
extern "C" int d17c_handle_load_8015adf4(const d17c_String_8020bb54 *, d17c_Object **, unsigned char);
extern "C" void d17c_read_float_800fc270(d17c_Key *, float *);
extern "C" d17c_Object *d17c_as_mesh_8034380c(d17c_Object *);
extern "C" int d17c_mesh_alloc_8018920c(d17c_Object *, int);
extern "C" unsigned char *d17c_mesh_flags_80189704(d17c_Object *);
extern "C" d17c_Uv *d17c_mesh_uvs_8018963c(d17c_Object *);
extern "C" d17c_Rgba *d17c_mesh_colours_80189760(d17c_Object *);
extern "C" void *memset(void *, int, unsigned long);
extern "C" d17c_Context *d17c_engine_context_80165254(void);
extern const char d17c_rain_splash_8038c480[];   // "Particle.RainSplash"
extern const char d17c_water_level_8038c494[];   // "Water.Level"

static inline void d17c_load_mesh(d17c_Object *&slot, const d17c_String_8020bb54 *name) {
    d17c_Ref loaded;
    loaded.value = 0;
    d17c_handle_load_8015adf4(name, &loaded.value, 255);
    d17c_Object *mesh = d17c_as_mesh_8034380c(loaded.value);
    if (mesh) mesh->vtable->retain(mesh);
    if (slot) slot->vtable->release(slot);
    slot = mesh;
}

extern "C" void d17c_rain_splash_init_800f26a8(d17c_Water *self) {
    {
        d17c_String_8020bb54 name(d17c_rain_splash_8038c480);
        d17c_load_mesh(self->mesh, &name);
    }
    d17c_Key key;
    key.text = d17c_water_level_8038c494;
    d17c_read_float_800fc270(&key, &self->level);
    d17c_mesh_alloc_8018920c(self->mesh, 50);
    unsigned char *flags = d17c_mesh_flags_80189704(self->mesh);
    d17c_Uv *uv = d17c_mesh_uvs_8018963c(self->mesh);
    d17c_Rgba *colour = d17c_mesh_colours_80189760(self->mesh);
    memset(flags, 0, 50);
    for (int i = 0; i < 50; i++) {
        uv[i].u = 0.1f;
        uv[i].v = 0.1f;
        colour[i].r = -1;
        colour[i].g = -1;
        colour[i].b = -1;
        colour[i].a = -56;
    }
    self->tick = d17c_engine_context_80165254()->tick;
}
