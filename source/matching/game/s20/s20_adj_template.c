#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
extern void fn_801a572c(void *, int);
void w3d_s20adj_801a59c0(char *p) {
    char *b = p ? p - 4 : 0;
    fn_801a572c(p, FIELD(b, int, 0x18));
}
