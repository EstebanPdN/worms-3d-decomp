/* Observed donkey payload target vectors and bounce sound updates. */
extern "C" {
struct W3dS1DonkeyVec { float x,y,z; };
struct W3dS1DonkeySound;
struct W3dS1DonkeySoundTable { void (*unused[5])();void (*trigger)(W3dS1DonkeySound *);void (*unknown[8])();void (*position)(W3dS1DonkeySound *,int,W3dS1DonkeyVec *); };
struct W3dS1DonkeySound { W3dS1DonkeySoundTable *vtable; };
struct W3dS1Donkey { char unknown0[36];W3dS1DonkeyVec position,velocity;char unknown3c[132];void *config;char unknownc4[56];void *handle;char unknown100[60];W3dS1DonkeyVec previous;W3dS1DonkeySound *sound; };
extern const float w3d_f32_80379298[],w3d_f32_8037929c[],w3d_f32_803792a0[];
void *w3d_empty_80341584(void *);
void *w3d_auto_801797b4(void *);
void *w3d_handle_member_query_80126360(void *);
void *w3d_fn_800610fc(W3dS1Donkey *self,void *arg1,void *arg2,W3dS1DonkeyVec *normal,W3dS1DonkeyVec *position)
{
    struct { W3dS1DonkeyVec vector; } local;
    w3d_auto_801797b4(w3d_empty_80341584(self->config));
    void *result=w3d_handle_member_query_80126360(self->handle);
    if(result) {
        W3dS1DonkeyVec *vector=&local.vector;
        vector->x=w3d_f32_80379298[0];vector->y=w3d_f32_8037929c[0];vector->z=w3d_f32_80379298[0];
        *normal=*vector;
        *position=self->position;
    }
    return result;
}
void w3d_fn_8006119c(W3dS1Donkey *self)
{
    if(self->velocity.y<w3d_f32_803792a0[0] && self->previous.y>w3d_f32_803792a0[0]) {
        self->sound->vtable->position(self->sound,3,&self->position);
        self->sound->vtable->trigger(self->sound);
    }
    self->previous=self->velocity;
}
}
