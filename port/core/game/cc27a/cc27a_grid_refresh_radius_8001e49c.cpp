#include "w3d_ptr.h"
#line 1 "cc27a_grid_refresh_radius_8001e49c.cpp"
// Compute original grid midpoint and horizontal radius before rectangle refresh.
struct cc27a_VecE49c {float x,y,z;
 cc27a_VecE49c(){}
 cc27a_VecE49c(float a,float b,float c){x=a;y=b;z=c;}
 cc27a_VecE49c(const cc27a_VecE49c& v){float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;}
 cc27a_VecE49c operator+(const cc27a_VecE49c&v)const{cc27a_VecE49c r;r.x=x+v.x;r.y=y+v.y;r.z=z+v.z;return r;}
 cc27a_VecE49c operator*(float f)const{cc27a_VecE49c r;r.x=x*f;r.y=y*f;r.z=z*f;return r;}
 float distance2(const cc27a_VecE49c&v)const {float dx=x-v.x,dy=y-v.y,dz=z-v.z;return dx*dx+dy*dy+dz*dz;}
};
struct cc27a_GridE49c {char unknown[108];float time1,time2;cc27a_VecE49c minimum,maximum;char unknown140[20];Ptr32<void> service;};
extern "C" Ptr32<void> cc27a_touch_80342a74(Ptr32<void>);
extern "C" float cc27a_clock_80178df0(Ptr32<void>);
extern "C" float cc27a_sqrt_802e82c0(float);
extern "C" void cc27a_refresh_8001cc90(Ptr32<const cc27a_VecE49c>,float);
extern "C" void cc27a_grid_refresh_radius_8001e49c(Ptr32<cc27a_GridE49c> self){self->time2=self->time1=cc27a_clock_80178df0((Ptr32<void>)cc27a_touch_80342a74(self->service));
 cc27a_VecE49c midpoint=(self->minimum+self->maximum)*0.5f;
 cc27a_VecE49c corner(self->minimum);corner.y=midpoint.y;
 float radius=cc27a_sqrt_802e82c0(midpoint.distance2(corner));
 cc27a_refresh_8001cc90(&midpoint,radius+1.0f);
}

