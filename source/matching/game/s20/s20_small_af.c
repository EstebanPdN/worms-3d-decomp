typedef struct S20Sink { void **vtable; } S20Sink;
typedef int (*S20Sink3)(S20Sink *, char *, char *);
extern char lbl_803a8200[];
extern char lbl_803a820c[];
int w3d_s20_describe_fields_80190538(char *self, S20Sink *sink) {
    ((S20Sink3)sink->vtable[37])(sink, self + 20, lbl_803a8200);
    ((S20Sink3)sink->vtable[28])(sink, self + 24, lbl_803a820c);
    return 0;
}
