struct K4bString { char *text; };
struct K4bNamed {
    void **vtable;
    char base[16];
    struct K4bString name;
    int value;
};
extern char *lbl_804b06a0[];
extern void *lbl_804163c0[];
extern void *w3d_tagged_construct_801ea0ec(void *object, int);
extern void w3d_string_base_init(struct K4bString *string);
extern unsigned short *w3d_string_header(struct K4bString *string);
struct K4bNamed *w3d_k4b_named_construct_801c90c0(struct K4bNamed *self, void * arg_r4)
{
    struct K4bString *name = &self->name;
    char **empty = lbl_804b06a0;
    w3d_tagged_construct_801ea0ec(self, arg_r4);
    self->vtable = lbl_804163c0;
    w3d_string_base_init(name);
    self->name.text = *empty;
    ++*w3d_string_header(name);
    self->value = 0;
    return self;
}
// desc: w3d_k4b_named_construct_801c90c0: Appears to construct a named object over 0x801ea0ec: vtable 0x804163c0, name string at +20 set to the shared empty string (reference count bumped), value cleared.
