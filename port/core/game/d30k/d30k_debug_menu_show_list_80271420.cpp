#include "w3d_ptr.h"
#line 1 "d30k_debug_menu_show_list_80271420.cpp"
// GWMP8P rev0 0x80271420. Debug text menu: builds the fixed help text from
// the null-terminated table at 0x804012fc, writes it to the console sink and
// clears the two held interfaces. Names are inferred from use.
struct Obj;
struct ObjVt { Ptr32<void> u[4]; Ptr32<void (Ptr32<Obj>)> release; };
struct Obj { Ptr32<ObjVt> vt; };
struct Held { Ptr32<Obj> p; template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Obj *)w3d_p.get()); }
 void operator=(Obj *n) { if (p) p->vt->release(p); p = n; } };
struct Text;
extern "C" void fn_8020c5c4(Ptr32<Text>);
extern "C" void fn_80341588(Ptr32<Text>);
struct Text { Ptr32<char> p; Text(); Text(const Text &); ~Text() { fn_8020c5c4(this); fn_80341588(this); } };
struct Menu;
extern "C" void fn_8027a934(Ptr32<Menu>, int);
extern "C" void fn_802cd220(Ptr32<Text>);
extern "C" void fn_802cd128(Ptr32<Text>);
extern "C" void fn_802cbf2c(Ptr32<Text>, Ptr32<const char>, int);
extern "C" void fn_802cd2e0(int, int);
extern "C" void fn_802cbdf8(int, Ptr32<char>, int);
extern Ptr32<const char> lbl_804012fc[];
struct Menu { char u[32]; Ptr32<void> sink; int f36; char u40[48]; Held f88; Held f92; };
extern "C" void w3d_d30k_debug_menu_show_list_80271420(Ptr32<Menu> self) {
 fn_8027a934(self, 1);
 Text s;
 fn_802cd220(&s);
 fn_802cd128(&s);
 self->f36 = 0;
 for (int i = 0; lbl_804012fc[i]; i++) fn_802cbf2c(&s, lbl_804012fc[i], 7);
 fn_802cd2e0((int)w3d::H(self->sink), 0);
 fn_802cbdf8((int)w3d::H(self->sink), s.p, 9);
 self->f88 = 0;
 self->f92 = 0;
}


