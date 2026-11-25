// GWMP8P rev0 0x80271420. Debug text menu: builds the fixed help text from
// the null-terminated table at 0x804012fc, writes it to the console sink and
// clears the two held interfaces. Names are inferred from use.
struct Obj;
struct ObjVt { void *u[4]; void (*release)(Obj *); };
struct Obj { ObjVt *vt; };
struct Held { Obj *p; void operator=(Obj *n) { if (p) p->vt->release(p); p = n; } };
struct Text;
extern "C" void fn_8020c5c4(Text *);
extern "C" void fn_80341588(Text *);
struct Text { char *p; Text(); Text(const Text &); ~Text() { fn_8020c5c4(this); fn_80341588(this); } };
struct Menu;
extern "C" void fn_8027a934(Menu *, int);
extern "C" void fn_802cd220(Text *);
extern "C" void fn_802cd128(Text *);
extern "C" void fn_802cbf2c(Text *, const char *, int);
extern "C" void fn_802cd2e0(int, int);
extern "C" void fn_802cbdf8(int, char *, int);
extern const char *lbl_804012fc[];
struct Menu { char u[32]; void *sink; int f36; char u40[48]; Held f88; Held f92; };
extern "C" void w3d_d30k_debug_menu_show_list_80271420(Menu *self) {
 fn_8027a934(self, 1);
 Text s;
 fn_802cd220(&s);
 fn_802cd128(&s);
 self->f36 = 0;
 for (int i = 0; lbl_804012fc[i]; i++) fn_802cbf2c(&s, lbl_804012fc[i], 7);
 fn_802cd2e0((int)self->sink, 0);
 fn_802cbdf8((int)self->sink, s.p, 9);
 self->f88 = 0;
 self->f92 = 0;
}
