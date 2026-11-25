/* Byte-identical copies of hand-matched leaf functions, written by
 * tools/gen_clone_units.py and verified identical to the original after
 * linking. Names are structural (address); the owning classes are unknown. */

typedef struct W3dMemberFunction {
    short delta;
    short index;
    union { void *function; short vtable_offset; } u;
} W3dMemberFunction;
typedef void (*W3dSetFn)(void *object, int value);
typedef int (*W3dReadFn)(void *reader, int *value, int key, int flags);
typedef struct W3dReader { void **vtable; } W3dReader;
typedef struct W3dReaderOwner { unsigned char unknown_00[8]; W3dReader *reader; } W3dReaderOwner;
typedef struct W3dReadBinding {
    W3dReaderOwner *owner;
    unsigned char unknown_04[0x10];
    W3dMemberFunction setter;
} W3dReadBinding;

int w3d_pmf_read_801eb5dc(const W3dReadBinding *binding, int key, char *target)
{
    int value;
    int result;
    W3dSetFn set;
    W3dReader *reader = binding->owner->reader;
    result = ((W3dReadFn)reader->vtable[18])(reader, &value, key, 0);
    if (result >= 0) {
        if (binding->setter.index >= 0)
            set = (W3dSetFn)((void **)*(char **)(target + binding->setter.u.vtable_offset))[binding->setter.index - 1];
        else
            set = (W3dSetFn)binding->setter.u.function;
        set(target + binding->setter.delta, value);
    }
    return result;
}

int w3d_pmf_read_801ebea0(const W3dReadBinding *binding, int key, char *target)
{
    int value;
    int result;
    W3dSetFn set;
    W3dReader *reader = binding->owner->reader;
    result = ((W3dReadFn)reader->vtable[18])(reader, &value, key, 0);
    if (result >= 0) {
        if (binding->setter.index >= 0)
            set = (W3dSetFn)((void **)*(char **)(target + binding->setter.u.vtable_offset))[binding->setter.index - 1];
        else
            set = (W3dSetFn)binding->setter.u.function;
        set(target + binding->setter.delta, value);
    }
    return result;
}

int w3d_pmf_read_801ec060(const W3dReadBinding *binding, int key, char *target)
{
    int value;
    int result;
    W3dSetFn set;
    W3dReader *reader = binding->owner->reader;
    result = ((W3dReadFn)reader->vtable[18])(reader, &value, key, 0);
    if (result >= 0) {
        if (binding->setter.index >= 0)
            set = (W3dSetFn)((void **)*(char **)(target + binding->setter.u.vtable_offset))[binding->setter.index - 1];
        else
            set = (W3dSetFn)binding->setter.u.function;
        set(target + binding->setter.delta, value);
    }
    return result;
}

int w3d_pmf_read_801ec784(const W3dReadBinding *binding, int key, char *target)
{
    int value;
    int result;
    W3dSetFn set;
    W3dReader *reader = binding->owner->reader;
    result = ((W3dReadFn)reader->vtable[18])(reader, &value, key, 0);
    if (result >= 0) {
        if (binding->setter.index >= 0)
            set = (W3dSetFn)((void **)*(char **)(target + binding->setter.u.vtable_offset))[binding->setter.index - 1];
        else
            set = (W3dSetFn)binding->setter.u.function;
        set(target + binding->setter.delta, value);
    }
    return result;
}

int w3d_pmf_read_801ecbd4(const W3dReadBinding *binding, int key, char *target)
{
    int value;
    int result;
    W3dSetFn set;
    W3dReader *reader = binding->owner->reader;
    result = ((W3dReadFn)reader->vtable[18])(reader, &value, key, 0);
    if (result >= 0) {
        if (binding->setter.index >= 0)
            set = (W3dSetFn)((void **)*(char **)(target + binding->setter.u.vtable_offset))[binding->setter.index - 1];
        else
            set = (W3dSetFn)binding->setter.u.function;
        set(target + binding->setter.delta, value);
    }
    return result;
}

int w3d_pmf_read_801ecd94(const W3dReadBinding *binding, int key, char *target)
{
    int value;
    int result;
    W3dSetFn set;
    W3dReader *reader = binding->owner->reader;
    result = ((W3dReadFn)reader->vtable[18])(reader, &value, key, 0);
    if (result >= 0) {
        if (binding->setter.index >= 0)
            set = (W3dSetFn)((void **)*(char **)(target + binding->setter.u.vtable_offset))[binding->setter.index - 1];
        else
            set = (W3dSetFn)binding->setter.u.function;
        set(target + binding->setter.delta, value);
    }
    return result;
}
