typedef struct S12ByteVector { char *begin, *end, *limit; } S12ByteVector;
typedef struct S12VectorOwner { char reserved[40]; S12ByteVector values; } S12VectorOwner;
extern void *fn_80212fd4(unsigned int);
extern void fn_802134fc(void *);
extern "C" void *memcpy(void *, ...);
static inline const int &s12_max(const int &a, const int &b) { return a < b ? b : a; }
static inline const unsigned int &s12_min(const unsigned int &a, const unsigned int &b) { return a > b ? b : a; }
extern "C" int w3d_s12_append_value_801b1bb0(S12VectorOwner *object, int value)
{
    S12ByteVector *vector = &object->values;
    const int *element = &value;
    if (vector->end == vector->limit) {
        unsigned int oldBytes = vector->end - vector->begin;
        int minimum = oldBytes + 1;
        int grown = oldBytes + (oldBytes >> 1);
        const int *capacity = &s12_max(minimum, grown);
        unsigned int newBytes = *capacity * 4;
        char *replacement = (char *)fn_80212fd4(newBytes);
        if (vector->begin) {
            const unsigned int *copied = &s12_min(newBytes, oldBytes);
            memcpy(replacement, vector->begin, *copied);
            fn_802134fc(vector->begin);
        }
        vector->begin = replacement;
        /* Preserve the observed order of pointer publication and capacity read. */
        ((volatile S12ByteVector *)vector)->end = replacement + oldBytes;
        vector->limit = replacement + *(volatile unsigned int *)&newBytes;
    }
    *(int *)vector->end = *element;
    vector->end += 4;
    return 0;
}
