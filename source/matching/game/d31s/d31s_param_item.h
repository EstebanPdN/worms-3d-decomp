/* Parameter owner holding a real STLport 4.5.3 list of 40-byte reference-counted items
 * (0x80165924 family). The vtables in the DOL witness the classes: 0x80411ac0 is a three-slot pure
 * interface, 0x80411a70 the item, 0x80411a88 an eleven-slot pure interface and 0x80411a30 the owner,
 * none with a destructor slot and all with a null type_info word. Without new virtuals the middle
 * class reuses its base's table. Names are inferred. */
#ifndef D31S_PARAM_ITEM_H
#define D31S_PARAM_ITEM_H
#pragma interface
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
struct D31sCounted {
    virtual int query(const void *id, void **out) = 0;
    virtual int retain() = 0;
    virtual int release() = 0;
};
struct D31sItemBase : D31sCounted, D31sTag {};
struct D31sItem : D31sItemBase {
    int type;
    int values[4];
    void *object;
    void *owner;
    int &value_at(int i) { int *p = values; return p[i]; }
    D31sItem() { for (unsigned i = 0; i < 4; i++) values[i] = 0; }
    virtual int query(const void *id, void **out);
    virtual int retain();
    virtual int release();
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
#endif
