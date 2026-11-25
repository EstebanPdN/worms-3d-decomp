// Observed PPC32 pointer-vector header and zero-length trailing move.
extern "C" void copy_802eee50(void*,const void*,...);
struct Cc17aVector{void **begin,**end,**capacity;unsigned cc17a_size(){return end-begin;}
 void clear(){void**first=begin;void**last=end;int bytes=(char*)last-(char*)first;copy_802eee50(first,last,0);end=(void**)((char*)end-bytes);}
};
extern "C" void destroy_800b916c(void*,int);
struct Cc17aOwner{char pad[52];Cc17aVector items;};
extern "C" int w3d_cc17a_clear_pair_strings_800b9a48(Cc17aOwner*self){for(unsigned i=0;i<self->items.cc17a_size();++i){void*item=*(void**)((char*)self->items.begin+(i<<2));if(item)destroy_800b916c(item,3);*(void**)((char*)self->items.begin+(i<<2))=0;}self->items.clear();return 0;}
