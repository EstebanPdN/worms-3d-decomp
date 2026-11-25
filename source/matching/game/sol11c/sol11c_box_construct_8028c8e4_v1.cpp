// Borrowed GameCube fields, four-byte held/text objects, and a three-float vector.
#define MEMBER(p,T,n) (*(T*)((char*)(p)+(n)))
typedef void(*RefMethod)(void*);
inline void retain(void* p){if(p)MEMBER(p,RefMethod*,0)[3](p);}
inline void release(void* p){if(p)MEMBER(p,RefMethod*,0)[4](p);}
extern "C" void string_base_finish_8020c5c4(void*),string_release_80341588(void*);
struct Text_8020bb54 {char* text;Text_8020bb54(const char*);~Text_8020bb54(){string_base_finish_8020c5c4(this);string_release_80341588(this);}};
struct Held {void* p; Held():p(0){} ~Held(){release(p);} void assign(void* q){retain(q);release(p);p=q;} };
extern "C" void* heap_801fe1d8(unsigned);
struct Named_8025dffc {void* p;Named_8025dffc(const char*,unsigned char);static void* operator new(unsigned n){return heap_801fe1d8(n);} };
struct Vec3 {float x,y,z;};
extern const Vec3 default_vector_8045e788;
extern const char back_name_803cfd8c[],highlight_name_803cfd9c[],grey_name_803cfdb0[];
extern const float inset_scale_803cfe14[],depth_803cfe18[];
extern "C" void clear_texts_8028c888(void*),set_name_8015adf4(Text_8020bb54*,Held*,unsigned char);
extern "C" void* native_cast_8034357c(void*);
extern "C" const unsigned* color_value_80178f54(void*);
extern "C" void color_assign_80173df0(void*,const unsigned*);
extern "C" const char* name_value_80263c24(void*);
extern "C" float text_size_802b1880(void*);
extern "C" void shape_dimensions_8025e128(Named_8025dffc*,float,float,float),shape_position_8025ee60(Named_8025dffc*,const Vec3*),shape_parent_8025ee94(Named_8025dffc*,void*),control_states_8028c160(void*);
typedef void(*SetVector)(void*,const Vec3*,int);
typedef void(*SetChild)(void*,void*,int);
extern "C" void sol11c_box_construct_8028c8e4(void* self,float border,float width,float height){
 void* context=MEMBER(self,void*,40);
 clear_texts_8028c888(self);
 if(!MEMBER(self,void*,224)){
  {
   Text_8020bb54 name(back_name_803cfd8c);Held resource;
   set_name_8015adf4(&name,&resource,(unsigned char)(MEMBER(self,unsigned char,35)+31));
   MEMBER(self,Held,224).assign(native_cast_8034357c(resource.p));
  }
  void* parent=MEMBER(self,void*,112);
  MEMBER(parent,SetChild*,0)[23](parent,MEMBER(self,void*,224),0);
  unsigned color=*color_value_80178f54(MEMBER(self,void*,228));
  color_assign_80173df0(MEMBER(self,void*,224),&color);
 }
 MEMBER(self,Named_8025dffc*,212)=new Named_8025dffc(name_value_80263c24(MEMBER(context,void*,120)),(unsigned char)(MEMBER(self,unsigned char,35)+32));
 MEMBER(self,Named_8025dffc*,216)=new Named_8025dffc(highlight_name_803cfd9c,(unsigned char)(MEMBER(self,unsigned char,35)+32));
 if(*(unsigned short*)(MEMBER(context,char*,60)-4))
  MEMBER(self,Named_8025dffc*,220)=new Named_8025dffc(grey_name_803cfdb0,(unsigned char)(MEMBER(self,unsigned char,35)+32));
 Vec3 dimensions=default_vector_8045e788;
 text_size_802b1880((char*)self+28);
 unsigned count=0;int offset=0;Named_8025dffc** shapes=(Named_8025dffc**)((char*)self+212);
 do{
  Named_8025dffc* shape=*(Named_8025dffc**)((char*)shapes+offset);
  if(shape){
   shape_dimensions_8025e128(shape,border,width,height);
   shape_position_8025ee60(*(Named_8025dffc**)((char*)shapes+offset),&MEMBER(self,Vec3,316));
   shape_parent_8025ee94(*(Named_8025dffc**)((char*)shapes+offset),MEMBER(self,void*,112));
  }
  ++count;offset+=4;
 }while(count<3);
 dimensions.x=width-border*inset_scale_803cfe14[0];
 dimensions.y=height-border*inset_scale_803cfe14[0];
 dimensions.z=depth_803cfe18[0];
 void* back=MEMBER(self,void*,224);
 MEMBER(back,SetVector*,0)[21](back,&dimensions,0);
 back=MEMBER(self,void*,224);MEMBER(back,SetVector*,0)[19](back,&MEMBER(self,Vec3,316),0);
 control_states_8028c160(self);
}
