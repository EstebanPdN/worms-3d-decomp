struct K4aListener { char pad0[28]; void *source; unsigned int subscription; };
struct K4aMessageId { unsigned short value; K4aMessageId() {} };
extern "C" char w3d_str_8036c914[];
extern "C" unsigned int w3d_message_804acad4;
extern "C" int w3d_constructor_lookup_name(const char **name, void **output);
extern "C" unsigned int w3d_auto_80025b04(K4aListener *self);
extern "C" unsigned int w3d_auto_800fcea0();
extern "C" int w3d_set_handle_owner_80025aa0(K4aListener *self, unsigned int owner);
extern "C" unsigned short w3d_cached_message_id(void *cache, int create);
extern "C" int w3d_subscribe_80162024(void *self, K4aMessageId *id, void *slot);

extern "C" void k4a_listener_setup_80025a1c(K4aListener *self)
{
    K4aMessageId id;
    const char *name = w3d_str_8036c914;
    w3d_constructor_lookup_name(&name, &self->source);
    unsigned int wanted = w3d_auto_80025b04(self);
    unsigned int limit = w3d_auto_800fcea0();
    if (wanted > limit)
        w3d_set_handle_owner_80025aa0(self, limit);
    id.value = w3d_cached_message_id(&w3d_message_804acad4, 1);
    w3d_subscribe_80162024(self, &id, &self->subscription);
}
