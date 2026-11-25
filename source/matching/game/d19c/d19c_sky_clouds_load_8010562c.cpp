// d19c: 0x8010562c (708 bytes). Load the clouds of a sky: find the first of
// the five sky/cloud table entries whose sky name matches, load its cloud layer
// node into +36 with load mode 255, hand the node's owner value to the sky
// (0x80106300), give it unit scale and the shared sky layer position, and start
// the looping "Cloud_Loop" clip on it through a retained node reference. Then
// load the same layer again into +40 with load mode 6 as the mirrored copy
// (scale and position negated on Y) and start the same clip on it.
// The translation unit is built with -mps-float (1.0f stays in f31 across
// calls; the flag reserves the 8 bytes below the register save area seen in
// the original frame), like the sibling moon loader 0x801058f0.
// 0x8015adf4 forwards the resource manager's virtual load result (int). The
// clip player 0x80181640 takes its integer flags after the three floats (the
// register assignment is the same either way; this order reproduces the
// original argument scheduling). The reference type has a user copy
// constructor, so it reuses the freed name slot as in the original.
// Shared engine string; constructor and release are out of line.
struct d19c_String_8020bb54 {
    char *text;
    d19c_String_8020bb54(const char *);
    d19c_String_8020bb54(const d19c_String_8020bb54 &);
    ~d19c_String_8020bb54();
};
extern "C" void d19c_string_finish_8020c5c4(d19c_String_8020bb54 *);
extern "C" void d19c_string_release_80341588(d19c_String_8020bb54 *);
inline d19c_String_8020bb54::~d19c_String_8020bb54() {
    d19c_string_finish_8020c5c4(this);
    d19c_string_release_80341588(this);
}
struct d19c_Node;
struct d19c_Ref {
    d19c_Node *value;
    d19c_Ref(d19c_Node *object) : value(object) {}
    d19c_Ref(const d19c_Ref &o);
    d19c_Ref &operator=(d19c_Node *object);
    ~d19c_Ref();
};
struct d19c_Vec3 { float x, y, z; };
struct d19c_NodeVtable {
    void *unknown00[3];
    void (*retain)(d19c_Node *);         // +12
    void (*release)(d19c_Node *);        // +16
    void *unknown20[14];
    int (*set_position)(d19c_Node *, const d19c_Vec3 *, int);   // +76
    void *unknown80;
    int (*set_scale)(d19c_Node *, const d19c_Vec3 *, int);      // +84
};
struct d19c_Node { d19c_NodeVtable *vtable; };
inline d19c_Ref &d19c_Ref::operator=(d19c_Node *object) {
    if (object) object->vtable->retain(object);
    if (value) value->vtable->release(value);
    value = object;
    return *this;
}
inline d19c_Ref::~d19c_Ref() { if (value) value->vtable->release(value); }
struct d19c_SkyPair { const char *sky; const char *layer; };   // {"ENGLAND.NIGHTSky", "ENGLAND.NIGHTClouds"}, ...
struct d19c_Sky {
    unsigned char unknown00[36];
    d19c_Node *clouds;                   // +36
    d19c_Node *clouds_mirror;            // +40
};
extern "C" int d19c_handle_load_8015adf4(const d19c_String_8020bb54 *, d19c_Node **, unsigned char);
extern "C" int strcmp(const char *, const char *);
extern "C" d19c_Node *d19c_as_node_80343584(d19c_Node *);
extern "C" int d19c_owner_value_80182150(d19c_Node *);
extern "C" int d19c_sky_bind_clouds_80106300(d19c_Sky *, void *);
extern "C" int d19c_play_clip_80181640(d19c_Node *, const char *, int *, float, float, float, int);
extern "C" int d19c_check_control_8018179c(d19c_Node *, int, int);
extern d19c_SkyPair d19c_sky_clouds_803fce18[];
extern d19c_Vec3 d19c_sky_layer_position_8044b67c;
extern const char *d19c_cloud_loop_clip_804aaf9c;   // -> "Cloud_Loop"

extern "C" void d19c_sky_clouds_load_8010562c(d19c_Sky *self, const char *sky) {
    for (unsigned i = 0; i < 5; i++) {
        if (d19c_sky_clouds_803fce18[i].sky && strcmp(sky, d19c_sky_clouds_803fce18[i].sky) == 0) {
            d19c_Vec3 scale;
            d19c_Vec3 *p = &scale;
            scale.x = 1.0f;
            p->y = 1.0f;
            p->z = 1.0f;
            d19c_Vec3 position;
            const d19c_Vec3 *from = &d19c_sky_layer_position_8044b67c;
            position.x = from->x;
            position.y = from->y;
            position.z = from->z;
            {
                d19c_String_8020bb54 name(d19c_sky_clouds_803fce18[i].layer);
                d19c_handle_load_8015adf4(&name, &self->clouds, 255);
            }
            d19c_sky_bind_clouds_80106300(self, (void *)(d19c_owner_value_80182150(self->clouds)));
            self->clouds->vtable->set_scale(self->clouds, p, 0);
            self->clouds->vtable->set_position(self->clouds, &position, 0);
            d19c_Ref node = 0;
            node = d19c_as_node_80343584(self->clouds);
            int control;
            d19c_play_clip_80181640(node.value, d19c_cloud_loop_clip_804aaf9c, &control, 1.0f, 0.0f, 0.0f, 0);
            d19c_check_control_8018179c(node.value, control, 1);
            {
                d19c_String_8020bb54 name(d19c_sky_clouds_803fce18[i].layer);
                d19c_handle_load_8015adf4(&name, &self->clouds_mirror, 6);
            }
            scale.y = -scale.y;
            position.y = -position.y;
            self->clouds_mirror->vtable->set_scale(self->clouds_mirror, p, 0);
            self->clouds_mirror->vtable->set_position(self->clouds_mirror, &position, 0);
            node = d19c_as_node_80343584(self->clouds_mirror);
            d19c_play_clip_80181640(node.value, d19c_cloud_loop_clip_804aaf9c, &control, 1.0f, 0.0f, 0.0f, 0);
            d19c_check_control_8018179c(node.value, control, 1);
            return;
        }
    }
}
