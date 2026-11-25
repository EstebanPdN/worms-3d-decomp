/* Reconstructed complete native wrappers. Names/types are inferred.
 * Return types explicitly preserve observed r3, including the allocation
 * result consumed by original caller80197db4. No state ownership claim. */
typedef unsigned int u32;
struct TemporaryOwner { void *data; };
extern "C" {
extern void *w3d_temporary_allocate(u32);
extern void *w3d_temporary_release(void *);
void *w3d_temporary_owner_allocate(TemporaryOwner *owner, u32 size)
{
    return owner->data = w3d_temporary_allocate((size + 31u) & ~31u);
}
void *w3d_temporary_owner_release(TemporaryOwner *owner)
{
    void *result = owner->data;
    if (result) {
        result = w3d_temporary_release(result);
        owner->data = 0;
    }
    return result;
}
}
