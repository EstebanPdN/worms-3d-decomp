// Original 80028494. Timing and state names inferred; float copy observed in DOL.
typedef unsigned short cc30a_u16;
struct cc30a_State_80028494 {char gap[28]; int state; unsigned time; unsigned savedTime;char gap28[8];float start;char gap34[16];int enabled;char gap48[4];float current;};
extern int cc30a_cache_804acbdc,cc30a_cache_804acbe4,cc30a_cache_804acbec,cc30a_cache_804acbf4;
extern "C" {
int cc30a_call_8015fb34(cc30a_State_80028494*,cc30a_u16*);
void cc30a_call_80028708(cc30a_State_80028494*);
int cc30a_call_8015f620(int*,unsigned);
int cc30a_call_8015f65c(unsigned,int*);
unsigned cc30a_call_8015fd14();
int cc30a_timed_state_messages_80028494(cc30a_State_80028494* self,cc30a_u16* msg) {
 if(*msg==64) { if(cc30a_call_8015fb34(self,msg)>=0){cc30a_call_80028708(self);return 0;}return 0x80004005; }
 else if(cc30a_call_8015f620(&cc30a_cache_804acbdc,*msg)) { self->state=3;self->time=self->savedTime; }
 else if(cc30a_call_8015f620(&cc30a_cache_804acbe4,*msg)) { self->state=2;self->time=self->savedTime; }
 else if(cc30a_call_8015f65c(*msg,&cc30a_cache_804acbec)) { self->state=2;self->time=cc30a_call_8015fd14();self->current=self->start;self->enabled=1; }
 else if(cc30a_call_8015f65c(*msg,&cc30a_cache_804acbf4)) { self->state=3;self->time=cc30a_call_8015fd14();self->current=self->start; }
 else return cc30a_call_8015fb34(self,msg);
 return 0;
}
}
