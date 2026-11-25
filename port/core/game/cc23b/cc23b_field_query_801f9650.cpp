#include "w3d_ptr.h"
#line 1 "cc23b_field_query_801f9650.cpp"
struct Cc23bFieldOwner { unsigned char unknown[40]; unsigned int field; };
extern "C" unsigned int w3d_cc23b_field_query_801f9650(Ptr32<Cc23bFieldOwner> self, unsigned int expected, int mode,Ptr32<unsigned int> out) {
 if(out)*out=self->field;
 switch(mode) {
 case 0: if(self->field == expected)return 0; goto unsupported;
 case 1: if(expected==0)return 0; goto invalid;
 case 2: goto unsupported;
 }
 invalid: return 0x90000002;
 unsupported: return 0x80004001;
}


