/* Timer cancellation service. Prefixes describe only observed fields. */
extern "C" {
#include "lua.h"
}
typedef unsigned int Word;
struct ScriptTimer {
    unsigned char unknown_00[8];
    int id;
    unsigned char unknown_0c[0x10];
    int inactive;
};
struct TimerVector {
    ScriptTimer **begin;
    ScriptTimer **end;
    Word size() const { return (Word)(end - begin); }
    ScriptTimer *&operator[](Word index) { return begin[index]; }
};
struct ScriptService {
    unsigned char unknown_00[0x44];
    lua_State *state;
    unsigned char unknown_48[0x138];
    TimerVector timers;
};
extern "C" {
extern void w3d_script_report_error(ScriptService *, const char *);
extern int w3d_timer_backend_cancel(int);

void w3d_timer_cancel(ScriptTimer *timer, int id)
{
    w3d_timer_backend_cancel(id);
    timer->inactive = 1;
}

int w3d_script_cancel_timer(ScriptService *service)
{
    int arguments = lua_gettop(service->state);
    int pop_index;
    lua_State *pop_state;
    if (arguments != 1) {
        w3d_script_report_error(service,
            "Incorrect number of arguments to function 'CancelTimer'");
        pop_state = service->state;
        pop_index = ~arguments;
    } else {
        if (!lua_isnumber(service->state, -1)) {
            w3d_script_report_error(service,
                "Invalid argument to function 'CancelTimer'");
        } else {
            int id = (int)lua_tonumber(service->state, -1);
            for (Word i = 0; i < service->timers.size(); ++i) {
                ScriptTimer *timer = service->timers[i];
                if (timer->inactive == 0 && timer->id == id)
                    w3d_timer_cancel(timer, id);
            }
        }
        pop_state = service->state;
        pop_index = -2;
    }
    lua_settop(pop_state, pop_index);
    return 0;
}
}
