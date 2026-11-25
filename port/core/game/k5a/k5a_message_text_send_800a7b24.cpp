#include "w3d_ptr.h"
#line 1 "k5a_message_text_send_800a7b24.cpp"
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
struct K5aDispatcher { char pad0[180]; int immediate; };
struct K5aEngineContext { char pad0[52]; int tick; };
extern "C" Ptr32<void> w3d_message_pool_804b1754;
extern "C" Ptr32<void> FUN_801613f0(Ptr32<void> pool, int size);
extern "C" Ptr32<void> w3d_message_string_init(Ptr32<void> storage, int id, Ptr32<const char> text);
extern "C" int w3d_message_post_current(Ptr32<void> message);
extern "C" Ptr32<K5aEngineContext> w3d_engine_get_context();
extern "C" int FUN_800f985c(int id, Ptr32<K5aString> text, int due);

extern "C" void k5a_message_text_send_800a7b24(Ptr32<K5aDispatcher> self, int id, Ptr32<const char> text)
{
    if (self->immediate != 0)
    {
        w3d_message_post_current(w3d_message_string_init(FUN_801613f0(w3d_message_pool_804b1754, 12), id, text));
    }
    else
    {
        K5aString string;
        w3d_string_from_text(&string, text);
        FUN_800f985c(id, &string, w3d_engine_get_context()->tick + 10);
    }
}


