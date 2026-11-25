// Partial external allocator/control views; none is constructed locally.
struct G1bHeap;
struct G1bHeapControl {unsigned flags,unknown,size;};
typedef void(*G1bHeapError)(G1bHeap*,int,void*);
struct G1bHeapCallbacks {G1bHeapError unknown,error;};
struct G1bHeap {char prefix[44];G1bHeapCallbacks*callbacks;G1bHeapControl*control;};
extern "C" void*fn_80216c4c(G1bHeap*,unsigned);
extern "C" void fn_80216f5c(G1bHeap*,void*);
extern "C" int fn_80216e7c(G1bHeap*,void*);
extern void(*callback_8040077c[])(G1bHeap*,void*,void*,unsigned);
extern "C" void*g1b_reallocate_fixed_8021707c(G1bHeap*self,void*pointer,unsigned bytes,unsigned options){
 G1bHeapControl*control=self->control;void*result;
 if(!pointer){result=fn_80216c4c(self,bytes);if(result&&(options&4)){unsigned*p=(unsigned*)result;do{*p++=0;}while((char*)p<(char*)result+bytes);}}
 else{
  if(bytes==0)fn_80216f5c(self,pointer);
  else{
   unsigned flags=control->flags;if(flags&1)return pointer;
   if(!(flags&8192)){
    if(bytes==control->size){control->flags=flags|16384;if(fn_80216e7c(self,pointer)==0){if((control->flags&2)&&callback_8040077c[0])callback_8040077c[0](self,pointer,pointer,bytes);return pointer;}}
    G1bHeapError error=self->callbacks->error;if(error)error(self,3,pointer);
   }
  }
  result=0;
 }
 return result;
}
