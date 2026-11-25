/* Describes an AI plan step (0x8000a4e4): runs the base description (0x8000756c),
 * then appends " -> " and the name of the table entry selected by +16, or
 * "-> Any" when +16 is -1. Field and type names are inferred from the original
 * instructions; the unit owns no data. */
struct String;
extern "C" void w3d_string_init_8020c5c0(String *);
extern "C" unsigned short *w3d_string_header_80341884(String *);
extern "C" void w3d_string_finish_8020c5c4(String *);
extern "C" void w3d_string_release_80341588(String *);
extern "C" int w3d_string_append_8020bf2c(String *, const char *);
struct String {
    const char *text;
    String(const char *);
    String(const String &o) {
        w3d_string_init_8020c5c0(this);
        text = o.text;
        ++*w3d_string_header_80341884(this);
    }
    ~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
    String &operator+=(const String &o) {
        w3d_string_append_8020bf2c(this, o.text);
        return *this;
    }
};
inline String operator+(String a, const String &b)
{
    a += b;
    return a;
}
inline String Prefixed(const String &p, const String &n) { return p + n; }
struct Named { char unknown00[4]; String name; };
struct Table {
    Named **first;
    Named *&operator[](int i) { return first[i]; }
};
extern Table *w3d_ai_table_804aa750;
struct Step { char unknown00[16]; int target; };
extern "C" void w3d_describe_8000756c(Step *, String *);
extern "C" char w3d_string_80369bb4[]; /* " -> " */
extern "C" char w3d_string_80369bbc[]; /* "-> Any" */

extern "C" void w3d_d24a_step_describe_8000a4e4(Step *self, String *out)
{
    w3d_describe_8000756c(self, out);
    if (self->target != -1)
        *out += Prefixed(String(w3d_string_80369bb4), (*w3d_ai_table_804aa750)[self->target]->name);
    else
        *out += String(w3d_string_80369bbc);
}
