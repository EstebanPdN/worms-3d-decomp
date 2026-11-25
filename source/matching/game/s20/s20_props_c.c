/* Property registration helpers with default vectors and extra entries. */
typedef struct S20Vec3 { float x; float y; float z; } S20Vec3;
extern char *fn_801f0504(char *, char *);
extern char *fn_801f0210(char *, char *);
extern void * fn_801ec52c(char *, char *);
extern void fn_801e8d9c(char *);
extern char lbl_803ac12c[];
extern char lbl_803ac150[];
extern char lbl_803ac18c[];
extern char lbl_803ac1c8[];
extern char lbl_803ac208[];
extern float lbl_803ac230[];

int w3d_s20_register_vector_entries_801bfcf4(char *self) {
    char *property;
    S20Vec3 value;
    volatile float *words;
    property = fn_801f0504(self, lbl_803ac12c);
    words = (volatile float *)&value;
    words[0] = lbl_803ac230[0];
    words[2] = lbl_803ac230[0];
    words[1] = lbl_803ac230[0];
    *(S20Vec3 *)(property + 8) = value;
    fn_801ec52c(self, lbl_803ac150);
    fn_801ec52c(self, lbl_803ac18c);
    fn_801ec52c(self, lbl_803ac1c8);
    fn_801ec52c(self, lbl_803ac208);
    fn_801e8d9c(self);
    return 0;
}
