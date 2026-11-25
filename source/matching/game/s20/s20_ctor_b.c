/* Constructors with the common header plus extra zeroed fields. */
extern char lbl_80411f40[];
extern char lbl_80411ef8[];
extern char lbl_80413858[];
extern char lbl_80413830[];

char *w3d_s20_construct_header_8016f2d8(char *self) {
    char *sub;
    char *later;
    *(char **)self = lbl_80411f40;
    sub = self + 4;
    ((volatile unsigned char *)sub)[7] = 2;
    later = self + 12;
    *(int *)(sub + 4) = ((volatile unsigned char *)sub)[7];
    *(int *)(self + 12) = 0;
    *(volatile int *)(later + 4) = 0;
    *(short *)(self + 4) = 0;
    *(short *)(sub + 2) = 0;
    *(char **)self = lbl_80411ef8;
    *(int *)(self + 28) = 0;
    *(short *)(self + 20) = 0;
    *(short *)(self + 22) = 0;
    *(short *)(self + 24) = 0;
    *(short *)(self + 26) = 0;
    return self;
}

char *w3d_s20_construct_header_8019e5b0(char *self) {
    char *sub;
    char *later;
    *(char **)self = lbl_80413858;
    sub = self + 4;
    ((volatile unsigned char *)sub)[7] = 2;
    later = self + 12;
    *(int *)(sub + 4) = ((volatile unsigned char *)sub)[7];
    *(int *)(self + 12) = 0;
    *(volatile int *)(later + 4) = 0;
    *(short *)(self + 4) = 0;
    *(short *)(sub + 2) = 0;
    *(char **)self = lbl_80413830;
    *(int *)(self + 24) = 0;
    return self;
}
