struct K5aSimpleMessage { unsigned short id; char pad0[2]; const void *kind; };
struct K5aFaller { char pad0[20]; int entity; char pad1[168]; void *service_handle; char pad2[112]; int motion[5]; int landed; int falling; char pad3[16]; int task_id; };
struct K5aEngineContext { char pad0[52]; int task_id; };
extern "C" char w3d_string_8037ca78[];
extern "C" char w3d_string_8037cad4[];
extern "C" char w3d_string_8037caec[];
extern "C" const float w3d_f32_8037caf4[];
extern "C" unsigned int w3d_message_804ad934;
extern "C" unsigned int w3d_message_804ad93c;
extern "C" const void *w3d_vtable_8040db38[];
extern "C" void *w3d_message_pool_804b1754;
extern "C" void *w3d_camera_set_804aa8c8;
extern "C" void *w3d_empty_80341584(void *);
extern "C" void *w3d_auto_801797b4(void *);
extern "C" void *FUN_801613f0(void *pool, int size);
extern "C" unsigned int w3d_cached_message_id(void *cache, int create);
extern "C" void *w3d_message_string_init(void *storage, unsigned short id, const char *text);
extern "C" int w3d_message_post_current(void *message);
extern "C" K5aEngineContext *w3d_engine_get_context();
extern "C" int s8_property_write_800fc43c(const char **name, int value);
extern "C" int FUN_80035714(void *set, const char *name, float blend);
extern "C" int w3d_auto_8015fc58(K5aFaller *self, void *message);

extern "C" void k5a_fall_camera_enter_80071d28(K5aFaller *self)
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
    const char *name = w3d_string_8037cad4;
    s8_property_write_800fc43c(&name, self->entity);
    FUN_80035714(w3d_camera_set_804aa8c8, w3d_string_8037caec, w3d_f32_8037caf4[0]);
    K5aSimpleMessage *msg = (K5aSimpleMessage *)FUN_801613f0(w3d_message_pool_804b1754, 8);
    msg->id = w3d_cached_message_id(&w3d_message_804ad93c, 1);
    msg->kind = w3d_vtable_8040db38;
    w3d_auto_8015fc58(self, msg);
}
