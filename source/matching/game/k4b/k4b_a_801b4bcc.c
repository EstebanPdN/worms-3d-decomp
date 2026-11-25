struct K4bString { char *text; };
struct K4bColor { float r, g, b, a; };
struct K4bNamedColor {
    void **vtable;
    char base[16];
    struct K4bColor color;
    struct K4bString name;
    int enabled;
};
extern char *lbl_804b06a0[];
extern void *lbl_804145c8[];
extern struct K4bColor lbl_8045e63c[];
extern void *w3d_tagged_construct_801ea0ec(void *object, int);
extern void w3d_string_base_init(struct K4bString *string);
extern unsigned short *w3d_string_header(struct K4bString *string);
static inline void k4b_color_copy(struct K4bColor *d, const struct K4bColor *s)
{
    float r = s->r;
    float g = s->g;
    float b = s->b;
    d->r = r;
    d->g = g;
    d->b = b;
    d->a = s->a;
}
struct K4bNamedColor *w3d_k4b_named_color_construct_801b4bcc(struct K4bNamedColor *self, void * arg_r4)
{
    struct K4bString *name = &self->name;
    char **empty = lbl_804b06a0;
    w3d_tagged_construct_801ea0ec(self, arg_r4);
    self->vtable = lbl_804145c8;
    k4b_color_copy(&self->color, &lbl_8045e63c[0]);
    w3d_string_base_init(name);
    self->name.text = *empty;
    ++*w3d_string_header(name);
    self->enabled = 1;
    return self;
}
// desc: w3d_k4b_named_color_construct_801b4bcc: Appears to construct a named colour object over 0x801ea0ec: vtable 0x804145c8, colour copied from global 0x8045e63c, empty shared name string, enabled flag set.
