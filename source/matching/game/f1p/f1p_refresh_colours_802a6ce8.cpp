// Partial field view and colour roles inferred from observed byte operations.
#define F(p,T,o) (*(T*)((char*)(p)+(o)))
struct Colour{unsigned char r,g,b,a;void set(unsigned char x,unsigned char y,unsigned char z,unsigned char w){r=x;g=y;b=z;a=w;}};
extern "C" int fn_802a7998(void*);
extern "C" void*fn_8034357c(void*);
extern "C" int fn_80173df0(void*,const Colour*);
inline void enable(void*p,int value){((void(*)(void*,int))(*(void***)p)[22])(p,value);}
extern "C" void w3d_refresh_colours_802a6ce8(void*self){if(F(self,void*,276)){Colour c;for(int i=0;i<8;++i){int selected=F(self,int,616);if(i>=selected||F(self,unsigned,584)<=F(self,unsigned,600)){if(!F(self,int,140)||fn_802a7998(self))c.set(122,122,122,255);else c=F(self,Colour,340);}else if(F(self,int,620)==4)c=F(self,Colour,304+selected*8);else if(selected!=-1)c=F(self,Colour,304+selected*4);else c=F(self,Colour,336);if(F(self,int,616)==-1){if(F(self,void*,232))enable(F(self,void*,232),1);c=F(self,Colour,336);}else if(F(self,void*,232))enable(F(self,void*,232),0);fn_80173df0(fn_8034357c(F(self,void*,276+i*4)),&c);}}}
