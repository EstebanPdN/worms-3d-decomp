typedef struct s8_SmallObject { int a,b; } s8_SmallObject;
extern char lbl_80360f00[];
extern char lbl_803e82c8[];
extern char lbl_803617d0[];
void * fn_800f165c(void);
int fn_80160038(void *, void *, void *, void (*)(void), int, int);
extern s8_SmallObject lbl_804af098;
extern char lbl_8038c404[];
int fn_8015f518(void *, void *);
void s8_static_init_800f1c6c(int initialize,int priority)
{
    if(priority==0xffff && initialize) {
        fn_80160038(lbl_80360f00, lbl_803e82c8, lbl_803617d0, fn_800f165c, 9, 0);
        fn_8015f518(&lbl_804af098, lbl_8038c404);
    }
}
