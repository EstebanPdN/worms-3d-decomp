extern "C" void w3d_string_release_header(unsigned short *header);
extern char *lbl_804b06a0[];
static inline unsigned short *k5b_text_header(char *text)
{
    return (unsigned short *)(text - 6);
}
struct K5bText {
    char *text;
    void assign_empty()
    {
        unsigned short *mine;
        ++*k5b_text_header(*lbl_804b06a0);
        mine = k5b_text_header(text);
        if (--*mine == 0)
            w3d_string_release_header(mine);
        text = *lbl_804b06a0;
    }
};
struct K5bTextArray {
    void **vtable;
    char pad4[20];
    unsigned int count;
    char pad28[4];
    K5bText items[1];
};
extern "C" K5bTextArray *w3d_k5b_text_array_set_count_801eef90(K5bTextArray *self, unsigned int count)
{
    unsigned int old = self->count;
    K5bText *items = self->items;
    if (old < count) {
        unsigned int i;
        for (i = old; i < count; i++)
            ;
    } else {
        unsigned int i;
        for (i = count; i < old; i++)
            items[i].assign_empty();
    }
    self->count = count;
    return self;
}
// desc: w3d_k5b_text_array_set_count_801eef90: Appears to set the element count of a shared-text array, resetting entries beyond the new count to the shared empty text.
