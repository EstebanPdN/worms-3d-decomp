#define F(p,T,o) (*(T*)((char*)(p)+(o)))
extern "C" void fn_8020c5c4(void*);
extern "C" void fn_80341588(void*);
struct Text_803426b8{
 Text_803426b8(const Text_803426b8 &);char*p;Text_803426b8();~Text_803426b8(){fn_8020c5c4(this);fn_80341588(this);}};
extern char edit_803ce3b0[],line_803cd33c[],empty_803cc0d8[],old_803ce3c0[],new_803ce3d0[];
extern "C" void fn_802cc0ac(Text_803426b8*,const char*,int);
extern "C" void fn_8027a934(void*,int);
extern "C" void fn_802cd220(Text_803426b8*);
extern "C" void fn_802cd128(Text_803426b8*);
extern "C" void fn_802cbf2c(Text_803426b8*,const char*,int);
extern "C" void fn_802cd2e0(void*,int);
extern "C" void fn_802cbdf8(int,const char*,int);
extern "C" void w3d_f5a_show_name_edit_80276d14(void*self){
 Text_803426b8 text;fn_802cd220(&text);fn_802cd128(&text);
 fn_802cbf2c(&text,edit_803ce3b0,7);fn_802cbf2c(&text,line_803cd33c,7);fn_802cbf2c(&text,empty_803cc0d8,9);
 fn_802cc0ac(&text,old_803ce3c0,9);fn_802cbf2c(&text,F(F(self,void*,88),char*,28),9);fn_802cc0ac(&text,new_803ce3d0,9);
 fn_8027a934(self,0);F(self,int,36)=34;fn_802cbdf8((int)(F(self,void*,32)),text.p,9);
}
