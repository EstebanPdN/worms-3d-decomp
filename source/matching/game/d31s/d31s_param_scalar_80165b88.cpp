/* GWMP8P rev0 0x80165b88. Appends a default parameter item of type 0 to the real STLport list through
 * the no-argument push_back, fills it and binds it to the target's interface. */
#include "d31s_param_owner.h"
int D31sOwner::set_scalar(D31sTarget *target, int v) {
    items.push_back();
    D31sItem &x = items.back();
    x.object = target;
    x.value_at(0) = v;
    x.type = 0;
    x.owner = this;
    binder->bind(target, &items.back());
    return 0;
}
