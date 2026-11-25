#include "w3d_ptr.h"
#line 1 "f17c_buffers_cleanup_800f6ca0.cpp"
// External receiver prefix only; no complete object size or allocation is inferred.
// Two observed three-pointer buffers occupy +4 and +16; unknown words remain unnamed.
// Original calls memcpy with a zero byte count and the varargs call-site CR convention.
// clear preserves the observed removed byte span across that call.
extern "C" Ptr32<void> copy_802eee50(Ptr32<void>,Ptr32<const void>,...);
extern "C" void release_80209920(Ptr32<void>,Ptr32<void>),free_802134fc(Ptr32<void>);
struct F17cHeap {unsigned observed;};extern F17cHeap heap_804adde4;
struct F17cInterface {Ptr32<Ptr32<void>> vtable;};
struct F17cBuffer {
 Ptr32<Ptr32<void>> begin; Ptr32<Ptr32<void>> end; Ptr32<Ptr32<void>> capacity;
 unsigned size()const{return end-begin;}
 void clear(){Ptr32<Ptr32<void>> first=begin; Ptr32<Ptr32<void>> last=end;unsigned removed=(Ptr32<char>)last-(Ptr32<char>)first;copy_802eee50(first,last,0);end=(Ptr32<Ptr32<void>>)((Ptr32<char>)end-removed);}
 ~F17cBuffer(){if(begin)free_802134fc(begin);}
};
struct F17cOwner {
 unsigned unknown0;F17cBuffer a,b;unsigned unknown28;Ptr32<F17cInterface> held;
};
extern "C" void f17c_cleanup_800f6ca0(Ptr32<F17cOwner> self,unsigned flags){
 unsigned i=0;for(;i<self->a.size();++i)*(Ptr32<Ptr32<void>>)((Ptr32<char>)self->a.begin+(i<<2))=0;
 self->a.clear();
 for(i=0;i<self->b.size();++i){release_80209920(&heap_804adde4,*(Ptr32<Ptr32<void>>)((Ptr32<char>)self->b.begin+(i<<2)));*(Ptr32<Ptr32<void>>)((Ptr32<char>)self->b.begin+(i<<2))=0;}
 self->b.clear();
 if(self->held)((Ptr32<void (Ptr32<F17cInterface>)>)self->held->vtable[4])(self->held);
 self->b.~F17cBuffer();self->a.~F17cBuffer();
 if(flags&1)release_80209920(&heap_804adde4,self);
}


