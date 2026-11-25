// Observed GC32 partial layouts; names describe roles, not original symbols.
struct Sol35e2Interface;
struct Sol35e2String { char *text; };
extern "C" void sol35e2_string_finish_8020c5c4(Sol35e2String *);
extern "C" void sol35e2_string_release_80341588(Sol35e2String *);
extern "C" void sol35e2_delete_801fe1f8(void *);

struct Sol35e2Interface {
    void **table;
    Sol35e2Interface *owner() {
        return ((Sol35e2Interface *(*)(Sol35e2Interface *))table[6])(this);
    }
    void release() { ((void (*)(Sol35e2Interface *))table[4])(this); }
    void remove(Sol35e2Interface *item) {
        ((void (*)(Sol35e2Interface *, Sol35e2Interface *))table[24])(this, item);
    }
};
struct Sol35e2Entry {
    Sol35e2Interface *held;
    unsigned unknown04;
    Sol35e2String name;
    void reset(Sol35e2Interface *next) {
        if (held) held->release();
        held = next;
    }
    ~Sol35e2Entry() {
        sol35e2_string_finish_8020c5c4(&name);
        sol35e2_string_release_80341588(&name);
        if (held) held->release();
    }
};
struct Sol35e2Range { Sol35e2Entry **first, **last, **capacity; };
struct Sol35e2Owner {
    unsigned char unknown00[336];
    Sol35e2Range entries;
};

extern "C" void sol35e2_clear_entries_8029f48c(Sol35e2Owner *self) {
    Sol35e2Entry **it = self->entries.first;
    if (it != self->entries.last) {
        Sol35e2Range &range = self->entries;
        do {
        Sol35e2Entry *entry = *it;
        if (entry) {
            if (entry->held) {
                if (entry->held->owner()) entry->held->owner()->remove(entry->held);
                entry->reset(0);
            }
            entry->~Sol35e2Entry();
            sol35e2_delete_801fe1f8(entry);
        }
            ++it;
        } while (it != range.last);
    }
    self->entries.last = self->entries.first;
}
