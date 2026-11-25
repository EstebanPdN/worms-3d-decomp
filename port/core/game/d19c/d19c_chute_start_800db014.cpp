#include "w3d_ptr.h"
#line 1 "d19c_chute_start_800db014.cpp"
// d19c: 0x800db014 (384 bytes). Start a chute launch (sol35b12's proof draft,
// rewritten readably): the first call only (+76). An already active object
// posts the target message (12-byte arena record carrying +164). Otherwise,
// unless blocked (+68), mark it active and launching, show it (0x800dc184),
// read "Gravity" times "Low.Gravity.Multiplier" and the wind direction/speed
// settings, set the acceleration (+120) to (cos(dir) * speed, gravity,
// sin(dir) * speed) and, unless silent (+160), post the open message with
// value 42. Meanings are inferred.
// Built with -mps-float: one FPR is saved (wind speed) and the unflagged build
// differed only by the 8-byte frame gap below the register save area.
struct d19c_Vec3 {
    float x, y, z;
    void set(float a, float b, float c) { x = a; y = b; z = c; }
};
struct d19c_Chute {
    unsigned char unknown00[68];
    int blocked;                         // +68
    int active;                          // +72
    int started;                         // +76
    int launching;                       // +80
    unsigned char unknown84[36];
    d19c_Vec3 acceleration;              // +120
    unsigned char unknown132[28];
    int silent;                          // +160
    int target;                          // +164
};
struct d19c_SettingKey { Ptr32<const char> text; };
struct d19c_MessageCache { unsigned words[2]; };
extern "C" void d19c_chute_show_800dc184(Ptr32<d19c_Chute>);
extern "C" int d19c_settings_read_float_800fc270(Ptr32<const d19c_SettingKey>, Ptr32<float>);
extern "C" float d19c_cosine_802e86d4(float);
extern "C" float d19c_sine_802e88ac(float);
extern "C" Ptr32<void> d19c_arena_alloc_801613f0(Ptr32<void>, unsigned);
extern "C" unsigned d19c_cached_message_id_8015f5a0(Ptr32<d19c_MessageCache>, int);
extern "C" Ptr32<void> d19c_target_message_init_800a82f0(Ptr32<void>, unsigned short, int);
extern "C" Ptr32<void> d19c_value_message_init_80125fdc(Ptr32<void>, unsigned short, int);
extern "C" int d19c_message_post_8016239c(Ptr32<void>);
extern Ptr32<void> d19c_message_arena_804b1754;
extern d19c_MessageCache d19c_chute_target_message_804aebec;
extern d19c_MessageCache d19c_chute_open_message_804aec14;

extern "C" void d19c_chute_start_800db014(Ptr32<d19c_Chute> self) {
    if (!self->started) {
        self->started = 1;
        if (self->active) {
            Ptr32<void> message = d19c_arena_alloc_801613f0(d19c_message_arena_804b1754, 12);
            d19c_message_post_8016239c(d19c_target_message_init_800a82f0(message, d19c_cached_message_id_8015f5a0(&d19c_chute_target_message_804aebec, 1), self->target));
        } else if (!self->blocked) {
            self->active = 1;
            self->launching = 1;
            d19c_chute_show_800dc184(self);
            d19c_SettingKey gravity_key = { "Gravity" };
            float gravity;
            d19c_settings_read_float_800fc270(&gravity_key, &gravity);
            d19c_SettingKey multiplier_key = { "Low.Gravity.Multiplier" };
            float multiplier;
            d19c_settings_read_float_800fc270(&multiplier_key, &multiplier);
            gravity *= multiplier;
            d19c_SettingKey direction_key = { "Wind.Direction" };
            float direction;
            d19c_settings_read_float_800fc270(&direction_key, &direction);
            d19c_SettingKey speed_key = { "Wind.Speed" };
            float speed;
            d19c_settings_read_float_800fc270(&speed_key, &speed);
            float x = d19c_cosine_802e86d4(direction) * speed;
            float z = d19c_sine_802e88ac(direction) * speed;
            self->acceleration.set(x, gravity, z);
            if (!self->silent) {
                Ptr32<void> message = d19c_arena_alloc_801613f0(d19c_message_arena_804b1754, 12);
                d19c_message_post_8016239c(d19c_value_message_init_80125fdc(message, d19c_cached_message_id_8015f5a0(&d19c_chute_open_message_804aec14, 1), 42));
            }
        }
    }
}


