// d30i: 0x801280b4. Parses the command line options (/FS, /NOAI, /LOGICSEED and others) into the settings object; a missing option value returns 0x80004005.
// Word and float views of the settings object.
struct String {
    char *text;
    String(const String &);
    ~String();
};
extern "C" void string_init_8020c5c0(String *);
extern "C" unsigned short *string_header_80341884(String *);
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
extern "C" void string_release_8020bb2c(void *);
inline String::String(const String &o) {
    string_init_8020c5c0(this);
    text = o.text;
    ++*string_header_80341884(this);
}
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
struct Settings {
    unsigned char unknown00[28];
    int w28;
    int w32;
    int w36;
    unsigned w40;
    unsigned char unknown2c[20];
    float f64;
    unsigned char unknown44[8];
    unsigned w76;
    unsigned char unknown50[84];
    int w164;
    int w168;
    int w172;
    unsigned char unknownb0[8];
    float f184;
    unsigned w188;
};
struct Args;
extern "C" Args *args_8015c3ec();
extern "C" unsigned count_8015b424(Args *);
extern "C" String *at_8015b410(Args *, unsigned);
extern "C" void upper_8020c2e8(String *);
extern "C" int strcmp(const char *, const char *);
extern "C" int atoi(const char *);
extern "C" double atof(const char *);
extern "C" unsigned get_801fcd6c();
extern "C" void set_801fcc48(unsigned);
extern "C" void assert_80206a00(int);
extern int music_804aa858, ai_804aa79c, ai_804aa7a0;
extern const char n_8039bf6c[], n_8039bf80[], n_8039bf98[], n_8039bfc0[], n_8039bff0[], n_8039c018[], n_8039c060[], n_8039c07c[], n_8039c098[], n_8039c0b4[], n_8039c0c8[], n_8039c0d8[], n_8039c114[], n_8039c130[], n_8039c154[], n_8039c170[], n_8039c190[], n_8039c1b0[], n_8039c1d4[], n_8039c1e8[], n_8039c204[], n_8039c20c[], n_8039c230[], n_8039c250[], n_8039c29c[], n_8039c2c4[], n_8039c2f0[], n_8039c308[], n_8039c334[], n_8039c380[], n_8039c3a0[], n_8039c3c0[], n_8039c3e4[], n_8039c414[], n_8039c444[], n_8039c474[], n_8039c49c[], n_8039c4ac[], n_8039c4c4[], n_8039c4f0[], n_8039c510[], n_8039c528[], n_8039c554[], n_8039c580[], n_8039c5ac[], n_8039c5d8[], n_8039c600[], n_8039c62c[], n_8039c648[], n_8039c674[], n_8039c6cc[], n_8039c700[];
static inline void copy(String &to, const String &from) {
    char *text = from.text;
    ++*(unsigned short *)(text - 6);
    char *old = to.text;
    unsigned short *header = (unsigned short *)(old - 6);
    unsigned short n = --*header;
    if (n == 0) string_release_8020bb2c(header);
    to.text = from.text;
}
static inline bool operator==(const String &a, const char *b) { return strcmp(a.text, b) == 0; }
static inline void trace(String) {}
// Options are matched after upper-casing; a missing value returns E_FAIL (0x80004005).
extern "C" int d30i_command_line_parse_801280b4(Settings *self) {
    unsigned i = 0;
    Args *args = args_8015c3ec();
    unsigned count = count_8015b424(args);
    for (; i < count; i++) {
        String arg(*at_8015b410(args, i));
        upper_8020c2e8(&arg);
        if (arg == n_8039bf6c) {
            self->w40 |= 0x80000000;
        }
        else if (arg == n_8039bf80) {
            self->w188 &= ~0x2000000;
        }
        else if (arg == n_8039bf98) {
            self->w188 |= 0x2000;
        }
        else if (arg == n_8039bfc0) {
            self->w188 |= 0x10;
        }
        else if (arg == n_8039bff0) {
            self->w188 &= ~0x8;
        }
        else if (arg == n_8039c018) {
            if (i == count - 1) return 0x80004005;
            copy(arg, *at_8015b410(args, ++i));
            self->w168 = atoi(arg.text); trace(arg);
        }
        else if (arg == n_8039c060) {
            if (i == count - 1) return 0x80004005;
            copy(arg, *at_8015b410(args, ++i));
            self->w164 = atoi(arg.text); trace(arg);
        }
        else if (arg == n_8039c07c) {
            if (i == count - 1) return 0x80004005;
            copy(arg, *at_8015b410(args, ++i));
            self->w172 = atoi(arg.text); trace(arg);
        }
        else if (arg == n_8039c098) {
            self->w188 &= 0x7fffffff;
        }
        else if (arg == n_8039c0b4) {
            self->w40 &= 0x7fffffff;
        }
        else if (arg == n_8039c0c8) {
            if (i == count - 1) return 0x80004005;
            copy(arg, *at_8015b410(args, ++i));
            self->w32 = atoi(arg.text); trace(arg);
        }
        else if (arg == n_8039c0d8) {
            if (i == count - 1) return 0x80004005;
            copy(arg, *at_8015b410(args, ++i));
            self->w36 = atoi(arg.text); trace(arg);
        }
        else if (arg == n_8039c114) {
            self->w188 |= 0x40000000;
        }
        else if (arg == n_8039c130) {
            self->w188 &= ~0x40000000;
        }
        else if (arg == n_8039c154) {
            self->w188 |= 0x20000000;
        }
        else if (arg == n_8039c170) {
            self->w188 |= 0x30000000;
        }
        else if (arg == n_8039c190) {
            self->w188 &= ~0x8000000;
        }
        else if (arg == n_8039c1b0) {
            self->w188 |= 0x8000000;
        }
        else if (arg == n_8039c1d4) {
            music_804aa858 = 1;
        }
        else if (arg == n_8039c1e8) {
            music_804aa858 = 0;
        }
        else if (arg == n_8039c204) {
            
        }
        else if (arg == n_8039c20c) {
            self->w188 |= 0x200000;
        }
        else if (arg == n_8039c230) {
            self->w188 &= ~0x200000;
        }
        else if (arg == n_8039c250) {
            if (i == count - 1) return 0x80004005;
        }
        else if (arg == n_8039c29c) {
            self->w188 |= 0x100000;
        }
        else if (arg == n_8039c2c4) {
            self->w188 &= ~0x100000;
        }
        else if (arg == n_8039c2f0) {
            self->w188 &= ~0x80000;
        }
        else if (arg == n_8039c308) {
            self->w188 |= 0x40000;
        }
        else if (arg == n_8039c334) {
            if (i == count - 1) return 0x80004005;
            copy(arg, *at_8015b410(args, ++i));
            self->f64 = atof(arg.text); self->w76 &= ~0x4000000;
        }
        else if (arg == n_8039c380) {
            self->w188 |= 0x2;
        }
        else if (arg == n_8039c3a0) {
            set_801fcc48(get_801fcd6c() | 63);
        }
        else if (arg == n_8039c3c0) {
            self->w28 = 2;
        }
        else if (arg == n_8039c3e4) {
            self->w28 = 1;
        }
        else if (arg == n_8039c414) {
            self->w28 = 6;
        }
        else if (arg == n_8039c444) {
            self->w28 = 7;
        }
        else if (arg == n_8039c474) {
            self->w188 |= 0x1000000;
        }
        else if (arg == n_8039c49c) {
            self->w188 |= 0x200;
        }
        else if (arg == n_8039c4ac) {
            self->w188 |= 0x800000;
        }
        else if (arg == n_8039c4c4) {
            self->w188 &= ~0x80;
        }
        else if (arg == n_8039c4f0) {
            self->w188 &= ~0x40;
        }
        else if (arg == n_8039c510) {
            self->w188 |= 0x400000;
        }
        else if (arg == n_8039c528) {
            ai_804aa79c = 1;
        }
        else if (arg == n_8039c554) {
            ai_804aa79c = 2;
        }
        else if (arg == n_8039c580) {
            ai_804aa7a0 = 1;
        }
        else if (arg == n_8039c5ac) {
            assert_80206a00(0);
        }
        else if (arg == n_8039c5d8) {
            self->w188 |= 0x1000;
        }
        else if (arg == n_8039c600) {
            self->w188 &= ~0x1000;
        }
        else if (arg == n_8039c62c) {
            self->w188 |= 0x800;
        }
        else if (arg == n_8039c648) {
            self->w188 |= 0x400;
        }
        else if (arg == n_8039c674) {
            if (i == count - 1) return 0x80004005;
            copy(arg, *at_8015b410(args, ++i));
            self->f184 = atof(arg.text);
        }
        else if (arg == n_8039c6cc) {
            self->w188 |= 0x1;
        }
        else strcmp(arg.text, n_8039c700);
    }
    return 0;
}
