// PPC32 focus state at +64/+68/+72; names inferred.
struct Owner{unsigned char opaque[64];int current,previous,mode;};extern "C" void dispatch_802c3ff0(Owner*,int,int);
struct Map10{int value[10];};struct Map6{int value[6];};extern "C" const Map10 map_803d86a8;extern "C" const Map6 map_803d86d0;
extern "C" void w3d_cx13b_focus_vertical_0_802c3b20(Owner*self){int next=self->current;if(self->mode==0)next=self->previous;else{if(next<=29){if(next<=9){Map10 local=map_803d86a8;next=local.value[self->current];}else next-=10;}else{Map6 local=map_803d86d0;next=local.value[next-30];}}if(next!=self->current){dispatch_802c3ff0(self,0,self->current);dispatch_802c3ff0(self,1,next);self->previous=self->current;self->current=next;self->mode=1;}}

