#include "w3d_ptr.h"
#line 1 "g3c_flush_pending_802171ec.cpp"
// Inferred runtime owner and pending-region views; no local aggregate storage is constructed.
struct Heap;typedef Ptr32<int (Ptr32<Heap>, Ptr32<unsigned int>, unsigned int, int)> ReleaseRegion;struct Callbacks{Ptr32<void> unknown0;ReleaseRegion release;};extern Callbacks callbacks_80400768[];
inline Ptr32<unsigned int> state(Ptr32<Heap> heap){return *(Ptr32<Ptr32<unsigned int>>)((Ptr32<char>)heap+48);}
extern "C" int g3c_flush_pending_802171ec(Ptr32<Heap> heap){
 Ptr32<unsigned int> pool=state(heap);unsigned flags=pool[0];
 if((flags&1)==0){if(flags&0x2000)return -1;pool[0]=flags|0x2000;}
 for(Ptr32<unsigned int> region=(Ptr32<unsigned int>)w3d::G(pool[3]);region;){
  Ptr32<unsigned int> pending=(Ptr32<unsigned int>)w3d::G(region[6]);Ptr32<unsigned int> next=(Ptr32<unsigned int>)w3d::G(region[1]);
  if(pending){region[6]=0;unsigned size=pending[1]&~7U;
   if(region[5]==size)size=region[3];else size+=8;
   if(callbacks_80400768[0].release(heap,region,size,1)<0)region[6]=(unsigned)w3d::H(pending);
  }
  region=next;
 }
 pool[0]&=~0x2000U;return 0;
}


