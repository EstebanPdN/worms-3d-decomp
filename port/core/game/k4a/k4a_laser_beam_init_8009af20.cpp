#include "w3d_ptr.h"
#line 1 "k4a_laser_beam_init_8009af20.cpp"
struct K4aMessageId { unsigned short value; K4aMessageId() {} };
struct K4aString;
extern "C" Ptr32<void> w3d_string_from_text(Ptr32<K4aString> string, Ptr32<const char> text);
extern "C" void w3d_string_base_finish(Ptr32<K4aString> string);
extern "C" void w3d_string_release(Ptr32<K4aString> string);
struct K4aString {
    Ptr32<char> text;
    int unused;
    K4aString() {}
    ~K4aString() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct K4aLaser { char pad0[32]; unsigned int handle; unsigned int unused2; unsigned int subscription; };
extern "C" char w3d_str_80380000[];
extern "C" unsigned int w3d_message_804adfc4;
extern "C" Ptr32<void> w3d_handle_set_name(Ptr32<K4aString> name, Ptr32<void> handle, unsigned int flags);
extern "C" unsigned short w3d_cached_message_id(Ptr32<void> cache, int create);
extern "C" int w3d_subscribe_80162024(Ptr32<void> self, Ptr32<K4aMessageId> id, Ptr32<void> slot);

extern "C" void k4a_laser_beam_init_8009af20(Ptr32<K4aLaser> self)
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


