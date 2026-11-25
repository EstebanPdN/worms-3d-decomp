// desc: Appears to report whether a lookup in the object's registry for the key and the object's halfword size plus four finds nothing.
struct S21Object { char pad[10]; unsigned short size; char pad1[4]; void *registry; };
extern void *fn_80207950(void *, void *, unsigned);
int w3d_s21_missing_8021a278(struct S21Object *self, void *key)
{
    return fn_80207950(self->registry, key, self->size + 4) == 0;
}
