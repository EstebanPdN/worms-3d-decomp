// Partial native object views. A descriptor-pointer array follows a 32-byte
// storage header; no complete allocation or original class size is claimed.
struct d11a_Bounds {
 unsigned char unknown0[8]; float center_y;
 unsigned char unknown12[8]; float axis_x;
 unsigned char unknown24[8]; float axis_y;
 unsigned char unknown36[8]; float axis_z;
 unsigned char unknown48[4]; float extent_x,extent_y,extent_z;
};
struct d11a_Descriptor { unsigned char unknown[56]; unsigned char flags; };
struct d11a_DescriptorStorage { unsigned char header[32]; };
struct d11a_Group { unsigned char unknown[76]; d11a_DescriptorStorage *descriptors; };
struct d11a_BoundsOwner { unsigned char unknown[80]; d11a_Group **groups; };
struct d11a_BoundsSet { unsigned char unknown[16]; d11a_Bounds **begin,**end,**capacity; unsigned group; };
extern const float d11a_bound_zero_8038c578[];
extern "C" double fabs(double);
extern "C" int d11a_bounds_valid_800f66ac(d11a_BoundsOwner *self,d11a_BoundsSet *set)
{
 d11a_Descriptor **descriptors=(d11a_Descriptor **)(self->groups[set->group]->descriptors+1);
 d11a_Bounds **end=set->end;
 d11a_Bounds **begin=set->begin;
 for(unsigned i=0;i<(unsigned)(end-begin);++i) {
   unsigned flags=descriptors[i]->flags;
   begin=set->begin;
   if(flags&2) {
     d11a_Bounds *b=*(d11a_Bounds **)((char *)begin+(i<<2));
     if ((b->axis_y*b->extent_y-(float)fabs(b->axis_x*b->extent_x))-(float)fabs(b->axis_z*b->extent_z) < d11a_bound_zero_8038c578[0]) return 0;
   }
 }
 return 1;
}
