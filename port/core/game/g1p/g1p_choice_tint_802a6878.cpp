#include "w3d_ptr.h"
#line 1 "g1p_choice_tint_802a6878.cpp"
// Inferred external panel views. Complete RGBA locals occupy four bytes each.
struct Control{Ptr32<Ptr32<void>> table;};
struct Color{unsigned char r,g,b,a;Color(){}Color(unsigned x,unsigned y,unsigned z,unsigned w){r=x;g=y;b=z;a=w;}void set(unsigned x,unsigned y,unsigned z,unsigned w){r=x;g=y;b=z;a=w;}};
struct Secondary{char unknown0[148];int normal,kind,alternate;int active()const{return kind==1?alternate:normal;}};
struct Choice{char unknown0[140];int enabled;char unknown144[68];Ptr32<Control> left; Ptr32<Control> right; Ptr32<Control> other;char unknown224[12];Ptr32<Control> confirm;unsigned unknown240;Ptr32<Control> a; Ptr32<Control> b; Ptr32<Control> c; Ptr32<Control> d; Ptr32<Control> e; Ptr32<Control> f; Ptr32<Control> g; Ptr32<Control> h;};
extern "C" int fn_802a7980(Ptr32<Choice>),fn_802a7998(Ptr32<Choice>);
extern "C" Ptr32<Control> fn_8034357c(Ptr32<Control>);
extern "C" int fn_80173df0(Ptr32<Control>,Ptr32<const Color>);
inline void setEnabled(Ptr32<Control> p,int value){((Ptr32<void (Ptr32<Control>, int)>)p->table[22])(p,value);}
inline void enable(Ptr32<Control> p,int value){if(p)((Ptr32<void (Ptr32<Control>, int)>)p->table[22])(p,value);}
inline void tint(Ptr32<Control> p,const Color&value){if(p)fn_80173df0(p,&value);}
extern "C" void g1p_choice_tint_802a6878(Ptr32<Choice> p){
 int present=fn_802a7980(p),busy=fn_802a7998(p);
 enable(p->confirm,present);
 unsigned level=present==1?255:150;
 Color grey(level,level,level,255),shade;
 if(!p->enabled||busy){
  shade.set(200,150,200,255);
  enable(p->left,0);enable(p->right,0);enable(p->other,1);
 }else{
  shade.set(255,255,255,255);
  enable(p->other,0);
  if(p->left&&((Ptr32<Secondary>)((Ptr32<char>)p+28))->active()==0)setEnabled(p->left,1);
  if(p->right&&((Ptr32<Secondary>)((Ptr32<char>)p+28))->active()!=0)setEnabled(p->right,1);
 }
 if(p->left)fn_80173df0(fn_8034357c(p->left),&grey);
 tint(p->a,shade);tint(p->c,shade);tint(p->e,shade);tint(p->g,shade);
 if(p->right)fn_80173df0(fn_8034357c(p->right),&grey);
 tint(p->b,grey);tint(p->d,grey);tint(p->f,grey);tint(p->h,grey);
}


