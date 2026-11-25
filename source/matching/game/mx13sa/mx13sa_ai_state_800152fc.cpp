// External GC32 AI state views; names are inferred from consumers and property keys.
struct Position { float x,y,z; };
struct WormView { unsigned char beforeTeam[213]; unsigned char team; };
extern "C" WormView *worm_800fc6dc(int);
extern "C" int team_mode_800154b4(int);
extern "C" Position *position_80015588(int);
extern "C" int artillery_800154e0(int);
extern "C" void *query_800fcb4c(int);
extern "C" int read_int_800fc230(const char *const *,int *);
extern "C" void init_teams_80006ff4();
extern int active_804aa6c0,selected_804aa6c4,current_804aa6c8,team_804aa6cc,mode_804aa6d0;
extern void *context_804aa6d8;
extern "C" int artillery_state_804aa6dc,busy_804aa598,pending_804aa59c;
extern Position origin_8041d3a0[],target_8041d3ac[];
extern const char choose_8036a588[];
extern "C" void mx13sa_ai_state_800152fc(int worm) {
 active_804aa6c0=worm;
 team_804aa6cc=worm_800fc6dc(worm)->team;
 mode_804aa6d0=team_mode_800154b4(worm);
 origin_8041d3a0[0]=*position_80015588(worm);
 target_8041d3ac[0]=origin_8041d3a0[0];
 artillery_state_804aa6dc=artillery_800154e0(worm);
 context_804aa6d8=query_800fcb4c(active_804aa6c0);
 const char *key=choose_8036a588;
 int enabled;
 current_804aa6c8=worm;
 read_int_800fc230(&key,&enabled);
 if(enabled && !busy_804aa598) {
  selected_804aa6c4=worm;
  init_teams_80006ff4();
  pending_804aa59c=1;
 }
}
