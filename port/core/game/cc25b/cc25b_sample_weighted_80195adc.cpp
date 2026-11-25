#include "w3d_ptr.h"
#line 1 "cc25b_sample_weighted_80195adc.cpp"
typedef unsigned int cc25b_u32;
extern float cc25b_constant_803a847c[];
struct cc25b_WeightedTrack {float weight,start,rate;};
struct cc25b_SampleOwner {unsigned char prefix[20];float time;Ptr32<float> first; Ptr32<float> last;unsigned char gap[8];Ptr32<cc25b_WeightedTrack> trackFirst; Ptr32<cc25b_WeightedTrack> trackLast;unsigned char gap2[8];Ptr32<void> channelFirst; Ptr32<void> channelLast;unsigned char gap3[56];int postprocess;};
extern "C" void cc25b_fn_80195ea8(float,float,Ptr32<cc25b_SampleOwner>,int,int);
extern "C" void cc25b_fn_801979fc(Ptr32<cc25b_SampleOwner>);
extern "C" void cc25b_fn_80196038(Ptr32<cc25b_SampleOwner>);
inline cc25b_u32 cc25b_float_bits(const float &v){return *(Ptr32<const cc25b_u32>)&v;}
extern "C" cc25b_u32 w3d_cc25b_sample_weighted_80195adc(Ptr32<cc25b_SampleOwner> self) {
 if(self->channelFirst==self->channelLast)return 0x80004005;
 int first=1;
 Ptr32<float> v=self->first; Ptr32<float> end=self->last;
 int index=0;
 Ptr32<cc25b_WeightedTrack> track=self->trackFirst; Ptr32<cc25b_WeightedTrack> trackEnd=self->trackLast;
 if(v!=end) {float zero=cc25b_constant_803a847c[0]; do {*v=zero;++v;}while(v!=end);}
 for(;track!=trackEnd;++track) {
  float weight=track->weight;
  float sample=self->time*track->rate+track->start;
  if(cc25b_float_bits(weight)!=0) {
   cc25b_fn_80195ea8(weight,sample,self,index,first);
   first=0;
  }
  ++index;
 }
 if(self->postprocess)cc25b_fn_801979fc(self);
 cc25b_fn_80196038(self);
 return 0;
}


