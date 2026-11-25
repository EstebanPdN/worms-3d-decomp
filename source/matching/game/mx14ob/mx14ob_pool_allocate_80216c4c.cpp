// Fixed-size pool allocation for the external region allocator; the routine shape follows
// AT&T vmalloc poolalloc (hypothesis: source identity is not proven).
// All layout types are external observed prefixes, never local complete objects.
typedef unsigned long size_t;
struct Region;struct Seg;struct Block;
typedef Block*(*Extend)(Region*,size_t,void*);
typedef void(*Trace)(Region*,unsigned char*,unsigned char*,size_t);
// Observed block header: owning segment or pool free link, then size with low status bits.
struct Block {union{Seg*seg;Block*link;};size_t size;};
struct Seg {Region*vm;Seg*next;void*addr;size_t extent;unsigned char*baddr;size_t size;Block*free;};
// mode, rounding increment, pool element size, segment list and pool free list.
struct Data {int mode;size_t incr;size_t pool;Seg*seg;Block*free;};
struct Region {unsigned unknown[12];Data*data;};
// Shared allocator hooks: extension, truncation, page size, two helpers and allocation trace.
struct Hooks {Extend extend;void*truncate;size_t pagesize;void*helper0;void*helper1;Trace trace;};
extern Hooks lbl_80400768;
#define ALIGN 8
#define BITS 7
#define TRUST_MODE 1
#define TRACE_MODE 2
#define AGAIN_MODE 0x1000
#define LOCK_MODE 0x2000
#define POOLFREE 0x55555555 // marks a block held on the pool free list
#define ROUND(x,y) (((y)&((y)-1))?((((x)+((y)-1))/(y))*(y)):(((x)+((y)-1))&~((y)-1)))
extern "C" Block*mx14ob_pool_allocate_80216c4c(Region*vm,size_t size){
 Data*vd=vm->data;Block*tp;Block*next;size_t s;Seg*seg;int local;
 if(size<=0)return 0;
 if(!(local=vd->mode&TRUST_MODE)){
  if(vd->mode&LOCK_MODE)return 0;
  if(vd->pool>0&&size!=vd->pool)return 0;
  vd->mode|=LOCK_MODE;
 }
 // The first allocation fixes the element size and carves every segment free block.
 if(vd->pool<=0){
  vd->pool=size;size=ROUND(size,ALIGN);
  for(seg=vd->seg;seg;seg=seg->next){
   if(!(tp=seg->free))continue;
   seg->free=0;
   for(s=(tp->size&~BITS)+8;s>=size;s-=size){
    tp->size=POOLFREE;tp->link=vd->free;vd->free=tp;
    tp=(Block*)((unsigned char*)tp+size);
   }
  }
 }
 while(!(tp=vd->free)){
  if((tp=(*lbl_80400768.extend)(vm,ROUND(vd->pool,vd->incr),0))){
   size=ROUND(vd->pool,ALIGN);
   next=(Block*)((unsigned char*)tp+size);
   for(s=vd->seg->baddr-((unsigned char*)next+8);s>=size;s-=size){
    next->size=POOLFREE;next->link=vd->free;vd->free=next;
    next=(Block*)((unsigned char*)next+size);
   }
   goto done;
  }else if(vd->mode&AGAIN_MODE)vd->mode&=~AGAIN_MODE;
  else goto done;
 }
 vd->free=tp->link;
done:
 if(!local&&(vd->mode&TRACE_MODE)&&lbl_80400768.trace&&tp)
  (*lbl_80400768.trace)(vm,0,(unsigned char*)tp,vd->pool);
 vd->mode&=~LOCK_MODE;
 return tp;
}
