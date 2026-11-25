// External service-owner prefix and interface views; local held interface is one pointer.
struct G4aPrepareIface{void**vt;};
struct G4aPrepareHeld{G4aPrepareIface*p;G4aPrepareHeld(G4aPrepareIface*q):p(q){if(p)((void(*)(G4aPrepareIface*))p->vt[3])(p);}~G4aPrepareHeld(){if(p)((void(*)(G4aPrepareIface*))p->vt[4])(p);}void assign(G4aPrepareIface*q){if(q)((void(*)(G4aPrepareIface*))q->vt[3])(q);if(p)((void(*)(G4aPrepareIface*))p->vt[4])(p);p=q;}};
struct G4aPrepareOwner{char unknown0[88];unsigned hasServices;unsigned unknown92;G4aPrepareHeld renderer,first,second,optional;};
extern "C" G4aPrepareIface*root_8020b648(),*lookup_8020b680(void*);
extern "C" void prepare_8015c994(G4aPrepareOwner*),prepare_8015ca48(G4aPrepareOwner*);
extern "C" int prepare_8015b72c(G4aPrepareOwner*);
extern "C" int bind_80164514(G4aPrepareIface*,G4aPrepareIface*,unsigned);
extern unsigned type_804143e0[],type_80412240[],type_804118f8[],type_80411960[],type_804168b0[],type_80411698[];
inline G4aPrepareIface*queryService(void*type){G4aPrepareIface*root=root_8020b648();return ((G4aPrepareIface*(*)(G4aPrepareIface*,void*))root->vt[23])(root,type);}
extern "C" int g4a_prepare_services_8015c670(G4aPrepareOwner*self){
 queryService(type_804143e0);
 self->first.assign(lookup_8020b680(type_80412240));
 self->renderer.assign(lookup_8020b680(type_804118f8));
 ((void(*)(G4aPrepareIface*))self->renderer.p->vt[6])(self->renderer.p);
 G4aPrepareHeld service(lookup_8020b680(type_80411960));
 bind_80164514(self->renderer.p,service.p,0xbabe000);
 prepare_8015b72c(self);prepare_8015c994(self);
 if(!self->hasServices)self->optional.assign(lookup_8020b680(type_804168b0));
 prepare_8015ca48(self);
 self->second.assign(lookup_8020b680(type_80411698));
 bind_80164514(self->renderer.p,self->second.p,0xbabe000);
 return 0;
}
