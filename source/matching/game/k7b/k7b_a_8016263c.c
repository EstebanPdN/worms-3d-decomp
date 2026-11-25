/* Static initializer: register a type descriptor and clear two file-scope pointer vectors. */
struct K7bVector { void *begin; void *end; void *capacity; };
extern char lbl_803618c0[];
extern char lbl_803e8878[];
extern char lbl_803618f0[];
extern void * fn_8016149c(void);
extern void * w3d_auto_801629f8(void *type, void *name, void *base, void (*factory)(void), int kind, int flags);
extern struct K7bVector lbl_80455244[];
extern struct K7bVector lbl_80455250[];
void w3d_k7b_static_init_8016263c(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        w3d_auto_801629f8(lbl_803618c0, lbl_803e8878, lbl_803618f0, fn_8016149c, 10, 0);
        lbl_80455244[0].capacity = 0;
        lbl_80455244[0].end = 0;
        lbl_80455244[0].begin = 0;
        lbl_80455250[0].capacity = 0;
        lbl_80455250[0].end = 0;
        lbl_80455250[0].begin = 0;
    }
}
