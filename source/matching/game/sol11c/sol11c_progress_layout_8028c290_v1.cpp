// Partial borrowed engine fields; vector/string values describe observed storage.
#define MEMBER(p,T,n) (*(T*)((char*)(p)+(n)))
extern "C" void string_base_finish_8020c5c4(void*),string_release_80341588(void*);
struct Text_803426b8 { char* text; Text_803426b8(); ~Text_803426b8(){string_base_finish_8020c5c4(this);string_release_80341588(this);} };
struct Vec3 {float x,y,z;};
struct Key {const char* text;};
extern "C" void* text_cast_80343580(void*);
extern "C" void text_format_8020c510(Text_803426b8*,const char*,...);
extern "C" void text_assign_8018c5b0(void*,const char*);
extern "C" int read_float_800fc270(const Key*,float*);
extern "C" float text_width_8018c8bc(void*),text_height_8018ca14(void*);
extern "C" void update_box_8028c8e4(void*,float,float,float);
extern const char percentage_format_803cfde4[],border_key_803cfdc0[];
extern const float percent_scale_803cfdf8[],one_803cfdfc[],range_bias_803cfe08[],automatic_803cfe0c[],half_803cfe10[];
typedef void (*SetVector)(void*,const Vec3*,int);
extern "C" void sol11c_progress_layout_8028c290(void* self) {
    unsigned last=MEMBER(self,unsigned,308)-1;
    if (last<MEMBER(self,unsigned,288)) MEMBER(self,unsigned,288)=last;
    void* text=0;
    if (MEMBER(self,void*,248)) {
        text=text_cast_80343580(MEMBER(self,void*,248));
        Text_803426b8 label;
        unsigned percent=(unsigned)(((float)MEMBER(self,unsigned,288)/(float)(MEMBER(self,unsigned,308)-1))*percent_scale_803cfdf8[0]+one_803cfdfc[0]);
        text_format_8020c510(&label,percentage_format_803cfde4,percent);
        text_assign_8018c5b0(text,label.text);
    }
    void* context=MEMBER(self,void*,40);
    if (MEMBER(context,int,172)) {
        float factor=(float)MEMBER(self,unsigned,288)*one_803cfdfc[0]/(float)(MEMBER(self,unsigned,308)-1)+range_bias_803cfe08[0];
        Vec3 dimensions=MEMBER(context,Vec3,20);
        dimensions.x*=factor;
        dimensions.y*=factor;
        void* control=MEMBER(self,void*,244);
        if(control) MEMBER(control,SetVector*,0)[21](control,&dimensions,0);
    }
    if (text) {
        Key key={border_key_803cfdc0}; float border;
        read_float_800fc270(&key,&border);
        if (MEMBER(context,float,152)!=automatic_803cfe0c[0]) border=MEMBER(context,float,152);
        float width=text_width_8018c8bc(text);
        float height=text_height_8018ca14(text);
        update_box_8028c8e4(self,border,width*one_803cfdfc[0]+border+height*half_803cfe10[0],height*one_803cfdfc[0]+border-height*half_803cfe10[0]);
    }
}
