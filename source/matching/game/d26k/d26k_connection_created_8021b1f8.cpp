// Connection created (Worms 3D GameCube PAL, 0x8021b1f8).
// 
// Asks the factory at +128 for a new connection, stores it as the team's connection
// at +60 (retain new, release old, drop the reference the factory returned), then
// sends a hello message from service 0x8041a938 carrying the cached id and the
// player name from the team properties, and sets the team state to 32.

struct SharedString;
extern "C" void string_init_8020c5c0(SharedString *);
extern "C" unsigned short *string_header_80341884(SharedString *);
extern "C" void string_finish_8020c5c4(SharedString *);
extern "C" void string_release_80341588(SharedString *);
extern "C" void release_header_8020bb2c(unsigned short *);
extern "C" SharedString *string_from_text_8020bb54(SharedString *, const char *);
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

struct Target { char pad[20]; unsigned short id; char pad2[2]; SharedString name; };
struct Props { char pad0[52]; SharedString first; SharedString name() const { return first; } };
struct Team { char pad[60]; Interface *conn;
  void setConn(Interface *n) { Interface *old = conn; conn = n; if (n) n->table->retain(n); if (old) old->table->release(old); } };
struct Owner { char pad[24]; Team *team; };
struct Factory;
struct FactoryTable { void *pad[13]; int (*create)(Factory *, Interface **); };
struct Factory { FactoryTable *table; };
struct Net { char pad0[36]; Owner *owner; char pad1[128 - 40]; Factory *factory; };
extern "C" Interface *lookup_8020b680(const void *);
extern "C" int msgid_8015f5a0(void *, int);
extern "C" Props *object_80240994(Team *);
extern "C" int send_8021e930(Team *, Interface *);
extern const char key_8041a938[];
extern char cache_804b0704;

struct RefT { Target *p; RefT(Target *o) : p(o) { if (p) reinterpret_cast<Interface *>(p)->table->retain(reinterpret_cast<Interface *>(p)); } RefT(const RefT &);
  Target *operator->() { return p; }
  ~RefT() { if (p) reinterpret_cast<Interface *>(p)->table->release(reinterpret_cast<Interface *>(p)); } };
extern "C" void w3d_d26k_connection_created_8021b1f8(Net *self) {
    Team *team = self->owner->team;
    Interface *created;
    if (self->factory->table->create(self->factory, &created) >= 0) {
        team->setConn(created);
        created->table->release(created);
        RefT msg(reinterpret_cast<Target *>(lookup_8020b680(key_8041a938)));
        msg->id = msgid_8015f5a0(&cache_804b0704, 1);
        msg->name = object_80240994(team)->name();
        send_8021e930(team, reinterpret_cast<Interface *>(msg.p));
        *reinterpret_cast<int *>(reinterpret_cast<char *>(team) + 32) = 32;
    }
}
