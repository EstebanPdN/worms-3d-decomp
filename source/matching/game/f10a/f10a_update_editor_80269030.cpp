// Partial layouts inferred from original instructions. The passed byte value
// occupies an observed forty-byte local buffer; remaining storage is unknown.
#define F(p,T,o) (*(T*)((char*)(p)+(o)))
typedef void (*F10aStateCall_80269030)(void*,int);
extern "C" void fn_802b0668(void*),fn_8026b2c4(void*),fn_8026c4dc(void*,int),fn_8026b3f0(void*);
extern "C" int fn_80173f88(void*,const unsigned char*);
extern void *world_804abb7c;
extern const float blend_803cb818[],carry_803cb824[],upper_803cb81c[],lower_803cb820[];
extern "C" int w3d_f10a_update_editor_80269030(void*self,int now){
 unsigned char value[40];
 fn_802b0668((char*)self+28);int remaining=now-F(self,int,420);if(remaining>100)remaining=100;
 if(remaining>19){const float blend=blend_803cb818[0],carry=carry_803cb824[0],upper=upper_803cb81c[0],lower=lower_803cb820[0];do{
 float desired=F(self,float,304),current=F(self,float,308);
 if(desired!=current){float next=current*carry+desired*blend;float difference=desired-next;F(self,float,308)=next;if(difference<upper&&difference>lower)F(self,float,308)=desired;fn_8026b2c4(self);}
 if(world_804abb7c){void *world=F(world_804abb7c,void*,68);if(world){bool active=F(world,int,3168)!=0;bool enabled=active;if(F(self,int,128))enabled=true;fn_8026c4dc(self,enabled);void*child=F(self,void*,296);if(child)F(child,F10aStateCall_80269030*,0)[22](child,enabled);unsigned count=F(self,unsigned,416)+1;F(self,unsigned,416)=count;if(enabled&&F(self,void*,296)){value[0]=(count/10)&3;fn_80173f88(F(self,void*,296),value);}}}
 else fn_8026c4dc(self,1);
 if(F(self,int,440)==1&&!F(self,int,128)&&F(self,int,112)){F(self,int,440)=0;fn_8026b3f0(self);}
 remaining-=20;
 }while(remaining>19);}
 F(self,int,420)=now-remaining;return 0;
}
