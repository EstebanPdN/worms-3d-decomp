#include "w3d_ptr.h"
#line 1 "sol35d12_assign_byte_suffix_8020c0fc_v2.cpp"
// Inferred native GC32 suffix assignment; external storage and API contracts.
namespace Sol35d12SuffixV28020c0fc {
struct String;
struct Header { unsigned short references, bytes, capacity; };
extern "C" void sol35d12_default_803426b8(Ptr32<String>);
extern "C" void sol35d12_base_init_8020c5c0(Ptr32<String>);
extern "C" void sol35d12_finish_8020c5c4(Ptr32<String>);
extern "C" void sol35d12_release_80341588(Ptr32<String>);
extern "C" Ptr32<unsigned short> sol35d12_header_80341884(Ptr32<String>);
extern "C" void sol35d12_free_8020bb2c(Ptr32<void>);
extern "C" Ptr32<Header> sol35d12_allocate_8020bc88(Ptr32<String>,unsigned);
extern "C" Ptr32<void> sol35d12_transfer_802eee50(Ptr32<void>,Ptr32<const void>,...);
struct String {
    Ptr32<char> data;
    String(); // Defined by the witnessed native default constructor.
    String(const String &other) {
        sol35d12_base_init_8020c5c0(this);
        data=other.data;
        ++*sol35d12_header_80341884(this);
    }
    String &operator=(const String &other) {
        ++((Ptr32<Header>)(other.data-6))->references;
        Ptr32<void> old=data-6;
        unsigned short references=--((Ptr32<Header>)old)->references;
        if(!references) sol35d12_free_8020bb2c(old);
        data=other.data;
        return *this;
    }
    ~String() {
        sol35d12_finish_8020c5c4(this);
        sol35d12_release_80341588(this);
    }
};
typedef char HeaderSize[(sizeof(Header)==6)?1:-1];
typedef char StringSize[(sizeof(String)==4)?1:-1];
}
extern "C" Ptr32<Sol35d12SuffixV28020c0fc::String> sol35d12_assign_byte_suffix_8020c0fc_v2(Ptr32<Sol35d12SuffixV28020c0fc::String> self,Ptr32<const Sol35d12SuffixV28020c0fc::String> source,int count) {
    using namespace Sol35d12SuffixV28020c0fc;
    if(source==self) {
        String temporary;
        sol35d12_assign_byte_suffix_8020c0fc_v2(&temporary,self,count);
        *self=temporary;
    } else {
        Ptr32<char> old=self->data;
        Ptr32<Header> header=(Ptr32<Header>)(old-6);
        int available=((Ptr32<Header>)(source->data-6))->bytes;
        if(count>available) count=available;
        int bytes=count;
        if(header->references>1 || bytes+1>int(header->capacity)) {
            unsigned short references=--header->references;
            if(!references) sol35d12_free_8020bb2c(header);
            header=sol35d12_allocate_8020bc88(self,bytes+1);
        }
        header->bytes=bytes;
        sol35d12_transfer_802eee50(self->data,source->data+((Ptr32<Header>)(source->data-6))->bytes-bytes,bytes);
        self->data[bytes]=0;
    }
    return self;
}


