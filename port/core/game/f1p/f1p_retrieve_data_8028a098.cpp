#include "w3d_ptr.h"
#line 1 "f1p_retrieve_data_8028a098.cpp"
// Partial reference wrapper and service roles inferred from observed calls.
struct Item{Ptr32<Ptr32<void>> v;};
struct Held{Ptr32<Item> p;int unknown;template <class W3dU> Held(Ptr32<W3dU> w3d_p) : Held((Item *)w3d_p.get()) {}
 Held(Item*q):p(q){if(p)((Ptr32<void (Ptr32<Item>)>)p->v[3])(p);}~Held(){if(p)((Ptr32<void (Ptr32<Item>)>)p->v[4])(p);}};
extern const char message_803cfab4[],service_80418f78[];
extern "C" void fn_802fb7ac(Ptr32<const char>,...);
extern "C" Ptr32<Item> fn_8020b680(Ptr32<const void>); Ptr32<Item> fn_80208aac(int);
extern "C" void fn_800fd488(Ptr32<Item>,int);
extern "C" Ptr32<void> fn_802eee50(Ptr32<void>,Ptr32<const void>,unsigned);
extern "C" void w3d_retrieve_data_8028a098(Ptr32<void>,Ptr32<void> out){fn_802fb7ac(message_803cfab4);Held source(fn_8020b680(service_80418f78));Held buffer(fn_80208aac(1));((Ptr32<void (Ptr32<Item>, unsigned int)>)buffer.p->v[8])(buffer.p,0x11800);((Ptr32<void (Ptr32<Item>, Ptr32<Item>)>)source.p->v[5])(source.p,buffer.p);fn_800fd488(source.p,2);struct{Ptr32<void> p;unsigned n[2];}range;((Ptr32<void (Ptr32<Item>, Ptr32<void>)>)buffer.p->v[10])(buffer.p,&range);fn_802eee50(out,range.p,0x11800);}


