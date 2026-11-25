/* Worms 3D GameCube PAL 0x800606e4. Rewrites a land name carrying a theme prefix: compares the leading characters of the name at +64 with ENGLAND, PIRATE, HORROR, WAR and LUNAR, keeps the remainder, and when one matched replaces the name with the Land.Theme setting followed by that remainder. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct Name;
extern "C" void string_finish_8020c5c4(Name *);
extern "C" void string_release_80341588(Name *);
struct Name {
    char *text;
    Name(const char *);
    ~Name() { string_finish_8020c5c4(this); string_release_80341588(this); }
    unsigned short length() const { return ((unsigned short *)text)[-2]; }
    Name(const Name &);
};
extern "C" int strcmp(const char *, const char *);
extern "C" void *prefix_8020c048(Name *, const Name *, int);
extern "C" void *suffix_8020c0fc(Name *, const Name *, int);
extern "C" void *assign_8020bd38(Name *, const char *);
extern "C" void *append_8020bf2c(Name *, const char *);
inline bool operator==(const Name &a, const char *b) { return strcmp(a.text, b) == 0; }
struct Key { const char *text; };
extern "C" int read_800fc2b0(Key *, const char **);
struct Self { char u0[64]; Name name; };
extern const char empty_8037917c[], s_80379180[], s_80379188[], s_80379190[], s_80379198[], s_8037919c[], s_803791a4[];
extern "C" void w3d_d24g_land_theme_name_800606e4(Self *self)
{
    Name rest(empty_8037917c);
    int themed = 0;
    Name prefix(empty_8037917c);
    prefix_8020c048(&prefix, &self->name, 7);
    if (prefix == s_80379180) { themed = 1; suffix_8020c0fc(&rest, &self->name, self->name.length() - 7); }
    prefix_8020c048(&prefix, &self->name, 6);
    if (prefix == s_80379188) { themed = 1; suffix_8020c0fc(&rest, &self->name, self->name.length() - 6); }
    if (prefix == s_80379190) { themed = 1; suffix_8020c0fc(&rest, &self->name, self->name.length() - 6); }
    prefix_8020c048(&prefix, &self->name, 3);
    if (prefix == s_80379198) { themed = 1; suffix_8020c0fc(&rest, &self->name, self->name.length() - 3); }
    prefix_8020c048(&prefix, &self->name, 5);
    if (prefix == s_8037919c) { themed = 1; suffix_8020c0fc(&rest, &self->name, self->name.length() - 5); }
    if (themed) {
        Key key;
        const char *theme;
        key.text = s_803791a4;
        read_800fc2b0(&key, &theme);
        assign_8020bd38(&self->name, theme);
        append_8020bf2c(&self->name, rest.text);
    }
}
