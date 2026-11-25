struct S19Q { char pad0[24]; int f24; };
extern float lbl_804aa570;
extern void w3d_ai_set_query_origin_8000a62c(struct S19Q *);
extern int w3d_ai_capture_query_8000a68c(struct S19Q *, int);
extern int FUN_8001aaf8(int *, float, float);

void s19_ai_query_step_8000a6ec(struct S19Q *p, float v) {
    lbl_804aa570 = lbl_804aa570 + 100.0f;
    w3d_ai_set_query_origin_8000a62c(p);
    w3d_ai_capture_query_8000a68c(p, FUN_8001aaf8(&p->f24, v, 1.0f));
}
