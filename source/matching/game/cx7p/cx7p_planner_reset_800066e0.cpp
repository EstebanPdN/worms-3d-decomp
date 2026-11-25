// Inferred AI planner reset; begin/end fields +0/+4 in pointer-vector headers.
struct Cx7pPlannerRange {char *begin,*end;};
extern void *plans_804aa558,*costs_804aa55c,*pending_804aa560,*named_804aa750;
extern Cx7pPlannerRange *first_range_804aa754,*second_range_804aa75c;
extern int planner_zero_804aa578,planner_zero_804aa57c,planner_zero_804aa56c;
extern float planner_time_804aa570;extern const float reset_time_803694e4[];
extern "C" void vector_destroy_803414b4(void *);extern "C" void named_destroy_80341518(void *);
extern "C" void *copy_802eee50(void *,const void *,...);
extern "C" void planner_state_800068a8(int);
static inline void clear_range(Cx7pPlannerRange *r){char *end=r->end,*begin=r->begin;int bytes=end-begin;copy_802eee50(begin,end,0);r->end-=bytes;}
extern "C" void w3d_cx7p_planner_reset_800066e0(){int zero=0;
 vector_destroy_803414b4(plans_804aa558);vector_destroy_803414b4(costs_804aa55c);vector_destroy_803414b4(pending_804aa560);named_destroy_80341518(named_804aa750);
 clear_range(first_range_804aa754);{Cx7pPlannerRange *r=second_range_804aa75c;char *begin=r->begin,*end=r->end;int bytes=end-begin;copy_802eee50(begin,end,0);r->end-=bytes;}
 planner_time_804aa570=reset_time_803694e4[0];planner_zero_804aa578=zero;planner_zero_804aa57c=zero;planner_zero_804aa56c=zero;planner_state_800068a8(2);
}
