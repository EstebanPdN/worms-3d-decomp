#include "w3d_ptr.h"
#line 1 "k4a_sink_subscribe_80024ea0.cpp"
struct K4aMessageSink { char pad0[28]; Ptr32<void> interface_ref; unsigned int subscription; };
struct K4aMessageId { unsigned short value; K4aMessageId() {} };
extern "C" char w3d_str_8036c7e8[];
extern "C" unsigned int w3d_message_804aca8c;
extern "C" int w3d_constructor_lookup_name(Ptr32<Ptr32<const char>> name, Ptr32<Ptr32<void>> output);
extern "C" unsigned short w3d_cached_message_id(Ptr32<void> cache, int create);
extern "C" int w3d_subscribe_80162024(Ptr32<void> self, Ptr32<K4aMessageId> id, Ptr32<void> slot);

extern "C" void k4a_sink_subscribe_80024ea0(Ptr32<K4aMessageSink> self)
{
    K4aMessageId id;
    Ptr32<const char> name = w3d_str_8036c7e8;
    w3d_constructor_lookup_name(&name, &self->interface_ref);
    id.value = w3d_cached_message_id(&w3d_message_804aca8c, 1);
    w3d_subscribe_80162024(self, &id, &self->subscription);
}


