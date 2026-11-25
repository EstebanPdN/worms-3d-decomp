#include "w3d_ptr.h"
#line 1 "k5a_rope_hooks_bind_800ccaf8.cpp"
struct K5aMessageId { unsigned short value; K5aMessageId() {} };
struct K5aString;
extern "C" Ptr32<void> w3d_string_from_text(Ptr32<K5aString> string, Ptr32<const char> text);
extern "C" void w3d_string_base_finish(Ptr32<K5aString> string);
extern "C" void w3d_string_release(Ptr32<K5aString> string);
struct K5aString {
    Ptr32<char> text;
    int unused;
    K5aString() {}
    ~K5aString() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct K5aRopeHooks { char pad0[20]; int owner; char pad1[12]; int hook; int gun; char pad2[12]; unsigned int sub_a; unsigned int sub_b; };
struct K5aSimpleMessage { unsigned short id; char pad0[2]; Ptr32<const void> kind; };
extern "C" char w3d_string_80387dd8[];
extern "C" char w3d_string_80387de8[];
extern "C" unsigned int w3d_message_804ae84c;
extern "C" unsigned int w3d_message_804ae854;
extern "C" unsigned int w3d_message_804ae85c;
extern "C" Ptr32<void> w3d_message_pool_804b1754;
extern "C" int w3d_handle_set_name(Ptr32<K5aString> name, Ptr32<int> handle, int flags);
extern "C" unsigned int w3d_cached_message_id(Ptr32<void> cache, int create);
extern "C" int w3d_subscribe_80162024(Ptr32<void> self, Ptr32<K5aMessageId> id, Ptr32<void> slot);
extern "C" Ptr32<void> FUN_801613f0(Ptr32<void> pool, int size);
extern "C" Ptr32<void> w3d_target_id_message_801190b4(Ptr32<void> storage, unsigned short id, unsigned int owner);
extern "C" int w3d_message_post_current(Ptr32<void> message);

extern "C" void k5a_rope_hooks_bind_800ccaf8(Ptr32<K5aRopeHooks> self)
{
    {
        K5aString name;
        w3d_string_from_text(&name, w3d_string_80387dd8);
        w3d_handle_set_name(&name, &self->hook, 255);
    }
    {
        K5aString name;
        w3d_string_from_text(&name, w3d_string_80387de8);
        w3d_handle_set_name(&name, &self->gun, 255);
    }
    K5aMessageId id_a;
    K5aMessageId id_b;
    id_a.value = w3d_cached_message_id(&w3d_message_804ae84c, 1);
    w3d_subscribe_80162024(self, &id_a, &self->sub_a);
    id_b.value = w3d_cached_message_id(&w3d_message_804ae854, 1);
    w3d_subscribe_80162024(self, &id_b, &self->sub_b);
    Ptr32<void> storage = FUN_801613f0(w3d_message_pool_804b1754, 12);
    w3d_message_post_current(w3d_target_id_message_801190b4(storage, w3d_cached_message_id(&w3d_message_804ae85c, 1), self->owner));
}


