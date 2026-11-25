// Inferred heap and block views. All storage belongs to external runtime objects.
struct Heap;extern "C" int fn_80214718(Heap*,unsigned*);extern "C" void*memset(void*,int,unsigned);
typedef void(*Notification)(Heap*,unsigned*,int,unsigned);extern Notification callback_8040077c[];
inline unsigned*state(Heap*heap){return *(unsigned**)((char*)heap+48);}
extern "C" int g3c_defer_free_80214894(Heap*heap,unsigned*payload){
 unsigned*pool=state(heap);if(!payload)return 0;
 unsigned direct=pool[0]&1;
 if(!direct){if(pool[0]&0x2000)return -1;pool[0]|=0x4000;if(fn_80214718(heap,payload)!=0)return -1;pool[0]|=0x2000;}
 unsigned*block=payload-2;block[1]|=4;memset(payload,0xdd,block[1]-8);
 if(block[1]<64){unsigned offset=(((block[1]-8)>>1)&0x7ffffffc)+56;unsigned*head=(unsigned*)((char*)pool+offset);block[2]=*head;*head=(unsigned)block;}
 else if(pool[4]==0)pool[4]=(unsigned)block;
 else{block[2]=pool[21];pool[21]=(unsigned)block;}
 if(!direct&&callback_8040077c[0]&&(pool[0]&0x7c2)==0x42)callback_8040077c[0](heap,payload,0,payload[-1]&~7U);
 pool[0]&=~0x2000U;return 0;
}
