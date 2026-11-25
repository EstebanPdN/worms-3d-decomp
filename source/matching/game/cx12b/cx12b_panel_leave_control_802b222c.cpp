// PPC32 direct control table +180 and property pointer +12 observed independently.
struct Owner;struct Control{void*unused[6];void(*text)(Owner*,const char*);void(*sound)(Owner*,const char*);};
struct Properties{unsigned char p[44];char*s44;unsigned char p2[44];char*s92,*s96;};
struct Owner{unsigned char opaque[12];Properties*properties;unsigned char mid[72];void*mesh;unsigned int control;int playing,stopped;unsigned char pad[32];float time;unsigned char tail[40];Control*methods;};

extern "C" float time_803d7af8[];
extern "C" void w3d_cx12b_panel_leave_control_802b222c(Owner*self){char*t=self->properties->s92;if(*(unsigned short*)(t-4)){self->time=time_803d7af8[0];self->methods->text(self,self->properties->s92);}char*sound=self->properties->s44;if(*(unsigned short*)(sound-4))self->methods->sound(self,sound);}


