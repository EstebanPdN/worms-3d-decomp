// Experimental GC32 SDK views. Not recovered or admitted.
// Original names, initialization semantics and table ownership are unknown.
extern "C" {
extern unsigned sol35p3_flag_804b1150;
extern unsigned sol35p3_flag_804b1170;
extern unsigned *sol35p3_table_804b11bc;
unsigned sol35p3_set_flags_802f9254() {
    sol35p3_flag_804b1150 = 1;
    sol35p3_flag_804b1170 = 1;
    return 1;
}
unsigned sol35p3_exchange_slot_802f9d54(unsigned index, unsigned replacement) {
    unsigned *slot = sol35p3_table_804b11bc + (index & 255);
    unsigned previous = *slot;
    *slot = replacement;
    return previous;
}
}
