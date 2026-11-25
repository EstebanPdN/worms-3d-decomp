typedef struct s8_SmallObject { int a,b; } s8_SmallObject;
extern int lbl_804aae64;
extern int lbl_804aea84;
extern int lbl_804aea8c;
extern int lbl_804aea90;
extern int lbl_804aea98;
extern int lbl_804aea9c;
extern int lbl_804aeaa0;
extern int lbl_804aea88;
extern int lbl_804aea94;
extern int lbl_804aeaa4;
extern s8_SmallObject lbl_804aeaa8;
extern char lbl_80389150[];
int fn_8015f518(void *, void *);
extern s8_SmallObject lbl_804aeab0;
extern char lbl_80389164[];
extern s8_SmallObject lbl_804aeab8;
extern char lbl_80389178[];
extern s8_SmallObject lbl_804aeac0;
extern char lbl_8038918c[];
void s8_static_init_800d74c8(int initialize,int priority)
{
    if(priority==0xffff && initialize) {
        int base0=lbl_804aae64;
        int offset1=base0+16384;
        int offset2=base0+736;
        int offset3=base0+12400;
        int offset4=base0+16368;
        int offset5=base0+16304;
        int offset6=base0+16176;
        lbl_804aea84=offset1;
        lbl_804aea8c=offset2;
        lbl_804aea90=offset3;
        lbl_804aea98=offset4;
        lbl_804aea9c=offset5;
        lbl_804aeaa0=offset6;
        lbl_804aea88=base0;
        lbl_804aea94=base0;
        lbl_804aeaa4=base0;
        fn_8015f518(&lbl_804aeaa8, lbl_80389150);
        fn_8015f518(&lbl_804aeab0, lbl_80389164);
        fn_8015f518(&lbl_804aeab8, lbl_80389178);
        fn_8015f518(&lbl_804aeac0, lbl_8038918c);
    }
}
