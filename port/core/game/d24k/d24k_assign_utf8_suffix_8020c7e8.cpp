#include "w3d_ptr.h"
#line 1 "d24k_assign_utf8_suffix_8020c7e8.cpp"
// UTF-8 suffix assignment (Worms 3D GameCube PAL, 0x8020c7e8).
//
// Assigns to self the last count UTF-8 characters of source (continuation bytes
// 10xxxxxx do not count), clamped to the source's character count (0x8020c5cc).
// When source is self it builds the result in a temporary and assigns it. A
// shared or too small buffer is released and reallocated (0x8020bc88) before the
// bytes are copied and terminated. The source text is a loop local, which gives
// the original's register order. Names and layouts are inferred.
namespace D24kUtf8Suffix {
struct String;
struct Header { unsigned short references, bytes, capacity; };
extern "C" void string_default_803426b8(Ptr32<String>);
extern "C" void string_base_init_8020c5c0(Ptr32<String>);
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
extern "C" Ptr32<unsigned short> string_header_80341884(Ptr32<String>);
extern "C" void string_free_8020bb2c(Ptr32<void>);
extern "C" Ptr32<Header> string_allocate_8020bc88(Ptr32<String>,unsigned);
extern "C" Ptr32<void> string_transfer_802eee50(Ptr32<void>,Ptr32<const void>,...);
struct String {
    Ptr32<char> data;
    String(); // Defined by the witnessed native default constructor.
    String(const String &other) {
        string_base_init_8020c5c0(this);
        data=other.data;
        ++*string_header_80341884(this);
    }
    String &operator=(const String &other) {
        ++((Ptr32<Header>)(other.data-6))->references;
        Ptr32<void> old=data-6;
        unsigned short references=--((Ptr32<Header>)old)->references;
        if(!references) string_free_8020bb2c(old);
        data=other.data;
        return *this;
    }
    ~String() {
        string_finish_8020c5c4(this);
        string_release_80341588(this);
    }
};
typedef char HeaderSize[(sizeof(Header)==6)?1:-1];
typedef char StringSize[(sizeof(String)==4)?1:-1];
extern "C" int string_character_count_8020c5cc(Ptr32<String>);
inline int characterCount(String value) { return string_character_count_8020c5cc(&value); }
}
extern "C" Ptr32<D24kUtf8Suffix::String> w3d_d24k_assign_utf8_suffix_8020c7e8(Ptr32<D24kUtf8Suffix::String> self,Ptr32<const D24kUtf8Suffix::String> source,int count) {
    using namespace D24kUtf8Suffix;
    if(source==self) {
        String temporary;
        w3d_d24k_assign_utf8_suffix_8020c7e8(&temporary,self,count);
        *self=temporary;
    } else {
int bytes=0;
 int available=characterCount(*source);
 Ptr32<Header> header=(Ptr32<Header>)(self->data-6);
 count=count>available?available:count;
Ptr32<const char> text=source->data;
 int characters=0;
 int index=((Ptr32<Header>)(text-6))->bytes-1;
 while(index>=0 && characters!=count) {
 if((static_cast<unsigned char>(text[index])&0xc0)!=0x80) ++characters;
 ++bytes;
 --index;
 }
        if(header->references>1 || unsigned(bytes+1)>header->capacity) {
            unsigned short references=--header->references;
            if(!references) string_free_8020bb2c(header);
            header=string_allocate_8020bc88(self,bytes+1);
        }
        header->bytes=bytes;
        string_transfer_802eee50(self->data,source->data+((Ptr32<Header>)(source->data-6))->bytes-bytes,bytes);
        self->data[bytes]=0;
    }
    return self;
}


