#include "w3d_ptr.h"
#line 1 "d11a_clear_color_801675bc_v0.cpp"
// Preserve the float clear color and convert its four channels to GX bytes.
// State is an observed prefix; the full renderer allocation size is unknown.
// The original uses the compiler's quantized unsigned-byte conversion route.
struct d11a_FloatColor { float r,g,b,a; };
struct d11a_ByteColor { unsigned char r,g,b,a; };
struct d11a_ClearState { unsigned char unknown[24];d11a_FloatColor color;d11a_ByteColor bytes; };
extern const float d11a_channel_scale_803a4e14[];
extern "C" void d11a_set_copy_clear_80308fc0(d11a_ByteColor,unsigned);
extern "C" int d11a_clear_color_801675bc(Ptr32<d11a_ClearState> self,Ptr32<const d11a_FloatColor> color)
{
 self->color=*color;
 self->bytes.r=(unsigned char)(color->r*d11a_channel_scale_803a4e14[0]);
 self->bytes.g=(unsigned char)(color->g*d11a_channel_scale_803a4e14[0]);
 self->bytes.b=(unsigned char)(color->b*d11a_channel_scale_803a4e14[0]);
 self->bytes.a=(unsigned char)(color->a*d11a_channel_scale_803a4e14[0]);
 d11a_set_copy_clear_80308fc0(self->bytes,0x00ffffff);
 return 0;
}


