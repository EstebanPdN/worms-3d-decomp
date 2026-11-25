#include "w3d_ptr.h"
#line 1 "s5_rope_mode_messages.cpp"
/* Rope camera/input mode transitions expressed as string messages. */
extern "C" {
struct S5RopeMessageName { unsigned value; Ptr32<const char> text; };
extern S5RopeMessageName w3d_rope_message_804ae950,w3d_rope_message_804ae948;
extern const char w3d_str_80388170[],w3d_str_8038817c[],w3d_str_80388188[],w3d_str_80388194[];
extern Ptr32<void> w3d_message_pool_804b1754;
Ptr32<void> w3d_message_allocate_801613f0(Ptr32<void>,unsigned);
unsigned w3d_cached_message_id(Ptr32<S5RopeMessageName>,int);
Ptr32<void> w3d_message_string_init(Ptr32<void>,unsigned short,Ptr32<const char>);
int w3d_message_post_current(Ptr32<void>);
static inline void s5_rope_post(Ptr32<S5RopeMessageName> name,Ptr32<const char> text)
{
    Ptr32<void> message=w3d_message_allocate_801613f0(w3d_message_pool_804b1754,12);
    w3d_message_post_current(w3d_message_string_init(message,w3d_cached_message_id(name,1),text));
}
void w3d_rope_enter_mode_800d0d6c(Ptr32<void> unused)
{
    Ptr32<void> message1=w3d_message_allocate_801613f0(w3d_message_pool_804b1754,12);
    w3d_message_post_current(w3d_message_string_init(message1,w3d_cached_message_id(&w3d_rope_message_804ae950,1),w3d_str_80388170));
    Ptr32<void> message2=w3d_message_allocate_801613f0(w3d_message_pool_804b1754,12);
    w3d_message_post_current(w3d_message_string_init(message2,w3d_cached_message_id(&w3d_rope_message_804ae948,1),w3d_str_8038817c));
    Ptr32<void> message3=w3d_message_allocate_801613f0(w3d_message_pool_804b1754,12);
    w3d_message_post_current(w3d_message_string_init(message3,w3d_cached_message_id(&w3d_rope_message_804ae948,1),w3d_str_80388188));
    Ptr32<void> message4=w3d_message_allocate_801613f0(w3d_message_pool_804b1754,12);
    w3d_message_post_current(w3d_message_string_init(message4,w3d_cached_message_id(&w3d_rope_message_804ae948,1),w3d_str_80388194));
}
void w3d_rope_exit_mode_800d0e60(Ptr32<void> unused)
{
    Ptr32<void> message5=w3d_message_allocate_801613f0(w3d_message_pool_804b1754,12);
    w3d_message_post_current(w3d_message_string_init(message5,w3d_cached_message_id(&w3d_rope_message_804ae950,1),w3d_str_8038817c));
    Ptr32<void> message6=w3d_message_allocate_801613f0(w3d_message_pool_804b1754,12);
    w3d_message_post_current(w3d_message_string_init(message6,w3d_cached_message_id(&w3d_rope_message_804ae950,1),w3d_str_80388188));
    Ptr32<void> message7=w3d_message_allocate_801613f0(w3d_message_pool_804b1754,12);
    w3d_message_post_current(w3d_message_string_init(message7,w3d_cached_message_id(&w3d_rope_message_804ae950,1),w3d_str_80388194));
    Ptr32<void> message8=w3d_message_allocate_801613f0(w3d_message_pool_804b1754,12);
    w3d_message_post_current(w3d_message_string_init(message8,w3d_cached_message_id(&w3d_rope_message_804ae948,1),w3d_str_80388170));
}
}


