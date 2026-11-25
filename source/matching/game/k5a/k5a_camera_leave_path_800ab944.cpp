struct K5aCameraView { char pad0[60]; const char *name; };
struct K5aCameraSet { char pad0[312]; int current; K5aCameraView **views; };
struct K5aSimpleMessage { unsigned short id; char pad0[2]; const void *kind; };
struct K5aFollower { char pad0[168]; int following; };
extern "C" char w3d_string_80381c08[];
extern "C" char w3d_string_80381c10[];
extern "C" const float w3d_f32_80381c18[];
extern "C" unsigned int w3d_message_804ae380;
extern "C" const void *w3d_vtable_8040db38[];
extern "C" void *w3d_message_pool_804b1754;
extern "C" K5aCameraSet *w3d_camera_set_804aa8c8;
extern "C" void *FUN_801613f0(void *pool, int size);
extern "C" unsigned int w3d_cached_message_id(void *cache, int create);
extern "C" int w3d_message_post_current(void *message);
extern "C" int strcmp(const char *a, const char *b);
extern "C" int FUN_80035714(K5aCameraSet *set, const char *name, float blend);

extern "C" void k5a_camera_leave_path_800ab944(K5aFollower *self)
{
    if (self->following != 0)
    {
        int other = strcmp((*(K5aCameraView **)((char *)w3d_camera_set_804aa8c8->views + (w3d_camera_set_804aa8c8->current << 2)))->name, w3d_string_80381c08) != 0;
        if (other)
            FUN_80035714(w3d_camera_set_804aa8c8, w3d_string_80381c10, w3d_f32_80381c18[0]);
    }
    self->following = 0;
    K5aSimpleMessage *msg = (K5aSimpleMessage *)FUN_801613f0(w3d_message_pool_804b1754, 8);
    msg->id = w3d_cached_message_id(&w3d_message_804ae380, 1);
    msg->kind = w3d_vtable_8040db38;
    w3d_message_post_current(msg);
}
