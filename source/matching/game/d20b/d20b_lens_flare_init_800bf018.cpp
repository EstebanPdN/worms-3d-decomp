// d20b: 0x800bf018 (700 bytes). Set up a lens flare: load the flare arrays
// resource ("Lens.Flares" in game mode 7, otherwise "FE.Lens.Flares") into
// +32, read the flare settings selected by the style byte (+60) into +36 and
// keep their parameters (+40); fill the seven corner texture coordinates from
// the static table, then for every configured flare copy its kind, square
// size, a zero offset and its colour into the arrays; subscribe to the flare
// message, create the flare handle (+28) at the origin with value 1, set its
// layer (+20), reset the timer (+48), fade (+52, 1) and frame (+44, from the
// engine context) and unlock the arrays.
// 0x8015adf4 forwards the resource manager's virtual load result, so it is
// declared with a status return; the array resize and reserve calls return
// a status too. Built with -mps-float: the unflagged build differs only by the
// 8-byte frame gap below the saved FPR. The float literals 0 and 1 are the
// first two entries of this translation unit's constant pool (0x80382e44).
struct d20b_String_8020bb54 {
 d20b_String_8020bb54(const d20b_String_8020bb54 &);
    char *text;
    d20b_String_8020bb54(const char *);
    ~d20b_String_8020bb54();
};
extern "C" void d20b_string_finish_8020c5c4(d20b_String_8020bb54 *);
extern "C" void d20b_string_release_80341588(d20b_String_8020bb54 *);
inline d20b_String_8020bb54::~d20b_String_8020bb54() {
    d20b_string_finish_8020c5c4(this);
    d20b_string_release_80341588(this);
}
struct d20b_Vec2 {
    float x, y;
    d20b_Vec2 &operator=(const d20b_Vec2 &o) { float a = o.x; float b = o.y; x = a; y = b; return *this; }
};
struct d20b_Vec3 { float x, y, z; void fill(float f) { x = f; y = f; z = f; } };
struct d20b_Colour {
    unsigned char r, g, b, a;
    d20b_Colour &operator=(const d20b_Colour &o) {
        unsigned char r0 = o.r, g0 = o.g, b0 = o.b, a0 = o.a;
        r = r0; g = g0; b = b0; a = a0;
        return *this;
    }
};
struct d20b_FlareArrays;
struct d20b_FlareArraysVtable {
    void *unknown00[22];
    void (*unlock)(d20b_FlareArrays *, int);   // +88
};
struct d20b_FlareArrays { d20b_FlareArraysVtable *vtable; };
struct d20b_FlareItem {
    unsigned char unknown00[20];
    int kind;                            // +20
    int Kind() const { return kind; }
    d20b_Colour colour;                  // +24
    unsigned char unknown28[4];
    float size;                          // +32
};
struct d20b_FlareSet {
    unsigned char unknown00[24];
    unsigned count;                      // +24
    unsigned char unknown28[4];
    d20b_FlareItem *items[1];            // +32
};
struct d20b_FlareParams { unsigned char unknown00[20]; d20b_FlareSet *set; };
struct d20b_FlareCorner { d20b_Vec2 uv0; d20b_Vec2 uv1; };
struct d20b_MessageId { unsigned short value; };
struct d20b_Game { unsigned char unknown000[208]; int mode; };
struct d20b_Context { unsigned char unknown00[48]; int frame; };
struct d20b_Heap { int opaque; };
struct d20b_LensFlare {
    unsigned char unknown00[20];
    int layer;                           // +20
    unsigned char unknown24[4];
    void *handle;                        // +28
    void *flares;                        // +32
    void *config;                        // +36
    d20b_FlareParams *params;            // +40
    int frame;                           // +44
    int timer;                           // +48
    float fade;                          // +52
    unsigned char subscription[4];       // +56
    unsigned char style;                 // +60
};
extern "C" int d20b_handle_load_8015adf4(const d20b_String_8020bb54 *, void **, unsigned char);
extern "C" d20b_FlareArrays *d20b_as_arrays_8034380c(void *);
extern "C" int d20b_setting_read_800fc1b0(const char **, void **);
extern "C" void *d20b_as_config_80341584(void *);
extern "C" d20b_FlareParams *d20b_flare_params_801797b4(void *);
extern "C" int d20b_arrays_resize_80189450(d20b_FlareArrays *, int);
extern "C" d20b_Vec2 *d20b_arrays_uv0_80189884(d20b_FlareArrays *);
extern "C" d20b_Vec2 *d20b_arrays_uv1_801898e0(d20b_FlareArrays *);
extern "C" int d20b_arrays_reserve_8018920c(d20b_FlareArrays *, unsigned);
extern "C" unsigned char *d20b_arrays_kind_80189828(d20b_FlareArrays *);
extern "C" d20b_Vec2 *d20b_arrays_size_8018963c(d20b_FlareArrays *);
extern "C" d20b_Vec3 *d20b_arrays_offset_80189518(d20b_FlareArrays *);
extern "C" d20b_Colour *d20b_arrays_colour_80189760(d20b_FlareArrays *);
extern "C" unsigned short d20b_cached_message_id_8015f5a0(void *, int);
extern "C" int d20b_subscribe_80162024(void *, d20b_MessageId *, void *);
extern "C" void *d20b_heap_allocate_802098d8(d20b_Heap *, unsigned);
extern "C" void *d20b_handle_construct_801261bc(void *, d20b_Vec3 *, float, int, int);   // (handle, bounds, value, slot, owner)
extern "C" void d20b_handle_set_layer_80126308(void *, int);
extern "C" d20b_Context *d20b_engine_context_80165254(void);
extern d20b_Game *d20b_game_804aaabc;
extern const char d20b_lens_flares_80382e28[];      // "Lens.Flares"
extern const char d20b_fe_lens_flares_80382e34[];   // "FE.Lens.Flares"
extern const char *d20b_flare_settings_803f4cb8[];
extern const d20b_FlareCorner d20b_flare_corners_80382e84[7];
extern int d20b_message_cache_804ae60c;
extern d20b_Heap d20b_handle_heap_804af5bc;

