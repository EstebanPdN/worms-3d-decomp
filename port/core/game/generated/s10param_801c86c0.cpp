#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10param_801c86c0.c"
/* Inline 64-byte record copies; observed destination offsets. */
typedef struct S10Record64 { unsigned int words[16]; } S10Record64;
typedef struct S10Holder20 { char reserved[20]; S10Record64 value; } S10Holder20;
void w3d_s10_copy_record_801c86c0(Ptr32<S10Holder20> object, Ptr32<const S10Record64> value)
{
    object->value = *value;
}
typedef struct S10Holder112 { char reserved[112]; S10Record64 value; } S10Holder112;
void w3d_s10_copy_record_801c882c(Ptr32<S10Holder112> object, Ptr32<const S10Record64> value)
{
    object->value = *value;
}
typedef struct S10Holder48 { char reserved[48]; S10Record64 value; } S10Holder48;
void w3d_s10_copy_record_801c88a0(Ptr32<S10Holder48> object, Ptr32<const S10Record64> value)
{
    object->value = *value;
}
typedef struct S10Holder44 { char reserved[44]; S10Record64 value; } S10Holder44;
void w3d_s10_copy_record_801c8a74(Ptr32<S10Holder44> object, Ptr32<const S10Record64> value)
{
    object->value = *value;
}
void w3d_s10_copy_record_801c8bf0(Ptr32<S10Holder20> object, Ptr32<const S10Record64> value)
{
    object->value = *value;
}
void w3d_s10_copy_record_801d16f8(Ptr32<S10Holder20> object, Ptr32<const S10Record64> value)
{
    object->value = *value;
}

}
