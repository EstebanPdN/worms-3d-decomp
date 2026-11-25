#include "w3d_ptr.h"
#line 1 "k10b_barracks_capacity_8029d7b4.cpp"
// Partial view: looks up the "DATA.TeamBarracks" property object, counts the
// members of its list whose +40 flag word is non-zero and succeeds when at
// most nine are set. The looked-up interface is released on every path. The
// property workspace keeps the interface at +0 and the key at +8 (two
// unused words), as observed on the stack.
struct K10bHeld_8029d7b4;
struct K10bHeldVtable_8029d7b4 {
    Ptr32<void> slots0[4];
    Ptr32<void (Ptr32<K10bHeld_8029d7b4>)> release;
};
struct K10bHeld_8029d7b4 {
    Ptr32<K10bHeldVtable_8029d7b4> vtable;
};

struct K10bMember_8029d7b4 {
    char unknown0[40];
    int active;
};
struct K10bMemberList_8029d7b4 {
    char unknown0[24];
    unsigned count;
    char unknown1c[4];
    Ptr32<K10bMember_8029d7b4> items[1];
};
struct K10bOwner_8029d7b4 {
    char unknown0[24];
    Ptr32<K10bMemberList_8029d7b4> list;
};
struct K10bQueryWorkspace_8029d7b4 {
    Ptr32<K10bHeld_8029d7b4> property;
    unsigned reserved04;
    Ptr32<const char> key;
    unsigned reserved0c;
};

extern "C" {
extern const char lbl_803d097c[];
int fn_800fc1b0(Ptr32<Ptr32<const char>> key, Ptr32<Ptr32<K10bHeld_8029d7b4>> output);
Ptr32<void> fn_80341584(Ptr32<void> object);
Ptr32<K10bOwner_8029d7b4> fn_801797b4(Ptr32<void> object);

int w3d_k10b_barracks_capacity_8029d7b4() {
    K10bQueryWorkspace_8029d7b4 workspace;
    workspace.property = 0;
    workspace.key = lbl_803d097c;
    unsigned used = 0;
    if (fn_800fc1b0(&workspace.key, &workspace.property) < 0) goto fail;
    {
        Ptr32<K10bMemberList_8029d7b4> list = fn_801797b4(fn_80341584(workspace.property))->list;
        Ptr32<Ptr32<K10bMember_8029d7b4>> item = list->items;
        for (unsigned i = 0; i < list->count; ++i) {
            Ptr32<K10bMember_8029d7b4> member = *item++;
            if (member->active) ++used;
        }
    }
    if (used > 9) {
    fail:
        if (workspace.property) workspace.property->vtable->release(workspace.property);
        return 0;
    }
    if (workspace.property) workspace.property->vtable->release(workspace.property);
    return 1;
}
}


