/* Applies death-worm damage and weighted score adjustments. */
typedef struct { unsigned char unknown00[28]; int damage; } W3dS6ActorCost;
typedef struct { W3dS6ActorCost **begin,**end; } W3dS6ActorCosts;
typedef struct { int kind; float score; unsigned char unknown08[56]; unsigned char flag; } W3dS6DeathPlan;
typedef struct { unsigned char unknown00[88]; float a,b; unsigned char unknown60[324]; float scale; } W3dS6DeathSettings;
extern W3dS6ActorCosts *w3d_ai_entries_804aa750;
extern W3dS6DeathSettings *w3d_s6_settings_804aa6d8;
extern int w3d_s6_selected_804aa6e8;
extern const char w3d_str_8036a358[];
extern const float w3d_f32_8036a380[];
void w3d_fn_800fc270(const char **,float *);
void w3d_auto_8000b2f8(W3dS6DeathPlan *,int);
float w3d_fn_8000b4c4(W3dS6DeathPlan *,float,float,float,float);
void w3d_ai_scale_exposure_8000b7dc(W3dS6DeathPlan *);
#if 0 /* Stack frame and indexed-load operand order differ. */
void w3d_ai_score_death_damage_80011950(W3dS6DeathPlan *plan,float damage,float radius) {
    const char *name;
    float extra;
    int index;
    w3d_auto_8000b2f8(plan,1);
    index=w3d_s6_selected_804aa6e8;
    if(index!=-1 && damage >= (float)w3d_ai_entries_804aa750->begin[index]->damage) {
        name=w3d_str_8036a358;
        w3d_fn_800fc270(&name,&extra);
        damage+=extra;
    }
    plan->score+=w3d_fn_8000b4c4(plan,radius,w3d_s6_settings_804aa6d8->b,w3d_s6_settings_804aa6d8->a,damage);
    w3d_ai_scale_exposure_8000b7dc(plan);
    plan->score*=w3d_s6_settings_804aa6d8->scale;
    if(plan->flag) plan->score*=*w3d_f32_8036a380;
}

#endif
