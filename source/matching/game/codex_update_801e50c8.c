typedef struct TerraOnlyCObject TerraOnlyCObject;
typedef struct { void (*slot0)(void); void (*slot1)(void); void (*slot2)(void); void (*slot3)(void); void (*slot4)(TerraOnlyCObject *, float); void (*slot5)(TerraOnlyCObject *, float); } TerraOnlyCTable;
struct TerraOnlyCObject { char unknown[8]; int state; int enabled; char unknown10[12]; TerraOnlyCTable *table; };
extern int terra_only_c_fn_801e4fcc(TerraOnlyCObject *);
extern float terra_only_c_fn_801e5460(TerraOnlyCObject *, void *);
extern float terra_only_c_fn_801e51c8(TerraOnlyCObject *, void *);
extern float terra_only_c_fn_801e5314(TerraOnlyCObject *, void *);
extern float terra_only_c_fn_801e560c(TerraOnlyCObject *, void *);
extern void terra_only_c_fn_801e5908(TerraOnlyCObject *, float);
extern void terra_only_c_fn_801e5960(TerraOnlyCObject *, float);
extern void terra_only_c_fn_801e50b8(TerraOnlyCObject *);
void codex_update_801e50c8(TerraOnlyCObject *self, int arg1) {
    float a,b,c,d;
    if (self->state == 0 && terra_only_c_fn_801e4fcc(self) && self->enabled != 0) {
        a=terra_only_c_fn_801e5460(self,arg1);
        b=terra_only_c_fn_801e51c8(self,arg1);
        c=terra_only_c_fn_801e5314(self,arg1);
        d=terra_only_c_fn_801e560c(self,arg1);
        self->table->slot5(self,a);
        self->table->slot4(self,b);
        terra_only_c_fn_801e5908(self,c);
        terra_only_c_fn_801e5960(self,d);
        terra_only_c_fn_801e50b8(self);
    }
}
