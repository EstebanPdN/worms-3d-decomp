struct State { char pad[240]; unsigned flags; };
extern State *state_804aaabc;
extern "C" int handles_8006e10c(State *);
extern "C" bool check_8006ae58(State *);
extern "C" int terra_only_a4_flags_8006ee18() {
    if (state_804aaabc->flags & 0x04000000) return 0;
    if (handles_8006e10c(state_804aaabc)) return 0;
    if (state_804aaabc->flags & 0x01000000) { if (!check_8006ae58(state_804aaabc)) return 0; return 1; }
    return 0;
}
