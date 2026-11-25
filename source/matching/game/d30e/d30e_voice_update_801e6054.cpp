// (Worms 3D GameCube PAL, 0x801e6054).
//
// Per-frame voice update. While starting, polls each claimed channel of the
// table at 0x8045dbc8, copies the decoded header from the DMA buffer into a
// 48-byte stream block, counts ready channels and, once all are ready, opens
// a mono or stereo stream at the configured volume. Otherwise applies volume
// and facing mix to the open stream, reopens a looping stream if needed, and
// when the voice stops releases its source and returns 0. Names are
// inferred.

struct File;
struct Stream { virtual void v0(),v1(),v2(),v3(),v4(),v5(),v6(),v7(),v8(),v9(),v10(),v11(),v12(),v13(),v14(),v15(),v16(),v17(),v18(),v19(),v20(); virtual void v92(); virtual void v22(),v23(),v24(),v25(),v26(),v27(),v28(),v29(),v30(),v31(),v32(),v33(); virtual File *v144(int); };
struct SourceBase { virtual void v0(),v1(),v2(),v3(); virtual void v24(); virtual void v5(),v6(); virtual int v36(); virtual void v8(),v9(),v10(),v11(),v12(),v13(),v14(),v15(),v16(),v17(); virtual int v80(); };
struct Source : SourceBase { char p[60]; Stream *s; };
struct Chan { char p[60]; unsigned a : 1; unsigned b : 1; };
extern Chan lbl_8045dbc8[];
struct Mgr;
struct Cfg { virtual void v0(),v1(),v2(),v3(),v4(),v5(),v6(),v7(),v8(),v9(),v10(),v11(),v12(),v13(),v14(),v15(),v16(),v17(),v18(),v19(),v20(),v21(),v22(),v23(),v24(),v25(),v26(),v27(),v28(),v29(),v30(); virtual float v132(int); };
extern Mgr *w3d_stream_system_804ab85c;
extern Cfg *w3d_sound_config_804ab80c;

struct Info { char x0[4]; unsigned rate; char x8[2]; unsigned short kind; unsigned short loop; char x14[14]; int fmt[8]; };
struct Fmt { int w[8]; };
struct Block { File *file; unsigned short kind; int size; unsigned len; Fmt fmt; };
struct Voice {
  int id; unsigned short slot[2]; unsigned count : 8; unsigned started : 1; unsigned opened : 1; unsigned active : 1;
  char q[4]; unsigned n; char r[24]; int sample; int x48; int y; int h; Info *buf[2]; Block block[2]; Source *src;
};
extern "C" int w3d_stream_is_open(Mgr *, int);
extern "C" void fn_802fa988(void *, int);
extern "C" int w3d_s21_link_query_801e65fc(Voice *);
extern "C" void w3d_s21_reset_801e6bbc(Voice *);
extern "C" int w3d_sound_sample_get_44(void *);
extern "C" int fn_801e41d0(Mgr *, Block *, Block *, int);
extern "C" int w3d_stream_open_mono(Mgr *, Block *, int, int);
extern "C" void w3d_s21_register_stream_801e6cd0(Voice *, File *);
extern "C" int w3d_s21_is_busy_801e5fd4(Voice *);
extern "C" float w3d_d26e_voice_volume_801e68d4(Voice *, void *);
extern "C" float w3d_facing_term_801e663c(Voice *, void *);
extern "C" float w3d_facing_term_801e6788(Voice *, void *);
extern "C" void w3d_stream_set_mix(Mgr *, int, int, int, int);
static inline void setMix(Mgr *m, int h, float v, float p, float q) { w3d_stream_set_mix(m, h, (unsigned char)(v * 127.0f), (unsigned char)(p * 127.0f), (unsigned char)(q * 127.0f)); }
static inline void setMix2(Mgr *m, int h, float v, float p, float q) { w3d_stream_set_mix(m, h, (unsigned char)(v * 127.0f), (unsigned char)((p + 1.0f) * 0.5f * 127.0f), (unsigned char)((q + 1.0f) * 0.5f * 127.0f)); }
extern "C" void w3d_open_stream_801e6b1c(Voice *);
extern "C" void w3d_auto_801e5dfc(Voice *);
extern "C" int w3d_d30e_voice_update_801e6054(Voice *self, int unused, int t) {
  if (self->active && self->src) {
    for (unsigned i = 0; i < self->n; i++) {
      if (self->slot[i] <= 15 && lbl_8045dbc8[self->slot[i]].a) {
        Info *in = self->buf[i];
        Stream *s = self->src->s;
        Block *b = &self->block[i];
        fn_802fa988(in, 96);
        b->fmt = *(Fmt *)in->fmt;
        b->file = s->v144(i);
        b->kind = in->kind;
        b->len = (in->rate >> 1) & 0x7fffffe0;
        b->size = 96;
        if (w3d_s21_link_query_801e65fc(self)) in->loop = 1;
        else in->loop = 0;
        if (b->kind != 32000) w3d_s21_reset_801e6bbc(self);
        else self->count++;
        Chan *c = &lbl_8045dbc8[self->slot[i]];
        c->a = 0;
        c->b = 0;
        self->slot[i] = 0xffff;
      }
    }
    if (self->n == self->count) {
      self->active = 0;
      self->count = 0;
      Stream *s0 = self->src->s;
      Mgr *mgr = w3d_stream_system_804ab85c;
      if (s0) s0->v92();
      Cfg *cfg = w3d_sound_config_804ab80c;
      float v = cfg->v132(w3d_sound_sample_get_44((void *)self->sample)) * 127.0f;
      int vol = (unsigned char)v;
      Stream *s = self->src->s;
      if (self->n > 1) self->h = fn_801e41d0(mgr, &self->block[0], &self->block[1], vol);
      else self->h = w3d_stream_open_mono(mgr, &self->block[0], vol, 64);
      w3d_s21_register_stream_801e6cd0(self, s->v144(0));
      self->opened = 1;
    }
    return 1;
  }
  if (w3d_s21_is_busy_801e5fd4(self)) {
    Mgr *mgr = w3d_stream_system_804ab85c;
    if (self->src->v80()) {
      float a = w3d_d26e_voice_volume_801e68d4(self, (void *)t);
      float b = w3d_facing_term_801e663c(self, (void *)t);
      float c = w3d_facing_term_801e6788(self, (void *)t);
      a *= 127.0f;
      b = (b + 1.0f) * 0.5f * 127.0f;
      c = (c + 1.0f) * 0.5f * 127.0f;
      w3d_stream_set_mix(mgr, self->h, (unsigned char)a, (unsigned char)b, (unsigned char)c);
    } else {
      float v = w3d_d26e_voice_volume_801e68d4(self, (void *)t);
      w3d_stream_set_mix(mgr, self->h, (unsigned char)(v * 127.0f), 64, 0);
    }
    if (w3d_s21_link_query_801e65fc(self) && self->started && !w3d_stream_is_open(mgr, self->h)) w3d_open_stream_801e6b1c(self);
  }
  if (!w3d_s21_is_busy_801e5fd4(self)) {
    self->started = 0;
    if (self->src) {
      if (self->src->v36()) self->src->v24();
      w3d_auto_801e5dfc(self);
    }
    return 0;
  }
  return 1;
}
