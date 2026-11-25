#include "w3d_ptr.h"
#line 1 "d27k_transfer_data_8025b7e8.cpp"
// Transfer data message handler (Worms 3D GameCube PAL, 0x8025b7e8).
// 
// Finds the transfer of the team. Mode 1 finishes it. Mode 0 writes the block, updates the total,
// finishes on a short write and acknowledges with a packet. Mode 2 writes the last block, closes the reader
// and sets state 2. The total store in mode 2 goes through a plain pointer so the table load stays before it.

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
struct Reader;
struct ReaderTable { Ptr32<void> pad[6]; Ptr32<int (Ptr32<Reader>, Ptr32<const void>, int, Ptr32<int>)> write; };
struct Reader { Ptr32<ReaderTable> table; };
struct Transfer {
    char pad0[24]; int started; char pad1[32 - 28]; int total; char pad2[48 - 36]; int state; char pad3[56 - 52]; int id; char pad4[68 - 60];
    SharedString name; char pad5[76 - 72]; Reader reader;
};
struct Block { char pad[32]; char bytes[4]; };
struct Request { char pad0[24]; int length; char pad1[40 - 28]; int mode; Ptr32<Block> block; };
struct Packet { char pad[36]; int w36; int w40; };
struct Props { char pad0[44]; SharedString second; char pad1[52 - 48]; SharedString first; };
struct Context { char pad[52]; int now; };
extern "C" Ptr32<Transfer> find_8021eab8(Ptr32<void>);
extern "C" int close_8020810c(Ptr32<Reader>);
extern "C" Ptr32<Interface> lookup_8020b680(Ptr32<const void>);
extern "C" int props_80240b84(Ptr32<void>);
extern "C" Ptr32<Props> object_80240994(Ptr32<void>);
extern "C" void finish_8021dd04(Ptr32<Transfer>);
extern "C" int send_8021e930(Ptr32<void>, Ptr32<Interface>);
extern "C" Ptr32<Context> context_80165254();
extern const char key_8041aa08[];
extern "C" void w3d_d27k_transfer_data_8025b7e8(Ptr32<Request> self, Ptr32<void> team) {
    Ptr32<Transfer> t = find_8021eab8(team);
    if (t == 0) return;
    int mode = self->mode;
    if (mode == 1) {
        use(t->name);
        finish_8021dd04(t);
        return;
    }
    if (mode == 0) {
        int written = 0;
        { Ptr32<const char> p = self->block->bytes; t->reader.table->write(&t->reader, p, self->length, &written); }
        t->total += self->length;
        if (written != 1) {
            use(t->name);
            finish_8021dd04(t);
        }
        Ref packet(lookup_8020b680(key_8041aa08));
        reinterpret_cast<Packet *>(w3d::R(packet.p))->w36 = t->id;
        reinterpret_cast<Packet *>(w3d::R(packet.p))->w40 = 0;
        if ((props_80240b84(team) & 64) == 0) {
            use(object_80240994(team)->first), use(object_80240994(team)->second), use(t->name);
            finish_8021dd04(t);
            return;
        }
        send_8021e930(team, packet.p);
        t->started = context_80165254()->now;
    }
    if (self->mode == 2) {
        use(t->name);
        if (self->length != 0) {
            int written = 0;
            Ptr32<const char> p = self->block->bytes; { Ptr32<int> tp = &t->total; *tp += self->length; }
            t->reader.table->write(&t->reader, p, self->length, &written);
            if (written != 1) {
                use(t->name);
                finish_8021dd04(t);
            }
        }
        use(t->name);
        close_8020810c(&t->reader);
        t->state = 2;
    }
}


