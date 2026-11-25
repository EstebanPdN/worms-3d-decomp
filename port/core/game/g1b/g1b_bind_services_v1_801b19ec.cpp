#include "w3d_ptr.h"
#line 1 "g1b_bind_services_v1_801b19ec.cpp"
// Partial external ABI views; no external object is allocated or constructed.
struct G1bInterface { Ptr32<Ptr32<void>> table; };
inline void retain(Ptr32<G1bInterface> p){if(p)((Ptr32<void (Ptr32<G1bInterface>)>)p->table[3])(p);}
inline void release(Ptr32<G1bInterface> p){if(p)((Ptr32<void (Ptr32<G1bInterface>)>)p->table[4])(p);}
struct G1bServiceOwner { char prefix[52]; unsigned member[5]; Ptr32<G1bInterface> first; Ptr32<G1bInterface> second; };
extern "C" Ptr32<G1bInterface> fn_8020b648();
extern "C" Ptr32<G1bInterface> fn_8020b680(Ptr32<const void>);
extern "C" void fn_801f2798(Ptr32<void>);
extern unsigned char key_804143e0[],key_80413be8[];
inline Ptr32<G1bInterface> findService(Ptr32<const void> key){Ptr32<G1bInterface> service=fn_8020b648();return ((Ptr32<Ptr32<G1bInterface> (Ptr32<G1bInterface>, Ptr32<const void>)>)service->table[23])(service,key);}
extern "C" int g1b_bind_services_801b19ec(Ptr32<G1bServiceOwner> self){
 Ptr32<G1bInterface> first=findService(key_804143e0);
 retain(first);release(self->first);self->first=first;
 Ptr32<G1bInterface> second=fn_8020b680(key_80413be8);
 retain(second);release(self->second);self->second=second;
 fn_801f2798(self->member);return 0;
}


