struct T261State { char unknown[240]; unsigned int flags; };
extern T261State *t261_state_804aaabc;
extern "C" int t261_handles_8006e10c(T261State *);
extern "C" bool t261_check_8006ae58(T261State *);
extern "C" int codex_flags_8006ee18() {
 if(t261_state_804aaabc->flags & 0x04000000) return 0;
 if(t261_handles_8006e10c(t261_state_804aaabc)) return 0;
 if(t261_state_804aaabc->flags & 0x01000000) { return t261_check_8006ae58(t261_state_804aaabc)?1:0; }
 return 0;
}
