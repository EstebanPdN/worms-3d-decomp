struct K5bString { char *text; };
struct K5bColor { float r, g, b, a; };
struct K5bVec3 { float x, y, z; };
struct K5bNamedColor {
    void **vtable;
    char base[16];
    struct K5bColor color;
    struct K5bString name;
    int enabled;
};
struct K5bLabelledFrame {
    struct K5bNamedColor named;
    struct K5bVec3 corners[4];
    struct K5bString label;
    struct K5bString tooltip;
};
extern char *lbl_804b06a0[];
extern void *lbl_8041b7f8[];
extern struct K5bNamedColor *w3d_k4b_named_color_construct_801b4bcc(struct K5bNamedColor *self);
extern void w3d_string_base_init(struct K5bString *string);
extern unsigned short *w3d_string_header(struct K5bString *string);
static inline void k5b_vec3_set(struct K5bVec3 *v, float x, float y, float z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}
struct K5bLabelledFrame *w3d_k5b_labelled_frame_construct_8024dac8(struct K5bLabelledFrame *self)
{
    struct K5bString *tooltip = &self->tooltip;
    struct K5bString *label = &self->label;
    char **empty = lbl_804b06a0;
    struct K5bVec3 *fourth = &self->corners[3];
    w3d_k4b_named_color_construct_801b4bcc(&self->named);
    self->named.vtable = lbl_8041b7f8;
    k5b_vec3_set(&self->corners[0], 0.0f, 0.0f, 0.0f);
    k5b_vec3_set(&self->corners[1], 0.0f, 0.0f, 0.0f);
    k5b_vec3_set(&self->corners[2], 0.0f, 0.0f, 0.0f);
    k5b_vec3_set(fourth, 0.0f, 0.0f, 0.0f);
    w3d_string_base_init(label);
    self->label.text = *empty;
    ++*w3d_string_header(label);
    w3d_string_base_init(tooltip);
    self->tooltip.text = *empty;
    ++*w3d_string_header(tooltip);
    return self;
}
// desc: w3d_k5b_labelled_frame_construct_8024dac8: Appears to construct a derived named colour object over 0x801b4bcc: vtable 0x8041b7f8, four zero vectors and two empty shared strings at +92 and +96.
