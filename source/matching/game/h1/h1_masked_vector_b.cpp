/* More masked float-vector property applications through pointers to
 * member functions (session b169b320), same template as h1_masked_vector
 * for 3-, 6-, 9-, 12- and 16-float values (full masks 7, 63, 511, 4095 and
 * 65535). */

class W3dObject
{
public:
    virtual void unused_slot();
};
typedef void (W3dObject::*W3dVectorSetter)(float *value);
typedef float *(W3dObject::*W3dVectorGetter)();

#define W3D_APPLY_MASKED_VECTOR(NAME, FULL) \
extern "C" void NAME(W3dObject *object, int mask, float *value, \
                     W3dVectorSetter set, W3dVectorGetter get) \
{ \
    if (mask == FULL) \
        (object->*set)(value); \
    else { \
        int bit = 1; \
        int i = 0; \
        float *current = (object->*get)(); \
        do { \
            if ((mask & bit) == 0) \
                value[i] = current[i]; \
            bit <<= 1; \
            i++; \
        } while (bit & FULL); \
        (object->*set)(value); \
    } \
}

W3D_APPLY_MASKED_VECTOR(w3d_apply_masked_vector_803582b4, 7)
W3D_APPLY_MASKED_VECTOR(w3d_apply_masked_vector_80358d24, 7)
W3D_APPLY_MASKED_VECTOR(w3d_apply_masked_vector_80359a88, 63)
W3D_APPLY_MASKED_VECTOR(w3d_apply_masked_vector_80358f74, 511)
W3D_APPLY_MASKED_VECTOR(w3d_apply_masked_vector_803591cc, 4095)
W3D_APPLY_MASKED_VECTOR(w3d_apply_masked_vector_8035909c, 65535)
