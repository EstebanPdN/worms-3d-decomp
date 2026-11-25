#include "w3d_ptr.h"
#line 1 "f1p_create_blue_box_802a31fc.cpp"
// Inferred frontend box creation with native copied vector and text lifetime.
extern "C" void fn_8020bb54(Ptr32<void>,Ptr32<const char>),fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>);
struct F1pBlueText_8020bb54{
 F1pBlueText_8020bb54(const F1pBlueText_8020bb54 &);Ptr32<char> p;template <class W3dU> F1pBlueText_8020bb54(Ptr32<W3dU> w3d_p) : F1pBlueText_8020bb54((const char *)w3d_p.get()) {}
 F1pBlueText_8020bb54(const char*s);~F1pBlueText_8020bb54(){fn_8020c5c4(this);fn_80341588(this);}};
struct F1pBlueVec{float x,y,z;F1pBlueVec(const F1pBlueVec&v):x(v.x),y(v.y),z(v.z){}};extern F1pBlueVec vector_8045e788;extern float scalar_803d2e24[];extern char text_803d2e08[],text_803d2e14[];
struct F1pBlueData{char unknown0[20];float width,height;char unknown28[104];int enabled;};struct F1pBlueOwner{char unknown0[32];unsigned char layer; char w3d_tag_rest[3];char unknown36[4];Ptr32<F1pBlueData> data;char unknown44[68];Ptr32<void> parent;char unknown116[100];Ptr32<void> box;};
extern "C" Ptr32<void> fn_801fe1d8(unsigned);extern "C" Ptr32<void> fn_8025dffc(Ptr32<void>,Ptr32<const char>,unsigned char);extern "C" void fn_8025e128(Ptr32<void>,float,float,float),fn_8025ee60(Ptr32<void>,Ptr32<const F1pBlueVec>),fn_8025ee94(Ptr32<void>,Ptr32<void>);
extern "C" void w3d_create_blue_box_802a31fc(Ptr32<F1pBlueOwner> s){F1pBlueText_8020bb54 text(text_803d2e08);Ptr32<F1pBlueData> d=s->data;if(!d->enabled)return;F1pBlueVec position=vector_8045e788;s->box=fn_8025dffc(fn_801fe1d8(4),text_803d2e14,s->layer+29);fn_8025e128(s->box,*scalar_803d2e24,d->width,d->height);fn_8025ee60(s->box,&position);fn_8025ee94(s->box,s->parent);}


