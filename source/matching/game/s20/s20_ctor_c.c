/* Constructor with the common flagged header plus two extra zeroed words. */
extern char lbl_804144b0[];
extern char lbl_80414488[];

char *w3d_s20_construct_header_801b440c(char *self) {
    char *sub;
    char *later;
    *(char **)self = lbl_804144b0;
    sub = self + 4;
    ((volatile unsigned char *)sub)[7] = 2;
    later = self + 12;
    *(int *)(sub + 4) = ((volatile unsigned char *)sub)[7];
    *(int *)(self + 12) = 0;
    *(volatile int *)(later + 4) = 0;
    *(short *)(self + 4) = 0;
    *(short *)(sub + 2) = 0;
    *(char **)self = lbl_80414488;
    *(int *)(self + 20) = 0;
    *(int *)(self + 24) = 0;
    return self;
}
