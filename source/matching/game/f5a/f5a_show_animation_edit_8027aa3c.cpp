#define F(p,T,o) (*(T*)((char*)(p)+(o)))
extern "C" void fn_8020c5c4(void*);
extern "C" void fn_80341588(void*);
struct Text_803426b8{
 Text_803426b8(const Text_803426b8 &);char*p;Text_803426b8();~Text_803426b8(){fn_8020c5c4(this);fn_80341588(this);}};
extern "C" void fn_802cd26c(Text_803426b8*,int,int);
extern "C" void fn_802cc0ac(Text_803426b8*,const char*,int);
extern "C" void fn_8027a934(void*,int);
extern "C" void fn_802cd220(Text_803426b8*);
extern "C" void fn_802cd128(Text_803426b8*);
extern "C" void fn_802cbf2c(Text_803426b8*,const char*,int);
extern "C" void fn_802cd2e0(void*,int);
extern "C" void fn_802cbdf8(int,const char*,int);
extern "C" void fn_802cbf68(Text_803426b8*,int,int);
extern char title_803ce6d8[],line_803ce6f4[],empty_803cc0d8[],help_803ce850[];
extern char label_803ce710[];
extern char label_803ce730[];
extern char label_803ce750[];
extern char label_803ce770[];
extern char label_803ce790[];
extern char label_803ce7b0[];
extern char label_803ce7d0[];
extern char label_803ce7f0[];
extern char label_803ce810[];
extern char label_803ce830[];
extern "C" void w3d_f5a_show_animation_edit_8027aa3c(void*self){fn_8027a934(self,1);Text_803426b8 text;fn_802cd220(&text);fn_802cd128(&text);F(self,int,36)=29;
fn_802cbf2c(&text,title_803ce6d8,7);fn_802cbf2c(&text,line_803ce6f4,7);fn_802cbf2c(&text,empty_803cc0d8,9);
fn_802cc0ac(&text,label_803ce710,9);fn_802cbf68(&text,F(F(self,void*,92),int,112),9);
fn_802cc0ac(&text,label_803ce730,9);fn_802cbf68(&text,F(F(self,void*,92),int,108),9);
fn_802cc0ac(&text,label_803ce750,9);fn_802cbf2c(&text,F(F(self,void*,92),char*,104),9);
fn_802cc0ac(&text,label_803ce770,9);fn_802cbf2c(&text,F(F(self,void*,92),char*,100),9);
fn_802cc0ac(&text,label_803ce790,9);fn_802cbf2c(&text,F(F(self,void*,92),char*,96),9);
fn_802cc0ac(&text,label_803ce7b0,9);fn_802cbf2c(&text,F(F(self,void*,92),char*,92),9);
fn_802cc0ac(&text,label_803ce7d0,9);fn_802cbf2c(&text,F(F(self,void*,92),char*,56),9);
fn_802cc0ac(&text,label_803ce7f0,9);fn_802cbf2c(&text,F(F(self,void*,92),char*,52),9);
fn_802cc0ac(&text,label_803ce810,9);fn_802cbf2c(&text,F(F(self,void*,92),char*,48),9);
fn_802cc0ac(&text,label_803ce830,9);fn_802cbf2c(&text,F(F(self,void*,92),char*,44),9);
fn_802cd26c(&text,0,24);fn_802cc0ac(&text,help_803ce850,7);fn_802cbdf8((int)(F(self,void*,32)),text.p,9);}
