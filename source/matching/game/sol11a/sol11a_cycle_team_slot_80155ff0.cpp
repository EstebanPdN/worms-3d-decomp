// Partial GC32 views of external containers; no instances of these views are created.
struct Sol11aSlotRange { unsigned *begin,*end,*capacity; bool empty()const { return begin==end; } unsigned size()const { return end-begin; } unsigned &operator[](unsigned i) { return *(unsigned *)((char *)begin+(i<<2)); } };
struct Sol11aCycleTeam { unsigned char external_prefix[213]; unsigned char owner; };
struct Sol11aCycleState { unsigned char external_prefix[52]; Sol11aSlotRange slots[8]; unsigned current[8]; unsigned char external_middle[116]; void *selection; Sol11aSlotRange &range(unsigned i) { return *(Sol11aSlotRange *)((char *)this+i*12+52); } };
extern const char active_worm_803a27ac[];
extern "C" int read_800fc1f0(const char *const *,int *);
extern "C" Sol11aCycleTeam *team_800fc6dc(int);
extern "C" void *identity_803426b4(void *);
extern "C" int update_80178c54(void *,const unsigned *);
extern "C" void refresh_801558dc(Sol11aCycleState *,unsigned);
extern "C" void sol11a_cycle_team_slot_80155ff0(Sol11aCycleState *self) {
 const char *key=active_worm_803a27ac;
 int active=0;
 read_800fc1f0(&key,&active);
 unsigned owner=team_800fc6dc(active)->owner;
 if(!self->range(owner).empty()) {
  ++self->current[owner];
  if(self->range(owner).size()<=self->current[owner])self->current[owner]=0;
  unsigned value=self->range(owner)[self->current[owner]];
  if(value<=16)update_80178c54(identity_803426b4(self->selection),&value);
  refresh_801558dc(self,owner);
 }
}
