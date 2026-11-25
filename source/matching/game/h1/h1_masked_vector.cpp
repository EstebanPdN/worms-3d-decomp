/* Masked float-vector property application through pointers to member
 * functions (session b169b320). A full mask (15, 3 or 1 for four, two or one
 * components) passes the value straight to the setter; otherwise the
 * components whose mask bit is clear are first filled from the getter's
 * current value. The template was emitted for 4-, 2- and 1-float values. Pointers to members use GCC 2.95's thunk-style vtables. */

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

W3D_APPLY_MASKED_VECTOR(w3d_apply_masked_vector_803583dc, 15)
W3D_APPLY_MASKED_VECTOR(w3d_apply_masked_vector_80358758, 15)
W3D_APPLY_MASKED_VECTOR(w3d_apply_masked_vector_803589a8, 15)
W3D_APPLY_MASKED_VECTOR(w3d_apply_masked_vector_80358e4c, 15)
W3D_APPLY_MASKED_VECTOR(w3d_apply_masked_vector_80359960, 15)
W3D_APPLY_MASKED_VECTOR(w3d_apply_masked_vector_80359bb0, 15)
W3D_APPLY_MASKED_VECTOR(w3d_apply_masked_vector_8035818c, 3)
W3D_APPLY_MASKED_VECTOR(w3d_apply_masked_vector_80358630, 3)
W3D_APPLY_MASKED_VECTOR(w3d_apply_masked_vector_80358880, 3)
W3D_APPLY_MASKED_VECTOR(w3d_apply_masked_vector_80358bfc, 3)
W3D_APPLY_MASKED_VECTOR(w3d_apply_masked_vector_80358504, 1)
W3D_APPLY_MASKED_VECTOR(w3d_apply_masked_vector_80358ad0, 1)
W3D_APPLY_MASKED_VECTOR(w3d_apply_masked_vector_80359708, 1)
W3D_APPLY_MASKED_VECTOR(w3d_apply_masked_vector_80359834, 1)
