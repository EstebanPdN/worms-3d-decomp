#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k7b_a_8016263c.c"
/* Static initializer: register a type descriptor and clear two file-scope pointer vectors. */
struct K7bVector { Ptr32<void> begin; Ptr32<void> end; Ptr32<void> capacity; };
extern char lbl_803618c0[];
extern char lbl_803e8878[];
extern char lbl_803618f0[];
extern Ptr32<void> fn_8016149c(void);
extern Ptr32<void> w3d_auto_801629f8(Ptr32<void> type, Ptr32<void> name, Ptr32<void> base, Ptr32<void (void)> factory, int kind, int flags);
extern struct K7bVector lbl_80455244[];
extern struct K7bVector lbl_80455250[];
void w3d_k7b_static_init_8016263c(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        w3d_auto_801629f8(lbl_803618c0, lbl_803e8878, lbl_803618f0, fn_8016149c, 10, 0);
        lbl_80455244[0].capacity = 0;
        lbl_80455244[0].end = 0;
        lbl_80455244[0].begin = 0;
        lbl_80455250[0].capacity = 0;
        lbl_80455250[0].end = 0;
        lbl_80455250[0].begin = 0;
    }
}

}
