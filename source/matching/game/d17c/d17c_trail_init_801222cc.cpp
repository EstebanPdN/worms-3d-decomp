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
extern "C" void d17c_string_init_8020c5c0(void *);
extern "C" unsigned short *d17c_string_header_80341884(void *);
// Shared engine string; constructor and release are out of line.
struct d17c_String_8020bb54 {
    char *text;
    d17c_String_8020bb54(const char *);
    d17c_String_8020bb54(const d17c_String_8020bb54 &o) {
        d17c_string_init_8020c5c0(this);
        text = o.text;
        ++*d17c_string_header_80341884(this);
    }
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
    void *unknown20[17];
    int (*set_visible)(d17c_Object *, int);   // +88
};
struct d17c_Object { d17c_ObjectVtable *vtable; };
struct d17c_Vec3 { float x, y, z; };
struct d17c_VecPair { d17c_Vec3 a, b; };
struct d17c_Trail {
    unsigned char unknown000[28];
    unsigned short kind;                 // +28
    unsigned char unknown030[26];
    d17c_Object *shape;                  // +56
    unsigned char segments[40];          // +60
    d17c_Object *mesh;                   // +100
    d17c_Object *trail;                  // +104
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
extern "C" int d17c_handle_load_8015adf4(const d17c_String_8020bb54 *, d17c_Object **, unsigned char);
extern "C" d17c_Object *d17c_as_mesh_8034357c(d17c_Object *);
extern "C" d17c_Object *d17c_mesh_shape_80174074(d17c_Object *);
extern "C" void *memset(void *, int, unsigned long);
extern const d17c_Vec3 d17c_vec3_zero_8045e788;
extern const char d17c_short_trail_8039b7d4[];   // "ShortTrail"
extern const char d17c_trail_8039b7e0[];         // "Trail"

static inline void d17c_load_trail(d17c_Object **slot, const d17c_String_8020bb54 *name) {
    d17c_handle_load_8015adf4(name, slot, 255);
}
static inline void d17c_load_mesh(d17c_Trail *self, d17c_String_8020bb54 &name, unsigned short kind, unsigned short count) {
    self->kind = kind;
    self->count = count;
    d17c_handle_load_8015adf4(&name, &self->mesh, 255);
    self->mesh->vtable->set_visible(self->mesh, 0);
    d17c_Object *shape = d17c_mesh_shape_80174074(d17c_as_mesh_8034357c(self->mesh));
    if (shape) shape->vtable->retain(shape);
    if (self->shape) self->shape->vtable->release(self->shape);
    self->shape = shape;
}

extern "C" void d17c_trail_init_801222cc(d17c_Trail *self, d17c_String_8020bb54 name, unsigned short kind, int owner, unsigned short count) {
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
