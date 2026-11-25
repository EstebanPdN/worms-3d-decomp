#include "w3d_ptr.h"
#line 1 "cc18a_cursor_inline_sinit_8004e690.cpp"
inline void *operator new(__SIZE_TYPE__,void*p){return p;}
struct Cc18aColor { signed char r,g,b,a; Cc18aColor(int R,int G,int B,int A){r=R;g=G;b=B;a=A;} };
struct Cc18aCachedName { unsigned int state; Ptr32<const char> text; };
extern Cc18aColor lbl_804ad454,lbl_804ad458,lbl_804ad45c;
extern "C" Ptr32<void> fn_8015f518(Ptr32<Cc18aCachedName>,Ptr32<const char>);
extern "C" Ptr32<void> fn_80160038(Ptr32<void>,Ptr32<void>,Ptr32<void>,Ptr32<void>,int,int);
extern "C" char lbl_803600f0[],lbl_803e7a94[],lbl_803617d0[];
extern "C" Ptr32<void> fn_8004da40();
extern "C" Cc18aCachedName lbl_804ad424;
extern "C" const char lbl_803777d0[];
extern "C" Cc18aCachedName lbl_804ad42c;
extern "C" const char lbl_803777e4[];
extern "C" Cc18aCachedName lbl_804ad434;
extern "C" const char lbl_803777fc[];
extern "C" Cc18aCachedName lbl_804ad43c;
extern "C" const char lbl_8037781c[];
extern "C" Cc18aCachedName lbl_804ad444;
extern "C" const char lbl_80377834[];
extern "C" Cc18aCachedName lbl_804ad44c;
extern "C" const char lbl_80377848[];
static inline void color(signed char g,signed char b,signed char r) {lbl_804ad454.r=r;lbl_804ad454.g=g;lbl_804ad454.b=b;}
extern "C" void w3d_cc18a_cursor_inline_sinit_8004e690(int init,int priority){if(priority==0xffff && init){
fn_8015f518(&lbl_804ad424,lbl_803777d0);
fn_8015f518(&lbl_804ad42c,lbl_803777e4);
fn_8015f518(&lbl_804ad434,lbl_803777fc);
fn_8015f518(&lbl_804ad43c,lbl_8037781c);
fn_8015f518(&lbl_804ad444,lbl_80377834);
fn_8015f518(&lbl_804ad44c,lbl_80377848);



color(32,0,-41);
lbl_804ad454.a=255;
lbl_804ad458.r=255;
lbl_804ad458.g=255;
lbl_804ad458.b=255;
lbl_804ad458.a=255;
lbl_804ad45c.r=98;
lbl_804ad45c.g=168;
lbl_804ad45c.b=255;
lbl_804ad45c.a=255;
fn_80160038(lbl_803600f0,lbl_803e7a94,lbl_803617d0,(Ptr32<void>)fn_8004da40,9,0);
}}


