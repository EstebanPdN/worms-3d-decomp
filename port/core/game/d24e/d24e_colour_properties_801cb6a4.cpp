#include "w3d_ptr.h"
#line 1 "d24e_colour_properties_801cb6a4.cpp"
// Colour property registration (Worms 3D GameCube PAL, 0x801cb6a4).
//
// Creates four colour bindings through 0x801f0b70 and fills each with a
// grey level and an alpha, registers four member bindings through 0x801ece2c
// and one typed binding through 0x801ec52c, calls the refresh routine
// 0x801e8d9c and returns 0. Float constants 0x803adf44..0x803adf50 stay
// external. Built with -mps-float (one saved FPR in a non-leaf function).
//
// The first colour is built by an inline constructor and assigned; the later
// ones are filled through a pointer and copied with an inline set().
struct d24e_Colour {
    float red;
    float green;
    float blue;
    float alpha;
    d24e_Colour() {}
    d24e_Colour(float rgb, float a) : red(rgb), green(rgb), blue(rgb), alpha(a) {}
};
struct d24e_ColourBinding {
    unsigned header[2];
    d24e_Colour value;
    void set(const d24e_Colour &c) { value = c; }
};
extern "C" Ptr32<d24e_ColourBinding> fn_801f0b70(Ptr32<void>, Ptr32<const void>);
extern "C" Ptr32<void> fn_801ece2c(Ptr32<void>, Ptr32<const void>);
extern "C" Ptr32<void> fn_801ec52c(Ptr32<void>, Ptr32<const void>);
extern "C" void fn_801e8d9c(Ptr32<void>);
extern const float lbl_803adf44[], lbl_803adf48[], lbl_803adf4c[], lbl_803adf50[];
extern const unsigned char lbl_803add84[], lbl_803addb0[], lbl_803adde0[], lbl_803ade10[];
extern const unsigned char lbl_803ade44[], lbl_803ade7c[], lbl_803adeb4[], lbl_803adeec[], lbl_803adf1c[];

extern "C" int w3d_d24e_register_colour_properties_801cb6a4(Ptr32<void> owner) {
    Ptr32<d24e_ColourBinding> binding1 = fn_801f0b70(owner, lbl_803add84);
    float alpha = lbl_803adf48[0];
    const d24e_Colour &colour1 = d24e_Colour(lbl_803adf44[0], alpha);
    binding1->value = colour1;

    Ptr32<d24e_ColourBinding> binding2 = fn_801f0b70(owner, lbl_803addb0);
    d24e_Colour colour2;
    Ptr32<d24e_Colour> p2 = &colour2;
    p2->red = lbl_803adf4c[0];
    p2->green = lbl_803adf4c[0];
    p2->blue = lbl_803adf4c[0];
    p2->alpha = alpha;
    binding2->set(colour2);

    Ptr32<d24e_ColourBinding> binding3 = fn_801f0b70(owner, lbl_803adde0);
    float black = lbl_803adf50[0];
    d24e_Colour colour3;
    Ptr32<d24e_Colour> p3 = &colour3;
    p3->red = black;
    p3->green = black;
    p3->blue = black;
    p3->alpha = black;
    binding3->set(colour3);

    Ptr32<d24e_ColourBinding> binding4 = fn_801f0b70(owner, lbl_803ade10);
    d24e_Colour colour4;
    Ptr32<d24e_Colour> p4 = &colour4;
    p4->red = black;
    p4->green = black;
    p4->blue = black;
    p4->alpha = black;
    binding4->set(colour4);

    fn_801ece2c(owner, lbl_803ade44);
    fn_801ece2c(owner, lbl_803ade7c);
    fn_801ece2c(owner, lbl_803adeb4);
    fn_801ece2c(owner, lbl_803adeec);
    fn_801ec52c(owner, lbl_803adf1c);
    fn_801e8d9c(owner);
    return 0;
}


