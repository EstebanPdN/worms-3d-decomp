typedef struct S3Interface S3Interface;
typedef struct S3InterfaceVtable {
    void (*slot0)(void);
    void (*slot1)(void);
    void (*slot2)(void);
    void (*retain)(S3Interface *);
    void (*release)(S3Interface *);
    void (*slot5)(void);
    void (*slot6)(void);
    void (*slot7)(void);
    void (*slot8)(void);
    void (*slot9)(void);
    void (*position)(S3Interface *, const void *);
    void (*text)(S3Interface *, const char *);
    void (*message)(S3Interface *, void *);
} S3InterfaceVtable;
struct S3Interface { S3InterfaceVtable *vtable; };
typedef struct S3WormPot {
    void *vtable;
    unsigned char pad04[0x14-4];
    int owner;
    int pad18;
    int first;
    int second;
    unsigned int target;
    float current;
    int last_time;
    S3Interface *pot;
} S3WormPot;
typedef struct S3PotState { unsigned char pad00[0x3c]; int state; } S3PotState;
extern void w3d_ctor_8015fef0(S3WormPot *);
extern void *w3d_vtable_80410ec0[];
extern const float w3d_f32_803a0404[];
extern const float w3d_f32_803a0410[];
extern int w3d_auto_8015fb34(S3WormPot *, void *);
extern S3Interface *w3d_fn_80164fc8(int);
extern void w3d_fn_800fc7f8(void *);
extern void w3d_fn_800fd3e4(int *, void *, ...);
extern void w3d_fn_8011adf8(S3Interface *, int *, int *);
extern int w3d_global_804af3b4;
extern int w3d_fn_8020b680(void *);
extern void *w3d_global_80410a10[];
extern int w3d_global_804b178c;
extern int w3d_fn_80164514(int, int, int);
extern const char w3d_str_803a0430[];
extern void w3d_constructor_lookup_name(const char **, S3Interface **);
extern S3Interface *w3d_empty_80341584(S3Interface *);
extern void w3d_fn_8011afac(S3Interface *, void *);
extern S3PotState *w3d_auto_801797b4(S3Interface *);
extern char w3d_str_804b194c;
extern const char w3d_str_803a0438[];
extern int w3d_fn_802ec254(char *, const char *, ...);
void w3d_worm_pot_initialize_80140e88(S3WormPot *);
void w3d_worm_pot_update_text(S3WormPot *);

S3WormPot *w3d_worm_pot_construct(S3WormPot *self)
{
    w3d_ctor_8015fef0(self);
    self->vtable = w3d_vtable_80410ec0;
    self->current = w3d_f32_803a0404[0];
    self->pot = 0;
    self->target = 0;
    self->last_time = 0;
    return self;
}
int w3d_worm_pot_dispatch(S3WormPot *self, unsigned short *message)
{
    if (*message == 64) {
        if (w3d_auto_8015fb34(self, message) >= 0) {
            w3d_worm_pot_initialize_80140e88(self);
            return 0;
        }
        return 0x80004005;
    }
    return w3d_auto_8015fb34(self, message);
}
int w3d_worm_pot_tick(S3WormPot *self, int time)
{
    float value = self->current;
    unsigned int target = self->target;
    if ((int)value != target) {
        float next = (float)(time - self->last_time) * w3d_f32_803a0410[0] + value;
        float limit = (float)target;
        if (next > limit) self->current = limit;
        else self->current = next;
        w3d_worm_pot_update_text(self);
    }
    self->last_time = time;
    return 0;
}
void w3d_worm_pot_set_second_text(S3WormPot *self, const char *text)
{
    S3Interface *object = w3d_fn_80164fc8(self->second);
    object->vtable->text(object, text);
}
void w3d_worm_pot_apply_message(S3WormPot *self, void *message)
{
    int first_value;
    int second_value;
    S3Interface *first = w3d_fn_80164fc8(self->first);
    S3Interface *second = w3d_fn_80164fc8(self->second);
    w3d_fn_800fc7f8(message);
    w3d_fn_800fd3e4(&first_value, message);
    w3d_fn_8011adf8(first, &first_value, &w3d_global_804af3b4);
    first->vtable->message(first, message);
    w3d_fn_800fd3e4(&second_value, message);
    w3d_fn_8011adf8(second, &second_value, &w3d_global_804af3b4);
    second->vtable->message(second, message);
}
#if 0 /* 0x80140e88: stack-local instruction scheduling differs after eight attempts. */
void w3d_worm_pot_initialize_80140e88(S3WormPot *self)
{
    struct { S3Interface *object; int unused; const char *key; } local;
    S3Interface *held;
    int id;
    void *data = w3d_global_80410a10;
    id = w3d_fn_8020b680(data);
    self->first = w3d_fn_80164514(w3d_global_804b178c, id, self->owner);
    id = w3d_fn_8020b680(data);
    self->second = w3d_fn_80164514(w3d_global_804b178c, id, self->owner);
    local.object = 0;
    local.key = w3d_str_803a0430;
    w3d_constructor_lookup_name(&local.key, &local.object);
    held = w3d_empty_80341584(local.object);
    if (held) held->vtable->retain(held);
    if (self->pot) self->pot->vtable->release(self->pot);
    self->pot = held;
    if (local.object) local.object->vtable->release(local.object);
}
#endif

void w3d_worm_pot_apply_pair(S3WormPot *self, void *first_message, void *second_message)
{
    S3Interface *first = w3d_fn_80164fc8(self->first);
    S3Interface *second = w3d_fn_80164fc8(self->second);
    w3d_fn_8011afac(second, second_message);
    w3d_fn_8011afac(first, first_message);
}
void w3d_worm_pot_update_text(S3WormPot *self)
{
    char text[16];
    int value = (int)self->current;
    S3Interface *first = w3d_fn_80164fc8(self->first);
    if (w3d_auto_801797b4(self->pot)->state == 1) {
        first->vtable->text(first, &w3d_str_804b194c);
    } else {
        w3d_fn_802ec254(text, w3d_str_803a0438, value);
        first->vtable->text(first, text);
    }
}
