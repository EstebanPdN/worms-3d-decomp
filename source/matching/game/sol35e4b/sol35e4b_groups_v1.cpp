// Observed GC32 views for 0x802a9f54; names and complete classes are inferred.
struct Sol35e4bInterface;
struct Sol35e4bTable {
    void (*unknown00[4])();
    void (*release)(Sol35e4bInterface*);
    void (*unknown14[19])();
    void (*detach)(Sol35e4bInterface*, Sol35e4bInterface*);
};
struct Sol35e4bInterface { Sol35e4bTable* table; };
struct Sol35e4bHandle {
    Sol35e4bInterface* value;
    void reset(Sol35e4bInterface* next) {
        if (value)
            value->table->release(value);
        value = next;
    }
};
struct Sol35e4bEntry {
    Sol35e4bHandle object;
    unsigned char unknown04[12];
};
struct Sol35e4bOwner {
    unsigned char unknown00[212];
    Sol35e4bHandle held[3];
    unsigned char unknowne0[20];
    Sol35e4bHandle top;
    Sol35e4bHandle groups[3];
    unsigned char unknown104[820];
    Sol35e4bEntry entries[3][5];
    unsigned char unknown528[36];
    Sol35e4bHandle final_a;
    Sol35e4bHandle final_b;
    Sol35e4bHandle clips[3];
};
typedef char Sol35e4bEntrySize[sizeof(Sol35e4bEntry) == 16 ? 1 : -1];
extern "C" void sol35e4b_clear_base_802b0fec(void*);

extern "C" void sol35e4b_cleanup_groups_802a9f54(Sol35e4bOwner* self)
{
    self->top.reset(0);
    for (int i = 0; i <= 2; ++i) {
        Sol35e4bEntry* entry = self->entries[i];
        for (int remaining = 5; remaining != 0; --remaining, ++entry) {
            if (entry->object.value) {
                Sol35e4bInterface* group = self->groups[i].value;
                group->table->detach(group, entry->object.value);
                entry->object.reset(0);
            }
        }
        self->groups[i].reset(0);
        self->clips[i].reset(0);
    }
    self->held[0].reset(0);
    self->held[1].reset(0);
    self->held[2].reset(0);
    self->final_b.reset(0);
    self->final_a.reset(0);
    sol35e4b_clear_base_802b0fec(reinterpret_cast<unsigned char*>(self) + 28);
}
