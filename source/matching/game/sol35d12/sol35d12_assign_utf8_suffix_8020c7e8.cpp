// Inferred native GC32 suffix assignment; external storage and API contracts.
namespace Sol35d12Suffix8020c7e8 {
struct String;
struct Header { unsigned short references, bytes, capacity; };
extern "C" void sol35d12_default_803426b8(String *);
extern "C" void sol35d12_base_init_8020c5c0(String *);
extern "C" void sol35d12_finish_8020c5c4(String *);
extern "C" void sol35d12_release_80341588(String *);
extern "C" unsigned short *sol35d12_header_80341884(String *);
extern "C" void sol35d12_free_8020bb2c(void *);
extern "C" Header *sol35d12_allocate_8020bc88(String *,unsigned);
extern "C" void *sol35d12_transfer_802eee50(void *,const void *,...);
struct String {
    char *data;
    String() { sol35d12_default_803426b8(this); }
    String(const String &other) {
        sol35d12_base_init_8020c5c0(this);
        data=other.data;
        ++*sol35d12_header_80341884(this);
    }
    String &operator=(const String &other) {
        ++((Header *)(other.data-6))->references;
        void *old=data-6;
        unsigned short references=--((Header *)old)->references;
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
extern "C" int sol35d12_character_count_8020c5cc(String *);
inline int characterCount(String value) { return sol35d12_character_count_8020c5cc(&value); }
}
extern "C" Sol35d12Suffix8020c7e8::String *sol35d12_assign_utf8_suffix_8020c7e8(Sol35d12Suffix8020c7e8::String *self,const Sol35d12Suffix8020c7e8::String *source,int count) {
    using namespace Sol35d12Suffix8020c7e8;
    if(source==self) {
        String temporary;
        sol35d12_assign_utf8_suffix_8020c7e8(&temporary,self,count);
        *self=temporary;
    } else {
        int bytes=0;
        int available=characterCount(*source);
        char *old=self->data;
        Header *header=(Header *)(old-6);
        if(count>available) count=available;
        int characters=0;
        int index=((Header *)(source->data-6))->bytes-1;
        while(index>=0 && characters!=count) {
            if((static_cast<unsigned char>(source->data[index])&0xc0)!=0x80) ++characters;
            ++bytes;
            --index;
        }
        if(header->references>1 || unsigned(bytes+1)>header->capacity) {
            unsigned short references=--header->references;
            if(!references) sol35d12_free_8020bb2c(header);
            header=sol35d12_allocate_8020bc88(self,bytes+1);
        }
        header->bytes=bytes;
        sol35d12_transfer_802eee50(self->data,source->data+((Header *)(source->data-6))->bytes-bytes,bytes);
        self->data[bytes]=0;
    }
    return self;
}
