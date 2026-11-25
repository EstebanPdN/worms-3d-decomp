#include "w3d_ptr.h"
#line 1 "d27k_connection_closed_8021bd4c.cpp"
// Connection closed handler (Worms 3D GameCube PAL, 0x8021bd4c).
// 
// When the team has flag 64 set and its connection state is 2, sets the team state to 16,
// posts a closed message, erases the pool entry and resets the shared state; posts more messages.
// The state store goes through a plain int pointer: the store is then not a struct member,
// so alias analysis keeps the following global arena load behind it.

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

struct Msg { unsigned short id; unsigned short pad02; Ptr32<const void> type; };
struct Conn; struct ConnTable { Ptr32<void> pad[14]; Ptr32<int (Ptr32<Conn>)> state; }; struct Conn { Ptr32<ConnTable> table; };
struct Props { char pad0[44]; SharedString second; char pad1[52 - 48]; SharedString first; SharedString copyf() const { return first; } SharedString copys() const { return second; } };
struct Team { char pad[32]; int flags; char pad1[60 - 36]; Ptr32<Conn> conn; };
struct Owner { char pad[24]; Ptr32<Team> team; };
struct Panel { char pad0[36]; Ptr32<Owner> owner; char pad1[88 - 40]; Ptr32<void> pool; int active; char pad2[156 - 96]; int forced; };
struct Flags { char p0[96]; unsigned int pad1:22; unsigned int flag:1; unsigned int pad0:9; };
extern const unsigned char table_8040db38[];
extern Ptr32<void> global_804b1754; extern Ptr32<void> global_804b1788; extern Ptr32<Flags> global_804aac54; extern Ptr32<char> global_804aaf48; extern int global_804abab4;
extern char cache_804b06dc, cache_804b0714, cache_804b078c;
extern "C" Ptr32<void> alloc_801613f0(Ptr32<void>, int);
extern "C" int msgid_8015f5a0(Ptr32<void>, int);
extern "C" int post_8016239c(Ptr32<Msg>);
extern "C" Ptr32<Msg> msgint_800a82f0(Ptr32<void>, unsigned short, int);
extern "C" int erase_800c56b8(Ptr32<void>);
extern "C" Ptr32<Props> object_80240994(Ptr32<Team>);
extern "C" int paused_8015ccbc(Ptr32<void>);
extern "C" void leave_801298cc(Ptr32<void>);
inline SharedString nm(Ptr32<Team> a) { return object_80240994(a)->first; }
inline SharedString ps(Ptr32<Team> a) { return object_80240994(a)->second; }
inline void use(SharedString s) { }
extern "C" void w3d_d27k_connection_closed_8021bd4c(Ptr32<Panel> self) {
    Ptr32<Team> team = self->owner->team;
    if ((team->flags & 64) && team->conn->table->state(team->conn) == 2) {
        Ptr32<int> state = &team->flags; *state = 16;
        int zero = 0;
        Ptr32<Msg> m = (Ptr32<Msg>)alloc_801613f0(global_804b1754, 8);
        m->id = msgid_8015f5a0(&cache_804b06dc, 1);
        Ptr32<const void> table = table_8040db38;
        m->type = table;
        post_8016239c(m);
        erase_800c56b8(self->pool);
        use(nm(team)), use(ps(team));
        if (paused_8015ccbc(global_804b1788)) leave_801298cc(global_804b1788);
        global_804abab4 = zero;
        global_804aac54->flag = 1;
        *(Ptr32<int>)(global_804aaf48 + 432) = zero;
        if (self->forced == 0) {
            Ptr32<Msg> n = (Ptr32<Msg>)alloc_801613f0(global_804b1754, 8);
            n->id = msgid_8015f5a0(&cache_804b0714, 1);
            n->type = table;
            post_8016239c(n);
        }
        Ptr32<Msg> i = (Ptr32<Msg>)alloc_801613f0(global_804b1754, 12);
        post_8016239c(msgint_800a82f0(i, msgid_8015f5a0(&cache_804b078c, 1), 0));
        self->active = zero;
    }
}


