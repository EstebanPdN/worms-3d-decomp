#include "w3d_ptr.h"
#line 1 "d25b_wobble_update_8009ddc4.cpp"
/* Gun wobble update (0x8009ddc4): from the elapsed time since +4 and the amplitude and
 * period read from +8 and +12 (0x80178df0, 0x80178d1c) computes a cosine decay, sums the
 * four X curves and the four Y curves (0x8009dfd4 with indices 0-3 and 4-7), and when the
 * flag is set adds random jitter at the interval in the settings object from +128
 * (0x801797b4) to the running offsets +120 and +124. Stores the results at +148 and +144
 * of the object loaded through +16 (0x80178c48, 0x800fc710). Field and type names are
 * inferred from the original instructions. Owns its float literals at 0x80380550. */
struct Context { char unknown00[52]; unsigned now; };
struct Settings { char unknown00[232]; unsigned interval; char unknown236[4]; float jitter; };
struct Target { char unknown00[144]; float y; float x; };
struct Descriptor_80178474 {
    Ptr32<void> value;
    unsigned tag;
    Descriptor_80178474() : value(0), tag(58280) {}
    ~Descriptor_80178474();
};
struct Wobble {
    char unknown00[4];
    unsigned start;    /* +4 */
    int amplitude;     /* +8 */
    int period;        /* +12 */
    int target;        /* +16 */
    char unknown20[96];
    unsigned last;     /* +116 */
    float offsetX;     /* +120 */
    float offsetY;     /* +124 */
    int settings;      /* +128 */
};
extern "C" Ptr32<Context> w3d_engine_get_context_80165254();
extern "C" float w3d_auto_80178df0(Ptr32<void>);
extern "C" unsigned w3d_auto_80178d1c(Ptr32<void>);
extern "C" float w3d_cosf_802e86d4(float);
extern "C" float k2a_curve_eval_8009dfd4(Ptr32<Wobble>, int, float);
extern "C" int w3d_auto_80178c48(Ptr32<void>);
extern "C" Ptr32<Target> s8_handle_800fc710(int, Ptr32<Descriptor_80178474>);
extern "C" int w3d_empty_80341584(int);
extern "C" Ptr32<Settings> w3d_auto_801797b4(Ptr32<void>);
extern "C" float fn_80162bc8();

extern "C" void w3d_d25b_wobble_update_8009ddc4(Ptr32<Wobble> self, int jitter)
{
    unsigned now = w3d_engine_get_context_80165254()->now;
    int elapsed = now - self->start;
    float amplitude = w3d_auto_80178df0((Ptr32<void>)w3d::G(self->amplitude));
    unsigned period = w3d_auto_80178d1c((Ptr32<void>)w3d::G(self->period));
    float scale = amplitude * w3d_cosf_802e86d4((float)elapsed / (float)period);
    float y = 0.0f;
    float x = y;
    for (unsigned i = 0; i <= 3; i++) x += k2a_curve_eval_8009dfd4(self, i, (float)elapsed);
    float scaledX = x * scale;
    for (unsigned j = 0; j <= 3; j++) y += k2a_curve_eval_8009dfd4(self, j + 4, (float)elapsed);
    y *= scale;
    Descriptor_80178474 descriptor;
    Ptr32<Target> target = s8_handle_800fc710(w3d_auto_80178c48((Ptr32<void>)w3d::G(self->target)), &descriptor);
    Ptr32<Settings> settings = w3d_auto_801797b4((Ptr32<void>)w3d::G((w3d_empty_80341584(self->settings))));
    if (jitter && now - self->last >= settings->interval) {
        self->last = now;
        self->offsetX += settings->jitter;
        self->offsetY += (fn_80162bc8() - 0.5f) * settings->jitter;
    }
    x = scaledX + self->offsetX;
    y += self->offsetY;
    target->x = x;
    target->y = y;
}


