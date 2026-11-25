#include "w3d_ptr.h"
#line 1 "d25i_weapon_panel_init_8012d0a4.cpp"
// d25i: 0x8012d0a4. Weapon panel setup: resolves ActiveWormIndex, reads
// FE.WeaponPanel and Inventory.WeaponDelays, resolves eight retained settings,
// enables the two WeaponsPanel flags, subscribes 23 cached messages, clears
// +16 of the last subscription's object and closes WeaponPanel.Open. Handles
// have one word and a user copy constructor.
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
extern "C" void set_value_80178d28(Ptr32<Object>, Ptr32<int>);
struct Panel {
    unsigned char unknown00[28];
    Ptr32<Object> active_worm_index;  // +28
    int weapon_panel;  // +32
    int weapon_delays;  // +36
    Ptr32<Object> fe_highlighted_item;  // +40
    Ptr32<Object> fe_weapon_count;  // +44
    Ptr32<Object> fe_weap_sel_text_col;  // +48
    Ptr32<Object> fe_menu_text_colour;  // +52
    Ptr32<Object> fe_unavailable_weap_col;  // +56
    Ptr32<Object> weapon_panel_open;  // +60
    Ptr32<Object> weapons_panel_worm_not_on_move_util;  // +64
    Ptr32<Object> weapons_panel_worm_not_jumping;  // +68
    unsigned char unknown48[12];
    int sub84;  // +84
    int sub88;  // +88
    int sub92;  // +92
    int sub96;  // +96
    int sub100;  // +100
    int sub104;  // +104
    int sub108;  // +108
    int sub112;  // +112
    int sub116;  // +116
    int sub120;  // +120
    int sub124;  // +124
    int sub128;  // +128
    int sub132;  // +132
    int sub136;  // +136
    int sub140;  // +140
    int sub144;  // +144
    int sub148;  // +148
    int sub152;  // +152
    int sub156;  // +156
    int sub160;  // +160
    int sub164;  // +164
    int sub168;  // +168
    Ptr32<int> sub172;  // +172
};
extern "C" Ptr32<Object> cast_803426b4(Ptr32<Object>);
static inline void load_803426b4(Ptr32<Object> &slot, Ptr32<const char> name) {
    Key key;
    key.name = name;
    Ref found;
    read_setting_800fc1b0(&key, &found);
    assign(slot, cast_803426b4(found.value));
}
extern "C" Ptr32<Object> cast_80342a78(Ptr32<Object>);
static inline void load_80342a78(Ptr32<Object> &slot, Ptr32<const char> name) {
    Key key;
    key.name = name;
    Ref found;
    read_setting_800fc1b0(&key, &found);
    assign(slot, cast_80342a78(found.value));
}
extern "C" Ptr32<Object> cast_80343744(Ptr32<Object>);
static inline void load_80343744(Ptr32<Object> &slot, Ptr32<const char> name) {
    Key key;
    key.name = name;
    Ref found;
    read_setting_800fc1b0(&key, &found);
    assign(slot, cast_80343744(found.value));
}
extern "C" Ptr32<Object> cast_80343df4(Ptr32<Object>);
static inline void load_80343df4(Ptr32<Object> &slot, Ptr32<const char> name) {
    Key key;
    key.name = name;
    Ref found;
    read_setting_800fc1b0(&key, &found);
    assign(slot, cast_80343df4(found.value));
}
extern char cache_804af6b4;
extern char cache_804af6bc;
extern char cache_804af6c4;
extern char cache_804af6cc;
extern char cache_804af6d4;
extern char cache_804af6dc;
extern char cache_804af6e4;
extern char cache_804af6ec;
extern char cache_804af6f4;
extern char cache_804af6fc;
extern char cache_804af704;
extern char cache_804af70c;
extern char cache_804af61c;
extern char cache_804af624;
extern char cache_804af63c;
extern char cache_804af644;
extern char cache_804af64c;
extern char cache_804af67c;
extern char cache_804af684;
extern char cache_804af654;
extern char cache_804af69c;
extern char cache_804af724;
extern char cache_804af66c;
extern const char n_8039d9f4[];  // "ActiveWormIndex"
extern const char n_8039da2c[];  // "FE.HighlightedItem"
extern const char n_8039da40[];  // "FE.WeaponCount"
extern const char n_8039da50[];  // "FE.WeapSelTextCol"
extern const char n_8039da64[];  // "FE.MenuTextColour"
extern const char n_8039da78[];  // "FE.UnavailableWeapCol"
extern const char n_8039da90[];  // "WeaponPanel.Open"
extern const char n_8039daa4[];  // "WeaponsPanel.WormNotOnMoveUtil"
extern const char n_8039dac4[];  // "WeaponsPanel.WormNotJumping"
extern const char n_8039da04[];  // "FE.WeaponPanel"
extern const char n_8039da14[];  // "Inventory.WeaponDelays"
static inline void read(Ptr32<void> out, Ptr32<const char> name) {
    Key key;
    key.name = name;
    read_setting_800fc1b0(&key, out);
}
extern "C" void d25i_weapon_panel_init_8012d0a4(Ptr32<Panel> self) {
    load_803426b4(self->active_worm_index, n_8039d9f4);
    read(&self->weapon_panel, n_8039da04);
    read(&self->weapon_delays, n_8039da14);
    load_80342a78(self->fe_highlighted_item, n_8039da2c);
    load_80343744(self->fe_weapon_count, n_8039da40);
    load_80343df4(self->fe_weap_sel_text_col, n_8039da50);
    load_80343df4(self->fe_menu_text_colour, n_8039da64);
    load_80343df4(self->fe_unavailable_weap_col, n_8039da78);
    load_80342a78(self->weapon_panel_open, n_8039da90);
    load_80342a78(self->weapons_panel_worm_not_on_move_util, n_8039daa4);
    load_80342a78(self->weapons_panel_worm_not_jumping, n_8039dac4);
    int one = 1;
    set_value_80178d28(self->weapons_panel_worm_not_on_move_util, &one);
    int one2 = 1;
    set_value_80178d28(self->weapons_panel_worm_not_jumping, &one2);
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af6b4, 1); subscribe_80162024(self, &id, &self->sub120); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af6bc, 1); subscribe_80162024(self, &id, &self->sub124); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af6c4, 1); subscribe_80162024(self, &id, &self->sub128); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af6cc, 1); subscribe_80162024(self, &id, &self->sub132); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af6d4, 1); subscribe_80162024(self, &id, &self->sub136); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af6dc, 1); subscribe_80162024(self, &id, &self->sub140); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af6e4, 1); subscribe_80162024(self, &id, &self->sub144); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af6ec, 1); subscribe_80162024(self, &id, &self->sub148); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af6f4, 1); subscribe_80162024(self, &id, &self->sub152); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af6fc, 1); subscribe_80162024(self, &id, &self->sub156); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af704, 1); subscribe_80162024(self, &id, &self->sub160); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af70c, 1); subscribe_80162024(self, &id, &self->sub164); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af61c, 1); subscribe_80162024(self, &id, &self->sub84); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af624, 1); subscribe_80162024(self, &id, &self->sub88); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af63c, 1); subscribe_80162024(self, &id, &self->sub92); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af644, 1); subscribe_80162024(self, &id, &self->sub96); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af64c, 1); subscribe_80162024(self, &id, &self->sub100); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af67c, 1); subscribe_80162024(self, &id, &self->sub104); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af684, 1); subscribe_80162024(self, &id, &self->sub108); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af654, 1); subscribe_80162024(self, &id, &self->sub112); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af69c, 1); subscribe_80162024(self, &id, &self->sub116); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af724, 1); subscribe_80162024(self, &id, &self->sub168); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af66c, 1); subscribe_80162024(self, &id, &self->sub172); }
    self->sub172[4] = 0;
    int zero = 0;
    set_value_80178d28(self->weapon_panel_open, &zero);
}


