#include "w3d_ptr.h"
#line 1 "d24a_chat_message_80038a70.cpp"
/* Chat message handler (0x80038a70): message 64 runs the base handler (0x8016293c;
 * a negative result returns 0x80004005) and the start-up 0x80038c74; message 66
 * runs 0x80038d18. Cached ids dispatch to 0x800396a8, 0x8003904c, open 0x80038e04
 * and close 0x80038f50; key 81 of id 0x804ad088 posts close or open by state +36;
 * id 0x804ad090 posts 0x804ad0a8 while open. The base handler ends every path.
 * Field and type names are inferred from the original instructions; the unit owns
 * no data. */
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Message {
    unsigned short id;
    unsigned short unknown02;
    Ptr32<void> vtable;
    unsigned short Id() const { return id; }
};
struct Chat { char unknown00[36]; int open; };
extern "C" int w3d_base_handler_8016293c(Ptr32<Chat>, Ptr32<Message>);
extern "C" void w3d_start_80038c74(Ptr32<Chat>);
extern "C" void w3d_stop_80038d18(Ptr32<Chat>);
extern "C" int w3d_message_id_equals_8015f65c(unsigned short, Ptr32<MessageCache>);
extern "C" void w3d_on_800396a8(Ptr32<Chat>, Ptr32<Message>);
extern "C" void w3d_on_8003904c(Ptr32<Chat>);
extern "C" void w3d_open_80038e04(Ptr32<Chat>);
extern "C" void w3d_close_80038f50(Ptr32<Chat>);
extern "C" int w3d_message_key_800a830c(Ptr32<Message>);
extern "C" int w3d_cached_message_id_8015f5a0(Ptr32<MessageCache>, int);
extern "C" Ptr32<Message> w3d_arena_alloc_801613f0(Ptr32<void>, int);
extern "C" int w3d_message_post_8016239c(Ptr32<Message>);
extern Ptr32<void> w3d_message_arena_804b1754;
extern unsigned char w3d_vtable_8040db38[];
extern MessageCache w3d_message_804ad068, w3d_message_804ad060, w3d_message_804ad070, w3d_message_804ad078,
    w3d_message_804ad080, w3d_message_804ad088, w3d_message_804ad090, w3d_message_804ad0a8;

inline void Post(Ptr32<MessageCache> cache)
{
    Ptr32<Message> m = w3d_arena_alloc_801613f0(w3d_message_arena_804b1754, 8);
    m->id = w3d_cached_message_id_8015f5a0(cache, 1);
    m->vtable = w3d_vtable_8040db38;
    w3d_message_post_8016239c(m);
}

extern "C" int w3d_d24a_chat_message_80038a70(Ptr32<Chat> self, Ptr32<Message> message)
{
    switch (message->Id()) {
    case 64:
        if (w3d_base_handler_8016293c(self, message) >= 0) {
            w3d_start_80038c74(self);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_stop_80038d18(self);
        break;
    default:
        if (w3d_message_id_equals_8015f65c(message->Id(), &w3d_message_804ad068)) {
            w3d_on_800396a8(self, message);
        } else if (w3d_message_id_equals_8015f65c(message->Id(), &w3d_message_804ad060)) {
            w3d_on_8003904c(self);
        } else if (w3d_message_id_equals_8015f65c(message->Id(), &w3d_message_804ad070)
                   || w3d_message_id_equals_8015f65c(message->Id(), &w3d_message_804ad078)) {
            w3d_open_80038e04(self);
        } else if (w3d_message_id_equals_8015f65c(message->Id(), &w3d_message_804ad080)) {
            w3d_close_80038f50(self);
        } else if (w3d_message_id_equals_8015f65c(message->Id(), &w3d_message_804ad088)) {
            if (w3d_message_key_800a830c(message) == 81) {
                if (self->open) Post(&w3d_message_804ad080);
                else Post(&w3d_message_804ad070);
            }
        } else if (w3d_message_id_equals_8015f65c(message->Id(), &w3d_message_804ad090)) {
            if (self->open) Post(&w3d_message_804ad0a8);
        }
        break;
    }
    return w3d_base_handler_8016293c(self, message);
}


