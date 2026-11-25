struct K7bEntry;
struct K7bEntryVector { struct K7bEntry **begin; struct K7bEntry **end; };
struct K7bRefresher;
struct K7bRefresherVtable { void *slots[37]; int (*refresh)(struct K7bRefresher *self); };
struct K7bRefresher { struct K7bRefresherVtable *vtable; char pad04[100]; struct K7bEntryVector entries; char pad70[52]; int dirty; };
extern void fn_8017a07c(struct K7bRefresher *self, unsigned index);
static inline unsigned k7b_entry_count(struct K7bEntryVector *v) { return v->end - v->begin; }
int w3d_k7b_refresher_update_8017b64c(struct K7bRefresher *self)
{
    unsigned i;
    int result;
    self->dirty = 0;
    result = self->vtable->refresh(self);
    for (i = 0; i < k7b_entry_count(&self->entries); i++)
        fn_8017a07c(self, i);
    return result;
}
