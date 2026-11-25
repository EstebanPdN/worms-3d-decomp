struct K5bColour { float r, g, b, a; };
struct K5bRect6 { float v[6]; };
struct K5bPanelStyle {
    char head[44];
    struct K5bColour colour;
    struct K5bRect6 frame;
    int selected;
};
extern struct K5bColour lbl_8045e63c[];
extern struct K5bRect6 lbl_8045e690[];
int w3d_k5b_panel_style_reset_801a54d0(struct K5bPanelStyle *self)
{
    self->colour = lbl_8045e63c[0];
    self->frame = lbl_8045e690[0];
    self->selected = 0;
    return 0;
}
// desc: w3d_k5b_panel_style_reset_801a54d0: Appears to copy the default colour at 0x8045e63c to +44 and the six-word default at 0x8045e690 to +60, clear +84 and return 0.
