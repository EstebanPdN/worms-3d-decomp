// GWMP8P rev0 0x80050c20. Cheat key handler: space unlocks the resources of
// nearly every entry, a letter from the cheat alphabet (0x804aa9fc) unlocks
// one entry, escape and space refresh the options page. Field and type names
// are inferred from the original instructions; strings and globals are
// external views of original data.
struct String;
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
extern "C" void string_init_8020c5c0(String *);
extern "C" unsigned short *string_header_80341884(String *);
extern "C" void string_upper_8020c2e8(String *);
extern "C" void * string_append_8020bf2c(String *, const char *);
struct String {
    char *text;
    String(const char *);
    String(const char *, int, int);
    const char *c_str() const { return text; }
    String(const String &o) {
        string_init_8020c5c0(this);
        text = o.text;
        ++*string_header_80341884(this);
    }
    ~String() { string_finish_8020c5c4(this); string_release_80341588(this); }
    String &operator+=(const char *t) { string_append_8020bf2c(this, t); return *this; }
    String &operator+=(const String &t) { string_append_8020bf2c(this, t.text); return *this; }
};
inline String operator+(const String &a, const char *b)
{
    String r = a;
    r += b;
    return r;
}
inline String operator+(const String &a, const String &b)
{
    String r = a;
    r += b;
    return r;
}
extern const char *names_803fcce0[];
extern const char *alphabet_804aa9fc;
extern const char s_80378128[], s_80378130[], s_80378138[];
extern "C" int unlock_800fd440(const char *, unsigned char, int);
extern "C" void refresh_8004fe48(void *);
extern "C" char *strchr(const char *, int);
#define UNLOCK(id) \
    unlock_800fd440((String(s_80378128) + name + s_80378130).text, id, 1); \
    unlock_800fd440((String(s_80378128) + name + s_80378138).text, id, 2);
extern "C" void w3d_d33g_cheat_key_80050c20(void *self, char key)
{
    switch (key) {
    case 32:
        for (unsigned i = 0; i <= 13; i++) {
            if (i > 1 && i != 9) {
                String name(names_803fcce0[i]);
                unsigned char id = i;
                UNLOCK(id)
            }
        }
        refresh_8004fe48(self);
        break;
    case 27:
        refresh_8004fe48(self);
        break;
    default: {
        String letter(&key, 0, 1);
        string_upper_8020c2e8(&letter);
        char *p = strchr(alphabet_804aa9fc, *letter.c_str());
        if (p == 0) return;
        unsigned id = p - alphabet_804aa9fc;
        if (id <= 13) {
            String name(names_803fcce0[id]);
            unsigned char id8 = id;
            UNLOCK(id8)
            refresh_8004fe48(self);
        }
        break;
    }
    }
}
