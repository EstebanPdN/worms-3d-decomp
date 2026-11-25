// d24i: 0x8012cf48 (348 bytes). Front-end tick. When +76 is set, reads the
// FE.ToolTip setting (0x800fc2b0), writes its text with "-HACK" appended and
// then the original text back (0x800fc550), which forces listeners to refresh.
// Then runs the two pending counters: +80 calls 0x8012d8c0 and +81 calls
// 0x8012f77c, each decremented once. Returns 100.
struct d24i_String;
extern "C" d24i_String *d24i_string_append_8020bf2c(d24i_String *, const char *);
struct d24i_String {
    char *text;
    d24i_String(const char *);
    d24i_String(const d24i_String &);
    ~d24i_String();
    d24i_String operator+(const char *suffix) const;
    d24i_String &add(const char *suffix) { d24i_string_append_8020bf2c(this, suffix); return *this; }
};
extern "C" void d24i_string_init_8020c5c0(d24i_String *);
extern "C" unsigned short *d24i_string_header_80341884(d24i_String *);
extern "C" void d24i_string_finish_8020c5c4(d24i_String *);
extern "C" void d24i_string_release_80341588(d24i_String *);
inline d24i_String::d24i_String(const d24i_String &other) {
    d24i_string_init_8020c5c0(this);
    text = other.text;
    ++*d24i_string_header_80341884(this);
}
inline d24i_String::~d24i_String() {
    d24i_string_finish_8020c5c4(this);
    d24i_string_release_80341588(this);
}
inline d24i_String d24i_String::operator+(const char *suffix) const {
    return d24i_String(*this).add(suffix);
}
struct d24i_Key {
    const char *name;
    d24i_Key(const char *n) { name = n; }
};
extern "C" int d24i_setting_read_800fc2b0(d24i_Key *, const char **);
extern "C" int d24i_setting_write_800fc550(d24i_Key *, const char *);
struct d24i_Screen {
    unsigned char unknown00[76];
    int refresh_tooltip;                 // +76
    unsigned char pending_a;             // +80
    unsigned char pending_b;             // +81
};
extern "C" void d24i_pending_a_8012d8c0(d24i_Screen *);
extern "C" void d24i_pending_b_8012f77c(d24i_Screen *);
extern const char d24i_tooltip_8039d9e0[];   // "FE.ToolTip"
extern const char d24i_hack_8039d9ec[];      // "-HACK"

extern "C" int d24i_tooltip_tick_8012cf48(d24i_Screen *self) {
    if (self->refresh_tooltip) {
        const char *stored;
        d24i_Key read_key(d24i_tooltip_8039d9e0);
        d24i_setting_read_800fc2b0(&read_key, &stored);
        d24i_String value(stored);
        d24i_Key hack_key(d24i_tooltip_8039d9e0);
        d24i_setting_write_800fc550(&hack_key, (value + d24i_hack_8039d9ec).text);
        d24i_Key restore_key(d24i_tooltip_8039d9e0);
        d24i_setting_write_800fc550(&restore_key, value.text);
    }
    if (self->pending_a) {
        d24i_pending_a_8012d8c0(self);
        --self->pending_a;
    }
    if (self->pending_b) {
        d24i_pending_b_8012f77c(self);
        --self->pending_b;
    }
    return 100;
}
