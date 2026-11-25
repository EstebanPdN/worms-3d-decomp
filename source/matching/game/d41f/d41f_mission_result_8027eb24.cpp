// GWMP8P rev0 0x8027eb24. Records the result of a finished mission once:
// reads the current category and mission, then updates team records for
// categories 0, 3 and 4. String, handle, list and score views are observed;
// roles are inferred. The category test is written out as explicit tests;
// two do/while forms wrap real code. See the caveat in d41f.json.
struct Obj { void **table; };
inline void retain(Obj *p) { if (p) ((void (*)(Obj *))p->table[3])(p); }
inline void release(Obj *p) { if (p) ((void (*)(Obj *))p->table[4])(p); }
struct Handle {
    Obj *p;
    Handle() : p(0) {}
    Handle(Obj *x) : p(x) { retain(p); }
    Handle(const Handle &o) : p(o.p) { retain(p); }
    ~Handle() { release(p); }
    Handle &operator=(const Handle &o) { Obj *next = o.p; if (next) { retain(next); release(p); p = next; } return *this; }
};
struct Descriptor_80178474 { int zero; unsigned type; Descriptor_80178474() : zero(0), type(58280) {} ~Descriptor_80178474(); };
extern "C" void w3d_string_base_finish(void *), w3d_string_release(void *), w3d_string_release_header(void *);
struct String_803426b8 {
    char *text;
    String_803426b8();
    String_803426b8(const char *);
    String_803426b8(const String_803426b8 &);
    unsigned Length() const { return ((unsigned short *)text)[-2]; }
    ~String_803426b8() { w3d_string_base_finish(this); w3d_string_release(this); }
    String_803426b8 &operator=(const String_803426b8 &other) {
        ++*(unsigned short *)(other.text - 6);
        char *old = text;
        unsigned short *header = (unsigned short *)(old - 6);
        unsigned short references = --*header;
        if (!references)
            w3d_string_release_header(header);
        text = other.text;
        return *this;
    }
};
typedef String_803426b8 String;
extern "C" void w3d_string_base_init(String *);
extern "C" unsigned short *w3d_string_header(String *);
inline String_803426b8::String_803426b8(const String_803426b8 &other) {
    w3d_string_base_init(this);
    text = other.text;
    ++*w3d_string_header(this);
}
inline void DebugNote(String) {}
extern "C" void w3d_auto_8015f558(void *, int);
struct CacheBase { int prefix[2]; ~CacheBase() { w3d_auto_8015f558(this, 2); } };
struct Cache_8015f704 : CacheBase { String name; Cache_8015f704(const char *); };
struct Key { const char *text; Key(const char *p) : text(p) {} Key() {} };
typedef Key Text;
struct Score { char pad[20]; unsigned bronzeTime; String bronze; unsigned silverTime; String silver; unsigned goldTime; String gold; };
struct ScoreList { char pad[24]; unsigned count; char pad28[4]; Score *items[1]; };
struct Record { char pad[24]; int medal; };
struct RecordList { char pad[24]; unsigned count; char pad28[4]; Record *items[1]; };
struct Team { char pad[48]; unsigned progress; RecordList *records; char pad56[4]; String name; };
struct TeamList { char pad[24]; unsigned count; char pad28[4]; Team *items[1]; };
struct BarracksSub { bool NoScores() { return scores == 0; } int a; ScoreList *scores; TeamList *teams; Team **Teams() { return teams->items; } Score **Scores() { return scores->items; } };
struct Barracks { char pad[16]; BarracksSub sub; };
extern char lbl_803cec70[], lbl_803ce9a0[], lbl_803ceab4[], lbl_803cea5c[], lbl_803cece4[], lbl_803cecf8[], lbl_803ced08[], lbl_803ced14[], lbl_803ced20[], lbl_803ced2c[], lbl_803ceaa0[], lbl_80419ea8[], lbl_803cec34[], lbl_803cec44[], lbl_803cec54[], lbl_803ced3c[], lbl_803ced4c[], lbl_803ced70[], lbl_803ced80[], lbl_803ceb80[], lbl_803ced90[], lbl_803ceda0[], lbl_803cedb0[], lbl_803cedc0[], lbl_803cedd0[], lbl_803cede0[], lbl_803cedf0[], lbl_803cee00[], lbl_803ceb50[], lbl_803ceb60[], lbl_803ceb74[], lbl_803ceb8c[], lbl_803ceba4[], lbl_803cebbc[], lbl_803cebd4[], lbl_803cebe4[], lbl_803cebf4[], lbl_803cec04[], lbl_803cec14[], lbl_803cec24[];
extern "C" int w3d_constructor_lookup_name(const Text &, Handle &);
extern "C" Obj *w3d_empty_80341584(Obj *);
extern "C" Barracks *w3d_auto_801797b4(Obj *);
extern "C" int w3d_auto_800fc230(const Text &, unsigned *);
extern "C" int w3d_auto_800fc2b0(const Text &, const char **);
extern "C" int s8_property_read_800fc550(const Text &, const char *);
extern "C" int s8_property_write_800fc43c(const Text &, unsigned);
extern "C" String *w3d_string_assign(String *, const char *);
extern "C" void w3d_string_format(String *, const char *, ...);
extern "C" int strcmp(const char *, const char *);
extern "C" unsigned w3d_r25b_category_count_8027be7c(void *, unsigned);
extern "C" unsigned w3d_f7a_lookup_team_skill_80281ea4(void *, int, unsigned);
extern "C" int w3d_mission_current_value_80281b20(void *);
extern "C" Obj *w3d_s10_service_forward_8020b680(void *);
extern "C" void w3d_k5b_iface_array_field_append_801ef174(Team *, int, int, Obj *);
extern "C" void fn_802814c4(void *);
inline Obj *Create(void *type) { return w3d_s10_service_forward_8020b680(type); }
template <char *T> inline Obj *CreateT() { return w3d_s10_service_forward_8020b680(T); }
extern "C" void w3d_d41f_mission_result_8027eb24(void *self) {
    char *flag = lbl_803cec70;
    unsigned pending = 0;
    w3d_auto_800fc230(flag, &pending);
    if (pending != 0)
        return;
    s8_property_write_800fc43c(flag, 1);
    unsigned current;
    w3d_auto_800fc230(lbl_803ce9a0, &current);
    int category = current;
    char *missionKey = lbl_803ceab4;
    unsigned mission;
    w3d_auto_800fc230(missionKey, &mission);
    String team;
    const char *text;
    w3d_auto_800fc2b0(lbl_803cea5c, &text);
    w3d_string_assign(&team, text);
    if (category == 3) goto c3;
    if (category > 3) goto x;
    if (category == 0) goto c0;
    goto done;
    x:
    do {
        if (category == 4) goto c4;
        goto done;
    } while (0);
    c0: {
        Handle teams;
        unsigned last = 0;
        w3d_auto_800fc230(lbl_803cece4, &last);
        int medal = 0;
        switch (last) {
        case 3:
            medal = 3;
            s8_property_read_800fc550(lbl_803cecf8, lbl_803ced08);
            break;
        case 2:
            medal = 2;
            s8_property_read_800fc550(lbl_803cecf8, lbl_803ced14);
            break;
        case 1:
            medal = 1;
            s8_property_read_800fc550(lbl_803cecf8, lbl_803ced20);
            break;
        default:
            s8_property_read_800fc550(lbl_803cecf8, lbl_803ced2c);
            break;
        }
        if (w3d_constructor_lookup_name(lbl_803ceaa0, teams) < 0)
            return;
        TeamList *list = w3d_auto_801797b4(w3d_empty_80341584(teams.p))->sub.teams;
        unsigned count = list->count;
        Team **items = list->items;
        for (unsigned i = 0; i < count; i++) {
            if (strcmp(items[i]->name.text, team.text) == 0) {
                RecordList *records = items[i]->records;
                unsigned m = mission;
                unsigned size = records->count;
                Record **list2 = records->items;
                if (size == m + 1) {
                    Record *record = list2[m];
                    if (record->medal < medal)
                        record->medal = medal;
                    Handle fresh(Create(lbl_80419ea8));
                    w3d_k5b_iface_array_field_append_801ef174(items[i], 52, 2, fresh.p);
                    if (w3d_r25b_category_count_8027be7c(self, 0) > mission + 1)
                        { Text k; k.text = lbl_803ceab4; s8_property_write_800fc43c(k, mission + 1); }
                } else if (size > m) {
                    Record *record = list2[m];
                    if (record->medal < medal)
                        record->medal = medal;
                }
                break;
            }
        }
        goto done;
    }
    c4: {
        unsigned skill = w3d_f7a_lookup_team_skill_80281ea4(self, 4, mission);
        int medal = 0;
        unsigned time;
        w3d_auto_800fc230(lbl_803cece4, &time);
        unsigned bestGold;
        w3d_auto_800fc230(lbl_803cec34, &bestGold);
        unsigned bestSilver;
        w3d_auto_800fc230(lbl_803cec44, &bestSilver);
        unsigned bestBronze;
        w3d_auto_800fc230(lbl_803cec54, &bestBronze);
        if (w3d_mission_current_value_80281b20(self)) {
            if (time > bestGold)
                medal = 3;
            else if (time > bestSilver)
                medal = 2;
            else if (time > bestBronze)
                medal = 1;
        } else {
            if (time < bestGold)
                medal = 3;
            else if (time < bestSilver)
                medal = 2;
            else if (time < bestBronze)
                medal = 1;
        }
        if (medal != 0) {
            Handle teams;
            if (w3d_constructor_lookup_name(lbl_803ceaa0, teams) < 0)
                return;
            Barracks *b = w3d_auto_801797b4(w3d_empty_80341584(teams.p));
            ScoreList *list = b->sub.scores;
            bool none = b->sub.NoScores();
            unsigned size = list->count;
            Score **items = list->items;
            if (none || skill >= size) {
                s8_property_read_800fc550(lbl_803ced3c, lbl_803ced4c);
                s8_property_read_800fc550(lbl_803ced70, lbl_803ced4c);
                s8_property_read_800fc550(lbl_803ced80, lbl_803ced4c);
                return;
            }
            if (medal == 3) {
                { Score *e = items[skill]; e->bronze = e->silver; }
                items[skill]->bronzeTime = items[skill]->silverTime;
                { Score *e = items[skill]; e->silver = e->gold; }
                items[skill]->silverTime = items[skill]->goldTime;
                { Score *e = items[skill]; e->gold = team; }
                items[skill]->goldTime = time;
            }
            if (medal == 2) {
                { Score *e = items[skill]; e->bronze = e->silver; }
                items[skill]->bronzeTime = items[skill]->silverTime;
                { Score *e = items[skill]; e->silver = team; }
                items[skill]->silverTime = time;
            }
            if (medal == 1) {
                { Score *e = items[skill]; e->bronze = team; }
                items[skill]->bronzeTime = time;
            }
        }
        String shown;
        w3d_string_format(&shown, lbl_803ceb80, time / 60000, time / 1000 - time / 60000 * 60);
        s8_property_read_800fc550(lbl_803ced90, shown.text);
        w3d_auto_800fc2b0(lbl_803ceda0, &text);
        s8_property_read_800fc550(lbl_803cedb0, text);
        switch (medal) {
        case 1:
            w3d_auto_800fc2b0(lbl_803cedc0, &text);
            s8_property_read_800fc550(lbl_803cedd0, text);
            s8_property_read_800fc550(lbl_803cecf8, lbl_803ced20);
            break;
        case 2:
            w3d_auto_800fc2b0(lbl_803cede0, &text);
            s8_property_read_800fc550(lbl_803cedd0, text);
            s8_property_read_800fc550(lbl_803cecf8, lbl_803ced14);
            break;
        case 3:
            w3d_auto_800fc2b0(lbl_803cedf0, &text);
            s8_property_read_800fc550(lbl_803cedd0, text);
            s8_property_read_800fc550(lbl_803cecf8, lbl_803ced08);
            break;
        default:
            w3d_auto_800fc2b0(lbl_803cee00, &text);
            s8_property_read_800fc550(lbl_803cedd0, text);
            s8_property_read_800fc550(lbl_803cecf8, lbl_803ced2c);
            break;
        }
        Handle teams;
        if (w3d_constructor_lookup_name(lbl_803ceaa0, teams) < 0)
            return;
        Barracks *scores = w3d_auto_801797b4(w3d_empty_80341584(teams.p));
        String gold, goldTime, silver, silverTime, bronze, bronzeTime;
        ScoreList *list = scores->sub.scores;
        Score **items = list->items;
        if (list->count == 0) {
            w3d_string_assign(&gold, lbl_803ceb50);
            w3d_string_assign(&silver, lbl_803ceb50);
            w3d_string_assign(&bronze, lbl_803ceb50);
            w3d_string_assign(&goldTime, lbl_803ceb50);
            w3d_string_assign(&silverTime, lbl_803ceb50);
            w3d_string_assign(&bronzeTime, lbl_803ceb50);
        } else if (skill >= list->count) {
            w3d_string_assign(&gold, lbl_803ceb60);
            w3d_string_assign(&silver, lbl_803ceb74);
            w3d_string_assign(&bronze, lbl_803ceb60);
            w3d_string_assign(&goldTime, lbl_803ceb74);
            w3d_string_assign(&silverTime, lbl_803ceb60);
            w3d_string_assign(&bronzeTime, lbl_803ceb74);
        } else {
            gold = items[skill]->gold;
            silver = items[skill]->silver;
            bronze = items[skill]->bronze;
            unsigned goldMs = items[skill]->goldTime;
            unsigned silverMs = items[skill]->silverTime;
            unsigned bronzeMs = items[skill]->bronzeTime;
            w3d_string_format(&goldTime, lbl_803ceb80, goldMs / 60000, goldMs / 1000 - goldMs / 60000 * 60);
            w3d_string_format(&silverTime, lbl_803ceb80, silverMs / 60000, silverMs / 1000 - silverMs / 60000 * 60);
            w3d_string_format(&bronzeTime, lbl_803ceb80, bronzeMs / 60000, bronzeMs / 1000 - bronzeMs / 60000 * 60);
        }
        if (gold.Length() == 0)
            w3d_string_format(&gold, lbl_803ceb8c, skill);
        if (silver.Length() == 0)
            w3d_string_format(&silver, lbl_803ceba4, skill);
        if (bronze.Length() == 0)
            w3d_string_format(&bronze, lbl_803cebbc, skill);
        do {
        s8_property_read_800fc550(lbl_803cebd4, gold.text);
        s8_property_read_800fc550(lbl_803cebe4, silver.text);
        s8_property_read_800fc550(lbl_803cebf4, bronze.text);
        s8_property_read_800fc550(lbl_803cec04, goldTime.text);
        s8_property_read_800fc550(lbl_803cec14, silverTime.text);
        s8_property_read_800fc550(lbl_803cec24, bronzeTime.text);
        goto done;
        } while (0);
    }
    c3: {
        Handle teams;
        if (w3d_constructor_lookup_name(lbl_803ceaa0, teams) < 0)
            return;
        Barracks *b = w3d_auto_801797b4(w3d_empty_80341584(teams.p));
        unsigned count = b->sub.teams->count;
        Team **items = b->sub.Teams();
        for (unsigned i = 0; i < count; i++) {
            if (strcmp(items[i]->name.text, team.text) == 0) {
                Team *t = items[i];
                if (t->progress == mission)
                    t->progress = mission + 1;
                if (mission + 1 < w3d_r25b_category_count_8027be7c(self, 3))
                    s8_property_write_800fc43c(missionKey, mission + 1);
                break;
            }
        }
        goto done;
    }
    done:
    fn_802814c4(self);
}
