/* Same source shape as the admitted property reset 0x80220f7c (genparam_80220f7c.c): resets the
 * ItemHighlightedMessage and ItemSelectedMessage string properties to the shared empty string, then
 * binds BorderColour. Observed string header: 16-bit reference count 6 bytes before the text. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct W3dStringHeader { unsigned short references; } W3dStringHeader;
typedef struct W3dString { char *text; } W3dString;
extern int lbl_804b06a0[];
extern char lbl_803b6a78[];
extern char lbl_803b6ab0[];
extern char lbl_803b6ad4[];
void * fn_801ece2c(void *self, const char *name);
void *fn_801ed24c(void *self, const char *name);
void fn_8020c5c0(W3dString *string);
unsigned short *fn_80341884(W3dString *string);
void fn_8020bb2c(W3dStringHeader *header);
void fn_8020c5c4(W3dString *string);
void fn_80341588(W3dString *string);
void fn_801e8d9c(void *self);

int w3d_cc17c_props_reset_80221c84(void *self)
{
    W3dString empty;
    char *property;
    char *second;
    property = fn_801ed24c(self, lbl_803b6a78);
    fn_8020c5c0(&empty);
    empty.text = (char *)lbl_804b06a0[0];
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
    second = fn_801ed24c(self, lbl_803b6ab0);
    fn_8020c5c0(&empty);
    empty.text = (char *)lbl_804b06a0[0];
    (*fn_80341884(&empty))++;
    ++((W3dStringHeader *)(empty.text - 6))->references;
    {
        W3dStringHeader *old = (W3dStringHeader *)(FIELD(second, char *, 8) - 6);
        if (--old->references == 0)
            fn_8020bb2c(old);
    }
    FIELD(second, char *, 8) = empty.text;
    fn_8020c5c4(&empty);
    fn_80341588(&empty);
    fn_801ece2c(self, lbl_803b6ad4);
    fn_801e8d9c(self);
    return 0;
}
