#include "w3d_ptr.h"
#line 1 "k5b_a_801eef90.cpp"
extern "C" void w3d_string_release_header(Ptr32<unsigned short> header);
extern Ptr32<char> lbl_804b06a0[];
static inline Ptr32<unsigned short> k5b_text_header(Ptr32<char> text)
{
    return (Ptr32<unsigned short>)(text - 6);
}
struct K5bText {
    Ptr32<char> text;
    void assign_empty()
    {
        Ptr32<unsigned short> mine;
        ++*k5b_text_header(*lbl_804b06a0);
        mine = k5b_text_header(text);
        if (--*mine == 0)
            w3d_string_release_header(mine);
        text = *lbl_804b06a0;
    }
};
struct K5bTextArray {
    Ptr32<Ptr32<void>> vtable;
    char pad4[20];
    unsigned int count;
    char pad28[4];
    K5bText items[1];
};
extern "C" Ptr32<K5bTextArray> w3d_k5b_text_array_set_count_801eef90(Ptr32<K5bTextArray> self, unsigned int count)
{
    unsigned int old = self->count;
    Ptr32<K5bText> items = self->items;
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


