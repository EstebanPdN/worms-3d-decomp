/* UNVERIFIED reference candidate for the CloseContainer service body.
 * Its C++ boolean predicate now has the observed native form, but branch
 * layout still differs and this function is not admitted as recovered.
 * Complete object allocation layouts remain separate recovery work.
 */
extern "C" {
#include "lua.h"
}

struct W3dScriptService {
    unsigned char unknown_00[0x44];
    lua_State *state;
    unsigned char unknown_48[0x11c];
    int open_containers;
};
struct W3dContainerLock {
    unsigned int unknown_00;
    unsigned int magic;
    bool valid() const { return magic == 0xe3a8; }
};
extern "C" {
void w3d_script_report_error(W3dScriptService *, const char *);
void w3d_container_lock_release(W3dContainerLock *, int);

int w3d_script_close_container(W3dScriptService *service)
{
    int arguments = lua_gettop(service->state);
    int pop_index;
    lua_State *pop_state;
    if (arguments != 1) {
        w3d_script_report_error(service,
            "Incorrect number of arguments to function 'CloseContainer'");
        pop_state = service->state;
        pop_index = -1 - arguments;
    } else if (lua_type(service->state, -1) != LUA_TLIGHTUSERDATA) {
        w3d_script_report_error(service,
            "Incorrect argument to function 'CloseContainer'");
        pop_state = service->state;
        pop_index = -2;
    } else {
        W3dContainerLock *lock =
            (W3dContainerLock *)lua_touserdata(service->state, -1);
        if (!lock->valid()) {
            w3d_script_report_error(service,
                "Invalid lock in function 'CloseContainer'");
            pop_state = service->state;
            pop_index = -2;
        } else {
            if (lock != 0)
                w3d_container_lock_release(lock, 3);
            --service->open_containers;
            pop_state = service->state;
            pop_index = -2;
        }
    }
    lua_settop(pop_state, pop_index);
    return 0;
}
}
