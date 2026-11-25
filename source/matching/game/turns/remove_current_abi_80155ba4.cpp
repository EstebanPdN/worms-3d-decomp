// The observed native call clears CR1 before its three integer arguments.
// A variadic native ABI view preserves that call convention; no optional
// arguments are passed or read by the witnessed forward-copy implementation.
// Calls the witnessed GameCube forward-copy routine at 0x802eee50.
// Adjacent erase ranges can overlap with destination below source; this
// native alias has no standard memcpy nonoverlap contract. Original routine
// reads and stores in increasing address order; portable adaptation is separate.
// Layout from original 0x80154918 and cleanup 0x80154aa8.
// Partial GC32 receiver; unknown fields and external function behavior remain obligations.
// GC32 reconstruction of observed integer-vector erase and team-empty notification.
struct Sol31bTurnContext;
struct Sol31bTeamQuery { unsigned char unknown[213]; unsigned char team; };
extern "C" Sol31bTurnContext *cast_80342a78(void *);
extern "C" int current_index_80178d1c(Sol31bTurnContext *);
extern "C" Sol31bTeamQuery *team_query_800fc6dc(unsigned int);
extern "C" void *native_forward_copy_802eee50(void *, const void *, unsigned int, ...);
inline unsigned int sol31b_byte_distance(const void *first, const void *last) {
 return (const char *)last - (const char *)first;
}
struct Sol31bIntVector {
 int *first, *last, *limit;
 int *begin() { return first; }
 int *end() { return last; }
 bool empty() { return begin() == end(); }
 void erase(int *where) {
  if (where + 1 != end()) native_forward_copy_802eee50(where, where + 1, sol31b_byte_distance(where, end() - 1));
  --last;
 }
};
struct Sol31bTurns {
 unsigned char unknown0[48]; void *context;
 // Constructor 0x80154918 initializes two four-element arrays at +52/+100.
 Sol31bIntVector teams[4];
 Sol31bIntVector otherTeams[4];
 unsigned char unknown148[164];
 // Constructor and reset 0x80156190 initialize exactly sixteen entries.
 int selection[16];
};
typedef char Sol31bGc32PointerCheck[sizeof(void *) == 4 ? 1 : -1];
typedef char Sol31bVectorStrideCheck[sizeof(Sol31bIntVector) == 12 ? 1 : -1];
extern "C" void notify_empty_801565e4(Sol31bTurns *, unsigned int);
extern "C" void w3d_turns_remove_current_80155ba4(Sol31bTurns *self) {
 int index = current_index_80178d1c(cast_80342a78(self->context));
 self->selection[index] = -1;
 unsigned int team = team_query_800fc6dc(index)->team;
 int *it = self->teams[team].begin();
 if (it != self->teams[team].end()) {
  do {
   if (*it == index) {
    self->teams[team].erase(it);
    if (self->teams[team].empty()) notify_empty_801565e4(self, team);
    return;
   }
   ++it;
  } while (it != self->teams[team].end());
 }
}
