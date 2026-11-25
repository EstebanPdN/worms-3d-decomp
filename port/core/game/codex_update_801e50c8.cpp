#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "codex_update_801e50c8.c"
typedef struct TerraOnlyCObject TerraOnlyCObject;
typedef struct { Ptr32<void (void)> slot0; Ptr32<void (void)> slot1; Ptr32<void (void)> slot2; Ptr32<void (void)> slot3; Ptr32<void (Ptr32<TerraOnlyCObject>, float)> slot4; Ptr32<void (Ptr32<TerraOnlyCObject>, float)> slot5; } TerraOnlyCTable;
struct TerraOnlyCObject { char unknown[8]; int state; int enabled; char unknown10[12]; Ptr32<TerraOnlyCTable> table; };
extern int terra_only_c_fn_801e4fcc(Ptr32<TerraOnlyCObject>);
extern float terra_only_c_fn_801e5460(Ptr32<TerraOnlyCObject>, Ptr32<void>);
extern float terra_only_c_fn_801e51c8(Ptr32<TerraOnlyCObject>, Ptr32<void>);
extern float terra_only_c_fn_801e5314(Ptr32<TerraOnlyCObject>, Ptr32<void>);
extern float terra_only_c_fn_801e560c(Ptr32<TerraOnlyCObject>, Ptr32<void>);
extern void terra_only_c_fn_801e5908(Ptr32<TerraOnlyCObject>, float);
extern void terra_only_c_fn_801e5960(Ptr32<TerraOnlyCObject>, float);
extern void terra_only_c_fn_801e50b8(Ptr32<TerraOnlyCObject>);
void codex_update_801e50c8(Ptr32<TerraOnlyCObject> self, int arg1) {
    float a,b,c,d;
    if (self->state == 0 && terra_only_c_fn_801e4fcc(self) && self->enabled != 0) {
        a=terra_only_c_fn_801e5460(self,w3d::G(arg1));
        b=terra_only_c_fn_801e51c8(self,w3d::G(arg1));
        c=terra_only_c_fn_801e5314(self,w3d::G(arg1));
        d=terra_only_c_fn_801e560c(self,w3d::G(arg1));
        self->table->slot5(self,a);
        self->table->slot4(self,b);
        terra_only_c_fn_801e5908(self,c);
        terra_only_c_fn_801e5960(self,d);
        terra_only_c_fn_801e50b8(self);
    }
}

}
