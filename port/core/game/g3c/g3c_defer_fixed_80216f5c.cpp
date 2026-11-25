#include "w3d_ptr.h"
#line 1 "g3c_defer_fixed_80216f5c.cpp"
// Inferred external heap state and free-block links. No local aggregate objects.
struct Heap;extern "C" int fn_80216e7c(Ptr32<Heap>,Ptr32<unsigned int>);
typedef Ptr32<void (Ptr32<Heap>, Ptr32<unsigned int>, int, unsigned int)> Notification;extern Notification callback_8040077c[];
inline Ptr32<unsigned int> state(Ptr32<Heap> heap){return *(Ptr32<Ptr32<unsigned int>>)((Ptr32<char>)heap+48);}
struct ErrorTable;typedef Ptr32<void (Ptr32<Heap>, int, Ptr32<unsigned int>, Ptr32<ErrorTable>)> Error;struct ErrorTable{Error unknown0,error;};
inline void report_bad(Ptr32<Heap> heap,Ptr32<unsigned int> payload){Ptr32<ErrorTable> callbacks=*(Ptr32<Ptr32<ErrorTable>>)((Ptr32<char>)heap+44);Error f=callbacks->error;if(f)f(heap,3,payload,callbacks);}
extern "C" int g3c_defer_fixed_80216f5c(Ptr32<Heap> heap,Ptr32<unsigned int> payload){
 Ptr32<unsigned int> pool=state(heap);
 if(payload){unsigned direct=pool[0]&1;
  if(!direct){if((pool[0]&0x2000)||pool[2]==0)return -1;pool[0]|=0x4000;if(fn_80216e7c(heap,payload)!=0){report_bad(heap,payload);return -1;}pool[0]|=0x2000;}
  payload[1]=0x55555555;payload[0]=pool[4];pool[4]=(unsigned)w3d::H(payload);
  if(!direct&&(pool[0]&2)&&callback_8040077c[0])callback_8040077c[0](heap,payload,0,pool[2]);
  if(!direct)pool[0]&=~0x2000U;
 }
 return 0;
}


