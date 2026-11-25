struct K6bString { char *text; };
struct K6bNamedEntry {
    void **vtable;
    char base[20];
    struct K6bString name;
    int value;
};
extern char *lbl_804b06a0[];
extern void *lbl_8041b080[];
extern int lbl_804af594;
extern int w3d_auto_80238d88(struct K6bNamedEntry *self, void *);
extern void w3d_string_base_init(struct K6bString *string);
extern unsigned short *w3d_string_header(struct K6bString *string);
struct K6bNamedEntry *w3d_k6b_named_entry_construct_80238f14(struct K6bNamedEntry *self, void * arg_r4)
{
    struct K6bString *name = &self->name;
    char **empty = lbl_804b06a0;
    w3d_auto_80238d88(self, arg_r4);
    self->vtable = lbl_8041b080;
    w3d_string_base_init(name);
    self->name.text = *empty;
    {
        unsigned short *header = w3d_string_header(name);
        int value = lbl_804af594;
        ++*header;
        self->value = value;
    }
    return self;
}
// desc: w3d_k6b_named_entry_construct_80238f14: Appears to construct an object over base 0x80238d88 with vtable 0x8041b080, an empty shared string at +24 and the global 0x804af594 copied to +28.
