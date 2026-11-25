#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
struct S19Ctx { char pad0[52]; int tick; };
extern void *FUN_801613f0(void *, int);
extern void *w3d_message_float_init(void *, int, float);
extern int w3d_message_post_current(void *);
extern struct S19Ctx *w3d_engine_get_context(void);
extern void FUN_800faa44(int, int, float);
extern void *lbl_804b1754;

void s19_send_float_800a7ca0(void *self, int id, float value)
{
    if (FIELD(self, int, 180) != 0)
        w3d_message_post_current(w3d_message_float_init(FUN_801613f0(lbl_804b1754, 12), id, value));
    else
        FUN_800faa44(id, w3d_engine_get_context()->tick + 10, value);
}
