/* Shared-string field assignment: copy the argument string, release the old value and store the new one. */
typedef struct W3dStringHeader { unsigned short references; } W3dStringHeader;
typedef struct W3dString { char *text; } W3dString;
extern void fn_8020bb54(W3dString *, char *);
extern void fn_8020bb2c(W3dStringHeader *);
extern void fn_8020c5c4(W3dString *);
extern void fn_80341588(W3dString *);

int w3d_s20_assign_string_801789ec(char *self, char **source) {
    char *owner = *(char **)(self + 4);
    W3dString copy;
    fn_8020bb54(&copy, source[0]);
    ++((W3dStringHeader *)(copy.text - 6))->references;
    {
        W3dStringHeader *old = (W3dStringHeader *)(*(char **)(owner + 24) - 6);
        if (--old->references == 0)
            fn_8020bb2c(old);
    }
    source = &copy.text;
    *(char **)(owner + 24) = *source;
    fn_8020c5c4(&copy);
    fn_80341588(&copy);
    return 0;
}
