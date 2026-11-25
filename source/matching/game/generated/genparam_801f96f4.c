/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct W3dRegistryList { unsigned char head[34]; unsigned short count; } W3dRegistryList;
extern W3dRegistryList w3d_registry_list_80365838;
void fn_8020fd2c(W3dRegistryList *list, void *entry);
extern W3dRegistryList w3d_registry_list_80365868;
extern W3dRegistryList w3d_registry_list_80365898;
extern W3dRegistryList w3d_registry_list_803658c8;

void w3d_registry_unlink_801f96f4(void *object)
{
    fn_8020fd2c(&w3d_registry_list_80365838, (char *)object + 12);
    w3d_registry_list_80365838.count--;
}

void w3d_registry_unlink_801f97a4(void *object)
{
    fn_8020fd2c(&w3d_registry_list_80365868, (char *)object + 8);
    w3d_registry_list_80365868.count--;
}

void w3d_registry_unlink_801fc04c(void *object)
{
    fn_8020fd2c(&w3d_registry_list_80365898, (char *)object + 12);
    w3d_registry_list_80365898.count--;
}

void w3d_registry_unlink_801fc0fc(void *object)
{
    fn_8020fd2c(&w3d_registry_list_803658c8, (char *)object + 8);
    w3d_registry_list_803658c8.count--;
}
