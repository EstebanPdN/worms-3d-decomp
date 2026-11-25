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
// Inferred pool allocation creates a 0x14-byte selection; owner storage +0x34.
struct Cx9aOwner {unsigned char unknown00[0x34];Cx9aStorage storage;};
struct Cx9aPool {unsigned int head;};
extern Cx9aPool selection_pool_804adde4;
extern "C" void *pool_allocate_802098d8(void *,unsigned int);
extern "C" void *selection_construct_800b912c(void *);
extern "C" void selection_initialize_800b923c(void *);
extern "C" void *selection_key_800b4d98(void *);
extern "C" void selection_set_key_800b9240(void *,void *);
extern "C" int w3d_cx9a_selection_create_append_800ba4c4(Cx9aOwner *self,void *key){unsigned int entry=(unsigned int)selection_construct_800b912c(pool_allocate_802098d8(&selection_pool_804adde4,0x14));selection_initialize_800b923c((void *)entry);selection_set_key_800b9240((void *)entry,selection_key_800b4d98(key));self->storage.push(entry);return 0;}
