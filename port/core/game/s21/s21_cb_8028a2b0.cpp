#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_cb_8028a2b0.c"
// desc: Appears to split a text at its first newline: it terminates the first line, copies the remainder to the destination and returns one, or returns zero without a newline.
extern Ptr32<char> fn_802ef2fc(Ptr32<char>, Ptr32<const char>);
int w3d_s21_split_line_8028a2b0(int unused, Ptr32<char> dest, Ptr32<char> text)
{
    int found = 0;
    while (*text) {
        if (*text == 10) {
            found = 1;
            break;
        }
        text++;
    }
    if (found) {
        *text = 0;
        fn_802ef2fc(dest, text + 1);
        return 1;
    }
    return 0;
}

}
