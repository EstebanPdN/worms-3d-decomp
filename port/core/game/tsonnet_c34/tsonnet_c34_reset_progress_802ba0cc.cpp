#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "tsonnet_c34_reset_progress_802ba0cc.c"
/* Reference-only: if a float member at +416 is non-zero, notifies through two
   virtual hooks of an embedded object at +28, zeroes the members at +412 and
   +416, calls an external refresh, sets the word at +244 and sends a 3-float
   vector (0, 0, member416 / member312 * constant) to the interface at +364.
   Offsets and meanings are inferred from the observed accesses. Callees and
   constants are external originals declared by address. */
struct Obj;
extern const float w3d_f32_803d8118[];
extern const float w3d_f32_803d811c[];
extern void w3d_refresh_802b929c(Ptr32<struct Obj>);
#define F(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))

void tsonnet_c34_reset_progress_802ba0cc(Ptr32<struct Obj> self) {
    float zero = w3d_f32_803d8118[0];
    if (F(self, float, 416) != zero) {
        Ptr32<void> sub = (Ptr32<char>)self + 28;
        (*(Ptr32<Ptr32<void (Ptr32<void>, int)>>)(*(Ptr32<Ptr32<char>>)((Ptr32<char>)self + 208) + 52))(sub, 0);
        F(self, float, 416) = zero;
        F(self, float, 412) = zero;
        w3d_refresh_802b929c(self);
        (*(Ptr32<Ptr32<void (Ptr32<void>, int)>>)(*(Ptr32<Ptr32<char>>)((Ptr32<char>)self + 208) + 20))(sub, 0);
        {
            float v[6];
            Ptr32<float> p = v;
            v[0] = zero;
            F(self, int, 244) = 1;
            p[1] = zero;
            p[2] = (F(self, float, 416) / F(self, float, 312)) * w3d_f32_803d811c[0];
            {
                Ptr32<void> o = F(self, void *, 364);
                (*(Ptr32<Ptr32<void (Ptr32<void>, Ptr32<float>, int)>>)(*(Ptr32<Ptr32<char>>)o + 80))(o, p, 0);
            }
        }
    }
}

}
