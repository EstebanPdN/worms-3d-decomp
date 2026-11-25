// d24d: 0x8015668c (504 bytes). Find the next team with queued worms after a
// given worm: with -1 the search starts from the team count in the "GM.GameInitData"
// settings (+84, read through 0x800fc1b0, 0x80341584 and 0x80179598; a failed
// lookup returns -1); otherwise from the team index byte (+60) of the worm's
// record. Walks the four lists at +100 with wrap-around and returns the first
// value of the first non-empty one, or the given id. The handle (key 0xe3a8) has an
// out-of-line destructor 0x80178474. Names are inferred.
struct d24d_Object { void **vtable; };
struct d24d_Ref { d24d_Object *value; d24d_Ref() { value = 0; } d24d_Ref(const d24d_Ref &o) { value = o.value; if (value) ((void (*)(d24d_Object *))value->vtable[3])(value); } d24d_Ref(d24d_Object *o) { value = o; if (value) ((void (*)(d24d_Object *))value->vtable[3])(value); } ~d24d_Ref() { if (value) ((void (*)(d24d_Object *))value->vtable[4])(value); }
  d24d_Ref &operator=(const d24d_Ref &o) { d24d_Object *n = o.value; if (n) { ((void (*)(d24d_Object *))n->vtable[3])(n); if (value) ((void (*)(d24d_Object *))value->vtable[4])(value); value = n; } return *this; }
};
struct d24d_Handle { int value; unsigned key; d24d_Handle() { value = 0; key = 58280; } ~d24d_Handle(); };
struct d24d_SettingKey { const char *name; };
struct d24d_GameInit { char pad[84]; int count; };
extern "C" int d24d_setting_lookup_800fc1b0(d24d_SettingKey *, d24d_Ref *);
extern "C" void *d24d_settings_view_80341584(d24d_Object *);
extern "C" d24d_Object *d24d_settings_get_80179598(void *, const d24d_Handle *);
struct d24d_TeamRecord { char pad[60]; unsigned char team; };
extern "C" d24d_TeamRecord *d24d_team_record_800fc7f8(int);
struct d24d_Queue { int *start, *finish, *end; bool empty() { return start == finish; } int *begin() { return start; } };
struct d24d_Turns { char pad[100]; d24d_Queue lists[4]; };
extern const char d24d_game_init_803a2aa4[];
extern "C" int d24d_next_team_8015668c(d24d_Turns *self, int cur) {
    int i, stop;
    if (cur == -1) {
        d24d_Ref data; d24d_Handle hh; const d24d_Handle *hp = &hh;
        d24d_SettingKey key; key.name = d24d_game_init_803a2aa4;
        if (d24d_setting_lookup_800fc1b0(&key, &data) < 0) return -1;
        d24d_Ref r;
        r = d24d_Ref(d24d_settings_get_80179598(d24d_settings_view_80341584(data.value), hp));
        int t = ((d24d_GameInit *)r.value)->count;
        stop = t - 1;
        i = t;
    } else {
        int t = d24d_team_record_800fc7f8(cur)->team;
        i = t + 1;
        stop = t;
    }
    for (; i != stop; i++) {
        if (i > 3) i = 0;
        if (!self->lists[i].empty()) return *self->lists[i].begin();
    }
    return cur;
}
