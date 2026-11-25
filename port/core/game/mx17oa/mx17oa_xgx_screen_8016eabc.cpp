#include "w3d_ptr.h"
#line 1 "mx17oa_xgx_screen_8016eabc.cpp"
// XGXScreen constructor (XGXScreenImpl.cpp, from the original assertion
// string). Offsets are observed; member names are inferred from the SDK
// calls they feed and remain structural where the use is unknown. The tag
// word at +8 packs a 24-bit pointer above an 8-bit kind, as in 0x80166d8c.
#include "mx17oa_xgx_screen_8016eabc_base.h"

// GX render-mode description, 60 bytes (Dolphin SDK GXRenderModeObj layout).
struct Mx17oaRenderMode {
    unsigned int tv_mode;               // +0
    unsigned short fb_width;            // +4
    unsigned short efb_height;          // +6
    unsigned short xfb_height;          // +8
    unsigned short vi_x_origin;         // +10
    unsigned short vi_y_origin;         // +12
    unsigned short vi_width;            // +14
    unsigned short vi_height;           // +16
    unsigned int xfb_mode;              // +20
    unsigned char field_rendering;      // +24
    unsigned char antialiasing;         // +25
    unsigned char sample_pattern[12][2]; // +26
    unsigned char vertical_filter[7];   // +50
};

// SDK render modes selected by TV format (0, 1, 2); these copies are
// adjusted in place below, so they are not declared const.
extern Mx17oaRenderMode w3d_render_mode_80408120;
extern Mx17oaRenderMode w3d_render_mode_803fe370;
extern Mx17oaRenderMode w3d_render_mode_80408378;

extern "C" {
void w3d_panic_802fb82c(Ptr32<const char> file, int line, Ptr32<const char> message, ...);
void w3d_video_init_803034b4();
unsigned int w3d_video_tv_format_80304de0();
void w3d_adjust_for_overscan_80308c84(Ptr32<const Mx17oaRenderMode> in, Ptr32<Mx17oaRenderMode> out,
                                      unsigned short horizontal, unsigned short vertical);
}

struct Mx17oaPair {
    int first;
    int second;
    void clear() { second = 0; }
    Mx17oaPair() { first = 0; clear(); }
};

struct Mx17oaScreenTag {
    unsigned short a;
    unsigned short b;
    unsigned int kind:8; unsigned int pointer:24;
    Mx17oaScreenTag(unsigned char tag) { kind = tag; pointer = 0; }
    void clear_halves() { a = 0; b = 0; }
};

// Tagged base: shares the root table (adds no virtual functions).
struct Mx17oaScreenTagged : Mx17oaScreenRoot {
    Mx17oaScreenTag tag __attribute__((aligned(__alignof__(Mx17oaScreenRoot))));    // +4
    Mx17oaPair pair;        // +12
    Mx17oaScreenTagged() : tag(2) { W3D_SET_VPTR(this->Mx17oaScreenRoot::w3d_vptr_Mx17oaScreenRoot, w3d_vt___vt_18Mx17oaScreenTagged, "__vt_18Mx17oaScreenTagged");  tag.clear_halves(); }
};

// 12-byte member with an out-of-line constructor at 0x802109dc
// (+0 word 0, +4 halfword 0, +6 halfword 4, +8 word 0); meaning unknown.
struct Mx17oaScreenList {
    int head;
    unsigned short count;
    unsigned short step;
    int tail;
    Mx17oaScreenList();
};

// 424-byte member with an out-of-line constructor at 0x8016f93c; it sets up
// projection/render parameters (see the cc43a unit). Contents unknown here.
struct Mx17oaScreenRender {
    char unknown0[424];
    Mx17oaScreenRender();
};

struct Mx17oaXGXScreen;
// Single live screen instance, published by the constructor.
extern Ptr32<Mx17oaXGXScreen> w3d_screen_804b1888;

struct Mx17oaXGXScreen : Mx17oaScreenTagged {
    Mx17oaScreenList list __attribute__((aligned(__alignof__(Mx17oaScreenTagged))));              // +20
    int unknown32;                      // +32
    int unknown36;                      // +36, not touched here
    Ptr32<Mx17oaRenderMode> render_mode;      // +40
    Mx17oaRenderMode adjusted_mode;     // +44
    Mx17oaScreenRender render;          // +104
    int unknown528[2];                  // +528
    int unknown536;                     // +536
    int unknown540;                     // +540
    float filter_scale;                 // +544
    unsigned char filter[7];            // +548
    Mx17oaXGXScreen();
    // Table 0x80411e60 slots are defined elsewhere, so it stays external.
    void w3d_r_slot0() __asm__(W3D_SYM("_ZN15Mx17oaXGXScreen5slot0Ev"));
    void set_filter_scale(float scale);     // 0x8016ee4c
    void setup_video_buffers();             // 0x8016f004
 __attribute__((always_inline)) inline void slot0() { this->Mx17oaScreenTagged::slot0(); } };

Mx17oaXGXScreen::Mx17oaXGXScreen()
    : unknown32(0)
{ W3D_SET_VPTR(this->Mx17oaScreenTagged::w3d_vptr_Mx17oaScreenRoot, w3d_vt___vt_15Mx17oaXGXScreen, "__vt_15Mx17oaXGXScreen"); 
    w3d_screen_804b1888 = this;
    unknown536 = 0;
    for (unsigned int i = 0; i < 2; i++)
        unknown528[i] = 0;
    w3d_video_init_803034b4();
    unknown540 = 0;
    switch (w3d_video_tv_format_80304de0()) {
    case 0:
        unknown540 = 0;
        render_mode = &w3d_render_mode_80408120;
        set_filter_scale(1.0f);
        break;
    case 1:
        unknown540 = 0;
        render_mode = &w3d_render_mode_803fe370;
        set_filter_scale(1.1f);
        break;
    case 2:
        unknown540 = 0;
        render_mode = &w3d_render_mode_80408378;
        set_filter_scale(1.1f);
        break;
    default:
        w3d_panic_802fb82c("XGXScreenImpl.cpp", 124, "XGXScreen: invalid TV format\n");
        break;
    }
    render_mode->vi_width = 660;
    render_mode->vi_x_origin = 30;
    w3d_adjust_for_overscan_80308c84(render_mode, &adjusted_mode, 0, 16);
    render_mode = &adjusted_mode;
    setup_video_buffers();
    set_filter_scale(filter_scale);
}


