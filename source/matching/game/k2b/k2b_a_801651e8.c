extern char w3d_obj_80361950[];
extern char w3d_obj_803e88cc[];
extern void *w3d_global_804b00c4;
extern void *w3d_global_804b00c8;
extern int w3d_service_get_802ee7dc(void);
extern void * w3d_callback_target_80162ce8(void);
extern void * w3d_s21_construct_8020fbd0(void *, void *, void *, void (*)(void), int, int);
void w3d_k2b_static_init_801651e8(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        w3d_global_804b00c4 = w3d_service_get_802ee7dc();
        w3d_global_804b00c8 = w3d_service_get_802ee7dc();
        w3d_s21_construct_8020fbd0(w3d_obj_80361950, w3d_obj_803e88cc, w3d_obj_80361950, w3d_callback_target_80162ce8, 0, 0);
    }
}
// desc: Appears to be a static initializer that caches two service lookups and constructs a global object with a callback.
