// Inferred interface names; observed PPC32 vtable byte offsets are explicit.
struct Interface;
struct Vtable { void *unused[3]; int (*retain)(Interface *); int (*release)(Interface *); };
struct Interface { Vtable *vtable; };

struct KeyVector {unsigned int *begin,*end,*capacity;};
struct Registry {unsigned char opaque[44]; Interface **services;KeyVector keys;};
extern "C" unsigned int *find_8035c220(unsigned int *,unsigned int *,const unsigned int *);
extern "C" int w3d_cx10b_service_find_indexed_80206720(Registry *self,unsigned int key,Interface **out) {
 KeyVector &keys=self->keys;
 unsigned int *p=find_8035c220(keys.begin,keys.end,&key);
 if(p==keys.end) { *out=0;return (int)0x80004005; }
 else {
  unsigned int offset=((unsigned int)p-(unsigned int)self->keys.begin)&~3u;
  Interface **slot=(Interface **)(offset+(unsigned int)self->services);
  Interface *value=*slot;
  *out=value;value->vtable->retain(value);return 0;
 }
}


