
struct SharedString { unsigned char *bytes; };
struct Reader { unsigned char reserved[20]; SharedString *string; unsigned int position; };
extern "C" void *copy_802eee50(void *,const void *,unsigned int);
static inline const unsigned int &minimum(const unsigned int &a,const unsigned int &b) { return b<a?b:a; }
extern "C" int w3d_cx9b_string_stream_read_8020d3c0(Reader *self,void *destination,unsigned int requested,unsigned int *read) {
 unsigned int count=minimum((unsigned int)(((unsigned short *)self->string->bytes)[-2]-self->position),requested);
 copy_802eee50(destination,self->string->bytes+self->position,count);
 if(read) *read=count;
 self->position+=count;
 return 0;
}

