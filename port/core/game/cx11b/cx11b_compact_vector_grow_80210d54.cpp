#include "w3d_ptr.h"
#line 1 "cx11b_compact_vector_grow_80210d54.cpp"
// PPC32 compact vector stores leading word +0, capacity halfword +4 and growth halfword +6.
struct Vector {unsigned int first;unsigned short capacity,quantum;};
extern "C" void resize_80210b90(Ptr32<Vector>,unsigned int);
extern "C" void w3d_cx11b_compact_vector_grow_80210d54(Ptr32<Vector> self,int requested){if((int)self->capacity<requested){unsigned int quantum=self->quantum;unsigned int first=self->first;if(!quantum)quantum=65536;unsigned int size=(requested+quantum)&-quantum;if(size>65535)size=65535;resize_80210b90(self,size);self->first=first;self->quantum<<=1;}}



