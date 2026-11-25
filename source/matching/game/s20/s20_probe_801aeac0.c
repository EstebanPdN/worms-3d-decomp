extern char lbl_804141b8[];
extern char lbl_80414170[];
char *w3d_s20_construct_header_801aeac0(char *self) {
    char *sub;
    char *later;
    char *second;
    char *third;
    *(char **)self = lbl_804141b8;
    sub = self + 4;
    ((volatile unsigned char *)sub)[7] = 2;
    later = self + 12;
    second = self + 20;
    third = self + 28;
    *(int *)(sub + 4) = ((volatile unsigned char *)sub)[7];
    *(int *)(self + 12) = 0;
    *(volatile int *)(later + 4) = 0;
    *(short *)(self + 4) = 0;
    *(short *)(sub + 2) = 0;
    *(char **)self = lbl_80414170;
    *(int *)(self + 20) = 0;
    *(volatile int *)(second + 4) = 0;
    *(volatile int *)(third + 4) = 0;
    return self;
}
