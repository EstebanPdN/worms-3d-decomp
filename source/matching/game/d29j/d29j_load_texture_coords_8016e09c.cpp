// Load a texture and its coordinate scale. Initialises a GX texture object from
// the header's size and format, loads it into map 0, loads a matrix scaling
// texture coordinates by the inverse size, and sets up one coordinate generator.
// The leading array holds the original words just before the literal pool, which
// starts 4 bytes past an 8-byte boundary. GWMP8P rev0 0x8016e09c.
extern const float lbl_803a6338[3] = { -0.024546f, 0.0f, 1.0842021724855044e-19f };
struct Tex { char u[24]; unsigned short format; char u1a[4]; unsigned short width, height; };
struct Obj { Tex *tex; };
struct TexObj { unsigned w[8]; };
extern "C" void fn_80309c88(TexObj *, void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
extern "C" void fn_80309f1c(TexObj *, int, int, float, float, float, int, int, int);
extern "C" void fn_8030a21c(TexObj *, int);
extern "C" void fn_80302e9c(float (*)[4], float, float, float);
extern "C" void fn_8030c0c8(float (*)[4], int, int);
extern "C" void fn_803080a4(int);
extern "C" void fn_80307e24(int, int, int, int, int, int);
extern "C" void d29j_load_texture_coords_8016e09c(Obj *self, void *image)
{
    float m[3][4];
    TexObj t;
    fn_80309c88(&t, image, self->tex->width, self->tex->height, self->tex->format, 0, 0, 0);
    fn_80309f1c(&t, 1, 1, 0.0f, 0.0f, 0.0f, 0, 0, 0);
    fn_8030a21c(&t, 0);
    fn_80302e9c(m, 1.0f / (float)(int)self->tex->width, 1.0f / (float)(int)self->tex->height, 1.0f);
    fn_8030c0c8(m, 30, 1);
    fn_803080a4(1);
    fn_80307e24(0, 1, 4, 30, 0, 125);
}
