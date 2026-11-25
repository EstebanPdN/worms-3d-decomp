#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct S19Iface { void **vtable; } S19Iface;
typedef void (*S19IfaceFn)(S19Iface *self);
extern int FUN_800b9a48(void *);
extern int FUN_800b9b0c(void *);
extern void FUN_8009081c(void *, int);
extern S19Iface *lbl_804ae548;
extern void *lbl_804b183c;
extern int lbl_804aad30;

void s19_shutdown_800ba5f8(void *self)
{
    void *zero = 0;
    FUN_800b9a48(self);
    FUN_800b9b0c(self);
    if (lbl_804ae548) {
        ((S19IfaceFn)lbl_804ae548->vtable[4])(lbl_804ae548);
    }
    lbl_804ae548 = zero;
    if (lbl_804b183c)
        FUN_8009081c(lbl_804b183c, 3);
    lbl_804b183c = zero;
    lbl_804aad30 = (int)zero;
}
