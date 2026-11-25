#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k6b_a_8020ed40.c"
struct K6bService { Ptr32<Ptr32<void>> vtable; };
extern Ptr32<struct K6bService> w3d_auto_8020b648(void);
extern char lbl_80419500[];
int w3d_k6b_service_copy_setting_8020ed40(void)
{
    Ptr32<char> key = lbl_80419500;
    Ptr32<struct K6bService> service = w3d_auto_8020b648();
    int value = ((Ptr32<int (Ptr32<struct K6bService>, Ptr32<char>)>)service->vtable[23])(service, key);
    service = w3d_auto_8020b648();
    ((Ptr32<void (Ptr32<struct K6bService>, Ptr32<char>, int)>)service->vtable[25])(service, key, value);
    return 0;
}
// desc: w3d_k6b_service_copy_setting_8020ed40: Appears to read the setting named by 0x80419500 through virtual slot 23 of the 0x8020b648 service and write it back through slot 25.

}
