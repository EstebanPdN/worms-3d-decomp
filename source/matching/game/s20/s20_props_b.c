/* Property registration helpers with default vectors, finishing through a shared routine. */
typedef struct S20Vec2 { float x; float y; } S20Vec2;
typedef struct S20Vec4 { float x; float y; float z; float w; } S20Vec4;
extern char *fn_801f00f0(char *, char *);
extern char *fn_801f0b70(char *, char *);
extern void * fn_801ec52c(char *, char *);
extern void * fn_801ece2c(char *, char *);
extern void fn_801e8d9c(char *);
extern char lbl_803abec0[];
extern char lbl_803abef4[];
extern char lbl_803abf24[];
extern char lbl_803abf58[];
extern float lbl_803abf7c[];
extern char lbl_803aecf8[];
extern char lbl_803aed28[];
extern char lbl_803aed58[];
extern float lbl_803aed80[];
extern float lbl_803aed84[];
extern char lbl_803aedf4[];
extern char lbl_803aee28[];
extern float lbl_803aee4c[];
extern float lbl_803aee50[];

int w3d_s20_register_float_pairs_801ce708(char *self) {
    char *property;
    volatile S20Vec2 first;
    volatile S20Vec2 second;
    property = fn_801f00f0(self, lbl_803aecf8);
    first.y = lbl_803aed80[0];
    first.x = lbl_803aed80[0];
    *(S20Vec2 *)(property + 8) = *(S20Vec2 *)&first;
    property = fn_801f00f0(self, lbl_803aed28);
    second.y = lbl_803aed84[0];
    second.x = lbl_803aed84[0];
    *(S20Vec2 *)(property + 8) = *(S20Vec2 *)&second;
    fn_801ec52c(self, lbl_803aed58);
    fn_801e8d9c(self);
    return 0;
}

int w3d_s20_register_float_pair_801bf55c(char *self) {
    char *property;
    volatile S20Vec2 value;
    fn_801ec52c(self, lbl_803abec0);
    fn_801ec52c(self, lbl_803abef4);
    fn_801ec52c(self, lbl_803abf24);
    property = fn_801f00f0(self, lbl_803abf58);
    value.y = lbl_803abf7c[0];
    value.x = lbl_803abf7c[0];
    *(S20Vec2 *)(property + 8) = *(S20Vec2 *)&value;
    fn_801e8d9c(self);
    return 0;
}

int w3d_s20_register_vec4_property_801cee80(char *self) {
    char *property;
    S20Vec4 value;
    volatile float *w;
    fn_801ece2c(self, lbl_803aedf4);
    property = fn_801f0b70(self, lbl_803aee28);
    w = (volatile float *)&value;
    w[0] = lbl_803aee4c[0];
    w[2] = lbl_803aee4c[0];
    w[3] = lbl_803aee50[0];
    w[1] = lbl_803aee4c[0];
    *(S20Vec4 *)(property + 8) = value;
    fn_801e8d9c(self);
    return 0;
}
