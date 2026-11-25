/* Set a string field of the inner object when it changed. */
typedef struct W3dStringHeader { unsigned short references; } W3dStringHeader;
typedef struct W3dString { char *text; } W3dString;
extern int strcmp(char *, char *);
extern void fn_8020bb54(W3dString *, char *);
extern void fn_8020bb2c(W3dStringHeader *);
extern void fn_8020c5c4(W3dString *);
extern void fn_80341588(W3dString *);
extern void fn_80178b5c(char *);

int w3d_s20_set_name_801790bc(char *self, char *name) {
    char *owner;
    W3dString copy;
    char **slot;
    if (strcmp(*(char **)(*(char **)(self + 4) + 28), name) == 0)
        return 1;
    owner = *(char **)(self + 4);
    fn_8020bb54(&copy, name);
    ++((W3dStringHeader *)(copy.text - 6))->references;
    {
        W3dStringHeader *old = (W3dStringHeader *)(*(char **)(owner + 28) - 6);
        if (--old->references == 0)
            fn_8020bb2c(old);
    }
    slot = &copy.text;
    *(char **)(owner + 28) = *slot;
    fn_8020c5c4(&copy);
    fn_80341588(&copy);
    fn_80178b5c(self);
    return 0;
}
