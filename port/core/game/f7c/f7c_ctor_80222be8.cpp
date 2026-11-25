#include "w3d_ptr.h"
#line 1 "f7c_ctor_80222be8.cpp"
// Names, roles, types, qualifiers and layout are inferred from original instructions.
// Unknown base storage is explicit; referenced constants and strings remain external.
extern "C" int fn_8021ef08(Ptr32<void>, Ptr32<void>);extern "C" void fn_8020c5c0(Ptr32<void>);extern "C" Ptr32<unsigned short> fn_80341884(Ptr32<void>);inline void*operator new(__SIZE_TYPE__,void*p){return p;}struct String_8020bb54{Ptr32<char> text;template <class W3dU> String_8020bb54(Ptr32<W3dU> w3d_p) : String_8020bb54((const char *)w3d_p.get()) {}
 String_8020bb54(const char*);String_8020bb54(const String_8020bb54&o){fn_8020c5c0(this);text=o.text;++*fn_80341884(this);}};typedef String_8020bb54 String;extern String lbl_804b06a0[];extern Ptr32<void> lbl_8041a438[];extern const float lbl_803b7018[],lbl_803b701c[];struct Owner{Ptr32<void> vtable;char unknown[112];float x,y;unsigned kind,enabled;String a,b,c,d;unsigned z0,z1,one,z2;};extern "C" Ptr32<Owner> f7c_ctor_80222be8(Ptr32<Owner> self, Ptr32<void> arg_r4){fn_8021ef08(self, arg_r4);self->vtable=lbl_8041a438;self->x=lbl_803b7018[0];self->y=lbl_803b701c[0];self->kind=3;self->enabled=1;new(&self->a)String(lbl_804b06a0[0]);new(&self->b)String(lbl_804b06a0[0]);new(&self->c)String(lbl_804b06a0[0]);new(&self->d)String(lbl_804b06a0[0]);self->z0=0;self->z1=0;self->one=1;self->z2=0;return self;}


