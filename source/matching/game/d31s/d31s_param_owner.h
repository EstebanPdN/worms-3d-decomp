/* The owner of the 0x80165924 family; see d31s_param_item.h. */
#ifndef D31S_PARAM_OWNER_H
#define D31S_PARAM_OWNER_H
#include "d31s_param_item.h"
struct D31sPair { int first; int second; D31sPair() { first = 0; second = 0; } };
struct D31sFullTag : D31sTagBase {
    D31sPair pair;
    D31sFullTag() { a = 0; b = 0; }
};
struct D31sOwnerRoot {
    virtual int query(const void *id, void **out) = 0;
    virtual int retain() = 0;
    virtual int release() = 0;
    virtual int set_scalar(D31sTarget *target, int v) = 0;
    virtual int remove_a(D31sTarget *target) = 0;
    virtual int set_float(D31sTarget *target, int v) = 0;
    virtual int remove_b(D31sTarget *target) = 0;
    virtual int set_element(D31sTarget *target, int v, int index) = 0;
    virtual int remove_c(D31sTarget *target) = 0;
    virtual int drain() = 0;
    virtual int lookup() = 0;
};
struct D31sOwnerApi : D31sOwnerRoot, D31sFullTag {};
struct D31sOwner : D31sOwnerApi {
    D31sBinder *binder;
    _STL::list<D31sItem> items;
    D31sOwner();
    virtual int query(const void *id, void **out);
    virtual int retain();
    virtual int release();
    virtual int set_scalar(D31sTarget *target, int v);
    virtual int remove_a(D31sTarget *target);
    virtual int set_float(D31sTarget *target, int v);
    virtual int remove_b(D31sTarget *target);
    virtual int set_element(D31sTarget *target, int v, int index);
    virtual int remove_c(D31sTarget *target);
    virtual int drain();
    virtual int lookup();
};
#endif
