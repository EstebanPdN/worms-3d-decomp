// Native editor locals: four-byte String, 28-byte reader, eight-byte descriptor.
// External editor and property objects are pointer views, never constructed here.
#define F(p,T,o) (*(T*)((char*)(p)+(o)))
extern "C" void fn_8020c5c4(void*),fn_80341588(void*),fn_8020d318(void*,void*),fn_8020d36c(void*,int);
extern "C" unsigned short fn_8020d2b8(void*);
struct G3aText_803426b8{char*p;G3aText_803426b8();~G3aText_803426b8(){fn_8020c5c4(this);fn_80341588(this);}};
struct G3aReader{void**vtable;unsigned short refs,tag;unsigned state;void*first;void*second;G3aText_803426b8*text;unsigned cursor;G3aReader(G3aText_803426b8&t){fn_8020d318(this,&t);}~G3aReader(){fn_8020d36c(this,2);}};
struct G3aDescriptor{G3aReader*p;unsigned type:7;unsigned flag:1;unsigned size:8;unsigned format:5;unsigned tail:11;
 G3aDescriptor(G3aReader&r):p(&r){((void(*)(void*))p->vtable[3])(p);type=10;flag=0;size=0;format=6;fn_8020d2b8(&r);}
 ~G3aDescriptor(){if(p)((void(*)(void*))p->vtable[4])(p);}};
extern "C" void fn_8027a934(void*,int),fn_802cd220(G3aText_803426b8*),fn_802cd128(G3aText_803426b8*),fn_802cbf2c(G3aText_803426b8*,const char*,int),fn_802cc0ac(G3aText_803426b8*,const char*,int),fn_802cd26c(G3aText_803426b8*,int,int),fn_802cbdf8(void*,const char*,int);
extern "C" void*fn_801e9db8(void*,int);
extern const char title_803cd184[],line_803cd198[],empty_803cc0d8[],highlight_803cd1ac[],selected_803cd1cc[],colour_803cd1ec[],help_803cc8b4[];
extern "C" void w3d_g3a_scroll_editor_8027410c(void*self){
 fn_8027a934(self,1);G3aText_803426b8 text;fn_802cd220(&text);fn_802cd128(&text);F(self,int,36)=9;
 fn_802cbf2c(&text,title_803cd184,7);fn_802cbf2c(&text,line_803cd198,7);fn_802cbf2c(&text,empty_803cc0d8,9);
 void*target=F(self,void*,92);fn_802cc0ac(&text,highlight_803cd1ac,9);fn_802cbf2c(&text,F(target,const char*,124),9);fn_802cc0ac(&text,selected_803cd1cc,9);fn_802cbf2c(&text,F(target,const char*,120),9);fn_802cc0ac(&text,colour_803cd1ec,9);
 G3aText_803426b8 colour;G3aReader reader(colour);G3aDescriptor descriptor(reader);
 void*property=fn_801e9db8((*(void*(***)(void*))(target))[5](target),22);
 (*(void(***)(void*,G3aDescriptor*,void*))((char*)property+4))[5](property,&descriptor,target);
 fn_802cbf2c(&text,colour.p,9);fn_802cd26c(&text,0,24);fn_802cc0ac(&text,help_803cc8b4,7);fn_802cbdf8(F(self,void*,32),text.p,9);
}
