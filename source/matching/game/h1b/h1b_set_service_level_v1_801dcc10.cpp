// External owner prefix and service interfaces; no complete external local objects.
struct Interface {void**table;};
struct List {unsigned count;unsigned short capacity,growth;Interface**storage;Interface*get(unsigned i){return storage[i];}};
struct Owner {unsigned unknown[12];List services;};
extern const float lbl_803b00d0[],lbl_803b00d4[];
inline int kind(Interface*p){return ((int(*)(Interface*))p->table[7])(p);}
inline int level(Interface*p,float value){return ((int(*)(Interface*,float))p->table[13])(p,value);}
extern "C" int h1b_set_service_level_v1_801dcc10(Owner*self,int mode,float*value){
 float bound=lbl_803b00d0[0];if(bound<*value || (bound=lbl_803b00d4[0],*value<bound))*value=bound;
 switch(mode){
 case 17:for(unsigned i=0;i<self->services.count;++i)if(kind(self->services.get(i))==2)return level(self->services.get(i),*value);break;
 case 18:for(unsigned i=0;i<self->services.count;++i)if(kind(self->services.get(i))==4)return level(self->services.get(i),*value);break;
 case 19:for(unsigned i=0;i<self->services.count;++i)if(kind(self->services.get(i))==1)return level(self->services.get(i),*value);break;
 }
 return 1;
}
