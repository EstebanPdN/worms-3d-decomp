// Original 0x802732e8. Layout and role inferred from byte witnesses.
struct Owner { char pad[92];void *field; };
extern "C" void fn_80275f18(Owner *);
extern "C" char *fn_802ef198(const char *,int);
extern "C" void fn_802761b8(Owner *,void *,int);
extern char *keys_804abb9c;
extern char *keys_804abba0;
extern "C" void w3d_key_family_8027aca0(Owner *self,int key) {
 if(key==27) {fn_80275f18(self);return;}
 char *p=fn_802ef198(keys_804abb9c,key);
 char *keys=keys_804abb9c;
 if(!p) { p=fn_802ef198(keys_804abba0,key);keys=keys_804abba0;if(!p)return; }
 switch((unsigned)(p-keys)) {
 case 0: fn_802761b8(self,self->field,0);break;
 case 1: fn_802761b8(self,self->field,1);break;
 case 2: fn_802761b8(self,self->field,4);break;
 case 3: fn_802761b8(self,self->field,5);break;
 case 4: fn_802761b8(self,self->field,6);break;
 case 5: fn_802761b8(self,self->field,7);break;
 case 6: fn_802761b8(self,self->field,16);break;
 case 7: fn_802761b8(self,self->field,17);break;
 case 8: fn_802761b8(self,self->field,18);break;
 case 9: fn_802761b8(self,self->field,19);break;
 }
}
