/* d19d: 0x8016c130 (196 bytes). Bind a scale/offset texture matrix to one
 * texture coordinate: build an identity 3x4 matrix in the shared render
 * context (+968) with 0x80302b60, set its S/T scale to `scale` and its S/T
 * translation to `s_offset`/`t_offset`, load it into the texture matrix slot
 * for coordinate `coord` (0x8030c0c8, type 0 = 3x4), then route coordinate
 * `coord` from `source` through that matrix (0x80307e24, function 0 = 3x4
 * matrix, no normalisation, post matrix 125 = identity). Finally mark the
 * owner as needing an update and set the coordinate's state to 4. Built with
 * -mps-float (SN paired-single mode: one reserved 8-byte slot per saved FPR).
 * Structures are partial views: only the fields used here are named. */
typedef struct D19dTexMtx {
    float m00;              /* +0 */
    float unknown04[2];
    float m03;              /* +12 */
    float unknown10;
    float m11;              /* +20 */
    float unknown18;
    float m13;              /* +28 */
} D19dTexMtx;
typedef struct D19dRenderContext {
    unsigned char unknown00[968];
    D19dTexMtx tex_mtx;     /* +968 */
} D19dRenderContext;
typedef struct D19dTexOwner {
    unsigned char unknown00[304];
    int dirty;              /* +304 */
    unsigned char unknown134[20];
    int coord_state[1];     /* +328, indexed by texture coordinate */
} D19dTexOwner;

extern D19dRenderContext *lbl_804b1884;
/* Texture matrix id per texture coordinate (30, 33, ... 51: matrices 0-7). */
extern const int lbl_803a56b0[];
extern void fn_80302b60(D19dTexMtx *mtx);
extern void fn_8030c0c8(D19dTexMtx *mtx, int id, int type);
extern void fn_80307e24(int coord, int func, int source, int mtx, int normalize, int post_mtx);

void d19d_texgen_scale_offset_8016c130(D19dTexOwner *self, int coord, int source,
                                       float scale, float s_offset, float t_offset)
{
    D19dTexMtx *mtx = &lbl_804b1884->tex_mtx;
    int id;
    fn_80302b60(mtx);
    mtx->m00 = scale;
    mtx->m11 = scale;
    mtx->m03 = s_offset;
    mtx->m13 = t_offset;
    id = lbl_803a56b0[coord];
    fn_8030c0c8(mtx, id, 0);
    fn_80307e24(coord, 0, source, id, 0, 125);
    self->dirty = 0;
    self->coord_state[coord] = 4;
}
