// Inferred native dlmalloc-family aligned-allocation flow. The retained
// newlib mallocr.c memalign algorithm is a structural comparison, not an
// identification of this binary's exact allocator release/configuration.
namespace sol35d7_aligned_allocate {
typedef unsigned long Size;
struct Chunk {Size previous,size;};
extern "C" void *fn_80212fd4(Size);
extern "C" void fn_802134fc(void *);
extern "C" int *fn_802eafc4();
inline Chunk *header(void *p){return reinterpret_cast<Chunk *>(static_cast<char *>(p)-8);}
inline void *payload(Chunk *p){return reinterpret_cast<char *>(p)+8;}
inline Chunk *at(Chunk *p,Size n){return reinterpret_cast<Chunk *>(reinterpret_cast<char *>(p)+n);}
typedef char ChunkSize[(sizeof(Chunk)==8)?1:-1];
}
extern "C" void *sol35d7_aligned_allocate_80213a8c(sol35d7_aligned_allocate::Size alignment,sol35d7_aligned_allocate::Size bytes) {
 using namespace sol35d7_aligned_allocate;
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
 void *memory=fn_80212fd4(n+alignment+16);
 if(!memory)return 0;
 Chunk *p=header(memory);
 if(reinterpret_cast<Size>(memory)%alignment!=0) {
  Chunk *next=header(reinterpret_cast<void *>((reinterpret_cast<Size>(memory)+alignment-1)&-alignment));
  if(static_cast<Size>(reinterpret_cast<char *>(next)-reinterpret_cast<char *>(p))<16)
   next=at(next,alignment);
  Size lead=reinterpret_cast<char *>(next)-reinterpret_cast<char *>(p);
  Size remaining=(p->size&~3UL)-lead;
  if(p->size&2) {
   next->size=remaining|2;
   next->previous=p->previous+lead;
   return payload(next);
  }
  next->size=remaining|1;
  at(next,remaining)->size|=1;
  p->size=(p->size&1)|lead;
  fn_802134fc(payload(p));
  p=next;
 }
 if(!(p->size&2)) {
  Size length=p->size&~3UL;
  if(n+16<length) {
   Chunk *remainder=at(p,n);
   remainder->size=(length-n)|1;
   p->size=(p->size&1)|n;
   fn_802134fc(payload(remainder));
  }
 }
 return payload(p);
}
