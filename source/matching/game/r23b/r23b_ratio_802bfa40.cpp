// desc: Return the float sum at +0x40/+0x3c divided by twice +0x24, capped by external bound; names inferred.
// Arithmetic uses single-precision operations. The external bound's ownership remains unresolved.
struct R23bRatioObject { unsigned char unknown[0x24]; float denominator; unsigned char gap[0x14]; float left, right; };
extern const float r23b_ratio_limit_803d8414[];
extern "C" float w3d_r23b_ratio_802bfa40(R23bRatioObject *self) {
 float value=(self->right+self->left)/(self->denominator+self->denominator);
 if(value>r23b_ratio_limit_803d8414[0]) value=r23b_ratio_limit_803d8414[0];
 return value;
}
