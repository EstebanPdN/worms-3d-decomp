#include "w3d_ptr.h"
#line 1 "d24a_worm_select_message_8003bc58.cpp"
/* Worm selection message handler (0x8003bc58): message 64 runs the base handler
 * (0x8015fb34; a negative result returns 0x80004005) and the start-up 0x8003c0f0;
 * message 66 runs 0x8003c364 and the base handler. Cached id 0x804ad170 stores the
 * engine time minus 3500 in +84 and applies (0x8003d0a0); 0x804ad178 reselects
 * (0x8003bf70, 0x8003ce0c); six ids refresh (0x8003cdcc); 0x804ad168 applies;
 * 0x804ad180 finishes (0x8015fd1c); others go to the base handler. Field and type
 * names are inferred from the original instructions; the unit owns no data. */
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Message {
    unsigned short id;
    unsigned short Id() const { return id; }
};
struct EngineContext { char unknown00[52]; int time; };
struct WormSelect { char unknown00[84]; int unknown84; };
extern "C" int w3d_base_handler_8015fb34(Ptr32<WormSelect>, Ptr32<Message>);
extern "C" void w3d_start_8003c0f0(Ptr32<WormSelect>);
extern "C" void w3d_stop_8003c364(Ptr32<WormSelect>);
extern "C" int w3d_message_id_equals_8015f65c(unsigned short, Ptr32<MessageCache>);
extern "C" Ptr32<EngineContext> w3d_engine_context_80165254(void);
extern "C" void w3d_apply_8003d0a0(Ptr32<WormSelect>);
extern "C" void w3d_select_8003bf70(Ptr32<WormSelect>, int);
extern "C" void w3d_refresh_8003ce0c(Ptr32<WormSelect>);
extern "C" void w3d_update_8003cdcc(Ptr32<WormSelect>);
extern "C" void w3d_finish_8015fd1c(Ptr32<WormSelect>);
extern MessageCache w3d_message_804ad170, w3d_message_804ad178, w3d_message_804ad138, w3d_message_804ad140,
    w3d_message_804ad148, w3d_message_804ad150, w3d_message_804ad158, w3d_message_804ad160,
    w3d_message_804ad168, w3d_message_804ad180;

extern "C" int w3d_d24a_worm_select_message_8003bc58(Ptr32<WormSelect> self, Ptr32<Message> message)
{
    unsigned short id = message->Id();
    switch (message->Id()) {
    case 64:
        if (w3d_base_handler_8015fb34(self, message) >= 0) {
            w3d_start_8003c0f0(self);
            break;
        }
        return 0x80004005;
    case 66:
        w3d_stop_8003c364(self);
        return w3d_base_handler_8015fb34(self, message);
    default:
        if (w3d_message_id_equals_8015f65c(id, &w3d_message_804ad170)) {
            self->unknown84 = w3d_engine_context_80165254()->time - 3500;
            w3d_apply_8003d0a0(self);
        }
        if (w3d_message_id_equals_8015f65c(id, &w3d_message_804ad178)) {
            w3d_select_8003bf70(self, 1);
            w3d_refresh_8003ce0c(self);
        }
        if (w3d_message_id_equals_8015f65c(id, &w3d_message_804ad138)
            || w3d_message_id_equals_8015f65c(id, &w3d_message_804ad140)
            || w3d_message_id_equals_8015f65c(id, &w3d_message_804ad148)
            || w3d_message_id_equals_8015f65c(id, &w3d_message_804ad150)
            || w3d_message_id_equals_8015f65c(id, &w3d_message_804ad158)
            || w3d_message_id_equals_8015f65c(id, &w3d_message_804ad160)) {
            w3d_update_8003cdcc(self);
            break;
        }
        if (w3d_message_id_equals_8015f65c(id, &w3d_message_804ad168)) {
            w3d_apply_8003d0a0(self);
            break;
        }
        if (w3d_message_id_equals_8015f65c(id, &w3d_message_804ad180)) {
            w3d_finish_8015fd1c(self);
            break;
        }
        return w3d_base_handler_8015fb34(self, message);
    }
    return 0;
}


