// Partial audio owner and virtual interface; original complete identities and
// sizes unknown. The three-float control vector is passed by address.
struct d11b_ClipVector { float x,y,z; d11b_ClipVector(float a,float b,float c):x(a),y(b),z(c) {} };
struct d11b_Clip;
struct d11b_ClipTable {
    unsigned int unknown00[5]; void (*start)(d11b_Clip *); void (*stop)(d11b_Clip *);
    unsigned int unknown1c[2]; int (*playing)(d11b_Clip *);
    unsigned int unknown28[4]; void (*setVector)(d11b_Clip *,int,const d11b_ClipVector *);
};
struct d11b_Clip { d11b_ClipTable *vtable; };
struct d11b_ClipOwner { unsigned char unknown00[1364]; d11b_Clip *clips[1]; };
extern const float d11b_clip_zero_803d6ae0[],d11b_clip_depth_803d6ae4[];
extern "C" void d11b_restart_clip_802ab630(d11b_ClipOwner *self,unsigned int index) {
    if (self->clips[index]) {
        if (self->clips[index]->vtable->playing(self->clips[index])) self->clips[index]->vtable->stop(self->clips[index]);
        d11b_ClipVector value(d11b_clip_zero_803d6ae0[0],d11b_clip_zero_803d6ae0[0],d11b_clip_depth_803d6ae4[0]);
        self->clips[index]->vtable->setVector(self->clips[index],3,&value);
        self->clips[index]->vtable->start(self->clips[index]);
    }
}
