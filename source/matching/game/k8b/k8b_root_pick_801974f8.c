struct K8bCurve { float *coefficients; int degree; };
extern float lbl_804ab6e4;
extern float w3d_s20_evaluate_polynomial_80197244(float *coefficients, int degree, float x);
extern float fn_8019727c(struct K8bCurve *self, float low, float high, float f_low, float f_high, float tolerance);

float w3d_k8b_root_pick_801974f8(struct K8bCurve *self, float low, float high, float tolerance)
{
    volatile char pad[32];
    float result;
    float f_low = w3d_s20_evaluate_polynomial_80197244(self->coefficients, self->degree, low);
    if (!(__builtin_fabsf(f_low) < lbl_804ab6e4)) {
        float f_high = w3d_s20_evaluate_polynomial_80197244(self->coefficients, self->degree, high);
        result = high;
        if (!(__builtin_fabsf(f_high) < lbl_804ab6e4))
            result = fn_8019727c(self, low, high, f_low, f_high, tolerance);
    } else {
        result = low;
    }
    return result;
}
