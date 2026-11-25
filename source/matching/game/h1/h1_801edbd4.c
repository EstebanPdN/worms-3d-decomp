/* Global service and task-array shutdown helpers (session 47b5d14a,
 * hand-matched). The service setter is an inline helper: GCC 2.95 keeps an
 * inline parameter in a saved register instead of folding the constant. */

typedef struct W3dService_802cafd0 W3dService_802cafd0;
typedef struct W3dServiceVtbl_802cafd0 {
    void *slots[4];
    void (*release)(W3dService_802cafd0 *self);     /* +16 */
} W3dServiceVtbl_802cafd0;
struct W3dService_802cafd0 {
    W3dServiceVtbl_802cafd0 *vtbl;
};

extern void *w3d_sda_task_array_804b05a8;
extern void *w3d_sda_task_array_804b05ac;
extern void *w3d_sda_task_array_804b05b0;
extern void *w3d_sda_task_array_804b05b4;
extern W3dService_802cafd0 *w3d_sda_service_804b10b0;
extern int w3d_sda_service_state_804abce4;

void w3d_task_array_release_backend(void *array);

int w3d_h1_release_task_arrays_801edbd4(void)
{
    w3d_task_array_release_backend(w3d_sda_task_array_804b05a8);
    w3d_task_array_release_backend(w3d_sda_task_array_804b05ac);
    w3d_task_array_release_backend(w3d_sda_task_array_804b05b0);
    w3d_task_array_release_backend(w3d_sda_task_array_804b05b4);
    w3d_sda_task_array_804b05a8 = 0;
    w3d_sda_task_array_804b05ac = 0;
    w3d_sda_task_array_804b05b0 = 0;
    w3d_sda_task_array_804b05b4 = 0;
    return 0;
}

static inline void w3d_h1_service_set(W3dService_802cafd0 *service, int state)
{
    if (w3d_sda_service_804b10b0)
        w3d_sda_service_804b10b0->vtbl->release(w3d_sda_service_804b10b0);
    w3d_sda_service_state_804abce4 = state;
    w3d_sda_service_804b10b0 = service;
}

void w3d_h1_service_shutdown_802cafd0(void)
{
    w3d_h1_service_set(0, 0);
}
