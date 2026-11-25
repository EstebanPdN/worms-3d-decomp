#include "w3d_ptr.h"
#line 1 "d30s_member_list_clear_80210660.cpp"
/* GWMP8P rev0 0x80210660. Clears the member list at +4 of a held object (d30s_member_list.h). */
#include "game/d30s/d30s_member_list.h"
extern "C" void d30s_member_list_clear_80210660(Ptr32<D30sMemberList> self) {
    self->clear_members();
}


