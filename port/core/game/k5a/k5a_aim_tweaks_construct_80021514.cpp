#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k5a_aim_tweaks_construct_80021514.c"
typedef struct K5aAimTweaks
{
  char pad0[4];
  int field_04;
  int field_08;
  int mode;
  Ptr32<const void> vtable;
  int angle_delta;
  int active_index;
} K5aAimTweaks;
extern char w3d_vtable_8040dd48[];
extern char w3d_string_8036c014[];
extern char w3d_string_8036c024[];
extern int w3d_constructor_lookup_name(Ptr32<Ptr32<const char>> name, Ptr32<void> output);

Ptr32<K5aAimTweaks> k5a_aim_tweaks_construct_80021514(Ptr32<K5aAimTweaks> self)
{
  Ptr32<const char> index_name;
  Ptr32<const char> delta_name;
  Ptr32<int> delta = &self->angle_delta;
  self->vtable = w3d_vtable_8040dd48;
  self->field_04 = 0;
  self->field_08 = 0;
  self->angle_delta = 0;
  self->active_index = 0;
  self->mode = 2;
  index_name = w3d_string_8036c014;
  w3d_constructor_lookup_name(&index_name, &self->active_index);
  delta_name = w3d_string_8036c024;
  w3d_constructor_lookup_name(&delta_name, delta);
  return self;
}

}
