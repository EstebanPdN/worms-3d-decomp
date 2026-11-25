// Inferred PPC32 views; padding records observed offsets, not complete classes.
struct Retained;
struct RetainTable { void *slots[3]; void (*retain)(Retained *); };
struct Retained { RetainTable *dispatch; };
struct LuaContext { unsigned char unknown[36]; void *environment; };
struct LuaState { unsigned char unknown[88]; LuaContext *context; };
struct Userdata { Retained *object; void *environment; };
extern "C" {
const char *fn_802dd028(LuaState *, int, unsigned int *);
Retained *fn_801a01f0(const char *, const void *);
Userdata *fn_802ce9d8(LuaState *, unsigned int);
void fn_802cd99c(LuaState *, int);
void fn_802ce5ec(LuaState *, int);
extern unsigned char lbl_80365788[];
}
// External lookup, Lua allocation, and retained-interface ownership remain dependencies.
extern "C" int w3d_r25a_create_named_userdata_8019e710(LuaState *state) {
    unsigned int length;
    Retained *object = fn_801a01f0(fn_802dd028(state, 1, &length), lbl_80365788);
    if (!object) return 0;
    Userdata *value = fn_802ce9d8(state, 8);
    value->object = object;
    object->dispatch->retain(object);
    value->environment = state->context->environment;
    fn_802cd99c(state, -10002);
    fn_802ce5ec(state, -2);
    return 1;
}
struct Actor {
    void *dispatch;
    unsigned char unknown04[72];
    int cleared4c, cleared50, cleared54, cleared58, cleared5c, cleared60;
    unsigned char member64[8];
    int cleared6c, cleared70, sentinel74;
};
extern "C" {
void fn_80161014(Actor *);
void fn_80126184(void *);
extern unsigned char lbl_80410bd8[];
}
extern "C" Actor *w3d_r25a_initialize_actor_80124edc(Actor *self) {
    fn_80161014(self);
    self->cleared5c = 0;
    self->cleared60 = 0;
    self->dispatch = lbl_80410bd8;
    fn_80126184(self->member64);
    self->cleared70 = 0;
    self->sentinel74 = -1;
    self->cleared6c = 0;
    self->cleared4c = 0;
    self->cleared50 = 0;
    self->cleared54 = 0;
    self->cleared58 = 0;
    return self;
}
