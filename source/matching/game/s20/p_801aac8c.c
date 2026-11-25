extern void fn_801a46bc(void *, int, int);
void w3d_s20_p_801aac8c(char *p, int a1) {
    char *b = p ? p - 4 : 0;
    fn_801a46bc(p, a1, *(int *)(b + 0x38));
}
