// PPC32 byte offsets, four-byte pointer slots and three-float vectors are observed. Semantic names inferred.
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
#define VCALL(p,T,o) ((T)(*(void **)(*(char **)(p)+(o))))
extern const float tolerance_803806a4[],zero_803806a8[],invalid_803806ac[],four_803806b0[];
extern "C" float sqrt_802e82c0(float);
extern "C" float w3d_cx12a_quadratic_roots_8009ee18(float *out,float constant,float linear,float quadratic){
 if(__builtin_fabsf(quadratic)<tolerance_803806a4[0]){if(linear!=zero_803806a8[0]){*out=invalid_803806ac[0];return -constant/linear;}}
 else {float disc=linear*linear-(quadratic*four_803806b0[0])*constant;if(!(disc<zero_803806a8[0])){float root=sqrt_802e82c0(disc);quadratic+=quadratic;*out=(-linear+root)/quadratic;return (-linear-root)/quadratic;}}
 *out=invalid_803806ac[0];return invalid_803806ac[0];
}
