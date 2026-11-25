typedef struct S10ByteVector { char *begin, *end, *limit; } S10ByteVector;
typedef struct S10VectorOwner { char reserved[60]; S10ByteVector values; } S10VectorOwner;
extern void *fn_80212fd4(unsigned int);
extern void fn_802134fc(void *);
void *memcpy();
int w3d_s10_append_value_801a654c(S10VectorOwner *object, int value)
{
    S10ByteVector *vector = &object->values;
    const int *element = &value;
    if (vector->end == vector->limit) {
        unsigned int oldBytes = vector->end - vector->begin;
        int minimum = oldBytes + 1;
        int grown = oldBytes + (oldBytes >> 1);
        int *capacity = minimum >= grown ? &minimum : &grown;
        unsigned int newBytes = *capacity * 4;
        char *replacement = fn_80212fd4(newBytes);
        if (vector->begin) {
            unsigned int *copied = newBytes <= oldBytes ? &newBytes : &oldBytes;
            memcpy(replacement, vector->begin, *copied);
            fn_802134fc(vector->begin);
        }
        vector->begin = replacement;
        vector->end = replacement + oldBytes;
        vector->limit = replacement + newBytes;
    }
    *(int *)vector->end = *element;
    vector->end += 4;
    return 0;
}
