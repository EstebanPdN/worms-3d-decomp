#include "w3d_ptr.h"
#line 1 "cx10a_segment_points_800afeb8.cpp"
// Observed PPC32 segment value +8, previous +0x14 and next +0x18; value copy is three words.
struct Cx10aWordVector {unsigned int x,y,z;};
struct Cx10aSegment {unsigned char unknown00[8];Cx10aWordVector value;Ptr32<Cx10aSegment> previous; Ptr32<Cx10aSegment> next;};
extern "C" void w3d_cx10a_segment_points_800afeb8(Ptr32<Cx10aSegment> self,Ptr32<Cx10aWordVector> a,Ptr32<Cx10aWordVector> b,Ptr32<Cx10aWordVector> c,Ptr32<Cx10aWordVector> d){
 if(!self->previous)*a=self->value;else *a=self->previous->value;
 *b=self->value;*c=self->next->value;
 if(!self->next->next)*d=self->next->value;else *d=self->next->next->value;
}


