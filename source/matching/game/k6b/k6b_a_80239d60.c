struct K6bString { char *text; };
struct K6bNamedRange {
    void **vtable;
    char base[20];
    int first;
    int second;
    struct K6bString name;
    int value;
};
extern char *lbl_804b06a0[];
extern void *lbl_8041af40[];
extern int w3d_auto_80238d88(struct K6bNamedRange *self, void *);
extern void w3d_string_base_init(struct K6bString *string);
extern unsigned short *w3d_string_header(struct K6bString *string);
struct K6bNamedRange *w3d_k6b_named_range_construct_80239d60(struct K6bNamedRange *self, void * arg_r4)
{
    int zero = 0;
    struct K6bString *name = &self->name;
    w3d_auto_80238d88(self, arg_r4);
    self->vtable = lbl_8041af40;
    self->first = zero;
    self->second = zero;
    w3d_string_base_init(name);
    self->name.text = lbl_804b06a0[0];
    ++*w3d_string_header(name);
    self->value = zero;
    return self;
}
// desc: w3d_k6b_named_range_construct_80239d60: Appears to construct an object over base 0x80238d88 with vtable 0x8041af40, zeroed +24 and +28, an empty shared string at +32 and 0 at +36.
