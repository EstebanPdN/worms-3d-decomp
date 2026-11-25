// Inferred GC32 views. Original tables at 80411d00, 80411d70 and 80413fc0
// put getter 8034bc58 at +88: it writes one unsigned count and returns slots.
struct Interface;
typedef void (*Slot)();
struct Interface { Slot *vtable; };
struct Array {
    unsigned count;
    unsigned short capacity;
    unsigned short growth;
    Interface **data;
};
struct Owner;
extern "C" int sol35f5a_key_801a2350(unsigned short);
extern "C" int sol35f5a_reserve_801f29d0(Array *, unsigned);
extern "C" int sol35f5a_fill_801a2b64(void *, Interface **, unsigned);
inline Array &array(Owner *owner)
{
    return *reinterpret_cast<Array *>(reinterpret_cast<char *>(owner) + 136);
}
inline unsigned short key(Interface *p)
{
    return *reinterpret_cast<unsigned short *>(reinterpret_cast<char *>(p) + 6);
}
inline void replace(Interface *&destination, Interface *fresh)
{
    if (fresh)
        reinterpret_cast<void (*)(Interface *)>(fresh->vtable[3])(fresh);
    if (destination)
        reinterpret_cast<void (*)(Interface *)>(destination->vtable[4])(destination);
    destination = fresh;
}
extern "C" int sol35f5a_slots_8034bc68(Owner *self, Interface *fresh)
{
    int wanted = sol35f5a_key_801a2350(key(fresh));
    Interface **last = array(self).data + array(self).count;
    Interface **cursor = array(self).data;
    do {
        if (cursor == last)
            goto append;
        if (sol35f5a_key_801a2350(key(*cursor)) != wanted) {
            ++cursor;
            continue;
        }
        replace(*cursor, fresh);
        goto filled;
    } while (true);
append:
    sol35f5a_reserve_801f29d0(&array(self), array(self).count + 1);
    replace(array(self).data[array(self).count], fresh);
    ++array(self).count;
filled:
    unsigned count;
    Interface *header = reinterpret_cast<Interface *>(self);
    Interface **slots = reinterpret_cast<Interface **(*)(Owner *, unsigned *)>(header->vtable[22])(self, &count);
    void *target = *reinterpret_cast<void **>(reinterpret_cast<char *>(self) + 116);
    sol35f5a_fill_801a2b64(target, slots, count);
    return 0;
}
