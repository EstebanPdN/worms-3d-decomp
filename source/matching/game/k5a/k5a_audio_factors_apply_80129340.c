typedef struct K5aAudioDevice K5aAudioDevice;
typedef struct K5aAudioDeviceVtable
{
  void (*unknown_00[8])(void);
  int (*set_rolloff)(K5aAudioDevice *self, float value);
  void (*unknown_24[1])(void);
  int (*set_distance)(K5aAudioDevice *self, float value);
  void (*unknown_2c[1])(void);
  int (*set_doppler)(K5aAudioDevice *self, float value);
} K5aAudioDeviceVtable;
struct K5aAudioDevice
{
  const K5aAudioDeviceVtable *vtable;
};
typedef struct K5aAudioContext
{
  char pad0[112];
  K5aAudioDevice *device;
} K5aAudioContext;
extern K5aAudioContext *w3d_audio_context_804b1788;
extern char w3d_string_8039c8fc[];
extern char w3d_string_8039c914[];
extern char w3d_string_8039c928[];
extern const float w3d_f32_8039c93c[];
extern const float w3d_f32_8039c940[];
extern int w3d_auto_800fc270(const char **name, float *value);

void k5a_audio_factors_apply_80129340(void)
{
  if (w3d_audio_context_804b1788->device != 0)
  {
    float distance = w3d_f32_8039c93c[0];
    float doppler = w3d_f32_8039c940[0];
    float rolloff = w3d_f32_8039c940[0];
    const char *distance_name = w3d_string_8039c8fc;
    const char *doppler_name;
    const char *rolloff_name;
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
