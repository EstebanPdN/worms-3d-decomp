struct K6bString { char *text; };
struct K6bLabelRecord {
    void **vtable;
    char base[16];
    int field_20;
    int field_24;
    int field_28;
    int field_32;
    int field_36;
    struct K6bString title;
    struct K6bString caption;
    int field_48;
};
extern char *lbl_804b06a0[];
extern void *lbl_8041a7c0[];
extern void *w3d_tagged_construct_801ea0ec(void *object, int);
extern void w3d_string_base_init(struct K6bString *string);
extern unsigned short *w3d_string_header(struct K6bString *string);
struct K6bLabelRecord *w3d_k6b_label_record_construct_80236e54(struct K6bLabelRecord *self, void * arg_r4)
{
    int zero = 0;
    struct K6bString *title = &self->title;
    char **empty;
    struct K6bString *caption;
    w3d_tagged_construct_801ea0ec(self, arg_r4);
    empty = lbl_804b06a0;
    self->field_20 = zero;
    self->field_24 = zero;
    self->field_28 = zero;
    self->field_32 = zero;
    caption = &self->caption;
    self->field_36 = zero;
    self->vtable = lbl_8041a7c0;
    w3d_string_base_init(title);
    self->title.text = *empty;
    ++*w3d_string_header(title);
    w3d_string_base_init(caption);
    self->caption.text = *empty;
    ++*w3d_string_header(caption);
    self->field_48 = zero;
    return self;
}
// desc: w3d_k6b_label_record_construct_80236e54: Appears to construct an object over 0x801ea0ec with vtable 0x8041a7c0, zeroed +20..+36 and +48, and empty shared strings at +40 and +44.
