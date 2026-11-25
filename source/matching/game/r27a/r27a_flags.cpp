struct R27aState { char unknown[240]; unsigned int flags; };
extern R27aState *r27a_state_804aaabc;
extern "C" int r27a_handles_8006e10c(R27aState *);
extern "C" int r27a_check_8006ae58(R27aState *);
extern "C" int r27a_flags_8006ee18() {
 if(r27a_state_804aaabc->flags & 0x04000000) return 0;
 if(r27a_handles_8006e10c(r27a_state_804aaabc)) return 0;
 if(r27a_state_804aaabc->flags & 0x01000000) { if (r27a_check_8006ae58(r27a_state_804aaabc)) goto yes; return 0; }
 return 0;
 yes: return 1;
}
