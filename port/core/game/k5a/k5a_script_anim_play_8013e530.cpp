#include "w3d_ptr.h"
#line 1 "k5a_script_anim_play_8013e530.cpp"
struct K5aWormRecord { char pad0[140]; Ptr32<const char> name; };
struct K5aScriptWorm { char pad0[28]; Ptr32<void> mesh; char pad1[80]; int worm_index; char pad2[356]; int control; };
extern "C" char w3d_string_8039fc64[];
extern "C" char w3d_string_8039fc74[];
extern "C" const float w3d_f32_8039fc8c[];
extern "C" const float w3d_f32_8039fc90[];
extern "C" const float w3d_f32_8039fc94[];
extern "C" unsigned int w3d_message_804af9b8;
extern "C" Ptr32<void> w3d_message_pool_804b1754;
extern "C" int w3d_auto_800fc2b0(Ptr32<Ptr32<const char>> name, Ptr32<Ptr32<const char>> value);
extern "C" int w3d_worm_play_named_801359ec(Ptr32<K5aScriptWorm> self, Ptr32<void> mesh, Ptr32<const char> name, Ptr32<int> control, float speed, float start, float end);
extern "C" Ptr32<K5aWormRecord> s8_index_query_800fc6dc(int index);
extern "C" int w3d_text_format_803434d4(Ptr32<char> buffer, Ptr32<const char> format, ...);
extern "C" Ptr32<void> FUN_801613f0(Ptr32<void> pool, int size);
extern "C" unsigned int w3d_cached_message_id(Ptr32<void> cache, int create);
extern "C" Ptr32<void> w3d_message_string_init(Ptr32<void> storage, unsigned short id, Ptr32<const char> text);
extern "C" int w3d_message_post_current(Ptr32<void> message);

extern "C" void k5a_script_anim_play_8013e530(Ptr32<K5aScriptWorm> self)
{
    char text[128];
    Ptr32<const char> anim = 0;
    Ptr32<const char> key = w3d_string_8039fc64;
    w3d_auto_800fc2b0(&key, &anim);
    if (w3d_worm_play_named_801359ec(self, self->mesh, anim, &self->control, w3d_f32_8039fc8c[0], w3d_f32_8039fc90[0], w3d_f32_8039fc94[0]) < 0)
    {
        w3d_text_format_803434d4(text, w3d_string_8039fc74, w3d::VA(s8_index_query_800fc6dc(self->worm_index)->name), w3d::VA(anim));
        w3d_message_post_current(w3d_message_string_init(FUN_801613f0(w3d_message_pool_804b1754, 12), w3d_cached_message_id(&w3d_message_804af9b8, 1), text));
    }
}


