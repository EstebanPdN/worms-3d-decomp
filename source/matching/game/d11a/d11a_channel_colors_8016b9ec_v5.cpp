// Partial material and renderer views. Convert the two witnessed RGB triples
// to byte colors with opaque alpha, preserving the global color cache writes.
struct d11a_RGB { float r,g,b; };
struct d11a_RGBA8 { unsigned char r,g,b,a; d11a_RGBA8(){} d11a_RGBA8(unsigned char red,unsigned char green,unsigned char blue,unsigned char alpha):r(red),g(green),b(blue),a(alpha){} };
struct d11a_Light { unsigned char unknown0[12];d11a_RGBA8 color; };
struct d11a_Material { unsigned char unknown0[120];d11a_RGB first,second; };
struct d11a_ColorRenderer { unsigned char unknown0[256];d11a_RGBA8 color; };
extern d11a_ColorRenderer *d11a_renderer_804b1884;
extern const float d11a_scale_803a5674[];
extern "C" void d11a_channel_second_8030972c(unsigned,d11a_RGBA8);
extern "C" void d11a_channel_first_803096a4(d11a_Light *,d11a_RGBA8);
inline d11a_RGBA8 d11a_convert_rgb(const d11a_RGB &rgb) {
 return d11a_RGBA8((unsigned char)(rgb.r*d11a_scale_803a5674[0]),(unsigned char)(rgb.g*d11a_scale_803a5674[0]),(unsigned char)(rgb.b*d11a_scale_803a5674[0]),255);
}
extern "C" void d11a_channel_colors_8016b9ec(d11a_Light *light,const d11a_Material *material)
{
 const d11a_RGB *second=&material->second;
 d11a_RGBA8 *color=&d11a_renderer_804b1884->color;
 color->r=(unsigned char)(second->r*d11a_scale_803a5674[0]);
 color->g=(unsigned char)(second->g*d11a_scale_803a5674[0]);
 color->b=(unsigned char)(second->b*d11a_scale_803a5674[0]);
 color->a=255;
 d11a_channel_second_8030972c(0,*color);
 d11a_RGBA8 first=d11a_convert_rgb(material->first);
 d11a_channel_first_803096a4(light,first);
}
