#include "w3d_ptr.h"
#line 1 "f5a_destroy_script_80270e58.cpp"
#define F(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char*)w3d::AG(p)+(o)))
extern char vt_8041be80[];
extern "C" void fn_8020c5c4(Ptr32<void>);
extern "C" void fn_80341588(Ptr32<void>);
extern "C" void fn_802134fc(Ptr32<void>);
extern "C" void fn_80210abc(Ptr32<void>,int);
extern "C" void fn_801628ec(Ptr32<void>,int);
inline void release(Ptr32<void> p){if(p)(*(Ptr32<Ptr32<Ptr32<void (Ptr32<void>)>>>)(p))[4](p);}
struct Range{Ptr32<char> begin;Ptr32<char> end;};
extern "C" void w3d_f5a_destroy_script_80270e58(Ptr32<void> self,int flags){
 *(Ptr32<Ptr32<void>>)self=vt_8041be80;release(F(self,void*,92));release(F(self,void*,88));
 Ptr32<Range> range=(Ptr32<Range>)((Ptr32<char>)self+64);Ptr32<char> p=range->begin; Ptr32<char> end=range->end;Ptr32<void> member=(Ptr32<char>)self+52;
 while(p!=end){fn_8020c5c4(p);fn_80341588(p);p+=4;}
 if(range->begin)fn_802134fc(range->begin);fn_80210abc(member,2);release(F(self,void*,28));fn_801628ec(self,flags);
}


