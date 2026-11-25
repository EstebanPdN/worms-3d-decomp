#include "w3d_ptr.h"
#line 1 "s1_earthquake_sound.cpp"
/* Earthquake stereo loop creation, pitch separation, and volume updates. */
extern "C" {
struct W3dS1QuakeVec { float x,y,z; };
struct W3dS1QuakeSound;
struct W3dS1QuakeSoundTable {
    Ptr32<void (void)> unused0[4];Ptr32<void (Ptr32<W3dS1QuakeSound>)> release;Ptr32<void (Ptr32<W3dS1QuakeSound>)> play;
    Ptr32<void (void)> unused6[6];Ptr32<void (Ptr32<W3dS1QuakeSound>, int, int)> set_int;Ptr32<void (Ptr32<W3dS1QuakeSound>, int, float)> set_float;
    Ptr32<void (Ptr32<W3dS1QuakeSound>, int, Ptr32<W3dS1QuakeVec>)> set_vector;Ptr32<void (Ptr32<W3dS1QuakeSound>, int, Ptr32<int>)> get_int;
};
struct W3dS1QuakeSound { Ptr32<W3dS1QuakeSoundTable> vtable; };
struct W3dS1QuakeManager;
struct W3dS1QuakeManagerTable { Ptr32<void (void)> unused[23];Ptr32<void (Ptr32<W3dS1QuakeManager>, Ptr32<const char>, Ptr32<Ptr32<W3dS1QuakeSound>>)> create;Ptr32<void (void)> unused24;Ptr32<void (Ptr32<W3dS1QuakeManager>, Ptr32<Ptr32<W3dS1QuakeSound>>, int)> stop; };
struct W3dS1QuakeManager { Ptr32<W3dS1QuakeManagerTable> vtable; };
struct W3dS1QuakeCamera;
struct W3dS1QuakeCameraTable { Ptr32<void (void)> unused[6];Ptr32<Ptr32<void> (Ptr32<W3dS1QuakeCamera>)> transform; };
struct W3dS1QuakeCamera { Ptr32<W3dS1QuakeCameraTable> vtable; };
struct W3dS1QuakeEnvironment { char unknown[48];Ptr32<W3dS1QuakeCamera> camera;char unknown34[56];Ptr32<W3dS1QuakeManager> sound; };
struct W3dS1QuakeAudio { char unknown[80];Ptr32<W3dS1QuakeSound> left; Ptr32<W3dS1QuakeSound> right;float volume; };
extern Ptr32<W3dS1QuakeEnvironment> w3d_environment_804b1788;
extern const char w3d_str_80379a80[];
extern const float w3d_f32_80379a8c[],w3d_f32_80379a90[],w3d_f32_80379aa0[],w3d_f32_80379aa4[];
int w3d_fn_801f6c2c(Ptr32<void>,Ptr32<void>);
void w3d_fn_80062950(Ptr32<W3dS1QuakeAudio>);
static inline const float &quake_min(const float &a,const float &b) { return b<a?b:a; }
static inline void quake_clear(Ptr32<W3dS1QuakeSound> &slot,Ptr32<W3dS1QuakeSound> next) { if(slot)slot->vtable->release(slot);slot=next; }
void w3d_fn_80062640(Ptr32<W3dS1QuakeAudio> self)
{
    int frequency;
    Ptr32<W3dS1QuakeManager> manager=w3d_environment_804b1788->sound;
    if(manager) {
        manager->vtable->create(manager,w3d_str_80379a80,&self->left);
        manager=w3d_environment_804b1788->sound;
        manager->vtable->create(manager,w3d_str_80379a80,&self->right);
        frequency=22050;self->left->vtable->get_int(self->left,12,&frequency);
        int spread=frequency/20;
        self->left->vtable->set_int(self->left,2,frequency+spread);
        self->right->vtable->set_int(self->right,2,frequency-spread);
        self->volume=w3d_f32_80379a8c[0];
        self->left->vtable->set_float(self->left,1,self->volume);
        self->right->vtable->set_float(self->right,1,self->volume);
        w3d_fn_80062950(self);
        self->left->vtable->play(self->left);self->right->vtable->play(self->right);
    }
}
void w3d_fn_800627a4(Ptr32<W3dS1QuakeAudio> self,int elapsed)
{
    struct { float maximum; } local;
    if(self->volume<w3d_f32_80379a90[0]) {
        self->volume=(float)elapsed*w3d_f32_80379aa0[0]+self->volume;
        local.maximum=w3d_f32_80379a90[0];
        self->volume=quake_min(self->volume,local.maximum);
    }
    if(self->left)self->left->vtable->set_float(self->left,1,self->volume);
    if(self->right)self->right->vtable->set_float(self->right,1,self->volume);
    w3d_fn_80062950(self);
}
void w3d_fn_80062884(Ptr32<W3dS1QuakeAudio> self)
{
    Ptr32<W3dS1QuakeManager> manager=w3d_environment_804b1788->sound;
    if(manager) {
        Ptr32<Ptr32<W3dS1QuakeSound>> left=&self->left;
        if(*left)manager->vtable->stop(manager,left,1000);
        Ptr32<Ptr32<W3dS1QuakeSound>> right=&self->right;
        if(*right) {
            Ptr32<W3dS1QuakeManager> other=w3d_environment_804b1788->sound;
            other->vtable->stop(other,right,1000);
        }
        quake_clear(self->left,0);quake_clear(self->right,0);
    }
}
void w3d_fn_80062950(Ptr32<W3dS1QuakeAudio> self)
{
    struct { W3dS1QuakeVec position;unsigned int pad0;float matrix[16];W3dS1QuakeVec left;unsigned int pad1;W3dS1QuakeVec right;unsigned int pad2[2]; } local;
    Ptr32<W3dS1QuakeCamera> camera=w3d_environment_804b1788->camera;
    w3d_fn_801f6c2c(local.matrix,camera->vtable->transform(camera));
    Ptr32<W3dS1QuakeVec> position=&local.position;
    float x=local.matrix[12],y=local.matrix[13];
    position->x=x;position->y=y;
    float spread=w3d_f32_80379aa4[0];
    float z=local.matrix[14];position->z=z;
    local.left.y=y;local.left.z=z;local.left.x=position->x+spread;
    if(self->left)self->left->vtable->set_vector(self->left,3,&local.left);
    float rightX=position->x-spread;
    float rightY=position->y,rightZ=position->z;
    local.right.z=rightZ;local.right.y=rightY;local.right.x=rightX;
    if(self->right)self->right->vtable->set_vector(self->right,3,&local.right);
}
}


