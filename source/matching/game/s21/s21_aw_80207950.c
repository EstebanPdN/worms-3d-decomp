// desc: Appears to look up a table entry by a halfword of the key and return its data pointer when its limit is at least the requested size, else zero.
struct S21Entry { void *data; unsigned limit; };
struct S21Key { char pad[5]; unsigned char slot0; unsigned char slot1; };
struct S21Registry { char pad[36]; struct S21Entry **entries; };
void *w3d_s21_find_data_80207950(struct S21Registry *self, struct S21Key *key, unsigned size)
{
    struct S21Entry *entry = *(struct S21Entry **)((char *)self->entries + (*(unsigned short *)((char *)key + 5) << 2));
    if (entry->limit < size)
        return 0;
    return entry->data;
}
