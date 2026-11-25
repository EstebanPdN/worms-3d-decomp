#include "w3d_ptr.h"
#line 1 "f5a_show_name_edit_80276d14.cpp"
#define F(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char*)w3d::AG(p)+(o)))
extern "C" void fn_8020c5c4(Ptr32<void>);
extern "C" void fn_80341588(Ptr32<void>);
struct Text_803426b8{
 Text_803426b8(const Text_803426b8 &);Ptr32<char> p;Text_803426b8();~Text_803426b8(){fn_8020c5c4(this);fn_80341588(this);}};
extern char edit_803ce3b0[],line_803cd33c[],empty_803cc0d8[],old_803ce3c0[],new_803ce3d0[];
extern "C" void fn_802cc0ac(Ptr32<Text_803426b8>,Ptr32<const char>,int);
extern "C" void fn_8027a934(Ptr32<void>,int);
extern "C" void fn_802cd220(Ptr32<Text_803426b8>);
extern "C" void fn_802cd128(Ptr32<Text_803426b8>);
extern "C" void fn_802cbf2c(Ptr32<Text_803426b8>,Ptr32<const char>,int);
extern "C" void fn_802cd2e0(Ptr32<void>,int);
extern "C" void fn_802cbdf8(int,Ptr32<const char>,int);
extern "C" void w3d_f5a_show_name_edit_80276d14(Ptr32<void> self){
 Text_803426b8 text;fn_802cd220(&text);fn_802cd128(&text);
 fn_802cbf2c(&text,edit_803ce3b0,7);fn_802cbf2c(&text,line_803cd33c,7);fn_802cbf2c(&text,empty_803cc0d8,9);
 fn_802cc0ac(&text,old_803ce3c0,9);fn_802cbf2c(&text,F(F(self,void*,88),char*,28),9);fn_802cc0ac(&text,new_803ce3d0,9);
 fn_8027a934(self,0);F(self,int,36)=34;fn_802cbdf8((int)w3d::H((F(self,void*,32))),text.p,9);
}


