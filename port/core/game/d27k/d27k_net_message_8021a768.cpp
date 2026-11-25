#include "w3d_ptr.h"
#line 1 "d27k_net_message_8021a768.cpp"
// Network page message handler (Worms 3D GameCube PAL, 0x8021a768).
// 
// Compares the message id against the cached ids and runs the matching step. The state store
// in the last branch goes through a plain int pointer so the following global loads stay behind it.

struct String_803426b8;
extern "C" void string_init_8020c5c0(Ptr32<String_803426b8>);
extern "C" Ptr32<unsigned short> string_header_80341884(Ptr32<String_803426b8>);
extern "C" void string_finish_8020c5c4(Ptr32<String_803426b8>);
extern "C" void string_release_80341588(Ptr32<String_803426b8>);
extern "C" void release_header_8020bb2c(Ptr32<unsigned short>);
struct String_803426b8 {
    Ptr32<char> text;
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
struct Message { unsigned short id; };
struct Flags { char p0[96]; unsigned int pad1:22; unsigned int flag:1; unsigned int pad0:9; };
extern const unsigned char table_8040db38[];
extern Ptr32<void> global_804b1754; extern Ptr32<void> global_804b1788; extern Ptr32<Flags> global_804aac54; extern Ptr32<char> global_804aaf48;
extern "C" Ptr32<void> alloc_801613f0(Ptr32<void>, int);
extern "C" int msgid_8015f5a0(Ptr32<void>, int);
extern "C" int post_8016239c(Ptr32<Msg>);
extern "C" Ptr32<Interface> lookup_8020b680(Ptr32<const void>);
extern "C" int base_8015fd1c(Ptr32<void>);

struct Conn; struct ConnTable { Ptr32<void> pad[11]; Ptr32<int (Ptr32<Conn>)> reset; }; struct Conn { Ptr32<ConnTable> table; };
struct Team { char pad0[20]; int start; char pad1[32 - 24]; int flags; char pad2[60 - 36]; Ptr32<Conn> conn; };
struct Owner { char pad[24]; Ptr32<Team> team; };
struct Net { char pad0[36]; Ptr32<Owner> owner; char pad1[92 - 40]; int active; char pad2[112 - 96]; int timer; char pad3[156 - 116]; int forced; };
extern "C" int same_8015f65c(unsigned short, Ptr32<void>);
extern "C" int equals_8015f620(Ptr32<void>, unsigned short);
extern "C" int value_8021eb00(Ptr32<Team>);
extern "C" int props_80240b84(Ptr32<Team>);
extern "C" void dispatch_8021c294(Ptr32<Net>, int);
extern "C" void empty_8021b0a8(Ptr32<Net>);
extern "C" void other_8021a704(Ptr32<Net>);
extern "C" int send_8021e930(Ptr32<Team>, Ptr32<Interface>);
extern "C" Ptr32<void> context_80165254();
extern "C" void reset_8015cbe0(Ptr32<void>, int);
extern "C" void title_80165018(Ptr32<String_803426b8>);
extern "C" int stamp_80162ba8();
extern const char key_8041a9a8[];
extern char cache_804b076c, cache_804b0774, cache_804b071c, cache_804b0724, cache_804b0734, cache_804b070c, cache_804b0754, cache_804b0784;
extern "C" void w3d_d27k_net_message_8021a768(Ptr32<Net> self, Ptr32<Message> m) {
    Ptr32<Team> team = self->owner->team;
    if (same_8015f65c(m->id, &cache_804b076c) || same_8015f65c(m->id, &cache_804b0774)) {
        if (value_8021eb00(team) != 0 && (props_80240b84(team) & 64) != 0) dispatch_8021c294(self, -1);
        self->forced = 1;
        self->active = 0;
    } else if (same_8015f65c(m->id, &cache_804b071c)) {
        empty_8021b0a8(self);
    } else if (same_8015f65c(m->id, &cache_804b0724)) {
        other_8021a704(self);
    } else if (same_8015f65c(m->id, &cache_804b0734)) {
        Ptr32<Msg> n = (Ptr32<Msg>)alloc_801613f0(global_804b1754, 8);
        n->id = msgid_8015f5a0(&cache_804b070c, 1);
        n->type = table_8040db38;
        post_8016239c(n);
    } else if (equals_8015f620(&cache_804b0754, m->id)) {
        Ref service(lookup_8020b680(key_8041a9a8));
        send_8021e930(self->owner->team, service.p);
        self->active = 1;
        self->owner->team->start = 0;
        self->timer = 0;
        context_80165254();
        reset_8015cbe0(global_804b1788, 0);
        String_803426b8 title;
        title_80165018(&title);
        { String_803426b8 copy(title); }
        stamp_80162ba8();
    } else if (same_8015f65c(m->id, &cache_804b0784)) {
        Ptr32<Team> t = self->owner->team;
        t->conn->table->reset(t->conn);
        Ptr32<int> state = &t->flags; *state = 16;
        global_804aac54->flag = 1;
        *(Ptr32<int>)(global_804aaf48 + 432) = 0;
        base_8015fd1c(self);
    }
}


