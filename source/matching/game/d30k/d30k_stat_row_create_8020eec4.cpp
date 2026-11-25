// GWMP8P rev0 0x8020eec4. Creates a stats table row: four columns built from
// one of two widget tables chosen by the info flag, then the left-aligned
// name label (format at 0x803b3310) is passed to each column by value. Names
// are inferred from use. The buffer object with an accessor, written in an
// inline helper, gives the shared address register.
struct Text;
extern "C" void fn_8020c5c4(Text *);
extern "C" void fn_80341588(Text *);
extern "C" void fn_8020c5c0(Text *);
extern "C" unsigned short *fn_80341884(Text *);
struct Text {
 char *p;
 Text(const char *);
 Text(const Text &o) { fn_8020c5c0(this); p = o.p; ++*fn_80341884(this); }
 ~Text() { fn_8020c5c4(this); fn_80341588(this); }
};
struct Src { char u[20]; int f20; };
struct Column { Column(int); void Take(Text); char u[40]; };
extern "C" void *fn_801fe1d8(unsigned);
inline void *operator new(unsigned n) { return fn_801fe1d8(n); }
extern Src *lbl_8045e99c[], *lbl_8045e9ac[];
extern "C" int fn_8035cb74(char *, const char *, ...);
extern char lbl_803b3310[];
struct Buf { char d[64]; char *get() { return d; } };
inline Text Label(const char *name) { Buf b; char *p = b.get(); fn_8035cb74(p, lbl_803b3310, name); return Text(p); }
struct Info { const char *name; char u4[32]; int f36; };
struct Row { Column *col[4]; };
extern "C" int w3d_d30k_stat_row_create_8020eec4(Row *self, Info *info) {
 if (info->f36) {
  self->col[0] = new Column(lbl_8045e99c[0]->f20);
  self->col[1] = new Column(lbl_8045e99c[1]->f20);
  self->col[2] = new Column(lbl_8045e99c[2]->f20);
  self->col[3] = new Column(lbl_8045e99c[3]->f20);
 } else {
  self->col[0] = new Column(lbl_8045e9ac[0]->f20);
  self->col[1] = new Column(lbl_8045e9ac[1]->f20);
  self->col[2] = new Column(lbl_8045e9ac[2]->f20);
  self->col[3] = new Column(lbl_8045e9ac[3]->f20);
 }
 Text s(Label(info->name));
 self->col[0]->Take(s);
 self->col[1]->Take(s);
 self->col[2]->Take(s);
 self->col[3]->Take(s);
 return 0;
}
