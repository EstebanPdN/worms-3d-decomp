#include "w3d_ptr.h"
#line 1 "d43k_game_state_reset_802487c4.cpp"
// GWMP8P rev0 0x802487c4. Resets a large state block: the second-level
// vectors and counters to zero, two mode words to 3, the 0.6 weight, two
// strings to the shared empty string (0x804b06a0, released through
// 0x8020bb2c), then a long run of enable flags to 1. Field names are
// offsets; the class meaning is not witnessed.
extern "C" void fn_8020bb2c(Ptr32<void>);
struct D43kStringHeader { unsigned short refs, length, capacity; };
struct D43kString { Ptr32<char> p; D43kString &operator=(const D43kString &o) { ++((Ptr32<D43kStringHeader>)(o.p - 6))->refs; Ptr32<D43kStringHeader> h = (Ptr32<D43kStringHeader>)(p - 6); if (--h->refs == 0) fn_8020bb2c(h); p = o.p; return *this; } };
extern D43kString lbl_804b06a0[];
struct D43kVec { float x, y, z; void Set(float a, float b, float c) { Ptr32<D43kVec> q = this; x = a; q->y = b; q->z = c; } };
struct D43kGameState { char u0[20]; D43kVec v20; D43kVec v32; D43kVec v44; D43kVec v56; D43kVec v68; char u80[12]; D43kVec v92; int f104; D43kString f108; int f112; float f116; int f120; float f124; int f128; int f132; int f136; char u140[4]; float f144; float f148; D43kString f152; int f156; int f160; int f164; short f168; short f170; unsigned char f172; unsigned char f173; unsigned char f174; unsigned char f175; unsigned char f176; unsigned char f177; unsigned char f178; unsigned char f179; int f180; int f184; int f188; int f192; int f196; int f200; int f204; int f208; char f212; char u213[3]; int f216; int f220; unsigned char f224; unsigned char f225; unsigned char f226; unsigned char f227; unsigned char f228; unsigned char f229; unsigned char f230; unsigned char f231; unsigned char f232; unsigned char f233; unsigned char f234; unsigned char f235; unsigned char f236; unsigned char f237; unsigned char f238; unsigned char f239; unsigned char f240; unsigned char f241; unsigned char f242; unsigned char f243; unsigned char f244; unsigned char f245; unsigned char f246; char u247[1]; int f248; unsigned char f252; char u253[3]; int f256; int f260; unsigned char f264; unsigned char f265; unsigned char f266; unsigned char f267; unsigned char f268; unsigned char f269; unsigned char f270; unsigned char f271; unsigned char f272; unsigned char f273; unsigned char f274; unsigned char f275; unsigned char f276; unsigned char f277; unsigned char f278; unsigned char f279; unsigned char f280; unsigned char f281; unsigned char f282;};
extern "C" void w3d_d43k_game_state_reset_802487c4(Ptr32<D43kGameState> self) {
 float zero = 0.0f;
 self->f220 = 0;
 self->v68.Set(zero, zero, zero);
 self->v56.Set(zero, zero, zero);
 self->v92.Set(zero, zero, zero);
 self->v44.Set(zero, zero, zero);
 self->v32.Set(zero, zero, zero);
 self->f112 = 3;
 self->f104 = 3;
 self->f116 = 0.6f;
 self->f128 = 0;
 self->f124 = zero;
 self->f132 = 0;
 self->f216 = 0;
 self->f170 = 0;
 self->f204 = 0;
 self->f168 = 0;
 self->f212 = 0;
 self->f196 = 0;
 self->f136 = 0;
 self->f120 = 0;
 self->f208 = 0;
 self->f164 = 0;
 self->f160 = 0;
 self->f156 = 0;
 self->f108 = lbl_804b06a0[0];
 self->f152 = lbl_804b06a0[0];
 self->f200 = 0;
 self->v20.Set(zero, zero, zero);
 self->f192 = 0;
 self->f188 = 1;
 self->f184 = 0;
 self->f148 = zero;
 self->f144 = zero;
 self->f180 = 0;
 self->f179 = 1;
 self->f178 = 1;
 self->f172 = 1;
 self->f176 = 1;
 self->f175 = 1;
 self->f174 = 1;
 self->f173 = 1;
 self->f177 = 1;
 self->f246 = 1;
 self->f236 = 1;
 self->f245 = 1;
 self->f244 = 1;
 self->f243 = 1;
 self->f242 = 1;
 self->f266 = 1;
 self->f240 = 1;
 self->f239 = 1;
 self->f238 = 1;
 self->f237 = 1;
 self->f272 = 1;
 self->f235 = 1;
 self->f234 = 1;
 self->f233 = 1;
 self->f232 = 1;
 self->f231 = 1;
 self->f230 = 1;
 self->f278 = 1;
 self->f228 = 1;
 self->f227 = 1;
 self->f226 = 1;
 self->f225 = 1;
 self->f271 = 1;
 self->f282 = 1;
 self->f281 = 1;
 self->f280 = 1;
 self->f279 = 1;
 self->f229 = 1;
 self->f277 = 1;
 self->f276 = 1;
 self->f275 = 1;
 self->f274 = 1;
 self->f273 = 1;
 self->f224 = 1;
 self->f252 = 1;
 self->f270 = 1;
 self->f269 = 1;
 self->f268 = 1;
 self->f267 = 1;
 self->f241 = 1;
 self->f265 = 1;
 self->f264 = 1;
 self->f260 = 0;
 self->f256 = 1;
 self->f248 = 0;
}


