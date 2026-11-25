// Curva de animación: valor en el instante t con su modo de repetición antes y después del tramo.
#include "native_common.h"

namespace {
struct CurveKey { float time, value; float in_divisor, in_slope, out_divisor, out_slope; };
struct CurveData {
    w3d_u32 flags;
    Ptr32<CurveKey> keys;   // +4
    uint16_t count;         // +8
};
struct Curve { Ptr32<CurveData> data; };
enum RepeatMode { kConstant, kLinear, kBounce2, kOffset, kPingPong };
inline int before_mode(const CurveData *data) { return (data->flags >> 25) & 7; }
inline int after_mode(const CurveData *data) { return (data->flags >> 22) & 7; }
}
extern "C" {
extern const float A803a84e4, A803a84e8, A803a84ec;
float A802e8b7c(float value, float *whole);
float A80196cf0(void *curve, float t);

// 0x80196a54: "before" dice si t está antes del tramo. Los modos 2 a 4 invierten el sentido de forma distinta según el lado: así lo hace el original.
float A80196a54(Ptr32<Curve> self, w3d_u32 before, float t) {
    const CurveData *data = self->data;
    if (!data || !data->count) return A803a84e4;
    const CurveKey *keys = data->keys;
    const CurveKey &first_key = keys[0], &last_key = keys[data->count - 1];
    const float first = first_key.time, last = last_key.time, span = (float)(last - first);
    if (span == A803a84e4) return first_key.value;
    const float from_start = (float)((t > last ? (float)(t - last) : (float)(t - first)) / span);
    float cycles;
    const float fraction = __builtin_fabsf(A802e8b7c(from_start, &cycles));
    cycles = (float)(__builtin_fabsf(cycles) + A803a84e8);
    float local = (float)(span * fraction);
    float half_part;
    const int mode = before ? before_mode(data) : after_mode(data);
    if (mode == kPingPong) {
        const bool odd = A802e8b7c((float)(cycles * A803a84ec), &half_part) != A803a84e4;
        local = odd == (before != 0) ? (float)(local + first) : (float)(last - local);
    } else if (mode == kBounce2 || mode == kOffset) {
        local = before ? (float)(last - local) : (float)(local + first);
    } else if (mode == kLinear) {
        if (before) {
            const float extra = (float)(first - t);
            if (first_key.in_divisor == A803a84e4) return first_key.value;
            return (float)(first_key.value - (float)((float)(extra * first_key.in_slope) / first_key.in_divisor));
        }
        const float extra = (float)(t - last);
        if (last_key.out_divisor == A803a84e4) return last_key.value;
        return (float)(last_key.value + (float)((float)(extra * last_key.out_slope) / last_key.out_divisor));
    }
    const float value = A80196cf0(self.get(), local);
    if (mode != kOffset) return value;
    const float change = (float)(last_key.value - first_key.value);
    return before ? (float)(value - (float)(cycles * change)) : fused_madd(cycles, change, value);
}
}
