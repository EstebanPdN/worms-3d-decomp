/* Constructors that install a base vtable, initialize a small header and install the final vtable. */
extern char lbl_80411fc0[];
extern char lbl_80411f90[];
extern char lbl_80413730[];
extern char lbl_80413710[];
extern char lbl_80413890[];
extern char lbl_80416610[];
extern char lbl_804165f0[];

char *w3d_s20_construct_header_8016f7cc(char *self) {
    char *sub;
    char *later;
    *(char **)self = lbl_80411fc0;
    sub = self + 4;
    ((volatile unsigned char *)sub)[7] = 2;
    later = self + 12;
    *(int *)(sub + 4) = ((volatile unsigned char *)sub)[7];
    *(int *)(self + 12) = 0;
    *(volatile int *)(later + 4) = 0;
    *(short *)(self + 4) = 0;
    *(short *)(sub + 2) = 0;
    *(char **)self = lbl_80411f90;
    return self;
}

char *w3d_s20_construct_header_8019d78c(char *self) {
    char *sub;
    char *later;
    *(char **)self = lbl_80413730;
    sub = self + 4;
    ((volatile unsigned char *)sub)[7] = 2;
    later = self + 12;
    *(int *)(sub + 4) = ((volatile unsigned char *)sub)[7];
    *(int *)(self + 12) = 0;
    *(volatile int *)(later + 4) = 0;
    *(short *)(self + 4) = 0;
    *(short *)(sub + 2) = 0;
    *(char **)self = lbl_80413710;
    return self;
}

char *w3d_s20_construct_header_801a0078(char *self) {
    char *sub;
    char *later;
    *(char **)self = lbl_80413730;
    sub = self + 4;
    ((volatile unsigned char *)sub)[7] = 2;
    later = self + 12;
    *(int *)(sub + 4) = ((volatile unsigned char *)sub)[7];
    *(int *)(self + 12) = 0;
    *(volatile int *)(later + 4) = 0;
    *(short *)(self + 4) = 0;
    *(short *)(sub + 2) = 0;
    *(char **)self = lbl_80413890;
    return self;
}

char *w3d_s20_construct_header_801d47b8(char *self) {
    char *sub;
    char *later;
    *(char **)self = lbl_80416610;
    sub = self + 4;
    ((volatile unsigned char *)sub)[7] = 2;
    later = self + 12;
    *(int *)(sub + 4) = ((volatile unsigned char *)sub)[7];
    *(int *)(self + 12) = 0;
    *(volatile int *)(later + 4) = 0;
    *(short *)(self + 4) = 0;
    *(short *)(sub + 2) = 0;
    *(char **)self = lbl_804165f0;
    return self;
}

