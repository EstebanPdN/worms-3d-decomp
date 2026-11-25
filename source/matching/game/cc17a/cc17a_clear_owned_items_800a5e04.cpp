// Observed PPC32 pointer-vector header and zero-length trailing move.
extern "C" void copy_802eee50(void*,const void*,...);
struct Cc17aVector{void **begin,**end,**capacity;void**cc17a_end(){return end;}
 void clear(){void**first=begin;void**last=end;int bytes=(char*)last-(char*)first;copy_802eee50(first,last,0);end=(void**)((char*)end-bytes);}
};
extern "C" void destroy_8015f558(void*,int),release_80209920(void*,void*);struct Cc17aHeap{unsigned state;};extern Cc17aHeap heap_804ae280;
struct Cc17aOwner{char pad[36];Cc17aVector items;int ready;};
extern "C" void w3d_cc17a_clear_owned_items_800a5e04(Cc17aOwner*self){*((char*)self+1)=0;for(void**p=self->items.begin;p!=self->items.cc17a_end();++p){void*item=*p;if(item){destroy_8015f558((char*)item+4,2);release_80209920(&heap_804ae280,item);}}self->items.clear();self->ready=1;}
