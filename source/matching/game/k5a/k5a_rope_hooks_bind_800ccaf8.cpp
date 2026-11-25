struct K5aMessageId { unsigned short value; K5aMessageId() {} };
struct K5aString;
extern "C" void * w3d_string_from_text(K5aString *string, const char *text);
extern "C" void w3d_string_base_finish(K5aString *string);
extern "C" void w3d_string_release(K5aString *string);
struct K5aString {
    char *text;
    int unused;
    K5aString() {}
    ~K5aString() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct K5aRopeHooks { char pad0[20]; int owner; char pad1[12]; int hook; int gun; char pad2[12]; unsigned int sub_a; unsigned int sub_b; };
struct K5aSimpleMessage { unsigned short id; char pad0[2]; const void *kind; };
extern "C" char w3d_string_80387dd8[];
extern "C" char w3d_string_80387de8[];
extern "C" unsigned int w3d_message_804ae84c;
extern "C" unsigned int w3d_message_804ae854;
extern "C" unsigned int w3d_message_804ae85c;
extern "C" void *w3d_message_pool_804b1754;
extern "C" int w3d_handle_set_name(K5aString *name, int *handle, int flags);
extern "C" unsigned int w3d_cached_message_id(void *cache, int create);
extern "C" int w3d_subscribe_80162024(void *self, K5aMessageId *id, void *slot);
extern "C" void *FUN_801613f0(void *pool, int size);
extern "C" void *w3d_target_id_message_801190b4(void *storage, unsigned short id, unsigned int owner);
extern "C" int w3d_message_post_current(void *message);

extern "C" void k5a_rope_hooks_bind_800ccaf8(K5aRopeHooks *self)
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
    void *storage = FUN_801613f0(w3d_message_pool_804b1754, 12);
    w3d_message_post_current(w3d_target_id_message_801190b4(storage, w3d_cached_message_id(&w3d_message_804ae85c, 1), self->owner));
}
