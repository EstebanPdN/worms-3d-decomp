#include "w3d_ptr.h"
#line 1 "cx8c_indexed_assign_80348bd0.cpp"
/* Observed offsets and 32-byte record stride; semantic names inferred. */
struct Cx8cInterface {Ptr32<Ptr32<void>> vtable;};
struct Cx8cArray {unsigned int words[2];Ptr32<Ptr32<Cx8cInterface>> begin;};
struct Cx8cRecord {unsigned char unknown[16];Cx8cArray array;unsigned int tail;};
struct Cx8cOwner {unsigned char unknown[24];Ptr32<Cx8cRecord> records;unsigned char unknown_1c[44];unsigned int capacity;};
extern "C" void cx8c_reserve_80210b90(Ptr32<Cx8cArray>,unsigned int);
extern "C" int w3d_cx8c_indexed_assign_80348bd0(Ptr32<Cx8cOwner> self,unsigned int record,unsigned int index,Ptr32<Cx8cInterface> value) {
 unsigned int record_offset=record<<5;unsigned int offset=index<<2;
 cx8c_reserve_80210b90(&((Ptr32<Cx8cRecord>)w3d::G(((unsigned int)w3d::H(self->records)+record_offset)))->array,self->capacity);
 Ptr32<Ptr32<Cx8cInterface>> base=((Ptr32<Cx8cRecord>)w3d::G(((unsigned int)w3d::H(self->records)+record_offset)))->array.begin;
 if(value) ((Ptr32<void (Ptr32<Cx8cInterface>)>)value->vtable[3])(value);
 Ptr32<Cx8cInterface> old=*(Ptr32<Ptr32<Cx8cInterface>>)w3d::G((offset+(unsigned int)w3d::H(base)));
 if(old) ((Ptr32<void (Ptr32<Cx8cInterface>)>)old->vtable[4])(old);
 *(Ptr32<Ptr32<Cx8cInterface>>)w3d::G((offset+(unsigned int)w3d::H(base)))=value;return 0;
}


