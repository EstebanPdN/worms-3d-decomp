struct cc29b_Component_8018bb28 {void** vtable;};
struct cc29b_Set_8018bb28 {char unknown[32];void* components;};
struct cc29b_Text_8018bb28 {char prefix[36];cc29b_Set_8018bb28* set;};
struct cc29b_Flags_8018bb28 {char unknown[7];unsigned char flags;void dirty(){flags|=2;}};
struct cc29b_Scale_8018bb28 {cc29b_Component_8018bb28 base;cc29b_Flags_8018bb28 flags;char gap[12];float y,x;void setX(float v){x=v;flags.dirty();}void setY(float v){y=v;flags.dirty();}};
extern "C" const float lbl_803a7dec[];
extern "C" char lbl_80364f04[];
extern "C" char lbl_80415ca0[];
extern "C" void* fn_801ee034(void*,const void*);
extern "C" int fn_801ee0e0(void*,void*,int*);
extern "C" void fn_801ef380(cc29b_Set_8018bb28*,int,int,int,int);
extern "C" cc29b_Scale_8018bb28* fn_8020b680(void*);
extern "C" int fn_801b14e8(cc29b_Set_8018bb28*,cc29b_Scale_8018bb28*);
// The observed frame reserves more than the single output index. This20-byte
// workspace is a sufficient model; the original declaration/extent is unknown.
struct cc29b_Lookup_8018bb28 {int index;char unknown[16];};
extern "C" void w3d_cc29b_scale_text_8018bb28(cc29b_Text_8018bb28* self,float x,float y){
 if(x==lbl_803a7dec[0] && y==lbl_803a7dec[0]){
  void* cls=fn_801ee034(self->set->components,lbl_80364f04);
  if(cls){cc29b_Lookup_8018bb28 found;found.index=0;if(fn_801ee0e0(self->set->components,cls,&found.index)>=0)fn_801ef380(self->set,32,2,found.index,1);}
 }else{cc29b_Scale_8018bb28* scale=fn_8020b680(lbl_80415ca0);scale->setX(x);scale->setY(y);fn_801b14e8(self->set,scale);}
}
