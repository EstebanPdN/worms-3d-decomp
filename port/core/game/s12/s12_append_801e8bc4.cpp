#include "w3d_ptr.h"
#line 1 "s12_append_801e8bc4.cpp"
typedef struct S12ByteVector { Ptr32<char> begin; Ptr32<char> end; Ptr32<char> limit; } S12ByteVector;
typedef struct S12VectorOwner { char reserved[48]; S12ByteVector values; } S12VectorOwner;
extern Ptr32<void> fn_80212fd4(unsigned int);
extern void fn_802134fc(Ptr32<void>);
extern "C" Ptr32<void> memcpy(Ptr32<void>, ...);
static inline const int &s12_max(const int &a, const int &b) { return a < b ? b : a; }
static inline const unsigned int &s12_min(const unsigned int &a, const unsigned int &b) { return a > b ? b : a; }
extern "C" int w3d_s12_append_value_801e8bc4(Ptr32<S12VectorOwner> object, int value)
{
    Ptr32<S12ByteVector> vector = &object->values;
    Ptr32<const int> element = &value;
    if (vector->end == vector->limit) {
        unsigned int oldBytes = vector->end - vector->begin;
        int minimum = oldBytes + 1;
        int grown = oldBytes + (oldBytes >> 1);
        Ptr32<const int> capacity = &s12_max(minimum, grown);
        unsigned int newBytes = *capacity * 4;
        Ptr32<char> replacement = (Ptr32<char>)fn_80212fd4(newBytes);
        if (vector->begin) {
            Ptr32<const unsigned int> copied = &s12_min(newBytes, oldBytes);
            memcpy(replacement, w3d::VA(vector->begin), *copied);
            fn_802134fc(vector->begin);
        }
        vector->begin = replacement;
        /* Preserve the observed order of pointer publication and capacity read. */
        ((Ptr32<volatile S12ByteVector>)vector)->end = replacement + oldBytes;
        vector->limit = replacement + *(Ptr32<volatile unsigned int>)&newBytes;
    }
    *(Ptr32<int>)vector->end = *element;
    vector->end += 4;
    return 0;
}


