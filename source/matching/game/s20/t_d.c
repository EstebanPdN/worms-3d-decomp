extern int fn_8020b680(void *);
typedef struct S { char pad[12]; void *held; } S;
int w3d_s20_x_8019013c(S *s) { if (!s->held) return 0; return fn_8020b680(s->held); }
