#include "w3d_ptr.h"
#line 1 "f1p_load_audio_802b253c.cpp"
// Partial layout and audio semantics inferred from observed calls and offsets.
struct Vec3{float x,y,z;};
struct Item{Ptr32<Ptr32<void>> v;};
struct Service{Ptr32<Ptr32<void>> v;};struct App{char pad[108];Ptr32<Service> service;};
struct Owner{char pad[80];int name[2];char pad88[16];int mode,loaded;int unused112,active;char pad120[12];Ptr32<Item> item;};
extern Ptr32<App> app_804b1788;extern const char error_803d7b04[];
extern "C" void fn_802b24bc(Ptr32<Owner>);extern "C" Vec3 fn_802b22e4(Ptr32<Owner>);extern "C" void fn_8020c510(Ptr32<void>,Ptr32<const char>,...);
extern "C" void w3d_load_audio_802b253c(Ptr32<Owner> self,Ptr32<const char> name){if(!name||!*name){fn_802b24bc(self);return;}if(!self->mode)fn_802b24bc(self);if(!self->loaded){Ptr32<Service> p=app_804b1788->service;if(p){if(((Ptr32<int (Ptr32<Service>, Ptr32<const char>, Ptr32<Ptr32<Item>>)>)p->v[23])(p,name,&self->item)>=0){self->loaded=1;if(self->mode==1)self->active=self->mode;else{((Ptr32<void (Ptr32<Item>, int, const Vec3 &)>)self->item->v[14])(self->item,3,fn_802b22e4(self));((Ptr32<void (Ptr32<Item>)>)self->item->v[5])(self->item);}}else fn_8020c510(&self->name,error_803d7b04,w3d::VA(name));}}}


