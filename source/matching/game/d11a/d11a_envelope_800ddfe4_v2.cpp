// Partial timing and envelope descriptors. Counter subtraction is unsigned;
// total lifetime is signed, while attack and hold durations are 16-bit values.
struct d11a_EnvelopeOwner { unsigned char unknown0[92];int duration;unsigned unknown96;unsigned start; };
struct d11a_Envelope { unsigned char unknown0[284];float decay;unsigned unknown288;float amplitude;unsigned char unknown296[96];unsigned short hold;unsigned char unknown394[16];unsigned short attack; };
extern const float d11a_zero_80389ba0[],d11a_one_80389ba4[];
inline float d11a_decay_to_end(float age,float hold_end,int duration,float amplitude) { return amplitude-amplitude*((age-hold_end)/((float)duration-hold_end)); }
inline float d11a_fixed_decay(float age,float hold_end,float decay,float amplitude) { return amplitude-decay*(age-hold_end); }
extern "C" float d11a_envelope_800ddfe4(d11a_EnvelopeOwner *self,unsigned now,d11a_Envelope *config)
{
 float age=(float)(now-self->start);
 float amplitude=config->amplitude;
 if(age<config->attack) amplitude*=age/(float)config->attack;
 else {
   float decay=config->decay;
   if(decay<d11a_zero_80389ba0[0]) {
     if(age>config->hold+config->attack) {
       amplitude=d11a_decay_to_end(age,config->hold+config->attack,self->duration,amplitude);
     }
   } else if(age>config->hold+config->attack) {
     amplitude=d11a_fixed_decay(age,config->hold+config->attack,decay,amplitude);
   }
 }
 if(amplitude<d11a_zero_80389ba0[0])amplitude=d11a_zero_80389ba0[0];
 else if(amplitude>d11a_one_80389ba4[0])amplitude=d11a_one_80389ba4[0];
 return amplitude;
}
