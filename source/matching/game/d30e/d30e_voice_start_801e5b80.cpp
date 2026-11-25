// (Worms 3D GameCube PAL, 0x801e5b80).
//
// Starts a voice from a source: refuses if the source's stream is unusable,
// there are no channels or it is already playing; takes the id from source
// virtual slot 16, runs stream slots 23 to 25, and unless the stream is open
// or the voice active, claims a free entry of the 16-channel table at
// 0x8045dbc8 for each stream channel, sets it up through 0x802f51e4 and
// 0x802f5568 with a lazily allocated 96-byte buffer and the 0x801e59b4
// callback. On failure it releases through stream slot 21 and returns 0.
// Names are inferred.

struct File;
struct Stream { virtual void v0(),v1(),v2(),v3(),v4(),v5(),v6(),v7(),v8(),v9(),v10(),v11(),v12(),v13(),v14(),v15(),v16(),v17(),v18(),v19(),v20(); virtual void v92(); virtual void v96(); virtual void v100(); virtual void v104(); virtual void v108(); virtual void v26(),v27(),v28(),v29(),v30(),v31(),v32(),v33(); virtual File *v144(int); };
struct SourceBase { virtual void v0(),v1(),v2(),v3(),v4(),v5(),v6(),v7(),v8(),v9(),v10(),v11(),v12(),v13(),v14(),v15(); virtual int v72(); };
struct Source : SourceBase { char p[60]; Stream *s; };
struct Chan { char p[60]; unsigned a : 1; unsigned b : 1; };
extern Chan lbl_8045dbc8[];
struct Mgr;
extern "C" int w3d_stream_is_open(Mgr *, int);
extern Mgr *w3d_stream_system_804ab85c;
extern "C" int fn_802f51e4(int, Chan *);
extern "C" int fn_802f5568(Chan *, void *, int, int, void (*)(), int);
extern "C" void *w3d_aligned_allocate(int, int);
extern "C" void fn_801e59b4(void *, void *);
struct Voice {
  int id; unsigned short slot[2]; unsigned count : 8; unsigned started : 1; unsigned opened : 1; unsigned active : 1;
  char q[4]; unsigned n; char r[28]; int x48; int y; int h; void *buf[2];
};
extern "C" int w3d_auto_801e64c0(Voice *, Stream *);
extern "C" int w3d_s21_is_playing_801e6c48(Voice *, File *);
extern "C" int w3d_d30e_voice_start_801e5b80(Voice *self, Source *src) {
  Stream *s = src->s;
  Mgr *mgr = w3d_stream_system_804ab85c;
  if (!w3d_auto_801e64c0(self, s) || !self->n || !src || w3d_s21_is_playing_801e6c48(self, s->v144(0))) return 0;
  self->x48 = 0;
  *(Source **)((char *)self + 164) = src;
  self->id = src->v72();
  s->v100();
  s->v104();
  s->v108();
  if (!w3d_stream_is_open(mgr, self->h) && !self->active) {
    for (unsigned i = 0; i < self->n; i++) {
      if (s->v144(i) != (File *)-1) {
        self->slot[i] = 0xffff;
        for (unsigned k = 0; k <= 15; k++) {
          if (!lbl_8045dbc8[k].b) { self->slot[i] = k; break; }
        }
        Chan *c = &lbl_8045dbc8[self->slot[i]];
        if (!fn_802f51e4((int)(s->v144(i)), c)) {
          s->v92();
          self->slot[i] = 0xffff;
          return 0;
        }
        if (!self->buf[i]) self->buf[i] = w3d_aligned_allocate(96, 32);
        fn_802f5568(c, self->buf[i], 96, 0, (void (*)())fn_801e59b4, 2);
        c->a = 0;
        c->b = 1;
      }
    }
    self->active = 1;
    self->count = 0;
  }
  self->started = 1;
  return 1;
}
