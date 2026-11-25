typedef struct K5aVolumeSink K5aVolumeSink;
typedef struct K5aVolumeSinkVtable
{
  void (*unknown_00[13])(void);
  int (*set_volume)(K5aVolumeSink *self, int fade, float volume);
} K5aVolumeSinkVtable;
struct K5aVolumeSink
{
  const K5aVolumeSinkVtable *vtable;
};
typedef struct K5aAudioMixer
{
  char pad0[28];
  K5aVolumeSink *music;
  K5aVolumeSink *ambient;
} K5aAudioMixer;
extern char w3d_string_80372340[];
extern char w3d_string_80372350[];
extern const float w3d_f32_8037237c[];
extern const float w3d_f32_80372380[];
extern int w3d_auto_800fc270(const char **name, float *value);

void k5a_audio_volumes_apply_8002a12c(K5aAudioMixer *self, int scaled)
{
  const char *music_name;
  float music_volume = w3d_f32_8037237c[0];
  const char *ambient_name;
  float ambient_volume = w3d_f32_8037237c[0];
  music_name = w3d_string_80372340;
  w3d_auto_800fc270(&music_name, &music_volume);
  ambient_name = w3d_string_80372350;
  w3d_auto_800fc270(&ambient_name, &ambient_volume);
  if (scaled)
  {
    music_volume *= w3d_f32_80372380[0];
    ambient_volume *= w3d_f32_80372380[0];
  }
  if (self->music != 0)
    self->music->vtable->set_volume(self->music, 1, music_volume);
  if (self->ambient != 0)
    self->ambient->vtable->set_volume(self->ambient, 1, ambient_volume);
}
