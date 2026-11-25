// Native shared-string layout: text pointer, references at text-6, length at text-4.
struct Sol35dPathString;
extern "C" Sol35dPathString *fn_803426b8(Sol35dPathString *);
extern "C" Sol35dPathString *fn_8020c00c(Sol35dPathString *, int);
extern "C" void fn_8020c5c4(Sol35dPathString *);
extern "C" void fn_80341588(Sol35dPathString *);
extern "C" void fn_8020bb2c(void *);
struct Sol35dPathString {
    char *data;
    ~Sol35dPathString() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
    unsigned length() const { return *(unsigned short *)(data - 4); }
    Sol35dPathString &operator=(const Sol35dPathString &other) {
        ++*(unsigned short *)(other.data - 6);
        char *old = data;
        void *header = old - 6;
        unsigned short references = --*(unsigned short *)header;
        if (!references) fn_8020bb2c(header);
        data = other.data;
        return *this;
    }
};
extern "C" void w3d_sol35d_normalize_path_80218194(Sol35dPathString *self) {
    Sol35dPathString output;
    fn_803426b8(&output); // Native initializer fills data before any use or destruction.
    bool previousBackslash = false;
    if (self->length() != 0) {
        for (unsigned index = 0; index < self->length(); ++index) {
            int character = (signed char)self->data[index];
            if (character == 92) {
                if (!previousBackslash) fn_8020c00c(&output, 47);
                previousBackslash = true;
            } else {
                fn_8020c00c(&output, character);
                previousBackslash = false;
            }
        }
        *self = output;
    }
}
