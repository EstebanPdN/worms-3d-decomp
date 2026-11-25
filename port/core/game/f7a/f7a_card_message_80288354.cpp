#include "w3d_ptr.h"
#line 1 "f7a_card_message_80288354.cpp"
// Observed card UI offsets and message cache identities; semantic names inferred.
struct F7aMsg{unsigned short id;};struct F7aCache{int words[2];};
struct F7aCardEntries{int unknown[2];int count;};
struct F7aCard{char unknown0[140];int busy;char unknown144[544];int selected;char unknown692[12];int state;char unknown708[260];Ptr32<F7aCardEntries> entries;char unknown972[44];unsigned flags;};
extern F7aCache cache_804b0c2c,cache_804b0c14,cache_804b0c1c,cache_804b0c24,cache_804b0c34,cache_804b0c3c;
extern char boot_803cf8b8[],save_803cf8d0[],load_803cf8e4[];
extern "C" int fn_8016293c(Ptr32<F7aCard>,Ptr32<F7aMsg>),fn_8015f65c(unsigned short,Ptr32<F7aCache>),fn_802fb7ac(Ptr32<const char>,...);
extern "C" void fn_80288ab8(Ptr32<F7aCard>),fn_80288b9c(Ptr32<F7aCard>),fn_80289da4(Ptr32<F7aCard>),fn_80289df8(Ptr32<F7aCard>),fn_80289e80(Ptr32<F7aCard>);
extern "C" int w3d_f7a_card_message_80288354(Ptr32<F7aCard> self,Ptr32<F7aMsg> msg){
 switch(msg->id){case 64:if(fn_8016293c(self,msg)>=0){fn_80288ab8(self);return 0;}return (int)0x80004005;case 66:fn_80288b9c(self);goto done;default:break;}
 if(fn_8015f65c(msg->id,&cache_804b0c2c)){fn_802fb7ac(boot_803cf8b8);fn_80289da4(self);}
 if(self->state==1){
 if(fn_8015f65c(msg->id,&cache_804b0c14)){if(self->entries&&self->entries->count){if(--self->selected<0)self->selected=self->entries->count-1;}}
 else if(fn_8015f65c(msg->id,&cache_804b0c1c)){if(self->entries&&self->entries->count){if(++self->selected>=self->entries->count)self->selected=0;}}
 else if(fn_8015f65c(msg->id,&cache_804b0c24)){if(self->entries&&self->entries->count)self->flags|=0x80000000;}
 else if(fn_8015f65c(msg->id,&cache_804b0c34)&&!self->busy){fn_802fb7ac(save_803cf8d0);fn_80289df8(self);}
 else if(fn_8015f65c(msg->id,&cache_804b0c3c)&&!self->busy){fn_802fb7ac(load_803cf8e4);fn_80289e80(self);}
 }
 done:return fn_8016293c(self,msg);
}


