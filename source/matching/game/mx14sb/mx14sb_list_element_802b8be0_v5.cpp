// Borrowed PPC32 ABI views: offsets and object extent are observed in the original.
// Semantic roles are inferred; these external types are not portable engine layouts.
#define MEMBER(p,T,n) (*(T*)((char*)(p)+(n)))
typedef void (*RefMethod)(void*);
inline void retain(void* p){if(p)MEMBER(p,RefMethod*,0)[3](p);}
inline void release(void* p){if(p)MEMBER(p,RefMethod*,0)[4](p);}
struct Held {void* p;Held(const Held& a):p(a.p){retain(p);}~Held(){release(p);}};
struct Vec3 {
 float x,y,z;
 Vec3(const float& a,const float& b,const float& c){x=a;z=c;y=b;}
 Vec3(const Vec3& a){float u=a.x,v=a.y,w=a.z;x=u;y=v;z=w;}
};
extern "C" void* allocate_801fe1d8(unsigned);
struct ListElement_802bce10 {
 unsigned observed_words[35]; // Constructor accesses offsets zero through 136; allocation is 140 bytes.
 ListElement_802bce10();
 static void* operator new(unsigned);
};
extern const float scale_803d80e0[],zero_803d80e4[],extent_803d80e8[];
extern "C" float text_size_802b1880(void*);
extern "C" void interface_802c0c24(void*,Held),interface_802bdc88(void*,Held);
extern "C" void length_802bd3cc(void*,float),select_802bd2c4(void*,unsigned,int);
extern "C" void layer_802c0cac(void*,unsigned),value_802bfb2c(void*,unsigned),height_802bfb68(void*,float),property_802bfba4(void*,unsigned);
extern "C" void position_802bd430(void*,Vec3),setup_802bd158(void*);
extern "C" void mx14sb_list_element_802b8be0(void* self){
 if(!MEMBER(self,void*,404)){
  void* context=MEMBER(self,void*,40);
  float inset=MEMBER(self,float,220)*scale_803d80e0[0];
  const Vec3& dimensions=MEMBER(context,Vec3,20);
  float width=dimensions.x-MEMBER(context,float,132)-inset;
  float size=MEMBER(context,float,128);
  if(size==zero_803d80e4[0])size=text_size_802b1880((char*)self+28);
  MEMBER(self,ListElement_802bce10*,404)=new ListElement_802bce10;
  interface_802c0c24(MEMBER(self,void*,404),MEMBER(self,Held,112));
  length_802bd3cc(MEMBER(self,void*,404),width);
  select_802bd2c4(MEMBER(self,void*,404),MEMBER(self,unsigned,296),0);
  layer_802c0cac(MEMBER(self,void*,404),MEMBER(self,unsigned,32));
  value_802bfb2c(MEMBER(self,void*,404),MEMBER(context,unsigned,144));
  height_802bfb68(MEMBER(self,void*,404),dimensions.y-inset);
  MEMBER(MEMBER(self,void*,404),float,76)=size;
  interface_802bdc88(MEMBER(self,void*,404),MEMBER(self,Held,280));
  property_802bfba4(MEMBER(self,void*,404),MEMBER(self,unsigned,188));
  Vec3 position(inset*extent_803d80e8[0]+(zero_803d80e4[0]-MEMBER(context,float,20)+width),zero_803d80e4[0],zero_803d80e4[0]);
  position_802bd430(MEMBER(self,void*,404),position);
  setup_802bd158(MEMBER(self,void*,404));
 }else select_802bd2c4(MEMBER(self,void*,404),MEMBER(self,unsigned,296),1);
}
