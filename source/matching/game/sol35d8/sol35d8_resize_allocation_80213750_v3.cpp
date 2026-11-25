// Native GC32 allocation resize. Names and dlmalloc-family identity inferred;
// only the original instruction/caller contracts establish this partial view.
namespace sol35d8_resize_allocation_v3 {
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
 Size words=bytes/sizeof(Size);
 if(words>9) {
  Size *in=static_cast<Size *>(source);
  Size *out=static_cast<Size *>(destination);
  Size tail=bytes/sizeof(Size);long loops;
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
  Size *out=static_cast<Size *>(destination),*in=static_cast<Size *>(source);
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
extern "C" void *sol35d8_resize_allocation_80213750_v3(void *memory,sol35d8_resize_allocation_v3::Size bytes) {
 using namespace sol35d8_resize_allocation_v3;
 Chunk **bins=lbl_80463c4c;
 if(!memory)return fn_80212fd4(bytes);
 if(bytes>static_cast<Size>(-33))goto failed;
 {
 Chunk *old=HEADER(memory);
 Size needed=(bytes+11<=15)?16:((bytes+11)&~7UL);
 Size oldsize=old->size&~3UL,newsize;
 if(old->size&2)goto failed;
 if(oldsize>=needed)newsize=oldsize;
 else {
  Chunk *next=AT(old,oldsize);
  if(next==bins[11]) {
   if((newsize=oldsize+(next->size&~3UL))>=needed+16) {
    Chunk *newtop=AT(old,needed);
    old->size=(old->size&1)|needed;
    bins[11]=newtop;
    newtop->size=(newsize-needed)|1;
    return memory;
   }
  } else if((AT(next,next->size&~1UL)->size&1)==0 &&
            (newsize=oldsize+(next->size&~3UL))>=needed) {
   Chunk *back=next->back;
   Chunk *forward=next->forward;
   forward->back=back; back->forward=forward;
   goto split;
  }
  {
   void *fresh=fn_80212fd4(needed-7);
   if(!fresh)return 0;
   Chunk *newchunk=HEADER(fresh);
   newsize=newchunk->size&~3UL;
   if(newchunk==next) {newsize+=oldsize;goto split;}
   {
    copy_words(PAYLOAD(newchunk),memory,oldsize-4);
    fn_802134fc(memory);
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
  Chunk *remainder=AT(old,needed);
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
