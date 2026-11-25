typedef struct S10ReferencedObject {
    char reserved[40];
    unsigned short references;
} S10ReferencedObject;
extern void fn_801e107c(S10ReferencedObject *);
extern void fn_801e0a5c(S10ReferencedObject *, int);
unsigned short w3d_s10_release_801dfa50(S10ReferencedObject *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        fn_801e107c(object);
        if (object)
            fn_801e0a5c(object, 3);
    }
    return remaining;
}
