#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_fz_802009c4.c"
// desc: Appears to be a static initialization entry that fills the ValueType descriptor with its name, two callbacks and link, clears a global pointer and registers it in an ordered list when called with the final priority.
struct S21Descriptor { int first; Ptr32<const char> name; Ptr32<void> create; Ptr32<void> destroy; int count; Ptr32<void> link; };
extern struct S21Descriptor lbl_8045eddc;
extern const char lbl_803b2a7c[];
extern char lbl_80200278[];
extern char lbl_802002fc[];
extern char lbl_80463308[];
extern Ptr32<void> lbl_804b063c;
extern void fn_80200af8(Ptr32<void>);
void w3d_s21_static_register_value_type_802009c4(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        lbl_8045eddc.name = lbl_803b2a7c;
        lbl_8045eddc.create = lbl_80200278;
        lbl_8045eddc.destroy = lbl_802002fc;
        lbl_804b063c = 0;
        lbl_8045eddc.count = 0;
        lbl_8045eddc.link = lbl_80463308;
        fn_80200af8(&lbl_8045eddc);
    }
}

}
