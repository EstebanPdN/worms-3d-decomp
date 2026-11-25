#include "w3d_ptr.h"
#line 1 "d25c_script_start_timer_80102b2c.cpp"
// d25c: 0x80102b2c. Script binding StartTimer(name, value): take the first free timer of the vector at +384,
// start it (0x8005ffc8) and push its result as a number. The goto loop keeps the size reload and indexed
// load per round; a structured loop is rotated and strength-reduced. Names are inferred.
struct lua_State;
extern "C" int lua_gettop(Ptr32<lua_State>);
extern "C" void lua_settop(Ptr32<lua_State>, int);
extern "C" int lua_isstring(Ptr32<lua_State>, int);
extern "C" int lua_isnumber(Ptr32<lua_State>, int);
extern "C" Ptr32<const char> lua_tostring(Ptr32<lua_State>, int);
extern "C" float lua_tonumber(Ptr32<lua_State>, int);
extern "C" void lua_pushnumber(Ptr32<lua_State>, float);
struct Timer { char u0[28]; int free; };
struct Timers {
    Ptr32<Ptr32<Timer>> start; Ptr32<Ptr32<Timer>> finish;
    unsigned size() const { return finish - start; }
    Ptr32<Timer> & operator[](unsigned i) { return start[i]; }
};
struct Script { char u0[68]; Ptr32<lua_State> L; char u72[312]; Timers timers; };
extern "C" void error_801022ec(Ptr32<Script>, Ptr32<const char>);
extern "C" unsigned start_8005ffc8(Ptr32<Timer>, Ptr32<const char>, int);
extern "C" int d25c_script_start_timer_80102b2c(Ptr32<Script> self) {
    int n = lua_gettop(self->L);
    if (n != 2) {
        lua_settop(self->L, -n - 1);
        error_801022ec(self, "Incorrect number of arguments to function 'StartTimer'");
        return 0;
    }
    if (!lua_isstring(self->L, -2) || !lua_isnumber(self->L, -1)) {
        error_801022ec(self, "Invalid argument to function 'StartTimer'");
        lua_settop(self->L, -3);
        return 0;
    }
    unsigned i = 0;
    goto test;
step:
    i++;
test:
    if (i < self->timers.size() && self->timers[i]->free == 0) goto step;
    int result;
    if (i >= self->timers.size()) {
        error_801022ec(self, "Too many timers requested in function 'StartTimer'");
        lua_settop(self->L, -3);
        result = 0;
    } else {
    Ptr32<const char> name = lua_tostring(self->L, -2);
    int v = (int)lua_tonumber(self->L, -1);
    unsigned h = start_8005ffc8(self->timers[i], name, v);
    lua_settop(self->L, -3);
    lua_pushnumber(self->L, (float)h);
    result = 1;
    }
    return result;
}


