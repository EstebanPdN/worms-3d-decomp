#include "w3d_ptr.h"
#line 1 "s8family_800fc43c.cpp"
struct s8_Interface { Ptr32<Ptr32<void (void)>> vtable; };
struct s8_Handle {
    Ptr32<s8_Interface> p;
    int unused;
    s8_Handle() : p(0) {}
    ~s8_Handle() { if(p) ((Ptr32<void (Ptr32<s8_Interface>)>)p->vtable[4])(p); }
};
struct s8_Service { char pad0[100]; Ptr32<s8_Interface> properties; };
extern Ptr32<s8_Service> lbl_804b1788;
extern "C" Ptr32<void> fn_80342a78(Ptr32<s8_Interface>);
extern "C" int fn_80178d28(Ptr32<void>,Ptr32<int>);
extern "C" int s8_property_write_800fc43c(Ptr32<void> name,int value) {
    s8_Handle property;
    Ptr32<s8_Interface> service=lbl_804b1788->properties;
    int status=((Ptr32<int (Ptr32<s8_Interface>, Ptr32<void>, Ptr32<s8_Handle>)>)service->vtable[31])(service,name,&property);
    if(status>=0) fn_80178d28(fn_80342a78(property.p),&value);
    return status;
}


