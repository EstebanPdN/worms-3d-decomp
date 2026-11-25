#include "w3d_ptr.h"
#line 1 "d26k_send_file_block_8021d928.cpp"
// Send a file block (Worms 3D GameCube PAL, 0x8021d928).
// 
// Builds a 0x8041a9f8 packet, reads the next chunk from the reader at +76 into its
// locked byte array and adds the count to the running total. A short read marks
// the packet result 2, sets the state to 4 and closes the reader. A team without
// property bit 64 finishes locally (0x8021dd04), any other sends the packet and
// stamps the time. The empty sink keeps the discarded string copies of the original.

struct SharedString;
extern "C" void string_init_8020c5c0(Ptr32<SharedString>);
extern "C" Ptr32<unsigned short> string_header_80341884(Ptr32<SharedString>);
extern "C" void string_finish_8020c5c4(Ptr32<SharedString>);
extern "C" void string_release_80341588(Ptr32<SharedString>);
extern "C" void release_header_8020bb2c(Ptr32<unsigned short>);
struct SharedString {
    Ptr32<char> text;
    
    SharedString(const SharedString &other) {
        string_init_8020c5c0(this);
        text = other.text;
        ++*string_header_80341884(this);
    }
    ~SharedString() {
        string_finish_8020c5c4(this);
        string_release_80341588(this);
    }
    SharedString &operator=(const SharedString &other) {
        ++reinterpret_cast<unsigned short *>(w3d::R(other.text))[-3];
        Ptr32<unsigned short> header = reinterpret_cast<unsigned short *>(w3d::R(text)) - 3;
        if (--*header == 0) {
            release_header_8020bb2c(header);
        }
        text = other.text;
        return *this;
    }
};
struct Interface;
struct InterfaceTable {
    Ptr32<void> reserved[3];
    Ptr32<int (Ptr32<Interface>)> retain;
    Ptr32<int (Ptr32<Interface>)> release;
};
struct Interface { Ptr32<InterfaceTable> table; };
struct Ref {
    Ptr32<Interface> p;
    template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Interface *)w3d_p.get()) {}
 Ref(Interface *o) : p(o) { if (p) p->table->retain(p); }
    Ref(const Ref &);
    ~Ref() { if (p) p->table->release(p); }
};

inline void use(SharedString s) { }
struct Header { char pad0[4]; unsigned short shared; char pad1[24 - 6]; unsigned count; unsigned short refs; char pad2[2]; char data[1]; };
struct Array;
extern "C" Ptr32<char> lock_801ef048(Ptr32<Array>, unsigned, int, int);
struct Array { Ptr32<Header> header;
    Ptr32<char> lock(unsigned n) {
        Ptr32<Header> h = header;
        if (h->shared == 1 && n == h->count) { ++h->refs; return h->data; }
        return lock_801ef048(this, n, 1, 0);
    }
};
struct Block { char pad0[24]; int length; char pad1[36 - 28]; int id; int result; Array array; };
struct Reader;
struct ReaderTable { Ptr32<void> pad[5]; Ptr32<int (Ptr32<Reader>, Ptr32<char>, unsigned int, Ptr32<unsigned int>)> read; };
struct Reader { Ptr32<ReaderTable> table; };
struct Props { char pad0[44]; SharedString second; char pad1[52 - 48]; SharedString first; };
struct Context { char pad[52]; int now; };
struct Asset {
    char pad0[20]; unsigned chunk; int started; int total; char pad1[36 - 32]; Ptr32<void> owner; char pad2[48 - 40]; int state; char pad3[56 - 52]; int id; char pad4[68 - 60];
    SharedString name; char pad5[76 - 72]; Reader reader;
};
extern "C" Ptr32<Interface> lookup_8020b680(Ptr32<const void>);
extern "C" int props_80240b84(Ptr32<void>);
extern "C" Ptr32<Props> object_80240994(Ptr32<void>);
extern "C" void finish_8021dd04(Ptr32<Asset>);
extern "C" int send_8021e930(Ptr32<void>, Ptr32<Interface>);
extern "C" Ptr32<Context> context_80165254();
extern "C" int close_8020810c(Ptr32<Reader>);
extern const char key_8041a9f8[];
#define BLOCK reinterpret_cast<Block *>(w3d::R(block.p))
extern "C" void w3d_d26k_send_file_block_8021d928(Ptr32<Asset> self) {
    Ref block(lookup_8020b680(key_8041a9f8));
    Ptr32<char> data = BLOCK->array.lock(self->chunk);
    unsigned got = 0;
    self->reader.table->read(&self->reader, data, self->chunk, &got);
    if (((self->total += got) & 8192) == 0) {
        use(self->name), use(object_80240994(self->owner)->first), use(object_80240994(self->owner)->second);
    }
    unsigned chunk = self->chunk;
    if (got < chunk) {
        use(self->name), use(object_80240994(self->owner)->first), use(object_80240994(self->owner)->second);
        BLOCK->result = 2;
        self->state = 4;
        close_8020810c(&self->reader);
    } else {
        BLOCK->result = 0;
    }
    BLOCK->length = got;
    BLOCK->id = self->id;
    if ((props_80240b84(self->owner) & 64) == 0) {
        use(object_80240994(self->owner)->first), use(object_80240994(self->owner)->second), use(self->name);
        finish_8021dd04(self);
        return;
    }
    send_8021e930(self->owner, block.p);
    self->started = context_80165254()->now;
}


