#include "w3d_ptr.h"
#line 1 "cx11b_string_prefix_assign_8020c048.cpp"
// Observed PPC32 shared-string header is six bytes before text: refs +0, length +2, capacity +4.
struct Header {unsigned short refs,length,capacity;};struct String {Ptr32<char> data;Ptr32<Header> header()const{return (Ptr32<Header>)(data-6);}};
extern "C" Ptr32<Header> allocate_8020bc88(Ptr32<String>,unsigned int);
extern "C" void release_8020bb2c(Ptr32<Header>);
extern "C" Ptr32<void> copy_802eee50(Ptr32<void>,Ptr32<const void>,unsigned int,...);

extern "C" Ptr32<String> w3d_cx11b_string_prefix_assign_8020c048(Ptr32<String> self,Ptr32<const String> other,int length){Ptr32<char> old=self->data;Ptr32<Header> h=(Ptr32<Header>)(old-6);if(length>(int)other->header()->length)length=other->header()->length;if(h->refs>1||length+1>(int)h->capacity){if(--((Ptr32<Header>)(old-6))->refs==0)release_8020bb2c(h);h=allocate_8020bc88(self,length+1);}h->length=length;copy_802eee50(self->data,other->data,length);self->data[length]=0;return self;}




