// Inferred texture-generation setup. These structs are partial offset views;
// their sizes do not establish the original class sizes. External tables remain unowned.
struct d10a_Matrix { float v[3][4]; };
struct d10a_RenderState { unsigned char unknown[0x3c8]; d10a_Matrix texture; };
struct d10a_TextureState { unsigned char unknown[0x130]; unsigned dirty; unsigned unknown134[5]; unsigned modes[8]; };
extern d10a_RenderState *d10a_render_804b1884;
extern unsigned d10a_matrix_ids_803a56b0[];
// Original SDK definitions were inspected: matrix pointer plus full-width enums;
// normalize is a byte. These side-effect-only interfaces discard SDK return registers.
extern "C" void d10a_identity_80302b60(d10a_Matrix *);
extern "C" void d10a_load_texture_8030c0c8(const d10a_Matrix *, unsigned, int);
extern "C" void d10a_texcoord_80307e24(unsigned, int, unsigned, unsigned, unsigned char, unsigned);
extern "C" void d10a_texgen_8016c130(d10a_TextureState *self, unsigned slot, unsigned source,
                                    float scale, float offset_s, float offset_t)
{
    d10a_Matrix *matrix = &d10a_render_804b1884->texture;
    d10a_identity_80302b60(matrix);
    matrix->v[0][0] = scale;
    matrix->v[1][1] = scale;
    unsigned id = d10a_matrix_ids_803a56b0[slot];
    matrix->v[0][3] = offset_s;
    matrix->v[1][3] = offset_t;
    d10a_load_texture_8030c0c8(matrix, id, 0);
    d10a_texcoord_80307e24(slot, 0, source, id, 0, 125);
    self->dirty = 0;
    self->modes[slot] = 4;
}
