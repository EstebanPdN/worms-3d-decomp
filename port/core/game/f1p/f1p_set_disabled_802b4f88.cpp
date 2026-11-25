#include "w3d_ptr.h"
#line 1 "f1p_set_disabled_802b4f88.cpp"
// Original 0x802b4f88: observed property disable/update sequence.
struct Item {Ptr32<Ptr32<void>> v;};
struct Carrier {char pad[156];Ptr32<void> value;};
struct Owner {char pad[40];Ptr32<Carrier> carrier;char pad2c[176];int disabled;char pade0[20];int updating;int unknownf8;Ptr32<Item> item;};
extern "C" Ptr32<Item> fn_803426b4(Ptr32<Item>);
extern "C" Ptr32<Item> fn_80342a78(Ptr32<Item>);
extern "C" int fn_80178c54(Ptr32<Item>,Ptr32<const int>);
extern "C" int fn_80178d28(Ptr32<Item>,Ptr32<const int>);
inline void set_boolean(Ptr32<Item> item,int value) {fn_80178c54(item,&value);}
extern "C" void w3d_set_disabled_802b4f88(Ptr32<Owner> self,int disabled) {
 if(self->carrier->value) {
  self->updating=1;
  if(self->item) {
   int value;if(disabled)value=0;else value=1;
   switch(((Ptr32<int (Ptr32<Item>)>)self->item->v[6])(self->item)) {
    case 0:set_boolean(fn_803426b4(self->item),value);break;
    case 1:fn_80178d28(fn_80342a78(self->item),&value);break;
   }
  }
  self->disabled=disabled;self->updating=0;
 }
}


