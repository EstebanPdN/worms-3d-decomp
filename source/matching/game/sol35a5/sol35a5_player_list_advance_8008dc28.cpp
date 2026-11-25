// Appears to advance a queue of pending player entries: when the global list size
// changed, a timer is running, or a selection exists within two entries of the
// queue size, it clears the selection, posts a target message for the first
// queued entry and removes that entry from the queue.
struct Sol35a5Queue
{
    void **begin;
    void **end;
};

struct Sol35a5PlayerList
{
    char pad0[292];
    int selection;               // +292
    char pad296[48];
    Sol35a5Queue pending;           // +344
};

extern "C" void *sol35a5_copy_802eee50(void *dst, const void *src, unsigned int size,...);
extern "C" int w3d_auto_80023128(void *list);
extern "C" int w3d_player_list_timer_active_8008dd18(Sol35a5PlayerList *self);
extern "C" int w3d_player_list_selection_8008dd4c(Sol35a5PlayerList *self);
extern "C" void *fn_801613f0(void *pool, int size);
extern "C" unsigned int w3d_cached_message_id(void *cache, int create);
extern "C" void *w3d_target_id_message_801190b4(void *message, unsigned int id, void *target);
extern "C" int w3d_message_post_current(void *message);
extern void *w3d_list_804aa7d4;
extern void *w3d_message_pool_804b1754;
struct Sol35a5CachedMessage { unsigned state; const char *name; };
extern Sol35a5CachedMessage w3d_message_cache_804add1c;

extern "C" void sol35a5_player_list_advance_8008dc28(Sol35a5PlayerList *self)
{
    unsigned int count = self->pending.end - self->pending.begin;
    if (count == 0)
        return;
    unsigned int listed = w3d_auto_80023128(w3d_list_804aa7d4);
    if (listed != count && !w3d_player_list_timer_active_8008dd18(self))
    {
        if (!w3d_player_list_selection_8008dd4c(self))
            return;
        if (listed > count + 2)
            return;
    }
    self->selection = 0;
    Sol35a5Queue *queue = &self->pending;
    void **first = queue->begin;
    void *target = *first;
    void *message = fn_801613f0(w3d_message_pool_804b1754, 12);
    unsigned short id = w3d_cached_message_id(&w3d_message_cache_804add1c, 1);
    w3d_message_post_current(w3d_target_id_message_801190b4(message, id, target));
    if (first + 1 != queue->end)
        sol35a5_copy_802eee50(first, first + 1, (unsigned)queue->end + (-4 - (unsigned)first));
    queue->end = queue->end - 1;
}

// Inferred GC32 ABI. Unknown spans describe external receiver offsets only.
// The erase byte count retains the native unsigned address arithmetic;
// pointer-to-integer conversion is reference-implementation specific.
// Native 802eee50 copies forwards and supports this downward overlap;
// this is deliberately an address-named external, not standard memcpy.
typedef char Sol35a5PointerWidth[sizeof(void *) == 4 ? 1 : -1];
typedef char Sol35a5SelectionOffset[(unsigned)&((Sol35a5PlayerList *)0)->selection == 292 ? 1 : -1];
typedef char Sol35a5PendingOffset[(unsigned)&((Sol35a5PlayerList *)0)->pending == 344 ? 1 : -1];
typedef char Sol35a5CacheSize[sizeof(Sol35a5CachedMessage) == 8 ? 1 : -1];
