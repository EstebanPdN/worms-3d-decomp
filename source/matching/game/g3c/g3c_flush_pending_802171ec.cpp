// Inferred runtime owner and pending-region views; no local aggregate storage is constructed.
struct Heap;typedef int(*ReleaseRegion)(Heap*,unsigned*,unsigned,int);struct Callbacks{void*unknown0;ReleaseRegion release;};extern Callbacks callbacks_80400768[];
inline unsigned*state(Heap*heap){return *(unsigned**)((char*)heap+48);}
extern "C" int g3c_flush_pending_802171ec(Heap*heap){
 unsigned*pool=state(heap);unsigned flags=pool[0];
 if((flags&1)==0){if(flags&0x2000)return -1;pool[0]=flags|0x2000;}
 for(unsigned*region=(unsigned*)pool[3];region;){
  unsigned*pending=(unsigned*)region[6];unsigned*next=(unsigned*)region[1];
  if(pending){region[6]=0;unsigned size=pending[1]&~7U;
   if(region[5]==size)size=region[3];else size+=8;
   if(callbacks_80400768[0].release(heap,region,size,1)<0)region[6]=(unsigned)pending;
  }
  region=next;
 }
 pool[0]&=~0x2000U;return 0;
}
