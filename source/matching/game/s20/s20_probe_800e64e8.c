extern void fn_800fc2b0(char **, unsigned char **);
extern void fn_800fd4c8(int, int);
extern void fn_800fd504(unsigned char *, int, int);
extern char lbl_8038a62c[];
void w3d_s20_trigger_effect_800e64e8(void) {
    char *key;
    unsigned char *flag;
    flag = 0;
    key = lbl_8038a62c;
    fn_800fc2b0(&key, &flag);
    fn_800fd4c8(6, 1);
    if (flag != 0 && *flag != 0)
        fn_800fd504(flag, 6, 1);
}

