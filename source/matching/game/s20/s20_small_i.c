/* Forwarding helpers, state swaps and handle checks. */
extern int fn_800e5da0(void *, void *, int, int, float);
extern void *lbl_804aaecc;

int w3d_s20_forward_global_800e5ca4(int a, int b, int c, float arg_f1) {
    if (lbl_804aaecc == 0)
        return 0;
    return fn_800e5da0(lbl_804aaecc, a, b, c, arg_f1);
}

extern int fn_800de16c(char *, void *, void *, void *);
extern int fn_800ddfe4(char *, void *, void *);

int w3d_s20_call_with_swapped_800e7114(char *self, void * arg_r4, void * arg_r5, void * arg_r6) {
    int first = *(int *)(self + 168);
    int second = *(int *)(self + 172);
    int saved_a = *(int *)(self + 100);
    int saved_b = *(int *)(self + 92);
    int result;
    *(int *)(self + 100) = first;
    *(int *)(self + 92) = second;
    result = fn_800de16c(self, arg_r4, arg_r5, arg_r6);
    *(int *)(self + 100) = saved_a;
    *(int *)(self + 92) = saved_b;
    return result;
}

int w3d_s20_call_with_swapped_800e7160(char *self, void * arg_r4, void * arg_r5) {
    int first = *(int *)(self + 168);
    int second = *(int *)(self + 172);
    int saved_a = *(int *)(self + 100);
    int saved_b = *(int *)(self + 92);
    int result;
    *(int *)(self + 100) = first;
    *(int *)(self + 92) = second;
    result = fn_800ddfe4(self, arg_r4, arg_r5);
    *(int *)(self + 100) = saved_a;
    *(int *)(self + 92) = saved_b;
    return result;
}

typedef struct S20HandleHolder152 { char pad[152]; int handle; } S20HandleHolder152;
extern void *fn_80164fc8(int);
extern void fn_800a4d3c(void *, char *);

void w3d_s20_forward_handle_8013dda8(S20HandleHolder152 *self) {
    if (self->handle != -1) {
        void *object = fn_80164fc8(self->handle);
        if (object == 0)
            self->handle = -1;
        else
            fn_800a4d3c(object, (char *)self + 52);
    }
}

extern char *fn_801ecab4(char *, char *);
extern void fn_801e8d9c(char *);
extern char lbl_803ab810[];

int w3d_s20_reset_named_801bc430(char *self) {
    char *result = fn_801ecab4(self, lbl_803ab810);
    *(long long *)(result + 8) = 0;
    fn_801e8d9c(self);
    return 0;
}
