// Observed partial animation owner and callback interface. The complete original
// class identities and sizes are unknown. Both activity tests are evaluated.
struct d11b_ScaleVector {
    float x,y,z;
    d11b_ScaleVector() {}
    d11b_ScaleVector(float a,float b,float c):x(a),y(b),z(c) {}
};
struct d11b_ScaleTarget;
struct d11b_ScaleTable { unsigned int unknown00[21]; void (*scale)(d11b_ScaleTarget *,const d11b_ScaleVector *,int); };
struct d11b_ScaleTarget { d11b_ScaleTable *vtable; };
struct d11b_ScaleOwner {
    unsigned char unknown00[56]; void *activeA,*activeB;
    unsigned char unknown40[48]; float pulseA,pulseB;
    unsigned char unknown78[12]; d11b_ScaleTarget *first,*second;
    unsigned char unknown8c[20]; float width,height;
};
extern const float d11b_zero_803d078c[],d11b_step_803d0790[],d11b_depth_803d0794[];
extern "C" int d11b_decay_scales_80294f64(d11b_ScaleOwner *self) {
    int b=1; if (!self->activeB) b=0;
    int a=1; if (!self->activeA) a=0;
    if (b & a) {
        float zeroA=d11b_zero_803d078c[0];
        if (self->pulseA!=zeroA) {
            self->pulseA-=d11b_step_803d0790[0];
            if (self->pulseA<zeroA) self->pulseA=zeroA;
            if (self->first) {
                d11b_ScaleVector scale;
                scale.x=self->width*self->pulseA+self->width;
                scale.y=self->height*self->pulseA+self->height;
                scale.z=d11b_depth_803d0794[0];
                self->first->vtable->scale(self->first,&scale,0);
            }
        }
        float zeroB=d11b_zero_803d078c[0];
        if (self->pulseB!=zeroB) {
            self->pulseB-=d11b_step_803d0790[0];
            if (self->pulseB<zeroB) self->pulseB=zeroB;
            if (self->second) {
                d11b_ScaleVector scale;
                scale.x=self->width*self->pulseB+self->width;
                scale.y=self->height*self->pulseB+self->height;
                scale.z=d11b_depth_803d0794[0];
                self->second->vtable->scale(self->second,&scale,0);
            }
        }
    }
    return 0;
}
