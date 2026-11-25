#include "w3d_ptr.h"
#line 1 "f1p_words_notify_802bd430.cpp"
// Original 0x802bd430. Observed layout and operations; role inferred.
struct Words { unsigned x,y,z; int operator==(const Words &b)const{return x==b.x && y==b.y && z==b.z;} };
struct Item { Ptr32<Ptr32<void>> v; };
struct Owner { char pad[40];Words words;char pad34[44];Ptr32<Item> item; };
extern "C" void fn_802bf81c(Ptr32<Owner>);
extern "C" void fn_802bd354(Ptr32<Owner>);
extern "C" void w3d_words_notify_802bd430(Ptr32<Owner> self,Ptr32<const Words> words) {
 int changed=0;
 if(!(self->words==*words)) {self->words=*words;changed=1;}
 if(changed==1 && self->item){((Ptr32<void (Ptr32<Item>, Ptr32<Words>, int)>)self->item->v[19])(self->item,&self->words,0);fn_802bf81c(self);}
 fn_802bd354(self);
}