extern "C" void d20b_lens_flare_init_800bf018(d20b_LensFlare *self) {
    if (d20b_game_804aaabc->mode == 7) {
        d20b_String_8020bb54 name(d20b_lens_flares_80382e28);
        d20b_handle_load_8015adf4(&name, &self->flares, 255);
    } else {
        d20b_String_8020bb54 name(d20b_fe_lens_flares_80382e34);
        d20b_handle_load_8015adf4(&name, &self->flares, 255);
    }
    d20b_FlareArrays *arrays = d20b_as_arrays_8034380c(self->flares);
    d20b_setting_read_800fc1b0(&d20b_flare_settings_803f4cb8[self->style], &self->config);
    d20b_FlareParams *params = d20b_flare_params_801797b4(d20b_as_config_80341584(self->config));
    self->params = params;
    d20b_FlareSet *set = params->set;
    unsigned count = set->count;
    d20b_FlareItem **items = set->items;
    d20b_arrays_resize_80189450(arrays, 7);
    for (unsigned i = 0; i < 7; i++) {
        const d20b_FlareCorner *c = &d20b_flare_corners_80382e84[i];
        *(d20b_Vec2 *)((char *)d20b_arrays_uv0_80189884(arrays) + (i << 3)) = c->uv0;
        *(d20b_Vec2 *)((char *)d20b_arrays_uv1_801898e0(arrays) + (i << 3)) = c->uv1;
    }
    d20b_arrays_reserve_8018920c(arrays, count);
    for (unsigned i = 0; i < count; i++) {
        d20b_arrays_kind_80189828(arrays)[i] = items[i]->Kind();
        d20b_Vec2 *size = (d20b_Vec2 *)((char *)d20b_arrays_size_8018963c(arrays) + (i << 3));
        float s = items[i]->size;
        size->x = s;
        size->y = s;
        d20b_arrays_offset_80189518(arrays)[i].fill(0.0f);
        const d20b_Colour &colour = items[i]->colour;
        d20b_arrays_colour_80189760(arrays)[i] = colour;
    }
    d20b_MessageId id;
    id.value = d20b_cached_message_id_8015f5a0(&d20b_message_cache_804ae60c, 1);
    d20b_subscribe_80162024(self, &id, self->subscription);
    d20b_Vec3 v;
    d20b_Vec3 *p = &v;
    float zero = 0.0f;
    v.x = zero;
    p->y = zero;
    p->z = zero;
    float one = 1.0f;
    self->handle = d20b_handle_construct_801261bc(d20b_heap_allocate_802098d8(&d20b_handle_heap_804af5bc, 8), p, one, 0, 1);
    d20b_handle_set_layer_80126308(self->handle, self->layer);
    self->fade = one;
    self->timer = 0;
    self->frame = d20b_engine_context_80165254()->frame;
    arrays->vtable->unlock(arrays, 0);
}
