#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_team_80020834.c"
struct S19Rec { char pad0[213]; unsigned char team; };
struct S19Team { char pad0[52]; int value; };
extern Ptr32<void> w3d_empty_803426b4(Ptr32<void>);
extern int w3d_auto_80178c48(Ptr32<void>);
extern Ptr32<struct S19Rec> s8_index_query_800fc6dc(int);
extern Ptr32<struct S19Team> s8_index_query_800fc7f8(int);

int s19_active_team_value_80020834(Ptr32<void> self)
{
    int handle = w3d_auto_80178c48(w3d_empty_803426b4(*(Ptr32<Ptr32<void>>)((Ptr32<char>)self + 28)));
    if (handle == -1)
        return 0;
    return s8_index_query_800fc7f8(s8_index_query_800fc6dc(handle)->team)->value;
}

}
