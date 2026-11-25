#include "w3d_ptr.h"
#line 1 "cc43b_read_records_802020f4_v3.cpp"
// Partial observed stream vtable. Status returns are known from sibling
// callers; this body ignores read/seek status. Original interface names unknown.
struct cc43b_Stream;
struct cc43b_StreamVtable {
    unsigned int unknown00[5];
    Ptr32<int (Ptr32<cc43b_Stream>, Ptr32<void>, unsigned int, int)> read;
    unsigned int unknown18;
    Ptr32<int (Ptr32<cc43b_Stream>, unsigned int, int, Ptr32<void>)> seek;
};
struct cc43b_Stream { Ptr32<cc43b_StreamVtable> vtable; };
struct cc43b_Reader { unsigned char unknown00[20]; Ptr32<cc43b_Stream> stream; };
inline void cc43b_swap_word(unsigned int &value) {
    value= value;
}
// The original repeatedly reads into the same record; it does not advance it.
struct cc43b_Record { unsigned int word; unsigned short first,second; unsigned int unknown08[2]; };
inline void cc43b_swap_half(unsigned short &value) {  }
extern "C" int cc43b_read_records_802020f4(Ptr32<cc43b_Reader> self,Ptr32<cc43b_Record> record,unsigned int count) {
    if (!record) return self->stream->vtable->seek(self->stream,count*16U,1,0);
    for (unsigned int i=0;i<count;++i) {
        int status=self->stream->vtable->read(self->stream,record,16,0);
        if (status<0) return status;
        cc43b_swap_word(record->word);
        cc43b_swap_half(record->first);
        cc43b_swap_half(record->second);
    }
    return 0;
}


