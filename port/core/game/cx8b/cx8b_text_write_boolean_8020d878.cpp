#include "w3d_ptr.h"
#line 1 "cx8b_text_write_boolean_8020d878.cpp"

struct Cx8bTextSink;
struct Cx8bTextSinkVtable {Ptr32<void> unknown00[6];Ptr32<int (Ptr32<Cx8bTextSink>, Ptr32<const char>, unsigned int, int)> write;};
struct Cx8bTextSink {Ptr32<Cx8bTextSinkVtable> vtable;};
struct Cx8bBooleanWriter {Ptr32<Cx8bTextSink> sink;};
extern "C" char text_803b3230[],text_803b3238[];
extern "C" Ptr32<Cx8bBooleanWriter> w3d_cx8b_text_write_boolean_8020d878(Ptr32<Cx8bBooleanWriter> self,int value) {
 if(value) self->sink->vtable->write(self->sink,text_803b3230,4,0);
 else self->sink->vtable->write(self->sink,text_803b3238,5,0);
 return self;
}



