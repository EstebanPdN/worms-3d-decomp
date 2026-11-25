#include "w3d_ptr.h"
#line 1 "cx7b_stream_write_words_802043b8.cpp"
struct Cx7bWordStream;
struct Cx7bWordStreamVtable { Ptr32<void> unknown[10]; Ptr32<int (Ptr32<Cx7bWordStream>, unsigned int, int, int)> write; };
struct Cx7bWordStream { Ptr32<Cx7bWordStreamVtable> vtable; };
extern "C" int w3d_cx7b_stream_write_words_802043b8(Ptr32<Cx7bWordStream> self,Ptr32<const unsigned int> words,unsigned int count) {
 for(unsigned int i=0;i<count;++i) self->vtable->write(self,*words++,0,0);
 return 0;
}


