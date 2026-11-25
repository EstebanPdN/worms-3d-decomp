#include "w3d_ptr.h"
#line 1 "d26l_base_menu_item_ctor_802afb20.cpp"
// GWMP8P rev0 0x802afb20. Constructor of the class behind the property name
// BaseMenuItem.RefCount, written as a plain function over a partial view.
// The vtable pointer at +180 is witnessed by the store; the other field
// names only record their offsets.
struct Str{Ptr32<char> p;Str();Str(const Str&);};
extern Ptr32<void> vt_8041c610[];
struct Key{Ptr32<const char> name;template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((const char *)w3d_p.get()) {}
 Key(const char*n):name(n){}};
extern "C" int fn_800fc1b0(const Key&,Ptr32<void>);
extern "C" void fn_802aff04(Ptr32<void>);
struct Item{int w0,w4;int t[18];Str name;int w84,w88,w92,w96,w100,w104,w108,w112,w116,w120,w124,w128,w132;float f136,f140,f144;int w148,w152,w156,w160,w164,w168;float f172;int w176;Ptr32<Ptr32<void>> vt;};
inline void*operator new(__SIZE_TYPE__,void*p){return p;}
extern "C" Ptr32<Item> d26l_base_menu_item_ctor_802afb20(Ptr32<Item> s){
 int z=0;
 s->t[0]=z;s->t[1]=z;s->t[2]=z;s->t[3]=z;s->t[4]=z;s->t[5]=z;s->t[6]=z;s->t[7]=z;s->t[8]=z;s->t[9]=z;s->t[10]=z;s->t[11]=z;s->t[12]=z;s->t[13]=z;s->t[14]=z;s->t[15]=z;s->t[16]=z;s->t[17]=z;
 s->vt=vt_8041c610;
 new(&s->name)Str;
 s->f172=0.0f; s->f144=-0.005f; s->f140=0.0f; s->w84=z; s->w88=z; s->w132=z; s->w176=z; s->w148=z; s->w152=z; s->w156=z; s->w160=z; s->w96=z; s->w164=z; s->w100=z; s->w104=z; s->w108=z; s->w116=z; s->w120=z; s->w124=z; s->w0=z; s->w4=z; s->w112=1; s->f136=0.0f; s->w128=1;
 fn_800fc1b0(Key("BaseMenuItem.RefCount"),&s->w176);
 fn_802aff04(s);
 return s;
}


