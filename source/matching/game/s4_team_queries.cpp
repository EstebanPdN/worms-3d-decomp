/* Observed team-slot queries and preview cleanup. */
extern "C" {
struct TeamQueryObject { void (**vtable)(TeamQueryObject *); };
struct TeamQueryRef { TeamQueryObject *object; int reserved; };
struct TeamQueryString { char *text; int reserved; };
struct TeamRecord { char unknown00[40]; int user; int protectedName; char unknown30[12]; char *name; };
struct TeamQueryList { char unknown00[24]; unsigned int count; int reserved; TeamRecord *entries[1]; };
struct TeamQueryData { char unknown00[24]; TeamQueryList *list; };
struct TeamGameInit { char unknown00[92]; unsigned int count; char unknown60[56]; unsigned int side1; char unknown9c[68]; unsigned int side2; unsigned int side3; int unknowne8; unsigned int side4; };
struct TeamPreview { char unknown00[124]; TeamQueryObject *object; };
extern void *w3d_global_804b1788;
extern const char w3d_str_803d0bf0[], w3d_str_803d097c[], w3d_str_803d09ec[];
void *memset(void *, ...);
int w3d_constructor_lookup_name(const char **, TeamQueryRef *);
TeamQueryObject *w3d_empty_80341584(TeamQueryObject *);
TeamQueryData *w3d_auto_801797b4(TeamQueryObject *);
void w3d_audio_set_mode5_80129738(void *);
void w3d_string_default(TeamQueryString *);
void w3d_string_assign(TeamQueryString *, const char *);
void w3d_string_base_finish(TeamQueryString *);
void w3d_string_release(TeamQueryString *);
int w3d_lookup_text_800fc2b0(const char **, const char **);
int strcmp(const char *, const char *);
unsigned int w3d_s4_team_first_unused_side()
{
    struct { TeamQueryRef ref; int used[4]; const char *query; int reserved; } local;
    register TeamQueryRef *ref = &local.ref;
    local.ref.object = 0;
    memset(local.used, 0, 16);
    local.query = w3d_str_803d0bf0;
    if (w3d_constructor_lookup_name(&local.query, ref) >= 0) {
        TeamGameInit *data = (TeamGameInit *)w3d_auto_801797b4(w3d_empty_80341584(local.ref.object));
        switch (data->count) {
        case 4: local.used[data->side4] = 1;
        case 3: local.used[data->side3] = 1;
        case 2: local.used[data->side2] = 1;
        default: break;
        }
        local.used[data->side1] = 1;
        int *entry = local.used;
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
#if 0 /* Null-path branch skips a repeated read in the candidate. */
void w3d_s4_team_preview_clear(TeamPreview *self)
{
    if (self->object) self->object->vtable[6](self->object);
    if (self->object) self->object->vtable[4](self->object);
    self->object = 0;
    w3d_audio_set_mode5_80129738(w3d_global_804b1788);
}
#endif
#if 0 /* Loop bound and counter register allocation differ. */
int w3d_s4_team_has_user_capacity()
{
    struct { TeamQueryRef ref; const char *name; int reserved; } local;
    local.ref.object = 0;
    local.name = w3d_str_803d097c;
    unsigned int users = 0;
    if (w3d_constructor_lookup_name(&local.name, &local.ref) >= 0) {
        TeamQueryData *data = w3d_auto_801797b4(w3d_empty_80341584(local.ref.object));
        TeamQueryList *list = data->list;
        register unsigned int count = list->count;
        TeamRecord **entry = list->entries;
        unsigned int i = 0;
        if (users < count) {
            register unsigned int bound = count;
            do {
                TeamRecord *record = *entry++;
                if (record->user) ++users;
                ++i;
            } while (i < bound);
        }
        if (users <= 9) goto yes;
    }
    if (local.ref.object) local.ref.object->vtable[4](local.ref.object);
    return 0;
yes:
    if (local.ref.object) local.ref.object->vtable[4](local.ref.object);
    return 1;
}
#endif
#if 0 /* Local string pointer and result register allocation differ. */
int w3d_s4_team_name_is_protected()
{
    struct { TeamQueryString name; TeamQueryRef ref; const char *userName; const char *result; const char *barracks; int reserved; } local;
    w3d_string_default(&local.name);
    register TeamQueryString *name = &local.name;
    local.userName = w3d_str_803d09ec;
    w3d_lookup_text_800fc2b0(&local.userName, &local.result);
    w3d_string_assign(&local.name, local.result);
    if (!*(unsigned short *)(local.name.text - 4) || local.result[0] == ' ') {
        w3d_string_base_finish(name);
        w3d_string_release(name);
        return 1;
    }
    local.ref.object = 0;
    local.barracks = w3d_str_803d097c;
    if (w3d_constructor_lookup_name(&local.barracks, &local.ref) >= 0) {
        TeamQueryData *data = w3d_auto_801797b4(w3d_empty_80341584(local.ref.object));
        TeamQueryList *list = data->list;
        unsigned int count = list->count;
        TeamRecord **entries = list->entries;
        for (unsigned int i = 0; i < count; ++i) {
            if (!strcmp(entries[i]->name, local.name.text)) {
                register int result = 1;
                if (!entries[i]->protectedName) result = 0;
                if (local.ref.object) local.ref.object->vtable[4](local.ref.object);
                w3d_string_base_finish(name);
                w3d_string_release(name);
                return result;
            }
        }
    }
    if (local.ref.object) local.ref.object->vtable[4](local.ref.object);
    w3d_string_base_finish(name);
    w3d_string_release(name);
    return 0;
}#endif

}
