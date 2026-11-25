extern "C" void *memcpy(...);
extern "C" int fn_801190d0(void *);
struct IdVector {
    int *begin, *end, *capacity;
    inline void erase(int *position) {
        int *next = position + 1;
        if (next != end) memcpy(position, next, (char *)(end - 1) - (char *)position);
        --end;
    }
};
struct Owner { char unknown[344]; IdVector ids; };
extern "C" void tterra_a31_erase_8008db88(Owner *owner, void *object) {
    int *it = owner->ids.begin;
    if (it != owner->ids.end) {
        IdVector *ids = &owner->ids;
        do {
            int value = fn_801190d0(object);
            if (*it == value) { owner->ids.erase(it); return; }
            ++it;
        } while (it != ids->end);
    }
}
