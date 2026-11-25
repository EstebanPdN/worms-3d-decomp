// d24d: 0x80155ff0 (232 bytes). Advance a team's worm rotation: read the
// "ActiveWormIndex" setting (0x800fc1f0), take the team byte (+213) of that worm
// (0x800fc6dc) and, when the team's list (+52, 12 bytes per team) is not empty,
// step its cursor (+148, wrapping at the list size). A listed value up to 16 is
// passed by address to 0x80178c54 on the object from 0x803426b4 (+296). Finally
// runs the team update 0x801558dc. Names are inferred from the setting.
struct d24d_SettingKey { const char *name; };
struct d24d_WormInfo {
    unsigned char unknown00[213];
    unsigned char team;                  // +213
};
struct d24d_List {
    int *start, *finish, *end;
    bool empty() { return start == finish; }
    unsigned size() { return finish - start; }
    int &operator[](unsigned i) { return start[i]; }
};
struct d24d_Teams {
    unsigned char unknown00[52];
    d24d_List lists[8];                  // +52
    unsigned cursor[37];                 // +148
    void *display;                       // +296
};
extern "C" int d24d_setting_read_800fc1f0(d24d_SettingKey *, int *);
extern "C" d24d_WormInfo *d24d_worm_info_800fc6dc(int);
extern "C" void *d24d_display_803426b4(void *);
extern "C" int d24d_display_update_80178c54(void *, unsigned *);
extern "C" int d24d_team_update_801558dc(d24d_Teams *, unsigned);
extern const char d24d_active_worm_803a27ac[];   // "ActiveWormIndex"

extern "C" void d24d_advance_team_worm_80155ff0(d24d_Teams *self) {
    d24d_SettingKey key;
    key.name = d24d_active_worm_803a27ac;
    int active = 0;
    d24d_setting_read_800fc1f0(&key, &active);
    unsigned team = d24d_worm_info_800fc6dc(active)->team;
    if (!self->lists[team].empty()) {
        unsigned next = ++self->cursor[team];
        if (self->lists[team].size() <= next) self->cursor[team] = 0;
        unsigned value = self->lists[team][self->cursor[team]];
        if (value <= 16) d24d_display_update_80178c54(d24d_display_803426b4(self->display), &value);
        d24d_team_update_801558dc(self, team);
    }
}
