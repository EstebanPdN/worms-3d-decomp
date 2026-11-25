struct K5aCameraView { char pad0[60]; const char *name; };
struct K5aCameraSet { char pad0[312]; int current; K5aCameraView **views; };
struct K5aSimpleMessage { unsigned short id; char pad0[2]; const void *kind; };
struct K5aRope { char pad0[44]; int swinging; char pad1[72]; int camera_active; };
extern "C" char w3d_string_80388094[];
extern "C" char w3d_string_8038809c[];
extern "C" const float w3d_f32_803880a4[];
extern "C" unsigned int w3d_message_804ae9b0;
extern "C" const void *w3d_vtable_8040db38[];
extern "C" void *w3d_message_pool_804b1754;
extern "C" K5aCameraSet *w3d_camera_set_804aa8c8;
extern "C" void *FUN_801613f0(void *pool, int size);
extern "C" unsigned int w3d_cached_message_id(void *cache, int create);
extern "C" int w3d_message_post_current(void *message);
extern "C" int strcmp(const char *a, const char *b);
extern "C" int FUN_80035714(K5aCameraSet *set, const char *name, float blend);
extern "C" void w3d_rope_enter_mode_800d0d6c(void *self);

extern "C" void k5a_rope_camera_reset_800cef44(K5aRope *self)
{
    if (self->swinging != 0)
        w3d_rope_enter_mode_800d0d6c(self);
    if (self->camera_active != 0)
    {
        int other = strcmp((*(K5aCameraView **)((char *)w3d_camera_set_804aa8c8->views + (w3d_camera_set_804aa8c8->current << 2)))->name, w3d_string_80388094) != 0;
        if (other)
            FUN_80035714(w3d_camera_set_804aa8c8, w3d_string_8038809c, w3d_f32_803880a4[0]);
    }
    K5aSimpleMessage *msg = (K5aSimpleMessage *)FUN_801613f0(w3d_message_pool_804b1754, 8);
    msg->id = w3d_cached_message_id(&w3d_message_804ae9b0, 1);
    msg->kind = w3d_vtable_8040db38;
    w3d_message_post_current(msg);
}
