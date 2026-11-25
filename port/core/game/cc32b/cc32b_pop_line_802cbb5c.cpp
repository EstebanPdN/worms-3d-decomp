#include "w3d_ptr.h"
#line 1 "cc32b_pop_line_802cbb5c.cpp"
typedef unsigned int cc32b_u32;
extern "C" {
extern int lbl_804abce4;
extern char lbl_80473624[];
Ptr32<void> fn_802ef2fc(Ptr32<char>,Ptr32<const char>);
void fn_8020bb2c(Ptr32<void>);
void fn_8020c5c4(Ptr32<void>);
void fn_80341588(Ptr32<void>);
}
inline void cc32b_release_header_802cbb5c(Ptr32<unsigned short> header) { if(--*header==0) fn_8020bb2c(header); }
struct Cc32bQueueString_802cbb5c {
 Ptr32<char> text;
 Cc32bQueueString_802cbb5c &operator=(const Cc32bQueueString_802cbb5c &other) {
  ++*(Ptr32<unsigned short>)(other.text-6);
  Ptr32<char> old=text;
  cc32b_release_header_802cbb5c((Ptr32<unsigned short>)(old-6));
  text=other.text; return *this;
 }
 ~Cc32bQueueString_802cbb5c(){fn_8020c5c4(this);fn_80341588(this);}
};
struct Cc32bQueue_802cbb5c {
 Ptr32<Cc32bQueueString_802cbb5c> begin; Ptr32<Cc32bQueueString_802cbb5c> end; Ptr32<Cc32bQueueString_802cbb5c> capacity; cc32b_u32 opaque;
};
extern "C" Cc32bQueue_802cbb5c lbl_804737a4[];
inline void cc32b_copy_queue_range_802cbb5c(Ptr32<Cc32bQueueString_802cbb5c> source,Ptr32<Cc32bQueueString_802cbb5c> end,Ptr32<Cc32bQueueString_802cbb5c> destination) {
 int count=end-source; for(;count>0;--count) { *destination=*source; ++source; ++destination; }
}
extern "C" Ptr32<char> w3d_cc32b_pop_line_802cbb5c(cc32b_u32 index) {
 if(!lbl_804abce4 || index>=16) return 0;
 Ptr32<Cc32bQueue_802cbb5c> queue=(Ptr32<Cc32bQueue_802cbb5c>)((index<<4)+(Ptr32<char>)lbl_804737a4);
 if(!(((cc32b_u32)w3d::H(queue->end)-(cc32b_u32)w3d::H(queue->begin))>>2)) return 0;
 {
  fn_802ef2fc(lbl_80473624,queue->begin->text);
  if(queue->begin+1!=queue->end) cc32b_copy_queue_range_802cbb5c(queue->begin+1,queue->end,queue->begin);
  --queue->end;
  queue->end->~Cc32bQueueString_802cbb5c();
  return lbl_80473624;
 }
 return 0;
}


