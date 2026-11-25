// Observed PPC32 shared-string header is six bytes before text: refs +0, length +2, capacity +4.
struct Header {unsigned short refs,length,capacity;};struct String {char *data;Header *header()const{return (Header *)(data-6);}};
extern "C" Header *allocate_8020bc88(String *,unsigned int);
extern "C" void release_8020bb2c(Header *);
extern "C" void *copy_802eee50(void *,const void *,unsigned int,...);

extern unsigned char classes_803db449[];
extern "C" void w3d_cx11b_string_uppercase_8020c2e8(String *self){char *old=self->data;Header *h=(Header *)(old-6);unsigned int length=h->length;if(h->refs>1){Header *fresh=allocate_8020bc88(self,length+1);if(--((Header *)(old-6))->refs==0)release_8020bb2c(h);fresh->length=length;}unsigned int i=0;char *out=self->data;for(;i<length;++i){int value=old[i];if(*(unsigned char *)(value+(unsigned int)classes_803db449)&2)value-=32;out[i]=value;}out[i]=0;}


