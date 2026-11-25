/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct W3dPropertyInfo {
    const char *name;
    unsigned short size;
    unsigned char unknown_06;
    unsigned char type;
    void *descriptor;
    int unknown_0c;
    int unknown_10;
} W3dPropertyInfo;
extern W3dPropertyInfo w3d_property_8045d020;
extern int w3d_property_guard_804b03a4;
extern char w3d_string_803ab45c[];
extern char w3d_descriptor_8045e2b4[];
void *memset();
int fn_801f23bc(void *self, W3dPropertyInfo *info);
int fn_801e8d9c(void *self);
extern W3dPropertyInfo w3d_property_8045d034;
extern int w3d_property_guard_804b03a8;
extern char w3d_descriptor_8045e314[];
int fn_801f2484(void *self, W3dPropertyInfo *info);
extern W3dPropertyInfo w3d_property_8045d048;
extern int w3d_property_guard_804b03ac;
extern char w3d_descriptor_8045ed7c[];
int fn_801efec4(void *self, W3dPropertyInfo *info);
extern W3dPropertyInfo w3d_property_8045d084;
extern int w3d_property_guard_804b03b8;
extern char w3d_string_803ab53c[];
extern char w3d_descriptor_8045e404[];
int fn_801f22f4(void *self, W3dPropertyInfo *info);
extern W3dPropertyInfo w3d_property_8045d098;
extern int w3d_property_guard_804b03bc;
extern char w3d_descriptor_8045e3bc[];
int fn_801f2290(void *self, W3dPropertyInfo *info);
extern W3dPropertyInfo w3d_property_8045d0ac;
extern int w3d_property_guard_804b03c0;
extern char w3d_descriptor_8045e3d4[];
int fn_801f222c(void *self, W3dPropertyInfo *info);
extern W3dPropertyInfo w3d_property_8045d0c0;
extern int w3d_property_guard_804b03c4;
extern char w3d_string_803ab0f8[];
extern char w3d_descriptor_8045e1dc[];
int fn_801f2164(void *self, W3dPropertyInfo *info);
extern W3dPropertyInfo w3d_property_8045d0d4;
extern int w3d_property_guard_804b03c8;
extern char w3d_descriptor_8045e23c[];
int fn_801f2100(void *self, W3dPropertyInfo *info);
extern W3dPropertyInfo w3d_property_8045d0e8;
extern int w3d_property_guard_804b03cc;
extern char w3d_descriptor_8045e254[];
int fn_801f209c(void *self, W3dPropertyInfo *info);
extern W3dPropertyInfo w3d_property_8045d110;
extern int w3d_property_guard_804b03d4;
extern char w3d_string_803ab640[];
extern char w3d_descriptor_8045e29c[];
int fn_801f2420(void *self, W3dPropertyInfo *info);
extern W3dPropertyInfo w3d_property_8045d124;
extern int w3d_property_guard_804b03d8;
extern W3dPropertyInfo w3d_property_8045d138;
extern int w3d_property_guard_804b03dc;
extern char w3d_descriptor_8045e2fc[];
int fn_801f24e8(void *self, W3dPropertyInfo *info);
extern W3dPropertyInfo w3d_property_8045d1b0;
extern int w3d_property_guard_804b03f4;
extern char w3d_string_803abbec[];
extern char w3d_descriptor_8045edc4[];
int fn_801eff28(void *self, W3dPropertyInfo *info);
extern W3dPropertyInfo w3d_property_8045d1c4;
extern int w3d_property_guard_804b03f8;
extern char w3d_string_803abc10[];
extern char w3d_descriptor_8045ed4c[];
int fn_801efdfc(void *self, W3dPropertyInfo *info);
extern W3dPropertyInfo w3d_property_8045d570;
extern int w3d_property_guard_804b04b4;
extern char w3d_string_803ac8b0[];
extern W3dPropertyInfo w3d_property_80464b58;
extern int w3d_property_guard_804b0810;
extern char w3d_string_803bab34[];
extern char w3d_descriptor_8045ed94[];
int fn_801efff0(void *self, W3dPropertyInfo *info);
extern W3dPropertyInfo w3d_property_80464d10;
extern int w3d_property_guard_804b0864;
extern char w3d_string_803beb58[];
extern W3dPropertyInfo w3d_property_80464d60;
extern int w3d_property_guard_804b0874;
extern char w3d_string_803c0568[];
extern W3dPropertyInfo w3d_property_80464d74;
extern int w3d_property_guard_804b0878;
extern char w3d_string_803c0590[];

