/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
void fn_801f8fbc(void *object, int flags);
void fn_80206b40(void *object, int flags);
void fn_8020803c(void *object, int flags);
void fn_8020d36c(void *object, int flags);
void fn_80219edc(void *object, int flags);
void fn_8021a208(void *object, int flags);
void fn_80219fc8(void *object, int flags);
void fn_8021a0b4(void *object, int flags);
void fn_8021a11c(void *object, int flags);

unsigned short w3d_release_801f8eb8(void *object)
{
    unsigned short count = --FIELD(object, unsigned short, 4);
    if (count == 0 && object)
        fn_801f8fbc(object, 3);
    return count;
}

unsigned short w3d_release_80206a44(void *object)
{
    unsigned short count = --FIELD(object, unsigned short, 4);
    if (count == 0 && object)
        fn_80206b40(object, 3);
    return count;
}

unsigned short w3d_release_80207f3c(void *object)
{
    unsigned short count = --FIELD(object, unsigned short, 4);
    if (count == 0 && object)
        fn_8020803c(object, 3);
    return count;
}

unsigned short w3d_release_8020d268(void *object)
{
    unsigned short count = --FIELD(object, unsigned short, 4);
    if (count == 0 && object)
        fn_8020d36c(object, 3);
    return count;
}

unsigned short w3d_release_80219ab8(void *object)
{
    unsigned short count = --FIELD(object, unsigned short, 20);
    if (count == 0 && object)
        fn_80219edc(object, 3);
    return count;
}

unsigned short w3d_release_80219b74(void *object)
{
    unsigned short count = --FIELD(object, unsigned short, 20);
    if (count == 0 && object)
        fn_8021a208(object, 3);
    return count;
}

unsigned short w3d_release_80219c30(void *object)
{
    unsigned short count = --FIELD(object, unsigned short, 20);
    if (count == 0 && object)
        fn_80219fc8(object, 3);
    return count;
}

unsigned short w3d_release_80219cec(void *object)
{
    unsigned short count = --FIELD(object, unsigned short, 20);
    if (count == 0 && object)
        fn_8021a0b4(object, 3);
    return count;
}

unsigned short w3d_release_80219da8(void *object)
{
    unsigned short count = --FIELD(object, unsigned short, 20);
    if (count == 0 && object)
        fn_8021a11c(object, 3);
    return count;
}
