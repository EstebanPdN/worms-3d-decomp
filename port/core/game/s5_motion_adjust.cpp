#include "w3d_ptr.h"
#line 1 "s5_motion_adjust.cpp"
/* Motion dispatch, two bounded adjustments and paired direction tests. */
extern "C" {
struct S5Motion;
struct S5MotionVec { float x,y,z; };
struct S5MotionOps { Ptr32<void (void)> reserved[8]; Ptr32<void (Ptr32<S5Motion>, float, Ptr32<void>)> step; };
struct S5Motion { unsigned char reserved00[72]; Ptr32<S5MotionOps> operations; unsigned char reserved76[60]; Ptr32<void> resource; unsigned char reserved140[40]; float extension,secondary; unsigned unknown188; float angle; };
struct S5MotionConfig { unsigned char reserved[52]; float minimum,maximum; unsigned field60; float limit; unsigned char reserved68[12]; float boundary,rate; };
Ptr32<void> w3d_empty_80341584(Ptr32<void>);
Ptr32<S5MotionConfig> w3d_auto_801797b4(Ptr32<void>);
void w3d_motion_adjust_800d4584(Ptr32<S5Motion>,float,Ptr32<void>);
void w3d_motion_apply_800d3208(Ptr32<S5Motion>,float,Ptr32<void>);
void w3d_motion_finish_800d40f4(Ptr32<S5Motion>,float,Ptr32<void>);
void w3d_motion_direction_800d4d64(Ptr32<S5Motion>,Ptr32<S5MotionVec>,float,float,float);
int w3d_motion_test_8015ac04(Ptr32<S5Motion>,Ptr32<S5MotionVec>,Ptr32<void>);
extern const float w3d_f32_80388d20[];
static inline const float &s5_motion_min(const float &left,const float &right) { return right<left?right:left; }
void w3d_motion_step_800d3160(Ptr32<S5Motion> motion,float delta,Ptr32<void> other)
{
    struct { short reserved[3]; } unused;
    motion->operations->step(motion,delta,other);
    w3d_motion_adjust_800d4584(motion,delta,other);
    w3d_motion_apply_800d3208(motion,delta,other);
    w3d_motion_finish_800d40f4(motion,delta,other);
}
/* 0x800d4734: floating-point temporaries and min slots differ after two attempts. */
#if 0
void w3d_motion_extend_800d4734(S5Motion *motion,float delta)
{
    S5MotionConfig *config=w3d_auto_801797b4(w3d_empty_80341584(motion->resource));
    if(motion->secondary>config->boundary) {
        motion->secondary=motion->secondary-delta*config->rate;
        if(motion->secondary<config->boundary) {
            float excess=config->boundary-motion->secondary;
            motion->secondary=config->boundary;
            delta-=excess/config->rate;
        } else delta=*w3d_f32_80388d20;
    }
    motion->extension=s5_motion_min(float(config->limit),motion->extension+delta);
    struct { short reserved[3]; } unused;
}
#endif
/* 0x800d47f0: floating-point temporaries and min slots differ after two attempts. */
#if 0
void w3d_motion_contract_800d47f0(S5Motion *motion,int clamp,float delta)
{
    S5MotionConfig *config=w3d_auto_801797b4(w3d_empty_80341584(motion->resource));
    motion->extension-=delta;
    if(motion->extension<config->minimum) {
        if(clamp) motion->extension=config->minimum;
        else {
            float excess=config->minimum-motion->extension;
            motion->secondary=s5_motion_min(motion->secondary+config->rate*excess,float(config->maximum));
            struct { short reserved[3]; } unused;
            motion->extension=config->minimum;
        }
    }
}
#endif
int w3d_motion_test_pair_800d4cec(Ptr32<S5Motion> motion,Ptr32<void> first,Ptr32<void> second,float pitch,float yaw)
{
    S5MotionVec direction;
    w3d_motion_direction_800d4d64(motion,&direction,pitch,yaw,motion->angle);
    int result=0;
    if(w3d_motion_test_8015ac04(motion,&direction,first)||w3d_motion_test_8015ac04(motion,&direction,second)) result=1;
    return result;
}
}


