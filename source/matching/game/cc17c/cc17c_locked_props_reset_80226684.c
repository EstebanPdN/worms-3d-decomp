/* Same source shape as the admitted string-field reset 0x8018e348 (genparamc_8018e348.c), with an
 * extra leading binding: binds Locked, resets the LockedTitle string to the shared empty string
 * (16-bit reference count 6 bytes before the text, observed) and binds LockedIcon. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
extern char lbl_803b7fec[];
extern char lbl_803b8020[];
extern char lbl_803b8050[];
extern char *lbl_804b06a0[];
void * fn_801eb674(void *, const char *);
void *fn_801ed24c(void *, const char *);
void fn_8020c5c0(void *);
unsigned short *fn_80341884(void *);
void fn_8020bb2c(void *);
void fn_8020c5c4(void *);
void fn_80341588(void *);
void * fn_801ece2c(void *, const char *);
void fn_801e8d9c(void *);
int w3d_cc17c_locked_props_reset_80226684(void *self)
{
    void *owner;
    char **empty;
    char *text[1];
    unsigned short *header;
    fn_801eb674(self, lbl_803b7fec);
    owner = fn_801ed24c(self, lbl_803b8020);
    empty = lbl_804b06a0;
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
    fn_801ece2c(self, lbl_803b8050);
    fn_801e8d9c(self);
    return 0;
}
