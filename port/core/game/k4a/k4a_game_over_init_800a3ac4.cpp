#include "w3d_ptr.h"
#line 1 "k4a_game_over_init_800a3ac4.cpp"
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
struct K4aGameOver { char pad0[72]; unsigned int subs[4]; int callback_slot; };
extern "C" char w3d_str_80380d14[];
extern "C" unsigned int w3d_message_804ae18c;
extern "C" unsigned int w3d_message_804ae194;
extern "C" unsigned int w3d_message_804ae19c;
extern "C" unsigned int w3d_message_804ae1a4;
extern "C" void FUN_800a3d0c(Ptr32<K4aGameOver> self);
extern "C" int FUN_800a4038(Ptr32<void>, Ptr32<void>);
extern "C" unsigned short w3d_cached_message_id(Ptr32<void> cache, int create);
extern "C" int w3d_subscribe_80162024(Ptr32<void> self, Ptr32<K4aMessageId> id, Ptr32<void> slot);
extern "C" int FUN_800fd62c(Ptr32<K4aString> name, Ptr32<void (void)> callback, Ptr32<void> context, Ptr32<void> slot);
extern "C" void s8_visibility_800a3c24(Ptr32<K4aGameOver> self);

extern "C" void k4a_game_over_init_800a3ac4(Ptr32<K4aGameOver> self)
{
    K4aMessageId id0;
    K4aMessageId id1;
    K4aMessageId id2;
    K4aMessageId id3;
    FUN_800a3d0c(self);
    id0.value = w3d_cached_message_id(&w3d_message_804ae18c, 1);
    w3d_subscribe_80162024(self, &id0, &self->subs[0]);
    id1.value = w3d_cached_message_id(&w3d_message_804ae194, 1);
    w3d_subscribe_80162024(self, &id1, &self->subs[1]);
    id2.value = w3d_cached_message_id(&w3d_message_804ae19c, 1);
    w3d_subscribe_80162024(self, &id2, &self->subs[2]);
    id3.value = w3d_cached_message_id(&w3d_message_804ae1a4, 1);
    w3d_subscribe_80162024(self, &id3, &self->subs[3]);
    {
        K4aString name;
        w3d_string_from_text(&name, w3d_str_80380d14);
        FUN_800fd62c(&name, (Ptr32<void (void)>)FUN_800a4038, self, &self->callback_slot);
    }
    s8_visibility_800a3c24(self);
}


