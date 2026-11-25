/* Property registration with entries and a four-float default. */
typedef struct S20Vec4 { float x; float y; float z; float w; } S20Vec4;
extern char *fn_801f0b70(char *, char *);
extern void * fn_801eb674(char *, char *);
extern void * fn_801ece2c(char *, char *);
extern void * fn_801ec52c(char *, char *);
extern void fn_801e8d9c(char *);
extern char lbl_803ae5bc[];
extern char lbl_803ae5ec[];
extern char lbl_803ae61c[];
extern char lbl_803ae648[];
extern char lbl_803ae674[];
extern char lbl_803ae6a4[];
extern float lbl_803ae6cc[];

int w3d_s20_register_entries_vec4_801cd188(char *self) {
    char *property;
    S20Vec4 value;
    volatile float *w;
    fn_801eb674(self, lbl_803ae5bc);
    fn_801ece2c(self, lbl_803ae5ec);
    property = fn_801f0b70(self, lbl_803ae61c);
    w = (volatile float *)&value;
    w[0] = lbl_803ae6cc[0];
    w[3] = lbl_803ae6cc[0];
    w[1] = lbl_803ae6cc[0];
    w[2] = lbl_803ae6cc[0];
    *(S20Vec4 *)(property + 8) = value;
    fn_801ec52c(self, lbl_803ae648);
    fn_801ec52c(self, lbl_803ae674);
    fn_801ec52c(self, lbl_803ae6a4);
    fn_801e8d9c(self);
    return 0;
}
