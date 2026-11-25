/* Game over handler (0x8008ad34): ignored once +384 is set. Otherwise clears the flag
 * 0x804ab420, posts a cached message, selects the camera and timer, reads the game type,
 * and for each outcome message builds the win text and the next menu: round end (announces
 * the first active player without a live record, advances GameOver.RoundNumber, names the
 * winner or its team colour, and picks the completed or next round menu), draw, end game,
 * mission, tutorial and challenge success and failure. Finally publishes FE.NextMenu and
 * FE.WinString and posts the return message, delayed by GameToFrontEndDelayTime unless the
 * message was end game or the second draw. Field and type names are inferred from the
 * original instructions; strings and globals are external views of original data. The
 * unit owns no data. */
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Message { unsigned short id; unsigned short unknown02; void *vtable; };
struct Logic { char unknown00[264]; void *object264; char unknown268[116]; int gameOver; };
struct Player { char unknown00[213]; unsigned char index; char unknown214[6]; int active; };
struct Context { char unknown00[52]; int now; };
struct Team { char unknown00[20]; unsigned wins; };
struct Scheme { char unknown00[256]; unsigned rounds; };
struct String;
struct PropertyKey { const char *name; };
struct Descriptor_80178474 {
    void *value;
    unsigned tag;
    Descriptor_80178474() : value(0), tag(58280) {}
    ~Descriptor_80178474();
};
struct String;
extern "C" void w3d_string_finish_8020c5c4(String *);
extern "C" void w3d_string_release_80341588(String *);
extern "C" void w3d_string_init_8020c5c0(String *);
extern "C" unsigned short *w3d_string_header_80341884(String *);
extern "C" String *w3d_string_assign_8020bd38(String *, const char *);
extern "C" int w3d_strcmp_802ef234(const char *, const char *);
extern "C" void w3d_string_format_8020c510(String *, const char *, ...);
struct String {
    char *text;
    String(const char *);
    String();
    String(const String &o) { w3d_string_init_8020c5c0(this); text = o.text; ++*w3d_string_header_80341884(this); }
    ~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
    bool operator==(const char *s) const { return w3d_strcmp_802ef234(text, s) == 0; }
    void assign(const char *s) { w3d_string_assign_8020bd38(this, s); }
};
struct Record { char unknown00[28]; String name; char unknown32[12]; int alive; char unknown48[12]; unsigned char team; };
extern "C" void *w3d_arena_alloc_801613f0(void *, int);
extern "C" int w3d_cached_message_id_8015f5a0(MessageCache *, int);
extern "C" int w3d_message_post_8016239c(void *);
extern "C" Message *w3d_message_int_init_800a82f0(void *, unsigned short, int);
extern "C" int w3d_message_equals_8015f65c(unsigned short, MessageCache *);
extern "C" int w3d_message_get_800a830c(Message *);
extern "C" void w3d_camera_select_80035a30(void *);
extern "C" void w3d_timer_set_8006e750(int);
extern "C" int w3d_read_text_800fc2b0(PropertyKey *, const char **);
extern "C" int w3d_read_scheme_800fc330(PropertyKey *, Scheme **);
extern "C" int w3d_read_int_800fc230(PropertyKey *, int *);
extern "C" int w3d_write_int_800fc43c(PropertyKey *, int);
extern "C" int w3d_write_text_800fc550(PropertyKey *, const char *);
extern "C" int w3d_read_time_800fc1f0(PropertyKey *, int *);
extern "C" int w3d_address_80127da4(void *);
extern "C" Player *w3d_player_800fc6dc(int);
extern "C" Record *w3d_record_800fc7f8(int);
extern "C" Record *w3d_handle_800fc82c(int, Descriptor_80178474 *);
extern "C" Team *w3d_handle_800fc948(int, Descriptor_80178474 *);
extern "C" int w3d_member_count_8008ac48(Logic *, int);
extern "C" unsigned w3d_count_records_8008acd0(Logic *, int);
extern "C" void w3d_inventory_reset_8008b80c(Logic *);
extern "C" void *w3d_cast_803426b4(void *);
extern "C" int w3d_value_80178c48(void *);
extern "C" void w3d_list_trim_800c4e18(void *);
extern "C" int w3d_list_toggle_800c4b00(void *, const char *);
extern "C" void w3d_list_freeze_800c4de8(void *);
extern "C" Context *w3d_context_80165254();
extern "C" int w3d_pool_add_800c53a0(void *, int);
extern "C" int w3d_strcmp_802ef234(const char *, const char *);
extern void *w3d_arena_804b1754;
extern void *w3d_camera_804aa8c8;
extern void *w3d_system_804b1788;
extern char *w3d_lists_804aaabc;
extern int w3d_flag_804ab420;
extern unsigned char w3d_vtable_8040db38[];
extern MessageCache c_804adbdc, c_804adcec, c_804adc44, c_804add74, c_804add64, c_804adc4c, c_804adc5c, c_804adc54, c_804adc6c, c_804adc64, c_804adc74, c_804adc7c, c_804adc84, c_804adc8c, c_804adc94, c_804adcd4;
extern const char s_8037dc3c[], s_8037dc50[], s_8037daf4[], s_8037dc58[], s_8037dc70[], s_8037dc78[], s_8037dc80[], s_8037dc8c[], s_8037dc98[], s_8037dca0[], s_8037dcbc[], s_8037dcc0[], s_8037dcd0[], s_8037dce8[], s_8037dcfc[], s_8037dd0c[], s_8037dd1c[], s_8037dd34[], s_8037dd54[], s_8037dd6c[], s_8037dd88[], s_8037dd9c[], s_8037ddac[], s_8037ddc8[], s_8037dde8[], s_8037de08[], s_8037de28[], s_8037de5c[], s_8037de6c[];
inline void Post8(MessageCache *c)
{
    Message *m = (Message *)w3d_arena_alloc_801613f0(w3d_arena_804b1754, 8);
    m->id = w3d_cached_message_id_8015f5a0(c, 1);
    m->vtable = w3d_vtable_8040db38;
    w3d_message_post_8016239c(m);
}
inline void Post12(int v)
{
    void *m = w3d_arena_alloc_801613f0(w3d_arena_804b1754, 12);
    w3d_message_post_8016239c(w3d_message_int_init_800a82f0(m, w3d_cached_message_id_8015f5a0(&c_804adcec, 1), v));
}
#define READ(s, out) { PropertyKey key; key.name = s; w3d_read_text_800fc2b0(&key, out); }
#define READ_TEXT(s) READ(s, &text)
#define WRITE(s, v) { PropertyKey key; key.name = s; w3d_write_text_800fc550(&key, v); }
extern "C" void w3d_d27b_game_over_8008ad34(Logic *self, Message *msg)
{
    if (self->gameOver) { self->gameOver = 1; return; }
    unsigned short id = msg->id;
    w3d_flag_804ab420 = 0;
    Post8(&c_804adbdc);
    w3d_camera_select_80035a30(w3d_camera_804aa8c8);
    w3d_timer_set_8006e750(1);
    const char *type;
    READ(s_8037dc3c, &type);
    String gameType(type);
    const char *next = 0;
    String win;
    const char *text;
    if (gameType == s_8037dc50) {
        next = (const char *)w3d_address_80127da4(w3d_system_804b1788);
    } else if (w3d_message_equals_8015f65c(id, &c_804adc44)) {
        int winner = w3d_message_get_800a830c(msg);
        for (int i = 0; i <= 15; i++) {
            Player *p = w3d_player_800fc6dc(i);
            Record *r = w3d_record_800fc7f8(p->index);
            if (p->active && r->alive == 0) { Post12(i); goto done; }
        }
        done:
        Scheme *scheme;
        { PropertyKey key; key.name = s_8037daf4; w3d_read_scheme_800fc330(&key, &scheme); }
        unsigned rounds = scheme->rounds;
        int round = 0;
        { PropertyKey key; key.name = s_8037dc58; w3d_read_int_800fc230(&key, &round); }
        round++;
        { PropertyKey key; key.name = s_8037dc58; w3d_write_int_800fc43c(&key, round); }
        Descriptor_80178474 desc;
        int team = w3d_handle_800fc82c(winner, &desc)->team;
        w3d_member_count_8008ac48(self, team);
        unsigned wins = w3d_handle_800fc948(winner, &desc)->wins;
        unsigned members = w3d_count_records_8008acd0(self, team);
        const char *colour = 0;
        if (team > 4) members = 0;
        if (members > 1) {
            switch (team) {
            case 0: READ(s_8037dc70, &colour); break;
            case 1: READ(s_8037dc78, &colour); break;
            case 2: READ(s_8037dc80, &colour); break;
            case 3: READ(s_8037dc8c, &colour); break;
            }
        }
        if (gameType == s_8037dc98) Post8(&c_804add74);
        if (wins >= rounds) {
            READ(s_8037dca0, &next);
            Post8(&c_804add64);
            w3d_inventory_reset_8008b80c(self);
            WRITE(s_8037dc3c, s_8037dcbc);
            String name(w3d_record_800fc7f8(winner)->name);
            if (colour) name.assign(colour);
            READ_TEXT(s_8037dcc0);
            w3d_string_format_8020c510(&win, text, name.text);
        } else {
            READ(s_8037dcd0, &next);
            String name(w3d_record_800fc7f8(winner)->name);
            if (colour) name.assign(colour);
            READ_TEXT(s_8037dce8);
            w3d_string_format_8020c510(&win, text, name.text);
        }
    } else if (w3d_message_equals_8015f65c(id, &c_804adc4c) || w3d_message_equals_8015f65c(id, &c_804adc5c)) {
        READ_TEXT(s_8037dcfc);
        w3d_string_assign_8020bd38(&win, text);
        READ(s_8037dcd0, &next);
    } else if (w3d_message_equals_8015f65c(id, &c_804adc54)) {
        READ_TEXT(s_8037dd0c);
        w3d_string_assign_8020bd38(&win, text);
        next = (const char *)w3d_address_80127da4(w3d_system_804b1788);
        WRITE(s_8037dc3c, s_8037dcbc);
    } else if (w3d_message_equals_8015f65c(id, &c_804adc6c)) {
        Post12(w3d_value_80178c48(w3d_cast_803426b4(self->object264)));
        READ_TEXT(s_8037dd1c);
        w3d_string_assign_8020bd38(&win, text);
        READ(s_8037dd34, &next);
        WRITE(s_8037dc3c, s_8037dcbc);
    } else if (w3d_message_equals_8015f65c(id, &c_804adc64)) {
        READ_TEXT(s_8037dd54);
        w3d_string_assign_8020bd38(&win, text);
        READ(s_8037dd6c, &next);
        WRITE(s_8037dd88, s_8037dd9c);
        WRITE(s_8037dc3c, s_8037dcbc);
    } else if (w3d_message_equals_8015f65c(id, &c_804adc74)) {
        READ_TEXT(s_8037dd54);
        w3d_string_assign_8020bd38(&win, text);
        READ(s_8037ddac, &next);
        WRITE(s_8037dd88, s_8037dd9c);
        WRITE(s_8037dc3c, s_8037dcbc);
    } else if (w3d_message_equals_8015f65c(id, &c_804adc7c)) {
        Post12(w3d_value_80178c48(w3d_cast_803426b4(self->object264)));
        READ_TEXT(s_8037dd1c);
        w3d_string_assign_8020bd38(&win, text);
        READ(s_8037ddc8, &next);
        WRITE(s_8037dc3c, s_8037dcbc);
    } else if (w3d_message_equals_8015f65c(id, &c_804adc84)) {
        next = 0;
        WRITE(s_8037dc3c, s_8037dcbc);
    } else if (w3d_message_equals_8015f65c(id, &c_804adc8c)) {
        Post12(w3d_value_80178c48(w3d_cast_803426b4(self->object264)));
        READ(s_8037dde8, &next);
        WRITE(s_8037dc3c, s_8037dcbc);
    } else if (w3d_message_equals_8015f65c(id, &c_804adc94)) {
        READ_TEXT(s_8037dd54);
        w3d_string_assign_8020bd38(&win, text);
        READ(s_8037de08, &next);
        WRITE(s_8037dd88, s_8037dd9c);
        WRITE(s_8037dc3c, s_8037dcbc);
    }
    w3d_list_trim_800c4e18(w3d_lists_804aaabc + 188);
    if (next) {
        WRITE(s_8037de28, next);
        w3d_list_toggle_800c4b00(w3d_lists_804aaabc + 188, next);
        w3d_list_freeze_800c4de8(w3d_lists_804aaabc + 188);
    }
    WRITE(s_8037de5c, win.text);
    if (w3d_message_equals_8015f65c(id, &c_804adc54) || w3d_message_equals_8015f65c(id, &c_804adc5c)) {
        Post8(&c_804adcd4);
    } else {
        int delay;
        { PropertyKey key; key.name = s_8037de6c; w3d_read_time_800fc1f0(&key, &delay); }
        Message *m = (Message *)w3d_arena_alloc_801613f0(w3d_arena_804b1754, 8);
        m->id = w3d_cached_message_id_8015f5a0(&c_804adcd4, 1);
        m->vtable = w3d_vtable_8040db38;
        w3d_pool_add_800c53a0(m, w3d_context_80165254()->now + delay);
    }
}
