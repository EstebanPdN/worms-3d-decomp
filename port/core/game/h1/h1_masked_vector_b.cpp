#include "w3d_ptr.h"
#line 1 "h1_masked_vector_b.cpp"
/* More masked float-vector property applications through pointers to
 * member functions (session b169b320), same template as h1_masked_vector
 * for 3-, 6-, 9-, 12- and 16-float values (full masks 7, 63, 511, 4095 and
 * 65535). */

class W3dObject
{
public:
    void w3d_r_unused_slot() __asm__(W3D_SYM("_ZN9W3dObject11unused_slotEv"));
 __attribute__((always_inline)) inline void unused_slot() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_W3dObject, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_W3dObject; };
typedef w3d::Pmf<W3dObject, void(Ptr32<float>)> W3dVectorSetter;
typedef w3d::Pmf<W3dObject, Ptr32<float>()> W3dVectorGetter;

#define W3D_APPLY_MASKED_VECTOR(NAME, FULL) \
extern "C" void NAME(W3dObject *object, int mask, float *value, \
                     W3dVectorSetter set, W3dVectorGetter get) \
{ \
    if (mask == FULL) \
        (set)(object, value); \
    else { \
        int bit = 1; \
        int i = 0; \
        float *current = (get)(object); \
        do { \
            if ((mask & bit) == 0) \
                value[i] = current[i]; \
            bit <<= 1; \
            i++; \
        } while (bit & FULL); \
        (set)(object, value); \
    } \
}

W3D_APPLY_MASKED_VECTOR(w3d_apply_masked_vector_803582b4, 7)
W3D_APPLY_MASKED_VECTOR(w3d_apply_masked_vector_80358d24, 7)
W3D_APPLY_MASKED_VECTOR(w3d_apply_masked_vector_80359a88, 63)
W3D_APPLY_MASKED_VECTOR(w3d_apply_masked_vector_80358f74, 511)
W3D_APPLY_MASKED_VECTOR(w3d_apply_masked_vector_803591cc, 4095)
W3D_APPLY_MASKED_VECTOR(w3d_apply_masked_vector_8035909c, 65535)


