typedef struct s8_SmallObject { int a,b; } s8_SmallObject;
extern int lbl_804aacb4;
extern int lbl_804ae43c;
extern int lbl_804ae444;
extern int lbl_804ae448;
extern int lbl_804ae450;
extern int lbl_804ae454;
extern int lbl_804ae458;
extern int lbl_804ae440;
extern int lbl_804ae44c;
extern int lbl_804ae45c;
extern s8_SmallObject lbl_804ae460;
extern char lbl_80382384[];
int fn_8015f518(void *, void *);
void s8_bound_800b06d8(int initialize,int priority)
{
    if(priority==0xffff && initialize) {
        int base0=lbl_804aacb4;
        int offset1=base0+16384;
        int offset2=base0+736;
        int offset3=base0+12400;
        int offset4=base0+16368;
        int offset5=base0+16304;
        int offset6=base0+16176;
        lbl_804ae43c=offset1;
        lbl_804ae444=offset2;
        lbl_804ae448=offset3;
        lbl_804ae450=offset4;
        lbl_804ae454=offset5;
        lbl_804ae458=offset6;
        lbl_804ae440=base0;
        lbl_804ae44c=base0;
        lbl_804ae45c=base0;
        fn_8015f518(&lbl_804ae460, lbl_80382384);
    }
}
