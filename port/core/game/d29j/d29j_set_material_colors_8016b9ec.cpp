#include "w3d_ptr.h"
#line 1 "d29j_set_material_colors_8016b9ec.cpp"
// Set the GX channel colours from a material. Scales the ambient float colour to
// bytes, stores it in the renderer's global state and passes it by value to the
// ambient setter for channel 0, then does the same for the diffuse colour on the
// given channel with a local colour. GWMP8P rev0 0x8016b9ec.
struct Color { unsigned char r, g, b, a; };
struct Vec { float x, y, z; };
struct Material { char u[120]; Vec diffuse; Vec ambient; };
struct Global { char u[256]; Color ambient; };
extern Ptr32<Global> global_804b1884;
extern "C" void fn_8030972c(int, Color);
extern "C" void fn_803096a4(Ptr32<void>, Color);
extern "C" void d29j_set_material_colors_8016b9ec(int channel, Ptr32<const Material> m)
{
    const float scale = 255.0f;
    Ptr32<Global> g = global_804b1884;
    {
    const Vec &v = m->ambient;
    Color &c = g->ambient;
    c.r = (unsigned char)(v.x * scale);
    c.g = (unsigned char)(v.y * scale);
    c.b = (unsigned char)(v.z * scale);
    c.a = 255;
    }
    fn_8030972c(0, g->ambient);
    Color d;
    const Vec &v = m->diffuse;
    d.r = (unsigned char)(v.x * scale);
    d.g = (unsigned char)(v.y * scale);
    d.b = (unsigned char)(v.z * scale);
    d.a = 255;
    fn_803096a4((Ptr32<void>)w3d::G(channel), d);
}


