// Send a file block (Worms 3D GameCube PAL, 0x8021d928).
// 
// Builds a 0x8041a9f8 packet, reads the next chunk from the reader at +76 into its
// locked byte array and adds the count to the running total. A short read marks
// the packet result 2, sets the state to 4 and closes the reader. A team without
// property bit 64 finishes locally (0x8021dd04), any other sends the packet and
// stamps the time. The empty sink keeps the discarded string copies of the original.

struct SharedString;
extern "C" void string_init_8020c5c0(SharedString *);
extern "C" unsigned short *string_header_80341884(SharedString *);
extern "C" void string_finish_8020c5c4(SharedString *);
extern "C" void string_release_80341588(SharedString *);
extern "C" void release_header_8020bb2c(unsigned short *);
struct SharedString {
    char *text;
    
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
        ++reinterpret_cast<unsigned short *>(other.text)[-3];
        unsigned short *header = reinterpret_cast<unsigned short *>(text) - 3;
        if (--*header == 0) {
            release_header_8020bb2c(header);
        }
        text = other.text;
        return *this;
    }
};
struct Interface;
struct InterfaceTable {
    void *reserved[3];
    int (*retain)(Interface *);
    int (*release)(Interface *);
};
struct Interface { InterfaceTable *table; };
struct Ref {
    Interface *p;
    Ref(Interface *o) : p(o) { if (p) p->table->retain(p); }
    Ref(const Ref &);
    ~Ref() { if (p) p->table->release(p); }
};

inline void use(SharedString s) { }
struct Header { char pad0[4]; unsigned short shared; char pad1[24 - 6]; unsigned count; unsigned short refs; char pad2[2]; char data[1]; };
struct Array;
extern "C" char *lock_801ef048(Array *, unsigned, int, int);
struct Array { Header *header;
    char *lock(unsigned n) {
        Header *h = header;
        if (h->shared == 1 && n == h->count) { ++h->refs; return h->data; }
        return lock_801ef048(this, n, 1, 0);
    }
};
struct Block { char pad0[24]; int length; char pad1[36 - 28]; int id; int result; Array array; };
struct Reader;
struct ReaderTable { void *pad[5]; int (*read)(Reader *, char *, unsigned, unsigned *); };
struct Reader { ReaderTable *table; };
struct Props { char pad0[44]; SharedString second; char pad1[52 - 48]; SharedString first; };
struct Context { char pad[52]; int now; };
struct Asset {
    char pad0[20]; unsigned chunk; int started; int total; char pad1[36 - 32]; void *owner; char pad2[48 - 40]; int state; char pad3[56 - 52]; int id; char pad4[68 - 60];
    SharedString name; char pad5[76 - 72]; Reader reader;
};
extern "C" Interface *lookup_8020b680(const void *);
extern "C" int props_80240b84(void *);
extern "C" Props *object_80240994(void *);
extern "C" void finish_8021dd04(Asset *);
extern "C" int send_8021e930(void *, Interface *);
extern "C" Context *context_80165254();
extern "C" int close_8020810c(Reader *);
extern const char key_8041a9f8[];
#define BLOCK reinterpret_cast<Block *>(block.p)
extern "C" void w3d_d26k_send_file_block_8021d928(Asset *self) {
    Ref block(lookup_8020b680(key_8041a9f8));
    char *data = BLOCK->array.lock(self->chunk);
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
