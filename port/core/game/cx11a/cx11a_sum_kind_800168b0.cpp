#include "w3d_ptr.h"
#line 1 "cx11a_sum_kind_800168b0.cpp"
// PPC32 entries store a float at +4 and kind at +8; owner kind is +0x14. Numeric transform meanings remain unknown.
struct Cx11aEntry {unsigned int unknown00;float value;int kind;};struct Cx11aVector {Ptr32<Ptr32<Cx11aEntry>> begin; Ptr32<Ptr32<Cx11aEntry>> end; Ptr32<Ptr32<Cx11aEntry>> capacity;};extern Ptr32<Cx11aVector> entries_804aa6fc;extern const float zero_8036a688[],factor_8036a68c[];extern "C" float transformA_802e83cc(float),transformB_802e8094(float);struct Cx11aOwner {unsigned char unknown00[0x14];int kind;};
static inline int entryCount(){Ptr32<Cx11aVector> v=entries_804aa6fc;return v->end-v->begin;}
extern "C" float w3d_cx11a_sum_kind_800168b0(Ptr32<const Cx11aOwner> self){float sum=zero_8036a688[0];for(int i=0;i<entryCount();++i){float value=zero_8036a688[0];Ptr32<Cx11aVector> v=entries_804aa6fc;Ptr32<Cx11aEntry> entry=*(Ptr32<Ptr32<Cx11aEntry>>)((Ptr32<char>)v->begin+(i<<2));if(self->kind==entry->kind)value=transformB_802e8094(transformA_802e83cc(entry->value)*factor_8036a68c[0]);sum+=value;}return sum;}


