// Appears to switch a worm's jetpack state: when a new state is given while one
// is active it plays the w3d_str_80381c48 animation unless the current team
// entry is named "Path", and clears the active flags; when the new state is
// empty it plays "Jetpack" for an active one. Always stores the new state.
extern "C" int strcmp(const char *a, const char *b);

struct K10aTeamEntry
{
    char pad0[60];
    const char *name;           // +60
};

struct K10aWorld
{
    char pad0[312];
    unsigned int current;       // +312
    K10aTeamEntry **entries;    // +316
};

struct K10aWorm
{
    char pad0[72];
    int attached;               // +72
    char pad76[72];
    int moving;                 // +148
    char pad152[16];
    int active;                 // +168
    int state;                  // +172
};

extern K10aWorld *w3d_world_804aa8c8;
extern const char w3d_str_80381c08[];   // "Path"
extern const char w3d_str_80381c48[];   // w3d_str_80381c48
extern const char w3d_str_80381c58[];   // "Jetpack"
extern "C" int fn_80035714(K10aWorld *world, const char *name, float weight);
extern "C" void w3d_auto_800aba08(K10aWorm *worm);

static inline bool k10a_differs(const char *a, const char *b)
{
    return strcmp(a, b) != 0;
}

extern "C" void w3d_k10a_jetpack_state_800ac14c(K10aWorm *self, int state)
{
    if (self->state == state)
        return;
    if (state != 0)
    {
        if (self->active != 0)
        {
            K10aWorld *world = w3d_world_804aa8c8;
            K10aTeamEntry *entry = *(K10aTeamEntry **)((char *)world->entries + (world->current << 2));
            if (k10a_differs(entry->name, w3d_str_80381c08))
                fn_80035714(w3d_world_804aa8c8, w3d_str_80381c48, 1.0f);
        }
        if (self->attached != 0)
            w3d_auto_800aba08(self);
        self->moving = 0;
        self->active = 0;
    }
    else
    {
        if (self->active != 0)
            fn_80035714(w3d_world_804aa8c8, w3d_str_80381c58, 1.0f);
    }
    self->state = state;
}
