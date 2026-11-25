// Original 0x802b879c. Panel activity and extent interpretations inferred.
// Inline clamp preserves the observed FPR lifetimes and operation order.
inline float clamp(float x,float low){if(x<low)x=low;return x;}
struct Owner {char pad00[40];char *carrier;char pad2c[176];float width;char pade0[60];void *related;int active;char pad124[20];float factor;char pad13c[100];float extra;};
extern "C" unsigned fn_802bc71c(void *);
extern "C" void fn_802b85f4(Owner *),fn_802b8754(Owner *);
extern float gain_803d80c8[],minimum_803d80cc[];
extern "C" void w3d_panel_activity_802b879c(Owner*self) {
 float width=self->width*gain_803d80c8[0];
 int desired=0;float total=width+width;char *carrier=self->carrier;
 if(self->related && fn_802bc71c(self->related)!=0 && total<(self->extra+self->extra)) {
  if(!*(int *)(carrier+180)) {
   float numerator=self->factor;float denom=*(float *)(carrier+136);total=numerator+numerator;denom=clamp(denom+denom,minimum_803d80cc[0]);
   total/=denom;
   if(total<(float)fn_802bc71c(self->related))desired=1;
  }else desired=1;
 }
 if(!self->active){if(desired==1)fn_802b85f4(self);}
 if(self->active && !desired)fn_802b8754(self);
}
