extern void fn_801a572c(void *, int);
void w3d_s20_p_801a59c0(char *p) {
    char *b = p ? p - 4 : 0;
    fn_801a572c(p, *(int *)(b + 0x18));
}
