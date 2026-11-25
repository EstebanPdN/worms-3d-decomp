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
extern char title_803cc65c[],line_803ccb48[],empty_803cc0d8[],help_803cc8b4[],tips_803ccd1c[];
extern char label_803ccc9c[];
extern char label_803cccbc[];
extern char label_803cccdc[];
extern char label_803cccfc[];
extern char label_803ccd28[];
extern char label_803ccd48[];
extern char label_803ccd68[];
extern char label_803ccd88[];
extern char label_803ccda8[];
extern char label_803ccdc8[];
extern char label_803ccde8[];
extern "C" void w3d_f5a_show_wormpot_edit_80273560(void*self){
 fn_8027a934(self,1);Text_803426b8 text;fn_802cd220(&text);fn_802cd128(&text);F(self,int,36)=33;
 fn_802cbf2c(&text,title_803cc65c,7);fn_802cbf2c(&text,line_803ccb48,7);fn_802cbf2c(&text,empty_803cc0d8,9);
 void*target=F(self,void*,92);
 fn_802cc0ac(&text,label_803ccc9c,9);fn_802cbf2c(&text,F(target,char*,156),9);
 fn_802cc0ac(&text,label_803cccbc,9);fn_802cbf2c(&text,F(target,char*,152),9);
 fn_802cc0ac(&text,label_803cccdc,9);fn_802cbf2c(&text,F(target,char*,148),9);
 fn_802cc0ac(&text,label_803cccfc,9);fn_802cbf2c(&text,F(target,char*,144),9);
 fn_802cc0ac(&text,tips_803ccd1c,9);
 fn_802cc0ac(&text,label_803ccd28,9);fn_802cbf2c(&text,F(target,char*,140),9);
 fn_802cc0ac(&text,label_803ccd48,9);fn_802cbf2c(&text,F(target,char*,136),9);
 fn_802cc0ac(&text,label_803ccd68,9);fn_802cbf2c(&text,F(target,char*,132),9);
 fn_802cc0ac(&text,label_803ccd88,9);fn_802cbf2c(&text,F(target,char*,128),9);
 fn_802cc0ac(&text,label_803ccda8,9);fn_802cbf2c(&text,F(target,char*,124),9);
 fn_802cc0ac(&text,label_803ccdc8,9);fn_802cbf2c(&text,F(target,char*,120),9);
 fn_802cc0ac(&text,label_803ccde8,9);fn_802cbf2c(&text,F(target,char*,116),9);
 fn_802cd26c(&text,0,24);fn_802cc0ac(&text,help_803cc8b4,7);fn_802cbdf8((int)(F(self,void*,32)),text.p,9);
}
