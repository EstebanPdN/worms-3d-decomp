struct s8_VisibilityGroup {
    char pad0[28];
    int visible;
    void *object32, *object36, *object40, *object44, *object48, *object52;
    void *unused56, *object60, *unused64, *object68;
};
extern "C" void *fn_80164fc8(void *);
extern "C" void fn_8002900c(void *,int);
extern "C" void fn_800f0c20(void *,int);
extern "C" void fn_801315a0(void *,int);
extern "C" void fn_800ff634(void *,int);
extern "C" void fn_800a3010(void *,int);
extern "C" void fn_80065c94(void *,int);
extern "C" void fn_800a14c4(void *,int);
extern "C" void fn_800243a8(void *,int);
extern "C" void s8_visibility_800a3c24(s8_VisibilityGroup *group) {
    void *p32 = fn_80164fc8(group->object32);
    if (p32) fn_8002900c(p32,group->visible);
    void *p36 = fn_80164fc8(group->object36);
    if (p36) fn_800f0c20(p36,group->visible);
    void *p40 = fn_80164fc8(group->object40);
    if (p40) fn_801315a0(p40,group->visible);
    void *p44 = fn_80164fc8(group->object44);
    if (p44) fn_800ff634(p44,group->visible);
    void *p48 = fn_80164fc8(group->object48);
    if (p48) fn_800a3010(p48,group->visible);
    void *p52 = fn_80164fc8(group->object52);
    if (p52) fn_80065c94(p52,group->visible);
    void *p60 = fn_80164fc8(group->object60);
    if (p60) fn_800a14c4(p60,group->visible);
    void *p68 = fn_80164fc8(group->object68);
    if (p68) fn_800243a8(p68,group->visible);
}
