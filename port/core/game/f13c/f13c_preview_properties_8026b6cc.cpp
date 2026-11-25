#include "w3d_ptr.h"
#line 1 "f13c_preview_properties_8026b6cc.cpp"
// Partial editor data-selection and shared-string ownership views.
#define F(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char*)w3d::AG(p)+(o)))
extern "C" void fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>),fn_8020c5c0(Ptr32<void>),fn_8020bb2c(Ptr32<void>);
extern "C" Ptr32<unsigned short> fn_80341884(Ptr32<void>);
struct F13cSelectHeader {unsigned short refs,length,capacity;void release(){if(!--refs)fn_8020bb2c(this);}};
struct F13cSelectText {
 F13cSelectText(const F13cSelectText &); F13cSelectText() {}Ptr32<char> p;~F13cSelectText(){fn_8020c5c4(this);fn_80341588(this);}unsigned length()const{return *(Ptr32<unsigned short>)(p-4);}void assign(const F13cSelectText&s){++((Ptr32<F13cSelectHeader>)(s.p-6))->refs;((Ptr32<F13cSelectHeader>)(p-6))->release();p=s.p;}};
struct F13cSelectFrom_8020bb54:F13cSelectText{template <class W3dU> F13cSelectFrom_8020bb54(Ptr32<W3dU> w3d_p) : F13cSelectFrom_8020bb54((const char *)w3d_p.get()) {}
 F13cSelectFrom_8020bb54(const char*);};
struct F13cSelectCopy:F13cSelectText{F13cSelectCopy(const F13cSelectText&s){fn_8020c5c0(this);p=s.p;++*fn_80341884(this);}};
struct F13cSelectHeld{Ptr32<void> p;F13cSelectHeld():p(0){}~F13cSelectHeld(){if(p)(*(Ptr32<Ptr32<Ptr32<void (Ptr32<void>)>>>)(p))[4](p);}};
struct F13cSelectKey{Ptr32<const char> p;template <class W3dU> F13cSelectKey(Ptr32<W3dU> w3d_p) : F13cSelectKey((const char *)w3d_p.get()) {}
 F13cSelectKey(const char*s):p(s){}};
extern "C" int fn_800fc1b0(const F13cSelectKey&,Ptr32<F13cSelectHeld>),fn_802ef234(Ptr32<const char>,Ptr32<const char>);
extern "C" Ptr32<void> fn_80343744(Ptr32<void>); Ptr32<void> fn_80341584(Ptr32<void>); Ptr32<void> fn_801797b4(Ptr32<void>);
extern "C" Ptr32<F13cSelectText> fn_80179170(Ptr32<void>);
extern "C" void fn_8020c510(Ptr32<void>,Ptr32<const char>,...),fn_8026c0d0(Ptr32<void>,int),fn_8026b9bc(Ptr32<void>),fn_8026a048(Ptr32<void>),fn_8026d8a0(Ptr32<void>),fn_8026b6cc(Ptr32<void>),fn_8026c4dc(Ptr32<void>,int);
extern const char empty_803cba1c[],random_803cba20[],error_803cb850[],type_803667a8[];
extern Ptr32<void> instance_804abb7c;
inline bool isType(Ptr32<void> p,Ptr32<const void> target){while(p!=target){Ptr32<void> next=F(p,void*,20);if(p==next)return false;p=next;}return true;}

struct F13cSelectDefault_803426b8:F13cSelectText{F13cSelectDefault_803426b8();};
struct F13cPreviewSize{float x,y,z;F13cPreviewSize(float a,float b,float c):x(a),y(b),z(c){}};
extern const char suffix_803cba58[],mission_803cba60[],border_803cba00[],missing_803cbaa8[],info_803cbacc[];
extern const float zero_803cbad8[],two_803cbadc[];
extern "C" Ptr32<F13cSelectText> fn_8020bd38(Ptr32<F13cSelectText>,Ptr32<const char>);
extern "C" void fn_8020c2e8(Ptr32<void>);
extern "C" unsigned fn_802ef9c0(Ptr32<const char>);
extern "C" Ptr32<void> fn_80342a74(Ptr32<void>); Ptr32<void> fn_8034357c(Ptr32<void>); Ptr32<void> fn_80343808(Ptr32<void>);
extern "C" float fn_80178df0(Ptr32<void>);
extern "C" int fn_8015adf4(Ptr32<F13cSelectText>,Ptr32<void>,unsigned char),fn_801712c4(Ptr32<void>,Ptr32<const char>);
extern "C" void fn_8026d8e8(Ptr32<void>,int);
extern "C" void w3d_f13c_preview_properties_8026b6cc(Ptr32<void> self){
 fn_8026d8e8(instance_804abb7c,0);
 F13cSelectDefault_803426b8 name;name.assign(F(self,F13cSelectText,428));
 int image=0;F13cSelectCopy upper(name);fn_8020c2e8(&upper);
 Ptr32<const char> text=upper.p;unsigned length=fn_802ef9c0(text);if(length>4)image=fn_802ef234(text+length-4,suffix_803cba58)==0;
 if(!name.length()||image==1)fn_8020bd38(&name,mission_803cba60);
 Ptr32<void> p=F(self,void*,284);(*(Ptr32<Ptr32<Ptr32<void (Ptr32<void>, int)>>>)(p))[22](p,0);
 F13cSelectHeld held;Ptr32<void> context=F(self,void*,40);
 F13cPreviewSize size(F(context,float,20),F(context,float,24),zero_803cbad8[0]);
 fn_800fc1b0(F13cSelectKey(border_803cba00),&held);float thickness=fn_80178df0(fn_80342a74(held.p));
 size.x-=thickness*two_803cbadc[0];size.y-=thickness*two_803cbadc[0];
 if(F(self,void*,216)){p=F(self,void*,112);(*(Ptr32<Ptr32<Ptr32<void (Ptr32<void>, Ptr32<void>)>>>)(p))[24](p,F(self,void*,216));p=F(self,void*,216);if(p)(*(Ptr32<Ptr32<Ptr32<void (Ptr32<void>)>>>)(p))[4](p);F(self,void*,216)=0;}
 fn_8015adf4(&name,(Ptr32<char>)self+216,(unsigned char)(F(self,unsigned char,32)+29));
 p=F(self,void*,216);(*(Ptr32<Ptr32<Ptr32<void (Ptr32<void>, const F13cPreviewSize &, int)>>>)(p))[21](p,size,0);
 p=F(self,void*,112);(*(Ptr32<Ptr32<Ptr32<void (Ptr32<void>, Ptr32<void>, int)>>>)(p))[23](p,F(self,void*,216),0);
 if(image==1){p=fn_8034357c(F(self,void*,216));Ptr32<void> resource=(*(Ptr32<Ptr32<Ptr32<Ptr32<void> (Ptr32<void>)>>>)(p))[16](p);
 if(fn_801712c4(fn_80343808(resource),F(self,F13cSelectText,428).p)<0){fn_8020c510((Ptr32<char>)self+108,missing_803cbaa8,F(self,F13cSelectText,428).p);F13cSelectFrom_8020bb54 error(info_803cbacc);fn_8015adf4(&error,(Ptr32<char>)self+216,(unsigned char)(F(self,unsigned char,32)+30));}}
}


