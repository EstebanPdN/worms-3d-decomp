#include "w3d_ptr.h"
#line 1 "f5a_show_accept_edit_80273054.cpp"
#define F(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char*)w3d::AG(p)+(o)))
extern "C" void fn_8020c5c4(Ptr32<void>);
extern "C" void fn_80341588(Ptr32<void>);
struct Text_803426b8{
 Text_803426b8(const Text_803426b8 &);Ptr32<char> p;Text_803426b8();~Text_803426b8(){fn_8020c5c4(this);fn_80341588(this);}};
extern char edit_803ccc24[],line_803ccc40[],empty_803cc0d8[],accept_803ccc5c[],cancel_803ccc7c[],help_803cc8b4[];
extern "C" void fn_802cd26c(Ptr32<Text_803426b8>,int,int);
extern "C" void fn_802cc0ac(Ptr32<Text_803426b8>,Ptr32<const char>,int);
extern "C" void fn_8027a934(Ptr32<void>,int);
extern "C" void fn_802cd220(Ptr32<Text_803426b8>);
extern "C" void fn_802cd128(Ptr32<Text_803426b8>);
extern "C" void fn_802cbf2c(Ptr32<Text_803426b8>,Ptr32<const char>,int);
extern "C" void fn_802cd2e0(Ptr32<void>,int);
extern "C" void fn_802cbdf8(int,Ptr32<const char>,int);
extern "C" void w3d_f5a_show_accept_edit_80273054(Ptr32<void> self){
 fn_8027a934(self,1);Text_803426b8 text;fn_802cd220(&text);fn_802cd128(&text);F(self,int,36)=7;
 fn_802cbf2c(&text,edit_803ccc24,7);fn_802cbf2c(&text,line_803ccc40,7);fn_802cbf2c(&text,empty_803cc0d8,9);
 Ptr32<void> target=F(self,void*,92);fn_802cc0ac(&text,accept_803ccc5c,9);fn_802cbf2c(&text,F(target,char*,120),9);fn_802cc0ac(&text,cancel_803ccc7c,9);fn_802cbf2c(&text,F(target,char*,116),9);
 fn_802cd26c(&text,0,24);fn_802cc0ac(&text,help_803cc8b4,7);fn_802cbdf8((int)w3d::H((F(self,void*,32))),text.p,9);
}


