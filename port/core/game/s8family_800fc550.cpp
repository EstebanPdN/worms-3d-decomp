#include "w3d_ptr.h"
#line 1 "s8family_800fc550.cpp"
struct s8_Interface { Ptr32<Ptr32<void (void)>> vtable; };
struct s8_Handle {
    Ptr32<s8_Interface> p;
    int unused;
    s8_Handle() : p(0) {}
    ~s8_Handle() { if(p) ((Ptr32<void (Ptr32<s8_Interface>)>)p->vtable[4])(p); }
};
struct s8_Service { char pad0[100]; Ptr32<s8_Interface> properties; };
extern Ptr32<s8_Service> lbl_804b1788;
extern "C" Ptr32<void> fn_80343744(Ptr32<s8_Interface>);
extern "C" int fn_801790bc(Ptr32<void>,Ptr32<void>);
extern "C" int s8_property_read_800fc550(Ptr32<void> name,Ptr32<void> output) {
    s8_Handle property;
    Ptr32<s8_Interface> service=lbl_804b1788->properties;
    int status=((Ptr32<int (Ptr32<s8_Interface>, Ptr32<void>, Ptr32<s8_Handle>)>)service->vtable[31])(service,name,&property);
    if(status>=0) fn_801790bc(fn_80343744(property.p),output);
    return status;
}


