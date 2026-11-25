#include "w3d_ptr.h"
#line 1 "f1p_key_selection_80277b50.cpp"
// Original 0x80277b50. Layout and role inferred from byte witnesses.
struct Owner { char pad[92];Ptr32<void> field; };
extern "C" void fn_80275f18(Ptr32<Owner>);
extern "C" Ptr32<char> fn_802ef198(Ptr32<const char>,int);
extern "C" void fn_802761b8(Ptr32<Owner>,Ptr32<void>,int);
extern Ptr32<char> keys_804abb9c;
extern Ptr32<char> keys_804abba0;
extern "C" void w3d_key_selection_80277b50(Ptr32<Owner> self,int key) {
 if(key==27) {fn_80275f18(self);return;}
 Ptr32<char> p=fn_802ef198(keys_804abb9c,key);
 Ptr32<char> keys=keys_804abb9c;
 if(!p) { keys=keys_804abba0;p=fn_802ef198(keys,key);if(!p)return; }
 switch(p-keys) {
 case 0: fn_802761b8(self,self->field,20);break;
 case 1: fn_802761b8(self,self->field,21);break;
 case 2: fn_802761b8(self,self->field,22);break;
 }
}


