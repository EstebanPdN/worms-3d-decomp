// Team stream ready handler (Worms 3D GameCube PAL, 0x8021b8c0).
// 
// Reads the next team item from the stream when it is ready. On success sets team state 64
// and posts one message, on failure closes the stream, sets state 8, posts two messages and erases
// the pool entry. State stores go through a plain int pointer so the arena load stays behind them.

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
struct Props;
extern "C" Props *object_80240994(void *);
struct Msg { unsigned short id; unsigned short pad02; const void *type; };
struct Stream; struct StreamTable { void *pad[11]; int (*close)(Stream *); void *pad2[6]; int (*ready)(Stream *, int); };
struct Stream { StreamTable *table; };
struct Props { char pad0[44]; SharedString second; char pad1[52 - 48]; SharedString first; };
struct Team { char pad[32]; int flags; char pad1[60 - 36]; Stream *stream; };
struct Owner { char pad[24]; Team *team; };
struct Panel { char pad0[36]; Owner *owner; char pad1[88 - 40]; void *pool; };
extern const unsigned char table_8040db38[];
extern void *global_804b1754;
extern char cache_804b0724, cache_804b06e4, cache_804b073c;
extern "C" void *alloc_801613f0(void *, int);
extern "C" int msgid_8015f5a0(void *, int);
extern "C" int post_8016239c(Msg *);
extern "C" int read_8021bb9c(Panel *, Stream *, void **);
extern "C" void *active_8021ec2c(Owner *);
extern "C" int erase_800c56b8(void *);
inline SharedString nm(void *a) { return object_80240994(a)->first; }
inline SharedString ps(void *a) { return object_80240994(a)->second; }
extern "C" void w3d_d27k_team_stream_ready_8021b8c0(Panel *self) {
    Team *team = self->owner->team;
    if ((team->flags & 32) == 0) return;
    Stream *stream = team->stream;
    if (stream->table->ready(stream, 0) == 0) return;
    void *found;
    if (read_8021bb9c(self, stream, &found)) {
        use(nm(team)), use(ps(team));
        use(nm(active_8021ec2c(self->owner))), use(ps(active_8021ec2c(self->owner)));
        { int *state = &team->flags; *state = 64; }
        Msg *m = (Msg *)alloc_801613f0(global_804b1754, 8);
        m->id = msgid_8015f5a0(&cache_804b0724, 1);
        m->type = table_8040db38;
        post_8016239c(m);
    } else {
        use(nm(team)), use(ps(team));
        stream->table->close(stream);
        { int *state = &team->flags; *state = 8; }
        const void *table;
        { Msg *m = (Msg *)alloc_801613f0(global_804b1754, 8);
        m->id = msgid_8015f5a0(&cache_804b06e4, 1);
        table = table_8040db38;
        m->type = table;
        post_8016239c(m); }
        { Msg *m = (Msg *)alloc_801613f0(global_804b1754, 8);
        m->id = msgid_8015f5a0(&cache_804b073c, 1);
        m->type = table;
        post_8016239c(m); }
        erase_800c56b8(self->pool);
    }
}
