#define F(p,T,o) (*(T*)((char*)(p)+(o)))
extern "C" void fn_8020c5c4(void*),fn_80341588(void*);
struct G2aBoxText_8020bb54 {char*p;G2aBoxText_8020bb54(const char*);~G2aBoxText_8020bb54(){fn_8020c5c4(this);fn_80341588(this);}};
struct G2aBoxKey{const char*p;G2aBoxKey(const char*s):p(s){}};
struct G2aBoxHeld{void*p;G2aBoxHeld():p(0){}~G2aBoxHeld(){if(p)(*(void(***)(void*))(p))[4](p);}};
struct G2aBoxVector{float x,y,z;G2aBoxVector(float a,float b,float c):x(a),y(b),z(c){}};
extern "C" int fn_8015adf4(const G2aBoxText_8020bb54*,void*,unsigned char),fn_800fc1b0(const G2aBoxKey&,G2aBoxHeld*);
extern "C" void*fn_80342a74(void*);
extern "C" float fn_80178df0(void*);
extern "C" void fn_80295cec(void*);
extern const char background_803d0798[],border_803d07a0[];
extern const float zero_803d07b4[],two_803d07b8[],half_803d07bc[];
inline void assignBox(void*&old,void*next){if(next)(*(void(***)(void*))(next))[3](next);if(old)(*(void(***)(void*))(old))[4](old);old=next;}
extern "C" void w3d_g2a_setup_box_80295268(void*self,G2aBoxHeld parent){
 F(self,int,56)=1;
 {G2aBoxText_8020bb54 text(background_803d0798);fn_8015adf4(&text,(char*)self+124,255);}
 {G2aBoxVector size(zero_803d07b4[0],zero_803d07b4[0],zero_803d07b4[0]);void*p=F(self,void*,124);(*(void(***)(void*,const G2aBoxVector&,int))(p))[21](p,size,0);}
 void*p=F(self,void*,124);void*owner=F(self,void*,124);(*(void(***)(void*,const void*,int))(p))[19](p,(char*)self+32,0);
 assignBox(F(self,void*,120),parent.p);p=F(self,void*,120);(*(void(***)(void*,void*,int))(p))[23](p,F(self,void*,124),0);
 G2aBoxHeld held;fn_800fc1b0(G2aBoxKey(border_803d07a0),&held);assignBox(F(self,void*,156),fn_80342a74(held.p));
 float value=fn_80178df0(F(self,void*,156));float scale=two_803d07b8[0];F(self,float,168)=value*scale;
 value=fn_80178df0(F(self,void*,156));float half=half_803d07bc[0];F(self,float,164)=value*scale;F(self,float,160)=F(self,float,168)*half;
 fn_80295cec(self);
}
