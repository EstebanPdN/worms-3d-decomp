/* Virtual-call helper (session 47b5d14a, hand-matched).
 * Offsets come from the original instructions; meanings are inferred. */

typedef struct W3dObject_801ee410 W3dObject_801ee410;
typedef struct W3dObjectVtbl_801ee410 {
    void *slots[4];
    void (*finish)(W3dObject_801ee410 *self);       /* +16 */
    void *slot20;
    int (*result)(W3dObject_801ee410 *self);        /* +24 */
} W3dObjectVtbl_801ee410;
struct W3dObject_801ee410 {
    W3dObjectVtbl_801ee410 *vtbl;
};

int w3d_h1_result_then_finish_801ee410(W3dObject_801ee410 *self)
{
    int result = self->vtbl->result(self);
    self->vtbl->finish(self);
    return result;
}
