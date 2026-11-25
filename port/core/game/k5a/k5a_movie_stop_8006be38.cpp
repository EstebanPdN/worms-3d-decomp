#include "w3d_ptr.h"
#line 1 "k5a_movie_stop_8006be38.cpp"
struct K5aSimpleMessage { unsigned short id; char pad0[2]; Ptr32<const void> kind; };
struct K5aMovieDevice;
struct K5aMovieDeviceVtable { Ptr32<void (void)> unknown_00[10]; Ptr32<int (Ptr32<K5aMovieDevice>, int)> set_active; };
struct K5aMovieDevice { Ptr32<const K5aMovieDeviceVtable> vtable; };
struct K5aAppContext { char pad0[108]; Ptr32<K5aMovieDevice> movie; };
struct K5aMoviePlayer { char pad0[240]; unsigned int flags; };
extern "C" char w3d_string_8037bea0[];
extern "C" char w3d_string_8037bb14[];
extern "C" unsigned int w3d_message_804ad83c;
extern "C" unsigned int w3d_message_804ad804;
extern "C" unsigned int w3d_message_804ad734;
extern "C" Ptr32<const void> w3d_vtable_8040db38[];
extern "C" Ptr32<void> w3d_message_pool_804b1754;
extern "C" Ptr32<K5aAppContext> w3d_context_804b1788;
extern "C" int w3d_runtime_is_paused(Ptr32<K5aAppContext> context);
extern "C" int w3d_auto_800fc230(Ptr32<Ptr32<const char>> name, Ptr32<int> value);
extern "C" Ptr32<void> FUN_801613f0(Ptr32<void> pool, int size);
extern "C" unsigned int w3d_cached_message_id(Ptr32<void> cache, int create);
extern "C" Ptr32<void> w3d_message_string_init(Ptr32<void> storage, unsigned short id, Ptr32<const char> text);
extern "C" int w3d_message_post_current(Ptr32<void> message);
extern "C" int w3d_app_leave_801298cc(Ptr32<K5aAppContext> context);
extern "C" int FUN_800a7e14(int slot, Ptr32<const char> name);

extern "C" void k5a_movie_stop_8006be38(Ptr32<K5aMoviePlayer> self)
{
    if (w3d_runtime_is_paused(w3d_context_804b1788) != 0)
    {
        Ptr32<const char> name;
        int active = 0;
        self->flags &= ~0x00800000u;
        name = w3d_string_8037bea0;
        w3d_auto_800fc230(&name, &active);
        if (active == 0)
        {
            Ptr32<K5aSimpleMessage> paused = (Ptr32<K5aSimpleMessage>)FUN_801613f0(w3d_message_pool_804b1754, 8);
            paused->id = w3d_cached_message_id(&w3d_message_804ad83c, 1);
            paused->kind = w3d_vtable_8040db38;
            w3d_message_post_current(paused);
        }
        Ptr32<K5aSimpleMessage> stopped = (Ptr32<K5aSimpleMessage>)FUN_801613f0(w3d_message_pool_804b1754, 8);
        stopped->id = w3d_cached_message_id(&w3d_message_804ad804, 1);
        stopped->kind = w3d_vtable_8040db38;
        w3d_message_post_current(stopped);
        w3d_message_post_current(w3d_message_string_init(FUN_801613f0(w3d_message_pool_804b1754, 12), w3d_cached_message_id(&w3d_message_804ad734, 1), w3d_string_8037bb14));
        w3d_app_leave_801298cc(w3d_context_804b1788);
        if (w3d_context_804b1788->movie != 0)
            w3d_context_804b1788->movie->vtable->set_active(w3d_context_804b1788->movie, 0);
        FUN_800a7e14(5, w3d_string_8037bb14);
    }
}


