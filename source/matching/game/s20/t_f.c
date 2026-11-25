extern int fn_8020b680(void *);
typedef struct S { char pad[12]; void *held; } S;
int w3d_s20_x_8019013c(S *s) { void *h; int r; h = s->held; r = 0; if (h) r = fn_8020b680(h); return r; }
