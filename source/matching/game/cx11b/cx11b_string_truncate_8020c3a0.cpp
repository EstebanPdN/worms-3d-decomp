// Observed PPC32 shared-string header is six bytes before text: refs +0, length +2, capacity +4.
struct Header {unsigned short refs,length,capacity;};struct String {char *data;Header *header()const{return (Header *)(data-6);}};
extern "C" Header *allocate_8020bc88(String *,unsigned int);
extern "C" void release_8020bb2c(Header *);
extern "C" void *copy_802eee50(void *,const void *,unsigned int,...);

extern "C" void w3d_cx11b_string_truncate_8020c3a0(String *self,int length){char *old=self->data;Header *h=(Header *)(old-6);Header *target;unsigned int oldLength=h->length;if(h->refs>1){target=allocate_8020bc88(self,oldLength+1);copy_802eee50(self->data,old,length);if(--((Header *)(old-6))->refs==0)release_8020bb2c(h);}else target=h;target->length=length;self->data[length]=0;}


