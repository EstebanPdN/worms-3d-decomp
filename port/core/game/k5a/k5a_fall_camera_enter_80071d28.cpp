#include "w3d_ptr.h"
#line 1 "k5a_fall_camera_enter_80071d28.cpp"
struct K5aSimpleMessage { unsigned short id; char pad0[2]; Ptr32<const void> kind; };
struct K5aFaller { char pad0[20]; int entity; char pad1[168]; Ptr32<void> service_handle; char pad2[112]; int motion[5]; int landed; int falling; char pad3[16]; int task_id; };
struct K5aEngineContext { char pad0[52]; int task_id; };
extern "C" char w3d_string_8037ca78[];
extern "C" char w3d_string_8037cad4[];
extern "C" char w3d_string_8037caec[];
extern "C" const float w3d_f32_8037caf4[];
extern "C" unsigned int w3d_message_804ad934;
extern "C" unsigned int w3d_message_804ad93c;
extern "C" Ptr32<const void> w3d_vtable_8040db38[];
extern "C" Ptr32<void> w3d_message_pool_804b1754;
extern "C" Ptr32<void> w3d_camera_set_804aa8c8;
extern "C" Ptr32<void> w3d_empty_80341584(Ptr32<void>);
extern "C" Ptr32<void> w3d_auto_801797b4(Ptr32<void>);
extern "C" Ptr32<void> FUN_801613f0(Ptr32<void> pool, int size);
extern "C" unsigned int w3d_cached_message_id(Ptr32<void> cache, int create);
extern "C" Ptr32<void> w3d_message_string_init(Ptr32<void> storage, unsigned short id, Ptr32<const char> text);
extern "C" int w3d_message_post_current(Ptr32<void> message);
extern "C" Ptr32<K5aEngineContext> w3d_engine_get_context();
extern "C" int s8_property_write_800fc43c(Ptr32<Ptr32<const char>> name, int value);
extern "C" int FUN_80035714(Ptr32<void> set, Ptr32<const char> name, float blend);
extern "C" int w3d_auto_8015fc58(Ptr32<K5aFaller> self, Ptr32<void> message);

extern "C" void k5a_fall_camera_enter_80071d28(Ptr32<K5aFaller> self)
{
    w3d_auto_801797b4(w3d_empty_80341584(self->service_handle));
    w3d_message_post_current(w3d_message_string_init(FUN_801613f0(w3d_message_pool_804b1754, 12), w3d_cached_message_id(&w3d_message_804ad934, 1), w3d_string_8037ca78));
    self->motion[0] = 0;
    self->motion[1] = 0;
    self->motion[2] = 0;
    self->motion[3] = 0;
    self->motion[4] = 0;
    self->landed = 0;
    self->task_id = w3d_engine_get_context()->task_id;
    self->falling = 1;
    Ptr32<const char> name = w3d_string_8037cad4;
    s8_property_write_800fc43c(&name, self->entity);
    FUN_80035714(w3d_camera_set_804aa8c8, w3d_string_8037caec, w3d_f32_8037caf4[0]);
    Ptr32<K5aSimpleMessage> msg = (Ptr32<K5aSimpleMessage>)FUN_801613f0(w3d_message_pool_804b1754, 8);
    msg->id = w3d_cached_message_id(&w3d_message_804ad93c, 1);
    msg->kind = w3d_vtable_8040db38;
    w3d_auto_8015fc58(self, msg);
}


