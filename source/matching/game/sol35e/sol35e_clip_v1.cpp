// Partial audio owner and virtual interface; original complete identities and
// sizes unknown. The three-float control vector is passed by address.
struct sol35e_ClipVector { float x,y,z; sol35e_ClipVector(float a,float b,float c):x(a),y(b),z(c) {} };
struct sol35e_Clip;
struct sol35e_ClipTable {
    unsigned int unknown00[5]; void (*start)(sol35e_Clip *); void (*stop)(sol35e_Clip *);
    unsigned int unknown1c[2]; int (*playing)(sol35e_Clip *);
    unsigned int unknown28[4]; void (*setVector)(sol35e_Clip *,int,const sol35e_ClipVector *);
};
struct sol35e_Clip { sol35e_ClipTable *vtable; };
struct sol35e_ClipOwner { unsigned char unknown00[1364]; sol35e_Clip *clips[1]; sol35e_Clip *clip(unsigned i) {return clips[i];} };
extern const float sol35e_clip_zero_803d6ae0[],sol35e_clip_depth_803d6ae4[];
extern "C" void sol35e_restart_clip_802ab630(sol35e_ClipOwner *self,unsigned int index) {
    if (self->clip(index)) {
        if (self->clip(index)->vtable->playing(self->clip(index))) self->clip(index)->vtable->stop(self->clip(index));
        sol35e_ClipVector value(sol35e_clip_zero_803d6ae0[0],sol35e_clip_zero_803d6ae0[0],sol35e_clip_depth_803d6ae4[0]);
        self->clip(index)->vtable->setVector(self->clip(index),3,&value);
        self->clip(index)->vtable->start(self->clip(index));
    }
}
