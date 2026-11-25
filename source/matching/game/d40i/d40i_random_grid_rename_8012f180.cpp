// d40i: 0x8012f180. Picks a random entry from a grid: draws column and row
// through 0x80161080 until the entry's message name at +128 equals
// WeaponPanel.PlaySound, then renames it to Weapon.PanelChanged#%d with the
// given number. The row variable is shared by both draws, which makes it a
// global pseudo.
struct d40i_String {
    char *text;
    d40i_String();
    d40i_String(const d40i_String &);
    d40i_String(const char *);
    ~d40i_String();
    d40i_String &operator=(const d40i_String &other);
    bool operator!=(const char *other) const;
};
struct d40i_Entry {
    unsigned char unknown00[128];
    d40i_String name;                    // +128
};
extern "C" void d40i_string_finish_8020c5c4(d40i_String *);
extern "C" void d40i_string_release_80341588(d40i_String *);
extern "C" void d40i_release_header_8020bb2c(unsigned short *);
extern "C" void d40i_string_format_8020c510(d40i_String *, const char *, ...);
extern "C" int strcmp(const char *, const char *);
extern "C" unsigned d40i_random_80161080(void *);
inline d40i_String::~d40i_String() {
    d40i_string_finish_8020c5c4(this);
    d40i_string_release_80341588(this);
}
inline d40i_String &d40i_String::operator=(const d40i_String &other) {
    // The allocation header begins six bytes before the text; its reference
    // counter is unsigned sixteen-bit.
    ++reinterpret_cast<unsigned short *>(other.text)[-3];
    unsigned short *header = reinterpret_cast<unsigned short *>(text) - 3;
    if (--*header == 0)
        d40i_release_header_8020bb2c(header);
    text = other.text;
    return *this;
}
inline bool d40i_String::operator!=(const char *other) const { return strcmp(text, other) != 0; }
static inline unsigned d40i_random_below(void *random, unsigned limit) { return d40i_random_80161080(random) % limit; }
extern const char d40i_empty_8039d9b0[], d40i_play_sound_8039dc40[], d40i_changed_8039dc68[];

extern "C" void d40i_random_grid_rename_8012f180(void *random, int number, d40i_Entry **entries, unsigned width, unsigned height) {
    unsigned column = d40i_random_below(random, width);
    unsigned row = d40i_random_below(random, height); d40i_Entry *entry = entries[row * width + column];
    d40i_String name(d40i_empty_8039d9b0);
    name = entry->name;
    while (name != d40i_play_sound_8039dc40) {
        column = d40i_random_below(random, width);
        row = d40i_random_below(random, height); entry = entries[row * width + column];
        name = entry->name;
    }
    d40i_String text;
    d40i_string_format_8020c510(&text, d40i_changed_8039dc68, number);
    entry->name = text;
}
