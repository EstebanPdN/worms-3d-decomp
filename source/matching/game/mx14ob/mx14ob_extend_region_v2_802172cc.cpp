// Provenance: adapted from the author's recollection of AT&T AST vmalloc vmextend
// (vmprivate.c, Kiem-Phong Vo, AT&T). No upstream file was consulted or copied; the
// control flow, local names and macro names follow that recalled upstream routine and
// were checked against the original instructions at 0x802172cc. The upstream license
// notice is not available in this project and is an open obligation (see report mx14ob).
// All layout types are external observed prefixes for the 32-bit reference target, never
// local complete objects. Portability: the alignment test reduces the address through
// size_t, and the exception callback receives the size in its pointer payload.
typedef unsigned long size_t;
struct Region;struct Disc;struct Data;struct Seg;struct Block;
typedef void*(*Memory)(Region*,void*,size_t,size_t,Disc*);
typedef int(*Except)(Region*,int,void*,Disc*);
typedef Block*(*Search)(Data*,size_t,Block*);
// Observed block header: owning segment, size with low status bits, free links.
struct Block {Seg*seg;size_t size;Block*link;Block*left;Block*right;Block**self;};
struct Seg {Region*vm;Seg*next;void*addr;size_t extent;unsigned char*baddr;size_t size;Block*free;};
// mode, rounding increment, unknown word, segment list, unknown word, wilderness block,
// unknown word, tiny free lists and delayed-free cache.
struct Data {int mode;size_t incr;size_t unknown0;Seg*seg;Block*unknown1;Block*wild;Block*unknown2;Block*tiny[7];Block*cache[8];};
struct Disc {Memory memoryf;Except exceptf;size_t round;};
struct Region {unsigned unknown[11];Disc*disc;Data*data;};
extern size_t lbl_80400770[]; // page size
#define ALIGN 8
#define BUSY 1
#define PFREE 2
#define JUNK 4
#define MULTI_MODES 0x640 // best/debug/profile methods
#define LOCK_MODE 0x2000
#define AGAIN_MODE 0x1000
#define NO_MEMORY 2
#define ROUND(x,y) (((y)&((y)-1))?((((x)+((y)-1))/(y))*(y)):(((x)+((y)-1))&~((y)-1)))
#define SEGBLOCK(s) ((Block*)((unsigned char*)(s)+32))
#define NEXT(b) ((Block*)((unsigned char*)&(b)->link+(b)->size)) // data area plus size
#define LAST(b) (*((Block**)((unsigned char*)(b)-sizeof(Block*))))
#define BLOCK(a) ((Block*)((unsigned char*)(a)-sizeof(Seg*)-sizeof(size_t)))
#define INDEX(s) (((s)-8)/ALIGN)
#define C_INDEX(s) ((s)<64?INDEX(s):7)
extern "C" Block*mx14ob_extend_region_v2_802172cc(Region*vm,size_t size,Search searchf){
 size_t s;Seg*seg;Block*bp;Block*t;unsigned char*addr;
 Data*vd=vm->data;Memory memoryf=vm->disc->memoryf;Except exceptf=vm->disc->exceptf;
 lbl_80400770[0]=8192;
 if(vd->incr<=0)vd->incr=lbl_80400770[0];
 // Room for the segment header, first block, trailing header and alignment slack.
 s=size+sizeof(Seg)+sizeof(Block)+8+2*ALIGN;
 if(s<=size)return 0;
 if((size=ROUND(s,vd->incr))<s)return 0;
 if(!(seg=vd->seg))addr=0;
 else{
  if(!vd->wild||vd->wild->seg!=seg)s=0;
  else{s=vd->wild->size+8;if((s=(s/vd->incr)*vd->incr)==size)size+=vd->incr;}
  addr=(unsigned char*)(*memoryf)(vm,seg->addr,seg->extent,seg->extent+size-s,vm->disc);
  if(!addr)seg=0;
  else{addr+=seg->extent;size-=s;}
 }
 while(!addr){
  if((addr=(unsigned char*)(*memoryf)(vm,0,0,size,vm->disc)))break;
  if(!exceptf)return 0;
  else{
   int rv,lock;
   lock=vd->mode&LOCK_MODE;vd->mode&=~LOCK_MODE;
   rv=(*exceptf)(vm,NO_MEMORY,(void*)size,vm->disc);
   vd->mode|=lock;
   if(rv<=0){if(rv==0)vd->mode|=AGAIN_MODE;return 0;}
  }
 }
 if(seg){
  bp=BLOCK(seg->baddr);
  if(vd->mode&MULTI_MODES){
   if(!(bp->size&PFREE))bp->size=size-8;
   else{
    bp=LAST(bp);
    if(bp==vd->wild)vd->wild=0;
    else if(bp->size!=8&&bp->right==bp){
     if((t=bp->link))t->left=bp->left;
     if((t=bp->left))t->link=bp->link;else vd->tiny[INDEX(bp->size)]=bp->link;
    }else(*searchf)(vd,bp->size,bp);
    bp->size+=size;
   }
  }else{
   if(seg->free){bp=seg->free;seg->free=0;bp->size+=size;}
   else bp->size=size-8;
  }
  seg->size+=size;seg->extent+=size;seg->baddr+=size;
 }else{
  Seg*sp;Seg*lastsp;
  if((s=(size_t)addr%ALIGN)!=0)addr+=ALIGN-s;
  seg=(Seg*)addr;
  seg->vm=vm;
  seg->addr=(void*)(addr-(s?ALIGN-s:0));
  seg->extent=size;
  seg->baddr=addr+size;
  if(s)seg->baddr-=2*ALIGN;
  seg->free=0;
  bp=SEGBLOCK(seg);
  bp->seg=seg;
  bp->size=seg->baddr-(unsigned char*)bp-2*8;
  // Multi-method regions keep segments in descending address order.
  lastsp=0;sp=vd->seg;
  if(vd->mode&MULTI_MODES)
   for(;sp;lastsp=sp,sp=sp->next)if(seg->addr>sp->addr)break;
  seg->next=sp;
  if(lastsp)lastsp->next=seg;else vd->seg=seg;
  seg->size=bp->size;
 }
 // Busy trailer header so the segment end is never coalesced.
 t=NEXT(bp);t->seg=seg;t->size=BUSY;
 // A wilderness block left in an older segment is retired to the cache or segment free slot.
 if((t=vd->wild)&&(seg=t->seg)!=vd->seg){
  NEXT(t)->size&=~PFREE;
  if(vd->mode&MULTI_MODES){
   t->size|=BUSY|JUNK;
   t->link=vd->cache[C_INDEX(t->size)];
   vd->cache[C_INDEX(t->size)]=t;
  }else seg->free=t;
  vd->wild=0;
 }
 return bp;
}
