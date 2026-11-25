/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct W3dPropertyInfo {
    const char *name;
    unsigned short size;
    unsigned char unknown_06;
    unsigned char type;
    void *descriptor;
    void *extra;
    int unknown_10;
} W3dPropertyInfo;
extern W3dPropertyInfo w3d_property_8045d0fc;
extern int w3d_property_guard_804b03d0;
extern char w3d_string_803ab620[];
extern char w3d_descriptor_8045e004[];
extern char w3d_extra_803fe540[];
void *memset();
int fn_801eff8c(void *self, W3dPropertyInfo *info);
int fn_801e8d9c(void *self);
extern W3dPropertyInfo w3d_property_8045d804;
extern int w3d_property_guard_804b0538;
extern char w3d_string_803ad844[];
extern char w3d_extra_803fe624[];
extern W3dPropertyInfo w3d_property_80464b1c;
extern int w3d_property_guard_804b0804;
extern char w3d_string_803ba528[];
extern char w3d_extra_80400814[];
extern W3dPropertyInfo w3d_property_80464b30;
extern int w3d_property_guard_804b0808;
extern char w3d_string_803ba544[];
extern char w3d_extra_80400820[];
extern W3dPropertyInfo w3d_property_80464b44;
extern int w3d_property_guard_804b080c;
extern char w3d_string_803ba72c[];
extern char w3d_extra_8040082c[];
extern W3dPropertyInfo w3d_property_80464b6c;
extern int w3d_property_guard_804b0814;
extern char w3d_string_803bab34[];
extern char w3d_extra_80400b60[];
extern W3dPropertyInfo w3d_property_80464b80;
extern int w3d_property_guard_804b0818;
extern char w3d_string_803bac10[];
extern char w3d_extra_80400b78[];
extern W3dPropertyInfo w3d_property_80464b94;
extern int w3d_property_guard_804b081c;
extern char w3d_string_803baeb4[];
extern char w3d_extra_80400b84[];
extern W3dPropertyInfo w3d_property_80464ba8;
extern int w3d_property_guard_804b0820;
extern char w3d_string_803bb048[];
extern char w3d_extra_80400b90[];
extern W3dPropertyInfo w3d_property_80464bbc;
extern int w3d_property_guard_804b0824;
extern char w3d_string_803bb0b0[];
extern char w3d_extra_80400b9c[];
extern W3dPropertyInfo w3d_property_80464bd0;
extern int w3d_property_guard_804b0828;
extern char w3d_string_803bb110[];
extern char w3d_extra_80400ba8[];
extern W3dPropertyInfo w3d_property_80464c48;
extern int w3d_property_guard_804b083c;
extern char w3d_string_803bbd64[];
extern char w3d_extra_80400bf0[];

int w3d_property_register_extra_801bae18(void *self)
{
    if (!w3d_property_guard_804b03d0) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803ab620;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045e004;
        info.extra = w3d_extra_803fe540;
        w3d_property_8045d0fc = info;
        w3d_property_guard_804b03d0 = 1;
    }
    fn_801eff8c(self, &w3d_property_8045d0fc);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_extra_801cea94(void *self)
{
    if (!w3d_property_guard_804b0538) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803ad844;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045e004;
        info.extra = w3d_extra_803fe624;
        w3d_property_8045d804 = info;
        w3d_property_guard_804b0538 = 1;
    }
    fn_801eff8c(self, &w3d_property_8045d804);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_extra_8022bf14(void *self)
{
    if (!w3d_property_guard_804b0804) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803ba528;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045e004;
        info.extra = w3d_extra_80400814;
        w3d_property_80464b1c = info;
        w3d_property_guard_804b0804 = 1;
    }
    fn_801eff8c(self, &w3d_property_80464b1c);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_extra_8022c168(void *self)
{
    if (!w3d_property_guard_804b0808) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803ba544;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045e004;
        info.extra = w3d_extra_80400820;
        w3d_property_80464b30 = info;
        w3d_property_guard_804b0808 = 1;
    }
    fn_801eff8c(self, &w3d_property_80464b30);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_extra_8022cd14(void *self)
{
    if (!w3d_property_guard_804b080c) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803ba72c;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045e004;
        info.extra = w3d_extra_8040082c;
        w3d_property_80464b44 = info;
        w3d_property_guard_804b080c = 1;
    }
    fn_801eff8c(self, &w3d_property_80464b44);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_extra_80235f98(void *self)
{
    if (!w3d_property_guard_804b0814) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803bab34;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045e004;
        info.extra = w3d_extra_80400b60;
        w3d_property_80464b6c = info;
        w3d_property_guard_804b0814 = 1;
    }
    fn_801eff8c(self, &w3d_property_80464b6c);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_extra_8023652c(void *self)
{
    if (!w3d_property_guard_804b0818) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803bac10;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045e004;
        info.extra = w3d_extra_80400b78;
        w3d_property_80464b80 = info;
        w3d_property_guard_804b0818 = 1;
    }
    fn_801eff8c(self, &w3d_property_80464b80);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_extra_80236ccc(void *self)
{
    if (!w3d_property_guard_804b081c) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803baeb4;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045e004;
        info.extra = w3d_extra_80400b84;
        w3d_property_80464b94 = info;
        w3d_property_guard_804b081c = 1;
    }
    fn_801eff8c(self, &w3d_property_80464b94);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_extra_802372b0(void *self)
{
    if (!w3d_property_guard_804b0820) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803bb048;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045e004;
        info.extra = w3d_extra_80400b90;
        w3d_property_80464ba8 = info;
        w3d_property_guard_804b0820 = 1;
    }
    fn_801eff8c(self, &w3d_property_80464ba8);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_extra_80237818(void *self)
{
    if (!w3d_property_guard_804b0824) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803bb0b0;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045e004;
        info.extra = w3d_extra_80400b9c;
        w3d_property_80464bbc = info;
        w3d_property_guard_804b0824 = 1;
    }
    fn_801eff8c(self, &w3d_property_80464bbc);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_extra_80237d78(void *self)
{
    if (!w3d_property_guard_804b0828) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803bb110;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045e004;
        info.extra = w3d_extra_80400ba8;
        w3d_property_80464bd0 = info;
        w3d_property_guard_804b0828 = 1;
    }
    fn_801eff8c(self, &w3d_property_80464bd0);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_extra_8023b414(void *self)
{
    if (!w3d_property_guard_804b083c) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803bbd64;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045e004;
        info.extra = w3d_extra_80400bf0;
        w3d_property_80464c48 = info;
        w3d_property_guard_804b083c = 1;
    }
    fn_801eff8c(self, &w3d_property_80464c48);
    fn_801e8d9c(self);
    return 0;
}
