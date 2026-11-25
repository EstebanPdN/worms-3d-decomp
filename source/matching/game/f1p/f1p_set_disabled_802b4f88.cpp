// Original 0x802b4f88: observed property disable/update sequence.
struct Item {void **v;};
struct Carrier {char pad[156];void *value;};
struct Owner {char pad[40];Carrier *carrier;char pad2c[176];int disabled;char pade0[20];int updating;int unknownf8;Item *item;};
extern "C" Item *fn_803426b4(Item *);
extern "C" Item *fn_80342a78(Item *);
extern "C" int fn_80178c54(Item *,const int *);
extern "C" int fn_80178d28(Item *,const int *);
inline void set_boolean(Item *item,int value) {fn_80178c54(item,&value);}
extern "C" void w3d_set_disabled_802b4f88(Owner *self,int disabled) {
 if(self->carrier->value) {
  self->updating=1;
  if(self->item) {
   int value;if(disabled)value=0;else value=1;
   switch(((int(*)(Item*))self->item->v[6])(self->item)) {
    case 0:set_boolean(fn_803426b4(self->item),value);break;
    case 1:fn_80178d28(fn_80342a78(self->item),&value);break;
   }
  }
  self->disabled=disabled;self->updating=0;
 }
}
