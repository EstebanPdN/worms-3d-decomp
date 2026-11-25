#include "w3d_ptr.h"
#line 1 "d24k_heap_resize_80213750.cpp"
// Heap reallocation (Worms 3D GameCube PAL, 0x80213750).
//
// dlmalloc-style realloc: a null block allocates (0x80212fd4); oversized requests
// set error 12 through 0x802eafc4 and return 0; memory-mapped blocks (bit 2) fail
// the same way. It grows into the top chunk or a free next chunk, else allocates
// a new chunk (absorbing it if adjacent), copies the words and frees the old
// block (0x802134fc). A spare tail of at least 16 bytes is split off and freed.
//
// The free after the copy sits in a do/while(0), as a dlmalloc-style macro would:
// it emits nothing but its loop depth weights the references to the block and
// gives the original's register order (block r28, request r27). Names are
// inferred from the dlmalloc family shape.
namespace d24k_heap_resize {
typedef unsigned int Size;
struct Chunk { Size previous,size; Ptr32<Chunk> forward; Ptr32<Chunk> back; };
extern "C" Ptr32<void> fn_80212fd4(Size);
extern "C" void fn_802134fc(Ptr32<void>);
extern "C" Ptr32<int> fn_802eafc4();
extern "C" Ptr32<Chunk> lbl_80463c4c[];
#define HEADER(p) reinterpret_cast<Chunk *>(w3d::R(reinterpret_cast<char *>(w3d::R(p))-8))
#define PAYLOAD(p) (reinterpret_cast<char *>(w3d::R(p))+8)
#define AT(p,n) reinterpret_cast<Chunk *>(w3d::R(reinterpret_cast<char *>(w3d::R(p))+(n)))
inline void copy_words(Ptr32<void> destination,Ptr32<void> source,Size bytes) {
 Size words=bytes/sizeof(Size);
 if(words>9) {
  Ptr32<Size> in=w3d::sc<Size *>(source);
  Ptr32<Size> out=w3d::sc<Size *>(destination);
  Size tail=bytes/sizeof(Size);int loops;
  if(tail<8)loops=0;
  else {loops=(tail-1)/8;tail%=8;}
  switch(tail) {
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
 } else {
  Ptr32<Size> out=w3d::sc<Size *>(destination); Ptr32<Size> in=w3d::sc<Size *>(source);
  out[0]=in[0];out[1]=in[1];out[2]=in[2];
  if(words>4) {
   out[3]=in[3];out[4]=in[4];
   if(words>6) {
    out[5]=in[5];out[6]=in[6];
    if(words>8) {out[7]=in[7];out[8]=in[8];}
   }
  }
 }
}
typedef char WordSize[(sizeof(Size)==4)?1:-1];
typedef char ChunkSize[(sizeof(Chunk)==16)?1:-1];
}
extern "C" Ptr32<void> w3d_d24k_heap_resize_80213750(Ptr32<void> memory,d24k_heap_resize::Size bytes) {
 using namespace d24k_heap_resize;
 Ptr32<Ptr32<Chunk>> bins=lbl_80463c4c;
 if(!memory)return fn_80212fd4(bytes);
 if(bytes>static_cast<Size>(-33))goto failed;
 {
 Size needed=(bytes+11<=15)?16:((bytes+11)&~7UL);
 Ptr32<Chunk> old=HEADER(memory);
 Size oldsize=old->size&~3UL,newsize;
 if(old->size&2)goto failed;
 if(oldsize>=needed)newsize=oldsize;
 else {
  Ptr32<Chunk> next=AT(old,oldsize);
  if(next==bins[11]) {
   if((newsize=oldsize+(next->size&~3UL))>=needed+16) {
    Ptr32<Chunk> newtop=AT(old,needed);
    old->size=(old->size&1)|needed;
    bins[11]=newtop;
    newtop->size=(newsize-needed)|1;
    return memory;
   }
  } else if((AT(next,next->size&~1UL)->size&1)==0 &&
            (newsize=oldsize+(next->size&~3UL))>=needed) {
   Ptr32<Chunk> forward=next->forward;
   Ptr32<Chunk> back=next->back;
   forward->back=back; back->forward=forward;
   goto split;
  }
  {
   Ptr32<void> fresh=fn_80212fd4(needed-7);
   if(!fresh)return 0;
   Ptr32<Chunk> newchunk=HEADER(fresh);
   newsize=newchunk->size&~3UL;
   if(newchunk==next) {newsize+=oldsize;goto split;}
   {
    copy_words(PAYLOAD(newchunk),memory,oldsize-4);
    do { fn_802134fc(memory); } while (0);
    return PAYLOAD(newchunk);
   }
  }
 }
split:
 Size spare=newsize-needed;
 if(spare<16) {
  old->size=(old->size&1)|newsize;
  AT(old,newsize)->size|=1;
 } else {
  Ptr32<Chunk> remainder=AT(old,needed);
  old->size=(old->size&1)|needed;
  remainder->size=spare|1;
  AT(remainder,spare)->size|=1;
  fn_802134fc(PAYLOAD(remainder));
 }
 return PAYLOAD(old);
 }
failed:
 *fn_802eafc4()=12;return 0;
}


