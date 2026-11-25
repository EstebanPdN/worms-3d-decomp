// Inferred raw byte-storage vector: begin +0, end +4, capacity +8.
extern "C" unsigned char *storage_allocate_80212fd4(unsigned int);
extern "C" void storage_release_802134fc(void *);
extern "C" void *storage_copy_802eee50(void *,const void *,...);
static inline const int &larger(const int &a,const int &b){return a<b?b:a;}
static inline const unsigned int &smaller(const unsigned int &a,const unsigned int &b){return b<a?b:a;}
struct Cx9aStorage {unsigned char *begin,*end,*capacity;
 void push(const unsigned int &value){
  if(end==capacity){unsigned int used=end-begin;int next=used+1;int grown=used+(used>>1);unsigned int allocated=larger(next,grown)*4;
   unsigned char *fresh=storage_allocate_80212fd4(allocated);
   if(begin){storage_copy_802eee50(fresh,begin,smaller(allocated,used));storage_release_802134fc(begin);}
   begin=fresh;end=fresh+used;capacity=fresh+allocated;
  }
  *(unsigned int *)end=value;end+=4;
 }
};
// PPC32 retained interface: table +0, retain slot +0xc, release slot +0x10.
struct Cx9aInterface;
struct Cx9aInterfaceTable {void *unknown[3];void (*retain)(Cx9aInterface *);void (*release)(Cx9aInterface *);};
struct Cx9aInterface {Cx9aInterfaceTable *table;unsigned char unknown04[0x18];unsigned int position[3];};
struct Cx9aHeld {Cx9aInterface *value;unsigned int spare;Cx9aHeld(Cx9aInterface *v):value(v){if(value)value->table->retain(value);}~Cx9aHeld(){if(value)value->table->release(value);}};
extern "C" Cx9aInterface *interface_lookup_8020b680(const void *);
extern "C" unsigned int service_create_80164514(void *,Cx9aInterface *,unsigned int);
extern void *service_804b178c;
// Owner creation argument +0x14, output storage +0x140.
struct Cx9aOwner {unsigned char unknown00[0x14];unsigned int argument;unsigned char unknown18[296];Cx9aStorage storage;};
extern unsigned char interface_key_8040fcf8[];
struct Cx9aWords3 {unsigned int x,y,z;};
extern "C" void w3d_cx9a_service_result_append_8008df50(Cx9aOwner *self,const Cx9aWords3 *position){Cx9aHeld held(interface_lookup_8020b680(interface_key_8040fcf8));Cx9aWords3 *out=(Cx9aWords3 *)held.value->position;*out=*position;self->storage.push(service_create_80164514(service_804b178c,held.value,self->argument));}
