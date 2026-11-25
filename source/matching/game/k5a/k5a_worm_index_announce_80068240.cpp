struct K5aAnnouncer { char pad0[36]; int announced; };
struct K5aSimpleMessage { unsigned short id; char pad0[2]; const void *kind; };
extern "C" char w3d_string_8037a214[];
extern "C" unsigned int w3d_message_804ad608;
extern "C" unsigned int w3d_message_804ad610;
extern "C" unsigned int w3d_message_804ad5f8;
extern "C" const void *w3d_vtable_8040db38[];
extern "C" void *w3d_message_pool_804b1754;
extern "C" void *FUN_801613f0(void *pool, int size);
extern "C" unsigned int w3d_cached_message_id(void *cache, int create);
extern "C" void *w3d_int_message_init_80125fdc(void *storage, unsigned short id, int value);
extern "C" void *w3d_message_int_init(void *storage, unsigned short id, int value);
extern "C" int w3d_message_post_current(void *message);
extern "C" int w3d_auto_800fc1f0(const char **name, int *value);
extern "C" int w3d_auto_8015fd1c(K5aAnnouncer *self);

extern "C" void k5a_worm_index_announce_80068240(K5aAnnouncer *self)
{
    if (self->announced == 0)
    {
        self->announced = 1;
        w3d_message_post_current(w3d_int_message_init_80125fdc(FUN_801613f0(w3d_message_pool_804b1754, 12), w3d_cached_message_id(&w3d_message_804ad608, 1), 45));
        const char *name = w3d_string_8037a214;
        int worm_index;
        w3d_auto_800fc1f0(&name, &worm_index);
        w3d_message_post_current(w3d_message_int_init(FUN_801613f0(w3d_message_pool_804b1754, 12), w3d_cached_message_id(&w3d_message_804ad610, 1), worm_index));
        K5aSimpleMessage *msg = (K5aSimpleMessage *)FUN_801613f0(w3d_message_pool_804b1754, 8);
        msg->id = w3d_cached_message_id(&w3d_message_804ad5f8, 1);
        msg->kind = w3d_vtable_8040db38;
        w3d_message_post_current(msg);
        w3d_auto_8015fd1c(self);
    }
}
