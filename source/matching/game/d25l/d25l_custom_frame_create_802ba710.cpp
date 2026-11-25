// GWMP8P rev0 0x802ba710. Creates the FE.NewFrame.Cust handle of a view when
// it has none. The vectors b and c are written and never read: the original
// stores them (32..40 and 48..56 of the frame), the source reason is
// unknown.
struct Vec { float x, y, z; Vec() {} Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; } };
struct D25lString_803426b8;
extern "C" void w3d_string_base_finish_8020c5c4(D25lString_803426b8 *), w3d_string_release_80341588(D25lString_803426b8 *);
struct D25lString_803426b8 { char *text; D25lString_803426b8();  D25lString_803426b8(const D25lString_803426b8 &); ~D25lString_803426b8() { w3d_string_base_finish_8020c5c4(this); w3d_string_release_80341588(this); } };
struct Data { char pad[20]; Vec pos; char pad32[84]; int a116; char pad120[4]; float a124; };
struct Named;
struct View { char pad0[35]; unsigned char a35; char pad36[4]; Data *data; char pad44[68]; int a112; char pad116[104]; Named *named; };
extern "C" void *w3d_heap_allocate_entry_801fe1d8(unsigned);
extern "C" Named *s11_named_handle_802badf0(void *, const char *, unsigned char);
extern "C" void fn_802baf1c(Named *, float, float, float);
extern "C" void w3d_forward_to_held_802bbc90(Named *, const Vec &);
extern "C" void w3d_call_with_owner_802bbcc4(Named *, void *);
extern Vec lbl_8045e788;
extern "C" void d25l_custom_frame_create_802ba710(View *self)
{
 D25lString_803426b8 s;
 Data *d = self->data;
 int base = d->a116;
 if (self->named == 0) {
  const Vec &g = lbl_8045e788; const Vec &p = d->pos; Vec a(g); Vec b(p); float w = d->a124; self->named = s11_named_handle_802badf0(w3d_heap_allocate_entry_801fe1d8(4), "FE.NewFrame.Cust", self->a35 + (base + 28)); Vec c(g); fn_802baf1c(self->named, w, d->pos.x, p.y); w3d_forward_to_held_802bbc90(self->named, a); w3d_call_with_owner_802bbcc4(self->named, (void *)self->a112);
 }
}
