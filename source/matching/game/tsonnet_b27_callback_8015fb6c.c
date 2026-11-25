/* Registers a callback in a list embedded at offset 24 of the owner. The
   two-word descriptor is copied first; when its low halfword is zero, the
   original supplies a default descriptor from an external table (unowned data
   at 0x803a45c4). Names and field meanings are inferred. */
typedef struct { int first; int second; } Pair;
extern Pair lbl_803a45c4[];
extern void fn_8015f7e0(void *, void *, int, void *, int, Pair *);
int tsonnet_b27_callback_8015fb6c(char *self, int a, void *node, int b, Pair *p) {
    Pair v = *p;
    Pair q;
    if ((short)v.first != 0) {
        q = v;
        fn_8015f7e0(node, self + 24, a, self, b, &q);
    } else {
        q = lbl_803a45c4[0];
        fn_8015f7e0(node, self + 24, a, self, b, &q);
    }
    return 0;
}
