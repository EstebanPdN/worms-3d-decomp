#include "w3d_ptr.h"
#line 1 "g3c_defer_free_80214894.cpp"
// Inferred heap and block views. All storage belongs to external runtime objects.
struct Heap;extern "C" int fn_80214718(Ptr32<Heap>,Ptr32<unsigned int>);extern "C" Ptr32<void> memset(Ptr32<void>,int,unsigned);
typedef Ptr32<void (Ptr32<Heap>, Ptr32<unsigned int>, int, unsigned int)> Notification;extern Notification callback_8040077c[];
inline Ptr32<unsigned int> state(Ptr32<Heap> heap){return *(Ptr32<Ptr32<unsigned int>>)((Ptr32<char>)heap+48);}
extern "C" int g3c_defer_free_80214894(Ptr32<Heap> heap,Ptr32<unsigned int> payload){
 Ptr32<unsigned int> pool=state(heap);if(!payload)return 0;
 unsigned direct=pool[0]&1;
 if(!direct){if(pool[0]&0x2000)return -1;pool[0]|=0x4000;if(fn_80214718(heap,payload)!=0)return -1;pool[0]|=0x2000;}
 Ptr32<unsigned int> block=payload-2;block[1]|=4;memset(payload,0xdd,block[1]-8);
 if(block[1]<64){unsigned offset=(((block[1]-8)>>1)&0x7ffffffc)+56;Ptr32<unsigned int> head=(Ptr32<unsigned int>)((Ptr32<char>)pool+offset);block[2]=*head;*head=(unsigned)w3d::H(block);}
 else if(pool[4]==0)pool[4]=(unsigned)w3d::H(block);
 else{block[2]=pool[21];pool[21]=(unsigned)w3d::H(block);}
 if(!direct&&callback_8040077c[0]&&(pool[0]&0x7c2)==0x42)callback_8040077c[0](heap,payload,0,payload[-1]&~7U);
 pool[0]&=~0x2000U;return 0;
}


