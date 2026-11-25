#include "w3d_ptr.h"
#line 1 "d31s_param_element_80166098.cpp"
/* GWMP8P rev0 0x80166098. Updates one element of the item bound to the target; if none is bound,
 * appends an item of type 2, fills that element and binds it. */
#include "d31s_param_owner.h"
int D31sOwner::w3d_r_set_element(Ptr32<D31sTarget> target, int v, int index) {
    Ptr32<D31sItem> found = binder->find(target);
    if (found) {
        found->values[index] = v;
    } else {
        items.push_back();
        D31sItem &x = items.back();
        x.object = target;
        x.value_at(index) = v;
        x.type = 2;
        x.owner = this;
        binder->bind(target, &items.back());
    }
    return 0;
}


