#include "w3d_ptr.h"
#line 1 "k4a_listener_subscribe_8002547c.cpp"
struct K4aListener { char pad0[28]; Ptr32<void> source; unsigned int subs[6]; };
struct K4aMessageId { unsigned short value; K4aMessageId() {} };
extern "C" char w3d_str_8036c84c[];
extern "C" unsigned int w3d_message_804aca9c;
extern "C" unsigned int w3d_message_804acaac;
extern "C" unsigned int w3d_message_804acab4;
extern "C" unsigned int w3d_message_804acabc;
extern "C" unsigned int w3d_message_804acac4;
extern "C" unsigned int w3d_message_804acacc;
extern "C" int w3d_constructor_lookup_name(Ptr32<Ptr32<const char>> name, Ptr32<Ptr32<void>> output);
extern "C" unsigned short w3d_cached_message_id(Ptr32<void> cache, int create);
extern "C" int w3d_subscribe_80162024(Ptr32<void> self, Ptr32<K4aMessageId> id, Ptr32<void> slot);

extern "C" void k4a_listener_subscribe_8002547c(Ptr32<K4aListener> self)
{
    K4aMessageId id0;
    K4aMessageId id1;
    K4aMessageId id2;
    K4aMessageId id3;
    K4aMessageId id4;
    K4aMessageId id5;
    Ptr32<const char> name = w3d_str_8036c84c;
    w3d_constructor_lookup_name(&name, &self->source);
    id0.value = w3d_cached_message_id(&w3d_message_804aca9c, 1);
    w3d_subscribe_80162024(self, &id0, &self->subs[0]);
    id1.value = w3d_cached_message_id(&w3d_message_804acaac, 1);
    w3d_subscribe_80162024(self, &id1, &self->subs[1]);
    id2.value = w3d_cached_message_id(&w3d_message_804acab4, 1);
    w3d_subscribe_80162024(self, &id2, &self->subs[2]);
    id3.value = w3d_cached_message_id(&w3d_message_804acabc, 1);
    w3d_subscribe_80162024(self, &id3, &self->subs[3]);
    id4.value = w3d_cached_message_id(&w3d_message_804acac4, 1);
    w3d_subscribe_80162024(self, &id4, &self->subs[4]);
    id5.value = w3d_cached_message_id(&w3d_message_804acacc, 1);
    w3d_subscribe_80162024(self, &id5, &self->subs[5]);
}


