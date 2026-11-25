// Partial reference wrapper and service roles inferred from observed calls.
struct Item{void**v;};
struct Held{Item*p;int unknown;Held(Item*q):p(q){if(p)((void(*)(Item*))p->v[3])(p);}~Held(){if(p)((void(*)(Item*))p->v[4])(p);}};
extern const char message_803cfab4[],service_80418f78[];
extern "C" void fn_802fb7ac(const char*,...);
extern "C" Item*fn_8020b680(const void*),*fn_80208aac(int);
extern "C" void fn_800fd488(Item*,int);
extern "C" void*fn_802eee50(void*,const void*,unsigned);
extern "C" void w3d_retrieve_data_8028a098(void*,void*out){fn_802fb7ac(message_803cfab4);Held source(fn_8020b680(service_80418f78));Held buffer(fn_80208aac(1));((void(*)(Item*,unsigned))buffer.p->v[8])(buffer.p,0x11800);((void(*)(Item*,Item*))source.p->v[5])(source.p,buffer.p);fn_800fd488(source.p,2);void*data;((void(*)(Item*,void**))buffer.p->v[10])(buffer.p,&data);fn_802eee50(out,data,0x11800);}
