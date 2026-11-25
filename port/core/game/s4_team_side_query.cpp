#include "w3d_ptr.h"
#line 1 "s4_team_side_query.cpp"
/* Observed team-slot queries and preview cleanup. */
extern "C" {
struct TeamQueryObject { Ptr32<Ptr32<void (Ptr32<TeamQueryObject>)>> vtable; };
struct TeamQueryRef { Ptr32<TeamQueryObject> object; int reserved; };
struct TeamQueryString { Ptr32<char> text; int reserved; };
struct TeamRecord { char unknown00[40]; int user; int protectedName; char unknown30[12]; Ptr32<char> name; };
struct TeamQueryList { char unknown00[24]; unsigned int count; int reserved; Ptr32<TeamRecord> entries[1]; };
struct TeamQueryData { char unknown00[24]; Ptr32<TeamQueryList> list; };
struct TeamGameInit { char unknown00[92]; unsigned int count; char unknown60[56]; unsigned int side1; char unknown9c[68]; unsigned int side2; unsigned int side3; int unknowne8; unsigned int side4; };
struct TeamPreview { char unknown00[124]; Ptr32<TeamQueryObject> object; };
extern Ptr32<void> w3d_global_804b1788;
extern const char w3d_str_803d0bf0[], w3d_str_803d097c[], w3d_str_803d09ec[];
Ptr32<void> memset(Ptr32<void>, ...);
int w3d_constructor_lookup_name(Ptr32<Ptr32<const char>>, Ptr32<TeamQueryRef>);
Ptr32<TeamQueryObject> w3d_empty_80341584(Ptr32<TeamQueryObject>);
Ptr32<TeamQueryData> w3d_auto_801797b4(Ptr32<TeamQueryObject>);
void w3d_audio_set_mode5_80129738(Ptr32<void>);
void w3d_string_default(Ptr32<TeamQueryString>);
void w3d_string_assign(Ptr32<TeamQueryString>, Ptr32<const char>);
void w3d_string_base_finish(Ptr32<TeamQueryString>);
void w3d_string_release(Ptr32<TeamQueryString>);
int w3d_lookup_text_800fc2b0(Ptr32<Ptr32<const char>>, Ptr32<Ptr32<const char>>);
int strcmp(Ptr32<const char>, Ptr32<const char>);
unsigned int w3d_s4_team_first_unused_side()
{
    struct { TeamQueryRef ref; int used[4]; Ptr32<const char> query; int reserved; } local;
    register Ptr32<TeamQueryRef> ref = &local.ref;
    local.ref.object = 0;
    memset(local.used, 0, 16);
    local.query = w3d_str_803d0bf0;
    if (w3d_constructor_lookup_name(&local.query, ref) >= 0) {
        Ptr32<TeamGameInit> data = (Ptr32<TeamGameInit>)w3d_auto_801797b4(w3d_empty_80341584(local.ref.object));
        switch (data->count) {
        case 4: local.used[data->side4] = 1;
        case 3: local.used[data->side3] = 1;
        case 2: local.used[data->side2] = 1;
        default: break;
        }
        local.used[data->side1] = 1;
        Ptr32<int> entry = local.used;
        for (unsigned int i = 0; i < 4; ++i) {
            if (!*entry++) {
                if (local.ref.object) local.ref.object->vtable[4](local.ref.object);
                return i;
            }
        }
    }
    if (local.ref.object) local.ref.object->vtable[4](local.ref.object);
    return 0;
}

}


