#include "w3d_ptr.h"
#line 1 "d17c_targeting_cursor_init_8012bd78.cpp"
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
    Ptr32<char> text;
    template <class W3dU> d17c_String_8020bb54(Ptr32<W3dU> w3d_p) : d17c_String_8020bb54((const char *)w3d_p.get()) {}
 d17c_String_8020bb54(const char *);
    ~d17c_String_8020bb54();
};
extern "C" void d17c_string_finish_8020c5c4(Ptr32<d17c_String_8020bb54>);
extern "C" void d17c_string_release_80341588(Ptr32<d17c_String_8020bb54>);
inline d17c_String_8020bb54::~d17c_String_8020bb54() {
    d17c_string_finish_8020c5c4(this);
    d17c_string_release_80341588(this);
}
struct d17c_Object;
struct d17c_ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<d17c_Object>)> retain;       // +12
    Ptr32<void (Ptr32<d17c_Object>)> release;      // +16
};
struct d17c_Object { Ptr32<d17c_ObjectVtable> vtable; };
// Retaining reference (one pointer); released when it goes out of scope.
struct d17c_Ref {
    Ptr32<d17c_Object> value;
    ~d17c_Ref() { if (value) value->vtable->release(value); }
};
// Settings key: a pointer to the setting's name.
struct d17c_Key { Ptr32<const char> text; };
struct d17c_Vec3 { float x, y, z; };
struct d17c_Rgba { char r, g, b, a; };
struct d17c_Node;
struct d17c_NodeVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<d17c_Node>)> retain;         // +12
    Ptr32<void (Ptr32<d17c_Node>)> release;        // +16
    Ptr32<void> unknown20[14];
    Ptr32<int (Ptr32<d17c_Node>, Ptr32<const d17c_Vec3>, int)> set_position;   // +76
    Ptr32<void> unknown80;
    Ptr32<void (Ptr32<d17c_Node>, Ptr32<const d17c_Vec3>, int)> set_scale;      // +84
};
struct d17c_Node { Ptr32<d17c_NodeVtable> vtable; };
struct d17c_Cursor {
    unsigned char unknown00[28];
    Ptr32<d17c_Node> node;                     // +28
    int mode;                            // +32
};
extern "C" Ptr32<void> d17c_read_int_800fc1b0(Ptr32<d17c_Key>, Ptr32<int>);
extern "C" Ptr32<d17c_Node> d17c_as_node_8034357c(Ptr32<d17c_Object>);
extern "C" int d17c_node_set_colour_80173df0(Ptr32<d17c_Node>, Ptr32<const d17c_Rgba>);
extern const d17c_Vec3 d17c_vec3_zero_8045e788[];
extern "C" int d17c_handle_load_8015adf4(Ptr32<const d17c_String_8020bb54>, Ptr32<Ptr32<d17c_Object>>, unsigned char);
extern "C" int d17c_read_float_800fc270(Ptr32<d17c_Key>, Ptr32<float>);
extern const char d17c_camera_mode_8039d388[];       // "Camera.CurrentMode"
extern const char d17c_cursor_mesh_8039d39c[];       // "HUD.TargetingCursor"
extern const char d17c_cursor_scale_8039d3b0[];      // "TargetingCursor.Scale"

static inline void d17c_load(const d17c_String_8020bb54 &name, Ptr32<Ptr32<d17c_Object>> out) {
    d17c_handle_load_8015adf4(&name, out, 255);
}
extern "C" void d17c_targeting_cursor_init_8012bd78(Ptr32<d17c_Cursor> self) {
    d17c_Key mode_key;
    mode_key.text = d17c_camera_mode_8039d388;
    d17c_read_int_800fc1b0(&mode_key, &self->mode);
    d17c_Ref loaded;
    loaded.value = 0;
    Ptr32<Ptr32<d17c_Object>> out = &loaded.value;
    {
        d17c_String_8020bb54 name(d17c_cursor_mesh_8039d39c);
        d17c_load(name, out);
    }
    Ptr32<d17c_Node> node = d17c_as_node_8034357c(loaded.value);
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
    Ptr32<d17c_Rgba> p = &colour;
    p->g = -1;
    p->b = -1;
    p->a = -1;
    d17c_node_set_colour_80173df0(self->node, p);
}


