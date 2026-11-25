// External GC32 object view: its trail handle is observed at byte 32.
struct Trail;
extern "C" Trail *lookup_80164fc8(int);
extern "C" void flag_80122af8(Trail *);
struct TrailHandle {
 int id;
 void release(int empty) {
  if(id!=-1) {
   Trail *trail=lookup_80164fc8(id);
   if(trail) flag_80122af8(trail);
   id=empty;
  }
 }
};
struct TrailOwnerView { unsigned externalWords[8]; TrailHandle trail; };
extern "C" void mx13sa_release_trail_800cd990(TrailOwnerView *owner) { owner->trail.release(-1); }
