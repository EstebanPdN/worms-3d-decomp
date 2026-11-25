// Native allocator boundary, using explicit byte cursors for variable chunks.
extern "C" void* fn_80212fd4(unsigned);
extern "C" void fn_802134fc(void*);
extern "C" int* fn_802eafc4();
inline unsigned& chunkSize(unsigned char* chunk){return *(unsigned*)(chunk+4);}
extern "C" void* g5c_aligned_allocate_80213a8c(unsigned alignment,unsigned bytes) {
 if(alignment<=8)return fn_80212fd4(bytes);
 if(alignment<16)alignment=16;
 if(alignment&(alignment-1)) {
  unsigned power=16;
  while(power<alignment)power<<=1;
  alignment=power;
 }
 if(bytes>=0xffffffe0U){*fn_802eafc4()=12;return 0;}
 unsigned padded=16;
 if(bytes+11>15)padded=(bytes+11)&~7U;
 unsigned char* memory=(unsigned char*)fn_80212fd4(padded+alignment+16);
 if(!memory)return 0;
 unsigned char* chunk=memory-8;
 if((unsigned)memory%alignment) {
  unsigned char* aligned=(unsigned char*)(((unsigned)memory+alignment-1)&-alignment)-8;
  if((unsigned)(aligned-chunk)<16)aligned+=alignment;
  unsigned lead=aligned-chunk;
  unsigned remaining=(chunkSize(chunk)&~3U)-lead;
  if(chunkSize(chunk)&2) {
   unsigned previous=*(unsigned*)(memory-8);
   chunkSize(aligned)=remaining|2;
   *(unsigned*)aligned=previous+lead;
   return aligned+8;
  }
  chunkSize(aligned)=remaining|1;
  chunkSize(aligned+remaining)|=1;
  chunkSize(chunk)=(chunkSize(chunk)&1)|lead;
  fn_802134fc(memory);
  chunk=aligned;
 }
 if(!(chunkSize(chunk)&2)) {
  unsigned available=chunkSize(chunk)&~3U;
  if(padded+16<available) {
   chunkSize(chunk+padded)=(available-padded)|1;
   chunkSize(chunk)=(chunkSize(chunk)&1)|padded;
   fn_802134fc(chunk+padded+8);
  }
 }
 return chunk+8;
}
