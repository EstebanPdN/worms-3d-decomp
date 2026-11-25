// (Worms 3D GameCube PAL, 0x801e47e8).
//
// Queues the next half buffer of a streaming sound slot: reads up to half the
// buffer from the disc file at the current position, zeroing what lies past
// the end of the clip; at the end it silences the voice and finishes the slot
// unless it is still starting; then flips the active bank. Names are
// inferred.

extern "C" void *memset(void *, int, unsigned);
struct Clip { char p[8]; char *data; };
struct Slot {
  char p0[16];
  Clip *clip;
  char p1[4];
  char file[60];
  void *voice;
  unsigned pos;
  unsigned size;
  char *buffer;
  unsigned bytes;
  unsigned voiceBytes;
  unsigned char bank;
  char p2[3];
  int starting;
  int p3;
  int busy;
};
extern "C" void fn_801e4a4c(int, void *);
extern "C" int fn_802f5568(void *, void *, int, int, void (*)(int, void *), int);
extern "C" void fn_803238fc(void *, unsigned, unsigned, int, int);
extern "C" void w3d_stream_slot_finish_801e4794(Slot *);
extern "C" void w3d_d40e_stream_fill_next_801e47e8(Slot *s) {
  unsigned n, len;
  n = len = s->bytes >> 1;
  char *dst;
  if (s->bank) dst = s->buffer + n;
  else dst = s->buffer;
  if (s->pos + len > s->size) {
    if (s->size > s->pos) {
      n = s->size - s->pos;
      memset(dst + n, 0, len - n);
    } else {
      memset(dst, 0, len);
      fn_803238fc(s->voice, s->bank ? s->voiceBytes >> 1 : 0, s->voiceBytes >> 1, 0, 0);
      n = 0;
    }
  }
  if (n) {
    fn_802f5568(s->file, dst, n, (int)(s->clip->data + s->pos), fn_801e4a4c, 2);
    s->busy = 1;
    s->pos += n;
  } else if (s->starting) {
    s->starting = n;
  } else {
    w3d_stream_slot_finish_801e4794(s);
  }
  s->bank ^= 1;
}
