#include "w3d_ptr.h"
#line 1 "cx11b_string_substring_construct_8020bbec.cpp"
// Observed PPC32 shared-string header is six bytes before text: refs +0, length +2, capacity +4.
struct Header {unsigned short refs,length,capacity;};struct String {Ptr32<char> data;Ptr32<Header> header()const{return (Ptr32<Header>)(data-6);}};
extern "C" Ptr32<Header> allocate_8020bc88(Ptr32<String>,unsigned int);
extern "C" Ptr32<void> copy_802eee50(Ptr32<void>,Ptr32<const void>,unsigned int,...);

extern "C" void base_8020c5c0(Ptr32<String>);struct Empty {Header header;char data[2];};extern Empty empty_804aba1c;
extern "C" Ptr32<String> w3d_cx11b_string_substring_construct_8020bbec(Ptr32<String> self,Ptr32<const char> input,int offset,int length){base_8020c5c0(self);if(!input||!input[offset]){self->data=empty_804aba1c.data;Ptr32<Header> h=&empty_804aba1c.header;++h->refs;}else{Ptr32<Header> h=allocate_8020bc88(self,length+1);h->length=length;copy_802eee50(self->data,input+offset,length);self->data[length]=0;}return self;}




