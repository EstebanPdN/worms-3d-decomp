#include "w3d_ptr.h"
#line 1 "genparam_801b2ab8.cpp"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef unsigned int size_t;
struct w3d_registry_cb { char head[24]; Ptr32<void> callback; char middle[6]; unsigned short count; };
extern w3d_registry_cb w3d_registry_8045ce60;
struct w3d_base_4 { int data; };
struct w3d_entry_base { int data; };
extern "C" void fn_8020fd04(Ptr32<w3d_registry_cb> registry, Ptr32<w3d_entry_base> entry);
struct w3d_class_801b2c4c : w3d_base_4, w3d_entry_base {
    char rest[96] __attribute__((aligned(__alignof__(w3d_base_4)), aligned(__alignof__(w3d_entry_base))));
    w3d_class_801b2c4c();
    static void *operator new(__SIZE_TYPE__ size);
};
extern Ptr32<w3d_class_801b2c4c> w3d_singleton_804ab7a4;
extern "C" Ptr32<Ptr32<void>> fn_8020b648(void);
extern "C" char lbl_804143e0[];
extern "C" int fn_801b2b70(void);
extern "C" void fn_801b2b48(void);
typedef Ptr32<void (Ptr32<void>, Ptr32<char>, Ptr32<void>)> W3dPublishFn;

extern "C" void w3d_singleton_create_801b2ab8(void)
{
    w3d_singleton_804ab7a4 = new w3d_class_801b2c4c;
    fn_8020fd04(&w3d_registry_8045ce60, w3d_singleton_804ab7a4);
    w3d_registry_8045ce60.count++;
    Ptr32<Ptr32<void>> manager = fn_8020b648();
    ((W3dPublishFn)((Ptr32<Ptr32<void>>)*manager)[24])(manager, lbl_804143e0, w3d_singleton_804ab7a4);
    w3d_registry_8045ce60.callback = (Ptr32<void>)fn_801b2b70;
    fn_801b2b48();
}


