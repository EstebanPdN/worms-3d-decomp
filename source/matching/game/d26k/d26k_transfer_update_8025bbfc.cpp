// Transfer update (Worms 3D GameCube PAL, 0x8025bbfc).
// 
// Looks up the team's transfer. Mode 1 opens its file for writing (flag 6) and
// clears the state; mode 0 records the size, reopens it for appending (flag 8), seeks
// to the end and stores the position. Then builds a 0x8041aa08 packet; a team
// without property bit 64 finishes the transfer locally (0x8021dd04), any other
// sends the packet and stamps the start time. The empty sink keeps the discarded
// string copies of the original, as in d26k_asset_finish_8021dd04.

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
struct Transfer {
    char pad0[24]; int started; char pad1[32 - 28]; int state; char pad2[44 - 36]; int position; char pad3[60 - 48];
    int w60; int w64; SharedString name; char pad4[76 - 72]; Reader reader;
};
struct Request { char pad0[24]; int w24; int w28; char pad1[36 - 32]; int w36; int mode; };
struct Packet { char pad[36]; int w36; int w40; };
struct Props { char pad0[44]; SharedString second; char pad1[52 - 48]; SharedString first; };
struct Context { char pad[52]; int now; };
extern "C" Transfer *find_8021eab8(void *);
extern "C" int open_802080a0(Reader *, char *, int);
extern "C" Interface *lookup_8020b680(const void *);
extern "C" int props_80240b84(void *);
extern "C" Props *object_80240994(void *);
extern "C" void finish_8021dd04(Transfer *);
extern "C" int send_8021e930(void *, Interface *);
extern "C" Context *context_80165254();
extern const char key_8041aa08[];
extern "C" void w3d_d26k_transfer_update_8025bbfc(Request *self, void *team) {
    Transfer *t = find_8021eab8(team);
    if (t == 0) return;
    int zero = 0;
    use(t->name);
    if (self->mode == 1) {
        use(t->name);
        open_802080a0(&t->reader, t->name.text, 6);
        t->state = zero;
    }
    if (self->mode == 0) {
        int value = t->w64;
t->w60 = value;
t->w64 = self->w24;
t->state = value;
        use(t->name);
        open_802080a0(&t->reader, t->name.text, 8);
        t->reader.table->seek(&t->reader, 0, 2, 0);
        t->position = self->w28;
    }
    Ref packet(lookup_8020b680(key_8041aa08));
    reinterpret_cast<Packet *>(packet.p)->w36 = self->w36;
    reinterpret_cast<Packet *>(packet.p)->w40 = zero;
    if ((props_80240b84(team) & 64) == 0) {
        use(object_80240994(team)->first), use(object_80240994(team)->second), use(t->name);
        finish_8021dd04(t);
        return;
    }
    send_8021e930(team, packet.p);
    t->started = context_80165254()->now;
}
