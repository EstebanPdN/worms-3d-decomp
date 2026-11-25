// External debug-heap views. Address arithmetic follows the32-bit guest ABI.
struct Heap;
extern "C" int g5c_debug_offset_80215e10(Heap* heap,unsigned address) {
 unsigned* state=*(unsigned**)((char*)heap+48);
 int result=-1;
 unsigned flags=state[0];
 unsigned nested=flags&0x4000;
 state[0]=flags&~0x4000U;
 if((!nested&&(flags&0x2000))||!address)return -1;
 if(!nested)state[0]=(flags&~0x4000U)|0x2000;
 unsigned region;
 for(region=state[3];region;region=*(unsigned*)(region+4)) {
  unsigned block=region+32;
  unsigned limit=*(unsigned*)(region+16)-8;
  if(block<address&&address<limit) {
   if(region) {
    if(!nested) {
     while(block<limit) {
      unsigned size=*(unsigned*)(block+4);
      if(block+8<=address&&address<block+8+size) {
       if((size&5)==1) {
        unsigned payload=block+24;
        if(payload<=address&&address<payload+*(unsigned*)(block+12))result=address-payload;
       }
       break;
      }
      block+=(size&~7U)+8;
     }
    }else if(*(unsigned*)(address-8)==region) {
     result=-2;
     if((*(unsigned*)(address-20)&5)==1)result=0;
    }
   }
   break;
  }
 }
 if(!nested)state[0]&=~0x2000U;
 return result;
}
