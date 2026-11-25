#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k5a_audio_factors_apply_80129340.c"
typedef struct K5aAudioDevice K5aAudioDevice;
typedef struct K5aAudioDeviceVtable
{
  Ptr32<void (void)> unknown_00[8];
  Ptr32<int (Ptr32<K5aAudioDevice>, float)> set_rolloff;
  Ptr32<void (void)> unknown_24[1];
  Ptr32<int (Ptr32<K5aAudioDevice>, float)> set_distance;
  Ptr32<void (void)> unknown_2c[1];
  Ptr32<int (Ptr32<K5aAudioDevice>, float)> set_doppler;
} K5aAudioDeviceVtable;
struct K5aAudioDevice
{
  Ptr32<const K5aAudioDeviceVtable> vtable;
};
typedef struct K5aAudioContext
{
  char pad0[112];
  Ptr32<K5aAudioDevice> device;
} K5aAudioContext;
extern Ptr32<K5aAudioContext> w3d_audio_context_804b1788;
extern char w3d_string_8039c8fc[];
extern char w3d_string_8039c914[];
extern char w3d_string_8039c928[];
extern const float w3d_f32_8039c93c[];
extern const float w3d_f32_8039c940[];
extern int w3d_auto_800fc270(Ptr32<Ptr32<const char>> name, Ptr32<float> value);

void k5a_audio_factors_apply_80129340(void)
{
  if (w3d_audio_context_804b1788->device != 0)
  {
    float distance = w3d_f32_8039c93c[0];
    float doppler = w3d_f32_8039c940[0];
    float rolloff = w3d_f32_8039c940[0];
    Ptr32<const char> distance_name = w3d_string_8039c8fc;
    Ptr32<const char> doppler_name;
    Ptr32<const char> rolloff_name;
    w3d_auto_800fc270(&distance_name, &distance);
    doppler_name = w3d_string_8039c914;
    w3d_auto_800fc270(&doppler_name, &doppler);
    rolloff_name = w3d_string_8039c928;
    w3d_auto_800fc270(&rolloff_name, &rolloff);
    w3d_audio_context_804b1788->device->vtable->set_distance(w3d_audio_context_804b1788->device, distance);
    w3d_audio_context_804b1788->device->vtable->set_doppler(w3d_audio_context_804b1788->device, doppler);
    w3d_audio_context_804b1788->device->vtable->set_rolloff(w3d_audio_context_804b1788->device, rolloff);
  }
}

}
