#include "w3d_ptr.h"
#line 1 "s11handle_802badf0.cpp"
/* Inferred named resource-handle construction. */
struct S11HandleObject;
struct S11HandleTable {
    Ptr32<void (void)> unknown[3];
    Ptr32<void (Ptr32<S11HandleObject>)> retain;
    Ptr32<void (Ptr32<S11HandleObject>)> release;
};
struct S11HandleObject { Ptr32<S11HandleTable> vtable; };
struct S11HandleString { int text; int reserved; };
struct S11HandleRef { Ptr32<S11HandleObject> value; int reserved; };
extern "C" {
int fn_8020BB54(Ptr32<S11HandleString>,Ptr32<const char>);
int fn_8015ADF4(Ptr32<S11HandleString>,Ptr32<S11HandleRef>,int);
Ptr32<S11HandleObject> fn_8034BF4C(Ptr32<S11HandleObject>);
void fn_8020C5C4(Ptr32<S11HandleString>);
int fn_80341588(Ptr32<S11HandleString>);
Ptr32<S11HandleRef> s11_named_handle_802badf0(Ptr32<S11HandleRef> self,Ptr32<const char> text,int flags) {
    struct {S11HandleString name;S11HandleRef found;} local;
    self->value=0;
    fn_8020BB54(&local.name,text);
    register Ptr32<S11HandleString> name=&local.name;
    local.found.value=0;
    fn_8015ADF4(name,&local.found,flags);
    Ptr32<S11HandleObject> next=fn_8034BF4C(local.found.value);
    if (next) next->vtable->retain(next);
    if (self->value) self->value->vtable->release(self->value);
    self->value=next;
    if (local.found.value) local.found.value->vtable->release(local.found.value);
    fn_8020C5C4(name);
    fn_80341588(name);
    return self;
}
}


