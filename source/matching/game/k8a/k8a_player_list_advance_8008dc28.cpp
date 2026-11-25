// Appears to advance the player list: when the active count and selection allow it, it
// clears a pending flag, posts a message naming the first player and removes that
// player from the list.
struct K8aPlayerVector
{
    int *begin;
    int *end;
};
struct K8aPlayerList
{
    char pad0[292];
    int pending;             // +292
    char pad296[48];
    K8aPlayerVector players; // +344
};
extern int w3d_state_804aa7d4;
extern char w3d_cache_804add1c[];
extern void *w3d_message_pool_804b1754;
extern "C" unsigned int w3d_auto_80023128(int state);
extern "C" int w3d_player_list_timer_active_8008dd18(K8aPlayerList *self);
extern "C" int w3d_player_list_selection_8008dd4c(K8aPlayerList *self);
extern "C" void *FUN_801613f0(void *pool, int size);
extern "C" unsigned int w3d_cached_message_id(void *cache, int create);
extern "C" void *w3d_target_id_message_801190b4(void *storage, unsigned short id, int target);
extern "C" int w3d_message_post_current(void *message);
extern "C" void w3d_memcpy_802eee50(void *dest, const void *source, unsigned int size, ...);
extern "C" void w3d_k8a_player_list_advance_8008dc28(K8aPlayerList *self)
{
    int count = self->players.end - self->players.begin;
    if (count)
    {
        unsigned int active = w3d_auto_80023128(w3d_state_804aa7d4);
        if ((int)active != count && !w3d_player_list_timer_active_8008dd18(self))
        {
            if (!w3d_player_list_selection_8008dd4c(self))
                return;
            if (active > (unsigned int)(count + 2))
                return;
        }
        self->pending = 0;
        int *first = self->players.begin;
        K8aPlayerVector *v = &self->players;
        int player = *first;
        void *storage = FUN_801613f0(w3d_message_pool_804b1754, 12);
        w3d_message_post_current(w3d_target_id_message_801190b4(storage, w3d_cached_message_id(w3d_cache_804add1c, 1), player));
        int *next = first + 1;
        if (next != v->end)
            w3d_memcpy_802eee50(first, next, (char *)(v->end - 1) - (char *)first);
        v->end = v->end - 1;
    }
}
