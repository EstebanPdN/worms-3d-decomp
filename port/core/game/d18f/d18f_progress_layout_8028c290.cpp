#include "w3d_ptr.h"
#line 1 "d18f_progress_layout_8028c290.cpp"
// Progress slider layout (original 0x8028c290), from the unproved sol11c v2 draft.
// Built with -mps-float (paired-single FP frame). Partial borrowed engine fields;
// vector/string values describe observed storage.
#define MEMBER(p,T,n) (*(w3d::slot_t<T> *)w3d::AG((char*)w3d::AG(p)+(n)))
extern "C" void string_base_finish_8020c5c4(Ptr32<void>),string_release_80341588(Ptr32<void>);
struct Text_803426b8 { Ptr32<char> text; Text_803426b8(); ~Text_803426b8(){string_base_finish_8020c5c4(this);string_release_80341588(this);} };
struct Vec3 {float x,y,z;};
struct Key {Ptr32<const char> text;};
extern "C" Ptr32<void> text_cast_80343580(Ptr32<void>);
extern "C" void text_format_8020c510(Ptr32<Text_803426b8>,Ptr32<const char>,...);
extern "C" int text_assign_8018c5b0(Ptr32<void>,Ptr32<const char>);
extern "C" int read_float_800fc270(Ptr32<const Key>,Ptr32<float>);
extern "C" float text_width_8018c8bc(Ptr32<void>),text_height_8018ca14(Ptr32<void>);
extern "C" void update_box_8028c8e4(Ptr32<void>,float,float,float);
extern const char percentage_format_803cfde4[],border_key_803cfdc0[];
typedef Ptr32<void (Ptr32<void>, Ptr32<const Vec3>, int)> SetVector;
extern "C" void d18f_progress_layout_8028c290(Ptr32<void> self) {
    unsigned last=MEMBER(self,unsigned,308)-1;
    if (MEMBER(self,unsigned,288)>last) MEMBER(self,unsigned,288)=last;
    Ptr32<void> text=0;
    if (MEMBER(self,void*,248)) {
        text=text_cast_80343580(MEMBER(self,void*,248));
        Text_803426b8 label;
        unsigned percent=(unsigned)(((float)MEMBER(self,unsigned,288)/(float)(MEMBER(self,unsigned,308)-1))*100.0f+0.5f);
        text_format_8020c510(&label,percentage_format_803cfde4,percent);
        text_assign_8018c5b0(text,label.text);
    }
    Ptr32<void> context=MEMBER(self,void*,40);
    if (MEMBER(context,int,172)) {
        float factor=(float)MEMBER(self,unsigned,288)*0.5f/(float)(MEMBER(self,unsigned,308)-1)+0.25f;
        Vec3 dimensions=MEMBER(context,Vec3,20);
        dimensions.x*=factor;
        dimensions.y*=factor;
        Ptr32<void> control=MEMBER(self,void*,244);
        if(control) MEMBER(control,SetVector*,0)[21](control,&dimensions,0);
    }
    if (text) {
        Key key={border_key_803cfdc0}; float border;
        read_float_800fc270(&key,&border);
        if (MEMBER(context,float,152)!=0.0f) border=MEMBER(context,float,152);
        float width=text_width_8018c8bc(text);
        float height=text_height_8018ca14(text);
        update_box_8028c8e4(self,border,width*0.5f+border+height*0.0625f,height*0.5f+border-height*0.0625f);
    }
}


