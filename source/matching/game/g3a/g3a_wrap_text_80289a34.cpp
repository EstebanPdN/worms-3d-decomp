// Text layout uses complete Vec3, four-byte strings and four-byte retained handles.
// The outer card UI and returned line records remain external views.
#define F(p,T,o) (*(T*)((char*)(p)+(o)))
extern "C" void fn_8020c5c4(void*),fn_80341588(void*);
struct G3aFontName_8020bb54{char*p;G3aFontName_8020bb54(const char*);~G3aFontName_8020bb54(){fn_8020c5c4(this);fn_80341588(this);}};
struct G3aFontHeld{void*p;G3aFontHeld():p(0){}~G3aFontHeld(){if(p)(*(void(***)(void*))(p))[4](p);}void assign(void*n){if(n)(*(void(***)(void*))(n))[3](n);if(p)(*(void(***)(void*))(p))[4](p);p=n;}};
struct G3aFontVec{float x,y,z;G3aFontVec(float a,float b,float c):x(a),y(b),z(c){}};
extern "C" void fn_8015adf4(G3aFontName_8020bb54*,G3aFontHeld*,int),fn_8018c5b0(void*,const char*);
extern "C" void*fn_80343580(void*),*fn_80289d2c(void*);
extern "C" float fn_8018c938(void*,int,int);
extern char font_803cf9f4[];extern const float size_803cfa24[],zero_803cfa28[],height_803cfa2c[],width_803cfa30[],half_803cfa40[];
extern "C" void w3d_g3a_wrap_text_80289a34(void*self,const char*text,int layer){
 G3aFontVec size(size_803cfa24[0],size_803cfa24[0],zero_803cfa28[0]);G3aFontHeld font;
 {G3aFontName_8020bb54 name(font_803cf9f4);G3aFontHeld found;fn_8015adf4(&name,&found,layer);font.assign(fn_80343580(found.p));}
 (*(void(***)(void*,G3aFontVec*,int))(font.p))[21](font.p,&size,0);fn_8018c5b0(font.p,text);
 int index=0;void*line=fn_80289d2c(self);F(line,const char*,16)=text;
 for(const char*p=text;*p;++p,++index){
 if(*p=='\n'){line=fn_80289d2c(self);F(line,const char*,16)=p+1;F(line,float,4)+=height_803cfa2c[0];}
 else{bool append=true;if(*p==' '){float word=zero_803cfa28[0];const char*q=p+1;while(*q!=' '&&*q&&*q!='\n'){word+=fn_8018c938(font.p,index,1);++q;}
 if(F(line,float,8)+word>width_803cfa30[0]){append=false;line=fn_80289d2c(self);F(line,const char*,16)=p+1;F(line,float,4)+=height_803cfa2c[0];}}
 if(append){float advance=fn_8018c938(font.p,index,1);++F(line,int,12);F(line,float,8)+=advance;}}
 }
 float step=height_803cfa2c[0];float y=(float)F(self,unsigned,956)*half_803cfa40[0]*step;
 for(unsigned i=0;i<F(self,unsigned,956);++i){F(self,float,716+i*20)=y;y-=step;}
}
