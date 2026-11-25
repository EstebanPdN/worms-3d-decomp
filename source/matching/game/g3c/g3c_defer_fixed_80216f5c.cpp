// Inferred external heap state and free-block links. No local aggregate objects.
struct Heap;extern "C" int fn_80216e7c(Heap*,unsigned*);
typedef void(*Notification)(Heap*,unsigned*,int,unsigned);extern Notification callback_8040077c[];
inline unsigned*state(Heap*heap){return *(unsigned**)((char*)heap+48);}
struct ErrorTable;typedef void(*Error)(Heap*,int,unsigned*,ErrorTable*);struct ErrorTable{Error unknown0,error;};
inline void report_bad(Heap*heap,unsigned*payload){ErrorTable*callbacks=*(ErrorTable**)((char*)heap+44);Error f=callbacks->error;if(f)f(heap,3,payload,callbacks);}
extern "C" int g3c_defer_fixed_80216f5c(Heap*heap,unsigned*payload){
 unsigned*pool=state(heap);
 if(payload){unsigned direct=pool[0]&1;
  if(!direct){if((pool[0]&0x2000)||pool[2]==0)return -1;pool[0]|=0x4000;if(fn_80216e7c(heap,payload)!=0){report_bad(heap,payload);return -1;}pool[0]|=0x2000;}
  payload[1]=0x55555555;payload[0]=pool[4];pool[4]=(unsigned)payload;
  if(!direct&&(pool[0]&2)&&callback_8040077c[0])callback_8040077c[0](heap,payload,0,pool[2]);
  if(!direct)pool[0]&=~0x2000U;
 }
 return 0;
}
