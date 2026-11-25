#include "w3d_ptr.h"
#line 1 "cx12b_focus_advance_802c3ef0.cpp"

struct Owner {unsigned char opaque[64];int current,previous,mode;};
extern "C" void dispatch_802c3ff0(Ptr32<Owner>,int,int);
extern "C" void w3d_cx12b_focus_advance_802c3ef0(Ptr32<Owner> self){int next=self->current;if(self->mode==2)next=self->previous;else{switch(next){case 9:case 19:case 29:next-=9;break;case 31:next=30;break;case 33:next=32;break;case 34:next=33;break;case 35:next=34;break;case 32:next=35;break;default:next++;break;}}
 if(next!=self->current){dispatch_802c3ff0(self,0,self->current);dispatch_802c3ff0(self,1,next);self->previous=self->current;self->current=next;self->mode=3;}}




