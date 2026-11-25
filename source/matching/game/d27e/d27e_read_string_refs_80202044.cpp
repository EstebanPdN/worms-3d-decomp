// (Worms 3D GameCube PAL, 0x80202044).
//
// Reads n string indices through 0x802024f4 and, when an output array is
// given, stores the matching entry of the name table at +140 in each slot:
// the new string's 16-bit reference count at -6 goes up, the old one's goes
// down and it is freed at zero. Strings are viewed as raw character pointers
// here. Names are inferred.

extern "C" void string_free_8020bb2c(void *);
struct Reader { char u[140]; char **names; };
extern "C" unsigned next_802024f4(Reader *);
inline void Release(char *old) {
    unsigned short *h = (unsigned short *)(old - 6);
    if (--*h == 0) string_free_8020bb2c(h);
}
extern "C" int w3d_d27e_read_string_refs_80202044(Reader *self, char **out, unsigned n) {
    unsigned i = 0;
    if (i < n) {
        char **q = out;
        do {
            unsigned index = next_802024f4(self);
            if (out) {
                char *const &from = *(char **)((char *)self->names + (index << 2));
                ++out;
                char **cur = q;
                ++q;
                ++*(unsigned short *)(from - 6);
                Release(q[-1]);
                *cur = from;
            }
            ++i;
        } while (i < n);
    }
    return 0;
}
