// Partial material and renderer views. Convert the two witnessed RGB triples
// to byte colors with opaque alpha, preserving the global color cache writes.
struct d11a_RGB { float r,g,b; };
struct d11a_RGBA8 { unsigned char r,g,b,a; };
struct d11a_Material { unsigned char unknown0[120];d11a_RGB first,second; };
struct d11a_ColorRenderer { unsigned char unknown0[256];d11a_RGBA8 color; };
extern d11a_ColorRenderer *d11a_renderer_804b1884;
extern const float d11a_scale_803a5674[];
extern "C" void d11a_channel_second_8030972c(unsigned,d11a_RGBA8);
extern "C" void d11a_channel_first_803096a4(unsigned,d11a_RGBA8);
extern "C" void d11a_channel_colors_8016b9ec(unsigned channel,const d11a_Material *material)
{
 d11a_RGBA8 *color=&d11a_renderer_804b1884->color;
 color->r=(unsigned char)(material->second.r*d11a_scale_803a5674[0]);
 color->g=(unsigned char)(material->second.g*d11a_scale_803a5674[0]);
 color->b=(unsigned char)(material->second.b*d11a_scale_803a5674[0]);
 color->a=255;
 d11a_channel_second_8030972c(0,*color);
 d11a_RGBA8 first;
 first.r=(unsigned char)(material->first.r*d11a_scale_803a5674[0]);
 first.g=(unsigned char)(material->first.g*d11a_scale_803a5674[0]);
 first.b=(unsigned char)(material->first.b*d11a_scale_803a5674[0]);
 first.a=255;
 d11a_channel_first_803096a4(channel,first);
}
