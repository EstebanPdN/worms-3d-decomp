#include "w3d_ptr.h"
#line 1 "f5a_show_title_edit_80272e28.cpp"
#define F(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char*)w3d::AG(p)+(o)))
extern "C" void fn_8020c5c4(Ptr32<void>);
extern "C" void fn_80341588(Ptr32<void>);
struct Text_803426b8{
 Text_803426b8(const Text_803426b8 &);Ptr32<char> p;Text_803426b8();~Text_803426b8(){fn_8020c5c4(this);fn_80341588(this);}};
extern "C" void fn_802cd26c(Ptr32<Text_803426b8>,int,int);
extern "C" void fn_802cc0ac(Ptr32<Text_803426b8>,Ptr32<const char>,int);
extern "C" void fn_8027a934(Ptr32<void>,int);
extern "C" void fn_802cd220(Ptr32<Text_803426b8>);
extern "C" void fn_802cd128(Ptr32<Text_803426b8>);
extern "C" void fn_802cbf2c(Ptr32<Text_803426b8>,Ptr32<const char>,int);
extern "C" void fn_802cd2e0(Ptr32<void>,int);
extern "C" void fn_802cbdf8(int,Ptr32<const char>,int);
extern "C" void fn_8020c510(Ptr32<Text_803426b8>,Ptr32<const char>,...);
extern "C" void fn_802cbfa4(Ptr32<Text_803426b8>,float,int);
extern char title_803ccb38[],line_803ccb48[],empty_803cc0d8[],help_803cc8b4[],format_803ccbb8[],true_803cc864[],false_803cc86c[];
extern char label_803ccb58[];
extern char label_803ccb78[];
extern char label_803ccb98[];
extern char label_803ccbc4[];
extern char label_803ccbe4[];
extern char label_803ccc04[];
extern "C" void w3d_f5a_show_title_edit_80272e28(Ptr32<void> self){
 fn_8027a934(self,1);Text_803426b8 text,formatted;fn_802cd220(&text);fn_802cd128(&text);F(self,int,36)=6;
 fn_802cbf2c(&text,title_803ccb38,7);fn_802cbf2c(&text,line_803ccb48,7);fn_802cbf2c(&text,empty_803cc0d8,9);
 Ptr32<void> target=F(self,void*,92);
 fn_802cc0ac(&text,label_803ccb58,9);fn_802cbf2c(&text,F(target,char*,128),9);
 fn_802cc0ac(&text,label_803ccb78,9);fn_802cbf2c(&text,F(target,char*,124),9);
 fn_802cc0ac(&text,label_803ccb98,9);
 struct Color{unsigned char r,g,b,a;};Ptr32<Color> color=(Ptr32<Color>)((Ptr32<char>)target+120);
 fn_8020c510(&formatted,format_803ccbb8,color->r,color->g,color->b,color->a);fn_802cbf2c(&text,formatted.p,9);
 fn_802cc0ac(&text,label_803ccbc4,9);fn_802cbf2c(&text,F(target,int,136)==1?true_803cc864:false_803cc86c,9);
 fn_802cc0ac(&text,label_803ccbe4,9);fn_802cbf2c(&text,F(target,int,132)==1?true_803cc864:false_803cc86c,9);
 fn_802cc0ac(&text,label_803ccc04,9);fn_802cbfa4(&text,F(target,float,116),9);
 fn_802cd26c(&text,0,24);fn_802cc0ac(&text,help_803cc8b4,7);fn_802cbdf8((int)w3d::H((F(self,void*,32))),text.p,9);
}


