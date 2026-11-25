#include "w3d_ptr.h"
#line 1 "s8hand_800b1394.cpp"
struct s8_Interface { Ptr32<Ptr32<void>> vtable; };
struct s8_ServiceOwner { char pad0[4]; Ptr32<s8_Interface> service; };
extern char lbl_8041b598[];
extern int lbl_804aaccc;
extern "C" Ptr32<s8_Interface> fn_8020b680(Ptr32<void>);
extern "C" void s8_acquire_service_800b1394(Ptr32<s8_ServiceOwner> self) {
    Ptr32<s8_Interface> service=fn_8020b680(lbl_8041b598);
    if(service) ((Ptr32<int (Ptr32<s8_Interface>)>)service->vtable[3])(service);
    Ptr32<s8_Interface> old=self->service;
    if(old) ((Ptr32<int (Ptr32<s8_Interface>)>)old->vtable[4])(old);
    self->service=service;
    ++lbl_804aaccc;
}


