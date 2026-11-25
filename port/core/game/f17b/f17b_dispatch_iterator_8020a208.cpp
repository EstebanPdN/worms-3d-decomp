#include "w3d_ptr.h"
#line 1 "f17b_dispatch_iterator_8020a208.cpp"
// External counter helper8020b85c increments804b069c for nonzero input and
// decrements it for zero. No dispatcher or target is locally allocated or
// constructed; these are partial external views, not complete object sizes.
// Partial external dispatcher view. The receiver and payload types are inferred;
// calls use original virtual slot24. Only iterator pointers are local values.
extern "C" void fn_8020b85c(int);
struct F17bDispatchTarget{Ptr32<Ptr32<void>> table;int dispatch(Ptr32<void> a,unsigned flags,Ptr32<void> b){return ((Ptr32<int (Ptr32<F17bDispatchTarget>, Ptr32<void>, unsigned int, Ptr32<void>)>)table[6])(this,a,flags,b);}};
struct F17bDispatcher{unsigned prefix[5];Ptr32<Ptr32<F17bDispatchTarget>> begin; Ptr32<Ptr32<F17bDispatchTarget>> end;unsigned unknown;Ptr32<F17bDispatchTarget> preferred;};
extern "C" int f17b_dispatch_8020a208(Ptr32<F17bDispatcher> self,Ptr32<void> a,unsigned flags,Ptr32<void> b){Ptr32<Ptr32<F17bDispatchTarget>> end=self->end;Ptr32<Ptr32<F17bDispatchTarget>> p=self->begin;fn_8020b85c(1);int result=0x80004005;
 if(self->preferred&&(flags&10)){result=self->preferred->dispatch(a,flags,b);if(result>=0){fn_8020b85c(0);return result;}}
 if(p!=end){Ptr32<Ptr32<F17bDispatchTarget>> next;do{next=p+1;if(next==end)fn_8020b85c(0);result=(*p)->dispatch(a,flags,b);if(result>=0){if(next!=end)fn_8020b85c(0);return result;}p=next;}while(next!=end);}
 return result;}


