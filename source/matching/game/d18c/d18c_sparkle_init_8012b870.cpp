// d18c: 0x8012b870 (408 bytes). Initialise a water sparkle effect: load the
// "water sparkle" mesh node into +28, read the water level setting into +72,
// make the node visible, allocate 10 mesh elements, place the node at the
// origin rotated a quarter turn about z, then give every element flag 0, a
// 30 x 30 size, opaque alpha and a start time spread up to 1023 ticks before
// the current engine tick (+32..+68).
// The translation unit was built with -mps-float: the function keeps a float
// literal in f31 across calls, and the flag reserves the 8 bytes below the
// register save area seen in the original frame.
// 0x8015adf4 forwards the resource manager's virtual load result, so it is
// declared with a status return. The name's address is handed to an inline
// loader, so it stays in a register after construction.
// Shared engine string; constructor and release are out of line.
struct d18c_String_8020bb54 {
 d18c_String_8020bb54(const d18c_String_8020bb54 &);
    char *text;
    d18c_String_8020bb54(const char *);
    ~d18c_String_8020bb54();
};
extern "C" void d18c_string_finish_8020c5c4(d18c_String_8020bb54 *);
extern "C" void d18c_string_release_80341588(d18c_String_8020bb54 *);
inline d18c_String_8020bb54::~d18c_String_8020bb54() {
    d18c_string_finish_8020c5c4(this);
    d18c_string_release_80341588(this);
}
// Settings key: the text pointer is its first field.
struct d18c_Key { const char *text; };
struct d18c_Vec3 { float x, y, z; };
struct d18c_Uv { float u, v; };
struct d18c_Rgba { unsigned char r, g, b, a; };
struct d18c_Node;
struct d18c_NodeVtable {
    void *unknown00[19];
    int (*set_position)(d18c_Node *, const d18c_Vec3 *, int);   // +76
    int (*set_rotation)(d18c_Node *, const d18c_Vec3 *, int);   // +80
    void *unknown84;
    int (*set_visible)(d18c_Node *, int);                      // +88
};
struct d18c_Node { d18c_NodeVtable *vtable; };
struct d18c_Context { unsigned char unknown00[52]; int tick; };
struct d18c_Sparkle {
    unsigned char unknown00[28];
    d18c_Node *node;                     // +28
    int times[10];                       // +32
    int level;                           // +72
};
extern "C" int d18c_read_int_800fc1b0(d18c_Key *, int *);
extern "C" int d18c_mesh_alloc_8018920c(d18c_Node *, int);
extern "C" unsigned char *d18c_mesh_flags_80189828(d18c_Node *);
extern "C" d18c_Uv *d18c_mesh_uvs_8018963c(d18c_Node *);
extern "C" d18c_Rgba *d18c_mesh_colours_80189760(d18c_Node *);
extern "C" d18c_Context *d18c_engine_context_80165254(void);
extern "C" unsigned d18c_random_8015ff5c(void *);
extern "C" int d18c_handle_load_node_8015adf4(const d18c_String_8020bb54 *, d18c_Node **, unsigned char);
extern const char d18c_water_sparkle_8039d338[];
extern const char d18c_water_level_8039d348[];

static inline void d18c_set(d18c_Vec3 *v, float x, float y, float z) {
    v->x = x;
    v->y = y;
    v->z = z;
}
extern "C" void d18c_sparkle_init_8012b870(d18c_Sparkle *self) {
    d18c_Vec3 v;
    d18c_Vec3 *p = &v;
    d18c_set(p, 0.0f, 0.0f, 0.0f);
    {
        d18c_String_8020bb54 name(d18c_water_sparkle_8039d338);
        d18c_handle_load_node_8015adf4(&name, &self->node, 255);
    }
    d18c_Node *node = self->node;
    d18c_Key key;
    key.text = d18c_water_level_8039d348;
    d18c_read_int_800fc1b0(&key, &self->level);
    node->vtable->set_visible(node, 1);
    d18c_mesh_alloc_8018920c(node, 10);
    d18c_set(p, 0.0f, 0.0f, 0.0f);
    self->node->vtable->set_position(self->node, p, 0);
    d18c_set(p, 0.0f, 0.0f, 1.5707964f);
    self->node->vtable->set_rotation(self->node, p, 0);
    int tick = d18c_engine_context_80165254()->tick;
    for (unsigned i = 0; i < 10; i++) {
        d18c_mesh_flags_80189828(node)[i] = 0;
        d18c_Uv *uv = (d18c_Uv *)((char *)d18c_mesh_uvs_8018963c(node) + (i << 3));
        uv->u = 30.0f;
        uv->v = 30.0f;
        d18c_mesh_colours_80189760(node)[i].a = 255;
        self->times[i] = tick - (d18c_random_8015ff5c(self) & 1023);
    }
}
