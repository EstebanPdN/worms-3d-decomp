// Partial external ABI views; no external object is allocated or constructed.
struct G1bInterface { void **table; };
inline void retain(G1bInterface*p){if(p)((void(*)(G1bInterface*))p->table[3])(p);}
inline void release(G1bInterface*p){if(p)((void(*)(G1bInterface*))p->table[4])(p);}
struct G1bServiceOwner { char prefix[52]; unsigned member[5]; G1bInterface *first,*second; };
extern "C" G1bInterface *fn_8020b648();
extern "C" G1bInterface *fn_8020b680(const void*);
extern "C" void fn_801f2798(void*);
extern unsigned char key_804143e0[],key_80413be8[];
inline G1bInterface *findService(const void*key){G1bInterface *service=fn_8020b648();return ((G1bInterface*(*)(G1bInterface*,const void*))service->table[23])(service,key);}
extern "C" int g1b_bind_services_801b19ec(G1bServiceOwner*self){
 G1bInterface *first=findService(key_804143e0);
 retain(first);release(self->first);self->first=first;
 G1bInterface *second=fn_8020b680(key_80413be8);
 retain(second);release(self->second);self->second=second;
 fn_801f2798(self->member);return 0;
}
