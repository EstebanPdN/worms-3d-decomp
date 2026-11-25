#include "w3d_ptr.h"
#line 1 "genparam_801f7b58.cpp"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef unsigned int size_t;
struct w3d_registry_cb { char head[24]; Ptr32<void> callback; char middle[6]; unsigned short count; };
extern w3d_registry_cb w3d_registry_8045e7b8;
struct w3d_base_4 { int data; };
struct w3d_entry_base { int data; };
extern "C" void fn_8020fd04(Ptr32<w3d_registry_cb> registry, Ptr32<w3d_entry_base> entry);
struct w3d_class_801f7cec : w3d_base_4, w3d_entry_base {
    char rest[28] __attribute__((aligned(__alignof__(w3d_base_4)), aligned(__alignof__(w3d_entry_base))));
    w3d_class_801f7cec();
    static void *operator new(__SIZE_TYPE__ size);
};
extern Ptr32<w3d_class_801f7cec> w3d_singleton_804ab8f8;
extern "C" Ptr32<Ptr32<void>> fn_8020b648(void);
extern "C" char lbl_80418070[];
extern "C" int fn_801f7c10(void);
extern "C" void fn_801f7be8(void);
typedef Ptr32<void (Ptr32<void>, Ptr32<char>, Ptr32<void>)> W3dPublishFn;
extern w3d_registry_cb w3d_registry_80463360;
struct w3d_class_8020dfdc : w3d_base_4, w3d_entry_base {
    char rest[28] __attribute__((aligned(__alignof__(w3d_base_4)), aligned(__alignof__(w3d_entry_base))));
    w3d_class_8020dfdc();
    static void *operator new(__SIZE_TYPE__ size);
};
extern Ptr32<w3d_class_8020dfdc> w3d_singleton_804aba34;
extern "C" char lbl_80419500[];
extern "C" int fn_8020df00(void);
extern "C" void fn_8020ded8(void);

extern "C" void w3d_singleton_create_801f7b58(void)
{
    w3d_singleton_804ab8f8 = new w3d_class_801f7cec;
    fn_8020fd04(&w3d_registry_8045e7b8, w3d_singleton_804ab8f8);
    w3d_registry_8045e7b8.count++;
    Ptr32<Ptr32<void>> manager = fn_8020b648();
    ((W3dPublishFn)((Ptr32<Ptr32<void>>)*manager)[24])(manager, lbl_80418070, w3d_singleton_804ab8f8);
    w3d_registry_8045e7b8.callback = (Ptr32<void>)fn_801f7c10;
    fn_801f7be8();
}

extern "C" void w3d_singleton_create_8020de48(void)
{
    w3d_singleton_804aba34 = new w3d_class_8020dfdc;
    fn_8020fd04(&w3d_registry_80463360, w3d_singleton_804aba34);
    w3d_registry_80463360.count++;
    Ptr32<Ptr32<void>> manager = fn_8020b648();
    ((W3dPublishFn)((Ptr32<Ptr32<void>>)*manager)[24])(manager, lbl_80419500, w3d_singleton_804aba34);
    w3d_registry_80463360.callback = (Ptr32<void>)fn_8020df00;
    fn_8020ded8();
}


