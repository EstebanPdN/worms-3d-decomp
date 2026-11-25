// Two-channel envelope slot. The owner and trailing storage are partial views.
// Durations and elapsed ticks use unsigned wrapping arithmetic.
struct d11a_ChannelEnvelope { unsigned age,end,attack,release;float first,second; };
struct d11a_ChannelOwner { unsigned char unknown[44];d11a_ChannelEnvelope slots[2]; };
extern const float d11a_zero_803981c8[],d11a_one_803981cc[];
extern "C" void d11a_set_channels_800fdf5c(d11a_ChannelOwner *,unsigned,unsigned,unsigned);
extern "C" void d11a_update_channels_800fdfec(d11a_ChannelOwner *self,unsigned slot,unsigned elapsed)
{
 d11a_ChannelEnvelope *e=&self->slots[slot];
 e->age+=elapsed;
 if(e->age<=e->end) {
   float age=(float)e->age;
   unsigned first,second;
   if(e->age<e->attack) {
     float ratio=age/(float)e->attack;
     float a=e->first*ratio;
     if(a>=e->first)a=e->first;
     float b=e->second*ratio;
     if(b>=e->second)b=e->second;
     first=(unsigned char)a;second=(unsigned char)b;
   } else if(e->age>e->release) {
     float ratio=(age-(float)e->release)/(float)(e->end-e->release);
     if(ratio<d11a_zero_803981c8[0])ratio=d11a_zero_803981c8[0];
     else if(ratio>d11a_one_803981cc[0])ratio=d11a_one_803981cc[0];
     float a=e->first*ratio;
     if(a>=e->first)a=e->first;
     float b=e->second*ratio;
     if(b>=e->second)b=e->second;
     first=(unsigned char)a;second=(unsigned char)b;
   } else {first=(unsigned char)e->first;second=(unsigned char)e->second;}
   d11a_set_channels_800fdf5c(self,slot,first,second);
 } else d11a_set_channels_800fdf5c(self,slot,0,0);
}
