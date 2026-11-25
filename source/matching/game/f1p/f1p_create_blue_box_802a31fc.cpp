// Inferred frontend box creation with native copied vector and text lifetime.
extern "C" void fn_8020bb54(void*,const char*),fn_8020c5c4(void*),fn_80341588(void*);
struct F1pBlueText_8020bb54{
 F1pBlueText_8020bb54(const F1pBlueText_8020bb54 &);char*p;F1pBlueText_8020bb54(const char*s);~F1pBlueText_8020bb54(){fn_8020c5c4(this);fn_80341588(this);}};
struct F1pBlueVec{float x,y,z;F1pBlueVec(const F1pBlueVec&v):x(v.x),y(v.y),z(v.z){}};extern F1pBlueVec vector_8045e788;extern float scalar_803d2e24[];extern char text_803d2e08[],text_803d2e14[];
struct F1pBlueData{char unknown0[20];float width,height;char unknown28[104];int enabled;};struct F1pBlueOwner{char unknown0[35];unsigned char layer;char unknown36[4];F1pBlueData*data;char unknown44[68];void*parent;char unknown116[100];void*box;};
extern "C" void*fn_801fe1d8(unsigned);extern "C" void*fn_8025dffc(void*,const char*,unsigned char);extern "C" void fn_8025e128(void*,float,float,float),fn_8025ee60(void*,const F1pBlueVec*),fn_8025ee94(void*,void*);
extern "C" void w3d_create_blue_box_802a31fc(F1pBlueOwner*s){F1pBlueText_8020bb54 text(text_803d2e08);F1pBlueData*d=s->data;if(!d->enabled)return;F1pBlueVec position=vector_8045e788;s->box=fn_8025dffc(fn_801fe1d8(4),text_803d2e14,s->layer+29);fn_8025e128(s->box,*scalar_803d2e24,d->width,d->height);fn_8025ee60(s->box,&position);fn_8025ee94(s->box,s->parent);}
