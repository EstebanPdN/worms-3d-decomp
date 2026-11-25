#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_gg_80209c28.c"
// desc: Appears to be a static initialization entry that fills the XMemoryManager descriptor with its name, callback, count and link and registers it in an ordered list when called with the final priority.
struct S21Descriptor { int first; Ptr32<const char> name; Ptr32<void> callback; int zero; int count; Ptr32<void> link; };
extern struct S21Descriptor lbl_804632d0;
extern const char lbl_803b2fbc[];
extern char lbl_80209ac0[];
extern char lbl_80463308[];
extern void fn_80200af8(Ptr32<void>);
void w3d_s21_static_register_memory_manager_80209c28(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        int zero;
        int count = 20;
        zero = 0;
        lbl_804632d0.name = lbl_803b2fbc;
        lbl_804632d0.callback = lbl_80209ac0;
        lbl_804632d0.zero = zero;
        lbl_804632d0.count = count;
        lbl_804632d0.link = lbl_80463308;
        fn_80200af8(&lbl_804632d0);
    }
}

}
