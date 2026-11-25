#include "w3d_ptr.h"
#line 1 "s5_light_colour.cpp"
/* Recomputes diffuse and ambient products after changing one light colour. */
extern "C" {
struct S5ColourVec { float x,y,z; };
struct S5ColourObject { unsigned char reserved[120]; S5ColourVec diffuse,ambient; };
struct S5ColourEntry { S5ColourVec position; Ptr32<S5ColourObject> light; unsigned char reserved[20]; S5ColourVec colour,base; };
struct S5ColourRange { Ptr32<S5ColourEntry> begin; Ptr32<S5ColourEntry> end; };
extern Ptr32<void> w3d_light_source_804aada8;
extern S5ColourRange w3d_light_range_8043c384[];
extern S5ColourVec w3d_ambient_8043c3d0[];
void w3d_light_set_colour_800c136c(int index,float red,float green,float blue)
{
    if (w3d_light_source_804aada8) {
        Ptr32<S5ColourEntry> entry=w3d_light_range_8043c384->begin+index;
        entry->colour.x=red; entry->colour.y=green; entry->colour.z=blue;
        S5ColourVec colour=entry->base;
        colour.x*=entry->colour.x;
        colour.y*=entry->colour.y;
        colour.z*=entry->colour.z;
        S5ColourVec ambient;
        ambient.x=w3d_ambient_8043c3d0->x*entry->colour.x;
        ambient.y=w3d_ambient_8043c3d0->y*entry->colour.y;
        ambient.z=w3d_ambient_8043c3d0->z*entry->colour.z;
        entry->light->diffuse=colour;
        Ptr32<unsigned int> destination=(Ptr32<unsigned int>)&entry->light->ambient;
        unsigned x=*(Ptr32<unsigned int>)&ambient.x;
        unsigned y=*(Ptr32<unsigned int>)&ambient.y;
        unsigned z=*(Ptr32<unsigned int>)&ambient.z;
        destination[0]=x;
        destination[1]=y;
        destination[2]=z;
    }
}
}


