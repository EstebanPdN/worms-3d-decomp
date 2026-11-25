// Partial observed interface and range, not a full recovered class definition.
struct cc42b_Checked;
struct cc42b_CheckedVtable { unsigned int unknown00[19]; int (*check)(cc42b_Checked *); };
struct cc42b_Checked { cc42b_CheckedVtable *vtable; };
struct cc42b_CheckedRange {
    cc42b_Checked **first;
    cc42b_Checked **last;
    cc42b_Checked **begin() { return first; }
    cc42b_Checked **end() { return last; }
};
struct cc42b_CheckedGroup {
    unsigned char unknown00[52];
    cc42b_CheckedRange entries;
};
// Every nonnull entry is visited, and the last negative status is retained.
extern "C" int cc42b_collect_failure_801fbe20(cc42b_CheckedGroup *self) {
    int result = 0;
    for (cc42b_Checked **entry = self->entries.begin(); entry != self->entries.end(); ++entry) {
        if (*entry) {
            int status = (*entry)->vtable->check(*entry);
            if (status < 0) result = status;
        }
    }
    return result;
}
