// Observed PPC32 shared-string header is six bytes before text: refs +0, length +2, capacity +4.
struct Header {unsigned short refs,length,capacity;};struct String {char *data;Header *header()const{return (Header *)(data-6);}};
extern "C" Header *allocate_8020bc88(String *,unsigned int);
extern "C" void release_8020bb2c(Header *);
extern "C" void *copy_802eee50(void *,const void *,unsigned int,...);

extern "C" String *w3d_cx11b_string_prefix_assign_8020c048(String *self,const String *other,int length){char *old=self->data;Header *h=(Header *)(old-6);if(length>(int)other->header()->length)length=other->header()->length;if(h->refs>1||length+1>(int)h->capacity){if(--((Header *)(old-6))->refs==0)release_8020bb2c(h);h=allocate_8020bc88(self,length+1);}h->length=length;copy_802eee50(self->data,other->data,length);self->data[length]=0;return self;}


