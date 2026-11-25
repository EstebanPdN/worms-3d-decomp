/* Damage costs for the selected and current indexed actors. */
typedef struct { unsigned char unknown00[28]; int damage; } W3dS6ActorCost;
typedef struct { W3dS6ActorCost **begin,**end; } W3dS6ActorCosts;
typedef struct { int kind; float score; unsigned char unknown08[8]; int index; } W3dS6DamagePlan;
extern W3dS6ActorCosts *w3d_ai_entries_804aa750;
extern int w3d_s6_selected_804aa6e8;
extern const float w3d_f32_8036a350[];
float w3d_fn_8000b344(W3dS6DamagePlan *,int,float,float);
#if 0 /* Indexed-load operand order differs in two words. */
void w3d_ai_score_dual_damage_800113b0(W3dS6DamagePlan *plan) {
    int index=w3d_s6_selected_804aa6e8;
    if(index!=-1) plan->score+=w3d_fn_8000b344(plan,index,*w3d_f32_8036a350,(float)(*(W3dS6ActorCost **)((char *)w3d_ai_entries_804aa750->begin+index*4))->damage);
    index=plan->index;
    plan->score+=w3d_fn_8000b344(plan,index,*w3d_f32_8036a350,(float)(*(W3dS6ActorCost **)((char *)w3d_ai_entries_804aa750->begin+index*4))->damage);
}

#endif
