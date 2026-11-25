/* Observed team/barracks property lookup and update operations. */
extern "C" {
struct TeamObject { void (**vtable)(TeamObject *); };
struct TeamRef { TeamObject *object; int reserved; };
struct TeamString { char *text; int reserved; };
struct TeamData { char unknown00[24]; struct TeamList *list; };
struct TeamList { char unknown00[24]; unsigned int count; };
struct GameInit { char unknown00[64]; char *team1; char unknown44[76]; char *team2; char unknown94[68]; char *team3; char unknowndc[72]; char *team4; };
void w3d_string_base_init(TeamString *);
unsigned short *w3d_string_header(TeamString *);
void w3d_string_base_finish(TeamString *);
void w3d_string_release(TeamString *);
int w3d_constructor_lookup_name(const char **, TeamRef *);
TeamObject *w3d_empty_80341584(TeamObject *);
TeamData *w3d_auto_801797b4(TeamObject *);
int w3d_team_kind_802997fc(void *);
void w3d_set_integer_800fc43c(const char **, int);
int w3d_get_integer_800fc1f0(const char **, int *);
void w3d_set_boolean_80178c54(TeamObject *, int *);
void w3d_set_integer_80178d28(TeamObject *, int *);
TeamObject *w3d_empty_803426b4(TeamObject *);
TeamObject *w3d_constructor_native_cast(TeamObject *);
void w3d_update_team_8029b83c(void *, const char *);
int w3d_lookup_text_800fc2b0(const char **, const char **);
void * w3d_string_from_text(TeamString *, const char *);
int strcmp(const char *, const char *);
extern const char w3d_str_803d097c[], w3d_str_803d0a54[], w3d_str_803d0b88[], w3d_str_803d0bf0[];
extern const char w3d_str_803d0c2c[], w3d_str_803d0c40[];
void w3d_team_set_named_80299b48(void *, TeamString *, int);
int w3d_s4_team_has_capacity(void *)
{
    struct { TeamRef ref; const char *name; int reserved; } local;
    local.ref.object = 0;
    local.name = w3d_str_803d097c;
    int available = 1;
    if (w3d_constructor_lookup_name(&local.name, &local.ref) < 0) {
        if (local.ref.object) local.ref.object->vtable[4](local.ref.object);
        return 0;
    }
    TeamData *data = w3d_auto_801797b4(w3d_empty_80341584(local.ref.object));
    if (data->list->count > 19) available = 0;
    if (local.ref.object) local.ref.object->vtable[4](local.ref.object);
    return available;
}
#if 0 /* Repeated string-cleanup blocks retain a different stack-pointer register. */
void w3d_team_set_named_80299b48(void *, TeamString *name, int value)
{
    struct { TeamRef ref; TeamString text; const char *query; int value; } local;
    local.value = value;
    local.ref.object = 0;
    local.query = name->text;
    if (w3d_constructor_lookup_name(&local.query, &local.ref) < 0) {
        w3d_string_base_init(&local.text);
        local.text.text = name->text;
        ++*w3d_string_header(&local.text);
        w3d_string_base_finish(&local.text);
        w3d_string_release(&local.text);
        if (local.ref.object) local.ref.object->vtable[4](local.ref.object);
        goto done;
    } else {
        int kind = ((int (*)(TeamObject *))local.ref.object->vtable[6])(local.ref.object);
        switch(kind) {
        case 0: w3d_set_boolean_80178c54(w3d_empty_803426b4(local.ref.object), &local.value); break;
        case 1: w3d_set_integer_80178d28(w3d_constructor_native_cast(local.ref.object), &local.value); break;
        default:
            w3d_string_base_init(&local.text);
            local.text.text = name->text;
            ++*w3d_string_header(&local.text);
            w3d_string_base_finish(&local.text);
            w3d_string_release(&local.text);
        }
    }
    if (local.ref.object) local.ref.object->vtable[4](local.ref.object);
done:
    w3d_string_base_finish(name);
    w3d_string_release(name);
}
#endif
void w3d_s4_team_update_named_state(void *self, TeamString *name)
{
    if (*(unsigned short *)(name->text - 4)) {
        int enabled = 1;
        if (!w3d_s4_team_has_capacity(self)) enabled = 0;
        if (w3d_team_kind_802997fc(self) == 1) enabled = 0;
        TeamString copy;
        w3d_string_base_init(&copy);
        copy.text = name->text;
        ++*w3d_string_header(&copy);
        w3d_team_set_named_80299b48(self, &copy, enabled);
    }
    w3d_string_base_finish(name);
    w3d_string_release(name);
}
#if 0 /* Boolean lowering and local-string register allocation differ. */
void w3d_s4_team_update_skill(void *self, TeamString *name)
{
    struct { TeamRef ref; TeamString copy; const char *skill; const char *permission; int permissionValue; int reserved; } local;
    if (!*(unsigned short *)(name->text - 4)) {
        local.skill = w3d_str_803d0a54;
        w3d_set_integer_800fc43c(&local.skill, 0);
    } else {
        local.ref.object = 0;
        register int difference = w3d_team_kind_802997fc(self) ^ 1;
        int value = difference != 0;
        if (value == 1) {
            local.permissionValue = 0;
            local.permission = w3d_str_803d0b88;
            w3d_get_integer_800fc1f0(&local.permission, &local.permissionValue);
            if (local.permissionValue == 1) value = 0;
        }
        w3d_string_base_init(&local.copy);
        local.copy.text = name->text;
        ++*w3d_string_header(&local.copy);
        w3d_team_set_named_80299b48(self, &local.copy, value);
        if (local.ref.object) local.ref.object->vtable[4](local.ref.object);
    }
    w3d_string_base_finish(name);
    w3d_string_release(name);
}
#endif
void w3d_s4_team_refresh_game_names(void *self)
{
    struct { TeamRef ref; const char *query; int reserved; } local;
    local.ref.object = 0;
    local.query = w3d_str_803d0bf0;
    if (w3d_constructor_lookup_name(&local.query, &local.ref) < 0) {
        if (local.ref.object) local.ref.object->vtable[4](local.ref.object);
        return;
    } else {
        GameInit *data = (GameInit *)w3d_auto_801797b4(w3d_empty_80341584(local.ref.object));
        w3d_update_team_8029b83c(self, data->team1);
        w3d_update_team_8029b83c(self, data->team2);
        w3d_update_team_8029b83c(self, data->team3);
        w3d_update_team_8029b83c(self, data->team4);
    }
    if (local.ref.object) local.ref.object->vtable[4](local.ref.object);
}
extern void *w3d_global_804b1754;
extern unsigned char w3d_message_804b0e54[8];
void *w3d_message_allocate_801613f0(void *, unsigned int);
unsigned int w3d_cached_message_id(void *, int);
void *w3d_message_string_init(void *, unsigned short, const char *);
int w3d_message_post_current(void *);
void w3d_s4_team_network_update(void *, const char *name)
{
    void *message = w3d_message_allocate_801613f0(w3d_global_804b1754, 12);
    unsigned short id = w3d_cached_message_id(w3d_message_804b0e54, 1);
    w3d_message_post_current(w3d_message_string_init(message, id, name));
}
void w3d_s4_team_update_for_game_type(void *self, const char *name)
{
    struct { TeamString type; const char *query; const char *result; } local;
    local.query = w3d_str_803d0c2c;
    w3d_lookup_text_800fc2b0(&local.query, &local.result);
    w3d_string_from_text(&local.type, local.result);
    register const char *network = w3d_str_803d0c40;
    bool offline = strcmp(local.type.text, network) != 0;
    if (offline) w3d_update_team_8029b83c(self, name);
    else w3d_s4_team_network_update(self, name);
    register TeamString *type = &local.type;
    w3d_string_base_finish(type);
    w3d_string_release(type);
}
}
