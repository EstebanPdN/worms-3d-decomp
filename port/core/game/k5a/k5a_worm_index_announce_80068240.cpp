#include "w3d_ptr.h"
#line 1 "k5a_worm_index_announce_80068240.cpp"
struct K5aAnnouncer { char pad0[36]; int announced; };
struct K5aSimpleMessage { unsigned short id; char pad0[2]; Ptr32<const void> kind; };
extern "C" char w3d_string_8037a214[];
extern "C" unsigned int w3d_message_804ad608;
extern "C" unsigned int w3d_message_804ad610;
extern "C" unsigned int w3d_message_804ad5f8;
extern "C" Ptr32<const void> w3d_vtable_8040db38[];
extern "C" Ptr32<void> w3d_message_pool_804b1754;
extern "C" Ptr32<void> FUN_801613f0(Ptr32<void> pool, int size);
extern "C" unsigned int w3d_cached_message_id(Ptr32<void> cache, int create);
extern "C" Ptr32<void> w3d_int_message_init_80125fdc(Ptr32<void> storage, unsigned short id, int value);
extern "C" Ptr32<void> w3d_message_int_init(Ptr32<void> storage, unsigned short id, int value);
extern "C" int w3d_message_post_current(Ptr32<void> message);
extern "C" int w3d_auto_800fc1f0(Ptr32<Ptr32<const char>> name, Ptr32<int> value);
extern "C" int w3d_auto_8015fd1c(Ptr32<K5aAnnouncer> self);

extern "C" void k5a_worm_index_announce_80068240(Ptr32<K5aAnnouncer> self)
{
    if (self->announced == 0)
    {
        self->announced = 1;
        w3d_message_post_current(w3d_int_message_init_80125fdc(FUN_801613f0(w3d_message_pool_804b1754, 12), w3d_cached_message_id(&w3d_message_804ad608, 1), 45));
        Ptr32<const char> name = w3d_string_8037a214;
        int worm_index;
        w3d_auto_800fc1f0(&name, &worm_index);
        w3d_message_post_current(w3d_message_int_init(FUN_801613f0(w3d_message_pool_804b1754, 12), w3d_cached_message_id(&w3d_message_804ad610, 1), worm_index));
        Ptr32<K5aSimpleMessage> msg = (Ptr32<K5aSimpleMessage>)FUN_801613f0(w3d_message_pool_804b1754, 8);
        msg->id = w3d_cached_message_id(&w3d_message_804ad5f8, 1);
        msg->kind = w3d_vtable_8040db38;
        w3d_message_post_current(msg);
        w3d_auto_8015fd1c(self);
    }
}


