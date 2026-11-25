// desc: Appears to look up an entry in the object's registry and return the word at the object's halfword offset within it, or zero when missing.
struct S21Object { char pad[10]; unsigned short size; char pad1[4]; void *registry; };
extern void *fn_80207950(void *, void *, unsigned);
int w3d_s21_read_entry_8021a32c(struct S21Object *self, void *key)
{
    void *entry = fn_80207950(self->registry, key, self->size + 4);
    if (entry)
        return *(int *)((char *)entry + self->size);
    return 0;
}
