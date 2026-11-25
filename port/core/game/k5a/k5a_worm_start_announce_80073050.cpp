#include "w3d_ptr.h"
#line 1 "k5a_worm_start_announce_80073050.cpp"
struct K5aSimpleMessage { unsigned short id; char pad0[2]; Ptr32<const void> kind; };
struct K5aStarter { char pad0[28]; int started; };
struct K5aWormRecord { char pad0[213]; unsigned char team; };
extern "C" char w3d_string_8037cdc8[];
extern "C" unsigned int w3d_message_804ad984;
extern "C" unsigned int w3d_message_804ad98c;
extern "C" unsigned int w3d_message_804ad974;
extern "C" unsigned int w3d_message_804ad97c;
extern "C" unsigned int w3d_message_804ad964;
extern "C" Ptr32<const void> w3d_vtable_8040db38[];
extern "C" Ptr32<void> w3d_message_pool_804b1754;
extern "C" int w3d_auto_800fc1f0(Ptr32<Ptr32<const char>> name, Ptr32<int> value);
extern "C" Ptr32<K5aWormRecord> s8_index_query_800fc6dc(int index);
extern "C" Ptr32<void> FUN_801613f0(Ptr32<void> pool, int size);
extern "C" unsigned int w3d_cached_message_id(Ptr32<void> cache, int create);
extern "C" Ptr32<void> w3d_int_message_init_80125fdc(Ptr32<void> storage, unsigned short id, int value);
extern "C" Ptr32<void> w3d_message_int_init(Ptr32<void> storage, unsigned short id, int value);
extern "C" int w3d_message_post_current(Ptr32<void> message);
extern "C" int w3d_auto_8015fd1c(Ptr32<K5aStarter> self);

extern "C" void k5a_worm_start_announce_80073050(Ptr32<K5aStarter> self)
{
    if (self->started == 0)
    {
        Ptr32<const char> name;
        int worm;
        self->started = 1;
        name = w3d_string_8037cdc8;
        w3d_auto_800fc1f0(&name, &worm);
        unsigned char team = s8_index_query_800fc6dc(worm)->team;
        Ptr32<K5aSimpleMessage> first = (Ptr32<K5aSimpleMessage>)FUN_801613f0(w3d_message_pool_804b1754, 8);
        first->id = w3d_cached_message_id(&w3d_message_804ad984, 1);
        first->kind = w3d_vtable_8040db38;
        w3d_message_post_current(first);
        Ptr32<K5aSimpleMessage> second = (Ptr32<K5aSimpleMessage>)FUN_801613f0(w3d_message_pool_804b1754, 8);
        second->id = w3d_cached_message_id(&w3d_message_804ad98c, 1);
        second->kind = w3d_vtable_8040db38;
        w3d_message_post_current(second);
        w3d_message_post_current(w3d_int_message_init_80125fdc(FUN_801613f0(w3d_message_pool_804b1754, 12), w3d_cached_message_id(&w3d_message_804ad974, 1), 52));
        w3d_message_post_current(w3d_message_int_init(FUN_801613f0(w3d_message_pool_804b1754, 12), w3d_cached_message_id(&w3d_message_804ad97c, 1), team));
        Ptr32<K5aSimpleMessage> last = (Ptr32<K5aSimpleMessage>)FUN_801613f0(w3d_message_pool_804b1754, 8);
        last->id = w3d_cached_message_id(&w3d_message_804ad964, 1);
        last->kind = w3d_vtable_8040db38;
        w3d_message_post_current(last);
        w3d_auto_8015fd1c(self);
    }
}


