// Partial layout and audio semantics inferred from observed calls and offsets.
struct Vec3{float x,y,z;};
struct Item{void**v;};
struct Service{void**v;};struct App{char pad[108];Service*service;};
struct Owner{char pad[80];int name[2];char pad88[16];int mode,loaded;int unused112,active;char pad120[12];Item*item;};
extern App*app_804b1788;extern const char error_803d7b04[];
extern "C" void fn_802b24bc(Owner*);extern "C" Vec3 fn_802b22e4(Owner*);extern "C" void fn_8020c510(void*,const char*,...);
extern "C" void w3d_load_audio_802b253c(Owner*self,const char*name){if(!name||!*name){fn_802b24bc(self);return;}if(!self->mode)fn_802b24bc(self);if(!self->loaded){Service*p=app_804b1788->service;if(p){if(((int(*)(Service*,const char*,Item**))p->v[23])(p,name,&self->item)>=0){self->loaded=1;if(self->mode==1)self->active=self->mode;else{((void(*)(Item*,int,const Vec3&))self->item->v[14])(self->item,3,fn_802b22e4(self));((void(*)(Item*))self->item->v[5])(self->item);}}else fn_8020c510(&self->name,error_803d7b04,name);}}}
