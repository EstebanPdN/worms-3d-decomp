struct K4aMessageId { unsigned short value; K4aMessageId() {} };
struct K4aShotPower { char pad0[20]; unsigned int owner; char pad1[4]; void *power_ref; void *time_ref; unsigned int sub_a; unsigned int sub_b; int a; int b; };
extern "C" char w3d_str_8038c2e4[];
extern "C" char w3d_str_8038c2f0[];
extern "C" const float w3d_f32_8038c308[];
extern "C" unsigned int w3d_message_804af060;
extern "C" unsigned int w3d_message_804af088;
extern "C" unsigned int w3d_message_804af070;
extern "C" void *w3d_message_pool_804b1754;
extern "C" int w3d_constructor_lookup_name(const char **name, void **output);
extern "C" unsigned int w3d_cached_message_id(void *cache, int create);
extern "C" int w3d_subscribe_80162024(void *self, K4aMessageId *id, void *slot);
extern "C" void *w3d_empty_80342a74(void *);
extern "C" int s9_permute_80178dfc(void *object, float *value);
extern "C" void *FUN_801613f0(void *pool, int size);
extern "C" void *w3d_target_id_message_801190b4(void *storage, unsigned short id, unsigned int owner);
extern "C" int w3d_message_post_current(void *message);

extern "C" void k4a_shot_power_init_800f1200(K4aShotPower *self)
{
    const char *power_name = w3d_str_8038c2e4;
    w3d_constructor_lookup_name(&power_name, &self->power_ref);
    const char *time_name = w3d_str_8038c2f0;
    w3d_constructor_lookup_name(&time_name, &self->time_ref);
    K4aMessageId id_a;
    id_a.value = w3d_cached_message_id(&w3d_message_804af060, 1);
    w3d_subscribe_80162024(self, &id_a, &self->sub_a);
    K4aMessageId id_b;
    id_b.value = w3d_cached_message_id(&w3d_message_804af088, 1);
    w3d_subscribe_80162024(self, &id_b, &self->sub_b);
    self->b = 0;
    self->a = 0;
    void *power = w3d_empty_80342a74(self->power_ref);
    float level = w3d_f32_8038c308[0];
    s9_permute_80178dfc(power, &level);
    void *storage = FUN_801613f0(w3d_message_pool_804b1754, 12);
    w3d_message_post_current(w3d_target_id_message_801190b4(storage, w3d_cached_message_id(&w3d_message_804af070, 1), self->owner));
}
