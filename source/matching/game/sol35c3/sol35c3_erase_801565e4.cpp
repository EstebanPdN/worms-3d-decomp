// Inferred four-vector identifier removal, GC32 observed layout.
typedef unsigned int u32;
struct WordVector { u32 *begin, *end, *capacity; };
struct Owner { unsigned char unknown0[100]; WordVector groups[4]; unsigned char unknown148[236]; int enabled; };
extern "C" void *fn_802eee50(void *, const void *, ...);
extern "C" void sol35c3_erase_801565e4(Owner *self, u32 value)
{
    if (self->enabled) {
        WordVector *group = self->groups;
        u32 index = 0;
        do {
            u32 *cursor = group->begin;
            while (cursor != group->end) {
                if (*cursor == value) {
                    if (cursor + 1 != group->end)
                        fn_802eee50(cursor, cursor + 1, (char *)(group->end - 1) - (char *)cursor);
                    --group->end;
                    return;
                }
                ++cursor;
            }
            ++index;
            ++group;
        } while (index < 4);
    }
}
