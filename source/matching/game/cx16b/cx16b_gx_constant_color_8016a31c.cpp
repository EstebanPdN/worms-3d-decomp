/* Original GX constant-color update. Quantized stores require the observed
   -mfast-cast reference option. Only RGBA component widths are asserted. */
struct Cx16bGxColor { unsigned char r,g,b,a; } __attribute__((aligned(4)));
struct Cx16bGxColorState { char pad[72]; float rgb[3]; };
extern "C" {
extern float lbl_803a54e0[];
void fn_8030981c(int,Cx16bGxColor);
int w3d_cx16b_gx_constant_color_8016a31c(void *unused,const Cx16bGxColorState *state)
{
    const float *rgb=state->rgb;
    Cx16bGxColor color;
    color.r=(unsigned char)(rgb[0]*lbl_803a54e0[0]);
    color.g=(unsigned char)(rgb[1]*lbl_803a54e0[0]);
    color.b=(unsigned char)(rgb[2]*lbl_803a54e0[0]);
    color.a=255;
    fn_8030981c(0,color);
    return 0;
}
}
