// d17c: 0x8012bd78 (364 bytes). Initialise the targeting cursor: read the
// "Camera.CurrentMode" setting into +32, load the "HUD.TargetingCursor" node
// into +28 (retained; the previous node is released), place it at the zero
// vector, scale it uniformly by the "TargetingCursor.Scale" setting and colour
// it opaque white.
// 0x8015adf4 and the settings reader 0x800fc270 forward virtual results, so
// they are declared with value returns, as is the node's position slot (+76):
// a value-returning callee makes GCC 2.95 load the call arguments last.
// The loaded reference is reached through a pointer local formed before the
// block-scoped name is built, as in the original register use.
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
struct d17c_Vec3 { float x, y, z; };
struct d17c_Rgba { char r, g, b, a; };
struct d17c_Node;
struct d17c_NodeVtable {
    void *unknown00[3];
    void (*retain)(d17c_Node *);         // +12
    void (*release)(d17c_Node *);        // +16
    void *unknown20[14];
    int (*set_position)(d17c_Node *, const d17c_Vec3 *, int);   // +76
    void *unknown80;
    void (*set_scale)(d17c_Node *, const d17c_Vec3 *, int);      // +84
};
struct d17c_Node { d17c_NodeVtable *vtable; };
struct d17c_Cursor {
    unsigned char unknown00[28];
    d17c_Node *node;                     // +28
    int mode;                            // +32
};
extern "C" void * d17c_read_int_800fc1b0(d17c_Key *, int *);
extern "C" d17c_Node *d17c_as_node_8034357c(d17c_Object *);
extern "C" int d17c_node_set_colour_80173df0(d17c_Node *, const d17c_Rgba *);
extern const d17c_Vec3 d17c_vec3_zero_8045e788[];
extern "C" int d17c_handle_load_8015adf4(const d17c_String_8020bb54 *, d17c_Object **, unsigned char);
extern "C" int d17c_read_float_800fc270(d17c_Key *, float *);
extern const char d17c_camera_mode_8039d388[];       // "Camera.CurrentMode"
extern const char d17c_cursor_mesh_8039d39c[];       // "HUD.TargetingCursor"
extern const char d17c_cursor_scale_8039d3b0[];      // "TargetingCursor.Scale"

static inline void d17c_load(const d17c_String_8020bb54 &name, d17c_Object **out) {
    d17c_handle_load_8015adf4(&name, out, 255);
}
extern "C" void d17c_targeting_cursor_init_8012bd78(d17c_Cursor *self) {
    d17c_Key mode_key;
    mode_key.text = d17c_camera_mode_8039d388;
    d17c_read_int_800fc1b0(&mode_key, &self->mode);
    d17c_Ref loaded;
    loaded.value = 0;
    d17c_Object **out = &loaded.value;
    {
        d17c_String_8020bb54 name(d17c_cursor_mesh_8039d39c);
        d17c_load(name, out);
    }
    d17c_Node *node = d17c_as_node_8034357c(loaded.value);
    if (node) node->vtable->retain(node);
    if (self->node) self->node->vtable->release(self->node);
    self->node = node;
    node->vtable->set_position(node, d17c_vec3_zero_8045e788, 0);
    d17c_Key scale_key;
    scale_key.text = d17c_cursor_scale_8039d3b0;
    float scale;
    d17c_read_float_800fc270(&scale_key, &scale);
    d17c_Vec3 v;
    v.x = scale;
    v.y = scale;
    v.z = scale;
    self->node->vtable->set_scale(self->node, &v, 1);
    d17c_Rgba colour;
    colour.r = -1;
    d17c_Rgba *p = &colour;
    p->g = -1;
    p->b = -1;
    p->a = -1;
    d17c_node_set_colour_80173df0(self->node, p);
}
