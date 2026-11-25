// PPC32 direct control table +180 and property pointer +12 observed independently.
struct Owner;struct Control{void*unused[6];void(*text)(Owner*,const char*);void(*sound)(Owner*,const char*);};
struct Properties{unsigned char p[44];char*s44;unsigned char p2[44];char*s92,*s96;};
struct Owner{unsigned char opaque[12];Properties*properties;unsigned char mid[72];void*mesh;unsigned int control;int playing,stopped;unsigned char pad[32];float time;unsigned char tail[40];Control*methods;};

extern "C" void*cast_80343584(void*);extern "C" int check_8018179c(void*,unsigned int,int);extern "C" int control_801817e0(void*,unsigned int);extern "C" float start_803d7ac8[],zero_803d7acc[];extern "C" char reset_803d7ac0[];extern "C" int reset_80181640(void*,const char*,unsigned int*,float,float,float,int);
extern "C" void w3d_cx12b_panel_mesh_reset_802b1cec(Owner*self){if(self->playing){check_8018179c(cast_80343584(self->mesh),self->control,0);control_801817e0(cast_80343584(self->mesh),self->control);if(!self->stopped)reset_80181640(cast_80343584(self->mesh),reset_803d7ac0,&self->control,start_803d7ac8[0],zero_803d7acc[0],zero_803d7acc[0],0);float zero=zero_803d7acc[0];self->playing=0;self->time=zero;self->stopped=0;}}




