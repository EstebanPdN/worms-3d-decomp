extern void fn_801f6834(char *, char *, int);
extern void fn_801aa79c(void *, char *);
void w3d_s20_p_801aab20(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    fn_801f6834(item + 48, item + 112, *(int *)(base + 56));
    fn_801aa79c(self, item);
}
