/* Adds an item to the owner's list unless the service reports an equal one, holding
 * the service's lock slot around the search. Returns the existing or the new item. */
#include "compat/stlport_sn_oom.h"
#include <vector>

class D29sItem_801b3e88 {
public:
    virtual void slot0();
    virtual void retain();
};
class D29sService_801b3e88 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int differs(D29sItem_801b3e88 *item);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void hold(D29sItem_801b3e88 *item);
};
class D29sOwner_801b3e88 {
public:
    D29sItem_801b3e88 *add_unique(D29sItem_801b3e88 *item);

private:
    char head[24];
    D29sService_801b3e88 *service;
    char gap[60];
    std::vector<D29sItem_801b3e88 *> items;
};

D29sItem_801b3e88 *D29sOwner_801b3e88::add_unique(D29sItem_801b3e88 *item) {
    service->hold(item);
    for (D29sItem_801b3e88 **it = items.begin(), **end = items.end(); it != end; ++it) {
        if (!service->differs(*it)) {
            service->hold(0);
            return *it;
        }
    }
    items.push_back(item);
    item->retain();
    service->hold(0);
    return item;
}
