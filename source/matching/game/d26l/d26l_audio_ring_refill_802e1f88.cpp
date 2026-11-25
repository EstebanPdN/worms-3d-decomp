// GWMP8P rev0 0x802e1f88. Audio DMA refill callback of the movie player.
// Mixer is a partial view of the object at 0x804b190c: its two sample
// buffers, buffer index, user callback and pending/current mix pointers are
// read from this code; the names are inference.
struct Mixer{char unknown0[16];void*buffers[2];unsigned index;void(*callback)();void*pending;void*current;int mode;};
extern Mixer*mixer_804b190c;
extern "C" void fn_80311254(void*,unsigned);
extern "C" int fn_802fdb80();
extern "C" int fn_802fdb94(int);
extern "C" void fn_802e1f54(Mixer*,void*,void*,unsigned);
extern "C" void fn_802fa988(void*,unsigned);
extern "C" void fn_802fa95c(void*,unsigned);
extern "C" unsigned fn_8031130c();
extern "C" void d26l_audio_ring_refill_802e1f88(){
 Mixer*m=mixer_804b190c;int level;
 if(m->mode==0){
  m->index^=1;
  fn_80311254(m->buffers[m->index],640);
  level=fn_802fdb80();
  fn_802e1f54(m,m->buffers[m->index],0,160);
  fn_802fa988(m->buffers[m->index],640);
  fn_802fdb94(level);
 }else{
  if(m->mode==1){
   if(m->pending)m->current=m->pending;
   m->callback();
   m->pending=(void*)(fn_8031130c()+0x80000000);
  }else{
   m->callback();
   m->current=(void*)(fn_8031130c()+0x80000000);
  }
  m->index^=1;
  fn_80311254(m->buffers[m->index],640);
  level=fn_802fdb80();
  if(m->current)fn_802fa95c(m->current,640);
  fn_802e1f54(m,m->buffers[m->index],m->current,160);
  fn_802fa988(m->buffers[m->index],640);
  fn_802fdb94(level);
 }
}
