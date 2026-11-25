/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct W3dStringHeader { unsigned short references; } W3dStringHeader;
typedef struct W3dString { char *text; } W3dString;
extern int lbl_804b06a0[];
extern char lbl_803b67a4[];
extern char lbl_803b67d8[];
void *fn_801ed24c(void *self, const char *name);
void fn_8020c5c0(W3dString *string);
unsigned short *fn_80341884(W3dString *string);
void fn_8020bb2c(W3dStringHeader *header);
void fn_8020c5c4(W3dString *string);
void fn_80341588(W3dString *string);
void fn_801e8d9c(void *self);
extern char lbl_803bab44[];
extern char lbl_803bab70[];
extern char lbl_803bb050[];
extern char lbl_803bb07c[];
extern char lbl_803bb0bc[];
extern char lbl_803bb0e0[];
extern char lbl_803bc420[];
extern char lbl_803bc44c[];
extern char lbl_803bc48c[];
extern char lbl_803bc4b0[];
extern char lbl_803bc4e4[];
extern char lbl_803bc508[];

int w3d_props_reset_80220f7c(void *self)
{
    W3dString empty;
    char *property;
    char *second;
    property = fn_801ed24c(self, lbl_803b67a4);
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
    second = fn_801ed24c(self, lbl_803b67d8);
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
    fn_801e8d9c(self);
    return 0;
}

int w3d_props_reset_80235cd4(void *self)
{
    W3dString empty;
    char *property;
    char *second;
    property = fn_801ed24c(self, lbl_803bab44);
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
    second = fn_801ed24c(self, lbl_803bab70);
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
    fn_801e8d9c(self);
    return 0;
}

int w3d_props_reset_8023754c(void *self)
{
    W3dString empty;
    char *property;
    char *second;
    property = fn_801ed24c(self, lbl_803bb050);
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
    second = fn_801ed24c(self, lbl_803bb07c);
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
    fn_801e8d9c(self);
    return 0;
}

int w3d_props_reset_80237ab4(void *self)
{
    W3dString empty;
    char *property;
    char *second;
    property = fn_801ed24c(self, lbl_803bb0bc);
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
    second = fn_801ed24c(self, lbl_803bb0e0);
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
    fn_801e8d9c(self);
    return 0;
}

int w3d_props_reset_8023d7f0(void *self)
{
    W3dString empty;
    char *property;
    char *second;
    property = fn_801ed24c(self, lbl_803bc420);
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
    second = fn_801ed24c(self, lbl_803bc44c);
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
    fn_801e8d9c(self);
    return 0;
}

int w3d_props_reset_8023dc64(void *self)
{
    W3dString empty;
    char *property;
    char *second;
    property = fn_801ed24c(self, lbl_803bc48c);
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
    second = fn_801ed24c(self, lbl_803bc4b0);
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
    fn_801e8d9c(self);
    return 0;
}

int w3d_props_reset_8023df70(void *self)
{
    W3dString empty;
    char *property;
    char *second;
    property = fn_801ed24c(self, lbl_803bc4e4);
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
    second = fn_801ed24c(self, lbl_803bc508);
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
    fn_801e8d9c(self);
    return 0;
}
