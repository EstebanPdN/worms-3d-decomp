// PPC32 direct control table +180 and property pointer +12 observed independently.
struct Owner;struct Control{void*unused[6];void(*text)(Owner*,const char*);void(*sound)(Owner*,const char*);};
struct Properties{unsigned char p[44];char*s44;unsigned char p2[44];char*s92,*s96;};
struct Owner{unsigned char opaque[12];Properties*properties;unsigned char mid[72];void*mesh;unsigned int control;int playing,stopped;unsigned char pad[32];float time;unsigned char tail[40];Control*methods;};

extern "C" float time_803d7af4[];extern "C" void*cast_80343584(void*);extern "C" int check_8018179c(void*,unsigned int,int);
extern "C" void w3d_cx12b_panel_enter_control_802b2164(Owner*self){char*t=self->properties->s96;if(*(unsigned short*)(t-4)){self->time=time_803d7af4[0];self->methods->text(self,self->properties->s96);if(self->playing==1&&!self->stopped)check_8018179c(cast_80343584(self->mesh),self->control,1);}}

