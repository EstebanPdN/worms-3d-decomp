/* Reference PPC32 reconstruction: the integer-to-pointer conversion and
   signed index shift are ABI-specific; valid index bounds are unverified. */
/* Advances a countdown on the object: subtracts the elapsed time since the
   stored stamp from the remaining time, or, once it has run out, reloads it from
   the source object and toggles a mode flag, writing either a global word or a
   value read through a property helper into the service table slot of the given
   index. The slot address is formed with integer arithmetic (offset first)
   because that operand order is the one the original indexed store uses.
   Offsets are observed; field names and meanings are inferred. The unused third
   argument is kept so the parameter registers agree with the original. */
typedef struct { char p0[32]; void *svc; char p1[20]; int mode; unsigned left; unsigned stamp; char p2[8]; void *src; } Obj;
extern void *fn_8034380c(void *);
extern int fn_80178d1c(void *);
extern int *fn_80189760(void *);
extern void * fn_800fd388(int *, ...);
extern int lbl_804af158;
void tsonnet_b32_countdown_800ff56c(Obj *o, int idx, int a5, unsigned now) {
    void *s = fn_8034380c(o->svc);
    unsigned d = now - o->stamp;
    o->stamp = now;
    if (d < o->left) {
        o->left -= d;
        return;
    }
    o->left = fn_80178d1c(o->src);
    if (o->mode) {
        fn_80189760(s)[idx] = lbl_804af158;
        o->mode = 0;
    } else {
        int off = idx << 2;
        char *t = (char *)fn_80189760(s);
        int v;
        fn_800fd388(&v, idx);
        *(int *)(off + (int)t) = v;
        o->mode = 1;
    }
}
