struct S19Ctx { char pad0[440]; char *grid; };
extern int lbl_804b179c;
extern unsigned lbl_804b1798;
extern int lbl_804b17a0;
extern struct { void **table; int pad[3]; } lbl_8043bb64;
extern struct S19Ctx *w3d_get_800b4d98(void *);
extern int FUN_8002c73c(void *, unsigned, unsigned, unsigned, int);

void s19_test_cell_800bd954(void)
{
    int result = 0;
    int index = lbl_804b179c;
    unsigned packed = lbl_804b1798;
    unsigned z = (packed >> 16) & 255;
    unsigned y = (packed >> 8) & 255;
    unsigned x = packed & 255;
    struct S19Ctx *ctx = w3d_get_800b4d98(*(void **)((char *)lbl_8043bb64.table + (index << 2)));
    if (FUN_8002c73c(ctx->grid + 32, x, y, z, 4))
        result = 1;
    lbl_804b17a0 = result;
}
