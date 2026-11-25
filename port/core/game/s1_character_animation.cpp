#include "w3d_ptr.h"
#line 1 "s1_character_animation.cpp"
/* Observed camera-linked character visibility and animation checks. */
extern "C" {
struct W3dS1CharacterMesh;
struct W3dS1CharacterTable {Ptr32<void (void)> unused[22];Ptr32<void (Ptr32<W3dS1CharacterMesh>, int)> visible;};
struct W3dS1CharacterMesh {Ptr32<W3dS1CharacterTable> vtable;};
struct W3dS1Character {char unknown[96];Ptr32<W3dS1CharacterMesh> mesh; Ptr32<W3dS1CharacterMesh> secondary;unsigned int actor;Ptr32<void> held;int animation,state;unsigned int enabled[10],names[10],ids[10],enabled2[10],names2[10],ids2[10];char unknown168[36];int visible;};
extern unsigned int w3d_message_804ad650,w3d_message_804ad658,w3d_message_804ad660,w3d_message_804ad638;
extern const char w3d_str_8037a858[];
int w3d_auto_8015fb34(Ptr32<void>,Ptr32<unsigned short>);
void w3d_fn_80068a14(Ptr32<void>);
void w3d_fn_80069430(Ptr32<void>);
int w3d_fn_8015f65c(unsigned short,Ptr32<void>);
void w3d_fn_800fc230(Ptr32<Ptr32<const char>>,Ptr32<int>);
void w3d_fn_8006947c(Ptr32<W3dS1Character>);
void w3d_fn_80069630(Ptr32<void>,int);
void w3d_fn_800697ac(Ptr32<void>);
int w3d_mesh_instance_is_playing(Ptr32<void>,unsigned int);
#if 0 /* Excluded: switch value copy and shared tail layout differ after three attempts. */
int w3d_fn_80068874(W3dS1Character *self,unsigned short *message)
{
    const char *key;int mode;
    unsigned short id=*message;
    switch(id) {
    case 64:if(w3d_auto_8015fb34(self,message)>=0) {w3d_fn_80068a14(self);goto handled;}return 0x80004005;
    case 66:w3d_fn_80069430(self);goto fallback;
    }
    if(w3d_fn_8015f65c(id,&w3d_message_804ad650)) {
        key=w3d_str_8037a858;w3d_fn_800fc230(&key,&mode);self->visible=(mode==1);
        w3d_fn_8006947c(self);goto handled;
    }
    if(w3d_fn_8015f65c(id,&w3d_message_804ad658)) {w3d_fn_80069630(self,3);goto handled;}
    if(w3d_fn_8015f65c(id,&w3d_message_804ad660)) {if(self->state!=8)w3d_fn_80069630(self,6);goto handled;}
    if(!w3d_fn_8015f65c(id,&w3d_message_804ad638))goto fallback;
    if(self->visible)w3d_fn_800697ac(self);
    goto handled;
fallback:
    return w3d_auto_8015fb34(self,message);
handled:
    return 0;
}
#endif
int w3d_franco_scope(float *zoom);   /* Port (francotirador de UM): con la mira puesta no se ven manos ni arma */
void w3d_fn_8006947c(Ptr32<W3dS1Character> self)
{
    const int show=self->visible && !w3d_franco_scope(nullptr);
    self->mesh->vtable->visible(self->mesh,show);
    if(self->secondary)self->secondary->vtable->visible(self->secondary,show);
    if(self->visible)w3d_fn_80069630(self,1);
}
bool w3d_fn_80069590(Ptr32<W3dS1Character> self,int animation)
{
    int first=self->enabled[animation]?w3d_mesh_instance_is_playing(self->mesh,self->ids[animation]):1;
    int second=self->enabled2[animation]?w3d_mesh_instance_is_playing(self->secondary,self->ids2[animation]):1;
    if(first==1 && second==1)return true;
    return false;
}
}


