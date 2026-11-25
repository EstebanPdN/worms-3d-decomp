// Partial timing and envelope descriptors. Counter subtraction is unsigned;
// total lifetime is signed, while attack and hold durations are 16-bit values.
struct d11a_EnvelopeOwner { unsigned char unknown0[92];int duration;unsigned unknown96;unsigned start; };
struct d11a_Envelope { unsigned char unknown0[284];float decay;unsigned unknown288;float amplitude;unsigned char unknown296[96];unsigned short hold;unsigned char unknown394[16];unsigned short attack; };
extern const float d11a_zero_80389ba0[],d11a_one_80389ba4[];
extern "C" float d11a_envelope_800ddfe4(d11a_EnvelopeOwner *self,unsigned now,d11a_Envelope *config)
{
 float age=(float)(now-self->start);
 float amplitude=config->amplitude;
 float decay;
 if(age<config->attack) amplitude*=age/(float)config->attack;
 else {
   decay=config->decay;
   if(decay<d11a_zero_80389ba0[0]) {
     if(age>config->hold+config->attack) {
       float end_of_hold=(float)(config->hold+config->attack);
       amplitude-=amplitude*((age-end_of_hold)/((float)self->duration-end_of_hold));
     }
   } else if(age>config->hold+config->attack) {
     amplitude-=decay*(age-(float)(config->hold+config->attack));
   }
 }
 if(amplitude<d11a_zero_80389ba0[0])amplitude=d11a_zero_80389ba0[0];
 else if(amplitude>d11a_one_80389ba4[0])amplitude=d11a_one_80389ba4[0];
 return amplitude;
}
