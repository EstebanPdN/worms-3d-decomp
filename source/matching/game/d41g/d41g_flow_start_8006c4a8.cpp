// GWMP8P rev0 0x8006c4a8. Game flow start: loads the title and menu timeout
// resources, subscribes to its messages, parses the command line options and
// posts the matching debug messages, then starts the default level.
struct String;
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
extern "C" void string_init_8020c5c0(String *);
extern "C" unsigned short *string_header_80341884(String *);
struct String {
    char *text;
    String(const String &o) {
        string_init_8020c5c0(this);
        text = o.text;
        ++*string_header_80341884(this);
    }
    ~String() { string_finish_8020c5c4(this); string_release_80341588(this); }
    unsigned short length() const { return ((unsigned short *)text)[-2]; }
};
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Message { unsigned short id; const void *vtable; };
struct Object;
struct ObjectVtable { void *u[3]; void (*retain)(Object *); void (*release)(Object *); };
struct Object { ObjectVtable *vtable; };
struct Ref {
    Ref() {}
    Ref(const Ref &);
    Object *value;
    ~Ref() { if (value) value->vtable->release(value); }
};
struct Key { const char *text; };
struct Sound { struct V { void *u[15]; int (*load)(Sound *, void *, void *); } *vtable; };
struct App { char u0[76]; unsigned flags; char u80[28]; Sound *sound; };
struct Bits { unsigned top : 1; unsigned rest : 31; };
struct Self { char u0[240]; union { unsigned flags; Bits bits; }; Object *gameOver; Object *titleTimeout; Object *menuTimeout; };
extern App *app_804b1788;
extern void *arg_804aa840;
extern char data_803ebc18[];
extern void *arena_804b1754;
extern char vt_8040db38[];
extern MessageCache c_804ad6ac, c_804ad6b4, c_804ad6bc, c_804ad6c4, c_804ad6cc, c_804ad6d4, c_804ad6dc, c_804ad6e4, c_804ad6ec, c_804ad6f4, c_804ad6fc, c_804ad704, c_804ad714, c_804ad71c, c_804ad724, c_804ad72c, c_804ad734, c_804ad75c, c_804ad764, c_804ad76c, c_804ad784, c_804ad7cc, c_804ad7d4, c_804ad7dc, c_804ad7e4, c_804ad7ec, c_804ad82c, c_804ad864;
extern "C" int read_800fc1b0(Key *, void *);
extern "C" int read_str_800fc2b0(Key *, const char **);
extern "C" Object *as_80342a78(Object *);
extern "C" void *args_8015c3ec();
extern "C" unsigned count_8015b424(void *);
extern "C" String *arg_8015b410(void *, unsigned);
extern "C" void finish_8006eebc(Self *);
extern "C" int message_id_8015f5a0(MessageCache *, int);
extern "C" int subscribe_80162024(Self *, const unsigned short &, void *);
extern "C" void upper_8020c2e8(String *);
extern "C" void *suffix_8020c0fc(String *, const String *, int);
extern "C" int strcmp(const char *, const char *);
extern "C" void *arena_alloc_801613f0(void *, int);
extern "C" int message_post_8016239c(void *);
extern "C" void *message_string_8010a8e0(void *, int, const char *);
extern "C" void set_mode_8006ab48(Self *, int, int, int, int);
inline bool named(const String &s, const char *n) { return strcmp(s.text, n) == 0; }
inline bool named2(const String &s, const char *n) { return named(s, n); }
#define READ(slot, name, none) { \
    Ref r; \
    r.value = none; \
    Key key; \
    key.text = name; \
    Ref *p = &r; read_800fc1b0(&key, p); \
    Object *o = as_80342a78(r.value); \
    if (o) o->vtable->retain(o); \
    if (self->slot) self->slot->vtable->release(self->slot); \
    self->slot = o; \
}
#define POST(cache) { \
    Message *m = (Message *)arena_alloc_801613f0(arena_804b1754, 8); \
    m->id = message_id_8015f5a0(cache, 1); \
    m->vtable = vt_8040db38; \
    message_post_8016239c(m); \
}
extern "C" void d41g_flow_start_8006c4a8(Self *self)
{
    {
    Object *zero = 0;
    READ(titleTimeout, "FCS.TitleScreenTimeout", zero)
    READ(menuTimeout, "FCS.MainMenuTimeout", zero)
    }
    void *args = args_8015c3ec();
    int plus = 0;
    int found = 0;
    unsigned i = 0;
    unsigned count = count_8015b424(args);
    {
    self->flags &= ~0x00800000;
    app_804b1788->sound->vtable->load(app_804b1788->sound, arg_804aa840, data_803ebc18);
    finish_8006eebc(self);
    subscribe_80162024(self, message_id_8015f5a0(&c_804ad6ac, 1), (char *)self + 32);
    subscribe_80162024(self, message_id_8015f5a0(&c_804ad6b4, 1), (char *)self + 36);
    subscribe_80162024(self, message_id_8015f5a0(&c_804ad6bc, 1), (char *)self + 40);
    subscribe_80162024(self, message_id_8015f5a0(&c_804ad6c4, 1), (char *)self + 44);
    subscribe_80162024(self, message_id_8015f5a0(&c_804ad6cc, 1), (char *)self + 52);
    subscribe_80162024(self, message_id_8015f5a0(&c_804ad6d4, 1), (char *)self + 56);
    subscribe_80162024(self, message_id_8015f5a0(&c_804ad6dc, 1), (char *)self + 60);
    subscribe_80162024(self, message_id_8015f5a0(&c_804ad6e4, 1), (char *)self + 64);
    subscribe_80162024(self, message_id_8015f5a0(&c_804ad6ec, 1), (char *)self + 68);
    subscribe_80162024(self, message_id_8015f5a0(&c_804ad6f4, 1), (char *)self + 80);
    subscribe_80162024(self, message_id_8015f5a0(&c_804ad71c, 1), (char *)self + 88);
    subscribe_80162024(self, message_id_8015f5a0(&c_804ad724, 1), (char *)self + 92);
    subscribe_80162024(self, message_id_8015f5a0(&c_804ad72c, 1), (char *)self + 96);
    subscribe_80162024(self, message_id_8015f5a0(&c_804ad734, 1), (char *)self + 100);
    subscribe_80162024(self, message_id_8015f5a0(&c_804ad6fc, 1), (char *)self + 104);
    subscribe_80162024(self, message_id_8015f5a0(&c_804ad76c, 1), (char *)self + 124);
    subscribe_80162024(self, message_id_8015f5a0(&c_804ad75c, 1), (char *)self + 128);
    subscribe_80162024(self, message_id_8015f5a0(&c_804ad764, 1), (char *)self + 132);
    subscribe_80162024(self, message_id_8015f5a0(&c_804ad784, 1), (char *)self + 140);
    subscribe_80162024(self, message_id_8015f5a0(&c_804ad7e4, 1), (char *)self + 148);
    subscribe_80162024(self, message_id_8015f5a0(&c_804ad7dc, 1), (char *)self + 152);
    subscribe_80162024(self, message_id_8015f5a0(&c_804ad7ec, 1), (char *)self + 156);
    subscribe_80162024(self, message_id_8015f5a0(&c_804ad7cc, 1), (char *)self + 164);
    subscribe_80162024(self, message_id_8015f5a0(&c_804ad82c, 1), (char *)self + 160);
    subscribe_80162024(self, message_id_8015f5a0(&c_804ad704, 1), (char *)self + 144);
    subscribe_80162024(self, message_id_8015f5a0(&c_804ad864, 1), (char *)self + 172);
    subscribe_80162024(self, message_id_8015f5a0(&c_804ad7d4, 1), (char *)self + 176);
    subscribe_80162024(self, message_id_8015f5a0(&c_804ad714, 1), (char *)self + 180);
    for (; i < count; i++) {

        String arg(*arg_8015b410(args, i));
        int isOption = 0;
        upper_8020c2e8(&arg);
        char c = arg.text[0];
        if (c == '/') {
            isOption = 1;
            String copy(arg);
            suffix_8020c0fc(&arg, &copy, copy.length() - 1);
        } else if (c == '+') {
            plus = 1;
            isOption = 1;
            String copy(arg);
            suffix_8020c0fc(&arg, &copy, copy.length() - 1);
        }
        if (isOption) {
            if (named(arg, "ANDY")) {
                found = 1;
                POST(&c_804ad6ac)
            } else
            if (named(arg, "CHARLES")) {
                found = 1;
                POST(&c_804ad6b4)
            } else
            if (named(arg, "IAN")) {
                found = 1;
                POST(&c_804ad6bc)
            } else
            if (named2(arg, "MARTIN")) {
                found = 1;
                POST(&c_804ad6c4)
            } else
            if (named2(arg, "DAMO")) {
                found = 1;
                POST(&c_804ad6cc)
            } else
            if (named2(arg, "PAUL")) {
                found = 1;
                POST(&c_804ad6d4)
            } else
            if (named2(arg, "PHIL")) {
                found = 1;
                POST(&c_804ad6dc)
            } else
            if (named2(arg, "STEVE")) {
                found = 1;
                POST(&c_804ad6e4)
            } else
            if (named2(arg, "JAMES")) {
                found = 1;
                POST(&c_804ad6ec)
            } else
            if (named(arg, "HOST")) {
            } else if (named(arg, "JOIN")) {
            } else if (named(arg, "NOAUTOLOOP")) {
                self->flags &= 0x7fffffff;
            } else if (named(arg, "VALIDATEGAMESTATE")) {
                self->flags |= 0x00100000;
            }
        }
    }
    if (!found || plus) {
        app_804b1788->flags |= 0x40000000;
        set_mode_8006ab48(self, 0, 0, 0, 0);
    }
    const char *level;
    { Key key; key.text = "Game.DefaultLevel"; read_str_800fc2b0(&key, &level); }
    {
        void *m = arena_alloc_801613f0(arena_804b1754, 12);
        message_post_8016239c(message_string_8010a8e0(m, (unsigned short)message_id_8015f5a0(&c_804ad76c, 1), level));
    }
    {
    Ref r;
    Key key;
    key.text = "FCS.GameOver";
    r.value = 0;
    Ref *p = &r; read_800fc1b0(&key, p);
    Object *o = as_80342a78(r.value);
    if (o) o->vtable->retain(o);
    if (self->gameOver) self->gameOver->vtable->release(self->gameOver);
    self->gameOver = o;
    }
    }
}
