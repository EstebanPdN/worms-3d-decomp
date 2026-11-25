#define F(p,T,o) (*(T*)((char*)(p)+(o)))
struct G2aGaugeKey{const char*p;G2aGaugeKey(const char*s):p(s){}};
struct G2aGaugeHeld{void*p;G2aGaugeHeld():p(0){}~G2aGaugeHeld(){if(p)(*(void(***)(void*))(p))[4](p);}};
extern "C" void*fn_80165254(),*fn_80342a74(void*);
extern "C" float fn_80178df0(void*);
extern "C" int fn_800fc1b0(const G2aGaugeKey&,void*);
extern "C" void fn_802b0b84(void*,void*,unsigned),fn_802663dc(void*),fn_802672cc(void*),fn_802683b8(float,void*),fn_80268568(void*,int),fn_80162024(void*,const unsigned short*,void*),fn_800fd62c(void*,void*,void*,void*),fn_8026836c();
extern "C" unsigned short fn_8015f5a0(void*,int);
extern const char border_803cb5a0[];
extern const float two_803cb5b4[],low_803cb5b8[],high_803cb5bc[],default_803cb5c0[];
extern char action_804b0aac[],action_804b0ab4[];
extern void*instance_804b1788;
inline const float& gaugeMax(const float&a,const float&b){return a<b?b:a;}
inline const float& gaugeMin(const float&a,const float&b){return b<a?b:a;}
extern "C" void w3d_g2a_setup_gauge_80265d34(void*self){
 void*engine=fn_80165254();fn_802b0b84((char*)self+28,self,F(engine,unsigned,52));
 void*context=F(self,void*,40);G2aGaugeHeld held;F(self,unsigned,436)=F(context,unsigned,152);
 fn_800fc1b0(G2aGaugeKey(border_803cb5a0),&held);
 F(self,float,556)=fn_80178df0(fn_80342a74(held.p));F(self,float,560)=fn_80178df0(fn_80342a74(held.p))*two_803cb5b4[0];
 float low=low_803cb5b8[0];F(self,float,540)=F(context,float,128);F(self,float,544)=F(context,float,124);float high=high_803cb5bc[0];
 F(self,float,540)=gaugeMax(F(self,float,540),low);F(context,float,128)=F(self,float,540);
 F(self,float,544)=gaugeMin(F(self,float,544),high);F(context,float,124)=F(self,float,544);
 F(self,float,552)=F(self,float,540);F(self,float,548)=F(self,float,540);
 fn_802663dc(self);F(self,int,176)=1;(*(void(***)(void*,int))((char*)self+208))[5]((char*)self+28,0);
 F(self,unsigned,432)=F(context,unsigned,156);fn_802672cc(self);float value=default_803cb5c0[0];
 if(*(unsigned short*)(F(context,char*,120)-4)){
 if(fn_800fc1b0(G2aGaugeKey(F(context,const char*,120)),(char*)self+732)>=0){fn_800fd62c((char*)context+120,(void*)fn_8026836c,self,(char*)self+564);value=fn_80178df0(fn_80342a74(F(self,void*,732)));}}
 if(*(unsigned short*)(F(context,char*,116)-4)){void*p=F(instance_804b1788,void*,108);if(p)(*(void(***)(void*,const char*,void*))(p))[23](p,F(context,const char*,116),(char*)self+728);}
 fn_802683b8(value,self);void*p=F(self,void*,728);if(p)(*(void(***)(void*))(p))[5](p);
 unsigned short first=fn_8015f5a0(action_804b0aac,1);fn_80162024(self,&first,(char*)self+696);
 unsigned short second=fn_8015f5a0(action_804b0ab4,1);fn_80162024(self,&second,(char*)self+700);
 fn_80268568(self,0);engine=fn_80165254();F(self,unsigned,492)=F(engine,unsigned,52);
}
