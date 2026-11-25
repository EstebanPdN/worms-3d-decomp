// d18c: 0x801058f0 (468 bytes). Load the moon of a sky: find the first of the
// four sky table entries whose cloud entry is present and whose moon entry
// names this sky, load that entry's moon layer node into +44, give it unit
// scale and the shared moon position, and for the arctic night sky start the
// looping borealis clip on the node (through a retained node reference).
// The translation unit was built with -mps-float: 1.0f stays in f31 across
// calls, and the flag reserves the 8 bytes below the register save area seen
// in the original frame.
// 0x8015adf4 forwards the resource manager's virtual load result, so it is
// declared with a status return. The reference type has a user copy
// constructor, so it reuses the freed name slot as in the original.
// Shared engine string; constructor and release are out of line.
struct d18c_String_8020bb54 {
    char *text;
    d18c_String_8020bb54(const char *);
    d18c_String_8020bb54(const d18c_String_8020bb54 &);
    ~d18c_String_8020bb54();
};
extern "C" void d18c_string_finish_8020c5c4(d18c_String_8020bb54 *);
extern "C" void d18c_string_release_80341588(d18c_String_8020bb54 *);
inline d18c_String_8020bb54::~d18c_String_8020bb54() {
    d18c_string_finish_8020c5c4(this);
    d18c_string_release_80341588(this);
}
struct d18c_Node;
struct d18c_Ref {
    d18c_Node *value;
    d18c_Ref(d18c_Node *object) : value(object) {}
    d18c_Ref(const d18c_Ref &o);
    d18c_Ref &operator=(d18c_Node *object);
    ~d18c_Ref();
};
struct d18c_Vec3 { float x, y, z; };
struct d18c_NodeVtable {
    void *unknown00[3];
    void (*retain)(d18c_Node *);         // +12
    void (*release)(d18c_Node *);        // +16
    void *unknown20[14];
    int (*set_position)(d18c_Node *, const d18c_Vec3 *, int);   // +76
    void *unknown80;
    int (*set_scale)(d18c_Node *, const d18c_Vec3 *, int);      // +84
};
struct d18c_Node { d18c_NodeVtable *vtable; };
inline d18c_Ref &d18c_Ref::operator=(d18c_Node *object) {
    if (object) object->vtable->retain(object);
    if (value) value->vtable->release(value);
    value = object;
    return *this;
}
inline d18c_Ref::~d18c_Ref() { if (value) value->vtable->release(value); }
struct d18c_SkyPair { const char *sky; const char *layer; };
struct d18c_Sky {
    unsigned char unknown00[44];
    d18c_Node *moon;                     // +44
};
extern "C" int d18c_handle_load_8015adf4(const d18c_String_8020bb54 *, d18c_Node **, unsigned char);
extern "C" int strcmp(const char *, const char *);
extern "C" d18c_Node *d18c_as_node_80343584(d18c_Node *);
extern "C" int d18c_play_clip_80181640(d18c_Node *, const char *, int *, int, float, float, float);
extern "C" int d18c_check_control_8018179c(d18c_Node *, int, int);
extern d18c_SkyPair d18c_sky_clouds_803fce18[];
extern d18c_SkyPair d18c_sky_moons_803fce58[];
extern d18c_Vec3 d18c_moon_position_8044b67c;
extern const char *d18c_borealis_clip_804aaf9c;
extern const char d18c_arctic_night_8039971c[];   // "ARCTIC.NIGHTSky"

extern "C" void d18c_sky_moon_load_801058f0(d18c_Sky *self, const char *sky) {
    for (unsigned i = 0; i < 4; i++) {
        if (d18c_sky_clouds_803fce18[i].sky && strcmp(sky, d18c_sky_moons_803fce58[i].sky) == 0) {
            d18c_Vec3 scale;
            d18c_Vec3 *p = &scale;
            scale.x = 1.0f;
            p->y = 1.0f;
            p->z = 1.0f;
            d18c_Vec3 position;
            position.x = d18c_moon_position_8044b67c.x;
            position.y = d18c_moon_position_8044b67c.y;
            position.z = d18c_moon_position_8044b67c.z;
            {
                d18c_String_8020bb54 name(d18c_sky_moons_803fce58[i].layer);
                d18c_handle_load_8015adf4(&name, &self->moon, 255);
            }
            self->moon->vtable->set_scale(self->moon, p, 0);
            self->moon->vtable->set_position(self->moon, &position, 0);
            if (strcmp(sky, d18c_arctic_night_8039971c) == 0) {
                d18c_Ref moon = 0;
                moon = d18c_as_node_80343584(self->moon);
                int control;
                d18c_play_clip_80181640(moon.value, d18c_borealis_clip_804aaf9c, &control, 1, 1.0f, 0.0f, 0.0f);
                d18c_check_control_8018179c(moon.value, control, 1);
            }
            return;
        }
    }
}
