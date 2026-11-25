// GWMP8P rev0 0x802b1258. Console command string runner: splits on the
// backslash separator, then posts one message per command by its type sigil.
// Str, Id and Message are partial views; Id is an 8-byte base with
// destructor 0x8015f558 plus a string.
extern "C" void fn_8020c5c4(void *), fn_80341588(void *), fn_8020bb2c(void *);
struct Header {
    unsigned short refs, length, capacity;
    void release() {
        if (!--refs)
            fn_8020bb2c(this);
    }
};
struct Str;
extern "C" void *fn_8020bd38(Str *, const char *);
struct Str {
    char *p;
    void set(const char *t) { fn_8020bd38(this, t); }
    Str();
    Str(const char *);
    Str(const Str &);
    ~Str() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
    unsigned len() const { return *(unsigned short *)(p - 4); }
    void assign(const Str &o) {
        ++((Header *)(o.p - 6))->refs;
        ((Header *)(p - 6))->release();
        p = o.p;
    }
};
extern "C" void fn_8020c3a0(Str *, unsigned);
extern "C" unsigned strcspn(const char *, const char *);
extern "C" void fn_8015f558(void *, int);
struct IdBase {
    char u0[8];
    ~IdBase() { fn_8015f558(this, 2); }
};
struct Id : IdBase {
    Str name;
    Id(const Str &);
};
extern "C" int fn_8015f5a0(Id *, int);
struct Message { unsigned short id; void *table; };
extern void *arena_804b1754;
extern char *separators_804abc64;
extern const char s_803d7a1c[];
extern char table_8040db38[];
extern "C" Message *fn_801613f0(void *, int);
extern "C" Message *fn_8010a8e0(Message *, unsigned short, const char *);
extern "C" Message *fn_80069a0c(Message *, unsigned short, float);
extern "C" Message *fn_800a82f0(Message *, unsigned short, int);
extern "C" int fn_8016239c(Message *);
extern "C" double atof(const char *);
extern "C" int atoi(const char *);
extern "C" void d40l_console_commands_802b1258(const char *commands) {
    if (commands && *commands) {
        Str rest(commands);
        Str cmd;
        while (rest.len()) {
            cmd.assign(rest);
            char *s = cmd.p;
            unsigned k = strcspn(s, s_803d7a1c);
            if (s[k] == '\\') {
                fn_8020c3a0(&cmd, k);
                k++;
                s = cmd.p;
            }
            unsigned j = strcspn(s, separators_804abc64);
            Str name(s);
            if (s[j])
                fn_8020c3a0(&name, j);
            Id id(name);
            switch (s[j]) {
            case '$': {
                Message *m = fn_801613f0(arena_804b1754, 12);
                unsigned short c = fn_8015f5a0(&id, 1);
                fn_8016239c(fn_8010a8e0(m, c, s + j + 1));
                break;
            }
            case '%': {
                Message *m = fn_801613f0(arena_804b1754, 12);
                unsigned short c = fn_8015f5a0(&id, 1);
                fn_8016239c(fn_80069a0c(m, c, atof(s + j + 1)));
                break;
            }
            case '#': {
                Message *m = fn_801613f0(arena_804b1754, 12);
                unsigned short c = fn_8015f5a0(&id, 1);
                fn_8016239c(fn_800a82f0(m, c, atoi(s + j + 1)));
                break;
            }
            case 0: {
                Message *m = fn_801613f0(arena_804b1754, 8);
                m->id = fn_8015f5a0(&id, 1);
                m->table = table_8040db38;
                fn_8016239c(m);
                break;
            }
            }
            s = rest.p;
            rest.set(s + k);
        }
    }
}
