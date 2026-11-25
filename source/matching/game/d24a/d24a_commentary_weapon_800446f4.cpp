/* Weapon commentary (0x800446f4): looks up the active worm's player record (+128,
 * 0x80178c48, 0x800fc6dc) and its selected weapon (+132) in the weapon table
 * 0x803eb63c (0x800fc330), reads the weapon's text property (+96). When the weapon
 * type derives from 0x80368328 it formats the name with the worm's ammunition: a
 * time and a unit (+536 set), a count (+484 set), or the name alone; other weapons
 * use the name alone. Plays the text through the interrupt 0x80044638. Field and
 * type names are inferred from the original instructions. Strings are external
 * views of original data; the unit owns no data. */
struct String;
extern "C" void w3d_string_init_8020c5c0(String *);
extern "C" unsigned short *w3d_string_header_80341884(String *);
extern "C" void w3d_string_finish_8020c5c4(String *);
extern "C" void w3d_string_release_80341588(String *);
struct String {
    const char *text;
    String();
    String(const String &o) {
        w3d_string_init_8020c5c0(this);
        text = o.text;
        ++*w3d_string_header_80341884(this);
    }
    ~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
};
struct PropertyKey { const char *name; };
struct TypeInfo { char unknown00[20]; TypeInfo *parent; };
struct Weapon;
struct WeaponVtable { void *unknown00[5]; TypeInfo *(*type)(Weapon *); };
struct Weapon {
    WeaponVtable *vtable;
    char unknown04[92];
    const char *textName;      /* +96 */
    char unknown100[384];
    int hasCount;              /* +484 */
    char unknown488[48];
    int hasTime;               /* +536 */
};
struct Key { int value; };
struct PlayerRecord {
    char unknown00[104];
    int count;                 /* +104 */
    char unknown108[4];
    int time;                  /* +112 */
    char unknown116[16];
    int weapon;                /* +132 */
};
struct Object;
struct Commentary { char unknown00[128]; Object *activeWormIndex; };
extern "C" Object *w3d_identity_803426b4(Object *);
extern "C" int w3d_object_int_80178c48(Object *);
extern "C" PlayerRecord *w3d_player_800fc6dc(int);
extern "C" int w3d_weapon_lookup_800fc330(Key *, Weapon **);
extern "C" int w3d_string_property_800fc2b0(PropertyKey *, const char **);
extern "C" void w3d_string_format_8020c510(String *, const char *, ...);
extern "C" void w3d_interrupt_80044638(Commentary *, String);
extern Key w3d_weapons_803eb63c[];
extern TypeInfo w3d_type_80368328[];
extern "C" char w3d_string_80374f2c[], w3d_string_80374f3c[], w3d_string_80374f48[], w3d_string_80374f54[],
    w3d_string_80374f60[], w3d_string_80374f6c[], w3d_string_80374f74[];

inline bool IsKindOf(TypeInfo *type, TypeInfo *base)
{
    while (type != base) {
        if (type == type->parent) return false;
        type = type->parent;
    }
    return true;
}

extern "C" void w3d_d24a_commentary_weapon_800446f4(Commentary *self)
{
    String text;
    PlayerRecord *record = w3d_player_800fc6dc(w3d_object_int_80178c48(w3d_identity_803426b4(self->activeWormIndex)));
    Weapon *weapon;
    w3d_weapon_lookup_800fc330(&w3d_weapons_803eb63c[record->weapon], &weapon);
    Weapon *held = weapon;
    PropertyKey nameKey;
    const char *name;
    nameKey.name = held->textName;
    w3d_string_property_800fc2b0(&nameKey, &name);
    if (IsKindOf(held->vtable->type(held), w3d_type_80368328)) {
        Weapon *current;
        w3d_weapon_lookup_800fc330(&w3d_weapons_803eb63c[record->weapon], &current);
        Weapon *ammo = current;
        PropertyKey k1;
        const char *seconds;
        k1.name = w3d_string_80374f2c;
        w3d_string_property_800fc2b0(&k1, &seconds);
        PropertyKey k2;
        const char *bounce;
        k2.name = w3d_string_80374f3c;
        w3d_string_property_800fc2b0(&k2, &bounce);
        PropertyKey k3;
        const char *lowest;
        k3.name = w3d_string_80374f48;
        w3d_string_property_800fc2b0(&k3, &lowest);
        PropertyKey k4;
        const char *highest;
        k4.name = w3d_string_80374f54;
        w3d_string_property_800fc2b0(&k4, &highest);
        int time = record->time;
        int count = record->count;
        if (ammo->hasTime) {
            w3d_string_format_8020c510(&text, w3d_string_80374f60, name, time, seconds);
        } else if (ammo->hasCount) {
            w3d_string_format_8020c510(&text, w3d_string_80374f6c, name, count);
        } else {
            w3d_string_format_8020c510(&text, w3d_string_80374f74, name);
        }
    } else {
        w3d_string_format_8020c510(&text, w3d_string_80374f74, name);
    }
    String copy(text);
    w3d_interrupt_80044638(self, copy);
}
