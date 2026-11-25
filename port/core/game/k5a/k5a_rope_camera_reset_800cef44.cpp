#include "w3d_ptr.h"
#line 1 "k5a_rope_camera_reset_800cef44.cpp"
struct K5aCameraView { char pad0[60]; Ptr32<const char> name; };
struct K5aCameraSet { char pad0[312]; int current; Ptr32<Ptr32<K5aCameraView>> views; };
struct K5aSimpleMessage { unsigned short id; char pad0[2]; Ptr32<const void> kind; };
struct K5aRope { char pad0[44]; int swinging; char pad1[72]; int camera_active; };
extern "C" char w3d_string_80388094[];
extern "C" char w3d_string_8038809c[];
extern "C" const float w3d_f32_803880a4[];
extern "C" unsigned int w3d_message_804ae9b0;
extern "C" Ptr32<const void> w3d_vtable_8040db38[];
extern "C" Ptr32<void> w3d_message_pool_804b1754;
extern "C" Ptr32<K5aCameraSet> w3d_camera_set_804aa8c8;
extern "C" Ptr32<void> FUN_801613f0(Ptr32<void> pool, int size);
extern "C" unsigned int w3d_cached_message_id(Ptr32<void> cache, int create);
extern "C" int w3d_message_post_current(Ptr32<void> message);
extern "C" int strcmp(Ptr32<const char> a, Ptr32<const char> b);
extern "C" int FUN_80035714(Ptr32<K5aCameraSet> set, Ptr32<const char> name, float blend);
extern "C" void w3d_rope_enter_mode_800d0d6c(Ptr32<void> self);

extern "C" void k5a_rope_camera_reset_800cef44(Ptr32<K5aRope> self)
{
    if (self->swinging != 0)
        w3d_rope_enter_mode_800d0d6c(self);
    if (self->camera_active != 0)
    {
        int other = strcmp((*(Ptr32<Ptr32<K5aCameraView>>)((Ptr32<char>)w3d_camera_set_804aa8c8->views + (w3d_camera_set_804aa8c8->current << 2)))->name, w3d_string_80388094) != 0;
        if (other)
            FUN_80035714(w3d_camera_set_804aa8c8, w3d_string_8038809c, w3d_f32_803880a4[0]);
    }
    Ptr32<K5aSimpleMessage> msg = (Ptr32<K5aSimpleMessage>)FUN_801613f0(w3d_message_pool_804b1754, 8);
    msg->id = w3d_cached_message_id(&w3d_message_804ae9b0, 1);
    msg->kind = w3d_vtable_8040db38;
    w3d_message_post_current(msg);
}


