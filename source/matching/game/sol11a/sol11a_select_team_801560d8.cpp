// Team, owner and blocking meanings are inferred; the borrow tag meaning is unknown.
// GC ABI external views. Only observed offsets are named; these views are never constructed.
struct Sol11aTeam { unsigned char external_prefix[213]; unsigned char owner; unsigned char external_gap[6]; int active; };
struct Sol11aOwner { unsigned char external_prefix[44]; int blocked; };
struct Sol11aSelection { unsigned char external_prefix[308]; void *value; };
struct Sol11aBorrow_80178474 { void *object; unsigned tag; Sol11aBorrow_80178474():object(0),tag(0xe3a8) {} ~Sol11aBorrow_80178474(); };
extern "C" {
 Sol11aTeam *team_800fc6dc(unsigned);
 Sol11aOwner *owner_800fc7f8(unsigned);
 void *identity_803426b4(void *);
 int update_80178c54(void *,const unsigned *);
}
extern "C" void sol11a_select_team_801560d8(Sol11aSelection *self) {
 unsigned selected=0;
 unsigned i=0;
 do {
  Sol11aTeam *team=team_800fc6dc(i);
  unsigned ownerIndex=team->owner;
  Sol11aBorrow_80178474 borrow;
  Sol11aOwner *owner=owner_800fc7f8(ownerIndex);
  if(team->active==1 && owner->blocked==0) { selected=team->owner; break; }
 } while(++i<=15);
 void *property=identity_803426b4(self->value);
 unsigned value=selected;
 update_80178c54(property,&value);
}
