/* Graphics quad submission. */
typedef union S20GxFifo { unsigned char u8; unsigned short u16; unsigned int u32; } S20GxFifo;
extern volatile S20GxFifo lbl_cc008000[];
extern void fn_803089c8(int, int, int);

void w3d_s20_draw_textured_quad_8016dfcc(char **self, int x, int y, int width, int height) {
    unsigned short base_u = *(unsigned short *)(*self + 16);
    unsigned short base_v = *(unsigned short *)(*self + 18);
    short left = x;
    short top = y;
    short span_u = width;
    short span_v = height;
    short right = base_u + width;
    short bottom = base_v + height;
    short u0 = base_u + x;
    short v0 = base_v + y;
    fn_803089c8(128, 0, 4);
    lbl_cc008000[0].u16 = left;
    lbl_cc008000[0].u16 = top;
    lbl_cc008000[0].u16 = 0;
    lbl_cc008000[0].u16 = span_u;
    lbl_cc008000[0].u16 = span_v;
    lbl_cc008000[0].u16 = u0;
    lbl_cc008000[0].u16 = top;
    lbl_cc008000[0].u16 = 0;
    lbl_cc008000[0].u16 = right;
    lbl_cc008000[0].u16 = span_v;
    lbl_cc008000[0].u16 = u0;
    lbl_cc008000[0].u16 = v0;
    lbl_cc008000[0].u16 = 0;
    lbl_cc008000[0].u16 = right;
    lbl_cc008000[0].u16 = bottom;
    lbl_cc008000[0].u16 = left;
    lbl_cc008000[0].u16 = v0;
    lbl_cc008000[0].u16 = 0;
    lbl_cc008000[0].u16 = span_u;
    lbl_cc008000[0].u16 = bottom;
}
