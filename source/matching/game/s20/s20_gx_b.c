/* Graphics write-pipe command sequences. */
typedef union S20GxFifo { unsigned char u8; unsigned short u16; unsigned int u32; } S20GxFifo;
extern volatile S20GxFifo lbl_cc008000[];
extern void fn_8030c410(int, int);

void w3d_s20_set_blend_mode_8016830c(int enable) {
    if (enable) {
        fn_8030c410(35, 22);
        lbl_cc008000[0].u8 = 97;
        lbl_cc008000[0].u32 = 0x2402c004;
        lbl_cc008000[0].u8 = 97;
        lbl_cc008000[0].u32 = 0x23000020;
        lbl_cc008000[0].u8 = 16;
        lbl_cc008000[0].u16 = 0;
        lbl_cc008000[0].u16 = 4102;
        lbl_cc008000[0].u32 = 0x00084400;
    } else {
        lbl_cc008000[0].u8 = 97;
        lbl_cc008000[0].u32 = 0x24000000;
        lbl_cc008000[0].u8 = 97;
        lbl_cc008000[0].u32 = 0x23000000;
        lbl_cc008000[0].u8 = 16;
        lbl_cc008000[0].u16 = enable;
        lbl_cc008000[0].u16 = 4102;
        lbl_cc008000[0].u32 = enable;
    }
}
