#include "w3d_ptr.h"
#line 1 "cc25a_planner_powerup_duration_8001b660.cpp"
// Original 0x8001b660: map vector magnitude to an observed power-up duration.
// Property handle lifetime and virtual release are retained; meaning inferred from key.
struct cc25a_Vec1b660 {float x,y,z;float norm2()const{return z*z+(x*x+y*y);}};
struct cc25a_Property1b660 {Ptr32<Ptr32<void>> dispatch;};
extern char cc25a_key_8036b024[];
extern float cc25a_offset_804b1774,cc25a_scale_804b1770;
extern "C" int cc25a_lookup_800fc1b0(Ptr32<Ptr32<const char>>,Ptr32<Ptr32<cc25a_Property1b660>>);
extern "C" Ptr32<void> cc25a_cast_80342a78(Ptr32<cc25a_Property1b660>);
extern "C" int cc25a_read_80178d1c(Ptr32<void>);
extern "C" float cc25a_sqrt_802e82c0(float);
extern "C" float cc25a_planner_powerup_duration_8001b660(Ptr32<const cc25a_Vec1b660> v){
 struct Workspace {Ptr32<cc25a_Property1b660> property;unsigned int gap;Ptr32<const char> name;unsigned char unknown[12];} w;
 // Additional observed caller workspace bytes have unknown original source purpose.
 w.property=0;w.name=cc25a_key_8036b024;
 cc25a_lookup_800fc1b0(&w.name,&w.property);
 int time=cc25a_read_80178d1c(cc25a_cast_80342a78(w.property));
 float value=((cc25a_sqrt_802e82c0(v->norm2())-cc25a_offset_804b1774)/cc25a_scale_804b1770)*(float)time;
 if(w.property)((Ptr32<void (Ptr32<cc25a_Property1b660>)>)w.property->dispatch[4])(w.property);
 return value;
}


