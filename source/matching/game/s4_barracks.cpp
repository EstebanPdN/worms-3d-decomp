extern "C" {
struct S4Object { void (**vtable)(S4Object *); };
struct S4Team { unsigned char pad[64]; int selection; };
struct S4TeamList { unsigned char pad[24]; unsigned int count; int unknown; S4Team *entries[1]; };
struct S4Barracks { unsigned char pad[24]; S4TeamList *teams; };
int w3d_constructor_lookup_name(const char **,S4Object **);
S4Object *w3d_empty_80341584(S4Object *);
S4Object *w3d_auto_80179598(S4Object *,void *);
void w3d_type_token_destroy_80178474(void *,int);
extern const char w3d_str_803ceaa0[];
// Deferred: token initialization and register allocation differ after three attempts.
#if 0
void w3d_barracks_clear_team_selections(void)
{
    struct {
        unsigned long long token; S4Object *object; int gap;
        S4Object *held; int gap24; S4Object *temp; int gap32;
        const char *key;
    } local;
    local.token = 58280;
    unsigned long long *token = &local.token;
    local.object = 0;
    local.key = w3d_str_803ceaa0;
    if(w3d_constructor_lookup_name(&local.key,&local.object) < 0) {
        if(local.object) local.object->vtable[4](local.object);
        w3d_type_token_destroy_80178474(token,2);
        return;
    }
    local.held = 0;
    local.temp = w3d_auto_80179598(w3d_empty_80341584(local.object),token);
    if(local.temp) local.temp->vtable[3](local.temp);
    S4Object *temp = local.temp;
    if(temp) {
        temp->vtable[3](temp);
        if(local.held) local.held->vtable[4](local.held);
        local.held = temp;
    }
    if(local.temp) local.temp->vtable[4](local.temp);
    S4TeamList *teams = ((S4Barracks *)local.held)->teams;
    unsigned int i = 0;
    unsigned int count = teams->count;
    S4Team **entries = teams->entries;
    if(i < count) do {
        (*entries)->selection = 0;
        ++i; ++entries;
    } while (i < count);
    if(local.held) local.held->vtable[4](local.held);
    if(local.object) local.object->vtable[4](local.object);
    w3d_type_token_destroy_80178474(&local.token,2);
}
#endif
struct S4String { char *text; int gap; };
struct S4Mission { char pad[32]; int value; };
void w3d_string_from_text(void *, const char *);
void w3d_find_mission_8027befc(S4String *,void *,int,int);
void w3d_string_release_header(void *);
void w3d_string_base_finish(void *);
void w3d_string_release(void *);
void w3d_string_assign(void *, const char *);
S4Mission *w3d_auto_801797b4(S4Object *);
extern const char w3d_str_803cea20[];
// Deferred: four argument-setup words still differ after four attempts.
#if 0
int w3d_mission_lookup_value(void *self,int kind,int index)
{
    struct { S4String name; union { S4String temporary; S4Object *object; } u; const char *lookup; } local;
    w3d_string_from_text(&local.name,w3d_str_803cea20);
    S4String *temporary = &local.u.temporary;
    w3d_find_mission_8027befc(temporary,self,kind,index);
    S4String *name = &local.name;
    char *incoming = local.u.temporary.text;
    ++*(unsigned short *)(incoming-6);
    char *old = local.name.text;
    unsigned short *header = (unsigned short *)(old-6);
    int remaining = *header - 1;
    *header = remaining;
    if((unsigned short)remaining == 0) w3d_string_release_header(header);
    local.name.text = local.u.temporary.text;
    w3d_string_base_finish(temporary);
    w3d_string_release(temporary);
    local.u.object = 0;
    local.lookup = local.name.text;
    if(w3d_constructor_lookup_name(&local.lookup,&local.u.object) < 0) {
        w3d_string_assign(name,w3d_str_803cea20);
        if(local.u.object) local.u.object->vtable[4](local.u.object);
        w3d_string_base_finish(name);
        w3d_string_release(name);
        return 999;
    }
    int value = w3d_auto_801797b4(w3d_empty_80341584(local.u.object))->value;
    if(local.u.object) local.u.object->vtable[4](local.u.object);
    w3d_string_base_finish(name);
    w3d_string_release(name);
    return value;
}
#endif
}
