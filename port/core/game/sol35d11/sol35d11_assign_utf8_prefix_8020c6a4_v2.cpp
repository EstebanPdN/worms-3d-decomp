#include "w3d_ptr.h"
#line 1 "sol35d11_assign_utf8_prefix_8020c6a4_v2.cpp"
// Inferred native shared-string prefix assignment. GC32-only storage view.
namespace Sol35d11Utf8PrefixV2 {
struct String;
struct Header { unsigned short references, bytes, capacity; };
extern "C" void sol35d11_base_init_8020c5c0(Ptr32<String>);
extern "C" void sol35d11_base_finish_8020c5c4(Ptr32<String>);
extern "C" void sol35d11_release_80341588(Ptr32<String>);
extern "C" Ptr32<unsigned short> sol35d11_header_80341884(Ptr32<String>);
extern "C" void sol35d11_free_header_8020bb2c(Ptr32<void>);
extern "C" Ptr32<Header> sol35d11_allocate_8020bc88(Ptr32<String>,unsigned);
extern "C" Ptr32<void> sol35d11_transfer_802eee50(Ptr32<void>,Ptr32<const void>,...);
struct String {
    Ptr32<char> data;
    String(const String &other) {
        sol35d11_base_init_8020c5c0(this);
        data=other.data;
        ++*sol35d11_header_80341884(this);
    }
    ~String() {
        sol35d11_base_finish_8020c5c4(this);
        sol35d11_release_80341588(this);
    }
};
// Native query code accepts the address of the caller-owned copy and returns
// only a scalar; caller copy and destruction establish these value boundaries.
extern "C" int sol35d11_character_count_8020c5cc(Ptr32<String>);
inline int characterCount(String value) { return sol35d11_character_count_8020c5cc(&value); }
extern "C" int sol35d11_prefix_bytes_8020c620(Ptr32<String>,unsigned);
inline int prefixBytes(String value,unsigned count) { return sol35d11_prefix_bytes_8020c620(&value,count); }
typedef char HeaderSize[(sizeof(Header)==6)?1:-1];
typedef char StringSize[(sizeof(String)==4)?1:-1];
}
extern "C" Ptr32<Sol35d11Utf8PrefixV2::String> sol35d11_assign_utf8_prefix_8020c6a4_v2(
    Ptr32<Sol35d11Utf8PrefixV2::String> self,Ptr32<const Sol35d11Utf8PrefixV2::String> source,int count) {
    using namespace Sol35d11Utf8PrefixV2;
    int available=characterCount(*source);
    Ptr32<char> old=self->data;
    Ptr32<Header> header=(Ptr32<Header>)(old-6);
    if(count>available) count=available;
    int bytes=prefixBytes(*source,count);
    if(header->references>1 || unsigned(bytes+1)>header->capacity) {
        unsigned short references=--header->references;
        if(!references) sol35d11_free_header_8020bb2c(header);
        header=sol35d11_allocate_8020bc88(self,bytes+1);
    }
    header->bytes=bytes;
    sol35d11_transfer_802eee50(self->data,source->data,bytes);
    self->data[bytes]=0;
    return self;
}


