#include "w3d_ptr.h"
#line 1 "d17c_trail_init_801222cc.cpp"
// d17c: 0x801222cc (692 bytes). Initialise a trail effect: store the
// even trail kind (+28) and point count (+120), load the named mesh (+100;
// the name is passed by value and destroyed here, as the callee of a by-value
// class argument), clear its flag through virtual slot +88, retain its shape
// (+56; the previous one is released), and load the trail resource (+104):
// "ShortTrail" for kind 2; otherwise "Trail", whose segment block (+60) is
// cleared and whose per-point ages, points and edge/normal pairs are reset to
// the zero vector. Both branches record the owner (+108), head 0 (+116) and
// style kind + 15 (+112).
// 0x8015adf4 forwards the resource manager's virtual load result, so it is
// declared with a status return. The trail name's address is handed to an
// inline loader, so it is kept in a register after construction.
extern "C" void d17c_string_init_8020c5c0(Ptr32<void>);
extern "C" Ptr32<unsigned short> d17c_string_header_80341884(Ptr32<void>);
// Shared engine string; constructor and release are out of line.
struct d17c_String_8020bb54 {
    Ptr32<char> text;
    template <class W3dU> d17c_String_8020bb54(Ptr32<W3dU> w3d_p) : d17c_String_8020bb54((const char *)w3d_p.get()) {}
 d17c_String_8020bb54(const char *);
    d17c_String_8020bb54(const d17c_String_8020bb54 &o) {
        d17c_string_init_8020c5c0(this);
        text = o.text;
        ++*d17c_string_header_80341884(this);
    }
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
    Ptr32<void> unknown20[17];
    Ptr32<int (Ptr32<d17c_Object>, int)> set_visible;   // +88
};
struct d17c_Object { Ptr32<d17c_ObjectVtable> vtable; };
struct d17c_Vec3 { float x, y, z; };
struct d17c_VecPair { d17c_Vec3 a, b; };
struct d17c_Trail {
    unsigned char unknown000[28];
    unsigned short kind;                 // +28
    unsigned char unknown030[26];
    Ptr32<d17c_Object> shape;                  // +56
    unsigned char segments[40];          // +60
    Ptr32<d17c_Object> mesh;                   // +100
    Ptr32<d17c_Object> trail;                  // +104
    int owner;                           // +108
    int style;                           // +112
    int head;                            // +116
    unsigned short count;                // +120
    unsigned char unknown122[6];
    d17c_Vec3 points[20];                // +128
    unsigned char unknown368[4];
    d17c_VecPair edges[20];              // +372
    d17c_VecPair normals[20];            // +852
    int ages[20];                        // +1332
};
extern "C" int d17c_handle_load_8015adf4(Ptr32<const d17c_String_8020bb54>, Ptr32<Ptr32<d17c_Object>>, unsigned char);
extern "C" Ptr32<d17c_Object> d17c_as_mesh_8034357c(Ptr32<d17c_Object>);
extern "C" Ptr32<d17c_Object> d17c_mesh_shape_80174074(Ptr32<d17c_Object>);
extern "C" Ptr32<void> memset(Ptr32<void>, int, unsigned int);
extern const d17c_Vec3 d17c_vec3_zero_8045e788;
extern const char d17c_short_trail_8039b7d4[];   // "ShortTrail"
extern const char d17c_trail_8039b7e0[];         // "Trail"

static inline void d17c_load_trail(Ptr32<Ptr32<d17c_Object>> slot, Ptr32<const d17c_String_8020bb54> name) {
    d17c_handle_load_8015adf4(name, slot, 255);
}
static inline void d17c_load_mesh(Ptr32<d17c_Trail> self, d17c_String_8020bb54 &name, unsigned short kind, unsigned short count) {
    self->kind = kind;
    self->count = count;
    d17c_handle_load_8015adf4(&name, &self->mesh, 255);
    self->mesh->vtable->set_visible(self->mesh, 0);
    Ptr32<d17c_Object> shape = d17c_mesh_shape_80174074(d17c_as_mesh_8034357c(self->mesh));
    if (shape) shape->vtable->retain(shape);
    if (self->shape) self->shape->vtable->release(self->shape);
    self->shape = shape;
}

extern "C" void d17c_trail_init_801222cc(Ptr32<d17c_Trail> self, d17c_String_8020bb54 name, unsigned short kind, int owner, unsigned short count) {
    kind &= ~1;
    if (kind == 2) {
        d17c_load_mesh(self, name, kind, count);
        {
            d17c_String_8020bb54 trail(d17c_short_trail_8039b7d4);
            d17c_load_trail(&self->trail, &trail);
        }
        self->owner = owner;
        self->head = 0;
        self->style = kind + 15;
    } else {
        d17c_load_mesh(self, name, kind, count);
        {
            d17c_String_8020bb54 trail(d17c_trail_8039b7e0);
            d17c_load_trail(&self->trail, &trail);
        }
        memset(self->segments, 0, 40);
        self->owner = owner;
        self->head = 0;
        self->style = kind + 15;
        for (unsigned short i = 0; i < count; i++) {
            self->ages[i] = 0;
            self->normals[i].a = d17c_vec3_zero_8045e788;
            self->normals[i].b = d17c_vec3_zero_8045e788;
            self->points[i] = d17c_vec3_zero_8045e788;
            self->edges[i].a = d17c_vec3_zero_8045e788;
            self->edges[i].b = d17c_vec3_zero_8045e788;
        }
    }
}


