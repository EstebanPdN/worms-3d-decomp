// Partial external views only: none of these types is locally constructed.
struct ArrayHeaderView {
 unsigned unknown0; unsigned short kind,unknown6;
 unsigned unknown8[4]; unsigned count; unsigned short locks;
};
struct ArrayRefView {
 ArrayHeaderView *header;
 void lock(unsigned start,unsigned mode) {
  ArrayHeaderView *h=header;
  if(h->kind==1 && h->count==start) ++h->locks;
  else lock_801ef048(this,start,mode,8);
 }
 static void *lock_801ef048(ArrayRefView*,unsigned,unsigned,unsigned);
};
extern "C" void *array_lock_801ef048(ArrayRefView*,unsigned,unsigned,unsigned);
inline void *ArrayRefView::lock_801ef048(ArrayRefView *p,unsigned a,unsigned b,unsigned c){return array_lock_801ef048(p,a,b,c);}
struct ChannelView {char unknown0[24];ArrayRefView data;};
struct ChannelSetView {char unknown0[24];ArrayRefView data;ChannelView *channel3,*channel2,*channel1,*channel0;};
struct ChannelOwnerView {char unknown0[92];ChannelSetView *channels;};
struct ChannelLockStateView {char unknown0[160];unsigned aggregate,channel0,channel1,channel2,channel3,flags,unknown184,active;};
extern "C" void g8a_release_channel_locks_8016b040(unsigned selected,ChannelOwnerView *owner,ChannelLockStateView *state){
 if(!state->active)return;
 unsigned flags=state->flags;
 if(flags>>31){
  ChannelSetView *set=owner->channels;
  if(selected&3){if((flags>>29)&1)set->channel0->data.lock(0,1);else set->channel0->data.lock(0,2);state->channel0=0;}
  if(selected&12){if((state->flags>>28)&1)set->channel1->data.lock(0,1);else set->channel1->data.lock(0,2);state->channel1=0;}
  if(selected&48){if((state->flags>>27)&1)set->channel2->data.lock(0,1);else set->channel2->data.lock(0,2);state->channel2=0;}
  if(selected&384){if((state->flags>>26)&1)set->channel3->data.lock(0,1);else set->channel3->data.lock(0,2);state->channel3=0;}
 }else{
  if((flags>>30)&1)owner->channels->data.lock(0,1);
  else {if(owner->channels->data.header->count)owner->channels->data.lock(0,2);state->aggregate=0;}
 }
 state->active=0;
}
