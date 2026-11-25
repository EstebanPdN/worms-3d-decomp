/* Reference-counted objects; observed field layouts. */
typedef struct S10ReferencedObject40 {
    char reserved[40];
    unsigned short references;
} S10ReferencedObject40;
extern void fn_801e107c(S10ReferencedObject40 *);
extern void fn_801e0a5c(S10ReferencedObject40 *, int);
typedef struct S10ReferencedObject12 {
    char reserved[12];
    unsigned short references;
} S10ReferencedObject12;
extern void fn_801f96f4(S10ReferencedObject12 *);
extern void fn_801fa11c(S10ReferencedObject12 *, int);
typedef struct S10ReferencedObject8 {
    char reserved[8];
    unsigned short references;
} S10ReferencedObject8;
extern void fn_801f97a4(S10ReferencedObject8 *);
extern void fn_801fb6a4(S10ReferencedObject8 *, int);
extern void fn_801fc04c(S10ReferencedObject12 *);
extern void fn_801fc428(S10ReferencedObject12 *, int);
extern void fn_801fc0fc(S10ReferencedObject8 *);
extern void fn_801fc564(S10ReferencedObject8 *, int);

unsigned short w3d_s10_release_801dfa50(S10ReferencedObject40 *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        fn_801e107c(object);
        if (object)
            fn_801e0a5c(object, 3);
    }
    return remaining;
}

unsigned short w3d_s10_release_801f9854(S10ReferencedObject12 *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        fn_801f96f4(object);
        if (object)
            fn_801fa11c(object, 3);
    }
    return remaining;
}

unsigned short w3d_s10_release_801f991c(S10ReferencedObject8 *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        fn_801f97a4(object);
        if (object)
            fn_801fb6a4(object, 3);
    }
    return remaining;
}

unsigned short w3d_s10_release_801fc1ac(S10ReferencedObject12 *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        fn_801fc04c(object);
        if (object)
            fn_801fc428(object, 3);
    }
    return remaining;
}

unsigned short w3d_s10_release_801fc274(S10ReferencedObject8 *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        fn_801fc0fc(object);
        if (object)
            fn_801fc564(object, 3);
    }
    return remaining;
}
