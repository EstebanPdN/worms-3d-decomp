#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4a_active_worm_apply_800217d0.c"
typedef struct K4aTeamRecord { char pad0[112]; int value; } K4aTeamRecord;
typedef struct K4aSetter { char pad0[4]; int flag; char pad1[16]; float amount; } K4aSetter;
extern char w3d_string_active_worm_index_8036c014[];
extern int w3d_auto_800fc1f0(Ptr32<Ptr32<const char>> name, Ptr32<int> value);
extern Ptr32<K4aTeamRecord> s8_index_query_800fc6dc(int index);

int k4a_active_worm_apply_800217d0(Ptr32<K4aSetter> self)
{
    Ptr32<const char> name;
    int index;
    name = w3d_string_active_worm_index_8036c014;
    w3d_auto_800fc1f0(&name, &index);
    s8_index_query_800fc6dc(index)->value = (int)self->amount;
    self->flag = 1;
    return 0;
}

}
