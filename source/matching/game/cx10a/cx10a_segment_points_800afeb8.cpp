// Observed PPC32 segment value +8, previous +0x14 and next +0x18; value copy is three words.
struct Cx10aWordVector {unsigned int x,y,z;};
struct Cx10aSegment {unsigned char unknown00[8];Cx10aWordVector value;Cx10aSegment *previous,*next;};
extern "C" void w3d_cx10a_segment_points_800afeb8(Cx10aSegment *self,Cx10aWordVector *a,Cx10aWordVector *b,Cx10aWordVector *c,Cx10aWordVector *d){
 if(!self->previous)*a=self->value;else *a=self->previous->value;
 *b=self->value;*c=self->next->value;
 if(!self->next->next)*d=self->next->value;else *d=self->next->next->value;
}
