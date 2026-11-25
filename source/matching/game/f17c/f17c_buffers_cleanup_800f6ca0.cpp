// External receiver prefix only; no complete object size or allocation is inferred.
// Two observed three-pointer buffers occupy +4 and +16; unknown words remain unnamed.
// Original calls memcpy with a zero byte count and the varargs call-site CR convention.
// clear preserves the observed removed byte span across that call.
extern "C" void *copy_802eee50(void*,const void*,...);
extern "C" void release_80209920(void*,void*),free_802134fc(void*);
struct F17cHeap {unsigned observed;};extern F17cHeap heap_804adde4;
struct F17cInterface {void **vtable;};
struct F17cBuffer {
 void **begin,**end,**capacity;
 unsigned size()const{return end-begin;}
 void clear(){void **first=begin,**last=end;unsigned removed=(char*)last-(char*)first;copy_802eee50(first,last,0);end=(void**)((char*)end-removed);}
 ~F17cBuffer(){if(begin)free_802134fc(begin);}
};
struct F17cOwner {
 unsigned unknown0;F17cBuffer a,b;unsigned unknown28;F17cInterface *held;
};
extern "C" void f17c_cleanup_800f6ca0(F17cOwner*self,unsigned flags){
 unsigned i=0;for(;i<self->a.size();++i)*(void**)((char*)self->a.begin+(i<<2))=0;
 self->a.clear();
 for(i=0;i<self->b.size();++i){release_80209920(&heap_804adde4,*(void**)((char*)self->b.begin+(i<<2)));*(void**)((char*)self->b.begin+(i<<2))=0;}
 self->b.clear();
 if(self->held)((void(*)(F17cInterface*))self->held->vtable[4])(self->held);
 self->b.~F17cBuffer();self->a.~F17cBuffer();
 if(flags&1)release_80209920(&heap_804adde4,self);
}
