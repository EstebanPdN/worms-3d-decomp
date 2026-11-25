// d31i: 0x801096f0. Reads the property named by key and replaces a %i, %d or
// (%s) placeholder in the text with its value.
struct String {
    char *text;
    String(const char *);
    String(const String &);
    ~String();
    void operator=(const String &o);
    void operator+=(const char *o);
    bool operator==(const char *o) const;
    unsigned short Length() const { return *(unsigned short *)(text - 4); }
};
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
extern "C" void string_release_8020bb2c(void *);
extern "C" void string_init_8020c5c0(String *);
extern "C" unsigned short *string_header_80341884(String *);
extern "C" void * string_append_8020bf2c(String *, const char *);
extern "C" char **string_assign_8020bd38(String *, const char *);
extern "C" void string_format_8020c510(String *, const char *, ...);
extern "C" int strcmp(const char *, const char *);
extern "C" int atoi(const char *);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
inline String::String(const String &o) {
    string_init_8020c5c0(this);
    text = o.text;
    ++*string_header_80341884(this);
}
inline void String::operator=(const String &o) {
    ++*(unsigned short *)(o.text - 6);
    unsigned short *h = (unsigned short *)(text - 6);
    unsigned short n = --*h;
    if (n == 0) string_release_8020bb2c(h);
    text = o.text;
}
inline void String::operator+=(const char *o) { string_append_8020bf2c(this, o); }
inline String operator+(const String &a, const String &b) { String r = a; r += b.text; return r; }
inline String operator+(const String &a, const char *b) { String r = a; r += b; return r; }
inline bool String::operator==(const char *o) const { return strcmp(text, o) == 0; }
struct Key { const char *name; };
extern "C" int read_text_800fc2b0(Key *, const char **);
extern "C" void replace_all_801099a4(void *, void *, const char *, const char *);
extern const char s_80399cc8[], s_80399c88[], s_80399c98[], s_80399c5c[], s_80399cd0[], s_80399cd4[];
extern "C" void d31i_stat_text_replace_801096f0(void *a, void *b, const char *name, const char *key) {
    String kind(name);
    if (kind.Length() == 0) return;
    const char *out = 0;
    if (read_text_800fc2b0((Key *)&key, &out) < 0) return;
    String value(out);
    if (value.Length() == 0) string_assign_8020bd38(&value, s_80399cc8);
    if (kind == s_80399c88 || kind == s_80399c98)
        string_format_8020c510(&value, s_80399c98, atoi(value.text));
    if (kind == s_80399c5c) {
        String wrapped = String(s_80399cd0) + value + s_80399cd4;
        value = wrapped;
    }
    replace_all_801099a4(a, b, name, value.text);
}
