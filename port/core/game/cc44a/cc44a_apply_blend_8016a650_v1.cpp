#include "w3d_ptr.h"
#line 1 "cc44a_apply_blend_8016a650_v1.cpp"
// Partial material view. Signed full-width factor words are compared and used as
// unchecked indices exactly as in the original; the mapping table remains unowned.
struct cc44a_BlendState { unsigned char unknown[24]; int destination, source; };
extern const int cc44a_blend_factors_803a5500[];
// Actual definitions write GX state/FIFO and have no defined result.
// Blend enums occupy full words; alpha thresholds and depth enable are narrowed
// by explicit low-byte operations inside their original callees.
extern "C" void cc44a_set_blend_8030b9b8(int,int,int,int);
extern "C" void cc44a_alpha_compare_8030b3dc(int,unsigned char,int,int,unsigned char);
extern "C" void cc44a_depth_location_8030ba98(unsigned char);
extern "C" int cc44a_apply_blend_8016a650(Ptr32<void>,Ptr32<const cc44a_BlendState> state) {
 int source=state->source;
 int destination=state->destination;
 if(source==11) {
   cc44a_set_blend_8030b9b8(3,1,cc44a_blend_factors_803a5500[destination],15);
 } else if(destination==11) {
   cc44a_set_blend_8030b9b8(3,cc44a_blend_factors_803a5500[source],1,15);
 } else if(source==1 && destination==0) {
   cc44a_set_blend_8030b9b8(0,1,0,15);
 } else {
   cc44a_set_blend_8030b9b8(1,cc44a_blend_factors_803a5500[source],cc44a_blend_factors_803a5500[destination],15);
   cc44a_alpha_compare_8030b3dc(4,15,0,4,15);
   cc44a_depth_location_8030ba98(1);
 }
 return 0;
}


