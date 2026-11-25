// (Worms 3D GameCube PAL, 0x801dffac).
//
// For each voice in the vector at +36 whose owner id (read through
// 0x801df288 from +88) equals id and that reports active (virtual slot 7),
// calls its slot 5, then scans the 32 slot pointers at +48 for the one whose
// first field equals the voice's sound (slot 16) and passes that slot to
// 0x801e4e6c. Returns 0. Names are inferred.

struct Sound;
struct VoiceBase {
  virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
  virtual void prepare();
  virtual void w6();
  virtual int active();
  virtual void w8(); virtual void w9(); virtual void w10(); virtual void w11(); virtual void w12(); virtual void w13(); virtual void w14(); virtual void w15();
  virtual Sound *sound();
};
struct Voice : VoiceBase {
  char p[84];
  void *owner;
};
struct Slot { Sound *sound; };
struct Vec {
  Voice **b, **e;
  unsigned size() const { return e - b; }
  Voice *&operator[](unsigned i) { return b[i]; }
};
struct Mixer {
  char p[36];
  Vec voices;
  char p1[4];
  Slot *slots[32];
};
extern "C" int w3d_get_801df288(void *);
extern "C" int w3d_auto_801e4e6c(Slot *);
extern "C" int w3d_d29e_stop_voices_801dffac(Mixer *self, int id) {
  for (unsigned i = 0; i < self->voices.size(); i++) {
    if (w3d_get_801df288(self->voices[i]->owner) == id && self->voices[i]->active()) {
      self->voices[i]->prepare();
      unsigned k = 0;
      do {
        Sound *s = self->slots[k]->sound;
        if (s == self->voices[i]->sound()) {
          w3d_auto_801e4e6c(self->slots[k]);
          break;
        }
        k++;
      } while (k <= 31);
    }
  }
  return 0;
}
