// GWMP8P rev0 0x802608dc. Menu panel constructor: base constructor, table
// pointer, cleared slots, default text, publishes the instance at
// 0x804abb44, links the shared counter (value 50) and sets the defaults 0.8
// and 1.1. Names are inferred from use. Owns the literals at 0x803cac38.
inline void *operator new(unsigned, void *q) { return q; }
struct Text { char *p; Text(); };
struct Obj { char u[188]; int f188; };
extern "C" int fn_801628b0(void *);
extern Obj *lbl_804aaabc;
struct Panel;
extern Panel *lbl_804abb44;
extern void *lbl_8041bbc0[];
struct Panel { void *vt; char u4[24]; int z28; int z32; int z36; int z40; int z44; int z48; int z52; int z56; int z60; int z64; int z68; int z72; int z76; int z80; int z84; int z88; int z92; int z96; int z100; int z104; int z108; int z112; int z116; int z120; int z124; int z128; int z132; int z136; int z140; int z144; int z148; int z152; int z156; int z160; int z164; int z168; int z172; int f176; int f180; int *f184; float f188; float f192; int f196; int f200; int f204; int f208; Text text; int u216; int t[20]; };
extern "C" Panel *w3d_d30k_menu_panel_construct_802608dc(Panel *self) {
 fn_801628b0(self);
 self->vt = lbl_8041bbc0;
 self->z28 = 0; self->z32 = 0; self->z36 = 0; self->z40 = 0; self->z44 = 0; self->z48 = 0; self->z52 = 0; self->z56 = 0; self->z60 = 0; self->z64 = 0; self->z68 = 0; self->z72 = 0; self->z76 = 0; self->z80 = 0; self->z84 = 0; self->z88 = 0; self->z92 = 0; self->z96 = 0; self->z100 = 0; self->z104 = 0; self->z108 = 0; self->z112 = 0; self->z116 = 0; self->z120 = 0; self->z124 = 0; self->z128 = 0; self->z132 = 0; self->z136 = 0; self->z140 = 0; self->z144 = 0; self->z148 = 0; self->z152 = 0; self->z156 = 0; self->z160 = 0; self->z164 = 0; self->z168 = 0; self->z172 = 0;
 self->f180 = 0; self->f200 = 0; self->f204 = 0;
 new (&self->text) Text;
 self->f176 = -1;
 Obj *g = lbl_804aaabc;
 self->f184 = &g->f188;
 g->f188 = 50;
 lbl_804abb44 = self;
 self->f188 = 0.8f;
 self->f196 = 0;
 self->f208 = 3;
 for (unsigned i = 0; i < 20; i++) self->t[i] = 0;
 self->f192 = 1.1f;
 return self;
}
