#include "w3d_ptr.h"
#line 1 "s4_team_properties.cpp"
/* Observed team/barracks property lookup and update operations. */
extern "C" {
struct TeamObject { Ptr32<Ptr32<void (Ptr32<TeamObject>)>> vtable; };
struct TeamRef { Ptr32<TeamObject> object; int reserved; };
struct TeamString { Ptr32<char> text; int reserved; };
struct TeamData { char unknown00[24]; Ptr32<struct TeamList> list; };
struct TeamList { char unknown00[24]; unsigned int count; };
struct GameInit { char unknown00[64]; Ptr32<char> team1; char unknown44[76]; Ptr32<char> team2; char unknown94[68]; Ptr32<char> team3; char unknowndc[72]; Ptr32<char> team4; };
void w3d_string_base_init(Ptr32<TeamString>);
Ptr32<unsigned short> w3d_string_header(Ptr32<TeamString>);
void w3d_string_base_finish(Ptr32<TeamString>);
void w3d_string_release(Ptr32<TeamString>);
int w3d_constructor_lookup_name(Ptr32<Ptr32<const char>>, Ptr32<TeamRef>);
Ptr32<TeamObject> w3d_empty_80341584(Ptr32<TeamObject>);
Ptr32<TeamData> w3d_auto_801797b4(Ptr32<TeamObject>);
int w3d_team_kind_802997fc(Ptr32<void>);
void w3d_set_integer_800fc43c(Ptr32<Ptr32<const char>>, int);
int w3d_get_integer_800fc1f0(Ptr32<Ptr32<const char>>, Ptr32<int>);
void w3d_set_boolean_80178c54(Ptr32<TeamObject>, Ptr32<int>);
void w3d_set_integer_80178d28(Ptr32<TeamObject>, Ptr32<int>);
Ptr32<TeamObject> w3d_empty_803426b4(Ptr32<TeamObject>);
Ptr32<TeamObject> w3d_constructor_native_cast(Ptr32<TeamObject>);
void w3d_update_team_8029b83c(Ptr32<void>, Ptr32<const char>);
int w3d_lookup_text_800fc2b0(Ptr32<Ptr32<const char>>, Ptr32<Ptr32<const char>>);
Ptr32<void> w3d_string_from_text(Ptr32<TeamString>, Ptr32<const char>);
int strcmp(Ptr32<const char>, Ptr32<const char>);
extern const char w3d_str_803d097c[], w3d_str_803d0a54[], w3d_str_803d0b88[], w3d_str_803d0bf0[];
extern const char w3d_str_803d0c2c[], w3d_str_803d0c40[];
void w3d_team_set_named_80299b48(Ptr32<void>, Ptr32<TeamString>, int);
int w3d_s4_team_has_capacity(Ptr32<void>)
{
    struct { TeamRef ref; Ptr32<const char> name; int reserved; } local;
    local.ref.object = 0;
    local.name = w3d_str_803d097c;
    int available = 1;
    if (w3d_constructor_lookup_name(&local.name, &local.ref) < 0) {
        if (local.ref.object) local.ref.object->vtable[4](local.ref.object);
        return 0;
    }
    Ptr32<TeamData> data = w3d_auto_801797b4(w3d_empty_80341584(local.ref.object));
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
void w3d_s4_team_update_named_state(Ptr32<void> self, Ptr32<TeamString> name)
{
    if (*(Ptr32<unsigned short>)(name->text - 4)) {
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
void w3d_s4_team_refresh_game_names(Ptr32<void> self)
{
    struct { TeamRef ref; Ptr32<const char> query; int reserved; } local;
    local.ref.object = 0;
    local.query = w3d_str_803d0bf0;
    if (w3d_constructor_lookup_name(&local.query, &local.ref) < 0) {
        if (local.ref.object) local.ref.object->vtable[4](local.ref.object);
        return;
    } else {
        Ptr32<GameInit> data = (Ptr32<GameInit>)w3d_auto_801797b4(w3d_empty_80341584(local.ref.object));
        w3d_update_team_8029b83c(self, data->team1);
        w3d_update_team_8029b83c(self, data->team2);
        w3d_update_team_8029b83c(self, data->team3);
        w3d_update_team_8029b83c(self, data->team4);
    }
    if (local.ref.object) local.ref.object->vtable[4](local.ref.object);
}
extern Ptr32<void> w3d_global_804b1754;
extern unsigned char w3d_message_804b0e54[8];
Ptr32<void> w3d_message_allocate_801613f0(Ptr32<void>, unsigned int);
unsigned int w3d_cached_message_id(Ptr32<void>, int);
Ptr32<void> w3d_message_string_init(Ptr32<void>, unsigned short, Ptr32<const char>);
int w3d_message_post_current(Ptr32<void>);
void w3d_s4_team_network_update(Ptr32<void>, Ptr32<const char> name)
{
    Ptr32<void> message = w3d_message_allocate_801613f0(w3d_global_804b1754, 12);
    unsigned short id = w3d_cached_message_id(w3d_message_804b0e54, 1);
    w3d_message_post_current(w3d_message_string_init(message, id, name));
}
void w3d_s4_team_update_for_game_type(Ptr32<void> self, Ptr32<const char> name)
{
    struct { TeamString type; Ptr32<const char> query; Ptr32<const char> result; } local;
    local.query = w3d_str_803d0c2c;
    w3d_lookup_text_800fc2b0(&local.query, &local.result);
    w3d_string_from_text(&local.type, local.result);
    register Ptr32<const char> network = w3d_str_803d0c40;
    bool offline = strcmp(local.type.text, network) != 0;
    if (offline) w3d_update_team_8029b83c(self, name);
    else w3d_s4_team_network_update(self, name);
    register Ptr32<TeamString> type = &local.type;
    w3d_string_base_finish(type);
    w3d_string_release(type);
}
}


