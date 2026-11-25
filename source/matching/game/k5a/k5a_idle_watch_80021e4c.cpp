struct K5aSimpleMessage { unsigned short id; char pad0[2]; const void *kind; };
struct K5aIdleWatch { char pad0[4]; int moving; char pad1[12]; int worm_index; char pad2[4]; unsigned int last_tick; };
struct K5aEngineContext { char pad0[52]; unsigned int tick; };
extern "C" char w3d_string_8036c014[];
extern "C" char w3d_string_8036c178[];
extern "C" unsigned int w3d_message_804aca1c;
extern "C" unsigned int w3d_message_804aca14;
extern "C" const void *w3d_vtable_8040db38[];
extern "C" void *w3d_message_pool_804b1754;
extern "C" int w3d_auto_800fc1f0(const char **name, int *value);
extern "C" void *FUN_801613f0(void *pool, int size);
extern "C" unsigned int w3d_cached_message_id(void *cache, int create);
extern "C" void *w3d_message_string_init(void *storage, unsigned short id, const char *text);
extern "C" int w3d_message_post_current(void *message);
extern "C" K5aEngineContext *w3d_engine_get_context();

extern "C" void k5a_idle_watch_80021e4c(K5aIdleWatch *self, unsigned int now)
{
    if (now > self->last_tick + 800)
    {
        const char *name = w3d_string_8036c014;
        int active_worm;
        w3d_auto_800fc1f0(&name, &active_worm);
        if (active_worm == self->worm_index)
        {
            w3d_message_post_current(w3d_message_string_init(FUN_801613f0(w3d_message_pool_804b1754, 12), w3d_cached_message_id(&w3d_message_804aca1c, 1), w3d_string_8036c178));
            self->moving = 1;
        }
        else
        {
            K5aSimpleMessage *msg = (K5aSimpleMessage *)FUN_801613f0(w3d_message_pool_804b1754, 8);
            msg->id = w3d_cached_message_id(&w3d_message_804aca14, 1);
            msg->kind = w3d_vtable_8040db38;
            w3d_message_post_current(msg);
            self->last_tick = w3d_engine_get_context()->tick;
        }
    }
}
