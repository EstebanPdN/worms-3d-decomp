/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Family templates, 2026-10-22 (third session), tenth batch: clearing a
 * shared-string field by assigning a temporary empty string. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))

extern char lbl_803a7f78[];
extern char lbl_803a7fa4[];
extern char *lbl_804b06a0[];
void *fn_801ed24c(void *, const char *);
void fn_8020c5c0(void *);
unsigned short *fn_80341884(void *);
void fn_8020bb2c(void *);
void fn_8020c5c4(void *);
void fn_80341588(void *);
void * fn_801ebf38(void *, const char *);
void fn_801e8d9c(void *);
/* Family templates, 2026-10-22 (third session), tenth batch: clearing a
 * shared-string field by assigning a temporary empty string. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))

extern char lbl_803ac6fc[];
extern char lbl_803ac730[];
void * fn_801ecc6c(void *, const char *);
/* Family templates, 2026-10-22 (third session), tenth batch: clearing a
 * shared-string field by assigning a temporary empty string. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))

extern char lbl_803b7c54[];
extern char lbl_803b7c84[];
void * fn_801eb674(void *, const char *);
/* Family templates, 2026-10-22 (third session), tenth batch: clearing a
 * shared-string field by assigning a temporary empty string. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))

extern char lbl_803c55a0[];
extern char lbl_803c55d0[];
void * fn_801ece2c(void *, const char *);

int w3d_clear_named_string_8018e348(void *self)
{
    void *owner = fn_801ed24c(self, lbl_803a7f78);
    char **empty = lbl_804b06a0;
    char *text[1];
    unsigned short *header;
    fn_8020c5c0(text);
    text[0] = *empty;
    ++*fn_80341884(text);
    ++*(unsigned short *)(text[0] - 6);
    header = (unsigned short *)(FIELD(owner, char *, 8) - 6);
    if (--*header == 0)
        fn_8020bb2c(header);
    FIELD(owner, char *, 8) = text[0];
    fn_8020c5c4(text);
    fn_80341588(text);
    fn_801ebf38(self, lbl_803a7fa4);
    fn_801e8d9c(self);
    return 0;
}

int w3d_clear_named_string_801c2260(void *self)
{
    void *owner = fn_801ed24c(self, lbl_803ac6fc);
    char **empty = lbl_804b06a0;
    char *text[1];
    unsigned short *header;
    fn_8020c5c0(text);
    text[0] = *empty;
    ++*fn_80341884(text);
    ++*(unsigned short *)(text[0] - 6);
    header = (unsigned short *)(FIELD(owner, char *, 8) - 6);
    if (--*header == 0)
        fn_8020bb2c(header);
    FIELD(owner, char *, 8) = text[0];
    fn_8020c5c4(text);
    fn_80341588(text);
    fn_801ecc6c(self, lbl_803ac730);
    fn_801e8d9c(self);
    return 0;
}

int w3d_clear_named_string_80225348(void *self)
{
    void *owner = fn_801ed24c(self, lbl_803b7c54);
    char **empty = lbl_804b06a0;
    char *text[1];
    unsigned short *header;
    fn_8020c5c0(text);
    text[0] = *empty;
    ++*fn_80341884(text);
    ++*(unsigned short *)(text[0] - 6);
    header = (unsigned short *)(FIELD(owner, char *, 8) - 6);
    if (--*header == 0)
        fn_8020bb2c(header);
    FIELD(owner, char *, 8) = text[0];
    fn_8020c5c4(text);
    fn_80341588(text);
    fn_801eb674(self, lbl_803b7c84);
    fn_801e8d9c(self);
    return 0;
}

int w3d_clear_named_string_8024f250(void *self)
{
    void *owner = fn_801ed24c(self, lbl_803c55a0);
    char **empty = lbl_804b06a0;
    char *text[1];
    unsigned short *header;
    fn_8020c5c0(text);
    text[0] = *empty;
    ++*fn_80341884(text);
    ++*(unsigned short *)(text[0] - 6);
    header = (unsigned short *)(FIELD(owner, char *, 8) - 6);
    if (--*header == 0)
        fn_8020bb2c(header);
    FIELD(owner, char *, 8) = text[0];
    fn_8020c5c4(text);
    fn_80341588(text);
    fn_801ece2c(self, lbl_803c55d0);
    fn_801e8d9c(self);
    return 0;
}
