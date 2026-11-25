/* Owner of a real STLport 4.5.3 list of polymorphic 40-byte parameter items (0x80165924 family).
 * Item layout comes from the 48-byte node and field copies; the tag base's kind byte and 24-bit
 * value come from the word read at 0x80210990. Field and class names are inferred. */
#ifndef D31S_PARAM_LIST_H
#define D31S_PARAM_LIST_H
#include "compat/stlport_sn_oom.h"
#include <list>
struct D31sTagBase {
    short a;
    short b;
    unsigned value : 24;
    unsigned kind : 8;
    D31sTagBase() { kind = 2; value = 0; }
    ~D31sTagBase();
};
struct D31sTag : D31sTagBase {
    D31sTag() { a = 0; }
};
struct D31sRoot { virtual void root_slot(); };
struct D31sItemBase : D31sRoot, D31sTag {
    virtual void base_slot();
    virtual ~D31sItemBase() {}
};
struct D31sItem : D31sItemBase {
    int type;
    int values[4];
    void *object;
    void *owner;
    int &value_at(int i) { int *p = values; return p[i]; }
    D31sItem() { for (unsigned i = 0; i < 4; i++) values[i] = 0; }
    virtual void item_slot();
    virtual ~D31sItem() {}
};
struct D31sInterface { virtual void iface_slot(); };
struct D31sObject { int first_word; };
struct D31sTarget : D31sObject, D31sInterface {};
struct D31sBinder {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void bind(D31sInterface *target, D31sItem *item);
    virtual D31sItem *find(D31sInterface *target);
};
struct D31sOwner {
    char unknown[20];
    D31sBinder *binder;
    _STL::list<D31sItem> items;
    int set_scalar(D31sTarget *target, int v);
    int set_float(D31sTarget *target, int v);
    int set_element(D31sTarget *target, int v, int index);
};
#endif
