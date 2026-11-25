#include "w3d_ptr.h"
#line 1 "cx7p_string_uppercase_8020c2e8.cpp"
// Observed PPC32 shared-string header is six bytes before text: refs +0, length +2, capacity +4.
struct Header {unsigned short refs,length,capacity;};struct String {Ptr32<char> data;Ptr32<Header> header()const{return (Ptr32<Header>)(data-6);}};
extern "C" Ptr32<Header> allocate_8020bc88(Ptr32<String>,unsigned int);
extern "C" void release_8020bb2c(Ptr32<Header>);

extern unsigned char classes_803db449[];
extern "C" void w3d_cx7p_string_uppercase_8020c2e8(Ptr32<String> self){Ptr32<char> old=self->data;Ptr32<Header> h=(Ptr32<Header>)(old-6);unsigned int length=h->length;if(h->refs>1){Ptr32<Header> fresh=allocate_8020bc88(self,length+1);if(--((Ptr32<Header>)(old-6))->refs==0)release_8020bb2c(h);fresh->length=length;}unsigned int i=0;Ptr32<char> out=self->data;for(;i<length;++i){int value=old[i];if(*(Ptr32<unsigned char>)w3d::G((value+(unsigned int)w3d::H(classes_803db449)))&2)value-=32;out[i]=value;}out[i]=0;}




