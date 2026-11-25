struct K6bString { char *text; };
struct K6bTaggedLabel {
    void **vtable;
    char base[16];
    int kind;
    struct K6bString name;
};
extern char *lbl_804b06a0[];
extern void *lbl_8041b758[];
extern void *w3d_tagged_construct_801ea0ec(void *object, int);
extern void w3d_string_base_init(struct K6bString *string);
extern unsigned short *w3d_string_header(struct K6bString *string);
struct K6bTaggedLabel *w3d_k6b_tagged_label_construct_8024f174(struct K6bTaggedLabel *self, void * arg_r4)
{
    struct K6bString *name = &self->name;
    char **empty = lbl_804b06a0;
    w3d_tagged_construct_801ea0ec(self, arg_r4);
    self->vtable = lbl_8041b758;
    self->kind = 23;
    w3d_string_base_init(name);
    self->name.text = *empty;
    ++*w3d_string_header(name);
    return self;
}
// desc: w3d_k6b_tagged_label_construct_8024f174: Appears to construct an object over 0x801ea0ec with vtable 0x8041b758, kind 23 at +20 and an empty shared string at +24.
