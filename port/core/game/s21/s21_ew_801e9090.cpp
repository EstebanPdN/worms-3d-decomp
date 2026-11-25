#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ew_801e9090.c"
// desc: Appears to change the 10-bit class field of an object and, when it differs, propagate the new class into the halfword at offset 6 of every linked node.
struct S21Bits { unsigned int rest:22; unsigned int klass:10; };
struct S21Node { char pad[6]; short klass; };
struct S21Object { char pad[32]; struct S21Bits bits; };
extern Ptr32<struct S21Node> fn_8020fe00(Ptr32<struct S21Object>);
extern Ptr32<struct S21Node> fn_8020fe18(Ptr32<struct S21Object>, Ptr32<struct S21Node>);
void w3d_s21_set_class_801e9090(Ptr32<struct S21Object> self, int klass)
{
    Ptr32<struct S21Node> node;
    if (klass == self->bits.klass)
        return;
    self->bits.klass = klass;
    node = fn_8020fe00(self);
    if (!node)
        return;
    do {
        node->klass = klass;
        node = fn_8020fe18(self, node);
    } while (node);
}

}
