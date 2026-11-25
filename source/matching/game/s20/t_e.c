extern int fn_8020b680(void *);
typedef struct S { char pad[12]; void *held; } S;
int w3d_s20_x_8019013c(S *s) { void *h = s->held; if (h == 0) return 0; return fn_8020b680(h); }
