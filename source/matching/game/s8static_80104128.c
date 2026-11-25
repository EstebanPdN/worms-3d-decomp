typedef struct s8_SmallObject { int a,b; } s8_SmallObject;
extern int lbl_804aaf90;
extern int lbl_804af17c;
extern int lbl_804af184;
extern int lbl_804af188;
extern int lbl_804af190;
extern int lbl_804af194;
extern int lbl_804af198;
extern int lbl_804af180;
extern int lbl_804af18c;
extern int lbl_804af19c;
extern s8_SmallObject lbl_804af1a0;
extern char lbl_8039959c[];
int fn_8015f518(void *, void *);
extern s8_SmallObject lbl_804af1a8;
extern char lbl_803995ac[];
void s8_static_init_80104128(int initialize,int priority)
{
    if(priority==0xffff && initialize) {
        int base0=lbl_804aaf90;
        int offset1=base0+16384;
        int offset2=base0+736;
        int offset3=base0+12400;
        int offset4=base0+16368;
        int offset5=base0+16304;
        int offset6=base0+16176;
        lbl_804af17c=offset1;
        lbl_804af184=offset2;
        lbl_804af188=offset3;
        lbl_804af190=offset4;
        lbl_804af194=offset5;
        lbl_804af198=offset6;
        lbl_804af180=base0;
        lbl_804af18c=base0;
        lbl_804af19c=base0;
        fn_8015f518(&lbl_804af1a0, lbl_8039959c);
        fn_8015f518(&lbl_804af1a8, lbl_803995ac);
    }
}
