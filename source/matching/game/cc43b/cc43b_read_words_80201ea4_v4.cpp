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
extern "C" void cc43b_read_words_80201ea4(cc43b_Reader *self,unsigned int *values,unsigned int count) {
    if (!values) self->stream->vtable->seek(self->stream,count*4U,1,0);
    else {
        self->stream->vtable->read(self->stream,values,count*4U,0);
        unsigned int *cursor=values;
        for (unsigned int i=0;i<count;++i) {
            unsigned int &value=*cursor++;
            cc43b_swap_word(value);
        }
    }
}
