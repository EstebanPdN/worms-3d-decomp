// desc: Appears to create a 28-byte typed entry with a float field, copying two callback pairs and appending it to the container.
struct S21Pair { int a; int b; };
struct S21Entry { char pad[4]; void *vtable; float flag; char pad1[0]; struct S21Pair first; struct S21Pair second; };
struct S21Source { char pad[20]; struct S21Pair first; struct S21Pair second; float flag; };
extern void *fn_801fe1d8(int);
extern void fn_801eb058(void *);
extern void fn_801eb0a8(struct S21Entry *, struct S21Source *);
extern int fn_801e8bc4(void *, struct S21Entry *);
extern void fn_80343740(void *);
extern char lbl_80417420[];
struct S21Entry *w3d_s21_create_typed_801ec52c(void *container, struct S21Source *source)
{
    struct S21Entry *entry = fn_801fe1d8(28);
    struct S21Pair first, second;
    float flag;
    fn_801eb058(entry);
    entry->vtable = lbl_80417420;
    
    fn_801eb0a8(entry, source);
    first = source->first;
    second = source->second;
    flag = source->flag;
    entry->first = first;
    entry->second = second;
    entry->flag = flag;
    fn_801e8bc4(container, entry);
    return entry;
}
