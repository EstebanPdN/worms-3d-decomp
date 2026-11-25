/* Header constructors followed by cleared fields. */
typedef struct S20Bits {
    char pad[24];
    unsigned char first;
    unsigned char second;
    unsigned int small : 2;
    unsigned int mid : 14;
    unsigned int top : 15;
    unsigned int low : 17;
} S20Bits;
extern char lbl_80413270[];
extern char lbl_80413210[];
extern void * fn_803426b8(char *);

extern char lbl_80413338[];
extern char lbl_804132e0[];

char *w3d_s20_construct_flags_801902e8(char *self) {
    char *sub;
    char *later;
    S20Bits *bits = (S20Bits *)self;
    *(char **)self = lbl_80413270;
    sub = self + 4;
    ((volatile unsigned char *)sub)[7] = 2;
    later = self + 12;
    *(int *)(sub + 4) = ((volatile unsigned char *)sub)[7];
    *(int *)(self + 12) = 0;
    *(volatile int *)(later + 4) = 0;
    *(short *)(self + 4) = 0;
    *(short *)(sub + 2) = 0;
    *(char **)self = lbl_80413210;
    fn_803426b8(self + 20);
    *(unsigned int *)(self + 24) &= 0xffff3fff;
    bits->top = 0;
    bits->first = 0;
    bits->second = 0;
    return self;
}

char *w3d_s20_construct_cleared_80190800(char *self) {
    char *sub;
    char *later;
    char *a;
    char *b;
    char *c;
    char *d;
    char *e;
    char *f;
    volatile char pad[24];
    *(char **)self = lbl_80413338;
    sub = self + 4;
    ((volatile unsigned char *)sub)[7] = 2;
    later = self + 12;
    *(int *)(sub + 4) = ((volatile unsigned char *)sub)[7];
    *(int *)(self + 12) = 0;
    *(volatile int *)(later + 4) = 0;
    *(short *)(self + 4) = 0;
    *(short *)(sub + 2) = 0;
    *(char **)self = lbl_804132e0;
    a = self + 20;
    b = self + 28;
    c = self + 36;
    d = self + 44;
    e = self + 52;
    f = self + 60;
    *(int *)(self + 20) = 0;
    *(int *)(a + 4) = 0;
    *(int *)(b + 4) = 0;
    *(int *)(self + 36) = 0;
    *(int *)(c + 4) = 0;
    *(int *)(d + 4) = 0;
    *(int *)(self + 52) = 0;
    *(int *)(e + 4) = 0;
    *(int *)(f + 4) = 0;
    fn_803426b8(self + 68);
    *(int *)(self + 76) = 0;
    *(int *)(self + 72) = 0;
    return self;
}
