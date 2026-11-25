/* Assigns a default text to the owner's string field, then replaces it with a
   shared string chosen from the scene's table by index (a value from the
   owner modulo the table count), adjusting the reference counts. Offsets are
   observed; field names and meanings are inferred. */
typedef struct { char p0[24]; unsigned int count; char p1[4]; } Table;
typedef struct { char p0[192]; void *ctx; char p1[108]; char *text; } Owner;
extern void *fn_80341584(void *);
extern char *fn_801797b4(void *);
extern void fn_8020bd38(char **, const char *);
extern void fn_8020bb2c(void *);
extern unsigned int fn_80161080(void *);
extern char lbl_8038b568[];
void tsonnet_b28_pick_800edd90(Owner *o) {
    Table *t = *(Table **)(fn_801797b4(fn_80341584(o->ctx)) + 232);
    unsigned int n = t->count;
    char **items = (char **)((char *)t + 32);
    fn_8020bd38(&o->text, lbl_8038b568);
    if (n != 0) {
        unsigned int i = fn_80161080(o) % n;
        char *s = items[i];
        (*(unsigned short *)(s - 6))++;
        { unsigned short *h = (unsigned short *)(o->text - 6); if (--*h == 0) fn_8020bb2c(h); }
        o->text = items[i];
    }
}
