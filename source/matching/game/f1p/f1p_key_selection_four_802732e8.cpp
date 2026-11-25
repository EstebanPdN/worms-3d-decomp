// Original 0x802732e8. Layout and role inferred from byte witnesses.
struct Owner { char pad[92];void *field; };
extern "C" void fn_80275f18(Owner *);
extern "C" char *fn_802ef198(const char *,int);
extern "C" void fn_802761b8(Owner *,void *,int);
extern char *keys_804abb9c;
extern char *keys_804abba0;
extern "C" void w3d_key_selection_four_802732e8(Owner *self,int key) {
 if(key==27) {fn_80275f18(self);return;}
 char *p=fn_802ef198(keys_804abb9c,key);
 char *keys=keys_804abb9c;
 if(!p) { keys=keys_804abba0;p=fn_802ef198(keys,key);if(!p)return; }
 switch(p-keys) {
 case 0: fn_802761b8(self,self->field,20);break;
 case 1: fn_802761b8(self,self->field,21);break;
 case 2: fn_802761b8(self,self->field,22);break;
 case 3: fn_802761b8(self,self->field,23);break;
 }
}
