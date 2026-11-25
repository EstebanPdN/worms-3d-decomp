#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
extern void *w3d_s10_service_forward_8020b680(void *);
extern int FUN_80164514(void *, void *, int);
extern unsigned char lbl_80410358[];
extern void *lbl_804b178c;
void s19_register_service_8008e1e0(void *self)
{
    void *s = w3d_s10_service_forward_8020b680(lbl_80410358);
    FUN_80164514(lbl_804b178c, s, FIELD(self, int, 20));
}
