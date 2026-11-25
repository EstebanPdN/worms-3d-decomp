#include "w3d_ptr.h"
#line 1 "s6_ai_lifecycle.cpp"
extern "C" {
struct S6AiVector { Ptr32<char> begin; Ptr32<char> end; Ptr32<char> limit; int reserved; };
extern Ptr32<S6AiVector> w3d_ai_vector_804aa558;
extern Ptr32<S6AiVector> w3d_ai_vector_804aa55c;
extern Ptr32<S6AiVector> w3d_ai_vector_804aa560;
extern Ptr32<S6AiVector> w3d_ai_vector_804aa750;
extern Ptr32<S6AiVector> w3d_ai_vector_804aa754;
extern Ptr32<S6AiVector> w3d_ai_vector_804aa75c;
extern Ptr32<S6AiVector> w3d_ai_vector_804aa564;
extern Ptr32<void> w3d_ai_delays_804aa5a8;
extern float w3d_ai_cost_804aa570;
extern int w3d_ai_flag_804aa56c, w3d_ai_flag_804aa578, w3d_ai_flag_804aa57c;
extern const float w3d_f32_803694e4[];
Ptr32<void> w3d_auto_8001523c(unsigned int);
Ptr32<void> w3d_heap_allocate_entry_a(unsigned int);
void w3d_fn_80019978();
void w3d_fn_80015d40();
void w3d_ai_planner_set_state(int);
void w3d_vector_destroy_virtual12(Ptr32<void>);
void w3d_vector_destroy_named(Ptr32<void>);
void memcpy(...);
void w3d_ai_initialize_vectors_800067a8() {
    Ptr32<S6AiVector> v = (Ptr32<S6AiVector>)w3d_auto_8001523c(16);
    v->limit = 0; v->end = 0; v->begin = 0; w3d_ai_vector_804aa558 = v;
    Ptr32<S6AiVector> v2 = (Ptr32<S6AiVector>)w3d_auto_8001523c(16);
    v2->limit = 0; v2->end = 0; v2->begin = 0; w3d_ai_vector_804aa55c = v2;
    Ptr32<S6AiVector> v3 = (Ptr32<S6AiVector>)w3d_auto_8001523c(16);
    v3->limit = 0; v3->end = 0; v3->begin = 0; w3d_ai_vector_804aa560 = v3;
    Ptr32<S6AiVector> v4 = (Ptr32<S6AiVector>)w3d_auto_8001523c(16);
    v4->limit = 0; v4->end = 0; v4->begin = 0; w3d_ai_vector_804aa750 = v4;
    Ptr32<S6AiVector> v5 = (Ptr32<S6AiVector>)w3d_auto_8001523c(16);
    v5->limit = 0; v5->end = 0; v5->begin = 0; w3d_ai_vector_804aa754 = v5;
    w3d_fn_80019978();
    Ptr32<S6AiVector> v6 = (Ptr32<S6AiVector>)w3d_heap_allocate_entry_a(12);
    w3d_ai_vector_804aa75c = v6; v6->end = 0; v6->begin = 0; v6->limit = 0;
    Ptr32<S6AiVector> v7 = (Ptr32<S6AiVector>)w3d_auto_8001523c(16);
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


