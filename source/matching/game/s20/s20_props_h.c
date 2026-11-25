/* Registration with a vector default and a lazily initialized property descriptor. */
typedef struct S20PropertyInfo {
    const char *name;
    unsigned short size;
    unsigned char elementType;
    unsigned char type;
    void *descriptor;
    void *extra;
    int reserved16;
} S20PropertyInfo;
typedef struct S20Vec3 { float x; float y; float z; } S20Vec3;
void *memset();
extern int lbl_804b03f0;
extern S20PropertyInfo lbl_8045d19c;
extern char lbl_803abbac[];
extern float lbl_803abbd8[];
extern char lbl_803abbd0[];
extern char lbl_8045ed7c[];
char *fn_801f0504(void *, char *);
void * fn_801efec4(void *, S20PropertyInfo *);
void fn_801e8d9c(void *);

int w3d_s20_register_range_property_801bd79c(void *object)
{
    char *property;
    S20Vec3 value;
    volatile float *words;
    S20PropertyInfo info;
    property = fn_801f0504(object, lbl_803abbac);
    words = (volatile float *)&value;
    words[0] = lbl_803abbd8[0];
    words[2] = lbl_803abbd8[0];
    words[1] = lbl_803abbd8[0];
    *(S20Vec3 *)(property + 8) = value;
    if (!lbl_804b03f0) {
        S20PropertyInfo *target = &lbl_8045d19c;
        memset(&info, 0, sizeof info);
        info.name = lbl_803abbd0;
        info.size = 40;
        info.elementType = 3;
        info.type = 9;
        info.descriptor = lbl_8045ed7c;
        *target = info;
        lbl_804b03f0 = 1;
    }
    fn_801efec4(object, &lbl_8045d19c);
    fn_801e8d9c(object);
    return 0;
}
