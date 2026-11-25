#include "w3d_ptr.h"
#line 1 "d26k_connection_created_8021b1f8.cpp"
// Connection created (Worms 3D GameCube PAL, 0x8021b1f8).
// 
// Asks the factory at +128 for a new connection, stores it as the team's connection
// at +60 (retain new, release old, drop the reference the factory returned), then
// sends a hello message from service 0x8041a938 carrying the cached id and the
// player name from the team properties, and sets the team state to 32.

struct SharedString;
extern "C" void string_init_8020c5c0(Ptr32<SharedString>);
extern "C" Ptr32<unsigned short> string_header_80341884(Ptr32<SharedString>);
extern "C" void string_finish_8020c5c4(Ptr32<SharedString>);
extern "C" void string_release_80341588(Ptr32<SharedString>);
extern "C" void release_header_8020bb2c(Ptr32<unsigned short>);
extern "C" Ptr32<SharedString> string_from_text_8020bb54(Ptr32<SharedString>, Ptr32<const char>);
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

struct Target { char pad[20]; unsigned short id; char pad2[2]; SharedString name; };
struct Props { char pad0[52]; SharedString first; SharedString name() const { return first; } };
struct Team { char pad[60]; Ptr32<Interface> conn;
  void setConn(Ptr32<Interface> n) { Ptr32<Interface> old = conn; conn = n; if (n) n->table->retain(n); if (old) old->table->release(old); } };
struct Owner { char pad[24]; Ptr32<Team> team; };
struct Factory;
struct FactoryTable { Ptr32<void> pad[13]; Ptr32<int (Ptr32<Factory>, Ptr32<Ptr32<Interface>>)> create; };
struct Factory { Ptr32<FactoryTable> table; };
struct Net { char pad0[36]; Ptr32<Owner> owner; char pad1[128 - 40]; Ptr32<Factory> factory; };
extern "C" Ptr32<Interface> lookup_8020b680(Ptr32<const void>);
extern "C" int msgid_8015f5a0(Ptr32<void>, int);
extern "C" Ptr32<Props> object_80240994(Ptr32<Team>);
extern "C" int send_8021e930(Ptr32<Team>, Ptr32<Interface>);
extern const char key_8041a938[];
extern char cache_804b0704;

struct RefT { Ptr32<Target> p; template <class W3dU> RefT(Ptr32<W3dU> w3d_p) : RefT((Target *)w3d_p.get()) {}
 RefT(Target *o) : p(o) { if (p) reinterpret_cast<Interface *>(w3d::R(p))->table->retain(reinterpret_cast<Interface *>(w3d::R(p))); } RefT(const RefT &);
  Ptr32<Target> operator->() { return p; }
  ~RefT() { if (p) reinterpret_cast<Interface *>(w3d::R(p))->table->release(reinterpret_cast<Interface *>(w3d::R(p))); } };
extern "C" void w3d_d26k_connection_created_8021b1f8(Ptr32<Net> self) {
    Ptr32<Team> team = self->owner->team;
    Ptr32<Interface> created;
    if (self->factory->table->create(self->factory, &created) >= 0) {
        team->setConn(created);
        created->table->release(created);
        RefT msg(reinterpret_cast<Target *>(w3d::R(lookup_8020b680(key_8041a938))));
        msg->id = msgid_8015f5a0(&cache_804b0704, 1);
        msg->name = object_80240994(team)->name();
        send_8021e930(team, reinterpret_cast<Interface *>(w3d::R(msg.p)));
        *reinterpret_cast<int *>(w3d::R(reinterpret_cast<char *>(w3d::R(team)) + 32)) = 32;
    }
}


