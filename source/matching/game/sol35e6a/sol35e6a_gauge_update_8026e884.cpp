// Inferred gauge smoothing; all offsets and external identities observed in PPC.
#define FIELD(p,T,o) (*reinterpret_cast<T *>(static_cast<char *>(p)+(o)))
extern const float sol35e6a_threshold_hi_803cbdf8[];
extern const float sol35e6a_threshold_lo_803cbdfc[];
extern const float sol35e6a_blend_803cbe00[];
extern const float sol35e6a_one_803cbe04[];
extern "C" void sol35e6a_value_a_802bc790(void *,float);
extern "C" void sol35e6a_value_b_80296410(void *,float);
extern "C" int sol35e6a_gauge_update_8026e884(void *self) {
 typedef void (*Tick)(void *);
 FIELD(self,Tick *,208)[3](static_cast<char *>(self)+28);
 void *control=FIELD(self,void *,292);
 if (control && FIELD(control,float,92)!=FIELD(self,float,308)) {
  float value=FIELD(control,float,92);
  if (FIELD(control,unsigned,68)==0) FIELD(self,float,312)=value;
  else {
   FIELD(self,float,308)=value;
   FIELD(self,float,312)=FIELD(control,float,92);
  }
 }
 float target=FIELD(self,float,312);
 float current=FIELD(self,float,308);
 if (target!=current) {
  float delta=target-current;
  if (sol35e6a_threshold_hi_803cbdf8[0]<=delta || delta<=sol35e6a_threshold_lo_803cbdfc[0])
   FIELD(self,float,308)=current*(sol35e6a_one_803cbe04[0]-sol35e6a_blend_803cbe00[0])+target*sol35e6a_blend_803cbe00[0];
  else FIELD(self,float,308)=target;
 }
 if (FIELD(self,void *,288)) sol35e6a_value_a_802bc790(FIELD(self,void *,288),FIELD(self,float,308));
 if (FIELD(self,void *,292)) sol35e6a_value_b_80296410(FIELD(self,void *,292),FIELD(self,float,308));
 return 0;
}
