typedef unsigned int cc32b_u32;
extern "C" {
extern int lbl_804abce4;
extern char lbl_80473624[];
void *fn_802ef2fc(char *,const char *);
void fn_8020bb2c(void *);
void fn_8020c5c4(void *);
void fn_80341588(void *);
}
inline void cc32b_release_header_802cbb5c(unsigned short *header) { if(--*header==0) fn_8020bb2c(header); }
struct Cc32bQueueString_802cbb5c {
 char *text;
 Cc32bQueueString_802cbb5c &operator=(const Cc32bQueueString_802cbb5c &other) {
  ++*(unsigned short*)(other.text-6);
  char *old=text;
  cc32b_release_header_802cbb5c((unsigned short*)(old-6));
  text=other.text; return *this;
 }
 ~Cc32bQueueString_802cbb5c(){fn_8020c5c4(this);fn_80341588(this);}
};
struct Cc32bQueue_802cbb5c {
 Cc32bQueueString_802cbb5c *begin,*end,*capacity; cc32b_u32 opaque;
};
extern "C" Cc32bQueue_802cbb5c lbl_804737a4[];
inline void cc32b_copy_queue_range_802cbb5c(Cc32bQueueString_802cbb5c *source,Cc32bQueueString_802cbb5c *end,Cc32bQueueString_802cbb5c *destination) {
 int count=end-source; for(;count>0;--count) { *destination=*source; ++source; ++destination; }
}
extern "C" char *w3d_cc32b_pop_line_802cbb5c(cc32b_u32 index) {
 if(!lbl_804abce4 || index>=16) return 0;
 Cc32bQueue_802cbb5c *queue=(Cc32bQueue_802cbb5c*)((index<<4)+(char*)lbl_804737a4);
 if(!(((cc32b_u32)queue->end-(cc32b_u32)queue->begin)>>2)) return 0;
 {
  fn_802ef2fc(lbl_80473624,queue->begin->text);
  if(queue->begin+1!=queue->end) cc32b_copy_queue_range_802cbb5c(queue->begin+1,queue->end,queue->begin);
  --queue->end;
  queue->end->~Cc32bQueueString_802cbb5c();
  return lbl_80473624;
 }
 return 0;
}
