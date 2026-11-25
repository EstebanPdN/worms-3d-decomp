// Observed PPC32 shared-string header is six bytes before text: refs +0, length +2, capacity +4.
struct Header {unsigned short refs,length,capacity;};struct String {char *data;Header *header()const{return (Header *)(data-6);}};
extern "C" Header *allocate_8020bc88(String *,unsigned int);
extern "C" void release_8020bb2c(Header *);
extern "C" void *copy_802eee50(void *,const void *,unsigned int,...);

extern "C" String *w3d_cx11b_string_byte_write_8020be94(String *self,int offset,char value){char *old=self->data;Header *h=(Header *)(old-6);if(h->refs>1){Header *fresh=allocate_8020bc88(self,h->capacity);copy_802eee50(self->data,old,h->capacity);fresh->length=h->length;if(--((Header *)(old-6))->refs==0)release_8020bb2c(h);}self->data[offset]=value;return self;}

