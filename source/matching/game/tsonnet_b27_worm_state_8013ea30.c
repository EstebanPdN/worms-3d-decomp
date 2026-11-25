/* Worm state transition: when the worm is not current and its state is one of
   two consecutive values, stores a computed value, registers a local record
   and writes a code into the object returned for the worm's handle. Struct
   offsets are observed; field names and meanings are inferred. */
typedef struct { int a; int b; } Tmp;
typedef struct { char p0[112]; int handle; char p1[380]; int state; char p2[180]; int value; } Worm;
extern int fn_80139158(Worm *);
extern int fn_801190d0(void *);
extern char *fn_800fc710(int, Tmp *);
extern void fn_80178474(Tmp *, int);
void tsonnet_b27_worm_state_8013ea30(Worm *w, int arg) {
    if (!fn_80139158(w) && (unsigned)(w->state - 21) <= 1) {
        Tmp t;
        int code = 34;
        w->value = fn_801190d0(arg);
        t.a = 0;
        t.b = 0xe3a8;
        *(int *)(fn_800fc710(w->handle, &t) + 128) = code;
        fn_80178474(&t, 2);
    }
}
