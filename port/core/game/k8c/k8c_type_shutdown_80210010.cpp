#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k8c_type_shutdown_80210010.c"
struct K8cHeld { Ptr32<struct K8cHeldVtable> vtable; };
struct K8cHeldVtable { Ptr32<void> slots[4]; Ptr32<void (Ptr32<struct K8cHeld>)> release; };
struct K8cTypeNode;
extern Ptr32<struct K8cTypeNode> w3d_sdata_804b1904;
extern Ptr32<struct K8cTypeNode> w3d_sdata_804b1908;
extern Ptr32<struct K8cHeld> w3d_sdata_804aba54;
extern void fn_8020fe64(Ptr32<struct K8cTypeNode> node);
extern Ptr32<void> fn_80210610(void);
extern void fn_80210660(Ptr32<void>);
int w3d_k8c_type_shutdown_80210010(void)
{
    while (w3d_sdata_804b1904)
        fn_8020fe64(w3d_sdata_804b1904);
    while (w3d_sdata_804b1908)
        fn_8020fe64(w3d_sdata_804b1908);fn_80210660((Ptr32<void>)fn_80210610());
    if (w3d_sdata_804aba54) {
        w3d_sdata_804aba54->vtable->release(w3d_sdata_804aba54);
        w3d_sdata_804aba54 = 0;
    }
    return 0;
}

}
