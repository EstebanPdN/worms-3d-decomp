// External debug-heap views. Address arithmetic follows the32-bit guest ABI.
struct Heap;
struct BlockHeader {unsigned region,size;};
extern "C" int g5c_debug_offset_80215e10(Heap* heap,unsigned address) {
 unsigned* state=*(unsigned**)((char*)heap+48);
 int result=-1;
 unsigned flags=state[0];
 unsigned nested=flags&0x4000;
 state[0]=flags&~0x4000U;
 if((!nested&&(flags&0x2000))||!address)return -1;
 if(!nested)state[0]=(flags&~0x4000U)|0x2000;
 unsigned region=state[3],limit;
 BlockHeader* block;
 for(;region;region=*(unsigned*)(region+4)) {
  block=(BlockHeader*)(region+32);
  limit=*(unsigned*)(region+16)-8;
  if(address>(unsigned)block&&address<limit)break;
 }
 if(region) {
  if(nested) {
   if(*(unsigned*)(address-8)==region) {
    result=-2;
    if((*(unsigned*)(address-20)&5)==1)result=0;
   }
  }else {
   if((unsigned)block<limit) do {
    unsigned size=block->size;
    unsigned data=(unsigned)(block+1);
    if(address>=data&&address<data+size) {
     if((size&5)==1) {
      unsigned payload=(unsigned)(block+3);
      if(address>=payload&&address<payload+*(unsigned*)(payload-12))result=address-payload;
     }
     break;
    }
    block+=(size>>3)+1;
   }while((unsigned)block<limit);
  }
 }
 if(!nested)state[0]&=~0x2000U;
 return result;
}
