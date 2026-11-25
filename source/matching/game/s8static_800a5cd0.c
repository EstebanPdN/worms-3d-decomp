typedef struct s8_SmallObject { int a,b; } s8_SmallObject;
extern char lbl_803607e0[];
extern char lbl_803e7ea0[];
extern char lbl_80361860[];
void * fn_800a5528(void);
int fn_8016115c(void *, void *, void *, void (*)(void), int, int);
extern s8_SmallObject lbl_804ae278;
extern char lbl_8038124c[];
int fn_8015f518(void *, void *);
void s8_static_init_800a5cd0(int initialize,int priority)
{
    if(priority==0xffff && initialize) {
        fn_8016115c(lbl_803607e0, lbl_803e7ea0, lbl_80361860, fn_800a5528, 11, 0);
        fn_8015f518(&lbl_804ae278, lbl_8038124c);
    }
}
