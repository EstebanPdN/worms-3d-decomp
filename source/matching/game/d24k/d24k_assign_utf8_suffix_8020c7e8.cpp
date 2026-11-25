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
extern "C" void string_default_803426b8(String *);
extern "C" void string_base_init_8020c5c0(String *);
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
extern "C" unsigned short *string_header_80341884(String *);
extern "C" void string_free_8020bb2c(void *);
extern "C" Header *string_allocate_8020bc88(String *,unsigned);
extern "C" void *string_transfer_802eee50(void *,const void *,...);
struct String {
    char *data;
    String(); // Defined by the witnessed native default constructor.
    String(const String &other) {
        string_base_init_8020c5c0(this);
        data=other.data;
        ++*string_header_80341884(this);
    }
    String &operator=(const String &other) {
        ++((Header *)(other.data-6))->references;
        void *old=data-6;
        unsigned short references=--((Header *)old)->references;
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
extern "C" int string_character_count_8020c5cc(String *);
inline int characterCount(String value) { return string_character_count_8020c5cc(&value); }
}
extern "C" D24kUtf8Suffix::String *w3d_d24k_assign_utf8_suffix_8020c7e8(D24kUtf8Suffix::String *self,const D24kUtf8Suffix::String *source,int count) {
    using namespace D24kUtf8Suffix;
    if(source==self) {
        String temporary;
        w3d_d24k_assign_utf8_suffix_8020c7e8(&temporary,self,count);
        *self=temporary;
    } else {
int bytes=0;
 int available=characterCount(*source);
 Header *header=(Header *)(self->data-6);
 count=count>available?available:count;
const char *text=source->data;
 int characters=0;
 int index=((Header *)(text-6))->bytes-1;
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
        string_transfer_802eee50(self->data,source->data+((Header *)(source->data-6))->bytes-bytes,bytes);
        self->data[bytes]=0;
    }
    return self;
}
