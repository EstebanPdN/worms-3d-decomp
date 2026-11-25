// Network connection open (Worms 3D GameCube PAL, 0x8021b388).
// 
// When the connection is idle (state 2), formats the host address (127.0.0.1:10017 for a local
// game, otherwise the active team's host), hands it to the looked-up service and opens the connection,
// counting the attempt. Once connected (flag 1 and state 0) it sends the team name message and sets state 32.
// The string copies are arguments of an empty inline sink in one comma expression: only slots witness them.

struct String_803426b8;
extern "C" void string_init_8020c5c0(String_803426b8 *);
extern "C" unsigned short *string_header_80341884(String_803426b8 *);
extern "C" void string_finish_8020c5c4(String_803426b8 *);
extern "C" void string_release_80341588(String_803426b8 *);
extern "C" void release_header_8020bb2c(unsigned short *);
struct String_803426b8 {
    char *text;
    String_803426b8();
    String_803426b8(const String_803426b8 &other) {
        string_init_8020c5c0(this);
        text = other.text;
        ++*string_header_80341884(this);
    }
    ~String_803426b8() {
        string_finish_8020c5c4(this);
        string_release_80341588(this);
    }
    String_803426b8 &operator=(const String_803426b8 &other) {
        ++reinterpret_cast<unsigned short *>(other.text)[-3];
        unsigned short *header = reinterpret_cast<unsigned short *>(text) - 3;
        if (--*header == 0) {
            release_header_8020bb2c(header);
        }
        text = other.text;
        return *this;
    }
};
typedef String_803426b8 SharedString;
struct Interface;
struct InterfaceTable {
    void *reserved[3];
    int (*retain)(Interface *);
    int (*release)(Interface *);
    void *pad0;
    int (*connect)(Interface *, char *);
};
struct Interface { InterfaceTable *table; };
struct ConnTable { void *pad[10]; int (*open)(struct Conn *, Interface *); void *pad1[3]; int (*state)(struct Conn *); };
struct Conn { ConnTable *table; };
struct Target { char pad[20]; unsigned short id; char pad2[2]; SharedString name; };
struct Ref { Interface *p; Ref(Interface *o) : p(o) { if (p) p->table->retain(p); } Ref(const Ref &); ~Ref() { if (p) p->table->release(p); } };
struct RefT { Target *p; RefT(Target *o) : p(o) { if (p) reinterpret_cast<Interface *>(p)->table->retain(reinterpret_cast<Interface *>(p)); } RefT(const RefT &);
  Target *operator->() { return p; }
  ~RefT() { if (p) reinterpret_cast<Interface *>(p)->table->release(reinterpret_cast<Interface *>(p)); } };
struct Props { char pad0[44]; SharedString second; char pad1[52 - 48]; SharedString first; };
struct Team { char pad[32]; int flags; int attempts; char pad1[60 - 40]; Conn *conn; };
struct Owner { char pad[24]; Team *team; };
struct Net { char pad0[36]; Owner *owner; };
extern "C" Interface *lookup_8020b680(const void *);
extern "C" int msgid_8015f5a0(void *, int);
extern "C" Props *object_80240994(Team *);
extern "C" int send_8021e930(Team *, Interface *);
extern "C" int local_8021ed0c(Props *);
extern "C" Team *active_8021ec2c(Owner *);
extern "C" void format_8020c510(String_803426b8 *, const char *, ...);
extern const char key_8041a938[], key_8041cb08[];
extern const char text_803b3c24[], text_803b3c94[];
extern char cache_804b0704;
inline SharedString nm(Team *a) { return object_80240994(a)->first; }
inline SharedString ps(Team *a) { return object_80240994(a)->second; }
inline void use(SharedString s) { }
extern "C" void w3d_d27k_net_open_8021b388(Net *self) {
    Team *team = self->owner->team;
    if (team->conn->table->state(team->conn) == 2) {
        Ref service(lookup_8020b680(key_8041cb08));
        String_803426b8 address;
        if (local_8021ed0c(object_80240994(self->owner->team))) {
            format_8020c510(&address, text_803b3c24, 10017);
        } else {
            SharedString host = ps(active_8021ec2c(self->owner));
            format_8020c510(&address, text_803b3c94, host.text, 10017);
        }
        service.p->table->connect(service.p, address.text);
        int attempts = team->attempts;
        use(nm(team)), use(ps(team)), use(nm(active_8021ec2c(self->owner))), use(ps(active_8021ec2c(self->owner))), use(address);
        int result = team->conn->table->open(team->conn, service.p);
        team->attempts = attempts + 1;
        if (result < 0) {
            use(nm(team)), use(ps(team));
            return;
        }
        team->flags = 1;
    }
    if (team->flags & 1) {
        int state = team->conn->table->state(team->conn);
        if (state == 0) {
            use(nm(team)), use(ps(team));
            RefT msg(reinterpret_cast<Target *>(lookup_8020b680(key_8041a938)));
            msg->id = msgid_8015f5a0(&cache_804b0704, 1);
            msg->name = nm(team);
            send_8021e930(team, reinterpret_cast<Interface *>(msg.p));
            team->attempts = state;
            team->flags = 32;
        }
    }
}
