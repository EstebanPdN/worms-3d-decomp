#include "w3d_ptr.h"
#line 1 "sol35d7_aligned_allocate_80213a8c_v2.cpp"
// Inferred native dlmalloc-family aligned-allocation flow. The retained
// newlib mallocr.c memalign algorithm is a structural comparison, not an
// identification of this binary's exact allocator release/configuration.
namespace sol35d7_aligned_allocate_v2 {
typedef unsigned int Size;
struct Chunk {Size previous,size;};
extern "C" Ptr32<void> fn_80212fd4(Size);
extern "C" void fn_802134fc(Ptr32<void>);
extern "C" Ptr32<int> fn_802eafc4();
#define HEADER(p) reinterpret_cast<Chunk *>(w3d::R(reinterpret_cast<char *>(w3d::R(p))-8))
#define PAYLOAD(p) (reinterpret_cast<char *>(w3d::R(p))+8)
#define AT(p,n) reinterpret_cast<Chunk *>(w3d::R(reinterpret_cast<char *>(w3d::R(p))+(n)))
typedef char ChunkSize[(sizeof(Chunk)==8)?1:-1];
}
extern "C" Ptr32<void> sol35d7_aligned_allocate_80213a8c_v2(sol35d7_aligned_allocate_v2::Size alignment,sol35d7_aligned_allocate_v2::Size bytes) {
 using namespace sol35d7_aligned_allocate_v2;
 if(alignment<=8)return fn_80212fd4(bytes);
 if(alignment<16)alignment=16;
 if((alignment&(alignment-1))!=0) {
  Size rounded=16;
  while(rounded<alignment)rounded<<=1;
  alignment=rounded;
 }
 if(bytes>static_cast<Size>(-33)) {
  *fn_802eafc4()=12;
  return 0;
 }
 Size n=(bytes+11<=15)?16:((bytes+11)&~7UL);
 Ptr32<char> memory=w3d::sc<char *>(fn_80212fd4(n+alignment+16));
 if(!memory)return 0;
 Ptr32<Chunk> p=HEADER(memory);
 if(reinterpret_cast<Size>(w3d::R(w3d::H(memory)))%alignment!=0) {
  Ptr32<Chunk> next=HEADER(reinterpret_cast<void *>(w3d::R(w3d::G((reinterpret_cast<Size>(w3d::R(w3d::H(memory)))+alignment-1)&-alignment))));
  if(static_cast<Size>(reinterpret_cast<char *>(w3d::R(next))-reinterpret_cast<char *>(w3d::R(p)))<16)
   next=AT(next,alignment);
  Size lead=reinterpret_cast<char *>(w3d::R(next))-reinterpret_cast<char *>(w3d::R(p));
  Size remaining=(p->size&~3UL)-lead;
  if(p->size&2) {
   next->previous=p->previous+lead;
   next->size=remaining|2;
   return PAYLOAD(next);
  }
  next->size=remaining|1;
  AT(next,remaining)->size|=1;
  p->size=(p->size&1)|lead;
  fn_802134fc(memory);
  p=next;
 }
 if(!(p->size&2)) {
  Size length=p->size&~3UL;
  if(length>n+16) {
   Ptr32<Chunk> remainder=AT(p,n);
   remainder->size=(length-n)|1;
   p->size=(p->size&1)|n;
   fn_802134fc(PAYLOAD(remainder));
  }
 }
 return PAYLOAD(p);
}


