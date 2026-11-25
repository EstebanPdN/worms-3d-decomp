// d19c: 0x801263fc (256 bytes). Nearest sphere query (mx14sa's parked draft,
// unchanged apart from names): begin a sphere query from the owner's slot and
// mask, walk the results and keep the nearest one whose registry owner differs
// from the excluded value, publish its distance, fraction and handle, end the
// query and return the handle (65535 when none).
// Built with -mps-float: the function saves an FPR (the running fraction) and
// the unflagged build differed only by the 8-byte frame gap below the register
// save area. The int to float conversion of the maximum uses the usual
// 0x4330000080000000 bias literal.
// External GC32 views: observed query owner and registry-entry fields only.
// Selection semantics are inferred; these are not portable ownership layouts.
struct d19c_QueryVector { float x, y, z; };
struct d19c_QueryOwner { unsigned short unknown, slot; unsigned mask; };
struct d19c_QueryEntry { unsigned observed_words[6]; int owner; };
extern unsigned d19c_query_distance_804b1790;
extern float d19c_query_fraction_804b17a4;
extern unsigned short d19c_query_hit_804aa95e;
extern int (*d19c_query_next_804b17b4)();
extern "C" void d19c_sphere_query_begin_8003fc70(unsigned, unsigned, const d19c_QueryVector *, unsigned, int);
extern "C" d19c_QueryEntry *d19c_registry_entry_8003f240(unsigned);
extern "C" void d19c_sphere_query_end_8003ffac(unsigned);
extern "C" int d19c_nearest_sphere_801263fc(d19c_QueryOwner *self, const d19c_QueryVector *vector, unsigned maximum, int excluded) {
 d19c_sphere_query_begin_8003fc70(self->slot,self->mask,vector,maximum,excluded);
 int selected=65535;
 float fraction=(float)(int)maximum;
 unsigned nearest=maximum;
 int current=d19c_query_next_804b17b4();
 while(current!=65535) {
  if(d19c_query_distance_804b1790<nearest && d19c_registry_entry_8003f240(d19c_query_hit_804aa95e)->owner!=excluded) {
   nearest=d19c_query_distance_804b1790;
   selected=current;
   fraction=d19c_query_fraction_804b17a4;
  }
  current=d19c_query_next_804b17b4();
 }
 d19c_query_distance_804b1790=nearest;
 d19c_query_fraction_804b17a4=fraction;
 d19c_query_hit_804aa95e=selected;
 d19c_sphere_query_end_8003ffac(self->slot);
 return selected;
}
