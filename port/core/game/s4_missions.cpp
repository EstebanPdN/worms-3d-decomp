#include "w3d_ptr.h"
#line 1 "s4_missions.cpp"
extern "C" {
struct S4Object { Ptr32<Ptr32<void (Ptr32<S4Object>)>> vtable; };
struct S4Team { unsigned char pad[40]; int status; unsigned char pad44[16]; Ptr32<const char> name; };
struct S4Teams { unsigned char pad[24]; unsigned int count; int unknown; Ptr32<S4Team> entries[1]; };
struct S4Mission { unsigned char pad[24]; Ptr32<S4Teams> teams; unsigned char pad28[48]; int value; };
struct S4String { Ptr32<char> text; int unknown; };
int w3d_read_int_800fc230(Ptr32<Ptr32<const char>>,Ptr32<int>);
Ptr32<void> w3d_find_mission_8027befc(Ptr32<S4String>, Ptr32<void>, int, int);
int w3d_constructor_lookup_name(Ptr32<Ptr32<const char>>,Ptr32<Ptr32<S4Object>>);
void w3d_string_base_finish(Ptr32<void>);
void w3d_string_release(Ptr32<void>);
Ptr32<S4Object> w3d_empty_80341584(Ptr32<S4Object>);
Ptr32<S4Mission> w3d_auto_801797b4(Ptr32<S4Object>);
extern const char w3d_str_803ceab4[];
int w3d_mission_current_value(Ptr32<void> self)
{
    struct { Ptr32<S4Object> object; int gap; S4String name; Ptr32<const char> key; int mission; Ptr32<const char> lookup; } local;
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
int strcmp(Ptr32<const char>, Ptr32<const char>);
int w3d_barracks_team_available(Ptr32<void>, Ptr32<const char> name)
{
    struct { Ptr32<S4Object> object; int gap; Ptr32<const char> key; } local;
    local.object = 0;
    Ptr32<Ptr32<S4Object>> handle = &local.object;
    if (name && *name != '0') {
        local.key = w3d_str_803ceaa0;
        if (w3d_constructor_lookup_name(&local.key, handle) >= 0) {
            unsigned int i = 0;
            Ptr32<S4Teams> teams = w3d_auto_801797b4(w3d_empty_80341584(local.object))->teams;
            unsigned int count = teams->count;
            Ptr32<Ptr32<S4Team>> entries = teams->entries;
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


