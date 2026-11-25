// GWMP8P rev0 0x801984fc. Picks a slot for new animation data in the 80-slot
// cache, freeing until the heap has size plus 2048 bytes: a free slot on the
// first pass, else the oldest unlocked in-use one, else with a warning the
// oldest in use. Names inferred from the original's messages.
extern "C" void fn_802fb7ac(const char *, ...);
extern "C" int fn_80343810();
extern "C" unsigned fn_801981f8();
struct Records;
extern "C" void fn_80197f98(Records *, int);
struct Owner { virtual void s8(); virtual void s12(); virtual void s16(); virtual void s20(); virtual void s24(); virtual void s28(); virtual void s32();
    virtual char *Find(int id); virtual int Size(int id); };
struct Slot { int id; Owner *owner; unsigned stamp; int flags; };
extern const char msg_803a85a0[], msg_803a85d8[], msg_803a8610[], msg_803a8630[], msg_803a8650[];
extern "C" Slot *w3d_d40n_evict_animation_slot_801984fc(Slot *slots, unsigned size) {
    unsigned need = size + 2048;
    int first = 1;
    unsigned tries = 0;
    Slot *e;
    int more;
    do {
        e = slots;
        unsigned best = 0xffffffff;
        int found = 0;
        unsigned victim = 80;
        for (unsigned i = 0; i < 80; i++) {
            e = &slots[i];
            if (e->flags >= 0 && first) { victim = i; found = 1; break; }
            if (!(e->flags & 0x40000000) && e->flags < 0 && e->stamp < best) { best = e->stamp; victim = i; found = 1; }
        }
        if (!found) {
            fn_802fb7ac(msg_803a85a0);
            fn_802fb7ac(msg_803a85d8);
            if (e->flags & 0x20000000) fn_802fb7ac(msg_803a8610);
            best = 0xffffffff;
            victim = 0;
            for (int i = 0; i < 80; i++) {
                if (slots[i].flags < 0 && slots[i].stamp < best) { best = slots[i].stamp; victim = i; }
            }
        }
        e = &slots[victim];
        if (e->flags < 0) {
            char *data = e->owner->Find(slots[victim].id);
            int bytes = e->owner->Size(slots[victim].id);
            if (data) {
                fn_802fb7ac(msg_803a8630);
                fn_80197f98((Records *)(data + 8), bytes);
                e->stamp = 0;
                e->flags &= 0x1fffffff;
            }
        }
        fn_80343810();
        if (fn_801981f8() < need) {
            tries++;
            first = 0;
            more = 1;
            if (tries > 80) { fn_802fb7ac(msg_803a8650); break; }
        } else {
            more = 0;
        }
    } while (more);
    return e;
}
