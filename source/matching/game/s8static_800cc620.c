typedef struct s8_SmallObject { int a,b; } s8_SmallObject;
extern int lbl_804aae24;
extern int lbl_804ae814;
extern int lbl_804ae81c;
extern int lbl_804ae820;
extern int lbl_804ae828;
extern int lbl_804ae82c;
extern int lbl_804ae830;
extern int lbl_804ae818;
extern int lbl_804ae824;
extern int lbl_804ae834;
extern s8_SmallObject lbl_804ae838;
extern char lbl_80387d60[];
int fn_8015f518(void *, void *);
void s8_static_init_800cc620(int initialize,int priority)
{
    if(priority==0xffff && initialize) {
        int base0=lbl_804aae24;
        int offset1=base0+16384;
        int offset2=base0+736;
        int offset3=base0+12400;
        int offset4=base0+16368;
        int offset5=base0+16304;
        int offset6=base0+16176;
        lbl_804ae814=offset1;
        lbl_804ae81c=offset2;
        lbl_804ae820=offset3;
        lbl_804ae828=offset4;
        lbl_804ae82c=offset5;
        lbl_804ae830=offset6;
        lbl_804ae818=base0;
        lbl_804ae824=base0;
        lbl_804ae834=base0;
        fn_8015f518(&lbl_804ae838, lbl_80387d60);
    }
}
