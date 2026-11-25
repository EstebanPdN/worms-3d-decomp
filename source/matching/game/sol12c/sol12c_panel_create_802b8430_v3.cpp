// Borrowed GameCube ABI views. Interface arguments are owned by-value copies.
#define MEMBER(p,T,n) (*(T*)((char*)(p)+(n)))
typedef void (*RefMethod)(void*);
inline void retain(void* p){if(p)MEMBER(p,RefMethod*,0)[3](p);}
inline void release(void* p){if(p)MEMBER(p,RefMethod*,0)[4](p);}
struct Held {void* p;Held(const Held& a):p(a.p){retain(p);}~Held(){release(p);}};
struct Vec3 {float x,y,z;Vec3(const float& a,const float& b,const float& c):x(a),y(b),z(c){} };
extern char service_8041c850[];
extern void* manager_804b178c;
extern unsigned dirty_804abb4c;
extern const float zero_803d80b0[],one_803d80c0[];
extern "C" void* create_8020b680(void*);
extern "C" void attach_80164514(void*,void*,unsigned);
extern "C" void interfaces_802bc098(void*,Held,Held);
extern "C" void position_802bc180(void*,const Vec3*);
extern "C" void layer_802bcd10(void*,unsigned),value_all_802bcb6c(void*,unsigned),child_value_802bcc40(void*,unsigned),clamp_802bcbd8(void*,float);
extern "C" float text_size_802b1880(void*);
extern "C" void setup_802bc570(void*),select_802bc8b4(void*,unsigned),activity_802b879c(void*);
extern "C" unsigned nested_value_802bc71c(void*);
extern "C" float panel_width_802bc778(void*);
extern "C" void dimensions_80296378(void*,float,float,float),height_80296410(void*,float);
extern "C" void sol12c_panel_create_802b8430(void* self){
 if(MEMBER(self,void*,280)&&!MEMBER(self,void*,284)){
  float inset=MEMBER(self,float,220);
  void* panel=create_8020b680(service_8041c850);
  MEMBER(self,void*,284)=panel;
  attach_80164514(manager_804b178c,panel,MEMBER(self,unsigned,20));
  interfaces_802bc098(MEMBER(self,void*,284),MEMBER(self,Held,280),MEMBER(self,Held,112));
  void* context=MEMBER(self,void*,40);
  Vec3 position(MEMBER(context,float,20)-inset,MEMBER(self,float,416),zero_803d80b0[0]);
  position_802bc180(MEMBER(self,void*,284),&position);
  layer_802bcd10(MEMBER(self,void*,284),MEMBER(self,unsigned,32)+5);
  value_all_802bcb6c(MEMBER(self,void*,284),MEMBER(context,unsigned,144));
  child_value_802bcc40(MEMBER(self,void*,284),MEMBER(self,unsigned,188));
  clamp_802bcbd8(MEMBER(self,void*,284),MEMBER(context,float,136));
  MEMBER(MEMBER(self,void*,284),float,92)=text_size_802b1880((char*)self+28);
  setup_802bc570(MEMBER(self,void*,284));
  select_802bc8b4(MEMBER(self,void*,284),MEMBER(self,unsigned,296));
  activity_802b879c(self);
  void* box=MEMBER(self,void*,288);
  if(box){float count=(float)nested_value_802bc71c(MEMBER(self,void*,284));float width=panel_width_802bc778(MEMBER(self,void*,284));dimensions_80296378(box,one_803d80c0[0],count,width);height_80296410(MEMBER(self,void*,288),MEMBER(MEMBER(self,void*,284),float,68));}
  dirty_804abb4c=1;MEMBER(self,unsigned,408)=1;
 }
}
