// GWMP8P rev0 0x8003904c. Sends the text in GS.OutBox as a chat message:
// finds the active worm and its team, takes the login nick as the sender,
// asks the object for the target and body, picks a packet type by command
// class (all, whisper, team or system with an empty sender), fills in and
// sends the packet, and shows the line locally when it is not addressed to
// the sender. Names are inferred from the original strings and instructions.
struct String;
extern "C" void w3d_string_base_finish(String *);
extern "C" void w3d_string_release(String *);
extern "C" void w3d_string_release_header(void *);
struct String {
    const char *text;
    String();
    String(const char *);
    String(const String &o);
    ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
    String &operator=(const String &o) {
        ++*(unsigned short *)(o.text - 6);
        unsigned short *h = (unsigned short *)(text - 6);
        if (--*h == 0) w3d_string_release_header(h);
        text = o.text;
        return *this;
    }
};
struct Object;
struct ObjectVtable { void *unknown00[3]; void (*retain)(Object *); void (*release)(Object *); };
struct Object { ObjectVtable *vtable; };
struct Packet : Object { char pad[24]; String a; String b; String c; };
struct Handle {
    Packet *value;
    Handle() : value(0) {}
    Handle(Packet *next) : value(next) { if (value) value->vtable->retain(value); }
    Handle(const Handle &);
    ~Handle() { if (value) value->vtable->release(value); }
    Handle &operator=(Packet *next) {
        if (next) next->vtable->retain(next);
        if (value) value->vtable->release(value);
        value = next;
        return *this;
    }
};
struct Team { char pad[60]; unsigned char id; };
struct Worm { char pad[213]; unsigned char team; };
struct Self;
struct SelfTable { char pad[40]; void (*target)(Self *, const char *, String *); void (*body)(Self *, const char *, String *); };
struct Self { SelfTable *t; char pad[52]; Worm *worm; Team *team; };
struct Net { char pad[24]; void *link; };
struct Holder { char pad[36]; Net *net; };
struct ChatLine { int words[6]; };
extern Holder *g_holder_804abac0;
extern String g_empty_804b06a0[];
extern char g_key_8041ab18[], g_key_8041ab28[], g_key_8041ab38[], g_key_8041ab48[];
extern char s_80374064[], s_80374070[], s_80374080[];
extern "C" int w3d_auto_800fc1f0(const char **, int *);
extern "C" int w3d_auto_800fc2b0(const char **, const char **);
extern "C" Worm *s8_index_query_800fc6dc(int);
extern "C" Team *s8_index_query_800fc7f8(int);
extern "C" int w3d_auto_80039b6c(Self *, const char *);
extern "C" Packet *w3d_s10_service_forward_8020b680(const void *);
extern "C" int w3d_d26k_send_serialized_8021e930(void *, Packet *);
extern "C" int strcmp(const char *, const char *);
extern "C" ChatLine *w3d_cx7a_message_construct_800a4ed0(ChatLine *, int, int, const char *, const char *, const char *);
extern "C" void fn_800396a8(Self *, ChatLine *);
extern "C" void w3d_d32a_chat_message_send_8003904c(Self *self)
{
    const char *n1 = s_80374064;
    const char *text;
    w3d_auto_800fc2b0(&n1, &text);
    const char *n2 = s_80374070;
    int idx = 0;
    w3d_auto_800fc1f0(&n2, &idx);
    self->worm = s8_index_query_800fc6dc(idx);
    self->team = s8_index_query_800fc7f8(self->worm->team);
    const char *n3 = s_80374080;
    const char *nick;
    w3d_auto_800fc2b0(&n3, &nick);
    String from(nick);
    String to;
    String body;
    self->t->target(self, text, &to);
    self->t->body(self, text, &body);
    Handle packet;
    switch (w3d_auto_80039b6c(self, text)) {
    case 3: {
        from = g_empty_804b06a0[0];
        Packet *q = w3d_s10_service_forward_8020b680(g_key_8041ab28);
        packet = q;
        Handle p(q);
        p.value->a = body;
        p.value->b = from;
        break;
    }
    case 0: {
        Packet *q = w3d_s10_service_forward_8020b680(g_key_8041ab18);
        packet = q;
        Handle p(q);
        p.value->a = body;
        p.value->b = from;
        break;
    }
    case 1: {
        Packet *q = w3d_s10_service_forward_8020b680(g_key_8041ab38);
        packet = q;
        Handle p(q);
        p.value->b = body;
        p.value->c = from;
        p.value->a = to;
        break;
    }
    case 2: {
        Packet *q = w3d_s10_service_forward_8020b680(g_key_8041ab48);
        packet = q;
        Handle p(q);
        p.value->a = body;
        p.value->b = from;
        break;
    }
    }
    w3d_d26k_send_serialized_8021e930(g_holder_804abac0->net->link, packet.value);
    if (strcmp(from.text, to.text) != 0 || w3d_auto_80039b6c(self, text) == 3) {
        ChatLine line;
        w3d_cx7a_message_construct_800a4ed0(&line, 0, w3d_auto_80039b6c(self, text), from.text, to.text, body.text);
        fn_800396a8(self, &line);
    }
}
