// GWMP8P rev0 observed 32-bit stores at receiver +12,+16. Names, member
// meanings, complete SDK type and API signature remain inferred. Requires
// aligned, live writable receiver storage; no ownership or caller proof.
struct Sol35p4Words12 {
    unsigned char unknown_prefix[12];
    unsigned first, second;
};
extern "C" void sol35p4_store_words_80306654(
    Sol35p4Words12 *self, unsigned first, unsigned second) {
    self->first = first;
    self->second = second;
}
