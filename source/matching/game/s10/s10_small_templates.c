typedef struct S10Service S10Service;
typedef int (*S10ServiceMethod)(S10Service *, void *);
struct S10Service { S10ServiceMethod *vtable; };
extern S10Service *fn_8020b648(void *);
int w3d_s10_service_forward_8020b680(void *object)
{
    S10Service *service = fn_8020b648(object);
    return service->vtable[21](service, object);
}

typedef struct S10OwnedEntry { char reserved[40]; void *owner; } S10OwnedEntry;
extern void *fn_801fe1d8(int);
extern S10OwnedEntry *fn_80208c0c(void *);
extern int fn_80208f48(S10OwnedEntry *, int, int);
S10OwnedEntry *w3d_s10_create_entry_80208aac(void *owner)
{
    S10OwnedEntry *entry = fn_80208c0c(fn_801fe1d8(44));
    entry->owner = owner;
    fn_80208f48(entry, 0, 0);
    return entry;
}
extern int fn_802047e0(void *, const void *, int);
void w3d_s10_write_double_80204224(void *writer, double value)
{
    double temporary = value;
    fn_802047e0(writer, &temporary, 8);
}
