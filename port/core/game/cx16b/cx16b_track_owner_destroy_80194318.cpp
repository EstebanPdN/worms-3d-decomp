#include "w3d_ptr.h"
#line 1 "cx16b_track_owner_destroy_80194318.cpp"
/* Observed cleanup order for the owner at this entry. Range record strides
   are 20, 16 and 12 bytes; class and track meanings remain inferred. */
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
struct Cx16bHeld { Ptr32<Ptr32<void>> vtable; };
struct Cx16bPlain12 { unsigned words[3]; };
struct Cx16bHeld16 { Ptr32<Cx16bHeld> held; unsigned words[3]; };
struct Cx16bNested20 { unsigned word; Ptr32<unsigned int> begin; Ptr32<unsigned int> end; Ptr32<unsigned int> capacity; unsigned tail; };
extern "C" {
extern char lbl_80413378[],lbl_804133c8[];
void fn_801907d0(Ptr32<void>);
void fn_80210990(Ptr32<void>,int);
void fn_801fe1f8(Ptr32<void>);
}
static inline void cx16b_release(Ptr32<Cx16bHeld> held){if(held)((Ptr32<void (Ptr32<Cx16bHeld>)>)held->vtable[4])(held);}
extern "C" void w3d_cx16b_track_owner_destroy_80194318(Ptr32<char> self,int flags)
{
    Ptr32<Cx16bHeld> held=FIELD(self,Cx16bHeld *,124);
    FIELD(self,char *,0)=lbl_80413378;
    cx16b_release(held);
    if(FIELD(self,void *,96))fn_801907d0(FIELD(self,void *,96));
    {
        Ptr32<char> nested=self+80;
        Ptr32<Cx16bNested20> it=FIELD(nested,Cx16bNested20 *,0);
        Ptr32<Cx16bNested20> end=FIELD(nested,Cx16bNested20 *,4);
        Ptr32<char> held_range=self+56;
        Ptr32<char> plain_range=self+40;
        Ptr32<char> base=self+4;
        while(it!=end){
            Ptr32<Ptr32<unsigned int>> range=&it->begin;
            Ptr32<unsigned int> first=it->begin; Ptr32<unsigned int> last=FIELD(range,unsigned *,4);
            Ptr32<Cx16bNested20> next=it+1;
            for(Ptr32<unsigned int> p=first;p!=last;++p){}
            if(*range)fn_801907d0(*range);
            it=next;
        }
        if(FIELD(nested,void *,0))fn_801907d0(FIELD(nested,void *,0));
        cx16b_release(FIELD(self,Cx16bHeld *,76));
        cx16b_release(FIELD(self,Cx16bHeld *,72));
        Ptr32<Cx16bHeld16> held_end=FIELD(held_range,Cx16bHeld16 *,4);
        for(Ptr32<Cx16bHeld16> p=FIELD(self,Cx16bHeld16 *,56);p!=held_end;++p)cx16b_release(p->held);
        if(FIELD(held_range,void *,0))fn_801907d0(FIELD(held_range,void *,0));
        Ptr32<Cx16bPlain12> plain_end=FIELD(plain_range,Cx16bPlain12 *,4);
        for(Ptr32<Cx16bPlain12> p=FIELD(self,Cx16bPlain12 *,40);p!=plain_end;++p){}
        Ptr32<void> plain_storage=FIELD(plain_range,void * volatile,0);
        if(plain_storage)fn_801907d0(plain_storage);
        if(FIELD(self,void *,24))fn_801907d0(FIELD(self,void *,24));
        FIELD(self,char *,0)=lbl_804133c8;
        fn_80210990(base,0);
    }
    if(flags&1)fn_801fe1f8(self);
}


