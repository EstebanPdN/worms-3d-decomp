#include "w3d_ptr.h"
#line 1 "f10a_key_vector_80278130.cpp"
// Original 0x80278130. Layout and role inferred from byte witnesses.
struct F10aKeyOwner_80278130 { char pad[92];Ptr32<void> field; };
extern "C" void fn_80275f18(Ptr32<F10aKeyOwner_80278130>);
extern "C" Ptr32<char> fn_802ef198(Ptr32<const char>,int);
extern "C" void fn_802761b8(Ptr32<F10aKeyOwner_80278130>,Ptr32<void>,int);
extern Ptr32<char> keys_804abb9c;
extern Ptr32<char> keys_804abba0;
extern "C" void w3d_f10a_key_vector_80278130(Ptr32<F10aKeyOwner_80278130> self,int key) {
 if(key==27) {fn_80275f18(self);return;}
 Ptr32<char> p=fn_802ef198(keys_804abb9c,key);
 Ptr32<char> keys=keys_804abb9c;
 if(!p) { keys=keys_804abba0;p=fn_802ef198(keys,key);if(!p)return; }
 switch(p-keys) {
 case 0: fn_802761b8(self,self->field,20);break;
 case 1: fn_802761b8(self,self->field,21);break;
 case 2: fn_802761b8(self,self->field,22);break;
 case 3: fn_802761b8(self,self->field,24);break;
 case 4: fn_802761b8(self,self->field,23);break;
 case 5: fn_802761b8(self,self->field,25);break;
 case 6: fn_802761b8(self,self->field,26);break;
 case 7: fn_802761b8(self,self->field,27);break;
 case 8: fn_802761b8(self,self->field,28);break;
 case 9: fn_802761b8(self,self->field,29);break;
 case 10: fn_802761b8(self,self->field,30);break;
 case 11: fn_802761b8(self,self->field,31);break;
 case 12: fn_802761b8(self,self->field,32);break;
 case 13: fn_802761b8(self,self->field,33);break;
 case 14: fn_802761b8(self,self->field,34);break;
 case 15: fn_802761b8(self,self->field,36);break;
 case 16: fn_802761b8(self,self->field,35);break;
 }
}


