// Large (5272-byte) state object built on the tagged-object family. Names and
// member meanings are inferred; offsets are observed. The tag word at +8
// packs a 24-bit pointer above an 8-bit kind, as in 0x8020b058.
#include "mx16oa_render_state_80166d8c_base.h"


// 4x4 float matrix; the shared copy at 0x8045e708 is filled at run time (the
// property code writes ones on its diagonal, so it is likely the identity).
struct Mx16oaMatrix {
    float m[4][4];
};
extern Mx16oaMatrix w3d_matrix_8045e708;

struct Mx16oaPair {
    int first;
    int second;
    void clear() { second = 0; }
    Mx16oaPair() { first = 0; clear(); }
};

struct Mx16oaStateTag {
    unsigned short a;
    unsigned short b;
    unsigned int pointer : 24;
    unsigned int kind : 8;
    Mx16oaStateTag(unsigned char tag) { kind = tag; pointer = 0; }
    void clear_halves() { a = 0; b = 0; }
};

// Tagged base: shares the root table (adds no virtual functions).
struct Mx16oaStateTagged : Mx16oaStateRoot {
    Mx16oaStateTag tag;     // +4
    Mx16oaPair pair;        // +12
    Mx16oaStateTagged() : tag(2) { tag.clear_halves(); }
};

struct Mx16oaVector4 {
    float x, y, z, w;
    Mx16oaVector4(float x0, float y0, float z0, float w0) : x(x0), y(y0), z(z0), w(w0) {}
};

struct Mx16oaColor {
    unsigned char r, g, b, a;
    Mx16oaColor(unsigned char r0, unsigned char g0, unsigned char b0, unsigned char a0)
        : r(r0), g(g0), b(b0), a(a0) {}
};

struct Mx16oaRenderState : Mx16oaStateTagged {
    int unknown20;                  // +20
    Mx16oaVector4 vector;           // +24
    Mx16oaColor color;              // +40
    float scale;                    // +44
    Mx16oaMatrix matrix_a;          // +48
    Mx16oaMatrix matrix_b;          // +112
    char unknown176[56];            // +176, not touched here
    int value232;                   // +232
    int value236;                   // +236
    int value240;                   // +240
    int value244;                   // +244
    int value248;                   // +248
    int value252;                   // +252
    unsigned char bytes256[4];      // +256
    int value260;                   // +260
    char unknown264[4996];          // +264, not touched here
    int value5260;                  // +5260
    int value5264;                  // +5264
    unsigned int flag0 : 1;         // +5268, top bit
    unsigned int flag1 : 1;
    unsigned int flag2 : 1;
    Mx16oaRenderState();
    // Table 0x80411c10 slots are defined elsewhere, so it stays external.
    void slot0();
};

Mx16oaRenderState::Mx16oaRenderState()
    : unknown20(0),
      vector(0.0f, 0.0f, 0.0f, 1.0f),
      color(0, 0, 0, 255),
      matrix_a(w3d_matrix_8045e708),
      matrix_b(w3d_matrix_8045e708)
{
    scale = 1.0f;
    value232 = 0;
    value236 = 2;
    value240 = 0;
    value244 = 0;
    value248 = 0;
    value252 = 1;
    value260 = 3;
    value5260 = 0;
    value5264 = 0;
    bytes256[0] = 0;
    bytes256[1] = 0;
    bytes256[2] = 0;
    bytes256[3] = 0;
    flag0 = 0;
    flag2 = 1;
}
