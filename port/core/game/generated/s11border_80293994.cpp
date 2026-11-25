#include "w3d_ptr.h"
#line 1 "s11border_80293994.cpp"
/* Named border resource attachment with observed shared-string ownership. */
struct S11BorderObject;
struct S11BorderTable { Ptr32<void (void)> unknown[3];Ptr32<void (Ptr32<S11BorderObject>)> retain;Ptr32<void (Ptr32<S11BorderObject>)> release; };
struct S11BorderObject {Ptr32<S11BorderTable> vtable;char unknown04[32];Ptr32<char> name;};
struct S11BorderRef {Ptr32<S11BorderObject> value;int reserved;};
struct S11BorderString {
 S11BorderString(const S11BorderString &); S11BorderString() {}Ptr32<char> text;};
extern "C" {
Ptr32<S11BorderObject> fn_8020B680(Ptr32<const void>);
int fn_8020BB54(Ptr32<S11BorderString>,Ptr32<const char>);
int fn_8020BB2C(Ptr32<unsigned short>);
void fn_8020C5C4(Ptr32<S11BorderString>);
int fn_80341588(Ptr32<S11BorderString>);
int fn_80174820(Ptr32<void>,Ptr32<S11BorderObject>);
extern const char lbl_803D06F4[];
extern const unsigned char lbl_804144E8[];
int s11_attach_border_80293994(Ptr32<void> owner) {
    struct {S11BorderRef ref;S11BorderString name;} local;
    local.ref.value=fn_8020B680(lbl_804144E8);
    if (local.ref.value) local.ref.value->vtable->retain(local.ref.value);
    Ptr32<S11BorderObject> object=local.ref.value;
    register Ptr32<S11BorderString> name=&local.name;
    fn_8020BB54(name,lbl_803D06F4);
    ++((Ptr32<unsigned short>)local.name.text)[-3];
    Ptr32<char> old=object->name;
    Ptr32<unsigned short> header=(Ptr32<unsigned short>)old-3;
    unsigned int count=*header-1;
    *header=count;
    if (!(unsigned short)count) fn_8020BB2C(header);
    object->name=local.name.text;
    fn_8020C5C4(name);
    fn_80341588(name);
    fn_80174820(owner,local.ref.value);
    if (local.ref.value) local.ref.value->vtable->release(local.ref.value);
    return 0;
}
}


