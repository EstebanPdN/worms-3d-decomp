/* GWMP8P rev0 0x801ea9a4. Clears both member lists of an object (d30s_member_list.h). */
#include "game/d30s/d30s_member_list.h"
struct D30sMemberListPair { D30sMemberList first, second; };
extern "C" void d30s_member_lists_clear_801ea9a4(D30sMemberListPair *self) {
    self->first.clear_members();
    self->second.clear_members();
}
