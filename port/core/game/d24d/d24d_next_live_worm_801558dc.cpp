#include "w3d_ptr.h"
#line 1 "d24d_next_live_worm_801558dc.cpp"
// d24d: 0x801558dc (616 bytes). Take the next live worm from a team's list:
// pop values from the front of list `team` (+52, 12 bytes each) until the worm
// record from 0x800fc6dc has state 1 (+220) or the list runs out. A live worm is
// appended to the list of its own team byte (+213), that team's cursor (+148)
// is set to the new last index, and the id is returned; otherwise returns -1.
// The emptiness test divides the byte span as unsigned (srwi.) while the cursor
// uses a signed element count (srawi); the two accessors reproduce both.
#include "d24d_int_list.h"
struct d24d_WormInfo {
    unsigned char unknown00[213];
    unsigned char team;                  // +213
    unsigned char unknownd6[6];
    int state;                           // +220
};
struct d24d_TeamList : d24d_IntList {
    unsigned count() { return ((unsigned)((Ptr32<char>)finish - (Ptr32<char>)start)) / 4; }
    int size() { return finish - start; }
};
struct d24d_Teams {
    unsigned char unknown00[52];
    d24d_TeamList lists[8];              // +52
    int cursor[8];                       // +148
};
extern "C" Ptr32<d24d_WormInfo> d24d_worm_info_800fc6dc(int);

extern "C" int d24d_next_live_worm_801558dc(Ptr32<d24d_Teams> self, int team) {
    if (team != -1 && self->lists[team].count()) {
        int worm = *self->lists[team].begin();
        self->lists[team].erase(self->lists[team].begin());
        while (d24d_worm_info_800fc6dc(worm)->state != 1 && self->lists[team].count()) {
            worm = *self->lists[team].begin();
            self->lists[team].erase(self->lists[team].begin());
        }
        if (d24d_worm_info_800fc6dc(worm)->state == 1) {
            unsigned own = d24d_worm_info_800fc6dc(worm)->team;
            self->lists[own].push_back(worm);
            self->cursor[own] = self->lists[own].size() - 1;
            return worm;
        }
    }
    return -1;
}


