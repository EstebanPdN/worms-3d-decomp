#include "w3d_ptr.h"
#line 1 "cx7p_r25a_objects_unadmitted.cpp"
// GWMP8P rev0 reference recovery. Names are inferred; extern dependencies remain unresolved.
// Inferred PPC32 views; padding records observed offsets, not complete classes.
struct Retained;
struct RetainTable { Ptr32<void> slots[3]; Ptr32<void (Ptr32<Retained>)> retain; };
struct Retained { Ptr32<RetainTable> dispatch; };
struct LuaContext { unsigned char unknown[36]; Ptr32<void> environment; };
struct LuaState { unsigned char unknown[88]; Ptr32<LuaContext> context; };
struct Userdata { Ptr32<Retained> object; Ptr32<void> environment; };
extern "C" {
Ptr32<const char> fn_802dd028(Ptr32<LuaState>, int, Ptr32<unsigned int>);
Ptr32<Retained> fn_801a01f0(Ptr32<const char>, Ptr32<const void>);
Ptr32<Userdata> fn_802ce9d8(Ptr32<LuaState>, unsigned int);
void fn_802cd99c(Ptr32<LuaState>, int);
int fn_802ce5ec(Ptr32<LuaState>, int);
extern unsigned char lbl_80365788[];
}
// External lookup, Lua allocation, and retained-interface ownership remain dependencies.
extern "C" int w3d_r25a_create_named_userdata_8019e710(Ptr32<LuaState> state) {
    unsigned int length;
    Ptr32<Retained> object = fn_801a01f0(fn_802dd028(state, 1, &length), lbl_80365788);
    if (!object) return 0;
    Ptr32<Userdata> value = fn_802ce9d8(state, 8);
    value->object = object;
    object->dispatch->retain(object);
    value->environment = state->context->environment;
    fn_802cd99c(state, -10002);
    fn_802ce5ec(state, -2);
    return 1;
}
struct Member_80126184 { unsigned char data[8]; Member_80126184(); };
inline void *operator new(__SIZE_TYPE__, void *place) { return place; }
struct Actor {
    Ptr32<void> dispatch;
    unsigned char unknown04[72];
    int cleared4c, cleared50, cleared54, cleared58, cleared5c, cleared60;
    Member_80126184 member64;
    int cleared6c, cleared70, sentinel74;
};
extern "C" {
void fn_80161014(Ptr32<Actor>);
extern unsigned char lbl_80410bd8[];
}


// Header is observed 16 bytes before the stored cursor; words are PPC32.
struct ListHeader { int count; int unknown; Ptr32<int> entries; Ptr32<void> owner; };
struct ListMember { int unknown; Ptr32<ListHeader> cursor; };
struct ListObject { unsigned char unknown[116]; ListMember list; };
extern "C" void fn_801ef174(Ptr32<void>, int, int, Ptr32<void>);
extern "C" void fn_801f2758(Ptr32<ListHeader>, int);
extern "C" void w3d_r25a_release_list_entries_801ad060(Ptr32<ListObject> self) {
    Ptr32<ListHeader> header = self->list.cursor - 1;
    Ptr32<int> entry = header->entries;
    Ptr32<void> owner = header->owner;
    Ptr32<int> end = entry + header->count;
    while (entry != end) {
        fn_801ef174(owner, 44, 3, (Ptr32<void>)w3d::G((*entry)));
        ++entry;
    }
    Ptr32<ListMember> list = &self->list;
    --list->cursor;
    fn_801f2758(list->cursor, 2);
}


