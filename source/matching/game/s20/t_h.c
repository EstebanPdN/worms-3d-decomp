typedef struct S { char pad[12]; void *held; } S;
extern char fn_8020b680(void *);
char w3d_s20_x_8019013c(S *s) { return s->held ? fn_8020b680(s->held) : 0; }
