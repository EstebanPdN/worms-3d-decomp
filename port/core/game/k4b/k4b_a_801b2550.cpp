#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_801b2550.c"
struct K4bString { Ptr32<char> text; };
struct K4bTextWriter {
    char pad0[44];
    unsigned int indent;
    char pad30[8];
    int column;
    struct K4bString line;
};
extern Ptr32<void> memset(Ptr32<void> dst, int value, unsigned int size);
extern Ptr32<void> w3d_string_append(Ptr32<struct K4bString> string, Ptr32<const char> text);
void w3d_k4b_writer_append_indent_801b2550(Ptr32<struct K4bTextWriter> self)
{
    char spaces[64];
    memset(spaces, ' ', self->indent);
    spaces[self->indent] = 0;
    self->column += self->indent;
    w3d_string_append(&self->line, spaces);
}
// desc: w3d_k4b_writer_append_indent_801b2550: Appears to append the current indentation as spaces to a text writer line and advance its column by the indent width.

}
