#include "w3d_ptr.h"
#line 1 "k5a_chat_close_80038f50.cpp"
struct K5aChat { char pad0[36]; int visible; int needs_leave; };
struct K5aSimpleMessage { unsigned short id; char pad0[2]; Ptr32<const void> kind; };
extern "C" char w3d_string_80374060[];
extern "C" char w3d_string_80374034[];
extern "C" unsigned int w3d_message_804ad0c0;
extern "C" unsigned int w3d_message_804ad0b0;
extern "C" unsigned int w3d_message_804ad0a0;
extern "C" Ptr32<const void> w3d_vtable_8040db38[];
extern "C" Ptr32<void> w3d_message_pool_804b1754;
extern "C" Ptr32<void> w3d_context_804b1788;
extern "C" Ptr32<void> FUN_801613f0(Ptr32<void> pool, int size);
extern "C" unsigned int w3d_cached_message_id(Ptr32<void> cache, int create);
extern "C" Ptr32<void> w3d_message_string_init(Ptr32<void> storage, unsigned short id, Ptr32<const char> text);
extern "C" int w3d_message_post_current(Ptr32<void> message);
extern "C" int w3d_app_leave_801298cc(Ptr32<void> context);
extern "C" int s8_property_write_800fc43c(Ptr32<Ptr32<const char>> name, int value);
extern "C" int FUN_800a7e14(int slot, int value);

extern "C" void k5a_chat_close_80038f50(Ptr32<K5aChat> self)
{
    if (self->needs_leave != 0)
        w3d_app_leave_801298cc(w3d_context_804b1788);
    w3d_message_post_current(w3d_message_string_init(FUN_801613f0(w3d_message_pool_804b1754, 12), w3d_cached_message_id(&w3d_message_804ad0c0, 1), w3d_string_80374060));
    Ptr32<K5aSimpleMessage> first = (Ptr32<K5aSimpleMessage>)FUN_801613f0(w3d_message_pool_804b1754, 8);
    first->id = w3d_cached_message_id(&w3d_message_804ad0b0, 1);
    first->kind = w3d_vtable_8040db38;
    w3d_message_post_current(first);
    Ptr32<const char> name = w3d_string_80374034;
    s8_property_write_800fc43c(&name, 0);
    Ptr32<K5aSimpleMessage> second = (Ptr32<K5aSimpleMessage>)FUN_801613f0(w3d_message_pool_804b1754, 8);
    second->id = w3d_cached_message_id(&w3d_message_804ad0a0, 1);
    second->kind = w3d_vtable_8040db38;
    w3d_message_post_current(second);
    FUN_800a7e14(4, 0);
    self->visible = 0;
}


