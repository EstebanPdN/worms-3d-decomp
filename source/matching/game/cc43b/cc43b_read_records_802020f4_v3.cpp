// Partial observed stream vtable. Status returns are known from sibling
// callers; this body ignores read/seek status. Original interface names unknown.
struct cc43b_Stream;
struct cc43b_StreamVtable {
    unsigned int unknown00[5];
    int (*read)(cc43b_Stream *,void *,unsigned int,int);
    unsigned int unknown18;
    int (*seek)(cc43b_Stream *,unsigned int,int,void *);
};
struct cc43b_Stream { cc43b_StreamVtable *vtable; };
struct cc43b_Reader { unsigned char unknown00[20]; cc43b_Stream *stream; };
inline void cc43b_swap_word(unsigned int &value) {
    value= (value<<24)|((value&0xff00U)<<8)|((value>>8)&0xff00U)|(value>>24);
}
// The original repeatedly reads into the same record; it does not advance it.
struct cc43b_Record { unsigned int word; unsigned short first,second; unsigned int unknown08[2]; };
inline void cc43b_swap_half(unsigned short &value) { unsigned short shifted=value<<8; value=(value>>8)|shifted; }
extern "C" int cc43b_read_records_802020f4(cc43b_Reader *self,cc43b_Record *record,unsigned int count) {
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
