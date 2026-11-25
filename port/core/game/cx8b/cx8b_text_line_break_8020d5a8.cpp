#include "w3d_ptr.h"
#line 1 "cx8b_text_line_break_8020d5a8.cpp"

// Writer layout inferred from flag access at +4.
struct Cx8bTextWriter { unsigned int unknown00, flags; };
extern "C" char text_803b3224[], text_803b322c[];
extern "C" Ptr32<Cx8bTextWriter> fn_8020dbf8(Ptr32<Cx8bTextWriter>,Ptr32<const char>);
extern "C" Ptr32<Cx8bTextWriter> w3d_cx8b_text_line_break_8020d5a8(Ptr32<Cx8bTextWriter> self) {
 if(self->flags & 0x01000000) fn_8020dbf8(self,text_803b3224);
 else fn_8020dbf8(self,text_803b322c);
 return self;
}



