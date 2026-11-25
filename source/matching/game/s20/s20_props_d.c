/* Property registration that resets a shared-string property to the empty string. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct W3dStringHeader { unsigned short references; } W3dStringHeader;
typedef struct W3dString { char *text; } W3dString;
extern int lbl_804b06a0[];
extern char lbl_803a8024[];
void *fn_801ed24c(void *self, const char *name);
void fn_8020c5c0(W3dString *string);
unsigned short *fn_80341884(W3dString *string);
void fn_8020bb2c(W3dStringHeader *header);
void fn_8020c5c4(W3dString *string);
void fn_80341588(W3dString *string);
void fn_801e8d9c(void *self);

int w3d_s20_register_string_property_8018e8b8(void *self)
{
    W3dString empty;
    char *property;
    int *empty_text = lbl_804b06a0;
    property = fn_801ed24c(self, lbl_803a8024);
    fn_8020c5c0(&empty);
    empty.text = (char *)empty_text[0];
    (*fn_80341884(&empty))++;
    ++((W3dStringHeader *)(empty.text - 6))->references;
    {
        W3dStringHeader *old = (W3dStringHeader *)(FIELD(property, char *, 8) - 6);
        if (--old->references == 0)
            fn_8020bb2c(old);
    }
    FIELD(property, char *, 8) = empty.text;
    fn_8020c5c4(&empty);
    fn_80341588(&empty);
    fn_801e8d9c(self);
    return 0;
}
