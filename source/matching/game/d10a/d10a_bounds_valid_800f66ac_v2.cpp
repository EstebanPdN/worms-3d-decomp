// Partial native object views. A descriptor-pointer array follows a 32-byte
// storage header; no complete allocation or original class size is claimed.
struct d10a_Bounds {
 unsigned char unknown0[8]; float center_y;
 unsigned char unknown12[8]; float axis_x;
 unsigned char unknown24[8]; float axis_y;
 unsigned char unknown36[8]; float axis_z;
 unsigned char unknown48[4]; float extent_x,extent_y,extent_z;
};
struct d10a_Descriptor { unsigned char unknown[56]; unsigned char flags; };
struct d10a_DescriptorStorage { unsigned char header[32]; };
struct d10a_Group { unsigned char unknown[76]; d10a_DescriptorStorage *descriptors; };
struct d10a_BoundsOwner { unsigned char unknown[80]; d10a_Group **groups; };
struct d10a_BoundsSet { unsigned char unknown[16]; d10a_Bounds **begin,**end,**capacity; unsigned group; };
extern const float d10a_bound_zero_8038c578[];
extern "C" double fabs(double);
extern "C" int d10a_bounds_valid_800f66ac(d10a_BoundsOwner *self,d10a_BoundsSet *set)
{
 d10a_Descriptor **descriptors=(d10a_Descriptor **)(self->groups[set->group]->descriptors+1);
 for(unsigned i=0;i<(unsigned)(set->end-set->begin);++i) {
   d10a_Bounds *b=*(d10a_Bounds **)((char *)set->begin+(i<<2));
   if(descriptors[i]->flags&2) {
     if ((b->axis_y*b->extent_y-(float)fabs(b->axis_x*b->extent_x))-(float)fabs(b->axis_z*b->extent_z) < d10a_bound_zero_8038c578[0]) return 0;
   }
 }
 return 1;
}
