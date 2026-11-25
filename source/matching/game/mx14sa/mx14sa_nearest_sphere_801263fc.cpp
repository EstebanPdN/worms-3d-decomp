// External GC32 views: observed query owner and registry-entry fields only.
// Selection semantics are inferred; these are not portable ownership layouts.
struct Mx14saVector { float x, y, z; };
struct Mx14saQueryOwner { unsigned short unknown, slot; unsigned mask; };
struct Mx14saQueryEntry { unsigned observed_words[6]; int owner; };
extern unsigned distance_804b1790;
extern float fraction_804b17a4;
extern unsigned short hit_804aa95e;
extern int (*next_804b17b4)();
extern "C" void begin_8003fc70(unsigned, unsigned, const Mx14saVector *, unsigned, int);
extern "C" Mx14saQueryEntry *entry_8003f240(unsigned);
extern "C" void end_8003ffac(unsigned);
extern "C" int mx14sa_nearest_sphere_801263fc(Mx14saQueryOwner *self, const Mx14saVector *vector, unsigned maximum, int excluded) {
 begin_8003fc70(self->slot,self->mask,vector,maximum,excluded);
 int selected=65535;
 float fraction=(float)(int)maximum;
 unsigned nearest=maximum;
 int current=next_804b17b4();
 while(current!=65535) {
  if(distance_804b1790<nearest && entry_8003f240(hit_804aa95e)->owner!=excluded) {
   nearest=distance_804b1790;
   selected=current;
   fraction=fraction_804b17a4;
  }
  current=next_804b17b4();
 }
 distance_804b1790=nearest;
 fraction_804b17a4=fraction;
 hit_804aa95e=selected;
 end_8003ffac(self->slot);
 return selected;
}
