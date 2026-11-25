typedef struct s8_SmallObject { int a,b; } s8_SmallObject;
extern char lbl_80360ff0[];
extern char lbl_803e8354[];
extern char lbl_803618f0[];
void * fn_800fd7f4(void);
int fn_801629f8(void *, void *, void *, void (*)(void), int, int);
extern s8_SmallObject lbl_804af13c;
extern char lbl_803981d0[];
int fn_8015f518(void *, void *);
void s8_static_init_800fe1a4(int initialize,int priority)
{
    if(priority==0xffff && initialize) {
        fn_801629f8(lbl_80360ff0, lbl_803e8354, lbl_803618f0, fn_800fd7f4, 10, 0);
        fn_8015f518(&lbl_804af13c, lbl_803981d0);
    }
}
