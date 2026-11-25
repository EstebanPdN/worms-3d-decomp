#include "w3d_ptr.h"
#line 1 "d26k_net_connect_8021adb8.cpp"
// Network connect (Worms 3D GameCube PAL, 0x8021adb8).
// 
// Reads Net.ServerPort, then points the host service 0x8041cb08 at 127.0.0.1 on
// port 10017. On failure posts two messages around copying Text.InvalidPort into
// Net.ConnectionStatus. On success creates the client 0x8041ca50 at +128, replacing
// the old one, and starts it on the host: failure posts one message, success sets
// the team flags to 1. Failure paths also call the base 0x8015fd1c.

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

struct PropertyKey { Ptr32<const char> name; };
struct Host; struct HostTable { Ptr32<void> pad[6]; Ptr32<int (Ptr32<Interface>, Ptr32<const char>)> connect; };
struct HostObject { Ptr32<HostTable> table; };
struct Client; struct ClientTable { Ptr32<void> pad[3]; Ptr32<int (Ptr32<Client>)> retain; Ptr32<int (Ptr32<Client>)> release; Ptr32<void> pad2[7]; Ptr32<int (Ptr32<Client>, Ptr32<Interface>)> start; };
struct Client { Ptr32<ClientTable> table; };
struct Team { char pad[32]; int flags; };
struct Owner { char pad[24]; Ptr32<Team> team; };
struct Net { char pad0[36]; Ptr32<Owner> owner; char pad1[128 - 40]; Ptr32<Client> client; };
extern "C" int read_800fc230(Ptr32<PropertyKey>, Ptr32<int>);
extern "C" int text_800fc2b0(Ptr32<PropertyKey>, Ptr32<Ptr32<const char>>);
extern "C" int write_800fc550(Ptr32<PropertyKey>, Ptr32<const char>);
extern "C" Ptr32<Client> client_8020b680(Ptr32<const void>);
extern "C" int format_8020c510(Ptr32<String_803426b8>, Ptr32<const char>, ...);
extern const char text_803b3c14[], text_803b3c24[], text_803b3c34[], text_803b3c48[];
extern const char key_8041cb08[], key_8041ca50[];
extern char cache_804b06fc, cache_804b077c;
extern "C" void w3d_d26k_net_connect_8021adb8(Ptr32<Net> self) {
    int port;
    {
        PropertyKey key;
        key.name = text_803b3c14;
        read_800fc230(&key, &port);
    }
    Ref host(lookup_8020b680(key_8041cb08));
    String_803426b8 address;
    port = 10017;
    format_8020c510(&address, text_803b3c24, 10017);
    if (reinterpret_cast<HostObject *>(w3d::R(host.p))->table->connect(host.p, address.text) < 0) {
        Ptr32<const void> table;
        { Ptr32<Msg> n = (Ptr32<Msg>)alloc_801613f0(global_804b1754, 8);
        n->id = msgid_8015f5a0(&cache_804b06fc, 1);
        table = table_8040db38;
        n->type = table;
        post_8016239c(n); }
        Ptr32<const char> text;
        {
            PropertyKey key;
            key.name = text_803b3c34;
            text_800fc2b0(&key, &text);
        }
        {
            PropertyKey key;
            key.name = text_803b3c48;
            write_800fc550(&key, text);
        }
        { Ptr32<Msg> n = (Ptr32<Msg>)alloc_801613f0(global_804b1754, 8);
        n->id = msgid_8015f5a0(&cache_804b077c, 1);
        n->type = table;
        post_8016239c(n); }
        base_8015fd1c(self);
        return;
    }
    Ptr32<Client> client = reinterpret_cast<Client *>(w3d::R(lookup_8020b680(key_8041ca50)));
    if (client) client->table->retain(client);
    if (self->client) self->client->table->release(self->client);
    self->client = client;
    if (client->table->start(client, host.p) < 0) {
        Ptr32<Msg> n = (Ptr32<Msg>)alloc_801613f0(global_804b1754, 8);
        n->id = msgid_8015f5a0(&cache_804b077c, 1);
        n->type = table_8040db38;
        post_8016239c(n);
        base_8015fd1c(self);
        return;
    }
    self->owner->team->flags = 1;
}


