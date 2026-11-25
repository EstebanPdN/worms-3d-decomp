#include "w3d_ptr.h"
#line 1 "d24h_choose_movie_800c61d8.cpp"
// Worms 3D GameCube PAL, 0x800c61d8 (260 bytes). Random movie choice: picks
// the table for the TV format, counts the 12-byte records of the wanted
// category up to terminator 29, draws a random number (0x80162ba8) modulo the
// count and returns the file name of that matching record, or null. An
// unknown format panics with the source name and line 339. A category with no
// record divides by zero, as in the original. Names are inferred.
//
// One table assignment is a one-pass do/while block. Its loop note raises the
// weight of the table register in global allocation (table r30, category r29);
// the block generates no instructions.
struct Movie { Ptr32<const char> name; int category; Ptr32<const char> file; };
extern Movie lbl_803f5728[];
extern Movie lbl_803f58b4[];
extern const char lbl_803876ac[];   // "MoviePlayerService.cpp"
extern const char lbl_803876c4[];   // "XGXScreen: invalid TV format\n"
extern "C" unsigned fn_80304de0();
extern "C" unsigned fn_80162ba8();
extern "C" void fn_802fb82c(Ptr32<const char>, int, Ptr32<const char>, ...);

extern "C" Ptr32<const char> w3d_d24h_choose_movie_800c61d8(Ptr32<void> self, int category) {
    Ptr32<Movie> table;
    switch (fn_80304de0()) {
    case 1: table = lbl_803f5728; break;
    case 0: case 2: do { table = lbl_803f58b4; } while (0); break;
    default: fn_802fb82c(lbl_803876ac, 339, lbl_803876c4); break;
    }
    unsigned count = 0;
    for (int i = 0; table[i].category != 29; i++) {
        if (table[i].category == category) count++;
    }
    unsigned choice = fn_80162ba8() % count;
    for (int j = 0; table[j].category != 29; j++) {
        if (table[j].category == category) {
            if (choice == 0) return table[j].file;
            choice--;
        }
    }
    return 0;
}


