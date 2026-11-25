// Send a serialized message (Worms 3D GameCube PAL, 0x8021e930).
// 
// When the connection at +60 reports state 0, serializes the message through the
// writer service 0x80418f78 into a new buffer (0x80208aac), sends the 4-byte
// size and then the data through connection slot 6, and returns the size; any other
// state returns 0. Stat (12 bytes) and Span (8 bytes) follow what the buffer
// methods 0x80209030 and 0x80208f2c write, which also explains the stack layout.

struct Object;
struct ObjectTable {
    void *reserved[3];
    int (*retain)(Object *);
    int (*release)(Object *);
};
struct Object { ObjectTable *table; };
struct Ref {
    Object *p;
    Ref(Object *o) : p(o) { if (p) p->table->retain(p); }
    Ref(const Ref &);
    ~Ref() { if (p) p->table->release(p); }
};

struct Conn;
struct ConnTable { void *pad[6]; int (*transfer)(Conn *, const void *, int, int *); void *pad2[7]; int (*state)(Conn *); };
struct Conn { ConnTable *table; };
struct Team { char pad[60]; Conn *conn; };
struct Writer;
struct WriterTable { void *pad[5]; int (*bind)(Writer *, Object *); void *pad2[2]; int (*put)(Writer *, Object *, int); };
struct Writer { WriterTable *table; };
struct Span { void *data; unsigned length; };
struct Stat { int size; int reserved; int kind; };
struct Buffer;
struct BufferTable { void *pad[9]; int (*stat)(Buffer *, Stat *); int (*span)(Buffer *, Span *); };
struct Buffer { BufferTable *table; };
extern "C" Object *lookup_8020b680(const void *);
extern "C" Object *create_80208aac(int);
extern const char key_80418f78[];
extern "C" int w3d_d26k_send_serialized_8021e930(Team *self, Object *msg) {
    int state = self->conn->table->state(self->conn);
    if (state != 0) return 0;
    Ref w(lookup_8020b680(key_80418f78));
    Ref e(create_80208aac(1));
    Stat stat;
    Span span;
    int done;
    Writer *wr = reinterpret_cast<Writer *>(w.p);
    wr->table->bind(wr, e.p);
    wr = reinterpret_cast<Writer *>(w.p);
    wr->table->put(wr, msg, 0);
    Buffer *bu = reinterpret_cast<Buffer *>(e.p);
    bu->table->span(bu, &span);
    bu = reinterpret_cast<Buffer *>(e.p);
    bu->table->stat(bu, &stat);
    done = state;
    self->conn->table->transfer(self->conn, &stat, 4, &done);
    self->conn->table->transfer(self->conn, span.data, stat.size, &done);
    return stat.size;
}
