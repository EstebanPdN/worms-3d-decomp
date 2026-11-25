
// Observed enable-like value at +140 and color receiver at +236.
struct Cx16cTint { unsigned char r,g,b,a; };
struct Cx16cTintPanel { char reserved[140]; int enabled; char gap[92]; void *view; };
extern "C" void *cx16c_color_view_8034357c(void*);
extern "C" int cx16c_set_color_80173df0(void*,const Cx16cTint*);
extern "C" void cx16c_refresh_802b4d58(Cx16cTintPanel*);
extern "C" void w3d_cx16c_panel_tint_refresh_802b4e10(Cx16cTintPanel *self) {
 unsigned char shade=255;
 
 if(self->enabled==0) shade=180;
 unsigned char alpha=255;
 if(self->enabled==0) alpha=100;
 Cx16cTint color;
 color.r=shade; color.g=shade; color.b=shade; color.a=alpha;
 if(self->view) cx16c_set_color_80173df0(cx16c_color_view_8034357c(self->view),&color);
 cx16c_refresh_802b4d58(self);
}
