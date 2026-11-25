#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparam_801f96f4.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct W3dRegistryList { unsigned char head[0x20]; unsigned short count; unsigned short w3d_flags_high; } W3dRegistryList;
extern W3dRegistryList w3d_registry_list_80365838;
void fn_8020fd2c(Ptr32<W3dRegistryList> list, Ptr32<void> entry);
extern W3dRegistryList w3d_registry_list_80365868;
extern W3dRegistryList w3d_registry_list_80365898;
extern W3dRegistryList w3d_registry_list_803658c8;

void w3d_registry_unlink_801f96f4(Ptr32<void> object)
{
    fn_8020fd2c(&w3d_registry_list_80365838, (Ptr32<char>)object + 12);
    w3d_registry_list_80365838.count--;
}

void w3d_registry_unlink_801f97a4(Ptr32<void> object)
{
    fn_8020fd2c(&w3d_registry_list_80365868, (Ptr32<char>)object + 8);
    w3d_registry_list_80365868.count--;
}

void w3d_registry_unlink_801fc04c(Ptr32<void> object)
{
    fn_8020fd2c(&w3d_registry_list_80365898, (Ptr32<char>)object + 12);
    w3d_registry_list_80365898.count--;
}

void w3d_registry_unlink_801fc0fc(Ptr32<void> object)
{
    fn_8020fd2c(&w3d_registry_list_803658c8, (Ptr32<char>)object + 8);
    w3d_registry_list_803658c8.count--;
}

}
