#include "w3d_ptr.h"
#line 1 "d11b_decay_scales_80294f64_v4.cpp"
// DOL literal words independently decoded: 00000000, 3ca3d70a, 3f800000.
// Observed partial animation owner and callback interface. The complete original
// class identities and sizes are unknown. Both activity tests are evaluated.
struct d11b_ScaleVector {
    float x,y,z;
    d11b_ScaleVector(float a,float b,float c):x(a),y(b),z(c) {}
};
struct d11b_ScaleTarget;
struct d11b_ScaleTable { unsigned int unknown00[21]; Ptr32<void (Ptr32<d11b_ScaleTarget>, Ptr32<const d11b_ScaleVector>, int)> scale; };
struct d11b_ScaleTarget { Ptr32<d11b_ScaleTable> vtable; };
struct d11b_ScaleOwner {
    unsigned char unknown00[56]; Ptr32<void> activeA; Ptr32<void> activeB;
    unsigned char unknown40[48]; float pulseA,pulseB;
    unsigned char unknown78[12]; Ptr32<d11b_ScaleTarget> first; Ptr32<d11b_ScaleTarget> second;
    unsigned char unknown8c[20]; float width,height;
};
extern "C" int d11b_decay_scales_80294f64(Ptr32<d11b_ScaleOwner> self) {
    int b=1; if (!self->activeB) b=0;
    int a=1; if (!self->activeA) a=0;
    if (b & a) {
        if (self->pulseA!=0.0f) {
            self->pulseA-=0.02f;
            if (self->pulseA<0.0f) self->pulseA=0.0f;
            if (self->first) {
                d11b_ScaleVector scale(self->width*self->pulseA+self->width,self->height*self->pulseA+self->height,1.0f);
                self->first->vtable->scale(self->first,&scale,0);
            }
        }
        if (self->pulseB!=0.0f) {
            self->pulseB-=0.02f;
            if (self->pulseB<0.0f) self->pulseB=0.0f;
            if (self->second) {
                d11b_ScaleVector scale(self->width*self->pulseB+self->width,self->height*self->pulseB+self->height,1.0f);
                self->second->vtable->scale(self->second,&scale,0);
            }
        }
    }
    return 0;
}


