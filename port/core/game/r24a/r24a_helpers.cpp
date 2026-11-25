#include "w3d_ptr.h"
#line 1 "r24a_helpers.cpp"
// Worms 3D PAL GWMP8P rev0. Names are inferred; offsets describe PPC32.
// External data and calls remain unresolved ownership dependencies.
extern "C" {
struct DampedValue {
    unsigned char unknown[136];
    float position; // +136
    float velocity; // +140
};
extern const float stiffness_8038989c[];
extern const float damping_803898a0[];
// The original computes fused (-position * stiffness + velocity), then damping.
// The float return is inferred from the final value in f1, not a recovered name.
float w3d_r24a_damp_value_800dbd74(Ptr32<DampedValue> value)
{
    value->velocity += -value->position * stiffness_8038989c[0];
    value->velocity *= damping_803898a0[0];
    return value->position += value->velocity;
}

struct QueueEntry {
    unsigned int first, second, third, fourth, untouched;
    void clear()
    {
        first = 0;
        second = 0;
        third = 0;
        fourth = 0;
    }
};
struct EntryQueue {
    unsigned char unknown[388];
    QueueEntry entries[8]; // +388, stride 20
    int count; // +548
};
Ptr32<QueueEntry> w3d_r24a_append_empty_entry_8016e908(Ptr32<EntryQueue> queue)
{
    Ptr32<QueueEntry> entry = &queue->entries[queue->count];
    entry->clear();
    queue->count++;
    return entry;
}

struct RetainedInterface;
struct RetainDispatch {
    Ptr32<void (void)> unknown[3];
    Ptr32<void (Ptr32<RetainedInterface>)> retain; // +12
};
struct RetainedInterface { Ptr32<RetainDispatch> dispatch; };
struct InterfaceHolder { Ptr32<RetainedInterface> held; };
struct InterfaceSource {
    unsigned char unknown[40];
    Ptr32<RetainedInterface> held; // +40
};
Ptr32<InterfaceHolder> w3d_r24a_copy_retain_800ccd04(Ptr32<InterfaceHolder> holder, Ptr32<InterfaceSource> source)
{
    Ptr32<RetainedInterface> held = source->held;
    holder->held = held;
    if (held) {
        held->dispatch->retain(held);
    }
    return holder;
}
// Lua implementation and the original "ctr" type-name string are external.
struct LuaState;
void lua_check_type_802dcf90(Ptr32<LuaState>, int, int);
int lua_get_metatable_802ce3d4(Ptr32<LuaState>, int);
int lua_equal_802cdbd0(Ptr32<LuaState>, int, int);
int lua_type_error_802dcd3c(Ptr32<LuaState>, int, Ptr32<const char>);
void lua_set_top_802cd808(Ptr32<LuaState>, int);
Ptr32<void> lua_to_userdata_802cde08(Ptr32<LuaState>, int);
extern const char container_type_803a9980[];
Ptr32<void> w3d_r24a_check_container_userdata_8019e68c(Ptr32<LuaState> state, int index)
{
    lua_check_type_802dcf90(state, index, 7);
    lua_get_metatable_802ce3d4(state, index);
    if (!lua_equal_802cdbd0(state, -10002, -1)) {
        lua_type_error_802dcd3c(state, index, container_type_803a9980);
    }
    lua_set_top_802cd808(state, -2);
    return lua_to_userdata_802cde08(state, index);
}
}


