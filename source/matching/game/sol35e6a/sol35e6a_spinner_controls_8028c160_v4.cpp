// Inferred spinner control and color update; GC32 offsets witnessed in original.
#define FIELD(p,T,o) (*reinterpret_cast<T *>(static_cast<char *>(p)+(o)))
union Color {
 struct { unsigned char red, green, blue, alpha; } channels;
 unsigned word;
};
extern "C" void sol35e6a_set_enabled_8025f064(void *, unsigned);
extern "C" const Color *sol35e6a_get_color_80178f54(void *);
extern "C" int sol35e6a_set_color_80173df0(void *, const Color *);
inline void set_virtual(void *p, unsigned value) {
 if (p) {
  typedef void (*SetEnabled)(void *, unsigned);
  SetEnabled *table = FIELD(p,SetEnabled *,0);
  table[22](p,value);
 }
}
extern "C" void sol35e6a_spinner_controls_8028c160_v4(void *self) {
 bool active = FIELD(self,bool,176);
 bool previous = !active;
 bool next = !FIELD(self,bool,140);
 if (!FIELD(self,bool,140)) {
  previous = FIELD(self,void *,240) == 0;
  active = false;
 }
 set_virtual(FIELD(self,void *,232),previous);
 set_virtual(FIELD(self,void *,236),active);
 set_virtual(FIELD(self,void *,240),next);
 if (FIELD(self,void *,212)) sol35e6a_set_enabled_8025f064(FIELD(self,void *,212),previous);
 if (FIELD(self,void *,216)) sol35e6a_set_enabled_8025f064(FIELD(self,void *,216),active);
 if (FIELD(self,void *,220)) sol35e6a_set_enabled_8025f064(FIELD(self,void *,220),next);
 Color color = *sol35e6a_get_color_80178f54(FIELD(self,void *,228));
 if (FIELD(self,bool,176)) color.channels.alpha = 255;
 if (FIELD(self,void *,224)) sol35e6a_set_color_80173df0(FIELD(self,void *,224),&color);
}
typedef char ColorSize[sizeof(Color)==4?1:-1];

typedef char BoolSize[sizeof(bool)==4?1:-1];
