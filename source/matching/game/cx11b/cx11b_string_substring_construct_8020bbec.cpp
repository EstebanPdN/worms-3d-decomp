// Observed PPC32 shared-string header is six bytes before text: refs +0, length +2, capacity +4.
struct Header {unsigned short refs,length,capacity;};struct String {char *data;Header *header()const{return (Header *)(data-6);}};
extern "C" Header *allocate_8020bc88(String *,unsigned int);
extern "C" void *copy_802eee50(void *,const void *,unsigned int,...);

extern "C" void base_8020c5c0(String *);struct Empty {Header header;char data[2];};extern Empty empty_804aba1c;
extern "C" String *w3d_cx11b_string_substring_construct_8020bbec(String *self,const char *input,int offset,int length){base_8020c5c0(self);if(!input||!input[offset]){self->data=empty_804aba1c.data;Header *h=&empty_804aba1c.header;++h->refs;}else{Header *h=allocate_8020bc88(self,length+1);h->length=length;copy_802eee50(self->data,input+offset,length);self->data[length]=0;}return self;}


