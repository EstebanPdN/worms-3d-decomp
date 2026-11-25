// Partial observed refcount interface and native pointer range. Original names
// and ignored callback return types remain unknown; no complete size claim.
struct cc42b_Registered;
struct cc42b_RegisteredVtable { unsigned int unknown00[4]; void (*release)(cc42b_Registered *); };
struct cc42b_Registered { cc42b_RegisteredVtable *vtable; };
struct cc42b_RegisteredRange {
    cc42b_Registered **first, **last;
    cc42b_Registered **begin() { return first; }
    cc42b_Registered **end() { return last; }
    void erase(cc42b_Registered **where) {
        if (where+1!=last) __builtin_memcpy(where,where+1,static_cast<unsigned int>(reinterpret_cast<char *>(last-1)-reinterpret_cast<char *>(where)));
        --last;
    }
};
struct cc42b_RegisteredOwner {
    unsigned char unknown00[20];
    cc42b_RegisteredRange entries;
    unsigned int unknown1c;
    cc42b_Registered *active;
};
extern "C" cc42b_Registered **cc42b_find_registered_8035c414(cc42b_Registered **,cc42b_Registered **,cc42b_Registered *const *);
extern "C" unsigned int cc42b_unregister_8020a808(cc42b_RegisteredOwner *self,cc42b_Registered *item) {
    cc42b_Registered **found=cc42b_find_registered_8035c414(self->entries.begin(),self->entries.end(),&item);
    if (found!=self->entries.end()) {
        self->entries.erase(found);
        item->vtable->release(item);
        if (self->active==item) {
            if (self->active) self->active->vtable->release(self->active);
            self->active=0;
        }
        return 0;
    }
    return 0x80004005U;
}
