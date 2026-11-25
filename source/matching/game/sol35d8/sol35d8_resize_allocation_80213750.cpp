// Native GC32 allocation resize. Names and dlmalloc-family identity inferred;
// only the original instruction/caller contracts establish this partial view.
namespace sol35d8_resize_allocation {
typedef unsigned long Size;
struct Chunk { Size previous,size; Chunk *forward,*back; };
extern "C" void *fn_80212fd4(Size);
extern "C" void fn_802134fc(void *);
extern "C" int *fn_802eafc4();
extern "C" Chunk *lbl_80463c4c[];
#define HEADER(p) reinterpret_cast<Chunk *>(reinterpret_cast<char *>(p)-8)
#define PAYLOAD(p) (reinterpret_cast<char *>(p)+8)
#define AT(p,n) reinterpret_cast<Chunk *>(reinterpret_cast<char *>(p)+(n))
inline void copy_words(void *destination,void *source,Size bytes) {
 Size *out=static_cast<Size *>(destination),*in=static_cast<Size *>(source);
 Size words=bytes/sizeof(Size);
 if(words<=9) {
  *out++=*in++; *out++=*in++; *out++=*in++;
  if(words>4) {
   *out++=*in++; *out++=*in++;
   if(words>6) {
    *out++=*in++; *out++=*in++;
    if(words>8) { *out++=*in++; *out=*in; }
   }
  }
 } else {
  long loops;
  if(words<8)loops=0;
  else {loops=(words-1)/8;words%=8;}
  switch(words) {
   case 0: for(;;) { *out++=*in++;
   case 7: *out++=*in++;
   case 6: *out++=*in++;
   case 5: *out++=*in++;
   case 4: *out++=*in++;
   case 3: *out++=*in++;
   case 2: *out++=*in++;
   case 1: *out++=*in++;if(loops<=0)break;--loops;
   }
  }
 }
}
typedef char WordSize[(sizeof(Size)==4)?1:-1];
typedef char ChunkSize[(sizeof(Chunk)==16)?1:-1];
}
extern "C" void *sol35d8_resize_allocation_80213750(void *memory,sol35d8_resize_allocation::Size bytes) {
 using namespace sol35d8_resize_allocation;
 if(!memory)return fn_80212fd4(bytes);
 if(bytes>static_cast<Size>(-33)) { *fn_802eafc4()=12;return 0; }
 Size needed=(bytes+11<=15)?16:((bytes+11)&~7UL);
 Chunk *old=HEADER(memory);
 Size oldsize=old->size&~3UL,newsize;
 if(old->size&2) { *fn_802eafc4()=12;return 0; }
 if(oldsize>=needed)newsize=oldsize;
 else {
  Chunk *next=AT(old,oldsize);
  if(next==lbl_80463c4c[11]) {
   if((newsize=oldsize+(next->size&~3UL))>=needed+16) {
    lbl_80463c4c[11]=AT(old,needed);
    old->size=(old->size&1)|needed;
    lbl_80463c4c[11]->size=(newsize-needed)|1;
    return memory;
   }
  } else if(!(AT(next,next->size&~1UL)->size&1) &&
            (newsize=oldsize+(next->size&~3UL))>=needed) {
   Chunk *back=next->back,*forward=next->forward;
   forward->back=back; back->forward=forward;
   goto split;
  }
  {
   void *fresh=fn_80212fd4(needed-7);
   if(!fresh)return 0;
   Chunk *newchunk=HEADER(fresh);
   newsize=newchunk->size&~3UL;
   if(newchunk!=next) {
    copy_words(fresh,memory,oldsize-4);
    fn_802134fc(memory);
    return fresh;
   }
   newsize+=oldsize;
  }
 }
split:
 Size spare=newsize-needed;
 if(spare<16) {
  old->size=(old->size&1)|newsize;
  AT(old,newsize)->size|=1;
 } else {
  Chunk *remainder=AT(old,needed);
  old->size=(old->size&1)|needed;
  remainder->size=spare|1;
  AT(remainder,spare)->size|=1;
  fn_802134fc(PAYLOAD(remainder));
 }
 return PAYLOAD(old);
}
