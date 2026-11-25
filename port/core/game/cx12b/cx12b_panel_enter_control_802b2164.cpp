#include "w3d_ptr.h"
#line 1 "cx12b_panel_enter_control_802b2164.cpp"
// PPC32 direct control table +180 and property pointer +12 observed independently.
struct Owner;struct Control{Ptr32<void> unused[6];Ptr32<void (Ptr32<Owner>, Ptr32<const char>)> text;Ptr32<void (Ptr32<Owner>, Ptr32<const char>)> sound;};
struct Properties{unsigned char p[44];Ptr32<char> s44;unsigned char p2[44];Ptr32<char> s92; Ptr32<char> s96;};
struct Owner{unsigned char opaque[12];Ptr32<Properties> properties;unsigned char mid[72];Ptr32<void> mesh;unsigned int control;int playing,stopped;unsigned char pad[32];float time;unsigned char tail[40];Ptr32<Control> methods;};

extern "C" float time_803d7af4[];extern "C" Ptr32<void> cast_80343584(Ptr32<void>);extern "C" int check_8018179c(Ptr32<void>,unsigned int,int);
extern "C" void w3d_cx12b_panel_enter_control_802b2164(Ptr32<Owner> self){Ptr32<char> t=self->properties->s96;if(*(Ptr32<unsigned short>)(t-4)){self->time=time_803d7af4[0];self->methods->text(self,self->properties->s96);if(self->playing==1&&!self->stopped)check_8018179c(cast_80343584(self->mesh),self->control,1);}}



