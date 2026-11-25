// desc: Appears to look up a shared object for a key: it retains the object from a global registry, initializes it, stores it in the output on success or releases it and returns the failure status.
// desc: Appears to look up a shared object for a key: it retains the object from a global registry, initializes it, stores it in the output on success or releases it and returns the failure status.
struct S21Ref;
struct S21RefMethods { void (*reserved[3])(void); void (*retain)(struct S21Ref *); void (*release)(struct S21Ref *); };
struct S21Ref { struct S21RefMethods *methods; };
extern char lbl_80365808[];
extern struct S21Ref *fn_8020fcb4(void *);
extern int fn_801f8754(struct S21Ref *, void *);
int w3d_s21_acquire_801f7e98(int unused, int key, struct S21Ref **out)
{
    struct S21Ref *object = fn_8020fcb4(lbl_80365808);
    int status;
    object->methods->retain(object);
    status = fn_801f8754(object, key);
    if (status < 0) {
        object->methods->release(object);
        return status;
    }
    *out = object;
    return 0;
}
