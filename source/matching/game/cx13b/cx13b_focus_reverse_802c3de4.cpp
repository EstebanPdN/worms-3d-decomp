// PPC32 focus state at +64/+68/+72; names inferred.
struct Owner{unsigned char opaque[64];int current,previous,mode;};extern "C" void dispatch_802c3ff0(Owner*,int,int);

extern "C" void w3d_cx13b_focus_reverse_802c3de4(Owner*self){int next=self->current;if(self->mode==3)next=self->previous;else{switch(next){case 0:case 10:case 20:next+=9;break;case 30:next=31;break;case 32:next=33;break;case 33:next=34;break;case 34:next=35;break;case 35:next=32;break;default:--next;break;}}if(next!=self->current){dispatch_802c3ff0(self,0,self->current);dispatch_802c3ff0(self,1,next);self->previous=self->current;self->current=next;self->mode=2;}}

