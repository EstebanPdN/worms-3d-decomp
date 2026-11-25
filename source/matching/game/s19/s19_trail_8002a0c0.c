#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
extern float w3d_motion_get_2c_800668ec(void *);
extern void *w3d_s10_service_forward_8020b680(void *);
extern int FUN_80164514(void *, void *, int);
extern void FUN_800517a4(void *, void *);
extern unsigned char lbl_8040eb10[];
extern void *lbl_804b178c;
extern void *w3d_s20_lookup_handle_object_80164fc8(int);

void s19_start_trail_8002a0c0(void *self, void *other)
{
    if (w3d_motion_get_2c_800668ec(other) > 20.0f) {
        void *s = w3d_s10_service_forward_8020b680(lbl_8040eb10);
        FUN_800517a4(w3d_s20_lookup_handle_object_80164fc8(FUN_80164514(lbl_804b178c, s, FIELD(self, int, 20))), other);
    }
}
