// desc: Appears to create a 28-byte typed entry, construct and initialize it from a source descriptor, copy two callback pairs and a flag byte and append it to the container.
struct S21Pair { int a; int b; };
struct S21Entry { char pad[4]; void *vtable; unsigned char flag; char pad1[3]; struct S21Pair first; struct S21Pair second; };
struct S21Source { char pad[20]; struct S21Pair first; struct S21Pair second; unsigned char flag; };
extern void *fn_801fe1d8(int);
extern void fn_801eb058(void *);
extern void fn_801eb0a8(struct S21Entry *, struct S21Source *);
extern int fn_801e8bc4(void *, struct S21Entry *);
extern char lbl_804175a0[];
struct S21Entry *w3d_s21_create_typed_801eb834(void *container, struct S21Source *source)
{
    struct S21Entry *entry = fn_801fe1d8(28);
    unsigned char flag;
    struct S21Pair first, second;
    fn_801eb058(entry);
    entry->vtable = lbl_804175a0;
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
