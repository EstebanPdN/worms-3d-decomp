/* Property registration helpers with default vectors and extra entries. */
typedef struct S20Vec3 { float x; float y; float z; } S20Vec3;
extern char *fn_801f0504(char *, char *);
extern char *fn_801f0210(char *, char *);
extern void fn_801ec52c(char *, char *);
extern void fn_801e8d9c(char *);
extern char lbl_803aba70[];
extern char lbl_803abaa8[];
extern float lbl_803abacc[];
extern char lbl_803ac12c[];
extern char lbl_803ac150[];
extern char lbl_803ac18c[];
extern char lbl_803ac1c8[];
extern char lbl_803ac208[];
extern float lbl_803ac230[];
int w3d_s20_register_vector_pair_801bd0a0(char *self) {
    char *property;
    S20Vec3 first;
    S20Vec3 second;
    volatile float *a;
    volatile float *b;
    float constant;
    property = fn_801f0210(self, lbl_803aba70);
    constant = lbl_803abacc[0];
    a = (volatile float *)&first;
    a[0] = constant;
    a[1] = constant;
    a[2] = constant;
    *(S20Vec3 *)(property + 8) = first;
    property = fn_801f0210(self, lbl_803abaa8);
    b = (volatile float *)&second;
    b[0] = constant;
    b[2] = constant;
    b[1] = constant;
    *(S20Vec3 *)(property + 8) = second;
    fn_801e8d9c(self);
    return 0;
}
