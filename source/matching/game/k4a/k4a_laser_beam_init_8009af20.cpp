struct K4aMessageId { unsigned short value; K4aMessageId() {} };
struct K4aString;
extern "C" void * w3d_string_from_text(K4aString *string, const char *text);
extern "C" void w3d_string_base_finish(K4aString *string);
extern "C" void w3d_string_release(K4aString *string);
struct K4aString {
    char *text;
    int unused;
    K4aString() {}
    ~K4aString() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct K4aLaser { char pad0[32]; unsigned int handle; unsigned int unused2; unsigned int subscription; };
extern "C" char w3d_str_80380000[];
extern "C" unsigned int w3d_message_804adfc4;
extern "C" void * w3d_handle_set_name(K4aString *name, void *handle, unsigned int flags);
extern "C" unsigned short w3d_cached_message_id(void *cache, int create);
extern "C" int w3d_subscribe_80162024(void *self, K4aMessageId *id, void *slot);

extern "C" void k4a_laser_beam_init_8009af20(K4aLaser *self)
{
    K4aMessageId id;
    {
        K4aString name;
        w3d_string_from_text(&name, w3d_str_80380000);
        w3d_handle_set_name(&name, &self->handle, 255);
    }
    id.value = w3d_cached_message_id(&w3d_message_804adfc4, 1);
    w3d_subscribe_80162024(self, &id, &self->subscription);
}
