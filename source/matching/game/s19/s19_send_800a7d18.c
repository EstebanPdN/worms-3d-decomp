#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
struct S19Ctx { char pad0[52]; int tick; };
extern void *FUN_801613f0(void *, int);
extern void *w3d_value_range_init_80069a30(void *, int, float, float);
extern int w3d_message_post_current(void *);
extern struct S19Ctx *w3d_engine_get_context(void);
extern void FUN_800fb1b8(int, int, float, float);
extern void *lbl_804b1754;

void s19_send_range_800a7d18(void *self, int id, float a, float b)
{
    if (FIELD(self, int, 180) != 0)
        w3d_message_post_current(w3d_value_range_init_80069a30(FUN_801613f0(lbl_804b1754, 16), id, a, b));
    else
        FUN_800fb1b8(id, w3d_engine_get_context()->tick + 10, a, b);
}
