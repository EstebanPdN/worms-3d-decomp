extern void *lbl_804ae5e0;
extern int lbl_804b1854;
extern unsigned lbl_804b1858;
extern struct { void **table; int pad[3]; } lbl_8043bb64;
extern void *w3d_constructor_native_cast(void *);
extern int w3d_auto_80178d1c(void *);
extern void FUN_800b46bc(void *, unsigned, unsigned, unsigned);

void s19_apply_cell_800bd9d0(void)
{
    if (!w3d_auto_80178d1c(w3d_constructor_native_cast(lbl_804ae5e0))) {
        int index = lbl_804b1854;
        unsigned packed = lbl_804b1858;
        FUN_800b46bc(*(void **)((char *)lbl_8043bb64.table + (index << 2)), packed & 255, (packed >> 8) & 255, (packed >> 16) & 255);
    }
}
