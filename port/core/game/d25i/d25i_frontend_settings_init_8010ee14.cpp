#include "w3d_ptr.h"
#line 1 "d25i_frontend_settings_init_8010ee14.cpp"
// d25i: 0x8010ee14. Front-end settings setup: subscribes one cached message to
// +48, resolves 18 retained FE list settings into +52..+120 through the cast
// 0x80341584, and reads the five FE.Combo values into +28..+44. Handles have
// one word and a user copy constructor.
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;       // +12
    Ptr32<void (Ptr32<Object>)> release;      // +16
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Key { Ptr32<const char> name; };
struct Ref {
    Ptr32<Object> value;
    Ref() { value = 0; }
    Ref(const Ref &);
    ~Ref() { if (value) value->vtable->release(value); }
};
extern "C" int read_setting_800fc1b0(Ptr32<Key>, Ptr32<void>);
static inline void assign(Ptr32<Object> &slot, Ptr32<Object> value) {
    if (value) value->vtable->retain(value);
    if (slot) slot->vtable->release(slot);
    slot = value;
}
struct MessageId { unsigned short value; };
extern "C" unsigned short cached_id_8015f5a0(Ptr32<void>, int);
extern "C" int subscribe_80162024(Ptr32<void>, Ptr32<MessageId>, Ptr32<void>);
extern "C" int read_colour_800fc370(Ptr32<Key>, Ptr32<int>);
extern char cache_804af308;
struct Frontend {
    unsigned char unknown00[28];
    int fe_combo_user;  // +28
    int fe_combo_fixed;  // +32
    int fe_combo_fixed_alt;  // +36
    int fe_combo_option;  // +40
    int fe_combo_changed;  // +44
    int sub48;  // +48
    Ptr32<Object> fe_tutorial_levels;  // +52
    Ptr32<Object> fe_challenge_levels;  // +56
    Ptr32<Object> fe_custom_levels;  // +60
    Ptr32<Object> fe_random_levels;  // +64
    Ptr32<Object> fe_level_table;  // +68
    Ptr32<Object> fe_scheme_list;  // +72
    Ptr32<Object> fe_worm_names;  // +76
    Ptr32<Object> fe_multi_levels;  // +80
    Ptr32<Object> fe_landscape_types;  // +84
    Ptr32<Object> fe_special_weapon_list;  // +88
    Ptr32<Object> fe_barracks;  // +92
    Ptr32<Object> fe_worms_list;  // +96
    Ptr32<Object> fe_allies_list;  // +100
    Ptr32<Object> fe_teams_in_local_game;  // +104
    Ptr32<Object> fe_pause_options;  // +108
    Ptr32<Object> fe_locked_list;  // +112
    Ptr32<Object> fe_flags_list;  // +116
    Ptr32<Object> fe_sound_banks;  // +120
};
extern "C" Ptr32<Object> cast_80341584(Ptr32<Object>);
static inline void load_80341584(Ptr32<Object> &slot, Ptr32<const char> name) {
    Key key;
    key.name = name;
    Ref found;
    read_setting_800fc1b0(&key, &found);
    assign(slot, cast_80341584(found.value));
}
extern const char n_8039a284[];  // "FE.TutorialLevels"
extern const char n_8039a298[];  // "FE.ChallengeLevels"
extern const char n_8039a2ac[];  // "FE.RandomLevels"
extern const char n_8039a2bc[];  // "FE.CustomLevels"
extern const char n_8039a2cc[];  // "FE.LevelTable"
extern const char n_8039a2dc[];  // "FE.SchemeList"
extern const char n_8039a2ec[];  // "FE.WormNames"
extern const char n_8039a2fc[];  // "FE.MultiLevels"
extern const char n_8039a30c[];  // "FE.Barracks"
extern const char n_8039a318[];  // "FE.WormsList"
extern const char n_8039a328[];  // "FE.AlliesList"
extern const char n_8039a338[];  // "FE.LandscapeTypes"
extern const char n_8039a34c[];  // "FE.TeamsInLocalGame"
extern const char n_8039a360[];  // "FE.PauseOptions"
extern const char n_8039a370[];  // "FE.SoundBanks"
extern const char n_8039a380[];  // "FE.LockedList"
extern const char n_8039a390[];  // "FE.FlagsList"
extern const char n_8039a3a0[];  // "FE.SpecialWeaponList"
extern const char n_8039a3b8[];  // "FE.Combo.User"
extern const char n_8039a3c8[];  // "FE.Combo.Fixed"
extern const char n_8039a3d8[];  // "FE.Combo.Fixed.Alt"
extern const char n_8039a3ec[];  // "FE.Combo.Option"
extern const char n_8039a3fc[];  // "FE.Combo.Changed"
static inline void colour(Ptr32<int> out, Ptr32<const char> name) {
    Key key;
    key.name = name;
    read_colour_800fc370(&key, out);
}
extern "C" void d25i_frontend_settings_init_8010ee14(Ptr32<Frontend> self) {
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af308, 1); subscribe_80162024(self, &id, &self->sub48); }
    load_80341584(self->fe_tutorial_levels, n_8039a284);
    load_80341584(self->fe_challenge_levels, n_8039a298);
    load_80341584(self->fe_random_levels, n_8039a2ac);
    load_80341584(self->fe_custom_levels, n_8039a2bc);
    load_80341584(self->fe_level_table, n_8039a2cc);
    load_80341584(self->fe_scheme_list, n_8039a2dc);
    load_80341584(self->fe_worm_names, n_8039a2ec);
    load_80341584(self->fe_multi_levels, n_8039a2fc);
    load_80341584(self->fe_barracks, n_8039a30c);
    load_80341584(self->fe_worms_list, n_8039a318);
    load_80341584(self->fe_allies_list, n_8039a328);
    load_80341584(self->fe_landscape_types, n_8039a338);
    load_80341584(self->fe_teams_in_local_game, n_8039a34c);
    load_80341584(self->fe_pause_options, n_8039a360);
    load_80341584(self->fe_sound_banks, n_8039a370);
    load_80341584(self->fe_locked_list, n_8039a380);
    load_80341584(self->fe_flags_list, n_8039a390);
    load_80341584(self->fe_special_weapon_list, n_8039a3a0);
    colour(&self->fe_combo_user, n_8039a3b8);
    colour(&self->fe_combo_fixed, n_8039a3c8);
    colour(&self->fe_combo_fixed_alt, n_8039a3d8);
    colour(&self->fe_combo_option, n_8039a3ec);
    colour(&self->fe_combo_changed, n_8039a3fc);
}


