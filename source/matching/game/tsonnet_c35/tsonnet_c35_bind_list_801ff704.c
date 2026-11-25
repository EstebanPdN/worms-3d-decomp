/* Reference-only: walks `count` object pointers in `list`. For each non-null
   entry it asks the entry (virtual at +8, with the key at 0x8040c970) to store
   a held interface into a stack slot, then passes that slot and `arg` to the
   virtual at +32 of `target`. A negative result releases the slot (virtual at
   +16) and is returned immediately; otherwise the slot is released and the walk
   continues. Returns 0 when every entry succeeded. The first parameter is not
   read. Offsets and meanings are inferred from the observed accesses; the key
   and the zero slot are external originals declared by address. */
extern const char w3d_key_8040c970[];

int tsonnet_c35_bind_list_801ff704(void *unused, void *target, void **list, int arg, unsigned int count) {
    unsigned int i;
    void *held;
    void **hp = &held;
    for (i = 0; i < count; i++) {
        void *entry;
        int r;

        entry = *list;
        held = 0;
        if (entry)
            (*(void (**)(void *, const char *, void **))(*(char **)entry + 8))(entry, w3d_key_8040c970, hp);
        else
            held = entry;
        r = (*(int (**)(void *, void *, int))(*(char **)target + 32))(target, held, arg);
        if (r < 0) {
            if (held)
                (*(void (**)(void *))(*(char **)held + 16))(held);
            return r;
        }
        list++;
        if (held)
            (*(void (**)(void *))(*(char **)held + 16))(held);
    }
    return 0;
}
