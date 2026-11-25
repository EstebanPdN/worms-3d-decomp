#define M2C_FIELD(p,T,o) (*(T)((char *)(p)+(o)))
int fn_8020BB54(int *, int *);          /* extern */
int fn_8020C5C4(int *);                     /* extern */
int fn_80341588(int *);                     /* extern */
extern int lbl_8039C85C[];
extern int lbl_8039C864[];
extern int lbl_8039C86C[];
extern int lbl_8039C874[];
extern int lbl_8039C878[];
extern int lbl_8039C88C[];

extern "C" void sol35c_load_groups_80128f6c(void *arg0) {
    int sp8;
    int temp_r0;
    void *temp_r30;
    void *temp_r30_2;
    void *temp_r30_3;
    void *temp_r30_4;
    void *temp_r30_5;
    void *temp_r30_6;

    if (!(M2C_FIELD(arg0, int *, 0xBC) & 0x20000000)) {
        goto block_3;
    }
    temp_r30 = M2C_FIELD(arg0, void **, 0);
    fn_8020BB54(&sp8, &(*lbl_8039C85C));
    M2C_FIELD(temp_r30, int (**)(void *, int *), 0x14)(arg0, &sp8);
    fn_8020C5C4(&sp8);
    fn_80341588(&sp8);
    temp_r0 = M2C_FIELD(arg0, int *, 0xBC);
    if (!(temp_r0 & 0x20000000)) {
        goto block_3;
    }
    if (!(temp_r0 & 0x10000000)) {
        goto block_4;
    }
block_3:
    temp_r30_2 = M2C_FIELD(arg0, void **, 0);
    fn_8020BB54(&sp8, &(*lbl_8039C864));
    M2C_FIELD(temp_r30_2, int (**)(void *, int *), 0x14)(arg0, &sp8);
    fn_8020C5C4(&sp8);
    fn_80341588(&sp8);
    temp_r30_3 = M2C_FIELD(arg0, void **, 0);
    fn_8020BB54(&sp8, &(*lbl_8039C86C));
    M2C_FIELD(temp_r30_3, int (**)(void *, int *), 0x14)(arg0, &sp8);
    fn_8020C5C4(&sp8);
    fn_80341588(&sp8);
    temp_r30_4 = M2C_FIELD(arg0, void **, 0);
    fn_8020BB54(&sp8, &(*lbl_8039C874));
    M2C_FIELD(temp_r30_4, int (**)(void *, int *), 0x14)(arg0, &sp8);
    fn_8020C5C4(&sp8);
    fn_80341588(&sp8);
    temp_r30_5 = M2C_FIELD(arg0, void **, 0);
    fn_8020BB54(&sp8, &(*lbl_8039C878));
    M2C_FIELD(temp_r30_5, int (**)(void *, int *), 0x14)(arg0, &sp8);
    fn_8020C5C4(&sp8);
    fn_80341588(&sp8);
    temp_r30_6 = M2C_FIELD(arg0, void **, 0);
    fn_8020BB54(&sp8, &(*lbl_8039C88C));
    M2C_FIELD(temp_r30_6, int (**)(void *, int *), 0x14)(arg0, &sp8);
    fn_8020C5C4(&sp8);
    fn_80341588(&sp8);
block_4:
    return;
}
