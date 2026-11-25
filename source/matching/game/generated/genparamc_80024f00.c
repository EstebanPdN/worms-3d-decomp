/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Family templates, 2026-10-22 (third session), fifth batch. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef int (*W3dMethod5)(void *, void *, int, int *, int);
typedef int (*W3dHandler2)(void *, void *);
typedef struct W3dPair { int first; int second; } W3dPair;
extern int lbl_804b0588;
extern char lbl_8045e0f8[];
void * fn_80357568(void *);
void fn_801ea910(void);
int fn_802ed7e0(void (*)(void));
void *fn_803426b4(void *);
void *fn_80178c48(void *);
void *fn_800fc710(int, W3dPair *);
void fn_80178474(W3dPair *, int);
void fn_8020bb2c(void *);
extern int lbl_804b068c;
extern char lbl_80462e90[];
void fn_80209ae4(void *);
void fn_80209a44(void);
extern int lbl_804b06b8;
extern char lbl_80463c04[];
void * fn_8035d5b4(void *);
void fn_802105e4(void);

void w3d_set_handle_owner_80024f00(void *self, int value)
{
    W3dPair key;
    key.first = 0;
    key.second = 58280;
    FIELD(fn_800fc710(fn_80178c48(fn_803426b4(FIELD(self, void *, 28))), &key), int, 216) = value;
    fn_80178474(&key, 2);
}

void w3d_set_handle_owner_8002557c(void *self, int value)
{
    W3dPair key;
    key.first = 0;
    key.second = 58280;
    FIELD(fn_800fc710(fn_80178c48(fn_803426b4(FIELD(self, void *, 28))), &key), int, 112) = value;
    fn_80178474(&key, 2);
}

void w3d_set_handle_owner_80025aa0(void *self, int value)
{
    W3dPair key;
    key.first = 0;
    key.second = 58280;
    FIELD(fn_800fc710(fn_80178c48(fn_803426b4(FIELD(self, void *, 28))), &key), int, 104) = value;
    fn_80178474(&key, 2);
}

int w3d_dispatch_by_index_801a3e60(void *self, void *message)
{
    void *handle = FIELD(message, void *, 36);
    if (handle)
        return FIELD(self, W3dHandler2 *, 24)[FIELD(handle, unsigned short, 6)](self, handle);
    return 0;
}

int w3d_dispatch_by_index_801a4824(void *self, void *message)
{
    void *handle = FIELD(message, void *, 20);
    if (handle)
        return FIELD(self, W3dHandler2 *, 24)[FIELD(handle, unsigned short, 6)](self, handle);
    return 0;
}

int w3d_dispatch_by_index_801a4c3c(void *self, void *message)
{
    void *handle = FIELD(message, void *, 20);
    if (handle)
        return FIELD(self, W3dHandler2 *, 24)[FIELD(handle, unsigned short, 6)](self, handle);
    return 0;
}

int w3d_forward_range_801ae784(void *iface, void *argument)
{
    char *self = iface ? (char *)iface - 4 : 0;
    void *target = FIELD(self, void *, 44);
    int *first = FIELD(self, int *, 48);
    (*(W3dMethod5 *)(*(char **)target + 20))(target, argument, FIELD(self, int, 40), first,
                                              FIELD(self, int *, 52) - first);
    return 0;
}

int w3d_forward_range_801ae7e4(void *iface, void *argument)
{
    char *self = iface ? (char *)iface - 4 : 0;
    void *target = FIELD(self, void *, 44);
    int *first = FIELD(self, int *, 48);
    (*(W3dMethod5 *)(*(char **)target + 40))(target, argument, FIELD(self, int, 40), first,
                                              FIELD(self, int *, 52) - first);
    return 0;
}

int w3d_forward_range_801ae844(void *iface, void *argument)
{
    char *self = iface ? (char *)iface - 4 : 0;
    void *target = FIELD(self, void *, 44);
    int *first = FIELD(self, int *, 48);
    (*(W3dMethod5 *)(*(char **)target + 60))(target, argument, FIELD(self, int, 40), first,
                                              FIELD(self, int *, 52) - first);
    return 0;
}

void *w3d_local_static_801ea954(void)
{
    if (!lbl_804b0588) {
        fn_80357568(lbl_8045e0f8);
        lbl_804b0588 = 1;
        fn_802ed7e0(fn_801ea910);
    }
    return lbl_8045e0f8;
}

void *w3d_local_static_80209a70(void)
{
    if (!lbl_804b068c) {
        fn_80209ae4(lbl_80462e90);
        lbl_804b068c = 1;
        fn_802ed7e0(fn_80209a44);
    }
    return lbl_80462e90;
}

void *w3d_local_static_80210610(void)
{
    if (!lbl_804b06b8) {
        fn_8035d5b4(lbl_80463c04);
        lbl_804b06b8 = 1;
        fn_802ed7e0(fn_802105e4);
    }
    return lbl_80463c04;
}

int w3d_get_string_802113a0(void *self, char **out)
{
    char *source = FIELD(self, char *, 24);
    unsigned short *header;
    FIELD(source, unsigned short, -6)++;
    header = (unsigned short *)(*out - 6);
    if (--*header == 0)
        fn_8020bb2c(header);
    *out = FIELD(self, char *, 24);
    return 0;
}

int w3d_get_string_802114b4(void *self, char **out)
{
    char *source = FIELD(self, char *, 28);
    unsigned short *header;
    FIELD(source, unsigned short, -6)++;
    header = (unsigned short *)(*out - 6);
    if (--*header == 0)
        fn_8020bb2c(header);
    *out = FIELD(self, char *, 28);
    return 0;
}

int w3d_get_string_8021158c(void *self, char **out)
{
    char *source = FIELD(self, char *, 32);
    unsigned short *header;
    FIELD(source, unsigned short, -6)++;
    header = (unsigned short *)(*out - 6);
    if (--*header == 0)
        fn_8020bb2c(header);
    *out = FIELD(self, char *, 32);
    return 0;
}
