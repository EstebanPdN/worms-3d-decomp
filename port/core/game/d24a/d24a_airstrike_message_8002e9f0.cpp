#include "w3d_ptr.h"
#line 1 "d24a_airstrike_message_8002e9f0.cpp"
/* Airstrike message handler (0x8002e9f0): message 64 runs the base handler
 * (0x8015fb34; a negative result returns 0x80004005) then the start-up 0x8002ead8;
 * message 66 runs 0x8002f354 and the base handler. The cached id 0x804acd34 passes
 * word +52 of the engine context to 0x8002f3d4; the cached id 0x804acd2c notifies
 * 250 (0x800fde64) and finishes (0x8015fd1c). Everything else goes to the base
 * handler. Field and type names are inferred from the original instructions; the
 * unit owns no data. */
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Message {
    unsigned short id;
    unsigned short Id() const { return id; }
};
struct Self;
struct EngineContext { char unknown00[52]; int unknown52; };
extern "C" int w3d_base_handler_8015fb34(Ptr32<Self>, Ptr32<Message>);
extern "C" void w3d_start_8002ead8(Ptr32<Self>);
extern "C" void w3d_stop_8002f354(Ptr32<Self>);
extern "C" int w3d_message_id_equals_8015f65c(unsigned short, Ptr32<MessageCache>);
extern "C" Ptr32<EngineContext> w3d_engine_context_80165254(void);
extern "C" void w3d_set_time_8002f3d4(Ptr32<Self>, int);
extern "C" int w3d_notify_800fde64(int);
extern "C" void w3d_finish_8015fd1c(Ptr32<Self>);
extern MessageCache w3d_message_804acd34, w3d_message_804acd2c;

extern "C" int w3d_d24a_airstrike_message_8002e9f0(Ptr32<Self> self, Ptr32<Message> message)
{
    unsigned short id = message->Id();
    switch (message->Id()) {
    case 64:
        if (w3d_base_handler_8015fb34(self, message) >= 0) {
            w3d_start_8002ead8(self);
            break;
        }
        return 0x80004005;
    case 66:
        w3d_stop_8002f354(self);
        return w3d_base_handler_8015fb34(self, message);
    default:
        if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acd34)) {
            w3d_set_time_8002f3d4(self, w3d_engine_context_80165254()->unknown52);
            break;
        }
        if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acd2c)) {
            w3d_notify_800fde64(250);
            w3d_finish_8015fd1c(self);
            break;
        }
        return w3d_base_handler_8015fb34(self, message);
    }
    return 0;
}


