extern "C" {
struct S6AiVector { char *begin; char *end; char *limit; int reserved; };
extern S6AiVector *w3d_ai_vector_804aa558;
extern S6AiVector *w3d_ai_vector_804aa55c;
extern S6AiVector *w3d_ai_vector_804aa560;
extern S6AiVector *w3d_ai_vector_804aa750;
extern S6AiVector *w3d_ai_vector_804aa754;
extern S6AiVector *w3d_ai_vector_804aa75c;
extern S6AiVector *w3d_ai_vector_804aa564;
extern void *w3d_ai_delays_804aa5a8;
extern float w3d_ai_cost_804aa570;
extern int w3d_ai_flag_804aa56c, w3d_ai_flag_804aa578, w3d_ai_flag_804aa57c;
extern const float w3d_f32_803694e4[];
void *w3d_auto_8001523c(unsigned int);
void *w3d_heap_allocate_entry_a(unsigned int);
void w3d_fn_80019978();
void w3d_fn_80015d40();
void w3d_ai_planner_set_state(int);
void w3d_vector_destroy_virtual12(void *);
void w3d_vector_destroy_named(void *);
void memcpy(...);
void w3d_ai_initialize_vectors_800067a8() {
    S6AiVector *v = (S6AiVector *)w3d_auto_8001523c(16);
    v->limit = 0; v->end = 0; v->begin = 0; w3d_ai_vector_804aa558 = v;
    S6AiVector *v2 = (S6AiVector *)w3d_auto_8001523c(16);
    v2->limit = 0; v2->end = 0; v2->begin = 0; w3d_ai_vector_804aa55c = v2;
    S6AiVector *v3 = (S6AiVector *)w3d_auto_8001523c(16);
    v3->limit = 0; v3->end = 0; v3->begin = 0; w3d_ai_vector_804aa560 = v3;
    S6AiVector *v4 = (S6AiVector *)w3d_auto_8001523c(16);
    v4->limit = 0; v4->end = 0; v4->begin = 0; w3d_ai_vector_804aa750 = v4;
    S6AiVector *v5 = (S6AiVector *)w3d_auto_8001523c(16);
    v5->limit = 0; v5->end = 0; v5->begin = 0; w3d_ai_vector_804aa754 = v5;
    w3d_fn_80019978();
    S6AiVector *v6 = (S6AiVector *)w3d_heap_allocate_entry_a(12);
    w3d_ai_vector_804aa75c = v6; v6->end = 0; v6->begin = 0; v6->limit = 0;
    S6AiVector *v7 = (S6AiVector *)w3d_auto_8001523c(16);
    v7->limit = 0; v7->end = 0; v7->begin = 0; w3d_ai_vector_804aa564 = v7;
    w3d_fn_80015d40();
    w3d_ai_delays_804aa5a8 = w3d_auto_8001523c(236);
    w3d_ai_planner_set_state(1);
}
#if 0 /* Three attempts: compiler folds zero-length memcpy calls. */
void w3d_ai_reset_vectors_800066e0() {
    w3d_vector_destroy_virtual12(w3d_ai_vector_804aa558);
    w3d_vector_destroy_virtual12(w3d_ai_vector_804aa55c);
    w3d_vector_destroy_virtual12(w3d_ai_vector_804aa560);
    w3d_vector_destroy_named(w3d_ai_vector_804aa750);
    S6AiVector *v = w3d_ai_vector_804aa754;
    int bytes = v->end - v->begin;
    memcpy(v->begin, v->end, 0);
    v->end -= bytes;
    v = w3d_ai_vector_804aa75c;
    bytes = v->end - v->begin;
    memcpy(v->begin, v->end, 0);
    v->end -= bytes;
    w3d_ai_cost_804aa570 = w3d_f32_803694e4[0];
    w3d_ai_flag_804aa56c = 0;
    w3d_ai_flag_804aa578 = 0;
    w3d_ai_flag_804aa57c = 0;
    w3d_ai_planner_set_state(2);
}
#endif
}
