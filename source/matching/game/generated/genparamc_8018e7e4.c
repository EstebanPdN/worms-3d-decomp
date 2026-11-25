/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Family templates, 2026-10-22 (third session), sixth batch. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef int (*W3dMethodA)(void *, int, void *, int);
typedef int (*W3dMethodB)(void *, void *, int, int);
extern char lbl_803abc8c[];
extern char lbl_803abcc4[];
extern char lbl_803abcf4[];
void * fn_801eb834(void *, const char *);
void * fn_801ecc6c(void *, const char *);
void fn_801e8d9c(void *);
extern char lbl_80413ad0[];
extern char lbl_80413a78[];
void * fn_801e81c8(void *);
extern char lbl_80413160[];
extern char *lbl_804b06a0[];
int fn_8018e26c(void *, void *);
void fn_8020c5c0(void *);
unsigned short *fn_80341884(void *);
extern char lbl_803ac314[];
extern char lbl_803ac344[];
extern char lbl_803ac374[];
void * fn_801ec52c(void *, const char *);
void * fn_801ec52c(void *, const char *);
extern char lbl_80416708[];
extern char lbl_804166c0[];
extern char lbl_80416848[];
extern char lbl_80416800[];
extern char lbl_8041b058[];
int fn_80238d88(void *, void *);
extern char lbl_8041ac20[];
int fn_8023b59c(void *, void *);
extern char lbl_803c4bfc[];
extern char lbl_803c4c2c[];
extern char lbl_803c4c5c[];

void *w3d_construct_with_string_8018e7e4(void *self, void * arg_r4)
{
    char *name = (char *)self + 28;
    char **empty = lbl_804b06a0;
    fn_8018e26c(self, arg_r4);
    FIELD(self, void *, 0) = lbl_80413160;
    fn_8020c5c0(name);
    FIELD(self, char *, 28) = *empty;
    ++*fn_80341884(name);
    return self;
}

void *w3d_construct_with_member_801a5334(void *self)
{
    FIELD(self, void *, 0) = lbl_80413ad0;
    fn_801e81c8((char *)self + 4);
    FIELD(self, void *, 0) = lbl_80413a78;
    FIELD(self, int, 40) = 0;
    FIELD(self, int, 88) = 0;
    return self;
}

int w3d_register_properties_801be210(void *self)
{
    fn_801eb834(self, lbl_803abc8c);
    fn_801eb834(self, lbl_803abcc4);
    fn_801ecc6c(self, lbl_803abcf4);
    fn_801e8d9c(self);
    return 0;
}

int w3d_register_properties_801c02a4(void *self)
{
    fn_801ec52c(self, lbl_803ac314);
    fn_801ec52c(self, lbl_803ac344);
    fn_801ec52c(self, lbl_803ac374);
    fn_801e8d9c(self);
    return 0;
}

void *w3d_construct_with_member_801d544c(void *self)
{
    FIELD(self, void *, 0) = lbl_80416708;
    fn_801e81c8((char *)self + 4);
    FIELD(self, void *, 0) = lbl_804166c0;
    FIELD(self, int, 40) = 0;
    FIELD(self, int, 48) = 0;
    return self;
}

void *w3d_construct_with_member_801d9a74(void *self)
{
    FIELD(self, void *, 0) = lbl_80416848;
    fn_801e81c8((char *)self + 4);
    FIELD(self, void *, 0) = lbl_80416800;
    FIELD(self, int, 40) = 0;
    FIELD(self, int, 44) = 0;
    return self;
}

int w3d_forward_by_flag_80201964(void *self, int flag, void *argument)
{
    void *member;
    if (!flag) {
        member = FIELD(self, void *, 20);
        return (*(W3dMethodB *)(*(char **)member + 28))(member, argument, 1, 0);
    }
    member = FIELD(self, void *, 20);
    return (*(W3dMethodA *)(*(char **)member + 20))(member, flag, argument, 0);
}

int w3d_forward_by_flag_802019bc(void *self, int flag, void *argument)
{
    void *member;
    if (!flag) {
        member = FIELD(self, void *, 20);
        return (*(W3dMethodB *)(*(char **)member + 28))(member, argument, 1, 0);
    }
    member = FIELD(self, void *, 20);
    return (*(W3dMethodA *)(*(char **)member + 20))(member, flag, argument, 0);
}

int w3d_forward_by_flag_8020229c(void *self, int flag, void *argument)
{
    void *member;
    if (!flag) {
        member = FIELD(self, void *, 20);
        return (*(W3dMethodB *)(*(char **)member + 28))(member, argument, 1, 0);
    }
    member = FIELD(self, void *, 20);
    return (*(W3dMethodA *)(*(char **)member + 20))(member, flag, argument, 0);
}

void *w3d_construct_with_string_80239204(void *self, void * arg_r4)
{
    char *name = (char *)self + 24;
    char **empty = lbl_804b06a0;
    fn_80238d88(self, arg_r4);
    FIELD(self, void *, 0) = lbl_8041b058;
    fn_8020c5c0(name);
    FIELD(self, char *, 24) = *empty;
    ++*fn_80341884(name);
    return self;
}

void *w3d_construct_with_string_8023d32c(void *self, void * arg_r4)
{
    char *name = (char *)self + 28;
    char **empty = lbl_804b06a0;
    fn_8023b59c(self, arg_r4);
    FIELD(self, void *, 0) = lbl_8041ac20;
    fn_8020c5c0(name);
    FIELD(self, char *, 28) = *empty;
    ++*fn_80341884(name);
    return self;
}

int w3d_register_properties_8024cda8(void *self)
{
    fn_801eb834(self, lbl_803c4bfc);
    fn_801eb834(self, lbl_803c4c2c);
    fn_801eb834(self, lbl_803c4c5c);
    fn_801e8d9c(self);
    return 0;
}
