#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_dm_801eec04.c"
// desc: Appears to be a destructor body that releases every shared string of the counted array at offset 32, installs the base vtable and destroys the embedded node.
// desc: Appears to be a destructor body that releases every shared string of the counted array at offset 32, installs the base vtable and destroys the embedded node.
struct S21Object { Ptr32<void> vtable; char node[20]; int count; char pad[4]; Ptr32<char> strings[1]; };
extern char lbl_80417670[];
extern char lbl_80411ac0[];
extern void fn_8020bb2c(Ptr32<void>);
extern void fn_80210990(Ptr32<void>, int);
void w3d_s21_destroy_801eec04(Ptr32<struct S21Object> self)
{
    int count = self->count;
    Ptr32<Ptr32<char>> strings = self->strings;
    Ptr32<Ptr32<char>> text;
    int remaining;
    self->vtable = lbl_80417670;
    if (count > 0) {
        text = strings;
        remaining = count;
        do {
            Ptr32<unsigned short> header = (Ptr32<unsigned short>)(*text - 6);
            unsigned short left;
            text++;
            left = --*header;
            if (left == 0)
                fn_8020bb2c(header);
        } while (--remaining);
    }
    self->vtable = lbl_80411ac0;
    fn_80210990(self->node, 0);
}

}
