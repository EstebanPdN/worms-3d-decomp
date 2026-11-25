#define F(p,T,o) (*(T*)((char*)(p)+(o)))
extern "C" void fn_8020c5c4(void*);
extern "C" void fn_80341588(void*);
struct Text_803426b8{
 Text_803426b8(const Text_803426b8 &);char*p;Text_803426b8();~Text_803426b8(){fn_8020c5c4(this);fn_80341588(this);}};
extern char edit_803cca90[],line_803ccaa4[],empty_803cc0d8[],gfx_803ccab8[],disabled_803ccad8[],help_803cc8b4[],incoming_803ccaf8[],outgoing_803ccb18[];
extern "C" void fn_802cd26c(Text_803426b8*,int,int);
extern "C" void fn_802cc0ac(Text_803426b8*,const char*,int);
extern "C" void fn_8027a934(void*,int);
extern "C" void fn_802cd220(Text_803426b8*);
extern "C" void fn_802cd128(Text_803426b8*);
extern "C" void fn_802cbf2c(Text_803426b8*,const char*,int);
extern "C" void fn_802cd2e0(void*,int);
extern "C" void fn_802cbdf8(int,const char*,int);
extern "C" void w3d_f5a_show_picture_edit_80272cc0(void*self){
 fn_8027a934(self,1);Text_803426b8 text;fn_802cd220(&text);fn_802cd128(&text);F(self,int,36)=5;
 fn_802cbf2c(&text,edit_803cca90,7);fn_802cbf2c(&text,line_803ccaa4,7);fn_802cbf2c(&text,empty_803cc0d8,9);
 void*target=F(self,void*,92);fn_802cc0ac(&text,gfx_803ccab8,9);fn_802cbf2c(&text,F(target,char*,128),9);fn_802cc0ac(&text,disabled_803ccad8,9);fn_802cbf2c(&text,F(target,char*,124),9);
 fn_802cc0ac(&text,incoming_803ccaf8,9);fn_802cbf2c(&text,F(target,char*,120),9);fn_802cc0ac(&text,outgoing_803ccb18,9);fn_802cbf2c(&text,F(target,char*,116),9);
 fn_802cd26c(&text,0,24);fn_802cc0ac(&text,help_803cc8b4,7);fn_802cbdf8((int)(F(self,void*,32)),text.p,9);
}
