#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_string_b.c"
/* Methods that take over a shared string argument. */
typedef struct W3dStringHeader { unsigned short references; } W3dStringHeader;
typedef struct W3dString { Ptr32<char> text; } W3dString;
extern void fn_800f6afc(Ptr32<char>, Ptr32<W3dString>, int);
extern void fn_8020bb2c(Ptr32<W3dStringHeader>);
extern void fn_8020c5c4(Ptr32<W3dString>);
extern int fn_80341588(Ptr32<W3dString>);

int w3d_s20_set_title_800f2f94(Ptr32<char> self, Ptr32<W3dString> title, int value) {
    fn_800f6afc(self, title, value);
    ++((Ptr32<W3dStringHeader>)(title->text - 6))->references;
    {
        Ptr32<W3dStringHeader> old = (Ptr32<W3dStringHeader>)(*(Ptr32<Ptr32<char>>)(self + 892) - 6);
        if (--old->references == 0)
            fn_8020bb2c(old);
    }
    {
        Ptr32<char> text = title->text;
        *(Ptr32<int>)(self + 3196) = value;
        *(Ptr32<Ptr32<char>>)(self + 892) = text;
        *(Ptr32<int>)(self + 3168) = 1;
        *(Ptr32<int>)(self + 3172) = 5;
    }
    fn_8020c5c4(title);
    return fn_80341588(title);
}

}
