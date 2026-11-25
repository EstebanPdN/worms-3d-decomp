// Asset transfer reply handler (Worms 3D GameCube PAL, 0x8025afc4).
// 
// Finds the asset of the message. Mode 0 stores the reply mode and state 4. Mode 1 sends a request packet
// and opens the reader on the request's text. Other modes compare the checksum of the local file with
// the request and send a packet (0 resume with a seek, 1 restart); when the team flag 64 is clear the transfer
// finishes. Packet ids come from the global counter 0x804abb1c through an inline post-increment.

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
struct Reader;
struct ReaderTable { void *pad[7]; int (*seek)(Reader *, int, int, int); };
struct Reader { ReaderTable *table; };
struct Packet { char pad[24]; int w24; int w28; SharedString name; int w36; int w40; };
struct Props { char pad0[44]; SharedString second; char pad1[52 - 48]; SharedString first; };
struct Asset { char pad0[24]; int started; char pad1[36 - 28]; void *owner; int w40; int w44; int state; char pad2[64 - 52]; int w64; SharedString name; char pad3[76 - 72]; Reader reader; };
struct Request { char pad[24]; int length; int sum; const char *text; char pad1[40 - 36]; int mode; };
struct Message { char pad[56]; void *arg; };
struct Context { char pad[52]; int now; };
struct RefP { Packet *p; RefP(Packet *o) : p(o) { if (p) reinterpret_cast<Interface *>(p)->table->retain(reinterpret_cast<Interface *>(p)); } RefP(const RefP &);
  Packet *operator->() { return p; }
  ~RefP() { if (p) reinterpret_cast<Interface *>(p)->table->release(reinterpret_cast<Interface *>(p)); } };
extern int global_804abb1c;
extern const char key_8041a9e8[];
inline int nextId() { int id = global_804abb1c; global_804abb1c = id + 1; return id; }
inline int next() { return global_804abb1c++; }
extern "C" Asset *find_8025d588(void *);
extern "C" Props *object_80240994(void *);
extern "C" int props_80240b84(void *);
extern "C" int *field_80240700(Asset *);
extern "C" int crc_8021d5c4(int, int);
extern "C" Interface *lookup_8020b680(const void *);
extern "C" int send_8021e930(void *, Packet *);
extern "C" int refill_802080a0(Reader *, const char *, int);
extern "C" Context *context_80165254(void);
extern "C" void finish_8021dd04(Asset *);
#define PK reinterpret_cast<Packet *>(lookup_8020b680(key_8041a9e8))
#define FILL(m) packet->name = t->name; packet->w40 = m; packet->w24 = t->w64; { int *w = &packet->w28; *w = t->w44; } packet->w36 = next();
extern "C" void w3d_d27k_transfer_reply_8025afc4(Request *self, Message *m) {
    Asset *t = find_8025d588(m->arg);
    if (t == 0) return;
    int mode = self->mode;
    if (mode == 0) {
        use(t->name), use(object_80240994(t->owner)->first), use(object_80240994(t->owner)->second);
        t->w40 = self->mode;
        t->state = 4;
    } else if (mode == 1) {
        RefP packet(PK);
        use(t->name), use(object_80240994(t->owner)->first), use(object_80240994(t->owner)->second);
        FILL(mode)
        if ((props_80240b84(t->owner) & 64) == 0) {
            use(object_80240994(t->owner)->first), use(object_80240994(t->owner)->second), use(t->name);
            finish_8021dd04(t);
            return;
        }
        send_8021e930(t->owner, packet.p);
        refill_802080a0(&t->reader, self->text, 1);
        t->state = 2;
        t->started = context_80165254()->now;
    } else {
        int sum = self->sum;
        int length = self->length;
        if (sum == crc_8021d5c4(*field_80240700(t), length)) {
            RefP packet(PK);
            use(t->name), use(object_80240994(t->owner)->first), use(object_80240994(t->owner)->second);
            FILL(0)
            if ((props_80240b84(t->owner) & 64) == 0) {
                use(object_80240994(t->owner)->first), use(object_80240994(t->owner)->second), use(t->name);
                finish_8021dd04(t);
                return;
            }
            send_8021e930(t->owner, packet.p);
            refill_802080a0(&t->reader, t->name.text, 1);
            t->reader.table->seek(&t->reader, self->length, 0, 0);
            t->state = 2;
            t->started = context_80165254()->now;
        } else {
            use(t->name), use(object_80240994(t->owner)->first), use(object_80240994(t->owner)->second);
            RefP packet(PK);
            FILL(1)
            if ((props_80240b84(t->owner) & 64) == 0) {
                use(object_80240994(t->owner)->first), use(object_80240994(t->owner)->second), use(t->name);
                finish_8021dd04(t);
                return;
            }
            send_8021e930(t->owner, packet.p);
            refill_802080a0(&t->reader, t->name.text, 1);
            t->state = 2;
            t->started = context_80165254()->now;
        }
    }
}
