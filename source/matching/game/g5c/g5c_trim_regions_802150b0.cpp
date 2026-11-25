// External native runtime state and variable chunk metadata; no local objects.
struct Heap;
extern "C" int fn_80213f98(unsigned*,unsigned*,unsigned);
extern "C" unsigned* fn_80213d90(unsigned*,unsigned,unsigned*);
typedef int(*ReleaseRegion)(Heap*,unsigned*,unsigned,int);
struct Callbacks {void* acquire;ReleaseRegion release;};
extern Callbacks callbacks_80400768[];
inline unsigned bucketOffset(unsigned size){return ((size-8)>>1)&0x7ffffffc;}
extern "C" int g5c_trim_regions_802150b0(Heap* heap) {
 unsigned* pool=*(unsigned**)((char*)heap+48);
 unsigned flags=pool[0];
 if(!(flags&1)){if(flags&0x2000)return -1;pool[0]=flags|0x2000;}
 fn_80213f98(pool,0,0);
 unsigned* next=(unsigned*)pool[3];
 while(next) {
  unsigned* region=next;
  next=(unsigned*)region[1];
  if(*(unsigned*)(region[4]-4)&2) {
   unsigned* block=*(unsigned**)(region[4]-12);
   unsigned size=block[1];
   if((unsigned)block+size+16<*(unsigned*)(pool[3]+16)) {
    if(size==8||(unsigned*)block[4]!=block)fn_80213d90(pool,block[1],block);
    else {
     if(block[2])*(unsigned*)(block[2]+12)=block[3];
     if(!block[3])*(unsigned*)((char*)pool+28+bucketOffset(size))=block[2];
     else *(unsigned*)(block[3]+8)=block[2];
    }
   }else pool[5]=0;
   *(unsigned*)((char*)block+block[1]+12)&=~2U;
   if(size<region[5])size+=8;
   if(callbacks_80400768[0].release(heap,region,size,1)>=0) {
    unsigned remaining=region[4]-(unsigned)block;
    if(remaining==8)block=0;
    else block[1]=remaining-16;
   }
   if(block) {
    block[1]|=5;
    unsigned offset=block[1]<64?bucketOffset(block[1]):28;
    block[2]=*(unsigned*)((char*)pool+56+offset);
    offset=block[1]<64?bucketOffset(block[1]):28;
    *(unsigned*)((char*)pool+56+offset)=(unsigned)block;
   }
  }
 }
 pool[0]&=~0x2000U;
 return 0;
}
