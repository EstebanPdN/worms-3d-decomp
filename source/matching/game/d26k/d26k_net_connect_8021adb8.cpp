// Network connect (Worms 3D GameCube PAL, 0x8021adb8).
// 
// Reads Net.ServerPort, then points the host service 0x8041cb08 at 127.0.0.1 on
// port 10017. On failure posts two messages around copying Text.InvalidPort into
// Net.ConnectionStatus. On success creates the client 0x8041ca50 at +128, replacing
// the old one, and starts it on the host: failure posts one message, success sets
// the team flags to 1. Failure paths also call the base 0x8015fd1c.

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

struct Msg { unsigned short id; unsigned short pad02; const void *type; };
struct Message { unsigned short id; };
struct Flags { char p0[96]; unsigned pad0 : 9; unsigned flag : 1; unsigned pad1 : 22; };
extern const unsigned char table_8040db38[];
extern void *global_804b1754; extern void *global_804b1788; extern Flags *global_804aac54; extern char *global_804aaf48;
extern "C" void *alloc_801613f0(void *, int);
extern "C" int msgid_8015f5a0(void *, int);
extern "C" int post_8016239c(Msg *);
extern "C" Interface *lookup_8020b680(const void *);
extern "C" int base_8015fd1c(void *);

struct PropertyKey { const char *name; };
struct Host; struct HostTable { void *pad[6]; int (*connect)(Interface *, const char *); };
struct HostObject { HostTable *table; };
struct Client; struct ClientTable { void *pad[3]; int (*retain)(Client *); int (*release)(Client *); void *pad2[7]; int (*start)(Client *, Interface *); };
struct Client { ClientTable *table; };
struct Team { char pad[32]; int flags; };
struct Owner { char pad[24]; Team *team; };
struct Net { char pad0[36]; Owner *owner; char pad1[128 - 40]; Client *client; };
extern "C" int read_800fc230(PropertyKey *, int *);
extern "C" int text_800fc2b0(PropertyKey *, const char **);
extern "C" int write_800fc550(PropertyKey *, const char *);
extern "C" Client *client_8020b680(const void *);
extern "C" int format_8020c510(String_803426b8 *, const char *, ...);
extern const char text_803b3c14[], text_803b3c24[], text_803b3c34[], text_803b3c48[];
extern const char key_8041cb08[], key_8041ca50[];
extern char cache_804b06fc, cache_804b077c;
extern "C" void w3d_d26k_net_connect_8021adb8(Net *self) {
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
    if (reinterpret_cast<HostObject *>(host.p)->table->connect(host.p, address.text) < 0) {
        const void *table;
        { Msg *n = (Msg *)alloc_801613f0(global_804b1754, 8);
        n->id = msgid_8015f5a0(&cache_804b06fc, 1);
        table = table_8040db38;
        n->type = table;
        post_8016239c(n); }
        const char *text;
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
        { Msg *n = (Msg *)alloc_801613f0(global_804b1754, 8);
        n->id = msgid_8015f5a0(&cache_804b077c, 1);
        n->type = table;
        post_8016239c(n); }
        base_8015fd1c(self);
        return;
    }
    Client *client = reinterpret_cast<Client *>(lookup_8020b680(key_8041ca50));
    if (client) client->table->retain(client);
    if (self->client) self->client->table->release(self->client);
    self->client = client;
    if (client->table->start(client, host.p) < 0) {
        Msg *n = (Msg *)alloc_801613f0(global_804b1754, 8);
        n->id = msgid_8015f5a0(&cache_804b077c, 1);
        n->type = table_8040db38;
        post_8016239c(n);
        base_8015fd1c(self);
        return;
    }
    self->owner->team->flags = 1;
}
