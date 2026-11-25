/* Worms 3D GameCube PAL 0x8006ba08. Front-end start: prepares, copies the next state to the current, clears FE.ShowMenuBackdrop, trims the menu list at +188 and refills it with the default menu and FE.LanguageSelect when needed, creates eleven part types with the owner id, posts one message if FE.UseMouse is set, posts two menu messages, steps 0x800a7ea0, posts an int message and runs storage maintenance. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Message { unsigned short id; const void *vtable; };
struct Key { const char *text; };
struct NameList;
struct App;
struct Self { char u0[20]; unsigned id; char u24[164]; char names[20]; int state; int nextState; };
extern "C" void prepare_8006eebc(Self *);
extern "C" int write_int_800fc3b0(Key *, int);
extern "C" int read_int_800fc1f0(Key *, int *);
extern "C" void trim_800c4e18(void *);
extern "C" int count_800c4660(void *);
extern "C" const char *default_name_80127da4(App *);
extern "C" int add_800c4b00(void *, const char *);
extern "C" int language_80127b48();
extern "C" void *type_8020b680(void *);
extern "C" void *create_80164514(void *, void *, unsigned);
extern "C" int message_id_8015f5a0(MessageCache *, int);
extern "C" void *arena_alloc_801613f0(void *, int);
extern "C" int message_post_8016239c(void *);
extern "C" void *message_string_8010a8e0(void *, int, const char *);
extern "C" void *message_int_800a82f0(void *, int, int);
extern "C" void step_800a7ea0();
extern "C" void maintain_8006e6c8(Self *);
extern void *arena_804b1754;
extern void *service_804b178c;
extern App *app_804b1788;
extern char vt_8040db38[];
extern unsigned char type_8040f240[], type_8041c1e0[], type_8041c260[], type_8041c1a0[], type_8040fa18[], type_80410898[], type_8040fa58[], type_8041bae0[], type_8040f9d8[], type_8041bbb0[], type_804100a8[];
extern MessageCache msg_804ad744, msg_804ad754, msg_804ad74c, msg_804ad78c;
extern const char s_8037be30[], s_8037be44[], s_8037be58[], s_8037bb14[], s_8037bd3c[];
#define POST_TEXT(cache, text) { \
    void *m = arena_alloc_801613f0(arena_804b1754, 12); \
    message_post_8016239c(message_string_8010a8e0(m, (unsigned short)message_id_8015f5a0(cache, 1), text)); \
}
extern "C" void w3d_d24g_frontend_start_8006ba08(Self *self)
{
    prepare_8006eebc(self);
    self->state = self->nextState;
    { Key key; key.text = s_8037be30; write_int_800fc3b0(&key, 0); }
    trim_800c4e18(self->names);
    if (count_800c4660(self->names) == 0) {
        add_800c4b00(self->names, default_name_80127da4(app_804b1788));
        if (language_80127b48() == 1)
            add_800c4b00(self->names, s_8037be44);
    }
    { void *type = type_8020b680(type_8040f240); create_80164514(service_804b178c, type, self->id); }
    { void *type = type_8020b680(type_8041c1e0); create_80164514(service_804b178c, type, self->id); }
    { void *type = type_8020b680(type_8041c260); create_80164514(service_804b178c, type, self->id); }
    { void *type = type_8020b680(type_8041c1a0); create_80164514(service_804b178c, type, self->id); }
    { void *type = type_8020b680(type_8040fa18); create_80164514(service_804b178c, type, self->id); }
    { void *type = type_8020b680(type_80410898); create_80164514(service_804b178c, type, self->id); }
    { void *type = type_8020b680(type_8040fa58); create_80164514(service_804b178c, type, self->id); }
    { void *type = type_8020b680(type_8041bae0); create_80164514(service_804b178c, type, self->id); }
    { void *type = type_8020b680(type_8040f9d8); create_80164514(service_804b178c, type, self->id); }
    { void *type = type_8020b680(type_8041bbb0); create_80164514(service_804b178c, type, self->id); }
    { void *type = type_8020b680(type_804100a8); create_80164514(service_804b178c, type, self->id); }
    int useMouse;
    { Key key; key.text = s_8037be58; read_int_800fc1f0(&key, &useMouse); }
    if (useMouse) {
        Message *m = (Message *)arena_alloc_801613f0(arena_804b1754, 8);
        m->id = message_id_8015f5a0(&msg_804ad744, 1);
        m->vtable = vt_8040db38;
        message_post_8016239c(m);
    }
    POST_TEXT(&msg_804ad754, s_8037bb14)
    POST_TEXT(&msg_804ad74c, s_8037bd3c)
    step_800a7ea0();
    {
        void *i = arena_alloc_801613f0(arena_804b1754, 12);
        message_post_8016239c(message_int_800a82f0(i, (unsigned short)message_id_8015f5a0(&msg_804ad78c, 1), 1));
    }
    maintain_8006e6c8(self);
}
