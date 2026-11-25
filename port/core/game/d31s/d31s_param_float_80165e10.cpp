#include "w3d_ptr.h"
#line 1 "d31s_param_float_80165e10.cpp"
/* GWMP8P rev0 0x80165e10. Appends a default parameter item of type 1 to the real STLport list through
 * the no-argument push_back, fills it and binds it to the target's interface. */
#include "d31s_param_owner.h"
int D31sOwner::w3d_r_set_float(Ptr32<D31sTarget> target, int v) {
    items.push_back();
    D31sItem &x = items.back();
    x.object = target;
    x.value_at(0) = v;
    x.type = 1;
    x.owner = this;
    binder->bind(target, &items.back());
    return 0;
}


