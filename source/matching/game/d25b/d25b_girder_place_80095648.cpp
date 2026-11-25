/* Girder placement try (0x80095648): when the placed count at +744 is below the limit at
 * +740, checks the state at +684, the flags at +696 and +704 and the query 0x80096564 and
 * otherwise runs 0x800959cc. Formats the large or small template name by +688, posts the
 * placement message (0x80108154), plays the placement effects (0x800fc330, 0x800fdc80,
 * 0x80178c54, the table at +108 of the sound owner 0x804b1788), raises the counter
 * through 0x80178d28, and either finishes (state 6, 0x8002ad9c, 0x8002ae70) or restarts
 * placement from the next height. Field and type names are inferred from the original
 * instructions. The unit owns no data. */
struct Vec3 {
    float x, y, z;
    void Set(float a, float b, float c) { x = a; Vec3 *p = this; p->y = b; p->z = c; }
};
struct Text128 {
    char text[128];
    Text128() { text[0] = 0; }
    Text128(const char *format, ...);
};
struct PropertyKey { const char *name; };
struct Info { char unknown00[152]; unsigned char a; unsigned char b; };
struct Message { unsigned short id; void *vtable; };
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Sounds;
struct SoundsVtable { char unknown00[96]; void (*play)(Sounds *, const char *, const Vec3 *); };
struct Sounds { SoundsVtable *vtable; };
struct Owner { char unknown00[108]; Sounds *sounds; };
struct Girder {
    char unknown00[184];
    Vec3 position;    /* +184 */
    Vec3 previous;    /* +196 */
    Vec3 start;       /* +208 */
    char unknown220[84];
    float y;          /* +304 */
    char unknown308[16];
    float x;          /* +324 */
    char unknown328[356];
    int state;        /* +684 */
    int large;        /* +688 */
    char unknown692[4];
    int busy;         /* +696 */
    char unknown700[4];
    int blocked;      /* +704 */
    char unknown708[8];
    int phase;        /* +716 */
    char unknown720[4];
    int positionValue; /* +724 */
    char unknown728[8];
    int placedValue;  /* +736 */
    unsigned limit;   /* +740 */
    unsigned count;   /* +744 */
    char unknown748[4];
    int occlude;      /* +752 */
};
extern "C" unsigned s19_handle_cast_query_80096564(Girder *);
extern "C" void w3d_empty_800959cc(Girder *);
extern "C" void *w3d_arena_alloc_801613f0(void *, int);
extern "C" int w3d_cached_message_id_8015f5a0(MessageCache *, int);
extern "C" void *w3d_particle_vector_message_80108154(void *, unsigned short, Text128 *, Vec3 *, Vec3 *);
extern "C" int w3d_message_post_8016239c(void *);
extern "C" int w3d_auto_800fc330(PropertyKey *, Info **);
extern "C" int w3d_forward_global6_800fdc80(int, int, Vec3 *, int, int, int);
extern "C" void s9_update_value_80178c54(void *, int *);
extern "C" int w3d_cast_80342a78(int);
extern "C" int s9_update_value_80178d28(void *, int *);
extern "C" void s19_fire_once_8002ad9c(Girder *);
extern "C" void w3d_auto_8002ae70(Girder *);
extern "C" int w3d_empty_80342fa4(int);
extern "C" int w3d_set_vector_80178fa4(void *, Vec3 *);
extern void *w3d_message_arena_804b1754;
extern Owner *w3d_owner_804b1788;
extern MessageCache w3d_message_804adf28, w3d_message_804adf10, w3d_message_804adf08;
extern char w3d_obj_8040db38[];
extern "C" char w3d_string_8037eb50[]; /* "Girder.TemplateLarge" */
extern "C" char w3d_string_8037eb68[]; /* "Girder.TemplateSmall" */
extern "C" char w3d_string_8037eb80[]; /* "kUtilityGirder" */
extern "C" char w3d_string_8037eb90[]; /* "Girder.Place" */

inline void PostPlain(MessageCache *cache)
{
    Message *m = (Message *)w3d_arena_alloc_801613f0(w3d_message_arena_804b1754, 8);
    m->id = w3d_cached_message_id_8015f5a0(cache, 1);
    m->vtable = w3d_obj_8040db38;
    w3d_message_post_8016239c(m);
}

extern "C" void w3d_d25b_girder_place_80095648(Girder *self)
{
    if (self->count >= self->limit) return;
    if (self->state != 1 || self->busy != 0 || self->blocked != 0 || s19_handle_cast_query_80096564(self) > 44) {
        w3d_empty_800959cc(self);
        return;
    }
    Vec3 at;
    at.Set(self->x, self->y, 0.0f);
    Text128 name;
    if (self->large == 1) name = Text128(w3d_string_8037eb50);
    else name = Text128(w3d_string_8037eb68);
    {
        void *m = w3d_arena_alloc_801613f0(w3d_message_arena_804b1754, 8);
        w3d_message_post_8016239c(w3d_particle_vector_message_80108154(m, w3d_cached_message_id_8015f5a0(&w3d_message_804adf28, 1), &name, &self->position, &at));
    }
    {
        PropertyKey key;
        Info *info;
        key.name = w3d_string_8037eb80;
        w3d_auto_800fc330(&key, &info);
        w3d_forward_global6_800fdc80(info->b, info->a, &self->position, 500, -1, -1);
    }
    {
        int zero = 0;
        s9_update_value_80178c54((void *)self->occlude, &zero);
    }
    Sounds *sounds = w3d_owner_804b1788->sounds;
    if (sounds) sounds->vtable->play(sounds, w3d_string_8037eb90, &self->position);
    {
        unsigned used = s19_handle_cast_query_80096564(self);
        int target = w3d_cast_80342a78(self->placedValue);
        int value = used + 1;
        s9_update_value_80178d28((void *)target, &value);
    }
    self->count++;
    if (self->count >= self->limit) {
        self->state = 6;
        if (self->limit > 1) PostPlain(&w3d_message_804adf10);
        s19_fire_once_8002ad9c(self);
        w3d_auto_8002ae70(self);
        return;
    }
    self->state = 1;
    self->phase = 1;
    self->position.y += 40.0f;
    self->start = self->position;
    self->previous = self->position;
    w3d_set_vector_80178fa4((void *)(w3d_empty_80342fa4(self->positionValue)), &self->position);
    PostPlain(&w3d_message_804adf08);
}
