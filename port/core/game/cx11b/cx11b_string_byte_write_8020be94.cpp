#include "w3d_ptr.h"
#line 1 "cx11b_string_byte_write_8020be94.cpp"
// Observed PPC32 shared-string header is six bytes before text: refs +0, length +2, capacity +4.
struct Header {unsigned short refs,length,capacity;};struct String {Ptr32<char> data;Ptr32<Header> header()const{return (Ptr32<Header>)(data-6);}};
extern "C" Ptr32<Header> allocate_8020bc88(Ptr32<String>,unsigned int);
extern "C" void release_8020bb2c(Ptr32<Header>);
extern "C" Ptr32<void> copy_802eee50(Ptr32<void>,Ptr32<const void>,unsigned int,...);

extern "C" Ptr32<String> w3d_cx11b_string_byte_write_8020be94(Ptr32<String> self,int offset,char value){Ptr32<char> old=self->data;Ptr32<Header> h=(Ptr32<Header>)(old-6);if(h->refs>1){Ptr32<Header> fresh=allocate_8020bc88(self,h->capacity);copy_802eee50(self->data,old,h->capacity);fresh->length=h->length;if(--((Ptr32<Header>)(old-6))->refs==0)release_8020bb2c(h);}self->data[offset]=value;return self;}



