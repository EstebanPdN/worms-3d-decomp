struct K5aSimpleMessage { unsigned short id; char pad0[2]; const void *kind; };
struct K5aHold { char pad0[28]; void *service; char pad1[16]; int active; };
extern "C" const float w3d_f32_8038c2e0[];
extern "C" unsigned int w3d_message_804af080;
extern "C" const void *w3d_vtable_8040db38[];
extern "C" void *w3d_message_pool_804b1754;
extern "C" int w3d_scene_timer_is_one_8006e71c(K5aHold *self);
extern "C" float FUN_800f12f0(K5aHold *self, int arg);
extern "C" void *FUN_801613f0(void *pool, int size);
extern "C" unsigned int w3d_cached_message_id(void *cache, int create);
extern "C" int w3d_message_post_current(void *message);
extern "C" void *w3d_empty_80342a74(void *service);
extern "C" int s9_permute_80178dfc(void *object, float *value);

extern "C" int k5a_hold_check_800f114c(K5aHold *self, int arg)
{
    int busy = w3d_scene_timer_is_one_8006e71c(self);
    if (busy == 0 && self->active != 0)
    {
        float level = FUN_800f12f0(self, arg);
        if (level >= w3d_f32_8038c2e0[0])
        {
            self->active = busy;
            K5aSimpleMessage *msg = (K5aSimpleMessage *)FUN_801613f0(w3d_message_pool_804b1754, 8);
            msg->id = w3d_cached_message_id(&w3d_message_804af080, 1);
            msg->kind = w3d_vtable_8040db38;
            w3d_message_post_current(msg);
        }
        s9_permute_80178dfc(w3d_empty_80342a74(self->service), &level);
    }
    return 20;
}
