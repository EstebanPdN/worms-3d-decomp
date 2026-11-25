typedef struct S10Registry { char reserved[34]; unsigned short count; } S10Registry;
extern S10Registry lbl_8045ce60;
extern void fn_801b2b78(void *);
extern void fn_8020fd2c(S10Registry *, void *);
void w3d_s10_registry_remove_801b2a6c(void *object)
{
    fn_801b2b78(object);
    fn_8020fd2c(&lbl_8045ce60, (char *)object + 4);
    --lbl_8045ce60.count;
}
