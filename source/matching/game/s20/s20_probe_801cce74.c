/* near miss: 4 words (lis/lfs scheduling) */

extern void fn_801cb41c(char *);
extern char lbl_80415fd8[];
extern float lbl_803ae4a4[];
extern float lbl_803ae4a8[];

char *w3d_s20_construct_box_801cce74(char *self) {
    float low;
    float high;
    char *sub;
    char *vt;
    fn_801cb41c(self);
    *(char **)self = lbl_80415fd8;
    low = lbl_803ae4a4[0];
    high = lbl_803ae4a8[0];
    sub = self + 24;
    *(float *)(self + 24) = low;
    *(volatile float *)(sub + 12) = high;
    *(volatile float *)(sub + 8) = low;
    *(volatile float *)(sub + 4) = low;
    *(int *)(self + 40) = 0;
    *(int *)(self + 44) = 0;
    *(int *)(self + 48) = 0;
    *(int *)(self + 52) = 0;
    return self;
}
