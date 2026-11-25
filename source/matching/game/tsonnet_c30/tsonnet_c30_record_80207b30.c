/* Reference-only: len + n may wrap, and the resulting stack allocation and
   input lengths have not been validated for arbitrary callers or platforms. */
/* Reference-only: posts a record to the optional service object. When extra
   text is given, the data and the text are concatenated in a stack buffer
   (alloca) first. The service object, the enable word and the vtable slot are
   inferred from offsets; the two copy declarations name the one copy routine
   at 0x802eee50 with and without a prototype, as the original call sites. */
typedef unsigned int size_t;
extern void fn_80207a58(void *a);
extern size_t fn_802ef9c0(const char *);
extern void *fn_802eee50(void *, const void *, size_t);
extern void *w3d_copy_802eee50(void *, const void *, size_t, ...);
typedef struct Svc { void **vt; } Svc;
extern Svc *lbl_804b0660;
extern int lbl_804b0664;

void tsonnet_c30_record_80207b30(int a0, unsigned id, const char *data, size_t len, const char *extra) {
    if (lbl_804b0660 && lbl_804b0664) fn_80207a58(a0);
    if (extra) {
        size_t n = fn_802ef9c0(extra);
        char *buf = (char *)__builtin_alloca(len + n);
        fn_802eee50(buf, data, len);
        w3d_copy_802eee50(buf + len, extra, n);
        data = buf;
        len += n;
    }
    if (lbl_804b0660) ((void (*)(Svc *, unsigned, const char *, size_t))lbl_804b0660->vt[2])(lbl_804b0660, id & 0x7fff, data, len);
}
