#include "w3d_ptr.h"
#line 1 "d40l_console_commands_802b1258.cpp"
// GWMP8P rev0 0x802b1258. Console command string runner: splits on the
// backslash separator, then posts one message per command by its type sigil.
// Str, Id and Message are partial views; Id is an 8-byte base with
// destructor 0x8015f558 plus a string.
extern "C" void fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>), fn_8020bb2c(Ptr32<void>);
struct Header {
    unsigned short refs, length, capacity;
    void release() {
        if (!--refs)
            fn_8020bb2c(this);
    }
};
struct Str;
extern "C" Ptr32<void> fn_8020bd38(Ptr32<Str>, Ptr32<const char>);
struct Str {
    Ptr32<char> p;
    void set(Ptr32<const char> t) { fn_8020bd38(this, t); }
    Str();
    template <class W3dU> Str(Ptr32<W3dU> w3d_p) : Str((const char *)w3d_p.get()) {}
 Str(const char *);
    Str(const Str &);
    ~Str() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
    unsigned len() const { return *(Ptr32<unsigned short>)(p - 4); }
    void assign(const Str &o) {
        ++((Ptr32<Header>)(o.p - 6))->refs;
        ((Ptr32<Header>)(p - 6))->release();
        p = o.p;
    }
};
extern "C" void fn_8020c3a0(Ptr32<Str>, unsigned);
extern "C" unsigned strcspn(Ptr32<const char>, Ptr32<const char>);
extern "C" void fn_8015f558(Ptr32<void>, int);
struct IdBase {
    char u0[8];
    ~IdBase() { fn_8015f558(this, 2); }
};
struct Id : IdBase {
    Str name __attribute__((aligned(__alignof__(IdBase))));
    Id(const Str &);
};
extern "C" int fn_8015f5a0(Ptr32<Id>, int);
struct Message { unsigned short id; Ptr32<void> table; };
extern Ptr32<void> arena_804b1754;
extern Ptr32<char> separators_804abc64;
extern const char s_803d7a1c[];
extern char table_8040db38[];
extern "C" Ptr32<Message> fn_801613f0(Ptr32<void>, int);
extern "C" Ptr32<Message> fn_8010a8e0(Ptr32<Message>, unsigned short, Ptr32<const char>);
extern "C" Ptr32<Message> fn_80069a0c(Ptr32<Message>, unsigned short, float);
extern "C" Ptr32<Message> fn_800a82f0(Ptr32<Message>, unsigned short, int);
extern "C" int fn_8016239c(Ptr32<Message>);
extern "C" double atof(Ptr32<const char>);
extern "C" int atoi(Ptr32<const char>);
extern "C" void d40l_console_commands_802b1258(Ptr32<const char> commands) {
    if (commands && *commands) {
        Str rest(commands);
        Str cmd;
        while (rest.len()) {
            cmd.assign(rest);
            Ptr32<char> s = cmd.p;
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
                Ptr32<Message> m = fn_801613f0(arena_804b1754, 12);
                unsigned short c = fn_8015f5a0(&id, 1);
                fn_8016239c(fn_8010a8e0(m, c, s + j + 1));
                break;
            }
            case '%': {
                Ptr32<Message> m = fn_801613f0(arena_804b1754, 12);
                unsigned short c = fn_8015f5a0(&id, 1);
                fn_8016239c(fn_80069a0c(m, c, atof(s + j + 1)));
                break;
            }
            case '#': {
                Ptr32<Message> m = fn_801613f0(arena_804b1754, 12);
                unsigned short c = fn_8015f5a0(&id, 1);
                fn_8016239c(fn_800a82f0(m, c, atoi(s + j + 1)));
                break;
            }
            case 0: {
                Ptr32<Message> m = fn_801613f0(arena_804b1754, 8);
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


