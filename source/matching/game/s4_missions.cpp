extern "C" {
struct S4Object { void (**vtable)(S4Object *); };
struct S4Team { unsigned char pad[40]; int status; unsigned char pad44[16]; const char *name; };
struct S4Teams { unsigned char pad[24]; unsigned int count; int unknown; S4Team *entries[1]; };
struct S4Mission { unsigned char pad[24]; S4Teams *teams; unsigned char pad28[48]; int value; };
struct S4String { char *text; int unknown; };
int w3d_read_int_800fc230(const char **,int *);
void * w3d_find_mission_8027befc(S4String *, void *, int, int);
int w3d_constructor_lookup_name(const char **,S4Object **);
void w3d_string_base_finish(void *);
void w3d_string_release(void *);
S4Object *w3d_empty_80341584(S4Object *);
S4Mission *w3d_auto_801797b4(S4Object *);
extern const char w3d_str_803ceab4[];
int w3d_mission_current_value(void *self)
{
    struct { S4Object *object; int gap; S4String name; const char *key; int mission; const char *lookup; } local;
    local.key = w3d_str_803ceab4;
    w3d_read_int_800fc230(&local.key,&local.mission);
    local.object = 0;
    w3d_find_mission_8027befc(&local.name,self,4,local.mission);
    local.lookup = local.name.text;
    int result = w3d_constructor_lookup_name(&local.lookup,&local.object);
    w3d_string_base_finish(&local.name);
    w3d_string_release(&local.name);
    if (result < 0) {
        if(local.object) local.object->vtable[4](local.object);
        return 1;
    }
    int value = w3d_auto_801797b4(w3d_empty_80341584(local.object))->value;
    if(local.object) local.object->vtable[4](local.object);
    return value;
}

extern const char w3d_str_803ceaa0[];
int strcmp(const char *, const char *);
int w3d_barracks_team_available(void *, const char *name)
{
    struct { S4Object *object; int gap; const char *key; } local;
    local.object = 0;
    S4Object **handle = &local.object;
    if (name && *name != '0') {
        local.key = w3d_str_803ceaa0;
        if (w3d_constructor_lookup_name(&local.key, handle) >= 0) {
            unsigned int i = 0;
            S4Teams *teams = w3d_auto_801797b4(w3d_empty_80341584(local.object))->teams;
            unsigned int count = teams->count;
            S4Team **entries = teams->entries;
            if (i < count) do {
                if (strcmp(name, entries[i]->name) == 0) {
                    if(entries[i]->status != 0) break;
                    if(local.object) local.object->vtable[4](local.object);
                    return 1;
                }
                ++i;
            } while (i < count);
        }
        if(local.object) local.object->vtable[4](local.object);
    }
    return 0;
}
}
