#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k8b_pool_size_8017e030.c"
extern unsigned short w3d_auto_80170b10(void);
extern unsigned short w3d_auto_8017f524(void);
extern unsigned short w3d_auto_80174520(void);
extern unsigned short w3d_auto_8018774c(void);
extern unsigned short w3d_pset_pool_size(void);
extern unsigned short w3d_auto_8018a7e4(void);
extern unsigned short w3d_null_pool_size(void);

int w3d_k8b_pool_size_8017e030(int unused, int kind)
{
    switch (kind) {
    case 0: return w3d_auto_80170b10();
    case 1: return w3d_auto_8017f524();
    case 2: return w3d_auto_80174520();
    case 3: return w3d_auto_8018774c();
    case 4: return w3d_pset_pool_size();
    case 5: return w3d_auto_8018a7e4();
    case 6: return w3d_null_pool_size();
    }
    return 0;
}

}
