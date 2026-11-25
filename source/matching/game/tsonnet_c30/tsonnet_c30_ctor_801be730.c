/* Reference-only: constructor of a held-base object. The two 64-byte members
   are copies of the same external 64-byte record and the count field is zero;
   layout and meaning are inferred from offsets. */
typedef struct { int w[16]; } Block64;
extern void *fn_801b4e94(void *self, void *);
extern char lbl_80415050[];
extern Block64 lbl_8045e708[];
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))

void *tsonnet_c30_ctor_801be730(void *self, void * arg_r4) {
    fn_801b4e94(self, arg_r4);
    FIELD(self, void *, 0) = lbl_80415050;
    FIELD(self, Block64, 48) = lbl_8045e708[0];
    FIELD(self, Block64, 112) = lbl_8045e708[0];
    FIELD(self, int, 176) = 0;
    return self;
}
