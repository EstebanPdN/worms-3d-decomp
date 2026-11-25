struct K4bString { char *text; };
struct K4bColor { float r, g, b, a; };
struct K4bVec3 { float x, y, z; };
struct K4bMtx44 { float m[16]; };
struct K4bNamedColor {
    void **vtable;
    char base[16];
    struct K4bColor color;
    struct K4bString name;
    int enabled;
};
struct K4bPlacement {
    struct K4bNamedColor named;
    struct K4bMtx44 transform;
    struct K4bVec3 position;
    struct K4bVec3 scale;
    struct K4bVec3 rotation;
    int parent;
    int visible;
    int index;
};
extern void *lbl_80414f60[];
extern struct K4bMtx44 lbl_8045e708[];
extern struct K4bNamedColor *w3d_k4b_named_color_construct_801b4bcc(struct K4bNamedColor *self, void *);
static inline void k4b_vec3_set(struct K4bVec3 *v, float x, float y, float z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}
struct K4bPlacement *w3d_k4b_placement_construct_801bf6a4(struct K4bPlacement *self, void * arg_r4)
{
    w3d_k4b_named_color_construct_801b4bcc(&self->named, arg_r4);
    self->named.vtable = lbl_80414f60;
    self->transform = lbl_8045e708[0];
    k4b_vec3_set(&self->position, 0.0f, 0.0f, 0.0f);
    k4b_vec3_set(&self->scale, 1.0f, 1.0f, 1.0f);
    k4b_vec3_set(&self->rotation, 0.0f, 0.0f, 0.0f);
    self->parent = 0;
    self->visible = 1;
    self->index = -1;
    return self;
}
// desc: w3d_k4b_placement_construct_801bf6a4: Appears to construct a placement over 0x801b4bcc: vtable 0x80414f60, matrix copied from global 0x8045e708, zero position and rotation, unit scale, visible, index -1.
