#include "w3d_ptr.h"
#line 1 "d26k_send_serialized_8021e930.cpp"
// Send a serialized message (Worms 3D GameCube PAL, 0x8021e930).
// 
// When the connection at +60 reports state 0, serializes the message through the
// writer service 0x80418f78 into a new buffer (0x80208aac), sends the 4-byte
// size and then the data through connection slot 6, and returns the size; any other
// state returns 0. Stat (12 bytes) and Span (8 bytes) follow what the buffer
// methods 0x80209030 and 0x80208f2c write, which also explains the stack layout.

struct Object;
struct ObjectTable {
    Ptr32<void> reserved[3];
    Ptr32<int (Ptr32<Object>)> retain;
    Ptr32<int (Ptr32<Object>)> release;
};
struct Object { Ptr32<ObjectTable> table; };
struct Ref {
    Ptr32<Object> p;
    template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Object *)w3d_p.get()) {}
 Ref(Object *o) : p(o) { if (p) p->table->retain(p); }
    Ref(const Ref &);
    ~Ref() { if (p) p->table->release(p); }
};

struct Conn;
struct ConnTable { Ptr32<void> pad[6]; Ptr32<int (Ptr32<Conn>, Ptr32<const void>, int, Ptr32<int>)> transfer; Ptr32<void> pad2[7]; Ptr32<int (Ptr32<Conn>)> state; };
struct Conn { Ptr32<ConnTable> table; };
struct Team { char pad[60]; Ptr32<Conn> conn; };
struct Writer;
struct WriterTable { Ptr32<void> pad[5]; Ptr32<int (Ptr32<Writer>, Ptr32<Object>)> bind; Ptr32<void> pad2[2]; Ptr32<int (Ptr32<Writer>, Ptr32<Object>, int)> put; };
struct Writer { Ptr32<WriterTable> table; };
struct Span { Ptr32<void> data; unsigned length; };
struct Stat { int size; int reserved; int kind; };
struct Buffer;
struct BufferTable { Ptr32<void> pad[9]; Ptr32<int (Ptr32<Buffer>, Ptr32<Stat>)> stat; Ptr32<int (Ptr32<Buffer>, Ptr32<Span>)> span; };
struct Buffer { Ptr32<BufferTable> table; };
extern "C" Ptr32<Object> lookup_8020b680(Ptr32<const void>);
extern "C" Ptr32<Object> create_80208aac(int);
extern const char key_80418f78[];
extern "C" int w3d_d26k_send_serialized_8021e930(Ptr32<Team> self, Ptr32<Object> msg) {
    int state = self->conn->table->state(self->conn);
    if (state != 0) return 0;
    Ref w(lookup_8020b680(key_80418f78));
    Ref e(create_80208aac(1));
    Stat stat;
    Span span;
    int done;
    Ptr32<Writer> wr = reinterpret_cast<Writer *>(w3d::R(w.p));
    wr->table->bind(wr, e.p);
    wr = reinterpret_cast<Writer *>(w3d::R(w.p));
    wr->table->put(wr, msg, 0);
    Ptr32<Buffer> bu = reinterpret_cast<Buffer *>(w3d::R(e.p));
    bu->table->span(bu, &span);
    bu = reinterpret_cast<Buffer *>(w3d::R(e.p));
    bu->table->stat(bu, &stat);
    done = state;
    self->conn->table->transfer(self->conn, &stat, 4, &done);
    self->conn->table->transfer(self->conn, span.data, stat.size, &done);
    return stat.size;
}


