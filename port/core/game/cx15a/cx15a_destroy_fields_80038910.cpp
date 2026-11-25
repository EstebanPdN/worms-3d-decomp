#include "w3d_ptr.h"
#line 1 "cx15a_destroy_fields_80038910.cpp"
// Inferred actions. PPC32 field byte offsets are observed in original instructions.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
#define VCALL(p,T,o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p)+(o))))
inline void release(Ptr32<void> p){if(p)VCALL(p,void(*)(void*),16)(p);}
extern unsigned vtable_8040e690[];extern "C" void base_801628ec(Ptr32<void>,unsigned);extern "C" void finish_8020c5c4(Ptr32<void>),release_string_80341588(Ptr32<void>);extern "C" void w3d_cx15a_destroy_fields_80038910(Ptr32<void> self,unsigned flags){FIELD(self,void*,0)=vtable_8040e690;release(FIELD(self,void*,88));release(FIELD(self,void*,84));release(FIELD(self,void*,80));release(FIELD(self,void*,76));release(FIELD(self,void*,72));release(FIELD(self,void*,68));release(FIELD(self,void*,64));finish_8020c5c4((Ptr32<char>)self+52);release_string_80341588((Ptr32<char>)self+52);finish_8020c5c4((Ptr32<char>)self+48);release_string_80341588((Ptr32<char>)self+48);finish_8020c5c4((Ptr32<char>)self+44);release_string_80341588((Ptr32<char>)self+44);release(FIELD(self,void*,32));base_801628ec(self,flags);}

