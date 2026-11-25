typedef struct s8_SmallObject { int a,b; } s8_SmallObject;
extern int lbl_804aaca4;
extern int lbl_804ae400;
extern int lbl_804ae408;
extern int lbl_804ae40c;
extern int lbl_804ae404;
extern int lbl_804ae410;
extern int lbl_804ae420;
extern int lbl_804ae414;
extern int lbl_804ae418;
extern int lbl_804ae41c;
extern char lbl_803608a0[];
extern char lbl_803e7f10[];
extern char lbl_80360c60[];
void * fn_800af380(void);
int fn_8016115c(void *, void *, void *, void (*)(void), int, int);
extern s8_SmallObject lbl_804ae424;
extern char lbl_803822dc[];
int fn_8015f518(void *, void *);
extern s8_SmallObject lbl_804ae42c;
extern char lbl_803822ec[];
extern s8_SmallObject lbl_804ae434;
extern char lbl_80382300[];
void s8_static_init_800afcd0(int initialize,int priority)
{
    if(priority==0xffff && initialize) {
        int base0=lbl_804aaca4;
        int offset1=base0+16384;
        int offset2=base0+736;
        int offset3=base0+12400;
        int offset4=base0+16368;
        int offset5=base0+16304;
        int offset6=base0+16176;
        lbl_804ae400=offset1;
        lbl_804ae408=offset2;
        lbl_804ae40c=offset3;
        lbl_804ae404=base0;
        lbl_804ae410=base0;
        lbl_804ae420=base0;
        lbl_804ae414=offset4;
        lbl_804ae418=offset5;
        lbl_804ae41c=offset6;
        fn_8016115c(lbl_803608a0, lbl_803e7f10, lbl_80360c60, fn_800af380, 11, 0);
        fn_8015f518(&lbl_804ae424, lbl_803822dc);
        fn_8015f518(&lbl_804ae42c, lbl_803822ec);
        fn_8015f518(&lbl_804ae434, lbl_80382300);
    }
}
