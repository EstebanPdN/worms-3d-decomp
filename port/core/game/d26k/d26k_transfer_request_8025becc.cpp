#include "w3d_ptr.h"
#line 1 "d26k_transfer_request_8025becc.cpp"
// Transfer request (Worms 3D GameCube PAL, 0x8025becc).
// 
// Builds a reply 0x8041a9d8 carrying the requested name and id and a transfer
// 0x8041aa18 kept on the team, opens the named file (0x8021d498) and then stores 1
// in the transfer state just before testing it, so this build always takes the
// first path: reply result 1. The other paths stay in the code: same size and check
// result 0, a local file at least as large result 1, a smaller one result 2 with its
// size and check. The empty sink keeps the discarded name copies of the original.

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
struct Request { char pad0[24]; int size; int check; SharedString name; int id; };
struct Reply { char pad0[24]; int size; int check; SharedString name; int id; int result; };
struct Transfer { char pad0[24]; int started; char pad1[44 - 28]; int check; int state; char pad2[64 - 52]; unsigned size; };
struct Team { char pad[52]; Ptr32<Interface> transfer;
    void setTransfer(Ptr32<Interface> n) { Ptr32<Interface> old = transfer; transfer = n; if (n) n->table->retain(n); if (old) old->table->release(old); } };
struct Context { char pad[52]; int now; };
extern "C" Ptr32<Interface> lookup_8020b680(Ptr32<const void>);
extern "C" int open_8021d498(Ptr32<Interface>, Ptr32<Team>, Ptr32<char>);
extern "C" int send_8021e930(Ptr32<Team>, Ptr32<Interface>);
extern "C" Ptr32<Context> context_80165254();
extern const char key_8041a9d8[], key_8041aa18[];
#define REPLY reinterpret_cast<Reply *>(w3d::R(reply.p))
#define XFER reinterpret_cast<Transfer *>(w3d::R(xfer.p))
extern "C" void w3d_d26k_transfer_request_8025becc(Ptr32<Request> self, Ptr32<Team> team) {
    use(self->name);
    Ref reply(lookup_8020b680(key_8041a9d8));
    REPLY->name = self->name;
    REPLY->id = self->id;
    Ref xfer(lookup_8020b680(key_8041aa18));
    team->setTransfer(xfer.p);
    int one = 1;
    open_8021d498(xfer.p, team, self->name.text);
    XFER->state = one;
    int state = XFER->state;
    if (state != 0) {
        use(self->name);
        REPLY->result = one;
        send_8021e930(team, reply.p);
        team->setTransfer(xfer.p);
        { Ptr32<Transfer> x = XFER; x->started = context_80165254()->now; }
        return;
    }
    if (XFER->size == self->size && XFER->check == self->check) {
        use(self->name);
        REPLY->result = state;
        send_8021e930(team, reply.p);
        return;
    }
    if (XFER->size >= (unsigned)self->size) {
        use(self->name);
        REPLY->result = 1;
        send_8021e930(team, reply.p);
        team->setTransfer(xfer.p);
        { Ptr32<Transfer> x = XFER; x->started = context_80165254()->now; }
        return;
    }
    team->setTransfer(xfer.p);
    use(self->name);
    REPLY->result = 2;
    REPLY->size = XFER->size;
    REPLY->check = XFER->check;
    send_8021e930(team, reply.p);
    { Ptr32<Transfer> x = XFER; x->started = context_80165254()->now; }
}


