#include "w3d_ptr.h"
#line 1 "cx12b_panel_leave_control_802b222c.cpp"
// PPC32 direct control table +180 and property pointer +12 observed independently.
struct Owner;struct Control{Ptr32<void> unused[6];Ptr32<void (Ptr32<Owner>, Ptr32<const char>)> text;Ptr32<void (Ptr32<Owner>, Ptr32<const char>)> sound;};
struct Properties{unsigned char p[44];Ptr32<char> s44;unsigned char p2[44];Ptr32<char> s92; Ptr32<char> s96;};
struct Owner{unsigned char opaque[12];Ptr32<Properties> properties;unsigned char mid[72];Ptr32<void> mesh;unsigned int control;int playing,stopped;unsigned char pad[32];float time;unsigned char tail[40];Ptr32<Control> methods;};

extern "C" float time_803d7af8[];
extern "C" void w3d_cx12b_panel_leave_control_802b222c(Ptr32<Owner> self){Ptr32<char> t=self->properties->s92;if(*(Ptr32<unsigned short>)(t-4)){self->time=time_803d7af8[0];self->methods->text(self,self->properties->s92);}Ptr32<char> sound=self->properties->s44;if(*(Ptr32<unsigned short>)(sound-4))self->methods->sound(self,sound);}




