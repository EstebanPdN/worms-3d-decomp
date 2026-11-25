#include "w3d_ptr.h"
#line 1 "f2a_update_water_80018ed0.cpp"
// Original entry 0x80018ed0. Water.Level is the original property string.
// The Name wrapper's reserved field is inferred.
struct Interface {Ptr32<Ptr32<void>> vt;};struct Array {Ptr32<Ptr32<void>> begin; Ptr32<Ptr32<void>> end;};
extern "C" {extern Ptr32<Array> lbl_804aa750;extern float lbl_804aa760;extern char lbl_8036a8f4[];int fn_800fc1b0(Ptr32<Ptr32<const char>>,Ptr32<Ptr32<Interface>>);Ptr32<Interface> fn_80342a74(Ptr32<Interface>);float fn_80178df0(Ptr32<Interface>);void fn_80018f88(Ptr32<void>,int);
void w3d_f2a_update_water_80018ed0(){struct Handle {
 Handle(const Handle &);Ptr32<Interface> p;Handle():p(0){}} handle;struct Name{Ptr32<const char> p;int reserved;Name(Ptr32<const char> w3d_p) : Name((const char *)w3d_p.get()) {}
 Name(const char *s):p(s){}} key(lbl_8036a8f4);fn_800fc1b0(&key.p,&handle.p);lbl_804aa760=fn_80178df0(fn_80342a74(handle.p));int count=lbl_804aa750->end-lbl_804aa750->begin;for(int i=0;i<count;++i)fn_80018f88(*(Ptr32<Ptr32<void>>)((Ptr32<char>)lbl_804aa750->begin+(i<<2)),i);if(handle.p)((Ptr32<void (Ptr32<Interface>)>)handle.p->vt[4])(handle.p);}}


