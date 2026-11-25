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
// Inferred 0x30-byte plan object; assignment of shared context at +0xc.
struct Cx9aPlan {unsigned char unknown00[0xc];void *context;unsigned char unknown10[0x20];};
extern "C" void *object_allocate_8001523c(unsigned int);
extern "C" Cx9aPlan *plan_construct_80015d04(void *);
extern Cx9aStorage *plans_804aa700;
extern void *context_804aa6c0;
extern "C" void w3d_cx9a_plan_create_append_80016ad0(){unsigned int plan=(unsigned int)plan_construct_80015d04(object_allocate_8001523c(0x30));((Cx9aPlan *)plan)->context=context_804aa6c0;plans_804aa700->push(plan);}
