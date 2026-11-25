extern int FUN_800b6800(void *);
extern int lbl_804b17ac;
extern struct { char *table; int pad[3]; } lbl_8043bb64;
void s19_dispatch_indexed_800bd920(void) {
    int i = lbl_804b17ac;
    FUN_800b6800(*(void **)(lbl_8043bb64.table + (i << 2)));
}
