typedef struct { int value; int rest[2]; } Text;
typedef struct { char pad[28]; int sink; int a,b; } First;
typedef struct { char pad[32]; int sink; int a,b; } Second;
extern int fn_802cd14c(int), fn_802cd07c(int);
extern int fn_802cd220(Text *), fn_802cd128(Text *);
extern int fn_803426b8(Text *), fn_802cbf2c(Text *, int, int);
extern int fn_802cbdf8(int, int, int), fn_8020c5c4(Text *), fn_80341588(Text *);
extern int lbl_803f3f7c[], lbl_803f4b50[];
void tterra_a33_8004fda4(First *p) {
 Text t; int *s;
 fn_802cd14c(p->sink); fn_802cd07c(p->sink); fn_803426b8(&t);
 s=lbl_803f3f7c; if (*s) do { fn_802cbf2c(&t,*s,7); ++s; } while (*s);
 fn_802cbdf8(p->sink,t.value,9); p->a=0; p->b=0;
 fn_8020c5c4(&t); fn_80341588(&t);
}
void tterra_a33_80098f24(Second *p) {
 Text t; int *s;
 fn_803426b8(&t); fn_802cd220(&t); fn_802cd128(&t);
 s=lbl_803f4b50; if (*s) do { fn_802cbf2c(&t,*s,7); ++s; } while (*s);
 fn_802cbdf8(p->sink,t.value,9); p->a=0; p->b=0;
 fn_8020c5c4(&t); fn_80341588(&t);
}
