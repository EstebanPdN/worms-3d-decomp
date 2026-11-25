#include "w3d_ptr.h"
#line 1 "sol35a5_player_list_advance_8008dc28.cpp"
// Appears to advance a queue of pending player entries: when the global list size
// changed, a timer is running, or a selection exists within two entries of the
// queue size, it clears the selection, posts a target message for the first
// queued entry and removes that entry from the queue.
struct Sol35a5Queue
{
    Ptr32<Ptr32<void>> begin;
    Ptr32<Ptr32<void>> end;
};

struct Sol35a5PlayerList
{
    char pad0[292];
    int selection;               // +292
    char pad296[48];
    Sol35a5Queue pending;           // +344
};

extern "C" Ptr32<void> sol35a5_copy_802eee50(Ptr32<void> dst, Ptr32<const void> src, unsigned int size,...);
extern "C" int w3d_auto_80023128(Ptr32<void> list);
extern "C" int w3d_player_list_timer_active_8008dd18(Ptr32<Sol35a5PlayerList> self);
extern "C" int w3d_player_list_selection_8008dd4c(Ptr32<Sol35a5PlayerList> self);
extern "C" Ptr32<void> fn_801613f0(Ptr32<void> pool, int size);
extern "C" unsigned int w3d_cached_message_id(Ptr32<void> cache, int create);
extern "C" Ptr32<void> w3d_target_id_message_801190b4(Ptr32<void> message, unsigned int id, Ptr32<void> target);
extern "C" int w3d_message_post_current(Ptr32<void> message);
extern Ptr32<void> w3d_list_804aa7d4;
extern Ptr32<void> w3d_message_pool_804b1754;
struct Sol35a5CachedMessage { unsigned state; Ptr32<const char> name; };
extern Sol35a5CachedMessage w3d_message_cache_804add1c;

extern "C" void sol35a5_player_list_advance_8008dc28(Ptr32<Sol35a5PlayerList> self)
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
    Ptr32<Sol35a5Queue> queue = &self->pending;
    Ptr32<Ptr32<void>> first = queue->begin;
    Ptr32<void> target = *first;
    Ptr32<void> message = fn_801613f0(w3d_message_pool_804b1754, 12);
    unsigned short id = w3d_cached_message_id(&w3d_message_cache_804add1c, 1);
    w3d_message_post_current(w3d_target_id_message_801190b4(message, id, target));
    if (first + 1 != queue->end)
        sol35a5_copy_802eee50(first, first + 1, (unsigned)w3d::H(queue->end) + (-4 - (unsigned)w3d::H(first)));
    queue->end = queue->end - 1;
}

// Inferred GC32 ABI. Unknown spans describe external receiver offsets only.
// The erase byte count retains the native unsigned address arithmetic;
// pointer-to-integer conversion is reference-implementation specific.
// Native 802eee50 copies forwards and supports this downward overlap;
// this is deliberately an address-named external, not standard memcpy.
typedef char Sol35a5PointerWidth[sizeof(Ptr32<void>) == 4 ? 1 : -1];
typedef char Sol35a5SelectionOffset[__builtin_offsetof(Sol35a5PlayerList,selection) == 292 ? 1 : -1];
typedef char Sol35a5PendingOffset[__builtin_offsetof(Sol35a5PlayerList,pending) == 344 ? 1 : -1];
typedef char Sol35a5CacheSize[sizeof(Sol35a5CachedMessage) == 8 ? 1 : -1];


