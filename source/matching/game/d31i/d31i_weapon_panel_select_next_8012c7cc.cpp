// d31i: 0x8012c7cc. Weapon panel: from the selected weapon, walks the row of
// the weapon table to the next usable weapon and posts the selection
// message.
struct String {
    char *text;
    String(const char *);
    String(const String &);
    ~String();
    bool operator==(const char *o) const;
};
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
extern "C" int strcmp(const char *, const char *);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
inline bool String::operator==(const char *o) const { return strcmp(text, o) == 0; }
struct Key { const char *name; };
struct Team { unsigned char unknown00[132]; int weapon; };
struct Panel {
    unsigned char unknown00[28];
    void *o28;
    unsigned char unknown20[40];
    int ready;       // +72
};
extern "C" int read_uint_800fc230(Key *, int *);
extern "C" int row_start_8012c768(Panel *, unsigned);
extern "C" void *inner_80178c48(void *);
extern "C" Team *team_800fc6dc(int);
extern "C" int stock_800fcec8(void *, int);
extern "C" int attr_800fd014(Team *, int);
extern "C" const char *reason_8012f0f8(Panel *, int);
extern "C" void *arena_801613f0(void *, int);
extern "C" int message_id_8015f5a0(void *, int);
extern "C" void *message_int_init_800a82f0(void *, int, int);
extern "C" int post_8016239c(void *);
extern void *arena_804b1754;
extern int msg_804af684;
extern int weapons_803fd9e4[];
extern const char s_8039d9a4[], s_8039d9b0[];

extern "C" void d31i_weapon_panel_select_next_8012c7cc(Panel *self, unsigned row) {
    if (row > 8 || self->ready == 0) return;
    Key typeKey = {s_8039d9a4};
    int type = 0;
    int col = 0;
    read_uint_800fc230(&typeKey, &type);
    int *table = weapons_803fd9e4;
    int first = row_start_8012c768(self, row);
    Team *team = team_800fc6dc((int)(inner_80178c48(self->o28)));
    unsigned r = 0;
    int current = team->weapon;
    int i = 0;
    for (;;) {
        int e = weapons_803fd9e4[i];
        if (e == 61) break;
        if (e == 60) {
            r++;
            col = -1;
        } else if (e == current) break;
        i++;
        col++;
    }
    if (r != row) col = -1;
    int off = first << 2;
    int start = col;
    int *p = (int *)((col << 2) + (off + (int)table));
    int w;
    int found = 0;
    do {
        w = *++p;
        col++;
        if (w == 60) {
            p = (int *)((off + (int)table) - 4);
            col = -1;
        } else if (stock_800fcec8(inner_80178c48(self->o28), w) && attr_800fd014(team, w)) {
            const char *why = reason_8012f0f8(self, w);
            int v;
            bool blank = String(why) == s_8039d9b0;
            if (blank)
                found = 1;
            else {
                read_uint_800fc230((Key *)&why, &v);
                if (v != 0) found = 1;
            }
        }
    } while (found == 0 && col != start);
    if (found) post_8016239c(message_int_init_800a82f0(arena_801613f0(arena_804b1754, 12), (unsigned short)message_id_8015f5a0(&msg_804af684, 1), w));
}
