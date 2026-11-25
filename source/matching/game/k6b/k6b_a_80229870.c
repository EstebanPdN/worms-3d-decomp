struct K6bString { char *text; };
struct K6bTextTriple {
    void **vtable;
    char base[16];
    int field_20;
    struct K6bString first;
    int field_28;
    struct K6bString second;
    int field_36;
    struct K6bString third;
};
extern char *lbl_804b06a0[];
extern void *lbl_8041a0f0[];
extern void *w3d_tagged_construct_801ea0ec(void *object, int);
extern void w3d_string_base_init(struct K6bString *string);
extern unsigned short *w3d_string_header(struct K6bString *string);
struct K6bTextTriple *w3d_k6b_text_triple_construct_80229870(struct K6bTextTriple *self, void * arg_r4)
{
    int zero = 0;
    struct K6bString *first = &self->first;
    char **empty;
    struct K6bString *second;
    struct K6bString *third;
    w3d_tagged_construct_801ea0ec(self, arg_r4);
    empty = lbl_804b06a0;
    self->field_20 = zero;
    self->vtable = lbl_8041a0f0;
    second = &self->second;
    third = &self->third;
    w3d_string_base_init(first);
    self->first.text = *empty;
    ++*w3d_string_header(first);
    self->field_28 = zero;
    w3d_string_base_init(second);
    self->second.text = *empty;
    ++*w3d_string_header(second);
    self->field_36 = zero;
    w3d_string_base_init(third);
    self->third.text = *empty;
    ++*w3d_string_header(third);
    return self;
}
// desc: w3d_k6b_text_triple_construct_80229870: Appears to construct an object over 0x801ea0ec with vtable 0x8041a0f0, zeroed +20/+28/+36 and empty shared strings at +24, +32 and +40.
