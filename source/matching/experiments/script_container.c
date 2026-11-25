/* Experimental behavioral reconstruction; NOT admitted as verified source.
 * Native body at 0x80103254 has different inline-predicate code generation.
 * Original external effects and edge cases still need differential proof.
 * Keep this candidate separate from the verified bridge build.
 */
#include "lua.h"
typedef struct W3dScriptService {
    unsigned char unknown_00[0x44];
    lua_State *state;
    unsigned char unknown_48[0x11c];
    int open_containers;
} W3dScriptService;
typedef struct W3dContainerLockPrefix {
    unsigned int unknown_00;
    unsigned int magic;
} W3dContainerLockPrefix;
extern void w3d_script_report_error(W3dScriptService *, const char *);
extern void w3d_container_lock_release(W3dContainerLockPrefix *, int);

int w3d_script_close_container(W3dScriptService *service)
{
    int arguments = lua_gettop(service->state);
    if (arguments == 1) {
        if (lua_type(service->state, -1) == LUA_TLIGHTUSERDATA) {
            W3dContainerLockPrefix *lock =
                (W3dContainerLockPrefix *)lua_touserdata(service->state, -1);
            if (lock->magic == 0xe3a8) {
                if (lock != 0)
                    w3d_container_lock_release(lock, 3);
                --service->open_containers;
            } else {
                w3d_script_report_error(service,
                    "Invalid lock in function 'CloseContainer'");
            }
        } else {
            w3d_script_report_error(service,
                "Incorrect argument to function 'CloseContainer'");
        }
        lua_settop(service->state, -2);
    } else {
        w3d_script_report_error(service,
            "Incorrect number of arguments to function 'CloseContainer'");
        lua_settop(service->state, -1 - arguments);
    }
    return 0;
}
