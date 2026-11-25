#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2b_a_80159fec.c"
extern Ptr32<void> w3d_global_804aa8c8;
extern Ptr32<void> w3d_global_804b1924;
extern int w3d_call_80033208(Ptr32<void> obj, Ptr32<void> arg);
Ptr32<void> w3d_k2b_call_twice_80159fec(Ptr32<void> unused, Ptr32<void> arg)
{
    Ptr32<void> obj = w3d_global_804aa8c8;
    if (obj != 0) {
        w3d_call_80033208(obj, arg);
        return w3d::G(w3d_call_80033208(obj, arg));
    }
    return w3d_global_804b1924;
}
// desc: Appears to call a global object's handler twice with an argument and return the second result, else a fallback global.

}
