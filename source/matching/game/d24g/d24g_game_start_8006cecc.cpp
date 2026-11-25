/* Worms 3D GameCube PAL 0x8006cecc. Starts a game: counts and logs it, prepares, then creates the game's part types with the owner id, reporting progress through the callback after each; watches GameOver.RoundNumber with 0x8006ce8c, resets four team slots on round 0, sets GameOver.AwardMovie, refreshes the menu list, runs 0x8006e124, posts InGame and CrateChuteRelease and, unless flag 0x00200000 is set, one more message. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct String;
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
struct String {
    char *text;
    String(const char *);
    ~String() { string_finish_8020c5c4(this); string_release_80341588(this); }
    String(const String &);
};
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Message { unsigned short id; const void *vtable; };
struct Key { const char *text; };
struct Handle { int a; int b; Handle() {} void set(int x, int y) { a = x; b = y; } private: Handle(const Handle &); };
struct Slot { char u[20]; int value; };
struct Self { char u0[20]; unsigned id; char u24[4]; char watch[160]; char names[52]; unsigned flags; };
typedef void (*Progress)(int, int);
extern unsigned char t_8040daf8[], t_8040dff8[], t_8040e278[], t_8040e578[], t_8040f110[], t_8040f240[], t_8040f4d8[], t_8040f598[], t_8040f898[], t_8040fa18[], t_804100a8[], t_804105e8[], t_80410768[], t_80410898[], t_80410a60[], t_80410df0[], t_80410f30[], t_8041bbb0[], t_8041c1a0[];
extern int games_804aaac4;
extern void *service_804b178c;
extern void *arena_804b1754;
extern char vt_8040db38[];
extern MessageCache msg_804ad74c, msg_804ad84c;
extern const char s_8037c05c[], s_8037c044[], s_8037baa4[], s_8037bb14[], s_8037be30[], s_8037c070[], s_8037c078[];
extern "C" void debug_print_802fb7ac(const char *, ...);
extern "C" void prepare_8006df98(Self *);
extern "C" void *type_8020b680(void *);
extern "C" void *create_80164514(void *, void *, unsigned);
extern "C" int watch_800fd62c(String *, void *, int, void *);
extern "C" int on_round_8006ce8c();
extern "C" int read_800fc230(Key *, int *);
extern "C" int write_string_800fc550(Key *, const char *);
extern "C" Slot *slot_800fc948(unsigned, Handle *);
extern "C" void destroy_owned_80178474(Handle *, int);
extern "C" void names_freeze_800c4de8(void *);
extern "C" int names_add_800c4b00(void *, const char *);
extern "C" int write_int_800fc3b0(Key *, int);
extern "C" void parts_8006e124(Self *);
extern "C" int message_id_8015f5a0(MessageCache *, int);
extern "C" void *arena_alloc_801613f0(void *, int);
extern "C" int message_post_8016239c(void *);
extern "C" void *message_string_8010a8e0(void *, int, const char *);
#define PROGRESS if (progress) progress(0, 1);
#define CREATE(t) { void *type = type_8020b680(t); create_80164514(service_804b178c, type, self->id); }
#define POST_TEXT(cache, text) { \
    void *m = arena_alloc_801613f0(arena_804b1754, 12); \
    message_post_8016239c(message_string_8010a8e0(m, (unsigned short)message_id_8015f5a0(cache, 1), text)); \
}
extern "C" void w3d_d24g_game_start_8006cecc(Self *self, Progress progress)
{
    debug_print_802fb7ac(s_8037c05c, ++games_804aaac4);
    prepare_8006df98(self);
    PROGRESS
    CREATE(t_8040f240) PROGRESS
    { String name(s_8037c044); watch_800fd62c(&name, (void *)on_round_8006ce8c, 0, self->watch); }
    CREATE(t_804100a8) PROGRESS
    CREATE(t_8040f898) PROGRESS
    CREATE(t_8040daf8) PROGRESS
    CREATE(t_8040e578) PROGRESS
    CREATE(t_8040f598) PROGRESS
    CREATE(t_8040f4d8) PROGRESS
    CREATE(t_80410f30) PROGRESS
    CREATE(t_80410768) PROGRESS
    Handle h;
    int round = 0;
    { Key key; key.text = s_8037c044; read_800fc230(&key, &round); }
    { Key key; key.text = s_8037baa4; write_string_800fc550(&key, s_8037bb14); }
    if (round == 0) {
        h.set(round, 58280);
        for (unsigned i = 0; i <= 3; i++)
            slot_800fc948(i, &h)->value = 0;
        destroy_owned_80178474(&h, 2);
    }
    CREATE(t_8040fa18) PROGRESS
    CREATE(t_8040f110) PROGRESS
    CREATE(t_8040e278) PROGRESS
    CREATE(t_80410df0) PROGRESS
    CREATE(t_80410a60) PROGRESS
    names_freeze_800c4de8(self->names);
    names_add_800c4b00(self->names, s_8037bb14);
    { Key key; key.text = s_8037be30; write_int_800fc3b0(&key, 0); }
    CREATE(t_80410898) PROGRESS
    CREATE(t_8041bbb0) PROGRESS
    CREATE(t_8041c1a0) PROGRESS
    CREATE(t_8040dff8) PROGRESS
    parts_8006e124(self);
    PROGRESS
    CREATE(t_804105e8) PROGRESS
    POST_TEXT(&msg_804ad74c, s_8037c070)
    POST_TEXT(&msg_804ad74c, s_8037c078)
    if (!(self->flags & 0x00200000)) {
        Message *m = (Message *)arena_alloc_801613f0(arena_804b1754, 8);
        m->id = message_id_8015f5a0(&msg_804ad84c, 1);
        m->vtable = vt_8040db38;
        message_post_8016239c(m);
    }
}
