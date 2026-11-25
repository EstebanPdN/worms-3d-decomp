#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4a_tally_team_match_80109b1c.c"
typedef struct K4aTeamRecord { char pad0[213]; unsigned char team; } K4aTeamRecord;
typedef struct K4aTally { char pad0[84]; int other_count; int same_count; char pad1[28]; int locked; } K4aTally;
extern char w3d_string_80399cd8[];
extern int w3d_auto_800fc1f0(Ptr32<Ptr32<const char>> name, Ptr32<int> value);
extern Ptr32<K4aTeamRecord> s8_index_query_800fc6dc(int index);

void k4a_tally_team_match_80109b1c(Ptr32<K4aTally> self, int other)
{
    if (self->locked == 0) {
        Ptr32<const char> name;
        int index = 0;
        name = w3d_string_80399cd8;
        w3d_auto_800fc1f0(&name, &index);
        if (index >= 0) {
            int team = s8_index_query_800fc6dc(index)->team;
            if (team == s8_index_query_800fc6dc(other)->team)
                self->same_count++;
            else
                self->other_count++;
        }
    }
}

}
