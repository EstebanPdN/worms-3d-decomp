// Observed PPC32 field layouts; semantic names are inferred.
extern "C" {
struct IndexedActor {
    unsigned char unknown[44];
    unsigned int unavailable; // +44, tested for zero
    unsigned char unknown48[12];
    unsigned char category; // +60, unsigned byte
};
IndexedActor *lookup_actor_800fc7f8(unsigned int index);
unsigned int w3d_r24a_count_available_category_8008acd0(void *, unsigned int category)
{
    unsigned int count = 0;
    unsigned int index = 0;
    do {
        IndexedActor *actor = lookup_actor_800fc7f8(index);
        if (actor->category == category && actor->unavailable == 0) {
            count++;
        }
        index++;
    } while (index <= 3);
    return count;
}

// Lua implementation and the original "ctr" type-name string are external.
struct LuaState;
void lua_check_type_802dcf90(LuaState *, int, int);
int lua_get_metatable_802ce3d4(LuaState *, int);
int lua_equal_802cdbd0(LuaState *, int, int);
int lua_type_error_802dcd3c(LuaState *, int, const char *);
void lua_set_top_802cd808(LuaState *, int);
void *lua_to_userdata_802cde08(LuaState *, int);
extern const char container_type_803a9980[];
void *w3d_r24a_check_container_userdata_8019e68c(LuaState *state, int index)
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
