typedef union S20GxFifo { unsigned char u8; unsigned short u16; unsigned int u32; } S20GxFifo;
extern volatile S20GxFifo lbl_cc008000[];
extern void fn_803089c8(int, int);

void w3d_s20_write_indices_8016b3f0(int arg, unsigned int mask, unsigned int count) {
    unsigned short i;
    fn_803089c8(arg, 0);
    for (i = 0; i < count; i++) {
        if (mask & 3)
            lbl_cc008000[0].u16 = i;
        if (mask & 0xc)
            lbl_cc008000[0].u16 = i;
        if (mask & 0x30)
            lbl_cc008000[0].u16 = i;
        if (mask & 0x180)
            lbl_cc008000[0].u16 = i;
    }
}