int w3d_property_register_801b8f94(void *self)
{
    if (!w3d_property_guard_804b03a4) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803ab45c;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045e2b4;
        w3d_property_8045d020 = info;
        w3d_property_guard_804b03a4 = 1;
    }
    fn_801f23bc(self, &w3d_property_8045d020);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_801b91dc(void *self)
{
    if (!w3d_property_guard_804b03a8) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803ab45c;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045e314;
        w3d_property_8045d034 = info;
        w3d_property_guard_804b03a8 = 1;
    }
    fn_801f2484(self, &w3d_property_8045d034);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_801b9794(void *self)
{
    if (!w3d_property_guard_804b03ac) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803ab45c;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045ed7c;
        w3d_property_8045d048 = info;
        w3d_property_guard_804b03ac = 1;
    }
    fn_801efec4(self, &w3d_property_8045d048);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_801b9cf8(void *self)
{
    if (!w3d_property_guard_804b03b8) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803ab53c;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045e404;
        w3d_property_8045d084 = info;
        w3d_property_guard_804b03b8 = 1;
    }
    fn_801f22f4(self, &w3d_property_8045d084);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_801ba0cc(void *self)
{
    if (!w3d_property_guard_804b03bc) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803ab53c;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045e3bc;
        w3d_property_8045d098 = info;
        w3d_property_guard_804b03bc = 1;
    }
    fn_801f2290(self, &w3d_property_8045d098);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_801ba314(void *self)
{
    if (!w3d_property_guard_804b03c0) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803ab53c;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045e3d4;
        w3d_property_8045d0ac = info;
        w3d_property_guard_804b03c0 = 1;
    }
    fn_801f222c(self, &w3d_property_8045d0ac);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_801ba55c(void *self)
{
    if (!w3d_property_guard_804b03c4) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803ab0f8;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045e1dc;
        w3d_property_8045d0c0 = info;
        w3d_property_guard_804b03c4 = 1;
    }
    fn_801f2164(self, &w3d_property_8045d0c0);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_801ba7a4(void *self)
{
    if (!w3d_property_guard_804b03c8) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803ab0f8;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045e23c;
        w3d_property_8045d0d4 = info;
        w3d_property_guard_804b03c8 = 1;
    }
    fn_801f2100(self, &w3d_property_8045d0d4);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_801ba9ec(void *self)
{
    if (!w3d_property_guard_804b03cc) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803ab0f8;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045e254;
        w3d_property_8045d0e8 = info;
        w3d_property_guard_804b03cc = 1;
    }
    fn_801f209c(self, &w3d_property_8045d0e8);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_801bb06c(void *self)
{
    if (!w3d_property_guard_804b03d4) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803ab640;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045e29c;
        w3d_property_8045d110 = info;
        w3d_property_guard_804b03d4 = 1;
    }
    fn_801f2420(self, &w3d_property_8045d110);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_801bb2b4(void *self)
{
    if (!w3d_property_guard_804b03d8) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803ab640;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045e2b4;
        w3d_property_8045d124 = info;
        w3d_property_guard_804b03d8 = 1;
    }
    fn_801f23bc(self, &w3d_property_8045d124);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_801bb4fc(void *self)
{
    if (!w3d_property_guard_804b03dc) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803ab640;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045e2fc;
        w3d_property_8045d138 = info;
        w3d_property_guard_804b03dc = 1;
    }
    fn_801f24e8(self, &w3d_property_8045d138);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_801bda2c(void *self)
{
    if (!w3d_property_guard_804b03f4) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803abbec;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045edc4;
        w3d_property_8045d1b0 = info;
        w3d_property_guard_804b03f4 = 1;
    }
    fn_801eff28(self, &w3d_property_8045d1b0);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_801bdc74(void *self)
{
    if (!w3d_property_guard_804b03f8) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803abc10;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045ed4c;
        w3d_property_8045d1c4 = info;
        w3d_property_guard_804b03f8 = 1;
    }
    fn_801efdfc(self, &w3d_property_8045d1c4);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_801c3b64(void *self)
{
    if (!w3d_property_guard_804b04b4) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803ac8b0;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045e2b4;
        w3d_property_8045d570 = info;
        w3d_property_guard_804b04b4 = 1;
    }
    fn_801f23bc(self, &w3d_property_8045d570);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_80235a44(void *self)
{
    if (!w3d_property_guard_804b0810) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803bab34;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045ed94;
        w3d_property_80464b58 = info;
        w3d_property_guard_804b0810 = 1;
    }
    fn_801efff0(self, &w3d_property_80464b58);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_80242d40(void *self)
{
    if (!w3d_property_guard_804b0864) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803beb58;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045ed94;
        w3d_property_80464d10 = info;
        w3d_property_guard_804b0864 = 1;
    }
    fn_801efff0(self, &w3d_property_80464d10);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_802445f8(void *self)
{
    if (!w3d_property_guard_804b0874) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803c0568;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045ed94;
        w3d_property_80464d60 = info;
        w3d_property_guard_804b0874 = 1;
    }
    fn_801efff0(self, &w3d_property_80464d60);
    fn_801e8d9c(self);
    return 0;
}

int w3d_property_register_80244840(void *self)
{
    if (!w3d_property_guard_804b0878) {
        W3dPropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = w3d_string_803c0590;
        info.size = 20;
        info.type = 9;
        info.descriptor = w3d_descriptor_8045ed94;
        w3d_property_80464d74 = info;
        w3d_property_guard_804b0878 = 1;
    }
    fn_801efff0(self, &w3d_property_80464d74);
    fn_801e8d9c(self);
    return 0;
}
