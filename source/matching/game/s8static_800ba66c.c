typedef struct s8_SmallObject { int a,b; } s8_SmallObject;
extern char lbl_803608d0[];
extern char lbl_803e7f2c[];
extern char lbl_803617d0[];
void * fn_800b93dc(void);
int fn_80160038(void *, void *, void *, void (*)(void), int, int);
extern s8_SmallObject lbl_804ae518;
extern char lbl_803828e0[];
int fn_8015f518(void *, void *);
extern s8_SmallObject lbl_804ae520;
extern char lbl_803828ec[];
extern s8_SmallObject lbl_804ae528;
extern char lbl_80382900[];
extern s8_SmallObject lbl_804ae530;
extern char lbl_80382914[];
extern s8_SmallObject lbl_804ae538;
extern char lbl_80382928[];
extern s8_SmallObject lbl_804ae540;
extern char lbl_8038292c[];
extern int lbl_804ae548;
void s8_static_init_800ba66c(int initialize,int priority)
{
    if(priority==0xffff && initialize) {
        fn_80160038(lbl_803608d0, lbl_803e7f2c, lbl_803617d0, fn_800b93dc, 9, 0);
        fn_8015f518(&lbl_804ae518, lbl_803828e0);
        fn_8015f518(&lbl_804ae520, lbl_803828ec);
        fn_8015f518(&lbl_804ae528, lbl_80382900);
        fn_8015f518(&lbl_804ae530, lbl_80382914);
        fn_8015f518(&lbl_804ae538, lbl_80382928);
        fn_8015f518(&lbl_804ae540, lbl_8038292c);
        lbl_804ae548=0;
    }
}
