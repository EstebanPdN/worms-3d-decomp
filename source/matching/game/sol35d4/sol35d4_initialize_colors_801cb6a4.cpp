// Inferred four-float color and partial native binding views, observed GC32 ABI.
struct Sol35d4Color {
    float red;
    float green;
    float blue;
    float alpha;
    Sol35d4Color(float rgb, float a) : red(rgb), green(rgb), blue(rgb), alpha(a) {}
};
struct Sol35d4ColorBinding {
    unsigned unknown_00[2];
    Sol35d4Color value;
};
extern "C" Sol35d4ColorBinding *fn_801f0b70(void *, void *);
extern "C" void *fn_801ece2c(void *, void *);
extern "C" void *fn_801ec52c(void *, void *);
extern "C" void fn_801e8d9c(void *);
extern const float lbl_803adf44[], lbl_803adf48[], lbl_803adf4c[], lbl_803adf50[];
extern unsigned char lbl_803add84[], lbl_803addb0[], lbl_803adde0[], lbl_803ade10[];
extern unsigned char lbl_803ade44[], lbl_803ade7c[], lbl_803adeb4[], lbl_803adeec[], lbl_803adf1c[];
extern "C" int w3d_sol35d4_initialize_colors_801cb6a4(void *self) {
    Sol35d4ColorBinding *binding1 = fn_801f0b70(self, lbl_803add84);
    float alpha = lbl_803adf48[0];
    const Sol35d4Color &color1 = Sol35d4Color(lbl_803adf44[0], alpha);
    binding1->value = color1;
    Sol35d4ColorBinding *binding2 = fn_801f0b70(self, lbl_803addb0);
    const Sol35d4Color &color2 = Sol35d4Color(lbl_803adf4c[0], alpha);
    binding2->value = color2;
    Sol35d4ColorBinding *binding3 = fn_801f0b70(self, lbl_803adde0);
    float black = lbl_803adf50[0];
    const Sol35d4Color &color3 = Sol35d4Color(black, black);
    binding3->value = color3;
    Sol35d4ColorBinding *binding4 = fn_801f0b70(self, lbl_803ade10);
    const Sol35d4Color &color4 = Sol35d4Color(black, black);
    binding4->value = color4;
    fn_801ece2c(self, lbl_803ade44);
    fn_801ece2c(self, lbl_803ade7c);
    fn_801ece2c(self, lbl_803adeb4);
    fn_801ece2c(self, lbl_803adeec);
    fn_801ec52c(self, lbl_803adf1c);
    fn_801e8d9c(self);
    return 0;
}
typedef char Sol35d4ColorSize[(sizeof(Sol35d4Color) == 16) ? 1 : -1];
