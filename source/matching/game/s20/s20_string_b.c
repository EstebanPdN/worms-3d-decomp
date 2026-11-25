/* Methods that take over a shared string argument. */
typedef struct W3dStringHeader { unsigned short references; } W3dStringHeader;
typedef struct W3dString { char *text; } W3dString;
extern void fn_800f6afc(char *, W3dString *, int);
extern void fn_8020bb2c(W3dStringHeader *);
extern void fn_8020c5c4(W3dString *);
extern int fn_80341588(W3dString *);

int w3d_s20_set_title_800f2f94(char *self, W3dString *title, int value) {
    fn_800f6afc(self, title, value);
    ++((W3dStringHeader *)(title->text - 6))->references;
    {
        W3dStringHeader *old = (W3dStringHeader *)(*(char **)(self + 892) - 6);
        if (--old->references == 0)
            fn_8020bb2c(old);
    }
    {
        char *text = title->text;
        *(int *)(self + 3196) = value;
        *(char **)(self + 892) = text;
        *(int *)(self + 3168) = 1;
        *(int *)(self + 3172) = 5;
    }
    fn_8020c5c4(title);
    return fn_80341588(title);
}
