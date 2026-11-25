// Inferred editor view; only the native four-byte shared-string value is constructed.
#define F(p,T,o) (*(T*)((char*)(p)+(o)))
extern "C" void fn_8020c5c4(void*),fn_80341588(void*);
struct G2aText_803426b8 {char*p;G2aText_803426b8();unsigned length()const{return *(unsigned short*)(p-4); }~G2aText_803426b8(){fn_8020c5c4(this);fn_80341588(this);}};
extern "C" void fn_802cd26c(G2aText_803426b8*,int,int),fn_802cc0ac(G2aText_803426b8*,const char*,int),fn_802cbdf8(int,const char*,int),fn_8027a934(void*,int),fn_8027ae00(void*);
extern "C" void*fn_801e9db8(void*,int);
extern const char red_803ce608[],green_803ce628[],blue_803ce648[],alpha_803ce668[];
extern "C" void w3d_g2a_colour_key_80279bd8(void*self,int key){
 G2aText_803426b8 text;
 void*p=F(self,void*,92);fn_801e9db8((*(void*(***)(void*))(p))[5](p),F(self,int,96));
 switch(key){
 case 'R':case 'r':fn_802cd26c(&text,0,4);fn_802cc0ac(&text,red_803ce608,7);fn_802cd26c(&text,9,4);F(self,int,48)=0;fn_8027a934(self,0);break;
 case 'G':case 'g':fn_802cd26c(&text,0,5);fn_802cc0ac(&text,green_803ce628,7);fn_802cd26c(&text,9,5);F(self,int,48)=1;fn_8027a934(self,0);break;
 case 'B':case 'b':fn_802cd26c(&text,0,6);fn_802cc0ac(&text,blue_803ce648,7);fn_802cd26c(&text,9,6);F(self,int,48)=2;fn_8027a934(self,0);break;
 case 'A':case 'a':fn_802cd26c(&text,0,7);fn_802cc0ac(&text,alpha_803ce668,7);fn_802cd26c(&text,9,7);F(self,int,48)=3;fn_8027a934(self,0);break;
 case 27:fn_8027ae00(self);break;
 }
 if(text.length())fn_802cbdf8((int)(F(self,void*,32)),text.p,9);
}
