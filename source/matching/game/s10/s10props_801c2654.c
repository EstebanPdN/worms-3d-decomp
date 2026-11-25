/* Literal fields and addresses derived from the original registration blocks. */
typedef struct S10PropertyInfo {
    const char *name;
    unsigned short size;
    unsigned char elementType;
    unsigned char type;
    void *descriptor;
    void *extra;
    int reserved16;
} S10PropertyInfo;
void *memset();

extern int lbl_804b0464;
extern S10PropertyInfo lbl_8045d3e0;
extern char lbl_803ac764[];
extern char lbl_8045e2b4[];
void * fn_801f23bc(void *, S10PropertyInfo *);
extern int lbl_804b0468;
extern S10PropertyInfo lbl_8045d3f4;
extern char lbl_803ac768[];
extern int lbl_804b046c;
extern S10PropertyInfo lbl_8045d408;
extern char lbl_803ac76c[];
extern char lbl_8045ed4c[];
void * fn_801efdfc(void *, S10PropertyInfo *);
extern int lbl_804b0470;
extern S10PropertyInfo lbl_8045d41c;
extern char lbl_803ac778[];
extern char lbl_8045ed34[];
void * fn_801efd98(void *, S10PropertyInfo *);
extern int lbl_804b0474;
extern S10PropertyInfo lbl_8045d430;
extern char lbl_803ac784[];
extern int lbl_804b0478;
extern S10PropertyInfo lbl_8045d444;
extern char lbl_803ac790[];
extern char lbl_8045ed7c[];
void * fn_801efec4(void *, S10PropertyInfo *);
extern int lbl_804b047c;
extern S10PropertyInfo lbl_8045d458;
extern char lbl_803ac798[];
extern int lbl_804b0480;
extern S10PropertyInfo lbl_8045d46c;
extern char lbl_803ac7a0[];
extern char lbl_8045ed1c[];
void * fn_801efd34(void *, S10PropertyInfo *);
void fn_801e8d9c(void *);
int w3d_s10_register_properties_801c2654(void *object)
{
    S10PropertyInfo info;
    if (!lbl_804b0464) {
        S10PropertyInfo *target = &lbl_8045d3e0;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac764;
        info.size = 24;
        info.type = 9;
        info.descriptor = lbl_8045e2b4;
        *target = info;
        lbl_804b0464 = 1;
    }
    fn_801f23bc(object, &lbl_8045d3e0);
    if (!lbl_804b0468) {
        S10PropertyInfo *target = &lbl_8045d3f4;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac768;
        info.size = 20;
        info.elementType = 1;
        info.type = 9;
        info.descriptor = lbl_8045e2b4;
        *target = info;
        lbl_804b0468 = 1;
    }
    fn_801f23bc(object, &lbl_8045d3f4);
    if (!lbl_804b046c) {
        S10PropertyInfo *target = &lbl_8045d408;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac76c;
        info.size = 32;
        info.elementType = 2;
        info.type = 9;
        info.descriptor = lbl_8045ed4c;
        *target = info;
        lbl_804b046c = 1;
    }
    fn_801efdfc(object, &lbl_8045d408);
    if (!lbl_804b0470) {
        S10PropertyInfo *target = &lbl_8045d41c;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac778;
        info.size = 44;
        info.elementType = 3;
        info.type = 9;
        info.descriptor = lbl_8045ed34;
        *target = info;
        lbl_804b0470 = 1;
    }
    fn_801efd98(object, &lbl_8045d41c);
    if (!lbl_804b0474) {
        S10PropertyInfo *target = &lbl_8045d430;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac784;
        info.size = 40;
        info.elementType = 4;
        info.type = 9;
        info.descriptor = lbl_8045ed34;
        *target = info;
        lbl_804b0474 = 1;
    }
    fn_801efd98(object, &lbl_8045d430);
    if (!lbl_804b0478) {
        S10PropertyInfo *target = &lbl_8045d444;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac790;
        info.size = 28;
        info.elementType = 5;
        info.type = 9;
        info.descriptor = lbl_8045ed7c;
        *target = info;
        lbl_804b0478 = 1;
    }
    fn_801efec4(object, &lbl_8045d444);
    if (!lbl_804b047c) {
        S10PropertyInfo *target = &lbl_8045d458;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac798;
        info.size = 36;
        info.elementType = 6;
        info.type = 9;
        info.descriptor = lbl_8045ed34;
        *target = info;
        lbl_804b047c = 1;
    }
    fn_801efd98(object, &lbl_8045d458);
    if (!lbl_804b0480) {
        S10PropertyInfo *target = &lbl_8045d46c;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac7a0;
        info.size = 48;
        info.elementType = 7;
        info.type = 9;
        info.descriptor = lbl_8045ed1c;
        *target = info;
        lbl_804b0480 = 1;
    }
    fn_801efd34(object, &lbl_8045d46c);
    fn_801e8d9c(object);
    return 0;
}
