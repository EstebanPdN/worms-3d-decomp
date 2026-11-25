#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s9_enable_adjust.c"
extern void fn_8016c7d0(Ptr32<void>,Ptr32<void>,int);
int s9_adjust_enable_8016d428(int self,int value)
{
    fn_8016c7d0(self ? w3d::R((Ptr32<void>)w3d::G((self-4))):0,w3d::G(value),1);
    return 0;
}

}
